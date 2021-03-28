/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
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

 /** \file am65xx_evm_clock.c
  *
  *  \brief This file contains initialization of wakeup and main PSC
  *  configuration structures and function definitions to get the number
  *  of wakeup and main PSC config exists.
  */

/**
 * \brief wkup PSC configuration parameters
 *
 *  This structure provides the device-level view with module association to
 *  the clock, power, and voltage domains.
 * 
 *  The PSC provides the user with an interface to control several important
 *  power and clock operations. The device has two PSC - WKUP_PSC0 and PSC0
 *  in WKUPSS and MAIN SoC, respectively.
 * 
 *  PSC: The Power Sleep Controller is the device has several power domains
 *  that can be turned ON for operation or OFF to minimize power dissipation,
 *  which includes a Global Power Sleep Controller(GPSC) and Local Power 
 *  Sleep Controller(LPSC).
 * 
 *  GPSC: Global Power Sleep Controller, is used to control the power gating
 *  of various power domains.
 * 
 *  LPSC: Local Power Sleep Controller, manages the clock gating for to each 
 *  logic block. For modules with a dedicated clock or multiple clocks, the 
 *  LPSC communicates with the PLL controller to enable and disable that
 *  module's clock(s) at the source. For modules that share a clock with
 *  other modules, the LPSC controls the clock gating logic for each module.    
 */

#include "board_clock.h"
#include <ti/drv/sciclient/sciclient.h>

#ifdef DISABLE_SCI_CLK_CONFIG
const pscConfig wkupPscConfigs[] =
{
    {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_WKUP_COMMON},
    /* {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_DMSC}, */
    {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_WKUP2MCU},
    {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_WKUP2MAIN_INFRA},
    {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_DEBUG2DMSC},
    {CSL_PSC_PD_WKUP,                CSL_PSC_LPSC_WKUP_GPIO},    
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU2MAIN_INFRA},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU2MAIN},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU2WKUP},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MAIN2MCU},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_COMMON},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_TEST},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_MCAN_0},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_MCAN_1},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_OSPI_0},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_OSPI_1},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_HYPERBUS},
    {CSL_PSC_PD_MCU,                 CSL_PSC_LPSC_MCU_DEBUG}
    /* {CSL_PSC_PD_MCU_PULSAR,          CSL_PSC_LPSC_MCU_R5_0}, */
    /* {CSL_PSC_PD_MCU_PULSAR,          CSL_PSC_LPSC_MCU_R5_1} */
};

/**
 * \brief main PSC configuration parameters
 *
 *  This structure provides the device-level view with module association to
 *  the clock, power, and voltage domains.
 * 
 *  The PSC provides the user with an interface to control several important
 *  power and clock operations. The device has two PSC - WKUP_PSC0 and PSC0
 *  in WKUPSS and MAIN SoC, respectively.
 * 
 *  PSC: The Power Sleep Controller is the device has several power domains
 *  that can be turned ON for operation or OFF to minimize power dissipation,
 *  which includes a Global Power Sleep Controller(GPSC) and Local Power 
 *  Sleep Controller(LPSC).
 * 
 *  GPSC: Global Power Sleep Controller, is used to control the power gating
 *  of various power domains.
 * 
 *  LPSC: Local Power Sleep Controller, manages the clock gating for to each 
 *  logic block. For modules with a dedicated clock or multiple clocks, the 
 *  LPSC communicates with the PLL controller to enable and disable that
 *  module's clock(s) at the source. For modules that share a clock with
 *  other modules, the LPSC controls the clock gating logic for each module.    
 */
