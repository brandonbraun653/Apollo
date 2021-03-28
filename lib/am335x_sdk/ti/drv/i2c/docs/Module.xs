/******************************************************************************
 * FILE PURPOSE: I2C Driver DOCS Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the I2C Driver Documentation .
 *
 * Copyright (C) 2008-2016, Texas Instruments, Inc.
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
    Pkg.makePrologue += "release: i2c_document_generation\n";
    Pkg.makePrologue += "i2c_document_generation:\n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";
    Pkg.makePrologue += "\t @echo Generating I2C Driver Documentation\n";
    Pkg.makePrologue += "\t doxygen docs/Doxyfile\n";
    Pkg.makePrologue += "\t @echo I2C Driver Documentation Generated \n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";

    /* Add the documentation file to the package. */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tifooter.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tiheader.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tilogo.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/titagline.gif";


    /* Add the I2C Software Manifest to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/I2C_LLD_SoftwareManifest.html";

    /* Add the HTML documentation to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/doxygen";

    /* Add the release notes to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/ReleaseNotes_I2C_LLD.pdf";

    /* Generate the ECLIPSE Plugin Generation: Only for SETUP Releases. */
    if (driverInstallType == "SETUP")
    {
        Pkg.makePrologue += "all: eclipse_plugin_generation\n";
        Pkg.makePrologue += "eclipse_plugin_generation:\n";
        Pkg.makePrologue += "\t @echo ----------------------------\n";
        Pkg.makePrologue += "\t @echo I2C Eclipse Plugin Generation\n";
        Pkg.makePrologue += "\t xs xdc.tools.eclipsePluginGen -o . -x ./eclipseDocs/sample.xml -c ./eclipseDocs/toc_cdoc_sample.xml\n";
        Pkg.makePrologue += "\t @echo I2C Eclipse Plugin Generated \n";
        Pkg.makePrologue += "\t @echo ----------------------------\n";
    }
}

