/*  ============================================================================
 *  Copyright (c) Texas Instruments Incorporated 2002-2018
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

#ifndef SHANNON_Atrenta_DSP1_H
#define SHANNON_Atrenta_DSP1_H

#define C6678_Atrenta_DSP1_H
#define TCI6608_Atrenta_DSP1_H

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Header files are included as per RTSC guidelines
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************
* Memory Region Descriptions for the device
**************************************************************************/
/**************************************************************************
* Peripheral Instance counts
**************************************************************************/

#define CSL_INTERNAL_RAM_PER_CNT          1
#define CSL_CGEM_0_5_LOCAL_REGISTERS_PER_CNT 1
#define CSL_CP_TRACER_PER_CNT             17
#define CSL_EMIF_16_PER_CNT                  1
#define CSL_PA_SS_PER_CNT                 1
#define CSL_TIMER_PER_CNT                 16
#define CSL_PLL_CONTROLLER_PER_CNT        1
#define CSL_GPIO_PER_CNT                  (1U)
#define CSL_SMARTREFLEX_PER_CNT           1
#define CSL_PSC_PER_CNT                   1
#define CSL_MPU_PER_CNT                   4
#define CSL_DEBUG_SS_PER_CNT              1
#define CSL_GEM_DEBUG_PER_CNT             1
#define CSL_SEC_CTL_PER_CNT               1
#define CSL_SEC_KEY_MGR_PER_CNT           1
#define CSL_I2C_PER_CNT                   (1U)
#define CSL_CP_INTC_PER_CNT               4
#define CSL_BOOT_CFG_PER_CNT              1
#define CSL_SEMAPHORE_PER_CNT             1
#define CSL_UART_PER_CNT                  (1U)
#define CSL_TPCC_PER_CNT                  3
#define CSL_EDMA3CC_PER_CNT               3
#define CSL_TPTC_PER_CNT                  10
#define CSL_EDMA3TC_PER_CNT               10
#define CSL_SRIO_PER_CNT                  1
#define CSL_QM_SS_PER_CNT                 1
#define CSL_MSMC_PER_CNT                  1
#define CSL_DSP0_GLOBAL_PER_CNT           1
#define CSL_DSP1_GLOBAL_PER_CNT           1
#define CSL_DSP2_GLOBAL_PER_CNT           1
#define CSL_DSP3_GLOBAL_PER_CNT           1
#define CSL_BOOT_PER_CNT                  1
#define CSL_SPI_PER_CNT                   (1U)
#define CSL_TSIP_PER_CNT                   2
#define CSL_DDR3EMIF_PER_CNT              1
#define CSL_MCM_PER_CNT                   1
#define CSL_PCIE_PER_CNT                  1

/**************************************************************************\
* Peripheral Instance definitions.
\**************************************************************************/

/** @brief Instance number of internal RAM */
#define CSL_INTERNAL_RAM                      (0) 

/** @brief Instance number of CGEM_0_5_LOCAL_REGISTERS */
#define CSL_CGEM_0_5_LOCAL_REGISTERS                      (0)

/** @brief Peripheral Instance numbers of CP_TRACER */
#define CSL_CP_TRACER_0                           (0) 
#define CSL_CP_TRACER_1                           (1) 
#define CSL_CP_TRACER_2                           (2) 
#define CSL_CP_TRACER_3                           (3) 
#define CSL_CP_TRACER_4                           (4) 
#define CSL_CP_TRACER_5                           (5) 
#define CSL_CP_TRACER_6                           (6) 
#define CSL_CP_TRACER_7                           (7) 
#define CSL_CP_TRACER_8                           (8) 
#define CSL_CP_TRACER_9                           (9) 
#define CSL_CP_TRACER_10                          (10) 
#define CSL_CP_TRACER_11                          (11) 
#define CSL_CP_TRACER_12                          (12) 
#define CSL_CP_TRACER_13                          (13) 
#define CSL_CP_TRACER_14                          (14) 
#define CSL_CP_TRACER_15                          (15) 
#define CSL_CP_TRACER_16                          (16) 

/** @brief Peripheral Instance for AIF */
#define CSL_EMIF_16                             (0)

/** @brief Peripheral Instance for PA_SS */
#define  CSL_PA_SS                           (0) 

/** @brief Peripheral Instance of Timer 64p */
#define CSL_TMR_0                           (0)
#define CSL_TMR_1                           (1)
#define CSL_TMR_2                           (2)
#define CSL_TMR_3                           (3)
#define CSL_TMR_4                           (4)
#define CSL_TMR_5                           (5)
#define CSL_TMR_6                           (6)
#define CSL_TMR_7                           (7)
#define CSL_TMR_8                           (8)
#define CSL_TMR_9                           (9)
#define CSL_TMR_10                           (10)
#define CSL_TMR_11                           (11)
#define CSL_TMR_12                           (12)
#define CSL_TMR_13                           (13)
#define CSL_TMR_14                           (14)
#define CSL_TMR_15                           (15)
/** @brief Instance number of PLL controller*/
#define CSL_PLLC                          (0) 

/** @brief Peripheral Instance for GPIO */
#define CSL_GPIO				            (0)

/** @brief Peripheral Instance for SMARTREFLEX */
#define CSL_SMARTREFLEX				            (0)

/** @brief Instance number of PSC controller */
#define CSL_PSC                             (0)

/** @brief Instance number of MPU */
#define CSL_MPU_0                             (0)
#define CSL_MPU_1                             (1)
#define CSL_MPU_2                             (2)
#define CSL_MPU_3                             (3)

/** @brief Instance number of DEBUG_SS */
#define CSL_DEBUG_SS                             (0)

/** @brief Instance number of GEM_DEBUG */
#define CSL_GEM_DEBUG                             (0)

/** @brief Instance number of SEC_CTL */
#define CSL_SEC_CTL                            (0)

/** @brief Instance number of SEC_KEY_MGR */
#define CSL_SEC_KEY_MGR                             (0)

/** @brief Peripheral Instance for I2C */
#define CSL_I2C                             (0) 

/** @brief Peripheral Instance of UART */
#define CSL_UART                            (0)

/** @brief Peripheral Instance numbers of CP_INTC */
#define CSL_CP_INTC_0                           (0) 
#define CSL_CP_INTC_1                           (1) 
#define CSL_CP_INTC_2                           (2) 
#define CSL_CP_INTC_3                           (3) 

/** @brief Peripheral Instance of BOOT_CFG */
#define CSL_BOOT_CFG                            (0)

/** @brief Peripheral Instance of SEMAPHORE */
#define CSL_SEMAPHORE                           (0)

/** @brief Peripheral Instance of TPCC instances */
#define CSL_TPCC_0                           (0)
#define CSL_TPCC_1                           (1)
#define CSL_TPCC_2                           (2)
/* Same as above - name changed to match data manuals */
#define CSL_EDMA3CC_0                        (0)
#define CSL_EDMA3CC_1                        (1)
#define CSL_EDMA3CC_2                        (2)

/** @brief Peripheral Instance of TPTC instances */
#define CSL_TPTC_0                           (0)
#define CSL_TPTC_1                           (1)
#define CSL_TPTC_2                           (2)
#define CSL_TPTC_3                           (3)
#define CSL_TPTC_4                           (4)
#define CSL_TPTC_5                           (5)
#define CSL_TPTC_6                           (6)
#define CSL_TPTC_7                           (7)
#define CSL_TPTC_8                           (8)
#define CSL_TPTC_9                           (9)
/* Same as above - name changed to match data manuals */
#define CSL_EDMA3TC_0                        (0)
#define CSL_EDMA3TC_1                        (1)
#define CSL_EDMA3TC_2                        (2)
#define CSL_EDMA3TC_3                        (3)
#define CSL_EDMA3TC_4                        (4)
#define CSL_EDMA3TC_5                        (5)
#define CSL_EDMA3TC_6                        (6)
#define CSL_EDMA3TC_7                        (7)
#define CSL_EDMA3TC_8                        (8)
#define CSL_EDMA3TC_9                        (9)

/** @brief Peripheral Instance of SRIO */
#define CSL_SRIO                           (0)

/** @brief Peripheral Instance of QM_SS */
#define CSL_QM_SS                           (0)

/** @brief Peripheral Instance of MSMC */
#define CSL_MSMC                           (0)

/** @brief Peripheral Instance of DSP0_GLOBAL */
#define CSL_DSP0_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP1_GLOBAL */
#define CSL_DSP1_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP2_GLOBAL */
#define CSL_DSP2_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP3_GLOBAL */
#define CSL_DSP3_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP4_GLOBAL */
#define CSL_DSP4_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP5_GLOBAL */
#define CSL_DSP5_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP6_GLOBAL */
#define CSL_DSP6_GLOBAL                          (0)

/** @brief Peripheral Instance of DSP7_GLOBAL */
#define CSL_DSP7_GLOBAL                          (0)

/** @brief Peripheral Instance of BOOT */
#define CSL_BOOT                          (0)

/** @brief Peripheral Instance of SPI */
#define CSL_SPI                          (0)

/** @brief Peripheral Instance of TSIP */
#define CSL_TSIP_0                          (0)
#define CSL_TSIP_1                          (1)

/** @brief Peripheral Instance for DDR3 */
#define CSL_DDR3                            (0)

/** @brief Instance number of MCM */
#define CSL_MCM                             (0)

/** @brief Peripheral Instance for PCIE_SS */
#define CSL_PCIE_SS				                (0)

/** @brief Instance number of device configuration module */
#define CSL_DEV                             (0) 

/* PSC Definitions */
#define CSL_PSC_NUM_PD 16
#define CSL_PSC_NUM_LPSC 23
/* PSC Power Domain Assignment Definitions */
#define CSL_PSC_PD_ALWAYSON 0
#define CSL_PSC_PD_DEBUG_TRC 1
#define CSL_PSC_PD_NETCP 2
#define CSL_PSC_PD_PASS  (CSL_PSC_PD_NETCP)
#define CSL_PSC_PD_PCIEX 3
#define CSL_PSC_PD_SRIO 4
#define CSL_PSC_PD_HYPERBRIDGE 5
#define CSL_PSC_PD_L2SRAM 6
#define CSL_PSC_PD_MSMCSRAM 7
#define CSL_PSC_PD_GEM0 8
#define CSL_PSC_PD_GEM1 9
#define CSL_PSC_PD_GEM2 10
#define CSL_PSC_PD_GEM3 11
#define CSL_PSC_PD_GEM4 12
#define CSL_PSC_PD_GEM5 13
#define CSL_PSC_PD_GEM6 14
#define CSL_PSC_PD_GEM7 15

/* PSC LPSC Module Assignment Definitions */
#define CSL_PSC_LPSC_MODRST0 0
#define CSL_PSC_LPSC_MODSRC3_PWR 1
#define CSL_PSC_LPSC_EMIF4F 2
#define CSL_PSC_LPSC_EMIF25_SPI 3
#define CSL_PSC_LPSC_TSIP 4
#define CSL_PSC_LPSC_DEBUGSS_TRC 5
#define CSL_PSC_LPSC_TETB_TRC 6
#define CSL_PSC_LPSC_PKTPROC 7
#define CSL_PSC_LPSC_PA     (CSL_PSC_LPSC_PKTPROC)
#define CSL_PSC_LPSC_CPGMAC 8
#define CSL_PSC_LPSC_Crypto  9
#define CSL_PSC_LPSC_SA     (CSL_PSC_LPSC_Crypto)
#define CSL_PSC_LPSC_PCIEX 10
#define CSL_PSC_LPSC_SRIO 11
#define CSL_PSC_LPSC_HYPERBRIDGE 12
#define CSL_PSC_LPSC_L2SRAM 13
#define CSL_PSC_LPSC_MSMCSRAM 14
#define CSL_PSC_LPSC_GEM0  15
#define CSL_PSC_LPSC_GEM1 16
#define CSL_PSC_LPSC_GEM2 17
#define CSL_PSC_LPSC_GEM3 18
#define CSL_PSC_LPSC_GEM4  19
#define CSL_PSC_LPSC_GEM5 20
#define CSL_PSC_LPSC_GEM6 21
#define CSL_PSC_LPSC_GEM7 22


/** @TPCC0 Configuration*/

#define CSL_EDMA3_TPCC0_NUM_DMACH 16
#define CSL_EDMA3_TPCC0_NUM_QDMACH 8
#define CSL_EDMA3_TPCC0_NUM_PARAMSETS 128
#define CSL_EDMA3_TPCC0_NUM_INTCH 16
#define CSL_EDMA3_TPCC0_NUM_EVQUE 2
#define CSL_EDMA3_TPCC0_NUM_TC 2
#define CSL_EDMA3_TPCC0_CHMAPEXIST 1
#define CSL_EDMA3_TPCC0_NUM_REGIONS 8
#define CSL_EDMA3_TPCC0_MEMPROTECT 1
/* Same as above - name changed to match data manuals */
#define CSL_EDMA3_EDMA3CC0_NUM_DMACH 16
#define CSL_EDMA3_EDMA3CC0_NUM_QDMACH 8
#define CSL_EDMA3_EDMA3CC0_NUM_PARAMSETS 128
#define CSL_EDMA3_EDMA3CC0_NUM_INTCH 16
#define CSL_EDMA3_EDMA3CC0_NUM_EVQUE 2
#define CSL_EDMA3_EDMA3CC0_NUM_TC 2
#define CSL_EDMA3_EDMA3CC0_CHMAPEXIST 1
#define CSL_EDMA3_EDMA3CC0_NUM_REGIONS 8
#define CSL_EDMA3_EDMA3CC0_MEMPROTECT 1

/** @TPCC1 Configuration*/

#define CSL_EDMA3_TPCC1_NUM_DMACH 64
#define CSL_EDMA3_TPCC1_NUM_QDMACH 8
#define CSL_EDMA3_TPCC1_NUM_PARAMSETS 512
#define CSL_EDMA3_TPCC1_NUM_INTCH 64
#define CSL_EDMA3_TPCC1_NUM_EVQUE 4
#define CSL_EDMA3_TPCC1_NUM_TC 4
#define CSL_EDMA3_TPCC1_CHMAPEXIST 1
#define CSL_EDMA3_TPCC1_NUM_REGIONS 8
#define CSL_EDMA3_TPCC1_MEMPROTECT 1
/* Same as above - name changed to match data manuals */
#define CSL_EDMA3_EDMA3CC1_NUM_DMACH 64
#define CSL_EDMA3_EDMA3CC1_NUM_QDMACH 8
#define CSL_EDMA3_EDMA3CC1_NUM_PARAMSETS 512
#define CSL_EDMA3_EDMA3CC1_NUM_INTCH 64
#define CSL_EDMA3_EDMA3CC1_NUM_EVQUE 4
#define CSL_EDMA3_EDMA3CC1_NUM_TC 4
#define CSL_EDMA3_EDMA3CC1_CHMAPEXIST 1
#define CSL_EDMA3_EDMA3CC1_NUM_REGIONS 8
#define CSL_EDMA3_EDMA3CC1_MEMPROTECT 1

/** @TPCC2 Configuration*/

