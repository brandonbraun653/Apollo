/******************************************************************************
 * FILE PURPOSE: Build subscript for SoC and IP
 ******************************************************************************
 * FILE NAME: Build.xs
 *
 * DESCRIPTION: 
 *  This file contains the build subscript for SoC and IP
 *
 * Copyright (C) 2012, Texas Instruments, Inc.
 *****************************************************************************/

/* Load the library utility. */
var libUtility = xdc.loadCapsule ("../../build/buildlib.xs");

/* This will have all the CSL source files - soc, ip's */
var cslFiles =[];

/* CSL Version File */
var cslSocFile = [
    "soc/k2g/src/csl_version.c",
    "soc/k2g/src/csl_gpioGetBaseAddress.c",
    "soc/k2g/src/csl_edma3GetBaseAddress.c",
    "soc/k2g/src/csl_cpIntcGetBaseAddress.c",
    "soc/k2g/src/csl_timerGetBaseAddress.c",
    "soc/k2g/src/csl_pllcGetBaseAddress.c",
    "soc/k2g/src/csl_mpuGetBaseAddress.c",
    "soc/k2g/src/csl_emif4fGetBaseAddress.c",
];



/* CHIP IP File */
var chipIPFile = [
    "src/ip/chip/V0/csl_chip.c",
];


/* EDMA IP File */
var edmaIPFile = [
    "src/ip/edma/V0/csl_edma3Init.c",
    "src/ip/edma/V0/csl_edma3Open.c",
    "src/ip/edma/V0/csl_edma3Close.c",
    "src/ip/edma/V0/csl_edma3HwSetup.c",
    "src/ip/edma/V0/csl_edma3HwControl.c",
    "src/ip/edma/V0/csl_edma3GetHwStatus.c",
    "src/ip/edma/V0/csl_edma3GetHwSetup.c",
    "src/ip/edma/V0/csl_edma3ChannelOpen.c",
    "src/ip/edma/V0/csl_edma3ChannelClose.c",
    "src/ip/edma/V0/csl_edma3HwChannelSetup.c",
    "src/ip/edma/V0/csl_edma3HwChannelControl.c",
    "src/ip/edma/V0/csl_edma3GetHwChannelStatus.c",
    "src/ip/edma/V0/csl_edma3GetHwChannelSetup.c",
    "src/ip/edma/V0/csl_edma3Param.c",
];


/* MDIO IP File */
var mdioIPFile = [
    "src/ip/mdio/V0/cslr_mdio_resetread.c", 
];


/* SERDES-SnowBush IP File */
var serdessbIPFile = [
    "src/ip/serdes_sb/V0/cslr_wiz8b4m4sb_resetread.c", 
    "src/ip/serdes_sb/V0/cslr_wiz8b4sb_2ckr_resetread.c", 
    "src/ip/serdes_sb/V0/cslr_wiz8b4sb_resetread.c", 
    "src/ip/serdes_sb/V0/cslr_wiz8b8m4sb_resetread.c", 
    "src/ip/serdes_sb/V0/cslr_wiz8b8sb_resetread.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_1p25G_156p25MHz_cmu0.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_1p25G_156p25MHz_comlane.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_10p3125G_16bit_lane1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_10p3125G_16bit_lane2.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_10p3125G_156p25MHz_cmu1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_10p3125G_comlane.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_reset_clr.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk100MHz_pci_5Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps_2l1c.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps_2l1c.c", 
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk125MHz_10bit_5Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk125MHz_20bit_5Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk125MHz_20bit_6p25Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_2l1c_sr1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk153p6MHz_20bit_4p9152Gbps_sr1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk153p6MHz_20bit_6p144Gbps_2l1c.c", 
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_10bit_5Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_20bit_5Gbps_sr1.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_20bit_6p25Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_20bit_10Gbps_sr1.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk156p25MHz_20bit_12p5Gbps_sr1.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk312p5MHz_20bit_5Gbps.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk312p5MHz_20bit_5Gbps_sr1.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk312p5MHz_20bit_6p25Gbps.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk312p5MHz_20bit_10Gbps_sr1.c",  
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk312p5MHz_20bit_12p5Gbps_sr1.c",         
];

/* SGMII IP File */
var sgmiiIPFile = [
   /*  "src/ip/sgmii/V0/cslr_cpsgmii_resetread.c", 
    "src/ip/sgmii/V0/csl_cpsgmii.c" */
];

