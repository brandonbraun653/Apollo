/******************************************************************************
 * FILE PURPOSE: Profilng Tool Module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for the Profiling Tool.
 *
 * Copyright (C) 2017, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the filters in the filter
 *  directory into the package.
 **************************************************************************/
function modBuild()
{
    /* Add all the .txt files to the release package. */
    var filterFiles = libUtility.listAllFiles (".txt", "filters", true);
    for (var k = 0 ; k < filterFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = filterFiles[k];
}
