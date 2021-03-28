/******************************************************************************
 * FILE PURPOSE: CPTS/CPSW source files for CPSW/CPTS example for SOC_K2G.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for CPTS/CPSW examples for SOC_K2G 
 *
 * Copyright (C) 2017, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the cpsw 
 *  directory into the package.
 **************************************************************************/
function modBuild() 
{
    /* Add all the .c files to the release package. */
    var cpswFiles = libUtility.listAllFiles (".c", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];

    /* Add all the .h files to the release package. */
    var cpswFiles = libUtility.listAllFiles (".h", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];

    /* Add all the .cmd files to the release package. */
    var cpswFiles = libUtility.listAllFiles (".cmd", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];

    /* Add all the .cfg files to the release package. */
    var cpswFiles = libUtility.listAllFiles (".cfg", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];

    /* Add all the make files to the release package. */
    var cpswFiles = libUtility.listAllFiles ("makefile", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];

    /* Add the .txt to the package */
    var cpswFiles = libUtility.listAllFiles (".txt", "cpsw", true);
    for (var k = 0 ; k < cpswFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = cpswFiles[k];
}
