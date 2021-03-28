/**
 *   @file  csl_wdtAux.h
 *
 *   @brief
 *      This is the WDT Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the WDT Module.
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

#ifndef CSL_WDTAUX_H_
#define CSL_WDTAUX_H_

#include <ti/csl/csl_wdt.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
* global macro declarations
\******************************************************************************/

/** @addtogroup CSL_WDTAUX_ENUM
 @{ */

/**
@}
*/

/** @addtogroup CSL_WDTAUX_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_wdtGetRevision
 *
 *   @b Description
 *   @n This API shall enable the user to read the revision number of WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtGetRevision(hWdt); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_wdtGetRevision(CSL_wdtHandle hWdt)
{
    /* Read the Revision number. */
    return(hWdt->WIDR);
}

/** ============================================================================
 *   @n@b CSL_wdtReset
 *
 *   @b Description
 *   @n This API shall perform a soft reset of the WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtReset(hWdt); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtReset(CSL_wdtHandle hWdt)
{
    /* Reset the WDT module. */
    CSL_FINS(hWdt->WDSC, WDT_WDSC_SOFTRESET, 0x1U);

    /* Wait until the reset is done */
    while(1U != (hWdt->WDST & 0x1U));
}

/** ============================================================================
 *   @n@b CSL_wdtEnable
 *
 *   @b Description
 *   @n This API shall enable(start)/disable(stop) the WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtEnable(hWdt, enableWdt); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtEnable(CSL_wdtHandle hWdt, Uint32 enableWdt)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WSPR);

    if (TRUE == enableWdt)
    {
        /* Enable the WDT module. Sequence 1 is initiated. */
        CSL_FINS(hWdt->WSPR, WDT_WSPR_WSPR_VALUE, CSL_WDT_ENABLE_SEQ1);

        /* Wait for previous write to complete. */
        CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WSPR);

        /* Enable the WDT module. Sequence 2 is initiated. */
        CSL_FINS(hWdt->WSPR, WDT_WSPR_WSPR_VALUE, CSL_WDT_ENABLE_SEQ2);
    }
    else
    {
        /* Disable the WDT module. Sequence 1 is initiated. */
        CSL_FINS(hWdt->WSPR, WDT_WSPR_WSPR_VALUE, CSL_WDT_DISABLE_SEQ1);

        /* Wait for previous write to complete. */
        CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WSPR);

        /* Disable the WDT module. Sequence 2 is initiated. */
        CSL_FINS(hWdt->WSPR, WDT_WSPR_WSPR_VALUE, CSL_WDT_DISABLE_SEQ2);
    }
}

/** ============================================================================
 *   @n@b CSL_wdtPrescalerClkEnable
 *
 *   @b Description
 *   @n This API shall enable and configure the WDT prescaler clock value.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtPrescalerClkEnable(hWdt, prescaler); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtPrescalerClkEnable(CSL_wdtHandle hWdt, Uint32 prescaler)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WCLR);

    /* Enable the prescaler for WDT. */
    CSL_FINS(hWdt->WCLR, WDT_WCLR_PRE, 0x1U);

    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WCLR);

    /* Configure the prescaler value. */
    CSL_FINS(hWdt->WCLR, WDT_WCLR_PTV, prescaler);
}

/** ============================================================================
 *   @n@b CSL_wdtPrescalerClkDisable
 *
 *   @b Description
 *   @n This API shall disable the WDT prescaler clock.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtPrescalerClkDisable(hWdt); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtPrescalerClkDisable(CSL_wdtHandle hWdt)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WCLR);

    /* Disable the prescaler for WDT. */
    CSL_FINS(hWdt->WCLR, WDT_WCLR_PRE, 0x0U);
}

/** ============================================================================
 *   @n@b CSL_wdtSetCounter
 *
 *   @b Description
 *   @n Set the WDT counter value. When the WDT is started/enabled
        the count will start from the current value present in the
        counter. This API shall program the counter value.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtSetCounter(hWdt, cntrVal); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtSetCounter(CSL_wdtHandle hWdt, Uint32 cntrVal)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WCRR);

    /* Program the WDT counter value. */
    hWdt->WCRR = cntrVal;
}

