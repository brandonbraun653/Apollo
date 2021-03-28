/*
 *   Copyright (c) Texas Instruments Incorporated 2015
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
 *  \ingroup CSL_IP_MODULE
 *  \defgroup CSL_RTI RTI
 *
 *  @{
 */
/**
 *  \file     rti.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of RTI.
 *            This also contains some related macros.
 *
 */

/**
 * \anchor CSL_RTIOverview
 * \name   RTI DWD Overview
 */

/**
 *   \details
 *   \verbatim
 *         Digital Windowed Watchdog(DWWD) Overview :
 *         The Digital Watchdog Timer(DWT) generates reset after a programmable
 *         period, if not serviced within that period. In DWT, time-out
 *         boundary is configurable.
 *         In DWWD, along with configurable time-out boundary, the start time
 *         boundary is also configurable. The DWWD can generate Reset or
 *         Interrupt, if not serviced within window(Open Window) defined by
 *         start time and time-out boundary. Also the DWWD can generate Reset or
 *         Interrupt if serviced outside Open Window (within Closed Window).
 *         Generation of Reset or Interrupt depends on the DWWD Reaction
 *         configuration.
 *
 *          DWWD Window Sizes Overview :
 *          time-out value...........................................3 2 1 0
 *    (100%)|___________________________Open Window________________________|
 *     (50%)|         Closed Window         |________Open Window___________|
 *     (25%)|            Closed Window                      |___OW_________|
 *   (12.5%)|                 Closed Window                         |_OW___|
 *   (6.25%)|                     Closed Window                         |OW|
 *  (3.125%)|                         Closed Window                      |O|
 *                                                                       |W|
 *         For time-out value calculation refer DWWD Down Counter Overview.
 *         DWWD Down Counter Overview :
 *         24............................................2 1 0
 *         |                25 bit down counter              |
 *         |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
 *         |  12 bit preload value |1|1|1|1|1|1|1|1|1|1|1|1|1|
 *         |-----------------------|-|-|-|-|-|-|-|-|-|-|-|-|-|
 *         Upper 12 bit part of the down counter is configurable and
 *         remaining 13 bit are always 1.
 *         Minimum possible time-out value is 2^13 RTI clock cycles.
 *         Maximum possible time-out value is 2^25 RTI clock cycles.
 *         Example :
 *         RTI frequency : 32kHz
 *         12 bit preload value : 0x004
 *         25 bit preload value : 0x0009FFF
 *         time-out value(in RTI clock cycles) : 40959.
 *         time-out value(in seconds) : 40959 / 32000 = 1.26859375 seconds.
 *
 *   \endverbatim
 */


#ifndef RTI_H_
#define RTI_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/cslr_rti.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/**
 * \anchor CSL_RTIPreloadValues
 * \name   RTI DWD Preload Value Ranges
 */
/**
 * \brief  Minimum possible preload value for RTI DWD counter (2^13).
 */
#define RTI_DWD_MIN_PRELOAD_VAL             (0x1FFFU)
/**
 * \brief  Maximum possible preload value for RTI DWD counter(2^25).
 */
#define RTI_DWD_MAX_PRELOAD_VAL             (0x1FFFFFFU)

/**
* \anchor CSL_RTIReactionValues
* \name   RTI DWD possible Reaction Values
*/

/**
 * \brief  macro to select the DWWD reaction after violation or
 *         expiration of DWWD timer.
 *
 *         DWWD can either generate reset or interrupt.
 */
#define    RTI_DWWD_REACTION_GENERATE_RESET  (RTI_RTIDWWDRXNCTRL_DWWDRXN_RESET)
    /**< Configure DWWD reaction to generate reset */
#define    RTI_DWWD_REACTION_GENERATE_NMI    (RTI_RTIDWWDRXNCTRL_DWWDRXN_INTERRUPT)
    /**< Configure DWWD reaction to generate
     * interrupt. The actual interrupt
     * used depends on the SOC and cross bar
     * mapping. */

/**
 * \brief  type to select the DWWD reaction after violation or
 *         expiration of DWWD timer.
 *         DWWD can either generate reset or interrupt.
 */
typedef uint32_t rtiDwwdReaction_t;

/**
* \anchor CSL_RTIWinSizeValues
* \name   RTI DWD possible Window Size Values
*/

