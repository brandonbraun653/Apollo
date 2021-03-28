/**
 * \file   am43xx_pm_app.c
 *
 * \brief  Source file containing the PM related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "hw_types.h"
#include "chipdb.h"
#include "hw_am43xx_chipdb.h"
#include "am437x.h"
#include "hw_cm_per.h"
#include "hw_cm_wkup.h"
#include "hw_prm_device.h"
#include "hw_edma3tc.h"
#include "prcm.h"
#include "board.h"
#include "device.h"
#include "gpmc.h"
#include "pm_app_types.h"
#include "pm_app_module_cfg.h"
#include "am43xx_pm_app_cm3.h"
#include "am43xx_pm_app_modules.h"
#include "am43xx_pm_app.h"
#include "console_utils.h"
#include "rtc_app.h"
#include "interrupt.h"
#include "pm_app.h"
#include "pmic_device.h"
#include "hs_mmcsd.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void PmAppClearWkpGenCfg();

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

pmAppModuleSelCfg_t gPmAppBootModuleList[] =
{
    {CHIPDB_MOD_ID_MMCSD, 0U, TRUE},
    {CHIPDB_MOD_ID_MMCSD, 1U, TRUE},
    {CHIPDB_MOD_ID_MMCSD, 2U, TRUE},
    {CHIPDB_MOD_ID_MCSPI, 0U, TRUE},
    {CHIPDB_MOD_ID_MCSPI, 1U, TRUE},
    {CHIPDB_MOD_ID_MCSPI, 2U, TRUE},
    {CHIPDB_MOD_ID_MCSPI, 3U, TRUE},
    {CHIPDB_MOD_ID_MCSPI, 4U, TRUE},
    {CHIPDB_MOD_ID_GPMC, 0U, TRUE},
    {CHIPDB_MOD_ID_ELM, 0U, TRUE},
    {CHIPDB_MOD_ID_USB, 0U, TRUE},
    {CHIPDB_MOD_ID_USB, 1U, TRUE},
    {CHIPDB_MOD_ID_QSPI, 0U, TRUE},
    {CHIPDB_MOD_ID_CPSW, 0U, TRUE},
    {CHIPDB_MOD_ID_UART, 0U, TRUE},
    {CHIPDB_MOD_ID_UART, 1U, TRUE},
    {CHIPDB_MOD_ID_UART, 2U, TRUE},
    {CHIPDB_MOD_ID_UART, 3U, TRUE},
    {CHIPDB_MOD_ID_UART, 4U, TRUE},
    {CHIPDB_MOD_ID_UART, 5U, TRUE},
};

pmAppModuleSelCfg_t gPmAppSecureModuleList[] =
{
    {CHIPDB_MOD_ID_AES, 0U, TRUE},
    {CHIPDB_MOD_ID_RNG, 0U, TRUE},
    {CHIPDB_MOD_ID_PKA, 0U, TRUE},
    {CHIPDB_MOD_ID_CRYPTODMA, 0U, TRUE},
    {CHIPDB_MOD_ID_DES, 0U, TRUE},
    {CHIPDB_MOD_ID_SHA, 0U, TRUE},
    {CHIPDB_MOD_ID_ADC1, 0U, TRUE},
    {CHIPDB_MOD_ID_OTFA, 0U, TRUE},
    {CHIPDB_MOD_ID_USIM, 0U, TRUE},
    {CHIPDB_MOD_ID_USIM, 1U, TRUE},
    {CHIPDB_MOD_ID_EMIF_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_GPMC_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_OCMCRAM_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_GFX_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_MMCSD2_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_MCASP0_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_MCASP1_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_EDMA3TC_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_QSPI_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_PRU_ICSS_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_EDMA3CC_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_DEBUGSS_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_AES_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_DES_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_SHA_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_ADC0_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_ADC1_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_L2_CACHE_FW, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_CMU, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_AXI2OCP, 0U, TRUE},
    {CHIPDB_MOD_ID_P1500, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_ROM_SECURE, 0U, TRUE},
    {CHIPDB_MOD_ID_SMARTREFLEX, 0U, TRUE},
    {CHIPDB_MOD_ID_SMARTREFLEX, 1U, TRUE},
};

pmAppModuleSelCfg_t gPmAppUtilsModuleList[] =
{
    {CHIPDB_MOD_ID_I2C, 0U, TRUE},
    {CHIPDB_MOD_ID_I2C, 1U, TRUE},
    {CHIPDB_MOD_ID_I2C, 2U, TRUE},
    {CHIPDB_MOD_ID_UART, 0U, TRUE},
    {CHIPDB_MOD_ID_UART, 1U, TRUE},
    {CHIPDB_MOD_ID_UART, 2U, TRUE},
    {CHIPDB_MOD_ID_UART, 3U, TRUE},
    {CHIPDB_MOD_ID_UART, 4U, TRUE},
    {CHIPDB_MOD_ID_UART, 5U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 0U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 2U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 3U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 4U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 5U, TRUE},
    {CHIPDB_MOD_ID_DMTIMER, 6U, TRUE},
};

pmAppModuleSelCfg_t gPmAppModuleSkipList[] =
{
    {CHIPDB_MOD_ID_ELM, 0U, TRUE},
    {CHIPDB_MOD_ID_RTC, 0U, TRUE},
    {CHIPDB_MOD_ID_MMCSD, 0U, TRUE},
    {CHIPDB_MOD_ID_GPMC, 0U, TRUE},
    {CHIPDB_MOD_ID_UART, 0U, TRUE},
    {CHIPDB_MOD_ID_WDT, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_CORE, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU, 0U, TRUE},
    {CHIPDB_MOD_ID_PRCM, 0U, TRUE},
    {CHIPDB_MOD_ID_CONTROL_MODULE, 0U, TRUE},
    {CHIPDB_MOD_ID_DEBUGSS, 0U, TRUE},
    {CHIPDB_MOD_ID_OCMCRAM, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC_UMEM, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC_DMEM, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC_BIT_BAND_REG, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC_NVIC, 0U, TRUE},
    {CHIPDB_MOD_ID_WKUP_PROC_ROM_TAB, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_ROM_PUBLIC, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_SRAM, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_L2_CACHE, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_INTC, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_SS_CFG, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_PL310, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_SCM, 0U, TRUE},
    {CHIPDB_MOD_ID_MPU_WAKEUP_GEN, 0U, TRUE},
    {CHIPDB_MOD_ID_ERMC, 0U, TRUE},
};

pmAppDevSelCfg_t gPmAppDevicesSkipList[] =
{
    {DEVICE_ID_VTT, 0U, TRUE},
    {DEVICE_ID_PMIC_TPS65217, 0U, TRUE},
    {DEVICE_ID_PMIC_TPS65910, 0U, TRUE},
};

pmAppPwrDomainCfg_t gPmAppDs0PwrDomainCfgList[] =
{
    {PRCM_PD_GFX, PRCM_PD_STATUS_OFF},
    {PRCM_PD_PER, PRCM_PD_STATUS_ON},
    {PRCM_PD_WKUP, PRCM_PD_STATUS_ON},
};

pmAppWakeSrcCfg_t gPmAppDs0WakeSrcCfgList[] =
{
    {CHIPDB_MOD_ID_RTC, 0U, RTC_APP_WAKE_SRC_CFG_WKUP_ALARM, 0U, NULL},
};

pmAppPwrModeCfg_t gPmAppPwrModesCfg[] =
{
    {
        PM_APP_PWR_MODES_DS0,
        &gPmAppDs0PwrDomainCfgList[0],
        sizeof(gPmAppDs0PwrDomainCfgList)/sizeof(gPmAppDs0PwrDomainCfgList[0]),
        &gPmAppDs0WakeSrcCfgList[0],
        sizeof(gPmAppDs0WakeSrcCfgList)/sizeof(gPmAppDs0WakeSrcCfgList[0])
    }
};

/*
 * \note  This array is sorted in ascending order of ResourceIds
 *        for fast binary search lookup.
 */