const pscConfig mainPscConfigs[] =
{
    {CSL_PSC_GP_CORE_CTL,            CSL_PSC_LPSC_MAIN_INFRA},
    {CSL_PSC_GP_CORE_CTL,            CSL_PSC_LPSC_MAIN_TEST},
    /* {CSL_PSC_GP_CORE_CTL,            CSL_PSC_LPSC_MAIN_PBIST},     */
    {CSL_PSC_PD_CC_TOP,              CSL_PSC_LPSC_CC_TOP},
    /* {CSL_PSC_PD_CC_TOP,              CSL_PSC_LPSC_CC_TOP_PBIST}, */
    {CSL_PSC_PD_A53_CLUSTER_0,       CSL_PSC_LPSC_A53_CLUSTER_0},
    /* {CSL_PSC_PD_A53_0,               CSL_PSC_LPSC_A53_0}, */
    /* {CSL_PSC_PD_A53_1,               CSL_PSC_LPSC_A53_1}, */
    {CSL_PSC_PD_A53_CLUSTER_1,       CSL_PSC_LPSC_A53_CLUSTER_1},
    /* {CSL_PSC_PD_A53_2,               CSL_PSC_LPSC_A53_2}, */
    /* {CSL_PSC_PD_A53_3,               CSL_PSC_LPSC_A53_3}, */
    /* {CSL_PSC_PD_A53_CLUSTER_0,       CSL_PSC_LPSC_A53_CLUSTER_0_PBIST}, */
    /* {CSL_PSC_PD_A53_CLUSTER_1,       CSL_PSC_LPSC_A53_CLUSTER_1_PBIST}, */
    {CSL_PSC_PD_DEBUG,               CSL_PSC_LPSC_MAIN_DEBUG},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_DSS},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_MMC},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_CAL},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_PCIE_0},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_PCIE_1},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_USB_0},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_USB_1},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_SAUL},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_PER_COMMON},
    {CSL_PSC_PD_PER,                 CSL_PSC_LPSC_NB},
    {CSL_PSC_PD_SERDES,              CSL_PSC_LPSC_SERDES_0},
    {CSL_PSC_PD_SERDES,              CSL_PSC_LPSC_SERDES_1},
    {CSL_PSC_PD_ICSSG,               CSL_PSC_LPSC_ICSSG_0},
    {CSL_PSC_PD_ICSSG,               CSL_PSC_LPSC_ICSSG_1},
    {CSL_PSC_PD_ICSSG,               CSL_PSC_LPSC_ICSSG_2},
    {CSL_PSC_PD_GPU,                 CSL_PSC_LPSC_GPU},
    /* {CSL_PSC_PD_GPU,                 CSL_PSC_LPSC_GPU_PBIST}, */
    {CSL_PSC_PD_EMIF,                CSL_PSC_LPSC_EMIF_DATA},
    {CSL_PSC_PD_EMIF,                CSL_PSC_LPSC_EMIF_CFG}
};

/**
 *  \brief    This function is used to get the number of \
 *            wkup PSC configs exists.
 *
 * \return
 * \n         uint32_t - Number of wkup PSC configs.
 */
uint32_t Board_getNumWkupPscCconfigs(void)
{
    return (sizeof(wkupPscConfigs) / sizeof(pscConfig));
}

/**
 *  \brief    This function is used to get the number of \
 *            main PSC configs exists.
 *
 * \return
 * \n         uint32_t - Number of main PSC configs.
 */
uint32_t Board_getNumMainPscCconfigs(void)
{
    return (sizeof(mainPscConfigs) / sizeof(pscConfig));
}

