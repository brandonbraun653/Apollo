/**
 *   @file  csl_bootcfgAux.h
 *
 *   @brief   
 *      This is the Boot Configuration Auxilary Header File which exposes 
 *      the various CSL Functional Layer API's to configure the BOOTCFG Module.
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

#ifndef CSL_BOOTCFGAUX_V2_H_
#define CSL_BOOTCFGAUX_V2_H_

#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_pllc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_BOOTCFG_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_BootCfgGetRevisionInfo
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
        CSL_BootCfgGetRevisionInfo (&info);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetRevisionInfo (Uint32* info)
{
    *info = hBootCfg->REVISION_REG;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDeviceId
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
        CSL_BootCfgGetDeviceId (&id);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDeviceId (Uint32* id)
{
    *id = hBootCfg->JTAG_ID_REG0;
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsLittleEndian
 *
 *   @b Description
 *   @n The function checks if the device is running in little endian mode or not?
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - Device is in Little Endian Mode
 *   @n FALSE - Device is in Big Endian Mode
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_DEVSTAT_LENDIAN
 *
 *   @b Example
 *   @verbatim

        // Check if device is in little endian mode or not?
        if (CSL_BootCfgIsLittleEndian () == TRUE)
        {
            // Little Endian
        }
        else
        {
            // Big Endian
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsLittleEndian (void)
{
    if (CSL_FEXT(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_LENDIAN) == 1)
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetBootMode
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
        bootMode = CSL_BootCfgGetBootMode();

     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_BootCfgGetBootMode (void)
{
    return CSL_FEXT(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_BOOTMODE);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetBootMode
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
        CSL_BootCfgSetBootMode(0x10);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetBootMode (Uint16 bootMode)
{
    CSL_FINS(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_BOOTMODE, bootMode);
}

/** ============================================================================
 *   @n@b CSL_BootCfgUnlockKicker
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
        CSL_BootCfgUnlockKicker();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgUnlockKicker (void)
{
    hBootCfg->KICK_REG0 = 0x83e70b13;
    hBootCfg->KICK_REG1 = 0x95a4f1e0;

    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgLockKicker
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
        CSL_BootCfgUnlockKicker();
        ...
        // Lock the kicker mechanism
        CSL_BootCfgLockKicker();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgLockKicker (void)
{
    hBootCfg->KICK_REG0 = 0x1;
    hBootCfg->KICK_REG1 = 0x1;

    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDSPBootAddress
 *
 *   @b Description
 *   @n The function is used to get the initial fetch address of each GEM core
 *
 *   @b Arguments
     @verbatim
        coreIdx -   Index of the core for which the fecth address is required
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
 *   @n  BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0
 *
 *   @b Example
 *   @verbatim
        Uint32  bootAddress;

        // Get the Boot configuration DSP Boot Address for Core 1
        bootAddress = CSL_BootCfgGetDSPBootAddress(1);

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_BootCfgGetDSPBootAddress (Uint8 coreIdx)
{
    return CSL_FEXT(hBootCfg->BOOTADDR_GEM_REG[coreIdx], BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDSPBootAddress
 *
 *   @b Description
 *   @n The function is used to set the initial fetch address of each GEM core
 *      This can be done only for non-secure devices.
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Index of the core for which the fetch address is configured
        bootAddress - Boot Address to be configured
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
 *   @n  BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0
 *
 *   @b Example
 *   @verbatim
        Uint32  bootAddress;

        // Set the Boot configuration DSP Boot Address for Core 1
        CSL_BootCfgSetDSPBootAddress(1, 0x20B00000);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDSPBootAddress (Uint8 coreIdx, Uint32 bootAddress)
{
    CSL_FINS(hBootCfg->BOOTADDR_GEM_REG[coreIdx], BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0, bootAddress);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetMacIdentifier
 *
 *   @b Description
 *   @n The function is used to get the MAC address for this device derived from
 *      the EFUSE.
 *
 *   @b Arguments
     @verbatim
        macId0  -   Contents of the MAC ID0 register
        macId1  -   Contents of the MAC ID1 register
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
 *   @n  BOOTCFG_MAC_ID0,BOOTCFG_MAC_ID1
 *
 *   @b Example
 *   @verbatim
        Uint32  macId0;
        Uint32  macId1;

        // Get the MAC Identifier
        CSL_BootCfgGetMacIdentifier(&macId0, &macId1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetMacIdentifier (Uint32* macId0, Uint32* macId1)
{
    *macId0 = hBootCfg->MAC_ID0;
    *macId1 = hBootCfg->MAC_ID1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsBootComplete
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
 *   @b  Reads
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM0_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM1_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE
 *
 *   @b Example
 *   @verbatim

        // Check if the booting is complete or not for core 2?
        if (CSL_BootCfgIsBootComplete(2) == TRUE)
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
static inline Bool CSL_BootCfgIsBootComplete (Uint8 coreIdx)
{
    if (coreIdx == 0)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM0_COMPLETE);
    else if (coreIdx == 1)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM1_COMPLETE);
    else if (coreIdx == 2)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE);
    else 
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetBootComplete
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
 *   @b  Writes
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM0_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM1_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE
 *
 *   @b Example
 *   @verbatim

        // Booting is done for core 0
        CSL_BootCfgSetBootComplete (0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetBootComplete (Uint8 coreIdx)
{
    if (coreIdx == 0)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM0_COMPLETE, 1);
    if (coreIdx == 1)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM1_COMPLETE, 1);
    if (coreIdx == 2)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE, 1);
    if (coreIdx == 3)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetBootProgress
 *
 *   @b Description
 *   @n The function is used to get the boot progress. 
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Boot progress contents.
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_BOOT_PROGRESS
 *
 *   @b Example
 *   @verbatim
        Uint32  bootProgress;

        // Get the boot progress
        bootProgress = CSL_BootCfgGetBootProgress ();

     @endverbatim
 * =============================================================================
 */
