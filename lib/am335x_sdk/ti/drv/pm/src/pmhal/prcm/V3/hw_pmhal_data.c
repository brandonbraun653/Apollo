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
    PMHAL_PRCM_PHY_BANK_RAM_MEM
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
    PMHAL_PRCM_RG_GFX_PWRON_RST,
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
    PMHAL_PRCM_RG_DMA_L3_RST,
    PMHAL_PRCM_RG_ICSS_RST,
    PMHAL_PRCM_RG_PCI_RST,
    PMHAL_PRCM_RG_PER_DOM_RST,
    PMHAL_PRCM_RG_USB_POR_RST,
    PMHAL_PRCM_RG_WKUP_DOM_RST
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
 *  \brief structure defining Reset Domain List of PMHAL_PRCM_PD_WKUP
 */
pmhalPrcmResetGroupId_t         PMHAL_PRCM_PD_WKUP_resetIdList[] =
{
    PMHAL_PRCM_RG_DPLL_RST,
    PMHAL_PRCM_RG_EMU_EARLY_PWRON_RST,
    PMHAL_PRCM_RG_EMU_PWRON_RST,
    PMHAL_PRCM_RG_EMU_RST,
    PMHAL_PRCM_RG_M3_PWRON_RST,
    PMHAL_PRCM_RG_WKUP_DOM_RST,
    PMHAL_PRCM_RG_WKUP_M3_RST
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
    PMHAL_PRCM_CD_GFX_L3,
    PMHAL_PRCM_CD_L4LS_GFX
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
    PMHAL_PRCM_CD_L4HS,
    PMHAL_PRCM_CD_PER_OCPWP_L3,
    PMHAL_PRCM_CD_ICSS_OCP,
    PMHAL_PRCM_CD_CPSW_125MHZ,
    PMHAL_PRCM_CD_LCD_L3,
    PMHAL_PRCM_CD_CLK_24MHZ
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
    PMHAL_PRCM_CD_L3_AON
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
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_STATE_ON_INACTIVE) |
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
        (SOC_PRM_CEFUSE_REGS + PRM_CEFUSE_PM_CEFUSE_PWRSTCTRL),
        (SOC_PRM_CEFUSE_REGS + PRM_CEFUSE_PM_CEFUSE_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_GFX */
        PMHAL_PRCM_VD_CORE,
        PRM_GFX_PM_GFX_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRM_GFX_PM_GFX_PWRSTCTRL_LOGICRETSTATE,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_RETENTION) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_STATE_ON_ACTIVE)),
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_RET_STATUS_CSWR),
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
        (SOC_PRM_GFX_REGS + PRM_GFX_PM_GFX_PWRSTCTRL),
        (SOC_PRM_GFX_REGS + PRM_GFX_PM_GFX_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_MPU */
        PMHAL_PRCM_VD_MPU,
        PRM_MPU_PM_MPU_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTCTRL_LOGICRETSTATE,
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
        (SOC_PRM_MPU_REGS + PRM_MPU_PM_MPU_PWRSTCTRL),
        (SOC_PRM_MPU_REGS + PRM_MPU_PM_MPU_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_RTC */
        PMHAL_PRCM_VD_RTC,
        PRM_RTC_PM_RTC_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRM_RTC_PM_RTC_PWRSTCTRL_LOGICRETSTATE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        0,
        VSIZE_TYPE(PMHAL_PRCM_PD_RTC_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_RTC_clockDomainList,
                   pmhalPrcmCdId_t),
        NULL,
        PMHAL_PRCM_PD_RTC_resetIdList,
        PMHAL_PRCM_PD_RTC_clockDomainList,
        (SOC_PRM_RTC_REGS + PRM_RTC_PM_RTC_PWRSTCTRL),
        (SOC_PRM_RTC_REGS + PRM_RTC_PM_RTC_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_WKUP */
        PMHAL_PRCM_VD_CORE,
        PRM_WKUP_PM_WKUP_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRM_WKUP_PM_WKUP_PWRSTCTRL_LOGICRETSTATE,
        PMHAL_VALUE_NOTAPPLICABLE,
        PMHAL_VALUE_NOTAPPLICABLE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_PD_LOW_PWR_REQUEST)),
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_phyMemIdList,
                   pmhalPrcmPhyMemBankId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_resetIdList,
                   pmhalPrcmResetGroupId_t),
        VSIZE_TYPE(PMHAL_PRCM_PD_WKUP_clockDomainList,
                   pmhalPrcmCdId_t),
        PMHAL_PRCM_PD_WKUP_phyMemIdList,
        PMHAL_PRCM_PD_WKUP_resetIdList,
        PMHAL_PRCM_PD_WKUP_clockDomainList,
        (SOC_PRM_WKUP_REGS + PRM_WKUP_PM_WKUP_PWRSTCTRL),
        (SOC_PRM_WKUP_REGS + PRM_WKUP_PM_WKUP_PWRSTST)
    },
    {
        /* PMHAL_PRCM_PD_PER */
        PMHAL_PRCM_VD_CORE,
        PRM_PER_PM_PER_PWRSTCTRL_LOGICRETSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTCTRL_LOGICRETSTATE,
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
        (SOC_PRM_PER_REGS + PRM_PER_PM_PER_PWRSTCTRL),
        (SOC_PRM_PER_REGS + PRM_PER_PM_PER_PWRSTST)
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
    }
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_PER_ICSS_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_PER_ICSS_RST_rstCtrlRegBitField =
{
    (SOC_PRM_PER_REGS + PRM_PER_RM_PER_RSTCTRL),
    PRM_PER_RM_PER_RSTCTRL_ICSS_LRST_SHIFT
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_WKUP_M3_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_WKUP_M3_RST_rstCtrlRegBitField =
{
    (SOC_PRM_WKUP_REGS + PRM_WKUP_RM_WKUP_RSTCTRL),
    PRM_WKUP_RM_WKUP_RSTCTRL_WKUP_M3_LRST_SHIFT
};

/**
 *  \brief structure defining STATUS Register for PMHAL_PRCM_RG_WKUP_M3_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_WKUP_M3_RST_rstStRegBitField =
{
    (SOC_PRM_WKUP_REGS + PRM_WKUP_RM_WKUP_RSTST),
    PRM_WKUP_RM_WKUP_RSTST_WKUP_M3_LRST_SHIFT
};

/**
 *  \brief structure defining CTRL Register for PMHAL_PRCM_RG_GFX_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_GFX_RST_rstCtrlRegBitField =
{
    (SOC_PRM_GFX_REGS + PRM_GFX_RM_GFX_RSTCTRL),
    PRM_GFX_RM_GFX_RSTCTRL_GFX_RST_SHIFT
};

/**
 *  \brief structure defining STATUS Register for PMHAL_PRCM_RG_GFX_RST
 */
regBitFieldShift_t              PMHAL_PRCM_RG_GFX_RST_rstStRegBitField =
{
    (SOC_PRM_GFX_REGS + PRM_GFX_RM_GFX_RSTST),
    PRM_GFX_RM_GFX_RSTST_GFX_RST_SHIFT
};

/**
 *  \brief structure defining programmable Reset Domain Elements
 */
const pmhalReset_t              pmhalResetDomainElems[] =
{
    {   /* PMHAL_PRCM_RG_PER_ICSS_RST */
        &PMHAL_PRCM_RG_PER_ICSS_RST_rstCtrlRegBitField,
        NULL,
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
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTCTRL),
    PRM_DEVICE_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_SHIFT
};

/**
 *  \brief structure defining Control Register for
 *         PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET
 */
regBitFieldShift_t
    PMHAL_PRCM_PD_RM_OCCUR_GLOBAL_COLD_RESET_rstctrlBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTCTRL),
    PRM_DEVICE_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_SHIFT
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
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_GLOBAL_COLD_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST
 */