#define    RTI_DWWD_WINDOWSIZE_100_PERCENT      (RTI_RTIDWWDSIZECTRL_DWWDSIZE_100_PERCENT)
    /**< Configure DWWD window size to 100% */
#define    RTI_DWWD_WINDOWSIZE_50_PERCENT       (RTI_RTIDWWDSIZECTRL_DWWDSIZE_50_PERCENT)
    /**< Configure DWWD window size to 50% */
#define    RTI_DWWD_WINDOWSIZE_25_PERCENT       (RTI_RTIDWWDSIZECTRL_DWWDSIZE_25_PERCENT)
    /**< Configure DWWD window size to 25% */
#define    RTI_DWWD_WINDOWSIZE_12_5_PERCENT     (RTI_RTIDWWDSIZECTRL_DWWDSIZE_12_5_PERCENT)
    /**< Configure DWWD window size to 12.5`% */
#define    RTI_DWWD_WINDOWSIZE_6_25_PERCENT     (RTI_RTIDWWDSIZECTRL_DWWDSIZE_6_25_PERCENT)
    /**< Configure DWWD window size to 6.25% */
#define    RTI_DWWD_WINDOWSIZE_3_125_PERCENT    (RTI_RTIDWWDSIZECTRL_DWWDSIZE_3_125_PERCENT)
    /**< Configure DWWD window size to 3.125% */

/**
 * \brief  type to select the DWWD window size.
 *
 *         Window Size : In what percentage of time-out value i.e open window,
 *         servicing DWWD is allowed.
 *         Configurable Window Sizes : 100%, 50%, 25%, 12.5%, 6.25%, 3.125%.
 *         Refer to for DWWD Window Sizes Overview.
 */
typedef uint32_t rtiDwwdWindowSize_t;

/**
* \anchor CSL_RTIDWWDStatusValues
* \name   RTI DWD possible Status Values
*/

#define    RTI_DWWD_STATUS_KEY_SEQ_VIOLATION          (RTI_RTIWDSTATUS_KEYST_MASK)
    /**< Key sequence violation mask */
#define    RTI_DWWD_STATUS_TIME_WINDOW_VIOLATION      (RTI_RTIWDSTATUS_DWWD_ST_MASK)
    /**< Window violation mask */
#define    RTI_DWWD_STATUS_ENDTIME_WINDOW_VIOLATION   (RTI_RTIWDSTATUS_END_TIME_VIOL_MASK)
    /**< End time window violation mask */
#define    RTI_DWWD_STATUS_STARTTIME_WINDOW_VIOLATION (RTI_RTIWDSTATUS_START_TIME_VIOL_MASK)
    /**< End time window violation mask */
#define    RTI_DWWD_STATUS_LAST_RESET                 (RTI_RTIWDSTATUS_DWDST_MASK)
    /**< DWWD last reset status mask */

/**
 * \brief  type to report the DWWD status.
 *
 *         Violations(Following bit-field will get set) :
 *         DWWD Status : If last reset is generated by DWWD.
 *         Key sequence violation : If wrong sequence is written to enable DWWD.
 *         Start Time Violation : If DWWD is serviced within closed window.
 *         End Time Violation : If DWWD is not serviced.
 *         Time Window Violation : If any of Start/End Time Violation happened.
 */
typedef uint32_t rtiDwwdStatus_t;

/**
* \anchor CSL_RTIDWWDResetStatusValues
* \name   RTI DWD possible Reset Status Values
*/

/**
 * \brief  macro to get the status of last reset.
 */
#define    RTI_DWWD_RESET_STATUS_GENERATED       (0U)
    /**< Last reset is generated by DWWD */
#define    RTI_DWWD_RESET_STATUS_NOT_GENERATED   (1U)
    /**< Last reset is not generated by DWWD */

/**
 * \brief  type to get the status of last reset.
 */
typedef uint32_t rtiDwwdResetStatus_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */
/**
* \anchor CSL_RTIDWWDStaticRegs
* \name   RTI DWD Static Register Set
*/

/**
 * \brief  List of Static Registers for RTI DWWD
 */
