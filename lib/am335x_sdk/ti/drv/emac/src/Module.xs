
/******************************************************************************
 * FILE PURPOSE: EMAC Driver Source Module Specification File.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the EMAC Source. The 
 *  source directory contains source code for the EMAC driver. The file 
 *  will build the library and will also package all the source files.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");


/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the EMAC LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
	/* First argument is the filename config.bld. If nothing else specified, build everything */
        for (var soc=0; soc < soc_names.length; soc++) 
	{
		var dev = socs[soc_names[soc]];
        	/* do not proceed if this SoC is not configured to be built */
        	if (dev.build == "false")
           		continue;

       		if (dev.socDevLib == "true")
		{
			var version = socs[soc_names[soc]].version;
			/* Build the libraries for all the targets specified. */
			for (var targets=0; targets < socs[soc_names[soc]].targets.length; targets++)
			{	
                		var libOptions = {
                    		copts: dev.copts,
                    		incs:  lldIncludePath, 
			        };	
				var files = libUtility.listAllFiles(".c", "src/"+version, true);

				if (files == undefined)
				{
					print("No source files for ./src/"+version);
					print("Skipping build.");
					continue;
				}
            			var targetFiles_soc = files.slice(); /* make copy */
            			targetFiles_soc.push (deviceConstruct[0]+soc_names[soc]+deviceConstruct[1]);
                		libUtility.buildLibrary (soc_names[soc], "false", "true", libOptions, Pkg.name, dev.targets[targets], targetFiles_soc);
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
}
