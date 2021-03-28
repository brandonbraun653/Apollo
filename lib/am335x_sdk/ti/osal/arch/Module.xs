/******************************************************************************
 * FILE PURPOSE: OSAL unit arch files.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for OSAL module arch files.
 *
 * Copyright (C) 2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the test
 *  directory into the package.
 **************************************************************************/
function modBuild()
{
    /* Add all the .c files to the release package. */
    var archFiles = libUtility.listAllFiles (".c", "arch", true);
    for (var k = 0 ; k < archFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = archFiles[k];

    /* Add all the .h files to the release package. */
    var archFiles = libUtility.listAllFiles (".h", "arch", true);
    for (var k = 0 ; k < archFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = archFiles[k];


    /* Add the .asm to the package */
    var archFiles = libUtility.listAllFiles (".asm", "arch", true);
    for (var k = 0 ; k < archFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = archFiles[k];
}
