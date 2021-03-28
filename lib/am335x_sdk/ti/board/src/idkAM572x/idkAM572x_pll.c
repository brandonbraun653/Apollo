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

#include "board_cfg.h"
#include "board_internal.h"

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 dccEnable;
    /**< Divider(n) Value */
    Uint32 autoDpllMode;
    /**< Auto DPLL Mode, refer to enum #sbllibAutoDpllMode_t for values */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
    Uint32 divH21;
    /**< H21 Divider Value */
    Uint32 divH22;
    /**< H22 Divider Value */
    Uint32 divH23;
    /**< H23 Divider Value */
    Uint32 divH24;
    /**< H24 Divider Value */
} pllcParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a MPU DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 dccEnable;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} pllcMpuParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a peripheral DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
} pllcPerParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a core DPLL.
 */
typedef struct {
    Uint32 l3ClkSel;
    /**< L3 divider */
    Uint32 l4ClkSel;
    /**< L3 divider */
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
    Uint32 divH14;
    /**< H14 Divider Value */
    Uint32 divH22;
    /**< H22 Divider Value */
    Uint32 divH23;
    /**< H23 Divider Value */
    Uint32 divH24;
    /**< H24 Divider Value */
} pllcCoreParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         an ABE DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
} pllcAbeParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         an IVA DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} pllcIvaParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a GMAC DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
    Uint32 divH12;
    /**< H12 Divider Value */
    Uint32 divH13;
    /**< H13 Divider Value */
} pllcGmacParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a PCIE DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} pllcPcieParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DDR DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
    Uint32 divH11;
    /**< H11 Divider Value */
} pllcDdrParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a GPU DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
} pllcGpuParam;

/**
 *  \brief This structure defines the various Configuration Parameters for
 *         a DSP DPLL.
 */
typedef struct {
    Uint32 mult;
    /**< Multiplier(m) Value */
    Uint32 div;
    /**< Divider(n) Value */
    Uint32 divM2;
    /**< M2 Divider Value */
    Uint32 divM3;
    /**< M3 Divider Value */
} pllcDspParam;

void pllcMpuUnlock(void);

void pllcMpuLock(void);

void pllcMpuConfigure(pllcMpuParam *mpuPllcParam);

void pllcIvaUnlock(void);

void pllcIvaLock(void);

void pllcIvaConfigure(pllcIvaParam *ivaPllcParam);

void pllcCoreUnlock(void);

void pllcCoreLock(void);

void pllcCoreConfigure(pllcCoreParam *corePllcParam);

void pllcAbeUnlock(void);

void pllcAbeLock(void);

void pllcAbeConfigure(pllcAbeParam *abePllcParam);

void pllcDdrUnlock(void);

void pllcDdrLock(void);

void pllcDdrConfigure(pllcDdrParam *ddrPllcParam);

void pllcDspUnlock(void);

void pllcDspLock(void);

void pllcDspConfigure(pllcDspParam *dspPllcParam);

void pllcGmacUnlock(void);

void pllcGmacLock(void);

void pllcGmacConfigure(pllcGmacParam *gmacPllcParam);

void pllcGpuUnlock(void);

void pllcGpuLock(void);

void pllcGpuConfigure(pllcGpuParam *gpuPllcParam);

void pllcPcieUnlock(void);

void pllcPcieLock(void);

void pllcPcieConfigure(pllcPcieParam *pciePllcParam);

void pllcPerUnlock(void);

void pllcPerLock(void);

void pllcPerConfigure(pllcPerParam *perPllcParam);