regBitFieldShift_t
    PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_GLOBAL_WARM_SW_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST
 */
regBitFieldShift_t    PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_MPU_SECURITY_VIOL_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST
 */
regBitFieldShift_t
    PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_EXTERNAL_WARM_RST_SHIFT
};

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_ICEPICK_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_ICEPICK_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_ICEPICK_RST_SHIFT
};

#if 0 /* WDT0 is not supported according to AM335x TRM and CTT */
/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_WDT0_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_WDT0_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_WDT0_RST_SHIFT
};
#endif

/**
 *  \brief structure defining Status Register for
 *         PMHAL_PRCM_GLB_RG_WDT1_RST
 */
regBitFieldShift_t              PMHAL_PRCM_GLB_RG_WDT1_RST_rstStBitField =
{
    (SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_RSTST),
    PRM_DEVICE_PRM_RSTST_WDT1_RST_SHIFT
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
#if 0 /* WDT0 is not supported according to AM335x TRM and CTT */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    PMHAL_PRCM_MOD_DES,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_MOD_ELM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    PMHAL_PRCM_MOD_EPWMSS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    PMHAL_PRCM_MOD_EPWMSS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    PMHAL_PRCM_MOD_EPWMSS2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
    PMHAL_PRCM_MOD_GPIO6,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
    PMHAL_PRCM_MOD_MAILBOX1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_PRCM_MOD_MMC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_PRCM_MOD_MMC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
    PMHAL_PRCM_MOD_OCPWP,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCPWP */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_MOD_SPINLOCK,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    PMHAL_PRCM_MOD_UART1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    PMHAL_PRCM_MOD_UART2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    PMHAL_PRCM_MOD_UART3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    PMHAL_PRCM_MOD_UART4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    PMHAL_PRCM_MOD_UART5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_PRCM_MOD_MCASP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_MOD_MCASP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
    PMHAL_PRCM_MOD_MCASP2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_PRCM_MOD_MMC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    PMHAL_PRCM_MOD_USB0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    PMHAL_PRCM_MOD_AES0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES1
    PMHAL_PRCM_MOD_AES1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    PMHAL_PRCM_MOD_EMIF,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    PMHAL_PRCM_MOD_L3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    PMHAL_PRCM_MOD_L3_INSTR,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
    PMHAL_PRCM_MOD_MLB,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    PMHAL_PRCM_MOD_MSTR_EXPS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    PMHAL_PRCM_MOD_OCMCRAM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
    PMHAL_PRCM_MOD_PCIE,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */
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
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4HS modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4HS_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    PMHAL_PRCM_MOD_L4_HS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_PER_OCPWP_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_PER_OCPWP_L3_modules[] =
{
    PMHAL_PRCM_MOD_UNDEF
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
 *  \brief Structure defining PMHAL_PRCM_CD_CLK_24MHZ modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_CLK_24MHZ_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    PMHAL_PRCM_MOD_CLKDIV32K
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_DMA_L3 modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_DMA_L3_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
    PMHAL_PRCM_MOD_DMA4_CRYPTO
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4FW modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4FW_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    PMHAL_PRCM_MOD_EMIF_FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    PMHAL_PRCM_MOD_L4FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4_WKUP modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4_WKUP_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_PRCM_MOD_ADC_TSC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    PMHAL_PRCM_MOD_L4WKUP,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    PMHAL_PRCM_MOD_WKUP_M3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
    PMHAL_PRCM_MOD_BITBLT,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    PMHAL_PRCM_MOD_GFX,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
    PMHAL_PRCM_MOD_MMU,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
};

/**
 *  \brief Structure defining PMHAL_PRCM_CD_L4LS_GFX modules
 */
pmhalPrcmModuleId_t             PMHAL_PRCM_CD_L4LS_GFX_modules[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
    PMHAL_PRCM_MOD_MMU_CFG
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */
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
        (SOC_CM_PER_REGS + CM_PER_L4LS_CLKSTCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_L3S_CLKSTCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_L3_CLKSTCTRL),
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
    {   /* PMHAL_PRCM_CD_L4HS */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REGS + CM_PER_L4HS_CLKSTCTRL),
        PMHAL_PRCM_CD_L4HS_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4HS_modules,
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
        (SOC_CM_PER_REGS + CM_PER_OCPWP_L3_CLKSTCTRL),
        NULL,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        0U,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_ICSS_OCP */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REGS + CM_PER_ICSS_CLKSTCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_CPSW_CLKSTCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_LCDC_CLKSTCTRL),
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
    {   /* PMHAL_PRCM_CD_CLK_24MHZ */
        PMHAL_PRCM_PD_PER,
        (SOC_CM_PER_REGS + CM_PER_CLK_24MHZ_CLKSTCTRL),
        PMHAL_PRCM_CD_CLK_24MHZ_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_CLK_24MHZ_modules,
                   pmhalPrcmModuleId_t),
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP) |
                   ((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_DMA_L3 */
        PMHAL_PRCM_PD_PER,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_CD_DMA_L3_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_DMA_L3_modules,
                   pmhalPrcmModuleId_t),
        0U
    },
    {   /* PMHAL_PRCM_CD_L4FW */
        PMHAL_PRCM_PD_PER,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_CD_L4FW_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4FW_modules,
                   pmhalPrcmModuleId_t),
        0U
    },
    {   /* PMHAL_PRCM_CD_L4_WKUP */
        PMHAL_PRCM_PD_WKUP,
        (SOC_CM_WKUP_REGS + CM_WKUP_CLKSTCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_L3_AON_CLKSTCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL),
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
    {   /* PMHAL_PRCM_CD_MPU */
        PMHAL_PRCM_PD_MPU,
        (SOC_CM_MPU_REGS + CM_MPU_CLKSTCTRL),
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
                    (uint32_t) PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP))
    },
    {   /* PMHAL_PRCM_CD_L4_RTC */
        PMHAL_PRCM_PD_RTC,
        (SOC_CM_RTC_REGS + CM_RTC_CLKSTCTRL),
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
        (SOC_CM_GFX_REGS + CM_GFX_L3_CLKSTCTRL),
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
    {   /* PMHAL_PRCM_CD_L4LS_GFX */
        PMHAL_PRCM_PD_GFX,
        (SOC_CM_GFX_REGS + CM_GFX_L4LS_GFX_CLKSTCTRL),
        PMHAL_PRCM_CD_L4LS_GFX_modules,
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_CD_L4LS_GFX_modules,
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
        (SOC_CM_CEFUSE_REGS + CM_CEFUSE_CLKSTCTRL),
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
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_PER),
 CM_WKUP_CM_DIV_M2_DPLL_PER_DPLL_CLKOUT_DIV,
 CM_WKUP_CM_DIV_M2_DPLL_PER_DPLL_CLKOUT_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_PER_DCO_LDO
 *         divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_PER_DCO_LDO_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKDCOLDO_DPLL_PER),
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_MPU_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_MPU_M2_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_MPU),
 CM_WKUP_CM_DIV_M2_DPLL_MPU_DPLL_CLKOUT_DIV,
 CM_WKUP_CM_DIV_M2_DPLL_MPU_DPLL_CLKOUT_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_DDR_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_DDR_M2_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_DDR),
 CM_WKUP_CM_DIV_M2_DPLL_DDR_DPLL_CLKOUT_DIV,
 CM_WKUP_CM_DIV_M2_DPLL_DDR_DPLL_CLKOUT_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_DISP_M2 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_DISP_M2_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_DISP),
 CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV,
 CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M4 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M4_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M4_DPLL_CORE),
 CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV,
 CM_WKUP_CM_DIV_M4_DPLL_CORE_HSDIVIDER_CLKOUT1_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M5 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M5_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M5_DPLL_CORE),
 CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV,
 CM_WKUP_CM_DIV_M5_DPLL_CORE_HSDIVIDER_CLKOUT2_DIV_SHIFT};

