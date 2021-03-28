/******************************************************************************
 * FILE PURPOSE: Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification to build this XDC package
 *
 * Copyright (C) 2015-2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : buildTarget
 **************************************************************************/
function buildTarget(evm)
{
	var boardName = boards[evm].name;
	/* Build the libraries for all the targets specified. */
	for (var targets=0; targets < boards[evm].targets.length; targets++)
	{	
		/* If building for K2K, use K2H source files */
		if (boardName.equals("evmK2K"))
			var files = libUtility.listAllFiles(".c", "src/evmK2H", true);
		else
			var files = libUtility.listAllFiles(".c", "src/"+boardName, true);

		if (java.lang.String(boardName).contains("evmK2") || java.lang.String(boardName).contains("evmC66"))
		{
			files[files.length++] = "./src/evmKeystone/board_utils.c";
			files[files.length++] = "./src/evmKeystone/board_clock.c";
			files[files.length++] = "./src/evmKeystone/board_lld_init.c";
			files[files.length++] = "./src/evmKeystone/board_pll.c";
		}

		if (files == undefined)
		{
			print("No source files for ./src/"+boardName);
			print("Skipping build.");
			continue;
		}
		files[files.length++] = "./src/board.c";

		/* Additional starterware files if defined */
		if (boards[evm].stwFiles != undefined)
		{
			for (var stwFile = 0; stwFile < boards[evm].stwFiles.length; stwFile++)
			{
				files[files.length++] = boards[evm].stwFiles[stwFile];
			}
		}

		/* Additional LLD dependent files if defined */
		if (boards[evm].lldFiles != undefined)
		{
			for (var lldFile = 0; lldFile < boards[evm].lldFiles.length; lldFile++)
			{
				files[files.length++] = boards[evm].lldFiles[lldFile];
			}
		}

		/* Additional flash dependent files if defined */
		if (boards[evm].flashFiles != undefined)
		{
			for (var flashFile = 0; flashFile < boards[evm].flashFiles.length; flashFile++)
			{
				files[files.length++] = boards[evm].flashFiles[flashFile];
			}
		}

		var libOptions = {
		};

		/* If AM5 and C66, add asm file for IO delay */
		if (java.lang.String(boardName).contains("AM5") && java.lang.String(boards[evm].targets[targets].name).contains("66"))
		files[files.length++] = "./src/"+boardName+"/iodelay_stack_C66.asm";

		/* Build the library */
		libUtility.buildLibrary (libOptions, Pkg.name, boards[evm], boards[evm].targets[targets], files);

	}
}

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************/
function modBuild() 
{
        if (boards.length != 0)
        {
                /* First argument is the filename config.bld. If nothing else specified, build everything */
                if (buildArguments.length == 1)
                {
                        print("Building for all boards");
                        for (var evm=0; evm < boards.length; evm++)
                        {
                                buildTarget(evm);
                        }
                }
                else
                {
                        for (var xdcArg=1; xdcArg < buildArguments.length; xdcArg++)
                        {
                                for (var evm=0; evm < boards.length; evm++)
                                {
                                        var boardName = boards[evm].name;
                                        if (boardName.equals(buildArguments[xdcArg]))
                                        {
                                                print("Building for " + boardName);
                                                buildTarget(evm);
                                        }
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

    /* Add all the .asm files to the release package. */
    var testFiles = libUtility.listAllFiles (".asm", "src", true);
    for (var k = 0 ; k < testFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = testFiles[k];

        /* Add all the .mk files to the release package. */
        var mkFiles = libUtility.listAllFiles (".mk", "src", true);
        for (var k = 0 ; k < mkFiles.length; k++)
            Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];
}