static inline Uint32 CSL_BootCfgGetBootProgress (void)
{
    return hBootCfg->BOOT_PROGRESS;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetBootProgress
 *
 *   @b Description
 *   @n The function is used to set the boot progress. 
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Boot progress contents.
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Writes
 *   @n  BOOTCFG_BOOT_PROGRESS
 *
 *   @b Example
 *   @verbatim

        // Set the boot progress
        CSL_BootCfgSetBootProgress (0xDEAD);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetBootProgress (Uint32 bootProgress)
{
    hBootCfg->BOOT_PROGRESS = bootProgress;
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsCoreLocalReset
 *
 *   @b Description
 *   @n The function is used to check if the core is locally reset or not?
 *
 *   @b Arguments
     @verbatim
        coreIdx - Core Index for which the reset status is needed
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - Core is locally reset.
 *   @n FALSE - Core is not locally reset.
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT0;BOOTCFG_RESET_STAT_LRST_STAT1;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT2;BOOTCFG_RESET_STAT_LRST_STAT3
 *
 *   @b Example
 *   @verbatim

        // Is Core 0 locally reset?
        if (CSL_BootCfgIsCoreLocalReset (0) == TRUE)
        {
            // Core 0 is locally reset.
        }
        else
        {
            // Core 0 is not locally reset.
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsCoreLocalReset (Uint8 coreIdx)
{
    if (coreIdx == 0)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM0_COMPLETE);
    else if (coreIdx == 1)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM1_COMPLETE);
    else if (coreIdx == 2)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE);
    else 
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE);
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearLocalReset
 *
 *   @b Description
 *   @n The function is used to clear the local reset state of the specified core
 *
 *   @b Arguments
     @verbatim
        coreIdx - Core Index for which the local reset state is to be cleared
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
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_1_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_2_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_3_CLR
 *
 *   @b  Affects
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT0=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT1=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT2=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT3=0
 *
 *   @b Example
 *   @verbatim

        // Is Core 0 locally reset?
        if (CSL_BootCfgIsCoreLocalReset (0) == TRUE)
        {
            // Core 0 is locally reset.
            ...
            // Clear Core 0 local reset.
            CSL_BootCfgClearLocalReset (0);
        }
        else
        {
            // Core 0 is not locally reset.
        }

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearLocalReset (Uint8 coreIdx)
{
    if (coreIdx == 0)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR, 1);
    if (coreIdx == 1)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_1_CLR, 1);
    if (coreIdx == 2)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_2_CLR, 1);
    if (coreIdx == 3)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_3_CLR, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsGlobalReset
 *
 *   @b Description
 *   @n The function is used to check if the device is globally reset or not?
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - Device is global reset.
 *   @n FALSE - Device is not globally reset.
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b  Reads
 *   @n  BOOTCFG_RESET_STAT_GRST_STAT
 *
 *   @b Example
 *   @verbatim

        // Is device globally reset?
        if (CSL_BootCfgIsGlobalReset () == TRUE)
        {
            // Device is global reset
        }
        else
        {
            // Device is NOT global reset
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsGlobalReset (void)
{
    return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_RESET_STAT_GRST_STAT);
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearGlobalReset
 *
 *   @b Description
 *   @n The function is used to clear the global reset state of the specified core
 *
 *   @b Arguments
     @verbatim
        coreIdx - Core Index for which the global reset state is to be cleared
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
 *   @n  BOOTCFG_RESET_STAT_GRST_STAT
 *
 *   @b Example
 *   @verbatim

        // Is device globally reset?
        if (CSL_BootCfgIsGlobalReset () == TRUE)
        {
            // Device is global reset
            ...
            // Clear the global reset flag
            CSL_BootCfgClearGlobalReset();
        }
        else
        {
            // Device is NOT global reset
        }

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearGlobalReset (void)
{
    CSL_FINS (hBootCfg->RESET_STAT,BOOTCFG_RESET_STAT_GRST_STAT, (Uint32) 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetNMILocalResetStatus
 *
 *   @b Description
 *   @n The function is used to get the NMI & Local reset status for a specific
 *      core.
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index for which the status is required
        nmiStatus   - NMI Status populated by this API
        localStatus - Local Reset Status populated by this API
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
 *   @n  BOOTCFG_LRSTNMISTAT_LRESET_STAT0;
 *   @n  BOOTCFG_LRSTNMISTAT_LRESET_STAT1;
 *   @n  BOOTCFG_LRSTNMISTAT_LRESET_STAT2;
 *   @n  BOOTCFG_LRSTNMISTAT_LRESET_STAT3;
 *
 *   @b Example
 *   @verbatim

        Uint8   nmiStatus;
        Uint8   localStatus;

        // Get the NMI and Local Reset Status for core 1
        CSL_BootCfgGetNMILocalResetStatus (1, &nmiStatus, &localStatus);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetNMILocalResetStatus (Uint8 coreIdx, Uint8* nmiStatus, Uint8* localStatus)
{
    Uint32 value = hBootCfg->LRSTNMISTAT;

    if (coreIdx == 0)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT0);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT0);
    }
    if (coreIdx == 1)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT1);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT1);
    } 
    if (coreIdx == 2)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT2);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT2);
    }
    if (coreIdx == 3)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT3);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT3);
    }
    
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearNMILocalResetStatus
 *
 *   @b Description
 *   @n The function is used to clear the NMI & Local reset status for a specific
 *      core.
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index for which the status is required
        nmiStatus   - NMI Status to be cleared
        localStatus - Local Reset Status to be cleared
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
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_1_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_1_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_2_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_2_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_3_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_3_CLR;
 *
 *   @b  Affects
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT0=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT0=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT1=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT1=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT2=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT2=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT3=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT3=0;
 *
 *   @b Example
 *   @verbatim

        Uint8   nmiStatus;
        Uint8   localStatus;

        // Get the NMI and Local Reset Status for core 1
        CSL_BootCfgGetNMILocalResetStatus (1, &nmiStatus, &localStatus);
        ...
        // Clear the status
        CSL_BootCfgClearNMILocalResetStatus (1, nmiStatus, localStatus);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearNMILocalResetStatus (Uint8 coreIdx, Uint8 nmiStatus, Uint8 localStatus)
{
    Uint32 value = 0;

    if (coreIdx == 0)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_0_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR, localStatus);
    }
    if (coreIdx == 1)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_1_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_1_CLR, localStatus);
    } 
    if (coreIdx == 2)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_2_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_2_CLR, localStatus);
    }
    if (coreIdx == 3)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_3_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_3_CLR, localStatus);
    }
    
    /* Write to the register to clear the NMI Status. */
    hBootCfg->LRSTNMISTAT_CLR = value;
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsSysClockEnabled
 *
 *   @b Description
 *   @n The function checks if the system clock is enabled or not?
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - Clock output enabled
 *   @n FALSE - No Clock Output
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_DEVCFG_SYSCLKOUTEN
 *
 *   @b Example
 *   @verbatim

        // Is System clock is enabled or not?
        if (CSL_BootCfgIsSysClockEnabled () == TRUE)
        {
            // Clock output is Enabled
        }
        else
        {
            // No Clock Output
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsSysClockEnabled (void)
{
    return (Bool)CSL_FEXT(hBootCfg->DEVCFG, BOOTCFG_DEVCFG_SYSCLKOUTEN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgEnableSysClock
 *
 *   @b Description
 *   @n The function is used to enable the sys clock 
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
 *   @b Writes
 *   @n BOOTCFG_DEVCFG_SYSCLKOUTEN=1
 *
 *   @b Example
 *   @verbatim

        CSL_BootCfgEnableSysClock();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgEnableSysClock (void)
{
    CSL_FINS(hBootCfg->DEVCFG, BOOTCFG_DEVCFG_SYSCLKOUTEN, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgDisableSysClock
 *
 *   @b Description
 *   @n The function is used to disable the sys clock 
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
 *   @b Writes
 *   @n BOOTCFG_DEVCFG_SYSCLKOUTEN=0
 *
 *   @b Example
 *   @verbatim

        CSL_BootCfgDisableSysClock();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgDisableSysClock (void)
{
    CSL_FINS(hBootCfg->DEVCFG, BOOTCFG_DEVCFG_SYSCLKOUTEN, 0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetPowerStatus
 *
 *   @b Description
 *   @n The function gets the Power status
 *
 *   @b Arguments
     @verbatim
        standbyStatus       - Indicates whether in Standby mode or not
        hibernationStatus   - Indicates whether in Hibernation mode or not
        hibernationMode     - Indicates whether in Hibernation mode1 or mode2
        generalPurpose      - General Purpose value in the register
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
 *   @b Reads
 *   @n BOOTCFG_PWR_STAT_STANDBY,BOOTCFG_PWR_STAT_HIBERNATION,
 *   @n BOOTCFG_PWR_STAT_HIBERNATION_MODE,BOOTCFG_PWR_STAT_PWR_STAT_GENERAL
 *
 *   @b Example
 *   @verbatim

        Uint8  standby;
        Uint8  hibernation;
        Uint8  hibernationMode;
        Uint32 generalPurpose;

        // Get the power status.
        CSL_BootCfgGetPowerStatus(&standby, &hibernation, &hibernationMode, &generalPurpose);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetPowerStatus 
(
    Uint8*  standby, 
    Uint8*  hibernation, 
    Uint8*  hibernationMode,
    Uint32* generalPurpose
)
{
    Uint32 value = hBootCfg->PWR_STAT;

    *standby        = CSL_FEXT (value, BOOTCFG_PWR_STAT_STANDBY);
    *hibernation    = CSL_FEXT (value, BOOTCFG_PWR_STAT_HIBERNATION);
    *hibernationMode= CSL_FEXT (value, BOOTCFG_PWR_STAT_HIBERNATION_MODE);
    *generalPurpose = CSL_FEXT (value, BOOTCFG_PWR_STAT_PWR_STAT_GENERAL);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetPowerStatus
 *
 *   @b Description
 *   @n The function sets the Power status
 *
 *   @b Arguments
     @verbatim
        standbyStatus       - Status of the standby to be configured
        hibernationStatus   - Hibernation Status to be configured
        hibernationMode     - Hibernation mode to be configured
        generalPurpose      - General Purpose value to be configured
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
 *   @b Writes
 *   @n BOOTCFG_PWR_STAT_STANDBY,BOOTCFG_PWR_STAT_HIBERNATION,
 *   @n BOOTCFG_PWR_STAT_HIBERNATION_MODE,BOOTCFG_PWR_STAT_PWR_STAT_GENERAL
 *
 *   @b Example
 *   @verbatim

        Uint8  standby;
        Uint8  hibernation;
        Uint8  hibernationMode;
        Uint32 generalPurpose;

        // Get the power status.
        CSL_BootCfgGetPowerStatus(&standby, &hibernation, &hibernationMode, &generalPurpose);
        ...
        // Set the power status to be in standby mode
        CSL_BootCfgSetPowerStatus (1, hibernation, hibernationMode, generalPurpose);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetPowerStatus 
(
    Uint8  standby, 
    Uint8  hibernation, 
    Uint8  hibernationMode,
    Uint32 generalPurpose
)
{
    hBootCfg->PWR_STAT = CSL_FMK (BOOTCFG_PWR_STAT_STANDBY,         standby)            |
                         CSL_FMK (BOOTCFG_PWR_STAT_HIBERNATION,     hibernation)        |
                         CSL_FMK (BOOTCFG_PWR_STAT_HIBERNATION_MODE,hibernationMode)    |
                         CSL_FMK (BOOTCFG_PWR_STAT_PWR_STAT_GENERAL,generalPurpose); 
}

/** ============================================================================
 *   @n@b CSL_BootCfgGenerateNMIEvent
 *
 *   @b Description
 *   @n The function is used to generate a NMI event to a specific core.
 *
 *   @b Arguments
     @verbatim
        coreNum    - Core Number on which the NMI event is to be generated.
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
 *   @b Writes
 *   @n BOOTCFG_NMIGR_0_NMIGR_0_REG;BOOTCFG_NMIGR_1_NMIGR_1_REG;
 *   @n BOOTCFG_NMIGR_2_NMIGR_2_REG;BOOTCFG_NMIGR_3_NMIGR_3_REG;
 *   @n BOOTCFG_NMIGR_4_NMIGR_4_REG;BOOTCFG_NMIGR_5_NMIGR_5_REG;
 *   @n BOOTCFG_NMIGR_6_NMIGR_6_REG;BOOTCFG_NMIGR_7_NMIGR_7_REG
 *
 *   @b Example
 *   @verbatim

        // Generate NMI Event on Core 0
        CSL_BootCfgGenerateNMIEvent(0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGenerateNMIEvent 
(
    Uint8  coreNum
)
{
    CSL_FINS (hBootCfg->NMIGR[coreNum], BOOTCFG_NMIGR_0_NMIGR_0_REG, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGenerateInterDSPInterrupt
 *
 *   @b Description
 *   @n The function is used to generate an inter-DSP interrupt.
 *
 *   @b Arguments
     @verbatim
        coreNum  - Core Number to which the interrupt is directed.
        sourceId - Source Id which identifies the entity generating the interrupt
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
 *   @b Writes
 *   @n BOOTCFG_IPCGR0_IPCGR0_SRC, BOOTCFG_IPCGR0_IPCGR0_REG=1;
 *   @n BOOTCFG_IPCGR1_IPCGR1_SRC, BOOTCFG_IPCGR1_IPCGR1_REG=1;
 *   @n BOOTCFG_IPCGR2_IPCGR2_SRC, BOOTCFG_IPCGR2_IPCGR2_REG=1;
 *   @n BOOTCFG_IPCGR3_IPCGR3_SRC, BOOTCFG_IPCGR3_IPCGR3_REG=1;
 *   @n BOOTCFG_IPCGR3_IPCGR4_SRC, BOOTCFG_IPCGR3_IPCGR4_REG=1;
 *   @n BOOTCFG_IPCGR3_IPCGR5_SRC, BOOTCFG_IPCGR3_IPCGR5_REG=1;
 *   @n BOOTCFG_IPCGR3_IPCGR6_SRC, BOOTCFG_IPCGR3_IPCGR6_REG=1;
 *   @n BOOTCFG_IPCGR3_IPCGR7_SRC, BOOTCFG_IPCGR3_IPCGR7_REG=1;
 *
 *   @b Example
 *   @verbatim

        // Generate Inter-DSP Interrupt to Core 1 with the Source Id as 4
        CSL_BootCfgGenerateInterDSPInterrupt(1, 4);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGenerateInterDSPInterrupt 
(
    Uint8   coreNum,
    Uint32  sourceId 
)
{
	hBootCfg->IPCGR[coreNum] = CSL_FMK(BOOTCFG_IPCGR0_IPCGR0_SRC, sourceId) | 
							   CSL_FMK(BOOTCFG_IPCGR0_IPCGR0_REG, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGenerateExternalHostInterrupt
 *
 *   @b Description
 *   @n The function is used to generate an external host interrupt.
 *
 *   @b Arguments
     @verbatim
        sourceId - Source Id which identifies the entity generating the interrupt
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
 *   @b Writes
 *   @n BOOTCFG_IPCGRH_IPCGRH_SRC, BOOTCFG_IPCGRH_IPCGRH_REG=1;
 *
 *   @b Example
 *   @verbatim

        // Generate External Host Interrupt with the Source Id as 2
        CSL_BootCfgGenerateExternalHostInterrupt(2);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGenerateExternalHostInterrupt 
(
    Uint32  sourceId 
)
{
    hBootCfg->IPCGRH = CSL_FMK(BOOTCFG_IPCGRH_IPCGRH_SRC, sourceId) |
                       CSL_FMK(BOOTCFG_IPCGRH_IPCGRH_REG, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetInterDSPInterruptStatus
 *
 *   @b Description
 *   @n The function is used to get the status of the Inter-DSP Interrupt 
 *      register. 
 *
 *   @b Arguments
     @verbatim
        coreNum   - Core Number for which the interrupt status is read.
        intStatus - Interrupt Status(Source ID) populated by this API.
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
 *   @b Reads
 *   @n BOOTCFG_IPCAR0_IPCGR0_SRC_CLR; BOOTCFG_IPCAR1_IPCAR1_SRC_CLR;
 *   @n BOOTCFG_IPCAR2_IPCAR2_SRC_CLR; BOOTCFG_IPCAR3_IPCAR3_SRC_CLR;
 *   @n BOOTCFG_IPCAR4_IPCAR4_SRC_CLR; BOOTCFG_IPCAR5_IPCAR5_SRC_CLR;
 *   @n BOOTCFG_IPCAR6_IPCAR6_SRC_CLR; BOOTCFG_IPCAR7_IPCAR7_SRC_CLR
 *
 *   @b Example
 *   @verbatim

        Uint32  srcId;

        // Get the Inter-DSP Interrupt Status for Core 2
        CSL_BootCfgGetInterDSPInterruptStatus(2, &srcId);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetInterDSPInterruptStatus 
(
    Uint8   coreNum,
    Uint32* intStatus 
)
{
    *intStatus = CSL_FEXT(hBootCfg->IPCAR[coreNum], BOOTCFG_IPCAR0_IPCGR0_SRC_CLR);
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearInterDSPInterruptStatus
 *
 *   @b Description
 *   @n The function is used to clear the status of the Inter-DSP Interrupt 
 *      register. 
 *
 *   @b Arguments
     @verbatim
        coreNum   - Core Number for which the interrupt status is read.
        intStatus - Interrupt Status(Source ID) to be cleared.
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
 *   @b Writes
 *   @n BOOTCFG_IPCAR0_IPCGR0_SRC_CLR; BOOTCFG_IPCAR1_IPCAR1_SRC_CLR;
 *   @n BOOTCFG_IPCAR2_IPCAR2_SRC_CLR; BOOTCFG_IPCAR3_IPCAR3_SRC_CLR
 *   @n BOOTCFG_IPCAR4_IPCAR4_SRC_CLR; BOOTCFG_IPCAR5_IPCAR5_SRC_CLR;
 *   @n BOOTCFG_IPCAR6_IPCAR6_SRC_CLR; BOOTCFG_IPCAR7_IPCAR7_SRC_CLR
 *
 *   @b Example
 *   @verbatim

        Uint32  srcId;

        // Get the Inter-DSP Interrupt Status for Core 2
        CSL_BootCfgGetInterDSPInterruptStatus(2, &srcId);
        ...
        // Clear the interrupts.
        CSL_BootCfgClearInterDSPInterruptStatus(2, srcId);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearInterDSPInterruptStatus 
(
    Uint8   coreNum,
    Uint32  intStatus 
)
{
    CSL_FINS(hBootCfg->IPCAR[coreNum], BOOTCFG_IPCAR0_IPCGR0_SRC_CLR, intStatus);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetExternalHostInterruptStatus
 *
 *   @b Description
 *   @n The function is used to get the status of the External Host Interrupt 
 *      register. 
 *
 *   @b Arguments
     @verbatim
        intStatus - Interrupt Status(Source ID) populated by this API.
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
 *   @b Reads
 *   @n BOOTCFG_IPCARH_IPCGRH_SRC_CLR
 *
 *   @b Example
 *   @verbatim

        Uint32  srcId;

        // Get the External Host Interrupt Status
        CSL_BootCfgGetExternalHostInterruptStatus(&srcId);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetExternalHostInterruptStatus 
(
    Uint32* intStatus 
)
{
    *intStatus = CSL_FEXT(hBootCfg->IPCARH, BOOTCFG_IPCARH_IPCGRH_SRC_CLR);
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearExternalHostInterruptStatus
 *
 *   @b Description
 *   @n The function is used to clear the status of the External Host Interrupt 
 *      register. 
 *
 *   @b Arguments
     @verbatim
        intStatus - Interrupt Status(Source ID) to be cleared
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
 *   @b Writes
 *   @n BOOTCFG_IPCARH_IPCGRH_SRC_CLR
 *
 *   @b Example
 *   @verbatim

        Uint32  srcId;

        // Get the External Host Interrupt Status
        CSL_BootCfgGetExternalHostInterruptStatus(&srcId);
        ...
        // Clear the Interrupt Status
        CSL_BootCfgClearExternalHostInterruptStatus(srcId);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearExternalHostInterruptStatus 
(
    Uint32 intStatus 
)
{
    CSL_FINS(hBootCfg->IPCARH, BOOTCFG_IPCARH_IPCGRH_SRC_CLR, intStatus);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerInputSelection0
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput0  - Timer Input 0 value being returned        
        timerInput1  - Timer Input 1 value being returned      
        timerInput2  - Timer Input 2 value being returned      
        timerInput3  - Timer Input 3 value being returned
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        Uint16 timerInput0,timerInput1,timerInput2,timerInput3;

        // Get the timer input selection 
        timerInput = CSL_BootCfgGetTimerInputSelection0(&timerInput0,
                                                       &timerInput1,
                                                       &timerInput2,
                                                       &timerInput3);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerInputSelection0(Uint16* timerInput0,
                                                       Uint16* timerInput1,
                                                       Uint16* timerInput2,
                                                       Uint16* timerInput3)
{
    *timerInput0 = 
    ( CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL0) |
      CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH0));
    
    *timerInput1 = 
    ( CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL1) |
      CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH1));
      
    *timerInput2 = 
    ( CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL2) |
      CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH2));
      
    *timerInput3 = 
    ( CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL3) |
      CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH3));
    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerInputSelection2
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput8  - Timer Input 8 value being returned        
        timerInput9  - Timer Input 9 value being returned      
        timerInput10  - Timer Input 10 value being returned      
        timerInput11  - Timer Input 11 value being returned
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        Uint16 timerInput8,timerInput9,timerInput10,timerInput11;

        // Get the timer input selection 
        timerInput = CSL_BootCfgGetTimerInputSelection2(&timerInput8,
                                                       &timerInput9,
                                                       &timerInput10,
                                                       &timerInput11);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerInputSelection2(Uint16* timerInput8,
                                                        Uint16* timerInput9,
                                                        Uint16* timerInput10,
                                                        Uint16* timerInput11)
{
    *timerInput8 = 
    ( CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL8) |
      CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH8));
    
    *timerInput9 = 
    ( CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL9) |
      CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH9));
      
    *timerInput10 = 
    ( CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL10) |
      CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH10));
      
    *timerInput11 = 
    ( CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL11) |
      CSL_FEXT (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH11));
    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerInputSelection3
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput12  - Timer Input 12 value being returned        
        timerInput13  - Timer Input 13 value being returned      
        timerInput14  - Timer Input 14 value being returned      
        timerInput15  - Timer Input 15 value being returned
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        Uint16 timerInput12,timerInput13,timerInput14,timerInput15;

        // Get the timer input selection 
        timerInput = CSL_BootCfgGetTimerInputSelection3(&timerInput12,
                                                       &timerInput13,
                                                       &timerInput14,
                                                       &timerInput15);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerInputSelection3(Uint16* timerInput12,
                                                        Uint16* timerInput13,
                                                        Uint16* timerInput14,
                                                        Uint16* timerInput15)
{
    *timerInput12 = 
    ( CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL12) |
      CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH12));
    
    *timerInput13 = 
    ( CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL13) |
      CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH13));
      
    *timerInput14 = 
    ( CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL14) |
      CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH14));
      
    *timerInput15 = 
    ( CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL15) |
      CSL_FEXT (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH15));
    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerInputSelection4
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput16  - Timer Input 12 value being returned        
        timerInput17  - Timer Input 13 value being returned  
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        Uint16 timerInput16,timerInput17;

        // Get the timer input selection 
        timerInput = CSL_BootCfgGetTimerInputSelection4(&timerInput16,
                                                       &timerInput17);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerInputSelection4(Uint16* timerInput16,
                                                        Uint16* timerInput17)
{
    *timerInput16 = 
    ( CSL_FEXT (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEL16) |
      CSL_FEXT (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEH16));
    
    *timerInput17 = 
    ( CSL_FEXT (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEL17) |
      CSL_FEXT (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEH17));
      
    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection0
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput0  - Timer Input 0 selection to be configured        
        timerInput1  - Timer Input 1 selection to be configured       
        timerInput2  - Timer Input 2 selection to be configured       
        timerInput3  - Timer Input 3 selection to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        // Set the timer input selection 
        CSL_BootCfgSetTimerInputSelection0(0x1,0x2,0x3,0x4);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerInputSelection0 (Uint16 timerInput0,
                                                        Uint16 timerInput1,
                                                        Uint16 timerInput2,
                                                        Uint16 timerInput3)
{
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL0, timerInput0);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH0, timerInput0);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL1, timerInput1);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH1, timerInput1);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL2, timerInput2);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH2, timerInput2);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL3, timerInput3);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEH3, timerInput3);
}
/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection2
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput8  - Timer Input 8 selection to be configured        
        timerInput9  - Timer Input 9 selection to be configured       
        timerInput10 - Timer Input 10 selection to be configured       
        timerInput11  - Timer Input 11 selection to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        // Set the timer input selection 
        CSL_BootCfgSetTimerInputSelection2(0x1,0x2,0x3,0x4);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerInputSelection2 (Uint16 timerInput8,
                                                        Uint16 timerInput9,
                                                        Uint16 timerInput10,
                                                        Uint16 timerInput11)
{
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL8, timerInput8);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH8, timerInput8);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL9, timerInput9);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH9, timerInput9);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL10, timerInput10);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH10, timerInput10);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEL11, timerInput11);
    CSL_FINS (hBootCfg->TINPSEL2,BOOTCFG_TINPSEL2_TINPLSEH11, timerInput11);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection3
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput12  - Timer Input 12 selection to be configured        
        timerInput13  - Timer Input 13 selection to be configured       
        timerInput14 - Timer Input 14 selection to be configured       
        timerInput15  - Timer Input 15 selection to be configured
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        // Set the timer input selection 
        CSL_BootCfgSetTimerInputSelection3(0x1,0x2,0x3,0x4);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerInputSelection3(Uint16 timerInput12,
                                                        Uint16 timerInput13,
                                                        Uint16 timerInput14,
                                                        Uint16 timerInput15)
{
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL12, timerInput12);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH12, timerInput12);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL13, timerInput13);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH13, timerInput13);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL14, timerInput14);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH14, timerInput14);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEL15, timerInput15);
    CSL_FINS (hBootCfg->TINPSEL3,BOOTCFG_TINPSEL3_TINPLSEH15, timerInput15);
}
/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection4
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput16  - Timer Input 16 selection to be configured        
        timerInput17  - Timer Input 17 selection to be configured 
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n Timer Input Selection
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Writes
 *   @n BOOTCFG_TINPSEL_TINPSEL
 *
 *   @b Example
 *   @verbatim

        // Set the timer input selection 
        CSL_BootCfgSetTimerInputSelection4(0x1,0x2,0x3,0x4);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerInputSelection4(Uint16 timerInput16,
                                                        Uint16 timerInput17)
{
    CSL_FINS (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEL16, timerInput16);
    CSL_FINS (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEH16, timerInput16);
    CSL_FINS (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEL17, timerInput17);
    CSL_FINS (hBootCfg->TINPSEL4,BOOTCFG_TINPSEL4_TINPLSEH17, timerInput17);
}
/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerOutputSelection0
 *
 *   @b Description
 *   @n The function gets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel0 -   Timer output selection 0
        timerOutputSel1 -   Timer output selection 1
        timerOutputSel2 -   Timer output selection 2
        timerOutputSel3 -   Timer output selection 3
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
 *   @b Reads
 *   @n BOOTCFG_TOUTPSEL0_TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL1,
 *      BOOTCFG_TOUTPSEL0_TOUTPSEL2,BOOTCFG_TOUTPSEL0_TOUTPSEL3
 *
 *   @b Example
 *   @verbatim

        Uint8 timerOutputSel0;
        Uint8 timerOutputSel1;
        Uint8 timerOutputSel2;
        Uint8 timerOutputSel3;

        // Get the timer output selections
        CSL_BootCfgGetTimerOutputSelection(&timerOutputSel0, 
                                           &timerOutputSel1, 
                                           &timerOutputSel2, 
                                           &timerOutputSel3);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerOutputSelection0 (Uint8* timerOutputSel0, 
                                                         Uint8* timerOutputSel1, 
                                                         Uint8* timerOutputSel2, 
                                                         Uint8* timerOutputSel3)
{
    *timerOutputSel0 = CSL_FEXT (hBootCfg->TOUTPSEL0, BOOTCFG_TOUTPSEL0_TOUTPSEL0);
    *timerOutputSel1 = CSL_FEXT (hBootCfg->TOUTPSEL0, BOOTCFG_TOUTPSEL0_TOUTPSEL1);
    *timerOutputSel2 = CSL_FEXT (hBootCfg->TOUTPSEL0, BOOTCFG_TOUTPSEL0_TOUTPSEL2);
    *timerOutputSel3 = CSL_FEXT (hBootCfg->TOUTPSEL0, BOOTCFG_TOUTPSEL0_TOUTPSEL3);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerOutputSelection1
 *
 *   @b Description
 *   @n The function gets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel4 -   Timer output selection 4
        timerOutputSel5 -   Timer output selection 5
        timerOutputSel6 -   Timer output selection 6
        timerOutputSel7 -   Timer output selection 7
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
 *   @b Reads
 *   @n BOOTCFG_TOUTPSEL1_TOUTPSEL4,BOOTCFG_TOUTPSEL1_TOUTPSEL5,
 *      BOOTCFG_TOUTPSEL1_TOUTPSEL6,BOOTCFG_TOUTPSEL1_TOUTPSEL7
 *
 *   @b Example
 *   @verbatim

        Uint8 timerOutputSel4;
        Uint8 timerOutputSel5;
        Uint8 timerOutputSel6;
        Uint8 timerOutputSel7;

        // Get the timer output selections
        CSL_BootCfgGetTimerOutputSelection1(&timerOutputSel4, 
                                           &timerOutputSel5, 
                                           &timerOutputSel6, 
                                           &timerOutputSel7);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerOutputSelection1 (Uint8* timerOutputSel4, 
                                                         Uint8* timerOutputSel5, 
                                                         Uint8* timerOutputSel6, 
                                                         Uint8* timerOutputSel7)
{
    *timerOutputSel4 = CSL_FEXT (hBootCfg->TOUTPSEL1, BOOTCFG_TOUTPSEL1_TOUTPSEL4);
    *timerOutputSel5 = CSL_FEXT (hBootCfg->TOUTPSEL1, BOOTCFG_TOUTPSEL1_TOUTPSEL5);
    *timerOutputSel6 = CSL_FEXT (hBootCfg->TOUTPSEL1, BOOTCFG_TOUTPSEL1_TOUTPSEL6);
    *timerOutputSel7 = CSL_FEXT (hBootCfg->TOUTPSEL1, BOOTCFG_TOUTPSEL1_TOUTPSEL7);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerOutputSelection0
 *
 *   @b Description
 *   @n The function sets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel0 -   Timer output selection 0
        timerOutputSel1 -   Timer output selection 1
        timerOutputSel2 -   Timer output selection 2
        timerOutputSel3 -   Timer output selection 3
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
 *   @b Writes
 *   @n BOOTCFG_TOUTPSEL0_TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL1,
 *      BOOTCFG_TOUTPSEL0_TOUTPSEL2,BOOTCFG_TOUTPSEL0_TOUTPSEL3
 *
 *   @b Example
 *   @verbatim

        // Set the timer output selections
        CSL_BootCfgGetTimerOutputSelection0(0x0, 0x1,0x2,0x3);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerOutputSelection0 (Uint8 timerOutputSel0, 
                                                         Uint8 timerOutputSel1, 
                                                         Uint8 timerOutputSel2, 
                                                         Uint8 timerOutputSel3)
{
    CSL_FINS (hBootCfg->TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL0, timerOutputSel0);
    CSL_FINS (hBootCfg->TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL1, timerOutputSel1);
    CSL_FINS (hBootCfg->TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL2, timerOutputSel2);
    CSL_FINS (hBootCfg->TOUTPSEL0,BOOTCFG_TOUTPSEL0_TOUTPSEL3, timerOutputSel3);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerOutputSelection1
 *
 *   @b Description
 *   @n The function sets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel4 -   Timer output selection 4
        timerOutputSel5 -   Timer output selection 5
        timerOutputSel6 -   Timer output selection 6
        timerOutputSel7 -   Timer output selection 7
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
 *   @b Writes
 *   @n BOOTCFG_TOUTPSEL1_TOUTPSEL4,BOOTCFG_TOUTPSEL1_TOUTPSEL5,
 *      BOOTCFG_TOUTPSEL1_TOUTPSEL6,BOOTCFG_TOUTPSEL1_TOUTPSEL7
 *
 *   @b Example
 *   @verbatim

        // Set the timer output selections
        CSL_BootCfgGetTimerOutputSelection1(0x0, 0x1,0x2,0x3);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerOutputSelection1 (Uint8 timerOutputSel4, 
                                                         Uint8 timerOutputSel5, 
                                                         Uint8 timerOutputSel6, 
                                                         Uint8 timerOutputSel7)
{
    CSL_FINS (hBootCfg->TOUTPSEL1,BOOTCFG_TOUTPSEL1_TOUTPSEL4, timerOutputSel4);
    CSL_FINS (hBootCfg->TOUTPSEL1,BOOTCFG_TOUTPSEL1_TOUTPSEL5, timerOutputSel5);
    CSL_FINS (hBootCfg->TOUTPSEL1,BOOTCFG_TOUTPSEL1_TOUTPSEL6, timerOutputSel6);
    CSL_FINS (hBootCfg->TOUTPSEL1,BOOTCFG_TOUTPSEL1_TOUTPSEL7, timerOutputSel7);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetResetMuxLockStatus
 *
 *   @b Description
 *   @n The function gets the reset mux block lock status
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        lockStatus  - Status of the register fields lock 
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
 *   @b Reads
 *   @n BOOTCFG_RSTMUX0_RSTMUX_LOCK0
 *
 *   @b Example
 *   @verbatim

        Uint8   lockStatus;

        // Get the lock status for core 0
        CSL_BootCfgGetResetMuxLockStatus (0, &lockStatus);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetResetMuxLockStatus (Uint8 coreIdx, Uint8* lockStatus)
{
    *lockStatus = CSL_FEXT (hBootCfg->RSTMUX[coreIdx],BOOTCFG_RSTMUX0_RSTMUX_LOCK0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetResetMuxLockStatus
 *
 *   @b Description
 *   @n The function sets the reset mux block lock status
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        lockStatus  - Status of the register fields lock 
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
 *   @b Writes
 *   @n BOOTCFG_RSTMUX0_RSTMUX_LOCK0
 *
 *   @b Example
 *   @verbatim

        // Lock registers for Core 0
        CSL_BootCfgSetResetMuxLockStatus (0, 1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetResetMuxLockStatus (Uint8 coreIdx, Uint8 lockStatus)
{
    CSL_FINS (hBootCfg->RSTMUX[coreIdx],BOOTCFG_RSTMUX0_RSTMUX_LOCK0, lockStatus);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetResetMuxOutputMode
 *
 *   @b Description
 *   @n The function gets the reset mux block output mode
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        outputMode  - Output Mode populated by this API
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
 *   @b Reads
 *   @n BOOTCFG_RSTMUX0_RSTMUX_OMODE0
 *
 *   @b Example
 *   @verbatim

        Uint8   outputMode;

        // Get the output mode for core 0
        CSL_BootCfgGetResetMuxOutputMode (0, &outputMode);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetResetMuxOutputMode (Uint8 coreIdx, Uint8* outputMode)
{
    *outputMode = CSL_FEXT (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_OMODE0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetResetMuxOutputMode
 *
 *   @b Description
 *   @n The function sets the reset mux block output mode
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        outputMode  - Output Mode to be configured
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
 *   @b Writes
 *   @n BOOTCFG_RSTMUX0_RSTMUX_OMODE0
 *
 *   @b Example
 *   @verbatim

        // Set the output mode for core 0 to ensure that the WD Timer generates a local reset
        CSL_BootCfgSetResetMuxOutputMode (0, 2);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetResetMuxOutputMode (Uint8 coreIdx, Uint8 outputMode)
{
    CSL_FINS (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_OMODE0, outputMode);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetResetMuxDelay
 *
 *   @b Description
 *   @n The function gets the reset mux delay between NMI & IReset
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        delay       - Delay populated by this API
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
 *   @b Reads
 *   @n BOOTCFG_RSTMUX0_RSTMUX_DELAY0
 *
 *   @b Example
 *   @verbatim

        Uint8   delay;

        // Get the delay for core 0
        CSL_BootCfgGetResetMuxOutputMode (0, &delay);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetResetMuxDelay (Uint8 coreIdx, Uint8* delay)
{
    *delay = CSL_FEXT (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_DELAY0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetResetMuxDelay
 *
 *   @b Description
 *   @n The function sets the reset mux delay between NMI & IReset
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
        delay       - Delay to be configured
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
 *   @b Writes
 *   @n BOOTCFG_RSTMUX0_RSTMUX_DELAY0
 *
 *   @b Example
 *   @verbatim

        // Set the delay for core 0 to be 2048 CPU/6 cycles delay between NMI & lreset
        CSL_BootCfgSetResetMuxDelay (0, 0x3);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetResetMuxDelay (Uint8 coreIdx, Uint8 delay)
{
    CSL_FINS (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_DELAY0, delay);
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsResetMuxEventDetected
 *
 *   @b Description
 *   @n The function checks if an event is detected by the Result Mux block 
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - Event has been detected
 *   @n FALSE - Event has not been detected
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0
 *
 *   @b Example
 *   @verbatim

        // Check if there is an event detected or not for core 1
        if (CSL_BootCfgIsResetMuxEventDetected (1) == TRUE)
        {
            // Reset Event has been detected
        }
        else
        {
            // Reset Event has NOT been detected
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsResetMuxEventDetected (Uint8 coreIdx)
{
    return (Bool)CSL_FEXT (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgClearResetMuxEvent
 *
 *   @b Description
 *   @n The function is to used clear the detected event in the reset mux block
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Core Index
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
 *   @b Writes
 *   @n BOOTCFG_RSTMUX0_RSTMUX_EVSTAT_CLR0
 *
 *   @b Example
 *   @verbatim

        // Check if there is an event detected or not for core 1
        if (CSL_BootCfgIsResetMuxEventDetected (1) == TRUE)
        {
            // Reset Event has been detected
            ...
            // Clear the reset event
            CSL_BootCfgClearResetMuxEvent(1);
        }
        else
        {
            // Reset Event has NOT been detected
        }

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgClearResetMuxEvent (Uint8 coreIdx)
{
    CSL_FINS (hBootCfg->RSTMUX[coreIdx], BOOTCFG_RSTMUX0_RSTMUX_EVSTAT_CLR0, 1);
}




/** ============================================================================
 *   @n@b CSL_BootCfgGetCOREPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the MAIN PLL configuration.
 *
 *   @b Arguments
     @verbatim
        mainPLLConfig0    - MAIN PLL Configuration0.
        mainPLLConfig1    - MAIN PLL Configuration1.
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
 *   @b Reads
 *   @n BOOTCFG_MAIN_PLL_CTL0, BOOTCFG_MAIN_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  mainPLLConfig0;
        Uint32  mainPLLConfig1;

        // Get the MAIN PLL Configuration
        CSL_BootCfgGetCOREPLLConfiguration (&mainPLLConfig0, &mainPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetCOREPLLConfiguration (Uint32* mainPLLConfig0, Uint32* mainPLLConfig1)
{
    *mainPLLConfig0 = hBootCfg->MAIN_PLL_CTL0;
    *mainPLLConfig1 = hBootCfg->MAIN_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetCOREPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the MAIN PLL configuration.
 *
 *   @b Arguments
     @verbatim
        mainPLLConfig0    - MAIN PLL Configuration0.
        mainPLLConfig1    - MAIN PLL Configuration1.
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
 *   @b Writes
 *   @n BOOTCFG_MAIN_PLL_CTL0, BOOTCFG_MAIN_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  mainPLLConfig0;
        Uint32  mainPLLConfig1;

        // Get the MAIN PLL Configuration
        CSL_BootCfgGetCOREPLLConfiguration (&mainPLLConfig0, &mainPLLConfig1);
        ...
        // Set the MAIN PLL Configuration
        CSL_BootCfgSetCOREPLLConfiguration (mainPLLConfig0, mainPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetCOREPLLConfiguration (Uint32 mainPLLConfig0, Uint32 mainPLLConfig1)
{
    hBootCfg->MAIN_PLL_CTL0 = mainPLLConfig0;
    hBootCfg->MAIN_PLL_CTL1 = mainPLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetARMPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the ARM PLL configuration.
 *
 *   @b Arguments
     @verbatim
        armPLLConfig0    - ARM PLL Configuration0.
        armPLLConfig1    - ARM PLL Configuration1.
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
 *   @b Reads
 *   @n BOOTCFG_ARM_PLL_CTL0, BOOTCFG_ARM_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  armPLLConfig0;
        Uint32  armPLLConfig1;

        // Get the ARM PLL Configuration
        CSL_BootCfgGetARMPLLConfiguration (&armPLLConfig0, &armPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetARMPLLConfiguration (Uint32* armPLLConfig0, Uint32* armPLLConfig1)
{
    *armPLLConfig0 = hBootCfg->ARM_PLL_CTL0;
    *armPLLConfig1 = hBootCfg->ARM_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetARMPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the ARM PLL configuration.
 *
 *   @b Arguments
     @verbatim
        armPLLConfig0    - ARM PLL Configuration0.
        armPLLConfig1    - ARM PLL Configuration1.
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
 *   @b Writes
 *   @n BOOTCFG_ARM_PLL_CTL0, BOOTCFG_ARM_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  armPLLConfig0;
        Uint32  armPLLConfig1;

        // Get the ARM PLL Configuration
        CSL_BootCfgGetARMPLLConfiguration (&armPLLConfig0, &armPLLConfig1);
        ...
        // Set the ARM PLL Configuration
        CSL_BootCfgSetARMPLLConfiguration (armPLLConfig0, armPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetARMPLLConfiguration (Uint32 armPLLConfig0, Uint32 armPLLConfig1)
{
    hBootCfg->ARM_PLL_CTL0 = armPLLConfig0;
    hBootCfg->ARM_PLL_CTL1 = armPLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDDR3PLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the DDR3A PLL configuration.
 *
 *   @b Arguments
     @verbatim
        ddr3APLLConfig0    - DDR3A PLL Configuration0.
        ddr3APLLConfig1    - DDR3A PLL Configuration1.
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
 *   @b Reads
 *   @n BOOTCFG_DDR3A_PLL_CTL0, BOOTCFG_DDR3A_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  ddr3APLLConfig0;
        Uint32  ddr3APLLConfig1;

        // Get the DDR3A PLL Configuration
        CSL_BootCfgGetDDR3PLLConfiguration (&ddr3APLLConfig0, &ddr3APLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDDR3PLLConfiguration (Uint32* ddr3APLLConfig0, Uint32* ddr3APLLConfig1)
{
    *ddr3APLLConfig0 = hBootCfg->DDRA_PLL_CTL0;
    *ddr3APLLConfig1 = hBootCfg->DDRA_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDDR3PLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the DDR3A PLL configuration.
 *
 *   @b Arguments
     @verbatim
        ddr3APLLConfig0    - DDR3A PLL Configuration0.
        ddr3APLLConfig1    - DDR3A PLL Configuration1.
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
 *   @b Writes
 *   @n BOOTCFG_DDR3A_PLL_CTL0, BOOTCFG_DDR3A_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  ddr3APLLConfig0;
        Uint32  ddr3APLLConfig1;

        // Get the DDR3A PLL Configuration
        CSL_BootCfgGetDDR3PLLConfiguration (&ddr3APLLConfig0, &ddr3APLLConfig1);
        ...
        // Set the DDR3A PLL Configuration
        CSL_BootCfgSetDDR3PLLConfiguration (ddr3APLLConfig0, ddr3APLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDDR3PLLConfiguration (Uint32 ddr3APLLConfig0, Uint32 ddr3APLLConfig1)
{
    hBootCfg->DDRA_PLL_CTL0 = ddr3APLLConfig0;
    hBootCfg->DDRA_PLL_CTL1 = ddr3APLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetPAPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the PA PLL configuration.
 *
 *   @b Arguments
     @verbatim
        paPLLConfig0    - PA PLL Configuration0.
        paPLLConfig1    - PA PLL Configuration1.
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
 *   @b Reads
 *   @n BOOTCFG_PASS_PLL_CTL0, BOOTCFG_PASS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  paPLLConfig0;
        Uint32  paPLLConfig1;

        // Get the PA PLL Configuration
        CSL_BootCfgGetPAPLLConfiguration (&paPLLConfig0, &paPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetPAPLLConfiguration (Uint32* paPLLConfig0, Uint32* paPLLConfig1)
{
    *paPLLConfig0 = hBootCfg->PASS_PLL_CTL0;
    *paPLLConfig1 = hBootCfg->PASS_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetPAPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the PA PLL configuration.
 *
 *   @b Arguments
     @verbatim
        paPLLConfig0    - PA PLL Configuration0.
        paPLLConfig1    - PA PLL Configuration1.
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
 *   @b Writes
 *   @n BOOTCFG_PASS_PLL_CTL0, BOOTCFG_PASS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  paPLLConfig0;
        Uint32  paPLLConfig1;

        // Get the PA PLL Configuration
        CSL_BootCfgGetPAPLLConfiguration (&paPLLConfig0, &paPLLConfig1);
        ...
        // Set the PA PLL Configuration
        CSL_BootCfgSetPAPLLConfiguration (paPLLConfig0, paPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetPAPLLConfiguration (Uint32 paPLLConfig0, Uint32 paPLLConfig1)
{
    hBootCfg->PASS_PLL_CTL0 = paPLLConfig0;
    hBootCfg->PASS_PLL_CTL1 = paPLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetPllFreq
 *
 *   @b Description
 *   @n  This function is used for getting the PLL Controller output frequency.
 *
 *
 *   @b Arguments
 *   @verbatim
            pll             Specifies the PLL controller type.
            input_clk       input clock to the PLL controller.
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n output frequency of the PLL controller, 0 if PLLC not supported
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   None
 *
 *   @b Affects
 *   @n None.
 *
 *   @b Example
 *   @verbatim
        Uint32       freq;
        Uint32       input_clk;

		input_clk = BOARD_get_external_clock(CSL_PLL_SYS);
        freq = CSL_getPllFreq(CSL_PLL_SYS, input_clk);

    @endverbatim
 * ===========================================================================
 */
static inline Uint32 CSL_BootCfgGetPllFreq(CSL_PllcType pll, Uint32 input_clk)
{
    CSL_PllcHandle handle;
    Uint32 PLLConfig0, PLLConfig1;
    Uint32 mult = 1, prediv = 1, output_div = 1;
    Uint32 freq;

    switch(pll)
    {
        case CSL_PLL_SYS:
            handle = (CSL_PllcHandle) CSL_PLLC_REGS;
            if (CSL_FEXT(handle->PLLCTL, PLLC_PLLCTL_PLLEN))
            {
                /* If main PLL is enabled, calculate the system clock based on
                   the input clock, multiplier and divider */
                CSL_BootCfgGetCOREPLLConfiguration(&PLLConfig0, &PLLConfig1);
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_MAIN_PLL_CTL0_PLLD) + 1;
                mult = (((PLLConfig0 & CSL_BOOTCFG_MAIN_PLL_CTL0_PLLM_MASK) >> 6) |
			            CSL_FEXT(handle->PLLM, PLLC_PLLM_PLLM)) + 1;
                output_div = CSL_FEXT(handle->SECCTL, PLLC_SECCTL_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        case CSL_PLL_PA:
            CSL_BootCfgGetPAPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_PASS_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_PASS_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_PASS_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_PASS_PLL_CTL0_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        case CSL_PLL_ARM:
            CSL_BootCfgGetARMPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_ARM_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_ARM_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_ARM_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_ARM_PLL_CTL0_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        case CSL_PLL_DDR3:
            CSL_BootCfgGetDDR3PLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_DDR3A_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3A_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3A_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3A_PLL_CTL0_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        default:
            freq = 0;
            break;
    }

    return freq;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetCorePLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to get the core PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the Core PLL IO Clock buffer.
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
 *   @b Reads
 *   @n BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the Core PLL Observation Clock Control 
        CSL_BootCfgGetCorePLLObservationClockControl(&selection, &enable);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetCorePLLObservationClockControl 
(
    Uint8* selection, 
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLK_CTL;

    *selection = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_PLL_OBSCLK_SEL);
    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_EN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetCorePLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to set the core PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the Core PLL IO Clock buffer.
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
 *   @b Writes
 *   @n BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the Core PLL Observation Clock Control 
        CSL_BootCfgGetCorePLLObservationClockControl(&selection, &enable);
        
        // IO Clock buffer is enabled.
        CSL_BootCfgSetCorePLLObservationClockControl(selection, 1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetCorePLLObservationClockControl 
(
    Uint8 selection, 
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_EN, enable);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDDR3PLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to get the DDR3A PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the DDR3A PLL IO Clock buffer.
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
 *   @b Reads
 *   @n BOOTCFG_OBSCLK_CTL_DDR3_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the DDR3A PLL Observation Clock Control 
        CSL_BootCfgGetDDR3PLLObservationClockControl(&selection, &enable);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDDR3PLLObservationClockControl 
(
    Uint8* selection, 
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLK_CTL;
    *selection = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_PLL_OBSCLK_SEL);
    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_DDR3_PLL_OBSCLK_EN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDDR3PLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to set the DDR3A PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the DDR3A PLL IO Clock buffer.
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
 *   @b Writes
 *   @n BOOTCFG_OBSCLK_CTL_DDR3_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the DDR3A PLL Observation Clock Control 
        CSL_BootCfgGetDDR3PLLObservationClockControl(&selection, &enable);

        // DDR3A IO Clock Buffer is disabled.
        CSL_BootCfgSetDDR3PLLObservationClockControl(selection, 0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDDR3PLLObservationClockControl 
(
    Uint8 selection, 
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_DDR3_PLL_OBSCLK_EN, enable);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetPAPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to get the PA PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the PA PLL IO Clock buffer.
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
 *   @b Reads
 *   @n BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the PA PLL Observation Clock Control 
        CSL_BootCfgGetPAPLLObservationClockControl(&selection, &enable);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetPAPLLObservationClockControl 
(
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLK_CTL;

     *enable    = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetPAPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to set the PA PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the PA PLL IO Clock buffer.
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
 *   @b Writes
 *   @n BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the PA PLL Observation Clock Control 
        CSL_BootCfgGetPAPLLObservationClockControl(&selection, &enable);

        // PA IO Clock Buffer is disabled.
        CSL_BootCfgSetPAPLLObservationClockControl(selection, 0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetPAPLLObservationClockControl 
(
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN, enable);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetQMPriority
 *
 *   @b Description
 *   @n The function is to used to get QM Master port transactions priority.
 *
 *   @b Arguments
     @verbatim
        qmprio  -   QM Master port transaction priority read.
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
 *   @b Reads
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRIOR
 *
 *   @b Example
 *   @verbatim

        Uint8   qmprio;

        // Get the QM Priority from Chip Misc Control register
        CSL_BootCfgGetQMPriority(&qmprio);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetQMPriority 
(
    Uint8* qmprio
)
{
    *qmprio = CSL_FEXT (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRIOR);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetQMPriority
 *
 *   @b Description
 *   @n The function is to used to set up QM Master port transactions priority.
 *
 *   @b Arguments
     @verbatim
        qmprio  -   QM Master port transaction priority to configure.
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
 *   @b Writes
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRIOR
 *
 *   @b Example
 *   @verbatim

        Uint8   qmprio = 1;

        // Set the QM Priority in Chip Misc Control register
        CSL_BootCfgSetQMPriority(qmprio);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetQMPriority(Uint8 qmprio)
{
    CSL_FINS (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRIOR, qmprio);
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsMSMCParityResetBlocked
 *
 *   @b Description
 *   @n The function is to used to get the MSMC parity RAM reset block status 
 *      from the Chip Miscellaneous Control register.
 *
 *   @b Arguments
 *   @n None
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
 *   @b Reads
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST
 *
 *   @b Example
 *   @verbatim

        // Get the MSMC parity block status from Chip Misc Control register
        if (CSL_BootCfgIsMSMCParityResetBlocked() == TRUE)
        {
            // MSMC parity RAM reset is blocked.
        }
        else
        {
            // MSMC parity RAM reset is un-blocked.
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsMSMCParityResetBlocked (void)
{
    return CSL_FEXT (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST);
}

/** ============================================================================
 *   @n@b CSL_BootCfgBlockMSMCParityReset
 *
 *   @b Description
 *   @n The function enables the MSMC Parity RAM block bit, thus preventing the
 *      MSMC parity RAM from being reset.
 *
 *   @b Arguments
 *   @n None
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
 *   @b Writes
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST=1
 *
 *   @b Example
 *   @verbatim

        // Block MSMC parity RAM from reset
        CSL_BootCfgBlockMSMCParityReset();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgBlockMSMCParityReset (void)
{
    CSL_FINS (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgUnblockMSMCParityReset
 *
 *   @b Description
 *   @n The function disables the MSMC Parity RAM block bit, thus enabling the
 *      MSMC parity RAM reset control.
 *
 *   @b Arguments
 *   @n None
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
 *   @b Writes
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST=0
 *
 *   @b Example
 *   @verbatim

        // Un-Block MSMC parity RAM from reset
        CSL_BootCfgUnblockMSMCParityReset();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgUnblockMSMCParityReset (void)
{
    CSL_FINS (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_MSMC_BLOCK_PARITY_RST, 0);
}

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_BOOTCFGAUX_V2_H_ */

