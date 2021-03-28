/******************************************************************************
 * FILE PURPOSE: CSL Source module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION:
 *  This file contains the module specification for the CSL source directory.
 *
 * Copyright (C) 2011-2015, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all subdirectories that combine to make the CSL and intc library.
 * Note the ip directory is not listed here. It will be build when soc is built.
 * The packaging is done below.
 */
var subDirectories = [ "src/intc", "soc/k2k", "soc/k2h", "soc/k2e",
                       "soc/k2l", "soc/k2g", "soc/am572x", "soc/am571x",
                       "soc/am335x", "soc/am437x",
                       "soc/c6678", "soc/c6657", "soc/omapl137" ];

function copy(src, dst)
{
    var ins = new java.io.FileInputStream(src);
    var outs = new java.io.FileOutputStream(dst, true);
    var inc = ins.getChannel();
    var outc = outs.getChannel();
    inc.transferTo(0, inc.size(), outc);    /* transfer entire src to dst */
    inc.close();
    outc.close();
    ins.close();
    outs.close();
}

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build all the components of the CSL
 **************************************************************************/
function modBuild()
{
    /* The files are already at the top level directory. */
    var copyFiles = libUtility.listAllFiles (".h", ".", false);

    /* This is a list of all header files in the CSL package.
     * Add the header files in the top level directory. */
    for (var k = 0 ; k < copyFiles.length; k++)
    {
        var file = new java.io.File(copyFiles[k]);

        /* The file Settings.h is a special case since this gets added automatically by the XDC package. */
        if (file.getName() != "Settings.h")
        {
            /* We add only those header files which are in the top level directory. */
            if (file.getParent() == ".")
                Pkg.otherFiles[Pkg.otherFiles.length++] = copyFiles[k];
        }
    }

    /* Get a list of all header files in src/ip folder and add them to the package. */
    var ipHdrFiles = libUtility.listAllFiles (".h", "src/ip", true);
    for (var j = 0; j < ipHdrFiles.length; j++)
    {
        Pkg.otherFiles[Pkg.otherFiles.length++] = ipHdrFiles[j];
    }

    /* Get a list of all header files in src/ip folder and add them to the package. */
    var ipSrcFiles = libUtility.listAllFiles (".c", "src/ip", true);
    for (var j = 0; j < ipSrcFiles.length; j++)
    {
        Pkg.otherFiles[Pkg.otherFiles.length++] = ipSrcFiles[j];
    }

    /* Get a list of all header files in src/ip folder and add them to the package. */
    var ipSrcFiles = libUtility.listAllFiles (".asm", "src/ip", true);
    for (var j = 0; j < ipSrcFiles.length; j++)
    {
        Pkg.otherFiles[Pkg.otherFiles.length++] = ipSrcFiles[j];
    }

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "src/ip", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "src/intc", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

    /*  cycle through each subdirectory inside source and build the libraries. */
    for (var i = 0; i < subDirectories.length; i++)
    {
        /* Load the capsule in the sub directory. */
        var caps = xdc.loadCapsule (subDirectories[i]+"/Build.xs");

        Pkg.otherFiles[Pkg.otherFiles.length++] = subDirectories[i]+"/Build.xs";

        /* Get a list of all source files and add them to the package. */
        var srcFiles = caps.getSources();
        for (var j = 0; j < srcFiles.length; j++)
            Pkg.otherFiles[Pkg.otherFiles.length++] = srcFiles[j];

        if (subDirectories[i] == "src/intc")
        {
            /* For the source release we need to get a list of all the
             * internal header files in each capsule and add them */
            var packageFiles = libUtility.listAllFiles (".h", subDirectories[i]);
            for (var k = 0 ; k < packageFiles.length; k++)
                Pkg.otherFiles[Pkg.otherFiles.length++] = packageFiles[k];

            /* Build the libraries for all the devices defined in config.bld */
            /* for each(var device in devices) */
            for each(var k = 1; k < devices.length; k++)
            {
                var build_device = 0;
                for ( j = 1; j < build_devices.length; j++ )
                {
                    if ( build_devices[j] == devices[k] )
                        build_device = 1;
                }
                if (build_device == 1)
                {
				    /* Get the list of targets for that device */
					var btargets = socs["all"].targets;

                    /* Build the libraries for all the targets specified. */
                    for (var targets=0; targets < btargets.length; targets++)
                    {
                        caps.buildLibrary (devices[k], btargets[targets], devicesCCOpt[k]);
                    }
                }
            }
        }
        else
        {
            var build_device = 0;
            for ( j = 1; j < build_devices.length; j++ )
            {
                if ( build_devices[j] == devices[i] )
                    build_device = 1;
            }
            if (build_device == 1)
            {
                /* Get the list of targets for that device */
                var btargets = socs[devices[i]].targets;
                /* Build the CSL device library for all the targets specified. */
                for (var targets=0; targets < btargets.length; targets++)
                {
                    caps.buildLibrary (devices[i], btargets[targets], devicesCCOpt[i]);
                }
            }
        }
    }
}