/**
 *  \brief Structure defining registers for PMHAL_PRCM_DPLL_CORE_M6 divider
 */
regBitField_t                 PMHAL_PRCM_DPLL_CORE_M6_regBitField =
{(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M6_DPLL_CORE),
 CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV,
 CM_WKUP_CM_DIV_M6_DPLL_CORE_HSDIVIDER_CLKOUT3_DIV_SHIFT};

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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_PER),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_PER),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_AUTOIDLE_DPLL_PER),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_PERIPH),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_DELTAMSTEP_DPLL_PER),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_MODFREQDIV_DPLL_PER),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKDCOLDO_DPLL_PER),
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_PERIPH_DPLL_MULT,
        CM_WKUP_CM_AUTOIDLE_DPLL_PER_AUTO_DPLL_MODE,
        CM_WKUP_CM_CLKMODE_DPLL_PER_DPLL_EN,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_DPLL_POWER_MODE_LP_STP_MODE) |
                   ((uint32_t) 1U <<
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_MPU),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_MPU),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_AUTOIDLE_DPLL_MPU),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_MPU),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_DELTAMSTEP_DPLL_MPU),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_MODFREQDIV_DPLL_MPU),
        PMHAL_REG_NOTAPPLICABLE,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_MPU_DPLL_MULT,
        CM_WKUP_CM_AUTOIDLE_DPLL_MPU_AUTO_DPLL_MODE,
        CM_WKUP_CM_CLKMODE_DPLL_MPU_DPLL_EN,
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DDR),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DDR),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_AUTOIDLE_DPLL_DDR),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DDR),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_DELTAMSTEP_DPLL_DDR),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_MODFREQDIV_DPLL_DDR),
        PMHAL_REG_NOTAPPLICABLE,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_DDR_DPLL_MULT,
        CM_WKUP_CM_AUTOIDLE_DPLL_DDR_AUTO_DPLL_MODE,
        CM_WKUP_CM_CLKMODE_DPLL_DDR_DPLL_EN,
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DISP),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DISP),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_AUTOIDLE_DPLL_DISP),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DISP),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_DELTAMSTEP_DPLL_DISP),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_MODFREQDIV_DPLL_DISP),
        PMHAL_REG_NOTAPPLICABLE,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_MULT,
        CM_WKUP_CM_AUTOIDLE_DPLL_DISP_AUTO_DPLL_MODE,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN,
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
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_CORE),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_CORE),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_AUTOIDLE_DPLL_CORE),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_CORE),
        PMHAL_REG_NOTAPPLICABLE,
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_DELTAMSTEP_DPLL_CORE),
        (SOC_CM_WKUP_REGS + CM_WKUP_CM_SSC_MODFREQDIV_DPLL_CORE),
        PMHAL_REG_NOTAPPLICABLE,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_CORE_DPLL_MULT,
        CM_WKUP_CM_AUTOIDLE_DPLL_CORE_AUTO_DPLL_MODE,
        CM_WKUP_CM_CLKMODE_DPLL_CORE_DPLL_EN,
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_AES1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_AES1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CLKDIV32K
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CLK_24MHZ,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_CLK_24MHZ_CLKSTCTRL_CLKACTIVITY_CLK_24MHZ_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CPGMAC0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_CPSW_CLKSTCTRL_CLKACTIVITY_CPSW_125MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_250MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4HS_CLKSTCTRL_CLKACTIVITY_CPSW_250MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_50MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4HS_CLKSTCTRL_CLKACTIVITY_CPSW_50MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_5MHZ_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4HS_CLKSTCTRL_CLKACTIVITY_CPSW_5MHZ_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_CPTS_RFT_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DCAN0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DCAN0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_CAN_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_CAN_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_CAN_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DES
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DES_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_DMA4_CRYPTO
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_DMA4_CRYPTO_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_DMA_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
    {PMHAL_PRCM_CLK_DMA_L4S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ELM
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ELM_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EMIF
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EMIF_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_EMIF_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_EMIF_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_EMIF_FW
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4FW_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_1_GDBCLK,
     CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK_SHIFT,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_1_GDBCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_2_GDBCLK,
     CM_PER_GPIO2_CLKCTRL_OPTFCLKEN_GPIO_2_GDBCLK_SHIFT,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_2_GDBCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_3_GDBCLK,
     CM_PER_GPIO3_CLKCTRL_OPTFCLKEN_GPIO_3_GDBCLK_SHIFT,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_3_GDBCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_4_GDBCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_5_GDBCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPIO6
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPIO6_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GPIO_6_GDBCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GPMC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GPMC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_I2C1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_I2C1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_I2C_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_SHIFT},
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
     CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_ICSS_IEP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_ICSS_OCP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_ICSS_OCP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_ICSS_UART_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_ICSS_CLKSTCTRL_CLKACTIVITY_ICSS_UART_GCLK_SHIFT},
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
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L3
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L3_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4FW
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4FW_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4FW_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_L4_HS
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_L4_HS_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4HS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4HS_CLKSTCTRL_CLKACTIVITY_L4HS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_LCDC_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_LCD_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_LCDC_CLKSTCTRL_CLKACTIVITY_LCDC_L3_OCP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_LCD_L4S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_LCDC_CLKSTCTRL_CLKACTIVITY_LCDC_L4_OCP_GCLK_SHIFT}
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MAILBOX0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MAILBOX1
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MAILBOX1_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MCASP0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MCASP0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MCASP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MCASP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MCASP2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MCASP2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MCASP_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MCASP_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MLB
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MLB_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMC0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMC0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_MMC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_MMC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_OCPWP
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_OCPWP_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCPWP */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_PCIE
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_PCIE_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_PKA
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_PKA_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_RNG
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_RNG_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_SPI_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_SPI_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_SPINLOCK
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER2
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER2_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER2_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER2_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER3_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER4_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER4_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER5_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER5_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER6_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER6_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_TIMER7_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_TIMER7_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TPCC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TPCC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
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
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_L4LS_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_UART_GFCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_UART_GFCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_USB0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_USB0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L3S_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_PER_L3S_CLKSTCTRL_CLKACTIVITY_L3S_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_USB_PLL_CLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_BITBLT
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_BITBLT_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_GFX_L3_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4LS_GFX_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L4LS_GFX_CLKSTCTRL_CLKACTIVITY_L4LS_GFX_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_GFX
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_GFX_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_GFX_L3_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_GFX_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_GFX_FCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMU
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMU_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_GFX_L3_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L3_CLKSTCTRL_CLKACTIVITY_GFX_L3_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_MMU_CFG
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_MMU_CFG_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4LS_GFX_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_GFX_L4LS_GFX_CLKSTCTRL_CLKACTIVITY_L4LS_GFX_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_ADC_TSC
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_ADC_FCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_ADC_FCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_CONTROL
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_DEBUGSS_CLKCTRL_OPTFCLKEN_DBGSYSCLK_SHIFT,
     CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DBGSYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_DEBUG_CLKA_SHIFT},
    {PMHAL_PRCM_CLK_L3_AON_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CM_L3_AON_CLKSTCTRL_CLKACTIVITY_L3_AON_GCLK_SHIFT},
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
     CM_WKUP_GPIO0_CLKCTRL_OPTFCLKEN_GPIO0_GDBCLK_SHIFT,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_GPIO0_GDBCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_I2C0_GFCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_SR_SYSCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_TIMER0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_TIMER0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_TIMER0_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER0_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_TIMER1_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_UART0_GFCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
};
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */

#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
/**
 *  \brief structure defining Clock Select Configuration for
 *          PMHAL_PRCM_MOD_WDT0
 */
pmhalClockSelConfig_t         PMHAL_PRCM_MOD_WDT0_ClkSelectCfg[] =
{
    {PMHAL_PRCM_CLK_WDT0_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT0_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_WDT1_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_WKUP_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_WKUP_CLKSTCTRL_CLKACTIVITY_L4_WKUP_GCLK_SHIFT},
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
     CM_WKUP_CM_L4_WKUP_AON_CLKSTCTRL_CLKACTIVITY_L4_WKUP_AON_GCLK_SHIFT},
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
     CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_CUST_EFUSE_SYS_CLK_SHIFT},
    {PMHAL_PRCM_CLK_L4_CEFUSE_GCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_CEFUSE_CLKSTCTRL_CLKACTIVITY_L4_CEFUSE_GICLK_SHIFT},
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
     CM_RTC_CLKSTCTRL_CLKACTIVITY_L4_RTC_GCLK_SHIFT},
    {PMHAL_PRCM_CLK_RTC_32KCLK,
     PMHAL_CLKSELCTRL_NOTAPPLICABLE,
     CM_RTC_CLKSTCTRL_CLKACTIVITY_RTC_32KCLK_SHIFT},
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
     CM_MPU_CLKSTCTRL_CLKACTIVITY_MPU_CLK_SHIFT}
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

/**
 *  \brief Structure defining SysConfig Elements
 */