pmAppModuleInstObj_t gPmAppModuleInstCfg[] = {
    {CHIPDB_MOD_ID_MPU_CORE, 0U, 0U, TRUE, NULL}, /* MPU_CORE- */
    {CHIPDB_MOD_ID_MPU, 0U, 0U, TRUE, NULL}, /* MPU */
    {CHIPDB_MOD_ID_DSS, 0U, 0U, TRUE, NULL}, /* DSS */
    {CHIPDB_MOD_ID_EMIF, 0U, 0U, TRUE, NULL}, /* EMIF */
    {CHIPDB_MOD_ID_GPMC, 0U, 0U, TRUE, NULL}, /* GPMC */
    {CHIPDB_MOD_ID_DCAN, 0U, 0U, TRUE, NULL}, /* DCAN0 */
    {CHIPDB_MOD_ID_DCAN, 1U, 0U, TRUE, NULL}, /* DCAN1 */
    {CHIPDB_MOD_ID_GPIO, 0U, 0U, TRUE, NULL}, /* GPIO0 */
    {CHIPDB_MOD_ID_GPIO, 1U, 0U, TRUE, NULL}, /* GPIO1 */
    {CHIPDB_MOD_ID_GPIO, 2U, 0U, TRUE, NULL}, /* GPIO2 */
    {CHIPDB_MOD_ID_GPIO, 3U, 0U, TRUE, NULL}, /* GPIO3 */
    {CHIPDB_MOD_ID_GPIO, 4U, 0U, TRUE, NULL}, /* GPIO4 */
    {CHIPDB_MOD_ID_GPIO, 5U, 0U, TRUE, NULL}, /* GPIO5 */
    {CHIPDB_MOD_ID_I2C, 0U, 0U, TRUE, NULL}, /* I2C0 */
    {CHIPDB_MOD_ID_I2C, 1U, 0U, TRUE, NULL}, /* I2C1 */
    {CHIPDB_MOD_ID_I2C, 2U, 0U, TRUE, NULL}, /* I2C2 */
    {CHIPDB_MOD_ID_MCASP, 0U, 0U, TRUE, NULL}, /* MCASP0- */
    {CHIPDB_MOD_ID_MCASP, 1U, 0U, TRUE, NULL}, /* MCASP1- */
    {CHIPDB_MOD_ID_USB, 0U, 0U, TRUE, NULL}, /* USB0- */
    {CHIPDB_MOD_ID_USB, 1U, 0U, TRUE, NULL}, /* USB1- */
    {CHIPDB_MOD_ID_MCSPI, 0U, 0U, TRUE, NULL}, /* SPI0 */
    {CHIPDB_MOD_ID_MCSPI, 1U, 0U, TRUE, NULL}, /* SPI1 */
    {CHIPDB_MOD_ID_MCSPI, 2U, 0U, TRUE, NULL}, /* SPI2 */
    {CHIPDB_MOD_ID_MCSPI, 3U, 0U, TRUE, NULL}, /* SPI3 */
    {CHIPDB_MOD_ID_MCSPI, 4U, 0U, TRUE, NULL}, /* SPI4 */
    {CHIPDB_MOD_ID_QSPI, 0U, 0U, TRUE, NULL}, /* QSPI */
    {CHIPDB_MOD_ID_UART, 0U, 0U, TRUE, NULL}, /* UART0 */
    {CHIPDB_MOD_ID_UART, 1U, 0U, TRUE, NULL}, /* UART1 */
    {CHIPDB_MOD_ID_UART, 2U, 0U, TRUE, NULL}, /* UART2 */
    {CHIPDB_MOD_ID_UART, 3U, 0U, TRUE, NULL}, /* UART3 */
    {CHIPDB_MOD_ID_UART, 4U, 0U, TRUE, NULL}, /* UART4 */
    {CHIPDB_MOD_ID_UART, 5U, 0U, TRUE, NULL}, /* UART5 */
    {CHIPDB_MOD_ID_PWMSS, 0U, 0U, TRUE, NULL}, /* EPWMSS0 */
    {CHIPDB_MOD_ID_PWMSS, 1U, 0U, TRUE, NULL}, /* EPWMSS1 */
    {CHIPDB_MOD_ID_PWMSS, 2U, 0U, TRUE, NULL}, /* EPWMSS2 */
    {CHIPDB_MOD_ID_PWMSS, 3U, 0U, TRUE, NULL}, /* EPWMSS3 */
    {CHIPDB_MOD_ID_PWMSS, 4U, 0U, TRUE, NULL}, /* EPWMSS4 */
    {CHIPDB_MOD_ID_PWMSS, 5U, 0U, TRUE, NULL}, /* EPWMSS5 */
    {CHIPDB_MOD_ID_SPINLOCK, 0U, 0U, TRUE, NULL}, /* SPINLOCK */
    {CHIPDB_MOD_ID_HDQ1W, 0U, 0U, TRUE, NULL}, /* HDQ1W */
    {CHIPDB_MOD_ID_AES, 0U, 0U, TRUE, NULL}, /* AES0 */
    {CHIPDB_MOD_ID_RNG, 0U, 0U, TRUE, NULL}, /* RNG */
    {CHIPDB_MOD_ID_PKA, 0U, 0U, TRUE, NULL}, /* PKA */
    {CHIPDB_MOD_ID_MPU_SCU, 0U, 0U, TRUE, NULL}, /* MPU_SCU- */
    {CHIPDB_MOD_ID_CRYPTODMA, 0U, 0U, TRUE, NULL}, /* CRYPTODMA */
    {CHIPDB_MOD_ID_DES, 0U, 0U, TRUE, NULL}, /* DES */
    {CHIPDB_MOD_ID_SHA, 0U, 0U, TRUE, NULL}, /* SHA0 */
    {CHIPDB_MOD_ID_ADC1, 0U, 0U, TRUE, NULL}, /* ADC1- */
    {CHIPDB_MOD_ID_GFX, 0U, 0U, TRUE, NULL}, /* GFX */
    {CHIPDB_MOD_ID_EDMA3CC, 0U, 0U, TRUE, NULL}, /* TPCC */
    {CHIPDB_MOD_ID_EDMA3TC, 0U, 0U, TRUE, NULL}, /* TPTC0 */
    {CHIPDB_MOD_ID_EDMA3TC, 1U, 0U, TRUE, NULL}, /* TPTC1 */
    {CHIPDB_MOD_ID_EDMA3TC, 2U, 0U, TRUE, NULL}, /* TPTC2 */
    {CHIPDB_MOD_ID_OTFA, 0U, 0U, TRUE, NULL}, /* OTFA_EMIF */
    {CHIPDB_MOD_ID_TPMSS, 0U, 0U, TRUE, NULL}, /* TPMSS */
    {CHIPDB_MOD_ID_VPFE, 0U, 0U, TRUE, NULL}, /* VPFE0 */
    {CHIPDB_MOD_ID_VPFE, 1U, 0U, TRUE, NULL}, /* VPFE1 */
    {CHIPDB_MOD_ID_CPSW, 0U, 0U, TRUE, NULL}, /* CPGMAC0 */
    {CHIPDB_MOD_ID_USIM, 0U, 0U, TRUE, NULL}, /* USIM0 */
    {CHIPDB_MOD_ID_USIM, 1U, 0U, TRUE, NULL}, /* USIM1 */
    {CHIPDB_MOD_ID_ADC0, 0U, 0U, TRUE, NULL}, /* ADC_TSC */
    {CHIPDB_MOD_ID_MMCSD, 0U, 0U, TRUE, NULL}, /* MMC0 */
    {CHIPDB_MOD_ID_MMCSD, 1U, 0U, TRUE, NULL}, /* MMC1 */
    {CHIPDB_MOD_ID_MMCSD, 2U, 0U, TRUE, NULL}, /* MMC2 */
    {CHIPDB_MOD_ID_DMTIMER, 0U, 0U, TRUE, NULL}, /* TIMER0 */
    {CHIPDB_MOD_ID_DMTIMER, 1U, 0U, TRUE, NULL}, /* DMTIMER1- */
    {CHIPDB_MOD_ID_DMTIMER, 2U, 0U, TRUE, NULL}, /* TIMER2 */
    {CHIPDB_MOD_ID_DMTIMER, 3U, 0U, TRUE, NULL}, /* TIMER3 */
    {CHIPDB_MOD_ID_DMTIMER, 4U, 0U, TRUE, NULL}, /* TIMER4 */
    {CHIPDB_MOD_ID_DMTIMER, 5U, 0U, TRUE, NULL}, /* TIMER5 */
    {CHIPDB_MOD_ID_DMTIMER, 6U, 0U, TRUE, NULL}, /* TIMER6 */
    {CHIPDB_MOD_ID_DMTIMER, 7U, 0U, TRUE, NULL}, /* TIMER7 */
    {CHIPDB_MOD_ID_DMTIMER, 8U, 0U, TRUE, NULL}, /* TIMER8 */
    {CHIPDB_MOD_ID_DMTIMER, 9U, 0U, TRUE, NULL}, /* TIMER9 */
    {CHIPDB_MOD_ID_DMTIMER, 10U, 0U, TRUE, NULL}, /* TIMER10 */
    {CHIPDB_MOD_ID_DMTIMER, 11U, 0U, TRUE, NULL}, /* TIMER11 */
    {CHIPDB_MOD_ID_DMTIMER1_1MS, 0U, 0U, TRUE, NULL}, /* TIMER1 */
    {CHIPDB_MOD_ID_WDT, 0U, 0U, TRUE, NULL}, /* WDT0 */
    {CHIPDB_MOD_ID_WDT, 0U, 0U, TRUE, NULL}, /* WDT1 */
    {CHIPDB_MOD_ID_L3F_CFG, 0U, 0U, TRUE, NULL}, /* L3F_CFG- */
    {CHIPDB_MOD_ID_L3S_CFG, 0U, 0U, TRUE, NULL}, /* L3S_CFG- */
    {CHIPDB_MOD_ID_MAILBOX, 0U, 0U, TRUE, NULL}, /* MAILBOX- */
    {CHIPDB_MOD_ID_OCP_WP_NOC, 0U, 0U, TRUE, NULL}, /* OCP_WP_NOC */
    {CHIPDB_MOD_ID_PRCM, 0U, 0U, TRUE, NULL}, /* PRCM- */
    {CHIPDB_MOD_ID_SMARTREFLEX, 0U, 0U, TRUE, NULL}, /* SMARTREFLEX0 */
    {CHIPDB_MOD_ID_SMARTREFLEX, 1U, 0U, TRUE, NULL}, /* SMARTREFLEX1 */
    {CHIPDB_MOD_ID_RTCSS, 0U, 0U, TRUE, NULL}, /* RTCSS- */
    {CHIPDB_MOD_ID_PRU_ICSS, 0U, 0U, TRUE, NULL}, /* PRU_ICSS0- */
    {CHIPDB_MOD_ID_PRU_ICSS, 1U, 0U, TRUE, NULL}, /* PRU_ICSS1- */
    {CHIPDB_MOD_ID_CONTROL_MODULE, 0U, 0U, TRUE, NULL}, /* CONTROL */
    {CHIPDB_MOD_ID_DEBUGSS, 0U, 0U, TRUE, NULL}, /* DEBUGSS */
    {CHIPDB_MOD_ID_OCMCRAM, 0U, 0U, TRUE, NULL}, /* OCMCRAM */
    {CHIPDB_MOD_ID_RTC, 0U, 0U, TRUE, NULL}, /* RTC */
    {CHIPDB_MOD_ID_SYNCTIMER, 0U, 0U, TRUE, NULL}, /* SYNCTIMER */
    {CHIPDB_MOD_ID_ERMC, 0U, 0U, TRUE, NULL}, /* ERMC */
    {CHIPDB_MOD_ID_ELM, 0U, 0U, TRUE, NULL}, /* ELM */
    {CHIPDB_MOD_ID_EMIF_FW, 0U, 0U, TRUE, NULL}, /* EMIF_FW */
    {CHIPDB_MOD_ID_GPMC_FW, 0U, 0U, TRUE, NULL}, /* GPMC_FW- */
    {CHIPDB_MOD_ID_OCMCRAM_FW, 0U, 0U, TRUE, NULL}, /* OCMCRAM_FW- */
    {CHIPDB_MOD_ID_GFX_FW, 0U, 0U, TRUE, NULL}, /* GFX_FW- */
    {CHIPDB_MOD_ID_MMCSD2_FW, 0U, 0U, TRUE, NULL}, /* MMCSD2_FW- */
    {CHIPDB_MOD_ID_MCASP0_FW, 0U, 0U, TRUE, NULL}, /* MCASP0_FW- */
    {CHIPDB_MOD_ID_MCASP1_FW, 1U, 0U, TRUE, NULL}, /* MCASP1_FW- */
    {CHIPDB_MOD_ID_EDMA3TC_FW, 0U, 0U, TRUE, NULL}, /* EDMA3TC_FW- */
    {CHIPDB_MOD_ID_QSPI_FW, 0U, 0U, TRUE, NULL}, /* QSPI_FW- */
    {CHIPDB_MOD_ID_PRU_ICSS_FW, 0U, 0U, TRUE, NULL}, /* PRU_ICSS_FW- */
    {CHIPDB_MOD_ID_EDMA3CC_FW, 0U, 0U, TRUE, NULL}, /* EDMA3CC_FW- */
    {CHIPDB_MOD_ID_DEBUGSS_FW, 0U, 0U, TRUE, NULL}, /* DEBUGSS_FW- */
    {CHIPDB_MOD_ID_AES_FW, 0U, 0U, TRUE, NULL}, /* AES_FW- */
    {CHIPDB_MOD_ID_DES_FW, 0U, 0U, TRUE, NULL}, /* DES_FW- */
    {CHIPDB_MOD_ID_SHA_FW, 0U, 0U, TRUE, NULL}, /* SHA_FW- */
    {CHIPDB_MOD_ID_ADC0_FW, 0U, 0U, TRUE, NULL}, /* ADC0_FW- */
    {CHIPDB_MOD_ID_ADC1_FW, 0U, 0U, TRUE, NULL}, /* ADC1_FW- */
    {CHIPDB_MOD_ID_MPU_L2_CACHE_FW, 0U, 0U, TRUE, NULL}, /* MPU_L2_CACHE_FW- */
    {CHIPDB_MOD_ID_MPU_CMU, 0U, 0U, TRUE, NULL}, /* MPU_CMU- */
    {CHIPDB_MOD_ID_MPU_AXI2OCP, 0U, 0U, TRUE, NULL}, /* MPU_AXI2OCP- */
    {CHIPDB_MOD_ID_P1500, 0U, 0U, TRUE, NULL}, /* P1500- */
    {CHIPDB_MOD_ID_WKUP_PROC, 0U, 0U, TRUE, NULL}, /* WKUP_M3 */
    {CHIPDB_MOD_ID_WKUP_PROC_UMEM, 0U, 0U, TRUE, NULL}, /* WKUP_PROC_UMEM- */
    {CHIPDB_MOD_ID_WKUP_PROC_DMEM, 0U, 0U, TRUE, NULL}, /* WKUP_PROC_DMEM- */
    {CHIPDB_MOD_ID_WKUP_PROC_BIT_BAND_REG, 0U, 0U, TRUE, NULL}, /* WKUP_PROC_BIT_BAND_REG- */
    {CHIPDB_MOD_ID_WKUP_PROC_NVIC, 0U, 0U, TRUE, NULL}, /* WKUP_PROC_NVIC- */
    {CHIPDB_MOD_ID_WKUP_PROC_ROM_TAB, 0U, 0U, TRUE, NULL}, /* WKUP_PROC_ROM_TAB- */
    {CHIPDB_MOD_ID_MPU_ROM_SECURE, 0U, 0U, TRUE, NULL}, /* MPU_ROM_SECURE- */
    {CHIPDB_MOD_ID_MPU_ROM_PUBLIC, 0U, 0U, TRUE, NULL}, /* MPU_ROM_PUBLIC- */
    {CHIPDB_MOD_ID_MPU_SRAM, 0U, 0U, TRUE, NULL}, /* MPU_SRAM- */
    {CHIPDB_MOD_ID_MPU_L2_CACHE, 0U, 0U, TRUE, NULL}, /* MPU_L2_CACHE- */
    {CHIPDB_MOD_ID_MPU_INTC, 0U, 0U, TRUE, NULL}, /* MPU_INTC- */
    {CHIPDB_MOD_ID_MPU_SS_CFG, 0U, 0U, TRUE, NULL}, /* MPU_SS_CFG- */
    {CHIPDB_MOD_ID_MPU_PL310, 0U, 0U, TRUE, NULL}, /* MPU_PL310- */
    {CHIPDB_MOD_ID_MPU_SCM, 0U, 0U, TRUE, NULL}, /* MPU_SCM- */
    {CHIPDB_MOD_ID_MPU_WAKEUP_GEN, 0U, 0U, TRUE, NULL}, /* MPU_WAKEUP_GEN- */
};

