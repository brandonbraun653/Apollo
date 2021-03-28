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

#ifndef CSL_BOOTCFGAUX_V0_H_
#define CSL_BOOTCFGAUX_V0_H_

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
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM4_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM5_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM6_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM7_COMPLETE
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
    else if (coreIdx == 3)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE);
    else if (coreIdx == 4)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM4_COMPLETE);
    else if (coreIdx == 5)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM5_COMPLETE);
    else if (coreIdx == 6)
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM6_COMPLETE);
    else
        return (Bool)CSL_FEXT (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM7_COMPLETE);
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
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM2_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM4_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM5_COMPLETE;
 *   @n  BOOTCFG_BOOT_COMPLETE_GEM6_COMPLETE;BOOTCFG_BOOT_COMPLETE_GEM7_COMPLETE
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
    if (coreIdx == 4)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM4_COMPLETE, 1);
    if (coreIdx == 5)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM5_COMPLETE, 1);
    if (coreIdx == 6)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM6_COMPLETE, 1);
    if (coreIdx == 7)
        CSL_FINS (hBootCfg->BOOT_COMPLETE,BOOTCFG_BOOT_COMPLETE_GEM7_COMPLETE, 1);
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
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT2;BOOTCFG_RESET_STAT_LRST_STAT3;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT4;BOOTCFG_RESET_STAT_LRST_STAT5;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT6;BOOTCFG_RESET_STAT_LRST_STAT7
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
    else if (coreIdx == 3)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM3_COMPLETE);
    else if (coreIdx == 4)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM4_COMPLETE);
    else if (coreIdx == 5)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM5_COMPLETE);
    else if (coreIdx == 6)
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM6_COMPLETE);
    else
        return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOT_COMPLETE_GEM7_COMPLETE);
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
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR;BOOTCFG_RESET_STAT_CLR_LRST_STAT_1_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_2_CLR;BOOTCFG_RESET_STAT_CLR_LRST_STAT_3_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_4_CLR;BOOTCFG_RESET_STAT_CLR_LRST_STAT_5_CLR;
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_6_CLR;BOOTCFG_RESET_STAT_CLR_LRST_STAT_7_CLR
 *
 *   @b  Affects
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT0=0;BOOTCFG_RESET_STAT_LRST_STAT1=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT2=0;BOOTCFG_RESET_STAT_LRST_STAT3=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT4=0;BOOTCFG_RESET_STAT_LRST_STAT5=0;
 *   @n  BOOTCFG_RESET_STAT_LRST_STAT6=0;BOOTCFG_RESET_STAT_LRST_STAT7=0
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
    if (coreIdx == 4)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_4_CLR, 1);
    if (coreIdx == 5)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_5_CLR, 1);
    if (coreIdx == 6)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_6_CLR, 1);
    if (coreIdx == 7)
        CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_LRST_STAT_7_CLR, 1);
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
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT0,BOOTCFG_LRSTNMISTAT_LRESET_STAT0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT1,BOOTCFG_LRSTNMISTAT_LRESET_STAT1;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT2,BOOTCFG_LRSTNMISTAT_LRESET_STAT2;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT3,BOOTCFG_LRSTNMISTAT_LRESET_STAT3;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT4,BOOTCFG_LRSTNMISTAT_LRESET_STAT4;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT5,BOOTCFG_LRSTNMISTAT_LRESET_STAT5;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT6,BOOTCFG_LRSTNMISTAT_LRESET_STAT6;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT7,BOOTCFG_LRSTNMISTAT_LRESET_STAT7;
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
    if (coreIdx == 4)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT4);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT4);
    }
    if (coreIdx == 5)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT5);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT5);
    }
    if (coreIdx == 6)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT6);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT6);
    }
    if (coreIdx == 7)
    {
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT7);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT7);
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
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_4_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_4_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_5_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_5_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_6_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_6_CLR;
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_7_CLR,BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_7_CLR;
 *
 *   @b  Affects
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT0=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT0=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT1=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT1=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT2=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT2=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT3=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT3=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT4=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT4=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT5=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT5=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT6=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT6=0;
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT7=0,BOOTCFG_LRSTNMISTAT_LRESET_STAT7=0;
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
    if (coreIdx == 4)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_4_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_4_CLR, localStatus);
    }
    if (coreIdx == 5)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_5_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_5_CLR, localStatus);
    }
    if (coreIdx == 6)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_6_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_6_CLR, localStatus);
    }
    if (coreIdx == 7)
    {
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_NMI_STAT_7_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_7_CLR, localStatus);
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
 *   @n@b CSL_BootCfgGetTimerInputSelection
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        None
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

        Uint16 timerInput;

        // Get the timer input selection 
        timerInput = CSL_BootCfgGetTimerInputSelection();

     @endverbatim
 * =============================================================================
 */
