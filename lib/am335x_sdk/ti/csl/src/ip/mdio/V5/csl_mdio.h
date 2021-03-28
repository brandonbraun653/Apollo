/**
 * @file csl_mdio.h
 *
 * @brief
 *  Header file for functional layer of CSL MDIO Version 5
 *
 *  It contains the various enumerations, structure definitions and function
 *  declarations
 *
 *  ============================================================================
 *  @n   (C) Copyright 2018-2019, Texas Instruments, Inc.
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
 * @defgroup CSL_MDIO_API_V5 MDIO - V5
 * @ingroup CSL_MDIO_API
 */
/**
@defgroup CSL_MDIO_SYMBOL  Symbols Defined
@ingroup CSL_MDIO_API_V5
*/
/**
@defgroup CSL_MDIO_DATASTRUCT   Data Structures
@ingroup CSL_MDIO_API_V5
*/
/**
@defgroup CSL_MDIO_FUNCTION  Functions
@ingroup CSL_MDIO_API_V5
*/
/**
@defgroup CSL_MDIO_ENUM Enumerated Data Types
@ingroup CSL_MDIO_API_V5
*/
#ifndef CSL_MDIO_V5_H
#define CSL_MDIO_V5_H

#ifdef __cplusplus
extern "C" {
#endif


#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_mdio.h>


/** @addtogroup CSL_MDIO_DATASTRUCT
 @{ */


/**
@}
*/

#include <string.h>
#include <stdbool.h>
#include <ti/csl/cslr.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mdio_def.h>

typedef volatile CSL_MdioRegs             *CSL_mdioHandle;

/** @addtogroup CSL_MDIO_FUNCTION
@{ */

/** ============================================================================
 *   @n@b CSL_MDIO_getVersionInfo
 *
 *   @b Description
 *   @n This function retrieves the MDIO version information.
 *
 *   @b Arguments
     @verbatim
        mdioVersionInfo     CSL_MDIO_VERSION structure that needs to be populated
                            with the version info read from the hardware.
 *     @endverbatim
 *
 *   <b> Return Value </b>
 *     @n     None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_VERSION_REG_REVMINOR,
 *      MDIO_VERSION_REG_REVMAJ,
 *      MDIO_VERSION_REG_MODID
 *
 *   @b Example
 *   @verbatim
        CSL_MDIO_VERSION    mdioVersionInfo;

        CSL_MDIO_getVersion (&mdioVersionInfo);

     @endverbatim
 *
 =================================================================================================
 */
void CSL_MDIO_getVersionInfo(
        CSL_mdioHandle          hMdioRegs,
        CSL_MDIO_VERSION*       mdioVersionInfo
);


/**
=================================================================================================
 *   @n@b CSL_MDIO_getClkDivVal
 *
 *   @b Description
 *   @n This function retrieves the clock divider value (CLKDIV) from the
 *      MDIO control register.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_CONTROL_REG_CLKDIV
 *
 *   @b Example
 *   @verbatim
 *      uint16_t      clkDivVal;

        clkDivVal   =   CSL_MDIO_getClkDivVal ();

     @endverbatim
 * =============================================================================
 */
uint16_t CSL_MDIO_getClkDivVal(
        CSL_mdioHandle          hMdioRegs
);


/** ============================================================================
 *   @n@b CSL_MDIO_setClkDivVal
 *
 *   @b Description
 *   @n This function configures the clock divider value (CLKDIV) in the
 *      MDIO control register with the value specified.
 *
 *   @b Arguments
     @verbatim
        clkDivVal           The value to use for clock divider configuration.
                            When this set to 0, the MDIO clock is disabled.
 *     @endverbatim
 *
 *   <b> Return Value </b>
 *     @n     None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  CONTROL_REG configured with the clock divider value. Configures the MDIO
 *       clock frequency.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_CLKDIV
 *
 *   @b Example
 *   @verbatim
 *      uint16_t      clkDivVal;

        clkDivVal = 165;

        // Setup the MDIO clock frequency
        CSL_MDIO_setClkDivVal (clkDivVal);

     @endverbatim
 * =============================================================================
 */
void CSL_MDIO_setClkDivVal(
        CSL_mdioHandle          hMdioRegs,
        uint16_t                 clkDivVal
);

/** ============================================================================
 *   @n@b CSL_MDIO_isStateMachineEnabled
 *
 *   @b Description
 *   @n This function returns the value of the Enable bit of the MDIO control
 *      register. It returns 1 to indicate that the MDIO state machine is enabled
 *      and is active and 0 to indicate otherwise.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_CONTROL_REG_ENABLE
 *
 *   @b Example
 *   @verbatim

        if (CSL_MDIO_isStateMachineEnabled ())
        {
            // MDIO state machine enabled
        }
        else
        {
            // MDIO state machine disabled
        }

     @endverbatim
 * =============================================================================
 */
 uint32_t CSL_MDIO_isStateMachineEnabled(
        CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_enableStateMachine
 *
 *   @b Description
 *   @n This function enables the MDIO state machine if not already active.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *     @n     None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Enables MDIO State machine.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_ENABLE
 *
 *   @b Example
 *   @verbatim
 *
        // Enable MDIO state machine
        CSL_MDIO_enableStateMachine ();

     @endverbatim
 * =============================================================================
 */
void CSL_MDIO_enableStateMachine(
        CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_disableStateMachine
 *
 *   @b Description
 *   @n This function sets the 'ENABLE' bit of the MDIO control register to 0,
 *      triggering the disable of MDIO state machine if active.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *     @n     None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  If the MDIO state machine is active at the time it is disabled, will
 *       complete the current operation before halting it and setting the
 *       idle bit.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_ENABLE=0
 *
 *   @b Example
 *   @verbatim
 *
        // Disable MDIO state machine
        CSL_MDIO_disableStateMachine ();

     @endverbatim
 * =============================================================================
 */
void CSL_MDIO_disableStateMachine(
        CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_isPhyAlive
 *
 *   @b Description
 *   @n For a given PHY address provided to this function in 'phyAddr',  this function
 *      reads the 'ALIVE' bit corresponding to that PHY; The function returns 1 to
 *      indicate that the most recent access for the address was acknowledged by the
 *      PHY and 0 otherwise.
 *
 *   @b Arguments
 *   @verbatim
 *      phyAddr             The PHY address number (0-31) for which the alive bit
 *                          status must be checked and returned by this function.
 *   @endverbatim
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_ALIVE_REG
 *
 *   @b Example
 *   @verbatim
 *      uint32_t      phyAddr = 0;

        // Check if PHY Address 0 is alive
        if (CSL_MDIO_isPhyAlive (phyAddr))
        {
            // MDIO PHY 0 access succeeded
        }
        else
        {
            // MDIO PHY 0 access failed
        }

     @endverbatim
 * =============================================================================
 */
uint32_t CSL_MDIO_isPhyAlive(
        CSL_mdioHandle          hMdioRegs,
        uint32_t                  phyAddr
);


/** ============================================================================
 *   @n@b CSL_MDIO_isPhyLinked
 *
 *   @b Description
 *   @n For a given PHY address provided to this function in 'phyAddr',  this function
 *      reads the 'LINK' bit corresponding to that PHY; The function returns 1 to
 *      indicate that the corresponding PHY address has a link.
 *
 *   @b Arguments
 *   @verbatim
 *      phyAddr             The PHY address number (0-31) for which the link bit
 *                          status must be checked and returned by this function.
 *   @endverbatim
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_LINK_REG
 *
 *   @b Example
 *   @verbatim
 *      uint32_t      phyAddr = 0;

        // Check if PHY Address 0 link is up
        if (CSL_MDIO_isPhyLinked (phyAddr))
        {
            // MDIO PHY 0 link up
        }
        else
        {
            // MDIO PHY 0 link not up
        }

     @endverbatim
 * =============================================================================
 */
uint32_t CSL_MDIO_isPhyLinked(
        CSL_mdioHandle          hMdioRegs,
        uint32_t                  phyAddr
);

/** ============================================================================
 *   @n@b CSL_MDIO_isUnmaskedLinkStatusChangeIntSet
 *
 *   @b Description
 *   @n For a given PHY selector(0-1) provided corresponding to the PHY address
 *      in USERPHYSEL register, this function returns the 'LINKINTRAW' register
 *      contents corresponding to it. This functions returns a 1 to indicate that
 *      the link status has changed for the PHY provided and 0 otherwise.
 *
 *   @b Arguments
 *   @verbatim
 *      index              The PHY selector (0-1) for which the link status change
 *                          bit must be read. Phy selector value 0 corresponds to the
 *                          PHY address programmed in USERPHYSEL0 register and a Phy
 *                          selector value 1 corresponds to the PHY address in
 *                          USERPHYSEL1 register.
 *   @endverbatim
 *
 *   <b> Return Value </b>  uint32_t
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Reads
 *   @n MDIO_ALIVE_REG
 *
 *   @b Example
 *   @verbatim
 *      uint32_t      index = 0;

        if (CSL_MDIO_isUnmaskedLinkStatusChangeIntSet (index))
        {
            // Link status has changed
        }
        else
        {
            // Link status has not changed
        }
        }

     @endverbatim
 * =============================================================================
 */
uint32_t CSL_MDIO_isUnmaskedLinkStatusChangeIntSet(
        CSL_mdioHandle          hMdioRegs,
        uint32_t                  index
);


/** ============================================================================
 *   @n@b CSL_MDIO_clearUnmaskedLinkStatusChangeInt
 *
 *   @b Description
 *   @n For a given PHY selector(0-1) provided corresponding to the PHY address
 *      in USERPHYSEL register, this function clears the 'LINKINTRAW' register
 *      contents corresponding to it.
 *
 *   @b Arguments
 *   @verbatim
 *      index              The PHY selector (0-1) for which the link status change
 *                          bit must be read. Phy selector value 0 corresponds to the
 *                          PHY address programmed in USERPHYSEL0 register and a Phy
 *                          selector value 1 corresponds to the PHY address in
 *                          USERPHYSEL1 register.
 *   @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Clears the Link change interrupt.
 *
 *   @b Writes
 *   @n MDIO_LINK_INT_RAW_REG
 *
 *   @b Example
 *   @verbatim
 *      uint32_t      index = 0;

        CSL_MDIO_clearUnmaskedLinkStatusChangeInt (index);
     @endverbatim
 * =============================================================================
 */
void CSL_MDIO_clearUnmaskedLinkStatusChangeInt(
        CSL_mdioHandle          hMdioRegs,
        uint32_t                  index
);

/** ============================================================================
 *   @n@b CSL_MDIO_phyRegRead
 *
 * \param   baseAddr      Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 * \param   regNum   Register Number to be read.
 * \param   pData    Pointer where the read value shall be written.
 *
 * \retval  TRUE     Read is successful.
 * \retval  FALSE    Read is not acknowledged properly.
 *
 * =============================================================================
 */
uint32_t  CSL_MDIO_phyRegRead(uint32_t baseAddr,
                    uint32_t phyAddr,
                    uint32_t regNum,
                    uint16_t *pData);

/** ============================================================================
 *   @n@b CSL_MDIO_phyRegWrite
 *
 * \brief   This API writes a PHY register using MDIO.
 *
 * \param   baseAddr      Base Address of the MDIO module.
 * \param   phyAddr       PHY Address.
 * \param   regNum        Register Number to be written.
 * \param   wrVal         Value to be written.
 *
 * =============================================================================
 */
void CSL_MDIO_phyRegWrite(uint32_t baseAddr, uint32_t phyAddr, uint32_t regNum, uint16_t wrVal);

/** ============================================================================
 *   @n@b CSL_MDIO_phyLinkStatus
 *
 * \brief   This API reads the link status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          link is active.
 *
 * \param   baseAddr Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 *
 * \return  TRUE   PHY link is active.
 * \return  FALSE  PHY link is inactive.
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_phyLinkStatus(uint32_t baseAddr, uint32_t phyAddr);

/** ============================================================================
 * @n@b CSL_MDIO_enableLinkStatusChangeInterrupt
 *
 * \brief Enable MDIO link interrupt (MDIO_LINKINT) for PHY monitoring
 *
 * This function enables the MDIO link interrupt (MDIO_LINKINT).  This function
 * is applicable only when MDIO is operating in Normal Mode.
 *
 * In Normal Mode, MDIO_LINKINT[0] event is set upon link change on the first
 * PHY being monitored. MDIO_LINKINT[1] event is set upon link change on the
 * second PHY being monitored.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 * \param   index          User group index (0 or 1)
 * \param   phyAddr        PHY address
 *
 * =============================================================================
 */
void CSL_MDIO_enableLinkStatusChangeInterrupt(
    CSL_mdioHandle hMdioRegs,
    Uint32 index,
    Uint32 phyAddr
);

/** ============================================================================
 * @n@b CSL_MDIO_disableLinkStatusChangeInterrupt
 *
 * \brief Disable MDIO link interrupt (MDIO_LINKINT) for PHY monitoring
 *
 * This function disables the MDIO link interrupt (MDIO_LINKINT).  This function
 * is applicable only when MDIO is operating in Normal Mode.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 * \param   index          User group index (0 or 1)
 * \param   phyAddr        PHY address
 *
 * =============================================================================
 */
void CSL_MDIO_disableLinkStatusChangeInterrupt(
    CSL_mdioHandle hMdioRegs,
    Uint32 index,
    Uint32 phyAddr
);

/** ============================================================================
 *   @n@b CSL_MDIO_enableFaultDetect
 *
 *   @b Description
 *   @n This function enables the Physical layer fault detection mechanism by
 *      setting 'FAULTENB' bit of the MDIO Control register to 1.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Enables PHY layer fault detection.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_FAULT_DETECT_ENABLE=1
 *
 *   @b Example
 *   @verbatim
 *
        // Enable Phy Layer fault detection
        CSL_MDIO_enableFaultDetect ();

     @endverbatim
 * =============================================================================
 */

void CSL_MDIO_enableFaultDetect (
    CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_disableFaultDetect
 *
 *   @b Description
 *   @n This function disables the Physical layer fault detection mechanism by
 *      setting 'FAULTENB' bit of the MDIO Control register to 0.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Disables PHY layer fault detection.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_FAULT_DETECT_ENABLE=0
 *
 *   @b Example
 *   @verbatim
 *
        // Disable Phy Layer fault detection
        CSL_MDIO_disableFaultDetect ();

     @endverbatim
 * =============================================================================
 */

void CSL_MDIO_disableFaultDetect (
    CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_enablePreamble
 *
 *   @b Description
 *   @n This function enables the MDIO preamble.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Enables MDIO Preamble frames.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_PREAMBLE=0
 *
 *   @b Example
 *   @verbatim
 *
        // Enable MDIO preamble frames
        CSL_MDIO_enablePreamble ();

     @endverbatim
 * =============================================================================
 */

void CSL_MDIO_enablePreamble (
    CSL_mdioHandle          hMdioRegs
);

/** ============================================================================
 *   @n@b CSL_MDIO_disablePreamble
 *
 *   @b Description
 *   @n This function disables the MDIO preamble.
 *
 *   @b Arguments   None
 *
 *   <b> Return Value </b>
 *	 @n	 None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Disables MDIO Preamble frames.
 *
 *   @b Writes
 *   @n MDIO_CONTROL_REG_PREAMBLE=1
 *
 *   @b Example
 *   @verbatim
 *
        // Disable MDIO preamble frames
        CSL_MDIO_disablePreamble ();

	 @endverbatim
 * =============================================================================
 */

void CSL_MDIO_disablePreamble (
    CSL_mdioHandle          hMdioRegs
);


/** ============================================================================
 *   @n@b CSL_MDIO_phyRegRead2
 *
 * \param   hMdioRegs Handle to MDIO module register overlay.
 * \param   userGroup     User group to use
 * \param   phyAddr  PHY Address.
 * \param   regNum   Register Number to be read.
 * \param   pData    Pointer where the read value shall be written.
 *
 * \return  TRUE     Read is successful.
 * \return  FALSE    Read is not acknowledged properly.
 *
 * =============================================================================
 */
uint32_t  CSL_MDIO_phyRegRead2(CSL_mdioHandle hMdioRegs,
                    uint32_t userGroup,
                    uint32_t phyAddr,
                    uint32_t regNum,
                    uint16_t *pData);

/** ============================================================================
 *   @n@b CSL_MDIO_phyRegWrite2
 *
 * \brief   This API writes a PHY register using MDIO.
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay.
 * \param   userGroup     User group to use
 * \param   phyAddr       PHY Address.
 * \param   regNum        Register Number to be written.
 * \param   wrVal         Value to be written.
 *
 * =============================================================================
 */
void CSL_MDIO_phyRegWrite2(CSL_mdioHandle hMdioRegs, uint32_t userGroup, uint32_t phyAddr, uint32_t regNum, uint16_t wrVal);

/** ============================================================================
 *   @n@b CSL_MDIO_setClause45EnableMask
 *
 * \brief Set Clause-45 enable mask. Each bit in the mask is associated with a
 *        PHY address, i.e. bit 0 is associated with PHY address 0, etc.
 *
 * \param hMdioRegs           Handle to MDIO module register overlay
 * \param clause45EnableMask  Clause-45 enable bit mask
 *
 * =============================================================================
 */
void CSL_MDIO_setClause45EnableMask(CSL_mdioHandle hMdioRegs,
                                    uint32_t clause45EnableMask);

/** ============================================================================
 *   @n@b CSL_MDIO_getClause45EnableMask
 *
 * \brief Get Clause-45 enable mask. Each bit in the mask is associated with a
 *        PHY address, i.e. bit 0 is associated with PHY address 0, etc.
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 *
 * \return Clause-45 enable mask
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_getClause45EnableMask(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 *   @n@b CSL_MDIO_phyInitiateRegWriteC45
 *
 * \brief Initiate a non-blocking write transaction with PHY using Clause-45
 *        frame. The user should call CSL_MDIO_isPhyRegAccessComplete() to query
 *        the transaction status.
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 * \param phyAddr    PHY address
 * \param mmdNum     MMD number
 * \param regAddr    Register address
 * \param wrVal      Value to be written
 *
 * \retval CSL_PASS   Register write has been initiated
 * \retval CSL_EFAIL  MDIO is busy with previous transaction
 *
 * =============================================================================
 */
int32_t CSL_MDIO_phyInitiateRegWriteC45(CSL_mdioHandle hMdioRegs,
                                        uint32_t userGroup,
                                        uint32_t phyAddr,
                                        uint32_t mmdNum,
                                        uint32_t regAddr,
                                        uint16_t wrVal);

/** ============================================================================
 *   @n@b CSL_MDIO_phyInitiateRegReadC45
 *
 * \brief Initiate a non-blocking register read transaction with PHY using
 *        Clause-45 frame. The user should call CSL_MDIO_isPhyRegAccessComplete()
 *        to query the transaction status, and once it's complete, get the
 *        value read from register via CSL_MDIO_phyGetRegReadVal().
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 * \param phyAddr    PHY address
 * \param mmdNum     MMD number
 * \param regAddr    Register address
 *
 * \retval CSL_PASS   Register read has been initiated
 * \retval CSL_EFAIL  MDIO is busy with previous transaction
 *
 * =============================================================================
 */
int32_t CSL_MDIO_phyInitiateRegReadC45(CSL_mdioHandle hMdioRegs,
                                       uint32_t userGroup,
                                       uint32_t phyAddr,
                                       uint32_t mmdNum,
                                       uint32_t regAddr);

/** ============================================================================
 *   @n@b CSL_MDIO_phyInitiateRegWriteC22
 *
 * \brief Initiate a non-blocking write transaction with PHY using Clause-22
 *        frame. The user should call CSL_MDIO_isPhyRegAccessComplete() to query
 *        the transaction status.
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 * \param phyAddr    PHY address
 * \param regAddr    Register address
 * \param wrVal      Value to be written
 *
 * \retval CSL_PASS   Register write has been initiated
 * \retval CSL_EFAIL  MDIO is busy with previous transaction
 *
 * =============================================================================
 */
int32_t CSL_MDIO_phyRegInitiateWriteC22(CSL_mdioHandle hMdioRegs,
                                        uint32_t userGroup,
                                        uint32_t phyAddr,
                                        uint32_t regAddr,
                                        uint16_t wrVal);

/** ============================================================================
 *   @n@b CSL_MDIO_phyInitiateRegReadC22
 *
 * \brief Initiate a non-blocking register read transaction with PHY using
 *        Clause-22 frame. The user should call CSL_MDIO_isPhyRegAccessComplete()
 *        to query the transaction status, and once it's complete, get the
 *        value read from register via CSL_MDIO_phyGetRegReadVal().
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 * \param phyAddr    PHY address
 * \param regAddr    Register address
 *
 * \retval CSL_PASS   Register read has been initiated
 * \retval CSL_EFAIL  MDIO is busy with previous transaction
 *
 * =============================================================================
 */
int32_t CSL_MDIO_phyInitiateRegReadC22(CSL_mdioHandle hMdioRegs,
                                       uint32_t userGroup,
                                       uint32_t phyAddr,
                                       uint32_t regAddr);

/** ============================================================================
 *   @n@b CSL_MDIO_phyGetRegReadVal
 *
 * \brief Get the value read from a PHY register from a transaction previously
 *        initiated through either CSL_MDIO_phyInitiateRegReadC22() or
 *        CSL_MDIO_phyInitiateRegReadC45().
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 * \param pData      Pointer where the read value shall be written
 *
 * \retval CSL_PASS     Register read was acknowledged and read value is valid
 * \retval CSL_ETIMEOUT Read transaction was not acknowledged by PHY
 * \retval CSL_EFAIL    MDIO is busy with previous transaction
 *
 * =============================================================================
 */
int32_t CSL_MDIO_phyGetRegReadVal(CSL_mdioHandle hMdioRegs,
                                  uint32_t userGroup,
                                  uint16_t *pData);

/** ============================================================================
 *   @n@b CSL_MDIO_isPhyRegAccessComplete
 *
 * \brief Check if there is a transaction going on in MDIO.
 *
 * \param hMdioRegs  Handle to MDIO module register overlay
 * \param userGroup  User group to use
 *
 * \retval TRUE   Last register access is complete
 * \retval FALSE  Last register access is active
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_isPhyRegAccessComplete(CSL_mdioHandle hMdioRegs,
                                         uint32_t userGroup);

/** ============================================================================
 *   @n@b CSL_MDIO_phyLinkStatus2
 *
 * \brief   This API reads the link status of all PHY connected to this MDIO.
 *          The bit corresponding to the PHY address will be set if the PHY
 *          link is active.
 *
 * \param   hMdioRegs Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 *
 * \return  TRUE   PHY link is active.
 * \return  FALSE  PHY link is inactive.
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_phyLinkStatus2(CSL_mdioHandle hMdioRegs, uint32_t phyAddr);

/** ============================================================================
 * @n@b CSL_MDIO_isStatusChangeModeInterruptEnabled
 *
 * \brief Check if the MDIO link interrupt (MDIO_LINKINT) is enabled
 *
 * This function checks if the MDIO link interrupt (MDIO_LINKINT) is enabled
 * or not.  This function is applicable only when MDIO is operating in State
 * Change Mode.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 *
 * \return 1 if MDIO link interrupt is enabled
 *         0 if MDIO link interrupt is disabled
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_isStatusChangeModeInterruptEnabled(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_enableStatusChangeModeInterrupt
 *
 * \brief Enable MDIO link interrupt (MDIO_LINKINT)
 *
 * This function enables the MDIO link interrupt (MDIO_LINKINT).  This function
 * is applicable only when MDIO is operating in State Change Mode.
 *
 * In State Change Mode, MDIO_LINKINT[0] is set when any bit in the ALIVE or
 * LINK registers is set. MDIO_LINKINT[1] is not used.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 *
 * =============================================================================
 */
void CSL_MDIO_enableStatusChangeModeInterrupt(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_disableLinkStatusChangeInterrupt
 *
 * \brief Disable MDIO link interrupt (MDIO_LINKINT)
 *
 * This function disables the MDIO link interrupt (MDIO_LINKINT). This function
 * is applicable only when MDIO is operating in State Change Mode.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 *
 * =============================================================================
 */
void CSL_MDIO_disableStatusChangeModeInterrupt(CSL_mdioHandle hMdioRegs);



/** ============================================================================
 * @n@b CSL_MDIO_getLinkStatusChangePhyAddr
 *
 * \brief Get the PHY address being monitored
 *
 * This function gets the address of the PHY whose state change is being
 * monitored.  This function is applicable only when MDIO is operating in
 * Normal Mode.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 * \param   index          User group index (0 or 1)
 * \return  PHY address
 *
 * =============================================================================
 */
Uint32 CSL_MDIO_getLinkStatusChangePhyAddr(CSL_mdioHandle hMdioRegs,
                                           Uint32 index);

/** ============================================================================
 * @n@b CSL_MDIO_isStateChangeModeEnabled
 *
 * \brief Checks if the State Change Mode is enabled or not
 *
 * This function checks if the State Change Mode is enabled as per STATECHANGEMODE
 * bit of the MDIO Poll register. It returns 1 to indicate that State Change Mode
 * is enabled, or 0 to indicate that Normal Mode is enabled.
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay
 *
 * \return 1 if State Change Mode is enabled
 *         0 if Normal Mode is enabled
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_isStateChangeModeEnabled(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_enableStateChangeMode
 *
 * \brief This function enables the MDIO State Change Mode
 *
 * This function enables the State Change Mode which is used to detect change
 * events on any PHY:
 *  MDIO_LINKINT[0] when any bit in MDIOAlive or MDIOLink registers is set
 *  MDIO_LINKINT[1] is not used
 *  MDIO_UserPhySel0/1 registers are not used
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay
 *
 * =============================================================================
 */
void CSL_MDIO_enableStateChangeMode(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_disableStateChangeMode
 *
 * \brief This function disables the MDIO State Change Mode
 *
 * This function disabled the State Change Mode, effectively enabling Normal
 * Mode which can be used to monitor only two PHYs.
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay
 *
 * =============================================================================
 */
void CSL_MDIO_disableStateChangeMode(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_setPollIPG
 *
 * \brief Set Polling Inter Packet Gap value
 *
 * This function sets the polling Inter Packet Gap (IPG) value which is the number
 * of MDCLK_O clocks between each poll when polling is enabled.
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay
 * \param   ipgVal        IPG value (in MDCLK_O clock pulses)
 *
 * =============================================================================
 */
void CSL_MDIO_setPollIPG(CSL_mdioHandle hMdioRegs,
                         uint8_t ipgVal);

/** ============================================================================
 * @n@b CSL_MDIO_getPollIPG
 *
 * \brief Get Polling Inter Packet Gap value
 *
 * This function gets the polling Inter Packet Gap (IPG) value which is the number
 * of MDCLK_O clocks between each poll when polling is enabled.
 *
 * \param   hMdioRegs     Handle to MDIO module register overlay
 *
 * \return  IPG value (in MDCLK_O clock pulses)
 *
 * =============================================================================
 */
uint8_t CSL_MDIO_getPollIPG(CSL_mdioHandle hMdioRegs);

/** ============================================================================
 * @n@b CSL_MDIO_setPollEnableMask
 *
 * \brief Set poll enable mask
 *
 * This function sets the poll enable mask. When set, each bit of the mask
 * indicates that the associated PHY will be included in the polling operations.
 *
 * Due to a hardware limitation, bit 31 is always set internally by this
 * function.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 * \param   pollEnableMask Poll enable mask
 *
 * =============================================================================
 */
void CSL_MDIO_setPollEnableMask(CSL_mdioHandle hMdioRegs,
                                uint32_t pollEnableMask);

/** ============================================================================
 * @n@b CSL_MDIO_getPollEnableMask
 *
 * \brief Get poll enable mask
 *
 * This function gets the poll enable mask. When set, each bit of the mask
 * indicates that the associated PHY will be included in the polling operations.
 *
 * \param   hMdioRegs      Handle to MDIO module register overlay
 *
 * \return Poll enable mask
 *
 * =============================================================================
 */
uint32_t CSL_MDIO_getPollEnableMask(CSL_mdioHandle hMdioRegs);

/**
@}
*/
#ifdef __cplusplus
}
#endif

#endif /* CSL_MDIO_V5_H */
