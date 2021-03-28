/**
 * @file  csl_cpgmac_slAux.h
 *
 * @brief
 *  API Auxilary header file for Ethernet MAC submodule CSL.
 *
 *  Contains the different control command and status query functions definations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2016, Texas Instruments, Inc.
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

#ifndef CSL_CPGMAC_SLAUX_V2_H
#define CSL_CPGMAC_SLAUX_V2_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_cpgmac_sl.h>

/** @addtogroup CSL_CPGMAC_SL_FUNCTION
@{ */


/********************************************************************************
*************** Ethernet Media Access Controller (EMAC) Submodule ***************
********************************************************************************/

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getMacVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the MAC submodule identification and
 *      version information for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the source MAC address
                                must be read and returned.
        pVersionInfo            CSL_CPGMAC_SL_VERSION structure that needs to be populated
                                with the version info read from the hardware.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_IDVER_REG_Y,
 *      CPGMAC_SL_IDVER_REG_X,
 *      CPGMAC_SL_IDVER_REG_Z,
 *      CPGMAC_SL_IDVER_REG_IDENT
 *
 *   @b Example
 *   @verbatim
        CSL_CPGMAC_SL_VERSION    versionInfo, portNum;

        portNum =   1;

        CSL_CPGMAC_SL_getMacVersionInfo (portNum, &versionInfo);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_getMacVersionInfo
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
	CSL_CPGMAC_SL_VERSION*      pVersionInfo
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_getMacVersionInfo
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
	CSL_CPGMAC_SL_VERSION*      pVersionInfo
)
{

    pVersionInfo->minorVer  =   CSL_FEXT (hCpgmacSlRegs->IDVER_REG, CPGMAC_SL_IDVER_REG_Y);
    pVersionInfo->majorVer  =   CSL_FEXT (hCpgmacSlRegs->IDVER_REG, CPGMAC_SL_IDVER_REG_X);
    pVersionInfo->rtlVer    =   CSL_FEXT (hCpgmacSlRegs->IDVER_REG, CPGMAC_SL_IDVER_REG_Z);
    pVersionInfo->id        =   CSL_FEXT (hCpgmacSlRegs->IDVER_REG, CPGMAC_SL_IDVER_REG_IDENT);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isFullDuplexEnabled
 *
 *   @b Description
 *   @n This function indicates if Full duplex mode is enabled in the
 *      MAC control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must retrieve the
                                settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Full duplex mode enabled
 *	 @n  FALSE                  Half duplex mode enabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum;

        portNum =   1;
        if (CSL_CPGMAC_SL_isFullDuplexEnabled (portNum) == TRUE)
        {
            // full duplex mode enabled
        }
        else
        {
            // full duplex mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isFullDuplexEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isFullDuplexEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableFullDuplex
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable full duplex
 *      mode for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX=1
 *
 *   @b Example
 *   @verbatim
 *      Uint32      portNum =   1;

        CSL_CPGMAC_SL_enableFullDuplex (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableFullDuplex
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableFullDuplex
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableFullDuplex
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable full duplex
 *      mode for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX=0
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum = 1;

        CSL_CPGMAC_SL_disableFullDuplex (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableFullDuplex
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableFullDuplex
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_FULLDUPLEX, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isLoopbackModeEnabled
 *
 *   @b Description
 *   @n This function indicates if loopback mode is enabled in the
 *      MAC control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Internal full duplex lopoback mode enabled
 *	 @n  FALSE                  Loopback mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_LOOPBACK
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum = 1;

        if (CSL_CPGMAC_SL_isLoopbackModeEnabled (portNum) == TRUE)
        {
            // loopback mode enabled
        }
        else
        {
            // loopback mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isLoopbackModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isLoopbackModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_LOOPBACK);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableLoopback
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable lopback mode
 *      for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_LOOPBACK=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum = 1;

        CSL_CPGMAC_SL_enableLoopback (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableLoopback
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableLoopback
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_LOOPBACK, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableLoopback
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable loopback
 *      mode for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_LOOPBACK=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableLoopback (portNum);
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableLoopback
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableLoopback
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_LOOPBACK, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isRxFlowControlEnabled
 *
 *   @b Description
 *   @n This function indicates if receive flow control is enabled in the
 *      MAC control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Receive flow control enabled
 *	 @n  FALSE                  Receive flow control disabled
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum = 1;

        if (CSL_CPGMAC_SL_isRxFlowControlEnabled (portNum) == TRUE)
        {
            // rx flow control enabled
        }
        else
        {
            // rx flow control disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isRxFlowControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isRxFlowControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableRxFlowControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable receive flow
 *      control for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_enableRxFlowControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableRxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableRxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableRxFlowControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable Receive
 *      flow control mode for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableRxFlowControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableRxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableRxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_FLOW_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isTxFlowControlEnabled
 *
 *   @b Description
 *   @n This function indicates if transmit flow control is enabled in the
 *      MAC control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Transmit flow control enabled
 *	 @n  FALSE                  Transmit flow control disabled
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isTxFlowControlEnabled (portNum) == TRUE)
        {
            // tx flow control enabled
        }
        else
        {
            // tx flow control disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isTxFlowControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isTxFlowControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableTxFlowControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transmit
 *      flow control for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_enableTxFlowControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableTxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableTxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableTxFlowControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable Transmit
 *      flow control for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableTxFlowControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableTxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableTxFlowControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_FLOW_EN, (Uint32)0);

    return;
}


/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isGMIIEnabled
 *
 *   @b Description
 *   @n This function indicates if GMII is enabled in the MAC control register
 *      for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   GMII enabled
 *	 @n  FALSE                  GMII disabled
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_GMII_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isGMIIEnabled (portNum) == TRUE)
        {
            // gmii enabled
        }
        else
        {
            // gmii disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isGMIIEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isGMIIEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GMII_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableGMII
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable GMII for the
 *      MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GMII_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_enableGMII (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableGMII
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableGMII
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GMII_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableGMII
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable GMII for the
 *      MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GMII_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableGMII (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableGMII
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableGMII
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GMII_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isTxPaceEnabled
 *
 *   @b Description
 *   @n This function indicates if transmit pacing is enabled in the MAC
 *      control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Transmit pacing enabled
 *	 @n  FALSE                  Transmit pacing disabled
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_PACE
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isTxPaceEnabled (portNum) == TRUE)
        {
            // tx pacing enabled
        }
        else
        {
            // tx pacing disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isTxPaceEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isTxPaceEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_PACE);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableTxPace
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transmit
 *      pacing for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_PACE=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum = 1;

        CSL_CPGMAC_SL_enableTxPace (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableTxPace
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableTxPace
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_PACE, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableTxPace
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable transmit
 *      pacing for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_PACE=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum = 1;

        CSL_CPGMAC_SL_disableTxPace (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableTxPace
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableTxPace
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_PACE, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isGigabitEnabled
 *
 *   @b Description
 *   @n This function indicates if Gigabit mode is enabled in the MAC
 *      control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Gigabit mode enabled
 *	 @n  FALSE                  Gigabit disabled. 10/100 mode enabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum = 1;

        if (CSL_CPGMAC_SL_isGigabitEnabled (portNum) == TRUE)
        {
            // gig enabled
        }
        else
        {
            // gig disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isGigabitEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isGigabitEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableGigabit
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable Gigabit
 *      mode (full duplex only) for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_enableGigabit (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableGigabit
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableGigabit
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableGigabit
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable Gigabit mode
 *      for MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_disableGigabit (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableGigabit
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableGigabit
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isTxShortGapEnabled
 *
 *   @b Description
 *   @n This function indicates if Transmit short gap is enabled in the MAC
 *      control register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Transmit short gap with a short IPG enabled
 *	 @n  FALSE                  Transmit short gap disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE
 *
 *   @b Example
 *   @verbatim
 *      Uint32 portNum  =   1;

        if (CSL_CPGMAC_SL_isTxShortGapEnabled (portNum) == TRUE)
        {
            // Tx short gap enabled
        }
        else
        {
            // Tx short gap disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isTxShortGapEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isTxShortGapEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableTxShortGap
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transmit short
 *      gap for MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_enableTxShortGap (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableTxShortGap
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableTxShortGap
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableTxShortGap
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable transmit
 *      short gap for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_disableTxShortGap (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableTxShortGap
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableTxShortGap
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_TX_SHORT_GAP_ENABLE, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isIdleModeEnabled
 *
 *   @b Description
 *   @n This function indicates if Idle mode is enabled in the MAC
 *      control register for MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Idle mode enabled
 *	 @n  FALSE                  Idle mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_CMD_IDLE
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum = 1;

        if (CSL_CPGMAC_SL_isTxShortGapEnabled (portNum) == TRUE)
        {
            // idle mode enabled
        }
        else
        {
            // idle mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isIdleModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isIdleModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CMD_IDLE);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableIdleMode
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable Idle mode for
 *      MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_CMD_IDLE=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_enableIdleMode (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableIdleMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableIdleMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CMD_IDLE, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableIdleMode
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable Idle mode for
 *      MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_CMD_IDLE=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_disableIdleMode (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableIdleMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableIdleMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CMD_IDLE, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isIFCTLAEnabled
 *
 *   @b Description
 *   @n This function indicates if IFCTL_A bit is set in the MAC
 *      control register for MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   IFCTL_A bit in MAC control register is set to 1.
 *	 @n  FALSE                  IFCTL_A bit in MAC control register reads 0.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_A
 *
 *   @b Example
 *   @verbatim
 *      Uint32 portNum  =   1;

        if (CSL_CPGMAC_SL_isIFCTLAEnabled (portNum) == TRUE)
        {
            // IFCTL_A bit set
        }
        else
        {
            // IFCTL_A bit cleared
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isIFCTLAEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isIFCTLAEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_A);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableIFCTLA
 *
 *   @b Description
 *   @n This function enables the IFCTL_A bit in the MAC control register for MAC
 *      port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_A=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_enableIFCTLA (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableIFCTLA
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableIFCTLA
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_A, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableIFCTLA
 *
 *   @b Description
 *   @n This function configures the MAC control register to clear the IFCTL_A
 *      bit for MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_A=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableIFCTLA (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableIFCTLA
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableIFCTLA
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_A, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isIFCTLBEnabled
 *
 *   @b Description
 *   @n This function indicates if IFCTL_B bit is set in the MAC
 *      control register for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   IFCTL_B bit in MAC control register is set to 1.
 *	 @n  FALSE                  IFCTL_B bit in MAC control register reads 0.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_B
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isIFCTLBEnabled (portNum) == TRUE)
        {
            // IFCTL_B bit set
        }
        else
        {
            // IFCTL_B bit cleared
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isIFCTLBEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isIFCTLBEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_B);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableIFCTLB
 *
 *   @b Description
 *   @n This function enables the IFCTL_B bit in the MAC control register for the
 *      MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_B=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_enableIFCTLB (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableIFCTLB
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableIFCTLB
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_B, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableIFCTLB
 *
 *   @b Description
 *   @n This function configures the MAC control register to clear the IFCTL_B
 *      bit for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_IFCTL_B=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_disableIFCTLB (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableIFCTLB
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableIFCTLB
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_IFCTL_B, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isGigForceModeEnabled
 *
 *   @b Description
 *   @n This function indicates if Gigabit mode force bit is enabled in the MAC
 *      control register for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Gigabit mode force enabled.
 *	 @n  FALSE                  Gigabit mode force disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG_FORCE
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isGigForceModeEnabled (portNum) == TRUE)
        {
            // gig mode force enabled
        }
        else
        {
            // gig mode force disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isGigForceModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isGigForceModeEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG_FORCE);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableGigForceMode
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable Gigabit
 *      force mode for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG_FORCE=1
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_enableGigForceMode (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableGigForceMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableGigForceMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG_FORCE, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableGigForceMode
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable Gigabit
 *      force mode for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_GIG_FORCE=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableGigForceMode (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableGigForceMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableGigForceMode
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_GIG_FORCE, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isExtControlEnabled
 *
 *   @b Description
 *   @n This function indicates if EXT_EN bit is enabled in the MAC control
 *      register for the MAC port specified. When this bit is set to 1, the Gigabit
 *      and Full duplex mode input is taken from an external source and not from
 *      the settings configured in this register.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   External control mode enabled.
 *	 @n  FALSE                  External control mode disabled.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_CTL_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isExtControlEnabled (portNum) == TRUE)
        {
            // external control mode enabled
        }
        else
        {
            // external control mode disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isExtControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isExtControlEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CTL_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableExtControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable external
 *      control of the Gigabit and full duplex mode settings.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_CTL_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_enableExtControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableExtControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableExtControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CTL_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableExtControl
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable external
 *      control of the Gigabit and full duplex settings.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_CTL_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_disableExtControl (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableExtControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableExtControl
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_CTL_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isRxCEFEnabled
 *
 *   @b Description
 *   @n This function indicates if MAC control register is programmed to copy
 *      frames containing errors to its memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Copy Error frames mode enabled. Error frames
 *	                            will be transferred to memory.
 *	 @n  FALSE                  Copy Error frames mode disabled. Error frames
 *	                            will be filtered.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN
 *
 *   @b Example
 *   @verbatim
 *      Uint32  portNum =   1;

        if (CSL_CPGMAC_SL_isRxCEFEnabled (portNum) == TRUE)
        {
            // Rx CEF enabled
        }
        else
        {
            // Rx CEF disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isRxCEFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isRxCEFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableRxCEF
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transfer
 *      of frames containing errors.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_enableRxCEF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableRxCEF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableRxCEF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableRxCEF
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable any error
 *      frames being transferred to the memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_disableRxCEF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableRxCEF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableRxCEF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CEF_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isRxCSFEnabled
 *
 *   @b Description
 *   @n This function indicates if MAC control register is programmed to copy
 *      short frames (frames shorter than 64 bytes) to its memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Copy Short frames mode enabled. Short frames
 *	                            will be transferred to memory.
 *	 @n  FALSE                  Copy Short frames mode disabled. Short frames
 *	                            will be filtered.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        if (CSL_CPGMAC_SL_isRxCSFEnabled (portNum) == TRUE)
        {
            // Rx CSF enabled
        }
        else
        {
            // Rx CSF disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isRxCSFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isRxCSFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableRxCSF
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transfer
 *      of frames that are shorter than 64 bytes.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_enableRxCSF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableRxCSF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableRxCSF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableRxCSF
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable any short
 *      frames being transferred to the memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_disableRxCSF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableRxCSF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableRxCSF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CSF_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isRxCMFEnabled
 *
 *   @b Description
 *   @n This function indicates if MAC control register is programmed to copy
 *      MAC Control Frames to its memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE                   Copy MAC control frames mode enabled. MAC control
 *	                            frames will be transferred to memory.
 *	 @n  FALSE                  Copy MAC control frames mode disabled. MAC control
 *	                            frames will be filtered.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        if (CSL_CPGMAC_SL_isRxCMFEnabled (portNum) == TRUE)
        {
            // Rx CMF enabled
        }
        else
        {
            // Rx CMF disabled
        }
	 @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isRxCMFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isRxCMFEnabled
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{

    return CSL_FEXT (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_enableRxCMF
 *
 *   @b Description
 *   @n This function configures the MAC control register to enable transfer
 *      of MAC control frames.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum = 1;

        CSL_CPGMAC_SL_enableRxCMF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_enableRxCMF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_enableRxCMF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_disableRxCMF
 *
 *   @b Description
 *   @n This function configures the MAC control register to disable any MAC control
 *      frames being transferred to the memory.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN=0
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum =   1;

        CSL_CPGMAC_SL_disableRxCMF (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_disableRxCMF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_disableRxCMF
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->MACCONTROL_REG, CPGMAC_SL_MACCONTROL_REG_RX_CMF_EN, (Uint32)0);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getMacControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of MAC control register in entirety.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                MAC control register contents.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACCONTROL_REG
 *
 *   @b Example
 *   @verbatim
        Uint32          macControlVal, portNum = 1;

        macControlVal   =   CSL_CPGMAC_SL_getMacControlReg (portNum);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_getMacControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_getMacControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return hCpgmacSlRegs->MACCONTROL_REG;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setMacControlReg
 *
 *   @b Description
 *   @n This function configures the contents of MAC control register in entirety.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the reset must be performed.
        macControlRegVal    value to be configured to the MAC control register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_MACCONTROL_REG
 *
 *   @b Example
 *   @verbatim
        Uint32          macControlVal, portNum = 1;

        macControlVal   =   CSL_CPGMAC_SL_getMacControlReg ();

        // Enable full duplex, giagbit mode too
        macControlVal   |=  CSL_CPGMAC_SL_MACCONTROL_FULLDUPLEX_EN |
                            CSL_CPGMAC_SL_MACCONTROL_GMII_EN;

        CSL_CPGMAC_SL_setMacControlReg (macControlVal, portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_setMacControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  macControlRegVal
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_setMacControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  macControlRegVal
)
{
    hCpgmacSlRegs->MACCONTROL_REG   =   macControlRegVal;

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getMacStatusReg
 *
 *   @b Description
 *   @n This function retrieves the contents of MAC status register.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
        pMacStatus              CSL_CPGMAC_SL_MACSTATUS structure to be populated with
                                the contents of MAC status register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_MACSTATUS_REG_TX_FLOW_ACT,
 *      CPGMAC_SL_MACSTATUS_REG_RX_FLOW_ACT,
 *      CPGMAC_SL_MACSTATUS_REG_EXT_FULLDUPLEX,
 *      CPGMAC_SL_MACSTATUS_REG_EXT_GIG,
 *      CPGMAC_SL_MACSTATUS_REG_IDLE
 *
 *   @b Example
 *   @verbatim
        CSL_CPGMAC_SL_MACSTATUS      macStatus;
        Uint32                       portNum = 1;

        CSL_CPGMAC_SL_getMacStatusReg (portNum, &macStatus);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_getMacStatusReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    CSL_CPGMAC_SL_MACSTATUS*    pMacStatus
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_getMacStatusReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    CSL_CPGMAC_SL_MACSTATUS*    pMacStatus
)
{
    Uint32                      macStatusVal;

    macStatusVal                        =   hCpgmacSlRegs->MACSTATUS_REG;
    pMacStatus->txFlowActive            =   CSL_FEXT (macStatusVal, CPGMAC_SL_MACSTATUS_REG_TX_FLOW_ACT);
    pMacStatus->rxFlowActive            =   CSL_FEXT (macStatusVal, CPGMAC_SL_MACSTATUS_REG_RX_FLOW_ACT);
    pMacStatus->extFullDuplexEnabled    =   CSL_FEXT (macStatusVal, CPGMAC_SL_MACSTATUS_REG_EXT_FULLDUPLEX);
    pMacStatus->extGigabitEnabled       =   CSL_FEXT (macStatusVal, CPGMAC_SL_MACSTATUS_REG_EXT_GIG);
    pMacStatus->idleEnabled             =   CSL_FEXT (macStatusVal, CPGMAC_SL_MACSTATUS_REG_IDLE);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_resetMac
 *
 *   @b Description
 *   @n This function issues a software reset to the MAC for the MAC port number
 *      specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the reset must be performed.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_SOFT_RESET_REG_SOFT_RESET=1
 *
 *   @b Example
 *   @verbatim
        Uint32 portNum  =   1;

        CSL_CPGMAC_SL_resetMac (portNum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_resetMac
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_resetMac
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    CSL_FINS (hCpgmacSlRegs->SOFT_RESET_REG, CPGMAC_SL_SOFT_RESET_REG_SOFT_RESET, (Uint32)1U);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_isMACResetDone
 *
 *   @b Description
 *   @n This function reads the MAC Soft Reset register to check if the software
 *      reset operation has completed.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 TRUE               MAC Soft reset done.
 *	 @n  FALSE              MAC Soft reset not yet completed.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_SOFT_RESET_REG_SOFT_RESET
 *
 *   @b Example
 *   @verbatim
        Uint32  portNum = 1;

        CSL_CPGMAC_SL_resetMac (portNum);

        // Wait until MAC software reset completes
        while (!CSL_CPGMAC_SL_isMACResetDone (portNum));

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_isMACResetDone
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_isMACResetDone
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    Uint32 ret_val;
    if (CSL_FEXT (hCpgmacSlRegs->SOFT_RESET_REG, CPGMAC_SL_SOFT_RESET_REG_SOFT_RESET) == 0)
    {
        ret_val = (Uint32)TRUE;
    }
    else
    {
        ret_val = (Uint32)FALSE;
    }
    return ret_val;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getRxMaxLen
 *
 *   @b Description
 *   @n This function retrieves the Receive maximum frame length configured in
 *      Receive Maximum length register for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                Receive maximum frame length read.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
        Uint32          mtu, portNum = 1;

        mtu =   CSL_CPGMAC_SL_getRxMaxLen (portNum);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_getRxMaxLen
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_getRxMaxLen
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return CSL_FEXT (hCpgmacSlRegs->RX_MAXLEN_REG, CPGMAC_SL_RX_MAXLEN_REG_RX_MAXLEN);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setRxMaxLen
 *
 *   @b Description
 *   @n This function sets up the Receive maximum frame length in Receive Maximum
 *      length register for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_RX_MAXLEN_REG_RX_MAXLEN
 *
 *   @b Example
 *   @verbatim
        Uint32          mtu, portNum = 1;

        mtu =   1518;

        CSL_CPGMAC_SL_setRxMaxLen (portNum, mtu);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_setRxMaxLen
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  rxMaxLen
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_setRxMaxLen
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  rxMaxLen
)
{
    return CSL_FINS (hCpgmacSlRegs->RX_MAXLEN_REG, CPGMAC_SL_RX_MAXLEN_REG_RX_MAXLEN, rxMaxLen);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getRxPauseTimerReg
 *
 *   @b Description
 *   @n This function retrieves the Receive pause timer value configured in
 *      Receive pause timer register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                Receive pause timer value read.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER
 *
 *   @b Example
 *   @verbatim
        Uint32          rxPauseTimer, portNum = 1;

        rxPauseTimer =   CSL_CPGMAC_SL_getRxPauseTimerReg (portNum);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_getRxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_getRxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return CSL_FEXT (hCpgmacSlRegs->RX_PAUSE_REG, CPGMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setRxPauseTimerReg
 *
 *   @b Description
 *   @n This function sets up the Receive pause timer value in Receive pause
 *      timer register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER
 *
 *   @b Example
 *   @verbatim
        Uint32          rxPauseTimer = 2, portNum = 1;

        CSL_CPGMAC_SL_setRxPauseTimerReg (portNum, rxPauseTimer);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_setRxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  rxPauseTimer
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_setRxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  rxPauseTimer
)
{
    return CSL_FINS (hCpgmacSlRegs->RX_PAUSE_REG, CPGMAC_SL_RX_PAUSE_REG_RX_PAUSETIMER, rxPauseTimer);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getTxPauseTimerReg
 *
 *   @b Description
 *   @n This function retrieves the Transmit pause timer value configured in
 *      Transmit pause timer register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API must
                                retrieve the settings.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 >=0                Transmit pause timer value read.
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER
 *
 *   @b Example
 *   @verbatim
        Uint32          txPauseTimer, portNum = 1;

        txPauseTimer =   CSL_CPGMAC_SL_getTxPauseTimerReg (portNum);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_getTxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_getTxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs
)
{
    return CSL_FEXT (hCpgmacSlRegs->TX_PAUSE_REG, CPGMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setTxPauseTimerReg
 *
 *   @b Description
 *   @n This function sets up the Transmit pause timer value in Transmit pause
 *      timer register for the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the settings must be configured.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER
 *
 *   @b Example
 *   @verbatim
        Uint32          txPauseTimer = 2, portNum = 1;

        CSL_CPGMAC_SL_setTxPauseTimerReg (portNum, txPauseTimer);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_CPGMAC_SL_setTxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  txPauseTimer
);/* for misra warnings*/
static inline Uint32 CSL_CPGMAC_SL_setTxPauseTimerReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  txPauseTimer
)
{
    return CSL_FINS (hCpgmacSlRegs->TX_PAUSE_REG, CPGMAC_SL_TX_PAUSE_REG_TX_PAUSETIMER, txPauseTimer);
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getEmulControlReg
 *
 *   @b Description
 *   @n This function retrieves the contents of Emulation control register for
 *      the MAC port number specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port number for which the API should retrieve
                            emulation settings for.
        pEmulFreeBit        Emulation free bit.
        pEmulSoftBit        Emulation soft bit.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_EMCONTROL_REG_FREE,
 *      CPGMAC_SL_EMCONTROL_REG_SOFT
 *
 *   @b Example
 *   @verbatim
        Uint32          emulSoftBit, emulFreeBit, portNum = 1;

        CSL_CPGMAC_SL_getEmulControlReg (portNum, &emulFreeBit, &emulSoftBit);
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_getEmulControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                 pEmulFreeBit,
    Uint32*                 pEmulSoftBit
); /* for misra warnings */
static inline void CSL_CPGMAC_SL_getEmulControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                 pEmulFreeBit,
    Uint32*                 pEmulSoftBit
)
{
    *pEmulFreeBit   =   CSL_FEXT (hCpgmacSlRegs->EMCONTROL_REG, CPGMAC_SL_EMCONTROL_REG_FREE);
    *pEmulSoftBit   =   CSL_FEXT (hCpgmacSlRegs->EMCONTROL_REG, CPGMAC_SL_EMCONTROL_REG_SOFT);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setEmulControlReg
 *
 *   @b Description
 *   @n This function sets up the contents of Emulation control register for the
 *      MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum             MAC port for which the settings must be configured.
        emulFreeBit         Emulation free bit.
        emulSoftBit         Emulation soft bit.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_EMCONTROL_REG_FREE,
 *      CPGMAC_SL_EMCONTROL_REG_SOFT
 *
 *   @b Example
 *   @verbatim
        Uint32          emulSoftBit, emulFreeBit, portNum = 1;

        emulFreeBit =   1;
        emulSoftBit =   0;

        CSL_CPGMAC_SL_setEmulControlReg (portNum, emulFreeBit, emulSoftBit);
     @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_setEmulControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  emulFreeBit,
    Uint32                  emulSoftBit
); /* for misra warnings */
static inline void CSL_CPGMAC_SL_setEmulControlReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32                  emulFreeBit,
    Uint32                  emulSoftBit
)
{
    CSL_FINS (hCpgmacSlRegs->EMCONTROL_REG, CPGMAC_SL_EMCONTROL_REG_FREE, emulFreeBit);
    CSL_FINS (hCpgmacSlRegs->EMCONTROL_REG, CPGMAC_SL_EMCONTROL_REG_SOFT, emulSoftBit);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_getMacRxPriMapReg
 *
 *   @b Description
 *   @n This function retrieves the contents of the MAC Receive Packet Priority to
 *      Header Priority Mapping Register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port number for which the API should retrieve
                                settings for.
        pMacRxPriMap            Array of MAC Rx packet priority map priority values
                                read from the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  The input parameter 'pMacRxPriMap' must be large enough to hold all
 *       the 8 priority values read from the register.
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n CPGMAC_SL_PRI_MAP_REG_PRI0,
 *      CPGMAC_SL_PRI_MAP_REG_PRI1,
 *      CPGMAC_SL_PRI_MAP_REG_PRI2,
 *      CPGMAC_SL_PRI_MAP_REG_PRI3,
 *      CPGMAC_SL_PRI_MAP_REG_PRI4,
 *      CPGMAC_SL_PRI_MAP_REG_PRI5,
 *      CPGMAC_SL_PRI_MAP_REG_PRI6,
 *      CPGMAC_SL_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      pPortRxPriMap [8], portNum = 1;

        CSL_CPGMAC_SL_getMacRxPriMapReg (portNum, pPortRxPriMap);

	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_getMacRxPriMapReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                     pMacRxPriMap
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_getMacRxPriMapReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                     pMacRxPriMap
)
{
    pMacRxPriMap [0]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI0);
    pMacRxPriMap [1]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI1);
    pMacRxPriMap [2]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI2);
    pMacRxPriMap [3]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI3);
    pMacRxPriMap [4]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI4);
    pMacRxPriMap [5]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI5);
    pMacRxPriMap [6]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI6);
    pMacRxPriMap [7]    =   CSL_FEXT (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI7);

    return;
}

/** ============================================================================
 *   @n@b CSL_CPGMAC_SL_setMacRxPriMapReg
 *
 *   @b Description
 *   @n This function sets up the contents of the MAC Receive Packet Priority
 *      to Header Priority Mapping Register for the MAC port specified.
 *
 *   @b Arguments
     @verbatim
        portNum                 MAC port for which the settings must be configured.
        pMacRxPriMap            Array of MAC Rx priority map priority values
                                that must be configured to the register.
 *	 @endverbatim
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Writes
 *   @n CPGMAC_SL_PRI_MAP_REG_PRI0,
 *      CPGMAC_SL_PRI_MAP_REG_PRI1,
 *      CPGMAC_SL_PRI_MAP_REG_PRI2,
 *      CPGMAC_SL_PRI_MAP_REG_PRI3,
 *      CPGMAC_SL_PRI_MAP_REG_PRI4,
 *      CPGMAC_SL_PRI_MAP_REG_PRI5,
 *      CPGMAC_SL_PRI_MAP_REG_PRI6,
 *      CPGMAC_SL_PRI_MAP_REG_PRI7
 *
 *   @b Example
 *   @verbatim
 *      Uint32      i, pMacRxPriMap [8], portNum = 1;

        for (i = 0; i < 8; i ++)
            pMacRxPriMap [i] = i;

        CSL_CPGMAC_SL_setMacRxPriMapReg (portNum, pMacRxPriMap);
	 @endverbatim
 * =============================================================================
 */
static inline void CSL_CPGMAC_SL_setMacRxPriMapReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                     pMacRxPriMap
);/* for misra warnings*/
static inline void CSL_CPGMAC_SL_setMacRxPriMapReg
(
    CSL_cpgmacSlHandle          hCpgmacSlRegs,
    Uint32*                     pMacRxPriMap
)
{
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI0, pMacRxPriMap [0]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI1, pMacRxPriMap [1]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI2, pMacRxPriMap [2]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI3, pMacRxPriMap [3]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI4, pMacRxPriMap [4]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI5, pMacRxPriMap [5]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI6, pMacRxPriMap [6]);
    CSL_FINS (hCpgmacSlRegs->PRI_MAP_REG, CPGMAC_SL_PRI_MAP_REG_PRI7, pMacRxPriMap [7]);

    return;
}

#ifdef __cplusplus
}
#endif

#endif

/**
@}
*/