#define CSL_EDMA3_TPCC2_NUM_DMACH 64
#define CSL_EDMA3_TPCC2_NUM_QDMACH 8
#define CSL_EDMA3_TPCC2_NUM_PARAMSETS 512
#define CSL_EDMA3_TPCC2_NUM_INTCH 64
#define CSL_EDMA3_TPCC2_NUM_EVQUE 4
#define CSL_EDMA3_TPCC2_NUM_TC 4
#define CSL_EDMA3_TPCC2_CHMAPEXIST 1
#define CSL_EDMA3_TPCC2_NUM_REGIONS 8
#define CSL_EDMA3_TPCC2_MEMPROTECT 1
/* Same as above - name changed to match data manuals */
#define CSL_EDMA3_EDMA3CC2_NUM_DMACH 64
#define CSL_EDMA3_EDMA3CC2_NUM_QDMACH 8
#define CSL_EDMA3_EDMA3CC2_NUM_PARAMSETS 512
#define CSL_EDMA3_EDMA3CC2_NUM_INTCH 64
#define CSL_EDMA3_EDMA3CC2_NUM_EVQUE 4
#define CSL_EDMA3_EDMA3CC2_NUM_TC 4
#define CSL_EDMA3_EDMA3CC2_CHMAPEXIST 1
#define CSL_EDMA3_EDMA3CC2_NUM_REGIONS 8
#define CSL_EDMA3_EDMA3CC2_MEMPROTECT 1
/**************************************************************************
* Peripheral Base Address-0.1.6
**************************************************************************/
#define CSL_CGEM0_5_LOCAL_L2_SRAM_REGS (0x00800000)
#define CSL_CGEM0_5_LOCAL_L1P_SRAM_REGS (0x00e00000)
#define CSL_CGEM0_5_L1D_SRAM_REGS (0x00f00000)
#define CSL_CGEM0_5_REG_BASE_ADDRESS_REGS (0x01800000)
#define CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS (CSL_CGEM0_5_REG_BASE_ADDRESS_REGS)
#define CSL_CGEM0_5_POWER_DOWN_CONTROL_REGS (0x01810000)
#define CSL_CGEM0_5_SECURITY_ID_REGS (0x01811000)
#define CSL_CGEM0_5_REVISION_ID_REGS (0x01812000)
#define CSL_CGEM0_5_L1_L2_CONTROL_REGS (0x01840000)
#define CSL_CGEM0_5_EMULATION_REGS (0x01bc0000)
#define CSL_TRACER_ICPM_MSMC0_MST_SLV_0_REGS (0x01d00000)
#define CSL_TRACER_ICPM_MSMC1_MST_SLV_1_REGS (0x01d08000)
#define CSL_TRACER_ICPM_MSMC2_MST_SLV_2_REGS (0x01d10000)
#define CSL_TRACER_ICPM_MSMC3_MST_SLV_3_REGS (0x01d18000)
#define CSL_TRACER_ICPM_QM_VBUSM_MST_SLV_4_REGS (0x01d20000)
#define CSL_TRACER_ICPM_DDR_MST_SLV_5_REGS (0x01d28000)
#define CSL_TRACER_ICPM_SM_MST_SLV_6_REGS (0x01d30000)
#define CSL_TRACER_ICPM_QM_VBUSP_MST_SLV_7_REGS (0x01d38000)
#define CSL_TRACER_ICPM_CFG_MST_SLV_8_REGS (0x01d40000)
#define CSL_TRACER_ICPM_L2_0_MST_SLV_9_REGS (0x01d48000)
#define CSL_TRACER_ICPM_L2_1_MST_SLV_10_REGS (0x01d50000)
#define CSL_TRACER_ICPM_L2_2_MST_SLV_11_REGS (0x01d58000)
#define CSL_TRACER_ICPM_L2_3_MST_SLV_12_REGS (0x01d60000)
#define CSL_TRACER_ICPM_L2_4_MST_SLV_13_REGS (0x01d68000)
#define CSL_TRACER_ICPM_L2_5_MST_SLV_14_REGS (0x01d70000)
#define CSL_TRACER_ICPM_L2_6_MST_SLV_15_REGS (0x01d78000)
#define CSL_TRACER_ICPM_L2_7_MST_SLV_16_REGS (0x01d80000)
#define CSL_TSIP0_REGS          (0x01e00000)
#define CSL_TSIP1_REGS          (0x01e80000)
#define CSL_PA_SS_CFG_REGS     (0x02000000)
#define CSL_NETCP_CFG_REGS     (CSL_PA_SS_CFG_REGS)
#define CSL_PA_SS_CFG_CPPI_DMA_GLOBAL_CFG_REGS (0x02004000)
#define CSL_PA_SS_CFG_CPPI_DMA_TX_CFG_REGS (0x02004400)
#define CSL_PA_SS_CFG_CPPI_DMA_RX_CFG_REGS (0x02004800)
#define CSL_PA_SS_CFG_CPPI_DMA_TX_SCHEDULER_CFG_REGS (0x02004c00)
#define CSL_PA_SS_CFG_CPPI_DMA_RX_FLOW_CFG_REGS (0x02005000)
#define CSL_PA_SS_CFG_CP_ACE_CFG_REGS (0x020C0000)
#define CSL_NETCP_CFG_SA_CFG_REGS  (CSL_PA_SS_CFG_CP_ACE_CFG_REGS)
#define CSL_TIMER_0_REGS        (0x02200000)
#define CSL_TIMER_1_REGS        (0x02210000)
#define CSL_TIMER_2_REGS        (0x02220000)
#define CSL_TIMER_3_REGS        (0x02230000)
#define CSL_TIMER_4_REGS        (0x02240000)
#define CSL_TIMER_5_REGS        (0x02250000)
#define CSL_TIMER_6_REGS        (0x02260000)
#define CSL_TIMER_7_REGS        (0x02270000)
#define CSL_TIMER_8_REGS        (0x02280000)
#define CSL_TIMER_9_REGS        (0x02290000)
#define CSL_TIMER_10_REGS       (0x022a0000)
#define CSL_TIMER_11_REGS       (0x022b0000)
#define CSL_TIMER_12_REGS       (0x022c0000)
#define CSL_TIMER_13_REGS       (0x022d0000)
#define CSL_TIMER_14_REGS       (0x022e0000)
#define CSL_TIMER_15_REGS       (0x022f0000)
#define CSL_PLL_CONTROLLER_REGS (0x02310000)
#define CSL_GPIO_REGS           (0x02320000)
#define CSL_PID_PLUS_RESERVED_REGS (0x02330000)
#define CSL_SR_VPRM_REGS        (0x02330080)
#define CSL_SMARTREFLEX_SENSOR0_REGS (0x02330100)
#define CSL_SMARTREFLEX_SENSOR1_REGS (0x02330180)
#define CSL_SMARTREFLEX_SENSOR2_REGS (0x02330200)
#define CSL_SMARTREFLEX_SENSOR3_REGS (0x02330280)
#define CSL_SR_VP_REGS          (0x02330300)
#define CSL_SR_VOLCON_REGS      (0x02330380)
#define CSL_PSC_REGS            (0x02350000)
#define CSL_MPU_0_REGS          (0x02360000)
#define CSL_MPU_1_REGS          (0x02368000)
#define CSL_MPU_2_REGS          (0x02370000)
#define CSL_MPU_3_REGS          (0x02378000)
#define CSL_DEBUG_SS_CONFIG_REGS (0x02400000)
#define CSL_TETB8_SYSTEM_TRACE_REGS (0x02850000)
#define CSL_STM_REGS            (0x20000000)
#define CSL_DEBUG_ADTF_0_REGS   (0x02440000)
#define CSL_DEBUG_ADTF_1_REGS   (0x02450000)
#define CSL_DEBUG_ADTF_2_REGS   (0x02460000)
#define CSL_DEBUG_ADTF_3_REGS   (0x02470000)
#define CSL_DEBUG_ADTF_4_REGS   (0x02480000)
#define CSL_DEBUG_ADTF_5_REGS   (0x02490000)
#define CSL_DEBUG_ADTF_6_REGS   (0x024a0000)
#define CSL_DEBUG_ADTF_7_REGS   (0x024b0000)
#define CSL_TETB_0_REGS         (0x027d0000)
#define CSL_TETB_1_REGS         (0x027e0000)
#define CSL_TETB_2_REGS         (0x027f0000)
#define CSL_TETB_3_REGS         (0x02800000)
#define CSL_TETB_4_REGS         (0x02810000)
#define CSL_TETB_5_REGS         (0x02820000)
#define CSL_TETB_6_REGS         (0x02830000)
#define CSL_TETB_7_REGS         (0x02840000)
#define CSL_SEC_CTL_REGS        (0x02500000)
#define CSL_SEC_KEY_MGR_REGS    (0x02520000)
#define CSL_I2C_DATA_CONTROL_REGS (0x02530000)
#define CSL_UART_REGS            (0x02540000)
#define CSL_CP_INTC_0_REGS      (0x02600000)
#define CSL_CP_INTC_1_REGS      (0x02604000)
#define CSL_CP_INTC_2_REGS      (0x02608000)
#define CSL_CP_INTC_3_REGS      (0x0260c000)
#define CSL_BOOT_CFG_REGS       (0x02620000)
#define CSL_SEMAPHORE_REGS      (0x02640000)
#define CSL_EDMA0CC_REGS  (0x02700000)
#define CSL_EDMA1CC_REGS  (0x02720000)
#define CSL_EDMA2CC_REGS  (0x02740000)
#define CSL_EDMA0TC0_REGS (0x02760000)
#define CSL_EDMA0TC1_REGS (0x02768000)
#define CSL_EDMA1TC0_REGS (0x02770000)
#define CSL_EDMA1TC1_REGS (0x02778000)
#define CSL_EDMA1TC2_REGS (0x02780000)
#define CSL_EDMA1TC3_REGS (0x02788000)
#define CSL_EDMA2TC0_REGS (0x02790000)
#define CSL_EDMA2TC1_REGS (0x02798000)
#define CSL_EDMA2TC2_REGS (0x027a0000)
#define CSL_EDMA2TC3_REGS (0x027a8000)
#define CSL_SRIO_CONFIG_REGS   (0x02900000)
#define CSL_SRIO_CONFIG_CPPI_DMA_GLOBAL_CFG_REGS (0x02901000)
#define CSL_SRIO_CONFIG_CPPI_DMA_TX_CFG_REGS (0x02901400)
#define CSL_SRIO_CONFIG_CPPI_DMA_RX_CFG_REGS (0x02901800)
#define CSL_SRIO_CONFIG_CPPI_DMA_TX_SCHEDULER_CFG_REGS (0x02901c00)
#define CSL_SRIO_CONFIG_CPPI_DMA_RX_FLOW_CFG_REGS (0x02902000)
#define CSL_QM_SS_CFG_QUE_PEEK_REGS (0x02a00000)
#define CSL_QM_SS_CFG_QM_QUEUE_DEQUEUE_REGS (0x02a20000)
#define CSL_QM_SS_CFG_PROXY_QUEUE_DEQUEUE_REGS (0x02a40000)
#define CSL_QM_SS_CFG_APDSP1_RAM_REGS (0x02a60000)
#define CSL_QM_SS_CFG_APDSP2_RAM_REGS (0x02a61000)
#define CSL_QM_SS_CFG_QM_STATUS_RAM_REGS (0x02a62000)
#define CSL_QM_SS_CFG_CONFIG_STARVATION_COUNTER_REGS (0x02a68000)
#define CSL_QM_SS_CFG_DESCRIPTION_REGS (0x02a6a000)
#define CSL_QM_SS_CFG_PROXY_CONFIG_REGS (0x02a6b000)
#define CSL_QM_SS_CFG_CPPI_DMA_GLOBAL_CFG_REGS (0x02a6c000)
#define CSL_QM_SS_CFG_CPPI_DMA_TX_CFG_REGS (0x02a6c400)
#define CSL_QM_SS_CFG_CPPI_DMA_RX_CFG_REGS (0x02a6c800)
#define CSL_QM_SS_CFG_CPPI_DMA_RX_FLOW_CFG_REGS (0x02a6d000)
#define CSL_QM_SS_CFG_CPPI_DMA_TX_SCHEDULER_CFG_REGS (0x02a6cc00)
#define CSL_QM_SS_CFG_ADSP1_REGS (0x02a6e000)
#define CSL_QM_SS_CFG_ADSP2_REGS (0x02a6f000)
#define CSL_QM_SS_CFG_LINKING_RAM_REGS (0x02a80000)
#define CSL_QM_SS_CFG_MCDMA_REGS (0x02a90000)
#define CSL_QM_SS_CFG_INTD_REGS (0x02aa0000)
#define CSL_QM_SS_CFG_TIMER1_REGS (0x02aa8000)
#define CSL_QM_SS_CFG_TIMER2_REGS (0x02aa8800)
#define CSL_QM_SS_CFG_SCRACH_RAM1_REGS (0x02ab8000)
#define CSL_QM_SS_CFG_SCRACH_RAM2_REGS (0x02abc000)
#define CSL_QM_SS_DATA_QM_QUEUE_DEQUEUE_REGS (0x34020000)
#define CSL_QM_SS_DATA_PROXY_QUEUE_DEQUEUE_REGS (0x34040000)
#define CSL_QM_SS_DATA_APDSP1_RAM_REGS (0x34060000)
#define CSL_QM_SS_DATA_APDSP2_RAM_REGS (0x34061000)
#define CSL_XMC_CONFIG_REGS     (0x08000000)
#define CSL_MSMC_CONFIG_REGS    (0x0bc00000)
#ifndef CSL_MODIFICATION
#define CSL_MSMC_CFG_REGS		(CSL_MSMC_CONFIG_REGS)
#endif
#define CSL_MSMC_SRAM_REGS      (0x0c000000)
#ifndef CSL_MODIFICATION
#define CSL_MSMC_SRAM_REGS_SIZE (0x400000)
#endif
#define CSL_DSP0_L2_SRAM_REGS   (0x10800000)
#define CSL_DSP0_L1P_SRAM_REGS  (0x10e00000)
#define CSL_DSP0_L1D_SRAM_REGS  (0x10f00000)
#define CSL_DSP1_L2_SRAM_REGS   (0x11800000)
#define CSL_DSP1_L1P_SRAM_REGS  (0x11e00000)
#define CSL_DSP1_L1D_SRAM_REGS  (0x11f00000)
#define CSL_DSP2_L2_SRAM_REGS   (0x12800000)
#define CSL_DSP2_L1P_SRAM_REGS  (0x12e00000)
#define CSL_DSP2_L1D_SRAM_REGS  (0x12f00000)
#define CSL_DSP3_L2_SRAM_REGS   (0x13800000)
#define CSL_DSP3_L1P_SRAM_REGS  (0x13e00000)
#define CSL_DSP3_L1D_SRAM_REGS  (0x13f00000)
#define CSL_DSP4_L2_SRAM_REGS   (0x14800000)
#define CSL_DSP4_L1P_SRAM_REGS  (0x14e00000)
#define CSL_DSP4_L1D_SRAM_REGS  (0x14f00000)
#define CSL_DSP5_L2_SRAM_REGS   (0x15800000)
#define CSL_DSP5_L1P_SRAM_REGS  (0x15e00000)
#define CSL_DSP5_L1D_SRAM_REGS  (0x15f00000)
#define CSL_DSP6_L2_SRAM_REGS   (0x16800000)
#define CSL_DSP6_L1P_SRAM_REGS  (0x16e00000)
#define CSL_DSP6_L1D_SRAM_REGS  (0x16f00000)
#define CSL_DSP7_L2_SRAM_REGS   (0x17800000)
#define CSL_DSP7_L1P_SRAM_REGS  (0x17e00000)
#define CSL_DSP7_L1D_SRAM_REGS  (0x17f00000)
#define CSL_BOOT_ROM_REGS       (0x20b00000)
#define CSL_SPI_REGS            (0x20bf0000)
#define CSL_EMIF16_REGS         (0x20c00000)
#define CSL_CS2_DATA_MEMORY_REGS (0x70000000)
#define CSL_CS3_DATA_MEMORY_REGS (0x74000000)
#define CSL_CS4_DATA_MEMORY_REGS (0x78000000)
#define CSL_CS5_DATA_MEMORY_REGS (0x7C000000)
#define CSL_DDR3_EMIF_CONFIG_REGS (0x21000000)
#define CSL_DDR3_DATA_0_REGS    (0x80000000)
#define CSL_DDR3_DATA_1_REGS    (0x90000000)
#define CSL_DDR3_DATA_2_REGS    (0xa0000000)
#define CSL_DDR3_DATA_3_REGS    (0xb0000000)
#define CSL_DDR3_DATA_4_REGS    (0xc0000000)
#define CSL_DDR3_DATA_5_REGS    (0xd0000000)
#define CSL_DDR3_DATA_6_REGS    (0xe0000000)
#define CSL_DDR3_DATA_7_REGS    (0xf0000000)
#define CSL_MCM_CONFIG_REGS     (0x21400000)
#define CSL_MCM_REGS            (0x40000000)
#define CSL_PCIE_CONFIG_REGS    (0x21800000)
#define CSL_PCIE_REGS           (0x60000000)

