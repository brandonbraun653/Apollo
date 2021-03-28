/******************************************************************************
 * FILE PURPOSE: ICSS_EMAC Driver Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the ICSS_EMAC Driver
 *
 * Copyright (C) 2015-2016 Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all the ICSS_EMAC Driver Files */
var icss_emacSockLibFiles = [
    "src/icss_emacDrv.c",
    "src/icss_emacFwInit.c",
    "src/icss_emacLearning.c",
    "src/icss_emacStatistics.c",
    "src/icss_emacStormControl.c",
    "src/icss_emacLoc.c"
    
];

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the ICSS_EMAC LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    if (socs.length != 0)
    {
        /* Build the device independent libraries for all the targets specified. */
        for (var targets=0; targets < socs["all"].targets.length; targets++)
        {
            var targetFiles = icss_emacSockLibFiles.slice(); /* make copy */
            var libOptions = {
                copts: socs["all"].copts,
                incs:  lldIncludePath, 
            };
            libUtility.buildLibrary ("",  "false", "false", libOptions, Pkg.name, socs["all"].targets[targets], targetFiles);
            libUtility.buildLibrary ("",  "false", "false", libOptions, Pkg.name, socs["all"].targets[targets], targetFiles, true);
        }
        
        /* Build library targets for device dependent SoCs */
        for (var soc=0; soc < soc_names.length; soc++) 
        {
            var dev = socs[soc_names[soc]];
            
            /* do not proceed if this SoC is not configured to be built */
            if (dev.build == "false")
               continue;

            if (dev.socDevLib == "true")
            { 
                var targetFiles_soc = icss_emacSockLibFiles.slice(); /* make copy */
                targetFiles_soc.push (deviceConstruct[0]+soc_names[soc]+deviceConstruct[1]);
                /* Build the libraries for all the targets specified. */
                for (var targets=0; targets < dev.targets.length; targets++)
                {
                    var libOptions = {
                        copts: dev.copts,
                        incs:  lldIncludePath, 
                    };
                    libUtility.buildLibrary (soc_names[soc], "false", "true", libOptions, Pkg.name, dev.targets[targets], targetFiles_soc);
                    libUtility.buildLibrary (soc_names[soc], "false", "true", libOptions, Pkg.name, dev.targets[targets], targetFiles_soc, true);
                }
            }
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

