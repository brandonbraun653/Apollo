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
    "soc/k2h/src/csl_version.c",
    "soc/k2h/src/csl_aif2GetBaseAddress.c",
    "soc/k2h/src/csl_gpioGetBaseAddress.c",
    "soc/k2h/src/csl_edma3GetBaseAddress.c",
    "soc/k2h/src/csl_cpIntcGetBaseAddress.c",
    "soc/k2h/src/csl_srioGetBaseAddress.c",
    "soc/k2h/src/csl_timerGetBaseAddress.c",
    "soc/k2h/src/csl_pllcGetBaseAddress.c",
    "soc/k2h/src/csl_mpuGetBaseAddress.c",
    "soc/k2h/src/csl_emif4fGetBaseAddress.c",
];

/* AIF IP File */
var aifIPFile = [
    "src/ip/aif2/V0/csl_aif2Init.c",
    "src/ip/aif2/V0/csl_aif2Open.c",
    "src/ip/aif2/V0/csl_aif2Close.c",
    "src/ip/aif2/V0/csl_aif2HwSetup.c",
    "src/ip/aif2/V0/csl_aif2HwControl.c",
    "src/ip/aif2/V0/csl_aif2GetHwStatus.c",
    "src/ip/aif2/V0/csl_aif2Reset.c",
];

/* BWMGMT IP File */
var bwmgmtIPFile = [
];

/* CACHE IP File: There are no source files associated with the CACHE Module. */
var cacheIPFile = [
];

/* EMIF4 IP File: There are no source files associated with the EMIF4 Module. */
var emif4IPFile = [
];

/* Boot Cfg IP File: There are no source files associated with the Boot Cfg Module. */
var bootCfgIPFile = [
];

/* CFG IP File */
var cfgIPFile = [
];

/* CHIP IP File */
var chipIPFile = [
    "src/ip/chip/V0/csl_chip.c",
];

/* CIC IP File */
var cicIPFile = [
];

/* DAT IP File */
var datIPFile = [
];

/* DDR2 IP File */
var ddr2IPFile = [
];

/* DTF IP File */
var dtfIPFile = [
];

/* ECTL IP File */
var ectlIPFile = [
];

