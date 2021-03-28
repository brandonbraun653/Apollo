/******************************************************************************
 * FILE PURPOSE: CSL DOCS Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the CSL Documentation .
 *
 * Copyright (C) 2011-2015, Texas Instruments, Inc.
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
    Pkg.makePrologue += ".PHONY: csl_lld_document_generation\n";
    Pkg.makePrologue += "release: csl_document_generation\n";
    Pkg.makePrologue += "docs/doxygen/html/index.html: csl_lld_document_generation\n";
    Pkg.makePrologue += "csl_document_generation:\n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";
    Pkg.makePrologue += "\t @echo Generating CSL Documentation\n";
    Pkg.makePrologue += "\t doxygen docs/Doxyfile\n";
    Pkg.makePrologue += "\t @echo CSL Documentation Generated \n";
    Pkg.makePrologue += "\t @echo ----------------------------\n";

    /* Add the documentation file to the package. */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tifooter.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tiheader.htm";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/tilogo.gif";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/titagline.gif";

    /* Add the HTML documentation to the package */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/doxygen";

    /* Add all the .pdf files to the release package. */
/*    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/CSL-legacy-API-changes.pdf"; */
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/CSL_SoftwareManifest.pdf";
    Pkg.otherFiles[Pkg.otherFiles.length++] = "docs/ReleaseNotes_CSL.pdf";
}