static inline Uint16 CSL_BootCfgGetTimerInputSelection (void)
{
    return CSL_FEXT (hBootCfg->TINPSEL,BOOTCFG_TINPSEL_TINPSEL);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput  - Timer Input selection to be configured
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
        CSL_BootCfgSetTimerInputSelection(0x1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerInputSelection (Uint16 timerInput)
{
    CSL_FINS (hBootCfg->TINPSEL,BOOTCFG_TINPSEL_TINPSEL, timerInput);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetTimerOutputSelection
 *
 *   @b Description
 *   @n The function gets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel0 -   Timer output selection 0
        timerOutputSel1 -   Timer output selection 1
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
 *   @n BOOTCFG_TOUTSEL_TOUTSEL0,BOOTCFG_TOUTSEL_TOUTSEL1
 *
 *   @b Example
 *   @verbatim

        Uint8 timerOutputSel0;
        Uint8 timerOutputSel1;

        // Get the timer output selections
        CSL_BootCfgGetTimerOutputSelection(&timerOutputSel0, &timerOutputSel1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetTimerOutputSelection (Uint8* timerOutputSel0, Uint8* timerOutputSel1)
{
    Uint32 value = hBootCfg->TOUTSEL;

    *timerOutputSel0 = CSL_FEXT (value, BOOTCFG_TOUTSEL_TOUTSEL0);
    *timerOutputSel1 = CSL_FEXT (value, BOOTCFG_TOUTSEL_TOUTSEL1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerOutputSelection
 *
 *   @b Description
 *   @n The function sets the timer output selection
 *
 *   @b Arguments
     @verbatim
        timerOutputSel0 -   Timer output selection 0
        timerOutputSel1 -   Timer output selection 1
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
 *   @n BOOTCFG_TOUTSEL_TOUTSEL0,BOOTCFG_TOUTSEL_TOUTSEL1
 *
 *   @b Example
 *   @verbatim

        // Set the timer output selections
        CSL_BootCfgGetTimerOutputSelection(0x0, 0x1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetTimerOutputSelection (Uint8 timerOutputSel0, Uint8 timerOutputSel1)
{
    hBootCfg->TOUTSEL = CSL_FMK (BOOTCFG_TOUTSEL_TOUTSEL0, timerOutputSel0) |
                        CSL_FMK (BOOTCFG_TOUTSEL_TOUTSEL1, timerOutputSel1);
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
    *ddr3APLLConfig0 = hBootCfg->DDR3A_PLL_CTL0;
    *ddr3APLLConfig1 = hBootCfg->DDR3A_PLL_CTL1;
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
    hBootCfg->DDR3A_PLL_CTL0 = ddr3APLLConfig0;
    hBootCfg->DDR3A_PLL_CTL1 = ddr3APLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDDR3BPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the DDR3B PLL configuration.
 *
 *   @b Arguments
     @verbatim
        ddr3BPLLConfig0    - DDR3B PLL Configuration0.
        ddr3BPLLConfig1    - DDR3B PLL Configuration1.
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
 *   @n BOOTCFG_DDR3B_PLL_CTL0, BOOTCFG_DDR3B_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  ddr3BPLLConfig0;
        Uint32  ddr3BPLLConfig1;

        // Get the DDR3B PLL Configuration
        CSL_BootCfgGetDDR3BPLLConfiguration (&ddr3BPLLConfig0, &ddr3BPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDDR3BPLLConfiguration (Uint32* ddr3BPLLConfig0, Uint32* ddr3BPLLConfig1)
{
    *ddr3BPLLConfig0 = hBootCfg->DDR3B_PLL_CTL0;
    *ddr3BPLLConfig1 = hBootCfg->DDR3B_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDDR3BPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the DDR3B PLL configuration.
 *
 *   @b Arguments
     @verbatim
        ddr3BPLLConfig0    - DDR3B PLL Configuration0.
        ddr3BPLLConfig1    - DDR3B PLL Configuration1.
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
 *   @n BOOTCFG_DDR3B_PLL_CTL0, BOOTCFG_DDR3B_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  ddr3BPLLConfig0;
        Uint32  ddr3BPLLConfig1;

        // Get the DDR3B PLL Configuration
        CSL_BootCfgGetDDR3BPLLConfiguration (&ddr3BPLLConfig0, &ddr3BPLLConfig1);
        ...
        // Set the DDR3B PLL Configuration
        CSL_BootCfgSetDDR3BPLLConfiguration (ddr3BPLLConfig0, ddr3BPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDDR3BPLLConfiguration (Uint32 ddr3BPLLConfig0, Uint32 ddr3BPLLConfig1)
{
    hBootCfg->DDR3B_PLL_CTL0 = ddr3BPLLConfig0;
    hBootCfg->DDR3B_PLL_CTL1 = ddr3BPLLConfig1;
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
            /* handle = CSL_PLLC_open(0); */
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

        case CSL_PLL_DDR3B:
            CSL_BootCfgGetDDR3BPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_DDR3B_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3B_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3B_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_DDR3B_PLL_CTL0_CLKOD) + 1;
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
 *   @n@b CSL_BootCfgGetLEDPassDoneStatus
 *
 *   @b Description
 *   @n The function is used to get the LED pass done (0) status for a specific core
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Index of the core for which the status is required.
        pass        - Pass Status Flag
        done        - Done Status Flag
        idle        - Idle Status Flag
        waitLoop    - Function Wait Loop Flag
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
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P0,BOOTCFG_LED_CORE_PASSDONE0_D0,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I0,BOOTCFG_LED_CORE_PASSDONE0_L0;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P1,BOOTCFG_LED_CORE_PASSDONE0_D1,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I1,BOOTCFG_LED_CORE_PASSDONE0_L1;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P2,BOOTCFG_LED_CORE_PASSDONE0_D2,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I2,BOOTCFG_LED_CORE_PASSDONE0_L2;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P3,BOOTCFG_LED_CORE_PASSDONE0_D3,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I3,BOOTCFG_LED_CORE_PASSDONE0_L3;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P4,BOOTCFG_LED_CORE_PASSDONE0_D4,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I4,BOOTCFG_LED_CORE_PASSDONE0_L4;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P5,BOOTCFG_LED_CORE_PASSDONE0_D5,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I5,BOOTCFG_LED_CORE_PASSDONE0_L5;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P6,BOOTCFG_LED_CORE_PASSDONE0_D6,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I6,BOOTCFG_LED_CORE_PASSDONE0_L6;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P7,BOOTCFG_LED_CORE_PASSDONE0_D7,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I7,BOOTCFG_LED_CORE_PASSDONE0_L7;
 *
 *   @b Example
 *   @verbatim

        Uint8  pass, 
        Uint8  done, 
        Uint8  idle, 
        Uint8  waitLoop

        // Get the LED Pass Done 0 Status for Core 1
        CSL_BootCfgGetLEDPassDoneStatus (1, &pass, &done, &idle, &waitLoop);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetLEDPassDoneStatus 
(
    Uint8   coreIdx, 
    Uint8*  pass, 
    Uint8*  done, 
    Uint8*  idle, 
    Uint8*  waitLoop
)
{
    Uint32 value = hBootCfg->LED_CORE_PASSDONE0; 

    if (coreIdx == 0)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P0);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D0);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I0);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L0);
    }else if (coreIdx == 1)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P1);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D1);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I1);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L1);
    }else if (coreIdx == 2)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P2);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D2);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I2);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L2);
    }else if (coreIdx == 3)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P3);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D3);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I3);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L3);
    }else if (coreIdx == 4)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P4);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D4);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I4);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L4);
    }else if (coreIdx == 5)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P5);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D5);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I5);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L5);
    }else if (coreIdx == 6)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P6);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D6);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I6);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L6);
    }else
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_P7);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_D7);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_I7);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE0_L7);
    }
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetLEDPassDoneStatus
 *
 *   @b Description
 *   @n The function is used to set the LED pass done status for a specific core
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Index of the core for which the status is required.
        pass        - Pass Status Flag
        done        - Done Status Flag
        idle        - Idle Status Flag
        waitLoop    - Function Wait Loop Flag
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
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P0,BOOTCFG_LED_CORE_PASSDONE0_D0,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I0,BOOTCFG_LED_CORE_PASSDONE0_L0;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P1,BOOTCFG_LED_CORE_PASSDONE0_D1,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I1,BOOTCFG_LED_CORE_PASSDONE0_L1;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P2,BOOTCFG_LED_CORE_PASSDONE0_D2,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I2,BOOTCFG_LED_CORE_PASSDONE0_L2;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P3,BOOTCFG_LED_CORE_PASSDONE0_D3,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I3,BOOTCFG_LED_CORE_PASSDONE0_L3;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P4,BOOTCFG_LED_CORE_PASSDONE0_D4,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I4,BOOTCFG_LED_CORE_PASSDONE0_L4;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P5,BOOTCFG_LED_CORE_PASSDONE0_D5,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I5,BOOTCFG_LED_CORE_PASSDONE0_L5;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P6,BOOTCFG_LED_CORE_PASSDONE0_D6,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I6,BOOTCFG_LED_CORE_PASSDONE0_L6;
 *   @n BOOTCFG_LED_CORE_PASSDONE0_P7,BOOTCFG_LED_CORE_PASSDONE0_D7,
 *   @n BOOTCFG_LED_CORE_PASSDONE0_I7,BOOTCFG_LED_CORE_PASSDONE0_L7;
 *
 *   @b Example
 *   @verbatim

        Uint8  pass, 
        Uint8  done, 
        Uint8  idle, 
        Uint8  waitLoop

        // Get the LED Pass Done Status for Core 0
        CSL_BootCfgGetLEDPassDoneStatus (0, &pass, &done, &idle, &waitLoop);
        ...
        // Set the PASS Flag for core 0
        CSL_BootCfgSetLEDPassDoneStatus(0, 1, done, idle, waitLoop);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetLEDPassDoneStatus 
