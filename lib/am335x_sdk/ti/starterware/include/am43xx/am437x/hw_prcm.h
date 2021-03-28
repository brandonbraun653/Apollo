/**
 *  \file      hw_prcm.h
 *
 *  \brief     This file contains enumeration declarations for different 
 *             elements of PRCM like clock, module, power domain, etc.
 *             which uniquely identifies each element of PRCM.
 *
 *  \warning   This file is auto generated. So avoid manual changes. 
 *             If manual changes are required the implications of the 
 *             change in this and other auto generated files has to be 
 *             completely understood.
 */

/* Copyright (c) 2013 Texas Instruments Inc - http://www.ti.com */

/*
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

#ifndef HW_PRCM_H 
#define HW_PRCM_H

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */
#include "hw_cm_cefuse.h"
#include "hw_prm_per.h"
#include "hw_cm_mpu.h"
#include "hw_prm_mpu.h"
#include "hw_prm_gfx.h"
#include "hw_cm_per.h"
#include "hw_cm_dpll.h"
#include "hw_cm_rtc.h"
#include "hw_cm_tamper.h"
#include "hw_cm_wkup.h"
#include "hw_cm_gfx.h"
#include "hw_prm_cefuse.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */
/**
 *  \brief Enum defining different modes of a module.
 */
typedef enum
{
    PRCM_MODULE_MODE_MIN = PRCM_CM_PER_L3_CLKCTRL_MODULEMODE_DISABLED,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_MODULE_MODE_DISABLED = PRCM_CM_PER_L3_CLKCTRL_MODULEMODE_DISABLED,
    /**< Disabled: Any access to module registers will result in error */
    PRCM_MODULE_MODE_AUTO  = PRCM_CM_MPU_CLKCTRL_MODULEMODE_AUTO,
    /**< Auto: Clocks will be gated automatically when there is no activity and
         enabled when there is an activity. */
    PRCM_MODULE_MODE_ENABLED  = PRCM_CM_PER_L3_CLKCTRL_MODULEMODE_ENABLE,
    /**< Enabled: Functional and interface clocks are available and access to 
         module registers are permitted. */
    PRCM_MODULE_MODE_MAX = PRCM_MODULE_MODE_ENABLED
    /**< Max value of the enum. Can be used for validation. */
}prcmModuleMode_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining idle states of the module. These values can be used to
 *         check the state of the module after configuring the module mode 
 *         property.
 */
typedef enum
{
    PRCM_MODULE_IDLEST_MIN = PRCM_CM_PER_L3_CLKCTRL_IDLEST_FUNC,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_MODULE_IDLEST_FUNC    = PRCM_CM_PER_L3_CLKCTRL_IDLEST_FUNC,
    /**< Module is functional and can be accessed */
    PRCM_MODULE_IDLEST_TRANS   = PRCM_CM_PER_L3_CLKCTRL_IDLEST_TRANS,
    /**< Module is performing transition: wakeup, or sleep,or sleep abortion */
    PRCM_MODULE_IDLEST_IDLE    = PRCM_CM_PER_L3_CLKCTRL_IDLEST_IDLE,
    /**< Module is in Idle mode (only interface part). It is functional if it 
         uses separate functional clock  */
    PRCM_MODULE_IDLEST_DISABLE = PRCM_CM_PER_L3_CLKCTRL_IDLEST_DISABLE,
    /**< Module is disabled and cannot be accessed */
    PRCM_MODULE_IDLEST_MAX = PRCM_MODULE_IDLEST_DISABLE
    /**< Max value of the enum. Can be used for validation. */
}prcmModuleIdleStates_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining standby states of the module (Master only). These 
 *         values can be used to check the state of the module after 
 *         configuring the module mode property.
 */
typedef enum
{
    PRCM_CLKCTRL_STBYST_MIN = PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_FUNC,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_CLKCTRL_STBYST_FUNC = PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_FUNC,
    /**< When master module wants to initiate a transaction on the device 
         interconnect and it requests specific (functional and interface) 
         clocks for that purpose. The PRCM module ensures that the required 
         clocks are active and the module is said to be functional after this
         transition completes. */
    PRCM_CLKCTRL_STBYST_STANDBY = PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_STANDBY,
    /**< When the master module no longer requires the clocks, it informs the 
         PRCM module, which can then gate the clocks to the module. */
    PRCM_CLKCTRL_STBYST_MAX = PRCM_CLKCTRL_STBYST_STANDBY
    /**< Max value of the enum. Can be used for validation. */
}prcmModuleStandbyStates_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining clock domain control values. These values can be used 
 *         to control the clock domain while initializing the system, entering 
 *         sleep state and waking up from sleep state.
 */
