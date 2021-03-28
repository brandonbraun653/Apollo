/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016-2017
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
 */

/**
 * \file    PowerPRCM_deviceInit.c
 *
 * \brief   This file contains the BUS communication utility functions to
 *          communicate with the PMIC.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/PowerExtended.h>
#include <ti/csl/hw_types.h>
#include <PowerPRCM_deviceInit.h>
#include <ti/drv/pm/include/pmic/pmhal_tps65910.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Device Package read Shift */
#define POWERPRCM_PACKAGE_BIT_SHIFT (16U)

/** \brief Device Package read Mask */
#define POWERPRCM_PACKAGE_BIT_MASK  (0x30000U)

/** \brief Device Package read address */
#define POWERPRCM_PACKAGE_READ_ADDR \
    (SOC_CONTROL_REGS + CONTROL_EFUSE_SMA)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

pmlibSysConfigPowerStateParams_t inputTable[] =
{{PMHAL_PRCM_MOD_CLKDIV32K,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_CPGMAC0,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DCAN0,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DCAN1,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ELM,                    PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EMIF,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EPWMSS0,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EPWMSS1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_EPWMSS2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO1,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO2,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO3,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPMC,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C1,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C2,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ICSS,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_IEEE5000,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3,                     PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L3_INSTR,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4LS,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4_HS,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_LCDC,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MAILBOX0,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP0,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MCASP1,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMC0,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMC1,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMC2,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCMCRAM,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_OCPWP,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPI0,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPI1,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SPINLOCK,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER2,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
/* Disable Timer 3 for time being.  BOOTROM configures CLKSEL_TIMER3_CLK
 * to use TCLKIN as default.  TCLKIN is not hooked up on AM335x.  This causes
 * the TIMER3 registers at 0x48042000 to be inaccessible.  Need to call API
 * in app to change source of TIMER3 to be CLK_M_OSC (0x1) or CLK_32KHZ (0x2)
 {PMHAL_PRCM_MOD_TIMER3,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED}, */
 {PMHAL_PRCM_MOD_TIMER4,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER5,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
/* Disable Timer 6 for time being.  BOOTROM configures CLKSEL_TIMER3_CLK
 * to use TCLKIN as default.  TCLKIN is not hooked up on AM335x.  This causes
 * the TIMER6 registers at 0x48048000 to be inaccessible.  Need to call API
 * in app to change source of TIMER6 to be CLK_M_OSC (0x1) or CLK_32KHZ (0x2)
 {PMHAL_PRCM_MOD_TIMER6,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED}, */
 {PMHAL_PRCM_MOD_TIMER7,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPCC,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC0,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC1,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TPTC2,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART1,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART2,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART3,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART4,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART5,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_USB0,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GFX,                    PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU,                    PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MMU_CFG,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_ADC_TSC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_CONTROL,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_DEBUGSS,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_GPIO0,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_I2C0,                   PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_L4WKUP,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SMARTREFLEX0,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_SMARTREFLEX1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_TIMER1,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_UART0,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_WKUP_M3,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_CEFUSE,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_RTCSS,                  PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
 {PMHAL_PRCM_MOD_MPU,                    PMLIB_SYS_CONFIG_ALWAYS_ENABLED}
};

const uint32_t numTableEntries = sizeof (inputTable) /
                                 sizeof (pmlibSysConfigPowerStateParams_t);

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

uint32_t PRCM_GetSiliconRev();

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PRCM_ConfigAllVoltageRails(uint32_t level, uint32_t siliconPkgType)
{
    pmErrCode_t     retVal = PM_SUCCESS;
    pmhalVmOppId_t  oppId;
    const pmhalPmicOperations_t *pmicOps;
    uint32_t        siliconRev;

    /* Register the I2C functions with the PMIC Communication to ensure the
     * PMIC can be communicated with I2C driver specific to SBL
     */

    if (level > Power_NUMPERFLEVELS)
    {
        retVal = PM_FAIL;
    }
    else
    {
        oppId  = (pmhalVmOppId_t) level;
        retVal = PM_SUCCESS;
    }
    if (retVal == PM_SUCCESS)
    {
        /*
         * Get the pmic ops and register with the pmic interface.
         */
        pmicOps = PMHALTps65910GetPMICOps();

        retVal = PMHALPmicRegister(pmicOps);

        retVal = PMHALVMSetOpp(PMHAL_PRCM_VD_MPU, oppId, PM_TIMEOUT_INFINITE);

        /* Do not perform CORE AVS for ES1.0 Samples */
        siliconRev = PRCM_GetSiliconRev();
        if (0U != siliconRev)
        {
            /* VD_CORE can only support OPP_NOM */
            retVal |= PMHALVMSetOpp(PMHAL_PRCM_VD_CORE,
                                    PMHAL_VM_OPP_NOM,
                                    PM_TIMEOUT_INFINITE);
        }
    }
    return (int32_t) retVal;
}

int32_t PRCM_InitModulePowerState()
{
    int32_t retVal = PM_SUCCESS;

    pmlibSysConfigErrReturn_t resultReturn[sizeof (inputTable) /
                                           sizeof (
                                               pmlibSysConfigPowerStateParams_t)
    ];

    retVal = PMLIBSysConfigSetPowerState(inputTable, (uint32_t) numTableEntries,
                                         PM_TIMEOUT_INFINITE,
                                         resultReturn);

    return retVal;
}

int32_t PRCM_ConfigAllDPLL(uint32_t level, uint32_t siliconPkgType)
{
    pmhalPrcmDpllConfig_t *dpllPerCfg = 0U;
    pmhalPrcmDpllConfig_t *dpllMpuCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllDdrCfg  = 0U;
    pmhalPrcmDpllConfig_t *dpllDispCfg = 0U;
    pmhalPrcmDpllConfig_t *dpllCoreCfg = 0U;
    int32_t retVal   = 0;
    uint32_t sysFreq = 0;
    uint32_t opp;
    pmhalPrcmSysClkVal_t   sysClkFreq = PMHAL_PRCM_SYSCLK_24_MHZ;

    if (level > Power_PERFLEVEL_HIGH)
    {
        retVal = PM_FAIL;
    }
    else
    {
        opp    = level;
        retVal = PM_SUCCESS;
    }

    if (retVal == PM_SUCCESS)
    {
        sysFreq = PMHALCMGetSysClockFreq();

        if (sysFreq == 24000U)
        {
            sysClkFreq = PMHAL_PRCM_SYSCLK_24_MHZ;
        }
        else if (sysFreq == 19200U)
        {
            sysClkFreq = PMHAL_PRCM_SYSCLK_19_2_MHZ;
            /* PMHAL_PRCM_SYSCLK_19_2_MHZ is not tested in am335x */
        }
        else
        {
            /* To remove MISRA C error */
        }
        
        /*Configure prcm_dpll_core*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_CORE,
                        sysClkFreq,
                        opp,
                        siliconPkgType,
                        &dpllCoreCfg);

        /* Config DPLL_CORE*/
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_CORE,
                                    dpllCoreCfg,
                                    PM_TIMEOUT_INFINITE);

        /*Configure prcm_dpll_per*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_PER,
                        sysClkFreq,
                        opp,
                        siliconPkgType,
                        &dpllPerCfg);

        /* Config DPLL_PER */
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_PER,
                                    dpllPerCfg,
                                    PM_TIMEOUT_INFINITE);

        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_MPU,
                              sysClkFreq,
                              opp,
                              siliconPkgType,
                              &dpllMpuCfg);
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_MPU,
                                      dpllMpuCfg,
                                      PM_TIMEOUT_INFINITE);

        /*Configure prcm_dpll_disp*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_DISP,
                              sysClkFreq,
                              opp,
                              siliconPkgType,
                              &dpllDispCfg);
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_DISP,
                                      dpllDispCfg,
                                      PM_TIMEOUT_INFINITE);

        /*Configure prcm_dpll_ddr*/
        PRCM_getDpllStructure(PMHAL_PRCM_DPLL_DDR,
                              sysClkFreq,
                              opp,
                              siliconPkgType,
                              &dpllDdrCfg);
        retVal = PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_DDR,
                                      dpllDdrCfg,
                                      PM_TIMEOUT_INFINITE);
    }
    return retVal;
}

