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
 *  \file      hw_pmhal_data.c
 *
 *  \brief     This file contains macros and data-structures pertaining to
 *              StarterWare PMHAL_PRCM implementation.
 *
 *  \warning   This file is auto generated. So avoid manual changes.
 *              If manual changes are required the implications of the
 *              change in this and other auto generated files has to be
 *              completely understood.
 */

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include "stdint.h"
#if  ((!defined (__cplusplus)) && !(defined (_TMS320C6X)))
#include "stdbool.h"
#endif
#include "stdio.h"
#include "hw_pmhal_clocktree_data.h"
#include "hw_pmhal_data.h"
#include <ti/csl/soc.h>

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */
/**
 *  \brief Structure defining Physical memory List of PMHAL_PRCM_PD_GFX
 */
pmhalPrcmPhyMemBankId_t         PMHAL_PRCM_PD_GFX_phyMemIdList[] =
{
    PMHAL_PRCM_PHY_BANK_GFX_MEM
};

/**
 *  \brief Structure defining Physical memory List of PMHAL_PRCM_PD_MPU
 */
pmhalPrcmPhyMemBankId_t         PMHAL_PRCM_PD_MPU_phyMemIdList[] =
{
    PMHAL_PRCM_PHY_BANK_MPU_L1,
    PMHAL_PRCM_PHY_BANK_MPU_L2,
    PMHAL_PRCM_PHY_BANK_MPU_RAM
};

/**
 *  \brief Structure defining Physical memory List of PMHAL_PRCM_PD_PER
 */
pmhalPrcmPhyMemBankId_t         PMHAL_PRCM_PD_PER_phyMemIdList[] =
{
    PMHAL_PRCM_PHY_BANK_PER_MEM,
    PMHAL_PRCM_PHY_BANK_ICSS_MEM,
    PMHAL_PRCM_PHY_BANK_RAM1_MEM,
    PMHAL_PRCM_PHY_BANK_RAM2_MEM
};

/**
 *  \brief Structure defining Physical memory List of PMHAL_PRCM_PD_WKUP
 */
pmhalPrcmPhyMemBankId_t         PMHAL_PRCM_PD_WKUP_phyMemIdList[] =
{
    PMHAL_PRCM_PHY_BANK_DEBUGSS_MEM
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_CUSTEFUSE
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_CUSTEFUSE_resetIdList[] =
{
    PMHAL_PRCM_RG_CUST_EFUSE_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_GFX
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_GFX_resetIdList[] =
{
    PMHAL_PRCM_RG_GFX_DOM_RST,
    PMHAL_PRCM_RG_GFX_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_MPU
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_MPU_resetIdList[] =
{
    PMHAL_PRCM_RG_MPU_AO_RST,
    PMHAL_PRCM_RG_MPU_PWRON_RST,
    PMHAL_PRCM_RG_MPU_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_PER
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_PER_resetIdList[] =
{
    PMHAL_PRCM_RG_DLL_RST,
    PMHAL_PRCM_RG_EMIF_DDR_PHY_PWRON_RST,
    PMHAL_PRCM_RG_ICSS_RST,
    PMHAL_PRCM_RG_PER_DOM_RST,
    PMHAL_PRCM_RG_USB_POR_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_RTC
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_RTC_resetIdList[] =
{
    PMHAL_PRCM_RG_RTC_DOM_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_STDEFUSE
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_STDEFUSE_resetIdList[] =
{
    PMHAL_PRCM_RG_STD_EFUSE_PWRON_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_TAMPER
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_TAMPER_resetIdList[] =
{
    PMHAL_PRCM_RG_TAMPER_DOM_RST
};

/**
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_WKUP
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_WKUP_resetIdList[] =
{
    PMHAL_PRCM_RG_DPLL_RST,
    PMHAL_PRCM_RG_EMU_EARLY_PWRON_RST,
    PMHAL_PRCM_RG_EMU_PWRON_RST,
    PMHAL_PRCM_RG_EMU_RST,
    PMHAL_PRCM_RG_WKUP_DOM_RST,
    PMHAL_PRCM_RG_WKUP_M3_RST,
    PMHAL_PRCM_RG_WKUP_PWRON_RST,
    PMHAL_PRCM_RG_WKUP_SYS_PWRON_RST
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_CUSTEFUSE
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_CUSTEFUSE_clockDomainList[] =
{
    PMHAL_PRCM_CD_L4_CEFUSE
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_GFX
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_GFX_clockDomainList[] =
{
    PMHAL_PRCM_CD_GFX_L3
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_MPU
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_MPU_clockDomainList[] =
{
    PMHAL_PRCM_CD_MPU
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_PER
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_PER_clockDomainList[] =
{
    PMHAL_PRCM_CD_L4LS,
    PMHAL_PRCM_CD_L3S,
    PMHAL_PRCM_CD_L3,
    PMHAL_PRCM_CD_OCPWP_L3,
    PMHAL_PRCM_CD_ICSS_OCP,
    PMHAL_PRCM_CD_CPSW_125MHZ,
    PMHAL_PRCM_CD_LCD_L3,
    PMHAL_PRCM_CD_EMIF_L3,
    PMHAL_PRCM_CD_DSS_L3
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_RTC
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_RTC_clockDomainList[] =
{
    PMHAL_PRCM_CD_L4_RTC
};

/**
 *  \brief structure defining Clock Domain List of PMHAL_PRCM_PD_WKUP
 */
pmhalPrcmCdId_t                 PMHAL_PRCM_PD_WKUP_clockDomainList[] =
{
    PMHAL_PRCM_CD_L4_WKUP,
    PMHAL_PRCM_CD_L4_WKUP_AON,
    PMHAL_PRCM_CD_L3_AON,
    PMHAL_PRCM_CD_L3S_TSC
};

/**
 *  \brief structure defining Power Domain Elements
 */
const pmhalPowerDomain_t        pmhalPowerDomainElems[] =
{
    {
        /* PMHAL_PRCM_PD_CUSTEFUSE */
        PMHAL_PRCM_VD_CORE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_ON_ACTIVE)),
        PMHAL_VALUE_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        0,
        VSIZE_TYPE(PMHAL_PRCM_PD_CUSTEFUSE_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_CUSTEFUSE_clockDomainList,
                   pmhalPrcmCdId_t),
        NULL,
        PMHAL_PRCM_PD_CUSTEFUSE_resetIdList,
        PMHAL_PRCM_PD_CUSTEFUSE_clockDomainList,
        (SOC_PRM_CEFUSE_REG + PRCM_PM_CEFUSE_PWRSTCTRL),
        (SOC_PRM_CEFUSE_REG + PRCM_PM_CEFUSE_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_GFX */
        PMHAL_PRCM_VD_CORE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_ON_ACTIVE)),
        PMHAL_VALUE_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        VSIZE_TYPE(PMHAL_PRCM_PD_GFX_phyMemIdList,
                   pmhalPrcmPhyMemBankId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_GFX_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_GFX_clockDomainList,
                   pmhalPrcmCdId_t),
        PMHAL_PRCM_PD_GFX_phyMemIdList,
        PMHAL_PRCM_PD_GFX_resetIdList,
        PMHAL_PRCM_PD_GFX_clockDomainList,
        (SOC_PRM_GFX_REG + PRCM_PRM_PM_GFX_PWRSTCTRL),
        (SOC_PRM_GFX_REG + PRCM_PRM_PM_GFX_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_MPU */
        PMHAL_PRCM_VD_MPU,
        PRCM_PM_MPU_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_LOGICRETSTATE_MASK,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_RETENTION) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_ON_ACTIVE)),
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_RET_STATUS_CSWR),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        VSIZE_TYPE(PMHAL_PRCM_PD_MPU_phyMemIdList,
                   pmhalPrcmPhyMemBankId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_MPU_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_MPU_clockDomainList,
                   pmhalPrcmCdId_t),
        PMHAL_PRCM_PD_MPU_phyMemIdList,
        PMHAL_PRCM_PD_MPU_resetIdList,
        PMHAL_PRCM_PD_MPU_clockDomainList,
        (SOC_PRM_MPU_REG + PRCM_PM_MPU_PWRSTCTRL),
        (SOC_PRM_MPU_REG + PRCM_PM_MPU_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_RTC */
        PMHAL_PRCM_VD_RTC,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        0,
        VSIZE_TYPE(PMHAL_PRCM_PD_RTC_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_RTC_clockDomainList,
                   pmhalPrcmCdId_t),
        NULL,
        PMHAL_PRCM_PD_RTC_resetIdList,
        PMHAL_PRCM_PD_RTC_clockDomainList,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_REG_NOTAPPLICABLE
    },
    {
        /* PMHAL_PRCM_PD_WKUP */
        PMHAL_PRCM_VD_CORE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_phyMemIdList,
                   pmhalPrcmPhyMemBankId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_clockDomainList,
                   pmhalPrcmCdId_t),
        PMHAL_PRCM_PD_WKUP_phyMemIdList,
        PMHAL_PRCM_PD_WKUP_resetIdList,
        PMHAL_PRCM_PD_WKUP_clockDomainList,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_REG_NOTAPPLICABLE
    },
    {
        /* PMHAL_PRCM_PD_PER */
        PMHAL_PRCM_VD_CORE,
        PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRCM_PM_PER_PWRSTCTRL_LOGICRETSTATE_MASK,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_RETENTION) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_ON_ACTIVE)),
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_RET_STATUS_CSWR),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        VSIZE_TYPE(PMHAL_PRCM_PD_PER_phyMemIdList,
                   pmhalPrcmPhyMemBankId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_PER_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_PER_clockDomainList,
                   pmhalPrcmCdId_t),
        PMHAL_PRCM_PD_PER_phyMemIdList,
        PMHAL_PRCM_PD_PER_resetIdList,
        PMHAL_PRCM_PD_PER_clockDomainList,
        (SOC_PRM_PER_REG + PRCM_PM_PER_PWRSTCTRL),
        (SOC_PRM_PER_REG + PRCM_PM_PER_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_STDEFUSE */
        PMHAL_PRCM_VD_CORE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        0,
        VSIZE_TYPE(PMHAL_PRCM_PD_STDEFUSE_resetIdList,
                   pmhalPrcmResetGroupId_t),
        0,
        NULL,
        PMHAL_PRCM_PD_STDEFUSE_resetIdList,
        NULL,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_REG_NOTAPPLICABLE
    },
    {
        /* PMHAL_PRCM_PD_TAMPER */
        PMHAL_PRCM_VD_TAMPER,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_MASK_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        0,
        VSIZE_TYPE(PMHAL_PRCM_PD_TAMPER_resetIdList,
                   pmhalPrcmResetGroupId_t),
        0,
        NULL,
        PMHAL_PRCM_PD_STDEFUSE_resetIdList,
        NULL,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_REG_NOTAPPLICABLE
    }
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_PER_ICSS_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_PER_ICSS_RST_rstCtrlRegBitField =
{
    (SOC_PRM_PER_REG + PRCM_RM_PER_RSTCTRL),
    PRCM_RM_PER_RSTCTRL_ICSS_LRST_SHIFT
};

