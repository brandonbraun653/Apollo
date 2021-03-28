/******************************************************************************
 * Copyright (c) 2010-2015 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_xmcAux.h>
#include <ti/csl/csl_emif4fAux.h>
#include <ti/csl/hw_types.h>

#include "board_internal.h"

extern void BOARD_delay(uint32_t usecs);

static void xmc_add_emif_cfg_region()
{
    /* mapping for ddr emif registers XMPAX*2 */
    CSL_XMC_XMPAXL    mpaxl;
    CSL_XMC_XMPAXH    mpaxh;

    /* base addr + seg size (64KB)*/    //"1B"-->"B" by xj */
    mpaxh.bAddr     = (0x2100000B >> 12);
    mpaxh.segSize   = (0x2100000B & 0x0000001F);

    /* replacement addr + perm*/
    mpaxl.rAddr     = 0x100000;
    mpaxl.sr        = 1;
    mpaxl.sw        = 1;
    mpaxl.sx        = 1;
    mpaxl.ur        = 1;
    mpaxl.uw        = 1;
    mpaxl.ux        = 1;

    /* set the xmpax for index2 */
    CSL_XMC_setXMPAXH(2, &mpaxh);
    CSL_XMC_setXMPAXL(2, &mpaxl);
}

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_DDR3Init()
{
    Board_STATUS             status = BOARD_SOK;
    uint32_t                 ddr3config, ddrPhyCtrl;
    uint8_t                  ddrPHYReadLatency;
    EMIF4F_TIMING1_CONFIG    sdram_tim1;
    EMIF4F_TIMING2_CONFIG    sdram_tim2;
    EMIF4F_TIMING3_CONFIG    sdram_tim3;
    EMIF4F_OUTPUT_IMP_CONFIG zqcfg;
    EMIF4F_PWR_MGMT_CONFIG   pwrmgmtcfg;
    EMIF4F_SDRAM_CONFIG      sdramcfg;

	xmc_add_emif_cfg_region();

    CSL_BootCfgUnlockKicker();

    /**************** 3.3 Leveling Register Configuration ********************/
    CSL_BootCfgGetDDRConfig(0, &ddr3config);
    ddr3config &= ~(0x007FE000);  // clear ctrl_slave_ratio field
    CSL_BootCfgSetDDRConfig(0, ddr3config);

    CSL_BootCfgGetDDRConfig(0, &ddr3config);
    ddr3config |= 0x00200000;     // set ctrl_slave_ratio to 0x100
    CSL_BootCfgSetDDRConfig(0, ddr3config);

    CSL_BootCfgGetDDRConfig(12, &ddr3config);
    ddr3config |= 0x08000000;    // Set invert_clkout = 1
    CSL_BootCfgSetDDRConfig(12, ddr3config);

    CSL_BootCfgGetDDRConfig(0, &ddr3config);
    ddr3config |= 0xF;            // set dll_lock_diff to 15
    CSL_BootCfgSetDDRConfig(0, ddr3config);

    CSL_BootCfgGetDDRConfig(23, &ddr3config);
    ddr3config |= 0x00000200;    // See section 4.2.1, set for partial automatic levelling
    CSL_BootCfgSetDDRConfig(23, ddr3config);

    /**************** 3.3 Partial Automatic Leveling ********************/
    ddr3config = 0x0000005E;
    CSL_BootCfgSetDDRConfig(2, ddr3config);
    ddr3config = 0x0000005E;
    CSL_BootCfgSetDDRConfig(3, ddr3config);
    ddr3config = 0x0000005E;
    CSL_BootCfgSetDDRConfig(4, ddr3config);
    ddr3config = 0x00000051;
    CSL_BootCfgSetDDRConfig(5, ddr3config);
    ddr3config = 0x00000038;
    CSL_BootCfgSetDDRConfig(6, ddr3config);
    ddr3config = 0x0000003A;
    CSL_BootCfgSetDDRConfig(7, ddr3config);
    ddr3config = 0x00000024;
    CSL_BootCfgSetDDRConfig(8, ddr3config);
    ddr3config = 0x00000020;
    CSL_BootCfgSetDDRConfig(9, ddr3config);
    ddr3config = 0x00000044;
    CSL_BootCfgSetDDRConfig(10, ddr3config);

    ddr3config = 0x000000DD;
    CSL_BootCfgSetDDRConfig(14, ddr3config);
    ddr3config = 0x000000DD;
    CSL_BootCfgSetDDRConfig(15, ddr3config);
    ddr3config = 0x000000BE;
    CSL_BootCfgSetDDRConfig(16, ddr3config);
    ddr3config = 0x000000CA;
    CSL_BootCfgSetDDRConfig(17, ddr3config);
    ddr3config = 0x000000A9;
    CSL_BootCfgSetDDRConfig(18, ddr3config);
    ddr3config = 0x000000A7;
    CSL_BootCfgSetDDRConfig(19, ddr3config);
    ddr3config = 0x0000009E;
    CSL_BootCfgSetDDRConfig(20, ddr3config);
    ddr3config = 0x000000A1;
    CSL_BootCfgSetDDRConfig(21, ddr3config);
    ddr3config = 0x000000BA;
    CSL_BootCfgSetDDRConfig(22, ddr3config);

    /*Do a PHY reset. Toggle DDR_PHY_CTRL_1 bit 15 0->1->0 */
    CSL_EMIF4F_GetPhyControl(&ddrPhyCtrl, &ddrPHYReadLatency);
    ddrPhyCtrl &= ~(0x00008000);
    CSL_EMIF4F_SetPhyControl(ddrPhyCtrl, ddrPHYReadLatency);

    CSL_EMIF4F_GetPhyControl(&ddrPhyCtrl, &ddrPHYReadLatency);
    ddrPhyCtrl |= (0x00008000);
    CSL_EMIF4F_SetPhyControl(ddrPhyCtrl, ddrPHYReadLatency);

    CSL_EMIF4F_GetPhyControl(&ddrPhyCtrl, &ddrPHYReadLatency);
    ddrPhyCtrl &= ~(0x00008000);
    CSL_EMIF4F_SetPhyControl(ddrPhyCtrl, ddrPHYReadLatency);

    /***************** 3.4 Basic Controller and DRAM configuration ************/
    /* enable configuration */
    /*    hEmif->SDRAM_REF_CTRL    = 0x00005162; */
    CSL_EMIF4F_EnableInitRefresh();
    CSL_EMIF4F_SetRefreshRate(0x5162);

    /*    hEmif->SDRAM_TIM_1   = 0x1113783C; */
    sdram_tim1.t_wtr    = 4;
    sdram_tim1.t_rrd    = 7;
    sdram_tim1.t_rc     = 0x20;
    sdram_tim1.t_ras    = 0x17;
    sdram_tim1.t_wr     = 9;
    sdram_tim1.t_rcd    = 8;
    sdram_tim1.t_rp     = 8;
    CSL_EMIF4F_SetTiming1Config(&sdram_tim1);

    /*    hEmif->SDRAM_TIM_2   = 0x30717FE3; */
    sdram_tim2.t_cke    = 3;
    sdram_tim2.t_rtp    = 4;
    sdram_tim2.t_xsrd   = 0x1FF;
    sdram_tim2.t_xsnr   = 0x071;
    sdram_tim2.t_xp     = 3;
    sdram_tim2.t_odt    = 0;
    CSL_EMIF4F_SetTiming2Config(&sdram_tim2);

    /*    hEmif->SDRAM_TIM_3   = 0x559F86AF; */
    sdram_tim3.t_rasMax     = 0xF;
    sdram_tim3.t_rfc        = 0x06A;
    sdram_tim3.t_tdqsckmax  = 0;
    sdram_tim3.zq_zqcs      = 0x3F;
    sdram_tim3.t_ckesr      = 4;
    sdram_tim3.t_csta       = 0x5;
    sdram_tim3.t_pdll_ul    = 0x5;
    CSL_EMIF4F_SetTiming3Config(&sdram_tim3);

    /*    hEmif->DDR_PHY_CTRL_1   = 0x0010010F; */
    ddrPHYReadLatency       = 0x0F;
    ddrPhyCtrl              = (0x08008);
    CSL_EMIF4F_SetPhyControl(ddrPhyCtrl, ddrPHYReadLatency);

    /*    hEmif->ZQ_CONFIG        = 0x70073214; */
    zqcfg.zqRefInterval     = 0x3214;
    zqcfg.zqZQCLMult        = 3;
    zqcfg.zqZQCLInterval    = 1;
    zqcfg.zqSFEXITEn        = 1;
    zqcfg.zqDualCSEn        = 1;
    zqcfg.zqCS0En           = 1;
    zqcfg.zqCS1En           = 0;
    CSL_EMIF4F_SetOutputImpedanceConfig(&zqcfg);

    /*    hEmif->PWR_MGMT_CTRL    = 0x0; */
    pwrmgmtcfg.csTime       = 0;
    pwrmgmtcfg.srTime       = 0;
    pwrmgmtcfg.lpMode       = 0;
    pwrmgmtcfg.dpdEnable    = 0;
    pwrmgmtcfg.pdTime       = 0;
    CSL_EMIF4F_SetPowerMgmtConfig(&pwrmgmtcfg);

    /* New value with DYN_ODT disabled and SDRAM_DRIVE = RZQ/7 */
    /*    hEmif->SDRAM_CONFIG     = 0x63062A32; */
    CSL_EMIF4F_GetSDRAMConfig(&sdramcfg);
    sdramcfg.pageSize       = 2;
    sdramcfg.eBank          = 0;
    sdramcfg.iBank          = 3;
    sdramcfg.rowSize        = 4;
    sdramcfg.CASLatency     = 10;
    sdramcfg.narrowMode     = 0;
    sdramcfg.CASWriteLat    = 2;
    sdramcfg.SDRAMDrive     = 1;
    sdramcfg.disableDLL     = 0;
    sdramcfg.dynODT         = 0;
    sdramcfg.ddrDDQS        = 0;
    sdramcfg.ddrTerm        = 3;
    sdramcfg.iBankPos       = 0;
    sdramcfg.type           = 3;
    CSL_EMIF4F_SetSDRAMConfig(&sdramcfg);

    BOARD_delay(600); /*Wait 600us for HW init to complete*/

    /* Refresh rate = (7.8*666MHz] */
    /*    hEmif->SDRAM_REF_CTRL   = 0x00001450;     */
    CSL_EMIF4F_SetRefreshRate(0x00001450);

    /***************** 4.2.1 Partial automatic leveling ************/
    /*    hEmif->RDWR_LVL_RMP_CTRL      =  0x80000000; */
    CSL_EMIF4F_SetLevelingRampControlInfo(1, 0, 0, 0, 0);

    /* Trigger full leveling - This ignores read DQS leveling result and uses ratio forced value */
    /*    hEmif->RDWR_LVL_CTRL          =  0x80000000; */
    CSL_EMIF4F_SetLevelingControlInfo(1, 0, 0, 0, 0);

    /************************************************************
      Wait for min 1048576 DDR clock cycles for leveling to complete
      = 1048576 * 1.5ns = 1572864ns = 1.57ms.
      Actual time = ~10-15 ms
     **************************************************************/
    BOARD_delay(3000); //Wait 3ms for leveling to complete

    return status;
}

