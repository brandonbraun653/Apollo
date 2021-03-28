/******************************************************************************
 * FILE PURPOSE: Build subscript for SoC and IP
 ******************************************************************************
 * FILE NAME: Build.xs
 *
 * DESCRIPTION:
 *  This file contains the build subscript for SoC and IP
 *
 * Copyright (C) 2012, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* This will have all the CSL source files - soc, ip's */
var cslFiles =[];

/* CSL Version File */
var cslSocFile = [
    "soc/omapl137/src/csl_version.c",
    "soc/omapl137/src/csl_gpioGetBaseAddress.c",
    "soc/omapl137/src/csl_edma3GetBaseAddress.c",
    "soc/omapl137/src/csl_timerGetBaseAddress.c",
    "soc/omapl137/src/csl_pllcGetBaseAddress.c",
    "soc/omapl137/src/csl_mpuGetBaseAddress.c",
    "soc/omapl137/src/csl_emif4fGetBaseAddress.c",
];



/* CHIP IP File */
var chipIPFile = [
    "src/ip/chip/V0/csl_chip.c",
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


/* MDIO IP File */
var mdioIPFile = [
    "src/ip/mdio/V0/cslr_mdio_resetread.c",
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

/* Arm9 File */
var arm9File = [
    "arch/a9/V0/csl_cp15.c",
    "arch/a9/V0/csl_arm9_cpu.c",
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

    /* Add all the CSL Device specific Files. */
    for (index = 0; index < cslSocFile.length; index++)
        cslFiles[cslFiles.length++] = cslSocFile[index];

    /* Add all the CHIP Files. */
    for (index = 0; index < chipIPFile.length; index++)
        cslFiles[cslFiles.length++] = chipIPFile[index];

    /* Add all the EDMA Files. */
    for (index = 0; index < edmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = edmaIPFile[index];


    /* Add all the MDIO Files. */
    for (index = 0; index < mdioIPFile.length; index++)
        cslFiles[cslFiles.length++] = mdioIPFile[index];

    /* Add all the TIMER Files. */
    for (index = 0; index < timerIPFile.length; index++)
        cslFiles[cslFiles.length++] = timerIPFile[index];

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

    if ( target.name == "Arm9" )
    {
        var files = [];
        /* Add all the CSL Device specific Files. */
        for (index = 0; index < cslSocFile.length; index++)
            files[cslFiles.length++] = cslSocFile[index];

        /* Add all the EDMA Files. */
        for (index = 0; index < edmaIPFile.length; index++)
            files[cslFiles.length++] = edmaIPFile[index];

        /* Add all the mdioIPFile. */
        for (index = 0; index < mdioIPFile.length; index++)
            files[cslFiles.length++] = mdioIPFile[index];

        /* Add all the timerIPFile. */
        for (index = 0; index < timerIPFile.length; index++)
            files[cslFiles.length++] = timerIPFile[index];

        /* Add all the Arm9 Files. */
        /*for (index = 0; index < arm9File.length; index++)
            files[files.length++] = arm9File[index];
			*/

        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, files);
    }
    else if (java.lang.String(target.name).contains('67'))
    {
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, cslFiles);
    }
}