typedef struct rtiDwwdStaticRegs_s
{
    /** RTI DWD Control register */
    uint32_t    RTI_DWDCTRL;
    /** RTI DWD Preload register */
    uint32_t    RTI_DWDPRLD;
    /** RTI DWD Reaction Control register */
    uint32_t    RTI_WWDRXNCTRL;
    /** RTI DWD Window Size Control */
    uint32_t    RTI_WWDSIZECTRL;
} rtiDwwdStaticRegs_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
* \anchor CSL_RTIDWDFunctions
* \name   RTI DWD Function Declarations
*/
/**
 * \brief   Configure DWWD before enabling.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   dwwdReaction    DWWD reaction for violation/expiration.
 *                          Values given by macro #rtiDwwdReaction_t
 *
 * \param   dwwdPreloadVal  Down counter preload value. This preload value is
 *                          time-out period in terms of number of clock cycles
 *                          of RTI clock source. This is 25 bit value
 *                          in the range 0x1FFFU to 0x1FFFFFFU.
 *                          - Refer DWWD Down Counter Overview.
 *
 * \param   dwwdWindowSize  DWWD window size
 *                          Values given by macro #rtiDwwdWindowSize_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdWindowConfig(uint32_t baseAddr,
                            uint32_t dwwdReaction,
                            uint32_t dwwdPreloadVal,
                            uint32_t dwwdWindowSize);

/**
 * \brief   Verify the window Configure DWWD before enabling.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   dwwdReaction    DWWD reaction for violation/expiration.
 *                          Values given by macro #rtiDwwdReaction_t
 *
 * \param   dwwdPreloadVal  Down counter preload value. This preload value is
 *                          time-out period in terms of number of clock cycles
 *                          of RTI clock source. This is 25 bit value
 *                          in the range 0x1FFFU to 0x1FFFFFFU.
 *                          - Refer DWWD Down Counter Overview.
 *
 * \param   dwwdWindowSize  DWWD window size
 *                          Values given by macro #rtiDwwdWindowSize_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdWindowVerifyConfig(uint32_t baseAddr,
                                  uint32_t dwwdReaction,
                                  uint32_t dwwdPreloadVal,
                                  uint32_t dwwdWindowSize);

/**
 * \brief   Enable DWWD down counter
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 *
 * \note    This API should be called after configuration of DWWD Window.
 */

int32_t RTIDwwdCounterEnable(uint32_t baseAddr);

/**
 * \brief   Check if DWWD down counter was enabled
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param  pIsCounterEnabled  pointer to status of counter enabled
 *                         - TRUE if counter is enabled.
 *                         - FALSE if counter is not enabled.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 * \note    This API should be called after configuration of DWWD Window.
 */

int32_t RTIDwwdIsCounterEnabled(uint32_t baseAddr, uint32_t *pIsCounterEnabled);

/**
 * \brief   Service DWWD.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdService(uint32_t baseAddr);

/**
 * \brief   Get DWWD Reset status.
 *          Last reset is generated by DWWD or not.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 * \param   pResetStatus    Pointer to Reset Status
 *                              Values given by macro #rtiDwwdResetStatus_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdGetLastResetStatus(uint32_t baseAddr, rtiDwwdResetStatus_t *pResetStatus);

/**
 * \brief   Set DWWD preload value.
 *          From this value down counter starts down counting.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   dwwdPreloadVal  Down counter preload value.
 *                          Refer DWWD Down Counter Overview.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdSetPreload(uint32_t baseAddr, uint32_t dwwdPreloadVal);

/**
 * \brief   Set DWWD reaction.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   dwwdReaction   DWWD reaction for violation/expiration.
 *                         Values given by macro #rtiDwwdReaction_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 * \note:   1. DWWD need to be serviced if Reaction is changed when DWWD is
 *          enabled and Window is Open,to take immediate effect. If not
 *          serviced, DWWD will generated previously configured Reaction
 *          irrespective of current configuration.
 *          2. If DWWD is enabled and Window is Close then any change in
 *          Reaction will take immediate effect. DWWD need not to be serviced
 *          in this case.
 */
int32_t RTIDwwdSetReaction(uint32_t baseAddr, rtiDwwdReaction_t dwwdReaction);

