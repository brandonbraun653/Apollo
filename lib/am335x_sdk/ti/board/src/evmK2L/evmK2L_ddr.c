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
#define DDRPHY_DATX8_8_OFFSET  0x3C0

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

static const ddr3_emif_config ddr3_1600 = {
	0x6200CE62,
	0x166C9855,
	0x00001D4A,
	0x435DFF53,
	0x543F0CFF,
	0x70073200,
	0x00001869,
};

static const ddr3_phy_config ddr3phy_1600 = {
	0x1C000,
	(IODDRM_MASK | ZCKSEL_MASK | ZCKSEL_MASK),
	((1 << 2) | (1 << 7) | (1 << 23)),
	0x42C21590,
	0xD05612C0,
	0, /* not set in gel */
	0x0D861A80,
	0x0C827100,
	(PDQ_MASK | MPRDQ_MASK | BYTEMASK_MASK),
	((1 << 10)),
	0x9D5CBB66,
	0x12868300,
	0x5002D200,
	0x00001C70,
	0x00000006,
	0x00000018,
	0x710035C7,
	0x00F07A12,
	0x0001005D,
	0x0001005B,
	0x0001005B,
	0x00000033,
	0x0000FF81,
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

static bool init_ddrphy(uint32_t base, const ddr3_phy_config *phy_cfg)
{
	uint32_t tmp;
    uint32_t timeoutCnt = 5;

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
	HW_WR_REG32(base + DDRPHY_MR2_OFFSET, phy_cfg->mr2);

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

	HW_WR_REG32(base + DDRPHY_PIR_OFFSET, phy_cfg->pir_v2);
	BOARD_delay(DDR_CFG_DELAY);
	timeoutCnt = 5;
	while((HW_RD_REG32(base + DDRPHY_PGSR0_OFFSET) & 0x1) != 0x1) {
        BOARD_delay(DDR_CFG_DELAY);
        timeoutCnt--;
        if (timeoutCnt == 0)
            return false;
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
	xmc_add_emif_cfg_region();

    CSL_BootCfgUnlockKicker();

    if (init_ddrphy(CSL_DDR3_0_PHY_CFG_REGS, &ddr3phy_1600) == false)
        return BOARD_INIT_DDR_FAIL;
    init_ddremif((CSL_Emif4fHandle)CSL_DDR3_0_SLV_CFG_REGS, &ddr3_1600);

    return BOARD_SOK;
}

