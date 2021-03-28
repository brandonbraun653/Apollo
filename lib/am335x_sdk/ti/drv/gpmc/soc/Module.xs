/******************************************************************************
 * FILE PURPOSE: gpmc LLD soc files.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for gpmc LLD soc files.
 *
 * Copyright (C) 2009, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the soc
 *  directory into the package.
 **************************************************************************/
function modBuild()
{
    /* Add all the .c files to the release package. */
    var configFiles = libUtility.listAllFiles (".c", "soc", true);
    for (var k = 0 ; k < configFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = configFiles[k];

    /* Add all the .h files to the release package. */
    var configFiles = libUtility.listAllFiles (".h", "soc", true);
    for (var k = 0 ; k < configFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = configFiles[k];

    /* Add all the .mk files to the release package. */
    var mkFiles  = libUtility.listAllFiles (".mk", "soc", true);
    for (var k = 0 ; k < mkFiles .length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles [k];


}