/* EDC IP File */
var edcIPFile = [
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

/* EMAC IP File */
var emacIPFile = [
    "src/ip/cpsw/V0/csl_cpsw_5gf.c",
    "src/ip/cpsw/V0/cslr_cpts_resetread.c", 
];

/* ETB IP File */
var tetbIPFile = [
];

/* FSYNC IP File */
var fsyncIPFile = [
];

/* GPIO IP File */
var gpioIPFile = [
];

/* I2C IP File */
var i2cIPFile = [
];

/* IDMA IP File */
var idmaIPFile = [
];

/* IPC IP File */
var ipcIPFile = [
];

/* McBSP IP File */
var mcbspIPFile = [
];

/* MDIO IP File */
var mdioIPFile = [
    "src/ip/mdio/V0/cslr_mdio_resetread.c", 
];

/* MEMPROT IP File */
var memprotIPFile = [
];

/* PLLC IP File */
var pllcIPFile = [
];

/* PSC IP File */
var pscIPFile = [
];

/* PWRDWN IP File */
var pwrdwnIPFile = [
];

/* RAC IP File */
var racIPFile = [
/*    "src/ip/rac/V0/csl_rac.c",
    "src/ip/rac/V0/csl_rac_regsGCCPAux.c",
    "src/ip/rac/V0/csl_rac_regsFEAux.c",
    "src/ip/rac/V0/csl_rac_regsBEAux.c", */
];

/* TAC IP File */
var tacIPFile = [
    "src/ip/tac2/V0/csl_tac2_regsBEAux.c",
    "src/ip/tac2/V0/csl_tac2_regsFEAux.c",
    "src/ip/tac2/V0/csl_tac2_regsSGCPAux.c",
];

/* SEM IP File: There are no source files associated with the SEM Module. */
var semIPFile = [
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
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_aneg_lane1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_aneg_lane2.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_Firmware.c",        
    "src/ip/serdes_sb/V0/csl_wiz8_sb_PhyB_reset_clr.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk100MHz_pci_5Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_4p9152Gbps_2l1c.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_6p144Gbps_2l1c.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_7p3728Gbps_2l1c.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_9p8304Gbps_2l1c_AIF_sr1.c",
    "src/ip/serdes_sb/V0/csl_wiz8_sb_refclk122p88MHz_20bit_9p8304Gbps_2l1c_JESD.c",             
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
    "src/ip/sgmii/V0/cslr_cpsgmii_resetread.c", 
    "src/ip/sgmii/V0/csl_cpsgmii.c" 
];

/* SRIO IP File: There are no source files associated with the SRIO Module. */
var srioIPFile = [
    "src/ip/srio/V0/cslr_srio_resetread.c",
];

/* TCP2 IP File */
var tcp2IPFile = [
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

/* VCP2 IP File */
var vcp2IPFile = [
    "src/ip/vcp2/V0/csl_vcp2.c",
];

/* MSMC IP File: There are no source files associated with the MSMC Module. */
var msmcIPFile = [
];

/* CPINTC IP File: There are no source files associated with the CPINTC Module. */
var cpIntcIPFile = [
];

/* XMC IP File: There are no source files associated with the XMC Module. */
var xmcIPFile = [
];

/* MPU IP File: There are no source files associated with the MPU Module. */
var mpuIPFile = [
];

/* EMIF16 IP File: There are no source files associated with the EMIF16 Module. */
var emif16IPFile = [
];

/* TCP2 IP File: There are no source files associated with the TCP2 Module. */
var tcp2IPFile = [
];

/* USIM IP File */
var usimIPFile = [
    "src/ip/usim/V0/cslr_usimocp_resetread.c",
];

/* XGE IP File */
var xgeIPFile = [
    "src/ip/xge/V0/cslr_xge_cpsw_resetread.c", 
    "src/ip/xge/V0/cslr_xge_cpsw_ss_s_resetread.c", 
    "src/ip/xge/V0/cslr_xge_cpxmac_sl_resetread.c", 
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

    /* Add all the CSL Version Files. */ 
    for (index = 0; index < cslSocFile.length; index++)
        cslFiles[cslFiles.length++] = cslSocFile[index];

    /* Add all the AIF Files. */ 
    for (index = 0; index < aifIPFile.length; index++)
        cslFiles[cslFiles.length++] = aifIPFile[index];

    /* Add all the BWMGMT Files. */ 
    for (index = 0; index < bwmgmtIPFile.length; index++)
        cslFiles[cslFiles.length++] = bwmgmtIPFile[index];

    /* Add all the CACHE Files. */ 
    for (index = 0; index < cacheIPFile.length; index++)
        cslFiles[cslFiles.length++] = cacheIPFile[index];

    /* Add all the EMIF4 Files. */ 
    for (index = 0; index < emif4IPFile.length; index++)
        cslFiles[cslFiles.length++] = emif4IPFile[index];

    /* Add all the Boot Cfg Files. */ 
    for (index = 0; index < bootCfgIPFile.length; index++)
        cslFiles[cslFiles.length++] = bootCfgIPFile[index];

    /* Add all the CFG Files. */ 
//    for (index = 0; index < cfgIPFile.length; index++)
//        cslFiles[cslFiles.length++] = cfgIPFile[index];

    /* Add all the CHIP Files. */ 
    for (index = 0; index < chipIPFile.length; index++)
        cslFiles[cslFiles.length++] = chipIPFile[index];

    /* Add all the CIC Files. */ 
//    for (index = 0; index < cicIPFile.length; index++)
//        cslFiles[cslFiles.length++] = cicIPFile[index];

    /* Add all the DAT Files. */ 
//    for (index = 0; index < datIPFile.length; index++)
//        cslFiles[cslFiles.length++] = datIPFile[index];

    /* Add all the DDR2 Files. */ 
//    for (index = 0; index < ddr2IPFile.length; index++)
//        cslFiles[cslFiles.length++] = ddr2IPFile[index];

    /* Add all the DTF Files. */ 
//    for (index = 0; index < dtfIPFile.length; index++)
//        cslFiles[cslFiles.length++] = dtfIPFile[index];

    /* Add all the ECTL Files. */ 
//    for (index = 0; index < ectlIPFile.length; index++)
//        cslFiles[cslFiles.length++] = ectlIPFile[index];

    /* Add all the ECTL Files. */ 
//    for (index = 0; index < edcIPFile.length; index++)
//        cslFiles[cslFiles.length++] = edcIPFile[index];

    /* Add all the EDMA Files. */ 
    for (index = 0; index < edmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = edmaIPFile[index];

    /* Add all the EMAC Files. */ 
    for (index = 0; index < emacIPFile.length; index++)
        cslFiles[cslFiles.length++] = emacIPFile[index];

    /* Add all the ETB Files. */ 
//    for (index = 0; index < tetbIPFile.length; index++)
//        cslFiles[cslFiles.length++] = tetbIPFile[index];

    /* Add all the FSYNC Files. */ 
//    for (index = 0; index < fsyncIPFile.length; index++)
//        cslFiles[cslFiles.length++] = fsyncIPFile[index];
    
	/* Add all the GPIO Files. */ 
//    for (index = 0; index < gpioIPFile.length; index++)
//        cslFiles[cslFiles.length++] = gpioIPFile[index];

    /* Add all the I2C Files. */ 
//    for (index = 0; index < i2cIPFile.length; index++)
//        cslFiles[cslFiles.length++] = i2cIPFile[index];

    /* Add all the IDMA Files. */ 
    for (index = 0; index < idmaIPFile.length; index++)
        cslFiles[cslFiles.length++] = idmaIPFile[index];

    /* Add all the IPC Files. */ 
    for (index = 0; index < ipcIPFile.length; index++)
        cslFiles[cslFiles.length++] = ipcIPFile[index];        

    /* Add all the McBSP Files. */ 
//    for (index = 0; index < mcbspIPFile.length; index++)
//        cslFiles[cslFiles.length++] = mcbspIPFile[index];

    /* Add all the MDIO Files. */ 
    for (index = 0; index < mdioIPFile.length; index++)
        cslFiles[cslFiles.length++] = mdioIPFile[index];

    /* Add all the MEMPROT Files. */ 
    for (index = 0; index < memprotIPFile.length; index++)
        cslFiles[cslFiles.length++] = memprotIPFile[index];

    /* Add all the PLLC Files. */ 
    for (index = 0; index < pllcIPFile.length; index++)
        cslFiles[cslFiles.length++] = pllcIPFile[index];

    /* Add all the PSC Files. */ 
    for (index = 0; index < pscIPFile.length; index++)
        cslFiles[cslFiles.length++] = pscIPFile[index];

    /* Add all the PWRDWN Files. */ 
    for (index = 0; index < pwrdwnIPFile.length; index++)
        cslFiles[cslFiles.length++] = pwrdwnIPFile[index];

    /* Add all the RAC Files. */ 
    for (index = 0; index < racIPFile.length; index++)
        cslFiles[cslFiles.length++] = racIPFile[index];

    /* Add all the TAC Files. */ 
    for (index = 0; index < tacIPFile.length; index++)
        cslFiles[cslFiles.length++] = tacIPFile[index];

    /* Add all the SEM Files. */ 
    for (index = 0; index < semIPFile.length; index++)
        cslFiles[cslFiles.length++] = semIPFile[index];

    /* Add all the SERDES-SnowBush Files. */ 
    for (index = 0; index < serdessbIPFile.length; index++)
        cslFiles[cslFiles.length++] = serdessbIPFile[index];

    /* Add all the SGMII Files. */ 
    for (index = 0; index < sgmiiIPFile.length; index++)
        cslFiles[cslFiles.length++] = sgmiiIPFile[index];

    /* Add all the SRIO Files. */ 
    for (index = 0; index < srioIPFile.length; index++)
        cslFiles[cslFiles.length++] = srioIPFile[index];

    /* Add all the TCP2 Files. */ 
//    for (index = 0; index < tcp2IPFile.length; index++)
//        cslFiles[cslFiles.length++] = tcp2IPFile[index];

    /* Add all the TIMER Files. */ 
    for (index = 0; index < timerIPFile.length; index++)
        cslFiles[cslFiles.length++] = timerIPFile[index];

    /* Add all the TSC Files. */ 
    for (index = 0; index < tscIPFile.length; index++)
        cslFiles[cslFiles.length++] = tscIPFile[index]; 

    /* Add all the VCP2 Files. */ 
    for (index = 0; index < vcp2IPFile.length; index++)
        cslFiles[cslFiles.length++] = vcp2IPFile[index];

    /* Add all the MSMC Files. */ 
    for (index = 0; index < msmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = msmcIPFile[index];

    /* Add all the CPINTC Files. */ 
    for (index = 0; index < cpIntcIPFile.length; index++)
        cslFiles[cslFiles.length++] = cpIntcIPFile[index];

    /* Add all the XMC Files. */ 
    for (index = 0; index < xmcIPFile.length; index++)
        cslFiles[cslFiles.length++] = xmcIPFile[index];
    
    /* Add all the MPU Files. */ 
    for (index = 0; index < mpuIPFile.length; index++)
        cslFiles[cslFiles.length++] = mpuIPFile[index];
    
    /* Add all the EMIF16 Files. */ 
    for (index = 0; index < emif16IPFile.length; index++)
        cslFiles[cslFiles.length++] = emif16IPFile[index];

    /* Add all the TCP2 Files. */ 
    for (index = 0; index < tcp2IPFile.length; index++)
        cslFiles[cslFiles.length++] = tcp2IPFile[index];

    /* Add all the USIM Files. */ 
    for (index = 0; index < usimIPFile.length; index++)
        cslFiles[cslFiles.length++] = usimIPFile[index];

    /* Add all the XGE Files. */ 
    for (index = 0; index < xgeIPFile.length; index++)
        cslFiles[cslFiles.length++] = xgeIPFile[index];

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
	
        for (index = 0; index < aifIPFile.length; index++)
            files[cslFiles.length++] = aifIPFile[index];

        /* Add all the EDMA Files. */
        for (index = 0; index < edmaIPFile.length; index++)
            files[cslFiles.length++] = edmaIPFile[index];
			
        for (index = 0; index < emacIPFile.length; index++)
            files[cslFiles.length++] = emacIPFile[index];

        /* Add all the mdioIPFile. */
        for (index = 0; index < mdioIPFile.length; index++)
            files[cslFiles.length++] = mdioIPFile[index];
			
        for (index = 0; index < tacIPFile.length; index++)
            files[cslFiles.length++] = tacIPFile[index];

        /* Add all the serdessbIPFiles. */
        for (index = 0; index < serdessbIPFile.length; index++)
            files[cslFiles.length++] = serdessbIPFile[index];	

        /* Add all the sgmiiIPFile. */
        for (index = 0; index < sgmiiIPFile.length; index++)
            files[cslFiles.length++] = sgmiiIPFile[index];			

        /* Add all the timerIPFile. */
        for (index = 0; index < timerIPFile.length; index++)
            files[cslFiles.length++] = timerIPFile[index];

        for (index = 0; index < srioIPFile.length; index++)
            files[cslFiles.length++] = srioIPFile[index];

        for (index = 0; index < usimIPFile.length; index++)
            files[cslFiles.length++] = usimIPFile[index];

        for (index = 0; index < xgeIPFile.length; index++)
            files[cslFiles.length++] = xgeIPFile[index];

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