const pmhalSysConfig_t        pmhalSysConfigElems[] =
{
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    {   /* PMHAL_PRCM_MOD_GPMC */
        (SOC_GPMC_0_REGS + GPMC_SYSCONFIG),
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
        (SOC_ELM_0_REGS + ELM_SYSCONFIG),
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
        (SOC_CONTROL_REGS + CONTROL_SYSCONFIG),
        CONTROL_SYSCONFIG_IDLEMODE_SHIFT,
        CONTROL_SYSCONFIG_IDLEMODE,
        FALSE,
        CONTROL_SYSCONFIG_STANDBY_SHIFT,
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
        (SOC_EDMA30CC_0_REGS + EDMA_TPCC_SYSCONFIG),
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
        (SOC_EDMA3TC_0_REGS + EDMA3TC_SYSCONFIG),
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
        (SOC_EDMA3TC_1_REGS + EDMA3TC_SYSCONFIG),
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
        (SOC_EDMA3TC_2_REGS + EDMA3TC_SYSCONFIG),
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
        (SOC_ADC_TSC_0_REGS + ADC0_SYSCONFIG),
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    {   /* PMHAL_PRCM_MOD_LCDC */
        (SOC_LCDC_0_REGS + LCDC_SYSCONFIG),
        LCDC_SYSCONFIG_IDLEMODE_SHIFT,
        LCDC_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        LCDC_SYSCONFIG_STANDBYMODE_SHIFT,
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
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    {   /* PMHAL_PRCM_MOD_EPWMSS0 */
        (SOC_PWMSS0_REGS + PWMSS_SYSCONFIG),
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
        (SOC_PWMSS1_REGS + PWMSS_SYSCONFIG),
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
        (SOC_PWMSS2_REGS + PWMSS_SYSCONFIG),
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    {   /* PMHAL_PRCM_MOD_USB0 */
        (SOC_USBSS_REGS + USBSS_SYSCONFIG),
        USBSS_SYSCONFIG_IDLEMODE_SHIFT,
        USBSS_SYSCONFIG_IDLEMODE_MASK,
        FALSE,
        USBSS_SYSCONFIG_STANDBYMODE_SHIFT,
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
                    (uint32_t) PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE) |
                   ((uint32_t) 1U <<
                    (uint32_t)
                    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE))
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    {   /* PMHAL_PRCM_MOD_MAILBOX0 */
        (SOC_MAILBOX_0_REGS + MLB_SYSCONFIG),
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
        (SOC_SPINLOCK_0_REGS + SPINLOCK_SYSCONFIG),
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
        (SOC_MMCHS_0_REGS + HS_MMC_SD_SYSCONFIG),
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
        (SOC_MMCHS_1_REGS + HS_MMC_SD_SYSCONFIG),
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
        (SOC_MMCHS_2_REGS + HS_MMC_SD_SYSCONFIG),
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    {   /* PMHAL_PRCM_MOD_RTCSS */
        (SOC_RTC_0_REGS + RTCSS_SYSCONFIG),
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
        (SOC_MCASP_0_CTRL_REGS + MCASP_PWRIDLESYSCONFIG),
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
        (SOC_MCASP_1_CTRL_REGS + MCASP_PWRIDLESYSCONFIG),
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
        (SOC_SPI_0_REGS + MCSPI_SYSCONFIG),
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
        (SOC_SPI_1_REGS + MCSPI_SYSCONFIG),
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    {   /* PMHAL_PRCM_MOD_GPIO0 */
        (SOC_GPIO_0_REGS + GPIO_SYSCONFIG),
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
        (SOC_GPIO_1_REGS + GPIO_SYSCONFIG),
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
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    {   /* PMHAL_PRCM_MOD_GPIO2 */
        (SOC_GPIO_2_REGS + GPIO_SYSCONFIG),
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
        (SOC_GPIO_3_REGS + GPIO_SYSCONFIG),
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
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    {   /* PMHAL_PRCM_MOD_I2C0 */
        (SOC_I2C_0_REGS + I2C_SYSC),
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
        (SOC_I2C_1_REGS + I2C_SYSC),
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
        (SOC_I2C_2_REGS + I2C_SYSC),
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
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_AES0_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES1
    {   /* PMHAL_PRCM_MOD_AES1 */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_AES1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_AES1_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    { /* PMHAL_PRCM_MOD_CLKDIV32K */
        PMHAL_PRCM_CD_CLK_24MHZ,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_CLKDIV32K_CLKCTRL),
        PMHAL_PRCM_MOD_CLKDIV32K_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    { /* PMHAL_PRCM_MOD_CPGMAC0 */
        PMHAL_PRCM_CD_CPSW_125MHZ,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_CPGMAC0_CLKCTRL),
        PMHAL_PRCM_MOD_CPGMAC0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_CPGMAC0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    { /* PMHAL_PRCM_MOD_DCAN0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DCAN0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_DCAN0_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_DCAN1_CLKCTRL),
        PMHAL_PRCM_MOD_DCAN1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_DCAN1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    { /* PMHAL_PRCM_MOD_DES */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DES_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_DES_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO
    { /* PMHAL_PRCM_MOD_DMA4_CRYPTO */
        PMHAL_PRCM_CD_DMA_L3,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_DMA4_CRYPTO_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_DMA4_CRYPTO_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DMA4_CRYPTO */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    { /* PMHAL_PRCM_MOD_ELM */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_ELM,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ELM_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_ELM_CLKCTRL),
        PMHAL_PRCM_MOD_ELM_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    { /* PMHAL_PRCM_MOD_EMIF */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_EMIF_CLKCTRL),
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
        PMHAL_PRCM_CD_L4FW,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_EMIF_FW_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        (SOC_CM_PER_REGS + CM_PER_EPWMSS0_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_EPWMSS1_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_EPWMSS2_CLKCTRL),
        PMHAL_PRCM_MOD_EPWMSS2_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    { /* PMHAL_PRCM_MOD_GPIO1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_GPIO1_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_GPIO2_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_GPIO3,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_GPIO3_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO4_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_GPIO4_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    { /* PMHAL_PRCM_MOD_GPIO5 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO5_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_GPIO5_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO6
    { /* PMHAL_PRCM_MOD_GPIO6 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPIO6_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_GPIO6_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    { /* PMHAL_PRCM_MOD_GPMC */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_GPMC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GPMC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_GPMC_CLKCTRL),
        PMHAL_PRCM_MOD_GPMC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    { /* PMHAL_PRCM_MOD_I2C1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_I2C1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_I2C1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_I2C1_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_I2C2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_I2C2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_I2C2_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_ICSS_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_IEEE5000_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_IEEE5000_CLKCTRL),
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
        PMHAL_PRCM_RT_PARTIAL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_L3_CLKCTRL),
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
        PMHAL_PRCM_RT_PARTIAL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L3_INSTR_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_L3_INSTR_CLKCTRL),
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
        PMHAL_PRCM_CD_L4FW,
        PMHAL_PRCM_RT_PARTIAL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4FW_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_L4FW_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    { /* PMHAL_PRCM_MOD_L4LS */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_PARTIAL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4LS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_L4LS_CLKCTRL),
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
        PMHAL_PRCM_CD_L4HS,
        PMHAL_PRCM_RT_PARTIAL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_L4_HS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_L4HS_CLKCTRL),
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
        PMHAL_PRCM_SYSCFG_LCDC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_LCDC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_LCDC_CLKCTRL),
        PMHAL_PRCM_MOD_LCDC_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED)),
        PMHAL_EDGE_MOD_LCDC,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    { /* PMHAL_PRCM_MOD_MAILBOX0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MAILBOX0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_MAILBOX0_CLKCTRL),
        PMHAL_PRCM_MOD_MAILBOX0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1
    { /* PMHAL_PRCM_MOD_MAILBOX1 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MAILBOX1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_MAILBOX1_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    { /* PMHAL_PRCM_MOD_MCASP0 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_MCASP0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_MCASP0_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_MCASP1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_MCASP1_CLKCTRL),
        PMHAL_PRCM_MOD_MCASP1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_MCASP1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP2
    { /* PMHAL_PRCM_MOD_MCASP2 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MCASP2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_MCASP2_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MLB
    { /* PMHAL_PRCM_MOD_MLB */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MLB_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_MLB_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MLB */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    { /* PMHAL_PRCM_MOD_MMC0 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MMC0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_MMC0_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_MMC1_CLKCTRL),
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
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_MMC2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMC2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_MMC2_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MSTR_EXPS_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_MSTR_EXPS_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        (SOC_CM_PER_REGS + CM_PER_OCMCRAM_CLKCTRL),
        PMHAL_PRCM_MOD_OCMCRAM_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCPWP
    {   /* PMHAL_PRCM_MOD_OCPWP */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_OCPWP_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_OCPWP_CLKCTRL),
        PMHAL_PRCM_MOD_OCPWP_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_OCPWP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PCIE
    {   /* PMHAL_PRCM_MOD_PCIE */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_PCIE_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_PCIE_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PCIE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    { /* PMHAL_PRCM_MOD_PKA */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_PKA_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_PKA_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    { /* PMHAL_PRCM_MOD_RNG */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_RNG_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_RNG_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SHA0_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SLV_EXPS_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SPARE0_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SPARE1_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
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
        (SOC_CM_PER_REGS + CM_PER_SPI0_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_SPI1_CLKCTRL),
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
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SPI2_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    { /* PMHAL_PRCM_MOD_SPI3 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPI3_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_SPI3_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    { /* PMHAL_PRCM_MOD_SPINLOCK */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_SPINLOCK,
        VSIZE_TYPE(PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_SPINLOCK_CLKCTRL),
        PMHAL_PRCM_MOD_SPINLOCK_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    { /* PMHAL_PRCM_MOD_TIMER2 */
        PMHAL_PRCM_CD_L4LS,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_TIMER2_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_TIMER3_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_TIMER4_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_TIMER5_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_TIMER6_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_TIMER7_CLKCTRL),
        PMHAL_PRCM_MOD_TIMER7_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_TIMER7,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    { /* PMHAL_PRCM_MOD_TPCC */
        PMHAL_PRCM_CD_L3,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_TPCC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPCC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_TPCC_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_TPTC0_CLKCTRL),
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC1,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC1_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_TPTC1_CLKCTRL),
        PMHAL_PRCM_MOD_TPTC1_ClkSelectCfg,
        FALSE,
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
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_TPTC2,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TPTC2_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_TPTC2_CLKCTRL),
        PMHAL_PRCM_MOD_TPTC2_ClkSelectCfg,
        FALSE,
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
        (SOC_CM_PER_REGS + CM_PER_UART1_CLKCTRL),
        PMHAL_PRCM_MOD_UART1_ClkSelectCfg,
        FALSE,
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
        (SOC_CM_PER_REGS + CM_PER_UART2_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_UART3_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_UART4_CLKCTRL),
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
        (SOC_CM_PER_REGS + CM_PER_UART5_CLKCTRL),
        PMHAL_PRCM_MOD_UART5_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART5,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB0
    { /* PMHAL_PRCM_MOD_USB0 */
        PMHAL_PRCM_CD_L3S,
        PMHAL_PRCM_RT_FULL_RETENTION,
        PMHAL_PRCM_SYSCFG_USB0,
        VSIZE_TYPE(PMHAL_PRCM_MOD_USB0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_PER_REGS + CM_PER_USB0_CLKCTRL),
        PMHAL_PRCM_MOD_USB0_ClkSelectCfg,
        TRUE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_USB0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_BITBLT
    { /* PMHAL_PRCM_MOD_BITBLT */
        PMHAL_PRCM_CD_GFX_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_BITBLT_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        PMHAL_REG_NOTAPPLICABLE,
        PMHAL_PRCM_MOD_BITBLT_ClkSelectCfg,
        FALSE,
        (uint8_t) (PMHAL_MODULEMODE_NOTAPPLICABLE),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_BITBLT */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    { /* PMHAL_PRCM_MOD_GFX */
        PMHAL_PRCM_CD_GFX_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_GFX_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_GFX_REGS + CM_GFX_GFX_CLKCTRL),
        PMHAL_PRCM_MOD_GFX_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_GFX,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU
    { /* PMHAL_PRCM_MOD_MMU */
        PMHAL_PRCM_CD_GFX_L3,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMU_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_GFX_REGS + CM_GFX_MMUDATA_CLKCTRL),
        PMHAL_PRCM_MOD_MMU_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG
    { /* PMHAL_PRCM_MOD_MMU_CFG */
        PMHAL_PRCM_CD_L4LS_GFX,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_MMU_CFG_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_GFX_REGS + CM_GFX_MMUCFG_CLKCTRL),
        PMHAL_PRCM_MOD_MMU_CFG_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMU_CFG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    { /* PMHAL_PRCM_MOD_ADC_TSC */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_ADC_TSC,
        VSIZE_TYPE(PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REGS + CM_WKUP_ADC_TSC_CLKCTRL),
        PMHAL_PRCM_MOD_ADC_TSC_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_ADC_TSC,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    { /* PMHAL_PRCM_MOD_CONTROL */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_CONTROL,
        VSIZE_TYPE(PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REGS + CM_WKUP_CONTROL_CLKCTRL),
        PMHAL_PRCM_MOD_CONTROL_ClkSelectCfg,
        TRUE,
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
        (SOC_CM_WKUP_REGS + CM_WKUP_DEBUGSS_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_GPIO0_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_I2C0_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_L4WKUP_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_SMARTREFLEX0_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_SMARTREFLEX1_CLKCTRL),
        PMHAL_PRCM_MOD_SMARTREFLEX1_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_SMARTREFLEX1,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    { /* PMHAL_PRCM_MOD_TIMER0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_TIMER0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REGS + CM_WKUP_TIMER0_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_TIMER1_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_UART0_CLKCTRL),
        PMHAL_PRCM_MOD_UART0_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_MOD_UART0,
        PMHAL_PRCM_CPU_ID_UNDEF
    },
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    { /* PMHAL_PRCM_MOD_WDT0 */
        PMHAL_PRCM_CD_L4_WKUP,
        PMHAL_PRCM_RT_NO_RETENTION,
        PMHAL_PRCM_SYSCFG_NOTAPPLICABLE,
        VSIZE_TYPE(PMHAL_PRCM_MOD_WDT0_ClkSelectCfg,
                   pmhalClockSelConfig_t),
        (SOC_CM_WKUP_REGS + CM_WKUP_WDT0_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_WDT1_CLKCTRL),
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
        (SOC_CM_WKUP_REGS + CM_WKUP_WKUP_M3_CLKCTRL),
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
        (SOC_CM_CEFUSE_REGS + CM_CEFUSE_CEFUSE_CLKCTRL),
        PMHAL_PRCM_MOD_CEFUSE_ClkSelectCfg,
        FALSE,
        (uint8_t) (((uint32_t) 1U <<
                    (uint32_t) PMHAL_PRCM_MODULE_MODE_ENABLED) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_MODULE_MODE_DISABLED)),
        PMHAL_EDGE_UNDEF,
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
        (SOC_CM_RTC_REGS + CM_RTC_RTC_CLKCTRL),
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
        (SOC_CM_MPU_REGS + CM_MPU_MPU_CLKCTRL),
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
};

/**
 *  \brief Structure defining Physical Memory Elements List
 */
const pmhalPhysicalMemory_t   pmhalPhysicalMemoryElems[] =
{
    {   /* PMHAL_PRCM_PHY_BANK_GFX_MEM */
        PRM_GFX_PM_GFX_PWRSTCTRL_GFX_MEM_ONSTATE_SHIFT,
        PRM_GFX_PM_GFX_PWRSTCTRL_GFX_MEM_RETSTATE_SHIFT,
        PRM_GFX_PM_GFX_PWRSTST_GFX_MEM_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON)
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_L1 */
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_ONSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L1_RETSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTST_MPU_L1_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON)
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_L2 */
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_ONSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_L2_RETSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTST_MPU_L2_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON)
    },
    {   /* PMHAL_PRCM_PHY_BANK_MPU_RAM */
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_ONSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTCTRL_MPU_RAM_RETSTATE_SHIFT,
        PRM_MPU_PM_MPU_PWRSTST_MPU_RAM_STATEST_SHIFT,
        (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON)
    },
    {   /* PMHAL_PRCM_PHY_BANK_PER_MEM */
        PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_ONSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTCTRL_PER_MEM_RETSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTST_PER_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_ICSS_MEM */
        PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_ONSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTCTRL_ICSS_MEM_RETSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTST_ICSS_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_RAM_MEM */
        PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_ONSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTCTRL_RAM_MEM_RETSTATE_SHIFT,
        PRM_PER_PM_PER_PWRSTST_RAM_MEM_STATEST_SHIFT,
        (uint8_t) (((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_OFF) |
                   ((uint32_t) 1U << (uint32_t) PMHAL_BANK_RET_ON))
    },
    {   /* PMHAL_PRCM_PHY_BANK_DEBUGSS_MEM */
        PMHAL_SHIFT_NOTAPPLICABLE,
        PMHAL_SHIFT_NOTAPPLICABLE,
        PRM_WKUP_PM_WKUP_PWRSTST_DEBUGSS_MEM_STATEST_SHIFT,
        (uint8_t) PMHAL_BANK_RET_UNDEF
    },
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_GFX_FCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_GFX_FCLK_validDivValues[] =
{
    {1U, CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_GFX_FCLK_DIV1},
    {2 , CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_GFX_FCLK_DIV2}
};

/**
 *  \brief Structure defining Valid divider Values for PMHAL_PRCM_DIV_EMIF_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_EMIF_GCLK_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
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
 *         PMHAL_PRCM_DIV_CLK_24MHZ
 */
validDivValue_t               PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
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
    {2U, CM_DPLL_CM_MAC_CLKSEL_MII_CLK_SEL_SEL0},
    {5 , CM_DPLL_CM_MAC_CLKSEL_MII_CLK_SEL_SEL1}
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
 *         PMHAL_PRCM_DIV_CLKOUT2
 */
validDivValue_t               PMHAL_PRCM_DIV_CLKOUT2_validDivValues[] =
{
    {1U, CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV1},
    {2,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV2},
    {3,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV3},
    {4,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV4},
    {5,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV5},
    {6,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV6},
    {7,  CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_DIV7}
};

/**
 *  \brief Structure defining Valid divider Values for
 *         PMHAL_PRCM_DIV_L4_RTC_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_L4_RTC_GCLK_validDivValues[] =
{
    {2, PMHAL_DIV_ENUM_NOTAPPLICABLE}
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
 *         PMHAL_PRCM_DIV_L4_WKUP_GCLK
 */
validDivValue_t               PMHAL_PRCM_DIV_L4_WKUP_GCLK_validDivValues[] =
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
 *         PMHAL_PRCM_DIV_SYSCLK1
 */
validDivValue_t               PMHAL_PRCM_DIV_SYSCLK1_validDivValues[] =
{
    {1, PMHAL_DIV_ENUM_NOTAPPLICABLE}
};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_GFX_FCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_GFX_FCLK_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_GFX_FCLK),
 CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_GFX_FCLK,
 CM_DPLL_CLKSEL_GFX_FCLK_CLKDIV_SEL_GFX_FCLK_SHIFT};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_EMIF_GCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_EMIF_GCLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CORE_100M
 */
regBitField_t                 PMHAL_PRCM_DIV_CORE_100M_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_UART_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_UART_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_MMC_CLK
 */
regBitField_t                 PMHAL_PRCM_DIV_MMC_CLK_regBitField =
{PMHAL_REG_NOTAPPLICABLE,
 PMHAL_MASK_NOTAPPLICABLE,
 PMHAL_SHIFT_NOTAPPLICABLE};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_CLK_24MHZ
 */
regBitField_t                 PMHAL_PRCM_DIV_CLK_24MHZ_regBitField =
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
{(SOC_CM_DPLL_REGS + CM_DPLL_CM_MAC_CLKSEL),
 CM_DPLL_CM_MAC_CLKSEL_MII_CLK_SEL,
 CM_DPLL_CM_MAC_CLKSEL_MII_CLK_SEL_SHIFT};

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
 *         PMHAL_PRCM_DIV_CLKOUT2
 */
regBitField_t                 PMHAL_PRCM_DIV_CLKOUT2_regBitField =
{(SOC_CM_DEVICE_REGS + CM_DEVICE_CM_CLKOUT_CTRL),
 CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV,
 CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2DIV_SHIFT};

/**
 *  \brief Structure defining divider Registers for
 *         PMHAL_PRCM_DIV_L4_RTC_GCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_L4_RTC_GCLK_regBitField =
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
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_L4_WKUP_GCLK
 */
regBitField_t                 PMHAL_PRCM_DIV_L4_WKUP_GCLK_regBitField =
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
 *  \brief Structure defining divider Registers for PMHAL_PRCM_DIV_SYSCLK1
 */
regBitField_t                 PMHAL_PRCM_DIV_SYSCLK1_regBitField =
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
    {   /* PMHAL_PRCM_DIV_EMIF_GCLK */
        &PMHAL_PRCM_DIV_EMIF_GCLK_regBitField,
        PMHAL_PRCM_DIV_EMIF_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_EMIF_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_CORE_100M */
        &PMHAL_PRCM_DIV_CORE_100M_regBitField,
        PMHAL_PRCM_DIV_CORE_100M_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CORE_100M_validDivValues,
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
    {   /* PMHAL_PRCM_DIV_CLK_24MHZ */
        &PMHAL_PRCM_DIV_CLK_24MHZ_regBitField,
        PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLK_24MHZ_validDivValues,
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
    {   /* PMHAL_PRCM_DIV_CLKOUT2 */
        &PMHAL_PRCM_DIV_CLKOUT2_regBitField,
        PMHAL_PRCM_DIV_CLKOUT2_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_CLKOUT2_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_L4_RTC_GCLK */
        &PMHAL_PRCM_DIV_L4_RTC_GCLK_regBitField,
        PMHAL_PRCM_DIV_L4_RTC_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_L4_RTC_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_VTP_CLK */
        &PMHAL_PRCM_DIV_VTP_CLK_regBitField,
        PMHAL_PRCM_DIV_VTP_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_VTP_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_L4_WKUP_GCLK */
        &PMHAL_PRCM_DIV_L4_WKUP_GCLK_regBitField,
        PMHAL_PRCM_DIV_L4_WKUP_GCLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_L4_WKUP_GCLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_UART0_CLK */
        &PMHAL_PRCM_DIV_UART0_CLK_regBitField,
        PMHAL_PRCM_DIV_UART0_CLK_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_UART0_CLK_validDivValues,
                   validDivValue_t)
    },
    {   /* PMHAL_PRCM_DIV_SYSCLK1 */
        &PMHAL_PRCM_DIV_SYSCLK1_regBitField,
        PMHAL_PRCM_DIV_SYSCLK1_validDivValues,
        VSIZE_TYPE(PMHAL_PRCM_DIV_SYSCLK1_validDivValues,
                   validDivValue_t)
    }
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_GFX_FCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_GFX_FCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DPLL_CORE, /* M4 */
     CM_DPLL_CLKSEL_GFX_FCLK_CLKSEL_GFX_FCLK_SEL0},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     CM_DPLL_CLKSEL_GFX_FCLK_CLKSEL_GFX_FCLK_SEL1}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER7_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER2_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER3_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER4_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL_CLK_M_OSC},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER5_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL_SEL2},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_TIMER6_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL_SEL2},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
validEnumValue_t       PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DPLL_CORE, /* M5 */
     CM_DPLL_CM_CPTS_RFT_CLKSEL_CLKSEL_SEL1},
    {PMHAL_PRCM_DPLL_CORE, /* M4 */
     CM_DPLL_CM_CPTS_RFT_CLKSEL_CLKSEL_SEL2}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_LCD_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_DPLL_CORE, /* M5 */
     CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL_SEL2},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX
 */
validEnumValue_t       PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_CLK_L3_GCLK,
     CM_DPLL_CLKSEL_ICSS_OCP_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_DPLL_DISP, /* M2 */
     CM_DPLL_CLKSEL_ICSS_OCP_CLK_CLKSEL_SEL2}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX
 */
validEnumValue_t          PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768,
     CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SEL0},
    {PMHAL_PRCM_CLK_L3_GCLK,
     CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SEL1},
    {PMHAL_PRCM_DPLL_DDR, /* M2 */
     CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SEL2},
    {PMHAL_PRCM_DPLL_PER, /* M2 */
     CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SEL4},
    {PMHAL_PRCM_CLK_LCD_GCLK,
     CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SEL5}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
validEnumValue_t            PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
     CM_DPLL_CLKSEL_GPIO0_DBCLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768,
     CM_DPLL_CLKSEL_GPIO0_DBCLK_CLKSEL_SEL2},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_GPIO0_DBCLK_CLKSEL_SEL3}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
