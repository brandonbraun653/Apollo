/**
 * @file csl_mdio.h
 *
 * @brief
 *  Header file for functional layer of CSL MDIO Version 4
 *
 *  It contains the various enumerations, structure definitions and function
 *  declarations
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2018, Texas Instruments, Inc.
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

 /** ============================================================================
 *
 * @defgroup CSL_MDIO_API_V4 MDIO - V4
 * @ingroup CSL_MDIO_API
 *
 * ============================================================================
 */
/**
@defgroup CSL_MDIO_SYMBOL  Symbols Defined
@ingroup CSL_MDIO_API_V4
*/
/**
@defgroup CSL_MDIO_DATASTRUCT   Data Structures
@ingroup CSL_MDIO_API_V4
*/
/**
@defgroup CSL_MDIO_FUNCTION  Functions
@ingroup CSL_MDIO_API_V4
*/
/**
@defgroup CSL_MDIO_ENUM Enumerated Data Types
@ingroup CSL_MDIO_API_V4
*/
#ifndef CSL_MDIO_V4_H
#define CSL_MDIO_V4_H

#ifdef __cplusplus
extern "C" {
#endif


#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_mdio.h>


/** @addtogroup CSL_MDIO_DATASTRUCT
 @{ */

typedef volatile CSL_MdioRegs             *CSL_mdioHandle;

/**
@}
*/

#include <string.h>
#include <stdbool.h>
#include <ti/csl/cslr.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mdio.h>

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
 * \param   baseAddr Base Address of the MDIO module.
 * \param   phyAddr  PHY Address.
 * \param   regNum   Register Number to be read.
 * \param   pData    Pointer where the read value shall be written.
 *
 * \retval  TRUE     Read is successful.
 * \retval  FALSE    Read is not acknowledged properly.
     @endverbatim
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
 * \retval  TRUE   PHY link is active.
 * \retval  FALSE  PHY link is inactive.
 * =============================================================================
 */
uint32_t CSL_MDIO_phyLinkStatus(uint32_t baseAddr, uint32_t phyAddr);

/** ============================================================================
 *   @n@b CSL_MDIO_enableLinkStatusChangeInterrupt
 *
 *   @b Description
 *   @n This function sets the 'LINKINTENB' bit to 1 for a PHY address 'phyAddr'
 *      being monitored by the MDIO module. This configuration is done for
 *      the 'USERPHYSEL' register corresponding to the index specified here.
 *
 *   @b Arguments
 *   @verbatim
 *      index               Specifies which of the USERPHYSEL register contents
 *                          must be configured by this function. Valid values are 0-1,
 *                          both inclusive.
 *      phyAddr             PHY Address for which the Link Status change interrupt
 *                          must be enabled.
 *   @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  USERPHYSEL register's 'PHYADDRMON' and 'LINKINTENB' bits are configured for
 *       the index specified. Link Status Change interrupt enabled for PHY address
 *       specified.
 *
 *   @b Writes
 *   @n MDIO_USER_PHY_SEL_REG_PHYADR_MON,
 *      MDIO_USER_PHY_SEL_REG_LINKINT_ENABLE=1
 *
 *   @b Example
 *   @verbatim
 *
        // Enable PHY 0's interrupt
        CSL_MDIO_enableLinkStatusChangeInterrupt (0, 0);

	 @endverbatim
 * =============================================================================
 */
void CSL_MDIO_enableLinkStatusChangeInterrupt (
    CSL_mdioHandle          hMdioRegs,
    Uint32                  index,
    Uint32                  phyAddr
);

/** ============================================================================
 *   @n@b CSL_MDIO_disableLinkStatusChangeInterrupt
 *
 *   @b Description
 *   @n This function sets the 'LINKINTENB' bit to 0 for a PHY address 'phyAddr'
 *      being monitored by the MDIO module. This configuration is done for
 *      the 'USERPHYSEL' register corresponding to the index specified here.
 *
 *   @b Arguments
 *   @verbatim
 *      index               Specifies which of the USERPHYSEL register contents
 *                          must be configured by this function. Valid values are 0-1,
 *                          both inclusive.
 *      phyAddr             PHY Address for which the Link Status change interrupt
 *                          must be disabled.
 *   @endverbatim
 *
 *   <b> Return Value </b>
 *   @n  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  USERPHYSEL register's 'PHYADDRMON' and 'LINKINTENB' bits are configured for
 *       the index specified.Link Status Change interrupt disabled for PHY address
 *       specified.
 *
 *   @b Writes
 *   @n MDIO_USER_PHY_SEL_REG_PHYADR_MON,
 *      MDIO_USER_PHY_SEL_REG_LINKINT_ENABLE=0
 *
 *   @b Example
 *   @verbatim
 *
        // Disable PHY 0's interrupt
        CSL_MDIO_disableLinkStatusChangeInterrupt (0, 0);

	 @endverbatim
 * =============================================================================
 */
void CSL_MDIO_disableLinkStatusChangeInterrupt (
    CSL_mdioHandle          hMdioRegs,
    Uint32                  index,
    Uint32                  phyAddr
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


/**
@}
*/
#ifdef __cplusplus
}
#endif

#endif /* CSL_MDIO_V4_H */