/**
 *  \brief structure defining STATUS Register for PMHAL_PRCM_RG_PER_ICSS_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_PER_ICSS_RST_rstStRegBitField =
{
    (SOC_PRM_PER_REG + PRCM_RM_PER_RSTST),
    PRCM_RM_PER_RSTST_ICSS_LRST_SHIFT
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_WKUP_M3_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_WKUP_M3_RST_rstCtrlRegBitField =
{
    (SOC_PRM_WKUP_REG + PRCM_RM_WKUP_RSTCTRL),
    PRCM_RM_WKUP_RSTCTRL_M3_LRST_SHIFT
};

/**
 *  \brief structure defining STATUS Register for PMHAL_PRCM_RG_WKUP_M3_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_WKUP_M3_RST_rstStRegBitField =
{
    (SOC_PRM_WKUP_REG + PRCM_RM_WKUP_RSTST),
    PRCM_RM_WKUP_RSTST_M3_LRST_SHIFT
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_GFX_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_GFX_RST_rstCtrlRegBitField =
{
    (SOC_PRM_GFX_REG + PRCM_PRM_RM_GFX_RSTCTRL),
    PRCM_PRM_RM_GFX_RSTCTRL_RST_SHIFT
};

/**
 *  \brief structure defining STATUS Register for PMHAL_PRCM_RG_GFX_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_GFX_RST_rstStRegBitField =
{
    (SOC_PRM_GFX_REG + PRCM_PRM_RM_GFX_RSTST),
    PRCM_PRM_RM_GFX_RSTST_RST_SHIFT
};

/**
 *  \brief structure defining programmable Reset Domain Elements
 */
const pmhalReset_t              pmhalResetDomainElems[] =
{
    {   /* PMHAL_PRCM_RG_PER_ICSS_RST */
        &PMHAL_PRCM_RG_PER_ICSS_RST_rstCtrlRegBitField,
        &PMHAL_PRCM_RG_PER_ICSS_RST_rstStRegBitField,
        PMHAL_PRCM_MOD_ICSS, /* To Subsystem */
        PMHAL_PRCM_MOD_UNDEF /* To CPU */
    },
    {                         /* PMHAL_PRCM_RG_WKUP_M3_RST */
        &PMHAL_PRCM_RG_WKUP_M3_RST_rstCtrlRegBitField,
        &PMHAL_PRCM_RG_WKUP_M3_RST_rstStRegBitField,
        PMHAL_PRCM_MOD_WKUP_M3, /* To Subsystem */
        PMHAL_PRCM_MOD_UNDEF    /* To CPU */
    },
    {                         /* PMHAL_PRCM_RG_GFX_RST */
        &PMHAL_PRCM_RG_GFX_RST_rstCtrlRegBitField,
        &PMHAL_PRCM_RG_GFX_RST_rstStRegBitField,
        PMHAL_PRCM_MOD_GFX,  /* To Subsystem */
        PMHAL_PRCM_MOD_UNDEF /* To CPU */
    }
};

/**
 *  \brief structure defining Control Register for
 *         PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_WARM_RESET
 */
regBitFieldShift_t
    PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_WARM_RESET_rstctrlBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTCTRL),
    PRCM_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_SHIFT
};

/**
 *  \brief structure defining Control Register for
 *         PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET
 */
regBitFieldShift_t
    PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET_rstctrlBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTCTRL),
    PRCM_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_SHIFT
};

/**
 *  \brief structure defining Global Reset Domain Control elements
 */
const pmhalGlobalResetControl_t pmhalGlobalResetControlElems[] =
{
    {   /* PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET */
        &PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET_rstctrlBitField
    },
    {   /* PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_WARM_RESET */
        &PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_WARM_RESET_rstctrlBitField
    }
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_GLOBAL_COLD_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_GLOBAL_COLD_RST_rstStBitField
    =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_GLOBAL_COLD_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST
 */
regBitFieldShift_t
    PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_GLOBAL_WARM_SW_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST
 */
regBitFieldShift_t    PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_MPU_SECURITY_VIOL_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST
 */
regBitFieldShift_t
    PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_EXTERNAL_WARM_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_ICEPICK_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_ICEPICK_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_ICEPICK_RST_SHIFT
};

#if 0 /* WDT0 is not supported according to AM437x TRM and CTT */
/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_WDT0_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_WDT0_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_WDT0_RST_SHIFT
};
#endif

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_WDT1_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_WDT1_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REG + PRCM_PRM_RSTST),
    PRCM_PRM_RSTST_WDT1_RST_SHIFT
};

const pmhalGlobalResetStatus_t  pmhalGlobalResetStatusElems[
                                                PMHAL_PRCM_GLB_RG_COUNT] =
{
    {   /* PMHAL_PRCM_GLB_RG_GLOBAL_COLD_RST */
        &PMHAL_PRCM_GLB_RG_GLOBAL_COLD_RST_rstStBitField
    },
    {   /* PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST */
        &PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST_rstStBitField
    },
#if 0 /* WDT0 is not supported according to AM437x TRM and CTT */
    {   /* PMHAL_PRCM_GLB_RG_WDT0_RST */
        &PMHAL_PRCM_GLB_RG_WDT0_RST_rstStBitField
    },
#endif
    {   /* PMHAL_PRCM_GLB_RG_WDT1_RST */
        &PMHAL_PRCM_GLB_RG_WDT1_RST_rstStBitField
    },
    {   /* PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST */
        &PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST_rstStBitField
    },
    {   /* PMHAL_PRCM_GLB_RG_ICEPICK_RST */
        &PMHAL_PRCM_GLB_RG_ICEPICK_RST_rstStBitField
    },
    {   /* PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST */
        &PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST_rstStBitField
    }
};

/**
 *  \brief structure defining PMHAL_PRCM_CD_L4LS modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4LS_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    PMHAL_PRCM_MOD_DCAN0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    PMHAL_PRCM_MOD_DCAN1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_MOD_ELM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    PMHAL_PRCM_MOD_EMIF_FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    PMHAL_PRCM_MOD_EPWMSS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    PMHAL_PRCM_MOD_EPWMSS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    PMHAL_PRCM_MOD_EPWMSS2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    PMHAL_PRCM_MOD_EPWMSS3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    PMHAL_PRCM_MOD_EPWMSS4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    PMHAL_PRCM_MOD_EPWMSS5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ERMC
    PMHAL_PRCM_MOD_ERMC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_PRCM_MOD_GPIO1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_PRCM_MOD_GPIO2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_PRCM_MOD_GPIO3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_PRCM_MOD_GPIO4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    PMHAL_PRCM_MOD_GPIO5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
    PMHAL_PRCM_MOD_HDQ1W,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    PMHAL_PRCM_MOD_I2C1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    PMHAL_PRCM_MOD_I2C2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    PMHAL_PRCM_MOD_L4LS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    PMHAL_PRCM_MOD_MAILBOX0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_PRCM_MOD_MMC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_PRCM_MOD_MMC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    PMHAL_PRCM_MOD_PKA,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    PMHAL_PRCM_MOD_RNG,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
    PMHAL_PRCM_MOD_SPARE0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
    PMHAL_PRCM_MOD_SPARE1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    PMHAL_PRCM_MOD_SPI0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    PMHAL_PRCM_MOD_SPI1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    PMHAL_PRCM_MOD_SPI2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    PMHAL_PRCM_MOD_SPI3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    PMHAL_PRCM_MOD_SPI4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_MOD_SPINLOCK,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
    PMHAL_PRCM_MOD_TIMER10,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
    PMHAL_PRCM_MOD_TIMER11,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    PMHAL_PRCM_MOD_TIMER2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    PMHAL_PRCM_MOD_TIMER3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    PMHAL_PRCM_MOD_TIMER4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    PMHAL_PRCM_MOD_TIMER5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    PMHAL_PRCM_MOD_TIMER6,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    PMHAL_PRCM_MOD_TIMER7,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    PMHAL_PRCM_MOD_TIMER8,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
    PMHAL_PRCM_MOD_TIMER9,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0
    PMHAL_PRCM_MOD_USBPHYOCP2SCP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1
    PMHAL_PRCM_MOD_USBPHYOCP2SCP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
    PMHAL_PRCM_MOD_USIM0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
    PMHAL_PRCM_MOD_USIM1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L3S modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L3S_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    PMHAL_PRCM_MOD_GPMC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
    PMHAL_PRCM_MOD_IEEE5000,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    PMHAL_PRCM_MOD_MAG_CARD,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_PRCM_MOD_MCASP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_MOD_MCASP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_PRCM_MOD_MMC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_PRCM_MOD_QSPI,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
    PMHAL_PRCM_MOD_USB_OTG_SS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
    PMHAL_PRCM_MOD_USB_OTG_SS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    PMHAL_PRCM_MOD_AES0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
    PMHAL_PRCM_MOD_CRYPTODMA,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DDRPHY
    PMHAL_PRCM_MOD_DDRPHY,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    PMHAL_PRCM_MOD_DES,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
    PMHAL_PRCM_MOD_DLL,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
    PMHAL_PRCM_MOD_DLL_AGING,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    PMHAL_PRCM_MOD_L3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    PMHAL_PRCM_MOD_L3_INSTR,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    PMHAL_PRCM_MOD_L4FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    PMHAL_PRCM_MOD_L4_HS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    PMHAL_PRCM_MOD_MSTR_EXPS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    PMHAL_PRCM_MOD_OCMCRAM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
    PMHAL_PRCM_MOD_SHA0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
    PMHAL_PRCM_MOD_SLV_EXPS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    PMHAL_PRCM_MOD_TPCC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    PMHAL_PRCM_MOD_TPTC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    PMHAL_PRCM_MOD_TPTC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    PMHAL_PRCM_MOD_TPTC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    PMHAL_PRCM_MOD_VPFE0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    PMHAL_PRCM_MOD_VPFE1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_PER_OCPWP_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_PER_OCPWP_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
        PMHAL_PRCM_MOD_OCP_WP_NOC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_ICSS_OCP modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_ICSS_OCP_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    PMHAL_PRCM_MOD_ICSS
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_CPSW_125MHZ modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_CPSW_125MHZ_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    PMHAL_PRCM_MOD_CPGMAC0
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_LCD_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_LCD_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    PMHAL_PRCM_MOD_LCDC
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_EMIF_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_EMIF_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    PMHAL_PRCM_MOD_EMIF
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_DSS_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_DSS_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_PRCM_MOD_DSS
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4_WKUP modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4_WKUP_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    PMHAL_PRCM_MOD_CONTROL,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    PMHAL_PRCM_MOD_GPIO0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    PMHAL_PRCM_MOD_I2C0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    PMHAL_PRCM_MOD_SMARTREFLEX0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    PMHAL_PRCM_MOD_SMARTREFLEX1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    PMHAL_PRCM_MOD_TIMER0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    PMHAL_PRCM_MOD_TIMER1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    PMHAL_PRCM_MOD_UART0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    PMHAL_PRCM_MOD_WDT0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    PMHAL_PRCM_MOD_WDT1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L3_AON modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L3_AON_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    PMHAL_PRCM_MOD_DEBUGSS
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4_WKUP_AON modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4_WKUP_AON_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
        PMHAL_PRCM_MOD_CLKDIV32K,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    PMHAL_PRCM_MOD_L4WKUP,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    PMHAL_PRCM_MOD_SYNCTIMER,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
    PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
    PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    PMHAL_PRCM_MOD_WKUP_M3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L3S_TSC modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L3S_TSC_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_PRCM_MOD_ADC_TSC
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_MPU modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_MPU_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    PMHAL_PRCM_MOD_MPU
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4_RTC modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4_RTC_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    PMHAL_PRCM_MOD_RTCSS
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_GFX_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_GFX_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    PMHAL_PRCM_MOD_GFX,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4_CEFUSE modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4_CEFUSE_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    PMHAL_PRCM_MOD_CEFUSE
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
};

/**
 *  \brief Structure defining Clock Domain Elements
 */
