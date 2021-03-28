/*
 * Copyright (c) 2010-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file  evmc66x.c
 *
 * \brief This contains C66x specific functions.
 *
 ******************************************************************************/

/************************
 * Include Files
 ************************/
#include "platform_internal.h"

/******************************************************************************
 *
 * Function:	pll_delay
 *
 * Description:	Delay function
 *
 * Parameters:	uint32_t ix - Delay value
 *
 * Return Value: None
 *
 ******************************************************************************/
static void pll_delay (uint32_t ix)
{
    while (ix--) {
        asm("   NOP");
    }
}

/******************************************************************************
 *
 * Function:	SetModulePllConfig
 *
 * Description:	Configures module specific PLL
 *
 * Parameters:	volatile uint32_t *pllCtl0 - PLL CTL0 register address
 *              volatile uint32_t *pllCtl1 - PLL CTL1 register address
 *              pll_init_data *data        - PLL configuration values
 *              char *name                 - Name of the module
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
static CSL_Status SetModulePllConfig (volatile uint32_t *pllCtl0,
                                      volatile uint32_t *pllCtl1,
                                      pll_init_data *data, char *name)
{
    uint32_t pllctl0val;
    uint32_t pllm  = data->pll_m;
    uint32_t plld  = data->pll_d;
    uint32_t clkod = data->pll_od;
    uint32_t temp;

    /* Unlock the Boot Config */
    CSL_BootCfgUnlockKicker();

	/* Usage Note 9: For optimal PLL operation, the ENSAT bit in the PLL control *
	 * registers should be set to 1.                                             *
	 * The PLL initialization sequence in the boot ROM sets this bit to 0 and    *
	 * could lead to non-optimal PLL operation. Software can set the bit to the  *
	 * optimal value of 1 after boot                                             *
	 * PLLCTL1_REG Bit map                                                    *
	 * |31...7   |6     |5 4       |3...0      |                                 *
	 * |Reserved |ENSAT |Reserved  |BWADJ[11:8]|                                 */

	*pllCtl1 |= 0x00000040;

	/* Put the PLL in Bypass Mode                                                *
	 * PLLCTL0_REG Bit map                                                     *
	 * |31...24    |23     |22...19       |18...6   |5...0 |                     *
	 * |BWADJ[7:0] |BYPASS |Reserved      |PLLM     |PLLD  |                     */

	*pllCtl0 |= 0x00800000; /* Set the Bit 23 */

	/* Program the necessary multipliers/dividers and BW adjustments             */
	/* Set the divider values */
	*pllCtl0 &= ~(MODULE_PLL_CLKD_MASK);
	*pllCtl0 |= (plld & MODULE_PLL_CLKD_MASK);

	/* Set the Multiplier values */
	*pllCtl0 &= ~(MODULE_PLL_CLKM_MASK);
	*pllCtl0 |= ((pllm << 6) & MODULE_PLL_CLKM_MASK);

	/* Set CLKOD value */
	*pllCtl0 &= ~(MODULE_PLL_CLKOD_MASK);
	*pllCtl0 |= ((clkod << 19) & MODULE_PLL_CLKOD_MASK);

	/* Set the BWADJ */
	temp = ((pllm + 1) >> 1) - 1;
	*pllCtl0 &= ~(0xFF000000);
	*pllCtl0 |= ((temp << 24) & 0xFF000000);
	*pllCtl1 &= ~(0x0000000F);
	*pllCtl1 |= ((temp >> 8) & 0x0000000F);

	 /* In PLL Controller, reset the PLL (bit 14), in PLLCTL1_REG register       */
	 *pllCtl1 |= 0x00004000;

	/* Wait for PLL to lock min 5 micro seconds */
	pll_delay(7000);

	/* In PLLCTL1_REG, write PLLRST = 0 to bring PLL out of reset */
	*pllCtl1 &= ~(0x00004000);

	/* Wait for PLL to lock min 50 micro seconds*/
	pll_delay(70000);

	/* Put the PLL in PLL Mode                                                   *
	 * PLLCTL0_REG Bit map                                                     *
	 * |31...24    |23     |22...19       |18...6   |5...0 |                     *
	 * |BWADJ[7:0] |BYPASS |Reserved      |PLLM     |PLLD  |                     */
	*pllCtl0 &= ~(0x00800000); /* Reset the Bit 23 */

	pllctl0val = *pllCtl0;

	IFPRINT(platform_write("%s PLL CTL0 Register Value = %d\n", name, *pllCtl0));
	IFPRINT(platform_write("%s PLL CTL1 Register Value = %d\n", name, *pllCtl1));

	/* Tells the multiplier value for the PLL */
	pllm = (((pllctl0val & MODULE_PLL_CLKM_MASK) >> 6) + 1);
	IFPRINT(platform_write("%s PLL programmable multiplier = %d\n", name, pllm));

	/* Tells the divider value for the PLL */
	plld = (((pllctl0val & MODULE_PLL_CLKD_MASK) >> 0) + 1);
	IFPRINT(platform_write("%s PLL programmable divider = %d\n", name, plld));

	/* Tells the output divider value for the PLL */
	clkod = (((pllctl0val & MODULE_PLL_CLKOD_MASK) >> 0) + 1);
	IFPRINT(platform_write("%s PLL output divider = %d\n", name, clkod));

	IFPRINT(platform_write("%s PLL Setup... Done.\n",name));

	return (CSL_SOK);
}

