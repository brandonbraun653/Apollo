/******************************************************************************
 * FILE PURPOSE: Build subscript for SoC and IP
 ******************************************************************************
 * FILE NAME: Build.xs
 *
 * DESCRIPTION:
 *  This file contains the build subscript for SoC and IP
 *
 * Copyright (C) 2014-2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* This will have all the CSL source files - soc, ip's */
var cslFiles =[];

/* QSPI IP File */
var qspiIPFile = [
    "src/ip/qspi/V1/priv/qspi.c",
];

/* GPIO IP */
var gpioIPFile = [
    "src/ip/gpio/V1/priv/gpio_v2.c",
];

/* MMC IP */
var mmcIPFile = [
    "src/ip/mmc/V0/priv/mmcsd.c",
];

/* UART IP */
var uartIPFile = [
    "src/ip/uart/V1/priv/uart.c",
];

/* MCAsp IP */
var mcaspIPFile = [
    "src/ip/mcasp/V0/priv/mcasp.c",
];

/* McSPI IP */
var mcspiIPFile = [
    "src/ip/mcspi/V0/priv/mcspi.c",
];


/* I2C IP */
var i2cIPFile = [
    "src/ip/i2c/V2/priv/i2c.c",
];

/* GPMC IP */
var gpmcIPFile = [
    "src/ip/gpmc/V1/priv/gpmc.c",
];

/* ELM IP */
var elmIPFile = [
    "src/ip/elm/V0/priv/elm.c",
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

    /* Add all the qspiIPFile Files. */
    for (index = 0; index < qspiIPFile.length; index++)
        cslFiles[cslFiles.length++] = qspiIPFile[index];

    /* Add all the GPIO Files. */
    for (index = 0; index < gpioIPFile.length; index++)
        cslFiles[cslFiles.length++] = gpioIPFile[index];

    /* Add all the MMC Files. */
    for (index = 0; index < mmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = mmcIPFile[index];

    /* Add all the UART Files. */
    for (index = 0; index < uartIPFile.length; index++)
        cslFiles[cslFiles.length++] = uartIPFile[index];

    /* Add all the MCAsp Files. */
    for (index = 0; index < mcaspIPFile.length; index++)
        cslFiles[cslFiles.length++] = mcaspIPFile[index];
		
    /* Add all the McSpi Files. */
    for (index = 0; index < mcspiIPFile.length; index++)
        cslFiles[cslFiles.length++] = mcspiIPFile[index];		

    /* Add all the I2C Files. */
    for (index = 0; index < i2cIPFile.length; index++)
        cslFiles[cslFiles.length++] = i2cIPFile[index];
		
    /* Add all the GPMC Files. */
    for (index = 0; index < gpmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = gpmcIPFile[index];
		
    /* Add all the ELM Files. */
    for (index = 0; index < elmIPFile.length; index++)
        cslFiles[cslFiles.length++] = elmIPFile[index];
		
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

    if (target.name == "A9F")
    {
        var files = [];

		/* Add all the qspiIPFile Files. */
		for (index = 0; index < qspiIPFile.length; index++)
			files[cslFiles.length++] = qspiIPFile[index];

		/* Add all the GPIO Files. */
		for (index = 0; index < gpioIPFile.length; index++)
			files[cslFiles.length++] = gpioIPFile[index];

		/* Add all the MMC Files. */
		for (index = 0; index < mmcIPFile.length; index++)
			files[cslFiles.length++] = mmcIPFile[index];

		/* Add all the UART Files. */
		for (index = 0; index < uartIPFile.length; index++)
			files[cslFiles.length++] = uartIPFile[index];

		/* Add all the MCAsp Files. */
		for (index = 0; index < mcaspIPFile.length; index++)
			files[cslFiles.length++] = mcaspIPFile[index];
			
		/* Add all the McSpi Files. */
		for (index = 0; index < mcspiIPFile.length; index++)
			files[cslFiles.length++] = mcspiIPFile[index];		

		/* Add all the I2C Files. */
		for (index = 0; index < i2cIPFile.length; index++)
			files[cslFiles.length++] = i2cIPFile[index];
		
		/* Add all the GPMC Files. */
		for (index = 0; index < gpmcIPFile.length; index++)
			files[cslFiles.length++] = gpmcIPFile[index];
		
		/* Add all the ELM Files. */
		for (index = 0; index < elmIPFile.length; index++)
			files[cslFiles.length++] = elmIPFile[index];
		
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, files);
    }
}