/**************************************************************************
* CHIP LEVEL INTC0 EVENT INPUT-0.1.10
**************************************************************************/

#define INTC0_EVENT_CNT                 160


/**************************************************************************
* CHIP LEVEL INTC0 EVENT DEFINITION
**************************************************************************/
#define CSL_INTC0_CPU_3_1_EDMACC_ERRINT (0x00000000)
#define CSL_INTC0_CPU_3_1_EDMACC_MPINT (0x00000001)
#define CSL_INTC0_CPU_3_1_EDMATC_ERRINT0 (0x00000002)
#define CSL_INTC0_CPU_3_1_EDMATC_ERRINT1 (0x00000003)
#define CSL_INTC0_CPU_3_1_EDMATC_ERRINT2 (0x00000004)
#define CSL_INTC0_CPU_3_1_EDMATC_ERRINT3 (0x00000005)
#define CSL_INTC0_CPU_3_1_EDMACC_GINT (0x00000006)
#define CSL_INTC0_RESERVED_1         (0x00000007)
#define CSL_INTC0_CPU_3_1_TPCCINT0   (0x00000008)
#define CSL_INTC0_CPU_3_1_TPCCINT1   (0x00000009)
#define CSL_INTC0_CPU_3_1_TPCCINT2   (0x0000000a)
#define CSL_INTC0_CPU_3_1_TPCCINT3   (0x0000000b)
#define CSL_INTC0_CPU_3_1_TPCCINT4   (0x0000000c)
#define CSL_INTC0_CPU_3_1_TPCCINT5   (0x0000000d)
#define CSL_INTC0_CPU_3_1_TPCCINT6   (0x0000000e)
#define CSL_INTC0_CPU_3_1_TPCCINT7   (0x0000000f)
/* Same as above - name changed to match data manuals */
#define CSL_INTC0_CPU_3_1_EDMA3CCINT0   (0x00000008)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT1   (0x00000009)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT2   (0x0000000a)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT3   (0x0000000b)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT4   (0x0000000c)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT5   (0x0000000d)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT6   (0x0000000e)
#define CSL_INTC0_CPU_3_1_EDMA3CCINT7   (0x0000000f)
#define CSL_INTC0_CPU_3_2_EDMACC_ERRINT (0x00000010)
#define CSL_INTC0_CPU_3_2_EDMACC_MPINT (0x00000011)
#define CSL_INTC0_CPU_3_2_EDMATC_ERRINT0 (0x00000012)
#define CSL_INTC0_CPU_3_2_EDMATC_ERRINT1 (0x00000013)
#define CSL_INTC0_CPU_3_2_EDMATC_ERRINT2 (0x00000014)
#define CSL_INTC0_CPU_3_2_EDMATC_ERRINT3 (0x00000015)
#define CSL_INTC0_CPU_3_2_EDMACC_GINT (0x00000016)
#define CSL_INTC0_RESERVED_2         (0x00000017)
#define CSL_INTC0_CPU_3_2_TPCCINT0   (0x00000018)
#define CSL_INTC0_CPU_3_2_TPCCINT1   (0x00000019)
#define CSL_INTC0_CPU_3_2_TPCCINT2   (0x0000001a)
#define CSL_INTC0_CPU_3_2_TPCCINT3   (0x0000001b)
#define CSL_INTC0_CPU_3_2_TPCCINT4   (0x0000001c)
#define CSL_INTC0_CPU_3_2_TPCCINT5   (0x0000001d)
#define CSL_INTC0_CPU_3_2_TPCCINT6   (0x0000001e)
#define CSL_INTC0_CPU_3_2_TPCCINT7   (0x0000001f)
/* Same as above - name changed to match data manuals */
#define CSL_INTC0_CPU_3_2_EDMA3CCINT0   (0x00000018)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT1   (0x00000019)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT2   (0x0000001a)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT3   (0x0000001b)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT4   (0x0000001c)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT5   (0x0000001d)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT6   (0x0000001e)
#define CSL_INTC0_CPU_3_2_EDMA3CCINT7   (0x0000001f)
#define CSL_INTC0_CPU_2_EDMACC_ERRINT (0x00000020)
#define CSL_INTC0_CPU_2_EDMACC_MPINT (0x00000021)
#define CSL_INTC0_CPU_2_EDMATC_ERRINT0 (0x00000022)
#define CSL_INTC0_CPU_2_EDMATC_ERRINT1 (0x00000023)
#define CSL_INTC0_CPU_2_EDMACC_GINT  (0x00000024)
#define CSL_INTC0_RESERVED_3         (0x00000025)
#define CSL_INTC0_CPU_2_TPCCINT0     (0x00000026)
#define CSL_INTC0_CPU_2_TPCCINT1     (0x00000027)
#define CSL_INTC0_CPU_2_TPCCINT2     (0x00000028)
#define CSL_INTC0_CPU_2_TPCCINT3     (0x00000029)
#define CSL_INTC0_CPU_2_TPCCINT4     (0x0000002a)
#define CSL_INTC0_CPU_2_TPCCINT5     (0x0000002b)
#define CSL_INTC0_CPU_2_TPCCINT6     (0x0000002c)
#define CSL_INTC0_CPU_2_TPCCINT7     (0x0000002d)
/* Same as above - name changed to match data manuals */
#define CSL_INTC0_CPU_2_EDMA3CCINT0     (0x00000026)
#define CSL_INTC0_CPU_2_EDMA3CCINT1     (0x00000027)
#define CSL_INTC0_CPU_2_EDMA3CCINT2     (0x00000028)
#define CSL_INTC0_CPU_2_EDMA3CCINT3     (0x00000029)
#define CSL_INTC0_CPU_2_EDMA3CCINT4     (0x0000002a)
#define CSL_INTC0_CPU_2_EDMA3CCINT5     (0x0000002b)
#define CSL_INTC0_CPU_2_EDMA3CCINT6     (0x0000002c)
#define CSL_INTC0_CPU_2_EDMA3CCINT7     (0x0000002d)
#define CSL_INTC0_RESERVED_4         (0x0000002e)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_12 (0x0000002f)
#define CSL_INTC0_PCIEXPRESS_ERR_INT (0x00000030)
#define CSL_INTC0_PCIEXPRESS_PM_INT  (0x00000031)
#define CSL_INTC0_PCIEXPRESS_LEGACY_INTA (0x00000032)
#define CSL_INTC0_PCIEXPRESS_LEGACY_INTB (0x00000033)
#define CSL_INTC0_PCIEXPRESS_LEGACY_INTC (0x00000034)
#define CSL_INTC0_PCIEXPRESS_LEGACY_INTD (0x00000035)
#define CSL_INTC0_SPIINT0            (0x00000036)
#define CSL_INTC0_SPIINT1            (0x00000037)
#define CSL_INTC0_SPIXEVT            (0x00000038)
#define CSL_INTC0_SPIREVT            (0x00000039)
#define CSL_INTC0_I2CINT             (0x0000003a)
#define CSL_INTC0_I2CREVT            (0x0000003b)
#define CSL_INTC0_I2CXEVT            (0x0000003c)
#define CSL_INTC0_KEYMGRINT          (0x0000003d)
#define CSL_INTC0_SECCTLINT          (0x0000003e)
#define CSL_INTC0_TETBHFULLINT       (0x0000003f)
#define CSL_INTC0_TETBFULLINT        (0x00000040)
#define CSL_INTC0_TETBACQINT         (0x00000041)
#define CSL_INTC0_TETBOVFLINT        (0x00000042)
#define CSL_INTC0_TETBUNFLINT        (0x00000043)
#define CSL_INTC0_MDIO_LINK_INTR0    (0x00000044)
#define CSL_INTC0_MDIO_LINK_INTR1    (0x00000045)
#define CSL_INTC0_MDIO_USER_INTR0    (0x00000046)
#define CSL_INTC0_MDIO_USER_INTR1    (0x00000047)
#define CSL_INTC0_MISC_INTR          (0x00000048)
#define CSL_INTC0_CP_TRACER_CORE_0_INTD (0x00000049)
#define CSL_INTC0_CP_TRACER_CORE_1_INTD (0x0000004a)
#define CSL_INTC0_CP_TRACER_CORE_2_INTD (0x0000004b)
#define CSL_INTC0_CP_TRACER_CORE_3_INTD (0x0000004c)
#define CSL_INTC0_CP_TRACER_DDR_INTD (0x0000004d)
#define CSL_INTC0_CP_TRACER_MSMC_0_INTD (0x0000004e)
#define CSL_INTC0_CP_TRACER_MSMC_1_INTD (0x0000004f)
#define CSL_INTC0_CP_TRACER_MSMC_2_INTD (0x00000050)
#define CSL_INTC0_CP_TRACER_MSMC_3_INTD (0x00000051)
#define CSL_INTC0_CP_TRACER_CFG_INTD (0x00000052)
#define CSL_INTC0_CP_TRACER_QM_SS_CFG_INTD (0x00000053)
#define CSL_INTC0_CP_TRACER_QM_SS_DMA_INTD (0x00000054)
#define CSL_INTC0_CP_TRACER_SEM_INTD (0x00000055)
#define CSL_INTC0_PSC_ALLINT         (0x00000056)
#define CSL_INTC0_MSMC_SCRUB_CERROR  (0x00000057)
#define CSL_INTC0_BOOTCFG_INTD       (0x00000058)
#define CSL_INTC0_PO_VCON_SMPSERR_INTR (0x00000059)
#define CSL_INTC0_MPU0_INTD          (0x0000005a)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_13 (0x0000005b)
#define CSL_INTC0_MPU1_INTD          (0x0000005c)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_14 (0x0000005d)
#define CSL_INTC0_MPU2_INTD          (0x0000005e)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_15 (0x0000005f)
#define CSL_INTC0_MPU3_INTD          (0x00000060)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_16 (0x00000061)
#define CSL_INTC0_MSMC_DEDC_CERROR   (0x00000062)
#define CSL_INTC0_MSMC_DEDC_NC_ERROR (0x00000063)
#define CSL_INTC0_MSMC_SCRUB_NC_ERROR (0x00000064)
#define CSL_INTC0_RESERVED_5 (0x00000065)
#define CSL_INTC0_MSMC_MPF_ERROR8    (0x00000066)
#define CSL_INTC0_MSMC_MPF_ERROR9    (0x00000067)
#define CSL_INTC0_MSMC_MPF_ERROR10   (0x00000068)
#define CSL_INTC0_MSMC_MPF_ERROR11   (0x00000069)
#define CSL_INTC0_MSMC_MPF_ERROR12   (0x0000006a)
#define CSL_INTC0_MSMC_MPF_ERROR13   (0x0000006b)
#define CSL_INTC0_MSMC_MPF_ERROR14   (0x0000006c)
#define CSL_INTC0_MSMC_MPF_ERROR15   (0x0000006d)
#define CSL_INTC0_DDR3_ERR           (0x0000006e)
#define CSL_INTC0_VUSR_INT_O         (0x0000006f)
#define CSL_INTC0_INTDST0            (0x00000070)
#define CSL_INTC0_INTDST1            (0x00000071)
#define CSL_INTC0_INTDST2            (0x00000072)
#define CSL_INTC0_INTDST3            (0x00000073)
#define CSL_INTC0_INTDST4            (0x00000074)
#define CSL_INTC0_INTDST5            (0x00000075)
#define CSL_INTC0_INTDST6            (0x00000076)
#define CSL_INTC0_INTDST7            (0x00000077)
#define CSL_INTC0_INTDST8            (0x00000078)
#define CSL_INTC0_INTDST9            (0x00000079)
#define CSL_INTC0_INTDST10           (0x0000007a)
#define CSL_INTC0_INTDST11           (0x0000007b)
#define CSL_INTC0_INTDST12           (0x0000007c)
#define CSL_INTC0_INTDST13           (0x0000007d)
#define CSL_INTC0_INTDST14           (0x0000007e)
#define CSL_INTC0_INTDST15           (0x0000007f)
#define CSL_INTC0_EASYNCERR          (0x00000080)
#define CSL_INTC0_CP_TRACER_CORE_4_INTD (0x00000081)
#define CSL_INTC0_CP_TRACER_CORE_5_INTD (0x00000082)
#define CSL_INTC0_CP_TRACER_CORE_6_INTD (0x00000083)
#define CSL_INTC0_CP_TRACER_CORE_7_INTD (0x00000084)
#define CSL_INTC0_QM_INT_CDMA_0      (0x00000085)
#define CSL_INTC0_QM_INT_CDMA_1      (0x00000086)
#define CSL_INTC0_RAPIDIO_INT_CDMA_0 (0x00000087)
#define CSL_INTC0_PASS_INT_CDMA_0    (0x00000088)
#define CSL_INTC0_SMARTREFLEX_INTRREQ0 (0x00000089)
#define CSL_INTC0_SMARTREFLEX_INTRREQ1 (0x0000008a)
#define CSL_INTC0_SMARTREFLEX_INTRREQ2 (0x0000008b)
#define CSL_INTC0_SMARTREFLEX_INTRREQ3 (0x0000008c)
#define CSL_INTC0_VPNOSMPSACK        (0x0000008d)
#define CSL_INTC0_VPEQVALUE          (0x0000008e)
#define CSL_INTC0_VPMAXVDD           (0x0000008f)
#define CSL_INTC0_VPMINVDD           (0x00000090)
#define CSL_INTC0_VPINIDLE           (0x00000091)
#define CSL_INTC0_VPOPPCHANGEDONE    (0x00000092)
#define CSL_INTC0_DFT_PBIST_CPU_INT  (0x00000093)
#define CSL_INTC0_UARTINT            (0x00000094)
#define CSL_INTC0_URXEVT             (0x00000095)
#define CSL_INTC0_UTXEVT             (0x00000096)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_17 (0x00000097)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_18 (0x00000098)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_19 (0x00000099)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_20 (0x0000009a)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_21 (0x0000009b)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_22 (0x0000009c)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_23 (0x0000009d)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_24 (0x0000009e)
#define CSL_INTC0_QM_INT_PASS_TXQ_PEND_25 (0x0000009f)
/**************************************************************************
* CHIP LEVEL INTC1 EVENT INPUT-0.1.10
**************************************************************************/