/******************************************************************************
 *
 * Function:	prog_pll1_values
 *
 * Description:	Configures PLL registers
 *
 * Parameters:	PllcHwSetup *hwSetup - PLL setup values
 *
 * Return Value: Status
 *
 ******************************************************************************/
int prog_pll1_values (PllcHwSetup *hwSetup)
{
    uint32_t temp;

    /* Check the Range for Multiplier and Divider here */
    if ((hwSetup->pllM > 4095) ||
        (hwSetup->preDiv > 63) ||
        (hwSetup->postDiv > 15))
    {
        return -1;
    }

    /* Set the PLL Multiplier, Divider, BWADJ                                    *
     * The PLLM[5:0] bits of the multiplier are controlled by the PLLM Register  *
     * inside the PLL Controller and the PLLM[12:6] bits are controlled by the   *
     * chip-level MAINPLLCTL0 Register.                                          *
     * PLL Control Register (PLLM)  Layout                                       *
     * |31...6   |5...0        |                                                 *
     * |Reserved |PLLM         |                                                 *
     *                                                                           *
     * Main PLL Control Register (MAINPLLCTL0)                                   *
     * |31...24   |23...19   |18...12    | 11...6   |5...0 |                     *
     * |BWADJ[7:0]| Reserved |PLLM[12:6] | Reserved | PLLD |                     */

    /* Set pll multiplier (13 bit field) */
    PLLM_REG     = (hwSetup->pllM & 0x0000003F); /* bits[5:0]  */
    temp          = (hwSetup->pllM & 0x1FC0) >> 6;       /* bits[12:6] */
    MAINPLLCTL0_REG  &=~(0x0007F000);                /*Clear PLLM field */
    MAINPLLCTL0_REG  |=((temp << 12) & 0x0007F000);

    /* Set the BWADJ     (12 bit field)                                          *
     * BWADJ[11:8] and BWADJ[7:0] are located in MAINPLLCTL0 and MAINPLLCTL1     *
     * registers. BWADJ[11:0] should be programmed to a value equal to half of   *
     * PLLM[12:0] value (round down if PLLM has an odd value)                    *
     * Example: If PLLM = 15, then BWADJ = 7                                     */
    temp = ((hwSetup->pllM + 1) >> 1) - 1; /* Divide the pllm by 2 */
    MAINPLLCTL0_REG &= ~(0xFF000000);  /* Clear the BWADJ Field */
    MAINPLLCTL0_REG |= ((temp << 24) & 0xFF000000);
    MAINPLLCTL1_REG &= ~(0x0000000F);   /* Clear the BWADJ field */
    MAINPLLCTL1_REG |= ((temp >> 8) & 0x0000000F);

    /* Set the pll divider (6 bit field)                                         *
     * PLLD[5:0] is located in MAINPLLCTL0                                       */
    MAINPLLCTL0_REG &= ~(0x0000003F);    /* Clear the Field */
    MAINPLLCTL0_REG |= (hwSetup->preDiv & 0x0000003F);

    /* Set the OUTPUT DIVIDE (4 bit field) in SECCTL */
    SECCTL_REG &= ~(0x00780000);     /* Clear the field       */
    SECCTL_REG |= ((hwSetup->postDiv << 19) & 0x00780000);

    IFPRINT(platform_write("Main PLL CTL0 Register Value = %d\n", MAINPLLCTL0_REG));
    IFPRINT(platform_write("Main PLL CTL1 Register Value = %d\n", MAINPLLCTL1_REG));

	temp  = (PLLM_REG & 0x0000003F);              /* bits[5:0] */
    temp |= (MAINPLLCTL0_REG & 0x0007F000) >> 6;  /* bits[12:6] */

    IFPRINT(platform_write("Main PLL Multiplier Value = %d\n", (temp + 1)));
    IFPRINT(platform_write("Main PLL Divider Value = %d\n",
                           ((MAINPLLCTL0_REG & 0x3F) + 1)));
    IFPRINT(platform_write("Main PLL Output Divider Value = %d\n",
                           (((SECCTL_REG & 0x00780000) >> 19) + 1)));

    return (0);
}

