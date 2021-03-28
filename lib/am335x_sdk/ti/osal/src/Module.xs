/******************************************************************************
 * FILE PURPOSE: OSAL Driver Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the osal Driver
 *
 * Copyright (C) 2015-2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");


/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the osal LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    if (socs.length != 0)
    {
        /* Build the target libs for TI RTOS libraries, SOC independent */
        var targetFiles_tirtos = osTypes["tirtos"].srcFile.slice(); /* make copy */
        for (var target=0; target < Build.targets.length; target++)
        {
            var libOptions = {
                    copts: osTypes["tirtos"].copts,
                    incs:  osalIncludePath, 
                    }
            libUtility.buildLibrary ("tirtos", "", libOptions, Pkg.name, Build.targets[target], targetFiles_tirtos);                
            
        }
            
        /* Build the target libs for SoC specific RTOS*/    
        for each(var soc in soc_names)
        {        
            var dev = socs[soc];
            var targetFiles_tirtos_soc;

                    if (dev.familyType == "keystone") {
                       targetFiles_tirtos_soc = osTypes["tirtos"].srcFile.slice().concat(keyStoneFamilySrcFiles["tirtos"].srcFile.slice());
                    }
                    else {
                       targetFiles_tirtos_soc = osTypes["tirtos"].srcFile.slice().concat(amFamilySrcFiles["tirtos"].srcFile.slice());			
                    }

            /* Don't build if it is not configured */
            if (dev.build == "false")
                continue;
                            
            /* Build the libraries for the soc targets */
            for (var target=0; target < dev.targets.length; target++)
            {
                print (" Building for Soc: " + soc + " target : " + dev.targets[target] );
                var copts_loc  = osTypes["tirtos"].copts + " " + dev.copts;
                var libOptions = {
                                copts: copts_loc,
                                incs:  osalIncludePath, 
                }
                libUtility.buildLibrary ("tirtos", soc, libOptions, Pkg.name, dev.targets[target], targetFiles_tirtos_soc);                
            }
        }	

        /* Build the target libs for SoC specific NON OS */    
        /* Build the libraries for the SoCs */
        for each(var soc in soc_names)
        {        
            var dev = socs[soc];
            var targetFiles_nonos;
                    
                    if (dev.familyType == "keystone") {
                       targetFiles_nonos = osTypes["nonos"].srcFile.slice().concat(keyStoneFamilySrcFiles["nonos"].srcFile.slice());
                    }
                    else {
                       targetFiles_nonos = osTypes["nonos"].srcFile.slice().concat(amFamilySrcFiles["nonos"].srcFile.slice());			
                    }

            /* Don't build if it is not configured */
            if (dev.build == "false")
                continue;
                
            /* Build the libraries for the soc targets */
            for (var target=0; target < dev.targets.length; target++)
            {
                print (" Building for Soc: " + soc + " target : " + dev.targets[target] );
                var copts_loc  = osTypes["nonos"].copts + " " + dev.copts;
                var libOptions = {
                                copts: copts_loc,
                                incs:  osalIncludePath, 
                }
                libUtility.buildLibrary ("nonos", soc, libOptions, Pkg.name, dev.targets[target], targetFiles_nonos);                
            }
        }	
    }	
    /* Add all the .c files to the release package. */
    var testFiles = libUtility.listAllFiles (".c", "src", true);
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];

    var testFiles = libUtility.listAllFiles (".c", "arch", true);
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
    var asmFiles = libUtility.listAllFiles (".asm", "arch", true);
    for (var k = 0 ; k < asmFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = asmFiles[k];

}