/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_PLLInit(Uint32 opp)
{
    pllcMpuParam mpuPllcParam;
    pllcIvaParam ivaPllcParam;
    pllcCoreParam corePllcParam;
    pllcAbeParam abePllcParam;
    pllcDdrParam ddrPllcParam;
    pllcDspParam dspPllcParam;
    pllcGmacParam gmacPllcParam;
    pllcGpuParam gpuPllcParam;
    pllcPcieParam pciePllcParam;
    pllcPerParam perPllcParam;
	socId_t socId = Board_soc_detect();
    CSL_ckgen_prmRegs *hCkgenPrm =
        (CSL_ckgen_prmRegs *) CSL_MPU_CKGEN_PRM_REGS;

    if (OPP_HIGH == opp)
	{
		/* 1500MHz at 20MHz sys_clk */
		mpuPllcParam.mult = 600U;
		mpuPllcParam.div = 7U;
		mpuPllcParam.dccEnable = 1U;
		mpuPllcParam.divM2 = 1U;
	}
	else if (OPP_OD == opp)
	{
		/* 1176MHz at 20MHz sys_clk */
		mpuPllcParam.mult = 294U;
		mpuPllcParam.div = 4U;
		mpuPllcParam.dccEnable = 0U;
		mpuPllcParam.divM2 = 1U;
	}
	else 
	{
		/* Default to OPP_NOM */
		/* 1000MHz at 20MHz sys_clk */
		mpuPllcParam.mult = 500U;
		mpuPllcParam.div = 9U;
		mpuPllcParam.dccEnable = 0U;
		mpuPllcParam.divM2 = 1U;
	}

    pllcMpuUnlock();
    pllcMpuConfigure(&mpuPllcParam);
    pllcMpuLock();

    if (OPP_HIGH == opp)
	{
		/* 532MHz at 20MHz sys_clk */
		ivaPllcParam.mult = 266U;
		ivaPllcParam.div = 4U;
		ivaPllcParam.divM2 = 2U;
	}
	else if (OPP_OD == opp)
	{
		/* 430MHz at 20MHz sys_clk */
		ivaPllcParam.mult = 172U;
		ivaPllcParam.div = 3U;
		ivaPllcParam.divM2 = 2U;
	}
	else 
	{
		/* Default to OPP_NOM */
		/* 388.3MHz at 20MHz sys_clk */
		ivaPllcParam.mult = 233U;
		ivaPllcParam.div = 3U;
		ivaPllcParam.divM2 = 3U;
	}

    pllcIvaUnlock();
    pllcIvaConfigure(&ivaPllcParam);
    pllcIvaLock();

    perPllcParam.mult = 0x60U;
    perPllcParam.div = 4U;
    perPllcParam.divM2 = 4U;
    perPllcParam.divM3 = 1U;
    perPllcParam.divH11 = 3U;
    perPllcParam.divH12 = 4U;
    perPllcParam.divH13 = 4U;
    perPllcParam.divH14 = 2U;
    pllcPerUnlock();
    pllcPerConfigure(&perPllcParam);
    pllcPerLock();

    corePllcParam.l3ClkSel = 1U;
    corePllcParam.l4ClkSel = 1U;
    corePllcParam.mult = 0x10AU;
    corePllcParam.div = 0x4U;
    corePllcParam.divM2 = 2U;
    corePllcParam.divM3 = 1U;
    corePllcParam.divH12 = 4U;
    corePllcParam.divH13 = 0x3EU;
    corePllcParam.divH14 = 0x5U;
    corePllcParam.divH22 = 0x5U;
    corePllcParam.divH23 = 0x4U;
    corePllcParam.divH24 = 0x6U;
    pllcCoreUnlock();
    pllcCoreConfigure(&corePllcParam);
    pllcCoreLock();

    hCkgenPrm->CM_CLKSEL_ABE_PLL_REF_REG = 0x00000000U;

    abePllcParam.mult = 0x13U;
    abePllcParam.div = 0x1U;
    abePllcParam.divM2 = 1U;
    abePllcParam.divM3 = 1U;
    pllcAbeUnlock();
    pllcAbeConfigure(&abePllcParam);
    pllcAbeLock();

    gmacPllcParam.mult = 0xFAU;
    gmacPllcParam.div = 0x4U;
    gmacPllcParam.divM2 = 0x4U;
    gmacPllcParam.divM3 = 0xAU;
    gmacPllcParam.divH11 = 0x28U;
    gmacPllcParam.divH12 = 0x8U;
    gmacPllcParam.divH13 = 0xAU;
    pllcGmacUnlock();
    pllcGmacConfigure(&gmacPllcParam);
    pllcGmacLock();

    if(OPP_HIGH == opp)
	{
        /* 532MHz at 20MHz sys_clk */
        gpuPllcParam.mult = 266U;
		gpuPllcParam.div = 4U;
		gpuPllcParam.divM2 = 2U;
	}
    else if(OPP_OD == opp)
	{
        /* 500MHz at 20MHz sys_clk */
        gpuPllcParam.mult = 200U;
		gpuPllcParam.div = 3U;
		gpuPllcParam.divM2 = 2U;
	}
	else
	{
        /* Default to OPP_NOM */
        /* 425MHz at 20MHz sys_clk */
        gpuPllcParam.mult = 170U;
        gpuPllcParam.div = 3U;
        gpuPllcParam.divM2 = 2U;
	}
    pllcGpuUnlock();
    pllcGpuConfigure(&gpuPllcParam);
    pllcGpuLock();

    if(OPP_HIGH == opp)
	{
        /* 750MHz at 20MHz sys_clk */
        dspPllcParam.mult = 150U;
        dspPllcParam.div = 3U;
        dspPllcParam.divM2 = 1U;
        dspPllcParam.divM3 = 3U;
	}
	else if(OPP_OD == opp)
	{
        /* 650MHz at 20MHz sys_clk */
        dspPllcParam.mult = 130U;
        dspPllcParam.div = 3U;
        dspPllcParam.divM2 = 1U;
        dspPllcParam.divM3 = 3U;
	}
	else
	{
        /* Default to OPP_NOM */
        /* 600MHz at 20MHz sys_clk */
        dspPllcParam.mult = 150U;
        dspPllcParam.div = 4U;
        dspPllcParam.divM2 = 1U;
        dspPllcParam.divM3 = 3U;
	}
    pllcDspUnlock();
    pllcDspConfigure(&dspPllcParam);
    pllcDspLock();

    pciePllcParam.mult = 750U;
    pciePllcParam.div = 9U;
    pciePllcParam.divM2 = 15U;
    pllcPcieUnlock();
    pllcPcieConfigure(&pciePllcParam);
    pllcPcieLock();
	
	if(socId == SOC_ID_AM574x)
	{
		/* Set DDR frequency to 666MHz for AM574x */
		ddrPllcParam.mult = 0x14DU;
		ddrPllcParam.div = 0x4U;
		ddrPllcParam.divM2 = 0x2U;
		ddrPllcParam.divM3 = 0x1U;
		ddrPllcParam.divH11 = 0x8U;
	}
	else{
		/* Set DDR frequency to 532MHz for AM572x */
    ddrPllcParam.mult = 0x10AU;
    ddrPllcParam.div = 0x4U;
    ddrPllcParam.divM2 = 0x2U;
    ddrPllcParam.divM3 = 0x1U;
    ddrPllcParam.divH11 = 0x8U;
	}
		
    pllcDdrUnlock();
    pllcDdrConfigure(&ddrPllcParam);
    pllcDdrLock();
    return BOARD_SOK;
}