/******************************************************************************
 *
 * Function:	CorePllcHwSetup
 *
 * Description:	Configures Core PLL
 *
 * Parameters:	PllcHwSetup *hwSetup - PLL setup values
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status CorePllcHwSetup (PllcHwSetup *hwSetup)
{
    CSL_Status        status = CSL_SOK;
    volatile uint32_t i;
    volatile uint32_t loopCount;
    uint32_t          temp;

    /* Unlock the Boot Config */
    CSL_BootCfgUnlockKicker();


    /* Wait for Stabilization time (min 100 us)                                *
     * The below loop is good enough for the Gel file to get minimum of        *
     * 100 micro seconds, this should be appropriately modified for port       *
     * to a C function                                                         *
     * Minimum delay in GEL can be 1 milli seconds, so program to 1ms=1000us,  *
     * more than required, but should be Okay                                  */
    pll_delay(140056);

    /* If PLL previously configured in RBL, avoid di/dt supply excursion by    *
     * matching PLL output to RefClk rate                                      *
     * if RBL configures the PLL, the BYPASS bit would be set to '0'           */
    temp = SECCTL_REG &  0x00800000; /* Check the Bit 23 value */

    if (temp != 0) {
        /* PLL BYPASS is enabled, we assume if not in Bypass ENSAT = 1 */

        /* Usage Note 9: For optimal PLL operation, the ENSAT bit in the PLL control *
         * registers for the Main PLL should be set to 1.                            *
         * The PLL initialization sequence in the boot ROM sets this bit to 0 and    *
         * could lead to non-optimal PLL operation. Software can set the bit to the  *
         * optimal value of 1 after boot                                             *
         * Ref: http://www.ti.com/lit/er/sprz334b/sprz334b.pdf                       *
         * |31...7   |6     |5 4       |3...0      |                                 *
         * |Reserved |ENSAT |Reserved  |BWADJ[11:8]|                                 */

        MAINPLLCTL1_REG = MAINPLLCTL1_REG | 0x00000040;

        /* Clear PLLEN bit */
        PLLCTL_REG &= ~(1 << 0);

        /* Clear PLLENSRC bit */
        PLLCTL_REG &= ~(1 << 5);

        /* Wait for 4 RefClks   *
         * Assuming slowest Ref clock of 24MHz, min: 160 ns delay */
        pll_delay(225);

        /* Bypass needed to perform PWRDN cycle for C6670 and C6678                  *
         * Needed on all devices when in NOBOOT, I2C or SPI boot modes               *
         * Ref: Figure 4-2 of http://www.ti.com/lit/ug/sprugv2a/sprugv2a.pdf         *
         * PLL Secondary Control Register (SECCTL)  Layout                           *
         * |31...24  |23     |22...19       |18...0   |                              *
         * |Reserved |BYPASS |OUTPUT DIVIDE |Reserved |                              */
        SECCTL_REG |= 0x00800000; /* Set the Bit 23 */

        /* Advisory 8: Multiple PLLs May Not Lock After Power-on Reset Issue         *
         * In order to ensure proper PLL startup, the PLL power_down pin needs to be *
         * toggled. This is accomplished by toggling the PLLPWRDN bit in the PLLCTL  *
         * register. This needs to be done before the main PLL initialization        *
         * sequence                                                                  *
         * Ref: Figure 4-1 of http://www.ti.com/lit/ug/sprugv2a/sprugv2a.pdf         *
         * PLL Control Register (PLLCTL)  Layout                                     *
         * |31...4   |3      |2        |1        |0        |                         *
         * |Reserved |PLLRST |Reserved |PLLPWRDN |Reserved |                         */

        PLLCTL_REG |= 0x00000002; /*Power Down the PLL */

        /* Stay in a loop such that the bit is set for 5 us (minimum) and           *
         * then clear the bit.                                                      */

        pll_delay(14005);

        /* Power up the PLL */
        PLLCTL_REG &= ~(0x00000002);

    }
    else // PLL bypass disabled
    {
        /* Clear PLLEN bit */
        PLLCTL_REG &= ~(1 << 0);

        /* Clear PLLENSRC bit */
        PLLCTL_REG &= ~(1 << 5);

        /* Wait for 4 RefClks   *
         * Assuming slowest Ref clock of 24MHz, min: 160 ns delay */
        pll_delay(225);
	}

    /* Program the necessary multipliers/dividers and BW adjustments             */
    prog_pll1_values(hwSetup);

    /* go stat bit needs to be zero here    */
    /* Read the GOSTAT bit in PLLSTAT to make sure the bit returns to 0 to      *
     * indicate that the GO operation has completed                             */
    /* wait for the GOSTAT, but don't trap if lock is never read */
    for (i = 0; i < 100; i++) {
        pll_delay(300);
        if ( (PLLSTAT_REG & 0x00000001) == 0 ) {
            break;
        }
    }
    if (i == 100) {
        return CSL_ESYS_FAIL;
    }

    /* Place PLL in Reset, In PLLCTL, write PLLRST = 1 (PLL is reset)         */
    PLLCTL_REG |= 0x00000008;

    /* wait for the GOSTAT, but don't trap if lock is never read */
    for (i = 0; i < 100; i++) {
        pll_delay(300);
        if ( (PLLSTAT_REG & 0x00000001) == 0 ) {
            break;
        }
    }
    if (i == 100) {
        return (CSL_ESYS_FAIL);
    }

    /* Set PLL dividers if needed */
    PLLDIV2_REG = (0x8000) | (hwSetup->pllDiv2);
    PLLDIV3_REG = (0x8000) | (hwSetup->pllDiv3);

    /* Program ALNCTLn */
    /* Set bit 1 and 2 */
    PLLALNCTL_REG |= ((1 << 1) | (1 << 2));

    /* Set GOSET bit in PLLCMD to initiate the GO operation to change the divide *
     * values and align the SYSCLKs as programmed                                */
    PLLCMD_REG |= 0x00000001;

    /* wait for the phase adj */
    pll_delay(1000);

    /* Read the GOSTAT bit in PLLSTAT to make sure the bit returns to 0 to      *
     * indicate that the GO operation has completed                             */

    /* wait for the GOSTAT, but don't trap if lock is never read */
    for (i = 0; i < 100; i++) {
        pll_delay(300);
        if ( (PLLSTAT_REG & 0x00000001) == 0 ) {
            break;
        }
    }
    if (i == 100) {
        return (CSL_ESYS_FAIL);
    }

    /* Wait for a minimum of 7 us*/
    pll_delay (14006);

    /*In PLLCTL, write PLLRST = 0 to bring PLL out of reset */
    PLLCTL_REG &= ~(0x00000008);

    /* Wait for PLL Lock time (min 50 us) */
    pll_delay (140056 >> 1);
    SECCTL_REG &= ~(0x00800000); /* Release Bypass */

    /* Set the PLLEN */
    PLLCTL_REG |= (1 << 0);

    return (status);
}