#else /* #ifdef DISABLE_SCI_CLK_CONFIG */
uint32_t gBoardClkModuleID[] = {
    TISCI_DEV_MCU_ADC0,
    TISCI_DEV_MCU_ADC1,
    TISCI_DEV_CAL0,
    TISCI_DEV_CMPEVENT_INTRTR0,
    TISCI_DEV_MCU_CPSW0,
    TISCI_DEV_CPT2_AGGR0,
    TISCI_DEV_MCU_CPT2_AGGR0,
    TISCI_DEV_STM0,
    TISCI_DEV_DCC0,
    TISCI_DEV_DCC1,
    TISCI_DEV_DCC2,
    TISCI_DEV_DCC3,
    TISCI_DEV_DCC4,
    TISCI_DEV_DCC5,
    TISCI_DEV_DCC6,
    TISCI_DEV_DCC7,
    TISCI_DEV_MCU_DCC0,
    TISCI_DEV_MCU_DCC1,
    TISCI_DEV_MCU_DCC2,
    TISCI_DEV_DDRSS0,
    TISCI_DEV_DEBUGSS_WRAP0,
    TISCI_DEV_WKUP_DMSC0,
    TISCI_DEV_TIMER0,
    TISCI_DEV_TIMER1,
    TISCI_DEV_TIMER10,
    TISCI_DEV_TIMER11,
    TISCI_DEV_TIMER2,
    TISCI_DEV_TIMER3,
    TISCI_DEV_TIMER4,
    TISCI_DEV_TIMER5,
    TISCI_DEV_TIMER6,
    TISCI_DEV_TIMER7,
    TISCI_DEV_TIMER8,
    TISCI_DEV_TIMER9,
    TISCI_DEV_MCU_TIMER0,
    TISCI_DEV_MCU_TIMER1,
    TISCI_DEV_MCU_TIMER2,
    TISCI_DEV_MCU_TIMER3,
    TISCI_DEV_ECAP0,
    TISCI_DEV_EHRPWM0,
    TISCI_DEV_EHRPWM1,
    TISCI_DEV_EHRPWM2,
    TISCI_DEV_EHRPWM3,
    TISCI_DEV_EHRPWM4,
    TISCI_DEV_EHRPWM5,
    TISCI_DEV_ELM0,
    TISCI_DEV_MMCSD0,
    TISCI_DEV_MMCSD1,
    TISCI_DEV_EQEP0,
    TISCI_DEV_EQEP1,
    TISCI_DEV_EQEP2,
    TISCI_DEV_ESM0,
    TISCI_DEV_MCU_ESM0,
    TISCI_DEV_WKUP_ESM0,
    TISCI_DEV_MCU_FSS0_FSAS_0,
    TISCI_DEV_MCU_FSS0_HYPERBUS0,
    TISCI_DEV_MCU_FSS0_OSPI_0,
    TISCI_DEV_MCU_FSS0_OSPI_1,
    TISCI_DEV_GIC0,
    TISCI_DEV_GPIO0,
    TISCI_DEV_GPIO1,
    TISCI_DEV_WKUP_GPIO0,
    TISCI_DEV_GPMC0,
    TISCI_DEV_GTC0,
    TISCI_DEV_PRU_ICSSG0,
    TISCI_DEV_PRU_ICSSG1,
    TISCI_DEV_PRU_ICSSG2,
    TISCI_DEV_GPU0,
    TISCI_DEV_CCDEBUGSS0,
    TISCI_DEV_DSS0,
    TISCI_DEV_DEBUGSS0,
    TISCI_DEV_EFUSE0,
    TISCI_DEV_PSC0,
    TISCI_DEV_MCU_DEBUGSS0,
    TISCI_DEV_MCU_EFUSE0,
    TISCI_DEV_PBIST0,
    TISCI_DEV_PBIST1,
    TISCI_DEV_MCU_PBIST0,
    TISCI_DEV_PLLCTRL0,
    TISCI_DEV_WKUP_PLLCTRL0,
    TISCI_DEV_MCU_ROM0,
    TISCI_DEV_WKUP_PSC0,
    TISCI_DEV_WKUP_VTM0,
    TISCI_DEV_DEBUGSUSPENDRTR0,
    TISCI_DEV_CBASS0,
    TISCI_DEV_CBASS_DEBUG0,
    TISCI_DEV_CBASS_FW0,
    TISCI_DEV_CBASS_INFRA0,
    TISCI_DEV_ECC_AGGR0,
    TISCI_DEV_ECC_AGGR1,
    TISCI_DEV_ECC_AGGR2,
    TISCI_DEV_MCU_CBASS0,
    TISCI_DEV_MCU_CBASS_DEBUG0,
    TISCI_DEV_MCU_CBASS_FW0,
    TISCI_DEV_MCU_ECC_AGGR0,
    TISCI_DEV_MCU_ECC_AGGR1,
    TISCI_DEV_WKUP_CBASS0,
    TISCI_DEV_WKUP_ECC_AGGR0,
    TISCI_DEV_WKUP_CBASS_FW0,
    TISCI_DEV_MAIN2MCU_LVL_INTRTR0,
    TISCI_DEV_MAIN2MCU_PLS_INTRTR0,
    TISCI_DEV_CTRL_MMR0,
    TISCI_DEV_GPIOMUX_INTRTR0,
    TISCI_DEV_PLL_MMR0,
    TISCI_DEV_MCU_MCAN0,
    TISCI_DEV_MCU_MCAN1,
    TISCI_DEV_MCASP0,
    TISCI_DEV_MCASP1,
    TISCI_DEV_MCASP2,
    TISCI_DEV_MCU_CTRL_MMR0,
    TISCI_DEV_MCU_PLL_MMR0,
    TISCI_DEV_MCU_SEC_MMR0,
    TISCI_DEV_I2C0,
    TISCI_DEV_I2C1,
    TISCI_DEV_I2C2,
    TISCI_DEV_I2C3,
    TISCI_DEV_MCU_I2C0,
    TISCI_DEV_WKUP_I2C0,
    TISCI_DEV_MCU_MSRAM0,
    TISCI_DEV_DFTSS0,
    TISCI_DEV_NAVSS0,
    TISCI_DEV_MCU_NAVSS0,
    TISCI_DEV_PCIE0,
    TISCI_DEV_PCIE1,
    TISCI_DEV_PDMA_DEBUG0,
    TISCI_DEV_PDMA0,
    TISCI_DEV_PDMA1,
    TISCI_DEV_MCU_PDMA0,
    TISCI_DEV_MCU_PDMA1,
    TISCI_DEV_MCU_PSRAM0,
    TISCI_DEV_PSRAMECC0,
    TISCI_DEV_SA2_UL0,
    TISCI_DEV_MCSPI0,
    TISCI_DEV_MCSPI1,
    TISCI_DEV_MCSPI2,
    TISCI_DEV_MCSPI3,
    TISCI_DEV_MCSPI4,
    TISCI_DEV_MCU_MCSPI0,
    TISCI_DEV_MCU_MCSPI1,
    TISCI_DEV_MCU_MCSPI2,
    TISCI_DEV_TIMESYNC_INTRTR0,
    TISCI_DEV_UART1,
    TISCI_DEV_UART2,
    TISCI_DEV_USB3SS0,
    TISCI_DEV_USB3SS1,
    TISCI_DEV_SERDES0,
    TISCI_DEV_SERDES1,
    TISCI_DEV_NAVSS0_CPTS0,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER0,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER1,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER2,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER3,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER4,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER5,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER6,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER7,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER8,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER9,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER10,
    TISCI_DEV_NAVSS0_MAILBOX0_CLUSTER11,
    TISCI_DEV_NAVSS0_MCRC0,
    TISCI_DEV_NAVSS0_PVU0,
    TISCI_DEV_NAVSS0_PVU1,
    TISCI_DEV_NAVSS0_UDMASS_INTA0,
    TISCI_DEV_NAVSS0_MODSS_INTA0,
    TISCI_DEV_NAVSS0_MODSS_INTA1,
    TISCI_DEV_NAVSS0_INTR_ROUTER_0,
    TISCI_DEV_NAVSS0_TIMER_MGR0,
    TISCI_DEV_NAVSS0_TIMER_MGR1,
    TISCI_DEV_NAVSS0_PROXY0,
    TISCI_DEV_NAVSS0_RINGACC0,
    TISCI_DEV_NAVSS0_UDMAP0,
    TISCI_DEV_MCU_NAVSS0_INTR_AGGR_0,
    TISCI_DEV_MCU_NAVSS0_INTR_ROUTER_0,
    TISCI_DEV_MCU_NAVSS0_PROXY0,
    TISCI_DEV_MCU_NAVSS0_MCRC0,
    TISCI_DEV_MCU_NAVSS0_UDMAP0,
    TISCI_DEV_MCU_NAVSS0_RINGACC0,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMLO_4,
    TISCI_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S1_3,
    TISCI_DEV_CPT2_PROBE_VBUSM_MCU_EXPORT_SLV_0,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMHI_3,
    TISCI_DEV_CPT2_PROBE_VBUSM_MCU_SRAM_SLV_1,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRHI_5,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRLO_6,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_CAL0_0,
    TISCI_DEV_CPT2_PROBE_VBUSM_MAIN_DSS_2,
    TISCI_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S0_2,
    TISCI_DEV_OLDI_TX_CORE_MAIN_0,
    TISCI_DEV_K3_ARM_ATB_FUNNEL_3_32_MCU_0,
    TISCI_DEV_ICEMELTER_WKUP_0,
    TISCI_DEV_K3_LED_MAIN_0,
    TISCI_DEV_VDC_DATA_VBUSM_32B_REF_WKUP2MCU,
    TISCI_DEV_VDC_DATA_VBUSM_32B_REF_MCU2WKUP,
    TISCI_DEV_VDC_DATA_VBUSM_64B_REF_MAIN2MCU,
    TISCI_DEV_VDC_DATA_VBUSM_64B_REF_MCU2MAIN,
    TISCI_DEV_VDC_DMSC_DBG_VBUSP_32B_REF_DBG2DMSC,
    TISCI_DEV_VDC_INFRA_VBUSP_32B_REF_WKUP2MAIN_INFRA,
    TISCI_DEV_VDC_INFRA_VBUSP_32B_REF_MCU2MAIN_INFRA,
    TISCI_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWWKUP2MCU,
    TISCI_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWMCU2MAIN,
    TISCI_DEV_VDC_MCU_DBG_VBUSP_32B_REF_DBGMAIN2MCU,
    TISCI_DEV_VDC_NAV_PSIL_128B_REF_MAIN2MCU,
    TISCI_DEV_GS80PRG_SOC_WRAP_WKUP_0,
    TISCI_DEV_GS80PRG_MCU_WRAP_WKUP_0,
    TISCI_DEV_MX_WAKEUP_RESET_SYNC_WKUP_0,
    TISCI_DEV_MX_EFUSE_MAIN_CHAIN_MAIN_0,
    TISCI_DEV_MX_EFUSE_MCU_CHAIN_MCU_0,
    TISCI_DEV_DUMMY_IP_LPSC_WKUP2MCU_VD,
    TISCI_DEV_DUMMY_IP_LPSC_WKUP2MAIN_INFRA_VD,
    TISCI_DEV_DUMMY_IP_LPSC_DEBUG2DMSC_VD,
    TISCI_DEV_DUMMY_IP_LPSC_DMSC_VD,
    TISCI_DEV_DUMMY_IP_LPSC_MCU2MAIN_INFRA_VD,
    TISCI_DEV_DUMMY_IP_LPSC_MCU2MAIN_VD,
    TISCI_DEV_DUMMY_IP_LPSC_MCU2WKUP_VD,
    TISCI_DEV_DUMMY_IP_LPSC_MAIN2MCU_VD,
    TISCI_DEV_DUMMY_IP_LPSC_EMIF_DATA_VD,
    TISCI_DEV_MCU_ARMSS0_CPU1
};

/**
 *  \brief    Returns number of module clocks
 *
 * \return
 * \n         uint32_t - number of module clocks
 */
uint32_t Board_getNumClkConfigs(void)
{
    return (sizeof (gBoardClkModuleID)/sizeof(uint32_t));
}

#endif /* #ifdef DISABLE_SCI_CLK_CONFIG */

