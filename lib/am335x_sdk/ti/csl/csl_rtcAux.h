/**
 *   @file  csl_rtcAux.h
 *
 *   @brief
 *      This is the RTC Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the RTC Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002-2011, Texas Instruments, Inc.
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

#ifndef CSL_RTCAUX_H
#define CSL_RTCAUX_H

#include <ti/csl/csl_rtc.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
* global macro declarations
\******************************************************************************/

/** @addtogroup CSL_RTC_ENUM
 @{ */

/**
@}
*/

/** @addtogroup CSL_RTC_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_rtcBcdToDec
 *
 *   @b Description
 *   @n This API converts the input BCD number to its decimal equivalent number.
 *
 *   @b Arguments
      @verbatim
          bcdNum     The value that holds the number in BCD format.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        bdcToDec = CSL_rtcBcdToDec(hRtc); // Convert BDC to decimal

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcBcdToDec(Uint32 bcdNum)
{
    Uint32 decNum = 0U;
    Uint32 multiplier = 1U;

    while(bcdNum > 0U)
    {
        decNum += (bcdNum & 0x0FU) * multiplier;
        multiplier = multiplier * 10U;
        bcdNum = bcdNum >> 0x4U;
    }

    return decNum;
}

/** ============================================================================
 *   @n@b CSL_rtcDecToBcd
 *
 *   @b Description
 *   @n This API converts the input decimal number to its BCD equivalent number.
 *
 *   @b Arguments
      @verbatim
          decNum   The value that holds the number in Hexadecimal format.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Example
 *   @verbatim

        decToBcd = CSL_rtcDecToBcd(hRtc); // Convert decimal to BCD

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcDecToBcd(Uint32 decNum)
{
    Uint32 bcdNum = 0U;
    Uint32 digit = 0U;
    Uint32 count = 0U;

    while(decNum > 0U)
    {
        digit = (decNum % 10U);
        bcdNum += (digit << (0x4U * count));
        count++;
        decNum = (decNum/10U);
    }

    return bcdNum;
}

/** ============================================================================
 *   @n@b CSL_rtcGetRevision
 *
 *   @b Description
 *   @n This function returns the revision Id of the module.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  The revision number of the RTC module. This will give the information
         regarding the major and minor revisions.
            - Bits[10:8] Major revision
            - Bits[7:6]  Custom revision for a particular device
            - Bits[5:0]  Minor revision
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_REVISION;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetRevision(hRtc); // Read RTC revision

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcGetRevision(CSL_rtcHandle hRtc)
{
    Uint32 revision = 0U;

    revision = hRtc->REVISION;

    return revision;
}

/** ============================================================================
 *   @n@b CSL_rtcWriteProtectEnable
 *
 *   @b Description
 *   @n This function enables/disables the write-protection for RTC registers.
 *
 *   @b Arguments
      @verbatim
          hRtc                The handle of the RTC module.
          enableWriteProtect  Value to specify whether write protection
                              feature has to be enabled/disabled.
                              'enableWriteProtect' can take any of the two values
                                - TRUE  to enable write protection the register
                                        are locked from spurious writes.
                                - FALSE to disable write protection to allow write
                                        access to RTC registers.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_KICK0;
 *      CSL_RTC_KICK1;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcWriteProtectEnable(hRtc, enableWriteProtect);
            // Enables/Disables the write-protection for RTC registers.

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcWriteProtectEnable(CSL_rtcHandle hRtc,
                                               Uint32 enableWriteProtect)
{
    if(TRUE == enableWriteProtect)
    {
        CSL_FINS(hRtc->KICK0, RTC_KICK0_KICK0, CSL_RTC_KICK0_LOCK_KEY);

        CSL_FINS(hRtc->KICK1, RTC_KICK1_KICK1, CSL_RTC_KICK1_LOCK_KEY);
    }
    else
    {
        CSL_FINS(hRtc->KICK0, RTC_KICK0_KICK0, CSL_RTC_KICK0_UNLOCK_KEY);

        CSL_FINS(hRtc->KICK1, RTC_KICK1_KICK1, CSL_RTC_KICK1_UNLOCK_KEY);
    }
}

/** ============================================================================
 *   @n@b CSL_rtcClkSrcSelect
 *
 *   @b Description
 *   @n This API selects the clock source for the RTC module.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          clkSrc     This specifies the RTC Clock source to be selected 'clkSrc'
                     can take one of the values from the following enum
                        - #CSL_rtcClkSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_OSC;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcClkSrcSelect(hRtc, clkSrc); // Select the clock source

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcClkSrcSelect(CSL_rtcHandle hRtc,
                                         CSL_rtcClkSrc clkSrc)
{
    /* Select the correct Clock Source */
    CSL_FINS(hRtc->OSC, RTC_OSC_K32CLK_SEL,
                    clkSrc);

    if(CSL_RTC_CLK_SRC_INTERNAL == clkSrc)
    {
        /* Disable the XTAL Pins and apply high impedance. */
        CSL_FINS(hRtc->OSC, RTC_OSC_OSC32K_GZ, ((uint32_t)0x1U));
    }
    else
    {
        /* Enable the XTAL Pins to connect it to the external Clk source. */
        CSL_FINS(hRtc->OSC, RTC_OSC_OSC32K_GZ, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcEnable
 *
 *   @b Description
 *   @n This API enables/disables the RTC module.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          enableModule  Value to indicate enabling/disabling of the module.
                        'enableModule' can take any of the two values:
                            - TRUE to enable the module.
                            - FALSE to disable the module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *   @n CSL_RTC_OSC;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcEnable(hRtc, enableModule); // Enable/Disable the RTC module.

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcEnable(CSL_rtcHandle hRtc, Uint32 enableModule)
{
    if(TRUE == enableModule)
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_RTC_DISABLE, ((uint32_t)0x0U));

        /* Enable the 32kHz clocks */
        CSL_FINS(hRtc->OSC, RTC_OSC_K32CLK_EN, ((uint32_t)0x1U));
    }
    else
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_RTC_DISABLE, ((uint32_t)0x01U));

        /* Disable the 32kHz clocks */
        CSL_FINS(hRtc->OSC, RTC_OSC_K32CLK_EN, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcRun
 *
 *   @b Description
 *   @n This function sets the RTC to run with the programmed date and time information.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcRun(hRtc); // Run RTC

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcRun(CSL_rtcHandle hRtc)
{
    CSL_FINS(hRtc->CTRL, RTC_CTRL_STOP_RTC, ((uint32_t)0x1U));
}

/** ============================================================================
 *   @n@b CSL_rtcStop
 *
 *   @b Description
 *   @n This function stops the RTC.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcStop(hRtc); // Stop RTC

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcStop(CSL_rtcHandle hRtc)
{
    CSL_FINS(hRtc->CTRL, RTC_CTRL_STOP_RTC, ((uint32_t)0x0U));
}

/** ============================================================================
 *   @n@b CSL_rtcTimerIntrEnable
 *
 *   @b Description
 *   @n This function enables the periodic timer interrupt.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          intrMask   This specifies the period between two consecutive Timer
                     interrupts. 'intrMask' can take one of the following values
                     from the following enum
                        - #CSL_rtcTimerIntrMask
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcTimerIntrEnable(hRtc, intrMask); // Enable timer interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcTimerIntrEnable(CSL_rtcHandle hRtc,
                                            CSL_rtcTimerIntrMask intrMask)
{
    /* Poll the status register flag until the BUSY  bit equals zero */
    CSL_RTC_WAIT_FOR_WRITE

    /* Enable Periodic Timer interrupts */
    CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_TIMER, ((uint32_t)0x1U));

    /* Set the Timer interrupt period. */
    CSL_FINS(hRtc->INTRS, RTC_INTRS_EVERY, intrMask);
}