/******************************************************************************
 *
 * Function:	CorePllcGetHwSetup
 *
 * Description:	Reads Core PLL configuration values
 *
 * Parameters:	PllcHwSetup *hwSetup - Structure to store PLL register values
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status CorePllcGetHwSetup (PllcHwSetup *hwSetup)
{
    hwSetup->divEnable  = 0;
	hwSetup->pllM       = ((MAINPLLCTL0_REG >> 12) & 0x7F) << 6;
    hwSetup->pllM      |= (PLLM_REG & 0x3F);
    hwSetup->preDiv     = (MAINPLLCTL0_REG & 0x3F);
    hwSetup->postDiv    = (SECCTL_REG & 0x00780000) >> 19;
    hwSetup->pllDiv2    = PLLDIV2_REG & 0xFF;
    hwSetup->pllDiv3    = PLLDIV3_REG & 0xFF;

    return (CSL_SOK);
}

/******************************************************************************
 *
 * Function:	SetNssPllConfig
 *
 * Description:	Configures NSS module PLL registers
 *
 * Parameters:	None
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status SetNssPllConfig (pll_init_data *data)
{
	CSL_Status status;

	status = SetModulePllConfig (&hBootCfg->NSS_PLL_CTL0,
								 &hBootCfg->NSS_PLL_CTL1,
                                 data, "NSS");

    return status;
}

/******************************************************************************
 *
 * Function:	SetDssPllConfig
 *
 * Description:	Configures DSS module PLL registers
 *
 * Parameters:	None
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status SetDssPllConfig (pll_init_data *data)
{
	CSL_Status status;

	status = SetModulePllConfig (&hBootCfg->DSS_PLL_CTL0,
								 &hBootCfg->DSS_PLL_CTL1,
                                 data, "DSS");

    return status;
}

/******************************************************************************
 *
 * Function:	SetIcssPllConfig
 *
 * Description:	Configures ICSS module PLL registers
 *
 * Parameters:	None
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status SetIcssPllConfig (pll_init_data *data)
{
	CSL_Status status;

	status = SetModulePllConfig (&hBootCfg->ICSS_PLL_CTL0,
								 &hBootCfg->ICSS_PLL_CTL1,
                                 data, "ICSS");

    return status;
}

/******************************************************************************
 *
 * Function:	SetUartPllConfig
 *
 * Description:	Configures UART module PLL registers
 *
 * Parameters:	None
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status SetUartPllConfig (pll_init_data *data)
{
	CSL_Status status;

	status = SetModulePllConfig (&hBootCfg->UART_PLL_CTL0,
								 &hBootCfg->UART_PLL_CTL1,
                                 data, "UART");

    return status;
}

/******************************************************************************
 *
 * Function:	SetDDR3PllConfig
 *
 * Description:	Configures DDR3 module PLL registers
 *
 * Parameters:	pll_init_data *data - PLL configuration values
 *
 * Return Value: CSL_Status
 *
 ******************************************************************************/