#define INTC1_EVENT_CNT                 160


/**************************************************************************
* CHIP LEVEL INTC1 EVENT DEFINITION
**************************************************************************/
#define CSL_INTC1_CPU_3_1_EDMACC_ERRINT (0x00000000)
#define CSL_INTC1_CPU_3_1_EDMACC_MPINT (0x00000001)
#define CSL_INTC1_CPU_3_1_EDMATC_ERRINT0 (0x00000002)
#define CSL_INTC1_CPU_3_1_EDMATC_ERRINT1 (0x00000003)
#define CSL_INTC1_CPU_3_1_EDMATC_ERRINT2 (0x00000004)
#define CSL_INTC1_CPU_3_1_EDMATC_ERRINT3 (0x00000005)
#define CSL_INTC1_CPU_3_1_EDMACC_GINT (0x00000006)
#define CSL_INTC1_RESERVED_1         (0x00000007)
#define CSL_INTC1_CPU_3_1_TPCCINT0   (0x00000008)
#define CSL_INTC1_CPU_3_1_TPCCINT1   (0x00000009)
#define CSL_INTC1_CPU_3_1_TPCCINT2   (0x0000000a)
#define CSL_INTC1_CPU_3_1_TPCCINT3   (0x0000000b)
#define CSL_INTC1_CPU_3_1_TPCCINT4   (0x0000000c)
#define CSL_INTC1_CPU_3_1_TPCCINT5   (0x0000000d)
#define CSL_INTC1_CPU_3_1_TPCCINT6   (0x0000000e)
#define CSL_INTC1_CPU_3_1_TPCCINT7   (0x0000000f)
#define CSL_INTC1_CPU_3_2_EDMACC_ERRINT (0x00000010)
#define CSL_INTC1_CPU_3_2_EDMACC_MPINT (0x00000011)
#define CSL_INTC1_CPU_3_2_EDMATC_ERRINT0 (0x00000012)
#define CSL_INTC1_CPU_3_2_EDMATC_ERRINT1 (0x00000013)
#define CSL_INTC1_CPU_3_2_EDMATC_ERRINT2 (0x00000014)
#define CSL_INTC1_CPU_3_2_EDMATC_ERRINT3 (0x00000015)
#define CSL_INTC1_CPU_3_2_EDMACC_GINT (0x00000016)
#define CSL_INTC1_RESERVED_2         (0x00000017)
#define CSL_INTC1_CPU_3_2_TPCCINT0   (0x00000018)
#define CSL_INTC1_CPU_3_2_TPCCINT1   (0x00000019)
#define CSL_INTC1_CPU_3_2_TPCCINT2   (0x0000001a)
#define CSL_INTC1_CPU_3_2_TPCCINT3   (0x0000001b)
#define CSL_INTC1_CPU_3_2_TPCCINT4   (0x0000001c)
#define CSL_INTC1_CPU_3_2_TPCCINT5   (0x0000001d)
#define CSL_INTC1_CPU_3_2_TPCCINT6   (0x0000001e)
#define CSL_INTC1_CPU_3_2_TPCCINT7   (0x0000001f)
#define CSL_INTC1_CPU_2_EDMACC_ERRINT (0x00000020)
#define CSL_INTC1_CPU_2_EDMACC_MPINT (0x00000021)
#define CSL_INTC1_CPU_2_EDMATC_ERRINT0 (0x00000022)
#define CSL_INTC1_CPU_2_EDMATC_ERRINT1 (0x00000023)
#define CSL_INTC1_CPU_2_EDMACC_GINT  (0x00000024)
#define CSL_INTC1_RESERVED_3         (0x00000025)
#define CSL_INTC1_CPU_2_TPCCINT0     (0x00000026)
#define CSL_INTC1_CPU_2_TPCCINT1     (0x00000027)
#define CSL_INTC1_CPU_2_TPCCINT2     (0x00000028)
#define CSL_INTC1_CPU_2_TPCCINT3     (0x00000029)
#define CSL_INTC1_CPU_2_TPCCINT4     (0x0000002a)
#define CSL_INTC1_CPU_2_TPCCINT5     (0x0000002b)
#define CSL_INTC1_CPU_2_TPCCINT6     (0x0000002c)
#define CSL_INTC1_CPU_2_TPCCINT7     (0x0000002d)
#define CSL_INTC1_RESERVED_4         (0x0000002e)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_18 (0x0000002f)
#define CSL_INTC1_PCIEXPRESS_ERR_INT (0x00000030)
#define CSL_INTC1_PCIEXPRESS_PM_INT  (0x00000031)
#define CSL_INTC1_PCIEXPRESS_LEGACY_INTA (0x00000032)
#define CSL_INTC1_PCIEXPRESS_LEGACY_INTB (0x00000033)
#define CSL_INTC1_PCIEXPRESS_LEGACY_INTC (0x00000034)
#define CSL_INTC1_PCIEXPRESS_LEGACY_INTD (0x00000035)
#define CSL_INTC1_SPIINT0            (0x00000036)
#define CSL_INTC1_SPIINT1            (0x00000037)
#define CSL_INTC1_SPIXEVT            (0x00000038)
#define CSL_INTC1_SPIREVT            (0x00000039)
#define CSL_INTC1_I2CINT             (0x0000003a)
#define CSL_INTC1_I2CREVT            (0x0000003b)
#define CSL_INTC1_I2CXEVT            (0x0000003c)
#define CSL_INTC1_KEYMGRINT          (0x0000003d)
#define CSL_INTC1_SECCTLINT          (0x0000003e)
#define CSL_INTC1_TETBHFULLINT       (0x0000003f)
#define CSL_INTC1_TETBFULLINT        (0x00000040)
#define CSL_INTC1_TETBACQINT         (0x00000041)
#define CSL_INTC1_TETBOVFLINT        (0x00000042)
#define CSL_INTC1_TETBUNFLINT        (0x00000043)
#define CSL_INTC1_MDIO_LINK_INTR0    (0x00000044)
#define CSL_INTC1_MDIO_LINK_INTR1    (0x00000045)
#define CSL_INTC1_MDIO_USER_INTR0    (0x00000046)
#define CSL_INTC1_MDIO_USER_INTR1    (0x00000047)
#define CSL_INTC1_MISC_INTR          (0x00000048)
#define CSL_INTC1_CP_TRACER_CORE_0_INTD (0x00000049)
#define CSL_INTC1_CP_TRACER_CORE_1_INTD (0x0000004a)
#define CSL_INTC1_CP_TRACER_CORE_2_INTD (0x0000004b)
#define CSL_INTC1_CP_TRACER_CORE_3_INTD (0x0000004c)
#define CSL_INTC1_CP_TRACER_DDR_INTD (0x0000004d)
#define CSL_INTC1_CP_TRACER_MSMC_0_INTD (0x0000004e)
#define CSL_INTC1_CP_TRACER_MSMC_1_INTD (0x0000004f)
#define CSL_INTC1_CP_TRACER_MSMC_2_INTD (0x00000050)
#define CSL_INTC1_CP_TRACER_MSMC_3_INTD (0x00000051)
#define CSL_INTC1_CP_TRACER_CFG_INTD (0x00000052)
#define CSL_INTC1_CP_TRACER_QM_SS_CFG_INTD (0x00000053)
#define CSL_INTC1_CP_TRACER_QM_SS_DMA_INTD (0x00000054)
#define CSL_INTC1_CP_TRACER_SEM_INTD (0x00000055)
#define CSL_INTC1_PSC_ALLINT         (0x00000056)
#define CSL_INTC1_MSMC_SCRUB_CERROR  (0x00000057)
#define CSL_INTC1_BOOTCFG_INTD       (0x00000058)
#define CSL_INTC1_PO_VCON_SMPSERR_INTR (0x00000059)
#define CSL_INTC1_MPU0_INTD          (0x0000005a)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_19 (0x0000005b)
#define CSL_INTC1_MPU1_INTD          (0x0000005c)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_20 (0x0000005d)
#define CSL_INTC1_MPU2_INTD          (0x0000005e)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_21 (0x0000005f)
#define CSL_INTC1_MPU3_INTD          (0x00000060)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_22 (0x00000061)
#define CSL_INTC1_MSMC_DEDC_CERROR   (0x00000062)
#define CSL_INTC1_MSMC_DEDC_NC_ERROR (0x00000063)
#define CSL_INTC1_MSMC_SCRUB_NC_ERROR (0x00000064)
#define CSL_INTC1_MSMC_MPAX_ADDR_ERROR (0x00000065)
#define CSL_INTC1_MSMC_MPF_ERROR8    (0x00000066)
#define CSL_INTC1_MSMC_MPF_ERROR9    (0x00000067)
#define CSL_INTC1_MSMC_MPF_ERROR10   (0x00000068)
#define CSL_INTC1_MSMC_MPF_ERROR11   (0x00000069)
#define CSL_INTC1_MSMC_MPF_ERROR12   (0x0000006a)
#define CSL_INTC1_MSMC_MPF_ERROR13   (0x0000006b)
#define CSL_INTC1_MSMC_MPF_ERROR14   (0x0000006c)
#define CSL_INTC1_MSMC_MPF_ERROR15   (0x0000006d)
#define CSL_INTC1_DDR3_ERR           (0x0000006e)
#define CSL_INTC1_VUSR_INT_O         (0x0000006f)
#define CSL_INTC1_INTDST0            (0x00000070)
#define CSL_INTC1_INTDST1            (0x00000071)
#define CSL_INTC1_INTDST2            (0x00000072)
#define CSL_INTC1_INTDST3            (0x00000073)
#define CSL_INTC1_INTDST4            (0x00000074)
#define CSL_INTC1_INTDST5            (0x00000075)
#define CSL_INTC1_INTDST6            (0x00000076)
#define CSL_INTC1_INTDST7            (0x00000077)
#define CSL_INTC1_INTDST8            (0x00000078)
#define CSL_INTC1_INTDST9            (0x00000079)
#define CSL_INTC1_INTDST10           (0x0000007a)
#define CSL_INTC1_INTDST11           (0x0000007b)
#define CSL_INTC1_INTDST12           (0x0000007c)
#define CSL_INTC1_INTDST13           (0x0000007d)
#define CSL_INTC1_INTDST14           (0x0000007e)
#define CSL_INTC1_INTDST15           (0x0000007f)
#define CSL_INTC1_EASYNCERR          (0x00000080)
#define CSL_INTC1_CP_TRACER_CORE_4_INTD (0x00000081)
#define CSL_INTC1_CP_TRACER_CORE_5_INTD (0x00000082)
#define CSL_INTC1_CP_TRACER_CORE_6_INTD (0x00000083)
#define CSL_INTC1_CP_TRACER_CORE_7_INTD (0x00000084)
#define CSL_INTC1_QM_INT_CDMA_0      (0x00000085)
#define CSL_INTC1_QM_INT_CDMA_1      (0x00000086)
#define CSL_INTC1_RAPIDIO_INT_CDMA_0 (0x00000087)
#define CSL_INTC1_PASS_INT_CDMA_0    (0x00000088)
#define CSL_INTC1_SMARTREFLEX_INTRREQ0 (0x00000089)
#define CSL_INTC1_SMARTREFLEX_INTRREQ1 (0x0000008a)
#define CSL_INTC1_SMARTREFLEX_INTRREQ2 (0x0000008b)
#define CSL_INTC1_SMARTREFLEX_INTRREQ3 (0x0000008c)
#define CSL_INTC1_VPNOSMPSACK        (0x0000008d)
#define CSL_INTC1_VPEQVALUE          (0x0000008e)
#define CSL_INTC1_VPMAXVDD           (0x0000008f)
#define CSL_INTC1_VPMINVDD           (0x00000090)
#define CSL_INTC1_VPINIDLE           (0x00000091)
#define CSL_INTC1_VPOPPCHANGEDONE    (0x00000092)
#define CSL_INTC1_DFT_PBIST_CPU_INT  (0x00000093)
#define CSL_INTC1_UARTINT            (0x00000094)
#define CSL_INTC1_URXEVT             (0x00000095)
#define CSL_INTC1_UTXEVT             (0x00000096)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_23 (0x00000097)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_24 (0x00000098)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_25 (0x00000099)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_26 (0x0000009a)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_27 (0x0000009b)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_28 (0x0000009c)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_29 (0x0000009d)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_30 (0x0000009e)
#define CSL_INTC1_QM_INT_PASS_TXQ_PEND_31 (0x0000009f)


/**************************************************************************
* CHIP LEVEL INTC2 EVENT INPUT
**************************************************************************/

#define INTC2_EVENT_CNT                 160