/** ============================================================================
 *   @n@b CSL_rtcTimerIntrDisable
 *
 *   @b Description
 *   @n This function disables the periodic timer interrupts.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcTimerIntrDisable(hRtc); // Disable timer interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcTimerIntrDisable(CSL_rtcHandle hRtc)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    CSL_RTC_WAIT_FOR_WRITE

    /* Disable Periodic Timer interrupts */
    CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_TIMER, ((uint32_t)0x0U));
}

/** ============================================================================
 *   @n@b CSL_rtcTimerIntrStatus
 *
 *   @b Description
 *   @n This function returns the status of TIMER interrupt events.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_STS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcTimerIntrStatus(hRtc); // Get RTC timer interrupt sttaus

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcTimerIntrStatus(CSL_rtcHandle hRtc)
{
    Uint32 regVal = 0U;

    regVal = hRtc->STS;
    regVal = (regVal & (CSL_RTC_STS_EVT_1S_MASK |
                CSL_RTC_STS_EVT_1M_MASK | CSL_RTC_STS_EVT_1H_MASK |
                CSL_RTC_STS_EVT_1D_MASK));

    return regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcAlarmIntrEnable
 *
 *   @b Description
 *   @n This function enables ALARM interrupts.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          alarmNum   The value identifies the alarm register for which the
                     Interrupts have to be enabled. 'alarmNum' can take one of
                     the following values from the following enum
                        - #CSL_rtcAlarmNum
    @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcAlarmIntrEnable(hRtc, alarmNum); // Enable the Alarm interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcAlarmIntrEnable(CSL_rtcHandle hRtc,
                                            CSL_rtcAlarmNum alarmNum)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    CSL_RTC_WAIT_FOR_WRITE

    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_ALARM, ((uint32_t)0x1U));
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_ALARM2, ((uint32_t)0x1U));
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcAlarmIntrDisable
 *
 *   @b Description
 *   @n This function disables the ALARM interrupts.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          alarmNum   The value identifies the alarm register for which the
                     Interrupts have to be enabled. 'alarmNum' can take one of
                     the following values from the following enum
                        - #CSL_rtcAlarmNum
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcAlarmIntrDisable(hRtc, alarmNum); // Disable the Alarm interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcAlarmIntrDisable(CSL_rtcHandle hRtc,
                                             CSL_rtcAlarmNum alarmNum)
{
    /* Poll the status register flag until the BUSY bit equals zero */
    CSL_RTC_WAIT_FOR_WRITE

    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_ALARM, ((uint32_t)0x0U));
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        /* Enable ALARM1 interrupts */
        CSL_FINS(hRtc->INTRS, RTC_INTRS_IT_ALARM2, ((uint32_t)0x0U));
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcAlarmIntrStatus
 *
 *   @b Description
 *   @n This function returns the status of ALARM interrupt events.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_STS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcAlarmIntrStatus(hRtc); // Get the alarm interrupt status

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcAlarmIntrStatus(CSL_rtcHandle hRtc)
{
    Uint32 regVal = 0U;

    regVal = hRtc->STS;
    regVal = (regVal & (CSL_RTC_STS_ALARM_MASK | CSL_RTC_STS_ALARM2_MASK));

    return regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcAlarmIntrClear
 *
 *   @b Description
 *   @n This function clears the ALARM interrupt status.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          alarmNum   The value identifies the alarm register for which the
                     Interrupts have to be enabled. 'alarmNum' can take one of
                     the following values from the following enum
                        - #CSL_rtcAlarmNum
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_STS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcAlarmIntrClear(hRtc, alarmNum); // Clear the alarm interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcAlarmIntrClear(CSL_rtcHandle hRtc,
                                           CSL_rtcAlarmNum alarmNum)
{
    Uint32 regVal = 0U;

    regVal = hRtc->STS;

    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        regVal = (regVal & ~CSL_RTC_STS_ALARM_MASK);
        regVal |= (((uint32_t)0x1U) << CSL_RTC_STS_ALARM_SHIFT);
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        regVal = (regVal & ~CSL_RTC_STS_ALARM2_MASK);
        regVal |= (((uint32_t)0x1U) << CSL_RTC_STS_ALARM2_SHIFT);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
    /* Write the updated value back to the register. */
    hRtc->STS = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcIsBusy
 *
 *   @b Description
 *   @n This function returns the status of RTC module.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  TRUE   indicating RTC is busy updating an event.
 *   @n  FALSE  indicating RTC event update is more than 15 seconds from the current time.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_STS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcIsBusy(hRtc); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcIsBusy(CSL_rtcHandle hRtc)
{
    Uint32 status = FALSE;

    if(0x1U ==
        CSL_FEXT(hRtc->STS, RTC_STS_BUSY))
    {
        status = TRUE;
    }

    return status;
}

/** ============================================================================
 *   @n@b CSL_rtcRoundingEnable
 *
 *   @b Description
 *   @n This function Enables/Disables the feature of minute rounding.
 *
 *   @b Arguments
      @verbatim
          hRtc              The handle of the RTC module.
          enableRounding    value to specify whether the Rounding feature
                            has to be enabled/disabled. 'enableRounding' can
                            take any of the two values:
                                - TRUE to indicate enabling Rounding off feature
                                - FALSE to indicate disabling Rounding off feature
    @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcRoundingEnable(hRtc, enableRounding);
                    // Enable/Disable the minutes rounding

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcRoundingEnable(CSL_rtcHandle hRtc,
                                           Uint32 enableRounding)
{
    if(enableRounding == TRUE)
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_ROUND_30S, ((uint32_t)0x1U));
    }
    else
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_ROUND_30S, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcSetTime
 *
 *   @b Description
 *   @n This function programs the specified time information in the Time registers.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          pTime      pointer to the structure CSL_rtcTimeObj which contains the
                     variables representing the Time to be set in the RTC.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_SECONDS;
 *   @n CSL_RTC_MINUTES;
 *   @n CSL_RTC_HOURS;
 *   @n CSL_RTC_CTRL;
 *   @n CSL_RTC_HOURS_PM_NAM;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetTime(hRtc, &time); // Set current time

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetTime(CSL_rtcHandle hRtc, CSL_rtcTimeObj *pTime)
{
    Uint32 timeVal = 0U;
    Uint32 regVal = 0U;

    /* Get The BCD equivalent of the seconds value */
    timeVal = CSL_rtcDecToBcd(pTime->seconds);

    regVal = hRtc->SECONDS;
    /* Clear the Seconds field */
    regVal &= ~(CSL_RTC_SECONDS_SEC0_MASK | CSL_RTC_SECONDS_SEC1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /* Write the seconds value */
    hRtc->SECONDS = regVal;

    /* Get The BCD equivalent of the minutes value */
    timeVal = CSL_rtcDecToBcd(pTime->minutes);

    regVal = hRtc->MINUTES;
    /* Clear the Minutes field */
    regVal &= ~(CSL_RTC_MINUTES_MIN0_MASK | CSL_RTC_MINUTES_MIN1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /* Write the seconds value */
    hRtc->MINUTES = regVal;

    /* Get the Time mode. */
    timeVal = pTime->timeMode;

    CSL_FINS(hRtc->CTRL, RTC_CTRL_MODE_12_24, timeVal);

    /* Get The BCD equivalent of the hours value*/
    timeVal = CSL_rtcDecToBcd(pTime->hours);

    /* Get the Hours value. */
    regVal = hRtc->HOURS;

    /* Clear the Hours field */
    regVal &= ~(CSL_RTC_HOURS_HOUR0_MASK | CSL_RTC_HOURS_HOUR1_MASK);
    regVal |= timeVal;

    if(CSL_RTC_TIME_MODE_12_HR == pTime->timeMode)
    {
        timeVal = pTime->meridiemMode;

        CSL_FINS(regVal, RTC_HOURS_PM_NAM, timeVal);
    }

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /* Write the Hours value. */
    hRtc->HOURS = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcGetTime
 *
 *   @b Description
 *   @n This function reads the current time from the registers holding time information.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          pTime      Pointer to the structure CSL_rtcTimeObj which contains the
                     variables representing the Time through which the time
                     set in the RTC will be returned.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_SECONDS;
 *   @n CSL_RTC_MINUTES;
 *   @n CSL_RTC_HOURS;
 *   @n CSL_RTC_CTRL;
 *   @n CSL_RTC_HOURS_PM_NAM;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetTime(hRtc, &time); // Get current time

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcGetTime(CSL_rtcHandle hRtc, CSL_rtcTimeObj *pTime)
{
    Uint32 timeVal = 0U;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /* Read the Seconds value. */
    timeVal = hRtc->SECONDS;
    timeVal &= (CSL_RTC_SECONDS_SEC0_MASK | CSL_RTC_SECONDS_SEC1_MASK);
    /* Get the Decimal equivalent of the seconds value in BCD */
    pTime->seconds = CSL_rtcBcdToDec(timeVal);

    /* Read the Minutes value. */
    timeVal = hRtc->MINUTES;
    timeVal &= (CSL_RTC_MINUTES_MIN0_MASK | CSL_RTC_MINUTES_MIN1_MASK);
    /* Get the Decimal equivalent of the minutes value in BCD */
    pTime->minutes = CSL_rtcBcdToDec(timeVal);

    /* Read the Time mode */
    timeVal = CSL_FEXT(hRtc->CTRL, RTC_CTRL_MODE_12_24);
    pTime->timeMode = (CSL_rtcTimeMode) timeVal;

    /* Read the Hours value. */
    timeVal = hRtc->HOURS;

    /*
    ** If the Time mode is in 12 hour format get the meridiem mode of the
    ** current time set.
    */
    if(CSL_RTC_TIME_MODE_12_HR == pTime->timeMode)
    {
        pTime->meridiemMode = (CSL_rtcTimeMeridiem) CSL_FEXT(timeVal, RTC_HOURS_PM_NAM);
    }

    timeVal &= (CSL_RTC_HOURS_HOUR0_MASK | CSL_RTC_HOURS_HOUR1_MASK);
    /* Get the Decimal equivalent of the hours value in BCD */
    pTime->hours = CSL_rtcBcdToDec(timeVal);

}

/** ============================================================================
 *   @n@b CSL_rtcSetDate
 *
 *   @b Description
 *   @n This function sets the specified date information in registers holding date information.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          pDate      pointer to the structure CSL_rtcDateObj which contains the
                     variables representing the Date to be set in the RTC.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_YEARS;
 *   @n CSL_RTC_MONTHS;
 *   @n CSL_RTC_DAYS;
 *   @n CSL_RTC_WEEKS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetDate(hRtc, &date); // Set current date

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetDate(CSL_rtcHandle hRtc, CSL_rtcDateObj *pDate)
{
    Uint32 dateVal = 0U;
    Uint32 regVal = 0U;

    /* Get The BCD equivalent of the years value*/
    dateVal = CSL_rtcDecToBcd(pDate->year);

    regVal = hRtc->YEARS;
    /* Clear the years field */
    regVal &= ~(CSL_RTC_YEARS_YEAR0_MASK | CSL_RTC_YEARS_YEAR1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Set the years value */
    hRtc->YEARS = regVal;

    /* Get the BCD equivalent of the month value. */
    dateVal = CSL_rtcDecToBcd(pDate->month);

    regVal = hRtc->MONTHS;
    /* Clear the month field */
    regVal &= ~(CSL_RTC_MONTHS_MONTH0_MASK | CSL_RTC_MONTHS_MONTH1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Set the month value */
    hRtc->MONTHS = regVal;

    /* Get the BCD equivalent of the Day value. */
    dateVal = CSL_rtcDecToBcd(pDate->day);

    regVal = hRtc->DAYS;
    /* Clear the years field */
    regVal &= ~(CSL_RTC_DAYS_DAY0_MASK | CSL_RTC_DAYS_DAY1_MASK);
    regVal |= dateVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Set the Day value */
    hRtc->DAYS = regVal;

    /* Get the Day of the Week. */
    dateVal = CSL_rtcDecToBcd(pDate->weekDay);

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /* Set the Day of the Week value */
    CSL_FINS(hRtc->WEEKS, RTC_WEEKS_WEEK, dateVal);
}

/** ============================================================================
 *   @n@b CSL_rtcGetDate
 *
 *   @b Description
 *   @n This function reads the calendar information from relevant registers holding date information.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          pDate      pointer to the structure CSL_rtcDateObj holding the variables
                     representing the Date through which the date set in the RTC
                     will be returned.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_YEARS;
 *   @n CSL_RTC_MONTHS;
 *   @n CSL_RTC_DAYS;
 *   @n CSL_RTC_WEEKS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetDate(hRtc, &date); // Get current date

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcGetDate(CSL_rtcHandle hRtc, CSL_rtcDateObj *pDate)
{
    Uint32 dateVal = 0U;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE

    /*
    ** Doing a dummy read of seconds register which internally
    ** fetches all the Time and Date register into shadow register.
    ** This ensures the same date and time is read when the last second read
    ** register was done.
    */
    hRtc->SECONDS = hRtc->SECONDS;

    /* Read the Year value */
    dateVal = hRtc->YEARS;
    dateVal &= (CSL_RTC_YEARS_YEAR0_MASK | CSL_RTC_YEARS_YEAR1_MASK);
    /* Get the decimal equivalent of the year value in BCD */
    pDate->year = CSL_rtcBcdToDec(dateVal);

    /* Read the Month value */
    dateVal = hRtc->MONTHS;
    dateVal &= (CSL_RTC_MONTHS_MONTH0_MASK | CSL_RTC_MONTHS_MONTH1_MASK);
    /* Get the decimal equivalent of the month value in BCD */
    pDate->month = CSL_rtcBcdToDec(dateVal);

    /* Read the Day value */
    dateVal = hRtc->DAYS;
    dateVal &= (CSL_RTC_DAYS_DAY0_MASK | CSL_RTC_DAYS_DAY1_MASK);
    /* Get the decimal equivalent of the date value in BCD */
    pDate->day = CSL_rtcBcdToDec(dateVal);

    /* Read the Days of the Week Value. */
    dateVal = CSL_FEXT(hRtc->WEEKS, RTC_WEEKS_WEEK);
    /* Get the decimal equivalent of the date value in BCD */
    pDate->weekDay = (CSL_rtcWeekDay) CSL_rtcBcdToDec(dateVal);

}

/** ============================================================================
 *   @n@b CSL_rtcSetAlarm
 *
 *   @b Description
 *   @n This function sets the specified alarm register with Alarm information including Time and Date.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          alarmNum   The value identifies the alarm register for which the
                     Interrupts have to be enabled. 'alarmNum' can take one of
                     the following values from the following enum
                        - #CSL_rtcAlarmNum
          pAlarmTime Pointer to the structure CSL_rtcTimeObj which contains the
                     variables representing Alarm Time to be set in the RTC.
          pAlarmDate Pointer to the structure dateObj which contains the
                     variables representing Alarm Date to be set in the RTC.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetAlarm(hRtc, alarmNum, &alarmTime, &alarmDate); // Configure alarm

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetAlarm(CSL_rtcHandle hRtc,
                                     CSL_rtcAlarmNum alarmNum,
                                     CSL_rtcTimeObj *pAlarmTime,
                                     CSL_rtcDateObj *pAlarmDate)
{
    Uint32 timeVal = 0U;
    Uint32 regVal = 0U;

    /* Get the BCD equivalent of the seconds value. */
    timeVal = CSL_rtcDecToBcd(pAlarmTime->seconds);
    regVal = CSL_RTC_MAKE_ALARM_SECONDS(alarmNum);
    /* Clear the Seconds field */
    regVal &= ~(CSL_RTC_ALARM_SECONDS_ALARM_SEC0_MASK |
                    CSL_RTC_ALARM_SECONDS_ALARM_SEC1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the seconds value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_SECONDS = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_SECONDS = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Get BCD equivalent of the minutes value. */
    timeVal = CSL_rtcDecToBcd(pAlarmTime->minutes);

    regVal = CSL_RTC_MAKE_ALARM_MINUTES(alarmNum);
    /* Clear the Seconds field */
    regVal &= ~(CSL_RTC_ALARM_MINUTES_ALARM_MIN0_MASK |
                    CSL_RTC_ALARM_MINUTES_ALARM_MIN1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the seconds value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_MINUTES = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_MINUTES = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Get the Time mode format. */
    timeVal = pAlarmTime->timeMode;

    CSL_FINS(hRtc->CTRL, RTC_CTRL_MODE_12_24, timeVal);

    /* Get the BCD equivalent of the Hours Value */
    timeVal = CSL_rtcDecToBcd(pAlarmTime->hours);

    regVal = CSL_RTC_MAKE_ALARM_HOURS(alarmNum);
    /* Clear the Hours field */
    regVal &= ~(CSL_RTC_ALARM_HOURS_ALARM_HOUR0_MASK |
                    CSL_RTC_ALARM_HOURS_ALARM_HOUR1_MASK);
    regVal |= timeVal;

    if(CSL_RTC_TIME_MODE_12_HR == pAlarmTime->timeMode)
    {
        timeVal = pAlarmTime->meridiemMode;

        CSL_FINS(regVal, RTC_ALARM_HOURS_ALARM_PM_NAM, timeVal);
    }

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the hours value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_HOURS = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_HOURS = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Get the BCD equivalent of the year value. */
    timeVal = CSL_rtcDecToBcd(pAlarmDate->year);

    regVal = CSL_RTC_MAKE_ALARM_YEARS(alarmNum);
    /* Clear the year field */
    regVal &= ~(CSL_RTC_ALARM_YEARS_ALARM_YEAR0_MASK |
                    CSL_RTC_ALARM_YEARS_ALARM_YEAR1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the year value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_YEARS = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_YEARS = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Get the BCD equivalent of the month value. */
    timeVal = CSL_rtcDecToBcd(pAlarmDate->month);

    regVal = CSL_RTC_MAKE_ALARM_MONTHS(alarmNum);
    /* Clear the months field */
    regVal &= ~(CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_MASK |
                    CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the months value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_MONTHS = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_MONTHS = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    /* Get the BCD equivalent of the day value. */
    timeVal = CSL_rtcDecToBcd(pAlarmDate->day);

    regVal = CSL_RTC_MAKE_ALARM_DAYS(alarmNum);
    /* Clear the day field */
    regVal &= ~(CSL_RTC_ALARM_DAYS_ALARM_DAY0_MASK |
                    CSL_RTC_ALARM_DAYS_ALARM_DAY1_MASK);
    regVal |= timeVal;

    /* Check if RTC is busy updating its registers. */
    CSL_RTC_WAIT_FOR_WRITE
    /* Write the day value */
    if(CSL_RTC_ALARM_NUM_1 == alarmNum)
    {
        hRtc->ALARM_DAYS = regVal;
    }
    else if(CSL_RTC_ALARM_NUM_2 == alarmNum)
    {
        hRtc->ALARM2_DAYS = regVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcGetAlarm
 *
 *   @b Description
 *   @n This function reads the programmed Alarm information including Time and Date from the specified alarm register.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          alarmNum   The value identifies the alarm register for which the
                     Interrupts have to be enabled. 'alarmNum' can take one of
                     the following values from the following enum
                        - #CSL_rtcAlarmNum
          pAlarmTime Pointer to the structure CSL_rtcTimeObj which contains the
                     variables representing Alarm Time to be set in the RTC.
          pAlarmDate Pointer to the structure CSL_rtcDateObj which contains the
                     variables representing Alarm Date to be set in the RTC.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_INTRS;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetAlarm(hRtc, alarmNum, &alarmTime, &alarmDate); // Read alarm configuration

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcGetAlarm(CSL_rtcHandle hRtc,
                                     CSL_rtcAlarmNum alarmNum,
                                     CSL_rtcTimeObj *pAlarmTime,
                                     CSL_rtcDateObj *pAlarmDate)
{
    Uint32 regVal = 0U;

    /* Read the Seconds value. */
    regVal = CSL_RTC_MAKE_ALARM_SECONDS(alarmNum);
    regVal &= (CSL_RTC_ALARM_SECONDS_ALARM_SEC0_MASK |
                    CSL_RTC_ALARM_SECONDS_ALARM_SEC1_MASK);
    /* Get the decimal equivalent of the seconds value in BCD */
    pAlarmTime->seconds = CSL_rtcBcdToDec(regVal);

    /* Read the minutes value. */
    regVal = CSL_RTC_MAKE_ALARM_MINUTES(alarmNum);
    regVal &= (CSL_RTC_ALARM_MINUTES_ALARM_MIN0_MASK |
                    CSL_RTC_ALARM_MINUTES_ALARM_MIN1_MASK);
    /* Get the decimal equivalent of the minutes value in BCD */
    pAlarmTime->minutes = CSL_rtcBcdToDec(regVal);

    /* Read the Hours value. */
    regVal = CSL_RTC_MAKE_ALARM_HOURS(alarmNum);
    regVal &= (CSL_RTC_ALARM_HOURS_ALARM_HOUR0_MASK |
                    CSL_RTC_ALARM_HOURS_ALARM_HOUR1_MASK);
    /* Get the decimal equivalent of the hours value in BCD */
    pAlarmTime->hours = CSL_rtcBcdToDec(regVal);

    regVal = CSL_FEXT(hRtc->CTRL, RTC_CTRL_MODE_12_24);
    pAlarmTime->timeMode = (CSL_rtcTimeMode) regVal;

    /*
    ** If the Time mode is in 12 hour format get the meridiem mode of the
    ** current time set.
    */
    if(CSL_RTC_TIME_MODE_12_HR == pAlarmTime->timeMode)
    {
        pAlarmTime->meridiemMode = (CSL_rtcTimeMeridiem)CSL_FEXT(regVal, RTC_ALARM_HOURS_ALARM_PM_NAM);
    }

    /* Read the Year value */
    regVal = CSL_RTC_MAKE_ALARM_YEARS(alarmNum);
    regVal &= (CSL_RTC_ALARM_YEARS_ALARM_YEAR0_MASK |
                    CSL_RTC_ALARM_YEARS_ALARM_YEAR1_MASK);

    /* Get the Decimal equivalent of the year value */
    pAlarmDate->year = CSL_rtcBcdToDec(regVal);

    /* Read the Month value */
    regVal = CSL_RTC_MAKE_ALARM_MONTHS(alarmNum);
    regVal &= (CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_MASK |
                    CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_MASK);
    /* Get the decimal equivalent of the month value */
    pAlarmDate->month = CSL_rtcBcdToDec(regVal);

     /* Read the Day value */
    regVal = CSL_RTC_MAKE_ALARM_DAYS(alarmNum);
    regVal &= (CSL_RTC_ALARM_DAYS_ALARM_DAY0_MASK |
                    CSL_RTC_ALARM_DAYS_ALARM_DAY1_MASK);
    /* Get the decimal equivalent of the day value */
    pAlarmDate->day = CSL_rtcBcdToDec(regVal);
}

/** ============================================================================
 *   @n@b CSL_rtcSetScratchPadVal
 *
 *   @b Description
 *   @n This function writes the specified arbitrary value to the specified scratch register.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          regNum     Specifies the scratch register number to be accessed. This
                     can take the values from the following enum
                      - #CSL_rtcScratchPadReg
          scratchVal Refers to the value to be written to the scratch registers.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_SCRATCH0;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetScratchPadVal(hRtc, regNum, scratchVal);
                    // Write given value to scratchpad register

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetScratchPadVal(CSL_rtcHandle hRtc,
                                             CSL_rtcScratchPadReg regNum,
                                             Uint32 scratchVal)
{
    if(CSL_RTC_SCRATCH_PAD_0 == regNum)
    {
        hRtc->SCRATCH0 = scratchVal;
    }
    else if(CSL_RTC_SCRATCH_PAD_1 == regNum)
    {
        hRtc->SCRATCH1 = scratchVal;
    }
    else if(CSL_RTC_SCRATCH_PAD_2 == regNum)
    {
        hRtc->SCRATCH2 = scratchVal;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcGetScratchPadVal
 *
 *   @b Description
 *   @n This function is used to enable the MMU.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CSL_RTC_SCRATCH0;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetScratchPadVal(hRtc, regNum); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_rtcGetScratchPadVal(CSL_rtcHandle hRtc, Uint32 regNum)
{
    Uint32 scratchVal = 0U;

    if(CSL_RTC_SCRATCH_PAD_0 == regNum)
    {
        scratchVal = hRtc->SCRATCH0;
    }
    else if(CSL_RTC_SCRATCH_PAD_1 == regNum)
    {
        scratchVal = hRtc->SCRATCH1;
    }
    else if(CSL_RTC_SCRATCH_PAD_2 == regNum)
    {
        scratchVal = hRtc->SCRATCH2;
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }

    return scratchVal;
}

/** ============================================================================
 *   @n@b CSL_rtcSetIdleMode
 *
 *   @b Description
 *   @n This API configures the Idle Mode for the RTC.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          idleMode   This specifies the idle mode that is to be enabled. 'idleMode'
                     can take any of the values from the following enum
                        - #CSL_rtcIdleMode
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_SYSCONFIG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetIdleMode(hRtc, idleMode); // Configure idle mode

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetIdleMode(CSL_rtcHandle hRtc,
                                        CSL_rtcIdleMode idleMode)
{
    /* Set the Idle mode in the SYS Config register */
    CSL_FINS(hRtc->SYSCONFIG, RTC_SYSCONFIG_IDLEMODE, idleMode);
}

/** ============================================================================
 *   @n@b CSL_rtcWakeupEnable
 *
 *   @b Description
 *   @n This API is used to Enable the Alarm and Timer event Wakeup signal to the CPU.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          wakeupSrc  Value to specify the wakeup event source to disable
                     i.e. either the timer or the alarm based wakeup.
                     wakeupSrc' can take any of the values from the following enum
                        - #CSL_rtcWakeupEvtSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_IRQWAKEEN;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcWakeupEnable(hRtc, wakeupSrc); // Enable the wakeup signal

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcWakeupEnable(CSL_rtcHandle hRtc,
                                         CSL_rtcWakeupEvtSrc wakeupSrc)
{
    if(CSL_RTC_WAKEUP_EVT_SRC_TIMER == wakeupSrc)
    {
        CSL_FINS(hRtc->IRQWAKEEN, RTC_IRQWAKEEN_TIMMER_WAKEEN, ((uint32_t)0x1U));
    }
    else if(CSL_RTC_WAKEUP_EVT_SRC_ALARM == wakeupSrc)
    {
        CSL_FINS(hRtc->IRQWAKEEN, RTC_IRQWAKEEN_ALARM_WAKEEN, ((uint32_t)0x1U));
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcWakeupDisable
 *
 *   @b Description
 *   @n This API controls the PMIC power enable signal which can be used to control an external PMIC.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          wakeupSrc  Value to specify the wakeup event source to disable
                     i.e. either the timer or the alarm based wakeup.
                     wakeupSrc' can take any of the values from the following enum
                        - #CSL_rtcWakeupEvtSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_IRQWAKEEN;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcWakeupDisable(hRtc, wakeupSrc); // Disable the wakeup signal

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcWakeupDisable(CSL_rtcHandle hRtc,
                                          CSL_rtcWakeupEvtSrc wakeupSrc)
{
    if(CSL_RTC_WAKEUP_EVT_SRC_TIMER == wakeupSrc)
    {
        CSL_FINS(hRtc->IRQWAKEEN, RTC_IRQWAKEEN_TIMMER_WAKEEN, ((uint32_t)0x0U));
    }
    else if(CSL_RTC_WAKEUP_EVT_SRC_ALARM == wakeupSrc)
    {
        CSL_FINS(hRtc->IRQWAKEEN, RTC_IRQWAKEEN_ALARM_WAKEEN, ((uint32_t)0x0U));
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

/** ============================================================================
 *   @n@b CSL_rtcPmicPowerEnable
 *
 *   @b Description
 *   @n This API controls the PMIC power enable signal which can be used to control an external PMIC.
 *
 *   @b Arguments
      @verbatim
          hRtc            The handle of the RTC module.
          enablePmicPower  This specifies whether the PMIC power enable signal
                           has to be pulled low or high. 'enablePmicPower'
                           can take any of the two values:
                                - TRUE to enable PMIC power enable signal
                                - FALSE to disable PMIC power enable signal
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicPowerEnable(hRtc, enablePmicPower);
                    // Control the PMIC power enable signal

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicPowerEnable(CSL_rtcHandle hRtc,
                                            Uint32 enablePmicPower)
{
    if(TRUE == enablePmicPower)
    {
        CSL_FINS(hRtc->RTC_PMIC_REG, RTC_RTC_PMIC_REG_PWR_EN, ((uint32_t)0x1U));
    }
    else
    {
        CSL_FINS(hRtc->RTC_PMIC_REG, RTC_RTC_PMIC_REG_PWR_EN, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupEnable
 *
 *   @b Description
 *   @n This API Enables the PMIC External Wakeup feature.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured 'extWakeupSrc'
                        can take any of the values from the following enum
                            - #CSL_rtcExtWakeupSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupEnable(hRtc, extWakeupSrc); // Enable the PMIC external wakeup

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupEnable(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc)
{
    Uint32 regVal = 0U;

    /* Enable external wakeup inputs */
    regVal = hRtc->RTC_PMIC_REG;
    regVal |= (((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupDisable
 *
 *   @b Description
 *   @n This API Disables the PMIC External Wakeup feature.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured 'extWakeupSrc'
                        can take any of the values from the following enum
                            - #CSL_rtcExtWakeupSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupDisable(hRtc, extWakeupSrc); // Disable the PMIC external wakeup

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupDisable(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc)
{
    Uint32 regVal = 0U;

    /* Disable external wakeup inputs */
    regVal = hRtc->RTC_PMIC_REG;
    regVal &= ~(((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupPol
 *
 *   @b Description
 *   @n This API configures the Polarity of PMIC External Wakeup Pin
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured. 'extWakeupSrc'
                        can take any of the values from the following enum
                            - #CSL_rtcExtWakeupSrc
          wakeupEvtPol  This specifies whether the PMIC External Wakeup.
                        Polarity to be low or high. 'wakeupEvtPol'
                        can take any of the values from the following enum
                            - #CSL_rtcWakeupEvtPol
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupPol(hRtc, extWakeupSrc, wakeupEvtPol);
                    // Configures the Polarity of PMIC External Wakeup Pin

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupPol(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc,
                                             CSL_rtcWakeupEvtPol wakeupEvtPol)
{
    Uint32 regVal = 0U;

    /* Configure the polarity of external wakeup inputs */
    regVal = hRtc->RTC_PMIC_REG;
    regVal &= ~(((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_SHIFT));
    regVal |= (wakeupEvtPol << (extWakeupSrc + CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupClear
 *
 *   @b Description
 *   @n This API clears the PMIC External Wakeup Status
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured 'extWakeupSrc'
                        can take any of the values from following enum
                            - #CSL_rtcExtWakeupSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupClear(hRtc, extWakeupSrc);
                    // Clears the PMIC External Wakeup Status

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupClear(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc)
{
    Uint32 regVal = 0U;

    /* Clears the external wakeup pin status */
    regVal = hRtc->RTC_PMIC_REG;
    regVal |= (((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_STS_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcFeedbackResistorSel
 *
 *   @b Description
 *   @n This API selects the mode of the Oscillator Feedback resistor to either internal or external of the SOC.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          resistorSel   This specifies whether the Oscillator Feedback resistor
                        to be used should be either external or internal to the
                        SoC. 'resistorSel' can take one of the following two
                        values from the following enum
                            - #CSL_rtcFeedbackResistor
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_OSC;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcFeedbackResistorSel(hRtc, resistorSel);
                    // Select the mode of Oscillator Feedback resistor

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcFeedbackResistorSel(CSL_rtcHandle hRtc,
                                          CSL_rtcFeedbackResistor resistorSel)
{
    /* Select the Feedback resistor type to either external or internal */
    CSL_FINS(hRtc->OSC, RTC_OSC_RES_SELECT, resistorSel);
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupDebounceEnable
 *
 *   @b Description
 *   @n This API Enables the External Wakeup Debounce feature.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured 'extWakeupSrc'
                        can take any of the values from following enum
                            - #CSL_rtcExtWakeupSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupDebounceEnable(hRtc, extWakeupSrc);
                    // Enable the External Wakeup Debounce

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupDebounceEnable(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc)
{
    Uint32 regVal = 0U;

    /* Enable external wakeup inputs */
    regVal = hRtc->RTC_PMIC_REG;
    regVal |= (((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcPmicExtWakeupDebounceDisable
 *
 *   @b Description
 *   @n This API Disables the External Wakeup Debounce feature.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          extWakeupSrc  The external Input pin to be configured 'extWakeupSrc'
                        can take any of the values from following enum
                            - #CSL_rtcExtWakeupSrc
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTC_PMIC_REG;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcPmicExtWakeupDebounceDisable(hRtc, extWakeupSrc);
                    // Disable the External Wakeup Debounce

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcPmicExtWakeupDebounceDisable(CSL_rtcHandle hRtc,
                                             CSL_rtcExtWakeupSrc extWakeupSrc)
{
    Uint32 regVal = 0U;

    /* Disable external wakeup inputs */
    regVal = hRtc->RTC_PMIC_REG;
    regVal &= ~(((uint32_t)0x1U) << (extWakeupSrc +
        CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_SHIFT));
    hRtc->RTC_PMIC_REG = regVal;
}

/** ============================================================================
 *   @n@b CSL_rtcSetDebounceTime
 *
 *   @b Description
 *   @n This API sets the debounce time for the RTC module.
 *
 *   @b Arguments
      @verbatim
          hRtc          The handle of the RTC module.
          debounceTime  The value to specify the debounce time.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_RTL_DEBOUNCE;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetDebounceTime(hRtc, debounceTime); // Set debounce time

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetDebounceTime(CSL_rtcHandle hRtc,
                                            Uint32 debounceTime)
{
    /* Set the Debounce Time */
    CSL_FINS(hRtc->RTL_DEBOUNCE, RTC_RTL_DEBOUNCE_DEBOUNCE_REG, debounceTime);
}

/** ============================================================================
 *   @n@b CSL_rtcTestModeEnable
 *
 *   @b Description
 *   @n This function is used to enable the MMU.
 *
 *   @b Arguments
      @verbatim
          hRtc           The handle of the RTC module.
          enableTestMode Value to specify enabling/disabling of the Test
                         Mode. 'enableTestMode' can take one of the following values:
                            - TRUE to enable a Test mode of the RTC
                            - FALSE to disable Test mode and switch back to functional mode.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcTestModeEnable(hRtc, enableTestMode); // Enable the test mode

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcTestModeEnable(CSL_rtcHandle hRtc,
                                           Uint32 enableTestMode)
{
    if(TRUE == enableTestMode)
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_TEST_MODE, ((uint32_t)0x1U));
    }
    else
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_TEST_MODE, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcCompensationEnable
 *
 *   @b Description
 *   @n This API is used to Enable/Disable Crystal Compensation feature
        to account for any inaccuracy in 32K oscillator.
 *
 *   @b Arguments
      @verbatim
          hRtc                The handle of the RTC module.
          enableCompensation  Value to specify enabling/disabling of the Test
                              Mode. 'enableCompensation' can take one of the
                              following values:
                                - TRUE to enable oscillator compensation feature
                                - FALSE to disable oscillator compensation feature
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_CTRL;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcCompensationEnable(hRtc, enableCompensation); // Enable compensation

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcCompensationEnable(CSL_rtcHandle hRtc,
                                               Uint32 enableCompensation)
{
    if(TRUE == enableCompensation)
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_AUTO_COMP, ((uint32_t)0x1U));
    }
    else
    {
        CSL_FINS(hRtc->CTRL, RTC_CTRL_AUTO_COMP, ((uint32_t)0x0U));
    }
}

/** ============================================================================
 *   @n@b CSL_rtcSetCompensationVal
 *
 *   @b Description
 *   @n This function sets the compensation registers with the
        specified drift compensation value versus one hour period of the
        oscillator frequency.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
          compVal    The drift compensation value.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CSL_RTC_COMP_LSB;
 *   @n CSL_RTC_COMP_MSB;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcSetCompensationVal(hRtc, compVal); // Set compensation value

     @endverbatim
 * =============================================================================
 */
static inline void CSL_rtcSetCompensationVal(CSL_rtcHandle hRtc, Int32 compVal)
{
    Uint32 lsbVal = 0U;
    Uint32 msbVal = 0U;
    uint32_t tempVal = (uint32_t)compVal;

    /* Get the 2's complement Value of the compensation value. */
    tempVal = ~(tempVal);
    compVal = (int32_t)(tempVal) + 1;

    lsbVal = (((uint32_t)compVal) & CSL_RTC_COMP_LSB_RTC_COMP_LSB_MASK);
    msbVal = ((((uint32_t)compVal) >> CSL_RTC_COMP_MSB_RTC_COMP_MSB_SHIFT) &
                 CSL_RTC_COMP_MSB_RTC_COMP_MSB_MASK);

    /* Poll the status register flag until the BUSY bit equals zero */
    CSL_RTC_WAIT_FOR_WRITE

    /* Set the compensation value to account for oscillator drift. */
    hRtc->COMP_LSB = lsbVal;
    hRtc->COMP_MSB = msbVal;
}

/** ============================================================================
 *   @n@b CSL_rtcGetCompensationVal
 *
 *   @b Description
 *   @n This function reads the compensation value being set in the compensation registers.
 *
 *   @b Arguments
      @verbatim
          hRtc       The handle of the RTC module.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CSL_RTC_COMP_LSB;
 *   @n CSL_RTC_COMP_MSB;
 *
 *   @b Example
 *   @verbatim

        CSL_rtcGetCompensationVal(hRtc); // Read compensation value

     @endverbatim
 * =============================================================================
 */
static inline Int32 CSL_rtcGetCompensationVal(CSL_rtcHandle hRtc)
{
    Uint32 lsbVal = 0U;
    Uint32 msbVal = 0U;
    Int32 compVal = 0;
    uint32_t tempVal = 0U;

    lsbVal = hRtc->COMP_LSB;
    msbVal = hRtc->COMP_MSB;

    msbVal = ((msbVal << CSL_RTC_COMP_MSB_RTC_COMP_MSB_SHIFT) &
                CSL_RTC_COMP_MSB_RTC_COMP_MSB_MASK);
    tempVal = (msbVal | lsbVal);
    tempVal = ~(tempVal);

    compVal = (int32_t)(tempVal) + 1;

    return compVal;
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /*CSL_RTCAUX_H*/
