/******************************************************************************
 * FILE PURPOSE: NIMU_ICSS Library Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the NIMU_ICSS Library
 *
 * Copyright (C) 2015 Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all the NIMU_ICSS Library Files */
var nimu_icssLibFiles = [
    "src/nimu_icssEth.c",
    "src/nimu_icssEthDriver.c",
    "src/nimu_icssSwitchEmac.c"
];

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the NIMU_ICSS Library and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    if (Build.targets.length != 0)
    {
        /* Build the libraries for all the targets specified. */
        for (var targets=0; targets < Build.targets.length; targets++)
        {
                var libOptions = {
                    incs: lldIncludePath, 
                };
                
                libUtility.buildLibrary (libOptions, Pkg.name, Build.targets[targets], nimu_icssLibFiles);
        }
    }
    /* Add all the .c files to the release package. */
    var testFiles = libUtility.listAllFiles (".c", "src", true);
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];

    /* Add all the .h files to the release package. */
    var testFiles = libUtility.listAllFiles (".h", "src", true);
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "src", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

}

