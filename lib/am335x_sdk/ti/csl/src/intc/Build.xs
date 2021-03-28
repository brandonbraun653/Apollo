/******************************************************************************
 * FILE PURPOSE: Build subscript for the INTC library
 ******************************************************************************
 * FILE NAME: package.bld
 *
 * DESCRIPTION: 
 *  This file contains the build subscript for the INTC library
 *
 * Copyright (C) 2008, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* List of all the NETTOOLS Files */
var intcLibFiles = [
    "src/intc/_csl_intcCombEventDispatcher.c",
    "src/intc/_csl_intcDispatcher.c",
    "src/intc/_csl_intcIntrEnDisRes.asm",
    "src/intc/_csl_intcIsrDispatch.asm",
    "src/intc/_csl_intcNmiDummy.asm",
    "src/intc/_csl_intcResource.c",
    "src/intc/csl_intcClose.c",
    "src/intc/csl_intcExcep.c",
    "src/intc/csl_intcGetHwStatus.c",
    "src/intc/csl_intcHookIsr.c",
    "src/intc/csl_intcHwControl.c",
    "src/intc/csl_intcInit.c",
    "src/intc/csl_intcOpen.c",
    "src/intc/csl_intcPlugEventHandler.c",
    "src/intc/csl_intcAsmUtils.c"
];

/**************************************************************************
 * FUNCTION NAME : getSources
 **************************************************************************
 * DESCRIPTION   :
 *  The function returns an array of source files that make the NETTOOLS 
 *  library
 **************************************************************************/
function getSources ()
{
    return intcLibFiles;
}

/**************************************************************************
 * FUNCTION NAME : buildLibrary
 **************************************************************************
 * DESCRIPTION   :
 *  The function is called from to build the OS Library.
 **************************************************************************/
function buildLibrary (device, target, opt)
{
    var libOptions = {
        copts: opt,
        incs: cslPathInclude, 
    };
    if ( java.lang.String(target.name).contains('66') )
    {
        libUtility.buildLibrary (libOptions, Pkg.name+".intc", device, target, intcLibFiles);
    }
}