/**************************************************************************
* CHIP LEVEL INTC2 EVENT DEFINITION
**************************************************************************/
#define CSL_INTC2_GPINT8             (0x00000000)
#define CSL_INTC2_GPINT9             (0x00000001)
#define CSL_INTC2_GPINT10            (0x00000002)
#define CSL_INTC2_GPINT11            (0x00000003)
#define CSL_INTC2_GPINT12            (0x00000004)
#define CSL_INTC2_GPINT13            (0x00000005)
#define CSL_INTC2_GPINT14            (0x00000006)
#define CSL_INTC2_GPINT15            (0x00000007)
#define CSL_INTC2_TETBHFULLINT       (0x00000008)
#define CSL_INTC2_TETBFULLINT        (0x00000009)
#define CSL_INTC2_TETBACQINT         (0x0000000a)
#define CSL_INTC2_TETBHFULLINT0      (0x0000000b)
#define CSL_INTC2_TETBFULLINT0       (0x0000000c)
#define CSL_INTC2_TETBACQINT0        (0x0000000d)
#define CSL_INTC2_TETBHFULLINT1      (0x0000000e)
#define CSL_INTC2_TETBFULLINT1       (0x0000000f)
#define CSL_INTC2_TETBACQINT1        (0x00000010)
#define CSL_INTC2_TETBHFULLINT2      (0x00000011)
#define CSL_INTC2_TETBFULLINT2       (0x00000012)
#define CSL_INTC2_TETBACQINT2        (0x00000013)
#define CSL_INTC2_TETBHFULLINT3      (0x00000014)
#define CSL_INTC2_TETBFULLINT3       (0x00000015)
#define CSL_INTC2_TETBACQINT3        (0x00000016)
#define CSL_INTC2_DFT_PBIST_CPU_INT  (0x00000017)
#define CSL_INTC2_QM_INT_HIGH_16     (0x00000018)
#define CSL_INTC2_QM_INT_HIGH_17     (0x00000019)
#define CSL_INTC2_QM_INT_HIGH_18     (0x0000001a)
#define CSL_INTC2_QM_INT_HIGH_19     (0x0000001b)
#define CSL_INTC2_QM_INT_HIGH_20     (0x0000001c)
#define CSL_INTC2_QM_INT_HIGH_21     (0x0000001d)
#define CSL_INTC2_QM_INT_HIGH_22     (0x0000001e)
#define CSL_INTC2_QM_INT_HIGH_23     (0x0000001f)
#define CSL_INTC2_QM_INT_HIGH_24     (0x00000020)
#define CSL_INTC2_QM_INT_HIGH_25     (0x00000021)
#define CSL_INTC2_QM_INT_HIGH_26     (0x00000022)
#define CSL_INTC2_QM_INT_HIGH_27     (0x00000023)
#define CSL_INTC2_QM_INT_HIGH_28     (0x00000024)
#define CSL_INTC2_QM_INT_HIGH_29     (0x00000025)
#define CSL_INTC2_QM_INT_HIGH_30     (0x00000026)
#define CSL_INTC2_QM_INT_HIGH_31     (0x00000027)
#define CSL_INTC2_MDIO_LINK_INTR0    (0x00000028)
#define CSL_INTC2_MDIO_LINK_INTR1    (0x00000029)
#define CSL_INTC2_MDIO_USER_INTR0    (0x0000002a)
#define CSL_INTC2_MDIO_USER_INTR1    (0x0000002b)
#define CSL_INTC2_MISC_INTR          (0x0000002c)
#define CSL_INTC2_CP_TRACER_CORE_0_INTD (0x0000002d)
#define CSL_INTC2_CP_TRACER_CORE_1_INTD (0x0000002e)
#define CSL_INTC2_CP_TRACER_CORE_2_INTD (0x0000002f)
#define CSL_INTC2_CP_TRACER_CORE_3_INTD (0x00000030)
#define CSL_INTC2_CP_TRACER_DDR_INTD (0x00000031)
#define CSL_INTC2_CP_TRACER_MSMC_0_INTD (0x00000032)
#define CSL_INTC2_CP_TRACER_MSMC_1_INTD (0x00000033)
#define CSL_INTC2_CP_TRACER_MSMC_2_INTD (0x00000034)
#define CSL_INTC2_CP_TRACER_MSMC_3_INTD (0x00000035)
#define CSL_INTC2_CP_TRACER_CFG_INTD (0x00000036)
#define CSL_INTC2_CP_TRACER_QM_SS_CFG_INTD (0x00000037)
#define CSL_INTC2_CP_TRACER_QM_SS_DMA_INTD (0x00000038)
#define CSL_INTC2_CP_TRACER_SEM_INTD (0x00000039)
#define CSL_INTC2_SEMERR0            (0x0000003a)
#define CSL_INTC2_SEMERR1            (0x0000003b)
#define CSL_INTC2_SEMERR2            (0x0000003c)
#define CSL_INTC2_SEMERR3            (0x0000003d)
#define CSL_INTC2_BOOTCFG_INTD       (0x0000003e)
#define CSL_INTC2_PASS_INT_CDMA_0    (0x0000003f)
#define CSL_INTC2_MPU0_INTD          (0x00000040)
#define CSL_INTC2_MSMC_SCRUB_CERROR (0x00000041)
#define CSL_INTC2_MPU1_INTD          (0x00000042)
#define CSL_INTC2_RAPIDIO_INT_CDMA_0 (0x00000043)
#define CSL_INTC2_MPU2_INTD          (0x00000044)
#define CSL_INTC2_QM_INT_CDMA_0      (0x00000045)
#define CSL_INTC2_MPU3_INTD          (0x00000046)
#define CSL_INTC2_QM_INT_CDMA_1      (0x00000047)
#define CSL_INTC2_MSMC_DEDC_CERROR   (0x00000048)
#define CSL_INTC2_MSMC_DEDC_NC_ERROR (0x00000049)
#define CSL_INTC2_MSMC_SCRUB_NC_ERROR (0x0000004a)
#define CSL_INTC2_MSMC_MPAX_ADDR_ERROR (0x0000004b)
#define CSL_INTC2_MSMC_MPF_ERROR0    (0x0000004c)
#define CSL_INTC2_MSMC_MPF_ERROR1    (0x0000004d)
#define CSL_INTC2_MSMC_MPF_ERROR2    (0x0000004e)
#define CSL_INTC2_MSMC_MPF_ERROR3    (0x0000004f)
#define CSL_INTC2_MSMC_MPF_ERROR4    (0x00000050)
#define CSL_INTC2_MSMC_MPF_ERROR5    (0x00000051)
#define CSL_INTC2_MSMC_MPF_ERROR6    (0x00000052)
#define CSL_INTC2_MSMC_MPF_ERROR7    (0x00000053)
#define CSL_INTC2_MSMC_MPF_ERROR8    (0x00000054)
#define CSL_INTC2_MSMC_MPF_ERROR9    (0x00000055)
#define CSL_INTC2_MSMC_MPF_ERROR10   (0x00000056)
#define CSL_INTC2_MSMC_MPF_ERROR11   (0x00000057)
#define CSL_INTC2_MSMC_MPF_ERROR12   (0x00000058)
#define CSL_INTC2_MSMC_MPF_ERROR13   (0x00000059)
#define CSL_INTC2_MSMC_MPF_ERROR14   (0x0000005a)
#define CSL_INTC2_MSMC_MPF_ERROR15   (0x0000005b)
#define CSL_INTC2_RESERVED_1         (0x0000005c)
#define CSL_INTC2_INTDST0            (0x0000005d)
#define CSL_INTC2_INTDST1            (0x0000005e)
#define CSL_INTC2_INTDST2            (0x0000005f)
#define CSL_INTC2_INTDST3            (0x00000060)
#define CSL_INTC2_INTDST4            (0x00000061)
#define CSL_INTC2_INTDST5            (0x00000062)
#define CSL_INTC2_INTDST6            (0x00000063)
#define CSL_INTC2_INTDST7            (0x00000064)
#define CSL_INTC2_INTDST8            (0x00000065)
#define CSL_INTC2_INTDST9            (0x00000066)
#define CSL_INTC2_INTDST10           (0x00000067)
#define CSL_INTC2_INTDST11           (0x00000068)
#define CSL_INTC2_INTDST12           (0x00000069)
#define CSL_INTC2_INTDST13           (0x0000006a)
#define CSL_INTC2_INTDST14           (0x0000006b)
#define CSL_INTC2_INTDST15           (0x0000006c)
#define CSL_INTC2_INTDST16           (0x0000006d)
#define CSL_INTC2_INTDST17           (0x0000006e)
#define CSL_INTC2_INTDST18           (0x0000006f)
#define CSL_INTC2_INTDST19           (0x00000070)
#define CSL_INTC2_INTDST20           (0x00000071)
#define CSL_INTC2_INTDST21           (0x00000072)
#define CSL_INTC2_INTDST22           (0x00000073)
#define CSL_INTC2_INTDST23           (0x00000074)
#define CSL_INTC2_EASYNCERR          (0x00000075)
#define CSL_INTC2_TETBHFULLINT4      (0x00000076)
#define CSL_INTC2_TETBFULLINT4       (0x00000077)
#define CSL_INTC2_TETBACQINT4        (0x00000078)
#define CSL_INTC2_TETBHFULLINT5      (0x00000079)
#define CSL_INTC2_TETBFULLINT5       (0x0000007a)
#define CSL_INTC2_TETBACQINT5        (0x0000007b)
#define CSL_INTC2_TETBHFULLINT6      (0x0000007c)
#define CSL_INTC2_TETBFULLINT6       (0x0000007d)
#define CSL_INTC2_TETBACQINT6        (0x0000007e)
#define CSL_INTC2_TETBHFULLINT7      (0x0000007f)
#define CSL_INTC2_TETBFULLINT7       (0x00000080)
#define CSL_INTC2_TETBACQINT7        (0x00000081)
#define CSL_INTC2_CP_TRACER_CORE_4_INTD (0x00000082)
#define CSL_INTC2_CP_TRACER_CORE_5_INTD (0x00000083)
#define CSL_INTC2_CP_TRACER_CORE_6_INTD (0x00000084)
#define CSL_INTC2_CP_TRACER_CORE_7_INTD (0x00000085)
#define CSL_INTC2_SEMERR4            (0x00000086)
#define CSL_INTC2_SEMERR5            (0x00000087)
#define CSL_INTC2_SEMERR6            (0x00000088)
#define CSL_INTC2_SEMERR7            (0x00000089)
#define CSL_INTC2_QM_INT_HIGH_0      (0x0000008a)
#define CSL_INTC2_QM_INT_HIGH_1      (0x0000008b)
#define CSL_INTC2_QM_INT_HIGH_2      (0x0000008c)
#define CSL_INTC2_QM_INT_HIGH_3      (0x0000008d)
#define CSL_INTC2_QM_INT_HIGH_4      (0x0000008e)
#define CSL_INTC2_QM_INT_HIGH_5      (0x0000008f)
#define CSL_INTC2_QM_INT_HIGH_6      (0x00000090)
#define CSL_INTC2_QM_INT_HIGH_7      (0x00000091)
#define CSL_INTC2_QM_INT_HIGH_8      (0x00000092)
#define CSL_INTC2_QM_INT_HIGH_9      (0x00000093)
#define CSL_INTC2_QM_INT_HIGH_10     (0x00000094)
#define CSL_INTC2_QM_INT_HIGH_11     (0x00000095)
#define CSL_INTC2_QM_INT_HIGH_12     (0x00000096)
#define CSL_INTC2_QM_INT_HIGH_13     (0x00000097)
#define CSL_INTC2_QM_INT_HIGH_14     (0x00000098)
#define CSL_INTC2_QM_INT_HIGH_15     (0x00000099)
#define CSL_INTC2_RESERVED_2         (0x0000009a)
#define CSL_INTC2_RESERVED_3         (0x0000009b)
#define CSL_INTC2_RESERVED_4         (0x0000009c)
#define CSL_INTC2_RESERVED_5         (0x0000009d)
#define CSL_INTC2_RESERVED_6         (0x0000009e)
#define CSL_INTC2_RESERVED_7         (0x0000009f)

/**************************************************************************
* CHIP LEVEL INTC3 EVENT INPUT
**************************************************************************/

#define INTC3_EVENT_CNT                 80


/**************************************************************************
* CHIP LEVEL INTC3 EVENT DEFINITION
**************************************************************************/
#define CSL_INTC3_GPINT0             (0x00000000)
#define CSL_INTC3_GPINT1             (0x00000001)
#define CSL_INTC3_GPINT2             (0x00000002)
#define CSL_INTC3_GPINT3             (0x00000003)
#define CSL_INTC3_GPINT4             (0x00000004)
#define CSL_INTC3_GPINT5             (0x00000005)
#define CSL_INTC3_GPINT6             (0x00000006)
#define CSL_INTC3_GPINT7             (0x00000007)
#define CSL_INTC3_GPINT8             (0x00000008)
#define CSL_INTC3_GPINT9             (0x00000009)
#define CSL_INTC3_GPINT10            (0x0000000a)
#define CSL_INTC3_GPINT11            (0x0000000b)
#define CSL_INTC3_GPINT12            (0x0000000c)
#define CSL_INTC3_GPINT13            (0x0000000d)
#define CSL_INTC3_GPINT14            (0x0000000e)
#define CSL_INTC3_GPINT15            (0x0000000f)
#define CSL_INTC3_TETBHFULLINT       (0x00000010)
#define CSL_INTC3_TETBFULLINT        (0x00000011)
#define CSL_INTC3_TETBACQINT         (0x00000012)
#define CSL_INTC3_TETBHFULLINT0      (0x00000013)
#define CSL_INTC3_TETBFULLINT0       (0x00000014)
#define CSL_INTC3_TETBACQINT0        (0x00000015)
#define CSL_INTC3_TETBHFULLINT1      (0x00000016)
#define CSL_INTC3_TETBFULLINT1       (0x00000017)
#define CSL_INTC3_TETBACQINT1        (0x00000018)
#define CSL_INTC3_TETBHFULLINT2      (0x00000019)
#define CSL_INTC3_TETBFULLINT2       (0x0000001a)
#define CSL_INTC3_TETBACQINT2        (0x0000001b)
#define CSL_INTC3_TETBHFULLINT3      (0x0000001c)
#define CSL_INTC3_TETBFULLINT3       (0x0000001d)
#define CSL_INTC3_TETBACQINT3        (0x0000001e)
#define CSL_INTC3_CP_TRACER_CORE_0_INTD (0x0000001f)
#define CSL_INTC3_CP_TRACER_CORE_1_INTD (0x00000020)
#define CSL_INTC3_CP_TRACER_CORE_2_INTD (0x00000021)
#define CSL_INTC3_CP_TRACER_CORE_3_INTD (0x00000022)
#define CSL_INTC3_CP_TRACER_DDR_INTD (0x00000023)
#define CSL_INTC3_CP_TRACER_MSMC_0_INTD (0x00000024)
#define CSL_INTC3_CP_TRACER_MSMC_1_INTD (0x00000025)
#define CSL_INTC3_CP_TRACER_MSMC_2_INTD (0x00000026)
#define CSL_INTC3_CP_TRACER_MSMC_3_INTD (0x00000027)
#define CSL_INTC3_CP_TRACER_CFG_INTD (0x00000028)
#define CSL_INTC3_CP_TRACER_QM_SS_CFG_INTD (0x00000029)
#define CSL_INTC3_CP_TRACER_QM_SS_DMA_INTD (0x0000002a)
#define CSL_INTC3_CP_TRACER_SEM_INTD (0x0000002b)
#define CSL_INTC3_VUSR_INT_O         (0x0000002c)
#define CSL_INTC3_TETBHFULLINT4      (0x0000002d)
#define CSL_INTC3_TETBFULLINT4       (0x0000002e)
#define CSL_INTC3_TETBACQINT4        (0x0000002f)
#define CSL_INTC3_TETBHFULLINT5      (0x00000030)
#define CSL_INTC3_TETBFULLINT5       (0x00000031)
#define CSL_INTC3_TETBACQINT5        (0x00000032)
#define CSL_INTC3_TETBHFULLINT6      (0x00000033)
#define CSL_INTC3_TETBFULLINT6       (0x00000034)
#define CSL_INTC3_TETBACQINT6        (0x00000035)
#define CSL_INTC3_TETBHFULLINT7      (0x00000036)
#define CSL_INTC3_TETBFULLINT7       (0x00000037)
#define CSL_INTC3_TETBACQINT7        (0x00000038)
#define CSL_INTC3_CP_TRACER_CORE_4_INTD (0x00000039)
#define CSL_INTC3_CP_TRACER_CORE_5_INTD (0x0000003a)
#define CSL_INTC3_CP_TRACER_CORE_6_INTD (0x0000003b)
#define CSL_INTC3_CP_TRACER_CORE_7_INTD (0x0000003c)
#define CSL_INTC3_DDR3_ERR           (0x0000003d)
#define CSL_INTC3_PO_VP_SMPSACK_INTR (0x0000003e)
#define CSL_INTC3_RESERVED_1         (0x0000003f)
#define CSL_INTC3_RESERVED_2         (0x00000040)
#define CSL_INTC3_RESERVED_3         (0x00000041)
#define CSL_INTC3_RESERVED_4         (0x00000042)
#define CSL_INTC3_RESERVED_5         (0x00000043)
#define CSL_INTC3_RESERVED_6         (0x00000044)
#define CSL_INTC3_RESERVED_7         (0x00000045)
#define CSL_INTC3_RESERVED_8         (0x00000046)
#define CSL_INTC3_RESERVED_9         (0x00000047)
#define CSL_INTC3_RESERVED_10        (0x00000048)
#define CSL_INTC3_RESERVED_11        (0x00000049)
#define CSL_INTC3_RESERVED_12        (0x0000004a)
#define CSL_INTC3_RESERVED_13        (0x0000004b)
#define CSL_INTC3_RESERVED_14        (0x0000004c)
#define CSL_INTC3_RESERVED_15        (0x0000004d)
#define CSL_INTC3_RESERVED_16        (0x0000004e)
#define CSL_INTC3_RESERVED_17        (0x0000004f)