pmAppModuleInterfObj_t *gPmAppModuleCfg[] =
{
    NULL, /* MPU_CORE */
    NULL, /* DSP */
    NULL, /* IVA */
    NULL, /* IPU_CORE */
    NULL, /* EVE */
    NULL, /* GPU */
    NULL, /* L3 */
    NULL, /* DDR */
    NULL, /* MPU */
    NULL, /* IPU */
    NULL, /* BB2D */
    NULL, /* ATL */
    NULL, /* VCP */
    NULL, /* PRUSS */
    NULL, /* VIP */
    NULL, /* VIP_VINA */
    NULL, /* VIP_VINB */
    NULL, /* VPE */
    NULL, /* DSS */
    NULL, /* DSS_VIDEO */
    NULL, /* DSS_HDMI */
    NULL, /* OCMC_RAM */
    NULL, /* EMIF */
    NULL, /* GPMC */
    NULL, /* DMM */
    NULL, /* SYSTEM_DMA */
    NULL, /* CRYPTO_DMA */
    NULL, /* EDMA */
    NULL, /* DCAN */
    NULL, /* GMAC_SW */
    NULL, /* GMAC_SW_PORT */
    NULL, /* GMAC_SW_SWITCH */
    NULL, /* GPIO */
    NULL, /* I2C */
    NULL, /* MCASP */
    NULL, /* PCIE */
    NULL, /* USB */
    NULL, /* SATA */
    NULL, /* MMC */
    NULL, /* MLB */
    NULL, /* MCSPI */
    NULL, /* QSPI */
    NULL, /* UART */
    NULL, /* PWMSS */
    NULL, /* RTC_SS */
    NULL, /* TIMER */
    NULL, /* COUNTER_32K */
    NULL, /* WD_TIMER */
    NULL, /* SPINLOCK */
    NULL, /* HDQ1W */
    NULL, /* KDB */
    NULL, /* DES3DES */
    NULL, /* SHAMD5 */
    NULL, /* AES */
    NULL, /* RNG */
    NULL, /* FPKA */
    NULL, /* PKA */
    NULL, /* MPU_SCU */
    NULL, /* CRYPTODMA */
    NULL, /* DES */
    NULL, /* SHA */
    NULL, /* ADC1 */
    NULL, /* GFX */
    NULL, /* EDMA3CC */
    NULL, /* EDMA3TC */
    NULL, /* OTFA */
    NULL, /* TPMSS */
    NULL, /* VPFE */
    NULL, /* CPSW */
    NULL, /* USIM */
    NULL, /* ADC0 */
    NULL, /* MMCSD */
    NULL, /* DMTIMER */
    NULL, /* DMTIMER1_1MS */
    NULL, /* WDT */
    NULL, /* L3F_CFG */
    NULL, /* L3S_CFG */
    NULL, /* MAILBOX */
    NULL, /* OCP_WP_NOC */
    NULL, /* PRCM */
    NULL, /* SMARTREFLEX */
    NULL, /* RTCSS */
    NULL, /* PRU_ICSS */
    NULL, /* CONTROL_MODULE */
    NULL, /* DEBUGSS */
    NULL, /* OCMCRAM */
    NULL, /* RTC */
    NULL, /* SYNCTIMER */
    NULL, /* ERMC */
    NULL, /* ELM */
    NULL, /* EMIF_FW */
    NULL, /* GPMC_FW */
    NULL, /* OCMCRAM_FW */
    NULL, /* GFX_FW */
    NULL, /* MMCSD2_FW */
    NULL, /* MCASP0_FW */
    NULL, /* MCASP1_FW */
    NULL, /* EDMA3TC_FW */
    NULL, /* QSPI_FW */
    NULL, /* PRU_ICSS_FW */
    NULL, /* EDMA3CC_FW */
    NULL, /* DEBUGSS_FW */
    NULL, /* AES_FW */
    NULL, /* DES_FW */
    NULL, /* SHA_FW */
    NULL, /* ADC0_FW */
    NULL, /* ADC1_FW */
    NULL, /* MPU_L2_CACHE_FW */
    NULL, /* MPU_CMU */
    NULL, /* MPU_AXI2OCP */
    NULL, /* P1500 */
    NULL, /* WKUP_PROC */
    NULL, /* WKUP_PROC_UMEM */
    NULL, /* WKUP_PROC_DMEM */
    NULL, /* WKUP_PROC_BIT_BAND_REG */
    NULL, /* WKUP_PROC_NVIC */
    NULL, /* WKUP_PROC_ROM_TAB */
    NULL, /* MPU_ROM_SECURE */
    NULL, /* MPU_ROM_PUBLIC */
    NULL, /* MPU_SRAM */
    NULL, /* MPU_L2_CACHE */
    NULL, /* MPU_INTC */
    NULL, /* MPU_SS_CFG */
    NULL, /* MPU_PL310 */
    NULL, /* MPU_SCM */
    NULL, /* MPU_WAKEUP_GEN */
};

