/******************************************************************************
 * FILE PURPOSE: UART Driver Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the UART Driver
 *
 * Copyright (C) 2009-2015, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all the UART Driver Files */
var uartSockLibFiles = [
    "src/UART_drv.c",
    "src/v1/UART_v1.c",
    "src/v0/UART_v0.c",
    "src/UART_stdio.c",
    "src/UART_ascii_utils.c",
    "src/UART_status.c"
];

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the UART LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    if (socs.length != 0)
    {
        /* Build the device independent libraries for all the targets specified. */
        for (var targets=0; targets < socs["all"].targets.length; targets++)
        {
            var targetFiles = uartSockLibFiles.slice(); /* make copy */
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

            var soc_name = soc_names[soc];
            if ( soc_name.equals("k2k") )
                soc_name = "k2h";

            if (dev.socDevLib == "true")
            { 
                var targetFiles_soc = uartSockLibFiles.slice(); /* make copy */

                targetFiles_soc.push (deviceConstruct[0]+soc_name+deviceConstruct[1]);
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

             if (dev.dmaDevLib == "true")
             {
                 var targetFiles_soc_dma = uartSockLibFiles.slice(); /* make copy */
                 targetFiles_soc_dma.push (deviceDmaConstruct[0]+soc_name+deviceDmaConstruct[1]);

                 /* Build the libraries for all the targets specified. */
                 for (var targets=0; targets < dev.targets.length; targets++)
                 {
                     var libOptions = {
                         copts: dev.copts,
                         incs:  lldIncludePath, 
                     };
                     libUtility.buildLibrary (soc_names[soc], "true", "true", libOptions, Pkg.name, dev.targets[targets], targetFiles_soc_dma);
                     libUtility.buildLibrary (soc_names[soc], "true", "true", libOptions, Pkg.name, dev.targets[targets], targetFiles_soc_dma, true);
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