/**************************************************************************
* TPCC0 (CPU_2) EVENT INPUT
**************************************************************************/

#define TPCC0_EVENT_CNT                 16

/**************************************************************************
* EDMA3CC0 (CPU/2) EVENT INPUT
**************************************************************************/

#define EDMA3CC0_EVENT_CNT              16

/**************************************************************************
* TPCC0 (CPU_2) EVENT DEFINITION
**************************************************************************/
#define CSL_TPCC0_TINT8L            (0x00000000)
#define CSL_TPCC0_TINT8H            (0x00000001)
#define CSL_TPCC0_TINT9L            (0x00000002)
#define CSL_TPCC0_TINT9H            (0x00000003)
#define CSL_TPCC0_TINT10L           (0x00000004)
#define CSL_TPCC0_TINT10H           (0x00000005)
#define CSL_TPCC0_TINT11L           (0x00000006)
#define CSL_TPCC0_TINT11H           (0x00000007)
#define CSL_TPCC0_INTC3_OUT0        (0x00000008)
#define CSL_TPCC0_INTC3_OUT1        (0x00000009)
#define CSL_TPCC0_INTC3_OUT2        (0x0000000a)
#define CSL_TPCC0_INTC3_OUT3        (0x0000000b)
#define CSL_TPCC0_INTC3_OUT4        (0x0000000c)
#define CSL_TPCC0_INTC3_OUT5        (0x0000000d)
#define CSL_TPCC0_INTC3_OUT6        (0x0000000e)
#define CSL_TPCC0_INTC3_OUT7        (0x0000000f)

/**************************************************************************
* EDMA3CC0 (CPU_2) EVENT DEFINITION
**************************************************************************/
#define CSL_EDMA3CC0_TINT8L            (0x00000000)
#define CSL_EDMA3CC0_TINT8H            (0x00000001)
#define CSL_EDMA3CC0_TINT9L            (0x00000002)
#define CSL_EDMA3CC0_TINT9H            (0x00000003)
#define CSL_EDMA3CC0_TINT10L           (0x00000004)
#define CSL_EDMA3CC0_TINT10H           (0x00000005)
#define CSL_EDMA3CC0_TINT11L           (0x00000006)
#define CSL_EDMA3CC0_TINT11H           (0x00000007)
#define CSL_EDMA3CC0_INTC3_OUT0        (0x00000008)
#define CSL_EDMA3CC0_INTC3_OUT1        (0x00000009)
#define CSL_EDMA3CC0_INTC3_OUT2        (0x0000000a)
#define CSL_EDMA3CC0_INTC3_OUT3        (0x0000000b)
#define CSL_EDMA3CC0_INTC3_OUT4        (0x0000000c)
#define CSL_EDMA3CC0_INTC3_OUT5        (0x0000000d)
#define CSL_EDMA3CC0_INTC3_OUT6        (0x0000000e)
#define CSL_EDMA3CC0_INTC3_OUT7        (0x0000000f)

/**************************************************************************
* TPCC1 (CPU_3) EVENT INPUT
**************************************************************************/

#define TPCC1_EVENT_CNT                 64


/**************************************************************************
* TPCC1 (CPU_3) EVENT DEFINITION
**************************************************************************/
#define CSL_TPCC1_SPIINT0           (0x00000000)
#define CSL_TPCC1_SPIINT1           (0x00000001)
#define CSL_TPCC1_SPIXEVT           (0x00000002)
#define CSL_TPCC1_SPIREVT           (0x00000003)
#define CSL_TPCC1_I2CREVT           (0x00000004)
#define CSL_TPCC1_I2CXEVT           (0x00000005)
#define CSL_TPCC1_GPINT0            (0x00000006)
#define CSL_TPCC1_GPINT1            (0x00000007)
#define CSL_TPCC1_GPINT2            (0x00000008)
#define CSL_TPCC1_GPINT3            (0x00000009)
#define CSL_TPCC1_GPINT4            (0x0000000a)
#define CSL_TPCC1_GPINT5            (0x0000000b)
#define CSL_TPCC1_GPINT6            (0x0000000c)
#define CSL_TPCC1_GPINT7            (0x0000000d)
#define CSL_TPCC1_SEMINT0           (0x0000000e)
#define CSL_TPCC1_SEMINT1           (0x0000000f)
#define CSL_TPCC1_SEMINT2           (0x00000010)
#define CSL_TPCC1_SEMINT3           (0x00000011)
#define CSL_TPCC1_SEMINT4           (0x00000012)
#define CSL_TPCC1_SEMINT5           (0x00000013)
#define CSL_TPCC1_SEMINT6           (0x00000014)
#define CSL_TPCC1_SEMINT7           (0x00000015)
#define CSL_TPCC1_TINT8L            (0x00000016)
#define CSL_TPCC1_TINT8H            (0x00000017)
#define CSL_TPCC1_TINT9L            (0x00000018)
#define CSL_TPCC1_TINT9H            (0x00000019)
#define CSL_TPCC1_TINT10L           (0x0000001a)
#define CSL_TPCC1_TINT10H           (0x0000001b)
#define CSL_TPCC1_TINT11L           (0x0000001c)
#define CSL_TPCC1_TINT11H           (0x0000001d)
#define CSL_TPCC1_TINT12L           (0x0000001e)
#define CSL_TPCC1_TINT12H           (0x0000001f)
#define CSL_TPCC1_TINT13L           (0x00000020)
#define CSL_TPCC1_TINT13H           (0x00000021)
#define CSL_TPCC1_TINT14L           (0x00000022)
#define CSL_TPCC1_TINT14H           (0x00000023)
#define CSL_TPCC1_TINT15L           (0x00000024)
#define CSL_TPCC1_TINT15H           (0x00000025)
#define CSL_TPCC1_INTC2_OUT44       (0x00000026)
#define CSL_TPCC1_INTC2_OUT45       (0x00000027)
#define CSL_TPCC1_INTC2_OUT46       (0x00000028)
#define CSL_TPCC1_INTC2_OUT47       (0x00000029)
#define CSL_TPCC1_INTC2_OUT0        (0x0000002a)
#define CSL_TPCC1_INTC2_OUT1        (0x0000002b)
#define CSL_TPCC1_INTC2_OUT2        (0x0000002c)
#define CSL_TPCC1_INTC2_OUT3        (0x0000002d)
#define CSL_TPCC1_INTC2_OUT4        (0x0000002e)
#define CSL_TPCC1_INTC2_OUT5        (0x0000002f)
#define CSL_TPCC1_INTC2_OUT6        (0x00000030)
#define CSL_TPCC1_INTC2_OUT7        (0x00000031)
#define CSL_TPCC1_INTC2_OUT8        (0x00000032)
#define CSL_TPCC1_INTC2_OUT9        (0x00000033)
#define CSL_TPCC1_INTC2_OUT10       (0x00000034)
#define CSL_TPCC1_INTC2_OUT11       (0x00000035)
#define CSL_TPCC1_INTC2_OUT12       (0x00000036)
#define CSL_TPCC1_INTC2_OUT13       (0x00000037)
#define CSL_TPCC1_INTC2_OUT14       (0x00000038)
#define CSL_TPCC1_INTC2_OUT15       (0x00000039)
#define CSL_TPCC1_INTC2_OUT16       (0x0000003a)
#define CSL_TPCC1_INTC2_OUT17       (0x0000003b)
#define CSL_TPCC1_INTC2_OUT18       (0x0000003c)
#define CSL_TPCC1_INTC2_OUT19       (0x0000003d)
#define CSL_TPCC1_INTC2_OUT20       (0x0000003e)
#define CSL_TPCC1_INTC2_OUT21       (0x0000003f)

/* Same as above - name changed to match data manuals */
/**************************************************************************
* EDMA3CC1 (CPU/3) EVENT INPUT
**************************************************************************/

#define EDMA3CC1_EVENT_CNT                 64

/**************************************************************************
* EDMA3CC1 (CPU_3) EVENT DEFINITION
**************************************************************************/
#define CSL_EDMA3CC1_SPIINT0           (0x00000000)
#define CSL_EDMA3CC1_SPIINT1           (0x00000001)
#define CSL_EDMA3CC1_SPIXEVT           (0x00000002)
#define CSL_EDMA3CC1_SPIREVT           (0x00000003)
#define CSL_EDMA3CC1_I2CREVT           (0x00000004)
#define CSL_EDMA3CC1_I2CXEVT           (0x00000005)
#define CSL_EDMA3CC1_GPINT0            (0x00000006)
#define CSL_EDMA3CC1_GPINT1            (0x00000007)
#define CSL_EDMA3CC1_GPINT2            (0x00000008)
#define CSL_EDMA3CC1_GPINT3            (0x00000009)
#define CSL_EDMA3CC1_GPINT4            (0x0000000a)
#define CSL_EDMA3CC1_GPINT5            (0x0000000b)
#define CSL_EDMA3CC1_GPINT6            (0x0000000c)
#define CSL_EDMA3CC1_GPINT7            (0x0000000d)
#define CSL_EDMA3CC1_SEMINT0           (0x0000000e)
#define CSL_EDMA3CC1_SEMINT1           (0x0000000f)
#define CSL_EDMA3CC1_SEMINT2           (0x00000010)
#define CSL_EDMA3CC1_SEMINT3           (0x00000011)
#define CSL_EDMA3CC1_SEMINT4           (0x00000012)
#define CSL_EDMA3CC1_SEMINT5           (0x00000013)
#define CSL_EDMA3CC1_SEMINT6           (0x00000014)
#define CSL_EDMA3CC1_SEMINT7           (0x00000015)
#define CSL_EDMA3CC1_TINT8L            (0x00000016)
#define CSL_EDMA3CC1_TINT8H            (0x00000017)
#define CSL_EDMA3CC1_TINT9L            (0x00000018)
#define CSL_EDMA3CC1_TINT9H            (0x00000019)
#define CSL_EDMA3CC1_TINT10L           (0x0000001a)
#define CSL_EDMA3CC1_TINT10H           (0x0000001b)
#define CSL_EDMA3CC1_TINT11L           (0x0000001c)
#define CSL_EDMA3CC1_TINT11H           (0x0000001d)
#define CSL_EDMA3CC1_TINT12L           (0x0000001e)
#define CSL_EDMA3CC1_TINT12H           (0x0000001f)
#define CSL_EDMA3CC1_TINT13L           (0x00000020)
#define CSL_EDMA3CC1_TINT13H           (0x00000021)
#define CSL_EDMA3CC1_TINT14L           (0x00000022)
#define CSL_EDMA3CC1_TINT14H           (0x00000023)
#define CSL_EDMA3CC1_TINT15L           (0x00000024)
#define CSL_EDMA3CC1_TINT15H           (0x00000025)
#define CSL_EDMA3CC1_INTC2_OUT44       (0x00000026)
#define CSL_EDMA3CC1_INTC2_OUT45       (0x00000027)
#define CSL_EDMA3CC1_INTC2_OUT46       (0x00000028)
#define CSL_EDMA3CC1_INTC2_OUT47       (0x00000029)
#define CSL_EDMA3CC1_INTC2_OUT0        (0x0000002a)
#define CSL_EDMA3CC1_INTC2_OUT1        (0x0000002b)
#define CSL_EDMA3CC1_INTC2_OUT2        (0x0000002c)
#define CSL_EDMA3CC1_INTC2_OUT3        (0x0000002d)
#define CSL_EDMA3CC1_INTC2_OUT4        (0x0000002e)
#define CSL_EDMA3CC1_INTC2_OUT5        (0x0000002f)
#define CSL_EDMA3CC1_INTC2_OUT6        (0x00000030)
#define CSL_EDMA3CC1_INTC2_OUT7        (0x00000031)
#define CSL_EDMA3CC1_INTC2_OUT8        (0x00000032)
#define CSL_EDMA3CC1_INTC2_OUT9        (0x00000033)
#define CSL_EDMA3CC1_INTC2_OUT10       (0x00000034)
#define CSL_EDMA3CC1_INTC2_OUT11       (0x00000035)
#define CSL_EDMA3CC1_INTC2_OUT12       (0x00000036)
#define CSL_EDMA3CC1_INTC2_OUT13       (0x00000037)
#define CSL_EDMA3CC1_INTC2_OUT14       (0x00000038)
#define CSL_EDMA3CC1_INTC2_OUT15       (0x00000039)
#define CSL_EDMA3CC1_INTC2_OUT16       (0x0000003a)
#define CSL_EDMA3CC1_INTC2_OUT17       (0x0000003b)
#define CSL_EDMA3CC1_INTC2_OUT18       (0x0000003c)
#define CSL_EDMA3CC1_INTC2_OUT19       (0x0000003d)
#define CSL_EDMA3CC1_INTC2_OUT20       (0x0000003e)
#define CSL_EDMA3CC1_INTC2_OUT21       (0x0000003f)


/**************************************************************************
* TPCC2 (CPU_3) EVENT INPUT
**************************************************************************/

#define TPCC2_EVENT_CNT                 64