CSL_Status SetDDR3PllConfig(pll_init_data *data)
{
	CSL_Status status;

	status = SetModulePllConfig (&hBootCfg->DDR3A_PLL_CTL0,
								 &hBootCfg->DDR3A_PLL_CTL1,
                                 data, "DDR3");
    return (status);
}

/******************************************************************************
 *
 * Function:	configPllClkSelection
 *
 * Description:	Configures pin muxing and clock selection for different modules
 *
 * Parameters:	uint8_t sysClkSel - SYSCLKSEL pin status
 *
 * Return Value: None
 *
 ******************************************************************************/
void configPllClkSelection (uint8_t sysClkSel)
{
	/* Configure clock source for DDR
	   ‘0’ - Select SYSOSC_IN (Output of SYS_CLK_MUX)
       ‘1’ - Select DDRCLKP/N (external clock input on device pins)
     */
	CSL_FINS(hBootCfg->DDR_CLKCTL, BOOTCFG_DDR_CLKCTL_DDR_CLK_MUXSEL,
	         sysClkSel);

	/* Configure ICSS clock input to ICSS PLL
	   0 - Selects ICSS PLL output
       1 - Selects NSS PLL output
     */
	CSL_FINS(hBootCfg->ICSS_CLKCTL, BOOTCFG_ICSS_CLKCTL_ICSS0_PLL_MUXSEL, 0);
	CSL_FINS(hBootCfg->ICSS_CLKCTL, BOOTCFG_ICSS_CLKCTL_ICSS1_PLL_MUXSEL, 0);

	/* Configure USB clock input to UART PLL
	   0 - Selects UART PLL output
       1 - Selects NSS PLL output
	 */
	CSL_FINS(hBootCfg->USB0_CLKCTL, BOOTCFG_USB0_CLKCTL_USB0_CLKCORE_SEL, 0);
	CSL_FINS(hBootCfg->USB1_CLKCTL, BOOTCFG_USB1_CLKCTL_USB1_CLKCORE_SEL, 0);
}

/******************************************************************************
 *
 * Function:	enablePllObsClk
 *
 * Description:	Enables PLL observation clock
 *
 * Parameters:	None
 *
 * Return Value: None
 *
 ******************************************************************************/
void enablePllObsClk (PllObsClk obsClk)
{
	uint32_t bawosc_obsclk_en = 0x100;

	/* Reset the observation clock register value */
	hBootCfg->OBSCLKCTL = CSL_BOOTCFG_OBSCLKCTL_RESETVAL;

	/* Enable the observation clock */
	hBootCfg->OBSCLKCTL = (bawosc_obsclk_en << obsClk);

    /* Select the observation clock */
	hBootCfg->OBSCLKCTL |= obsClk;
}