uint32_t PRCM_GetPackageType(void)
{
    uint32_t packageType =
        HW_RD_FIELD32(POWERPRCM_PACKAGE_READ_ADDR, POWERPRCM_PACKAGE_BIT);

    return packageType;
}

int32_t PRCM_ConfigFirmware(const void *pImage, uint32_t imageSize)
{
    int32_t retVal = PM_SUCCESS;
    int32_t status;

    if ((pImage == NULL) || (imageSize == 0))
    {
        retVal = PM_BADARGS;
    }

    if (retVal == PM_SUCCESS)
    {
        PMHALMpuM3IntRegister();
        PMHALMpuM3EventsClear();
        PMHALMpuM3LoadAndRun(pImage, imageSize);
        status = PMHALMpuM3WaitForM3TxEvent(FALSE);

        if (status == PM_SUCCESS)
        {
            PMHALMpuM3MailBoxInit();
        }
        else {
            retVal = PM_FAIL;
        }
    }

    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

uint32_t PRCM_GetSiliconRev()
{
    uint32_t siliconRev;

    siliconRev = HW_RD_REG32(
        SOC_CONTROL_REGS + CONTROL_DEVICE_ID);

    siliconRev = (siliconRev & 0xF0000000U) >> 28U;

    return (siliconRev);
}

inline void delayLoop(uint32_t delay)
{
    uint32_t i;
    for (i = 0; i < (1000U * delay); ++i)
    {}
}

