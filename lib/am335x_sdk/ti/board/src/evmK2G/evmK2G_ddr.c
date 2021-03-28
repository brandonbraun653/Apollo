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
#include <ti/csl/csl_emif4f.h>
#include <ti/csl/hw_types.h>

#include "board_internal.h"
#include "board_utils.h"
extern int Board_getJTAGID(void);
extern int Board_getDEVSPEED(void);

/** \brief DDR configuration dealy in usec */
#define DDR_CFG_DELAY          200

/** \brief DDR PHY register offset */
#define DDRPHY_PIR_OFFSET      0x04
#define DDRPHY_PGCR0_OFFSET    0x08
#define DDRPHY_PGCR1_OFFSET    0x0C
#define DDRPHY_PGSR0_OFFSET    0x10
#define DDRPHY_PGSR1_OFFSET    0x14
#define DDRPHY_PLLCR_OFFSET    0x18
#define DDRPHY_PTR0_OFFSET     0x1C
#define DDRPHY_PTR1_OFFSET     0x20
#define DDRPHY_PTR2_OFFSET     0x24
#define DDRPHY_PTR3_OFFSET     0x28
#define DDRPHY_PTR4_OFFSET     0x2C
#define DDRPHY_DCR_OFFSET      0x44
#define DDRPHY_DTPR0_OFFSET    0x48
#define DDRPHY_DTPR1_OFFSET    0x4C
#define DDRPHY_DTPR2_OFFSET    0x50
#define DDRPHY_MR0_OFFSET      0x54
#define DDRPHY_MR1_OFFSET      0x58
#define DDRPHY_MR2_OFFSET      0x5C
#define DDRPHY_DTCR_OFFSET     0x68
#define DDRPHY_PGCR2_OFFSET    0x8C
#define DDRPHY_ZQ0CR1_OFFSET   0x184
#define DDRPHY_ZQ1CR1_OFFSET   0x194
#define DDRPHY_ZQ2CR1_OFFSET   0x1A4
#define DDRPHY_ZQ3CR1_OFFSET   0x1B4

#define DDRPHY_DATX8_4_OFFSET  0x2C0
#define DDRPHY_DATX8_5_OFFSET  0x300
#define DDRPHY_DATX8_6_OFFSET  0x340
#define DDRPHY_DATX8_7_OFFSET  0x380
#define DDRPHY_DATX8_8_OFFSET  0x3C0

#define DDR3_MIDR_OFFSET       0x00
#define DDR3_STATUS_OFFSET     0x04
#define DDR3_SDCFG_OFFSET      0x08
#define DDR3_SDRFC_OFFSET      0x10
#define DDR3_SDTIM1_OFFSET     0x18
#define DDR3_SDTIM2_OFFSET     0x1C
#define DDR3_SDTIM3_OFFSET     0x20
#define DDR3_SDTIM4_OFFSET     0x28
#define DDR3_PMCTL_OFFSET      0x38
#define DDR3_ZQCFG_OFFSET      0xC8
#define DDR3_TMPALRT_OFFSET    0xCC
#define DDR3_DDRPHYC_OFFSET    0xE4
#define DDR3_ECC_CTRL_OFFSET   0x110

#define IODDRM_MASK            0x00000180
#define ZCKSEL_MASK            0x01800000
#define CL_MASK				   0x00000072
#define WR_MASK				   0x00000E00
#define BL_MASK				   0x00000003
#define RRMODE_MASK            0x00040000
#define UDIMM_MASK             0x20000000
#define BYTEMASK_MASK          0x0000FC00
#define MPRDQ_MASK             0x00000080
#define PDQ_MASK               0x00000070
#define NOSRA_MASK             0x08000000
#define ECC_MASK               0x00000001


/**
 *  \brief This structure defines the various Configuration Parameters for
 *         DDR3 PHY.
 */
