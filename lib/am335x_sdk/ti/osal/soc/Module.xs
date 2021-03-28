/******************************************************************************
 * FILE PURPOSE: OSAL unit arch files.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for OSAL module soc files.
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
    var socFiles = libUtility.listAllFiles (".c", "soc", true);
    for (var k = 0 ; k < socFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = socFiles[k];

    /* Add all the .h files to the release package. */
    var socFiles = libUtility.listAllFiles (".h", "soc", true);
    for (var k = 0 ; k < socFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = socFiles[k];


    /* Add all the .h files to the release package. */
    var socFiles = libUtility.listAllFiles (".h", ".", true);
    for (var k = 0 ; k < socFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = socFiles[k];

}
