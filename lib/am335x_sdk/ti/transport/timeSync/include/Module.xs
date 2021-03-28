/******************************************************************************
 * FILE PURPOSE: TimeSync Source module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the TimeSync source directory.
 *
 * Copyright (C) 2018, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build all the components of the TimeSYnc library
 **************************************************************************/
function modBuild() 
{
    /* Add all the .h files to the release package. */
    var testFiles = libUtility.listAllFiles (".h", "include");
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];
}