const pmhalClkDomain_t          pmhalClockDomainElems[] =
{
    {   /* PMHAL_PRCM_CD_L4LS */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKSTCTRL),
        PMHAL_PRCM_CD_L4LS_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4LS_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L3S */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3S_CLKSTCTRL),
        PMHAL_PRCM_CD_L3S_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L3S_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L3 */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_CLKSTCTRL),
        PMHAL_PRCM_CD_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_PER_OCPWP_L3 */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_OCPWP_L3_CLKSTCTRL),
        PMHAL_PRCM_CD_PER_OCPWP_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_PER_OCPWP_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_ICSS_OCP */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_ICSS_CLKSTCTRL),
        PMHAL_PRCM_CD_ICSS_OCP_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_ICSS_OCP_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_CPSW_125MHZ */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_CPSW_CLKSTCTRL),
        PMHAL_PRCM_CD_CPSW_125MHZ_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_CPSW_125MHZ_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_LCD_L3 */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_LCDC_CLKSTCTRL),
        PMHAL_PRCM_CD_LCD_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_LCD_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_EMIF_L3 */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKSTCTRL),
        PMHAL_PRCM_CD_EMIF_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_EMIF_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_DSS_L3 */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REG + PRCM_CM_PER_DSS_CLKSTCTRL),
        PMHAL_PRCM_CD_DSS_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_DSS_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L4_WKUP */
        PMHAL_PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_CLKSTCTRL),
        PMHAL_PRCM_CD_L4_WKUP_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4_WKUP_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L3_AON */
        PMHAL_PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L3_AON_CLKSTCTRL),
        PMHAL_PRCM_CD_L3_AON_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L3_AON_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L4_WKUP_AON */
        PMHAL_PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L4_WKUP_AON_CLKSTCTRL),
        PMHAL_PRCM_CD_L4_WKUP_AON_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4_WKUP_AON_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L3S_TSC */
        PMHAL_PRCM_PD_WKUP,
        (SOC_CM_WKUP_REG + PRCM_CM_L3S_TSC_CLKSTCTRL),
        PMHAL_PRCM_CD_L3S_TSC_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L3S_TSC_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_MPU */
        PMHAL_PRCM_PD_MPU,
        (SOC_CM_MPU_REG + PRCM_CM_MPU_CLKSTCTRL),
        PMHAL_PRCM_CD_MPU_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_MPU_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_HW_AUTO))
    },
    {   /* PMHAL_PRCM_CD_L4_RTC */
        PMHAL_PRCM_PD_RTC,
        (SOC_CM_RTC_REG + PRCM_CM_RTC_CLKSTCTRL),
        PMHAL_PRCM_CD_L4_RTC_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4_RTC_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_GFX_L3 */
        PMHAL_PRCM_PD_GFX,
        (SOC_CM_GFX_REG + PRCM_CM_GFX_L3_CLKSTCTRL),
        PMHAL_PRCM_CD_GFX_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_GFX_L3_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L4_CEFUSE */
        PMHAL_PRCM_PD_CUSTEFUSE,
        (SOC_CM_CEFUSE_REG + PRCM_CM_CEFUSE_CLKSTCTRL),
        PMHAL_PRCM_CD_L4_CEFUSE_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4_CEFUSE_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    }
};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_PER_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_PER_M2_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_PER),
 PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_MASK,
 PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_PER_DCO_LDO
 *         divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_PER_DCO_LDO_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_CLKDCOLDO_DPLL_PER),
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_MPU_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_MPU_M2_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_MPU),
 PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_MASK,
 PRCM_CM_DIV_M2_DPLL_MPU_CLKOUT_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_DDR_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_DDR_M2_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_DDR),
 PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_MASK,
 PRCM_CM_DIV_M2_DPLL_DDR_CLKOUT_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_DDR_M4 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_DDR_M4_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M4_DPLL_DDR),
 PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_MASK,
 PRCM_CM_DIV_M4_DPLL_DDR_HSDIVIDER_CLKOUT1_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_DISP_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_DISP_M2_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_DISP),
 PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_MASK,
 PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M4 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M4_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M4_DPLL_CORE),
 PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_MASK,
 PRCM_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M5 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M5_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M5_DPLL_CORE),
 PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_MASK,
 PRCM_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M6 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M6_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M6_DPLL_CORE),
 PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_MASK,
 PRCM_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_EXTDEV_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_EXTDEV_M2_regBitField =
{(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_EXTDEV),
 PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_MASK,
 PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_SHIFT};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_PER divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_PER_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_PER_M2 */
        PMHAL_PRCM_DPLL_POST_DIV_M2,
        &PMHAL_PRCM_DPLL_PER_M2_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    },
    {   /* PMHAL_PRCM_DPLL_PER_DCO_LDO */
        PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO,
        &PMHAL_PRCM_DPLL_PER_DCO_LDO_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_MPU divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_MPU_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_MPU_M2 */
        PMHAL_PRCM_DPLL_POST_DIV_M2,
        &PMHAL_PRCM_DPLL_MPU_M2_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_DDR divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_DDR_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_DDR_M2 */
        PMHAL_PRCM_DPLL_POST_DIV_M2,
        &PMHAL_PRCM_DPLL_DDR_M2_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    },
    {   /* PMHAL_PRCM_DPLL_DDR_M4 */
        PMHAL_PRCM_DPLL_POST_DIV_M4,
        &PMHAL_PRCM_DPLL_DDR_M4_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_DISP divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_DISP_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_DISP_M2 */
        PMHAL_PRCM_DPLL_POST_DIV_M2,
        &PMHAL_PRCM_DPLL_DISP_M2_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_CORE divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_CORE_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_CORE_M4 */
        PMHAL_PRCM_DPLL_POST_DIV_M4,
        &PMHAL_PRCM_DPLL_CORE_M4_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    },
    {   /* PMHAL_PRCM_DPLL_CORE_M5 */
        PMHAL_PRCM_DPLL_POST_DIV_M5,
        &PMHAL_PRCM_DPLL_CORE_M5_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    },
    {   /* PMHAL_PRCM_DPLL_CORE_M6 */
        PMHAL_PRCM_DPLL_POST_DIV_M6,
        &PMHAL_PRCM_DPLL_CORE_M6_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining PMHAL_PRCM_DPLL_EXTDEV divider configuration
 */
pmhalDpllPostDiv_t            PMHAL_PRCM_DPLL_EXTDEV_postdividers[] =
{
    {   /* PMHAL_PRCM_DPLL_DISP_M2 */
        PMHAL_PRCM_DPLL_POST_DIV_M2,
        &PMHAL_PRCM_DPLL_EXTDEV_M2_regBitField,
        PMHAL_CTRL_POSTDIV_NOTAPPLICABLE
    }
};

/**
 *  \brief Structure defining DPLL Post Dividers controlled by control module
 *         added for compatibility between TDA2xx and TDA3xx
 */
const pmhalDpllCtrlMdlHsDiv_t pmhalCtrlModuleDpllDividerElems[] =
{{PMHAL_PRCM_DPLL_POST_DIV_INVALID,
  NULL,
  NULL,
  NULL,
  NULL,
  0,
  0}};

/**
 *  \brief Structure defining DPLL Element List
 */
const pmhalDpll_t             pmhalDpllElems[] =
{
    {   /* PMHAL_PRCM_DPLL_PER */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_PER),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL2_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_PER),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKDCOLDO_DPLL_PER),
        PRCM_CM_CLKSEL_DPLL_PER_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_PER_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_PER_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLLLJ,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_PER_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_PER_postdividers,
        PMHAL_EDGE_DPLL_PER
    },
    {   /* PMHAL_PRCM_DPLL_MPU */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_MPU),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_MPU),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_MPU),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_MPU),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_MPU),
        PMHAL_REG_NOTAPPLICABLE,
        PRCM_CM_CLKSEL_DPLL_MPU_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_MPU_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_MPU_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_FR_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLL,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_MPU_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_MPU_postdividers,
        PMHAL_EDGE_DPLL_MPU
    },
    {   /* PMHAL_PRCM_DPLL_DDR */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DDR),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DDR),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DDR),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_DDR),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_DDR),
        PMHAL_REG_NOTAPPLICABLE,
        PRCM_CM_CLKSEL_DPLL_DDR_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_DDR_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_DDR_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_FR_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLL,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_DDR_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_DDR_postdividers,
        PMHAL_EDGE_DPLL_DDR
    },
    {   /* PMHAL_PRCM_DPLL_DISP */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_DISP),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_DISP),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_DISP),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_DISP),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_DISP),
        PMHAL_REG_NOTAPPLICABLE,
        PRCM_CM_CLKSEL_DPLL_DISP_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_DISP_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_DISP_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_FR_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLL,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_DISP_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_DISP_postdividers,
        PMHAL_EDGE_DPLL_DISP
    },
    {   /* PMHAL_PRCM_DPLL_CORE */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_CORE),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_CORE),
        PMHAL_REG_NOTAPPLICABLE,
        PRCM_CM_CLKSEL_DPLL_CORE_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_CORE_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_CORE_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_FR_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLL,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_CORE_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_CORE_postdividers,
        PMHAL_EDGE_DPLL_CORE
    },
    {   /* PMHAL_PRCM_DPLL_EXTDEV */
        (SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_EXTDEV),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_CLKSEL2_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_DELTAMSTEP_DPLL_EXTDEV),
        (SOC_CM_WKUP_REG + PRCM_CM_SSC_MODFREQDIV_DPLL_EXTDEV),
        PMHAL_REG_NOTAPPLICABLE,
        PRCM_CM_CLKSEL_DPLL_EXTDEV_DIV_MASK,
        PRCM_CM_CLKSEL_DPLL_EXTDEV_MULT_MASK,
        PMHAL_MASK_NOTAPPLICABLE,
        PRCM_CM_CLKMODE_DPLL_EXTDEV_EN_MASK,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE)),
        PMHAL_PRCM_DPLL_TYPE_ADPLLLJ,
        VSIZE_TYPE(PMHAL_PRCM_DPLL_EXTDEV_postdividers,
                   pmhalDpllPostDiv_t),
        PMHAL_PRCM_DPLL_EXTDEV_postdividers,
        PMHAL_EDGE_DPLL_EXTDEV
    }
};

