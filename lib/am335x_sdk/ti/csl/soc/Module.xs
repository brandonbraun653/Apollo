/******************************************************************************
 * FILE PURPOSE: CSL DEVICE Module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the CSL Device.
 *
 * Copyright (C) 2011-2012, Texas Instruments, Inc.
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
    var deviceFiles = libUtility.listAllFiles (".h", "soc", true);
    for (var k = 0 ; k < deviceFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = deviceFiles[k];

	/* Add all the .h files to the release package. */
    var deviceFiles = libUtility.listAllFiles (".c", "soc", true);
    for (var k = 0 ; k < deviceFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = deviceFiles[k];

    /* Add all the .mk files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".mk", "soc", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];

}