/******************************************************************************
 *
 * Function:	enable_power_domain
 *
 * Description:	Enables the power for the given domain and its sub-module
 *
 * Parameters:	uint32_t  domain - Power domain ID
 *
 * Return Value: None
 *
 ******************************************************************************/
static void enable_power_domain(uint32_t  domain)
{
    CSL_PSC_enablePowerDomain (domain);

    /* Enable sub-modules in the power domain */
    switch(domain)
    {
		case CSL_PSC_PD_ALWAYSON:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_PMMC,
			                            PSC_MODSTATE_ENABLE);
		case CSL_PSC_PD_DEBUG:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_DEBUG,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_NSS:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_SA:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SA,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_TERANET:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_TERANET,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_SYS_COMP:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SYS_COMP,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_QSPI,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_MMC,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_GPMC,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_MLB,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_EHRPWM,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_EQEP,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_ECAP,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_MCASP,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_SR:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SR,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_MSMC:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_MSMC,
			                            PSC_MODSTATE_ENABLE);
		case CSL_PSC_PD_C66X_COREPAC_0:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_C66X_COREPAC_0,
			                            PSC_MODSTATE_ENABLE);
		case CSL_PSC_PD_ARM:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_ARM,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_ASRC:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_ASRC,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_ICSS:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_ICSS,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_DSS:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_DSS,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_PCIE:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_PCIE,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_USB:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_USB_0,
			                            PSC_MODSTATE_ENABLE);
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_USB_1,
			                            PSC_MODSTATE_ENABLE);
			break;
		case CSL_PSC_PD_DDR3:
			CSL_PSC_setModuleNextState (CSL_PSC_LPSC_DDR3,
			                            PSC_MODSTATE_ENABLE);
			break;
		default:
			break;
	}

    /* Start the state transition */
    CSL_PSC_startStateTransition (domain);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (domain));
}

/******************************************************************************
 *
 * Function:	PowerUpDomains
 *
 * Description:	Power up all the power domains
 *
 * Parameters:	None
 *
 * Return Value: None
 *
 ******************************************************************************/
void PowerUpDomains (void)
{
    /* Enable NSS power domain */
    enable_power_domain (CSL_PSC_PD_NSS);

    /* Enable SA power domain */
    enable_power_domain (CSL_PSC_PD_SA);

    /* Enable Teranet power domain */
    enable_power_domain (CSL_PSC_PD_TERANET);

    /* Enable SYS_COMP power domain */
    enable_power_domain (CSL_PSC_PD_SYS_COMP);

    /* Enable SR power domain */
    enable_power_domain (CSL_PSC_PD_SR);

    /* Enable MSMC power domain */
    enable_power_domain (CSL_PSC_PD_MSMC);

    /* Enable ASRC power domain */
    enable_power_domain (CSL_PSC_PD_ASRC);

    /* Enable ICSS power domain */
    enable_power_domain (CSL_PSC_PD_ICSS);

    /* Enable DSS power domain */
    enable_power_domain (CSL_PSC_PD_DSS);

    /* Enable power PCIE power domain */
    enable_power_domain (CSL_PSC_PD_PCIE);

    /* Enable power USB power domain */
    enable_power_domain (CSL_PSC_PD_USB);

    /* Enable power DDR3 power domain */
    enable_power_domain (CSL_PSC_PD_DDR3);
}

#define XMC_BASE_ADDR (CSL_XMC_CFG_REGS)
#define XMPAX2_L     (*(volatile unsigned int*)(XMC_BASE_ADDR + 0x00000010))
#define XMPAX2_H     (*(volatile unsigned int*)(XMC_BASE_ADDR + 0x00000014))
/*--------------------------------------------------------------*/
/* xmc_setup()                                                  */
/* XMC MPAX register setting to access DDR3 config space        */
/*--------------------------------------------------------------*/
void xmc_setup()
{
    /* mapping for ddr emif registers XMPAX*2 */
    XMPAX2_L =  0x121010FF;  /* replacement addr + perm */
    XMPAX2_H =  0x2101000B;    /* base addr + seg size (64KB)*/	//"1B"-->"B" by xj
}

static ddr3_emif_config ddr3_1600 = {
	0x62005662,    // sdcfg
	0x0A344C23,    // sdtim1
	0x00001CA5,    // sdtim2
	0x21ADFF32,    // sdtim3
	0x533F067F,    // sdtim4
	0x70073200,    // zqcfg
	0x00000C34,    // sdrfc
};