validEnumValue_t            PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SEL2},
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SEL3},
    {PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
     CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SEL4},
    {PMHAL_PRCM_ROOT_CLK_SYS_CLK_32768,
     CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SEL5}
};

#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_TIMER0_GCLK_MUX.  Note: Not implemented on actual
 *         device.
 */
validEnumValue_t            PMHAL_PRCM_MUX_TIMER0_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_SYS_CLKIN,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_TCLKIN,
     UNKNOWN},
    {PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
     UNKNOWN}
};

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_WDT0_GCLK_MUX.  Note: Not implemented on actual
 *         device.
 */
validEnumValue_t              PMHAL_PRCM_MUX_WDT0_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_DPLL_CORE,
     UNKNOWN},
    {PMHAL_PRCM_DIV_L3_ICLK,
     UNKNOWN}
};
#endif

/**
 *  \brief Structure defining valid Enumeration values for
 *         PMHAL_PRCM_MUX_WDT1_GCLK_MUX
 */
validEnumValue_t              PMHAL_PRCM_MUX_WDT1_GCLK_MUX_validEnumValues[] =
{
    {PMHAL_PRCM_ROOT_CLK_CLK_RC32K,
     CM_DPLL_CLKSEL_WDT1_CLK_CLKSEL_SEL1},
    {PMHAL_PRCM_ROOT_CLK_CLK_32KHZ,
     CM_DPLL_CLKSEL_WDT1_CLK_CLKSEL_SEL2}
};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_GFX_FCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_GFX_FCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_GFX_FCLK),
 CM_DPLL_CLKSEL_GFX_FCLK_CLKSEL_GFX_FCLK,
 CM_DPLL_CLKSEL_GFX_FCLK_CLKSEL_GFX_FCLK_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER7_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER7_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER7_CLK),
 CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER7_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER2_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER2_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER2_CLK),
 CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER2_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER3_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER3_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER3_CLK),
 CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER3_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER4_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER4_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER4_CLK),
 CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER4_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER5_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER5_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER5_CLK),
 CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER5_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER6_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER6_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER6_CLK),
 CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER6_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CM_CPTS_RFT_CLKSEL),
 CM_DPLL_CM_CPTS_RFT_CLKSEL_CLKSEL,
 CM_DPLL_CM_CPTS_RFT_CLKSEL_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_LCD_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_LCD_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_LCDC_PIXEL_CLK),
 CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL,
 CM_DPLL_CLKSEL_LCDC_PIXEL_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_ICSS_OCP_CLK),
 CM_DPLL_CLKSEL_ICSS_OCP_CLK_CLKSEL,
 CM_DPLL_CLKSEL_ICSS_OCP_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_regBitField =
{(SOC_CM_DEVICE_REGS + CM_DEVICE_CM_CLKOUT_CTRL),
 CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE,
 CM_DEVICE_CM_CLKOUT_CTRL_CLKOUT2SOURCE_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_GPIO0_DBCLK),
 CM_DPLL_CLKSEL_GPIO0_DBCLK_CLKSEL,
 CM_DPLL_CLKSEL_GPIO0_DBCLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining register structures for
 *         PMHAL_PRCM_MUX_TIMER1_GCLK_MUX
 */