/**************************************************************************
* TPCC2 (CPU_3) EVENT DEFINITION
**************************************************************************/
#define CSL_TPCC2_SPIINT0           (0x00000000)
#define CSL_TPCC2_SPIINT1           (0x00000001)
#define CSL_TPCC2_SPIXEVT           (0x00000002)
#define CSL_TPCC2_SPIREVT           (0x00000003)
#define CSL_TPCC2_I2CREVT           (0x00000004)
#define CSL_TPCC2_I2CXEVT           (0x00000005)
#define CSL_TPCC2_GPINT0            (0x00000006)
#define CSL_TPCC2_GPINT1            (0x00000007)
#define CSL_TPCC2_GPINT2            (0x00000008)
#define CSL_TPCC2_GPINT3            (0x00000009)
#define CSL_TPCC2_GPINT4            (0x0000000a)
#define CSL_TPCC2_GPINT5            (0x0000000b)
#define CSL_TPCC2_GPINT6            (0x0000000c)
#define CSL_TPCC2_GPINT7            (0x0000000d)
#define CSL_TPCC2_SEMINT0           (0x0000000e)
#define CSL_TPCC2_SEMINT1           (0x0000000f)
#define CSL_TPCC2_SEMINT2           (0x00000010)
#define CSL_TPCC2_SEMINT3           (0x00000011)
#define CSL_TPCC2_SEMINT4           (0x00000012)
#define CSL_TPCC2_SEMINT5           (0x00000013)
#define CSL_TPCC2_SEMINT6           (0x00000014)
#define CSL_TPCC2_SEMINT7           (0x00000015)
#define CSL_TPCC2_TINT8L            (0x00000016)
#define CSL_TPCC2_TINT8H            (0x00000017)
#define CSL_TPCC2_TINT9L            (0x00000018)
#define CSL_TPCC2_TINT9H            (0x00000019)
#define CSL_TPCC2_TINT10L           (0x0000001a)
#define CSL_TPCC2_TINT10H           (0x0000001b)
#define CSL_TPCC2_TINT11L           (0x0000001c)
#define CSL_TPCC2_TINT11H           (0x0000001d)
#define CSL_TPCC2_TINT12L           (0x0000001e)
#define CSL_TPCC2_TINT12H           (0x0000001f)
#define CSL_TPCC2_TINT13L           (0x00000020)
#define CSL_TPCC2_TINT13H           (0x00000021)
#define CSL_TPCC2_TINT14L           (0x00000022)
#define CSL_TPCC2_TINT14H           (0x00000023)
#define CSL_TPCC2_TINT15L           (0x00000024)
#define CSL_TPCC2_TINT15H           (0x00000025)
#define CSL_TPCC2_INTC2_OUT48       (0x00000026)
#define CSL_TPCC2_INTC2_OUT49       (0x00000027)
#define CSL_TPCC2_URXEVT            (0x00000028)
#define CSL_TPCC2_UTXEVT            (0x00000029)
#define CSL_TPCC2_INTC2_OUT22       (0x0000002a)
#define CSL_TPCC2_INTC2_OUT23       (0x0000002b)
#define CSL_TPCC2_INTC2_OUT24       (0x0000002c)
#define CSL_TPCC2_INTC2_OUT25       (0x0000002d)
#define CSL_TPCC2_INTC2_OUT26       (0x0000002e)
#define CSL_TPCC2_INTC2_OUT27       (0x0000002f)
#define CSL_TPCC2_INTC2_OUT28       (0x00000030)
#define CSL_TPCC2_INTC2_OUT29       (0x00000031)
#define CSL_TPCC2_INTC2_OUT30       (0x00000032)
#define CSL_TPCC2_INTC2_OUT31       (0x00000033)
#define CSL_TPCC2_INTC2_OUT32       (0x00000034)
#define CSL_TPCC2_INTC2_OUT33       (0x00000035)
#define CSL_TPCC2_INTC2_OUT34       (0x00000036)
#define CSL_TPCC2_INTC2_OUT35       (0x00000037)
#define CSL_TPCC2_INTC2_OUT36       (0x00000038)
#define CSL_TPCC2_INTC2_OUT37       (0x00000039)
#define CSL_TPCC2_INTC2_OUT38       (0x0000003a)
#define CSL_TPCC2_INTC2_OUT39       (0x0000003b)
#define CSL_TPCC2_INTC2_OUT40       (0x0000003c)
#define CSL_TPCC2_INTC2_OUT41       (0x0000003d)
#define CSL_TPCC2_INTC2_OUT42       (0x0000003e)
#define CSL_TPCC2_INTC2_OUT43       (0x0000003f)

/* Same as above - name changed to match data manuals */
/**************************************************************************
* EDMA3CC2 (CPU/3) EVENT INPUT
**************************************************************************/

#define EDMA3CC2_EVENT_CNT                 64

/**************************************************************************
* EDMA3CC2 (CPU_3) EVENT DEFINITION
**************************************************************************/
#define CSL_EDMA3CC2_SPIINT0           (0x00000000)
#define CSL_EDMA3CC2_SPIINT1           (0x00000001)
#define CSL_EDMA3CC2_SPIXEVT           (0x00000002)
#define CSL_EDMA3CC2_SPIREVT           (0x00000003)
#define CSL_EDMA3CC2_I2CREVT           (0x00000004)
#define CSL_EDMA3CC2_I2CXEVT           (0x00000005)
#define CSL_EDMA3CC2_GPINT0            (0x00000006)
#define CSL_EDMA3CC2_GPINT1            (0x00000007)
#define CSL_EDMA3CC2_GPINT2            (0x00000008)
#define CSL_EDMA3CC2_GPINT3            (0x00000009)
#define CSL_EDMA3CC2_GPINT4            (0x0000000a)
#define CSL_EDMA3CC2_GPINT5            (0x0000000b)
#define CSL_EDMA3CC2_GPINT6            (0x0000000c)
#define CSL_EDMA3CC2_GPINT7            (0x0000000d)
#define CSL_EDMA3CC2_SEMINT0           (0x0000000e)
#define CSL_EDMA3CC2_SEMINT1           (0x0000000f)
#define CSL_EDMA3CC2_SEMINT2           (0x00000010)
#define CSL_EDMA3CC2_SEMINT3           (0x00000011)
#define CSL_EDMA3CC2_SEMINT4           (0x00000012)
#define CSL_EDMA3CC2_SEMINT5           (0x00000013)
#define CSL_EDMA3CC2_SEMINT6           (0x00000014)
#define CSL_EDMA3CC2_SEMINT7           (0x00000015)
#define CSL_EDMA3CC2_TINT8L            (0x00000016)
#define CSL_EDMA3CC2_TINT8H            (0x00000017)
#define CSL_EDMA3CC2_TINT9L            (0x00000018)
#define CSL_EDMA3CC2_TINT9H            (0x00000019)
#define CSL_EDMA3CC2_TINT10L           (0x0000001a)
#define CSL_EDMA3CC2_TINT10H           (0x0000001b)
#define CSL_EDMA3CC2_TINT11L           (0x0000001c)
#define CSL_EDMA3CC2_TINT11H           (0x0000001d)
#define CSL_EDMA3CC2_TINT12L           (0x0000001e)
#define CSL_EDMA3CC2_TINT12H           (0x0000001f)
#define CSL_EDMA3CC2_TINT13L           (0x00000020)
#define CSL_EDMA3CC2_TINT13H           (0x00000021)
#define CSL_EDMA3CC2_TINT14L           (0x00000022)
#define CSL_EDMA3CC2_TINT14H           (0x00000023)
#define CSL_EDMA3CC2_TINT15L           (0x00000024)
#define CSL_EDMA3CC2_TINT15H           (0x00000025)
#define CSL_EDMA3CC2_INTC2_OUT48       (0x00000026)
#define CSL_EDMA3CC2_INTC2_OUT49       (0x00000027)
#define CSL_EDMA3CC2_URXEVT            (0x00000028)
#define CSL_EDMA3CC2_UTXEVT            (0x00000029)
#define CSL_EDMA3CC2_INTC2_OUT22       (0x0000002a)
#define CSL_EDMA3CC2_INTC2_OUT23       (0x0000002b)
#define CSL_EDMA3CC2_INTC2_OUT24       (0x0000002c)
#define CSL_EDMA3CC2_INTC2_OUT25       (0x0000002d)
#define CSL_EDMA3CC2_INTC2_OUT26       (0x0000002e)
#define CSL_EDMA3CC2_INTC2_OUT27       (0x0000002f)
#define CSL_EDMA3CC2_INTC2_OUT28       (0x00000030)
#define CSL_EDMA3CC2_INTC2_OUT29       (0x00000031)
#define CSL_EDMA3CC2_INTC2_OUT30       (0x00000032)
#define CSL_EDMA3CC2_INTC2_OUT31       (0x00000033)
#define CSL_EDMA3CC2_INTC2_OUT32       (0x00000034)
#define CSL_EDMA3CC2_INTC2_OUT33       (0x00000035)
#define CSL_EDMA3CC2_INTC2_OUT34       (0x00000036)
#define CSL_EDMA3CC2_INTC2_OUT35       (0x00000037)
#define CSL_EDMA3CC2_INTC2_OUT36       (0x00000038)
#define CSL_EDMA3CC2_INTC2_OUT37       (0x00000039)
#define CSL_EDMA3CC2_INTC2_OUT38       (0x0000003a)
#define CSL_EDMA3CC2_INTC2_OUT39       (0x0000003b)
#define CSL_EDMA3CC2_INTC2_OUT40       (0x0000003c)
#define CSL_EDMA3CC2_INTC2_OUT41       (0x0000003d)
#define CSL_EDMA3CC2_INTC2_OUT42       (0x0000003e)
#define CSL_EDMA3CC2_INTC2_OUT43       (0x0000003f)


/**************************************************************************
* MCM EVENT INPUT
**************************************************************************/

#define CSL_MCM_EVENT_CNT                   64


/**************************************************************************
* MCM EVENT DEFINITION
**************************************************************************/
#define CSL_MCM_INTC3_OUT8          (0x00000000)
#define CSL_MCM_INTC3_OUT9          (0x00000001)
#define CSL_MCM_INTC3_OUT10         (0x00000002)
#define CSL_MCM_INTC3_OUT11         (0x00000003)
#define CSL_MCM_INTC3_OUT12         (0x00000004)
#define CSL_MCM_INTC3_OUT13         (0x00000005)
#define CSL_MCM_INTC3_OUT14         (0x00000006)
#define CSL_MCM_INTC3_OUT15         (0x00000007)
#define CSL_MCM_INTC3_OUT16         (0x00000008)
#define CSL_MCM_INTC3_OUT17         (0x00000009)
#define CSL_MCM_INTC3_OUT18         (0x0000000a)
#define CSL_MCM_INTC3_OUT19         (0x0000000b)
#define CSL_MCM_INTC3_OUT20         (0x0000000c)
#define CSL_MCM_INTC3_OUT21         (0x0000000d)
#define CSL_MCM_INTC3_OUT22         (0x0000000e)
#define CSL_MCM_INTC3_OUT23         (0x0000000f)
#define CSL_MCM_INTC3_OUT24         (0x00000010)
#define CSL_MCM_INTC3_OUT25         (0x00000011)
#define CSL_MCM_INTC3_OUT26         (0x00000012)
#define CSL_MCM_INTC3_OUT27         (0x00000013)
#define CSL_MCM_INTC3_OUT28         (0x00000014)
#define CSL_MCM_INTC3_OUT29         (0x00000015)
#define CSL_MCM_INTC3_OUT30         (0x00000016)
#define CSL_MCM_INTC3_OUT31         (0x00000017)
#define CSL_MCM_INTC3_OUT32         (0x00000018)
#define CSL_MCM_INTC3_OUT33         (0x00000019)
#define CSL_MCM_INTC3_OUT34         (0x0000001a)
#define CSL_MCM_INTC3_OUT35         (0x0000001b)
#define CSL_MCM_INTC3_OUT36         (0x0000001c)
#define CSL_MCM_INTC3_OUT37         (0x0000001d)
#define CSL_MCM_INTC3_OUT38         (0x0000001e)
#define CSL_MCM_INTC3_OUT39         (0x0000001f)
#define CSL_MCM_QUE_PENDING_864     (0x00000020)
#define CSL_MCM_QUE_PENDING_865     (0x00000021)
#define CSL_MCM_QUE_PENDING_866     (0x00000022)
#define CSL_MCM_QUE_PENDING_867     (0x00000023)
#define CSL_MCM_QUE_PENDING_868     (0x00000024)
#define CSL_MCM_QUE_PENDING_869     (0x00000025)
#define CSL_MCM_QUE_PENDING_870     (0x00000026)
#define CSL_MCM_QUE_PENDING_871     (0x00000027)
#define CSL_MCM_QUE_PENDING_872     (0x00000028)
#define CSL_MCM_QUE_PENDING_873     (0x00000029)
#define CSL_MCM_QUE_PENDING_874     (0x0000002a)
#define CSL_MCM_QUE_PENDING_875     (0x0000002b)
#define CSL_MCM_QUE_PENDING_876     (0x0000002c)
#define CSL_MCM_QUE_PENDING_877     (0x0000002d)
#define CSL_MCM_QUE_PENDING_878     (0x0000002e)
#define CSL_MCM_QUE_PENDING_879     (0x0000002f)
#define CSL_MCM_QUE_PENDING_880     (0x00000030)
#define CSL_MCM_QUE_PENDING_881     (0x00000031)
#define CSL_MCM_QUE_PENDING_882     (0x00000032)
#define CSL_MCM_QUE_PENDING_883     (0x00000033)
#define CSL_MCM_QUE_PENDING_884     (0x00000034)
#define CSL_MCM_QUE_PENDING_885     (0x00000035)
#define CSL_MCM_QUE_PENDING_886     (0x00000036)
#define CSL_MCM_QUE_PENDING_887     (0x00000037)
#define CSL_MCM_QUE_PENDING_888     (0x00000038)
#define CSL_MCM_QUE_PENDING_889     (0x00000039)
#define CSL_MCM_QUE_PENDING_890     (0x0000003a)
#define CSL_MCM_QUE_PENDING_891     (0x0000003b)
#define CSL_MCM_QUE_PENDING_892     (0x0000003c)
#define CSL_MCM_QUE_PENDING_893     (0x0000003d)
#define CSL_MCM_QUE_PENDING_894     (0x0000003e)
#define CSL_MCM_QUE_PENDING_895     (0x0000003f)


/**************************************************************************
* GEM EVENT INPUT
**************************************************************************/

#define GEM_EVENT_CNT                   128