/* TIMER IP File */
var timerIPFile = [
    "src/ip/timer/V0/csl_tmrInit.c",
    "src/ip/timer/V0/csl_tmrOpen.c",
    "src/ip/timer/V0/csl_tmrClose.c",
    "src/ip/timer/V0/csl_tmrHwSetup.c",
    "src/ip/timer/V0/csl_tmrHwSetupRaw.c",
    "src/ip/timer/V0/csl_tmrHwControl.c",
    "src/ip/timer/V0/csl_tmrGetHwStatus.c",
    "src/ip/timer/V0/csl_tmrGetHwSetup.c",
];

/* TSC IP File */
var tscIPFile = [
    "src/ip/tsc/V0/csl_tsc.asm",
];

/* USIM IP File */
var usimIPFile = [
    "src/ip/usim/V0/cslr_usimocp_resetread.c",
];

/* A15 File */
var a15File = [
    "arch/a15/V0/csl_a15Asm.asm",
    "arch/a15/V0/csl_a15.c",
    "arch/a15/V0/csl_a15AsmUtils.c",
];


/**************************************************************************
 * FUNCTION NAME : getSources
 **************************************************************************
 * DESCRIPTION   :
 *  The function returns an array of source files that constitute the chip 
 *  support library
 **************************************************************************/
function getSources ()
{
    var index;

    /* Add all the CSL Device specific Files. */ 
    for (index = 0; index < cslSocFile.length; index++)
        cslFiles[cslFiles.length++] = cslSocFile[index];

    /* Add all the CHIP Files. */ 
    for (index = 0; index < chipIPFile.length; index++)
        cslFiles[cslFiles.length++] = chipIPFile[index];

    /* Add all the EDMA Files. */ 
    for (index = 0; index < edmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = edmaIPFile[index];


    /* Add all the MDIO Files. */ 
    for (index = 0; index < mdioIPFile.length; index++)
        cslFiles[cslFiles.length++] = mdioIPFile[index];


    /* Add all the SERDES-SnowBush Files. */ 
    for (index = 0; index < serdessbIPFile.length; index++)
        cslFiles[cslFiles.length++] = serdessbIPFile[index];

    /* Add all the SGMII Files. */ 
    for (index = 0; index < sgmiiIPFile.length; index++)
        cslFiles[cslFiles.length++] = sgmiiIPFile[index];

    /* Add all the TIMER Files. */ 
    for (index = 0; index < timerIPFile.length; index++)
        cslFiles[cslFiles.length++] = timerIPFile[index];

    /* Add all the TSC Files. */ 
    for (index = 0; index < tscIPFile.length; index++)
        cslFiles[cslFiles.length++] = tscIPFile[index]; 


    /* Add all the USIM Files. */ 
    for (index = 0; index < usimIPFile.length; index++)
        cslFiles[cslFiles.length++] = usimIPFile[index];

    /* Return the list of all CSL Files */
    return cslFiles;
}

/**************************************************************************
 * FUNCTION NAME : buildLibrary
 **************************************************************************
 * DESCRIPTION   :
 *  The function is used to build the chip support library.
 **************************************************************************/
function buildLibrary (soc, target, opt) {
    var libOptions = {
        copts: opt,
        incs: cslPathInclude,
    };

    if ( target.name == "A15F" )
    {
        var files = [];
        /* Add all the CSL Device specific Files. */
        for (index = 0; index < cslSocFile.length; index++)
            files[cslFiles.length++] = cslSocFile[index];
	
        /* Add all the EDMA Files. */
        for (index = 0; index < edmaIPFile.length; index++)
            files[cslFiles.length++] = edmaIPFile[index];
			
        /* Add all the mdioIPFile. */
        for (index = 0; index < mdioIPFile.length; index++)
            files[cslFiles.length++] = mdioIPFile[index];
			
        /* Add all the serdessbIPFiles. */
        for (index = 0; index < serdessbIPFile.length; index++)
            files[cslFiles.length++] = serdessbIPFile[index];	

        /* Add all the sgmiiIPFile. */
        for (index = 0; index < sgmiiIPFile.length; index++)
            files[cslFiles.length++] = sgmiiIPFile[index];			

        /* Add all the timerIPFile. */
        for (index = 0; index < timerIPFile.length; index++)
            files[cslFiles.length++] = timerIPFile[index];

        /* Add all the A15 Files. */
        for (index = 0; index < a15File.length; index++)
            files[files.length++] = a15File[index];
			
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, files);
    }
    else if (java.lang.String(target.name).contains('66'))
    {
        libUtility.buildLibrary (libOptions, Pkg.name, soc, target, cslFiles);
    }
}

