/******************************************************************************
 * FILE PURPOSE: CSL example module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the CSL arch folder .
 *
 * Copyright (C) 2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to add all the source files in the example 
 *  directory into the package.
 **************************************************************************/
function modBuild() 
{
    /* Add all the .c files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".c", "arch", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];
		
    /* Add all the .asm files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".asm", "arch", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];

    /* Add all the .h files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".h", "arch", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];

    /* Add all the .mk files to the release package. */
    var exampleFiles = libUtility.listAllFiles (".mk", "arch", true);
    for (var k = 0 ; k < exampleFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = exampleFiles[k];
}
