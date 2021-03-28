/******************************************************************************
 * FILE PURPOSE: Build subscript for SoC and IP
 ******************************************************************************
 * FILE NAME: Build.xs
 *
 * DESCRIPTION: 
 *  This file contains the build subscript for SoC and IP
 *
 * Copyright (C) 2008, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* This will have all the CSL source files - soc, ip's */
var cslFiles =[];

/* CSL Version File */
var cslSocFile = [
    "soc/c6657/src/csl_version.c",
    "soc/c6657/src/csl_gpioGetBaseAddress.c",
    "soc/c6657/src/csl_cpIntcGetBaseAddress.c",
    "soc/c6657/src/csl_edma3GetBaseAddress.c",
    "soc/c6657/src/csl_srioGetBaseAddress.c",
    "soc/c6657/src/csl_timerGetBaseAddress.c",
    "soc/c6657/src/csl_pllcGetBaseAddress.c",
    "soc/c6657/src/csl_mpuGetBaseAddress.c",
];

/* Boot Cfg IP File: There are no source files associated with the Boot Cfg Module. */
var bootCfgIPFile = [
];

/* BWMGMT IP File */
var bwmgmtIPFile = [
];

/* CACHE IP File: There are no source files associated with the CACHE Module. */
var cacheIPFile = [
];

/* CHIP IP File */
var chipIPFile = [
    "src/ip/chip/V0/csl_chip.c",
];

/* CPINTC IP File: There are no source files associated with the CPINTC Module. */
var cpIntcIPFile = [
];

/* ECTL IP File: There are no source files associated with the ECTL Module. */
var ectlIPFile = [
];

/* EDMA IP File */
var edmaIPFile = [
    "src/ip/edma/V0/csl_edma3Init.c",
    "src/ip/edma/V0/csl_edma3Open.c",
    "src/ip/edma/V0/csl_edma3Close.c",
    "src/ip/edma/V0/csl_edma3HwSetup.c",
    "src/ip/edma/V0/csl_edma3HwControl.c",
    "src/ip/edma/V0/csl_edma3GetHwStatus.c",
    "src/ip/edma/V0/csl_edma3GetHwSetup.c",
    "src/ip/edma/V0/csl_edma3ChannelOpen.c",
    "src/ip/edma/V0/csl_edma3ChannelClose.c",
    "src/ip/edma/V0/csl_edma3HwChannelSetup.c",
    "src/ip/edma/V0/csl_edma3HwChannelControl.c",
    "src/ip/edma/V0/csl_edma3GetHwChannelStatus.c",
    "src/ip/edma/V0/csl_edma3GetHwChannelSetup.c",
    "src/ip/edma/V0/csl_edma3Param.c",
];

/* EMAC IP File: There are no source files associated with the EMAC Module. */
var emacIPFile = [
];

/* EMIF4 IP File: There are no source files associated with the EMIF4 Module. */
var emif4IPFile = [
];

/* EMIF16 IP File: There are no source files associated with the EMIF16 Module. */
var emif16IPFile = [
];

/* GPIO IP File: There are no source files associated with the GPIO Module. */
var gpioIPFile = [
];

/* I2C IP File: There are no source files associated with the I2C Module. */
var i2cIPFile = [
];

/* IDMA IP File: There are no source files associated with the IDMA Module. */
var idmaIPFile = [
];

/* IPC IP File: There are no source files associated with the IPC Module. */
var ipcIPFile = [
];

/* McBSP IP File: There are no source files associated with the MCBSP Module. */
var mcbspIPFile = [
];

/* MDIO IP File: There are no source files associated with the MDIO Module. */
var mdioIPFile = [
];

/* MEMPROT IP File: There are no source files associated with the MEMPROT Module. */
var memprotIPFile = [
];

/* MPU IP File: There are no source files associated with the MPU Module. */
var mpuIPFile = [
];

/* MSMC IP File: There are no source files associated with the MSMC Module. */
var msmcIPFile = [
];

/* PLLC IP File: There are no source files associated with the PLLC Module. */
var pllcIPFile = [
];

