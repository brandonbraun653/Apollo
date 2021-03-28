/******************************************************************************
 * FILE PURPOSE: NIMU transport unit example files.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for NIMU transport include files.
 *
 * Copyright (C) 2015, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the include
 *  directory into the package.
 **************************************************************************/
function modBuild() 
{
    /* Add all the .h files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".h", "include", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "include", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

}
