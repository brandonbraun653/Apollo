/******************************************************************************
 * FILE PURPOSE: MCASP LLD DOCS Module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the MCASP LLD Documentation.
 *
 * Copyright (C) 2012-2016, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build all the components of the documentation
 **************************************************************************/
function modBuild() 
{
    /* Create the actual PROLOGUE Section for the Documentation.*/
    Pkg.makePrologue += "release: mcasp_lld_document_generation\n";
    Pkg.makePrologue += "mcasp_lld_document_generation:\n";
    Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
    Pkg.makePrologue += "\t @echo Generating MCASP LLD Documentation\n";
    Pkg.makePrologue += "\t doxygen docs/Doxyfile\n";
    Pkg.makePrologue += "\t @echo MCASP LLD Documentation Generated \n";
    Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";

    /* Add the documentation file to the package. */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tifooter.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tiheader.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tilogo.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/titagline.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/doxygen";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/MCASP_LLD_SDS.pdf";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/MCASP_LLD_SoftwareManifest.pdf";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/ReleaseNotes_MCASP_LLD.pdf";

    if (driverInstallType == "SETUP")
    {
        /* Generate the ECLIPSE Plugin Generation */
        Pkg.makePrologue += "all: eclipse_plugin_generation\n";
        Pkg.makePrologue += "eclipse_plugin_generation:\n";
        Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
        Pkg.makePrologue += "\t @echo MCASP LLD Eclipse Plugin Generation\n";
        Pkg.makePrologue += "\t xs xdc.tools.eclipsePluginGen -o . -x ./eclipseDocs/sample.xml -c ./eclipseDocs/toc_cdoc_sample.xml\n";
        Pkg.makePrologue += "\t @echo MCASP LLD Eclipse Plugin Generated \n";
        Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
    }
}