#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_AES0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_AES0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CPGMAC0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_125MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_250MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_250MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_50MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_50MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_5MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_5MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_CPTS_RFT_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CRYPTODMA_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3D2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DCAN0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CAN_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_CAN_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DCAN1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DCAN1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CAN_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_CAN_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DDRPHY
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DDRPHY
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DDRPHY_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_EMIF_PHY_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_PHY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DDRPHY */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DES
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DES_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DLL
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DLL_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DDR_DLL_GCLK,
     PRCM_CM_PER_DLL_CLKCTRL_OPTFCLKEN_CLK_SHIFT,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_DLL_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DLL_AGING
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DLL_AGING_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DLL_AGING_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_DLL_AGING_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DSS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DSS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DSS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_DSS_CLKSTCTRL_CLKACTIVITY_CLK_SHIFT},
    {PMHAL_PRCM_CLK_DSS_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_DSS_CLKSTCTRL_CLKACTIVITY_L3_OCP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_DSS_L4_GCLK_EN,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_DSS_SYSCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_DSS_CLKSTCTRL_CLKACTIVITY_SYSCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ELM
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ELM_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EMIF
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EMIF_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DDR_DLL_GCLK,
     PRCM_CM_PER_DLL_CLKCTRL_OPTFCLKEN_CLK_SHIFT,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_DLL_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_EMIF_PHY_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_PHY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_EMIF_L3_GICLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EMIF_FW
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS4
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS4_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EPWMSS5
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EPWMSS5_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ERMC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ERMC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ERMC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ERMC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_1_GDBCLK,
     PRCM_CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_1_GDBCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_2_GDBCLK,
     PRCM_CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_2_GDBCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_3_GDBCLK,
     PRCM_CM_PER_GPIO3_CLKCTRL_OPTFCLKEN_GPIO_3_GDBCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_3_GDBCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO4
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO4_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_4_GDBCLK,
     PRCM_CM_PER_GPIO4_CLKCTRL_OPTFCLKEN_GPIO_4_GDBCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_4_GDBCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO5
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO5_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_5_GDBCLK,
     PRCM_CM_PER_GPIO5_CLKCTRL_OPTFCLKEN_GPIO_5_GDBCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_5_GDBCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPMC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPMC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_HDQ1W
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_HDQ1W_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_HDQ1W_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_I2C1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_I2C1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_I2C2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_I2C2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ICSS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ICSS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_ICSS_IEP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_IEP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_ICSS_OCP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_OCP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_ICSS_UART_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_UART_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_IEEE5000
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_IEEE5000_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3D2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L3_INSTR
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L3_INSTR_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4FW
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4FW_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3D2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4LS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4LS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4_HS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4_HS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_LCDC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_LCDC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_LCD_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_LCDC_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_LCD_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_LCDC_CLKSTCTRL_CLKACTIVITY_L3_OCP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_LCD_L4S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MAG_CARD
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MAG_CARD_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_MGC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MGC_FGCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MAILBOX0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MCASP0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MCASP0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MCASP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MCASP1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MCASP1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MCASP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMC0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMC0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MMC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMC1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMC1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MMC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMC2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMC2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MMC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MSTR_EXPS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MSTR_EXPS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_OCMCRAM
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_OCMCRAM_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_OCP_WP_NOC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_OCP_WP_NOC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_OCPWP_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_OCPWP_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_OTFA_EMIF
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_OTFA_EMIF_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_EMIF_L3_GICLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_EMIF_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_PKA
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_PKA_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_QSPI
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_QSPI_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_RNG
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_RNG_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SHA0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SHA0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SLV_EXPS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SLV_EXPS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPARE0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPARE0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPARE1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPARE1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPI0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPI0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPI1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPI1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPI2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPI2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPI3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPI3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPI4
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPI4_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPINLOCK
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER10
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER10_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER10_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER10_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER11
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER11_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER11_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER11_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER2_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER4
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER4_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER4_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER5
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER5_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER5_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER5_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER6
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER6_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER6_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER6_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER7
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER7_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER7_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER7_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER8
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER8_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER8_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER8_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER9
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER9_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER9_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER9_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPCC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPCC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPTC0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPTC0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPTC1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPTC1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPTC2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPTC2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART4
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART4_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART5
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART5_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USBPHYOCP2SCP0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USBPHYOCP2SCP0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USBPHYOCP2SCP1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USBPHYOCP2SCP1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USB_OTG_SS0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USB_OTG_SS0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK,
     PRCM_CM_PER_USB_OTG_SS0_CLKCTRL_OPTFCLKEN_REFCLK960M_SHIFT,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REFCLK_SHIFT},
    {PMHAL_PRCM_CLK_USB_PLL_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USB_OTG_SS1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USB_OTG_SS1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK,
     PRCM_CM_PER_USB_OTG_SS1_CLKCTRL_OPTFCLKEN_REFCLK960M_SHIFT,
     PRCM_CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REFCLK_SHIFT},
    {PMHAL_PRCM_CLK_USB_PLL_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USIM0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USIM0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_USIM0_FCLK,
     PRCM_CM_PER_USIM0_CLKCTRL_OPTFCLKEN_FCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_USIM0_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_USIM0_FCLK32,
     PRCM_CM_PER_USIM0_CLKCTRL_OPTFCLKEN_FCLK32_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_USIM0_FCLK32_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USIM1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USIM1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_USIM1_FCLK,
     PRCM_CM_PER_USIM1_CLKCTRL_OPTFCLKEN_FCLK_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_USIM1_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_USIM1_FCLK32,
     PRCM_CM_PER_USIM1_CLKCTRL_OPTFCLKEN_FCLK32_SHIFT,
     PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_USIM1_FCLK32_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_VPFE0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_VPFE0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3D2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_VPFE1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_VPFE1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_PER_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3D2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GFX
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GFX_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GFX_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_FCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ADC_TSC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_ADC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_TSC_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L3S_TSC_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CLKDIV32K
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CLK_24MHZ,
     PRCM_CM_WKUP_CLKDIV32K_CLKCTRL_OPTFCLKEN_FCLK_SHIFT,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CONTROL
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DEBUGSS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DEBUGSS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DBGSYSCLK,
     PRCM_CM_WKUP_DBGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_SHIFT,
     PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKA_SHIFT},
    {PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKB_SHIFT},
    {PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBG_CLKC_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_GPIO0_GDBCLK,
     PRCM_CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GDBCLK_SHIFT,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_I2C0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_I2C0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_I2C0_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4WKUP
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4WKUP_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SMARTREFLEX0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SMARTREFLEX0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_SR_SYSCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SMARTREFLEX1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SMARTREFLEX1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_SR_SYSCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SYNCTIMER
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SYNCTIMER_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK,
     PRCM_CM_WKUP_SYNCTIMER_CLKCTRL_OPTFCLKEN_FCLK32_SHIFT,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_SYNCTIMER32K_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_TIMER0_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_TIMER1_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_UART0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_UART0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_UART0_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK,
     PRCM_CM_WKUP_USBPHY0_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK,
     PRCM_CM_WKUP_USBPHY1_CLKCTRL_OPTFCLKEN_CLK32K_SHIFT,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_USBPHY_32KHZ_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_WDT0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_WDT0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_WDT0_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_WDT1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_WDT1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_WDT1_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_WKUP_M3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_WKUP_M3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CEFUSE
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CEFUSE_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_CEFUSE_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_GICLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_RTCSS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_RTCSS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_RTC_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_RTC_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_RTC_32KCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_RTC_CLKSTCTRL_CLKACTIVITY_32KCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MPU
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MPU_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MPU_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_MPU_CLKSTCTRL_CLKACTIVITY_CLK_SHIFT}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EFUSE
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EFUSE_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPMSS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPMSS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPMSS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_TAMPER_L4_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PRCM_CM_TAMPER_CLKSTCTRL_CLKACTIVITY_L4_GCLK_SHIFT}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPMSS */

/**
 *  \brief Structure defining SysConfig Elements
 */
