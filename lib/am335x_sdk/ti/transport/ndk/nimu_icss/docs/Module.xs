/******************************************************************************
 * FILE PURPOSE: NIMU_ICSS TRANSPORT DOCS Module specification file.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the NIMU_ICSS TRANSPORT Documentation.
 *
 * Copyright (C) 2017, Texas Instruments, Inc.
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
    Pkg.makePrologue += "release: nimu_icss_transport document_generation\n";
    Pkg.makePrologue += "nimu_icss_transport document_generation:\n";
    Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
    Pkg.makePrologue += "\t @echo Generating NIMU_ICSS TRANSPORT Documentation\n";
    Pkg.makePrologue += "\t doxygen docs/Doxyfile\n";
    Pkg.makePrologue += "\t @echo NIMU_ICSS TRANSPORT Documentation Generated \n";
    Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";

    /* Add the documentation file to the package. */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tifooter.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tiheader.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tilogo.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/titagline.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/doxygen";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/NIMU_ICSS_TRANSPORT_SoftwareManifest.pdf";

    if (driverInstallType == "SETUP")
    {
        /* Generate the ECLIPSE Plugin Generation */
        Pkg.makePrologue += "all: eclipse_plugin_generation\n";
        Pkg.makePrologue += "eclipse_plugin_generation:\n";
        Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
        Pkg.makePrologue += "\t @echo NIMU_ICSS TRANSPORT Eclipse Plugin Generation\n";
        Pkg.makePrologue += "\t xs xdc.tools.eclipsePluginGen -o . -x ./eclipseDocs/sample.xml -c ./eclipseDocs/toc_cdoc_sample.xml\n";
        Pkg.makePrologue += "\t @echo NIMU_ICSS TRANSPORT Eclipse Plugin Generated \n";
        Pkg.makePrologue += "\t @echo -------------------------------------------------------\n";
    }
}
