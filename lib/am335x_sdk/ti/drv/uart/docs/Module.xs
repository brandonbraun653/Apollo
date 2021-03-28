/******************************************************************************
 * FILE PURPOSE: UART Driver DOCS Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the UART Driver Documentation .
 *
 * Copyright (C) 2008, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the LLD documentation and add it to the
 *  package.
 **************************************************************************/
function modBuild() 
{
    /* Create the actual PROLOGUE Section for the Documentation.*/
    Pkg.makePrologue += "release: uart_document_generation\n";
    Pkg.makePrologue += "uart_document_generation:\n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";
    Pkg.makePrologue += "\t @echo Generating UART Driver Documentation\n";
    Pkg.makePrologue += "\t doxygen docs/Doxyfile\n";
    Pkg.makePrologue += "\t @echo UART Driver Documentation Generated \n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";

    /* Add the documentation file to the package. */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tifooter.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tiheader.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tilogo.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/titagline.gif";

    /* Add the UART Design Document to the package */
   /* Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/UART_SDS.pdf";*/

    /* Add the UART Software Manifest to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/UART_LLD_SoftwareManifest.html";

    /* Add the HTML documentation to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/doxygen";

    /* Add the release notes to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/ReleaseNotes_UART_LLD.pdf";

    /* Generate the ECLIPSE Plugin Generation: Only for SETUP Releases. */
    if (driverInstallType == "SETUP")
    {
        Pkg.makePrologue += "all: eclipse_plugin_generation\n";
        Pkg.makePrologue += "eclipse_plugin_generation:\n";
        Pkg.makePrologue += "\t @echo ----------------------------\n";
        Pkg.makePrologue += "\t @echo UART Eclipse Plugin Generation\n";
        Pkg.makePrologue += "\t xs xdc.tools.eclipsePluginGen -o . -x ./eclipseDocs/sample.xml -c ./eclipseDocs/toc_cdoc_sample.xml\n";
        Pkg.makePrologue += "\t @echo UART Eclipse Plugin Generated \n";
        Pkg.makePrologue += "\t @echo ----------------------------\n";
    }
}

