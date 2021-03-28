/*
 *  Copyright (C) 2008-2013 Texas Instruments Incorporated - www.ti.com/
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
 *  \file   SOC.h
 *
 *  \brief  SOC memory map header file
 *
**/

#ifndef SOC_H_
#define SOC_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define SOC_DSP_L2_BASE                                                         (0x800000U)
#define SOC_DSP_L1P_BASE                                                        (0xe00000U)
#define SOC_DSP_L1D_BASE                                                        (0xf00000U)
#define SOC_DSP_ICFG_BASE                                                       (0x1000000U)
#define SOC_DSP_SYSTEM_BASE                                                     (0x1d00000U)
#define SOC_DSP_MMU0CFG_BASE                                                    (0x1d01000U)
#define SOC_DSP_MMU1CFG_BASE                                                    (0x1d02000U)
#define SOC_DSP_FW0CFG_BASE                                                     (0x1d03000U)
#define SOC_DSP_FW1CFG_BASE                                                     (0x1d04000U)
#define SOC_DSP_EDMA_TC0_BASE                                                   (0x1d05000U)
#define SOC_DSP_EDMA_TC1_BASE                                                   (0x1d06000U)
#define SOC_DSP_NOC_BASE                                                        (0x1d07000U)
#define SOC_DSP_DFT_BASE                                                        (0x1d0f000U)
#define SOC_DSP_EDMA_CC_BASE                                                    (0x1d10000U)
#define SOC_EVE1_DMEM_BASE                                                      (0x2020000U)
#define SOC_EVE1_WBUF_BASE                                                      (0x2040000U)
#define SOC_EVE1_IBUFLA_BASE                                                    (0x2050000U)
#define SOC_EVE1_IBUFHA_BASE                                                    (0x2054000U)
#define SOC_EVE1_IBUFLB_BASE                                                    (0x2070000U)
#define SOC_EVE1_IBUFHB_BASE                                                    (0x2074000U)
#define SOC_EVE1_EVE_CONTROL_BASE                                               (0x2080000U)
#define SOC_EVE1_MMU0_BASE                                                      (0x2081000U)
#define SOC_EVE1_MMU1_BASE                                                      (0x2082000U)
#define SOC_EVE1_T16_BASE                                                       (0x2083000U)
#define SOC_EVE1_VCOP_BASE                                                      (0x2084000U)
#define SOC_EVE1_CTM_BASE                                                       (0x2085000U)
#define SOC_EVE1_TPTC0_BASE                                                     (0x2086000U)
#define SOC_EVE1_TPTC1_BASE                                                     (0x2087000U)
#define SOC_EVE1_SMSET_CONF_BASE                                                (0x2088000U)
#define SOC_EVE1_SMSET_SW_BASE                                                  (0x2089000U)
#define SOC_EVE1_L2_FNOC_EVE_BASE                                               (0x208a000U)
#define SOC_EVE1_MBX0_BASE                                                      (0x208b000U)
#define SOC_EVE1_MBX1_BASE                                                      (0x208c000U)
#define SOC_EVE1_MBX2_BASE                                                      (0x208d000U)
#define SOC_EVE1_MBX3_BASE                                                      (0x208e000U)
#define SOC_EVE1_MBX4_BASE                                                      (0x208f000U)
#define SOC_EVE1_PCACHE_RAW_BASE                                                (0x2090000U)
#define SOC_EVE1_PCACHE_TAGS_BASE                                               (0x2098000U)
#define SOC_EVE1_TPCC0_BASE                                                     (0x20a0000U)
#define SOC_EDMA_CC_BASE                                                        (0x3300000U)
#define SOC_EDMA_TC0_BASE                                                       (0x3400000U)
#define SOC_EDMA_TC1_BASE                                                       (0x3500000U)
#define SOC_DSP_XMC_CTRL_BASE                                                   (0x8000000U)
#define SOC_DSP_EDI_BASE                                                        (0x8010000U)
#define SOC_GPMC_BASE                                                           (0x14000000U)
#define SOC_OCMC_RAM1_BASE                                                      (0x40300000U)
#define SOC_DSP1_L2_SRAM_BASE                                                   (0x40800000U)
#define SOC_DSP1_SYSTEM_BASE                                                    (0x40d00000U)
#define SOC_DSP1_MMU0CFG_BASE                                                   (0x40d01000U)
#define SOC_DSP1_MMU1CFG_BASE                                                   (0x40d02000U)
#define SOC_DSP1_FW0CFG_BASE                                                    (0x40d03000U)
#define SOC_DSP1_FW1CFG_BASE                                                    (0x40d04000U)
#define SOC_DSP1_EDMA_TC0_BASE                                                  (0x40d05000U)
#define SOC_DSP1_EDMA_TC1_BASE                                                  (0x40d06000U)
#define SOC_DSP1_NOC_BASE                                                       (0x40d07000U)
#define SOC_DSP1_L1P_SRAM_BASE                                                  (0x40e00000U)
#define SOC_DSP1_L1D_SRAM_BASE                                                  (0x40f00000U)
#define SOC_DSP2_L2_SRAM_BASE                                                   (0x41000000U)
#define SOC_DSP2_SYSTEM_BASE                                                    (0x41500000U)
#define SOC_DSP2_MMU0CFG_BASE                                                   (0x41501000U)
#define SOC_DSP2_MMU1CFG_BASE                                                   (0x41502000U)
#define SOC_DSP2_FW0CFG_BASE                                                    (0x41503000U)
#define SOC_DSP2_FW1CFG_BASE                                                    (0x41504000U)
#define SOC_DSP2_EDMA_TC0_BASE                                                  (0x41505000U)
#define SOC_DSP2_EDMA_TC1_BASE                                                  (0x41506000U)
#define SOC_DSP2_NOC_BASE                                                       (0x41507000U)
#define SOC_DSP2_DFT_BASE                                                       (0x4150f000U)
#define SOC_DSP2_EDMA_CC_BASE                                                   (0x41510000U)
#define SOC_DSP2_L1P_SRAM_BASE                                                  (0x41600000U)
#define SOC_DSP2_L1D_SRAM_BASE                                                  (0x41700000U)
#define SOC_OCMC_RAM1_CBUF_BASE                                                 (0x41800000U)
#define SOC_EVE_DMEM_BASE                                                       (0x42020000U)
#define SOC_EVE_WBUF_BASE                                                       (0x42040000U)
#define SOC_EVE_IBUFLA_BASE                                                     (0x42050000U)
#define SOC_EVE_IBUFHA_BASE                                                     (0x42054000U)
#define SOC_EVE_IBUFLB_BASE                                                     (0x42070000U)
#define SOC_EVE_IBUFHB_BASE                                                     (0x42074000U)
#define SOC_EVE_EVE_CONTROL_BASE                                                (0x42080000U)
#define SOC_EVE_MMU0_BASE                                                       (0x42081000U)
#define SOC_EVE_MMU1_BASE                                                       (0x42082000U)
#define SOC_EVE_T16_BASE                                                        (0x42083000U)
#define SOC_EVE_VCOP_BASE                                                       (0x42084000U)
#define SOC_EVE_CTM_BASE                                                        (0x42085000U)
#define SOC_EVE_TPTC0_BASE                                                      (0x42086000U)
#define SOC_EVE_TPTC1_BASE                                                      (0x42087000U)
#define SOC_EVE_SMSET_CONF_BASE                                                 (0x42088000U)
#define SOC_EVE_SMSET_SW_BASE                                                   (0x42089000U)
#define SOC_EVE_L2_FNOC_EVE_BASE                                                (0x4208a000U)
#define SOC_EVE_L3_MBX0_BASE                                                    (0x4208b000U)
#define SOC_EVE_L3_MBX1_BASE                                                    (0x4208c000U)
#define SOC_EVE_L3_MBX2_BASE                                                    (0x4208d000U)
#define SOC_EVE_L3_MBX3_BASE                                                    (0x4208e000U)
#define SOC_EVE_L3_MBX4_BASE                                                    (0x4208f000U)
#define SOC_EVE_PCACHE_RAW_BASE                                                 (0x42090000U)
#define SOC_EVE_PCACHE_TAGS_BASE                                                (0x42098000U)
#define SOC_EVE_TPCC0_BASE                                                      (0x420a0000U)
#define SOC_EDMA_TPCC_BASE                                                      (0x43300000U)
/* Virtual and Physical address for EDMA is same in non-M4 core */
#define SOC_EDMA_TPCC_BASE_VIRT                                                 (SOC_EDMA_TPCC_BASE)
#define SOC_L3_MAIN_BASE                                                        (0x44000000U)
#define SOC_MCASP1_BASE                                                         (0x45800000U)
/* MCASP2 and MCASP3 base address is valid for TDA3xx SR2.0 and above */
#define SOC_MCASP2_BASE                                                         (0x48436000U)
#define SOC_MCASP3_BASE                                                         (0x4843A000U)
#define SOC_L4_PER_AP_BASE                                                      (0x48000000U)
#define SOC_UART3_BASE                                                          (0x48020000U)
#define SOC_TIMER2_BASE                                                         (0x48032000U)
#define SOC_TIMER3_BASE                                                         (0x48034000U)
#define SOC_TIMER4_BASE                                                         (0x48036000U)
#define SOC_GPIO2_BASE                                                          (0x48055000U)
#define SOC_GPIO3_BASE                                                          (0x48057000U)
#define SOC_GPIO4_BASE                                                          (0x48059000U)
#define SOC_UART1_BASE                                                          (0x4806a000U)
#define SOC_UART2_BASE                                                          (0x4806c000U)
#define SOC_I2C1_BASE                                                           (0x48070000U)
#define SOC_I2C2_BASE                                                           (0x48072000U)
#define SOC_ELM_BASE                                                            (0x48078000U)
#define SOC_MCSPI1_BASE                                                         (0x48098000U)
#define SOC_MCSPI2_BASE                                                         (0x4809a000U)
#define SOC_MCSPI3_BASE                                                         (0x480b8000U)
#define SOC_MCSPI4_BASE                                                         (0x480ba000U)
#define SOC_MMC4_BASE                                                           (0x480d1000U)
#define SOC_L4_PER2_AP_BASE                                                     (0x48400000U)
#define SOC_PWMSS1_IPWMSS_BASE                                                  (0x4843e000U)
#define SOC_PWMSS1_IECAP_BASE                                                   (0x4843e100U)
#define SOC_PWMSS1_IEQEP_BASE                                                   (0x4843e180U)
#define SOC_PWMSS1_IEPWM_BASE                                                   (0x4843e200U)
#define SOC_MCASP1_CFG_BASE                                                     (0x48460000U)
/* SOC_MCASP2_CFG_BASE and SOC_MCASP3_CFG_BASE is valid for TDA3xx SR2.0 and above */
#define SOC_MCASP2_CFG_BASE                                                     (0x4846C000U)
#define SOC_MCASP3_CFG_BASE                                                     (0x48470000U)
/* DCAN 2 base address is valid for TDA3xx SR1.0 only*/
#define SOC_DCAN2_BASE                                                          (0x48480000U)
/* MCAN base address is valid for TDA3xx SR2.0 and above */
#define SOC_MCAN_BASE                                                           (0x48480000U)
#define SOC_DCAN2_MESSAGERAM_BASE                                               (0x48481000U)
#define SOC_GMAC_SS_BASE                                                        (0x48484000U)
#define SOC_GMAC_PORT_BASE                                                      (0x48484100U)
#define SOC_GMAC_CPDMA_BASE                                                     (0x48484800U)
#define SOC_GMAC_STATERAM_BASE                                                  (0x48484a00U)
#define SOC_GMAC_CPTS_BASE                                                      (0x48484c00U)
#define SOC_GMAC_ALE_BASE                                                       (0x48484d00U)
#define SOC_GMAC_SL1_BASE                                                       (0x48484d80U)
#define SOC_GMAC_SL2_BASE                                                       (0x48484dc0U)
#define SOC_GMAC_MDIO_BASE                                                      (0x48485000U)
#define SOC_GMAC_WR_BASE                                                        (0x48485200U)
#define SOC_OCMC_RAM1_CFG_BASE                                                  (0x48804000U)
#define SOC_ESM_BASE                                                            (0x4a23c000U)
#define SOC_L4_PER3_AP_BASE                                                     (0x48800000U)
#define SOC_MMU_BASE                                                            (0x4881c000U)
#define SOC_MMU2_BASE                                                           (0x4881e000U)
#define SOC_TIMER5_BASE                                                         (0x48820000U)
#define SOC_TIMER6_BASE                                                         (0x48822000U)
#define SOC_TIMER7_BASE                                                         (0x48824000U)
#define SOC_TIMER8_BASE                                                         (0x48826000U)
#define SOC_MAILBOX2_BASE                                                       (0x4883a000U)
#define SOC_MAILBOX3_BASE                                                       (0x4883c000U)
#define SOC_MAILBOX4_BASE                                                       (0x4883e000U)
#define SOC_DCC1_BASE                                                           (0x48828000U)
#define SOC_DCC2_BASE                                                           (0x4882A000U)
#define SOC_DCC3_BASE                                                           (0x4882C000U)
#define SOC_DCC4_BASE                                                           (0x4882E000U)
#define SOC_DCC5_BASE                                                           (0x4884E000U)
#define SOC_DCC6_BASE                                                           (0x48852000U)
#define SOC_DCC7_BASE                                                           (0x48854000U)
#define SOC_VIP1_VIP_REGS_BASE                                                  (0x48970000U)
#define SOC_VIP1_VIP_PARSER_SLICE0_REGS_BASE                                    (0x48975500U)
#define SOC_VIP1_VIP_CSC_SLICE0_REGS_BASE                                       (0x48975700U)
#define SOC_VIP1_VIP_SC_SLICE0_REGS_BASE                                        (0x48975800U)
#define SOC_VIP1_VIP_PARSER_SLICE1_REGS_BASE                                    (0x48975a00U)
#define SOC_VIP1_VIP_CSC_SLICE1_REGS_BASE                                       (0x48975c00U)
#define SOC_VIP1_VIP_SC_SLICE1_REGS_BASE                                        (0x48975d00U)
#define SOC_VIP1_VIP_VPDMA_REGS_BASE                                            (0x4897d000U)
#define SOC_L4_CFG_AP_BASE                                                      (0x4A000000U)
#define SOC_IA_IP0_BASE                                                         (0x4a001000U)
#define SOC_CTRL_MODULE_CORE_BASE                                               (0x4a002000U)
#define SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE                                (0x4a002100U)
#define SOC_IRQ_DMARQ_CROSSBAR_REGISTERS_BASE                                   (0x4a0027a0U)
#define SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE                            (0x4a002da0U)
#define SOC_CORE_PAD_IO_REGISTERS_BASE                                          (0x4a003400U)
#define SOC_SEC_EFUSE_REGISTERS_BASE                                            (0x4a003a00U)
#define SOC_TA_CTRL_MODULE_CORE_TARG_BASE                                       (0x4a004000U)
#define SOC_OCP_SOCKET_CM_CORE_AON_BASE                                         (0x4a005000U)
#define SOC_CKGEN_CM_CORE_AON_BASE                                              (0x4a005100U)
#define SOC_MPU_CM_CORE_AON_BASE                                                (0x4a005300U)
#define SOC_DSP1_CM_CORE_AON_BASE                                               (0x4a005400U)
#define SOC_IPU_CM_CORE_AON_BASE                                                (0x4a005500U)
#define SOC_DSP2_CM_CORE_AON_BASE                                               (0x4a005600U)
#define SOC_EVE1_CM_CORE_AON_BASE                                               (0x4a005640U)
#define SOC_EVE2_CM_CORE_AON_BASE                                               (0x4a005680U)
#define SOC_EVE3_CM_CORE_AON_BASE                                               (0x4a0056c0U)
#define SOC_EVE4_CM_CORE_AON_BASE                                               (0x4a005700U)
#define SOC_RTC_CM_CORE_AON_BASE                                                (0x4a005740U)
#define SOC_VPE_CM_CORE_AON_BASE                                                (0x4a005760U)
#define SOC_RESTORE_CM_CORE_AON_BASE                                            (0x4a005e00U)
#define SOC_INSTR_CM_CORE_AON_BASE                                              (0x4a005f00U)
#define SOC_TA_CM_CORE_AON_TARG_BASE                                            (0x4a006000U)
#define SOC_OCP_SOCKET_CM_CORE_BASE                                             (0x4a008000U)
#define SOC_CKGEN_CM_CORE_BASE                                                  (0x4a008100U)
#define SOC_COREAON_CM_CORE_BASE                                                (0x4a008600U)
#define SOC_CORE_CM_CORE_BASE                                                   (0x4a008700U)
#define SOC_IVA_CM_CORE_BASE                                                    (0x4a008f00U)
#define SOC_CAM_CM_CORE_BASE                                                    (0x4a009000U)
#define SOC_DSS_CM_CORE_BASE                                                    (0x4a009100U)
#define SOC_GPU_CM_CORE_BASE                                                    (0x4a009200U)
#define SOC_L3INIT_CM_CORE_BASE                                                 (0x4a009300U)
#define SOC_CUSTEFUSE_CM_CORE_BASE                                              (0x4a009600U)
#define SOC_L4PER_CM_CORE_BASE                                                  (0x4a009700U)
#define SOC_RESTORE_CM_CORE_BASE                                                (0x4a009e18U)
#define SOC_TA_CM_CORE_TARG_BASE                                                (0x4a00a000U)
#define SOC_OCP2SCP1_USB_PHY1_CORE_BASE                                         (0x4a084000U)
#define SOC_OCP2SCP1_USB3RX_PHY_USB_BASE                                        (0x4a084400U)
#define SOC_OCP2SCP1_USB3TX_PHY_USB_BASE                                        (0x4a084800U)
#define SOC_OCP2SCP1_USB_PHY2_CORE_BASE                                         (0x4a085000U)
#define SOC_TA_OCP2SCP1_TARG_BASE                                               (0x4a088000U)
#define SOC_SMARTREFLEX_CORE_BASE                                               (0x4a0dd000U)
#define SOC_TA_SMARTREFLEX_CORE_TARG_BASE                                       (0x4a0de000U)
#define SOC_EFUSE_CTRL_CUST_BASE                                                (0x4a0e0000U)
#define SOC_TA_EFUSE_CTRL_CUST_TARG_BASE                                        (0x4a0e1000U)
#define SOC_MAILBOX1_BASE                                                       (0x4a0f4000U)
#define SOC_TA_MAILBOX1_TARG_BASE                                               (0x4a0f5000U)
#define SOC_SPINLOCK_BASE                                                       (0x4a0f6000U)
#define SOC_TA_SPINLOCK_TARG_BASE                                               (0x4a0f7000U)
#define SOC_OCP_WP_NOC_BASE                                                     (0x4a102000U)
#define SOC_TA_OCP_WP_NOC_TARG_BASE                                             (0x4a103000U)
#define SOC_IEEE1500_2_OCP_BASE                                                 (0x4a108000U)
#define SOC_TA_IEEE1500_2_OCP_TARG_BASE                                         (0x4a109000U)
#define SOC_SECURITYCORE_EVE1_BASE                                              (0x4a151000U)
#define SOC_TA_EVE1_FW_CFG_TARG_BASE                                            (0x4a152000U)
#define SOC_SECURITYCORE_IPU1_BASE                                              (0x4a15b000U)
#define SOC_TA_IPU1_FW_CFG_TARG_BASE                                            (0x4a15c000U)
#define SOC_SECURITYCORE_TPCC_BASE                                              (0x4a161000U)
#define SOC_TA_EDMA_TPCC_FW_CFG_TARG_BASE                                       (0x4a162000U)
#define SOC_SECURITYCORE_TPTC_BASE                                              (0x4a163000U)
#define SOC_TA_EDMA_TC0_FW_CFG_TARG_BASE                                        (0x4a164000U)
#define SOC_SECURITYCORE_MCASP1_BASE                                            (0x4a167000U)
#define SOC_TA_MCASP1_FW_CFG_TARG_BASE                                          (0x4a168000U)
#define SOC_SECURITYCORE_TSC_ADC_BASE                                           (0x4a16d000U)
#define SOC_TA_TSC_ADC_FW_CFG_TARG_BASE                                         (0x4a16e000U)
#define SOC_SECURITYCORE_DSP1_SDMA_BASE                                         (0x4a171000U)
#define SOC_TA_DSP1_FW_CFG_TARG_BASE                                            (0x4a172000U)
#define SOC_SECURITYCORE_DSP2_SDMA_BASE                                         (0x4a173000U)
#define SOC_TA_DSP2_FW_CFG_TARG_BASE                                            (0x4a174000U)
#define SOC_SECURITYCORE_QSPI_BASE                                              (0x4a179000U)
#define SOC_TA_QSPI_FW_CFG_TARG_BASE                                            (0x4a17a000U)
#define SOC_SMARTREFLEX_DSPEVE_BASE                                             (0x4a183000U)
#define SOC_TA_SMARTREFLEX_DSPEVE_TARG_BASE                                     (0x4a184000U)
#define SOC_SECURITYCORE_OCMC_ROM_BASE                                          (0x4a200000U)
#define SOC_TA_OCMC_ROM_FW_CFG_TARG_BASE                                        (0x4a201000U)
#define SOC_SECURITYCORE_OCP_FW_EMIF_5430_BASE                                  (0x4a20c000U)
#define SOC_TA_EMIF_OCP_FW_CFG_TARG_BASE                                        (0x4a20d000U)
#define SOC_SECURITYCORE_OCMC_RAM2_BASE                                         (0x4a20e000U)
#define SOC_TA_OCMC_RAM2_FW_CFG_TARG_BASE                                       (0x4a20f000U)
#define SOC_SECURITYCORE_GPMC_BASE                                              (0x4a210000U)
#define SOC_TA_GPMC_FW_CFG_TARG_BASE                                            (0x4a211000U)
#define SOC_SECURITYCORE_OCMC_RAM1_BASE                                         (0x4a212000U)
#define SOC_TA_OCMC_RAM1_FW_CFG_TARG_BASE                                       (0x4a213000U)
#define SOC_SECURITYCORE_DSS_BASE                                               (0x4a21c000U)
#define SOC_TA_DSS_FW_CFG_TARG_BASE                                             (0x4a21d000U)
#define SOC_SECURITYCORE_DEBUGSS_CT_TBR_BASE                                    (0x4a224000U)
#define SOC_TA_DEBUGSS_CT_TBR_FW_CFG_TARG_BASE                                  (0x4a225000U)
#define SOC_SECURITYCORE_L3_INSTR_BASE                                          (0x4a226000U)
#define SOC_TA_L3_INSTR_FW_CFG_TARG_BASE                                        (0x4a227000U)
#define SOC_SECURITYCORE_OCMC_RAM3_BASE                                         (0x4a22a000U)
#define SOC_TA_OCMC_RAM3_FW_CFG_TARG_BASE                                       (0x4a22b000U)
#define SOC_SECURITYCORE_AES1_BASE                                              (0x4a22c000U)
#define SOC_TA_AES1_FW_CFG_TARG_BASE                                            (0x4a22d000U)
#define SOC_SECURITYCORE_AES2_BASE                                              (0x4a22e000U)
#define SOC_TA_AES2_FW_CFG_TARG_BASE                                            (0x4a22f000U)
#define SOC_SECURITYCORE_SHA2MD5_P1_BASE                                        (0x4a230000U)
#define SOC_TA_SHA2MD5_1_FW_CFG_TARG_BASE                                       (0x4a231000U)
#define SOC_SECURITYCORE_SHA2MD5_P2_BASE                                        (0x4a232000U)
#define SOC_TA_SHA2MD5_2_FW_CFG_TARG_BASE                                       (0x4a233000U)
#define SOC_TA_UNKNOWN8_TARG_BASE                                               (0x4a23d000U)
#define SOC_SECURITYCORE_ISS_BASE                                               (0x4a23e000U)
#define SOC_TA_ISS_FW_CFG_TARG_BASE                                             (0x4a23f000U)
#define SOC_SECURITYCORE_TESOC_BASE                                             (0x4a240000U)
#define SOC_TA_TESOC_FW_CFG_TARG_BASE                                           (0x4a241000U)
#define SOC_TA_JESD_FW_CFG_TARG_BASE                                            (0x4a243000U)
#define SOC_SECURITYCORE_CRC_BASE                                               (0x4a244000U)
#define SOC_TA_CRC_FW_CFG_TARG_BASE                                             (0x4a245000U)
#define SOC_TA_TSC_ADC_DAT_TARG_BASE                                            (0x4a247000U)
#define SOC_TA_WD_TIMER3_TARG_BASE                                              (0x4a249000U)
#define SOC_TA_WD_TIMER4_TARG_BASE                                              (0x4a24b000U)
#define SOC_TA_WD_TIMER5_TARG_BASE                                              (0x4a24d000U)
#define SOC_TA_WD_TIMER6_TARG_BASE                                              (0x4a24f000U)
#define SOC_TA_WD_TIMER7_TARG_BASE                                              (0x4a251000U)
#define SOC_TA_WD_TIMER8_TARG_BASE                                              (0x4a253000U)
#define SOC_TA_WD_TIMER9_TARG_BASE                                              (0x4a255000U)
#define SOC_TA_WD_TIMER10_TARG_BASE                                             (0x4a257000U)
#define SOC_TA_UNKNOWN9_TARG_BASE                                               (0x4a259000U)
#define SOC_TA_UNKNOWN10_TARG_BASE                                              (0x4a25b000U)
#define SOC_TA_UNKNOWN11_TARG_BASE                                              (0x4a25d000U)
#define SOC_TA_UNKNOWN12_TARG_BASE                                              (0x4a25f000U)
#define SOC_TA_CRC_CFG_TARG_BASE                                                (0x4a261000U)
#define SOC_TA_EMIF_MPU_TARG_BASE                                               (0x4a263000U)
#define SOC_TSC_ADC_BASE                                                        (0x4a264000U)
#define SOC_TA_TSC_ADC_CFG_TARG_BASE                                            (0x4a265000U)
#define SOC_L4_WKUP_AP_BASE                                                     (0x4AE00000U)
#define SOC_COUNTER_32K_BASE                                                    (0x4ae04000U)
#define SOC_OCP_SOCKET_PRM_BASE                                                 (0x4ae06000U)
#define SOC_CKGEN_PRM_BASE                                                      (0x4ae06100U)
#define SOC_MPU_PRM_BASE                                                        (0x4ae06300U)
#define SOC_DSP1_PRM_BASE                                                       (0x4ae06400U)
#define SOC_IPU_PRM_BASE                                                        (0x4ae06500U)
#define SOC_COREAON_PRM_BASE                                                    (0x4ae06628U)
#define SOC_CORE_PRM_BASE                                                       (0x4ae06700U)
#define SOC_IVA_PRM_BASE                                                        (0x4ae06f00U)
#define SOC_CAM_PRM_BASE                                                        (0x4ae07000U)
#define SOC_DSS_PRM_BASE                                                        (0x4ae07100U)
#define SOC_GPU_PRM_BASE                                                        (0x4ae07200U)
#define SOC_L3INIT_PRM_BASE                                                     (0x4ae07300U)
#define SOC_L4PER_PRM_BASE                                                      (0x4ae07400U)
#define SOC_CUSTEFUSE_PRM_BASE                                                  (0x4ae07600U)
#define SOC_WKUPAON_PRM_BASE                                                    (0x4ae07724U)
#define SOC_WKUPAON_CM_BASE                                                     (0x4ae07800U)
#define SOC_EMU_PRM_BASE                                                        (0x4ae07900U)
#define SOC_EMU_CM_BASE                                                         (0x4ae07a00U)
#define SOC_DSP2_PRM_BASE                                                       (0x4ae07b00U)
#define SOC_EVE1_PRM_BASE                                                       (0x4ae07b40U)
#define SOC_EVE2_PRM_BASE                                                       (0x4ae07b80U)
#define SOC_EVE3_PRM_BASE                                                       (0x4ae07bc0U)
#define SOC_EVE4_PRM_BASE                                                       (0x4ae07c00U)
#define SOC_RTC_PRM_BASE                                                        (0x4ae07c60U)
#define SOC_VPE_PRM_BASE                                                        (0x4ae07c80U)
#define SOC_DEVICE_PRM_BASE                                                     (0x4ae07d00U)
#define SOC_INSTR_PRM_BASE                                                      (0x4ae07f00U)
#define SOC_CTRL_MODULE_WKUP_BASE                                               (0x4ae0c000U)
#define SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE                                (0x4ae0c100U)
#define SOC_CTRL_MODULE_WKUP_CORE_PAD_REGISTERS_BASE                            (0x4ae0c5a8U)
#define SOC_GPIO1_BASE                                                          (0x4ae10000U)
#define SOC_TIMER1_BASE                                                         (0x4ae18000U)
#define SOC_RTI1_BASE                                                           (0x4ae31000U)
#define SOC_RTI2_BASE                                                           (0x4ae33000U)
#define SOC_RTI3_BASE                                                           (0x4ae35000U)
#define SOC_RTI4_BASE                                                           (0x4ae37000U)
#define SOC_RTI5_BASE                                                           (0x4ae39000U)
#define SOC_DCAN1_BASE                                                          (0x4ae3c000U)
#define SOC_DCAN1_MESSAGERAM_BASE                                               (0x4ae3d000U)
#define SOC_QSPI_ADDRSP0_BASE                                                   (0x4b300000U)
#define SOC_TESOC_BASE                                                          (0x4b800000U)
#define SOC_CRC_BASE                                                            (0x4bc00000U)
#define SOC_EMIF1_CONF_REGS_BASE                                                (0x4c000000U)
#define SOC_GPMC_CONF_REGS_BASE                                                 (0x50000000U)
#define SOC_ISS_REGS_BASE                                                       (0x52000000U)
#define SOC_I_CSCTI_MPU_C0_BASE                                                 (0x54148000U)
#define SOC_I_CSCTI_MPU_C1_BASE                                                 (0x54149000U)
#define SOC_I_CSTF_BASE                                                         (0x54158000U)
#define SOC_I_DAP_PC_BASE                                                       (0x54159000U)
#define SOC_I_CSSTM_BASE                                                        (0x5415ac04U)
#define SOC_I_SGU_BASE                                                          (0x5415b000U)
#define SOC_I_CSCTI_BASE                                                        (0x5415c000U)
#define SOC_I_DRM_BASE                                                          (0x54160000U)
#define SOC_I_MIPI_STM_BASE                                                     (0x54161000U)
#define SOC_I_CSTPIU_BASE                                                       (0x54163000U)
#define SOC_I_CSTF1_BASE                                                        (0x54164000U)
#define SOC_I_DEBUGSS_OMAP5430_CFGBUS_CT_TBR_BASE                               (0x54167004U)
#define SOC_CT_UART_BASE                                                        (0x54168000U)
#define SOC_CSCTI_BASE                                                          (0x54169000U)
#define SOC_OCP2SCP_BASE                                                        (0x54171000U)
#define SOC_PLLCTRL_BASE                                                        (0x54171800U)
#define SOC_CT_TBR_BASE                                                         (0x54800000U)
#define SOC_DSSREG_BASE                                                         (0x58000000U)
#define SOC_VENC_BASE                                                           (0x58005000U)
#define SOC_DISPC_COMMON_BASE                                                   (0x58010000U)
#define SOC_DISPC_GFX1_BASE                                                     (0x58011000U)
#define SOC_DISPC_WB_BASE                                                       (0x58015000U)
#define SOC_DISPC_VID1_BASE                                                     (0x58017000U)
#define SOC_DISPC_VID2_BASE                                                     (0x58018000U)
#define SOC_DISPC_OVR1_BASE                                                     (0x5801a800U)
#define SOC_DISPC_OVR2_BASE                                                     (0x5801a900U)
#define SOC_DISPC_VP1_BASE                                                      (0x5801ac00U)
#define SOC_IPU1_TARGET_BASE                                                    (0x58800000U)
#define SOC_IPU1_TARGET_UNICACHE_MMU_BASE                                       (0x58880800U)
#define SOC_IPU1_TARGET_L2_MMU_BASE                                             (0x58882000U)
#define SOC_QSPI_ADDRSP1_BASE                                                   (0x5c000000U)
#define SOC_EMIF1_SDRAM_CS0_BASE                                                (0x80000000U)
#define SOC_EMIF1_SDRAM_CS1_BASE                                                (0xc0000000U)


/* Alias definitions required to reuse higher layer code across SoCs */
#define CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS                                  (0x1800000U)
#define CSL_DSP_DSP_XMC_CTRL_REGS                                               (SOC_DSP_XMC_CTRL_BASE)

#ifdef __cplusplus
}
#endif
#endif /* _SOC_H_ */
