/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
#include <ti/drv/pm/include/pmic/pmhal_tps65917.h>
#include <ti/drv/pm/include/pmic/pmhal_lp8731.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

pmlibSysConfigPowerStateParams_t inputTable[] =
{
    {PMHAL_PRCM_MOD_CRC,                 PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_SMARTREFLEX_CORE,    PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_EFUSE_CTRL_CUST,     PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DSP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DSP2,                PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_DSS,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_EMIF1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#ifndef __TI_ARM_V7M4__
    {PMHAL_PRCM_MOD_EVE1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#endif
    {PMHAL_PRCM_MOD_CPGMAC,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_MCASP1,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_TIMER5,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TIMER6,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TIMER7,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TIMER8,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
#ifndef __TI_ARM_V7M4__
    {PMHAL_PRCM_MOD_IPU1,                PMLIB_SYS_CONFIG_AUTO_CG       },
#endif
    {PMHAL_PRCM_MOD_IEEE1500_2_OCP,      PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_CTRL_MODULE_BANDGAP, PMLIB_SYS_CONFIG_AUTO_CG},
    {PMHAL_PRCM_MOD_DLL_AGING,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_L3_INSTR,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_L3_MAIN_2,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_OCP_WP_NOC,          PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_GPMC,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_L3_MAIN_1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_MMU_EDMA,            PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_OCMC_RAM1,           PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TESOC,               PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_TPCC,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TPTC1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TPTC2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_L4_CFG,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_SPINLOCK,            PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_MAILBOX1,            PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_MAILBOX2,            PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_I2C1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_I2C2,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_L4_PER1,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DCC6,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DCC7,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_TIMER2,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TIMER3,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_TIMER4,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DCC5,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_ELM,                 PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_ESM,                 PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_MCSPI1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_MCSPI2,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_MCSPI3,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_MCSPI4,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_UART1,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_UART2,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_UART3,               PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_GPIO2,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_GPIO3,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_GPIO4,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_MMC4,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_DCAN2,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_L4_PER2,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_ADC,                 PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_PWMSS1,              PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_QSPI,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_L4_PER3,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DCC1,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_DCC2,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_DCC3,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_DCC4,                PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_VIP1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_ISS,                 PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DEBUG_LOGIC,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_COUNTER_32K,         PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_DCAN1,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_GPIO1,               PMLIB_SYS_CONFIG_DISABLED      },
    {PMHAL_PRCM_MOD_L4_WKUP,             PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_RTI1,                PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
    {PMHAL_PRCM_MOD_RTI2,                PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_RTI3,                PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_RTI4,                PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_RTI5,                PMLIB_SYS_CONFIG_AUTO_CG       },
    {PMHAL_PRCM_MOD_TIMER1,              PMLIB_SYS_CONFIG_ALWAYS_ENABLED},
};


const uint32_t numTableEntries = sizeof (inputTable) /
                                 sizeof (pmlibSysConfigPowerStateParams_t);

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function configures the source for DSP and EVE clocks
 *          based on the package type and opp.
 *
 * \param   oppId       Index giving the choice of Operating point.
 * \param   packageType Parameter indicates if this is a 15x15 or a 12x12
 *                      package.
 *
 * \return  status       Multiplexer configuration status.
 *                       PM_SUCCESS   : Multiplexer configured successfully
 *                       PM_FAIL      : Failed to configure multiplexer
 *
 */
int32_t PRCM_ConfigureDspEveMux(uint32_t oppId,
                                   uint32_t siliconPackageType);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PRCM_ConfigAllVoltageRails(uint32_t level, uint32_t siliconPkgType)
{
    pmErrCode_t     retVal = PM_SUCCESS;
    const pmhalPmicOperations_t *pmicOps;
    pmhalVmOppId_t opp;
    int32_t  vdId;

    /*
     * Get the pmic ops and register with the pmic interface.
     */
     /* 15x15 package */
    if (POWERPRCM_PACKAGE_TYPE_1 == siliconPkgType)
    {
        pmicOps = PMHALTps65917GetPMICOps();
    }
    else
    {
        /* NOTE : Additionally need to program PRCM for I2C2 if configuring more
         * voltage rails than CORE and DSPEVE.
         */
        pmicOps = PMHALLP8731GetPMICOps();
    }

    retVal = PMHALPmicRegister(pmicOps);
    /* Set the opp level passed by the app*/
    opp = (pmhalVmOppId_t)level;

    /* Set the voltage for PMHAL_PRCM_VD_CORE and PMHAL_PRCM_VD_DSPEVE. */
    for (vdId = (int32_t) PMHAL_PRCM_VD_MIN;
         vdId < (int32_t) PMHAL_PRCM_VD_COUNT;
         vdId++)
    {
        if(PMHAL_PRCM_VD_CORE == vdId)
        {
            /* VD CORE supports only OPP NOM*/
            opp = (pmhalVmOppId_t)Power_PERFLEVEL_NOM;
        }
        retVal += PMHALVMSetOpp((pmhalPrcmVdId_t) vdId,
                                 opp, PM_TIMEOUT_INFINITE);
        opp = (pmhalVmOppId_t)level;
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
    uint32_t oppId;
    pmhalPrcmDpllConfig_t *dpllParams = 0U;
    int32_t  retVal = PM_SUCCESS;
    pmhalPrcmSysClkVal_t sysClkFreq = PMHALCMGetSysClockFreqEnum();

    if (level > Power_PERFLEVEL_HIGH)
    {
        retVal = PM_FAIL;
    }
    else
    {
        oppId    = level;
        retVal = PM_SUCCESS;
    }

    /* Configure PRCM and Control Module registers before configuring DPLL. */
    retVal = PRCM_ConfigureDspEveMux(oppId, siliconPkgType);

    /* Configure DPLL CORE */
    retVal += PRCM_getDpllStructure(PMHAL_PRCM_DPLL_CORE,
                                     sysClkFreq,
                                     oppId,
                                     siliconPkgType,
                                     &dpllParams);

    /* L3 clock = CORE CLK /2, L4 clock = L3 clock /2 */
    PMHALCMDpllSetClockDivider(PMHAL_PRCM_DIV_L3_ICLK, (uint32_t) 2U);
    PMHALCMDpllSetClockDivider(PMHAL_PRCM_DIV_L4_ROOT_CLK, (uint32_t) 2U);

    retVal += PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_CORE,
                                   dpllParams,
                                   PM_TIMEOUT_INFINITE);

    /* Configure DPLL PER */
    retVal += PRCM_getDpllStructure(PMHAL_PRCM_DPLL_PER,
                                     sysClkFreq,
                                     oppId,
                                     siliconPkgType,
                                     &dpllParams);

    retVal += PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_PER,
                                   dpllParams,
                                   PM_TIMEOUT_INFINITE);

    /* Configure DPLL GMAC */
    retVal += PRCM_getDpllStructure(PMHAL_PRCM_DPLL_DSP_GMAC,
                                     sysClkFreq,
                                     oppId,
                                     siliconPkgType,
                                     &dpllParams);

    retVal += PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_DSP_GMAC,
                                   dpllParams,
                                   PM_TIMEOUT_INFINITE);
    if (PM_SUCCESS == retVal)
    {

        /* The EVE VID DSP DPLL sources the DSP clock only in OPP HIGH. Hence
        * configure this DPLL only when the OPP chosen is OPP_HIGH.
        */
        if (Power_PERFLEVEL_HIGH == oppId)
        {
            /* Configure DPLL EVE_VID_DSP */
            retVal += PRCM_getDpllStructure(PMHAL_PRCM_DPLL_EVE_VID_DSP,
                                            sysClkFreq,
                                            oppId,
                                            siliconPkgType,
                                            &dpllParams);

            retVal += PMHALCMDpllConfigure(PMHAL_PRCM_DPLL_EVE_VID_DSP,
                                        dpllParams,
                                        PM_TIMEOUT_INFINITE);
        }
    }
    return retVal;
}

uint32_t PRCM_GetPackageType(void)
{
    uint32_t packageType;

    packageType = HW_RD_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                           CTRL_CORE_BOOTSTRAP,
                           CTRL_CORE_BOOTSTRAP_SYSBOOT_7);
    return packageType;
}


int32_t PRCM_ConfigureDspEveMux(uint32_t oppId,
                                   uint32_t siliconPackageType)
{
    int32_t retVal = PM_SUCCESS;
    /* In case of 15X15 Silicon, DSP and EVE are sourced from DPLL GMAC.
     * Configure PRCM and Control Module registers before configuring DPLL.
     */
    if (POWERPRCM_PACKAGE_TYPE_1 == siliconPackageType)
    {
        /* Select DSP Clock Source */
        switch (oppId)
        {
            case Power_PERFLEVEL_NOM:
                retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
                                                 PMHAL_PRCM_DPLL_DSP_GMAC);
                break;
            case Power_PERFLEVEL_OD:
                retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
                                                 PMHAL_PRCM_DPLL_CORE);
                break;
            case Power_PERFLEVEL_HIGH:
                retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
                                                 PMHAL_PRCM_DPLL_EVE_VID_DSP);
                break;
            default:
                retVal = PM_FAIL;
                break;
        }
        /* Select EVE Clock Source */
        retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_EVE_GCLK_MUX,
                                         PMHAL_PRCM_DPLL_DSP_GMAC);
        retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_EVE_CLK_MUX,
                                         PMHAL_PRCM_MUX_EVE_GCLK_MUX);
    }
    else
    {
        /* Select DSP Clock Source */
        retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_DSP_GFCLK_MUX,
                                         PMHAL_PRCM_DPLL_CORE);

        /* Select EVE Clock Source */
        retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_EVE_GCLK_MUX,
                                         PMHAL_PRCM_DPLL_CORE);
        retVal += PMHALCMMuxParentSelect(PMHAL_PRCM_MUX_EVE_CLK_MUX,
                                         PMHAL_PRCM_MUX_EVE_GCLK_MUX);
    }
    return retVal;
}