(
    Uint8  coreIdx, 
    Uint8  pass, 
    Uint8  done, 
    Uint8  idle, 
    Uint8  waitLoop
)
{
    if (coreIdx == 0)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P0, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D0, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I0, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L0, waitLoop);
    }else if (coreIdx == 1)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P1, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D1, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I1, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L1, waitLoop);
    }else if (coreIdx == 2)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P2, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D2, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I2, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L2, waitLoop);
    }else if (coreIdx == 3)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P3, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D3, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I3, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L3, waitLoop);
    }else if (coreIdx == 4)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P4, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D4, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I4, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L4, waitLoop);
    }else if (coreIdx == 5)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P5, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D5, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I5, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L5, waitLoop);
    }else if (coreIdx == 6)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P6, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D6, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I6, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L6, waitLoop);
    }else
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_P7, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_D7, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_I7, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE0, BOOTCFG_LED_CORE_PASSDONE0_L7, waitLoop);
    }
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetLEDPassDone1Status
 *
 *   @b Description
 *   @n The function is used to get the LED pass done (1) status for a specific core
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Index of the core for which the status is required.
        pass        - Pass Status Flag
        done        - Done Status Flag
        idle        - Idle Status Flag
        waitLoop    - Function Wait Loop Flag
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
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P0,BOOTCFG_LED_CORE_PASSDONE1_D0,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I0,BOOTCFG_LED_CORE_PASSDONE1_L0;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P1,BOOTCFG_LED_CORE_PASSDONE1_D1,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I1,BOOTCFG_LED_CORE_PASSDONE1_L1;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P2,BOOTCFG_LED_CORE_PASSDONE1_D2,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I2,BOOTCFG_LED_CORE_PASSDONE1_L2;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P3,BOOTCFG_LED_CORE_PASSDONE1_D3,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I3,BOOTCFG_LED_CORE_PASSDONE1_L3;
 *
 *   @b Example
 *   @verbatim

        Uint8  pass, 
        Uint8  done, 
        Uint8  idle, 
        Uint8  waitLoop

        // Get the LED Pass Done 0 Status for Core 1
        CSL_BootCfgGetLEDPassDone1Status (1, &pass, &done, &idle, &waitLoop);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetLEDPassDone1Status 