/* PSC IP File: There are no source files associated with the PSC Module. */
var pscIPFile = [
];

/* SEM2 IP File: There are no source files associated with the SEM2 Module. */
var sem2IPFile = [
];

/* SGMII IP File: There are no source files associated with the SGMII Module. */
var sgmiiIPFile = [
];

/* SPI IP File: There are no source files associated with the SPI Module. */
var spiIPFile = [
];

/* SRIO IP File: There are no source files associated with the SRIO Module. */
var srioIPFile = [
];

/* TIMER IP File */
var timerIPFile = [
    "src/ip/timer/V0/csl_tmrInit.c",
    "src/ip/timer/V0/csl_tmrOpen.c",
    "src/ip/timer/V0/csl_tmrClose.c",
    "src/ip/timer/V0/csl_tmrHwSetup.c",
    "src/ip/timer/V0/csl_tmrHwSetupRaw.c",
    "src/ip/timer/V0/csl_tmrHwControl.c",
    "src/ip/timer/V0/csl_tmrGetHwStatus.c",
    "src/ip/timer/V0/csl_tmrGetHwSetup.c",
];

/* TSC IP File */
var tscIPFile = [
    "src/ip/tsc/V0/csl_tsc.asm",
];

/* UART IP File: There are no source files associated with the UART Module. */
var uartIPFile = [
];

/* UPP IP File: There are no source files associated with the UPP Module. */
var uppIPFile = [
];

/* VCP2 IP File */
var vcp2IPFile = [
    "src/ip/vcp2/V1/csl_vcp2.c",
];

/* VUSR IP File: There are no source files associated with the VUSR Module. */
var vusrIPFile = [
];

/* XMC IP File: There are no source files associated with the XMC Module. */
var xmcIPFile = [
];


/**************************************************************************
 * FUNCTION NAME : getSources
 **************************************************************************
 * DESCRIPTION   :
 *  The function returns an array of source files that constitute the chip 
 *  support library
 **************************************************************************/