extern pmAppCm3Config_t ds0Data;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

extern void saveRestoreContext(unsigned int slpMode, unsigned int memType,
                               unsigned int socVer);
/*
** Enter the desired power save mode
*/
void PMAppInit(pmAppInitObj_t *pInitObj)
{
    /* Initialize the CM3. */
    PMAppCm3Init();

    pInitObj->pModulesInterf = gPmAppModuleCfg[0];
    pInitObj->maxModuleIds = sizeof(gPmAppModuleCfg)/sizeof(gPmAppModuleCfg[0]);
    pInitObj->pModulesCfg = &gPmAppModuleInstCfg[0];
    pInitObj->maxModules = sizeof(gPmAppModuleInstCfg)/sizeof(gPmAppModuleInstCfg[0]);
    pInitObj->pPwrModeCfg = &gPmAppPwrModesCfg[0];
    pInitObj->maxPwrModes = sizeof(gPmAppPwrModesCfg)/sizeof(gPmAppPwrModesCfg[0]);
    pInitObj->pBootModules = &gPmAppBootModuleList[0];
    pInitObj->maxBootModules = sizeof(gPmAppBootModuleList)/sizeof(gPmAppBootModuleList[0]);
    pInitObj->pModulesSkip = &gPmAppModuleSkipList[0];
    pInitObj->maxModulesSkip = sizeof(gPmAppModuleSkipList)/sizeof(gPmAppModuleSkipList[0]);
    pInitObj->pSecureModules = &gPmAppSecureModuleList[0];
    pInitObj->maxSecureModules = sizeof(gPmAppSecureModuleList)/sizeof(gPmAppSecureModuleList[0]);

    /* Initialize the PMIC device. */
    PMICInit();
}