(
    Uint8   coreIdx, 
    Uint8*  pass, 
    Uint8*  done, 
    Uint8*  idle, 
    Uint8*  waitLoop
)
{
    Uint32 value = hBootCfg->LED_CORE_PASSDONE1; 

    if (coreIdx == 0)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_P0);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_D0);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_I0);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_L0);
    }else if (coreIdx == 1)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_P1);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_D1);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_I1);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_L1);
    }else if (coreIdx == 2)
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_P2);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_D2);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_I2);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_L2);
    }else
    {
        *pass     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_P3);
        *done     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_D3);
        *idle     = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_I3);
        *waitLoop = CSL_FEXT (value, BOOTCFG_LED_CORE_PASSDONE1_L3);
    }
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetLEDPassDone1Status
 *
 *   @b Description
 *   @n The function is used to set the LED pass done (1) status for a specific core
 *
 *   @b Arguments
     @verbatim
        coreIdx     - Index of the core for which the status is required.
        pass        - Pass Status Flag
        done        - Done Status Flag
        idle        - Idle Status Flag
        waitLoop    - Function Wait Loop Flag
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
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P0,BOOTCFG_LED_CORE_PASSDONE1_D0,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I0,BOOTCFG_LED_CORE_PASSDONE1_L0;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P1,BOOTCFG_LED_CORE_PASSDONE1_D1,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I1,BOOTCFG_LED_CORE_PASSDONE1_L1;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P2,BOOTCFG_LED_CORE_PASSDONE1_D2,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I2,BOOTCFG_LED_CORE_PASSDONE1_L2;
 *   @n BOOTCFG_LED_CORE_PASSDONE1_P3,BOOTCFG_LED_CORE_PASSDONE1_D3,
 *   @n BOOTCFG_LED_CORE_PASSDONE1_I3,BOOTCFG_LED_CORE_PASSDONE1_L3;
 *
 *   @b Example
 *   @verbatim

        Uint8  pass, 
        Uint8  done, 
        Uint8  idle, 
        Uint8  waitLoop

        // Get the LED Pass Done (1) Status for Core 0
        CSL_BootCfgGetLEDPassDone1Status (0, &pass, &done, &idle, &waitLoop);
        ...
        // Set the PASS Flag for core 0
        CSL_BootCfgSetLEDPassDone1Status(0, 1, done, idle, waitLoop);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetLEDPassDone1Status 