const pmhalSysConfig_t        pmhalSysConfigElems[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    {   /* PMHAL_PRCM_MOD_GPMC */
        (SOC_GPMC_CONFIG_REG + GPMC_SYSCONFIG),
        GPMC_SYSCONFIG_SIDLEMODE_SHIFT,
        GPMC_SYSCONFIG_SIDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /*BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    {   /* PMHAL_PRCM_MOD_ELM */
        (SOC_ELM_REG + ELM_SYSCONFIG),
        ELM_SYSCONFIG_SIDLEMODE_SHIFT,
        ELM_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /*BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    {   /* PMHAL_PRCM_MOD_CONTROL */
        (SOC_CONTROL_MODULE_REG + CTRL_SYSCONFIG),
        CTRL_SYSCONFIG_IDLEMODE_SHIFT,
        CTRL_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        CTRL_SYSCONFIG_STANDBY_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /*BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    {   /* PMHAL_PRCM_MOD_TPCC */
        (SOC_EDMA3CC_REG + EDMA_TPCC_SYSCONFIG),
        EDMA_TPCC_SYSCONFIG_IDLEMODE_SHIFT,
        EDMA_TPCC_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    {   /* PMHAL_PRCM_MOD_TPTC0 */
        (SOC_EDMA3TC0_REG + EDMA3TC_SYSCONFIG),
        EDMA_TPTC_SYSCONFIG_IDLEMODE_SHIFT,
        EDMA_TPTC_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        EDMA_TPTC_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    {   /* PMHAL_PRCM_MOD_TPTC1 */
        (SOC_EDMA3TC1_REG + EDMA3TC_SYSCONFIG),
        EDMA_TPTC_SYSCONFIG_IDLEMODE_SHIFT,
        EDMA_TPTC_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        EDMA_TPTC_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    {   /* PMHAL_PRCM_MOD_TPTC2 */
        (SOC_EDMA3TC2_REG + EDMA3TC_SYSCONFIG),
        EDMA_TPTC_SYSCONFIG_IDLEMODE_SHIFT,
        EDMA_TPTC_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        EDMA_TPTC_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    {   /* PMHAL_PRCM_MOD_ADC_TSC */
        (SOC_ADC_TSC_REG + ADC0_SYSCONFIG),
        ADC0_SYSCONFIG_IDLEMODE_SHIFT,
        ADC0_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    {   /* PMHAL_PRCM_MOD_MAG_CARD */
        (SOC_MAGCARD_REG + ADC0_SYSCONFIG),
        ADC0_SYSCONFIG_IDLEMODE_SHIFT,
        ADC0_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    {   /* PMHAL_PRCM_MOD_DSS */
        (SOC_DSS_DISPC_REG + DISPC_SYSCFG),
        DISPC_SYSCFG_SIDLEMODE_SHIFT,
        DISPC_SYSCFG_SIDLEMODE_MASK,
        TRUE,
        DISPC_SYSCFG_MIDLEMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    {   /* PMHAL_PRCM_MOD_VPFE0 */
        (SOC_VPFE0_REG + VPFE_SYSCONFIG),
        VPFE_SYSCONFIG_IDLEMODE_SHIFT,
        VPFE_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        VPFE_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    {   /* PMHAL_PRCM_MOD_DSS_VPFE1 */
        (SOC_VPFE1_REG + VPFE_SYSCONFIG),
        VPFE_SYSCONFIG_IDLEMODE_SHIFT,
        VPFE_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        VPFE_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    {   /* PMHAL_PRCM_MOD_EPWMSS0 */
        (SOC_PWMSS0_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    {   /* PMHAL_PRCM_MOD_EPWMSS1 */
        (SOC_PWMSS1_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    {   /* PMHAL_PRCM_MOD_EPWMSS2 */
        (SOC_PWMSS2_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    {   /* PMHAL_PRCM_MOD_EPWMSS3 */
        (SOC_PWMSS3_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    {   /* PMHAL_PRCM_MOD_EPWMSS4 */
        (SOC_PWMSS4_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    {   /* PMHAL_PRCM_MOD_EPWMSS5 */
        (SOC_PWMSS5_REG + PWMSS_SYSCONFIG),
        PWMSS_SYSCONFIG_IDLEMODE_SHIFT,
        PWMSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PWMSS_SYSCONFIG_STANDBYMODE_SHIFT,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY)),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    {   /* PMHAL_PRCM_MOD_MAILBOX0 */
        (SOC_MAILBOX0_REG + MLB_SYSCONFIG),
        MLB_SYSCONFIG_SIDLEMODE_SHIFT,
        MLB_SYSCONFIG_SIDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    {   /* PMHAL_PRCM_MOD_SPINLOCK */
        (SOC_SPINLOCK_REG + SPINLOCK_SYSCONFIG),
        SPINLOCK_SYSCONFIG_IDLEMODE_SHIFT,
        SPINLOCK_SYSCONFIG_IDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    {   /* PMHAL_PRCM_MOD_MMC0 */
        (SOC_MMCSD0_REG + HS_MMC_SD_SYSCONFIG),
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_SHIFT,
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    {   /* PMHAL_PRCM_MOD_MMC1 */
        (SOC_MMCSD1_REG + HS_MMC_SD_SYSCONFIG),
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_SHIFT,
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    {   /* PMHAL_PRCM_MOD_MMC2 */
        (SOC_MMCSD2_REG + HS_MMC_SD_SYSCONFIG),
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_SHIFT,
        HS_MMC_SD_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    {   /* PMHAL_PRCM_MOD_SYNCTIMER */
        (SOC_SYNCTIMER_REG + SYNCTIMER_SYSCONFIG),
        SYNCTIMER_SYSCONFIG_IDLEMODE_SHIFT,
        SYNCTIMER_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    {   /* PMHAL_PRCM_MOD_RTCSS */
        (SOC_RTCSS_REG + RTCSS_SYSCONFIG),
        RTCSS_SYSCONFIG_IDLEMODE_SHIFT,
        RTCSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    {   /* PMHAL_PRCM_MOD_MCASP0 */
        (SOC_MCASP0_CFG_REG + MCASP_PWRIDLESYSCONFIG),
        MCASP_PWRIDLESYSCONFIG_IDLEMODE_SHIFT,
        MCASP_PWRIDLESYSCONFIG_IDLEMODE,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    {   /* PMHAL_PRCM_MOD_MCASP1 */
        (SOC_MCASP1_CFG_REG + MCASP_PWRIDLESYSCONFIG),
        MCASP_PWRIDLESYSCONFIG_IDLEMODE_SHIFT,
        MCASP_PWRIDLESYSCONFIG_IDLEMODE,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    {   /* PMHAL_PRCM_MOD_SPI0 */
        (SOC_MCSPI0_REG + MCSPI_SYSCONFIG),
        MCSPI_SYSCONFIG_SIDLEMODE_SHIFT,
        MCSPI_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    {   /* PMHAL_PRCM_MOD_SPI1 */
        (SOC_MCSPI1_REG + MCSPI_SYSCONFIG),
        MCSPI_SYSCONFIG_SIDLEMODE_SHIFT,
        MCSPI_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    {   /* PMHAL_PRCM_MOD_SPI2 */
        (SOC_MCSPI2_REG + MCSPI_SYSCONFIG),
        MCSPI_SYSCONFIG_SIDLEMODE_SHIFT,
        MCSPI_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    {   /* PMHAL_PRCM_MOD_SPI3 */
        (SOC_MCSPI3_REG + MCSPI_SYSCONFIG),
        MCSPI_SYSCONFIG_SIDLEMODE_SHIFT,
        MCSPI_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    {   /* PMHAL_PRCM_MOD_SPI4 */
        (SOC_MCSPI4_REG + MCSPI_SYSCONFIG),
        MCSPI_SYSCONFIG_SIDLEMODE_SHIFT,
        MCSPI_SYSCONFIG_SIDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    {   /* PMHAL_PRCM_MOD_QSPI */
        (SOC_QSPI_ADDRSP0_REG + QSPI_SYSCONFIG),
        QSPI_SYSCONFIG_IDLE_MODE_SHIFT,
        QSPI_SYSCONFIG_IDLE_MODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    {   /* PMHAL_PRCM_MOD_GPIO0 */
        (SOC_GPIO0_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    {   /* PMHAL_PRCM_MOD_GPIO1 */
        (SOC_GPIO1_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    {   /* PMHAL_PRCM_MOD_GPIO2 */
        (SOC_GPIO2_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    {   /* PMHAL_PRCM_MOD_GPIO3 */
        (SOC_GPIO3_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    {   /* PMHAL_PRCM_MOD_GPIO4 */
        (SOC_GPIO4_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    {   /* PMHAL_PRCM_MOD_GPIO5 */
        (SOC_GPIO5_REG + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE_SHIFT,
        GPIO_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    {   /* PMHAL_PRCM_MOD_I2C0 */
        (SOC_I2C0_REG + I2C_SYSC),
        I2C_SYSC_IDLEMODE_SHIFT,
        I2C_SYSC_IDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    {   /* PMHAL_PRCM_MOD_I2C1 */
        (SOC_I2C1_REG + I2C_SYSC),
        I2C_SYSC_IDLEMODE_SHIFT,
        I2C_SYSC_IDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    {   /* PMHAL_PRCM_MOD_I2C2 */
        (SOC_I2C2_REG + I2C_SYSC),
        I2C_SYSC_IDLEMODE_SHIFT,
        I2C_SYSC_IDLEMODE_MASK,
        TRUE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
};

/**
 *  \brief Structure defining Module Elements List
 */
const pmhalModule_t           pmhalModuleElems[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    {   /* PMHAL_PRCM_MOD_AES0 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_AES0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_AES0_CLKCTRL),
        PMHAL_PRCM_MOD_AES0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    { /* PMHAL_PRCM_MOD_CPGMAC0 */
        PMHAL_PRCM_CD_CPSW_125MHZ,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_CPGMAC0_CLKCTRL),
        PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_CPGMAC0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
    {   /* PMHAL_PRCM_MOD_CRYPTODMA */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CRYPTODMA_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_CRYPTODMA_CLKCTRL),
        PMHAL_PRCM_MOD_CRYPTODMA_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_CRYPTODMA,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    { /* PMHAL_PRCM_MOD_DCAN0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_DCAN0_CLKCTRL),
        PMHAL_PRCM_MOD_DCAN0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_DCAN0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    { /* PMHAL_PRCM_MOD_DCAN1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_DCAN1_CLKCTRL),
        PMHAL_PRCM_MOD_DCAN1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_DCAN1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DDRPHY
    {   /* PMHAL_PRCM_MOD_DDRPHY */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DDRPHY_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_DDRPHY_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    { /* PMHAL_PRCM_MOD_DES */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DES_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_DES_CLKCTRL),
        PMHAL_PRCM_MOD_DES_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
    {   /* PMHAL_PRCM_MOD_DLL */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DLL_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_DLL_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
    {   /* PMHAL_PRCM_MOD_DLL_AGING */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DLL_AGING_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_DLL_AGING_CLKCTRL),
        PMHAL_PRCM_MOD_DLL_AGING_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    {   /* PMHAL_PRCM_MOD_DSS */
        PMHAL_PRCM_CD_DSS_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_DSS,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DSS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_DSS_CLKCTRL),
        PMHAL_PRCM_MOD_DSS_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    { /* PMHAL_PRCM_MOD_ELM */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_ELM,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ELM_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_ELM_CLKCTRL),
        PMHAL_PRCM_MOD_ELM_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_DSS,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    { /* PMHAL_PRCM_MOD_EMIF */
        PMHAL_PRCM_CD_EMIF_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_ELM,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKCTRL),
        PMHAL_PRCM_MOD_EMIF_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_EMIF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    { /* PMHAL_PRCM_MOD_EMIF_FW */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EMIF_FW_CLKCTRL),
        PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    { /* PMHAL_PRCM_MOD_EPWMSS0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS0_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS0_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    { /* PMHAL_PRCM_MOD_EPWMSS1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS1_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS1_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    { /* PMHAL_PRCM_MOD_EPWMSS2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS2_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS2_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    {   /* PMHAL_PRCM_MOD_EPWMSS3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS3,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS3_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS3_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    {   /* PMHAL_PRCM_MOD_EPWMSS4 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS4,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS4_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS4_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    {   /* PMHAL_PRCM_MOD_EPWMSS5 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_EPWMSS5,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EPWMSS5_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_EPWMSS5_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS5_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ERMC
    {   /* PMHAL_PRCM_MOD_ERMC */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ERMC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_ERMC_CLKCTRL),
        PMHAL_PRCM_MOD_ERMC_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    { /* PMHAL_PRCM_MOD_GPIO1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO1_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    { /* PMHAL_PRCM_MOD_GPIO2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO2_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    { /* PMHAL_PRCM_MOD_GPIO3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO3,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO3_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO3,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    { /* PMHAL_PRCM_MOD_GPIO4 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO4,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO4_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO4_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO4,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    { /* PMHAL_PRCM_MOD_GPIO5 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO5,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO5_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPIO5_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO5_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO5,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    { /* PMHAL_PRCM_MOD_GPMC */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPMC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPMC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_GPMC_CLKCTRL),
        PMHAL_PRCM_MOD_GPMC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
    {   /* PMHAL_PRCM_MOD_HDQ1W */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_HDQ1W_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_HDQ1W_CLKCTRL),
        PMHAL_PRCM_MOD_HDQ1W_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_HDQ1W,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    { /* PMHAL_PRCM_MOD_I2C1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_I2C1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_I2C1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL),
        PMHAL_PRCM_MOD_I2C1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_I2C1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    { /* PMHAL_PRCM_MOD_I2C2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_I2C2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_I2C2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_I2C2_CLKCTRL),
        PMHAL_PRCM_MOD_I2C2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_I2C2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    { /* PMHAL_PRCM_MOD_ICSS */
        PMHAL_PRCM_CD_ICSS_OCP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ICSS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_ICSS_CLKCTRL),
        PMHAL_PRCM_MOD_ICSS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_ICSS,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
    { /* PMHAL_PRCM_MOD_IEEE5000 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_IEEE5000_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_IEEE5000_CLKCTRL),
        PMHAL_PRCM_MOD_IEEE5000_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    { /* PMHAL_PRCM_MOD_L3 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_CLKCTRL),
        PMHAL_PRCM_MOD_L3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_L3,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    { /* PMHAL_PRCM_MOD_L3_INSTR */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L3_INSTR_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_L3_INSTR_CLKCTRL),
        PMHAL_PRCM_MOD_L3_INSTR_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    { /* PMHAL_PRCM_MOD_L4FW */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4FW_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_L4FW_CLKCTRL),
        PMHAL_PRCM_MOD_L4FW_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_L4FW,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    { /* PMHAL_PRCM_MOD_L4LS */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4LS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKCTRL),
        PMHAL_PRCM_MOD_L4LS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    {   /* PMHAL_PRCM_MOD_L4_HS */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4_HS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_L4HS_CLKCTRL),
        PMHAL_PRCM_MOD_L4_HS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    {   /* PMHAL_PRCM_MOD_LCDC */
        PMHAL_PRCM_CD_LCD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_LCDC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_LCDC_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_MOD_LCDC,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    {   /* PMHAL_PRCM_MOD_MAG_CARD */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MAG_CARD,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MAG_CARD_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MAG_CARD_CLKCTRL),
        PMHAL_PRCM_MOD_MAG_CARD_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_MAG_CARD,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    { /* PMHAL_PRCM_MOD_MAILBOX0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MAILBOX0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MAILBOX0_CLKCTRL),
        PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    { /* PMHAL_PRCM_MOD_MCASP0 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MCASP0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MCASP0_CLKCTRL),
        PMHAL_PRCM_MOD_MCASP0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MCASP0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    { /* PMHAL_PRCM_MOD_MCASP1 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MCASP1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MCASP1_CLKCTRL),
        PMHAL_PRCM_MOD_MCASP1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MCASP1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    { /* PMHAL_PRCM_MOD_MMC0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MMC0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC0_CLKCTRL),
        PMHAL_PRCM_MOD_MMC0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MMC0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    { /* PMHAL_PRCM_MOD_MMC1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MMC1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMC1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC1_CLKCTRL),
        PMHAL_PRCM_MOD_MMC1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MMC1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC01 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    { /* PMHAL_PRCM_MOD_MMC2 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MMC2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMC2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MMC2_CLKCTRL),
        PMHAL_PRCM_MOD_MMC2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MMC2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    { /* PMHAL_PRCM_MOD_MSTR_EXPS */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MSTR_EXPS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_MSTR_EXPS_CLKCTRL),
        PMHAL_PRCM_MOD_MSTR_EXPS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    {   /* PMHAL_PRCM_MOD_OCMCRAM */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_OCMCRAM_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_OCMCRAM_CLKCTRL),
        PMHAL_PRCM_MOD_OCMCRAM_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
    {   /* PMHAL_PRCM_MOD_OCP_WP_NOC */
        PMHAL_PRCM_CD_OCPWP_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_OCP_WP_NOC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_OCPWP_CLKCTRL),
        PMHAL_PRCM_MOD_OCP_WP_NOC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_OCP_WP_NOC,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF
    {   /* PMHAL_PRCM_MOD_OTFA_EMIF */
        PMHAL_PRCM_CD_EMIF_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_OTFA_EMIF_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_OTFA_EMIF_CLKCTRL),
        PMHAL_PRCM_MOD_OTFA_EMIF_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    { /* PMHAL_PRCM_MOD_PKA */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_PKA_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_PKA_CLKCTRL),
        PMHAL_PRCM_MOD_PKA_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    {   /* PMHAL_PRCM_MOD_QSPI */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_QSPI,
        VSIZE_TYPE(PMHAL_PRCM_MOD_QSPI_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_QSPI_CLKCTRL),
        PMHAL_PRCM_MOD_QSPI_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_QSPI,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    { /* PMHAL_PRCM_MOD_RNG */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_RNG_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_RNG_CLKCTRL),
        PMHAL_PRCM_MOD_RNG_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
    { /* PMHAL_PRCM_MOD_SHA0 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SHA0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SHA0_CLKCTRL),
        PMHAL_PRCM_MOD_SHA0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
    {   /* PMHAL_PRCM_MOD_SLV_EXPS */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SLV_EXPS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SLV_EXPS_CLKCTRL),
        PMHAL_PRCM_MOD_SLV_EXPS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
    { /* PMHAL_PRCM_MOD_SPARE0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPARE0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPARE0_CLKCTRL),
        PMHAL_PRCM_MOD_SPARE0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
    { /* PMHAL_PRCM_MOD_SPARE1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPARE1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPARE1_CLKCTRL),
        PMHAL_PRCM_MOD_SPARE1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    { /* PMHAL_PRCM_MOD_SPI0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPI0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI0_CLKCTRL),
        PMHAL_PRCM_MOD_SPI0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SPI0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    { /* PMHAL_PRCM_MOD_SPI1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPI1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI1_CLKCTRL),
        PMHAL_PRCM_MOD_SPI1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SPI1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    { /* PMHAL_PRCM_MOD_SPI2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPI2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI2_CLKCTRL),
        PMHAL_PRCM_MOD_SPI2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SPI2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    { /* PMHAL_PRCM_MOD_SPI3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPI3,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI3_CLKCTRL),
        PMHAL_PRCM_MOD_SPI3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SPI3,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    {   /* PMHAL_PRCM_MOD_SPI4 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPI4,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPI4_CLKCTRL),
        PMHAL_PRCM_MOD_SPI4_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SPI4,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    { /* PMHAL_PRCM_MOD_SPINLOCK */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPINLOCK,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_SPINLOCK_CLKCTRL),
        PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
    {   /* PMHAL_PRCM_MOD_TIMER10 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER10_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER10_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER10_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER10,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
    {   /* PMHAL_PRCM_MOD_TIMER11 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER11_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER11_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER11_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER11,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    { /* PMHAL_PRCM_MOD_TIMER2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER2_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    { /* PMHAL_PRCM_MOD_TIMER3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER3_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER3,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    { /* PMHAL_PRCM_MOD_TIMER4 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER4_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER4_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER4,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    { /* PMHAL_PRCM_MOD_TIMER5 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER5_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER5_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER5_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER5,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    { /* PMHAL_PRCM_MOD_TIMER6 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER6_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER6_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER6_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER6,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    { /* PMHAL_PRCM_MOD_TIMER7 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER7_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER7_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER7_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER7,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    {   /* PMHAL_PRCM_MOD_TIMER8 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER8_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER8_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER8_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER8,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
    {   /* PMHAL_PRCM_MOD_TIMER9 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER9_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TIMER9_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER9_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER9,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    { /* PMHAL_PRCM_MOD_TPCC */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_TPCC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPCC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TPCC_CLKCTRL),
        PMHAL_PRCM_MOD_TPCC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    { /* PMHAL_PRCM_MOD_TPTC0 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC0_CLKCTRL),
        PMHAL_PRCM_MOD_TPTC0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    { /* PMHAL_PRCM_MOD_TPTC1 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC1_CLKCTRL),
        PMHAL_PRCM_MOD_TPTC1_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    { /* PMHAL_PRCM_MOD_TPTC2 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_TPTC2_CLKCTRL),
        PMHAL_PRCM_MOD_TPTC2_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    { /* PMHAL_PRCM_MOD_UART1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_UART1_CLKCTRL),
        PMHAL_PRCM_MOD_UART1_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    { /* PMHAL_PRCM_MOD_UART2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_UART2_CLKCTRL),
        PMHAL_PRCM_MOD_UART2_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART2,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    { /* PMHAL_PRCM_MOD_UART3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_UART3_CLKCTRL),
        PMHAL_PRCM_MOD_UART3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART3,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    { /* PMHAL_PRCM_MOD_UART4 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_UART4_CLKCTRL),
        PMHAL_PRCM_MOD_UART4_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART4,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    { /* PMHAL_PRCM_MOD_UART5 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART5_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_UART5_CLKCTRL),
        PMHAL_PRCM_MOD_UART5_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART5,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0
    {   /* PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USBPHYOCP2SCP0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USBPHYOCP2SCP0_CLKCTRL),
        PMHAL_PRCM_MOD_USBPHYOCP2SCP0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1
    {   /* PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USBPHYOCP2SCP1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USBPHYOCP2SCP1_CLKCTRL),
        PMHAL_PRCM_MOD_USBPHYOCP2SCP1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
    {   /* PMHAL_PRCM_MOD_USB_OTG_SS0 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USB_OTG_SS0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USB_OTG_SS0_CLKCTRL),
        PMHAL_PRCM_MOD_USB_OTG_SS0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_USB_OTG_SS0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
    {   /* PMHAL_PRCM_MOD_USB_OTG_SS1 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USB_OTG_SS1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USB_OTG_SS1_CLKCTRL),
        PMHAL_PRCM_MOD_USB_OTG_SS1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_USB_OTG_SS1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
    {   /* PMHAL_PRCM_MOD_USIM0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USIM0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USIM0_CLKCTRL),
        PMHAL_PRCM_MOD_USIM0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_USIM0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
    {   /* PMHAL_PRCM_MOD_USIM1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USIM1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_USIM1_CLKCTRL),
        PMHAL_PRCM_MOD_USIM1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_USIM1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    {   /* PMHAL_PRCM_MOD_VPFE0 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_VPFE0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_VPFE1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_VPFE0_CLKCTRL),
        PMHAL_PRCM_MOD_VPFE1_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_VPFE0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    {   /* PMHAL_PRCM_MOD_VPFE1 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_VPFE1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_VPFE0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REG + PRCM_CM_PER_VPFE1_CLKCTRL),
        PMHAL_PRCM_MOD_VPFE0_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_VPFE1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    { /* PMHAL_PRCM_MOD_GFX */
        PMHAL_PRCM_CD_GFX_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GFX_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_GFX_REG + PRCM_CM_GFX_CLKCTRL),
        PMHAL_PRCM_MOD_GFX_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GFX,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    { /* PMHAL_PRCM_MOD_ADC_TSC */
        PMHAL_PRCM_CD_L3S_TSC,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_ADC_TSC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_ADC_TSC_CLKCTRL),
        PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_ADC_TSC,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    { /* PMHAL_PRCM_MOD_CLKDIV32K */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    { /* PMHAL_PRCM_MOD_CONTROL */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_CONTROL,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_CTRL_CLKCTRL),
        PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    { /* PMHAL_PRCM_MOD_DEBUGSS */
        PMHAL_PRCM_CD_L3_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DEBUGSS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_DBGSS_CLKCTRL),
        PMHAL_PRCM_MOD_DEBUGSS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_DEBUGSS,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    { /* PMHAL_PRCM_MOD_GPIO0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_GPIO0_CLKCTRL),
        PMHAL_PRCM_MOD_GPIO0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GPIO0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    { /* PMHAL_PRCM_MOD_I2C0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_I2C0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_I2C0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_I2C0_CLKCTRL),
        PMHAL_PRCM_MOD_I2C0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_I2C0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    { /* PMHAL_PRCM_MOD_L4WKUP */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4WKUP_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_L4WKUP_CLKCTRL),
        PMHAL_PRCM_MOD_L4WKUP_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    { /* PMHAL_PRCM_MOD_SMARTREFLEX0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SMARTREFLEX0_CLKCTRL),
        PMHAL_PRCM_MOD_SMARTREFLEX0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SMARTREFLEX0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    { /* PMHAL_PRCM_MOD_SMARTREFLEX1 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SMARTREFLEX1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SMARTREFLEX1_CLKCTRL),
        PMHAL_PRCM_MOD_SMARTREFLEX1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SMARTREFLEX1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    {   /* PMHAL_PRCM_MOD_SYNCTIMER */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SYNCTIMER,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SYNCTIMER_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_SYNCTIMER_CLKCTRL),
        PMHAL_PRCM_MOD_SYNCTIMER_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SYNCTIMER,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    { /* PMHAL_PRCM_MOD_TIMER0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER0_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    { /* PMHAL_PRCM_MOD_TIMER1 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER1_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    { /* PMHAL_PRCM_MOD_UART0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_UART0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_UART0_CLKCTRL),
        PMHAL_PRCM_MOD_UART0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
    {   /* PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
    {   /* PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    { /* PMHAL_PRCM_MOD_WDT0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_WDT0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_WDT0_CLKCTRL),
        PMHAL_PRCM_MOD_WDT0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_WDT0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    { /* PMHAL_PRCM_MOD_WDT1 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_WDT1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_WDT1_CLKCTRL),
        PMHAL_PRCM_MOD_WDT1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_WDT1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    { /* PMHAL_PRCM_MOD_WKUP_M3 */
        PMHAL_PRCM_CD_L4_WKUP_AON,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_WKUP_M3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REG + PRCM_CM_WKUP_M3_CLKCTRL),
        PMHAL_PRCM_MOD_WKUP_M3_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    { /* PMHAL_PRCM_MOD_CEFUSE */
        PMHAL_PRCM_CD_L4_CEFUSE,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CEFUSE_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_CEFUSE_REG + PRCM_CM_CEFUSE_CLKCTRL),
        PMHAL_PRCM_MOD_CEFUSE_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_CEFUSE,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    { /* PMHAL_PRCM_MOD_RTCSS */
        PMHAL_PRCM_CD_L4_RTC,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_RTCSS,
        VSIZE_TYPE(PMHAL_PRCM_MOD_RTCSS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_RTC_REG + PRCM_CM_RTC_CLKCTRL),
        PMHAL_PRCM_MOD_RTCSS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_RTCSS,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    { /* PMHAL_PRCM_MOD_MPU */
        PMHAL_PRCM_CD_MPU,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MPU_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_MPU_REG + PRCM_CM_MPU_CLKCTRL),
        PMHAL_PRCM_MOD_MPU_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_MPU
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
    { /* PMHAL_PRCM_MOD_EFUSE */
        PMHAL_PRCM_CD_COUNT, /* No CD so use count as invalid */
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EFUSE_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_EFUSE_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPMSS
    {   /* PMHAL_PRCM_MOD_TPMSS */
        PMHAL_PRCM_CD_COUNT, /* No TAMPER_L4 CD so use count as invalid */
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPMSS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_TAMPER_REG + PRCM_CM_TAMPER_TPMSS_CLKCTRL),
        PMHAL_PRCM_MOD_TPMSS_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPMSS */
};

/**
 *  \brief Structure defining Physical Memory Elements List
 */
const pmhalPhysicalMemory_t   pmhalPhysicalMemoryElems[] =
{
    {   /* PMHAL_PRCM_PHY_BANK_GFX_MEM */
        PRCM_PRM_PM_GFX_PWRSTCTRL_MEM_ONSTATE_SHIFT,
        PRCM_PRM_PM_GFX_PWRSTCTRL_MEM_RETSTATE_SHIFT,
        PRCM_PRM_PM_GFX_PWRSTST_MEM_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF)
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_L1 */
        PRCM_PM_MPU_PWRSTCTRL_L1_ONSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_L1_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTST_L1_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF)
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_L2 */
        PRCM_PM_MPU_PWRSTCTRL_L2_ONSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_L2_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTST_L2_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_RAM */
        PRCM_PM_MPU_PWRSTCTRL_RAM_ONSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTCTRL_RAM_RETSTATE_SHIFT,
        PRCM_PM_MPU_PWRSTST_RAM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_PER_MEM */
        PRCM_PM_PER_PWRSTCTRL_MEM_ONSTATE_SHIFT,
        PRCM_PM_PER_PWRSTCTRL_MEM_RETSTATE_SHIFT,
        PRCM_PM_PER_PWRSTST_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_ICSS_MEM */
        PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_SHIFT,
        PRCM_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_SHIFT,
        PRCM_PM_PER_PWRSTST_ICSS_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_RAM1_MEM */
        PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_ONSTATE_SHIFT,
        PRCM_PM_PER_PWRSTCTRL_RAM1_MEM_RETSTATE_SHIFT,
        PRCM_PM_PER_PWRSTST_RAM1_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_RAM2_MEM */
        PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_ONSTATE_SHIFT,
        PRCM_PM_PER_PWRSTCTRL_RAM2_MEM_RETSTATE_SHIFT,
        PRCM_PM_PER_PWRSTST_RAM2_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_DEBUGSS_MEM */
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        (uint8_t) PMHAL_BANK_RET_UNDEF
    },
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_GFX_FCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_GFX_FCLK_validDivValues[] =
{
    {1U, PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_DIV1},
    {2 , PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_DIV2}
};

/**
 *  \brief Structure defining Valid divider Values for PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1_validDivValues[] =
{
    {1, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV1},
    {2, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV2},
    {3, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV3},
    {4, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV4},
    {5, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV5},
    {6, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV6},
    {7, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV7},
    {8, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_DIV8}
};

/**
 *  \brief Structure defining Valid divider Values for PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2_validDivValues[] =
{
    {1 , PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV1},
    {2 , PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV2},
    {4 , PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV4},
    {8 , PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV8},
    {16, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV16},
    {32, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_POSTDIV32}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CLKIN
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKIN_validDivValues[] =
{
    {1, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV1},
    {2, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV2},
    {3, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV3},
    {4, PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_DIV4}
};

/**
 *  \brief Structure defining Valid divider Values for PMHAL_PRCM_DIV_CLKOUT2_PREDIV1
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKOUT2_PREDIV1_validDivValues[] =
{
    {1, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV1},
    {2, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV2},
    {3, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV3},
    {4, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV4},
    {5, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV5},
    {6, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV6},
    {7, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV7},
    {8, PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_DIV8}
};

/**
 *  \brief Structure defining Valid divider Values for PMHAL_PRCM_DIV_CLKOUT2_PREDIV2
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKOUT2_PREDIV2_validDivValues[] =
{
    {1 , PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV1},
    {2 , PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV2},
    {4 , PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV4},
    {8 , PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV8},
    {16, PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV16},
    {32, PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_POSTDIV32}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_DLL_AGING_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_DLL_AGING_GCLK_validDivValues[] =
{
    {8 , PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV8},
    {16, PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV16},
    {32, PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_DIV32}

};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_UART_CLK
 */
validDivValue_t               PMHAL_PRCM_DIV_UART_CLK_validDivValues[] =
{
    {4, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_MMC_CLK
 */
validDivValue_t               PMHAL_PRCM_DIV_MMC_CLK_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_FUNC_12M_CLK
 */
validDivValue_t               PMHAL_PRCM_DIV_FUNC_12M_CLK_validDivValues[] =
{
    {16, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CPSW_50MHZ_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_CPSW_50MHZ_GCLK_validDivValues[] =
{
    {2, PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_DIV_1_2},
    {5, PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_DIV_1_5}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CPSW_5MHZ_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_CPSW_5MHZ_GCLK_validDivValues[] =
{
    {10, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CORE_200M
 */
validDivValue_t               PMHAL_PRCM_DIV_CORE_200M_validDivValues[] =
{
    {5, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_SYSCLK1
 */
validDivValue_t               PMHAL_PRCM_DIV_SYSCLK1_validDivValues[] =
{
    {1, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CORE_100M
 */
validDivValue_t               PMHAL_PRCM_DIV_CORE_100M_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CORE_25M
 */
validDivValue_t               PMHAL_PRCM_DIV_CORE_25M_validDivValues[] =
{
    {8, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_VTP_CLK
 */
validDivValue_t               PMHAL_PRCM_DIV_VTP_CLK_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_UART0_CLK
 */
validDivValue_t               PMHAL_PRCM_DIV_UART0_CLK_validDivValues[] =
{
    {4, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_CLK_24MHZ
 */
validDivValue_t               PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues[] =
{
    {8, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_GFX_FCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_GFX_FCLK_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_GFX_FCLK),
 PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_MASK,
 PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_SHIFT};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV2_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CLKIN
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKIN_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL0DIV_SHIFT};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_CLKOUT2_PREDIV1
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKOUT2_PREDIV1_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT2_CTRL),
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_MASK,
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2DIV_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CLKOUT2_PREDIV2
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKOUT2_PREDIV2_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT2_CTRL),
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_MASK,
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2POSTDIV_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_DLL_AGING_GCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_DLL_AGING_GCLK_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK),
 PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_DLL_AGING_CLK_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_UART_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_UART_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_MMC_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_MMC_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_FUNC_12M_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_FUNC_12M_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CPSW_50MHZ_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_MAC_CLK),
 PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_MASK,
 PRCM_CM_DPLL_CLKSEL_MAC_CLK_MII_SEL_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CPSW_5MHZ_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CORE_200M
 */
regBitField_t                 PMHAL_PRCM_DIV_CORE_200M_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_SYSCLK1
 */
regBitField_t                 PMHAL_PRCM_DIV_SYSCLK1_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_CORE_100M
 */
regBitField_t                 PMHAL_PRCM_DIV_CORE_100M_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_CORE_25M
 */
regBitField_t                 PMHAL_PRCM_DIV_CORE_25M_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_VTP_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_VTP_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_UART0_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_UART0_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_CLK_24MHZ
 */
regBitField_t                 PMHAL_PRCM_DIV_CLK_24MHZ_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining Divider Elements
 */
const pmhalClockDivider_t     pmhalDividerElems[] =
{
    {   /* PMHAL_PRCM_DIV_GFX_FCLK */
        &PMHAL_PRCM_DIV_GFX_FCLK_regBitField,
        PMHAL_PRCM_DIV_GFX_FCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_GFX_FCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1 */
        &PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1_regBitField,
        PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2 */
        &PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2_regBitField,
        PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLKIN */
        &PMHAL_PRCM_DIV_CLKIN_regBitField,
        PMHAL_PRCM_DIV_CLKIN_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKIN_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLKOUT2_PREDIV1 */
        &PMHAL_PRCM_DIV_CLKOUT2_PREDIV1_regBitField,
        PMHAL_PRCM_DIV_CLKOUT2_PREDIV1_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT2_PREDIV1_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLKOUT2_PREDIV2 */
        &PMHAL_PRCM_DIV_CLKOUT2_PREDIV2_regBitField,
        PMHAL_PRCM_DIV_CLKOUT2_PREDIV2_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT2_PREDIV2_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_DLL_AGING_GCLK */
        &PMHAL_PRCM_DIV_DLL_AGING_GCLK_regBitField,
        PMHAL_PRCM_DIV_DLL_AGING_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_DLL_AGING_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_UART_CLK */
        &PMHAL_PRCM_DIV_UART_CLK_regBitField,
        PMHAL_PRCM_DIV_UART_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_UART_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_MMC_CLK */
        &PMHAL_PRCM_DIV_MMC_CLK_regBitField,
        PMHAL_PRCM_DIV_MMC_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_MMC_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_FUNC_12M_CLK */
        &PMHAL_PRCM_DIV_FUNC_12M_CLK_regBitField,
        PMHAL_PRCM_DIV_FUNC_12M_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_FUNC_12M_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK */
        &PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_regBitField,
        PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CPSW_50MHZ_CLK */
        &PMHAL_PRCM_DIV_CPSW_50MHZ_CLK_regBitField,
        PMHAL_PRCM_DIV_CPSW_50MHZ_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_50MHZ_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CPSW_5MHZ_CLK */
        &PMHAL_PRCM_DIV_CPSW_5MHZ_CLK_regBitField,
        PMHAL_PRCM_DIV_CPSW_5MHZ_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CPSW_5MHZ_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CORE_200M */
        &PMHAL_PRCM_DIV_CORE_200M_regBitField,
        PMHAL_PRCM_DIV_CORE_200M_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CORE_200M_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_SYSCLK1 */
        &PMHAL_PRCM_DIV_SYSCLK1_regBitField,
        PMHAL_PRCM_DIV_SYSCLK1_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_SYSCLK1_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CORE_100M */
        &PMHAL_PRCM_DIV_CORE_100M_regBitField,
        PMHAL_PRCM_DIV_CORE_100M_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CORE_100M_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CORE_25M */
        &PMHAL_PRCM_DIV_CORE_25M_regBitField,
        PMHAL_PRCM_DIV_CORE_25M_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CORE_25M_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_VTP_CLK */
        &PMHAL_PRCM_DIV_VTP_CLK_regBitField,
        PMHAL_PRCM_DIV_VTP_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_VTP_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_UART0_CLK */
        &PMHAL_PRCM_DIV_UART0_CLK_regBitField,
        PMHAL_PRCM_DIV_UART0_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_UART0_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CLK_24MHZ */
        &PMHAL_PRCM_DIV_CLK_24MHZ_regBitField,
        PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues,
                   validDivValue_t)
    }
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_GFX_GFCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_GFX_GFCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CORE_PLL},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     PRCM_CM_DPLL_CLKSEL_GFX_FCLK_PER_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CLKOUT_32K_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_CLKOUT_32K_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SEL0},
    {PMHAL_PRCM_ROOT_CLK_32K_RTC,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SEL1}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_MUX_CLKOUT_32K_MUX,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL0},
    {PMHAL_PRCM_DIV_SYSCLK1,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL1},
    {PMHAL_PRCM_DPLL_DDR, /* M2 */
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL2},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL3},
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL4},
    {PMHAL_PRCM_DPLL_MPU, /* M2 */
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2SOURCE_SEL5}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CLKOUT1_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_CLKOUT1_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DIV_CLKIN,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL0},
    {PMHAL_PRCM_MUX_CLKOUT_32K_MUX,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL1},
    {PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2,
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL2},
    {PMHAL_PRCM_DPLL_EXTDEV, /* M2 */
     PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CLKOUT2_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_CLKOUT2_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_MUX_CLKOUT_32K_MUX,
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL0},
    {PMHAL_PRCM_DIV_SYSCLK1,
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL1},
    {PMHAL_PRCM_DPLL_DDR, /* M2 */
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL2},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL3},
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL4},
    {PMHAL_PRCM_DPLL_MPU, /* M2 */
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL5},
    {PMHAL_PRCM_DPLL_EXTDEV, /* M2 */
     PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SEL6}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_MGC_FGCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_MGC_FGCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_MAIN_XTAL},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_PER_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_DISP_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_DISP_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_DISP_PLL_CLKOUTM2},
    {PMHAL_PRCM_DPLL_CORE, /* M5 */
     PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CORE_PLL_CLKOUTM5},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_PER_PLL_CLKOUTM2}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_L3F},
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_DISP}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER7_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER2_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER3_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER4_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER5_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER6_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER8_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER8_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_32KHZ},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_RSVD}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER9_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER9_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_32KHZ},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_RSVD}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER10_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER10_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_32KHZ},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_RSVD}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER11_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER11_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_32KHZ},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_RSVD}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
validEnumValue_t       PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DIV_SYSCLK1,
     PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_HSDIV_CORE_M4},
    {PMHAL_PRCM_DPLL_CORE, /* M5 */
     PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_HSDIV_CORE_M5},
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_DISP_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_USIM0_FCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_USIM0_FCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_USIM_FCLK_OSC_CLK},
    {PMHAL_PRCM_DIV_CORE_200M,
     PRCM_CM_DPLL_CLKSEL_USIM_FCLK_CORE_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_USIM0_FCLK32_MUX
 */
validEnumValue_t       PMHAL_PRCM_MUX_USIM0_FCLK32_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_CLK_RC32K},
    {PMHAL_PRCM_ROOT_CLK_32K_MOSC,
     PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_MOSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_PER_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_USIM1_FCLK_MUX
 */
validEnumValue_t          PMHAL_PRCM_MUX_USIM1_FCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_USIM_FCLK_OSC_CLK},
    {PMHAL_PRCM_DIV_CORE_200M,
     PRCM_CM_DPLL_CLKSEL_USIM_FCLK_CORE_PLL}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
validEnumValue_t            PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_32KHZ},
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_TCLKIN},
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_RC32K},
    {PMHAL_PRCM_ROOT_CLK_32K_RTC,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_RTC_32K},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_TPM_32K}
};

#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER0_GCLK_MUX.  Note: Not implemented on actual
 *         device.
 */
validEnumValue_t            PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     UNKNOWN}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_WDT0_GCLK_MUX.  Note: Not implemented on actual
 *         device.
 */
validEnumValue_t              PMHAL_PRCM_MUX_WDT0_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     UNKNOWN}
};
#endif

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_WDT1_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     PRCM_CM_DPLL_CLKSEL_WDT1_CLK_RC32K},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_WDT1_CLK_CLKDIV_32KHZ}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX
 */
validEnumValue_t       PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RTC,
     PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_RTC_32K},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_TPM_32K}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
validEnumValue_t            PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RC,
     PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_CLK_RC32K},
    {PMHAL_PRCM_ROOT_CLK_32K_RTC,
     PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_OSC_32K},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_PER_PLL},
    {PMHAL_PRCM_ROOT_CLK_32K_MOSC,
     PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_SYS_CLK},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_CLK_32K_TPM}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX
 */
validEnumValue_t            PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_32K_RTC,
     PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_RTC_32K},
    {PMHAL_PRCM_ROOT_CLK_32K_TPM,
     PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_TPM_32K},
    {PMHAL_PRCM_ROOT_CLK_32K_PER,
     PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_PER_PLL_32K}
};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_GFX_GFCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_GFX_GFCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_GFX_FCLK),
 PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_MASK,
 PRCM_CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CLKOUT_32K_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CLKOUT_32K_MUX_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT_32KSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SEL2DIV1_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CLKOUT1_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CLKOUT1_MUX_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT1_CTRL),
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_MASK,
 PRCM_CM_CLKOUT1_CTRL_CLKOUT1SOURCE_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CLKOUT2_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CLKOUT2_MUX_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_CLKOUT2_CTRL),
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_MASK,
 PRCM_CM_CLKOUT2_CTRL_CLKOUT2SOURCE_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_MGC_FGCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_MGC_FGCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK),
 PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_MAG_CARD_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_DISP_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_DISP_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK),
 PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK),
 PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_ICSS_OCP_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER7_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER7_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER7_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER2_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER2_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER2_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER3_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER3_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER3_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER4_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER4_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER4_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER5_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER5_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER5_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER6_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER6_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER6_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER8_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER8_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER8_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER8_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER9_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER9_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER9_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER9_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER10_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER10_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER10_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER10_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER11_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER11_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER11_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER11_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK),
 PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_CPTS_RFT_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_USIM0_FCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_USIM0_FCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_USIM_FCLK(0)),
 PRCM_CM_DPLL_CLKSEL_USIM_FCLK_MASK,
 PRCM_CM_DPLL_CLKSEL_USIM_FCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_USIM0_FCLK32_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_USIM0_FCLK32_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_USIM_DBCLK),
 PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_MASK,
 PRCM_CM_DPLL_CLKSEL_USIM_DBCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_USIM1_FCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_USIM1_FCLK_MUX_regBitField =
{(SOC_CM_DEVICE_REG + PRCM_CM_DPLL_CLKSEL_USIM_FCLK(1)),
 PRCM_CM_DPLL_CLKSEL_USIM_FCLK_MASK,
 PRCM_CM_DPLL_CLKSEL_USIM_FCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER1_CLK),
 PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_TIMER1_CLK_SHIFT};

#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER0_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + UNKNOWN),
 CM_CAM_VIP1_CLKCTRL_CLKSEL_MASK,
 CM_CAM_VIP1_CLKCTRL_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_WDT0_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_WDT0_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + UNKNOWN),
 CM_CAM_VIP2_CLKCTRL_CLKSEL_MASK,
 CM_CAM_VIP2_CLKCTRL_CLKSEL_SHIFT};
#endif

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_WDT1_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_WDT1_CLK),
 PRCM_CM_DPLL_CLKSEL_WDT1_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_WDT1_CLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK),
 PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_MASK,
 PRCM_CM_DPLL_CLKSEL_USBPHY32KHZ_GCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK),
 PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_MASK,
 PRCM_CM_DPLL_CLKSEL_GPIO0_DBCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX_regBitField =
{(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK),
 PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_MASK,
 PRCM_CM_DPLL_CLKSEL_SYNCTIMER_CLK_SHIFT};

/**
 *  \brief Structure defining Mux Elements
 */
const pmhalMultiplexer_t      pmhalMultiplexerElems[] =
{
    {   /* PMHAL_PRCM_MUX_GFX_GFCLK_MUX */
        &PMHAL_PRCM_MUX_GFX_GFCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_GFX_GFCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_GFX_GFCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_CLKOUT_32K_MUX */
        &PMHAL_PRCM_MUX_CLKOUT_32K_MUX_regBitField,
        PMHAL_PRCM_MUX_CLKOUT_32K_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CLKOUT_32K_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX */
        &PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX_regBitField,
        PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_CLKOUT1_MUX */
        &PMHAL_PRCM_MUX_CLKOUT1_MUX_regBitField,
        PMHAL_PRCM_MUX_CLKOUT1_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CLKOUT1_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_CLKOUT2_MUX */
        &PMHAL_PRCM_MUX_CLKOUT2_MUX_regBitField,
        PMHAL_PRCM_MUX_CLKOUT2_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CLKOUT2_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_MGC_FGCLK_MUX */
        &PMHAL_PRCM_MUX_MGC_FGCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_MGC_FGCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_MGC_FGCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_DISP_CLK_MUX */
        &PMHAL_PRCM_MUX_DISP_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_DISP_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_DISP_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX */
        &PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER7_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER7_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER7_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER7_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER2_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER2_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER2_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER2_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER3_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER3_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER3_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER3_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER4_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER4_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER4_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER4_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER5_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER5_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER5_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER5_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER6_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER6_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER6_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER6_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER8_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER8_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER8_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER8_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER9_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER9_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER9_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER9_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER10_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER10_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER10_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER10_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER11_CLK_MUX */
        &PMHAL_PRCM_MUX_TIMER11_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER11_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER11_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX */
        &PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_USIM0_FCLK_MUX */
        &PMHAL_PRCM_MUX_USIM0_FCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_USIM0_FCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_USIM0_FCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_USIM0_FCLK32_MUX */
        &PMHAL_PRCM_MUX_USIM0_FCLK32_MUX_regBitField,
        PMHAL_PRCM_MUX_USIM0_FCLK32_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_USIM0_FCLK32_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_USIM1_FCLK_MUX */
        &PMHAL_PRCM_MUX_USIM1_FCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_USIM1_FCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_USIM1_FCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_TIMER1_GCLK_MUX */
        &PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
    {   /* PMHAL_PRCM_MUX_TIMER0_GCLK_MUX */
        &PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_WDT0_GCLK_MUX */
        &PMHAL_PRCM_MUX_WDT0_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_WDT0_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_WDT0_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
#endif
    {   /* PMHAL_PRCM_MUX_WDT1_GCLK_MUX */
        &PMHAL_PRCM_MUX_WDT1_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_WDT1_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_WDT1_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX */
        &PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX */
        &PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX */
        &PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX_validEnumValues,
                   validEnumValue_t)
    }
};

/** \brief Array defining the list of valid system clock frequencies in kHz. */
const uint32_t                gPmhalSysClkFreqkHz[PMHAL_PRCM_SYSCLK_COUNT] =
{
    19200U, /* PMHAL_PRCM_SYSCLK_19_2_MHZ */
    24000U, /* PMHAL_PRCM_SYSCLK_24_MHZ */
    25000U, /* PMHAL_PRCM_SYSCLK_25_MHZ */
    26000U  /* PMHAL_PRCM_SYSCLK_26_MHZ */
};

/**
 *  \note  The following structures should not be changed as they define silicon
 *         characteristics or supported frequencies for a given OPP.
 */
/**
 *
 * \brief OPP Table for AM335x devices. This is a fixed table and should not be
 *        changed.
 *
 *   2. Frequency Table
 *     +-----------+-----------+--------------+-------------+-------------+
 *     | Voltage   |  Module   |   OPP_LOW    |   OPP_NOM   |    OPP_OD   |
 *     | Domain    |           | Max Freq MHz | Max Freq MHz| Max Freq MHz|
 *     +-----------+-----------+--------------+-------------+-------------+
 *     | VD_MPU    |  MPU      |     300.0    |    600.0    |     720.0   |
 *     +-----------+-----------+--------------+-------------+-------------+
 *                             |   OPP_HIGH   |  OPP_HIGH2  |
 *                             | Max Freq MHz | Max Freq MHz|
 *                             +--------------+-------------+
 *                             |     800.0    |    1000.0   |
 *                             +------------ -+-------------+
 *
 */
uint32_t                      pmhalOppModuleMaxRate[PMHAL_PRCM_CPU_ID_COUNT][
    PMHAL_VM_OPP_MAX] =
{
    /* PMLIB_CPU_ID_MPU */
    {300000000U, 600000000U, 720000000U, 800000000U, 1000000000U},
};

/** \brief Array defining the dependent CPU's for a given CPU ID. */
pmhalPrcmCpuId_t              pmhalDepCpuList[] =
{
    PMHAL_PRCM_CPU_ID_UNDEF
};

pmhalPrcmModuleId_t           pmhalCpuModuleId[] =
{
    PMHAL_PRCM_MOD_MPU
};

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

