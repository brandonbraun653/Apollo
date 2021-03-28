/******************************************************************************
 * FILE PURPOSE: Processor SDK Utilities Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for the Processor SDK Utilities
 *
 * Copyright (C) 2015 Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all the Profiling Hook Files */
var profilingHookFiles = [
    "src/profilingHooksArmV7_A.c",
    "src/profilingHooksArmV7_AAssembly.asm",
    "src/profilingHooksM4.c",
    "src/profilingHooksC66.c",
    "src/profilingHooksArmV8_A.c",
    "src/profilingHooksR5.c"
];

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the Processor SDK Utilities
 **************************************************************************/
function modBuild()
{
    if (socs.length != 0)
    {
        /* Build the device independent libraries for all the targets specified. */
        for (var targets=0; targets < socs["all"].targets.length; targets++)
        {
            var profilingBaseFile = [];
            var libOptions = {
                copts: socs["all"].copts,
                incs: lldIncludePath,
            };

            if ((Build.targets[targets].name == "A15F" ) ||
                (Build.targets[targets].name == "A8F" ) ||
                (Build.targets[targets].name == "A9F" )) {
                profilingBaseFile[0] = profilingHookFiles[0];
            } else if (Build.targets[targets].name == "M4") {
                profilingBaseFile[0] = profilingHookFiles[1];
            } else {
                profilingBaseFile[0] = profilingHookFiles[2];
            }
            libUtility.buildLibrary ("",  "false", "false", libOptions, Pkg.name, socs["all"].targets[targets], profilingBaseFile);
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

    /* Add all the .asm files to the release package. */
    var testFiles = libUtility.listAllFiles (".asm", "src", true);
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];
}
