/******************************************************************************
 * FILE PURPOSE: USB Driver Source Module specification file.
 ******************************************************************************
 * FILE NAME: module.xs
 *
 * DESCRIPTION: 
 *  This file contains the module specification for the USB Driver
 *
 * Copyright (C) 2015 Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../build/buildlib.xs");

/* List of all the USB Driver Files */
var usbSrcFiles = [
    "src/usb_drv.c",
    "src/usb_func/common/usb_desc.c",
    "src/usb_func/device/usbdmsc.c",
    "src/usb_func/device/usbdcdesc.c",
    "src/usb_func/device/usb_dcd_interface.c",
    "src/usb_func/device/usb_dev_dman.c",
    "src/usb_func/host/usbhmsc.c",
    "src/usb_func/host/usbhscsi.c",
    "src/usb_func/common/usbtick.c",
];

var usbAm335xSrcFiles = [
    "src/musb/musb.c",
    "src/musb/usb_musb.c",
    "src/musb/usb_musb_dcd.c",
    "src/usb_func/host/usbhenum_musb.c", 
];

var usbAm437xSrcFiles = [
    "src/dwc/usb_xhci_hcd.c",
    "src/dwc/usb_dwc_dcd.c",
    "src/dwc/usb_dwc.c",
    "src/usb_func/host/usbhenum_dwc.c",
];

/**************************************************************************
 * FUNCTION NAME : modBuild
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the USB LLD Driver and to add the core
 *  driver files to the package. 
 **************************************************************************/
function modBuild() 
{
    if (socs.length != 0)
    {
        /* Build the device independent libraries for all the targets specified. */
        for (var targets=0; targets < socs["all"].targets.length; targets++)
        {
            var targetFiles = usbSrcFiles.slice(); /* make copy */
            var libOptions = {
                copts: socs["all"].copts,
                incs:  lldIncludePath, 
            };
            libUtility.buildLibrary ("",  "false", "false", libOptions, Pkg.name, socs["all"].targets[targets], targetFiles);
        }
        
        /* Build library targets for device dependent SoCs */
        for (var soc=0; soc < soc_names.length; soc++) 
        {
            var dev = socs[soc_names[soc]];
     
            /* do not proceed if this SoC is not configured to be built */
            if (dev.build == "false")
               continue;

            print("SOC being built is: " + soc_names[soc]);

            if (dev.socDevLib == "true")
            { 
                var targetFiles_soc = usbSrcFiles.slice(); /* make copy */


                /* get the soc dependent files */
                var socSrcFileList = libUtility.listAllFiles(".c", "soc/"+soc_names[soc], true);

                for (var i=0; i<socSrcFileList.length; i++)
                {
                    print(socSrcFileList[i]);
                    targetFiles_soc.push ( socSrcFileList[i]);
                }

                if (soc_names[soc] == "am335x") {
                    for (var i=0; i<usbAm335xSrcFiles.length; i++) {
                        targetFiles_soc.push (usbAm335xSrcFiles[i]);
                    }
                }

                if ((soc_names[soc] == "am437x") || 
                    (soc_names[soc] == "am571x") || 
                    (soc_names[soc] == "am572x") ||  
                    (soc_names[soc] == "am574x") ||
                    (soc_names[soc] == "am57xx") ||  
                    (soc_names[soc] == "k2g"))  {
                    for (var i=0; i<usbAm437xSrcFiles.length; i++) {
                        targetFiles_soc.push (usbAm437xSrcFiles[i]);
                    }
                }

                /* Build the libraries for all the targets specified. */
                for (var targets=0; targets < dev.targets.length; targets++)
                {
                    var libOptions = {
                        copts: dev.copts,
                        incs:  lldIncludePath, 
                    };

                    libUtility.buildLibrary (soc_names[soc], "false", "true", libOptions, Pkg.name, 
                                             dev.targets[targets], targetFiles_soc);
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

    /* Add all the .mk files to the release package. */
    var mkFiles = libUtility.listAllFiles (".mk", "src", true);
    for (var k = 0 ; k < mkFiles.length; k++)
        Pkg.otherFiles[Pkg.otherFiles.length++] = mkFiles[k];

}

