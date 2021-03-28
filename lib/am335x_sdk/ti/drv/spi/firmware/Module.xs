/******************************************************************************
 * FILE PURPOSE: SPI Firmware Source specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the SPI Driver
 *
 * Copyright (C) 2015-2018 Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the SPI LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    /* Add all the .h files to the release package. */
    var fwFiles = libUtility.listAllFiles (".h");
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];
    
    fwFiles = libUtility.listAllFiles (".c"); 
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];
    
    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "firmware", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

    /* Add all the .cmd files to the release package. */
    var fwFiles = libUtility.listAllFiles (".cmd", "firmware", true);
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];
    
    /* Add all the .asm files to the release package. */
    var fwFiles = libUtility.listAllFiles (".asm", "firmware", true);
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];
    
    /* Add all the .inc files to the release package. */
    var fwFiles = libUtility.listAllFiles (".inc", "firmware", true);
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];

    /* Add all the .bin files to the release package. */
    var fwFiles = libUtility.listAllFiles (".bin", "firmware", true);
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];

    /* Add all the .pdf files to the release package. */
    var fwFiles = libUtility.listAllFiles (".pdf", "firmware", true);
    for (var k = 0 ; k < fwFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = fwFiles[k];
    
}