/** ============================================================================
 *   @n@b CSL_wdtGetCounter
 *
 *   @b Description
 *   @n This function sets the WDT reload value.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtGetCounter(hWdt); // Set the WDT reload value.

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_wdtGetCounter(CSL_wdtHandle hWdt)
{
    /* Read the WDT counter value. */
    return(hWdt->WCRR);
}

/** ============================================================================
 *   @n@b CSL_wdtSetReloadVal
 *
 *   @b Description
 *   @n This function is used to enable the MMU.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
          reloadVal           WDT reload value.
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

        CSL_wdtSetReloadVal(hWdt, reloadVal); // Enable the MMU

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtSetReloadVal(CSL_wdtHandle hWdt, Uint32 reloadVal)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WLDR);

    /* Program the WDT counter value. */
    hWdt->WLDR = reloadVal;
}

/** ============================================================================
 *   @n@b CSL_wdtGetReloadVal
 *
 *   @b Description
 *   @n This API shall enable the user to read the WDT reload value.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtGetReloadVal(hWdt); // Read the WDT reload value

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_WDTGetReloadVal(CSL_wdtHandle hWdt)
{
    /* Read the WDT reload value. */
    return(hWdt->WLDR);
}

/** ============================================================================
 *   @n@b CSL_wdtTriggerReload
 *
 *   @b Description
 *   @n This API enables the trigger feature of WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt              The handle of the WDT module.
          trigVal           Trigger value to be programmed.
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

        CSL_wdtTriggerReload(hWdt, trigVal); // Enable trigger

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtTriggerReload(CSL_wdtHandle hWdt, Uint32 trigVal)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WTGR);

    /* Program the WDT trigger register. */
    hWdt->WTGR = trigVal;
}

/** ============================================================================
 *   @n@b CSL_wdtSetDelayVal
 *
 *   @b Description
 *   @n This API sets the WDT delay value.
 *
 *   @b Arguments
      @verbatim
          hWdt             The handle of the WDT module.
          delayVal         Delay value to be programmed.
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

        CSL_wdtSetDelayVal(hWdt, delayVal); // Sets the WDT delay value

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtSetDelayVal(CSL_wdtHandle hWdt, Uint32 delayVal)
{
    /* Wait for previous write to complete. */
    CSL_WDT_WAIT_FOR_WRITE(CSL_WDT_WRITE_POST_WDLY);

    /* Program the WDT delay register. */
    hWdt->WDLY = delayVal;
}

/** ============================================================================
 *   @n@b CSL_wdtGetDelayVal
 *
 *   @b Description
 *   @n This API shall enable the user to read the Delay value.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtGetDelayVal(hWdt); // Read the Delay value

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_wdtGetDelayVal(CSL_wdtHandle hWdt)
{
    /* Read the WDT delay register value. */
    return(hWdt->WDLY);
}

/** ============================================================================
 *   @n@b CSL_wdtIntrTrigger
 *
 *   @b Description
 *   @n This API triggers an interrupt request for the specified event.
 *
 *   @b Arguments
      @verbatim
          hWdt           The handle of the WDT module.
          intrMask       Interrupts to be triggered. intrMask will contain
                         values from the following enum.
                            -#CSL_wdtIntrMask
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

        CSL_wdtIntrTrigger(hWdt, intrMask); // Triggers an interrupt request

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtIntrTrigger(CSL_wdtHandle hWdt,
                                        CSL_wdtIntrMask intrMask)
{
    /* Trigger the raw interrupt. */
    hWdt->WIRQSTATRAW = intrMask;
}

/** ============================================================================
 *   @n@b CSL_wdtIntrRawStatus
 *
 *   @b Description
 *   @n This API reads the raw interrupt status of WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtIntrRawStatus(hWdt); // Reads the raw interrupt status

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_wdtIntrRawStatus(CSL_wdtHandle hWdt)
{
    /* Read the interrupt raw status. */
    return(hWdt->WIRQSTATRAW);
}

