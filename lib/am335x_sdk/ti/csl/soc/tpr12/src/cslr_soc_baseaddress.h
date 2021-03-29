/********************************************************************
*
* SOC memory map header file
*
* Copyright (C) 2020 Texas Instruments Incorporated.
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
#ifndef CSLR_SOC_BASEADDRESS_H
#define CSLR_SOC_BASEADDRESS_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/* Global addresses in unified address space */
#define CSL_MSS_SPIA_RAM_U_BASE                 (0x2000000ul)
#define CSL_MSS_SPIB_RAM_U_BASE                 (0x2020000ul)
#define CSL_MSS_MCANA_MSG_RAM_U_BASE            (0x2040000ul)
#define CSL_MSS_VIM_R5A_U_BASE                  (0x2080000ul)
#define CSL_MSS_VIM_R5B_U_BASE                  (0x20A0000ul)
#define CSL_MSS_IOMUX_U_BASE                    (0x20C0000ul)
#define CSL_MSS_RCM_U_BASE                      (0x2100000ul)
#define CSL_MSS_CTRL_U_BASE                     (0x2120000ul)
#define CSL_MSS_TOPRCM_U_BASE                   (0x2140000ul)
#define CSL_MSS_DEBUGSS_U_BASE                  (0x2A00000ul)
#define CSL_MSS_PCR1_U_BASE                     (0x2F78000ul)
#define CSL_TOP_PBIST_U_BASE                    (0x2F79400ul)
#define CSL_MSS_R5SS_STC_U_BASE                 (0x2F79800ul)
#define CSL_MSS_DCCA_U_BASE                     (0x2F79C00ul)
#define CSL_MSS_DCCB_U_BASE                     (0x2F79D00ul)
#define CSL_MSS_DCCC_U_BASE                     (0x2F79E00ul)
#define CSL_MSS_DCCD_U_BASE                     (0x2F79F00ul)
#define CSL_MSS_RTIA_U_BASE                     (0x2F7A000ul)
#define CSL_MSS_RTIB_U_BASE                     (0x2F7A100ul)
#define CSL_MSS_RTIC_U_BASE                     (0x2F7A200ul)
#define CSL_MSS_WDT_U_BASE                      (0x2F7A300ul)
#define CSL_MSS_ESM_U_BASE                      (0x2F7A400ul)
#define CSL_TOP_EFUSE_FARM_U_BASE               (0x2F7A800ul)
#define CSL_MSS_CCMR_U_BASE                     (0x2F7AC00ul)
#define CSL_MSS_I2C_U_BASE                      (0x2F7B000ul)
#define CSL_MSS_GIO_U_BASE                      (0x2F7B400ul)
#define CSL_MSS_ECC_AGG_R5A_U_BASE              (0x2F7B800ul)
#define CSL_MSS_ECC_AGG_R5B_U_BASE              (0x2F7BC00ul)
#define CSL_MSS_ECC_AGG_CSL_MSS_U_BASE          (0x2F7C000ul)
#define CSL_MSS_SPIA_U_BASE                     (0x2F7E800ul)
#define CSL_MSS_SPIB_U_BASE                     (0x2F7EA00ul)
#define CSL_MSS_SCIA_U_BASE                     (0x2F7EC00ul)
#define CSL_MSS_SCIB_U_BASE                     (0x2F7ED00ul)
#define CSL_MSS_MCANA_ECC_U_BASE                (0x2F7F800ul)
#define CSL_MSS_MCANA_CFG_U_BASE                (0x2F7FC00ul)
#define CSL_MSS_MCANB_MSG_RAM_U_BASE            (0x3040000ul)
#define CSL_TOP_AURORA_TX_U_BASE                (0x3060000ul)
#define CSL_TOP_MDO_INFRA_U_BASE                (0x3080000ul)
#define CSL_MSS_GPADC_PKT_RAM_U_BASE            (0x30C0000ul)
#define CSL_TOP_CTRL_U_BASE                     (0x30E0000ul)
#define CSL_MSS_TPCC_A_U_BASE                   (0x3100000ul)
#define CSL_MSS_TPCC_B_U_BASE                   (0x3120000ul)
#define CSL_MSS_TPTC_A0_U_BASE                  (0x3140000ul)
#define CSL_MSS_TPTC_A1_U_BASE                  (0x3160000ul)
#define CSL_MSS_TPTC_B0_U_BASE                  (0x3180000ul)
#define CSL_MSS_PCR2_U_BASE                     (0x3F78000ul)
#define CSL_MSS_ETPWMA_U_BASE                   (0x3F78C00ul)
#define CSL_MSS_ETPWMB_U_BASE                   (0x3F78D00ul)
#define CSL_MSS_ETPWMC_U_BASE                   (0x3F78E00ul)
#define CSL_MSS_GPADC_REG_U_BASE                (0x3F79800ul)
#define CSL_MSS_DMM_A_U_BASE                    (0x3F79C00ul)
#define CSL_MSS_DMM_B_U_BASE                    (0x3F79E00ul)
#define CSL_MSS_MCANB_ECC_U_BASE                (0x3F7F800ul)
#define CSL_MSS_MCANB_CFG_U_BASE                (0x3F7FC00ul)
#define CSL_RCSS_RCM_U_BASE                     (0x5000000ul)
#define CSL_RCSS_CTRL_U_BASE                    (0x5020000ul)
#define CSL_RCSS_SPIA_RAM_U_BASE                (0x5040000ul)
#define CSL_RCSS_SPIB_RAM_U_BASE                (0x5060000ul)
#define CSL_RCSS_CSI2A_U_BASE                   (0x5080000ul)
#define CSL_RCSS_CSI2B_U_BASE                   (0x50A0000ul)
#define CSL_RCSS_SCI_A_U_BASE                   (0x50C0000ul)
#define CSL_RCSS_TPCC_A_U_BASE                  (0x5100000ul)
#define CSL_RCSS_TPTC_A0_U_BASE                 (0x5160000ul)
#define CSL_RCSS_TPTC_A1_U_BASE                 (0x5180000ul)
#define CSL_RCSS_MCASP_A_U_BASE                 (0x51E0000ul)
#define CSL_RCSS_MCASP_B_U_BASE                 (0x5200000ul)
#define CSL_RCSS_MCASP_C_U_BASE                 (0x5220000ul)
#define CSL_RCSS_ATL_U_BASE                     (0x5240000ul)
#define CSL_RCSS_PCR_U_BASE                     (0x5F78000ul)
#define CSL_RCSS_ECAP_U_BASE                    (0x5F79C00ul)
#define CSL_RCSS_GIO_U_BASE                     (0x5F7B400ul)
#define CSL_RCSS_SPIA_U_BASE                    (0x5F7E800ul)
#define CSL_RCSS_SPIB_U_BASE                    (0x5F7EA00ul)
#define CSL_RCSS_I2CA_U_BASE                    (0x5F7EC00ul)
#define CSL_RCSS_I2CB_U_BASE                    (0x5F7F000ul)
#define CSL_DSS_RCM_U_BASE                      (0x6000000ul)
#define CSL_DSS_CTRL_U_BASE                     (0x6020000ul)
#define CSL_DSS_CBUFF_U_BASE                    (0x6040000ul)
#define CSL_DSS_HWA_PARAM_U_BASE                (0x6060000ul)
#define CSL_DSS_HWA_CFG_U_BASE                  (0x6062000ul)
#define CSL_DSS_HWA_WINDOW_RAM_U_BASE           (0x6064000ul)
#define CSL_DSS_HWA_MULT_RAM_U_BASE             (0x6068000ul)
#define CSL_DSS_HWA_DEROT_RAM_U_BASE            (0x606C000ul)
#define CSL_DSS_HWA_SHUFFLE_RAM_U_BASE          (0x606E000ul)
#define CSL_DSS_HWA_2DSTAT_ITER_VAL_RAM_U_BASE  (0x6080000ul)
#define CSL_DSS_HWA_2DSTAT_ITER_IDX_RAM_U_BASE  (0x6082000ul)
#define CSL_DSS_HWA_2DSTAT_SMPL_VAL_RAM_U_BASE  (0x6084000ul)
#define CSL_DSS_HWA_2DSTAT_SMPL_IDX_RAM_U_BASE  (0x6086000ul)
#define CSL_DSS_HWA_HIST_RAM_U_BASE             (0x6088000ul)
#define CSL_DSS_HWA_HIST_THRESH_RAM_U_BASE      (0x608C000ul)
#define CSL_DSS_ECC_AGG_U_BASE                  (0x60A0000ul)
#define CSL_DSS_TPCC_A_U_BASE                   (0x6100000ul)
#define CSL_DSS_TPCC_B_U_BASE                   (0x6120000ul)
#define CSL_DSS_TPCC_C_U_BASE                   (0x6140000ul)
#define CSL_DSS_TPTC_A0_U_BASE                  (0x6160000ul)
#define CSL_DSS_TPTC_A1_U_BASE                  (0x6180000ul)
#define CSL_DSS_TPTC_B0_U_BASE                  (0x61A0000ul)
#define CSL_DSS_TPTC_B1_U_BASE                  (0x61C0000ul)
#define CSL_DSS_TPTC_C0_U_BASE                  (0x61E0000ul)
#define CSL_DSS_TPTC_C1_U_BASE                  (0x6200000ul)
#define CSL_DSS_TPTC_C2_U_BASE                  (0x6220000ul)
#define CSL_DSS_TPTC_C3_U_BASE                  (0x6240000ul)
#define CSL_DSS_TPTC_C4_U_BASE                  (0x6260000ul)
#define CSL_DSS_TPTC_C5_U_BASE                  (0x6280000ul)
#define CSL_DSS_PCR_U_BASE                      (0x6F78000ul)
#define CSL_DSS_DSP_PBIST_U_BASE                (0x6F79000ul)
#define CSL_DSS_DSP_STC_U_BASE                  (0x6F79200ul)
#define CSL_DSS_CM4_STC_U_BASE                  (0x6F79400ul)
#define CSL_DSS_DCCA_U_BASE                     (0x6F79C00ul)
#define CSL_DSS_DCCB_U_BASE                     (0x6F79D00ul)
#define CSL_DSS_RTIA_U_BASE                     (0x6F7A000ul)
#define CSL_DSS_RTIB_U_BASE                     (0x6F7A100ul)
#define CSL_DSS_WDT_U_BASE                      (0x6F7A200ul)
#define CSL_DSS_SCIA_U_BASE                     (0x6F7B000ul)
#define CSL_DSS_CMC_CFG_U_BASE                  (0x6F7C000ul)
#define CSL_DSS_ESM_U_BASE                      (0x6F7D000ul)
#define CSL_MSS_CPSW_U_BASE                     (0x7000000ul)
#define CSL_MSS_L2_U_BASE                       (0x10200000ul)
#define CSL_HSM_ROM_U_BASE                      (0x20000000ul)
#define CSL_HSM_RAM_U_BASE                      (0x20020000ul)
#define CSL_DSS_CM4_RAM_U_BASE                  (0x28000000ul)
#define CSL_HSM_SOC_CTRL_U_BASE                 (0x40000000ul)
#define CSL_MPU_MSS_L2_BANKA_U_BASE             (0x40020000ul)
#define CSL_MPU_MSS_L2_BANKB_U_BASE             (0x40040000ul)
#define CSL_MPU_DTHE_U_BASE                     (0x40060000ul)
#define CSL_MPU_MSS_MBOX_U_BASE                 (0x40080000ul)
#define CSL_MPU_MSS_PCRA_U_BASE                 (0x400A0000ul)
#define CSL_MPU_MSS_QSPI_U_BASE                 (0x400C0000ul)
#define CSL_MPU_MSS_CR5A_AXIS_U_BASE            (0x400E0000ul)
#define CSL_MPU_MSS_CR5B_AXIS_U_BASE            (0x40100000ul)
#define CSL_MPU_DSS_L3_BANKA_U_BASE             (0x40120000ul)
#define CSL_MPU_DSS_L3_BANKB_U_BASE             (0x40140000ul)
#define CSL_MPU_DSS_L3_BANKC_U_BASE             (0x40160000ul)
#define CSL_MPU_DSS_L3_BANKD_U_BASE             (0x40180000ul)
#define CSL_MPU_DSS_HWA_DMA0_U_BASE             (0x401A0000ul)
#define CSL_MPU_DSS_HWA_DMA1_U_BASE             (0x401C0000ul)
#define CSL_MPU_DSS_HWA_PROC_U_BASE             (0x401E0000ul)
#define CSL_MPU_DSS_MBOX_U_BASE                 (0x40200000ul)
#define CSL_MPU_HSM_BASE                        (0x40220000ul)
#define CSL_HSM_SOC_PCR_U_BASE                  (0x40F78000ul)
#define CSL_HSM_STC_U_BASE                      (0x40F78C00ul)
#define CSL_HSM_PBIST_U_BASE                    (0x40F79000ul)
#define CSL_HSM_ECC_AGGR_U_BASE                 (0x40F79400ul)
#define CSL_HSM_MBOX_U_BASE                     (0x44000000ul)
#define CSL_HSM_SEC_MGR_U_BASE                  (0x46000000ul)
#define CSL_HSM_SEC_RAM_U_BASE                  (0x46050000ul)
#define CSL_HSM_CTRL_U_BASE                     (0x47000000ul)
#define CSL_HSM_TPCCA_U_BASE                    (0x47020000ul)
#define CSL_HSM_TPTCA0_U_BASE                   (0x47040000ul)
#define CSL_HSM_TPTCA1_U_BASE                   (0x47060000ul)
#define CSL_HSM_PCR_U_BASE                      (0x47F78000ul)
#define CSL_HSM_RTIA_U_BASE                     (0x47F78C00ul)
#define CSL_HSM_WDT_U_BASE                      (0x47F78D00ul)
#define CSL_HSM_DCCA_U_BASE                     (0x47F79000ul)
#define CSL_HSM_ESM_U_BASE                      (0x47F79400ul)
#define CSL_HSM_DMTA_U_BASE                     (0x47F79800ul)
#define CSL_HSM_DMTB_U_BASE                     (0x47F79900ul)
#define CSL_HSM_DMTC_U_BASE                     (0x47F79A00ul)
#define CSL_HSM_DMTD_U_BASE                     (0x47F79B00ul)
#define CSL_DSS_CM4_MBOX_U_BASE                 (0x48000000ul)
#define CSL_DSS_CM4_CTRL_U_BASE                 (0x48020000ul)
#define CSL_DSS_L2_U_BASE                       (0x80800000ul)
#define CSL_DSS_L1P_U_BASE                      (0x80E00000ul)
#define CSL_DSS_L1D_U_BASE                      (0x80F00000ul)
#define CSL_DSS_HWA_DMA0_U_BASE                 (0x82000000ul)
#define CSL_DSS_HWA_DMA1_U_BASE                 (0x82100000ul)
#define CSL_DSS_MAILBOX_U_BASE                  (0x83100000ul)
#define CSL_DSS_MCRC_U_BASE                     (0x83300000ul)
#define CSL_DSS_CMC_UCOMP0_U_BASE               (0x85000000ul)
#define CSL_DSS_CMC_UCOMP1_U_BASE               (0x85001000ul)
#define CSL_DSS_CMC_UCOMP2_U_BASE               (0x85002000ul)
#define CSL_DSS_CMC_UCOMP3_U_BASE               (0x85003000ul)
#define CSL_DSS_CMC_COMP_U_BASE                 (0x85080000ul)
#define CSL_DSS_L3_U_BASE                       (0x88000000ul)
#define CSL_RCSS_ICSSM_DATARAMA_U_BASE          (0xA0000000ul)
#define CSL_RCSS_ICSSM_DATARAMB_U_BASE          (0xA0002000ul)
#define CSL_RCSS_ICSSM_DATARAMC_U_BASE          (0xA0010000ul)
#define CSL_RCSS_ICSSM_INTC_U_BASE              (0xA0020000ul)
#define CSL_RCSS_ICSSM_PRU0_CTRL_U_BASE         (0xA0022000ul)
#define CSL_RCSS_ICSSM_PRU0_DEBUG_U_BASE        (0xA0022400ul)
#define CSL_RCSS_ICSSM_CFG_U_BASE               (0xA0026000ul)
#define CSL_RCSS_ICSSM_ECC_CFG_U_BASE           (0xA0027000ul)
#define CSL_RCSS_ICSSM_UART_0_U_BASE            (0xA0028000ul)
#define CSL_RCSS_ICSSM_IEP_U_BASE               (0xA002E000ul)
#define CSL_RCSS_ICSSM_ECAP_U_BASE              (0xA0030000ul)
#define CSL_RCSS_ICSSM_MII_RT_CFG_U_BASE        (0xA0032000ul)
#define CSL_RCSS_ICSSM_MII_MDIO_U_BASE          (0xA0032400ul)
#define CSL_RCSS_ICSSM_IRAMA_U_BASE             (0xA0034000ul)
#define CSL_RCSS_ICSSM_IRAMB_U_BASE             (0xA0038000ul)
#define CSL_RCSS_ICSSM_VBUSP_U_BASE             (0xA0040000ul)
#define CSL_RCSS_MCASPA_DATA_U_BASE             (0xA0080000ul)
#define CSL_RCSS_MCASPB_DATA_U_BASE             (0xA0080400ul)
#define CSL_MSS_TCMA_CR5A_U_BASE                (0xC1000000ul)
#define CSL_MSS_TCMB_CR5A_U_BASE                (0xC1800000ul)
#define CSL_MSS_ICACHE_CR5A_U_BASE              (0xC2000000ul)
#define CSL_MSS_DCACHE_CR5A_U_BASE              (0xC2800000ul)
#define CSL_MSS_TCMA_CR5B_U_BASE                (0xC3000000ul)
#define CSL_MSS_TCMB_CR5B_U_BASE                (0xC3800000ul)
#define CSL_MSS_ICACHE_CR5B_U_BASE              (0xC4000000ul)
#define CSL_MSS_DCACHE_CR5B_U_BASE              (0xC4800000ul)
#define CSL_MSS_MBOX_U_BASE                     (0xC5000000ul)
#define CSL_MSS_RETRAM_U_BASE                   (0xC5010000ul)
#define CSL_MSS_MCRC_U_BASE                     (0xC5020000ul)
#define CSL_MSS_GPADC_DATA_RAM_U_BASE           (0xC5030000ul)
#define CSL_EXT_FLASH_U_BASE                    (0xC6000000ul)
#define CSL_MSS_QSPI_U_BASE                     (0xC8000000ul)
#define CSL_HSM_DTHE_U_BASE                     (0xCE000000ul)
#define CSL_HSM_SHA_U_BASE                      (0xCE004000ul)
#define CSL_HSM_AES_U_BASE                      (0xCE006000ul)
#define CSL_HSM_TRNG_U_BASE                     (0xCE00A000ul)
#define CSL_HSM_PKA_U_BASE                      (0xCE010000ul)
#define CSL_HSM_PKA_RAM_U_BASE                  (0xCE014000ul)
  
#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_BASEADDRESS_H_ */