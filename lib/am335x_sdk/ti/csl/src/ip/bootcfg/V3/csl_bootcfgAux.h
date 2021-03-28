/**
 *   @file  csl_bootcfgAux.h
 *
 *   @brief   
 *      This is the Boot Configuration Auxilary Header File which exposes 
 *      limited set of CSL Functional Layer API's to configure the BOOTCFG Module.
 *      APIs being exposed are limited to the one available in pre-existing
 *      KeyStone-2 devices.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2014, Texas Instruments, Inc.
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

#ifndef CSL_BOOTCFGAUX_V3_H_
#define CSL_BOOTCFGAUX_V3_H_

#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_pllc.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_BOOTCFG_FUNCTION
 @{ */

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
 *   @n  BOOTCFG_JTAGID
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
    *id = hBootCfg->JTAGID;
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
    hBootCfg->KICK0 = 0x83e70b13;
    hBootCfg->KICK1 = 0x95a4f1e0;

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
    hBootCfg->KICK0 = 0x1;
    hBootCfg->KICK1 = 0x1;

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
    return CSL_FEXT(hBootCfg->DSP_BOOT_ADDR0, BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL);
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
    CSL_FINS(hBootCfg->DSP_BOOT_ADDR0, BOOTCFG_DSP_BOOT_ADDR0_ISTP_RST_VAL, bootAddress);
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
    *macId0 = hBootCfg->MACID0;
    *macId1 = hBootCfg->MACID1;
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
 *   @n  BOOTCOMPLETE
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
static inline Bool CSL_BootCfgIsBootComplete (void)
{
    return (Bool)CSL_FEXT (hBootCfg->BOOTCOMPLETE,BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE);    
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
 *   @n  BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE;
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
        CSL_FINS (hBootCfg->BOOTCOMPLETE,BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE, 1);    
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
 *   @n  BOOTCFG_BOOTPROGRESS
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
    return hBootCfg->BOOTPROGRESS;
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
 *   @n  BOOTCFG_BOOTPROGRESS
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
    hBootCfg->BOOTPROGRESS = bootProgress;
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
    return (Bool)CSL_FEXT (hBootCfg->RESET_STAT,BOOTCFG_BOOTCOMPLETE_GEM0_COMPLETE);
    
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
 *   @n  BOOTCFG_RESET_STAT_CLR_LRST_STAT_0_CLR=0;
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
    CSL_FINS (hBootCfg->RESET_STAT_CLR,BOOTCFG_RESET_STAT_CLR_GRST_STAT_CLR, (Uint32) 1);
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
 *   @n  BOOTCFG_LRSTNMISTAT_LRESET_STAT;
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
        *nmiStatus   = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_NMI_STAT);
        *localStatus = CSL_FEXT (value, BOOTCFG_LRSTNMISTAT_LRESET_STAT);
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
 *   @n  BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR
 *
 *   @b  Affects
 *   @n  BOOTCFG_LRSTNMISTAT_NMI_STAT=0
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
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR,    nmiStatus);
        CSL_FINS (value, BOOTCFG_LRSTNMISTAT_CLR_LRESET_STAT_0_CLR, localStatus);
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
        powerModeStatus       - Indicates whether in powerMode mode or not
        pmmcFwLoadStatus   - Indicates whether in pmmcFwLoad mode or not
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
 *   @n BOOTCFG_PWR_STATE_PWR_MODE,BOOTCFG_PWR_STATE_PMMC_FW_LOAD,
 *   @n BOOTCFG_PWR_STATE_PWR_STATE_GENERAL
 *
 *   @b Example
 *   @verbatim

        Uint8  powerMode;
        Uint8  pmmcFwLoad;
        Uint32 generalPurpose;

        // Get the power status.
        CSL_BootCfgGetPowerStatus(&powerMode, &pmmcFwLoad,  &generalPurpose);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetPowerStatus 