/** ============================================================================
 *   @n@b CSL_wdtIntrStatus
 *
 *   @b Description
 *   @n This API reads the interrupt status of WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt                The handle of the WDT module.
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

        CSL_wdtIntrStatus(hWdt); // Reads the raw interrupt status

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_wdtIntrStatus(CSL_wdtHandle hWdt)
{
    /* Read the interrupt status. */
    return(hWdt->WISR);
}

/** ============================================================================
 *   @n@b CSL_wdtIntrClear
 *
 *   @b Description
 *   @n This API clears the WDT interrupts.
 *
 *   @b Arguments
      @verbatim
          hWdt           The handle of the WDT module.
          intrMask       Interrupts to be triggered. intrMask will contain
                         values from the following enum.
                            -#CSL_wdtIntrMask
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

        CSL_wdtIntrClear(hWdt, intrMask); // Clear interrupt status

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtIntrClear(CSL_wdtHandle hWdt,
                                      CSL_wdtIntrMask intrMask)
{
    /* Clear the interrupt status. */
    hWdt->WIRQSTAT = intrMask;
}

/** ============================================================================
 *   @n@b CSL_wdtIntrEnable
 *
 *   @b Description
 *   @n This API enables the WDT interrupts.
 *
 *   @b Arguments
      @verbatim
          hWdt           The handle of the WDT module.
          intrMask       Interrupts to be triggered. intrMask will contain
                         values from the following enum.
                            -#CSL_wdtIntrMask
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

        CSL_wdtIntrEnable(hWdt, intrMask); // Enable interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtIntrEnable(CSL_wdtHandle hWdt,
                                       CSL_wdtIntrMask intrMask)
{
    /* Enable the WDT interrupts. */
    hWdt->WIRQENSET = intrMask;
}

/** ============================================================================
 *   @n@b CSL_wdtIntrDisable
 *
 *   @b Description
 *   @n This API disables the WDT interrupts.
 *
 *   @b Arguments
      @verbatim
          hWdt           The handle of the WDT module.
          intrMask       Interrupts to be triggered. intrMask will contain
                         values from the following enum.
                            -#CSL_wdtIntrMask
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

        CSL_wdtIntrDisable(hWdt, intrMask); // Disable interrupt

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtIntrDisable(CSL_wdtHandle hWdt,
                                        CSL_wdtIntrMask intrMask)
{
    /* Disable the WDT interrupts. */
    hWdt->WIRQENCLR = intrMask;
}

/** ============================================================================
 *   @n@b CSL_wdtSetIdleMode
 *
 *   @b Description
 *   @n This API configures one of the idle modes.
 *
 *   @b Arguments
      @verbatim
          hWdt             The handle of the WDT module.
          idleMode         Value to determine idle mode selection idleMode can
                           take macros from the following enum
                            - #CSL_wdtIdleMode
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

        CSL_wdtSetIdleMode(hWdt, idleMode); // Configure idle mode

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtSetIdleMode(CSL_wdtHandle hWdt,
                                        CSL_wdtIdleMode idleMode)
{
    /* Configure the Idle mode of WDT. */
    CSL_FINS(hWdt->WDSC, WDT_WDSC_IDLEMODE, idleMode);
}

/** ============================================================================
 *   @n@b CSL_wdtEmuModeEnable
 *
 *   @b Description
 *   @n This API enable/disable emulation mode of WDT.
 *
 *   @b Arguments
      @verbatim
          hWdt              The handle of the WDT module.
          enableEmuMode     Enable/disable the emulation mode.
                            enableEmuMode will take the following values.
                                -# TRUE - Enable emulation mode.
                                -# FALSE - Disable emulation mode.

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

        CSL_wdtEmuModeEnable(hWdt, enableEmuMode); // Enable/Disable emulation

     @endverbatim
 * =============================================================================
 */
static inline void CSL_wdtEmuModeEnable(CSL_wdtHandle hWdt, Uint32 enableEmuMode)
{
    if (TRUE == enableEmuMode)
    {
        /* Counter is frozen during emulation. */
        CSL_FINS(hWdt->WDSC, WDT_WDSC_EMUFREE, 0x0U);
    }
    else
    {
        /* Counter is free running during emulation. */
        CSL_FINS(hWdt->WDSC, WDT_WDSC_EMUFREE, 0x1U);
    }
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /*CSL_WDTAUX_H_*/