typedef struct ddr3_phy_config {
    uint32_t pllcr;
    uint32_t pgcr1_mask;
    uint32_t pgcr1_val;
    uint32_t ptr0;
    uint32_t ptr1;
    uint32_t ptr2;
    uint32_t ptr3;
    uint32_t ptr4;
    uint32_t dcr_mask;
    uint32_t dcr_val;
    uint32_t dtpr0;
    uint32_t dtpr1;
    uint32_t dtpr2;
    uint32_t mr0;
    uint32_t mr1;
    uint32_t mr2;
    uint32_t dtcr;
    uint32_t pgcr2;
    uint32_t zq0cr1;
    uint32_t zq1cr1;
    uint32_t zq2cr1;
    uint32_t pir_v1;
    uint32_t pir_v2;
    uint32_t ecc_ctl;
} ddr3_phy_config;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         EMIF4 controller.
 */
typedef struct ddr3_emif_config {
    uint32_t sdcfg;
    uint32_t sdtim1;
    uint32_t sdtim2;
    uint32_t sdtim3;
    uint32_t sdtim4;
    uint32_t zqcfg;
    uint32_t sdrfc;
} ddr3_emif_config;

static const ddr3_emif_config ddr3_800 = {
	0x62005662,
	0x0A385033,
	0x00001CA5,
	0x21ADFF32,
	0x533F067F,
	0x70073200,
	0x00000C34,
};

static const ddr3_phy_config ddr3phy_800 = {
	0xDC000,
	(IODDRM_MASK | ZCKSEL_MASK),
	((1 << 2) | (2 << 7) | (1 << 23)),
	0x42C21590,
	0xD05612C0,
	0, /* not set in gel */
	0x06C30D40,
	0x6413880,
	(PDQ_MASK | MPRDQ_MASK | BYTEMASK_MASK),
	(1 << 10),
	0x550F6644,
	0x328341E0,
	0x50022A00,
	0x00001430,
	0x00000006,
	0x00000000,
	0x710035C7,
	0x00F03D09,
	0x0001005D,
	0x0001005B,
	0x0001005B,
	0x00000033,
	0x00000F81,
	0xB0000000
};

static const ddr3_emif_config ddr3_1066 = {
	0x62005662,
	0x0E4C6843,
	0x00001CC6,
	0x323DFF32,
	0x533F08AF,
	0x70073200,
	0x00001044,
};

static const ddr3_phy_config ddr3phy_1066 = {
	0xDC000,
	(IODDRM_MASK | ZCKSEL_MASK),
	((1 << 2) | (2 << 7) | (1 << 23)),
	0x42C21590,
	0xD05612C0,
	0, /* not set in gel */
	0x0904111D,
	0x0859A072,
	(PDQ_MASK | MPRDQ_MASK | BYTEMASK_MASK),
	(1 << 10),
	0x6D147744,
	0x32845A80,
	0x50023600,
	0x00001830,
	0x00000006,
	0x00000008,
	0x710035C7,
	0x00F05159,
	0x0001005D,
	0x0001005B,
	0x0001005B,
	0x00000033,
	0x00000F81,
	0xB0000000
};

extern void BOARD_delay(uint32_t usecs);

