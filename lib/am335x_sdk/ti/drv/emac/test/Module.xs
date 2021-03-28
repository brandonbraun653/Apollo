/*
 * Module.xs
 *
 * EMAC Driver Documents Module Specification File.
 *
 * Copyright (C) 2010-2019 Texas Instruments Incorporated - http://www.ti.com/
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

/******************************************************************************
 * FILE PURPOSE: EMAC Driver Documents Module Specification File.
 ******************************************************************************
 * FILE NAME: Module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification file for the EMAC Driver.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function builds all the components for the documentation. Here we
 *  add all the documentation files to the release package.
 **************************************************************************/
function modBuild() 
{

    /* Always add all the documentation to the release package. */
    var documentFiles = libUtility.listAllFiles (".c", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".h", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles ("makefile", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles ("makefile_without_ddr", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles ("makefile_dualmac", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles ("makefile_switch", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles ("makefile_switch_benchmark", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles ("makefile_switch_link_status", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".cdtbuild", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".cdtproject", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".project", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".ini", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".cfg", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".txt", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }

    var documentFiles = libUtility.listAllFiles (".xs", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles (".lds", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
    
    var documentFiles = libUtility.listAllFiles (".asm", "./test");
    for (var k = 0 ; k < documentFiles.length; k++) {
        Pkg.otherFiles[Pkg.otherFiles.length++] = documentFiles[k];
    }
}