typedef enum
{
    PRCM_CD_CLK_TRANS_MIN = PRCM_CM_PER_L3_CLKSTCTRL_CLKTRCTRL_NO_SLEEP,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_CD_CLK_TRANS_NO_SLEEP = PRCM_CM_MPU_CLKSTCTRL_CLKTRCTRL_NO_SLEEP,
    /**< No sleep in the clock domain */
    PRCM_CD_CLK_TRANS_SW_SLEEP = PRCM_CM_MPU_CLKSTCTRL_CLKTRCTRL_SW_SLEEP,
    /**< Start a software forced sleep transition on the clock domain. */
    PRCM_CD_CLK_TRANS_SW_WKUP  = PRCM_CM_MPU_CLKSTCTRL_CLKTRCTRL_SW_WKUP,
    /**< Start a software forced wake-up transition on the clock domain. */
    PRCM_CD_CLK_TRANS_HW_AUTO  = PRCM_CM_MPU_CLKSTCTRL_CLKTRCTRL_HW_AUTO,
    /**< If there is no activity in the clock domain HW automatically puts it 
         into sleep mode. On detecting any activity it wakes up. */
    PRCM_CD_CLK_TRANS_MAX = PRCM_CD_CLK_TRANS_HW_AUTO
    /**< Max value of the enum. Can be used for validation. */
}prcmClockDomainControl_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining power domain status values. These values can be used 
 *         to control the clock domain while initializing the system, entering 
 *         sleep state and waking up from sleep state.
 */
typedef enum
{
    PRCM_PD_STATUS_MIN = PRCM_PM_MPU_PWRSTST_POWERSTATEST_OFF,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_PD_STATUS_OFF = PRCM_PM_MPU_PWRSTST_POWERSTATEST_OFF,
    /**< Power to the domain is off. */
    PRCM_PD_STATUS_RET = PRCM_PM_MPU_PWRSTST_POWERSTATEST_RET,
    /**< Power to the domain is in retention mode and it will not be functional
         but the memory will be retained. */
    PRCM_PD_STATUS_ON  = PRCM_PM_MPU_PWRSTST_POWERSTATEST_ON,
    /**< Power to the domain is ON. */
    PRCM_PD_STATUS_MAX = PRCM_PD_STATUS_ON
    /**< Max value of the enum. Can be used for validation. */
}prcmPowerDomainStatus_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enumeration for different different post dividers.
 */
