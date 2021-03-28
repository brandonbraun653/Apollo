/******************************************************************************
 * Copyright (c) 2015 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_internal.h"
#include "keystone_pll.h"

static CSL_PllcHandle pllcReg = (CSL_PllcHandle)PLLCTL_REGS_BASE_ADDR;

static void pllc_delay(uint32_t loops)
{
    while (loops--) {
        asm("   NOP");
    }
}

static void wait_for_completion(const pllcConfig *data)
{
	int i;
	for (i = 0; i < 100; i++) {
		pllc_delay(450);
		if ((pllctl_reg_read(PLLSTAT) & PLLSTAT_GO) == 0)
			break;
	}
}


void init_pll(const pllcConfig *data)
{
	uint32_t tmp, tmp_ctl, pllm, plld, pllod, bwadj;

	pllm = data->pll_m - 1;
	plld = (data->pll_d - 1) & PLL_DIV_MASK;
	pllod = (data->pll_od - 1) & PLL_CLKOD_MASK;

	if (data->pll == CSL_PLL_SYS) {
		/* The requered delay before main PLL configuration */
		pllc_delay(210000);

		tmp = pllctl_reg_read(SECCTL);

		if (tmp & (PLLCTL_BYPASS)) {
			setbits32(keystonePllcRegs[data->pll].reg1,
				     PLLCTL_ENSAT);

			pllctl_reg_clrbits(PLLCTL, PLLCTL_PLLEN |
					   PLLCTL_PLLENSRC);
			pllc_delay(340);

			pllctl_reg_setbits(SECCTL, PLLCTL_BYPASS);
			pllctl_reg_setbits(PLLCTL, PLLCTL_PLLPWRDN);
			pllc_delay(21000);

			pllctl_reg_clrbits(PLLCTL, PLLCTL_PLLPWRDN);
		} else {
			pllctl_reg_clrbits(PLLCTL, PLLCTL_PLLEN |
					   PLLCTL_PLLENSRC);
			pllc_delay(340);
		}
	/* */
#ifdef SOC_K2G
		/* Reset PLL */
		pllctl_reg_setbits(PLLCTL, PLLCTL_PLLRST);
#endif

		pllctl_reg_write(PLLM, pllm & PLLM_MULT_LO_MASK);

		clrsetbits32(keystonePllcRegs[data->pll].reg0,
				PLLM_MULT_HI_SMASK, (pllm << 6));

		/* Set the BWADJ     (12 bit field)  */
		tmp_ctl = pllm >> 1; /* Divide the pllm by 2 */
		clrsetbits32(keystonePllcRegs[data->pll].reg0,
				PLL_BWADJ_LO_SMASK,
				(tmp_ctl << PLL_BWADJ_LO_SHIFT));
		clrsetbits32(keystonePllcRegs[data->pll].reg1,
				PLL_BWADJ_HI_MASK,
				(tmp_ctl >> 8));

		/*
		 * Set the pll divider (6 bit field) *
		 * PLLD[5:0] is located in MAINPLLCTL0
		 */
		clrsetbits32(keystonePllcRegs[data->pll].reg0,
				PLL_DIV_MASK, plld);

		/* Set the OUTPUT DIVIDE (4 bit field) in SECCTL */
		pllctl_reg_rmw(SECCTL, PLL_CLKOD_SMASK,
			       (pllod << PLL_CLKOD_SHIFT));
		wait_for_completion(data);

#ifndef SOC_K2G
		pllctl_reg_write(PLLDIV1_3[0], PLLM_RATIO_DIV1);
		pllctl_reg_write(PLLDIV1_3[1], PLLM_RATIO_DIV2);
		pllctl_reg_write(PLLDIV1_3[2], PLLM_RATIO_DIV3);
		pllctl_reg_write(PLLDIV4_16[0], PLLM_RATIO_DIV4);
		pllctl_reg_write(PLLDIV4_16[1], PLLM_RATIO_DIV5);

		pllctl_reg_setbits(ALNCTL, 0x1f);
#endif
		/*
		 * Set GOSET bit in PLLCMD to initiate the GO operation
		 * to change the divide
		 */
		pllctl_reg_setbits(PLLCMD, PLLSTAT_GO);
		pllc_delay(1500); /* wait for the phase adj */
		wait_for_completion(data);

#ifndef SOC_K2G
		/* Reset PLL */
		pllctl_reg_setbits(PLLCTL, PLLCTL_PLLRST);
#endif
		pllc_delay(21000);	/* Wait for a minimum of 7 us*/
		pllctl_reg_clrbits(PLLCTL, PLLCTL_PLLRST);
		pllc_delay(105000);	/* Wait for PLL Lock time (min 50 us) */

		pllctl_reg_clrbits(SECCTL, PLLCTL_BYPASS);

		pllctl_reg_setbits(PLLCTL, PLLCTL_PLLEN);