regBitField_t                 PMHAL_PRCM_MUX_TIMER1_GCLK_MUX_regBitField =
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER1MS_CLK),
 CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL,
 CM_DPLL_CLKSEL_TIMER1MS_CLK_CLKSEL_SHIFT};

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
{(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_WDT1_CLK),
 CM_DPLL_CLKSEL_WDT1_CLK_CLKSEL,
 CM_DPLL_CLKSEL_WDT1_CLK_CLKSEL_SHIFT};

/**
 *  \brief Structure defining Mux Elements
 */
const pmhalMultiplexer_t      pmhalMultiplexerElems[] =
{
    {   /* PMHAL_PRCM_MUX_GFX_FCLK_MUX */
        &PMHAL_PRCM_MUX_GFX_FCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_GFX_FCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_GFX_FCLK_MUX_validEnumValues,
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
    {   /* PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX */
        &PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_regBitField,
        PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_LCD_GCLK_MUX */
        &PMHAL_PRCM_MUX_LCD_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_LCD_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_LCD_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX */
        &PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_PRU_ICSS_OCP_GCLK_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX */
        &PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_regBitField,
        PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_SYSCLKOUT_PRE_MUX_validEnumValues,
                   validEnumValue_t)
    },
    {   /* PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX */
        &PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_regBitField,
        PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues,
        VSIZE_TYPE(PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX_validEnumValues,
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