static void xmc_add_emif_cfg_region()
{
    /* mapping for ddr emif registers XMPAX*2 */
    CSL_XMC_XMPAXL    mpaxl;
    CSL_XMC_XMPAXH    mpaxh;

    mpaxh.bAddr     = 0x21010;  /* Segment Base Address */
    mpaxh.segSize   = 0xB;      /* Segment size 4KB */

    mpaxl.rAddr     = 0x121010; /* Replacement Address */
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

static bool init_ddrphy(uint32_t base, const ddr3_phy_config *phy_cfg, uint32_t eccEnable)
{
	uint32_t tmp;
    uint32_t timeoutCnt = 5;

	/* Reset DDR PHY */
	CSL_FINS(hBootCfg->DDR3A_PLL_CTL1,
	         BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST, (uint32_t)1);  /* Assert DDR PHY reset after PLL enabled */
	BOARD_delay(DDR_CFG_DELAY);
	CSL_FINS(hBootCfg->DDR3A_PLL_CTL1,
	         BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST, (uint32_t)0);  /* Release DDR PHY reset */

	while((HW_RD_REG32(base + DDRPHY_PGSR0_OFFSET)
		 & 0x00000001) != 0x00000001) {
        BOARD_delay(DDR_CFG_DELAY);
        timeoutCnt--;
        if (timeoutCnt == 0)
            return false;
	}

	HW_WR_REG32(base + DDRPHY_PLLCR_OFFSET, phy_cfg->pllcr);
	BOARD_delay(DDR_CFG_DELAY);

	tmp = HW_RD_REG32(base + DDRPHY_PGCR1_OFFSET);
	tmp &= ~(phy_cfg->pgcr1_mask);
	tmp |= phy_cfg->pgcr1_val;
        HW_WR_REG32(base + DDRPHY_PGCR1_OFFSET, tmp);
	BOARD_delay(DDR_CFG_DELAY);

	HW_WR_REG32(base + DDRPHY_PTR0_OFFSET, phy_cfg->ptr0);
	HW_WR_REG32(base + DDRPHY_PTR1_OFFSET, phy_cfg->ptr1);
	HW_WR_REG32(base + DDRPHY_PTR3_OFFSET, phy_cfg->ptr3);
	HW_WR_REG32(base + DDRPHY_PTR4_OFFSET, phy_cfg->ptr4);

	tmp =  HW_RD_REG32(base + DDRPHY_DCR_OFFSET);
	tmp &= ~(phy_cfg->dcr_mask);
	tmp |= phy_cfg->dcr_val;
	HW_WR_REG32(base + DDRPHY_DCR_OFFSET, tmp);
	BOARD_delay(DDR_CFG_DELAY);

	HW_WR_REG32(base + DDRPHY_DTPR0_OFFSET, phy_cfg->dtpr0);
	HW_WR_REG32(base + DDRPHY_DTPR1_OFFSET, phy_cfg->dtpr1);
	HW_WR_REG32(base + DDRPHY_DTPR2_OFFSET, phy_cfg->dtpr2);

	HW_WR_REG32(base + DDRPHY_MR0_OFFSET, phy_cfg->mr0);
	HW_WR_REG32(base + DDRPHY_MR1_OFFSET, phy_cfg->mr1);
	//HW_WR_REG32(base + DDRPHY_MR2_OFFSET, phy_cfg->mr2);

	HW_WR_REG32(base + DDRPHY_DTCR_OFFSET, phy_cfg->dtcr);
	BOARD_delay(DDR_CFG_DELAY);
	HW_WR_REG32(base + DDRPHY_PGCR2_OFFSET, phy_cfg->pgcr2);
	BOARD_delay(DDR_CFG_DELAY);

	HW_WR_REG32(base + DDRPHY_ZQ0CR1_OFFSET, phy_cfg->zq0cr1);
	HW_WR_REG32(base + DDRPHY_ZQ1CR1_OFFSET, phy_cfg->zq1cr1);
	HW_WR_REG32(base + DDRPHY_ZQ2CR1_OFFSET, phy_cfg->zq2cr1);

	HW_WR_REG32(base + DDRPHY_PIR_OFFSET, phy_cfg->pir_v1);
	BOARD_delay(DDR_CFG_DELAY);

	timeoutCnt = 5;
	while((HW_RD_REG32(base + DDRPHY_PGSR0_OFFSET) & 0x1) != 0x1) {
        BOARD_delay(DDR_CFG_DELAY);
        timeoutCnt--;
        if (timeoutCnt == 0)
            return false;
	}

	if (eccEnable == 0)
	{
		tmp = HW_RD_REG32(base + DDRPHY_DATX8_4_OFFSET);
		tmp = tmp & 0xFFFFFFFE; //Disable ECC byte lane
		HW_WR_REG32(base + DDRPHY_DATX8_4_OFFSET, tmp);
	}

	tmp = HW_RD_REG32(base + DDRPHY_DATX8_5_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL5 byte lane - not present in K2G
	HW_WR_REG32(base + DDRPHY_DATX8_5_OFFSET, tmp);

	tmp = HW_RD_REG32(base + DDRPHY_DATX8_6_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL6 byte lane - not present in K2G
	HW_WR_REG32(base + DDRPHY_DATX8_6_OFFSET, tmp);

	tmp = HW_RD_REG32(base + DDRPHY_DATX8_7_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL7 byte lane - not present in K2G
	HW_WR_REG32(base + DDRPHY_DATX8_7_OFFSET, tmp);

	tmp = HW_RD_REG32(base + DDRPHY_DATX8_8_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL8 byte lane - not present in K2G
	HW_WR_REG32(base + DDRPHY_DATX8_8_OFFSET, tmp);

	/* Trigger DDR3 initialization and leveling/training in DDR PHY
	   through the VBUSP interface.
	 * If using a 16-bit wide DDR interface, program DXEN=0 in the DATX8 2-7
	   General Configuration Registers (address offsets 0x240, 0x280, 0x2C0,
	   0x300, 0x340, and 0x380) to disable the leveling/training
	   for the upper byte lanes.
	 * If using a 32-bit wide DDR interface, program DXEN=0 in the DATX8 4-7
	   General Configuration Registers (address offsets 0x2C0, 0x300, 0x340,
	   and 0x380) to disable the leveling/training for the upper byte lanes.
	 * If ECC is not required, program DXEN=0 in the DATX8 8 General
	   Configuration Register (address offset 0x3C0) to disable the
	   leveling/training for the ECC byte lane.
	 * NOTE: Setup supports 64-bit by default,  ECC enable by default.
	 */

	HW_WR_REG32(base + DDRPHY_PIR_OFFSET, phy_cfg->pir_v2);
	BOARD_delay(DDR_CFG_DELAY);
	timeoutCnt = 50;
	while((HW_RD_REG32(base + DDRPHY_PGSR0_OFFSET) & 0x1) != 0x1) {
        BOARD_delay(DDR_CFG_DELAY);
        timeoutCnt--;
        if (timeoutCnt == 0)
            return false;
	}

	if(eccEnable == 1)
	{
		/* Enable ECC */
		HW_WR_REG32(base + DDR3_ECC_CTRL_OFFSET, phy_cfg->ecc_ctl);
	}

    return true;
}

static void init_ddremif(CSL_Emif4fHandle hEmif4, const ddr3_emif_config *emif_cfg)
{
    hEmif4->SDRAM_CONFIG   = emif_cfg->sdcfg;
    hEmif4->SDRAM_TIM_1    = emif_cfg->sdtim1;
    hEmif4->SDRAM_TIM_2    = emif_cfg->sdtim2;
    hEmif4->SDRAM_TIM_3    = emif_cfg->sdtim3;
    hEmif4->SDRAM_TIM_4    = emif_cfg->sdtim4;
    hEmif4->ZQ_CONFIG      = emif_cfg->zqcfg;
    hEmif4->SDRAM_REF_CTRL = emif_cfg->sdrfc;
}

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_DDR3Init()
{
	uint32_t var;
	xmc_add_emif_cfg_region();

    CSL_BootCfgUnlockKicker();
    var= Board_getDEVSPEED();

	if(var == DEVSPEED1G)
    {
		if (init_ddrphy(CSL_DDR_0_PHY_CFG_REGS, &ddr3phy_1066, 0) == false)
			return BOARD_INIT_DDR_FAIL;
		init_ddremif((CSL_Emif4fHandle)CSL_DDR3_0_SLV_CFG_REGS, &ddr3_1066);
	}
	else
    {
		if (init_ddrphy(CSL_DDR_0_PHY_CFG_REGS, &ddr3phy_800, 0) == false)
			return BOARD_INIT_DDR_FAIL;
		init_ddremif((CSL_Emif4fHandle)CSL_DDR3_0_SLV_CFG_REGS, &ddr3_800);
	}
	

    return BOARD_SOK;
}

