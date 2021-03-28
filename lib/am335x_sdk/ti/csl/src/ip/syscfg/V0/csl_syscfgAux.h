/**
 *   @file  csl_SYSCFGAux.h
 *
 *   @brief
 *      This is the Boot Configuration Auxilary Header File which exposes
 *      the various CSL Functional Layer API's to configure the SYSCFG Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2013, Texas Instruments, Inc.
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

#ifndef CSL_SYSCFGAUX_V0_H_
#define CSL_SYSCFGAUX_V0_H_

#include <ti/csl/csl_syscfg.h>
#include <ti/csl/csl_pllc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_SYSCFG_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_SysCfgGetRevisionInfo
 *
 *   @b Description
 *   @n The function is used to get the revision information for the boot
 *      configuration module.
 *
 *   @b Arguments
     @verbatim
        info    Revision information populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_REVISION_REG
 *
 *   @b Example
 *   @verbatim
        Uint32  info;

        // Get the boot configuration revision information.
        CSL_SysCfgGetRevisionInfo (&info);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgGetRevisionInfo (Uint32* info)
{
    *info = hSysCfg->REVID;
}

/** ============================================================================
 *   @n@b CSL_SysCfgGetDeviceId
 *
 *   @b Description
 *   @n The function is used to get the device (JTAG) identifier.
 *
 *   @b Arguments
     @verbatim
        id    Device (JTAG) Identifier populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_JTAG_ID_REG0
 *
 *   @b Example
 *   @verbatim
        Uint32  id;

        // Get the device identifier.
        CSL_SysCfgGetDeviceId (&id);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgGetDeviceId (Uint32* id)
{
    *id = hSysCfg->DEVIDR0;
}

/** ============================================================================
 *   @n@b CSL_SysCfgGetBootMode
 *
 *   @b Description
 *   @n The function returns the boot mode which is latched at POR or RESETFULL.
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Boot mode
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_DEVSTAT_BOOTMODE
 *
 *   @b Example
 *   @verbatim

        Uint16 bootMode;

        // Get the boot mode.
        bootMode = CSL_SysCfgGetBootMode();

     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_SysCfgGetBootMode (void)
{
    return CSL_FEXT(hSysCfg->BOOTCFG, SYSCFG_BOOTCFG_BOOTMODE);
}

/** ============================================================================
 *   @n@b CSL_SysCfgSetBootMode
 *
 *   @b Description
 *   @n The function sets the boot mode
 *
 *   @b Arguments
     @verbatim
        bootMode    - Boot Mode to be configured.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Writes
 *   @n  BOOTCFG_DEVSTAT_BOOTMODE
 *
 *   @b Example
 *   @verbatim

        // Set the boot mode.
        CSL_SysCfgSetBootMode(0x10);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgSetBootMode (Uint16 bootMode)
{
    CSL_FINS(hSysCfg->BOOTCFG, SYSCFG_BOOTCFG_BOOTMODE, bootMode);
}

/** ============================================================================
 *   @n@b CSL_SysCfgUnlockKicker
 *
 *   @b Description
 *   @n The function is used to unlock the kicker mechanism which will allow the
 *      Boot configuration MMR registers to be come writeable.
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Writes
 *   @n  BOOTCFG_KICK_REG0=0x83e70b13, BOOTCFG_KICK_REG1=0x95a4f1e0
 *
 *   @b Example
 *   @verbatim

        // Unlock the kicker to ensure Boot configuration MMR is writeable
        CSL_SysCfgUnlockKicker();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgUnlockKicker (void)
{
    hSysCfg->KICK0R = 0x83E70B13;
    hSysCfg->KICK1R = 0x95A4F1E0;
    hSysCfg->CFGCHIP3 |= 0x4;

    return;
}

/** ============================================================================
 *   @n@b CSL_SysCfgLockKicker
 *
 *   @b Description
 *   @n The function is used to lock the kicker mechanism which will ensure
 *      that all subequent writes to the Boot configuration MMR are now blocked
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Writes
 *   @n  BOOTCFG_KICK_REG0=0x1, BOOTCFG_KICK_REG1=0x1
 *
 *   @b Example
 *   @verbatim

        // Unlock the kicker to ensure Boot configuration MMR is writeable
        CSL_SysCfgUnlockKicker();
        ...
        // Lock the kicker mechanism
        CSL_SysCfgLockKicker();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgLockKicker (void)
{
    hSysCfg->KICK0R = 0x1;
    hSysCfg->KICK1R = 0x1;

    return;
}



/** ============================================================================
 *   @n@b CSL_SysCfgIsBootComplete
 *
 *   @b Description
 *   @n The function is used to check if the booting is complete for a specific
 *      core or not?
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core index which is to be checked
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Example
 *   @verbatim

        // Check if the booting is complete or not for core 2?
        if (CSL_SysCfgIsBootComplete(2) == TRUE)
        {
            // Booting is done
        }
        else
        {
            // Booting is not done.
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_SysCfgIsBootComplete (Uint8 coreIdx)
{
    if (coreIdx == 0)
        return (Bool)CSL_FEXT (hSysCfg->HOST0CFG,SYSCFG_HOST0CFG_BOOTRDY);
    else
        return (Bool)CSL_FEXT (hSysCfg->HOST1CFG,SYSCFG_HOST1CFG_BOOTRDY);
}

/** ============================================================================
 *   @n@b CSL_SysCfgSetBootComplete
 *
 *   @b Description
 *   @n The function is used to set the boot complete. This can be done only once
 *      by the software.
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core index which for which boot complete is to be set
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Example
 *   @verbatim

        // Booting is done for core 0
        CSL_SysCfgSetBootComplete (0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_SysCfgSetBootComplete (Uint8 coreIdx)
{
    if (coreIdx == 0)
        CSL_FINS (hSysCfg->HOST0CFG,SYSCFG_HOST0CFG_BOOTRDY, 1);
    if (coreIdx == 1)
        CSL_FINS (hSysCfg->HOST1CFG,SYSCFG_HOST1CFG_BOOTRDY, 1);
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_SYSCFGAUX_V0_H_ */