#if defined (SOC_K2H) || (SOC_K2K) || (SOC_K2L) || (SOC_K2G)
	} else if (data->pll == CSL_PLL_ARM) {
		bwadj = pllm >> 1;
		/*
		 * Refer Section 3.7 in PLL User Guide http://www.ti.com/lit/ug/sprugv2i/sprugv2i.pdf
		 * 1. and 2. Set CHIPMISCCTL1[13] = 0 (enable glitchfree bypass)
		 * Applicable for all Keystone II devices.
		 */
		clrbits32(KS2_CHIP_MISC1, KS2_ARM_PLL_EN);
		
		/* 3 In PLLCTL1, write PLLCTL_ENSTAT = 1 (optimal PLL operation) */
		setbits32(keystonePllcRegs[data->pll].reg1 ,
			     PLL_PLLRST | PLLCTL_ENSAT);
		
		/* 4. Set PLLCTL0[BYPASS] =1 (enable bypass), */
		setbits32(keystonePllcRegs[data->pll].reg0,  PLLCTL_BYPASS);

		/*
		 * 5 Program PLLM and PLLD in PLLCTL0 register
		 * 6 Program BWADJ[7:0] in PLLCTL0 and BWADJ[11:8] in
		 * PLLCTL1 register. BWADJ value must be set
		 * to ((PLLM + 1) >> 1) â?? 1)
		 */
		tmp = ((bwadj & PLL_BWADJ_LO_MASK) << PLL_BWADJ_LO_SHIFT) |
			(pllm << 6) |
			(plld & PLL_DIV_MASK) |
			(pllod << PLL_CLKOD_SHIFT) | PLLCTL_BYPASS;
		HW_WR_REG32(keystonePllcRegs[data->pll].reg0, tmp);

		/* Set BWADJ[11:8] bits */
		tmp = HW_RD_REG32(keystonePllcRegs[data->pll].reg1);
		tmp &= ~(PLL_BWADJ_HI_MASK);
		tmp |= ((bwadj>>8) & PLL_BWADJ_HI_MASK);
		HW_WR_REG32(keystonePllcRegs[data->pll].reg1, tmp);
		
		/* 7. In PLLCTL1, write PLLRST = 1 (PLL reset is asserted) */
		setbits32(keystonePllcRegs[data->pll].reg1, PLL_PLLRST);
		
		/*
		 * 8 Wait for at least 5 us based on the reference
		 * clock (PLL reset time)
		 */
		pllc_delay(21000);	/* Wait for a minimum of 7 us*/

		/* 9 In PLLCTL1, write PLLRST = 0 (PLL reset is released) */
		clrbits32(keystonePllcRegs[data->pll].reg1, PLL_PLLRST);
		
		/*
		 * 10 Wait for at least 500 * REFCLK cycles * (PLLD + 1)
		 * (PLL lock time)
		 */
		pllc_delay(105000);
		
		/* 11 disable bypass */
		clrbits32(keystonePllcRegs[data->pll].reg0, PLLCTL_BYPASS);
		
		/*
		 * 12 Set CHIPMISCCTL1[13] = 1 (disable glitchfree bypass)
		 * only applicable for Kepler
		 */
		setbits32(KS2_CHIP_MISC1, KS2_ARM_PLL_EN);
#endif
	} else {
		setbits32(keystonePllcRegs[data->pll].reg1, PLLCTL_ENSAT);
		/*
		 * process keeps state of Bypass bit while programming
		 * all other DDR PLL settings
		 */
		tmp = HW_RD_REG32(keystonePllcRegs[data->pll].reg0);
		tmp &= PLLCTL_BYPASS;	/* clear everything except Bypass */
		setbits32(keystonePllcRegs[data->pll].reg0, PLLCTL_BYPASS);

		/*
		 * Set the BWADJ[7:0], PLLD[5:0] and PLLM to PLLCTL0,
		 * bypass disabled
		 */
		bwadj = pllm >> 1;
		tmp |= ((bwadj & PLL_BWADJ_LO_MASK) << PLL_BWADJ_LO_SHIFT) |
			(pllm << PLL_MULT_SHIFT) |
			(plld & PLL_DIV_MASK) |
			(pllod << PLL_CLKOD_SHIFT);
		HW_WR_REG32(keystonePllcRegs[data->pll].reg0, tmp);

		/* Set BWADJ[11:8] bits */
		tmp = HW_RD_REG32(keystonePllcRegs[data->pll].reg1);
		tmp &= ~(PLL_BWADJ_HI_MASK);
		tmp |= ((bwadj >> 8) & PLL_BWADJ_HI_MASK);

		HW_WR_REG32(keystonePllcRegs[data->pll].reg1, tmp);

		/* Reset bit: bit 14 for both DDR3 & PASS PLL */
		tmp = PLL_PLLRST;
		/* Set RESET bit = 1 */
		setbits32(keystonePllcRegs[data->pll].reg1, tmp);
		/* Wait for a minimum of 7 us*/
		pllc_delay(21000);
		/* Clear RESET bit */
		clrbits32(keystonePllcRegs[data->pll].reg1, tmp);
		pllc_delay(105000);

		/* clear BYPASS (Enable PLL Mode) */
		clrbits32(keystonePllcRegs[data->pll].reg0, PLLCTL_BYPASS);
		pllc_delay(21000);	/* Wait for a minimum of 7 us*/
#if !defined (SOC_C6657) && !defined (SOC_K2G)
		if (data->pll == CSL_PLL_PA)
		{
			setbits32(keystonePllcRegs[data->pll].reg1, PA_PLL_SEL);
			pllc_delay(21000);	/* Wait for a minimum of 7 us*/
		}
#endif
	}

	/*
	 * This is required to provide a delay between multiple
	 * consequent PPL configurations
	 */
	pllc_delay(210000);
}

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_PLLInit()
{
	uint32_t i;
	uint32_t numConfigs;

	numConfigs = Board_getNumPllcConfigs();
	for (i = 0; i < numConfigs; i++)
		init_pll(&pllcConfigs[i]);

    return BOARD_SOK;
}

