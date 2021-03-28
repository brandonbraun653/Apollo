/**
 *   @file  csl_tsipAux.h
 *
 *   @brief   
 *      This is the TSIP Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the TSIP Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2008, 2009, 2018, Texas Instruments, Inc.
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

#ifndef CSL_TSIPAUX_H_
#define CSL_TSIPAUX_H_

#include <ti/csl/csl_tsip.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_TSIP_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_tsipGetPid 
 *
 *   @b Description
 *   @n This function returns the PID of TSIP module.
 *
 *   @b Arguments
 *   @verbatim
            hTsip          Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  The Module ID Version Information.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_MOD_VER_REVISION
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint16              modId;
        Uint16              majorRev;
        Uint16              minorRev;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the TSIP Module PID Information.
        CSL_tsipGetPid(hTsip, &pidInfo);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_tsipGetPid (CSL_TsipHandle  hTsip)
{
    /* Read from the PID */
    return (Uint32)CSL_FEXT(hTsip->MOD_VER, TSIP_MOD_VER_REVISION);
}


/** ============================================================================
 *   @n@b CSL_tsipEmutstSetTestMode
 *
 *   @b Description
 *   @n This function sets the test mode for the TSIP.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            testMode        Flag which determines the test mode; set to TRUE for 
                            test mode else FALSE implies normal operating mode.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_EMU_TST_SIUTST
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Enable the test mode for TSIP.
        CSL_tsipEmutstSetTestMode(hTsip, TRUE);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipEmutstSetTestMode (CSL_TsipHandle hTsip, Bool testMode)
{
    /* Set the clock redundancy mode. */
    if (testMode == TRUE)
        CSL_FINS(hTsip->EMU_TST, TSIP_EMU_TST_SIUTST, 1);
    else
        CSL_FINS(hTsip->EMU_TST, TSIP_EMU_TST_SIUTST, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipEmutstSelectTestMode
 *
 *   @b Description
 *   @n This function selects the test mode for the TSIP.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            testModeSelect  Flag which selects the test mode; set to 1 for internal
                            link loopback else 0 for external data loopback.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_EMU_TST_LBS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Enable the test mode for TSIP.
        CSL_tsipEmutstSelectTestMode(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipEmutstSelectTestMode (CSL_TsipHandle hTsip, Bool testModeSelect)
{
    /* Set the clock redundancy mode. */
    if (testModeSelect == CSL_TSIP_TESTMODE_LINK_LOOPBACK)
        CSL_FINS(hTsip->EMU_TST, TSIP_EMU_TST_LBS, CSL_TSIP_TESTMODE_LINK_LOOPBACK);
    else
        CSL_FINS(hTsip->EMU_TST, TSIP_EMU_TST_LBS, CSL_TSIP_TESTMODE_DATA_LOOPBACK);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipResetSIU 
 *
 *   @b Description
 *   @n This function resets the Serial Interface Unit of the TSIP Module.
 *
 *   @b Arguments
 *   @verbatim
            hTsip          Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RESET_SIURST
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Reset the Serial Interface Unit for TSIP Module 0.
        CSL_tsipResetSIU(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipResetSIU (CSL_TsipHandle hTsip)
{
    /* Reset the SIU */
    CSL_FINS(hTsip->RESET, TSIP_RESET_SIURST, 1);

    /* Wait for the reset to complete. */
    while (CSL_FEXT(hTsip->RESET, TSIP_RESET_SIURST) == 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipResetTDMU_DMATCU 
 *
 *   @b Description
 *   @n This function resets the Timeslot Data Management Unit (TDMU)and the 
 *      Direct Memory Access Transfer Control Unit (DMATCU) of the TSIP Module.
 *
 *   @b Arguments
 *   @verbatim
            hTsip          Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RESET_DMARST=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Reset the TDMU and DMATCU for TSIP Module 0.
        CSL_tsipResetTDMU_DMATCU(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipResetTDMU_DMATCU (CSL_TsipHandle hTsip)
{
    /* Reset the TDMU and DMATCU */
    CSL_FINS(hTsip->RESET, TSIP_RESET_DMARST, 1);

    /* Wait for the reset to complete. */
    while (CSL_FEXT(hTsip->RESET, TSIP_RESET_DMARST) == 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetClockRedundancy 
 *
 *   @b Description
 *   @n This function sets the SIU Clock Redundancy Mode for the SIU.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            dualClockMode   Flag which determines the clock mode; set to TRUE for DUAL Clock mode
                            else FALSE implies Redundant clock mode.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_GCTL_CLKD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the SIU Clock Redundancy Mode to operate in Dual Clock mode.
        CSL_tsipSIUSetClockRedundancy(hTsip, TRUE);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetClockRedundancy (CSL_TsipHandle hTsip, Bool dualClockMode)
{
    /* Set the clock redundancy mode. */
    if (dualClockMode == TRUE)
        CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_CLKD, 1);
    else
        CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_CLKD, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetClockRedundancy 
 *
 *   @b Description
 *   @n This function sets the SIU Clock Redundancy Mode for the SIU.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  TRUE  - Dual Clock Redundancy Mode
 *	 @n  FALSE - Redundant Clock Mode.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_GCTL_CLKD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Bool                clockMode;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the SIU Clock Redundancy Mode.
        clockMode = CSL_tsipSIUGetClockRedundancy(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipSIUGetClockRedundancy (CSL_TsipHandle hTsip)
{
    return (Bool)CSL_FEXT(hTsip->SIU_GCTL, TSIP_SIU_GCTL_CLKD);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUEnableReceive
 *
 *   @b Description
 *   @n This function enables the SIU receive
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_GCTL_RCVENB=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Enable the SIU Receive.
        CSL_tsipSIUEnableReceive(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUEnableReceive (CSL_TsipHandle hTsip)
{
    CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_RCVENB, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUDisableReceive
 *
 *   @b Description
 *   @n This function disables the SIU receive
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_GCTL_RCVENB=0
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Disable the SIU Receive.
        CSL_tsipSIUDisableReceive(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUDisableReceive (CSL_TsipHandle hTsip)
{
    CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_RCVENB, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUIsReceiveEnabled
 *
 *   @b Description
 *   @n This function checks if the SIU receive is enabled or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  TRUE  -   SIU Receive is enabled.
 *	 @n  FALSE -   SIU Receive is disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_GCTL_RCVENB
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Check if SIU receive is enabled or not?
        if (CSL_tsipSIUIsReceiveEnabled(hTsip) == TRUE)
        {
            // Receive is enabled.
        }
        else
        {
            // Receive is disabled.
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipSIUIsReceiveEnabled (CSL_TsipHandle hTsip)
{
    return (Bool)CSL_FEXT(hTsip->SIU_GCTL, TSIP_SIU_GCTL_RCVENB);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUEnableTransmit
 *
 *   @b Description
 *   @n This function enables the SIU transmit
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_GCTL_XMTENB=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Enable the SIU Transmit.
        CSL_tsipSIUEnableTransmit(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUEnableTransmit (CSL_TsipHandle hTsip)
{
    CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_XMTENB, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUDisableTransmit
 *
 *   @b Description
 *   @n This function disables the SIU transmit
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_GCTL_XMTENB=0
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Disable the SIU Transmit.
        CSL_tsipSIUDisableTransmit(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUDisableTransmit (CSL_TsipHandle hTsip)
{
    CSL_FINS(hTsip->SIU_GCTL, TSIP_SIU_GCTL_XMTENB, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUIsTransmitEnabled
 *
 *   @b Description
 *   @n This function checks if the SIU transmit is enabled or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  TRUE  -   SIU Transmit is enabled.
 *	 @n  FALSE -   SIU Transmit is disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_GCTL_XMTENB
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Check if SIU transmit is enabled or not?
        if (CSL_tsipSIUIsTransmitEnabled(hTsip) == TRUE)
        {
            // Transmit is enabled.
        }
        else
        {
            // Transmit is disabled.
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipSIUIsTransmitEnabled (CSL_TsipHandle hTsip)
{
    return (Bool)CSL_FEXT(hTsip->SIU_GCTL, TSIP_SIU_GCTL_XMTENB);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxClockSource
 *
 *   @b Description
 *   @n This function sets the SIU Transmit Clock Source.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            clockSource     Clock Source to be used for the SIU Transmit 
                            Value of 0 implies TCLK_A else TCLK_B
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTSEL_XMTSRC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the SIU Transmit Clock to use TCLK_B & TFS_B
        CSL_tsipSIUSetTxClockSource(hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxClockSource (CSL_TsipHandle hTsip, Uint8 clockSource)
{
    /* Use the clock source to configure the Transmit Clock Source register.*/
    if (clockSource == 0)
        CSL_FINS(hTsip->SIU_XMTSEL, TSIP_SIU_XMTSEL_XMTSRC, 0);
    else
        CSL_FINS(hTsip->SIU_XMTSEL, TSIP_SIU_XMTSEL_XMTSRC, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxClockSource
 *
 *   @b Description
 *   @n This function gets the SIU Transmit Clock Source.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  0  -   Implies Clock Source A
 *	 @n  1  -   Implies Clock Source B
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTSEL_XMTSRC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the SIU Transmit Clock Source
        if (CSL_tsipSIUGetTxClockSource(hTsip) == 1)
        {
            // Using Clock Source A
        }
        else
        {
            // Using Clock Source B
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxClockSource (CSL_TsipHandle hTsip)
{
    /* Get the clock source. */
    return (Uint8) CSL_FEXT(hTsip->SIU_XMTSEL, TSIP_SIU_XMTSEL_XMTSRC);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxDataDelay
 *
 *   @b Description
 *   @n This function sets the transmit data delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            txDataDelay     Transmit Data Delay to be configured.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTDATD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Data Delay to be 1023 (Single Rate 8Mbps serial link with 128 time slots)
        CSL_tsipSIUSetTxDataDelay (hTsip, 1023);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxDataDelay (CSL_TsipHandle hTsip, Uint16 txDataDelay)
{
    CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDATD, txDataDelay);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxDataDelay
 *
 *   @b Description
 *   @n This function gets the transmit data delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Data Delay configured.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTDATD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint16              txDataDelay;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Data Delay 
        txDataDelay = CSL_tsipSIUGetTxDataDelay (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_tsipSIUGetTxDataDelay (CSL_TsipHandle hTsip)
{
    return CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDATD);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxOutputDelay
 *
 *   @b Description
 *   @n This function sets the transmit output delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            txOutputDelay   Transmit Output Delay to be configured.
                            Value of 0 implies no added delay else the 
                            output enable is delayed by one-half serial clock 
                            period.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Output delay for no added delay. 
        CSL_tsipSIUSetTxOutputDelay (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxOutputDelay 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txOutputDelay
)
{
    /* Use the Transmit Output Delay to configure the Transmit Control Register. */
    if (txOutputDelay == 0)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDLY, 0);
    else
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDLY, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxOutputDelay
 *
 *   @b Description
 *   @n This function gets the transmit output delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n  0 - No added delay
 *   @n  1 - Output enable is delayed by one half serial clock period.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint16              txOutputDelay;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Output Delay 
        txOutputDelay = CSL_tsipSIUGetTxOutputDelay (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxOutputDelay (CSL_TsipHandle hTsip)
{
    return CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDLY);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxDisabledState
 *
 *   @b Description
 *   @n This function sets the transmit disabled state
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            txDisabledState     Transmit Disabled State
                                0 - High Impedance
                                1 - Driven Low
                                2 - Driven High
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTDIS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Disabled State for High Impedance
        CSL_tsipSIUSetTxDisabledState (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxDisabledState 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txDisabledState
)
{
    /* Use the Transmit Disabled State to configure the Transmit Control Register. */
    if (txDisabledState == 0)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDIS, 0);
    else if (txDisabledState == 1)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDIS, 2);
    else if (txDisabledState == 2)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDIS, 3);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxDisabledState
 *
 *   @b Description
 *   @n This function gets the transmit disabled state
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Disabled State
 *   @n 0 - High Impedance
 *   @n 1 - Driven Low
 *   @n 2 - Driven High
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTDIS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txDisabledState;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Disabled State
        txDisabledState = CSL_tsipSIUGetTxDisabledState (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxDisabledState (CSL_TsipHandle hTsip)
{
    Uint8   txDisabledState;

    /* Get the Transmit Disabled State and return appropriately. */
    txDisabledState = CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDIS);
    if (txDisabledState == 0)
        return 0;
    else if (txDisabledState == 2)
        return 1;
    else
        return 2;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxFrameSyncPolarity
 *
 *   @b Description
 *   @n This function sets the transmit frame sync polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
            txFrameSyncPolarity     Transmit Frame Sync Polarity to be configured.
                                    0   -   Active Low
                                    1   -   Active High
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTFSYNCP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Frame Sync Priority to be ACTIVE HIGH
        CSL_tsipSIUSetTxFrameSyncPolarity (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxFrameSyncPolarity 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txFrameSyncPolarity
)
{
    /* Use the Transmit Frame Sync Polarity to configure the Transmit Control Register. */
    if (txFrameSyncPolarity == 0)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFSYNCP, 0);
    else 
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFSYNCP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxFrameSyncPolarity
 *
 *   @b Description
 *   @n This function gets the transmit frame sync polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Frame Sync Polarity
 *   @n 0   -   Active Low
 *   @n 1   -   Active High
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTFSYNCP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txFrameSyncPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Frame Sync Priority.
        txFrameSyncPolarity = CSL_tsipSIUGetTxFrameSyncPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxFrameSyncPolarity (CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFSYNCP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxFrameSyncClockPolarity
 *
 *   @b Description
 *   @n This function sets the transmit frame sync clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
            txFrameSyncClkPolarity  Transmit Frame Sync Clock Polarity to be configured.
                                    0   -   Frame Sync is sample on rising edge
                                    1   -   Frame Sync is sample on falling edge
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTFCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Frame Sync Clock Priority to be sampled on the falling edge
        CSL_tsipSIUSetTxFrameSyncClockPolarity (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxFrameSyncClockPolarity 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txFrameSyncClockPolarity
)
{
    /* Use the Transmit Frame Sync Clock Polarity to configure the Transmit Control Register. */
    if (txFrameSyncClockPolarity == 0)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFCLKP, 0);
    else 
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFCLKP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxFrameSyncClockPolarity
 *
 *   @b Description
 *   @n This function gets the transmit frame sync clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Frame Sync Clock Polarity
 *   @n 0   -   Frame Sync is sample on rising edge
 *   @n 1   -   Frame Sync is sample on falling edge
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTFCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txFrameSyncClockPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Frame Sync Clock Priority.
        txFrameSyncClockPolarity = CSL_tsipSIUGetTxFrameSyncClockPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxFrameSyncClockPolarity (CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTFCLKP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxDataClockPolarity
 *
 *   @b Description
 *   @n This function sets the transmit data clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
            txDataClkPolarity       Transmit Frame Data Clock Polarity to be configured.
                                    0   -   Transmit data is driven on the rising edge 
                                    1   -   Transmit data is driven on the falling edge 
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTDCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Data Clock Priority to be done on the rising edge of TCLK
        CSL_tsipSIUSetTxDataClockPolarity (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxDataClockPolarity 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txDataClkPolarity
)
{
    /* Use the Transmit Data Clock Polarity to configure the Transmit Control Register. */
    if (txDataClkPolarity == 0)
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDCLKP, 0);
    else 
        CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDCLKP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxDataClockPolarity
 *
 *   @b Description
 *   @n This function gets the transmit data clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Data Clock Polarity
 *   @n 0   -   Transmit data is driven on the rising edge 
 *   @n 1   -   Transmit data is driven on the falling edge 
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTDCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txDataClockPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Data Clock Priority.
        txDataClockPolarity = CSL_tsipSIUGetTxDataClockPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxDataClockPolarity (CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDCLKP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxDataRate
 *
 *   @b Description
 *   @n This function sets the transmit data rate
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            txDataRate       Transmit Data Rate
                               0   -  Data Rate is 8.192  Mbps
                               1   -  Data Rate is 16.384 Mbps
                               2   -  Data Rate is 32.768 Mbps
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTDATR
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Data Rate to be 8.192 Mbps.
        CSL_tsipSIUSetTxDataRate (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxDataRate 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txDataRate
)
{
    /* Configure the transmit data rate. */
    CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDATR, txDataRate);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxDataRate
 *
 *   @b Description
 *   @n This function gets the transmit data rate.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Data Rate
 *   @n 0   -  Data Rate is 8.192  Mbps
 *   @n 1   -  Data Rate is 16.384 Mbps
 *   @n 2   -  Data Rate is 32.768 Mbps
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTDATR
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txDataRate;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Data Rate
        txDataRate = CSL_tsipSIUGetTxDataRate (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxDataRate (CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTDATR);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxClockMode
 *
 *   @b Description
 *   @n This function sets the transmit clock mode
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            txClockMode      Transmit Clock Mode
                               0   -  Double Rate Clock
                               1   -  Single Rate Clock
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTCTL_XMTCLKM
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Clock Mode to be Single Rate 
        CSL_tsipSIUSetTxClockMode (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxClockMode 
(
    CSL_TsipHandle  hTsip, 
    Uint8           txClockMode
)
{
    /* Configure the transmit clock mode. */
    CSL_FINS(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTCLKM, txClockMode);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxClockMode
 *
 *   @b Description
 *   @n This function gets the transmit clock mode.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Clock Mode
 *   @n 0   -  Double Rate Clock
 *   @n 1   -  Single Rate Clock
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_XMTCTL_XMTCLKM
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txClockMode;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Clock Mode
        txClockMode = CSL_tsipSIUGetTxClockMode (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxClockMode (CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_XMTCTL, TSIP_SIU_XMTCTL_XMTCLKM);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxFrameCount
 *
 *   @b Description
 *   @n This function sets the transmit frame count.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            txFrameCount     Transmit Frame Count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTSIZ_XMTFCNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Frame Count to 8
        CSL_tsipSIUSetTxFrameCount (hTsip, 8);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxFrameCount
(
    CSL_TsipHandle  hTsip, 
    Uint8           txFrameCount
)
{
    /* Configure the transmit frame count mode. */
    CSL_FINS(hTsip->SIU_XMTSIZ, TSIP_SIU_XMTSIZ_XMTFCNT, txFrameCount);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxFrameCount
 *
 *   @b Description
 *   @n This function gets the transmit frame count.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Frame Count.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTSIZ_XMTFCNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txFrameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Frame Count
        txFrameCount = CSL_tsipSIUGetTxFrameCount (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxFrameCount (CSL_TsipHandle hTsip)
{
    return CSL_FEXT(hTsip->SIU_XMTSIZ, TSIP_SIU_XMTSIZ_XMTFCNT);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetTxFrameSize
 *
 *   @b Description
 *   @n This function sets the transmit frame size
 *
 *   @b Arguments
 *   @verbatim
            hTsip          Handle to TSIP instance
            txFrameSize    Transmit Frame Size
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTSIZ_XMTFSIZ
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Transmit Frame Size to 8
        CSL_tsipSIUSetTxFrameSize (hTsip, 8);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetTxFrameSize
(
    CSL_TsipHandle  hTsip, 
    Uint8           txFrameSize
)
{
    /* Configure the transmit frame size */
    CSL_FINS(hTsip->SIU_XMTSIZ, TSIP_SIU_XMTSIZ_XMTFSIZ, txFrameSize);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetTxFrameSize
 *
 *   @b Description
 *   @n This function gets the transmit frame size.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Frame Size.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_XMTSIZ_XMTFSIZ
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txFrameSize;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Transmit Frame Size
        txFrameSize = CSL_tsipSIUGetTxFrameSize (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetTxFrameSize (CSL_TsipHandle hTsip)
{
    return CSL_FEXT(hTsip->SIU_XMTSIZ, TSIP_SIU_XMTSIZ_XMTFSIZ);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxClockSource
 *
 *   @b Description
 *   @n This function sets the SIU Receive Clock Source.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            clockSource     Clock Source to be used for the SIU Receive 
                            Value of 0 implies TCLK_A else TCLK_B
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVSEL_RCVSRC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the SIU Receive Clock to use TCLK_B & TFS_B
        CSL_tsipSIUSetRxClockSource(hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxClockSource (CSL_TsipHandle hTsip, Uint8 clockSource)
{
    /* Use the clock source to configure the Receive Clock Source register.*/
    if (clockSource == 0)
        CSL_FINS(hTsip->SIU_RCVSEL, TSIP_SIU_RCVSEL_RCVSRC, 0);
    else
        CSL_FINS(hTsip->SIU_RCVSEL, TSIP_SIU_RCVSEL_RCVSRC, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxClockSource
 *
 *   @b Description
 *   @n This function gets the SIU Receive Clock Source.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *	 @n  0  -   Implies Clock Source A
 *	 @n  1  -   Implies Clock Source B
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVSEL_RCVSRC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the SIU Receive Clock Source
        if (CSL_tsipSIUGetRxClockSource(hTsip) == 1)
        {
            // Using Clock Source A
        }
        else
        {
            // Using Clock Source B
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxClockSource (CSL_TsipHandle hTsip)
{
    /* Get the clock source. */
    return (Uint8) CSL_FEXT(hTsip->SIU_RCVSEL, TSIP_SIU_RCVSEL_RCVSRC);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxDataDelay
 *
 *   @b Description
 *   @n This function sets the receive data delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            rxDataDelay     Receive Data Delay to be configured.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVDATD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive Data Delay to be 1023 (Single Rate 8Mbps serial link with 128 time slots)
        CSL_tsipSIUSetRxDataDelay (hTsip, 1023);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxDataDelay (CSL_TsipHandle hTsip, Uint16 rxDataDelay)
{
    CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDATD, rxDataDelay);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxDataDelay
 *
 *   @b Description
 *   @n This function gets the transmit data delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Data Delay configured.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVCTL_RCVDATD
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint16              rxDataDelay;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive Data Delay 
        rxDataDelay = CSL_tsipSIUGetRxDataDelay (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_tsipSIUGetRxDataDelay (CSL_TsipHandle hTsip)
{
    return CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDATD);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxFrameSyncPolarity
 *
 *   @b Description
 *   @n This function sets the receive frame sync polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
            rxFrameSyncPolarity     Receive Frame Sync Polarity to be configured.
                                    0   -   Active Low
                                    1   -   Active High
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVFSYNCP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive frame sync polarity to be active low
        CSL_tsipSIUSetRxFrameSyncPolarity (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxFrameSyncPolarity
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxFrameSyncPolarity
)
{
    /* Use the Receive Frame Sync Polarity to configure the Receive Control Register. */
    if (rxFrameSyncPolarity == 0)
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFSYNCP, 0);
    else 
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFSYNCP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxFrameSyncPolarity
 *
 *   @b Description
 *   @n This function gets the receive frame sync polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Frame Sync Polarity
 *   @n 0   -   Active Low
 *   @n 1   -   Active High
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVFSYNCP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxFrameSyncPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive frame sync polarity
        rxFrameSyncPolarity = CSL_tsipSIUGetRxFrameSyncPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxFrameSyncPolarity(CSL_TsipHandle  hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFSYNCP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxFrameSyncClockPolarity
 *
 *   @b Description
 *   @n This function sets the receive frame sync clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                       Handle to TSIP instance
            rxFrameSyncClockPolarity    Receive Frame Sync Polarity to be configured.
                                        0   -   Clock is sample on the rising edge
                                        1   -   Clock is sample on the falling edge
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVFCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive frame sync clock polarity to be on the falling edge
        CSL_tsipSIUSetRxFrameSyncClockPolarity (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxFrameSyncClockPolarity
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxFrameSyncClockPolarity
)
{
    /* Use the Receive Frame Sync Polarity to configure the Receive Control Register. */
    if (rxFrameSyncClockPolarity == 0)
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFCLKP, 0);
    else 
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFCLKP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxFrameSyncClockPolarity
 *
 *   @b Description
 *   @n This function gets the receive frame sync clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Frame Sync Polarity
 *   @n 0   -   Clock is sampled on the rising edge
 *   @n 1   -   Clock is sampled on the falling edge
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVFCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxFrameSyncClockPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive frame sync clock polarity
        rxFrameSyncClockPolarity = CSL_tsipSIUGetRxFrameSyncClockPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxFrameSyncClockPolarity(CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVFCLKP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxDataClockPolarity
 *
 *   @b Description
 *   @n This function sets the receive frame data clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
            rxDataClockPolarity     Receive Data Clock Polarity to be configured.
                                        0   -   Clock is sampled on the rising edge
                                        1   -   Clock is sampled on the falling edge
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVDCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        
        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive data clock polarity to be on the falling edge
        CSL_tsipSIUSetRxDataClockPolarity (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxDataClockPolarity
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxDataClockPolarity
)
{
    /* Use the Receive Data Clock Polarity to configure the Receive Control Register. */
    if (rxDataClockPolarity == 0)
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDCLKP, 0);
    else 
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDCLKP, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxDataClockPolarity
 *
 *   @b Description
 *   @n This function gets the receive frame data clock polarity.
 *
 *   @b Arguments
 *   @verbatim
            hTsip                   Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Data Clock Polarity.
 *   @n 0   -   Clock is sampled on the rising edge
 *   @n 1   -   Clock is sampled on the falling edge
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVCTL_RCVDCLKP
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxDataClockPolarity;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive data clock polarity...
        rxDataClockPolarity = CSL_tsipSIUGetRxDataClockPolarity (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxDataClockPolarity(CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDCLKP);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxDataRate
 *
 *   @b Description
 *   @n This function sets the receive frame data rate
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            rxDataRate       Receive Data Rate
                               0   -  Data Rate is 8.192  Mbps
                               1   -  Data Rate is 16.384 Mbps
                               2   -  Data Rate is 32.768 Mbps
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVDATR
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive data rate to be 8Mbps
        CSL_tsipSIUSetRxDataRate (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxDataRate
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxDataRate
)
{
    /* Configure the receive data rate. */
    CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDATR, rxDataRate);
    return;        
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxDataRate
 *
 *   @b Description
 *   @n This function gets the receive frame data rate
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Data Rate
 *   @n  0   -  Data Rate is 8.192  Mbps
 *   @n  1   -  Data Rate is 16.384 Mbps
 *   @n  2   -  Data Rate is 32.768 Mbps
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVCTL_RCVDATR
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxDataRate;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive data rate to be 8Mbps
        rxDataRate = CSL_tsipSIUGetRxDataRate (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxDataRate(CSL_TsipHandle hTsip)
{
    /* Configure the receive data rate. */
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVDATR);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxClockMode
 *
 *   @b Description
 *   @n This function sets the receive clock mode.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            rxClockMode      Receive Clock Mode
                               0   -  Double Rate Clock
                               1   -  Single Rate Clock
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVCTL_RCVCLKM
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive clock mode to be a single rate clock
        CSL_tsipSIUSetRxClockMode (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxClockMode
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxClockMode
)
{
    /* Configure the receive clock mode. */
    if (rxClockMode == 0)
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVCLKM, 0);
    else
        CSL_FINS(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVCLKM, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxClockMode
 *
 *   @b Description
 *   @n This function gets the receive clock mode.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Clock Mode.
 *   @n 0   -  Double Rate Clock
 *   @n 1   -  Single Rate Clock
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVCTL_RCVCLKM
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxClockMode;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive clock mode
        rxClockMode = CSL_tsipSIUGetRxClockMode (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxClockMode(CSL_TsipHandle  hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVCTL, TSIP_SIU_RCVCTL_RCVCLKM);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxFrameSize
 *
 *   @b Description
 *   @n This function sets the receive frame size
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            rxFrameSize      Receive Frame Size
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVSIZ_RCVFSIZ
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive frame size to be 8
        CSL_tsipSIUSetRxFrameSize (hTsip, 8);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxFrameSize
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxFrameSize
)
{
    /* Configure the receive frame size */
    CSL_FINS(hTsip->SIU_RCVSIZ, TSIP_SIU_RCVSIZ_RCVFSIZ, rxFrameSize);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxFrameSize
 *
 *   @b Description
 *   @n This function gets the receive frame size
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Frame Size.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_SIU_RCVSIZ_RCVFSIZ
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxFrameSize;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive frame size
        rxFrameSize = CSL_tsipSIUGetRxFrameSize (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxFrameSize(CSL_TsipHandle hTsip)
{
    /* Configure the receive frame size */
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVSIZ, TSIP_SIU_RCVSIZ_RCVFSIZ);
}

/** ============================================================================
 *   @n@b CSL_tsipSIUSetRxFrameCount
 *
 *   @b Description
 *   @n This function sets the receive frame count
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            rxFrameCount     Receive Frame Count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVSIZ_RCVFCNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Set the Receive frame count to be 8
        CSL_tsipSIUSetRxFrameCount (hTsip, 8);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipSIUSetRxFrameCount
(
    CSL_TsipHandle  hTsip, 
    Uint8           rxFrameCount
)
{
    /* Configure the receive frame count */
    CSL_FINS(hTsip->SIU_RCVSIZ, TSIP_SIU_RCVSIZ_RCVFCNT, rxFrameCount);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipSIUGetRxFrameCount
 *
 *   @b Description
 *   @n This function sets the receive frame count
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Frame Count.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_SIU_RCVSIZ_RCVFCNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxFrameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Get the Receive frame count
        rxFrameCount = CSL_tsipSIUGetRxFrameCount (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipSIUGetRxFrameCount(CSL_TsipHandle hTsip)
{
    /* Get the receive frame count */
    return (Uint8)CSL_FEXT(hTsip->SIU_RCVSIZ, TSIP_SIU_RCVSIZ_RCVFCNT);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUDisable 
 *
 *   @b Description
 *   @n This function is used to disable the TDMU and DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None 
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_TDMU_GCTL_DMAENB=0
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Disable the TDMU and DMATCU
        CSL_tsipTDMUDisable(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUDisable(CSL_TsipHandle hTsip)
{
    CSL_FINS (hTsip->TDMU_GCTL, TSIP_TDMU_GCTL_DMAENB, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUEnable 
 *
 *   @b Description
 *   @n This function is used to enable the TDMU and DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None 
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_TDMU_GCTL_DMAENB=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Enable the TDMU and DMATCU
        CSL_tsipTDMUEnable(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUEnable(CSL_TsipHandle hTsip)
{
    CSL_FINS (hTsip->TDMU_GCTL, TSIP_TDMU_GCTL_DMAENB, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUIsEnabled 
 *
 *   @b Description
 *   @n This function is used to check if the TDMU and DMATCU is enabled or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Status of the TDMU and DMATCU
 *   @n TRUE  - TDMU/DMATCU are enabled and running
 *   @n FALSE - TDMU/DMATCU are disabled and stopped
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_TDMU_GCTL_DMAENB
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);

        // Is the TDMU and DMATCU enabled? 
        if (CSL_tsipTDMUIsEnabled(hTsip) == TRUE)
        {
            // TDMU and DMATCU is enabled and running.
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipTDMUIsEnabled(CSL_TsipHandle hTsip)
{
    if (CSL_FEXT (hTsip->TDMU_GCTL, TSIP_TDMU_GCTL_DMAENB) == 1)
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetTxFreeRunningCounter
 *
 *   @b Description
 *   @n This function gets the transmit free running frame counter
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transmit Free Running Frame Counter.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTFRFC_TXFRFC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              txCounter;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the transmit free running frame counter.
        txCounter = CSL_tsipTDMUGetTxFreeRunningCounter(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_tsipTDMUGetTxFreeRunningCounter(CSL_TsipHandle hTsip)
{
    return (Uint32)CSL_FEXT(hTsip->XMTFRFC, TSIP_XMTFRFC_TXFRFC);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetRxFreeRunningCounter
 *
 *   @b Description
 *   @n This function gets the receive free running frame counter
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Free Running Frame Counter.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVFRFC_RXFRFC
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              rxCounter;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the receive free running frame counter.
        rxCounter = CSL_tsipTDMUGetRxFreeRunningCounter(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_tsipTDMUGetRxFreeRunningCounter(CSL_TsipHandle hTsip)
{
    return (Uint32)CSL_FEXT(hTsip->RCVFRFC, TSIP_RCVFRFC_RXFRFC);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUSetEndianess
 *
 *   @b Description
 *   @n This function sets the endian mode in which the TDMU operates.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
            endian           Endianess for the TDMU
                                0 - Little Endian
                                1 - Big Endian
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Receive Free Running Frame Counter.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_TDMU_GECTL_BEND
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the endianess to operate in Little Endian
        CSL_tsipTDMUSetEndianess(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUSetEndianess
(
    CSL_TsipHandle  hTsip, 
    Uint8           endian
)
{
    /* Configure the endianess */
    if (endian == 0)
        CSL_FINS (hTsip->TDMU_GECTL, TSIP_TDMU_GECTL_BEND, 0);
    else
        CSL_FINS (hTsip->TDMU_GECTL, TSIP_TDMU_GECTL_BEND, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetEndianess
 *
 *   @b Description
 *   @n This function gets the endian mode in which the TDMU operates.
 *
 *   @b Arguments
 *   @verbatim
            hTsip            Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Endianess 
 *   @n 0 - Little Endian
 *   @n 1 - Big Endian
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_TDMU_GECTL_BEND
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               endian;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the endianess
        endian = CSL_tsipTDMUGetEndianess(hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUGetEndianess(CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT (hTsip->TDMU_GECTL, TSIP_TDMU_GECTL_BEND);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetTxChannelBitmapStatus
 *
 *   @b Description
 *   @n This function gets the transmit channel bitmap status.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number whose status is to be enquired.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Channel Status
 *   @n 0x0 - Both Bitmap A and B are inactive.
 *   @n 0x1 - Bitmap A is active and Bitmap B is inactive
 *   @n 0x2 - Bitmap A is inactive and Bitmap B is active
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n XMTCBAS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txChannelStatus;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transmit Channel Status of Channel 0
        txChannelStatus = CSL_tsipTDMUGetTxChannelBitmapStatus(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUGetTxChannelBitmapStatus
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    Uint8 lsb = (channelNumber << 1);
    return (Uint8)CSL_FEXTR (hTsip->XMTCBAS, (lsb + 1), lsb);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetRxChannelBitmapStatus
 *
 *   @b Description
 *   @n This function gets the receive channel bitmap status.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number whose status is to be enquired.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Channel Status
 *   @n 0x0 - Both Bitmap A and B are inactive.
 *   @n 0x1 - Bitmap A is active and Bitmap B is inactive
 *   @n 0x2 - Bitmap A is inactive and Bitmap B is active
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n RCVCBAS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxChannelStatus;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Receive Channel Status of Channel 0
        rxChannelStatus = CSL_tsipTDMUGetRxChannelBitmapStatus(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUGetRxChannelBitmapStatus
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    Uint8 lsb = (channelNumber << 1);
    return (Uint8)CSL_FEXTR (hTsip->RCVCBAS, (lsb + 1), lsb);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetMaxTransferPriority
 *
 *   @b Description
 *   @n This function sets the MAX transfer priority of the DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            maxPriority     Max Transfer Priority of the DMATCU
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_DMATCU_GCTL_MAXPRI
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Max Transfer Priority to be 1
        CSL_tsipDMATCUSetMaxTransferPriority (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetMaxTransferPriority
(
    CSL_TsipHandle  hTsip, 
    Uint8           maxPriority
)
{
    CSL_FINS(hTsip->DMATCU_GCTL, TSIP_DMATCU_GCTL_MAXPRI, maxPriority);
    return; 
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetMaxTransferPriority
 *
 *   @b Description
 *   @n This function gets the MAX transfer priority of the DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Max Transfer Priority of the DMATCU
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_DMATCU_GCTL_MAXPRI
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               maxPriority;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Max Transfer Priority to be 1
        maxPriority = CSL_tsipDMATCUGetMaxTransferPriority (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetMaxTransferPriority(CSL_TsipHandle hTsip)
{
    return (Uint8)CSL_FEXT(hTsip->DMATCU_GCTL, TSIP_DMATCU_GCTL_MAXPRI);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetTransferPriority
 *
 *   @b Description
 *   @n This function sets the transfer priority of the DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            priority        Transfer Priority of the DMATCU
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_DMATCU_GCTL_BASEPRI
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Transfer Priority to be 2
        CSL_tsipDMATCUSetTransferPriority (hTsip, 2);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetTransferPriority
(
    CSL_TsipHandle  hTsip, 
    Uint8           priority
)
{
    CSL_FINS(hTsip->DMATCU_GCTL, TSIP_DMATCU_GCTL_BASEPRI, priority);
    return; 
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetTransferPriority
 *
 *   @b Description
 *   @n This function gets the transfer priority of the DMATCU
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Transfer Priority of the DMATCU
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_DMATCU_GCTL_BASEPRI
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               priority;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transfer Priority
        priority = CSL_tsipDMATCUGetTransferPriority (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetTransferPriority(CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->DMATCU_GCTL, TSIP_DMATCU_GCTL_BASEPRI);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetTxSuperFrameIntSelection
 *
 *   @b Description
 *   @n This function sets the Tx Super frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            txSFIntSelection    Tx Superframe Interrupt Selection.
                                0 - Interrupt on Transfer ACK
                                1 - Interrupt on delay count
                                2 - Interrupt on either Transfer ACK or delay count
                                3 - Interrupt on both Transfer ACK or delay count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTTDR_XMTFSINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Transmit Transfer to interrupt only on TRANSFER ACK.
        CSL_tsipDMATCUSetTxSuperFrameIntSelection (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetTxSuperFrameIntSelection 
(    
    CSL_TsipHandle  hTsip,
    Uint8           txSFIntSelection
)
{
    CSL_FINS(hTsip->XMTTDR, TSIP_XMTTDR_XMTFSINT, txSFIntSelection);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetTxSuperFrameIntSelection
 *
 *   @b Description
 *   @n This function gets the Tx Super frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Tx Superframe Interrupt Selection.
 *   @n  0 - Interrupt on Transfer ACK
 *   @n  1 - Interrupt on delay count
 *   @n  2 - Interrupt on either Transfer ACK or delay count
 *   @n  3 - Interrupt on both Transfer ACK or delay count
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTTDR_XMTFSINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txSFIntSelection;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transmit Superframe interrupt Selection.
        txSFIntSelection = CSL_tsipDMATCUGetTxSuperFrameIntSelection (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetTxSuperFrameIntSelection(CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->XMTTDR, TSIP_XMTTDR_XMTFSINT);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetTxFrameIntSelection
 *
 *   @b Description
 *   @n This function sets the Tx frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            txIntSelection      Tx Frame Interrupt Selection.
                                0 - Interrupt on Transfer ACK
                                1 - Interrupt on delay count
                                2 - Interrupt on either Transfer ACK or delay count
                                3 - Interrupt on both Transfer ACK or delay count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTTDR_XMTFRINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Transmit Transfer to interrupt only on TRANSFER ACK.
        CSL_tsipDMATCUSetTxFrameIntSelection (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetTxFrameIntSelection 
(    
    CSL_TsipHandle  hTsip,
    Uint8           txIntSelection
)
{
    CSL_FINS(hTsip->XMTTDR, TSIP_XMTTDR_XMTFRINT, txIntSelection);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetTxFrameIntSelection
 *
 *   @b Description
 *   @n This function gets the Tx frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Tx Frame Interrupt Selection.
 *   @n  0 - Interrupt on Transfer ACK
 *   @n  1 - Interrupt on delay count
 *   @n  2 - Interrupt on either Transfer ACK or delay count
 *   @n  3 - Interrupt on both Transfer ACK or delay count
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTTDR_XMTFRINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txIntSelection;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transmit Frame interrupt selection
        txIntSelection = CSL_tsipDMATCUGetTxFrameIntSelection (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetTxFrameIntSelection(CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->XMTTDR, TSIP_XMTTDR_XMTFRINT);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetTxFrameIntDelay
 *
 *   @b Description
 *   @n This function sets the Tx frame interrupt delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            txIntDelay          Tx Frame Interrupt Delay
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTTDR_XMTFDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Transmit Transfer Interrupt delay to be 0
        CSL_tsipDMATCUSetTxFrameIntDelay (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetTxFrameIntDelay 
(    
    CSL_TsipHandle  hTsip,
    Uint8           txIntDelay
)
{
    CSL_FINS(hTsip->XMTTDR, TSIP_XMTTDR_XMTFDLY, txIntDelay);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetTxFrameIntDelay
 *
 *   @b Description
 *   @n This function gets the Tx frame interrupt delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Tx Frame Interrupt Delay
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTTDR_XMTFDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txIntDelay;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transmit Transfer Interrupt delay
        txIntDelay = CSL_tsipDMATCUSetTxFrameIntDelay (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetTxFrameIntDelay (CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->XMTTDR, TSIP_XMTTDR_XMTFDLY);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetRxSuperFrameIntSelection
 *
 *   @b Description
 *   @n This function sets the Rx Super frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            rxSFIntSelection    Rx Superframe Interrupt Selection.
                                0 - Interrupt on Transfer ACK
                                1 - Interrupt on delay count
                                2 - Interrupt on either Transfer ACK or delay count
                                3 - Interrupt on both Transfer ACK or delay count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVTDR_RCVFSINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Receive Transfer to interrupt only on TRANSFER ACK.
        CSL_tsipDMATCUSetRxSuperFrameIntSelection (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetRxSuperFrameIntSelection 
(    
    CSL_TsipHandle  hTsip,
    Uint8           rxSFIntSelection
)
{
    CSL_FINS(hTsip->RCVTDR, TSIP_RCVTDR_RCVFSINT, rxSFIntSelection);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetRxSuperFrameIntSelection
 *
 *   @b Description
 *   @n This function gets the Rx Super frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Rx Superframe Interrupt Selection.
 *   @n  0 - Interrupt on Transfer ACK
 *   @n  1 - Interrupt on delay count
 *   @n  2 - Interrupt on either Transfer ACK or delay count
 *   @n  3 - Interrupt on both Transfer ACK or delay count
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVTDR_RCVFSINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxSFIntSelection;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Receive Superframe interrupt Selection.
        rxSFIntSelection = CSL_tsipDMATCUGetRxSuperFrameIntSelection (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetRxSuperFrameIntSelection(CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->RCVTDR, TSIP_RCVTDR_RCVFSINT);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetRxFrameIntSelection
 *
 *   @b Description
 *   @n This function sets the Rx frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            rxIntSelection      Rx Frame Interrupt Selection.
                                0 - Interrupt on Transfer ACK
                                1 - Interrupt on delay count
                                2 - Interrupt on either Transfer ACK or delay count
                                3 - Interrupt on both Transfer ACK or delay count
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVTDR_RCVFRINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Receive Transfer to interrupt only on TRANSFER ACK.
        CSL_tsipDMATCUSetRxFrameIntSelection (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetRxFrameIntSelection 
(    
    CSL_TsipHandle  hTsip,
    Uint8           rxIntSelection
)
{
    CSL_FINS(hTsip->RCVTDR, TSIP_RCVTDR_RCVFRINT, rxIntSelection);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetRxFrameIntSelection
 *
 *   @b Description
 *   @n This function gets the Rx frame interrupt selection.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Rx Frame Interrupt Selection.
 *   @n  0 - Interrupt on Transfer ACK
 *   @n  1 - Interrupt on delay count
 *   @n  2 - Interrupt on either Transfer ACK or delay count
 *   @n  3 - Interrupt on both Transfer ACK or delay count
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVTDR_RCVFRINT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxIntSelection;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Receive Frame interrupt selection
        rxIntSelection = CSL_tsipDMATCUGetRxFrameIntSelection (hTsip);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetRxFrameIntSelection(CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->RCVTDR, TSIP_RCVTDR_RCVFRINT);
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUSetRxFrameIntDelay
 *
 *   @b Description
 *   @n This function sets the Rx frame interrupt delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            rxIntDelay          Rx Frame Interrupt Delay
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVTDR_RCVFDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Receive Transfer Interrupt delay to be 0
        CSL_tsipDMATCUSetRxFrameIntDelay (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipDMATCUSetRxFrameIntDelay 
(    
    CSL_TsipHandle  hTsip,
    Uint8           rxIntDelay
)
{
    CSL_FINS(hTsip->RCVTDR, TSIP_RCVTDR_RCVFDLY, rxIntDelay);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipDMATCUGetRxFrameIntDelay
 *
 *   @b Description
 *   @n This function gets the Rx frame interrupt delay.
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Rx Frame Interrupt Delay
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVTDR_RCVFDLY
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxIntDelay;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Receive Transfer Interrupt delay
        rxIntDelay = CSL_tsipDMATCUGetRxFrameIntDelay (hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipDMATCUGetRxFrameIntDelay (CSL_TsipHandle hTsip)
{
    return (Uint8) CSL_FEXT(hTsip->RCVTDR, TSIP_RCVTDR_RCVFDLY);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetTxChannelStatus
 *
 *   @b Description
 *   @n This function gets the transmit channel status.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number whose status is to be enquired.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Channel Status
 *   @n 0x0 - Both Configurations A and B are inactive.
 *   @n 0x1 - Configuration A is active and Configuration B is inactive
 *   @n 0x2 - Configuration A is inactive and Configuration B is active
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n XMTCCAS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               txChannelStatus;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Transmit Channel Status of Channel 0
        txChannelStatus = CSL_tsipTDMUGetTxChannelStatus(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUGetTxChannelStatus
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    Uint8 lsb = (channelNumber << 1);
    return (Uint8)CSL_FEXTR (hTsip->XMTCCAS, (lsb + 1), lsb);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetRxChannelStatus
 *
 *   @b Description
 *   @n This function gets the receive channel status.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number whose status is to be enquired.
     @endverbatim
 *
 *   <b> Return Value </b>  
 *   @n Channel Status
 *   @n 0x0 - Both Configurations A and B are inactive.
 *   @n 0x1 - Configuration A is active and Configuration B is inactive
 *   @n 0x2 - Configuration A is inactive and Configuration B is active
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n RCVCCAS
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               rxChannelStatus;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Receive Channel Status of Channel 0
        rxChannelStatus = CSL_tsipTDMUGetRxChannelStatus(hTsip, 0);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUGetRxChannelStatus
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    Uint8 lsb = (channelNumber << 1);
    return (Uint8)CSL_FEXTR (hTsip->RCVCCAS, (lsb + 1), lsb);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelClearOverflowError
 *
 *   @b Description
 *   @n This function clears the error queue overflow.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the error is to be cleared.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_CH0ECR_CH0CEQOV=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Clear the overflow error on Channel 1
        CSL_tsipTDMUChannelClearOverflowError (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUChannelClearOverflowError
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS(hTsip->ERR[channelNumber].ERRCTL, TSIP_CH0ECR_CH0CEQOV, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelClearErrorQueue
 *
 *   @b Description
 *   @n This function clears the error queue.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the error is to be cleared.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_CH0ECR_CH0CLRQ=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Clear the error queue on Channel 2
        CSL_tsipTDMUChannelClearErrorQueue (hTsip, 2);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUChannelClearErrorQueue
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS(hTsip->ERR[channelNumber].ERRCTL, TSIP_CH0ECR_CH0CLRQ, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelPopErrorEntry
 *
 *   @b Description
 *   @n This function pops the top error entry off the error queue.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the error is to be popped off.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_CH0ECR_CH0POPQ=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Pop the error off channel 3.
        CSL_tsipTDMUChannelPopErrorEntry (hTsip, 3);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUChannelPopErrorEntry
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS(hTsip->ERR[channelNumber].ERRCTL, TSIP_CH0ECR_CH0POPQ, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelGetErrorCount
 *
 *   @b Description
 *   @n This function gets the number of entries in the error queue.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the error queue is to read
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Number of entries in the error queue.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_CH0ERRS_CH0ECNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               errCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the number of error entries for channel 3 
        errCount = CSL_tsipTDMUChannelGetErrorCount (hTsip, 3);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUChannelGetErrorCount
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    return (Uint8)CSL_FEXT(hTsip->ERR[channelNumber].ERRCNT, TSIP_CH0ERRS_CH0ECNT);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelIsErrorQueueOverflow
 *
 *   @b Description
 *   @n This function checks if the error queue for a specific channel has 
 *      overflown or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the overflow is to be checked
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Error Queue Overflow status
 *   @n  TRUE  - Error Queue Overflown
 *   @n  FALSE - Error Queue has *not* Overflown
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_CH0ERRS_CH0EQOV
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Check if there is an overflow error on Channel 4
        if(CSL_tsipTDMUChannelIsErrorQueueOverflow (hTsip, 4) == TRUE)
        {
            // Error Queue has overflow on channel 4. 
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipTDMUChannelIsErrorQueueOverflow
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    if (CSL_FEXT(hTsip->ERR[channelNumber].ERRCNT, TSIP_CH0ERRS_CH0EQOV) == 1)
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUChannelGetErrorCodeInfo
 *
 *   @b Description
 *   @n This function gets the error code and information for a specific channel.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Channel Number for which the error info is required
            errCode         Error Code populated by this API
            errInfo         Error Information populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Error Code and Information is populated.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_CH0EQR_CH0ERRC, TSIP_CH0EQR_CH0INFO
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               errCode;
        Uint32              errInfo;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Error Code and Information for Channel 1
        CSL_tsipTDMUChannelGetErrorCodeInfo (hTsip, 1, &errCode, &errInfo);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUChannelGetErrorCodeInfo
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint8*          errCode,
    Uint32*         errInfo
)
{
    *errCode = (Uint8) CSL_FEXT (hTsip->ERR[channelNumber].ERRQ, TSIP_CH0EQR_CH0ERRC);
    *errInfo = (Uint32)CSL_FEXT (hTsip->ERR[channelNumber].ERRQ, TSIP_CH0EQR_CH0INFO);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUTxChannelEnable
 *
 *   @b Description
 *   @n This function enables the specific transmit channel.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number which is to be enabled.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNEN_0_TXCH0ENB=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Enable Tx Channel 1.
        CSL_tsipTDMUTxChannelEnable (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUTxChannelEnable
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS (hTsip->XCHEN[channelNumber].XCHEN, TSIP_XMTCHNEN_0_TXCH0ENB, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUTxChannelDisable
 *
 *   @b Description
 *   @n This function disables the specific transmit channel.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number which is to be disabled.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNEN_0_TXCH0ENB=0
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Disable Tx Channel 1.
        CSL_tsipTDMUTxChannelDisable (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUTxChannelDisable
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS (hTsip->XCHEN[channelNumber].XCHEN, TSIP_XMTCHNEN_0_TXCH0ENB, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUIsTxChannelEnabled
 *
 *   @b Description
 *   @n This function checks if the specific transmit channel is enabled or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number whose status is being enquired.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Status of the Transmit Channel.
 *   @n   TRUE  - Channel is enabled.
 *   @n   FALSE - Channel is disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTCHNEN_0_TXCH0ENB
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Check the status of channel 1
        if (CSL_tsipTDMUIsTxChannelEnabled (hTsip, 1) == FALSE)
        {
            // Channel 1 is disabled...
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipTDMUIsTxChannelEnabled
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    if (CSL_FEXT (hTsip->XCHEN[channelNumber].XCHEN, TSIP_XMTCHNEN_0_TXCH0ENB) == 1)
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUTxChannelSetConfiguration
 *
 *   @b Description
 *   @n This function sets the transmit channel configuration identification.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number for which the CFG Id is to be set.
            cfgInfo         Configuration Information to be configured.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNEN_0_TXC0ID
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration Information for Tx Channel 1 to use B
        CSL_tsipTDMUTxChannelSetConfiguration (hTsip, 1, 0x1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUTxChannelSetConfiguration
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint8           cfgInfo
)
{
    CSL_FINS (hTsip->XCHEN[channelNumber].XCHEN, TSIP_XMTCHNEN_0_TXC0ID, cfgInfo);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUTxChannelGetConfiguration
 *
 *   @b Description
 *   @n This function gets the transmit channel configuration identification.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Tx Channel Number for which the CFG Id is to be set.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Configuration Information associated with the channel.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTCHNEN_0_TXC0ID
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               cfgInfo;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration Information for Tx Channel 1 
        cfgInfo = CSL_tsipTDMUTxChannelGetConfiguration (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMUTxChannelGetConfiguration
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber    
)
{
    return (Uint8)CSL_FEXT (hTsip->XCHEN[channelNumber].XCHEN, TSIP_XMTCHNEN_0_TXC0ID);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMURxChannelEnable
 *
 *   @b Description
 *   @n This function enables the specific receive channel.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number which is to be enabled.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVCHNEN_0_RXCH0ENB=1
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Enable Rx Channel 1.
        CSL_tsipTDMURxChannelEnable (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMURxChannelEnable
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS (hTsip->RCHEN[channelNumber].RCHEN, TSIP_RCVCHNEN_0_RXCH0ENB, 1);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMURxChannelDisable
 *
 *   @b Description
 *   @n This function disables the specific receive channel.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number which is to be disabled.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVCHNEN_0_RXCH0ENB=0
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Disable Rx Channel 1.
        CSL_tsipTDMURxChannelDisable (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMURxChannelDisable
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    CSL_FINS (hTsip->RCHEN[channelNumber].RCHEN, TSIP_RCVCHNEN_0_RXCH0ENB, 0);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUIsRxChannelEnabled
 *
 *   @b Description
 *   @n This function checks if the specific receive channel is enabled or not?
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number whose status is being enquired.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Status of the Receive Channel.
 *   @n   TRUE  - Channel is enabled.
 *   @n   FALSE - Channel is disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVCHNEN_0_RXCH0ENB
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Check the status of channel 1
        if (CSL_tsipTDMUIsRxChannelEnabled (hTsip, 1) == FALSE)
        {
            // Channel 1 is disabled...
        }
        ...
     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_tsipTDMUIsRxChannelEnabled
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber
)
{
    if (CSL_FEXT (hTsip->RCHEN[channelNumber].RCHEN, TSIP_RCVCHNEN_0_RXCH0ENB) == 1)
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMURxChannelSetConfiguration
 *
 *   @b Description
 *   @n This function sets the receive channel configuration identification.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number for which the CFG Id is to be set.
            cfgInfo         Configuration Information to be configured.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVCHNEN_0_RXC0ID
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration Information for Rx Channel 1 to use B
        CSL_tsipTDMURxChannelSetConfiguration (hTsip, 1, 0x1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMURxChannelSetConfiguration
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint8           cfgInfo
)
{
    CSL_FINS (hTsip->RCHEN[channelNumber].RCHEN, TSIP_RCVCHNEN_0_RXC0ID, cfgInfo);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMURxChannelGetConfiguration
 *
 *   @b Description
 *   @n This function gets the receive channel configuration identification.
 *
 *   @b Arguments
 *   @verbatim
            hTsip           Handle to TSIP instance
            channelNumber   Rx Channel Number for which the CFG Id is to be retrieved.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Configuration Information associated with the channel.
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVCHNEN_0_RXC0ID
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint8               cfgInfo;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration Information for Rx Channel 1 
        cfgInfo = CSL_tsipTDMURxChannelGetConfiguration (hTsip, 1);
        ...
     @endverbatim
 * =============================================================================
 */
static inline Uint8 CSL_tsipTDMURxChannelGetConfiguration
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber    
)
{
    return (Uint8)CSL_FEXT (hTsip->RCHEN[channelNumber].RCHEN, TSIP_RCVCHNEN_0_RXC0ID);
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUSetTxChannelAConfig
 *
 *   @b Description
 *   @n This function sets the transmit channel A configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Tx Channel Number 
            memoryBaseAddress   Memory Base Address
            frameAllocation     Frame Allocation 
            frameSize           Number of bytes to transfer for each frame
            frameCount          Number of frames in a buffer.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR;TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC;
 *      TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE;TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration for Tx Channel(A) 1 
        CSL_tsipTDMUSetTxChannelAConfig (hTsip, 1, 0x8000000, 0x1000, 0x128, 10);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUSetTxChannelAConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32          memoryBaseAddress,
    Uint16          frameAllocation,
    Uint16          frameSize,
    Uint8           frameCount
)
{
    /* Set the Transmit Channel A Configuration */
    CSL_FINS (hTsip->DXCH[channelNumber].ABASE, TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR, memoryBaseAddress);
    CSL_FINS (hTsip->DXCH[channelNumber].AFALLOC, TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC, frameAllocation);
    CSL_FINS (hTsip->DXCH[channelNumber].AFSIZE, TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE, frameSize);
    CSL_FINS (hTsip->DXCH[channelNumber].AFCNT, TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT, frameCount);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetTxChannelAConfig
 *
 *   @b Description
 *   @n This function gets the transmit channel A configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Tx Channel Number 
            memoryBaseAddress   Memory Base Address populated by this API
            frameAllocation     Frame Allocation populated by this API
            frameSize           Number of bytes to transfer for each frame populated by this API
            frameCount          Number of frames in a buffer populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR;TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC;
 *      TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE;TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              memoryBaseAddress;
        Uint16              frameAllocation;
        Uint16              frameSize;
        Uint8               frameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration for Tx Channel(A) 1 
        CSL_tsipTDMUGetTxChannelAConfig (hTsip, 1, &memoryBaseAddress, 
                                         &frameAllocation, &frameSize, &frameCount);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUGetTxChannelAConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32*         memoryBaseAddress,
    Uint16*         frameAllocation,
    Uint16*         frameSize,
    Uint8*          frameCount
)
{
    /* Get the Transmit Channel A Configuration */
    *memoryBaseAddress = (Uint32)CSL_FEXT (hTsip->DXCH[channelNumber].ABASE, TSIP_XMTCHNCON_ABA_0_TXC0AMEMBASEADR);
    *frameAllocation = (Uint16)CSL_FEXT (hTsip->DXCH[channelNumber].AFALLOC, TSIP_XMTCHNCON_AFA_0_TXC0AFRAMEALLOC);
    *frameSize  = (Uint16)CSL_FEXT (hTsip->DXCH[channelNumber].AFSIZE, TSIP_XMTCHNCON_AFS_0_TXC0AFSIZE);
    *frameCount = (Uint8)CSL_FEXT (hTsip->DXCH[channelNumber].AFCNT, TSIP_XMTCHNCON_AFC_0_TXC0AFCOUNT);
    return;    
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUSetTxChannelBConfig
 *
 *   @b Description
 *   @n This function sets the transmit channel B configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Tx Channel Number 
            memoryBaseAddress   Memory Base Address
            frameAllocation     Frame Allocation 
            frameSize           Number of bytes to transfer for each frame
            frameCount          Number of frames in a buffer.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR;TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC;
 *      TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE;TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration for Tx Channel(B) 1 
        CSL_tsipTDMUSetTxChannelAConfig (hTsip, 1, 0x8000000, 0x1000, 0x128, 10);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUSetTxChannelBConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32          memoryBaseAddress,
    Uint16          frameAllocation,
    Uint16          frameSize,
    Uint8           frameCount
)
{
    /* Set the Transmit Channel B Configuration */
    CSL_FINS (hTsip->DXCH[channelNumber].BBASE, TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR, memoryBaseAddress);
    CSL_FINS (hTsip->DXCH[channelNumber].BFALLOC, TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC, frameAllocation);
    CSL_FINS (hTsip->DXCH[channelNumber].BFSIZE, TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE, frameSize);
    CSL_FINS (hTsip->DXCH[channelNumber].BFCNT, TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT, frameCount);
    return;    
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetTxChannelBConfig
 *
 *   @b Description
 *   @n This function gets the transmit channel B configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Tx Channel Number 
            memoryBaseAddress   Memory Base Address populated by this API
            frameAllocation     Frame Allocation populated by this API
            frameSize           Number of bytes to transfer for each frame populated by this API
            frameCount          Number of frames in a buffer populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR;TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC;
 *      TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE;TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              memoryBaseAddress;
        Uint16              frameAllocation;
        Uint16              frameSize;
        Uint8               frameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration for Tx Channel(B) 1 
        CSL_tsipTDMUGetTxChannelBConfig (hTsip, 1, &memoryBaseAddress, 
                                         &frameAllocation, &frameSize, &frameCount);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUGetTxChannelBConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32*         memoryBaseAddress,
    Uint16*         frameAllocation,
    Uint16*         frameSize,
    Uint8*          frameCount
)
{
    /* Get the Transmit Channel B Configuration */
    *memoryBaseAddress = (Uint32)CSL_FEXT (hTsip->DXCH[channelNumber].BBASE, TSIP_XMTCHNCON_BBA_0_TXC0BMEMBASEADR);
    *frameAllocation = (Uint16)CSL_FEXT (hTsip->DXCH[channelNumber].BFALLOC, TSIP_XMTCHNCON_BFA_0_TXC0BFRAMEALLOC);
    *frameSize  = (Uint16)CSL_FEXT (hTsip->DXCH[channelNumber].BFSIZE, TSIP_XMTCHNCON_BFS_0_TXC0BFSIZE);
    *frameCount = (Uint8)CSL_FEXT (hTsip->DXCH[channelNumber].BFCNT, TSIP_XMTCHNCON_BFC_0_TXC0BFCOUNT);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUSetRxChannelAConfig
 *
 *   @b Description
 *   @n This function sets the receive channel A configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Rx Channel Number 
            memoryBaseAddress   Memory Base Address
            frameAllocation     Frame Allocation 
            frameSize           Number of bytes to transfer for each frame
            frameCount          Number of frames in a buffer.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR;TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC;
 *      TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE;TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration for Rx Channel(A) 1 
        CSL_tsipTDMUSetRxChannelAConfig (hTsip, 1, 0x8000000, 0x1000, 0x128, 10);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUSetRxChannelAConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32          memoryBaseAddress,
    Uint16          frameAllocation,
    Uint16          frameSize,
    Uint8           frameCount
)
{
    /* Set the Transmit Channel A Configuration */
    CSL_FINS (hTsip->DRCH[channelNumber].ABASE, TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR, memoryBaseAddress);
    CSL_FINS (hTsip->DRCH[channelNumber].AFALLOC, TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC, frameAllocation);
    CSL_FINS (hTsip->DRCH[channelNumber].AFSIZE, TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE, frameSize);
    CSL_FINS (hTsip->DRCH[channelNumber].AFCNT, TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT, frameCount);
    return;
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetRxChannelAConfig
 *
 *   @b Description
 *   @n This function gets the receive channel A configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Rx Channel Number 
            memoryBaseAddress   Memory Base Address populated by this API
            frameAllocation     Frame Allocation populated by this API
            frameSize           Number of bytes to transfer for each frame populated by this API
            frameCount          Number of frames in a buffer populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR;TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC;
 *      TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE;TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              memoryBaseAddress;
        Uint16              frameAllocation;
        Uint16              frameSize;
        Uint8               frameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration for Rx Channel(A) 1 
        CSL_tsipTDMUGetRxChannelAConfig (hTsip, 1, &memoryBaseAddress, 
                                         &frameAllocation, &frameSize, &frameCount);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUGetRxChannelAConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32*         memoryBaseAddress,
    Uint16*         frameAllocation,
    Uint16*         frameSize,
    Uint8*          frameCount
)
{
    /* Get the Transmit Channel A Configuration */
    *memoryBaseAddress = (Uint32)CSL_FEXT (hTsip->DRCH[channelNumber].ABASE, TSIP_RCVCHNCON_ABA_0_RXC0AMEMBASEADR);
    *frameAllocation = (Uint16)CSL_FEXT (hTsip->DRCH[channelNumber].AFALLOC, TSIP_RCVCHNCON_AFA_0_RXC0AFRAMEALLOC);
    *frameSize  = (Uint16)CSL_FEXT (hTsip->DRCH[channelNumber].AFSIZE, TSIP_RCVCHNCON_AFS_0_RXC0AFSIZE);
    *frameCount = (Uint8)CSL_FEXT (hTsip->DRCH[channelNumber].AFCNT, TSIP_RCVCHNCON_AFC_0_RXC0AFCOUNT);
    return;    
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUSetRxChannelBConfig
 *
 *   @b Description
 *   @n This function sets the receive channel B configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Rx Channel Number 
            memoryBaseAddress   Memory Base Address
            frameAllocation     Frame Allocation 
            frameSize           Number of bytes to transfer for each frame
            frameCount          Number of frames in a buffer.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Writes
 *   @n TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR;TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC;
 *      TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE;TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Set the Configuration for Rx Channel(B) 1 
        CSL_tsipTDMUSetRxChannelBConfig (hTsip, 1, 0x8000000, 0x1000, 0x128, 10);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUSetRxChannelBConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32          memoryBaseAddress,
    Uint16          frameAllocation,
    Uint16          frameSize,
    Uint8           frameCount
)
{
    /* Set the Receive Channel B Configuration */
    CSL_FINS (hTsip->DRCH[channelNumber].BBASE, TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR, memoryBaseAddress);
    CSL_FINS (hTsip->DRCH[channelNumber].BFALLOC, TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC, frameAllocation);
    CSL_FINS (hTsip->DRCH[channelNumber].BFSIZE, TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE, frameSize);
    CSL_FINS (hTsip->DRCH[channelNumber].BFCNT, TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT, frameCount);
    return;    
}

/** ============================================================================
 *   @n@b CSL_tsipTDMUGetRxChannelBConfig
 *
 *   @b Description
 *   @n This function gets the receive channel B configuration 
 *
 *   @b Arguments
 *   @verbatim
            hTsip               Handle to TSIP instance
            channelNumber       Rx Channel Number 
            memoryBaseAddress   Memory Base Address populated by this API
            frameAllocation     Frame Allocation populated by this API
            frameSize           Number of bytes to transfer for each frame populated by this API
            frameCount          Number of frames in a buffer populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  @a CSL_tsipOpen() must be called successfully.
 *
 *   <b> Post Condition </b>
 *    @n None
 *
 *   @b Reads
 *   @n TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR;TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC;
 *      TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE;TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT
 *
 *   @b Example
 *   @verbatim
        CSL_TsipHandle      hTsip;
        Uint32              memoryBaseAddress;
        Uint16              frameAllocation;
        Uint16              frameSize;
        Uint8               frameCount;

        // Open the TSIP Module 0
        hTsip = CSL_tsipOpen(0);
        ...
        // Get the Configuration for Rx Channel(B) 1 
        CSL_tsipTDMUGetRxChannelBConfig (hTsip, 1, &memoryBaseAddress, 
                                         &frameAllocation, &frameSize, &frameCount);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_tsipTDMUGetRxChannelBConfig
(
    CSL_TsipHandle  hTsip, 
    Uint8           channelNumber,
    Uint32*         memoryBaseAddress,
    Uint16*         frameAllocation,
    Uint16*         frameSize,
    Uint8*          frameCount
)
{
    /* Get the Receive Channel B Configuration */
    *memoryBaseAddress = (Uint32)CSL_FEXT (hTsip->DRCH[channelNumber].BBASE, TSIP_RCVCHNCON_BBA_0_RXC0BMEMBASEADR);
    *frameAllocation = (Uint16)CSL_FEXT (hTsip->DRCH[channelNumber].BFALLOC, TSIP_RCVCHNCON_BFA_0_RXC0BFRAMEALLOC);
    *frameSize  = (Uint16)CSL_FEXT (hTsip->DRCH[channelNumber].BFSIZE, TSIP_RCVCHNCON_BFS_0_RXC0BFSIZE);
    *frameCount = (Uint8)CSL_FEXT (hTsip->DRCH[channelNumber].BFCNT, TSIP_RCVCHNCON_BFC_0_RXC0BFCOUNT);
    return;
}

/**
@}
*/
#ifdef __cplusplus
}
#endif

#endif /* CSL_TSIPAUX_H_ */