function getSources ()
{
    var index;

    /* Add all the CSL Version Files. */ 
    for (index = 0; index < cslSocFile.length; index++)
        cslFiles[cslFiles.length++] = cslSocFile[index];

    /* Add all the Boot Cfg Files. */ 
    for (index = 0; index < bootCfgIPFile.length; index++)
        cslFiles[cslFiles.length++] = bootCfgIPFile[index];

    /* Add all the BWMGMT Files. */ 
    for (index = 0; index < bwmgmtIPFile.length; index++)
        cslFiles[cslFiles.length++] = bwmgmtIPFile[index];

    /* Add all the CACHE Files. */ 
    for (index = 0; index < cacheIPFile.length; index++)
        cslFiles[cslFiles.length++] = cacheIPFile[index];

    /* Add all the CHIP Files. */ 
    for (index = 0; index < chipIPFile.length; index++)
        cslFiles[cslFiles.length++] = chipIPFile[index];

    /* Add all the CPINTC Files. */ 
    for (index = 0; index < cpIntcIPFile.length; index++)
        cslFiles[cslFiles.length++] = cpIntcIPFile[index];

    /* Add all the ECTL Files. */ 
    for (index = 0; index < ectlIPFile.length; index++)
        cslFiles[cslFiles.length++] = ectlIPFile[index];

    /* Add all the EDMA Files. */ 
    for (index = 0; index < edmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = edmaIPFile[index];

    /* Add all the EMAC Files. */ 
    for (index = 0; index < emacIPFile.length; index++)
        cslFiles[cslFiles.length++] = emacIPFile[index];

    /* Add all the EMIF4 Files. */ 
    for (index = 0; index < emif4IPFile.length; index++)
        cslFiles[cslFiles.length++] = emif4IPFile[index];

    /* Add all the EMIF16 Files. */ 
    for (index = 0; index < emif16IPFile.length; index++)
        cslFiles[cslFiles.length++] = emif16IPFile[index];

    /* Add all the GPIO Files. */ 
    for (index = 0; index < gpioIPFile.length; index++)
        cslFiles[cslFiles.length++] = gpioIPFile[index];

    /* Add all the I2C Files. */ 
    for (index = 0; index < i2cIPFile.length; index++)
        cslFiles[cslFiles.length++] = i2cIPFile[index];

    /* Add all the IDMA Files. */ 
    for (index = 0; index < idmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = idmaIPFile[index];

    /* Add all the IPC Files. */ 
    for (index = 0; index < ipcIPFile.length; index++)
        cslFiles[cslFiles.length++] = ipcIPFile[index];        

    /* Add all the McBSP Files. */ 
    for (index = 0; index < mcbspIPFile.length; index++)
        cslFiles[cslFiles.length++] = mcbspIPFile[index];

    /* Add all the MDIO Files. */ 
    for (index = 0; index < mdioIPFile.length; index++)
        cslFiles[cslFiles.length++] = mdioIPFile[index];

    /* Add all the MEMPROT Files. */ 
    for (index = 0; index < memprotIPFile.length; index++)
        cslFiles[cslFiles.length++] = memprotIPFile[index];

    /* Add all the MPU Files. */ 
    for (index = 0; index < mpuIPFile.length; index++)
        cslFiles[cslFiles.length++] = mpuIPFile[index];

    /* Add all the MSMC Files. */ 
    for (index = 0; index < msmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = msmcIPFile[index];

    /* Add all the PLLC Files. */ 
    for (index = 0; index < pllcIPFile.length; index++)
        cslFiles[cslFiles.length++] = pllcIPFile[index];

    /* Add all the PSC Files. */ 
    for (index = 0; index < pscIPFile.length; index++)
        cslFiles[cslFiles.length++] = pscIPFile[index];

    /* Add all the SEM2 Files. */ 
    for (index = 0; index < sem2IPFile.length; index++)
        cslFiles[cslFiles.length++] = sem2IPFile[index];

    /* Add all the SGMII Files. */ 
    for (index = 0; index < sgmiiIPFile.length; index++)
        cslFiles[cslFiles.length++] = sgmiiIPFile[index];

    /* Add all the SPI Files. */ 
    for (index = 0; index < spiIPFile.length; index++)
        cslFiles[cslFiles.length++] = spiIPFile[index];

    /* Add all the SRIO Files. */ 
    for (index = 0; index < srioIPFile.length; index++)
        cslFiles[cslFiles.length++] = srioIPFile[index];

    /* Add all the TIMER Files. */ 
    for (index = 0; index < timerIPFile.length; index++)
        cslFiles[cslFiles.length++] = timerIPFile[index];

    /* Add all the TSC Files. */ 
    for (index = 0; index < tscIPFile.length; index++)
        cslFiles[cslFiles.length++] = tscIPFile[index]; 

    /* Add all the UART Files. */ 
    for (index = 0; index < uartIPFile.length; index++)
        cslFiles[cslFiles.length++] = uartIPFile[index]; 

    /* Add all the UPP Files. */ 
    for (index = 0; index < uppIPFile.length; index++)
        cslFiles[cslFiles.length++] = uppIPFile[index]; 

    /* Add all the VCP2 Files. */ 
    for (index = 0; index < vcp2IPFile.length; index++)
        cslFiles[cslFiles.length++] = vcp2IPFile[index];

    /* Add all the VUSR Files. */ 
    for (index = 0; index < vusrIPFile.length; index++)
        cslFiles[cslFiles.length++] = vusrIPFile[index];

    /* Add all the XMC Files. */ 
    for (index = 0; index < xmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = xmcIPFile[index];
    
    /* Return the list of all CSL Files */
    return cslFiles;
}

/**************************************************************************
 * FUNCTION NAME : buildLibrary
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the chip support library.
 **************************************************************************/
function buildLibrary (soc, target, opt) {
    var libOptions = {
        copts: opt,
        incs: cslPathInclude,
    };

    if (java.lang.String(target.name).contains('66'))
    {
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, cslFiles);
    }
}