void CtrlLockMMR(void)
{
    CSL_control_coreRegs *ctrlCoreReg =
        (CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS;

    /* unlock MMR1 space for region 0x0100 to 0x079F */
    ctrlCoreReg->MMR_LOCK_1 = 438075716U;
    /* unlock MMR2 space for region 0x07A0 to 0x0D9F */
    ctrlCoreReg->MMR_LOCK_2 = 4260648240U;
    /* unlock MMR3 space for region 0x0DA0 to 0x0FFF */
    ctrlCoreReg->MMR_LOCK_3 = 451339040U;
    /* unlock MMR4 space for region 0x1000 to 0x13FF */
    ctrlCoreReg->MMR_LOCK_4 = 515838749U;
    /* unlock MMR5 space for region 0x1400 to 0x1FFF */
    ctrlCoreReg->MMR_LOCK_5 = 339706668U;
}

void pllcMpuUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcMpuLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_MPU_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcMpuConfigure(pllcMpuParam *mpuPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_DIV, mpuPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DPLL_MULT, mpuPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_MPU_REG_DCC_EN, mpuPllcParam->dccEnable);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_MPU_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_MPU_REG_DIVHS, mpuPllcParam->divM2);
}

void pllcIvaUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcIvaLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_IVA_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcIvaConfigure(pllcIvaParam *ivaPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_DIV, ivaPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_IVA_REG_DPLL_MULT, ivaPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_IVA_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_IVA_REG_DIVHS, ivaPllcParam->divM2);
}

void pllcCoreUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcCoreLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_CORE_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcCoreConfigure(pllcCoreParam *corePllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_CORE_REG_CLKSEL_L3, corePllcParam->l3ClkSel);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_DIV, corePllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_CORE_REG_DPLL_MULT, corePllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_CORE_REG_DIVHS, corePllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_CORE_REG_DIVHS, corePllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H12_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_CORE_REG_DIVHS, corePllcParam->divH12);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H13_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_CORE_REG_DIVHS, corePllcParam->divH13);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H14_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H14_DPLL_CORE_REG_DIVHS, corePllcParam->divH14);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H22_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H22_DPLL_CORE_REG_DIVHS, corePllcParam->divH22);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H23_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H23_DPLL_CORE_REG_DIVHS, corePllcParam->divH23);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H24_DPLL_CORE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H24_DPLL_CORE_REG_DIVHS, corePllcParam->divH24);
}

void pllcAbeUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcAbeLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_ABE_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcAbeConfigure(pllcAbeParam *abePllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_DIV, abePllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_ABE_REG_DPLL_MULT, abePllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_ABE_REG_DIVHS, abePllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_ABE_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_ABE_REG_DIVHS, abePllcParam->divM3);
}

void pllcDdrUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcDdrLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DDR_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcDdrConfigure(pllcDdrParam *ddrPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_DIV, ddrPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DDR_REG_DPLL_MULT, ddrPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DDR_REG_DIVHS, ddrPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DDR_REG_DIVHS, ddrPllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H11_DPLL_DDR_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_DDR_REG_DIVHS, ddrPllcParam->divH11);
}

void pllcDspUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcDspLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_DSP_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcDspConfigure(pllcDspParam *dspPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_DIV, dspPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_DSP_REG_DPLL_MULT, dspPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_DSP_REG_DIVHS, dspPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_DSP_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_DSP_REG_DIVHS, dspPllcParam->divM3);
}

void pllcGmacUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcGmacLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GMAC_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcGmacConfigure(pllcGmacParam *gmacPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_DIV, gmacPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GMAC_REG_DPLL_MULT, gmacPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divM2);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M3_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M3_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divM3);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H11_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H11_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH11);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H12_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H12_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH12);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_H13_DPLL_GMAC_REG,
        CKGEN_CM_CORE_AON_CM_DIV_H13_DPLL_GMAC_REG_DIVHS, gmacPllcParam->divH13);
}

void pllcGpuUnlock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcGpuLock(void)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKMODE_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_AON_CM_CLKMODE_DPLL_GPU_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcGpuConfigure(pllcGpuParam *gpuPllcParam)
{
    CSL_ckgen_cm_core_aonRegs *ckgenCmCoreAonReg =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;

    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_DIV, gpuPllcParam->div);
    CSL_FINS(ckgenCmCoreAonReg->CM_CLKSEL_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_CLKSEL_DPLL_GPU_REG_DPLL_MULT, gpuPllcParam->mult);
    CSL_FINS(ckgenCmCoreAonReg->CM_DIV_M2_DPLL_GPU_REG,
        CKGEN_CM_CORE_AON_CM_DIV_M2_DPLL_GPU_REG_DIVHS, gpuPllcParam->divM2);
}

void pllcPcieUnlock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKMODE_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcPcieLock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKMODE_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PCIE_REF_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcPcieConfigure(pllcPcieParam *pciePllcParam)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_DIV, pciePllcParam->div);
    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PCIE_REF_REG_DPLL_MULT, pciePllcParam->mult);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_M2_DPLL_PCIE_REF_REG,
        CKGEN_CM_CORE_CM_DIV_M2_DPLL_PCIE_REF_REG_DIVHS, pciePllcParam->divM2);
}

void pllcPerUnlock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKMODE_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LP_BYP_MODE);
}

void pllcPerLock(void)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKMODE_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN,
        CSL_CKGEN_CM_CORE_CM_CLKMODE_DPLL_PER_REG_DPLL_EN_DPLL_LOCK_MODE);
}

void pllcPerConfigure(pllcPerParam *perPllcParam)
{
    CSL_ckgen_cm_coreRegs *ckgenCmCoreReg =
        (CSL_ckgen_cm_coreRegs *) CSL_MPU_CKGEN_CM_CORE_REGS;

    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_DIV, perPllcParam->div);
    CSL_FINS(ckgenCmCoreReg->CM_CLKSEL_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_CLKSEL_DPLL_PER_REG_DPLL_MULT, perPllcParam->mult);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_M2_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_M2_DPLL_PER_REG_DIVHS, perPllcParam->divM2);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_M3_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_M3_DPLL_PER_REG_DIVHS, perPllcParam->divM3);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_H11_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_H11_DPLL_PER_REG_DIVHS, perPllcParam->divH11);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_H12_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_H12_DPLL_PER_REG_DIVHS, perPllcParam->divH12);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_H13_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_H13_DPLL_PER_REG_DIVHS, perPllcParam->divH13);
    CSL_FINS(ckgenCmCoreReg->CM_DIV_H14_DPLL_PER_REG,
        CKGEN_CM_CORE_CM_DIV_H14_DPLL_PER_REG_DIVHS, perPllcParam->divH14);
}