(
    Uint8*  powerMode, 
    Uint8*  pmmcFwLoad, 
    Uint32* generalPurpose
)
{
    Uint32 value = hBootCfg->PWR_STATE;

    *powerMode        = CSL_FEXT (value, BOOTCFG_PWR_STATE_PWR_MODE);
    *pmmcFwLoad    = CSL_FEXT (value, BOOTCFG_PWR_STATE_PMMC_FW_LOAD);
    *generalPurpose = CSL_FEXT (value, BOOTCFG_PWR_STATE_PWR_STATE_GENERAL);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetPowerStatus
 *
 *   @b Description
 *   @n The function sets the Power status
 *
 *   @b Arguments
     @verbatim
        powerModeStatus       - Status of the powerMode to be configured
        pmmcFwLoadStatus   - pmmcFwLoad Status to be configured
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
 *   @n BOOTCFG_PWR_STATE_PWR_MODE,BOOTCFG_PWR_STATE_PMMC_FW_LOAD,
 *   @n BOOTCFG_PWR_STATE_PWR_STATE_GENERAL
 *
 *   @b Example
 *   @verbatim

        Uint8  powerMode;
        Uint8  pmmcFwLoad;
        Uint32 generalPurpose;

        // Get the power status.
        CSL_BootCfgGetPowerStatus(&powerMode, &pmmcFwLoad, &generalPurpose);
        ...
        // Set the power status to be in powerMode mode
        CSL_BootCfgSetPowerStatus (1, hibernation, hibernationMode, generalPurpose);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetPowerStatus 
(
    Uint8  powerMode, 
    Uint8  pmmcFwLoad,
    Uint32 generalPurpose
)
{
    hBootCfg->PWR_STATE = CSL_FMK (BOOTCFG_PWR_STATE_PWR_MODE,         powerMode)            |
                         CSL_FMK (BOOTCFG_PWR_STATE_PMMC_FW_LOAD,     pmmcFwLoad)        |
                         CSL_FMK (BOOTCFG_PWR_STATE_PWR_STATE_GENERAL,generalPurpose); 
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
 *   @n BOOTCFG_NMIGR0_NMIGR0_REG
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
    CSL_FINS (hBootCfg->NMIGR0, BOOTCFG_NMIGR0_NMIGR0_REG, 1);
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
    hBootCfg->IPCGR0 = CSL_FMK(BOOTCFG_NMIGR0_NMIGR0_REG, sourceId) | 
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
 *   @n BOOTCFG_IPCAR8_IPCGR8_SRC_CLR; 
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
    *intStatus = CSL_FEXT(hBootCfg->IPCAR8, BOOTCFG_IPCAR8_IPCGR8_SRC_CLR);
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
 *   @n BOOTCFG_IPCAR8_IPCGR8_SRC_CLR; 
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
    CSL_FINS(hBootCfg->IPCAR8, BOOTCFG_IPCAR8_IPCGR8_SRC_CLR, intStatus);
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
 *   @n@b CSL_BootCfgGetTimerInputSelection
 *
 *   @b Description
 *   @n The function gets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput0  - Timer Input 1 value being returned        
        timerInput2  - Timer Input 2 value being returned 
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
static inline void CSL_BootCfgGetTimerInputSelection(Uint16* timerInput0,
                                                       Uint16* timerInput2)
{
    *timerInput0 = 
    ( CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL0) |
      CSL_FEXT (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPHSEL0));
    
    *timerInput2 = 
    ( CSL_FEXT (hBootCfg->TINPSEL1,BOOTCFG_TINPSEL0_TINPLSEL1) |
      CSL_FEXT (hBootCfg->TINPSEL1,BOOTCFG_TINPSEL0_TINPHSEL1));      
    
    return;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetTimerInputSelection
 *
 *   @b Description
 *   @n The function sets the timer input selection
 *
 *   @b Arguments
     @verbatim
        timerInput0  - Timer Input 1 selection to be configured        
        timerInput2  - Timer Input 2 selection to be configured 
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
static inline void CSL_BootCfgSetTimerInputSelection (Uint16 timerInput0,
                                                        Uint16 timerInput2)
{
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPLSEL0, timerInput0);
    CSL_FINS (hBootCfg->TINPSEL0,BOOTCFG_TINPSEL0_TINPHSEL0, timerInput0);
    CSL_FINS (hBootCfg->TINPSEL1,BOOTCFG_TINPSEL0_TINPLSEL1, timerInput2);
    CSL_FINS (hBootCfg->TINPSEL1,BOOTCFG_TINPSEL0_TINPHSEL1, timerInput2);
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
static inline void CSL_BootCfgGetTimerOutputSelection (Uint8* timerOutputSel0)
{
    *timerOutputSel0 = CSL_FEXT (hBootCfg->TOUTPSEL0, BOOTCFG_TOUTPSEL0_TOUTPSEL0);
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
static inline void CSL_BootCfgSetTimerOutputSelection (Uint8 timerOutputSel0)
{
    hBootCfg->TOUTPSEL0 = CSL_FMK (BOOTCFG_TOUTPSEL0_TOUTPSEL0, timerOutputSel0);
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
 *   @n BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0
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
    CSL_FINS (hBootCfg->RSTMUX0, BOOTCFG_RSTMUX0_RSTMUX_EVSTATCLR0, 1);
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
 *   @n@b CSL_BootCfgGetNSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the NSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        nssPLLConfig0    - NSS PLL Configuration0.
        nssPLLConfig1    - NSS PLL Configuration1.
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
 *   @n BOOTCFG_NSS_PLL_CTL0, BOOTCFG_NSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  nssPLLConfig0;
        Uint32  nssPLLConfig1;

        // Get the NSS PLL Configuration
        CSL_BootCfgGetNSSPLLConfiguration (&nssPLLConfig0, &nssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetNSSPLLConfiguration (Uint32* nssPLLConfig0, Uint32* nssPLLConfig1)
{
    *nssPLLConfig0 = hBootCfg->NSS_PLL_CTL0;
    *nssPLLConfig1 = hBootCfg->NSS_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetNSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the NSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        nssPLLConfig0    - NSS PLL Configuration0.
        nssPLLConfig1    - NSS PLL Configuration1.
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
 *   @n BOOTCFG_NSS_PLL_CTL0, BOOTCFG_NSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  nssPLLConfig0;
        Uint32  nssPLLConfig1;

        // Get the NSS PLL Configuration
        CSL_BootCfgGetNSSPLLConfiguration (&nssPLLConfig0, &nssPLLConfig1);
        ...
        // Set the NSS PLL Configuration
        CSL_BootCfgSetNSSPLLConfiguration (nssPLLConfig0, nssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetNSSPLLConfiguration (Uint32 nssPLLConfig0, Uint32 nssPLLConfig1)
{
    hBootCfg->NSS_PLL_CTL0 = nssPLLConfig0;
    hBootCfg->NSS_PLL_CTL1 = nssPLLConfig1;
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
 *   @n@b CSL_BootCfgGetDSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the DSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        dssPLLConfig0    - DSS PLL Configuration0.
        dssPLLConfig1    - DSS PLL Configuration1.
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
 *   @n BOOTCFG_DSS_PLL_CTL0, BOOTCFG_DSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  dssPLLConfig0;
        Uint32  dssPLLConfig1;

        // Get the DSS PLL Configuration
        CSL_BootCfgGetDSSPLLConfiguration (&dssPLLConfig0, &dssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetDSSPLLConfiguration (Uint32* dssPLLConfig0, Uint32* dssPLLConfig1)
{
    *dssPLLConfig0 = hBootCfg->DSS_PLL_CTL0;
    *dssPLLConfig1 = hBootCfg->DSS_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetDSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the DSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        dssPLLConfig0    - DSS PLL Configuration0.
        dssPLLConfig1    - DSS PLL Configuration1.
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
 *   @n BOOTCFG_DSS_PLL_CTL0, BOOTCFG_DSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  dssPLLConfig0;
        Uint32  dssPLLConfig1;

        // Get the DSS PLL Configuration
        CSL_BootCfgGetDSSPLLConfiguration (&dssPLLConfig0, &dssPLLConfig1);
        ...
        // Set the DSS PLL Configuration
        CSL_BootCfgSetDSSPLLConfiguration (dssPLLConfig0, dssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetDSSPLLConfiguration (Uint32 dssPLLConfig0, Uint32 dssPLLConfig1)
{
    hBootCfg->DSS_PLL_CTL0 = dssPLLConfig0;
    hBootCfg->DSS_PLL_CTL1 = dssPLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetICSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the ICSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        icssPLLConfig0    - ICSS PLL Configuration0.
        icssPLLConfig1    - ICSS PLL Configuration1.
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
 *   @n BOOTCFG_ICSS_PLL_CTL0, BOOTCFG_ICSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  icssPLLConfig0;
        Uint32  icssPLLConfig1;

        // Get the ICSS PLL Configuration
        CSL_BootCfgGetICSSPLLConfiguration (&icssPLLConfig0, &icssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetICSSPLLConfiguration (Uint32* icssPLLConfig0, Uint32* icssPLLConfig1)
{
    *icssPLLConfig0 = hBootCfg->ICSS_PLL_CTL0;
    *icssPLLConfig1 = hBootCfg->ICSS_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetICSSPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the ICSS PLL configuration.
 *
 *   @b Arguments
     @verbatim
        icssPLLConfig0    - ICSS PLL Configuration0.
        icssPLLConfig1    - ICSS PLL Configuration1.
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
 *   @n BOOTCFG_ICSS_PLL_CTL0, BOOTCFG_ICSS_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  icssPLLConfig0;
        Uint32  icssPLLConfig1;

        // Get the ICSS PLL Configuration
        CSL_BootCfgGetICSSPLLConfiguration (&icssPLLConfig0, &icssPLLConfig1);
        ...
        // Set the ICSS PLL Configuration
        CSL_BootCfgSetICSSPLLConfiguration (icssPLLConfig0, icssPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetICSSPLLConfiguration (Uint32 icssPLLConfig0, Uint32 icssPLLConfig1)
{
    hBootCfg->ICSS_PLL_CTL0 = icssPLLConfig0;
    hBootCfg->ICSS_PLL_CTL1 = icssPLLConfig1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetUARTPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used get the UART PLL configuration.
 *
 *   @b Arguments
     @verbatim
        uartPLLConfig0    - UART PLL Configuration0.
        uartPLLConfig1    - UART PLL Configuration1.
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
 *   @n BOOTCFG_UART_PLL_CTL0, BOOTCFG_UART_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  uartPLLConfig0;
        Uint32  uartPLLConfig1;

        // Get the UART PLL Configuration
        CSL_BootCfgGetUARTPLLConfiguration (&uartPLLConfig0, &uartPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetUARTPLLConfiguration (Uint32* uartPLLConfig0, Uint32* uartPLLConfig1)
{
    *uartPLLConfig0 = hBootCfg->UART_PLL_CTL0;
    *uartPLLConfig1 = hBootCfg->UART_PLL_CTL1;
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetUARTPLLConfiguration
 *
 *   @b Description
 *   @n The function is to used set the UART PLL configuration.
 *
 *   @b Arguments
     @verbatim
        uartPLLConfig0    - UART PLL Configuration0.
        uartPLLConfig1    - UART PLL Configuration1.
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
 *   @n BOOTCFG_UART_PLL_CTL0, BOOTCFG_UART_PLL_CTL1
 *
 *   @b Example
 *   @verbatim

        Uint32  uartPLLConfig0;
        Uint32  uartPLLConfig1;

        // Get the UART PLL Configuration
        CSL_BootCfgGetUARTPLLConfiguration (&uartPLLConfig0, &uartPLLConfig1);
        ...
        // Set the UART PLL Configuration
        CSL_BootCfgSetUARTPLLConfiguration (uartPLLConfig0, uartPLLConfig1);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetUARTPLLConfiguration (Uint32 uartPLLConfig0, Uint32 uartPLLConfig1)
{
    hBootCfg->UART_PLL_CTL0 = uartPLLConfig0;
    hBootCfg->UART_PLL_CTL1 = uartPLLConfig1;
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
 *   @n BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_SEL,BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN
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
    Uint32 value = hBootCfg->OBSCLKCTL;

    *selection = CSL_FEXT (value, BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL);
    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN);
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
 *   @n BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_SEL,BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN
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
    CSL_FINS (hBootCfg->OBSCLKCTL, BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLKCTL, BOOTCFG_OBSCLKCTL_MAINPLL_OBSCLK_EN, enable);
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
 *   @n BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN
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
    Uint32 value = hBootCfg->OBSCLKCTL;
    *selection = CSL_FEXT (value, BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL);
    *enable    = CSL_FEXT (value, BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN);
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
 *   @n BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN
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
    CSL_FINS (hBootCfg->OBSCLKCTL, BOOTCFG_OBSCLKCTL_PLL_OBSCLK_SEL, selection);
    CSL_FINS (hBootCfg->OBSCLKCTL, BOOTCFG_OBSCLKCTL_DDR3APLL_OBSCLK_EN, enable);
}

/** ============================================================================
 *   @n@b CSL_BootCfgGetNSSPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to get the NSS PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the NSS PLL IO Clock buffer.
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
 *   @n BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the NSS PLL Observation Clock Control 
        CSL_BootCfgGetNSSPLLObservationClockControl(&selection, &enable);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetNSSPLLObservationClockControl 
(
    Uint8* enable
)
{
    Uint32 value = hBootCfg->OBSCLKCTL;

     *enable    = CSL_FEXT (value, BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN);
}

/** ============================================================================
 *   @n@b CSL_BootCfgSetNSSPLLObservationClockControl
 *
 *   @b Description
 *   @n The function is to used to set the NSS PLL observation clock control
 *
 *   @b Arguments
     @verbatim
        selection - Controls which clock is output
        enable    - Status of the NSS PLL IO Clock buffer.
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
 *   @n BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN
 *
 *   @b Example
 *   @verbatim

        Uint8   selection;
        Uint8   enable;

        // Get the NSS PLL Observation Clock Control 
        CSL_BootCfgGetNSSPLLObservationClockControl(&selection, &enable);

        // PA IO Clock Buffer is disabled.
        CSL_BootCfgSetNSSPLLObservationClockControl(selection, 0);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgSetNSSPLLObservationClockControl 
(
    Uint8 enable
)
{
    CSL_FINS (hBootCfg->OBSCLKCTL, BOOTCFG_OBSCLKCTL_NSSPLL_OBSCLK_EN, enable);
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
        	handle = (CSL_PllcHandle) CSL_PLLC_CFG_REGS;
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

        case CSL_PLL_NSS:
            CSL_BootCfgGetNSSPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_NSS_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_NSS_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_NSS_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_NSS_PLL_CTL0_CLKOD) + 1;
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

        case CSL_PLL_DSS:
            CSL_BootCfgGetDSSPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_DSS_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_DSS_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_DSS_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_DSS_PLL_CTL0_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        case CSL_PLL_ICSS:
            CSL_BootCfgGetICSSPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_ICSS_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_ICSS_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_ICSS_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_ICSS_PLL_CTL0_CLKOD) + 1;
            }
            freq = input_clk / prediv / output_div * mult;
            break;

        case CSL_PLL_UART:
            CSL_BootCfgGetUARTPLLConfiguration(&PLLConfig0, &PLLConfig1);
            if (!CSL_FEXT(PLLConfig0, BOOTCFG_UART_PLL_CTL0_BYPASS))
            {
                prediv = CSL_FEXT(PLLConfig0, BOOTCFG_UART_PLL_CTL0_PLLD) + 1;
                mult = CSL_FEXT(PLLConfig0, BOOTCFG_UART_PLL_CTL0_PLLM) + 1;
                output_div = CSL_FEXT(PLLConfig0, BOOTCFG_UART_PLL_CTL0_CLKOD) + 1;
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
 *   @n@b CSL_BootCfgSetEthernetCfgMode
 *
 *   @b Description
 *   @n The function is to used set the Ethernet configuration mode
 *
 *   @b Arguments
     @verbatim
        ethCfgMode    - Ethernet configuration mode
        possible ethernet configuration modes:
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_GMII_MII              (0x00000000U)
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RMII                  (0x00000001U)
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RGMII                 (0x00000002U)
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
 *   @n BOOTCFG_ETHERNET_CFG_MODE_SEL
 *
 *   @b Example
 *   @verbatim

        Uint32  ethCfgMode;

        // Set the Ethernet Configuration mode
        CSL_BootCfgSetEthernetCfgMode (ethCfgMode);

    @endverbatim
 * ===========================================================================
 */

static inline void CSL_BootCfgSetEthernetCfgMode (uint32_t ethCfgMode)
{
    CSL_FINS (hBootCfg->ETHERNET_CFG, BOOTCFG_ETHERNET_CFG_MODE_SEL, ethCfgMode);
}


/** ============================================================================
 *   @n@b CSL_BootCfgGetEthernetCfgMode
 *
 *   @b Description
 *   @n The function is to used get the Ethernet configuration mode
 *
 *   @b Arguments
     @verbatim
        ethCfgMode       - ethCfgMode populated by this API
        possible ethernet configuration mode populated by this API
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_GMII_MII              (0x00000000U)
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RMII                  (0x00000001U)
        #define CSL_BOOTCFG_ETHERNET_CFG_MODE_SEL_RGMII                 (0x00000002U)
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
 *   @n BOOTCFG_ETHERNET_CFG_MODE_SEL
 *
 *   @b Example
 *   @verbatim

        Uint8   ethCfgMode;

        // Get the ethernet configuration mode
        CSL_BootCfgGetEthernetCfgMode (0, &ethCfgMode);

     @endverbatim
 * =============================================================================
 */
static inline void CSL_BootCfgGetEthernetCfgMode(uint32_t* ethCfgMode)
{
    *ethCfgMode = hBootCfg->ETHERNET_CFG;
}
/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /* CSL_BOOTCFGAUX_V3_H_ */