(
    Uint8  coreIdx, 
    Uint8  pass, 
    Uint8  done, 
    Uint8  idle, 
    Uint8  waitLoop
)
{
    if (coreIdx == 0)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_P0, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_D0, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_I0, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_L0, waitLoop);
    }else if (coreIdx == 1)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_P1, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_D1, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_I1, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_L1, waitLoop);
    }else if (coreIdx == 2)
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_P2, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_D2, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_I2, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_L2, waitLoop);
    }else
    {
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_P3, pass);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_D3, done);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_I3, idle);
        CSL_FINS (hBootCfg->LED_CORE_PASSDONE1, BOOTCFG_LED_CORE_PASSDONE1_L3, waitLoop);
    }
}

/** ============================================================================
 *   @n@b CSL_BootCfgIsLEDPLLLocked
 *
 *   @b Description
 *   @n The function is to used check if the LED PLL is locked or not?
 *
 *   @b Arguments
     @verbatim
        None
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n TRUE  - LED PLL Locked
 *   @n FALSE - LED PLL is not Locked
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n BOOTCFG_LED_PLLLOCK0_PLLLOCK
 *
 *   @b Example
 *   @verbatim

        // Is the LED PLL Locked or not?
        if (CSL_BootCfgIsLEDPLLLocked () == TRUE)
        {
            // LED PLL is locked
        }
        else
        {
            // LED PLL is not locked.
        }

     @endverbatim
 * =============================================================================
 */
static inline Bool CSL_BootCfgIsLEDPLLLocked (void)
{
    return (Bool)CSL_FEXT(hBootCfg->LED_PLLLOCK0, BOOTCFG_LED_PLLLOCK0_PLLLOCK);
}