typedef enum
{
    PRCM_PLL_POST_DIV_INVALID   = (-1),
    /**< Invalid value. */
    PRCM_PLL_POST_DIV_MIN       = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_PLL_POST_DIV_M2        = 0x1U,
    /**< M2 post divider. */
    PRCM_PLL_POST_DIV_M4        = 0x2U,
    /**< M4 post divider. */
    PRCM_PLL_POST_DIV_M5        = 0x4U,
    /**< M5 post divider. */
    PRCM_PLL_POST_DIV_M6        = 0x8U,
    /**< M6 post divider. */
    PRCM_PLL_POST_DIV_MAX       = PRCM_PLL_POST_DIV_M6
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllPostDivId_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining CLKINPULOW input selection.
 *
 *  These parameters define the clock input to CLKINPULOW signal in bypass 
 *  mode.
 */
typedef enum
{
    PRCM_DPLL_CLKINPULOW_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_CLKINPULOW_CORE_CLKOUTM6 = PRCM_DPLL_CLKINPULOW_MIN,
    /**< Select CORE_CLKOUTM6 as the input for CLKINPULOW. */
    PRCM_DPLL_CLKINPULOW_PER_CLKOUTM2  = 1U,
    /**< Select PER_CLKOUTM2 as the input for CLKINPULOW. */
    PRCM_DPLL_CLKINPULOW_MAX = PRCM_DPLL_CLKINPULOW_PER_CLKOUTM2
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllClkInputLowSel_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining bypass input clock selection for the PLL.
 *
 *  The bypass clock can either be CLKINP (Master Osc) or CLKINPULOW 
 *  (above enum value).
 */
typedef enum
{
    PRCM_DPLL_BYP_MIN = PRCM_CM_CLKSEL_DPLL_MPU_BYP_SEL0,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_BYP_CLKINP      = PRCM_CM_CLKSEL_DPLL_MPU_BYP_SEL0,
    /**< Select CLKINP (Master Oscillator) as the bypass mode clock. */
    PRCM_DPLL_BYP_CLKINPULOW  = PRCM_CM_CLKSEL_DPLL_MPU_BYP_SEL1,
    /**< Select CLKINPULOW as the bypass mode clock. Refer 
         prcmDpllClkInputLowSel_t for possible inputs for CLKINPULOW. */
    PRCM_DPLL_BYP_MAX = PRCM_DPLL_BYP_CLKINPULOW
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllBypassClkSel_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining different bypass modes for the PLL.
 */
typedef enum
{
    PRCM_DPLL_BYP_MODE_MIN = PRCM_CM_CLKMODE_DPLL_MPU_EN_MN_BYP_MODE,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_BYP_MODE_MN_BYP_MODE = PRCM_CM_CLKMODE_DPLL_MPU_EN_MN_BYP_MODE,
    /**< MN Bypass mode, the value of multiplier and divider of DPLL are set to
         Zero. */
    PRCM_DPLL_BYP_MODE_LP_BYP_MODE = PRCM_CM_CLKMODE_DPLL_MPU_EN_LP_BYP_MODE,
    /**< Low Power Bypass mode, the value of multiplier and divider of DPLL are
         retained. */
    PRCM_DPLL_BYP_MODE_FR_BYP_MODE = PRCM_CM_CLKMODE_DPLL_MPU_EN_FR_BYP_MODE,
    /**< Fast relock Bypass mode. */
    PRCM_DPLL_BYP_MODE_LOCK_MODE   = PRCM_CM_CLKMODE_DPLL_MPU_EN_LOCK_MODE,
    /**< DPLL Lock mode. */
    PRCM_DPLL_BYP_MODE_MAX = PRCM_DPLL_BYP_MODE_LOCK_MODE
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllBypassMode_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining different ramp levels for the PLL.
 */
typedef enum
{
    PRCM_DPLL_RAMP_LEVEL_MIN       = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_DISABLE,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_RAMP_LEVEL_DISABLE   = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_DISABLE,
    /**< Ramp level is disabled. */    
    PRCM_DPLL_RAMP_LEVEL_ALGO1     = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_ALGO1,
    /**< Ramp level to use algorithm1. 
          CLKOUT   => Bypass clk -> Fout/8 -> Fout/4 -> Fout/2 -> Fout
          CLKOUTX2 => Bypass clk -> Foutx2/8 -> Foutx2/4 -> Foutx2/2 -> Foutx2
    */
    PRCM_DPLL_RAMP_LEVEL_ALGO2     = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_LEVEL_ALGO2,
    /**< Ramp level to use algorithm2. 
         CLKOUT   => Bypass clk -> Fout/4 -> Fout/2 -> Fout/1.5 -> Fout
         CLKOUTX2 => Bypass clk -> Foutx2/4 -> Foutx2/2 -> Foutx2/1.5 -> Foutx2
    */
    PRCM_DPLL_RAMP_LEVEL_MAX       = PRCM_DPLL_RAMP_LEVEL_ALGO2
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllRampLevel_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining different ramp rates for the PLL. These rates .
 *         indicates the time spent in each ramp step.
 */
typedef enum
{
    PRCM_DPLL_RAMP_RATE_MIN        = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX2,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_RAMP_RATE_REFCLKX2   = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX2,
    /**< 2 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX4   = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX4, 
    /**< 4 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX8   = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX8,  
    /**< 8 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX16  = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX16, 
    /**< 16 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX32  = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX32, 
    /**< 32 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX64  = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX64, 
    /**< 64 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX128 = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX128,
    /**< 128 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_REFCLKX512 = PRCM_CM_CLKMODE_DPLL_MPU_RAMP_RATE_REFCLKX512,
    /**< 512 REFCLKs per each ramp step. */
    PRCM_DPLL_RAMP_RATE_MAX        = PRCM_DPLL_RAMP_RATE_REFCLKX512
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllRampRate_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining lock statuses of DPLL.
 */
typedef enum
{
    PRCM_DPLL_IDLEST_ST_CLK_MIN      = PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_UNLOCKED,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_DPLL_IDLEST_ST_CLK_UNLOCKED = PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_UNLOCKED,
    /**< DPLL is in bypass mode. */
    PRCM_DPLL_IDLEST_ST_CLK_LOCKED   = PRCM_CM_IDLEST_DPLL_MPU_ST_CLK_LOCKED,
    /**< DPLL is in lock mode. */
    PRCM_DPLL_IDLEST_ST_CLK_MAX      = PRCM_DPLL_IDLEST_ST_CLK_LOCKED
    /**< Max value of the enum. Can be used for validation. */
}prcmDpllLockStatus_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Enum defining different types of root clock.
 */
typedef enum
{
    PRCM_ROOT_CLK_FREQ_MIN            = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PRCM_ROOT_CLK_FREQ_FIXED          = PRCM_DPLL_IDLEST_ST_CLK_MIN,
    /**< Frequency of the root clock is fixed in the SoC. */
    PRCM_ROOT_CLK_FREQ_STATIC_CONFIG  = 1U,
    /**< Frequency of the root clock is not fixed in the SoC, but fixed during 
         board design or system initialization. */
    PRCM_ROOT_CLK_FREQ_MAX            = PRCM_ROOT_CLK_FREQ_STATIC_CONFIG
    /**< Min value of the enum. Can be used for validation. */
}prcmRootClkType_t;

/*----------------------------------------------------------------------------*/
/** 
 * \brief Voltage Domains
 */
typedef enum 
{
    PRCM_VD_CORE,
    PRCM_VD_MIN = PRCM_VD_CORE,
    /*!< Lower bound (inclusive) */
    PRCM_VD_MPU,
    PRCM_VD_RTC,
    PRCM_VD_TAMPER,
    PRCM_VD_MAX = PRCM_VD_TAMPER,
    /*!< Enum Upper bound */
    PRCM_VD_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmVdId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Power Domains
 */
typedef enum 
{
    PRCM_PD_CUST_EFUSE,
    PRCM_PD_MIN = PRCM_PD_CUST_EFUSE,
    /*!< Lower bound (inclusive) */
    PRCM_PD_GFX,
    PRCM_PD_MPU,
    PRCM_PD_PER,
    PRCM_PD_RTC,
    PRCM_PD_STD_EFUSE,
    PRCM_PD_TAMPER,
    PRCM_PD_WKUP,
    PRCM_PD_MAX = PRCM_PD_WKUP,
    /*!< Enum Upper bound */
    PRCM_PD_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmPdId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Clock Domains
 */
typedef enum 
{
    PRCM_CD_CEFUSE,
    PRCM_CD_MIN = PRCM_CD_CEFUSE,
    /*!< Lower bound (inclusive) */
    PRCM_CD_GFX_L3,
    PRCM_CD_MPU,
    PRCM_CD_PER_L3,
    PRCM_CD_PER_CPSW,
    PRCM_CD_PER_EMIF,
    PRCM_CD_PER_DSS,
    PRCM_CD_PER_ICSS,
    PRCM_CD_PER_L3S,
    PRCM_CD_PER_L4LS,
    PRCM_CD_PER_LCDC,
    PRCM_CD_PER_OCPWP_L3,
    PRCM_CD_RTC,
    PRCM_CD_STD_EFUSE,
    PRCM_CD_TAMPER,
    PRCM_CD_L4_WKUP_AON,
    PRCM_CD_L3S_TSC,
    PRCM_CD_L3_AON,
    PRCM_CD_WKUP,
    PRCM_CD_MAX = PRCM_CD_WKUP,
    /*!< Enum Upper bound */
    PRCM_CD_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmCdId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Clocks
 */
typedef enum 
{
    PRCM_CLK_L4_CEFUSE_GCLK,
    PRCM_CLK_MIN = PRCM_CLK_L4_CEFUSE_GCLK,
    /*!< Lower bound (inclusive) */
    PRCM_CLK_CUST_EFUSE_SYSCLK,
    PRCM_CLK_DEBUG_CLKA_GCLK,
    PRCM_CLK_DEBUG_CLKB_GCLK,
    PRCM_CLK_DEBUG_CLKC_GCLK,
    PRCM_CLK_L3_AON_GCLK,
    PRCM_CLK_DBGSYSCLK,
    PRCM_CLK_DSS_GCLK,
    PRCM_CLK_DSS_L3_GCLK,
    PRCM_CLK_DSS_L4_GCLK_EN,
    PRCM_CLK_DSS_SYSCLK,
    PRCM_CLK_L4LS_GCLK,
    PRCM_CLK_EMIF_PHY_GCLK,
    PRCM_CLK_DDR_DLL_GCLK,
    PRCM_CLK_DLL_AGING_GCLK,
    PRCM_CLK_EMIF_L3_GICLK,
    PRCM_CLK_L3S_GCLK,
    PRCM_CLK_MMC_FCLK,
    PRCM_CLK_L3_GCLK,
    PRCM_CLK_GFX_GFCLK,
    PRCM_CLK_GFX_L3_GCLK,
    PRCM_CLK_GPIO_1_GDBCLK,
    PRCM_CLK_GPIO_2_GDBCLK,
    PRCM_CLK_GPIO_3_GDBCLK,
    PRCM_CLK_GPIO_4_GDBCLK,
    PRCM_CLK_GPIO_5_GDBCLK,
    PRCM_CLK_MGC_FGCLK,
    PRCM_CLK_L3D2_GCLK,
    PRCM_CLK_ICSS_IEP_GCLK,
    PRCM_CLK_ICSS_OCP_GCLK,
    PRCM_CLK_ICSS_UART_GCLK,
    PRCM_CLK_LCD_L3_GCLK,
    PRCM_CLK_LCD_L4S_GCLK,
    PRCM_CLK_LCD_GCLK,
    PRCM_CLK_CAN_CLK,
    PRCM_CLK_HDQ1W_GCLK,
    PRCM_CLK_I2C_FCLK,
    PRCM_CLK_MCASP_FCLK,
    PRCM_CLK_SPI_GCLK,
    PRCM_CLK_TIMER10_GCLK,
    PRCM_CLK_TIMER11_GCLK,
    PRCM_CLK_TIMER2_GCLK,
    PRCM_CLK_TIMER3_GCLK,
    PRCM_CLK_TIMER4_GCLK,
    PRCM_CLK_TIMER5_GCLK,
    PRCM_CLK_TIMER6_GCLK,
    PRCM_CLK_TIMER7_GCLK,
    PRCM_CLK_TIMER8_GCLK,
    PRCM_CLK_TIMER9_GCLK,
    PRCM_CLK_UART_GFCLK,
    PRCM_CLK_CPSW_CPTS_RFT_CLK,
    PRCM_CLK_CPSW_250MHZ_CLK,
    PRCM_CLK_CPSW_5MHZ_CLK,
    PRCM_CLK_CPSW_50MHZ_CLK,
    PRCM_CLK_CPSW_125MHZ_GCLK,
    PRCM_CLK_MPU_CLK,
    PRCM_CLK_OCPWP_L3_GCLK,
    PRCM_CLK_OCPWP_L4_GCLK_EN,
    PRCM_CLK_RTC_32KCLK,
    PRCM_CLK_L4_RTC_GCLK,
    PRCM_CLK_L4_WKUP_GCLK,
    PRCM_CLK_SR_SYSCLK,
    PRCM_CLK_USBPHY_32KHZ_GCLK,
    PRCM_CLK_WDT0_GCLK,
    PRCM_CLK_WDT1_GCLK,
    PRCM_CLK_TAMPER_L4_GCLK,
    PRCM_CLK_USB_OTG_SS_REFCLK,
    PRCM_CLK_USB_PLL_CLK,
    PRCM_CLK_USIM0_FCLK,
    PRCM_CLK_USIM0_FCLK32,
    PRCM_CLK_USIM1_FCLK,
    PRCM_CLK_USIM1_FCLK32,
    PRCM_CLK_L3S_TSC_GCLK,
    PRCM_CLK_ADC_FCLK,
    PRCM_CLK_24MHZ,
    PRCM_CLK_GPIO0_GDBCLK,
    PRCM_CLK_I2C0_GFCLK,
    PRCM_CLK_L4_WKUP_AON_GCLK,
    PRCM_CLK_SYNCTIMER32K_GFCLK,
    PRCM_CLK_TIMER0_GCLK,
    PRCM_CLK_TIMER1_GCLK,
    PRCM_CLK_UART0_GFCLK,
    PRCM_CLK_STD_EFUSE_SYSCLK,
    PRCM_CLK_MAX = PRCM_CLK_STD_EFUSE_SYSCLK,
    /*!< Enum Upper bound */
    PRCM_CLK_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmClockId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Reset Groups
 */
typedef enum 
{
    PRCM_RG_CUST_EFUSE_RST,
    PRCM_RG_MIN = PRCM_RG_CUST_EFUSE_RST,
    /*!< Lower bound (inclusive) */
    PRCM_RG_DLL_RESET,
    PRCM_RG_DPLL_RST,
    PRCM_RG_EMIF_DDR_PHY_PWRON_RST,
    PRCM_RG_EMU_EARLY_PWRON_RST,
    PRCM_RG_EMU_PWRON_RST,
    PRCM_RG_EMU_RST,
    PRCM_RG_GFX_DOM_RST,
    PRCM_RG_GFX_RST,
    PRCM_RG_ICSS_LRST,
    PRCM_RG_MPU_AO_RST,
    PRCM_RG_MPU_PWRON_RST,
    PRCM_RG_MPU_RST,
    PRCM_RG_PER_DOM_RST,
    PRCM_RG_RTC_DOM_RST,
    PRCM_RG_STD_EFUSE_PWRON_RST,
    PRCM_RG_TAMPER_DOM_RST,
    PRCM_RG_USB_POR,
    PRCM_RG_WKUP_DOM_RST,
    PRCM_RG_WKUP_M3_LRST,
    PRCM_RG_WKUP_PWRON_RST,
    PRCM_RG_WKUP_SYS_PWRON_RST,
    PRCM_RG_MAX = PRCM_RG_WKUP_SYS_PWRON_RST,
    /*!< Enum Upper bound */
    PRCM_RG_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmResetGroupId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Reset List
 */
typedef enum 
{
    PRCM_RST_MIN,
    /*!< Enum Lower bound */
    PRCM_RST_MAX = PRCM_RST_MIN,
    /*!< Enum Upper bound */
    PRCM_RST_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmResetId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Specification of Memory ON State
 */
typedef enum 
{
    MEM_ON_ALWAYS_ON,
    MEM_ON_MIN = MEM_ON_ALWAYS_ON,
    /*!< Lower bound (inclusive) */
    MEM_ON_SOFTWARE_CONTROL,
    MEM_ON_MAX = MEM_ON_SOFTWARE_CONTROL,
    /*!< Enum Upper bound */
    MEM_ON_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} memOnState_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Specification of Memory Retention State
 */
typedef enum 
{
    MEM_RET_ALWAYS_OFF,
    MEM_RET_MIN = MEM_RET_ALWAYS_OFF,
    /*!< Lower bound (inclusive) */
    MEM_RET_ALWAYS_RETENTION,
    MEM_RET_SOFTWARE_CONTROL,
    MEM_RET_MAX = MEM_RET_SOFTWARE_CONTROL,
    /*!< Enum Upper bound */
    MEM_RET_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} memRetState_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Type of DPLL
 */
typedef enum 
{
    PRCM_DPLL_TYPE_ADPLLS,
    PRCM_DPLL_TYPE_MIN = PRCM_DPLL_TYPE_ADPLLS,
    /*!< Lower bound (inclusive) */
    PRCM_DPLL_TYPE_ADPLLLJ,
    PRCM_DPLL_TYPE_MAX = PRCM_DPLL_TYPE_ADPLLLJ,
    /*!< Enum Upper bound */
    PRCM_DPLL_TYPE_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmDpllType_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief PRCM Logic Retention Type
 */
typedef enum 
{
    PRCM_RT_NO_RETENTION,
    PRCM_RT_MIN = PRCM_RT_NO_RETENTION,
    /*!< Lower bound (inclusive) */
    PRCM_RT_FULL_RETENTION,
    PRCM_RT_PARTIAL_RETENTION,
    PRCM_RT_MAX = PRCM_RT_PARTIAL_RETENTION,
    /*!< Enum Upper bound */
    PRCM_RT_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmRetentionType_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Physical Memories
 */
typedef enum 
{
    PRCM_PHY_MEM_DEBUGSS,
    PRCM_PHY_MEM_MIN = PRCM_PHY_MEM_DEBUGSS,
    /*!< Lower bound (inclusive) */
    PRCM_PHY_MEM_DSSMEM,
    PRCM_PHY_MEM_UART,
    PRCM_PHY_MEM_BANK1,
    PRCM_PHY_MEM_BANK2,
    PRCM_PHY_MEM_GFX,
    PRCM_PHY_MEM_DMEM0,
    PRCM_PHY_MEM_DMEM1,
    PRCM_PHY_MEM_DMEM2,
    PRCM_PHY_MEM_DMEM3,
    PRCM_PHY_MEM_IMEM0,
    PRCM_PHY_MEM_IMEM1,
    PRCM_PHY_MEM_IMEM2,
    PRCM_PHY_MEM_IMEM3,
    PRCM_PHY_MEM_PRUSS0_MEM,
    PRCM_PHY_MEM_PRUSS1_MEM,
    PRCM_PHY_MEM_LCD_CORE_PALETTE_RAM,
    PRCM_PHY_MEM_LCD_DMA_FIFO_RAM,
    PRCM_PHY_MEM_MEMORYBANKNONAME,
    PRCM_PHY_MEM_MBOXSRAM,
    PRCM_PHY_MEM_MSHSI2COCP_MEMORY,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_CPPI,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ADDR,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_DB,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_INFO,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ST,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_STATE,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_STATISTICS,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_DB,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_INFO,
    PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_ST,
    PRCM_PHY_MEM_MPU_L1,
    PRCM_PHY_MEM_MPU_L2,
    PRCM_PHY_MEM_MPU_RAM,
    PRCM_PHY_MEM_DMA_CRYPTO,
    PRCM_PHY_MEM_PKA_MEM,
    PRCM_PHY_MEM_USB,
    PRCM_PHY_MEM_WB0,
    PRCM_PHY_MEM_WB1,
    PRCM_PHY_MEM_MAX = PRCM_PHY_MEM_WB1,
    /*!< Enum Upper bound */
    PRCM_PHY_MEM_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmPhyMemId_t;

/*----------------------------------------------------------------------------*/ 
/** 
 * \brief Clock Tree nodes - RootClk, Div, Mux, Pll
 */
typedef enum 
{
    PRCM_ROOT_CLK_MPU_PLL,
    PRCM_ROOT_CLK_MIN = PRCM_ROOT_CLK_MPU_PLL,
    /*!< Lower bound (inclusive) */
    PRCM_NODE_MIN = PRCM_ROOT_CLK_MIN,
    /*!< Lower bound for Node */
    PRCM_ROOT_CLK_SYS_CLKIN,
    PRCM_ROOT_CLK_TCLKIN,
    PRCM_ROOT_CLK_32K_MOSC,
    PRCM_ROOT_CLK_32K_PER,
    PRCM_ROOT_CLK_32K_RC,
    PRCM_ROOT_CLK_32K_RTC,
    PRCM_ROOT_CLK_32K_TPM,
    PRCM_ROOT_CLK_MAX = PRCM_ROOT_CLK_32K_TPM,
    /*!< Enum Upper bound */
    PRCM_MUX_CLKOUT1SEL2,
    PRCM_MUX_MIN = PRCM_MUX_CLKOUT1SEL2,
    /*!< Lower bound (inclusive) */
    PRCM_MUX_CLKOUT1,
    PRCM_MUX_CLKOUT_32K,
    PRCM_MUX_CLKOUT1_MUX1,
    PRCM_MUX_CLKOUT1_MUX2,
    PRCM_MUX_CLKOUT1_MUX3,
    PRCM_MUX_SGX_CLKSEL,
    PRCM_MUX_MAG_FCLK,
    PRCM_MUX_ICSS_OCP_CLK,
    PRCM_MUX_LCD_CLK,
    PRCM_MUX_TIMER10_CLK,
    PRCM_MUX_TIMER11_CLK,
    PRCM_MUX_TIMER1_CLK,
    PRCM_MUX_TIMER2_CLK,
    PRCM_MUX_TIMER3_CLK,
    PRCM_MUX_TIMER4_CLK,
    PRCM_MUX_TIMER5_CLK,
    PRCM_MUX_TIMER6_CLK,
    PRCM_MUX_TIMER8_CLK,
    PRCM_MUX_TIMER9_CLK,
    PRCM_MUX_CPTS_RFT,
    PRCM_MUX_USBPHY_32KHZ,
    PRCM_MUX_WDT0,
    PRCM_MUX_WDT1,
    PRCM_MUX_USIM0_FCLK,
    PRCM_MUX_USIM1_FCLK,
    PRCM_MUX_USIM_DBCLKMUX,
    PRCM_MUX_GPIO_DBCLK,
    PRCM_MUX_SYNCTIMER32K,
    PRCM_MUX_TIMER0,
    PRCM_MUX_TIMER1,
    PRCM_MUX_MAX = PRCM_MUX_TIMER1,
    /*!< Enum Upper bound */
    PRCM_DIV_CORE_L4,
    PRCM_DIV_MIN = PRCM_DIV_CORE_L4,
    /*!< Lower bound (inclusive) */
    PRCM_DIV_CORE_25M,
    PRCM_DIV_SYSCLK,
    PRCM_DIV_CLKOUT1SEL0DIV,
    PRCM_DIV_CLKOUT1SEL2DIV1,
    PRCM_DIV_CLKOUT1SEL2DIV2,
    PRCM_DIV_CLKOUT2_DIV1,
    PRCM_DIV_CLKOUT2_DIV2,
    PRCM_DIV_DLL_AGING_CLK,
    PRCM_DIV_GFX_FCLK,
    PRCM_DIV_PERS_CLK,
    PRCM_DIV_MMC,
    PRCM_DIV_PDA2CAD8896B3447FD,
    PRCM_DIV_CPSW_125MHZ_OCP,
    PRCM_DIV_CPSW_50M,
    PRCM_DIV_CPSW_5M,
    PRCM_DIV_USIM_FCLK,
    PRCM_DIV_VTP_CLK,
    PRCM_DIV_CLK_DIV_24,
    PRCM_DIV_UART5,
    PRCM_DIV_MAX = PRCM_DIV_UART5,
    /*!< Enum Upper bound */
    PRCM_DPLL_CORE,
    PRCM_DPLL_MIN = PRCM_DPLL_CORE,
    /*!< Lower bound (inclusive) */
    PRCM_DPLL_DDR,
    PRCM_DPLL_DISP,
    PRCM_DPLL_EXTDEV,
    PRCM_DPLL_MPU,
    PRCM_DPLL_PER,
    PRCM_DPLL_MAX = PRCM_DPLL_PER,
    /*!< Enum Upper bound */
    PRCM_NODE_MAX = PRCM_DPLL_MAX,
    /*!< Upper bound for Node */
    PRCM_ROOT_CLK_UNDEF = (UINT32_MAX),
    /*!< Undefined value */
    PRCM_MUX_UNDEF = (UINT32_MAX),
    /*!< Undefined value */
    PRCM_DIV_UNDEF = (UINT32_MAX),
    /*!< Undefined value */
    PRCM_DPLL_UNDEF = (UINT32_MAX),
    /*!< Undefined value */
    PRCM_NODE_UNDEF = (UINT32_MAX),
    /*!< Undefined value */

} prcmNodeId_t;

/*----------------------------------------------------------------------------*/
/**
 *  \brief Structure defining pll post divider value with post divider ID.
 *         User will use this struct to pass information to the prcm API's.
 * 
 *  The division values are 1-N (direct value written to register), so mapping 
 *  to bit-field config value is not needed.
 */
typedef struct
{
    const prcmDpllPostDivId_t postDivId;
    /**< Unique Id of the post divider. */
    uint32_t configValue;
    /**< Division value. */    
}pllPostDivValue_t;

/*----------------------------------------------------------------------------*/
/**
 * \brief This shall be used by the APIs to take configuration input from the user.
 *          This struct will not be modelled to represent a PLL.
 */
typedef struct
{
    uint16_t multiplier;
    /**< Multiplier value for DPLL configuration. */
    uint16_t divider;
    /**< Divider value for DPLL configuration. */
    pllPostDivValue_t *postDivConfList;
    /**< List of post divider configuration values. */
    uint8_t postDivConfigValueMax;
    /**< Number of post divider configurations. */
}prcmDpllConfig_t;

/* ========================================================================== */
/*                        Global Variables Declarations                       */
/* ========================================================================== */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* HW_PRCM_H */