/*
 * Enter the desired power save mode
 */
void PMAppPowerSaveModeEnter(pmAppCfgObj_t *pSuspendCfg, uint32_t slpMode)
{
    uint32_t memType = 0;
    uint32_t deviceVersion = 0;
    volatile uint32_t i = 0, j = 0, k = 0, l = 0;
    uint32_t moduleIdx = 0U;
    uint32_t moduleInst = 0U;
    uint32_t resId = 0U;
    uint32_t devInterfIdx = 0U;
    uint32_t devInterfInst = 0U;
    uint32_t devInterfResId = 0U;
    uint32_t retVal = S_PASS;
    uint32_t pwrDomain = 0U;
    uint32_t devIdx = 0U;
    uint32_t devInstNum = 0U;
    uint32_t modId = 0U;
    uint32_t gpioInstNum = 0U;
    uint32_t pinNum = 0U;
    uint32_t devSkipMask[DEVICE_ID_MAX] = {0U};
    uint32_t devActiveMask[DEVICE_ID_MAX] = {0U};
    const boardData_t *pBoardData = NULL;
    const prcmModuleId_t* pFirstModPtr = NULL;
    prcmModuleId_t prcmResId = 0U;

    /*
     * Configure CM3.
     */
    ds0Data.word.param3 = 0x0;

    /* DDR type. */
    ds0Data.param.memType = 0x3;

    /* DDR VTT configuration. */
    ds0Data.param.vttState = 0x0;
    ds0Data.param.ioIsolation = 0x1U;

    /* Get the GPIO data for VTT from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_VTT, 0U);
    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_GPIO == modId)
    {
        gpioInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_VTT,
            0U);
        pinNum = BOARDGetDeviceCtrlInfo(DEVICE_ID_VTT, 0U);

        if ((INVALID_INST_NUM == gpioInstNum) || (INVALID_INFO == pinNum))
        {
            CONSOLEUtilsPrintf("Invalid GPIO board data!\n");
            retVal = E_FAIL;
        }
        else
        {
            /* The configuration of VTT GPIO pin is talen careof in bootlader. */
            ds0Data.param.vttGpioPin = 0U;
            retVal = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to GPIO!\n");
    }

    /* Wake source configuration. */
    ds0Data.param.wakeSources = 0x1FFFU;

    PMAppCm3Config(ds0Data);

    /* Sync CM3. */
    PMAppCm3Sync();

    /*
     * Skip modules.
     */
    if(S_PASS == retVal)
    {
        /* Secure modules. */
        for(i = 0U; i < pSuspendCfg->pInitObj->maxSecureModules; i++)
        {
            moduleIdx = pSuspendCfg->pInitObj->pSecureModules[i].moduleId;
            moduleInst = pSuspendCfg->pInitObj->pSecureModules[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;
            }
        }

        /* Skip modules. */
        for(i = 0U; i < pSuspendCfg->pInitObj->maxModulesSkip; i++)
        {
            moduleIdx = pSuspendCfg->pInitObj->pModulesSkip[i].moduleId;
            moduleInst = pSuspendCfg->pInitObj->pModulesSkip[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;
            }
        }
    }

    /*
     * Check modules enable status.
     */
    if(S_PASS == retVal)
    {
        /* Traverse modules list. */
        for(i = 0U; i < pSuspendCfg->pInitObj->maxModules; i++)
        {
            moduleIdx = pSuspendCfg->pInitObj->pModulesCfg[i].moduleId;
            moduleInst = pSuspendCfg->pInitObj->pModulesCfg[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                /* Check if module is not skipped. */
                if(FALSE != pSuspendCfg->pInitObj->pModulesCfg[i].cfgPmEnable)
                {
                    /* Check if module is disabled. */
                    if(FALSE == PRCMIsModuleEnabled(moduleIdx, moduleInst))
                    {
                        /* Mark the module as skipped. */
                        pSuspendCfg->pInitObj->pModulesCfg[i].cfgPmEnable = FALSE;
                    }
                }
            }
        }
    }

    /*
     * Check for skip devices.
     */
    if(S_PASS == retVal)
    {
        /* Traverse device list. */
        for(i = 0U; i < pSuspendCfg->maxDeviceSkip; i++)
        {
            devIdx = pSuspendCfg->pDevicesSkipList[i].devId;
            devInstNum = pSuspendCfg->pDevicesSkipList[i].devInst;

            /* Skip the device to power off. */
            devSkipMask[devIdx] |= (1U << devInstNum);
        }
    }

    /*
     * Check for active devices and power off.
     */
    if(S_PASS == retVal)
    {
        pBoardData = BOARDGetData();
        /* Traverse board devices. */
        for(i = 0U; i < pBoardData->numDev; i++)
        {
            devIdx = pBoardData->pDevData[i].devId;
            devInstNum = pBoardData->pDevData[i].devInstNum;
            moduleIdx = pBoardData->pDevData[i].ctrlModId;
            moduleInst = pBoardData->pDevData[i].ctrlModInstNum;
            resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            /* Check if control module of device is enabled. */
            if(TRUE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
            {
                devInterfIdx = pBoardData->pDevData[i].dataModId;
                devInterfInst = pBoardData->pDevData[i].dataModInstNum;
                devInterfResId = CHIPDB_GET_RESOURCEID(devInterfIdx, devInterfInst);
                if((CHIPDB_MOD_ID_INVALID == pBoardData->pDevData[i].dataModId) ||
                    (TRUE == pSuspendCfg->pInitObj->pModulesCfg[devInterfResId].cfgPmEnable))
                {
                    /* Mark the device as active. */
                    devActiveMask[devIdx] |= (1U << devInstNum);

                    /* Mark the instance of device to power off. */
                }
            }
            /* Check if control module of device is enabled. */
            if((0U != (devActiveMask[devIdx] & (1U << devInstNum)))
                && (0U != (devSkipMask[devIdx] & (1U << devInstNum))))
            {
                if(pSuspendCfg->pInitObj->maxModules > resId)
                {
                    /* Mark the control module of device as skipped. */
                    pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;

                    /* Save context of control module of device. */
                }

                if(pSuspendCfg->pInitObj->maxModules > devInterfResId)
                {
                    /* Mark the interface module of device as skipped. */
                    pSuspendCfg->pInitObj->pModulesCfg[devInterfResId].cfgPmEnable = FALSE;

                    /* Save context of interface module of device. */
                }
            }
            else if(0U != (devActiveMask[devIdx] & (1U << devInstNum)))
            {
                if(NULL != pBoardData->pDevData[i].pFnPowerOnDev)
                {
                    BOARDPowerOnDevice(devIdx, devInstNum, FALSE);
                }
            }
            else
            {
                /* Do nothing */
            }
        }
    }

    /* Clear Wakeup Gen configuration. */
    PmAppClearWkpGenCfg();

    /* Save the Control register and Utils context. */
    PMAppSavePeripheralCntxt(slpMode, CHIPDB_MOD_ID_RTC);

    /* Save the Utils Context. */
    PmAppSaveUtilsCntxt();

    /*
     * Halt system.
     */
    if(S_PASS == retVal)
    {
        /* Save and halt EDMA context. */

        /* Save and disable interrupt context. */
    }

    /*
     * Skip wake source.
     */
    if(S_PASS == retVal)
    {
        /* Traverse wake sources list. */
        for(i = 0U; i < pSuspendCfg->maxWakeSrc; i++)
        {
            moduleIdx = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleId;
            moduleInst = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Mark the module configured for wake source as skipped. */
                pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;
            }
        }
    }

    /*
     * Skip system modules.
     */
    if(S_PASS == retVal)
    {
        /* Traverse system modules list. */
        for(i = 0U; i < pSuspendCfg->maxSysModules; i++)
        {
            moduleIdx = pSuspendCfg->pSysModulesList[i].moduleId;
            moduleInst = pSuspendCfg->pSysModulesList[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Mark the system module as skipped. */
                pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;
            }
        }
    }

    /*
     * Suspend modules of power domains.
     */
    if(S_PASS == retVal)
    {
        /* Travers power domains list. */
        for(i = 0U; i < pSuspendCfg->pInitObj->maxPwrModes; i++)
        {
            /* Travers power domains list. */
            for(j = 0U; j < pSuspendCfg->pInitObj->pPwrModeCfg[i].maxPwrDomains; j++)
            {
                pwrDomain = pSuspendCfg->pInitObj->pPwrModeCfg[i].pPwrDomainCfg[j].pwrDomain;
                /* Travers clock domain list. */
                for(k = 0U; k < (PRCM_CD_MAX - 1); k++)
                {
                    /* Check if clock domain is in this power domain. */
                    if(pwrDomain == prcmClockDomainElems[k].powerDomainId)
                    {
                        /* Travers modules list. */
                        for(l = 0U; l < prcmClockDomainElems[k].numModulesInCd; l++)
                        {
                            pFirstModPtr = prcmClockDomainElems[k].pFirstModPtr;
                            prcmResId = pFirstModPtr[l] - PRCM_NODE_MAX;
                            moduleIdx = resourceIdModuleIdInstMap[prcmResId].moduleId;
                            moduleInst = resourceIdModuleIdInstMap[prcmResId].instNum;

                            if(CHIPDB_MOD_ID_COUNT > moduleIdx)
                            {
                                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
                                /* Check if module is not skipped. */
                                if(TRUE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                                {
                                    /* Save context. */

                                    /* Halt module. */

                                    /* Disable module. */
                                    PRCMModuleDisable(moduleIdx, moduleInst, FALSE);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    /*
     * Configure wake sources.
     */
    if(S_PASS == retVal)
    {
        /* Traverse wake sources list. */
        for(i = 0U; i < pSuspendCfg->maxWakeSrc; i++)
        {
            moduleIdx = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleId;
            moduleInst = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Check if wake source configuration is not skipped. */
                if(FALSE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                {
                    /* Save context. */

                    /* Configure for wake. */

                    /* This change needs to be validated. */
                    PRCMModuleDisable(moduleIdx, moduleInst, FALSE);
                }
            }
        }
    }

    /*
     * Configure OPP for suspend.
     */
    if(S_PASS == retVal)
    {
        /* Save current OPP. */

        /* Configure minimum OPP. */
        PMAppMinOppConfig();
    }

    /*
     * Disable interrupt.
     */
    if(S_PASS == retVal)
    {
        INTCDisableCpuIntr();
    }

    /*
     * Suspend system modules.
     */
    if(S_PASS == retVal)
    {
        /* Traverse system modules list. */
        for(i = 0U; i < pSuspendCfg->maxSysModules; i++)
        {
            moduleIdx = pSuspendCfg->pSysModulesList[i].moduleId;
            moduleInst = pSuspendCfg->pSysModulesList[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Check if wake source configuration is not skipped. */
                if(TRUE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                {
                    /* Save context. */

                    /* Halt module. */

                    /* Disable module. */
                    PRCMModuleDisable(moduleIdx, moduleInst, FALSE);
                }
            }
        }

        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKDCOLDO_DPLL_PER,
            PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL,
            PRCM_CM_CLKDCOLDO_DPLL_PER_GATE_CTRL_CLK_AUTOGATE);

        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_PER,
            PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL,
            PRCM_CM_DIV_M2_DPLL_PER_CLKOUT_GATE_CTRL_CLK_AUTOGATE);

        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_DISP,
            PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL,
            PRCM_CM_DIV_M2_DPLL_DISP_CLKOUT_GATE_CTRL_CLK_AUTOGATE);

        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_DIV_M2_DPLL_EXTDEV,
            PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL,
            PRCM_CM_DIV_M2_DPLL_EXTDEV_CLKOUT_GATE_CTRL_CLK_AUTOGATE);
    }

    /*
     * Perform sleep/wake.
     */
    if(S_PASS == retVal)
    {
        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_UART0_CLKCTRL,
            PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE,
            PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_DISABLED);

        /* A8 & CM3 sleep/wake. */
        slpMode = 0x1U;
        memType = 0x3U;
        deviceVersion = 0U;
        saveRestoreContext(slpMode, memType, deviceVersion);
    }

    /*
     * Resume system modules.
     */
    if(S_PASS == retVal)
    {
        HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_UART0_CLKCTRL,
            PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE,
            PRCM_CM_WKUP_UART0_CLKCTRL_MODULEMODE_ENABLE);

        /* Restore the Utils Context. */
        PmAppRestoreUtilsCntxt();

        /* Traverse system modules list. */
        for(i = 0U; i < pSuspendCfg->maxSysModules; i++)
        {
            moduleIdx = pSuspendCfg->pSysModulesList[i].moduleId;
            moduleInst = pSuspendCfg->pSysModulesList[i].moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Check if wake source configuration is not skipped. */
                if(TRUE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                {
                    /* Enable module. */
                    PRCMModuleEnable(moduleIdx, moduleInst, FALSE);

                    /* Resume module. */

                    /* Restore context. */
                }
            }
        }
    }

    /*
     * Enable interrupt.
     */
    if(S_PASS == retVal)
    {
        INTCEnableCpuIntr(INTC_ARM_IRQ_MASK);
    }

    /*
     * Restore OPP configuration.
     */
    if(S_PASS == retVal)
    {
        /* Restore OPP. */
        PMAppOppConfig(PM_APP_OPP_100);
    }

    /*
     * Disable wake sources.
     */
    if(S_PASS == retVal)
    {
        /* Traverse wake sources list. */
        for(i = 0U; i < pSuspendCfg->maxWakeSrc; i++)
        {
            moduleIdx = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleId;
            moduleInst = pSuspendCfg->pWakeSrcList[i].wakeSrc.moduleInst;

            if(moduleInst < CHIPDBModuleMaxInstanceNumber(moduleIdx))
            {
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
            }

            if(pSuspendCfg->pInitObj->maxModules > resId)
            {
                /* Check if wake source configuration is not skipped. */
                if(FALSE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                {

                    /* Disable wake configuration. */
                    PRCMModuleEnable(moduleIdx, moduleInst, FALSE);

                    /* Restore context. */
                    pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = TRUE;
                }
            }
        }
    }

    /*
     * Resume modules of power domains.
     */
    if(S_PASS == retVal)
    {
        /* Travers power domains list. */
        for(i = 0U; i < pSuspendCfg->pInitObj->maxPwrModes; i++)
        {
            /* Travers power domains list. */
            for(j = 0U; j < pSuspendCfg->pInitObj->pPwrModeCfg[i].maxPwrDomains; j++)
            {
                pwrDomain = pSuspendCfg->pInitObj->pPwrModeCfg[i].pPwrDomainCfg[j].pwrDomain;

                /* Travers clock domain list. */
                for(k = 0U; k < (PRCM_CD_MAX - 1); k++)
                {
                    /* Check if clock domain is in this power domain. */
                    if(pwrDomain == prcmClockDomainElems[k].powerDomainId)
                    {
                        /* Travers modules list. */
                        for(l = 0U; l < prcmClockDomainElems[k].numModulesInCd; l++)
                        {
                            if(NULL != prcmClockDomainElems[k].pFirstModPtr)
                            {
                                pFirstModPtr = prcmClockDomainElems[k].pFirstModPtr;
                                prcmResId = pFirstModPtr[l] - PRCM_NODE_MAX;
                                moduleIdx = resourceIdModuleIdInstMap[prcmResId].moduleId;
                                moduleInst = resourceIdModuleIdInstMap[prcmResId].instNum;

                                if(CHIPDB_MOD_ID_INVALID != moduleIdx)
                                {
                                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
                                /* Check if module is not skipped. */
                                if(TRUE == pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable)
                                {
                                    /* Enable module. */
                                    PRCMModuleEnable(moduleIdx, moduleInst, FALSE);

                                    /* Resume module. */

                                    /* Restore context. */
                                }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    /*
     * Resume system.
     */

    /* Restore the Control register Peripheral Context. */
    PMAppRestorePeripheralCntxt(slpMode, CHIPDB_MOD_ID_RTC);

    if(S_PASS == retVal)
    {
        /* Restore EDMA transfers. */

        /* Restore interrupts. */
    }

    /*
     * Check for active devices and power on.
     */
    if(S_PASS == retVal)
    {
        pBoardData = BOARDGetData();
        /* Traverse board devices. */
        for(i = 0U; i < pBoardData->numDev; i++)
        {
            devIdx = pBoardData->pDevData[i].devId;
            devInstNum = pBoardData->pDevData[i].devInstNum;
            /* Check if control module of device is enabled. */
            if((0U != (devActiveMask[devIdx] & (1U << devInstNum)))
                && (0U != (devSkipMask[devIdx] & (1U << devInstNum))))
            {
                devActiveMask[devIdx] &= ~(1U << devInstNum);
                devSkipMask[devIdx] &= ~(1U << devInstNum);

                moduleIdx = pBoardData->pDevData[i].ctrlModId;
                moduleInst = pBoardData->pDevData[i].ctrlModInstNum;
                resId = CHIPDB_GET_RESOURCEID(moduleIdx, moduleInst);
                if(pSuspendCfg->pInitObj->maxModules > resId)
                {
                    /* Mark the control module of device as skipped. */
                    pSuspendCfg->pInitObj->pModulesCfg[resId].cfgPmEnable = FALSE;
                    /* Restore context of control module of device. */
                }

                devInterfIdx = pBoardData->pDevData[i].dataModId;
                devInterfInst = pBoardData->pDevData[i].dataModInstNum;
                devInterfResId = CHIPDB_GET_RESOURCEID(devInterfIdx, devInterfInst);
                if(pSuspendCfg->pInitObj->maxModules > devInterfResId)
                {
                    /* Mark the interface module of device as skipped. */
                    pSuspendCfg->pInitObj->pModulesCfg[devInterfResId].cfgPmEnable = FALSE;
                    /* Restore context of interface module of device. */
                }
            }
            else if(0U != (devActiveMask[devIdx] & (1U << devInstNum)))
            {
                if(NULL != pBoardData->pDevData[i].pFnPowerOnDev)
                {
                    devActiveMask[devIdx] &= ~(1U << devInstNum);
                    BOARDPowerOnDevice(devIdx, devInstNum, TRUE);
                }
            }
            else
            {
                /* Do nothing */
            }
        }
    }

    /*
     * Refresh skip list of active modules.
     */
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void PmAppClearWkpGenCfg()
{
    /* Clear the Wakegen configuration. */
    HW_WR_REG32(0x48281010, 0U);
    HW_WR_REG32(0x48281014, 0U);
    HW_WR_REG32(0x48281018, 0U);
    HW_WR_REG32(0x4828101C, 0U);
    HW_WR_REG32(0x48281020, 0U);
    HW_WR_REG32(0x48281024, 0U);
    HW_WR_REG32(0x48281028, 0U);
}

void PmAppConfigIdleMode()
{
    /* TPTC0 */
    HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC0_CLKCTRL,
        PRCM_CM_PER_TPTC0_CLKCTRL_MODULEMODE,
        PRCM_CM_PER_TPTC0_CLKCTRL_MODULEMODE_ENABLE);

    while((PRCM_CM_PER_TPTC0_CLKCTRL_IDLEST_MASK |
        PRCM_CM_PER_TPTC0_CLKCTRL_STBYST_MASK) &
            HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC0_CLKCTRL));

        HW_WR_REG32(SOC_EDMA3TC0_REG + EDMA3TC_SYSCONFIG, 0x08);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC0_CLKCTRL,
            PRCM_CM_PER_TPTC0_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_TPTC0_CLKCTRL_MODULEMODE_DISABLED);

        /* TPTC1 */
        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC1_CLKCTRL,
            PRCM_CM_PER_TPTC1_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_TPTC1_CLKCTRL_MODULEMODE_ENABLE);

        while((PRCM_CM_PER_TPTC1_CLKCTRL_IDLEST_MASK |
            PRCM_CM_PER_TPTC1_CLKCTRL_STBYST_MASK) &
            HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC1_CLKCTRL));

        HW_WR_REG32(SOC_EDMA3TC1_REG + EDMA3TC_SYSCONFIG, 0x08U);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC1_CLKCTRL,
            PRCM_CM_PER_TPTC1_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_TPTC1_CLKCTRL_MODULEMODE_DISABLED);

        /* TPTC2 */
        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC2_CLKCTRL,
            PRCM_CM_PER_TPTC2_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_TPTC2_CLKCTRL_MODULEMODE_ENABLE);

        while((PRCM_CM_PER_TPTC2_CLKCTRL_IDLEST_MASK |
            PRCM_CM_PER_TPTC2_CLKCTRL_STBYST_MASK) &
            HW_RD_REG32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC2_CLKCTRL));

        HW_WR_REG32(SOC_EDMA3TC2_REG + EDMA3TC_SYSCONFIG, 0x08U);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_TPTC2_CLKCTRL,
            PRCM_CM_PER_TPTC2_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_TPTC2_CLKCTRL_MODULEMODE_DISABLED);

        /* GPMC */
        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_ELM_CLKCTRL,
            PRCM_CM_PER_ELM_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_ELM_CLKCTRL_MODULEMODE_DISABLED);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_GPMC_CLKCTRL,
            PRCM_CM_PER_GPMC_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_GPMC_CLKCTRL_MODULEMODE_ENABLE);

        while(PRCM_CM_PER_GPMC_CLKCTRL_IDLEST_FUNC !=
            HW_RD_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_GPMC_CLKCTRL,
            PRCM_CM_PER_GPMC_CLKCTRL_IDLEST));

        GPMCModuleSoftReset(SOC_GPMC_CONFIG_REG);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_GPMC_CLKCTRL,
            PRCM_CM_PER_GPMC_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_GPMC_CLKCTRL_MODULEMODE_DISABLED);

        HSMMCSDSoftReset(SOC_MMCSD0_REG);

        HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_MMC0_CLKCTRL,
            PRCM_CM_PER_MMC0_CLKCTRL_MODULEMODE,
            PRCM_CM_PER_MMC0_CLKCTRL_MODULEMODE_DISABLED);
}