/** ============================================================================
 *   @n@b CSL_BootCfgLockLEDPLL
 *
 *   @b Description
 *   @n The function is to used lock the LED PLL
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
 *   @n BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK=1
 *
 *   @b Example
 *   @verbatim

        // Lock the LED PLL 
        CSL_BootCfgLockLEDPLL();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgLockLEDPLL (void)
{
    CSL_FINS(hBootCfg->LED_PLLLOCK0, BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK, 1);
}

/** ============================================================================
 *   @n@b CSL_BootCfgUnlockLEDPLL
 *
 *   @b Description
 *   @n The function is to used unlock the LED PLL (0)
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
 *   @n BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK=0
 *
 *   @b Example
 *   @verbatim

        // Lock the LED PLL 
        CSL_BootCfgLockLEDPLL();

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgUnlockLEDPLL (void)
{
    CSL_FINS(hBootCfg->LED_PLLLOCK0, BOOTCFG_LED_PLLLOCK0_STICKY_EN_LOCK, 0);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetLEDChipPassDoneStatus
 *
 *   @b Description
 *   @n The function is to used to get the LED Chip Pass Done Status
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
 *   @b Reads
 *   @n BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS,BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE
 *
 *   @b Example
 *   @verbatim

        Uint8   pass;
        Uint8   done;

        // Get the LED Chip Pass Done 
        CSL_BootCfgGetLEDChipPassDoneStatus(&pass, &done);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetLEDChipPassDoneStatus (Uint8* pass, Uint8* done)
{
    Uint32 value = hBootCfg->LED_CHIP_PASSDONE;

    *pass = CSL_FEXT(value, BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS);
    *done = CSL_FEXT(value, BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetLEDChipPassDoneStatus
 *
 *   @b Description
 *   @n The function is to used to set the LED Chip Pass Done Status
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
 *   @n BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS,BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE
 *
 *   @b Example
 *   @verbatim

        // Set the LED Chip Pass Done flags 
        CSL_BootCfgSetLEDChipPassDoneStatus(1, 1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetLEDChipPassDoneStatus (Uint8 pass, Uint8 done)
{
    hBootCfg->LED_CHIP_PASSDONE = CSL_FMK (BOOTCFG_LED_CHIP_PASSDONE_CHIP_PASS, pass) | 
                                  CSL_FMK (BOOTCFG_LED_CHIP_PASSDONE_CHIP_DONE, done);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetROMChecksum
 *
 *   @b Description
 *   @n The function is to used to get the ROM checksum
 *
 *   @b Arguments
     @verbatim
        romLSBChecksum     - LSB of 64-bit ROM Checksum
        romMSBChecksum     - MSB of 64-bit ROM Checksum
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
 *   @n BOOTCFG_EFUSE_SECROM_CHKSUM0,BOOTCFG_EFUSE_SECROM_CHKSUM1
 *
 *   @b Example
 *   @verbatim

        Uint32   romLSBChecksum;
        Uint32   romMSBChecksum;

        // Get the ROM Checksum
        CSL_BootCfgGetROMChecksum(&romLSBChecksum, &romMSBChecksum);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetROMChecksum (Uint32* romLSBChecksum, Uint32* romMSBChecksum)
{
    *romLSBChecksum = hBootCfg->EFUSE_SECROM_CHKSUM0;
    *romMSBChecksum = hBootCfg->EFUSE_SECROM_CHKSUM1;
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

    *selection = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_SEL);
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
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_CORE_PLL_OBSCLK_EN, enable);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetDDR3BPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to get the DDR3B PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        enable    - Status of the DDR3B PLL IO Clock buffer.
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
 *   @n BOOTCFG_OBSCLK_CTL_DDR3B_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   enable;

        // Get the DDR3B PLL Observation Clock Control 
        CSL_BootCfgGetDDR3BPLLObservationClockControl(&enable);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDDR3BPLLObservationClockControl 
(
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLK_CTL;

    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_DDR3B_PLL_OBSCLK_EN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDDR3BPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to set the DDR3B PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        enable    - Status of the DDR3B PLL IO Clock buffer.
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
 *   @n BOOTCFG_OBSCLK_CTL_DDR3B_PLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   enable;

        // Get the DDR3B PLL Observation Clock Control 
        CSL_BootCfgGetDDR3BPLLObservationClockControl(&enable);

        // DDR3B IO Clock Buffer is disabled.
        CSL_BootCfgSetDDR3BPLLObservationClockControl(0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDDR3BPLLObservationClockControl 
(
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_DDR3B_PLL_OBSCLK_EN, enable);
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
 *   @n BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_EN
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

    *selection = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_SEL);
    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_EN);
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
 *   @n BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_EN
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
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_DDR3A_PLL_OBSCLK_EN, enable);
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
 *   @n BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN
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
    Uint8* selection, 
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLK_CTL;

    *selection = CSL_FEXT (value, BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_SEL);
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
 *   @n BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_SEL,BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_EN
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
    Uint8 selection, 
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLK_CTL, BOOTCFG_OBSCLK_CTL_PA_PLL_OBSCLK_SEL, selection);
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
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRI
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
    *qmprio = CSL_FEXT (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRI);
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
 *   @n BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRI
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
    CSL_FINS (hBootCfg->CHIP_MISC, BOOTCFG_CHIP_MISC_CHIP_MISC_QM_PRI, qmprio);
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

#endif /* CSL_BOOTCFGAUX_V0_H_ */