/**************************************************************************
* GEM EVENT DEFINITION
**************************************************************************/
#define CSL_GEM_EVT0                 (0x00000000)
#define CSL_GEM_EVT1                 (0x00000001)
#define CSL_GEM_EVT2                 (0x00000002)
#define CSL_GEM_EVT3                 (0x00000003)
#define CSL_GEM_TETBHFULLINTN        (0x00000004)
#define CSL_GEM_TETBFULLINTN         (0x00000005)
#define CSL_GEM_TETBACQINTN          (0x00000006)
#define CSL_GEM_TETBOVFLINTN         (0x00000007)
#define CSL_GEM_TETBUNFLINTN         (0x00000008)
#define CSL_GEM_EMU_DTDMA            (0x00000009)
#define CSL_GEM_MSMC_MPF_ERRORN      (0x0000000a)
#define CSL_GEM_EMU_RTDXRX           (0x0000000b)
#define CSL_GEM_EMU_RTDXTX           (0x0000000c)
#define CSL_GEM_IDMA0                (0x0000000d)
#define CSL_GEM_IDMA1                (0x0000000e)
#define CSL_GEM_SEMERRN              (0x0000000f)
#define CSL_GEM_SEMINTN              (0x00000010)
#define CSL_GEM_PCIEXPRESS_MSI_INTN  (0x00000011)
#define CSL_GEM_TSIP0_ERRINT_N      (0x00000012)
#define CSL_GEM_TSIP1_ERRINT_N      (0x00000013)
#define CSL_GEM_INTDST_N_PLUS_16     (0x00000014)
#define CSL_GEM_INTC0_OUT_32_PLUS_11_MUL_N_OR_INTC0_OUT_32_PLUS_11_MUL_N_MINUS_4 (0x00000015)
#define CSL_GEM_INTC0_OUT_33_PLUS_11_MUL_N_OR_INTC0_OUT_33_PLUS_11_MUL_N_MINUS_4 (0x00000016)
#define CSL_GEM_INTC0_OUT_34_PLUS_11_MUL_N_OR_INTC0_OUT_34_PLUS_11_MUL_N_MINUS_4 (0x00000017)
#define CSL_GEM_INTC0_OUT_35_PLUS_11_MUL_N_OR_INTC0_OUT_35_PLUS_11_MUL_N_MINUS_4 (0x00000018)
#define CSL_GEM_INTC0_OUT_36_PLUS_11_MUL_N_OR_INTC0_OUT_36_PLUS_11_MUL_N_MINUS_4 (0x00000019)
#define CSL_GEM_INTC0_OUT_37_PLUS_11_MUL_N_OR_INTC0_OUT_37_PLUS_11_MUL_N_MINUS_4 (0x0000001a)
#define CSL_GEM_INTC0_OUT_38_PLUS_11_MUL_N_OR_INTC0_OUT_38_PLUS_11_MUL_N_MINUS_4 (0x0000001b)
#define CSL_GEM_INTC0_OUT_39_PLUS_11_MUL_N_OR_INTC0_OUT_39_PLUS_11_MUL_N_MINUS_4 (0x0000001c)
#define CSL_GEM_INTC0_OUT_40_PLUS_11_MUL_N_OR_INTC0_OUT_40_PLUS_11_MUL_N_MINUS_4 (0x0000001d)
#define CSL_GEM_INTC0_OUT_41_PLUS_11_MUL_N_OR_INTC0_OUT_41_PLUS_11_MUL_N_MINUS_4 (0x0000001e)
#define CSL_GEM_INTC0_OUT_42_PLUS_11_MUL_N_OR_INTC0_OUT_42_PLUS_11_MUL_N_MINUS_4 (0x0000001f)
/* Same as above - name changed to match data manuals */
#define CSL_GEM_CIC0_OUT_32_PLUS_11_MUL_N_OR_CIC0_OUT_32_PLUS_11_MUL_N_MINUS_4 (0x00000015)
#define CSL_GEM_CIC0_OUT_33_PLUS_11_MUL_N_OR_CIC0_OUT_33_PLUS_11_MUL_N_MINUS_4 (0x00000016)
#define CSL_GEM_CIC0_OUT_34_PLUS_11_MUL_N_OR_CIC0_OUT_34_PLUS_11_MUL_N_MINUS_4 (0x00000017)
#define CSL_GEM_CIC0_OUT_35_PLUS_11_MUL_N_OR_CIC0_OUT_35_PLUS_11_MUL_N_MINUS_4 (0x00000018)
#define CSL_GEM_CIC0_OUT_36_PLUS_11_MUL_N_OR_CIC0_OUT_36_PLUS_11_MUL_N_MINUS_4 (0x00000019)
#define CSL_GEM_CIC0_OUT_37_PLUS_11_MUL_N_OR_CIC0_OUT_37_PLUS_11_MUL_N_MINUS_4 (0x0000001a)
#define CSL_GEM_CIC0_OUT_38_PLUS_11_MUL_N_OR_CIC0_OUT_38_PLUS_11_MUL_N_MINUS_4 (0x0000001b)
#define CSL_GEM_CIC0_OUT_39_PLUS_11_MUL_N_OR_CIC0_OUT_39_PLUS_11_MUL_N_MINUS_4 (0x0000001c)
#define CSL_GEM_CIC0_OUT_40_PLUS_11_MUL_N_OR_CIC0_OUT_40_PLUS_11_MUL_N_MINUS_4 (0x0000001d)
#define CSL_GEM_CIC0_OUT_41_PLUS_11_MUL_N_OR_CIC0_OUT_41_PLUS_11_MUL_N_MINUS_4 (0x0000001e)
#define CSL_GEM_CIC0_OUT_42_PLUS_11_MUL_N_OR_CIC0_OUT_42_PLUS_11_MUL_N_MINUS_4 (0x0000001f)
#define CSL_GEM_QM_INT_LOW_0         (0x00000020)
#define CSL_GEM_QM_INT_LOW_1         (0x00000021)
#define CSL_GEM_QM_INT_LOW_2         (0x00000022)
#define CSL_GEM_QM_INT_LOW_3         (0x00000023)
#define CSL_GEM_QM_INT_LOW_4         (0x00000024)
#define CSL_GEM_QM_INT_LOW_5         (0x00000025)
#define CSL_GEM_QM_INT_LOW_6         (0x00000026)
#define CSL_GEM_QM_INT_LOW_7         (0x00000027)
#define CSL_GEM_QM_INT_LOW_8         (0x00000028)
#define CSL_GEM_QM_INT_LOW_9         (0x00000029)
#define CSL_GEM_QM_INT_LOW_10        (0x0000002a)
#define CSL_GEM_QM_INT_LOW_11        (0x0000002b)
#define CSL_GEM_QM_INT_LOW_12        (0x0000002c)
#define CSL_GEM_QM_INT_LOW_13        (0x0000002d)
#define CSL_GEM_QM_INT_LOW_14        (0x0000002e)
#define CSL_GEM_QM_INT_LOW_15        (0x0000002f)
#define CSL_GEM_QM_INT_HIGH_N        (0x00000030)
#define CSL_GEM_QM_INT_HIGH__N_PLUS_8 (0x00000031)
#define CSL_GEM_QM_INT_HIGH__N_PLUS_16 (0x00000032)
#define CSL_GEM_QM_INT_HIGH__N_PLUS_24 (0x00000033)
#define CSL_GEM_TSIP0_RFSINT_N       (0x00000034)
#define CSL_GEM_TSIP0_RSFINT_N       (0x00000035)
#define CSL_GEM_TSIP0_XFSINT_N       (0x00000036)
#define CSL_GEM_TSIP0_XSFINT_N       (0x00000037)
#define CSL_GEM_TSIP1_RFSINT_N       (0x00000038)
#define CSL_GEM_TSIP1_RSFINT_N       (0x00000039)
#define CSL_GEM_TSIP1_XFSINT_N       (0x0000003a)
#define CSL_GEM_TSIP1_XSFINT_N       (0x0000003b)
#define CSL_GEM_RESERVED_60          (0x0000003c)
#define CSL_GEM_RESERVED_61          (0x0000003d)
#define CSL_GEM_INTC0_OUT_2_PLUS_8_MUL_N_OR_INTC0_OUT_2_PLUS_8_MUL_N_MINUS_4 (0x0000003e)
#define CSL_GEM_INTC0_OUT_3_PLUS_8_MUL_N_OR_INTC0_OUT_3_PLUS_8_MUL_N_MINUS_4 (0x0000003f)
/* Same as above - name changed to match data manuals */
#define CSL_GEM_CIC0_OUT_2_PLUS_8_MUL_N_OR_CIC0_OUT_2_PLUS_8_MUL_N_MINUS_4 (0x0000003e)
#define CSL_GEM_CIC0_OUT_3_PLUS_8_MUL_N_OR_CIC0_OUT_3_PLUS_8_MUL_N_MINUS_4 (0x0000003f)
#define CSL_GEM_TINTLN               (0x00000040)
#define CSL_GEM_TINTHN               (0x00000041)
#define CSL_GEM_TINT8L               (0x00000042)
#define CSL_GEM_TINT8H               (0x00000043)
#define CSL_GEM_TINT9L               (0x00000044)
#define CSL_GEM_TINT9H               (0x00000045)
#define CSL_GEM_TINT10L              (0x00000046)
#define CSL_GEM_TINT10H              (0x00000047)
#define CSL_GEM_TINT11L              (0x00000048)
#define CSL_GEM_TINT11H              (0x00000049)
#define CSL_GEM_TINT12L              (0x0000004a)
#define CSL_GEM_TINT12H              (0x0000004b)
#define CSL_GEM_TINT13L              (0x0000004c)
#define CSL_GEM_TINT13H              (0x0000004d)
#define CSL_GEM_TINT14L              (0x0000004e)
#define CSL_GEM_TINT14H              (0x0000004f)
#define CSL_GEM_TINT15L              (0x00000050)
#define CSL_GEM_TINT15H              (0x00000051)
#define CSL_GEM_GPINT8               (0x00000052)
#define CSL_GEM_GPINT9               (0x00000053)
#define CSL_GEM_GPINT10              (0x00000054)
#define CSL_GEM_GPINT11              (0x00000055)
#define CSL_GEM_GPINT12              (0x00000056)
#define CSL_GEM_GPINT13              (0x00000057)
#define CSL_GEM_GPINT14              (0x00000058)
#define CSL_GEM_GPINT15              (0x00000059)
#define CSL_GEM_GPINTN               (0x0000005a)
#define CSL_GEM_IPC_LOCAL            (0x0000005b)
#define CSL_GEM_INTC0_OUT_4_PLUS_8_MUL_N_OR_INTC0_OUT_4_PLUS_8_MUL_N_MINUS_4 (0x0000005c)
#define CSL_GEM_INTC0_OUT_5_PLUS_8_MUL_N_OR_INTC0_OUT_5_PLUS_8_MUL_N_MINUS_4 (0x0000005d)
#define CSL_GEM_INTC0_OUT_6_PLUS_8_MUL_N_OR_INTC0_OUT_6_PLUS_8_MUL_N_MINUS_4 (0x0000005e)
#define CSL_GEM_INTC0_OUT_7_PLUS_8_MUL_N_OR_INTC0_OUT_7_PLUS_8_MUL_N_MINUS_4 (0x0000005f)
/* Same as above - name changed to match data manuals */
#define CSL_GEM_CIC0_OUT_4_PLUS_8_MUL_N_OR_CIC0_OUT_4_PLUS_8_MUL_N_MINUS_4 (0x0000005c)
#define CSL_GEM_CIC0_OUT_5_PLUS_8_MUL_N_OR_CIC0_OUT_5_PLUS_8_MUL_N_MINUS_4 (0x0000005d)
#define CSL_GEM_CIC0_OUT_6_PLUS_8_MUL_N_OR_CIC0_OUT_6_PLUS_8_MUL_N_MINUS_4 (0x0000005e)
#define CSL_GEM_CIC0_OUT_7_PLUS_8_MUL_N_OR_CIC0_OUT_7_PLUS_8_MUL_N_MINUS_4 (0x0000005f)
#define CSL_GEM_INTERR               (0x00000060)
#define CSL_GEM_EMC_IDMAERR          (0x00000061)
#define CSL_GEM_PBISTINT             (0x00000062)
#define CSL_GEM_RESERVED_99          (0x00000063)
#define CSL_GEM_EFIINTA              (0x00000064)
#define CSL_GEM_EFIINTB              (0x00000065)
#define CSL_GEM_INTC0_OUT0_OR_INTC1_OUT0 (0x00000066)
#define CSL_GEM_INTC0_OUT1_OR_INTC1_OUT1 (0x00000067)
#define CSL_GEM_INTC0_OUT8_OR_INTC1_OUT8 (0x00000068)
#define CSL_GEM_INTC0_OUT9_OR_INTC1_OUT9 (0x00000069)
#define CSL_GEM_INTC0_OUT16_OR_INTC1_OUT16 (0x0000006a)
#define CSL_GEM_INTC0_OUT17_OR_INTC1_OUT17 (0x0000006b)
#define CSL_GEM_INTC0_OUT24_OR_INTC1_OUT24 (0x0000006c)
#define CSL_GEM_INTC0_OUT25_OR_INTC1_OUT25 (0x0000006d)
/* Same as above - name changed to match data manuals */
#define CSL_GEM_CIC0_OUT0_OR_CIC1_OUT0 (0x00000066)
#define CSL_GEM_CIC0_OUT1_OR_CIC1_OUT1 (0x00000067)
#define CSL_GEM_CIC0_OUT8_OR_CIC1_OUT8 (0x00000068)
#define CSL_GEM_CIC0_OUT9_OR_CIC1_OUT9 (0x00000069)
#define CSL_GEM_CIC0_OUT16_OR_CIC1_OUT16 (0x0000006a)
#define CSL_GEM_CIC0_OUT17_OR_CIC1_OUT17 (0x0000006b)
#define CSL_GEM_CIC0_OUT24_OR_CIC1_OUT24 (0x0000006c)
#define CSL_GEM_CIC0_OUT25_OR_CIC1_OUT25 (0x0000006d)
#define CSL_GEM_MDMAERREVT         (0x0000006e)
#define CSL_GEM_RESERVED_111         (0x0000006f)
#define CSL_GEM_CPU_2_EDMACC_AETEVT  (0x00000070)
#define CSL_GEM_PMC_ED               (0x00000071)
#define CSL_GEM_CPU_3_1_EDMACC_AETEVT (0x00000072)
#define CSL_GEM_CPU_3_2_EDMACC_AETEVT (0x00000073)
#define CSL_GEM_UMC_ED1              (0x00000074)
#define CSL_GEM_UMC_ED2              (0x00000075)
#define CSL_GEM_PDC_INT              (0x00000076)
#define CSL_GEM_SYS_CMPA         (0x00000077)
#define CSL_GEM_PMC_CMPA             (0x00000078)
#define CSL_GEM_PMC_DMPA             (0x00000079)
#define CSL_GEM_DMC_CMPA             (0x0000007a)
#define CSL_GEM_DMC_DMPA             (0x0000007b)
#define CSL_GEM_UMC_CMPA             (0x0000007c)
#define CSL_GEM_UMC_DMPA             (0x0000007d)
#define CSL_GEM_EMC_CMPA             (0x0000007e)
#define CSL_GEM_EMC_BUSERR           (0x0000007f)

/**************************************************************************
* EOI Values
**************************************************************************/
#define CSL_MPU_EOI_VALUE           0
#define CSL_TRACER_EOI_VALUE           0
#define CSL_BOOTCFG_EOI_VALUE           0

#ifndef CSL_MODIFICATION
#define SOC_UART0_BASE                 (CSL_UART_REGS)
#define SOC_DSP_L1P_BASE               (CSL_CGEM0_5_LOCAL_L1P_SRAM_REGS)
#define SOC_DSP_L1D_BASE               (CSL_CGEM0_5_L1D_SRAM_REGS)
#define SOC_DSP_L2_BASE                (CSL_CGEM0_5_LOCAL_L2_SRAM_REGS)
#define SOC_DSP_ICFG_BASE              (CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS - 0x800000U)
#endif

#ifdef __cplusplus
}
#endif

#endif

