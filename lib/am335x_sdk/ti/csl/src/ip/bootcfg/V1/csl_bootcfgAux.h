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

#ifndef CSL_BOOTCFGAUX_V1_H_
#define CSL_BOOTCFGAUX_V1_H_

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
    if (CSL_FEXT(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_BIG_ENDIAN) == 1)
        return FALSE;
    return TRUE;
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
    return CSL_FEXT(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_BOOT_MODE);
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
 *   @n  BOOTCFG_DEVSTAT_BOOT_MODE
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
    CSL_FINS(hBootCfg->DEVSTAT, BOOTCFG_DEVSTAT_BOOT_MODE, bootMode);
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
    return CSL_FEXT(hBootCfg->BOOTADDR_GEM0_REG, BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0);
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
    CSL_FINS(hBootCfg->BOOTADDR_GEM0_REG, BOOTCFG_BOOTADDR_GEM0_REG_BOOTADDR_GEM0, bootAddress);
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
 *   @n BOOTCFG_NMIGR_0_NMIGR_0_REG
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
    CSL_FINS (hBootCfg->NMIGR_0, BOOTCFG_NMIGR_0_NMIGR_0_REG, 1);
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

	hBootCfg->IPCGR0 = CSL_FMK(BOOTCFG_IPCGR0_IPCGR0_SRC, sourceId) | 
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
    *lockStatus = CSL_FEXT (hBootCfg->RSTMUX0,BOOTCFG_RSTMUX0_RSTMUX_LOCK0);
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
    CSL_FINS (hBootCfg->RSTMUX0,BOOTCFG_RSTMUX0_RSTMUX_LOCK0, lockStatus);
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
    *outputMode = CSL_FEXT (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_OMODE0);
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
    CSL_FINS (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_OMODE0, outputMode);
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
    *delay = CSL_FEXT (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_DELAY0);
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
    CSL_FINS (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_DELAY0, delay);
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
    return (Bool)CSL_FEXT (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_EVSTAT0);
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
    CSL_FINS (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_EVSTAT_CLR0, 1);
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

/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_BOOTCFGAUX_V1_H_ */

