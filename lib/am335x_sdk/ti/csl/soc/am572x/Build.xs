/******************************************************************************
 * FILE PURPOSE: Build subscript for SoC and IP
 ******************************************************************************
 * FILE NAME: Build.xs
 *
 * DESCRIPTION:
 *  This file contains the build subscript for SoC and IP
 *
 * Copyright (C) 2014-2015, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* This will have all the CSL source files - soc, ip's */
var cslFiles =[];

/* CSL Version File */
var cslSocFile = [
    "soc/am572x/src/csl_version.c",
    "soc/am572x/src/csl_device_xbar.c",
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


/* TSC IP File */
var tscIPFile = [
    "src/ip/tsc/V0/csl_tsc.asm",
];

/* DCAN IP File */
var dcanIPFile = [
    "src/ip/dcan/V0/priv/dcan.c",
];

/* A15 File */
var a15File = [
    "arch/a15/V0/csl_a15Asm.asm",
    "arch/a15/V0/csl_a15.c",
    "arch/a15/V0/csl_a15AsmUtils.c",
];

/* A15 Init File */
var a15InitFile = [
    "arch/a15/src/csl_a15_init.asm",
    "arch/a15/src/csl_a15_startup.c",
];

/* I2C IP */
var i2cIPFile = [
    "src/ip/i2c/V2/priv/i2c.c",
];

/* A15 WUGEN File */
var a15WugenFile = [
    "arch/a15/src/mpu_wugen.c",
];

/* M4 WUGEN File */
var m4WugenFile = [
    "arch/m4/src/ipu_wugen.c",
];

/* ECAP File */
var ecapIPFile = [
    "src/ip/ecap/V0/priv/ecap.c",
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

    /* Add all the TSC Files. */
    for (index = 0; index < tscIPFile.length; index++)
        cslFiles[cslFiles.length++] = tscIPFile[index];

    /* Add all the DCAN Files. */
    for (index = 0; index < dcanIPFile.length; index++)
        cslFiles[cslFiles.length++] = dcanIPFile[index];
		
    /* Add all the ECAP Files. */
    for (index = 0; index < ecapIPFile.length; index++)
        cslFiles[cslFiles.length++] = ecapIPFile[index];		

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

    if (target.name == "A15F")
    {
        var files = [];
        var initFiles = [];
        var initPackaeName = Pkg.name + ".init";

        /* Add all the A15 Files. */
        for (index = 0; index < a15InitFile.length; index++)
            initFiles[initFiles.length++] = a15InitFile[index];

        /* Add all the A15 Files. */
        for (index = 0; index < a15File.length; index++)
            files[files.length++] = a15File[index];

        /* Add all the CSL Device specific Files. */
        for (index = 0; index < cslSocFile.length; index++)
            files[files.length++] = cslSocFile[index];

        /* Add all the EDMA Files. */
        for (index = 0; index < edmaIPFile.length; index++)
            files[files.length++] = edmaIPFile[index];

        /* Add all the I2C Files. */
        for (index = 0; index < i2cIPFile.length; index++)
            files[files.length++] = i2cIPFile[index];

        /* Add all the A15 WUGEN Files. */
        for (index = 0; index < a15WugenFile.length; index++)
            files[files.length++] = a15WugenFile[index];

        /* Add all the ECAP Files. */
        for (index = 0; index < ecapIPFile.length; index++)
            files[cslFiles.length++] = ecapIPFile[index];
		
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, files);
        libUtility.buildLibrary (libOptions, initPackaeName, soc, target, initFiles);
    }
    else if (target.name == "M4")
    {
        var files = [];
        /* Add all the CSL Device specific Files. */
        for (index = 0; index < cslSocFile.length; index++)
            files[cslFiles.length++] = cslSocFile[index];

        /* Add all the EDMA Files. */
        for (index = 0; index < edmaIPFile.length; index++)
            files[cslFiles.length++] = edmaIPFile[index];

        /* Add all the DCAN Files. */
        for (index = 0; index < dcanIPFile.length; index++)
            files[cslFiles.length++] = dcanIPFile[index];

        /* Add all the I2C Files. */
        for (index = 0; index < i2cIPFile.length; index++)
            files[cslFiles.length++] = i2cIPFile[index];

        /* Add all the M4 WUGEN Files. */
        for (index = 0; index < m4WugenFile.length; index++)
            files[cslFiles.length++] = m4WugenFile[index];

        /* Add all the ECAP Files. */
        for (index = 0; index < ecapIPFile.length; index++)
           files[cslFiles.length++] = ecapIPFile[index];
		
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, files);
    }
    else
    {
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, cslFiles);
    }
}