/**
 * \brief   Set DWWD Window Size.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   dwwdWindowSize  DWWD Window Size.
 *                          Values given by macro #rtiDwwdWindowSize_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 * \note:   1. DWWD need to be serviced if Window Size is changed when DWWD is
 *          enabled and Window is Open,to take immediate effect. If not
 *          serviced, DWWD Window Size will not be changed
 *          irrespective of current configuration.
 *          2. If DWWD is enabled and Window is Close then any change in
 *          Window Size will take immediate effect. DWWD need not to be serviced
 *          in this case.
 */
int32_t RTIDwwdSetWindowSize(uint32_t baseAddr, rtiDwwdWindowSize_t dwwdWindowSize);

/**
 * \brief   Check for Closed Window.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pWinStatus      pointer to Closed Window Status
 *                          TRUE if Window is Closed. FALSE if Window is Open.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdIsClosedWindow(uint32_t baseAddr, uint32_t *pWinStatus);

/**
 * \brief   Generate forced system reset/interrupt.
 *          Depends upon DWWD reaction what to generate
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdGenerateSysReset(uint32_t baseAddr);

/**
 * \brief   Get DWWD status.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pDWWDStatus     pointer to DWWD status. Refer macro #rtiDwwdStatus_t for
 *                          possible bitwise or of all return values.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdGetStatus(uint32_t baseAddr, rtiDwwdStatus_t *pDWWDStatus);

/**
 * \brief   Clear DWWD status.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   status          Violation status to clear.
 *                          Values given by bitwise or of macro #rtiDwwdStatus_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 */
int32_t RTIDwwdClearStatus(uint32_t baseAddr, rtiDwwdStatus_t status);

/**
 * \brief   Get current value of DWWD down counter.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pCurDownCntVal  pointer to current down counter value
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdGetCurrentDownCounter(uint32_t baseAddr, uint32_t *pCurDownCntVal);

/**
 * \brief   Check for correct sequence write to DWWD key Register.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pKeySeqStatus   Pointer to RTI key sequence status.
 *                          - Incorrect Key: RTI_RTIWDSTATUS_KEYST_INCORRECT_KEY
 *                          - Correct Key: RTI_RTIWDSTATUS_KEYST_CORRECT_KEY
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIIsDwwdKeySequenceCorrect(uint32_t baseAddr, uint32_t *pKeySeqStatus);

/**
 * \brief   This API will return current configured Preload value.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pCurPreload     pointer to current preload value
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdGetPreload(uint32_t baseAddr, uint32_t *pCurPreload);

/**
 * \brief   This API will return current configured Window Size.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pWindowSize     pointer to Configured Window Size.
 *                          Refer macro #rtiDwwdWindowSize_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdGetWindowSize(uint32_t baseAddr, rtiDwwdWindowSize_t *pWindowSize);

/**
 * \brief   This API will return current configured time out
 *          (number of clock cycles of RTI clock) value.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pTimeOut        pointer to Configured time out value.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdGetTimeOut(uint32_t baseAddr, uint32_t *pTimeOut);

/**
 * \brief   This API will return current configured Reaction.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pReaction       pointer to Configured Reaction.
 *                          Refer macro #rtiDwwdReaction_t
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTIDwwdGetReaction(uint32_t baseAddr, rtiDwwdReaction_t *pReaction);

/**
 * \brief   This API returns the number of clock cycles of RTI clock remaining
 *          for the Window to Open.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pClockCycles    Pointer to Clock cycles remaining for Open Window.
 *                          Returns '0' if Window is already Open.
 *
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 * \note    Number of clock cycles returned by this API may differ from actual
 *          clock cycles needed for Window to open, User should also check
 *          if window is open or not before doing any further operation.
 *          For this purpose user can use RTIDwwdIsClosedWindow() API.
 */
int32_t RTIDwwdGetTicksToOpenWindow(uint32_t baseAddr, uint32_t *pClockCycles);

/**
 * \brief   This API returns the static registers for RTI-DWWD.
 *
 * \param   baseAddr        Base Address of the RTI instance.
 *
 * \param   pStaticRegs     Pointer to RTI DWWD Static Registers.
 *
 * \return  status          Success of the window configuration
 *                                - Success: CSL_PASS
 *                                - Fail   : CSL_EFAIL
 *
 */
int32_t RTI_DWWDReadStaticRegs(uint32_t baseAddr, rtiDwwdStaticRegs_t *pStaticRegs);

#ifdef __cplusplus
}
#endif

#endif /* RTI_H_ */
 /** @} */
