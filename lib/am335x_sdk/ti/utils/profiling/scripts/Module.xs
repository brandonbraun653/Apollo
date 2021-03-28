/******************************************************************************
 * FILE PURPOSE: Profilng Tool Module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for the Profiling Tool.
 *
 * Copyright (C) 2015, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the device
 *  directory into the package.
 **************************************************************************/
function modBuild()
{
    /* Add all the .h files to the release package. */
    var deviceFiles = libUtility.listAllFiles (".h", "scripts", true);
    for (var k = 0 ; k < deviceFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = deviceFiles[k];

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "scripts", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

}