static ddr3_phy_config ddr3phy_1600 = {
	0xDC000,    // pllcr
	(IODDRM_MASK | ZCKSEL_MASK),    // pgcr1_mask
	((1 << 2) | (2 << 7) | (1 << 23)),    // pgcr1_val
	0x42C21590,    // ptr0
	0xD05612C0,    // ptr1
	0, /* not set in gel */    // ptr2
	0x06C30D40,    // ptr3
	0x6413880,     // ptr4
	(PDQ_MASK | MPRDQ_MASK | BYTEMASK_MASK),    // dcr_mask
	((1 << 10)),     // dcr_val
	0x550F6644,      // dtpr0
	0x328341E0,      // dtpr1
	0x50022A00,      // dtpr2
	0x00001430,      // mr0
	0x00000006,      // mr1
	0x00000018,      // mr2
	0x710035C7,      // dtcr
	0x00F03D09,      // pgcr2
	0x0001005D,      // zq0cr1
	0x0001005B,      // zq1cr1
	0x0001005B,      // zq2cr1
	0x00000033,      // pir_v1
	0x0000FF81,      // pir_v2
	0xB0000000       // ecc_ctl
};

void init_ddrphy(uint32_t base, ddr3_phy_config *phy_cfg, uint8_t eccEnable)
{
	uint32_t tmp;

	/* Reset DDR PHY */
	CSL_FINS(hBootCfg->DDR3A_PLL_CTL1,
	         BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST, (uint32_t)1);  //Assert DDR PHY reset after PLL enabled
	platform_delay(5000);
		CSL_FINS(hBootCfg->DDR3A_PLL_CTL1,
	         BOOTCFG_DDR3A_PLL_CTL1_DDR3A_PHY_RST, (uint32_t)0);  //Release DDR PHY reset

	while((read_reg(base + DDRPHY_PGSR0_OFFSET)
		 & 0x00000001) != 0x00000001);

    // Program FRQSEL in the PLL Control Register (address offset 0x018).
	write_reg(phy_cfg->pllcr, base + DDRPHY_PLLCR_OFFSET);
	platform_delay (DDR_CFG_DELAY);

    // Program WLSTEP=1, IODDRM=2(DDR3L), and ZCKSEL in the
    // PHY General Configuration Register 1 (address offset 0x00C).
	tmp = read_reg(base + DDRPHY_PGCR1_OFFSET);
	tmp &= ~(phy_cfg->pgcr1_mask);
	tmp |= phy_cfg->pgcr1_val;
        write_reg(tmp, DDRPHY_PGCR1_OFFSET);
	platform_delay (DDR_CFG_DELAY);

    // Program PHY Timing Parameters Register 0-4 (address offset 0x01C - 0x02C).
	write_reg(phy_cfg->ptr0,   base + DDRPHY_PTR0_OFFSET);
	write_reg(phy_cfg->ptr1,   base + DDRPHY_PTR1_OFFSET);
	// Maintain default values of Phy Timing Parameters Register 2 in PUB
	write_reg(phy_cfg->ptr3,  base + DDRPHY_PTR3_OFFSET);
	write_reg(phy_cfg->ptr4,  base + DDRPHY_PTR4_OFFSET);

	/* Program PDQ, MPRDQ, and BYTEMASK in the DRAM Configuration
	   Register (address offset 0x044). */
	// All other fields must be left at their default values.
	tmp =  read_reg(base + DDRPHY_DCR_OFFSET);
	tmp &= ~(phy_cfg->dcr_mask);
	tmp |= phy_cfg->dcr_val;
	write_reg(tmp, base + DDRPHY_DCR_OFFSET);
	platform_delay (DDR_CFG_DELAY);

    // Program DRAM Timing Parameters Register 0-2 (address offset 0x048 - 0x050).
	write_reg(phy_cfg->dtpr0, base + DDRPHY_DTPR0_OFFSET);
	write_reg(phy_cfg->dtpr1, base + DDRPHY_DTPR1_OFFSET);
	write_reg(phy_cfg->dtpr2, base + DDRPHY_DTPR2_OFFSET);

	// Program BL=0, CL, WR, and PD=1 in the Mode Register 0 (address offset 0x054).
	// All other fields must be left at their default values.
	write_reg(phy_cfg->mr0,   base + DDRPHY_MR0_OFFSET);

	// Program DIC, RTT, and TDQS in the Mode Register 1 (address offset 0x058).
	// All other fields must be left at their default values.
	write_reg(phy_cfg->mr1,   base + DDRPHY_MR1_OFFSET);

	// Program Mode Register 2 (address offset 0x05C).
	// Maintaining default values of Program Mode Register 2
	//write_reg(phy_cfg->mr2,   base + DDRPHY_MR2_OFFSET);

	write_reg(phy_cfg->dtcr,  base + DDRPHY_DTCR_OFFSET);  //Single-rank
	platform_delay (DDR_CFG_DELAY);

	/* Program tREFPRD=(5*tREFI/ddr_clk_period) in the PHY General
	   Configuration Register 2 (address offset 0x08C). */
	//All other fields must be left at their default values.
	write_reg(phy_cfg->pgcr2, base + DDRPHY_PGCR2_OFFSET);
	platform_delay (DDR_CFG_DELAY);

    //Set Impedence Register and DFIPU0=1
	write_reg(phy_cfg->zq0cr1, base + DDRPHY_ZQ0CR1_OFFSET);
	write_reg(phy_cfg->zq1cr1, base + DDRPHY_ZQ1CR1_OFFSET);
	write_reg(phy_cfg->zq2cr1, base + DDRPHY_ZQ2CR1_OFFSET);

	// Re-trigger PHY initialization in DDR PHY through the VBUSP interface.
	// Program 0x00000033 to the PHY Initialization Register (address offset 0x004)
	// to re-trigger PLL, ZCAL, and DCAL initialization.
	write_reg(phy_cfg->pir_v1, base + DDRPHY_PIR_OFFSET);
	platform_delay (DDR_CFG_DELAY);
	while((read_reg(base + DDRPHY_PGSR0_OFFSET) & 0x1) != 0x1);

	if(eccEnable == 0)
	{
		tmp = read_reg(base + DDRPHY_DATX8_4_OFFSET);
		tmp = tmp & 0xFFFFFFFE; //Disable ECC byte lane
		write_reg(tmp, base + DDRPHY_DATX8_4_OFFSET);
	}

	tmp = read_reg(base + DDRPHY_DATX8_5_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL5 byte lane - not present in K2G
	write_reg(tmp, base + DDRPHY_DATX8_5_OFFSET);

	tmp = read_reg(base + DDRPHY_DATX8_6_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL6 byte lane - not present in K2G
	write_reg(tmp, base + DDRPHY_DATX8_6_OFFSET);

	tmp = read_reg(base + DDRPHY_DATX8_7_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL7 byte lane - not present in K2G
	write_reg(tmp, base + DDRPHY_DATX8_7_OFFSET);

	tmp = read_reg(base + DDRPHY_DATX8_8_OFFSET);
	tmp = tmp & 0xFFFFFFFE; //Disable BL8 byte lane - not present in K2G
	write_reg(tmp, base + DDRPHY_DATX8_8_OFFSET);

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
	write_reg(phy_cfg->pir_v2, base + DDRPHY_PIR_OFFSET);
	platform_delay (DDR_CFG_DELAY);
	while((read_reg(base + DDRPHY_PGSR0_OFFSET) & 0x1) != 0x1);

	if(eccEnable == 1)
	{
		// Enable ECC
		write_reg(phy_cfg->ecc_ctl, base + DDR3_ECC_CTRL_OFFSET);
	}
}

void init_ddremif(uint32_t base, ddr3_emif_config *emif_cfg)
{
	write_reg(emif_cfg->sdcfg,  base + DDR3_SDCFG_OFFSET );
	write_reg(emif_cfg->sdtim1, base + DDR3_SDTIM1_OFFSET);
	write_reg(emif_cfg->sdtim2, base + DDR3_SDTIM2_OFFSET);
	write_reg(emif_cfg->sdtim3, base + DDR3_SDTIM3_OFFSET);
	write_reg(emif_cfg->sdtim4, base + DDR3_SDTIM4_OFFSET);
	write_reg(emif_cfg->zqcfg,  base + DDR3_ZQCFG_OFFSET );
	write_reg(emif_cfg->sdrfc,  base + DDR3_SDRFC_OFFSET );
}


/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
CSL_Status DDR3Init()
{
    CSL_Status status = CSL_SOK;

    CSL_BootCfgUnlockKicker();


    init_ddrphy(DDR3A_DDRPHYC, &ddr3phy_1600, 0);
    init_ddremif(DDR3A_EMIF_CTRL_BASE, &ddr3_1600);

    return (status);
}


