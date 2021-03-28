/*
* hw_control_am43xx.h
*
* Register-level header file for CONTROL
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/ 
* 
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

#ifndef HW_CONTROL_AM43XX_H_
#define HW_CONTROL_AM43XX_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Pinmux mode configuration */
#define CONTROL_CONF_MUXMODE(n)        (n)

/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define CTRL_REVISION                                               (0x0U)
#define CTRL_HWINFO                                                 (0x4U)
#define CTRL_SYSCONFIG                                              (0x10U)
#define CTRL_STS                                                    (0x40U)
#define CTRL_BOOTSTAT                                               (0x44U)
#define CTRL_L4_FWCFG0_ROLE_CFG_LO                                  (0x80U)
#define CTRL_L4_FWCFG0_ROLE_CFG_HI                                  (0x84U)
#define CTRL_L4_FWCFG1_ROLE_CFG_LO                                  (0x88U)
#define CTRL_L4_FWCFG1_ROLE_CFG_HI                                  (0x8cU)
#define CTRL_L4_WKUPCFG0_ROLE_CFG_LO                                (0x90U)
#define CTRL_L4_WKUPCFG0_ROLE_CFG_HI                                (0x94U)
#define CTRL_L4_WKUPCFG1_ROLE_CFG_LO                                (0x98U)
#define CTRL_L4_WKUPCFG1_ROLE_CFG_HI                                (0x9cU)
#define CTRL_L4_PERCFG0_ROLE_CFG_LO                                 (0xa0U)
#define CTRL_L4_PERCFG0_ROLE_CFG_HI                                 (0xa4U)
#define CTRL_L4_PERCFG1_ROLE_CFG_LO                                 (0xa8U)
#define CTRL_L4_PERCFG1_ROLE_CFG_HI                                 (0xacU)
#define CTRL_L4_PERCFG2_ROLE_CFG_LO                                 (0xb0U)
#define CTRL_L4_PERCFG2_ROLE_CFG_HI                                 (0xb4U)
#define CTRL_L4_FASTCFG0_ROLE_CFG_LO                                (0xc0U)
#define CTRL_L4_FASTCFG0_ROLE_CFG_HI                                (0xc4U)
#define CTRL_L4_FASTCFG1_ROLE_CFG_LO                                (0xc8U)
#define CTRL_L4_FASTCFG1_ROLE_CFG_HI                                (0xccU)
#define CTRL_L4_FWCFG0_MEMBER_CFG                                   (0xd0U)
#define CTRL_L4_FWCFG1_MEMBER_CFG                                   (0xd4U)
#define CTRL_L4_WKUPCFG0_MEMBER_CFG                                 (0xd8U)
#define CTRL_L4_WKUPCFG1_MEMBER_CFG                                 (0xdcU)
#define CTRL_L4_PERCFG0_MEMBER_CFG                                  (0xe0U)
#define CTRL_L4_PERCFG1_MEMBER_CFG                                  (0xe4U)
#define CTRL_L4_PERCFG2_MEMBER_CFG                                  (0xe8U)
#define CTRL_L4_FASTCFG0_MEMBER_CFG                                 (0xf0U)
#define CTRL_L4_FASTCFG1_MEMBER_CFG                                 (0xf4U)
#define CTRL_SEC                                                    (0x100U)
#define CTRL_SEC_SW                                                 (0x104U)
#define CTRL_SEC_EMU                                                (0x108U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG                               (0x110U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2                             (0x114U)
#define CTRL_SW_CFG                                                 (0x118U)
#define CTRL_SW_CCFG                                                (0x11cU)
#define CTRL_MPK_0                                                  (0x120U)
#define CTRL_MPK_1                                                  (0x124U)
#define CTRL_MPK_2                                                  (0x128U)
#define CTRL_MPK_3                                                  (0x12cU)
#define CTRL_MPK_4                                                  (0x130U)
#define CTRL_MPK_5                                                  (0x134U)
#define CTRL_MPK_6                                                  (0x138U)
#define CTRL_MPK_7                                                  (0x13cU)
#define CTRL_MPK_8                                                  (0x140U)
#define CTRL_MPK_9                                                  (0x144U)
#define CTRL_MPK_10                                                 (0x148U)
#define CTRL_MPK_11                                                 (0x14cU)
#define CTRL_MPK_12                                                 (0x150U)
#define CTRL_MPK_13                                                 (0x154U)
#define CTRL_MPK_14                                                 (0x158U)
#define CTRL_MPK_15                                                 (0x15cU)
#define CTRL_SWRV_0                                                 (0x160U)
#define CTRL_SWRV_1                                                 (0x164U)
#define CTRL_SWRV_2                                                 (0x168U)
#define CTRL_SWRV_3                                                 (0x16cU)
#define CTRL_SWRV_4                                                 (0x170U)
#define CTRL_SWRV_5                                                 (0x174U)
#define CTRL_SWRV_6                                                 (0x178U)
#define CTRL_SEC_TAP                                                (0x180U)
#define CTRL_SEC_TAP_CMDIN                                          (0x184U)
#define CTRL_SEC_TAP_CMDOUT                                         (0x188U)
#define CTRL_SEC_TAP_DATIN                                          (0x18cU)
#define CTRL_SEC_TAP_DATOUT                                         (0x190U)
#define CTRL_MREQDOMAIN_EXP1                                        (0x198U)
#define CTRL_MREQDOMAIN_EXP2                                        (0x19cU)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0                                 (0x1a0U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1                                 (0x1a4U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF                                  (0x1a8U)
#define CTRL_SEC_LOAD_FW_EXP_VAL                                    (0x1acU)
#define CTRL_SEC_RO                                                 (0x1b4U)
#define CTRL_EMIF_OBFUSCATION_KEY                                   (0x1b8U)
#define CTRL_SEC_CLK                                                (0x1bcU)
#define CTRL_MREQDOMAIN_EXP3                                        (0x1d4U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2                                 (0x1d8U)
#define CTRL_TAMPER                                                 (0x1dcU)
#define CTRL_SEC_SPARE0                                             (0x1e0U)
#define CTRL_SEC_SPARE1                                             (0x1e4U)
#define CTRL_MEK_0                                                  (0x200U)
#define CTRL_MEK_1                                                  (0x204U)
#define CTRL_MEK_2                                                  (0x208U)
#define CTRL_MEK_3                                                  (0x20cU)
#define CTRL_MEK_4                                                  (0x210U)
#define CTRL_MEK_5                                                  (0x214U)
#define CTRL_MEK_6                                                  (0x218U)
#define CTRL_MEK_7                                                  (0x21cU)
#define CTRL_MSV_0                                                  (0x224U)
#define CTRL_MSV_BCH_0                                              (0x228U)
#define CTRL_MSV_BCH_1                                              (0x22cU)
#define CTRL_SEC_STS                                                (0x240U)
#define CTRL_SECMEM_STS                                             (0x244U)
#define CTRL_SEC_ERR_STAT_FUNC0                                     (0x248U)
#define CTRL_SEC_ERR_STAT_FUNC1                                     (0x24cU)
#define CTRL_SEC_ERR_STAT_DBUG0                                     (0x250U)
#define CTRL_SEC_ERR_STAT_DBUG1                                     (0x254U)
#define CTRL_KEK_SW_0                                               (0x260U)
#define CTRL_KEK_SW_1                                               (0x264U)
#define CTRL_KEK_SW_2                                               (0x268U)
#define CTRL_KEK_SW_3                                               (0x26cU)
#define CTRL_KEK_SW_4                                               (0x270U)
#define CTRL_KEK_SW_5                                               (0x274U)
#define CTRL_KEK_SW_6                                               (0x278U)
#define CTRL_KEK_SW_7                                               (0x27cU)
#define CTRL_SMEK_0                                                 (0x280U)
#define CTRL_SMEK_1                                                 (0x284U)
#define CTRL_SMEK_2                                                 (0x288U)
#define CTRL_SMEK_3                                                 (0x28cU)
#define CTRL_SMEK_4                                                 (0x290U)
#define CTRL_SMEK_5                                                 (0x294U)
#define CTRL_SMEK_6                                                 (0x298U)
#define CTRL_SMEK_7                                                 (0x29cU)
#define CTRL_SMPK_0                                                 (0x2b0U)
#define CTRL_SMPK_1                                                 (0x2b4U)
#define CTRL_SMPK_2                                                 (0x2b8U)
#define CTRL_SMPK_3                                                 (0x2bcU)
#define CTRL_SMPK_4                                                 (0x2c0U)
#define CTRL_SMPK_5                                                 (0x2c4U)
#define CTRL_SMPK_6                                                 (0x2c8U)
#define CTRL_SMPK_7                                                 (0x2ccU)
#define CTRL_SMPK_8                                                 (0x2d0U)
#define CTRL_SMPK_9                                                 (0x2d4U)
#define CTRL_SMPK_10                                                (0x2d8U)
#define CTRL_SMPK_11                                                (0x2dcU)
#define CTRL_SMPK_12                                                (0x2e0U)
#define CTRL_SMPK_13                                                (0x2e4U)
#define CTRL_SMPK_14                                                (0x2e8U)
#define CTRL_SMPK_15                                                (0x2ecU)
#define CTRL_SMPK_BCH_0                                             (0x380U)
#define CTRL_SMPK_BCH_1                                             (0x384U)
#define CTRL_SMPK_BCH_2                                             (0x388U)
#define CTRL_SMPK_BCH_3                                             (0x38cU)
#define CTRL_SMPK_BCH_4                                             (0x390U)
#define CTRL_SMPK_BCH_5                                             (0x394U)
#define CTRL_SMPK_BCH_6                                             (0x398U)
#define CTRL_SMPK_BCH_7                                             (0x39cU)
#define CTRL_SMPK_BCH_8                                             (0x3a0U)
#define CTRL_SMPK_BCH_9                                             (0x3a4U)
#define CTRL_SMPK_BCH_10                                            (0x3a8U)
#define CTRL_SMPK_BCH_11                                            (0x3acU)
#define CTRL_SMPK_BCH_12                                            (0x3b0U)
#define CTRL_SMPK_BCH_13                                            (0x3b4U)
#define CTRL_SMPK_BCH_14                                            (0x3b8U)
#define CTRL_SMPK_BCH_15                                            (0x3bcU)
#define CTRL_SMPK_BCH_16                                            (0x3c0U)
#define CTRL_SMPK_BCH_17                                            (0x3c4U)
#define CTRL_SMPK_BCH_18                                            (0x3c8U)
#define CTRL_SMPK_BCH_19                                            (0x3ccU)
#define CTRL_SMEK_BCH_0                                             (0x3d0U)
#define CTRL_SMEK_BCH_1                                             (0x3d4U)
#define CTRL_SMEK_BCH_2                                             (0x3d8U)
#define CTRL_SMEK_BCH_3                                             (0x3dcU)
#define CTRL_SMEK_BCH_4                                             (0x3e0U)
#define CTRL_SMEK_BCH_5                                             (0x3e4U)
#define CTRL_SMEK_BCH_6                                             (0x3e8U)
#define CTRL_SMEK_BCH_7                                             (0x3ecU)
#define CTRL_SMEK_BCH_8                                             (0x3f0U)
#define CTRL_SMEK_BCH_9                                             (0x3f4U)
#define CTRL_CANARY_TUN_SEL_0                                       (0x3800U)
#define CTRL_CANARY_TUN_SEL_1                                       (0x3804U)
#define CTRL_CANARY_TUN_SEL_2                                       (0x3808U)
#define CTRL_CANARY_TUN_SEL_3                                       (0x380cU)
#define CTRL_CANARY_TUN_SEL_4                                       (0x3810U)
#define CTRL_CANARY_TUN_SEL_5                                       (0x3814U)
#define CTRL_CANARY_TUN_SEL_6                                       (0x3818U)
#define CTRL_CANARY_TUN_SEL_7                                       (0x381cU)
#define CTRL_CANARY_TUN_SEL_8                                       (0x3820U)
#define CTRL_CANARY_TUN_SEL_9                                       (0x3824U)
#define CTRL_CANARY_TUN_SEL_10                                      (0x3828U)
#define CTRL_CANARY_TUN_SEL_11                                      (0x382cU)
#define CTRL_CANARY_TUN_SEL_12                                      (0x3830U)
#define CTRL_CANARY_TUN_SEL_13                                      (0x3834U)
#define CTRL_CANARY_TUN_SEL_14                                      (0x3838U)
#define CTRL_CANARY_TUN_SEL_15                                      (0x383cU)
#define CTRL_CANARY_EN_0                                            (0x3880U)
#define CTRL_CANARY_EN_1                                            (0x3884U)
#define CTRL_CANARY_STAT_0                                          (0x3890U)
#define CTRL_CANARY_STAT_1                                          (0x3894U)
#define CTRL_CANARY_FSM                                             (0x38a0U)
#define CTRL_SSM_END_FAST_SECRAM                                    (0x300U)
#define CTRL_SSM_END_L3_SECRAM                                      (0x36cU)
#define CTRL_SSM_START_L3_SECRAM                                    (0x370U)
#define CTRL_CORTEX_VBBLDO                                          (0x41cU)
#define CTRL_CORE_SLDO                                              (0x428U)
#define CTRL_MPU_SLDO                                               (0x42cU)
#define CTRL_CLK32KDIVRATIO                                         (0x444U)
#define CTRL_BANDGAP                                                (0x448U)
#define CTRL_BANDGAP_TRIM                                           (0x44cU)
#define CTRL_PLL_CLKINPULOW                                         (0x458U)
#define CTRL_MOSC                                                   (0x468U)
#define CTRL_SMA7                                                   (0x46cU)
#define CTRL_DEEPSLEEP                                              (0x470U)
#define CTRL_PE_SCRATCHPAD_0                                        (0x500U)
#define CTRL_PE_SCRATCHPAD_1                                        (0x504U)
#define CTRL_PE_SCRATCHPAD_2                                        (0x508U)
#define CTRL_DPLL_PWR_SW_STS                                        (0x50cU)
#define CTRL_PE_SCRATCHPAD_3                                        (0x510U)
#define CTRL_PE_SCRATCHPAD_4                                        (0x514U)
#define CTRL_PE_SCRATCHPAD_5                                        (0x518U)
#define CTRL_DISPLAY_PLL_SEL                                        (0x534U)
#define CTRL_USIM                                                   (0x538U)
#define CTRL_DEVICE_ID                                              (0x600U)
#define CTRL_DEV_FEATURE                                            (0x604U)
#define CTRL_INIT_PRIORITY_0                                        (0x608U)
#define CTRL_INIT_PRIORITY_1                                        (0x60cU)
#define CTRL_DEV_ATTR                                               (0x610U)
#define CTRL_TPTC_CFG                                               (0x614U)
#define CTRL_OCMC_CFG                                               (0x618U)
#define CTRL_USB_CTRL0                                              (0x620U)
#define CTRL_USB_STS0                                               (0x624U)
#define CTRL_USB_CTRL1                                              (0x628U)
#define CTRL_USB_STS1                                               (0x62cU)
#define CTRL_MAC_ID0_LO                                             (0x630U)
#define CTRL_MAC_ID0_HI                                             (0x634U)
#define CTRL_MAC_ID1_LO                                             (0x638U)
#define CTRL_MAC_ID1_HI                                             (0x63cU)
#define CTRL_DCAN_RAMINIT                                           (0x644U)
#define CTRL_SMA5                                                   (0x648U)
#define CTRL_USB_CTRL2                                              (0x64cU)
#define CTRL_GMII_SEL                                               (0x650U)
#define CTRL_MPUSS                                                  (0x654U)
#define CTRL_TIMER_CASCADE                                          (0x658U)
#define CTRL_PWMSS                                                  (0x664U)
#define CTRL_MREQPRIO_0                                             (0x670U)
#define CTRL_MREQPRIO_1                                             (0x674U)
#define CTRL_HW_EVT_SEL_GRP1                                        (0x690U)
#define CTRL_HW_EVT_SEL_GRP2                                        (0x694U)
#define CTRL_HW_EVT_SEL_GRP3                                        (0x698U)
#define CTRL_HW_EVT_SEL_GRP4                                        (0x69cU)
#define CTRL_SMRT                                                   (0x6a0U)
#define CTRL_MPUSS_HW_DBG_SEL                                       (0x6a4U)
#define CTRL_MPUSS_HW_DBG_INFO                                      (0x6a8U)
#define CTRL_MRGN_MODE0                                             (0x6c0U)
#define CTRL_MRGN_MODE1                                             (0x6c4U)
#define CTRL_VDD_MPU_OPP_050                                        (0x770U)
#define CTRL_VDD_MPU_OPP_100                                        (0x774U)
#define CTRL_VDD_MPU_OPP_119                                        (0x778U)
#define CTRL_VDD_MPU_OPP_TURBO                                      (0x77cU)
#define CTRL_VDD_MPU_OPP_NITRO                                      (0x780U)
#define CTRL_VDD_CORE_OPP_050                                       (0x7b8U)
#define CTRL_VDD_CORE_OPP_100                                       (0x7bcU)
#define CTRL_BB_SCALE                                               (0x7d0U)
#define CTRL_USB_VIDPID                                             (0x7f4U)
#define CTRL_EFUSE_SMA                                              (0x7fcU)
#define CTRL_RESET_ISO                                              (0x1000U)
#define CTRL_DPLL_PWR_SW                                            (0x1318U)
#define CTRL_DDR_CKE                                                (0x131cU)
#define CTRL_SMA2                                                   (0x1320U)
#define CTRL_WAKEM3_TXEV_EOI                                        (0x1324U)
#define CTRL_IPC_MSG_REG0                                           (0x1328U)
#define CTRL_IPC_MSG_REG1                                           (0x132cU)
#define CTRL_IPC_MSG_REG2                                           (0x1330U)
#define CTRL_IPC_MSG_REG3                                           (0x1334U)
#define CTRL_IPC_MSG_REG4                                           (0x1338U)
#define CTRL_IPC_MSG_REG5                                           (0x133cU)
#define CTRL_IPC_MSG_REG6                                           (0x1340U)
#define CTRL_IPC_MSG_REG7                                           (0x1344U)
#define CTRL_IPC_MSG_REG8                                           (0x1348U)
#define CTRL_IPC_MSG_REG9                                           (0x134cU)
#define CTRL_IPC_MSG_REG10                                          (0x1350U)
#define CTRL_IPC_MSG_REG11                                          (0x1354U)
#define CTRL_IPC_MSG_REG12                                          (0x1358U)
#define CTRL_IPC_MSG_REG13                                          (0x135cU)
#define CTRL_IPC_MSG_REG14                                          (0x1360U)
#define CTRL_IPC_INTR                                               (0x1364U)
#define CTRL_DPLL_PWR_SW_CTRL2                                      (0x138cU)
#define CTRL_DPLL_PWR_SW_STS2                                       (0x1390U)
#define CTRL_SMA4                                                   (0x1394U)
#define CTRL_CQDETECT_STS                                           (0xe00U)
#define CTRL_DDR_IO                                                 (0xe04U)
#define CTRL_CQDETECT_STS2                                          (0xe08U)
#define CTRL_VTP                                                    (0xe0cU)
#define CTRL_VREF                                                   (0xe14U)
#define CTRL_TPCC_EVT_MUX_0_3                                       (0xf90U)
#define CTRL_TPCC_EVT_MUX_4_7                                       (0xf94U)
#define CTRL_TPCC_EVT_MUX_8_11                                      (0xf98U)
#define CTRL_TPCC_EVT_MUX_12_15                                     (0xf9cU)
#define CTRL_TPCC_EVT_MUX_16_19                                     (0xfa0U)
#define CTRL_TPCC_EVT_MUX_20_23                                     (0xfa4U)
#define CTRL_TPCC_EVT_MUX_24_27                                     (0xfa8U)
#define CTRL_TPCC_EVT_MUX_28_31                                     (0xfacU)
#define CTRL_TPCC_EVT_MUX_32_35                                     (0xfb0U)
#define CTRL_TPCC_EVT_MUX_36_39                                     (0xfb4U)
#define CTRL_TPCC_EVT_MUX_40_43                                     (0xfb8U)
#define CTRL_TPCC_EVT_MUX_44_47                                     (0xfbcU)
#define CTRL_TPCC_EVT_MUX_48_51                                     (0xfc0U)
#define CTRL_TPCC_EVT_MUX_52_55                                     (0xfc4U)
#define CTRL_TPCC_EVT_MUX_56_59                                     (0xfc8U)
#define CTRL_TPCC_EVT_MUX_60_63                                     (0xfccU)
#define CTRL_TIMER_EVT_CAPT                                         (0xfd0U)
#define CTRL_ECAP_EVT_CAPT                                          (0xfd4U)
#define CTRL_ADC_EVT_CAPT                                           (0xfd8U)
#define CTRL_MAG_EVT_CAPT                                           (0xfdcU)
#define CTRL_DDR_ADDRCTRL_IOCTRL                                    (0x1404U)
#define CTRL_DDR_ADDRCTRL_WD0_IOCTRL                                (0x1408U)
#define CTRL_DDR_ADDRCTRL_WD1_IOCTRL                                (0x140cU)
#define CTRL_DDR_DATA0_IOCTRL                                       (0x1440U)
#define CTRL_DDR_DATA1_IOCTRL                                       (0x1444U)
#define CTRL_DDR_DATA2_IOCTRL                                       (0x1448U)
#define CTRL_DDR_DATA3_IOCTRL                                       (0x144cU)
#define CTRL_EMIF_SDRAM_CONFIG_EXT                                  (0x1460U)
#define CTRL_EMIF_SDRAM_STS_EXT                                     (0x1464U)
#define CTRL_PRINTER                                                (0x2000U)
#define CTRL_STRB_CNTR_LOAD_VAL                                     (0x2004U)
#define CTRL_STRB_CNTR_LOAD                                         (0x2008U)
#define CTRL_STRB_CNTR_EOI                                          (0x200cU)
#define CTRL_STRB_CNTR                                              (0x2010U)
#define CTRL_SPI_CNTR_LOAD_VAL                                      (0x2014U)
#define CTRL_SPI_CNTR_LOAD_STRB                                     (0x2018U)
#define CTRL_SPI_CNTR_EOI                                           (0x201cU)
#define CTRL_PRINTER_TIMER_TIMEOUT                                  (0x2020U)
#define CTRL_DIE_ID2                                                (0x1824U)
#define CTRL_ID_UNLOCK1                                             (0x1828U)
#define CTRL_ID_UNLOCK2                                             (0x182cU)
#define CTRL_DIE_ID0                                                (0x183cU)
#define CTRL_ID_UNLOCK0                                             (0x1844U)
#define CTRL_DIE_ID1                                                (0x1848U)
#define CTRL_ID_UNLOCK3                                             (0x184cU)
#define CTRL_DIE_ID3                                                (0x1850U)
#define CTRL_DISPPLL_CLKCTRL                                        (0x3000U)
#define CTRL_DISPPLL_TEN                                            (0x3004U)
#define CTRL_DISPPLL_TENIV                                          (0x3008U)
#define CTRL_DISPPLL_M2NDIV                                         (0x300cU)
#define CTRL_DISPPLL_MN2DIV                                         (0x3010U)
#define CTRL_DISPPLL_FRACDIV                                        (0x3014U)
#define CTRL_DISPPLL_BWCTRL                                         (0x3018U)
#define CTRL_DISPPLL_FRACCTRL                                       (0x301cU)
#define CTRL_DISPPLL_STS                                            (0x3020U)
#define CTRL_DISPPLL_M3DIV                                          (0x3024U)
#define CTRL_DISPPLL_RAMPCTRL                                       (0x3028U)
#define CTRL_CONF_GPMC_AD0                                          (0x800U)
#define CTRL_CONF_GPMC_AD1                                          (0x804U)
#define CTRL_CONF_GPMC_AD2                                          (0x808U)
#define CTRL_CONF_GPMC_AD3                                          (0x80cU)
#define CTRL_CONF_GPMC_AD4                                          (0x810U)
#define CTRL_CONF_GPMC_AD5                                          (0x814U)
#define CTRL_CONF_GPMC_AD6                                          (0x818U)
#define CTRL_CONF_GPMC_AD7                                          (0x81cU)
#define CTRL_CONF_GPMC_AD8                                          (0x820U)
#define CTRL_CONF_GPMC_AD9                                          (0x824U)
#define CTRL_CONF_GPMC_AD10                                         (0x828U)
#define CTRL_CONF_GPMC_AD11                                         (0x82cU)
#define CTRL_CONF_GPMC_AD12                                         (0x830U)
#define CTRL_CONF_GPMC_AD13                                         (0x834U)
#define CTRL_CONF_GPMC_AD14                                         (0x838U)
#define CTRL_CONF_GPMC_AD15                                         (0x83cU)
#define CTRL_CONF_GPMC_A0                                           (0x840U)
#define CTRL_CONF_GPMC_A1                                           (0x844U)
#define CTRL_CONF_GPMC_A2                                           (0x848U)
#define CTRL_CONF_GPMC_A3                                           (0x84cU)
#define CTRL_CONF_GPMC_A4                                           (0x850U)
#define CTRL_CONF_GPMC_A5                                           (0x854U)
#define CTRL_CONF_GPMC_A6                                           (0x858U)
#define CTRL_CONF_GPMC_A7                                           (0x85cU)
#define CTRL_CONF_GPMC_A8                                           (0x860U)
#define CTRL_CONF_GPMC_A9                                           (0x864U)
#define CTRL_CONF_GPMC_A10                                          (0x868U)
#define CTRL_CONF_GPMC_A11                                          (0x86cU)
#define CTRL_CONF_GPMC_WAIT0                                        (0x870U)
#define CTRL_CONF_GPMC_WPN                                          (0x874U)
#define CTRL_CONF_GPMC_BE1N                                         (0x878U)
#define CTRL_CONF_GPMC_CSN0                                         (0x87cU)
#define CTRL_CONF_GPMC_CSN1                                         (0x880U)
#define CTRL_CONF_GPMC_CSN2                                         (0x884U)
#define CTRL_CONF_GPMC_CSN3                                         (0x888U)
#define CTRL_CONF_GPMC_CLK                                          (0x88cU)
#define CTRL_CONF_GPMC_ADVN_ALE                                     (0x890U)
#define CTRL_CONF_GPMC_OEN_REN                                      (0x894U)
#define CTRL_CONF_GPMC_WEN                                          (0x898U)
#define CTRL_CONF_GPMC_BE0N_CLE                                     (0x89cU)
#define CTRL_CONF_LCD_DATA0                                         (0x8a0U)
#define CTRL_CONF_LCD_DATA1                                         (0x8a4U)
#define CTRL_CONF_LCD_DATA2                                         (0x8a8U)
#define CTRL_CONF_LCD_DATA3                                         (0x8acU)
#define CTRL_CONF_LCD_DATA4                                         (0x8b0U)
#define CTRL_CONF_LCD_DATA5                                         (0x8b4U)
#define CTRL_CONF_LCD_DATA6                                         (0x8b8U)
#define CTRL_CONF_LCD_DATA7                                         (0x8bcU)
#define CTRL_CONF_LCD_DATA8                                         (0x8c0U)
#define CTRL_CONF_LCD_DATA9                                         (0x8c4U)
#define CTRL_CONF_LCD_DATA10                                        (0x8c8U)
#define CTRL_CONF_LCD_DATA11                                        (0x8ccU)
#define CTRL_CONF_LCD_DATA12                                        (0x8d0U)
#define CTRL_CONF_LCD_DATA13                                        (0x8d4U)
#define CTRL_CONF_LCD_DATA14                                        (0x8d8U)
#define CTRL_CONF_LCD_DATA15                                        (0x8dcU)
#define CTRL_CONF_LCD_VSYNC                                         (0x8e0U)
#define CTRL_CONF_LCD_HSYNC                                         (0x8e4U)
#define CTRL_CONF_LCD_PCLK                                          (0x8e8U)
#define CTRL_CONF_LCD_AC_BIAS_EN                                    (0x8ecU)
#define CTRL_CONF_MMC0_DAT3                                         (0x8f0U)
#define CTRL_CONF_MMC0_DAT2                                         (0x8f4U)
#define CTRL_CONF_MMC0_DAT1                                         (0x8f8U)
#define CTRL_CONF_MMC0_DAT0                                         (0x8fcU)
#define CTRL_CONF_MMC0_CLK                                          (0x900U)
#define CTRL_CONF_MMC0_CMD                                          (0x904U)
#define CTRL_CONF_MII1_COL                                          (0x908U)
#define CTRL_CONF_MII1_CRS                                          (0x90cU)
#define CTRL_CONF_MII1_RXERR                                        (0x910U)
#define CTRL_CONF_MII1_TXEN                                         (0x914U)
#define CTRL_CONF_MII1_RXDV                                         (0x918U)
#define CTRL_CONF_MII1_TXD3                                         (0x91cU)
#define CTRL_CONF_MII1_TXD2                                         (0x920U)
#define CTRL_CONF_MII1_TXD1                                         (0x924U)
#define CTRL_CONF_MII1_TXD0                                         (0x928U)
#define CTRL_CONF_MII1_TXCLK                                        (0x92cU)
#define CTRL_CONF_MII1_RXCLK                                        (0x930U)
#define CTRL_CONF_MII1_RXD3                                         (0x934U)
#define CTRL_CONF_MII1_RXD2                                         (0x938U)
#define CTRL_CONF_MII1_RXD1                                         (0x93cU)
#define CTRL_CONF_MII1_RXD0                                         (0x940U)
#define CTRL_CONF_RMII1_REFCLK                                      (0x944U)
#define CTRL_CONF_MDIO_DATA                                         (0x948U)
#define CTRL_CONF_MDIO_CLK                                          (0x94cU)
#define CTRL_CONF_SPI0_SCLK                                         (0x950U)
#define CTRL_CONF_SPI0_D0                                           (0x954U)
#define CTRL_CONF_SPI0_D1                                           (0x958U)
#define CTRL_CONF_SPI0_CS0                                          (0x95cU)
#define CTRL_CONF_SPI0_CS1                                          (0x960U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT                                 (0x964U)
#define CTRL_CONF_UART0_CTSN                                        (0x968U)
#define CTRL_CONF_UART0_RTSN                                        (0x96cU)
#define CTRL_CONF_UART0_RXD                                         (0x970U)
#define CTRL_CONF_UART0_TXD                                         (0x974U)
#define CTRL_CONF_UART1_CTSN                                        (0x978U)
#define CTRL_CONF_UART1_RTSN                                        (0x97cU)
#define CTRL_CONF_UART1_RXD                                         (0x980U)
#define CTRL_CONF_UART1_TXD                                         (0x984U)
#define CTRL_CONF_I2C0_SDA                                          (0x988U)
#define CTRL_CONF_I2C0_SCL                                          (0x98cU)
#define CTRL_CONF_MCASP0_ACLKX                                      (0x990U)
#define CTRL_CONF_MCASP0_FSX                                        (0x994U)
#define CTRL_CONF_MCASP0_AXR0                                       (0x998U)
#define CTRL_CONF_MCASP0_AHCLKR                                     (0x99cU)
#define CTRL_CONF_MCASP0_ACLKR                                      (0x9a0U)
#define CTRL_CONF_MCASP0_FSR                                        (0x9a4U)
#define CTRL_CONF_MCASP0_AXR1                                       (0x9a8U)
#define CTRL_CONF_MCASP0_AHCLKX                                     (0x9acU)
#define CTRL_CONF_CCDC0_HD                                          (0x9b0U)
#define CTRL_CONF_CCDC0_VD                                          (0x9b4U)
#define CTRL_CONF_CCDC0_FIELD                                       (0x9b8U)
#define CTRL_CONF_CCDC0_WEN                                         (0x9bcU)
#define CTRL_CONF_CCDC0_PCLK                                        (0x9c0U)
#define CTRL_CONF_CCDC0_DATA8                                       (0x9c4U)
#define CTRL_CONF_CCDC0_DATA9                                       (0x9c8U)
#define CTRL_CONF_CCDC1_DATA9                                       (0x9ccU)
#define CTRL_CONF_CCDC1_DATA8                                       (0x9d0U)
#define CTRL_CONF_CCDC1_HD                                          (0x9d4U)
#define CTRL_CONF_CCDC1_VD                                          (0x9d8U)
#define CTRL_CONF_CCDC1_PCLK                                        (0x9dcU)
#define CTRL_CONF_CCDC1_FIELD                                       (0x9e0U)
#define CTRL_CONF_CCDC1_WEN                                         (0x9e4U)
#define CTRL_CONF_CCDC1_DATA0                                       (0x9e8U)
#define CTRL_CONF_CCDC1_DATA1                                       (0x9ecU)
#define CTRL_CONF_CCDC1_DATA2                                       (0x9f0U)
#define CTRL_CONF_CCDC1_DATA3                                       (0x9f4U)
#define CTRL_CONF_CCDC1_DATA4                                       (0x9f8U)
#define CTRL_CONF_CCDC1_DATA5                                       (0x9fcU)
#define CTRL_CONF_CCDC1_DATA6                                       (0xa00U)
#define CTRL_CONF_CCDC1_DATA7                                       (0xa04U)
#define CTRL_CONF_CCDC0_DATA0                                       (0xa08U)
#define CTRL_CONF_CCDC0_DATA1                                       (0xa0cU)
#define CTRL_CONF_CCDC0_DATA2                                       (0xa10U)
#define CTRL_CONF_CCDC0_DATA3                                       (0xa14U)
#define CTRL_CONF_CCDC0_DATA4                                       (0xa18U)
#define CTRL_CONF_CCDC0_DATA5                                       (0xa1cU)
#define CTRL_CONF_CCDC0_DATA6                                       (0xa20U)
#define CTRL_CONF_CCDC0_DATA7                                       (0xa24U)
#define CTRL_CONF_UART3_RXD                                         (0xa28U)
#define CTRL_CONF_UART3_TXD                                         (0xa2cU)
#define CTRL_CONF_UART3_CTSN                                        (0xa30U)
#define CTRL_CONF_UART3_RTSN                                        (0xa34U)
#define CTRL_CONF_PRINT_NSTROBE                                     (0xa38U)
#define CTRL_CONF_PRINT_MA                                          (0xa3cU)
#define CTRL_CONF_PRINT_MNA                                         (0xa40U)
#define CTRL_CONF_PRINT_MB                                          (0xa44U)
#define CTRL_CONF_PRINT_MNB                                         (0xa48U)
#define CTRL_CONF_PRINT_ON                                          (0xa4cU)
#define CTRL_CONF_SPI4_SCLK                                         (0xa50U)
#define CTRL_CONF_SPI4_D0                                           (0xa54U)
#define CTRL_CONF_SPI4_D1                                           (0xa58U)
#define CTRL_CONF_SPI4_CS0                                          (0xa5cU)
#define CTRL_CONF_SPI2_SCLK                                         (0xa60U)
#define CTRL_CONF_SPI2_D0                                           (0xa64U)
#define CTRL_CONF_SPI2_D1                                           (0xa68U)
#define CTRL_CONF_SPI2_CS0                                          (0xa6cU)
#define CTRL_CONF_TM_PIO_12                                         (0xad8U)
#define CTRL_CONF_TM_PIO_4                                          (0xadcU)
#define CTRL_CONF_TM_PIO_13                                         (0xae0U)
#define CTRL_CONF_TM_PIO_5                                          (0xae4U)
#define CTRL_CONF_TM_PIO_14                                         (0xae8U)
#define CTRL_CONF_TM_PIO_6                                          (0xaecU)
#define CTRL_CONF_TM_PIO_15                                         (0xaf0U)
#define CTRL_CONF_TM_PIO_7                                          (0xaf4U)
#define CTRL_CONF_TM_PIO_8                                          (0xaf8U)
#define CTRL_CONF_TM_PIO_0                                          (0xafcU)
#define CTRL_CONF_TM_PIO_9                                          (0xb00U)
#define CTRL_CONF_TM_PIO_1                                          (0xb04U)
#define CTRL_CONF_TM_PIO_10                                         (0xb08U)
#define CTRL_CONF_TM_PIO_2                                          (0xb0cU)
#define CTRL_CONF_TM_PIO_11                                         (0xb10U)
#define CTRL_CONF_TM_PIO_3                                          (0xb14U)
#define CTRL_CONF_TAMPER_EVT                                        (0xb18U)
#define CTRL_CONF_XDMA_EVT_INTR0                                    (0xa70U)
#define CTRL_CONF_XDMA_EVT_INTR1                                    (0xa74U)
#define CTRL_CONF_CLKREQ                                            (0xa78U)
#define CTRL_CONF_NRESETIN_OUT                                      (0xa7cU)
#define CTRL_CONF_PORZ                                              (0xa80U)
#define CTRL_CONF_NNMI                                              (0xa84U)
#define CTRL_CONF_OSC0_IN                                           (0xa88U)
#define CTRL_CONF_OSC0_OUT                                          (0xa8cU)
#define CTRL_CONF_TMS                                               (0xa90U)
#define CTRL_CONF_TDI                                               (0xa94U)
#define CTRL_CONF_TDO                                               (0xa98U)
#define CTRL_CONF_TCK                                               (0xa9cU)
#define CTRL_CONF_NTRST                                             (0xaa0U)
#define CTRL_CONF_EMU0                                              (0xaa4U)
#define CTRL_CONF_EMU1                                              (0xaa8U)
#define CTRL_CONF_OSC1_IN                                           (0xaacU)
#define CTRL_CONF_OSC1_OUT                                          (0xab0U)
#define CTRL_CONF_RTC_PORZ                                          (0xab4U)
#define CTRL_CONF_EXT_WAKEUP0                                       (0xab8U)
#define CTRL_CONF_PMIC_POWER_EN0                                    (0xabcU)
#define CTRL_CONF_USB0_DRVVBUS                                      (0xac0U)
#define CTRL_CONF_USB1_DRVVBUS                                      (0xac4U)
#define CTRL_CONF_TEST_EN                                           (0xac8U)
#define CTRL_CONF_IFORCE                                            (0xaccU)
#define CTRL_CONF_VSENSE                                            (0xad0U)
#define CTRL_CONF_TESTOUT                                           (0xad4U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define CTRL_REVISION_IP_REV_MINOR_SHIFT                                                (0U)
#define CTRL_REVISION_IP_REV_MINOR_MASK                                                 (0x0000003fU)

#define CTRL_REVISION_IP_REV_CUSTOM_SHIFT                                               (6U)
#define CTRL_REVISION_IP_REV_CUSTOM_MASK                                                (0x000000c0U)

#define CTRL_REVISION_IP_REV_MAJOR_SHIFT                                                (8U)
#define CTRL_REVISION_IP_REV_MAJOR_MASK                                                 (0x00000700U)

#define CTRL_REVISION_IP_REV_RTL_SHIFT                                                  (11U)
#define CTRL_REVISION_IP_REV_RTL_MASK                                                   (0x0000f800U)

#define CTRL_REVISION_IP_REV_FUNC_SHIFT                                                 (16U)
#define CTRL_REVISION_IP_REV_FUNC_MASK                                                  (0x0fff0000U)

#define CTRL_REVISION_IP_REV_SCHEME_SHIFT                                               (30U)
#define CTRL_REVISION_IP_REV_SCHEME_MASK                                                (0xc0000000U)

#define CTRL_HWINFO_IP_SHIFT                                                            (0U)
#define CTRL_HWINFO_IP_MASK                                                             (0xffffffffU)

#define CTRL_SYSCONFIG_FREEEMU_SHIFT                                                    (1U)
#define CTRL_SYSCONFIG_FREEEMU_MASK                                                     (0x00000002U)

#define CTRL_SYSCONFIG_IDLEMODE_SHIFT                                                   (2U)
#define CTRL_SYSCONFIG_IDLEMODE_MASK                                                    (0x0000000cU)

#define CTRL_SYSCONFIG_STANDBY_SHIFT                                                    (4U)
#define CTRL_SYSCONFIG_STANDBY_MASK                                                     (0x00000030U)

#define CTRL_STS_SYSBOOT0_SHIFT                                                         (0U)
#define CTRL_STS_SYSBOOT0_MASK                                                          (0x000000ffU)

#define CTRL_STS_DEVTYPE_SHIFT                                                          (8U)
#define CTRL_STS_DEVTYPE_MASK                                                           (0x00000700U)

#define CTRL_STS_BW_SHIFT                                                               (16U)
#define CTRL_STS_BW_MASK                                                                (0x00010000U)

#define CTRL_STS_WAITEN_SHIFT                                                           (17U)
#define CTRL_STS_WAITEN_MASK                                                            (0x00020000U)

#define CTRL_STS_ADMUX_SHIFT                                                            (18U)
#define CTRL_STS_ADMUX_MASK                                                             (0x000c0000U)

#define CTRL_STS_SYSBOOT13_12_SHIFT                                                     (20U)
#define CTRL_STS_SYSBOOT13_12_MASK                                                      (0x00300000U)

#define CTRL_STS_SYSBOOT15_14_SHIFT                                                     (22U)
#define CTRL_STS_SYSBOOT15_14_MASK                                                      (0x00c00000U)

#define CTRL_STS_SYSBOOT16_SHIFT                                                        (24U)
#define CTRL_STS_SYSBOOT16_MASK                                                         (0x01000000U)

#define CTRL_STS_SYSBOOT17_SHIFT                                                        (25U)
#define CTRL_STS_SYSBOOT17_MASK                                                         (0x02000000U)

#define CTRL_STS_SYSBOOT18_SHIFT                                                        (26U)
#define CTRL_STS_SYSBOOT18_MASK                                                         (0x04000000U)

#define CTRL_STS_CRYSTAL_FREQ_SELECTION_SHIFT                                           (29U)
#define CTRL_STS_CRYSTAL_FREQ_SELECTION_MASK                                            (0x60000000U)

#define CTRL_STS_CRYSTAL_FREQ_SOURCE_SHIFT                                              (31U)
#define CTRL_STS_CRYSTAL_FREQ_SOURCE_MASK                                               (0x80000000U)

#define CTRL_BOOTSTAT_BC_SHIFT                                                          (0U)
#define CTRL_BOOTSTAT_BC_MASK                                                           (0x00000001U)

#define CTRL_BOOTSTAT_BOOTERR_SHIFT                                                     (16U)
#define CTRL_BOOTSTAT_BOOTERR_MASK                                                      (0x000f0000U)

#define CTRL_L4_FWCFG0_ROLE_CFG_LO_ROLECFGLO_SHIFT                                      (0U)
#define CTRL_L4_FWCFG0_ROLE_CFG_LO_ROLECFGLO_MASK                                       (0xffffffffU)

#define CTRL_L4_FWCFG0_ROLE_CFG_HI_ROLECFGHI_SHIFT                                      (0U)
#define CTRL_L4_FWCFG0_ROLE_CFG_HI_ROLECFGHI_MASK                                       (0xffffffffU)

#define CTRL_L4_FWCFG1_ROLE_CFG_LO_ROLECFGLO_SHIFT                                      (0U)
#define CTRL_L4_FWCFG1_ROLE_CFG_LO_ROLECFGLO_MASK                                       (0xffffffffU)

#define CTRL_L4_FWCFG1_ROLE_CFG_HI_ROLECFGHI_SHIFT                                      (0U)
#define CTRL_L4_FWCFG1_ROLE_CFG_HI_ROLECFGHI_MASK                                       (0xffffffffU)

#define CTRL_L4_WKUPCFG0_ROLE_CFG_LO_ROLECFGLO_SHIFT                                    (0U)
#define CTRL_L4_WKUPCFG0_ROLE_CFG_LO_ROLECFGLO_MASK                                     (0xffffffffU)

#define CTRL_L4_WKUPCFG0_ROLE_CFG_HI_ROLECFGHI_SHIFT                                    (0U)
#define CTRL_L4_WKUPCFG0_ROLE_CFG_HI_ROLECFGHI_MASK                                     (0xffffffffU)

#define CTRL_L4_WKUPCFG1_ROLE_CFG_LO_ROLECFGLO_SHIFT                                    (0U)
#define CTRL_L4_WKUPCFG1_ROLE_CFG_LO_ROLECFGLO_MASK                                     (0xffffffffU)

#define CTRL_L4_WKUPCFG1_ROLE_CFG_HI_ROLECFGHI_SHIFT                                    (0U)
#define CTRL_L4_WKUPCFG1_ROLE_CFG_HI_ROLECFGHI_MASK                                     (0xffffffffU)

#define CTRL_L4_PERCFG0_ROLE_CFG_LO_ROLECFGLO_SHIFT                                     (0U)
#define CTRL_L4_PERCFG0_ROLE_CFG_LO_ROLECFGLO_MASK                                      (0xffffffffU)

#define CTRL_L4_PERCFG0_ROLE_CFG_HI_ROLECFGHI_SHIFT                                     (0U)
#define CTRL_L4_PERCFG0_ROLE_CFG_HI_ROLECFGHI_MASK                                      (0xffffffffU)

#define CTRL_L4_PERCFG1_ROLE_CFG_LO_ROLECFGLO_SHIFT                                     (0U)
#define CTRL_L4_PERCFG1_ROLE_CFG_LO_ROLECFGLO_MASK                                      (0xffffffffU)

#define CTRL_L4_PERCFG1_ROLE_CFG_HI_ROLECFGHI_SHIFT                                     (0U)
#define CTRL_L4_PERCFG1_ROLE_CFG_HI_ROLECFGHI_MASK                                      (0xffffffffU)

#define CTRL_L4_PERCFG2_ROLE_CFG_LO_ROLECFGLO_SHIFT                                     (0U)
#define CTRL_L4_PERCFG2_ROLE_CFG_LO_ROLECFGLO_MASK                                      (0xffffffffU)

#define CTRL_L4_PERCFG2_ROLE_CFG_HI_ROLECFGHI_SHIFT                                     (0U)
#define CTRL_L4_PERCFG2_ROLE_CFG_HI_ROLECFGHI_MASK                                      (0xffffffffU)

#define CTRL_L4_FASTCFG0_ROLE_CFG_LO_ROLECFGLO_SHIFT                                    (0U)
#define CTRL_L4_FASTCFG0_ROLE_CFG_LO_ROLECFGLO_MASK                                     (0xffffffffU)

#define CTRL_L4_FASTCFG0_ROLE_CFG_HI_ROLECFGHI_SHIFT                                    (0U)
#define CTRL_L4_FASTCFG0_ROLE_CFG_HI_ROLECFGHI_MASK                                     (0xffffffffU)

#define CTRL_L4_FASTCFG1_ROLE_CFG_LO_ROLECFGLO_SHIFT                                    (0U)
#define CTRL_L4_FASTCFG1_ROLE_CFG_LO_ROLECFGLO_MASK                                     (0xffffffffU)

#define CTRL_L4_FASTCFG1_ROLE_CFG_HI_ROLECFGHI_SHIFT                                    (0U)
#define CTRL_L4_FASTCFG1_ROLE_CFG_HI_ROLECFGHI_MASK                                     (0xffffffffU)

#define CTRL_L4_FWCFG0_MEMBER_CFG_MEMBERCFG_SHIFT                                       (0U)
#define CTRL_L4_FWCFG0_MEMBER_CFG_MEMBERCFG_MASK                                        (0x0000ffffU)

#define CTRL_L4_FWCFG0_MEMBER_CFG_L4FWCFG0WRDIS_SHIFT                                   (31U)
#define CTRL_L4_FWCFG0_MEMBER_CFG_L4FWCFG0WRDIS_MASK                                    (0x80000000U)

#define CTRL_L4_FWCFG1_MEMBER_CFG_MEMBERCFG_SHIFT                                       (0U)
#define CTRL_L4_FWCFG1_MEMBER_CFG_MEMBERCFG_MASK                                        (0x0000ffffU)

#define CTRL_L4_FWCFG1_MEMBER_CFG_L4FWCFG1WRDIS_SHIFT                                   (31U)
#define CTRL_L4_FWCFG1_MEMBER_CFG_L4FWCFG1WRDIS_MASK                                    (0x80000000U)

#define CTRL_L4_WKUPCFG0_MEMBER_CFG_MEMBERCFG_SHIFT                                     (0U)
#define CTRL_L4_WKUPCFG0_MEMBER_CFG_MEMBERCFG_MASK                                      (0x0000ffffU)

#define CTRL_L4_WKUPCFG0_MEMBER_CFG_L4WKUPCFG0WRDIS_SHIFT                               (31U)
#define CTRL_L4_WKUPCFG0_MEMBER_CFG_L4WKUPCFG0WRDIS_MASK                                (0x80000000U)

#define CTRL_L4_WKUPCFG1_MEMBER_CFG_MEMBERCFG_SHIFT                                     (0U)
#define CTRL_L4_WKUPCFG1_MEMBER_CFG_MEMBERCFG_MASK                                      (0x0000ffffU)

#define CTRL_L4_WKUPCFG1_MEMBER_CFG_L4WKUPCFG1WRDIS_SHIFT                               (31U)
#define CTRL_L4_WKUPCFG1_MEMBER_CFG_L4WKUPCFG1WRDIS_MASK                                (0x80000000U)

#define CTRL_L4_PERCFG0_MEMBER_CFG_MEMBERCFG_SHIFT                                      (0U)
#define CTRL_L4_PERCFG0_MEMBER_CFG_MEMBERCFG_MASK                                       (0x0000ffffU)

#define CTRL_L4_PERCFG0_MEMBER_CFG_L4PERCFG0WRDIS_SHIFT                                 (31U)
#define CTRL_L4_PERCFG0_MEMBER_CFG_L4PERCFG0WRDIS_MASK                                  (0x80000000U)

#define CTRL_L4_PERCFG1_MEMBER_CFG_MEMBERCFG_SHIFT                                      (0U)
#define CTRL_L4_PERCFG1_MEMBER_CFG_MEMBERCFG_MASK                                       (0x0000ffffU)

#define CTRL_L4_PERCFG1_MEMBER_CFG_L4PERCFG1WRDIS_SHIFT                                 (31U)
#define CTRL_L4_PERCFG1_MEMBER_CFG_L4PERCFG1WRDIS_MASK                                  (0x80000000U)

#define CTRL_L4_PERCFG2_MEMBER_CFG_MEMBERCFG_SHIFT                                      (0U)
#define CTRL_L4_PERCFG2_MEMBER_CFG_MEMBERCFG_MASK                                       (0x0000ffffU)

#define CTRL_L4_PERCFG2_MEMBER_CFG_L4PERCFG2WRDIS_SHIFT                                 (31U)
#define CTRL_L4_PERCFG2_MEMBER_CFG_L4PERCFG2WRDIS_MASK                                  (0x80000000U)

#define CTRL_L4_FASTCFG0_MEMBER_CFG_MEMBERCFG_SHIFT                                     (0U)
#define CTRL_L4_FASTCFG0_MEMBER_CFG_MEMBERCFG_MASK                                      (0x0000ffffU)

#define CTRL_L4_FASTCFG0_MEMBER_CFG_L4FASTCFG0WRDIS_SHIFT                               (31U)
#define CTRL_L4_FASTCFG0_MEMBER_CFG_L4FASTCFG0WRDIS_MASK                                (0x80000000U)

#define CTRL_L4_FASTCFG1_MEMBER_CFG_MEMBERCFG_SHIFT                                     (0U)
#define CTRL_L4_FASTCFG1_MEMBER_CFG_MEMBERCFG_MASK                                      (0x0000ffffU)

#define CTRL_L4_FASTCFG1_MEMBER_CFG_L4FASTCFG1WRDIS_SHIFT                               (31U)
#define CTRL_L4_FASTCFG1_MEMBER_CFG_L4FASTCFG1WRDIS_MASK                                (0x80000000U)

#define CTRL_SEC_WDOPDISABLE_SHIFT                                                      (0U)
#define CTRL_SEC_WDOPDISABLE_MASK                                                       (0x00000001U)

#define CTRL_SEC_WDREGEN_SHIFT                                                          (1U)
#define CTRL_SEC_WDREGEN_MASK                                                           (0x00000002U)

#define CTRL_SEC_KEKSWEN_SHIFT                                                          (2U)
#define CTRL_SEC_KEKSWEN_MASK                                                           (0x00000004U)

#define CTRL_SEC_DMLEDCOREEN_SHIFT                                                      (7U)
#define CTRL_SEC_DMLEDCOREEN_MASK                                                       (0x00000080U)

#define CTRL_SEC_BSCEN_SHIFT                                                            (9U)
#define CTRL_SEC_BSCEN_MASK                                                             (0x00000200U)

#define CTRL_SEC_CPEFUSELDDONE_SHIFT                                                    (10U)
#define CTRL_SEC_CPEFUSELDDONE_MASK                                                     (0x00000400U)

#define CTRL_SEC_CPEFUSEWRDIS_SHIFT                                                     (11U)
#define CTRL_SEC_CPEFUSEWRDIS_MASK                                                      (0x00000800U)

#define CTRL_SEC_CPEFUSENOTDEC_SHIFT                                                    (12U)
#define CTRL_SEC_CPEFUSENOTDEC_MASK                                                     (0x00001000U)

#define CTRL_SEC_SMPKEFUSENOTDEC_SHIFT                                                  (13U)
#define CTRL_SEC_SMPKEFUSENOTDEC_MASK                                                   (0x00002000U)

#define CTRL_SEC_L3OCMSECSAVE_SHIFT                                                     (26U)
#define CTRL_SEC_L3OCMSECSAVE_MASK                                                      (0x0c000000U)

#define CTRL_SEC_FASTOCMSECSAVE_SHIFT                                                   (28U)
#define CTRL_SEC_FASTOCMSECSAVE_MASK                                                    (0x30000000U)

#define CTRL_SEC_SECUREMODEINITDONE_SHIFT                                               (30U)
#define CTRL_SEC_SECUREMODEINITDONE_MASK                                                (0x40000000U)

#define CTRL_SEC_SECCTRLWRDISABLE_SHIFT                                                 (31U)
#define CTRL_SEC_SECCTRLWRDISABLE_MASK                                                  (0x80000000U)

#define CTRL_SEC_SW_HW_PARAMETERS_SHIFT                                                 (0U)
#define CTRL_SEC_SW_HW_PARAMETERS_MASK                                                  (0xffffffffU)

#define CTRL_SEC_EMU_GENDBGEN_SHIFT                                                     (0U)
#define CTRL_SEC_EMU_GENDBGEN_MASK                                                      (0x00000fffU)

#define CTRL_SEC_EMU_ETMSECPRIVDBGEN_SHIFT                                              (12U)
#define CTRL_SEC_EMU_ETMSECPRIVDBGEN_MASK                                               (0x00001000U)

#define CTRL_SEC_EMU_ICESECPRIVDBGEN_SHIFT                                              (13U)
#define CTRL_SEC_EMU_ICESECPRIVDBGEN_MASK                                               (0x00002000U)

#define CTRL_SEC_EMU_GENDBGEN_M3_SHIFT                                                  (14U)
#define CTRL_SEC_EMU_GENDBGEN_M3_MASK                                                   (0x0000c000U)

#define CTRL_SEC_EMU_SECEMUWRDIS_SHIFT                                                  (31U)
#define CTRL_SEC_EMU_SECEMUWRDIS_MASK                                                   (0x80000000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_PAGESIZE_SHIFT                                    (0U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_PAGESIZE_MASK                                     (0x00000007U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_EBANK_SHIFT                                       (3U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_EBANK_MASK                                        (0x00000008U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_IBANK_SHIFT                                       (4U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_IBANK_MASK                                        (0x00000070U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_ROWSIZE_SHIFT                                     (7U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_ROWSIZE_MASK                                      (0x00000380U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_CL_SHIFT                                          (10U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_CL_MASK                                           (0x00003c00U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_NARROW_MODE_SHIFT                                 (14U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_NARROW_MODE_MASK                                  (0x0000c000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_CWL_SHIFT                                         (16U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_CWL_MASK                                          (0x00030000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DRIVE_SHIFT                                       (18U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DRIVE_MASK                                        (0x000c0000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR_DISABLE_DLL_SHIFT                             (20U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR_DISABLE_DLL_MASK                              (0x00100000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DYN_ODT_SHIFT                                     (21U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DYN_ODT_MASK                                      (0x00600000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR2_DQS_SHIFT                                    (23U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR2_DQS_MASK                                     (0x00800000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR_TERM_SHIFT                                    (24U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_DDR_TERM_MASK                                     (0x07000000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_IBANK_POS_SHIFT                                   (27U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_IBANK_POS_MASK                                    (0x18000000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_TYPE_SHIFT                                        (29U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_TYPE_MASK                                         (0xe0000000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_RDBSIZE_SHIFT                                   (0U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_RDBSIZE_MASK                                    (0x00000007U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_RDBNUM_SHIFT                                    (4U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_RDBNUM_MASK                                     (0x00000030U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_EBANK_POS_SHIFT                                 (27U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_EBANK_POS_MASK                                  (0x08000000U)

#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_CS1_NVMEN_SHIFT                                 (30U)
#define CTRL_SECURE_EMIF_SDRAM_CONFIG_2_CS1_NVMEN_MASK                                  (0x40000000U)

#define CTRL_SW_CFG_SHIFT                                                               (0U)
#define CTRL_SW_CFG_MASK                                                                (0xffffffffU)

#define CTRL_SW_CCFG_SHIFT                                                              (0U)
#define CTRL_SW_CCFG_MASK                                                               (0x0000ffffU)

#define CTRL_SW_CCFG_RED_SHIFT                                                          (16U)
#define CTRL_SW_CCFG_RED_MASK                                                           (0xffff0000U)

#define CTRL_MPK_0_SHIFT                                                                (0U)
#define CTRL_MPK_0_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_1_SHIFT                                                                (0U)
#define CTRL_MPK_1_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_2_SHIFT                                                                (0U)
#define CTRL_MPK_2_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_3_SHIFT                                                                (0U)
#define CTRL_MPK_3_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_4_SHIFT                                                                (0U)
#define CTRL_MPK_4_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_5_SHIFT                                                                (0U)
#define CTRL_MPK_5_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_6_SHIFT                                                                (0U)
#define CTRL_MPK_6_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_7_SHIFT                                                                (0U)
#define CTRL_MPK_7_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_8_SHIFT                                                                (0U)
#define CTRL_MPK_8_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_9_SHIFT                                                                (0U)
#define CTRL_MPK_9_MASK                                                                 (0xffffffffU)

#define CTRL_MPK_10_SHIFT                                                               (0U)
#define CTRL_MPK_10_MASK                                                                (0xffffffffU)

#define CTRL_MPK_11_SHIFT                                                               (0U)
#define CTRL_MPK_11_MASK                                                                (0xffffffffU)

#define CTRL_MPK_12_SHIFT                                                               (0U)
#define CTRL_MPK_12_MASK                                                                (0xffffffffU)

#define CTRL_MPK_13_SHIFT                                                               (0U)
#define CTRL_MPK_13_MASK                                                                (0xffffffffU)

#define CTRL_MPK_14_SHIFT                                                               (0U)
#define CTRL_MPK_14_MASK                                                                (0xffffffffU)

#define CTRL_MPK_15_SHIFT                                                               (0U)
#define CTRL_MPK_15_MASK                                                                (0xffffffffU)

#define CTRL_SWRV_0_SHIFT                                                               (0U)
#define CTRL_SWRV_0_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_0_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_0_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_1_SHIFT                                                               (0U)
#define CTRL_SWRV_1_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_1_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_1_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_2_SHIFT                                                               (0U)
#define CTRL_SWRV_2_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_2_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_2_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_3_SHIFT                                                               (0U)
#define CTRL_SWRV_3_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_3_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_3_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_4_SHIFT                                                               (0U)
#define CTRL_SWRV_4_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_4_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_4_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_5_SHIFT                                                               (0U)
#define CTRL_SWRV_5_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_5_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_5_RED_MASK                                                            (0xffff0000U)

#define CTRL_SWRV_6_SHIFT                                                               (0U)
#define CTRL_SWRV_6_MASK                                                                (0x0000ffffU)

#define CTRL_SWRV_6_RED_SHIFT                                                           (16U)
#define CTRL_SWRV_6_RED_MASK                                                            (0xffff0000U)

#define CTRL_SEC_TAP_DAPTAPEN_SHIFT                                                     (0U)
#define CTRL_SEC_TAP_DAPTAPEN_MASK                                                      (0x00000001U)

#define CTRL_SEC_TAP_WAKEUPTAPEN_SHIFT                                                  (2U)
#define CTRL_SEC_TAP_WAKEUPTAPEN_MASK                                                   (0x00000004U)

#define CTRL_SEC_TAP_1500EN_SHIFT                                                       (3U)
#define CTRL_SEC_TAP_1500EN_MASK                                                        (0x00000008U)

#define CTRL_SEC_TAP_PART1500DIS_SHIFT                                                  (4U)
#define CTRL_SEC_TAP_PART1500DIS_MASK                                                   (0x00000010U)

#define CTRL_SEC_TAP_MPUTAPEN_SHIFT                                                     (9U)
#define CTRL_SEC_TAP_MPUTAPEN_MASK                                                      (0x00000200U)

#define CTRL_SEC_TAP_SECTAPWRDISABLE_SHIFT                                              (31U)
#define CTRL_SEC_TAP_SECTAPWRDISABLE_MASK                                               (0x80000000U)

#define CTRL_SEC_TAP_CMDIN_SHIFT                                                        (0U)
#define CTRL_SEC_TAP_CMDIN_MASK                                                         (0x000000ffU)

#define CTRL_SEC_TAP_CMDOUT_SHIFT                                                       (0U)
#define CTRL_SEC_TAP_CMDOUT_MASK                                                        (0x000000ffU)

#define CTRL_SEC_TAP_DATIN_DATAIN_SHIFT                                                 (0U)
#define CTRL_SEC_TAP_DATIN_DATAIN_MASK                                                  (0x000000ffU)

#define CTRL_SEC_TAP_DATOUT_DATAOUT_SHIFT                                               (0U)
#define CTRL_SEC_TAP_DATOUT_DATAOUT_MASK                                                (0x000000ffU)

#define CTRL_MREQDOMAIN_EXP1_LCD_DOM_SHIFT                                              (15U)
#define CTRL_MREQDOMAIN_EXP1_LCD_DOM_MASK                                               (0x00038000U)

#define CTRL_MREQDOMAIN_EXP1_WAKE_DOM_SHIFT                                             (21U)
#define CTRL_MREQDOMAIN_EXP1_WAKE_DOM_MASK                                              (0x00e00000U)

#define CTRL_MREQDOMAIN_EXP1_SGX_DOM_SHIFT                                              (24U)
#define CTRL_MREQDOMAIN_EXP1_SGX_DOM_MASK                                               (0x07000000U)

#define CTRL_MREQDOMAIN_EXP1_LCK_SHIFT                                                  (31U)
#define CTRL_MREQDOMAIN_EXP1_LCK_MASK                                                   (0x80000000U)

#define CTRL_MREQDOMAIN_EXP2_USB0_DOM_SHIFT                                             (9U)
#define CTRL_MREQDOMAIN_EXP2_USB0_DOM_MASK                                              (0x00000e00U)

#define CTRL_MREQDOMAIN_EXP2_USB1_DOM_SHIFT                                             (12U)
#define CTRL_MREQDOMAIN_EXP2_USB1_DOM_MASK                                              (0x00007000U)

#define CTRL_MREQDOMAIN_EXP2_P1500_DOM_SHIFT                                            (15U)
#define CTRL_MREQDOMAIN_EXP2_P1500_DOM_MASK                                             (0x00038000U)

#define CTRL_MREQDOMAIN_EXP2_GEMAC_DOM_SHIFT                                            (18U)
#define CTRL_MREQDOMAIN_EXP2_GEMAC_DOM_MASK                                             (0x001c0000U)

#define CTRL_MREQDOMAIN_EXP2_LCK_SHIFT                                                  (31U)
#define CTRL_MREQDOMAIN_EXP2_LCK_MASK                                                   (0x80000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPTC_SECLOCK_EN_SHIFT                               (3U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPTC_SECLOCK_EN_MASK                                (0x00000008U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPCC_SECLOCK_EN_SHIFT                               (4U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPCC_SECLOCK_EN_MASK                                (0x00000010U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_SGX_SECLOCK_EN_SHIFT                                (7U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_SGX_SECLOCK_EN_MASK                                 (0x00000080U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_L3RAM_SECLOCK_EN_SHIFT                              (8U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_L3RAM_SECLOCK_EN_MASK                               (0x00000100U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPTC_SECDBG_EN_SHIFT                                (19U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPTC_SECDBG_EN_MASK                                 (0x00080000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPCC_SECDBG_EN_SHIFT                                (20U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_TPCC_SECDBG_EN_MASK                                 (0x00100000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_SGX_SECDBG_EN_SHIFT                                 (23U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_SGX_SECDBG_EN_MASK                                  (0x00800000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF0_L3RAM_SECDBG_EN_SHIFT                               (24U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF0_L3RAM_SECDBG_EN_MASK                                (0x01000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_GPMC_SECLOCK_EN_SHIFT                               (3U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_GPMC_SECLOCK_EN_MASK                                (0x00000008U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP0_SECLOCK_EN_SHIFT                             (4U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP0_SECLOCK_EN_MASK                              (0x00000010U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP1_SECLOCK_EN_SHIFT                             (5U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP1_SECLOCK_EN_MASK                              (0x00000020U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_EMIF_SECLOCK_EN_SHIFT                               (8U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_EMIF_SECLOCK_EN_MASK                                (0x00000100U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_DBG_SECLOCK_EN_SHIFT                                (9U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_DBG_SECLOCK_EN_MASK                                 (0x00000200U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MMCHS2_SECLOCK_EN_SHIFT                             (10U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MMCHS2_SECLOCK_EN_MASK                              (0x00000400U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_ADCTSC_SECLOCK_EN_SHIFT                             (11U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_ADCTSC_SECLOCK_EN_MASK                              (0x00000800U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_AES0_SECLOCK_EN_SHIFT                               (12U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_AES0_SECLOCK_EN_MASK                                (0x00001000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_SHA_SECLOCK_EN_SHIFT                                (14U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_SHA_SECLOCK_EN_MASK                                 (0x00004000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_3DES_SECLOCK_EN_SHIFT                               (15U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_3DES_SECLOCK_EN_MASK                                (0x00008000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_GPMC_SECDBG_EN_SHIFT                                (19U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_GPMC_SECDBG_EN_MASK                                 (0x00080000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP0_SECDBG_EN_SHIFT                              (20U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP0_SECDBG_EN_MASK                               (0x00100000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP1_SECDBG_EN_SHIFT                              (21U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MCASP1_SECDBG_EN_MASK                               (0x00200000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_EMIF_SECDBG_EN_SHIFT                                (24U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_EMIF_SECDBG_EN_MASK                                 (0x01000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_DBG_SECDBG_EN_SHIFT                                 (25U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_DBG_SECDBG_EN_MASK                                  (0x02000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MMCHS2_SECDBG_EN_SHIFT                              (26U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_MMCHS2_SECDBG_EN_MASK                               (0x04000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_ADCTSC_SECDBG_EN_SHIFT                              (27U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_ADCTSC_SECDBG_EN_MASK                               (0x08000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_AES0_SECDBG_EN_SHIFT                                (28U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_AES0_SECDBG_EN_MASK                                 (0x10000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_SHA_SECDBG_EN_SHIFT                                 (30U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_SHA_SECDBG_EN_MASK                                  (0x40000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF1_3DES_SECDBG_EN_SHIFT                                (31U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF1_3DES_SECDBG_EN_MASK                                 (0x80000000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_AP_SECLOCK_EN_SHIFT                            (0U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_AP_SECLOCK_EN_MASK                             (0x00000001U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_CRYPTO_SECLOCK_EN_SHIFT                        (1U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_CRYPTO_SECLOCK_EN_MASK                         (0x00000002U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_AP_SECLOCK_EN_SHIFT                             (4U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_AP_SECLOCK_EN_MASK                              (0x00000010U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_SEC_SECLOCK_EN_SHIFT                            (5U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_SEC_SECLOCK_EN_MASK                             (0x00000020U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FAST_AP_SECLOCK_EN_SHIFT                           (8U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FAST_AP_SECLOCK_EN_MASK                            (0x00000100U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_AP_SECLOCK_EN_SHIFT                           (12U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_AP_SECLOCK_EN_MASK                            (0x00001000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_SEC_SECLOCK_EN_SHIFT                          (13U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_SEC_SECLOCK_EN_MASK                           (0x00002000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_AP_SECDBG_EN_SHIFT                             (16U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_AP_SECDBG_EN_MASK                              (0x00010000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_CRYPTO_SECDBG_EN_SHIFT                         (17U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4PER_CRYPTO_SECDBG_EN_MASK                          (0x00020000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_AP_SECDBG_EN_SHIFT                              (20U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_AP_SECDBG_EN_MASK                               (0x00100000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_SEC_SECDBG_EN_SHIFT                             (21U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FW_SEC_SECDBG_EN_MASK                              (0x00200000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FAST_AP_SECDBG_EN_SHIFT                            (24U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4FAST_AP_SECDBG_EN_MASK                             (0x01000000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_AP_SECDBG_EN_SHIFT                            (28U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_AP_SECDBG_EN_MASK                             (0x10000000U)

#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_SEC_SECDBG_EN_SHIFT                           (29U)
#define CTRL_L4_HW_FW_EXP_VAL_CONF_L4WKUP_SEC_SECDBG_EN_MASK                            (0x20000000U)

#define CTRL_SEC_LOAD_FW_EXP_VAL_L4FW_LD_EXPVAL_REQN_SHIFT                              (2U)
#define CTRL_SEC_LOAD_FW_EXP_VAL_L4FW_LD_EXPVAL_REQN_MASK                               (0x00000004U)

#define CTRL_SEC_LOAD_FW_EXP_VAL_L4PER_LD_EXPVAL_REQN_SHIFT                             (3U)
#define CTRL_SEC_LOAD_FW_EXP_VAL_L4PER_LD_EXPVAL_REQN_MASK                              (0x00000008U)

#define CTRL_SEC_LOAD_FW_EXP_VAL_L4FAST_LD_EXPVAL_REQN_SHIFT                            (4U)
#define CTRL_SEC_LOAD_FW_EXP_VAL_L4FAST_LD_EXPVAL_REQN_MASK                             (0x00000010U)

#define CTRL_SEC_LOAD_FW_EXP_VAL_L4WKUP_LD_EXPVAL_REQN_SHIFT                            (5U)
#define CTRL_SEC_LOAD_FW_EXP_VAL_L4WKUP_LD_EXPVAL_REQN_MASK                             (0x00000020U)

#define CTRL_SEC_RO_EMIF_CFG_EN_SHIFT                                                   (1U)
#define CTRL_SEC_RO_EMIF_CFG_EN_MASK                                                    (0x00000002U)

#define CTRL_SEC_RO_EMIF_OBFS_EN_SHIFT                                                  (2U)
#define CTRL_SEC_RO_EMIF_OBFS_EN_MASK                                                   (0x00000004U)

#define CTRL_SEC_RO_MEKACCEN_SHIFT                                                      (3U)
#define CTRL_SEC_RO_MEKACCEN_MASK                                                       (0x00000008U)

#define CTRL_SEC_RO_SMPKPROG_SHIFT                                                      (4U)
#define CTRL_SEC_RO_SMPKPROG_MASK                                                       (0x00000010U)

#define CTRL_SEC_RO_SMEKACCEN_SHIFT                                                     (5U)
#define CTRL_SEC_RO_SMEKACCEN_MASK                                                      (0x00000020U)

#define CTRL_SEC_RO_EFUSEACCEN_SHIFT                                                    (6U)
#define CTRL_SEC_RO_EFUSEACCEN_MASK                                                     (0x00000040U)

#define CTRL_EMIF_OBFUSCATION_KEY_OBFUSCATIONKEY_SHIFT                                  (0U)
#define CTRL_EMIF_OBFUSCATION_KEY_OBFUSCATIONKEY_MASK                                   (0x0000ffffU)

#define CTRL_SEC_CLK_SECWDCLKSEL_SHIFT                                                  (0U)
#define CTRL_SEC_CLK_SECWDCLKSEL_MASK                                                   (0x00000001U)

#define CTRL_SEC_CLK_SECTIMERCLKSEL_SHIFT                                               (4U)
#define CTRL_SEC_CLK_SECTIMERCLKSEL_MASK                                                (0x00000030U)

#define CTRL_SEC_CLK_SECCLKLCK_SHIFT                                                    (31U)
#define CTRL_SEC_CLK_SECCLKLCK_MASK                                                     (0x80000000U)

#define CTRL_MREQDOMAIN_EXP3_PRU1_DOM0_SHIFT                                            (0U)
#define CTRL_MREQDOMAIN_EXP3_PRU1_DOM0_MASK                                             (0x00000007U)

#define CTRL_MREQDOMAIN_EXP3_PRU1_DOM1_SHIFT                                            (3U)
#define CTRL_MREQDOMAIN_EXP3_PRU1_DOM1_MASK                                             (0x00000038U)

#define CTRL_MREQDOMAIN_EXP3_PRU0_DOM0_SHIFT                                            (6U)
#define CTRL_MREQDOMAIN_EXP3_PRU0_DOM0_MASK                                             (0x000001c0U)

#define CTRL_MREQDOMAIN_EXP3_PRU0_DOM1_SHIFT                                            (9U)
#define CTRL_MREQDOMAIN_EXP3_PRU0_DOM1_MASK                                             (0x00000e00U)

#define CTRL_MREQDOMAIN_EXP3_VPFE0_DOM_SHIFT                                            (12U)
#define CTRL_MREQDOMAIN_EXP3_VPFE0_DOM_MASK                                             (0x00007000U)

#define CTRL_MREQDOMAIN_EXP3_VPFE1_DOM_SHIFT                                            (15U)
#define CTRL_MREQDOMAIN_EXP3_VPFE1_DOM_MASK                                             (0x00038000U)

#define CTRL_MREQDOMAIN_EXP3_LCK_SHIFT                                                  (31U)
#define CTRL_MREQDOMAIN_EXP3_LCK_MASK                                                   (0x80000000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_L2RAM_SECLOCK_EN_SHIFT                              (0U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_L2RAM_SECLOCK_EN_MASK                               (0x00000001U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_QSPI_SECLOCK_EN_SHIFT                               (1U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_QSPI_SECLOCK_EN_MASK                                (0x00000002U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_MSR_SECLOCK_EN_SHIFT                                (2U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_MSR_SECLOCK_EN_MASK                                 (0x00000004U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_ICSS_SECLOCK_EN_SHIFT                               (4U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_ICSS_SECLOCK_EN_MASK                                (0x00000010U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_L2RAM_SECDBG_EN_SHIFT                               (16U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_L2RAM_SECDBG_EN_MASK                                (0x00010000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_QSPI_SECDBG_EN_SHIFT                                (17U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_QSPI_SECDBG_EN_MASK                                 (0x00020000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_MSR_SECDBG_EN_SHIFT                                 (18U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_MSR_SECDBG_EN_MASK                                  (0x00040000U)

#define CTRL_L3_HW_FW_EXP_VAL_CONF2_ICSS_SECDBG_EN_SHIFT                                (20U)
#define CTRL_L3_HW_FW_EXP_VAL_CONF2_ICSS_SECDBG_EN_MASK                                 (0x00100000U)

#define CTRL_TAMPER_CTPM_PD_SHIFT                                                       (0U)
#define CTRL_TAMPER_CTPM_PD_MASK                                                        (0x00000001U)

#define CTRL_TAMPER_CTPM_RESET_EN_SHIFT                                                 (1U)
#define CTRL_TAMPER_CTPM_RESET_EN_MASK                                                  (0x00000002U)

#define CTRL_TAMPER_CANARY_RESET_EN_SHIFT                                               (2U)
#define CTRL_TAMPER_CANARY_RESET_EN_MASK                                                (0x00000004U)

#define CTRL_TAMPER_CORE_GLITCH_EN_SHIFT                                                (4U)
#define CTRL_TAMPER_CORE_GLITCH_EN_MASK                                                 (0x00000010U)

#define CTRL_TAMPER_MPU_GLITCH_EN_SHIFT                                                 (5U)
#define CTRL_TAMPER_MPU_GLITCH_EN_MASK                                                  (0x00000020U)

#define CTRL_TAMPER_HF_DETECT_RST_EN_SHIFT                                              (8U)
#define CTRL_TAMPER_HF_DETECT_RST_EN_MASK                                               (0x00000100U)

#define CTRL_TAMPER_MOSC_CANARY_RST_EN_SHIFT                                            (9U)
#define CTRL_TAMPER_MOSC_CANARY_RST_EN_MASK                                             (0x00000200U)

#define CTRL_TAMPER_HF_DELAY_SEL_SHIFT                                                  (10U)
#define CTRL_TAMPER_HF_DELAY_SEL_MASK                                                   (0x00000c00U)

#define CTRL_TAMPER_TRIM_REG_SEL_SHIFT                                                  (16U)
#define CTRL_TAMPER_TRIM_REG_SEL_MASK                                                   (0x00ff0000U)

#define CTRL_TAMPER_TMP_SPARE_SHIFT                                                     (24U)
#define CTRL_TAMPER_TMP_SPARE_MASK                                                      (0xff000000U)

#define CTRL_SEC_SPARE0_SHIFT                                                           (0U)
#define CTRL_SEC_SPARE0_MASK                                                            (0xffffffffU)

#define CTRL_SEC_SPARE0_PIUSEL2SRAM_SHIFT						(16U)
#define CTRL_SEC_SPARE0_PIUSEL2SRAM_MASK						(0x00010000U)

#define CTRL_SEC_SPARE1_SHIFT                                                           (0U)
#define CTRL_SEC_SPARE1_MASK                                                            (0xffffffffU)

#define CTRL_MEK_0_SHIFT                                                                (0U)
#define CTRL_MEK_0_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_1_SHIFT                                                                (0U)
#define CTRL_MEK_1_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_2_SHIFT                                                                (0U)
#define CTRL_MEK_2_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_3_SHIFT                                                                (0U)
#define CTRL_MEK_3_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_4_SHIFT                                                                (0U)
#define CTRL_MEK_4_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_5_SHIFT                                                                (0U)
#define CTRL_MEK_5_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_6_SHIFT                                                                (0U)
#define CTRL_MEK_6_MASK                                                                 (0xffffffffU)

#define CTRL_MEK_7_SHIFT                                                                (0U)
#define CTRL_MEK_7_MASK                                                                 (0xffffffffU)

#define CTRL_MSV_0_SHIFT                                                                (0U)
#define CTRL_MSV_0_MASK                                                                 (0xffffffffU)

#define CTRL_MSV_BCH_0_SHIFT                                                            (0U)
#define CTRL_MSV_BCH_0_MASK                                                             (0xffffffffU)

#define CTRL_MSV_BCH_1_SHIFT                                                            (0U)
#define CTRL_MSV_BCH_1_MASK                                                             (0xffffffffU)

#define CTRL_SEC_STS_GLOBALCOLDRST_SHIFT                                                (0U)
#define CTRL_SEC_STS_GLOBALCOLDRST_MASK                                                 (0x00000001U)

#define CTRL_SEC_STS_GLOBALWARMRST_SHIFT                                                (1U)
#define CTRL_SEC_STS_GLOBALWARMRST_MASK                                                 (0x00000002U)

#define CTRL_SEC_STS_PUBWDRST_SHIFT                                                     (2U)
#define CTRL_SEC_STS_PUBWDRST_MASK                                                      (0x00000004U)

#define CTRL_SEC_STS_SECWDRST_SHIFT                                                     (3U)
#define CTRL_SEC_STS_SECWDRST_MASK                                                      (0x00000008U)

#define CTRL_SEC_STS_SSMVIOLATIONRST_SHIFT                                              (4U)
#define CTRL_SEC_STS_SSMVIOLATIONRST_MASK                                               (0x00000010U)

#define CTRL_SEC_STS_EMURST_SHIFT                                                       (5U)
#define CTRL_SEC_STS_EMURST_MASK                                                        (0x00000020U)

#define CTRL_SEC_STS_MPUDOMAINRST_SHIFT                                                 (6U)
#define CTRL_SEC_STS_MPUDOMAINRST_MASK                                                  (0x00000040U)

#define CTRL_SEC_STS_PERDOMAINRST_SHIFT                                                 (7U)
#define CTRL_SEC_STS_PERDOMAINRST_MASK                                                  (0x00000080U)

#define CTRL_SEC_STS_WKUPDOMAINRST_SHIFT                                                (8U)
#define CTRL_SEC_STS_WKUPDOMAINRST_MASK                                                 (0x00000100U)

#define CTRL_SEC_STS_GFXDOMAINRST_SHIFT                                                 (9U)
#define CTRL_SEC_STS_GFXDOMAINRST_MASK                                                  (0x00000200U)

#define CTRL_SEC_STS_MPURST_SHIFT                                                       (17U)
#define CTRL_SEC_STS_MPURST_MASK                                                        (0x00020000U)

#define CTRL_SEC_STS_ICSS1RST_SHIFT                                                     (19U)
#define CTRL_SEC_STS_ICSS1RST_MASK                                                      (0x00080000U)

#define CTRL_SECMEM_STS_A9L1DEST_SHIFT                                                  (0U)
#define CTRL_SECMEM_STS_A9L1DEST_MASK                                                   (0x00000001U)

#define CTRL_SECMEM_STS_A9L2DEST_SHIFT                                                  (1U)
#define CTRL_SECMEM_STS_A9L2DEST_MASK                                                   (0x00000002U)

#define CTRL_SECMEM_STS_FASTSECRAMDEST_SHIFT                                            (2U)
#define CTRL_SECMEM_STS_FASTSECRAMDEST_MASK                                             (0x00000004U)

#define CTRL_SECMEM_STS_L3SECRAM0DEST_SHIFT                                             (3U)
#define CTRL_SECMEM_STS_L3SECRAM0DEST_MASK                                              (0x00000008U)

#define CTRL_SECMEM_STS_L3SECRAM1DEST_SHIFT                                             (4U)
#define CTRL_SECMEM_STS_L3SECRAM1DEST_MASK                                              (0x00000010U)

#define CTRL_SECMEM_STS_A9L1NOTACC_SHIFT                                                (16U)
#define CTRL_SECMEM_STS_A9L1NOTACC_MASK                                                 (0x00010000U)

#define CTRL_SECMEM_STS_A9L2NOTACC_SHIFT                                                (17U)
#define CTRL_SECMEM_STS_A9L2NOTACC_MASK                                                 (0x00020000U)

#define CTRL_SECMEM_STS_FASTSECRAMNOTACC_SHIFT                                          (18U)
#define CTRL_SECMEM_STS_FASTSECRAMNOTACC_MASK                                           (0x00040000U)

#define CTRL_SECMEM_STS_L3SECRAM0NOTACC_SHIFT                                           (19U)
#define CTRL_SECMEM_STS_L3SECRAM0NOTACC_MASK                                            (0x00080000U)

#define CTRL_SECMEM_STS_L3SECRAM1NOTACC_SHIFT                                           (20U)
#define CTRL_SECMEM_STS_L3SECRAM1NOTACC_MASK                                            (0x00100000U)

#define CTRL_SEC_ERR_STAT_FUNC0_L3RAMFWERR_SHIFT                                        (0U)
#define CTRL_SEC_ERR_STAT_FUNC0_L3RAMFWERR_MASK                                         (0x00000001U)

#define CTRL_SEC_ERR_STAT_FUNC0_GPMCFWERR_SHIFT                                         (2U)
#define CTRL_SEC_ERR_STAT_FUNC0_GPMCFWERR_MASK                                          (0x00000004U)

#define CTRL_SEC_ERR_STAT_FUNC0_L2RAMFWERR_SHIFT                                        (3U)
#define CTRL_SEC_ERR_STAT_FUNC0_L2RAMFWERR_MASK                                         (0x00000008U)

#define CTRL_SEC_ERR_STAT_FUNC0_EMIFFWERR_SHIFT                                         (4U)
#define CTRL_SEC_ERR_STAT_FUNC0_EMIFFWERR_MASK                                          (0x00000010U)

#define CTRL_SEC_ERR_STAT_FUNC0_DSSFWERR_SHIFT                                          (6U)
#define CTRL_SEC_ERR_STAT_FUNC0_DSSFWERR_MASK                                           (0x00000040U)

#define CTRL_SEC_ERR_STAT_FUNC0_ICSSFWERR_SHIFT                                         (7U)
#define CTRL_SEC_ERR_STAT_FUNC0_ICSSFWERR_MASK                                          (0x00000080U)

#define CTRL_SEC_ERR_STAT_FUNC0_SGXFWERR_SHIFT                                          (17U)
#define CTRL_SEC_ERR_STAT_FUNC0_SGXFWERR_MASK                                           (0x00020000U)

#define CTRL_SEC_ERR_STAT_FUNC0_TPCCFWERR_SHIFT                                         (23U)
#define CTRL_SEC_ERR_STAT_FUNC0_TPCCFWERR_MASK                                          (0x00800000U)

#define CTRL_SEC_ERR_STAT_FUNC0_TPTC0FWERR_SHIFT                                        (24U)
#define CTRL_SEC_ERR_STAT_FUNC0_TPTC0FWERR_MASK                                         (0x01000000U)

#define CTRL_SEC_ERR_STAT_FUNC0_TPTC1FWERR_SHIFT                                        (25U)
#define CTRL_SEC_ERR_STAT_FUNC0_TPTC1FWERR_MASK                                         (0x02000000U)

#define CTRL_SEC_ERR_STAT_FUNC0_TPTC2FWERR_SHIFT                                        (26U)
#define CTRL_SEC_ERR_STAT_FUNC0_TPTC2FWERR_MASK                                         (0x04000000U)

#define CTRL_SEC_ERR_STAT_FUNC1_MCASP0FWERR_SHIFT                                       (0U)
#define CTRL_SEC_ERR_STAT_FUNC1_MCASP0FWERR_MASK                                        (0x00000001U)

#define CTRL_SEC_ERR_STAT_FUNC1_MCASP1FWERR_SHIFT                                       (1U)
#define CTRL_SEC_ERR_STAT_FUNC1_MCASP1FWERR_MASK                                        (0x00000002U)

#define CTRL_SEC_ERR_STAT_FUNC1_QSPIFWERR_SHIFT                                         (6U)
#define CTRL_SEC_ERR_STAT_FUNC1_QSPIFWERR_MASK                                          (0x00000040U)

#define CTRL_SEC_ERR_STAT_FUNC1_MAGCARDFWERR_SHIFT                                      (7U)
#define CTRL_SEC_ERR_STAT_FUNC1_MAGCARDFWERR_MASK                                       (0x00000080U)

#define CTRL_SEC_ERR_STAT_FUNC1_ADCFWERR_SHIFT                                          (9U)
#define CTRL_SEC_ERR_STAT_FUNC1_ADCFWERR_MASK                                           (0x00000200U)

#define CTRL_SEC_ERR_STAT_FUNC1_MMCHS2FWERR_SHIFT                                       (15U)
#define CTRL_SEC_ERR_STAT_FUNC1_MMCHS2FWERR_MASK                                        (0x00008000U)

#define CTRL_SEC_ERR_STAT_FUNC1_DBGPORTFWERR_SHIFT                                      (17U)
#define CTRL_SEC_ERR_STAT_FUNC1_DBGPORTFWERR_MASK                                       (0x00020000U)

#define CTRL_SEC_ERR_STAT_FUNC1_SECMODFWERR_SHIFT                                       (18U)
#define CTRL_SEC_ERR_STAT_FUNC1_SECMODFWERR_MASK                                        (0x00040000U)

#define CTRL_SEC_ERR_STAT_FUNC1_CRYPTODMAFWERR_SHIFT                                    (19U)
#define CTRL_SEC_ERR_STAT_FUNC1_CRYPTODMAFWERR_MASK                                     (0x00080000U)

#define CTRL_SEC_ERR_STAT_FUNC1_AES0FWERR_SHIFT                                         (20U)
#define CTRL_SEC_ERR_STAT_FUNC1_AES0FWERR_MASK                                          (0x00100000U)

#define CTRL_SEC_ERR_STAT_FUNC1_SHAFWERR_SHIFT                                          (22U)
#define CTRL_SEC_ERR_STAT_FUNC1_SHAFWERR_MASK                                           (0x00400000U)

#define CTRL_SEC_ERR_STAT_FUNC1_DESFWERR_SHIFT                                          (23U)
#define CTRL_SEC_ERR_STAT_FUNC1_DESFWERR_MASK                                           (0x00800000U)

#define CTRL_SEC_ERR_STAT_FUNC1_L4PERFWERR_SHIFT                                        (24U)
#define CTRL_SEC_ERR_STAT_FUNC1_L4PERFWERR_MASK                                         (0x01000000U)

#define CTRL_SEC_ERR_STAT_FUNC1_L4FASTFWERR_SHIFT                                       (25U)
#define CTRL_SEC_ERR_STAT_FUNC1_L4FASTFWERR_MASK                                        (0x02000000U)

#define CTRL_SEC_ERR_STAT_FUNC1_L4WKUPFWERR_SHIFT                                       (26U)
#define CTRL_SEC_ERR_STAT_FUNC1_L4WKUPFWERR_MASK                                        (0x04000000U)

#define CTRL_SEC_ERR_STAT_FUNC1_L4FWFWERR_SHIFT                                         (27U)
#define CTRL_SEC_ERR_STAT_FUNC1_L4FWFWERR_MASK                                          (0x08000000U)

#define CTRL_SEC_ERR_STAT_DBUG0_L3RAMDBGFWERR_SHIFT                                     (0U)
#define CTRL_SEC_ERR_STAT_DBUG0_L3RAMDBGFWERR_MASK                                      (0x00000001U)

#define CTRL_SEC_ERR_STAT_DBUG0_GPMCDBGFWERR_SHIFT                                      (2U)
#define CTRL_SEC_ERR_STAT_DBUG0_GPMCDBGFWERR_MASK                                       (0x00000004U)

#define CTRL_SEC_ERR_STAT_DBUG0_L2RAMDBGFWERR_SHIFT                                     (3U)
#define CTRL_SEC_ERR_STAT_DBUG0_L2RAMDBGFWERR_MASK                                      (0x00000008U)

#define CTRL_SEC_ERR_STAT_DBUG0_EMIFDBGFWERR_SHIFT                                      (4U)
#define CTRL_SEC_ERR_STAT_DBUG0_EMIFDBGFWERR_MASK                                       (0x00000010U)

#define CTRL_SEC_ERR_STAT_DBUG0_DSSDBGFWERR_SHIFT                                       (6U)
#define CTRL_SEC_ERR_STAT_DBUG0_DSSDBGFWERR_MASK                                        (0x00000040U)

#define CTRL_SEC_ERR_STAT_DBUG0_ICSSDBGFWERR_SHIFT                                      (7U)
#define CTRL_SEC_ERR_STAT_DBUG0_ICSSDBGFWERR_MASK                                       (0x00000080U)

#define CTRL_SEC_ERR_STAT_DBUG0_SGXDBGFWERR_SHIFT                                       (17U)
#define CTRL_SEC_ERR_STAT_DBUG0_SGXDBGFWERR_MASK                                        (0x00020000U)

#define CTRL_SEC_ERR_STAT_DBUG0_TPCCDBGFWERR_SHIFT                                      (23U)
#define CTRL_SEC_ERR_STAT_DBUG0_TPCCDBGFWERR_MASK                                       (0x00800000U)

#define CTRL_SEC_ERR_STAT_DBUG0_TPTC0DBGFWERR_SHIFT                                     (24U)
#define CTRL_SEC_ERR_STAT_DBUG0_TPTC0DBGFWERR_MASK                                      (0x01000000U)

#define CTRL_SEC_ERR_STAT_DBUG0_TPTC1DBGFWERR_SHIFT                                     (25U)
#define CTRL_SEC_ERR_STAT_DBUG0_TPTC1DBGFWERR_MASK                                      (0x02000000U)

#define CTRL_SEC_ERR_STAT_DBUG0_TPTC2DBGFWERR_SHIFT                                     (26U)
#define CTRL_SEC_ERR_STAT_DBUG0_TPTC2DBGFWERR_MASK                                      (0x04000000U)

#define CTRL_SEC_ERR_STAT_DBUG1_MCASP0DBGFWERR_SHIFT                                    (0U)
#define CTRL_SEC_ERR_STAT_DBUG1_MCASP0DBGFWERR_MASK                                     (0x00000001U)

#define CTRL_SEC_ERR_STAT_DBUG1_MCASP1DBGFWERR_SHIFT                                    (1U)
#define CTRL_SEC_ERR_STAT_DBUG1_MCASP1DBGFWERR_MASK                                     (0x00000002U)

#define CTRL_SEC_ERR_STAT_DBUG1_QSPIDBGFWERR_SHIFT                                      (6U)
#define CTRL_SEC_ERR_STAT_DBUG1_QSPIDBGFWERR_MASK                                       (0x00000040U)

#define CTRL_SEC_ERR_STAT_DBUG1_MAGCARDDBGFWERR_SHIFT                                   (7U)
#define CTRL_SEC_ERR_STAT_DBUG1_MAGCARDDBGFWERR_MASK                                    (0x00000080U)

#define CTRL_SEC_ERR_STAT_DBUG1_ADCDBGFWERR_SHIFT                                       (9U)
#define CTRL_SEC_ERR_STAT_DBUG1_ADCDBGFWERR_MASK                                        (0x00000200U)

#define CTRL_SEC_ERR_STAT_DBUG1_MMCHS2DBGFWERR_SHIFT                                    (15U)
#define CTRL_SEC_ERR_STAT_DBUG1_MMCHS2DBGFWERR_MASK                                     (0x00008000U)

#define CTRL_SEC_ERR_STAT_DBUG1_DBGPORTDBGFWERR_SHIFT                                   (17U)
#define CTRL_SEC_ERR_STAT_DBUG1_DBGPORTDBGFWERR_MASK                                    (0x00020000U)

#define CTRL_SEC_ERR_STAT_DBUG1_CRYPTODMADBGFWERR_SHIFT                                 (19U)
#define CTRL_SEC_ERR_STAT_DBUG1_CRYPTODMADBGFWERR_MASK                                  (0x00080000U)

#define CTRL_SEC_ERR_STAT_DBUG1_AES0DBGFWERR_SHIFT                                      (20U)
#define CTRL_SEC_ERR_STAT_DBUG1_AES0DBGFWERR_MASK                                       (0x00100000U)

#define CTRL_SEC_ERR_STAT_DBUG1_SHADBGFWERR_SHIFT                                       (22U)
#define CTRL_SEC_ERR_STAT_DBUG1_SHADBGFWERR_MASK                                        (0x00400000U)

#define CTRL_SEC_ERR_STAT_DBUG1_DESDBGFWERR_SHIFT                                       (23U)
#define CTRL_SEC_ERR_STAT_DBUG1_DESDBGFWERR_MASK                                        (0x00800000U)

#define CTRL_SEC_ERR_STAT_DBUG1_L4PERDBGFWERR_SHIFT                                     (24U)
#define CTRL_SEC_ERR_STAT_DBUG1_L4PERDBGFWERR_MASK                                      (0x01000000U)

#define CTRL_SEC_ERR_STAT_DBUG1_L4FASTDBGFWERR_SHIFT                                    (25U)
#define CTRL_SEC_ERR_STAT_DBUG1_L4FASTDBGFWERR_MASK                                     (0x02000000U)

#define CTRL_SEC_ERR_STAT_DBUG1_L4WKUPDBGFWERR_SHIFT                                    (26U)
#define CTRL_SEC_ERR_STAT_DBUG1_L4WKUPDBGFWERR_MASK                                     (0x04000000U)

#define CTRL_SEC_ERR_STAT_DBUG1_L4FWDBGFWERR_SHIFT                                      (27U)
#define CTRL_SEC_ERR_STAT_DBUG1_L4FWDBGFWERR_MASK                                       (0x08000000U)

#define CTRL_KEK_SW_0_SHIFT                                                             (0U)
#define CTRL_KEK_SW_0_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_1_SHIFT                                                             (0U)
#define CTRL_KEK_SW_1_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_2_SHIFT                                                             (0U)
#define CTRL_KEK_SW_2_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_3_SHIFT                                                             (0U)
#define CTRL_KEK_SW_3_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_4_SHIFT                                                             (0U)
#define CTRL_KEK_SW_4_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_5_SHIFT                                                             (0U)
#define CTRL_KEK_SW_5_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_6_SHIFT                                                             (0U)
#define CTRL_KEK_SW_6_MASK                                                              (0xffffffffU)

#define CTRL_KEK_SW_7_SHIFT                                                             (0U)
#define CTRL_KEK_SW_7_MASK                                                              (0xffffffffU)

#define CTRL_SMEK_0_SHIFT                                                               (0U)
#define CTRL_SMEK_0_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_1_SHIFT                                                               (0U)
#define CTRL_SMEK_1_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_2_SHIFT                                                               (0U)
#define CTRL_SMEK_2_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_3_SHIFT                                                               (0U)
#define CTRL_SMEK_3_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_4_SHIFT                                                               (0U)
#define CTRL_SMEK_4_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_5_SHIFT                                                               (0U)
#define CTRL_SMEK_5_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_6_SHIFT                                                               (0U)
#define CTRL_SMEK_6_MASK                                                                (0xffffffffU)

#define CTRL_SMEK_7_SHIFT                                                               (0U)
#define CTRL_SMEK_7_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_0_SHIFT                                                               (0U)
#define CTRL_SMPK_0_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_1_SHIFT                                                               (0U)
#define CTRL_SMPK_1_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_2_SHIFT                                                               (0U)
#define CTRL_SMPK_2_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_3_SHIFT                                                               (0U)
#define CTRL_SMPK_3_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_4_SHIFT                                                               (0U)
#define CTRL_SMPK_4_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_5_SHIFT                                                               (0U)
#define CTRL_SMPK_5_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_6_SHIFT                                                               (0U)
#define CTRL_SMPK_6_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_7_SHIFT                                                               (0U)
#define CTRL_SMPK_7_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_8_SHIFT                                                               (0U)
#define CTRL_SMPK_8_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_9_SHIFT                                                               (0U)
#define CTRL_SMPK_9_MASK                                                                (0xffffffffU)

#define CTRL_SMPK_10_SHIFT                                                              (0U)
#define CTRL_SMPK_10_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_11_SHIFT                                                              (0U)
#define CTRL_SMPK_11_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_12_SHIFT                                                              (0U)
#define CTRL_SMPK_12_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_13_SHIFT                                                              (0U)
#define CTRL_SMPK_13_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_14_SHIFT                                                              (0U)
#define CTRL_SMPK_14_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_15_SHIFT                                                              (0U)
#define CTRL_SMPK_15_MASK                                                               (0xffffffffU)

#define CTRL_SMPK_BCH_0_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_0_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_1_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_1_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_2_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_2_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_3_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_3_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_4_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_4_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_5_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_5_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_6_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_6_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_7_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_7_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_8_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_8_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_9_SHIFT                                                           (0U)
#define CTRL_SMPK_BCH_9_MASK                                                            (0xffffffffU)

#define CTRL_SMPK_BCH_10_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_10_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_11_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_11_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_12_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_12_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_13_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_13_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_14_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_14_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_15_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_15_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_16_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_16_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_17_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_17_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_18_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_18_MASK                                                           (0xffffffffU)

#define CTRL_SMPK_BCH_19_SHIFT                                                          (0U)
#define CTRL_SMPK_BCH_19_MASK                                                           (0xffffffffU)

#define CTRL_SMEK_BCH_0_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_0_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_1_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_1_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_2_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_2_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_3_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_3_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_4_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_4_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_5_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_5_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_6_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_6_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_7_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_7_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_8_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_8_MASK                                                            (0xffffffffU)

#define CTRL_SMEK_BCH_9_SHIFT                                                           (0U)
#define CTRL_SMEK_BCH_9_MASK                                                            (0xffffffffU)

#define CTRL_CANARY_TUN_SEL_0_SHIFT                                                     (0U)
#define CTRL_CANARY_TUN_SEL_0_MASK                                                      (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_0_1_SHIFT                                                   (8U)
#define CTRL_CANARY_TUN_SEL_0_1_MASK                                                    (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_0_2_SHIFT                                                   (16U)
#define CTRL_CANARY_TUN_SEL_0_2_MASK                                                    (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_0_3_SHIFT                                                   (24U)
#define CTRL_CANARY_TUN_SEL_0_3_MASK                                                    (0xff000000U)

#define CTRL_CANARY_TUN_SEL_1_4_SHIFT                                                   (0U)
#define CTRL_CANARY_TUN_SEL_1_4_MASK                                                    (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_1_5_SHIFT                                                   (8U)
#define CTRL_CANARY_TUN_SEL_1_5_MASK                                                    (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_1_6_SHIFT                                                   (16U)
#define CTRL_CANARY_TUN_SEL_1_6_MASK                                                    (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_1_7_SHIFT                                                   (24U)
#define CTRL_CANARY_TUN_SEL_1_7_MASK                                                    (0xff000000U)

#define CTRL_CANARY_TUN_SEL_2_8_SHIFT                                                   (0U)
#define CTRL_CANARY_TUN_SEL_2_8_MASK                                                    (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_2_9_SHIFT                                                   (8U)
#define CTRL_CANARY_TUN_SEL_2_9_MASK                                                    (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_2_10_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_2_10_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_2_11_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_2_11_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_3_12_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_3_12_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_3_13_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_3_13_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_3_14_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_3_14_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_3_15_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_3_15_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_4_16_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_4_16_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_4_17_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_4_17_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_4_18_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_4_18_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_4_19_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_4_19_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_5_20_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_5_20_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_5_21_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_5_21_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_5_22_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_5_22_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_5_23_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_5_23_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_6_24_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_6_24_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_6_25_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_6_25_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_6_26_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_6_26_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_6_27_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_6_27_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_7_28_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_7_28_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_7_29_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_7_29_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_7_30_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_7_30_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_7_31_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_7_31_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_8_32_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_8_32_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_8_33_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_8_33_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_8_34_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_8_34_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_8_35_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_8_35_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_9_36_SHIFT                                                  (0U)
#define CTRL_CANARY_TUN_SEL_9_36_MASK                                                   (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_9_37_SHIFT                                                  (8U)
#define CTRL_CANARY_TUN_SEL_9_37_MASK                                                   (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_9_38_SHIFT                                                  (16U)
#define CTRL_CANARY_TUN_SEL_9_38_MASK                                                   (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_9_39_SHIFT                                                  (24U)
#define CTRL_CANARY_TUN_SEL_9_39_MASK                                                   (0xff000000U)

#define CTRL_CANARY_TUN_SEL_10_40_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_10_40_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_10_41_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_10_41_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_10_42_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_10_42_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_10_43_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_10_43_MASK                                                  (0xff000000U)

#define CTRL_CANARY_TUN_SEL_11_44_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_11_44_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_11_45_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_11_45_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_11_46_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_11_46_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_11_47_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_11_47_MASK                                                  (0xff000000U)

#define CTRL_CANARY_TUN_SEL_12_48_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_12_48_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_12_49_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_12_49_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_12_50_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_12_50_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_12_51_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_12_51_MASK                                                  (0xff000000U)

#define CTRL_CANARY_TUN_SEL_13_52_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_13_52_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_13_53_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_13_53_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_13_54_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_13_54_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_13_55_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_13_55_MASK                                                  (0xff000000U)

#define CTRL_CANARY_TUN_SEL_14_56_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_14_56_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_14_57_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_14_57_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_14_58_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_14_58_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_14_59_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_14_59_MASK                                                  (0xff000000U)

#define CTRL_CANARY_TUN_SEL_15_60_SHIFT                                                 (0U)
#define CTRL_CANARY_TUN_SEL_15_60_MASK                                                  (0x000000ffU)

#define CTRL_CANARY_TUN_SEL_15_61_SHIFT                                                 (8U)
#define CTRL_CANARY_TUN_SEL_15_61_MASK                                                  (0x0000ff00U)

#define CTRL_CANARY_TUN_SEL_15_62_SHIFT                                                 (16U)
#define CTRL_CANARY_TUN_SEL_15_62_MASK                                                  (0x00ff0000U)

#define CTRL_CANARY_TUN_SEL_15_63_SHIFT                                                 (24U)
#define CTRL_CANARY_TUN_SEL_15_63_MASK                                                  (0xff000000U)

#define CTRL_CANARY_EN_0_CAN_SHIFT                                                      (0U)
#define CTRL_CANARY_EN_0_CAN_MASK                                                       (0x00000001U)

#define CTRL_CANARY_EN_0_CAN_1_SHIFT                                                    (1U)
#define CTRL_CANARY_EN_0_CAN_1_MASK                                                     (0x00000002U)

#define CTRL_CANARY_EN_0_CAN_2_SHIFT                                                    (2U)
#define CTRL_CANARY_EN_0_CAN_2_MASK                                                     (0x00000004U)

#define CTRL_CANARY_EN_0_CAN_3_SHIFT                                                    (3U)
#define CTRL_CANARY_EN_0_CAN_3_MASK                                                     (0x00000008U)

#define CTRL_CANARY_EN_0_CAN_4_SHIFT                                                    (4U)
#define CTRL_CANARY_EN_0_CAN_4_MASK                                                     (0x00000010U)

#define CTRL_CANARY_EN_0_CAN_5_SHIFT                                                    (5U)
#define CTRL_CANARY_EN_0_CAN_5_MASK                                                     (0x00000020U)

#define CTRL_CANARY_EN_0_CAN_6_SHIFT                                                    (6U)
#define CTRL_CANARY_EN_0_CAN_6_MASK                                                     (0x00000040U)

#define CTRL_CANARY_EN_0_CAN_7_SHIFT                                                    (7U)
#define CTRL_CANARY_EN_0_CAN_7_MASK                                                     (0x00000080U)

#define CTRL_CANARY_EN_0_CAN_8_SHIFT                                                    (8U)
#define CTRL_CANARY_EN_0_CAN_8_MASK                                                     (0x00000100U)

#define CTRL_CANARY_EN_0_CAN_9_SHIFT                                                    (9U)
#define CTRL_CANARY_EN_0_CAN_9_MASK                                                     (0x00000200U)

#define CTRL_CANARY_EN_0_CAN_10_SHIFT                                                   (10U)
#define CTRL_CANARY_EN_0_CAN_10_MASK                                                    (0x00000400U)

#define CTRL_CANARY_EN_0_CAN_11_SHIFT                                                   (11U)
#define CTRL_CANARY_EN_0_CAN_11_MASK                                                    (0x00000800U)

#define CTRL_CANARY_EN_0_CAN_12_SHIFT                                                   (12U)
#define CTRL_CANARY_EN_0_CAN_12_MASK                                                    (0x00001000U)

#define CTRL_CANARY_EN_0_CAN_13_SHIFT                                                   (13U)
#define CTRL_CANARY_EN_0_CAN_13_MASK                                                    (0x00002000U)

#define CTRL_CANARY_EN_0_CAN_14_SHIFT                                                   (14U)
#define CTRL_CANARY_EN_0_CAN_14_MASK                                                    (0x00004000U)

#define CTRL_CANARY_EN_0_CAN_15_SHIFT                                                   (15U)
#define CTRL_CANARY_EN_0_CAN_15_MASK                                                    (0x00008000U)

#define CTRL_CANARY_EN_0_CAN_16_SHIFT                                                   (16U)
#define CTRL_CANARY_EN_0_CAN_16_MASK                                                    (0x00010000U)

#define CTRL_CANARY_EN_0_CAN_17_SHIFT                                                   (17U)
#define CTRL_CANARY_EN_0_CAN_17_MASK                                                    (0x00020000U)

#define CTRL_CANARY_EN_0_CAN_18_SHIFT                                                   (18U)
#define CTRL_CANARY_EN_0_CAN_18_MASK                                                    (0x00040000U)

#define CTRL_CANARY_EN_0_CAN_19_SHIFT                                                   (19U)
#define CTRL_CANARY_EN_0_CAN_19_MASK                                                    (0x00080000U)

#define CTRL_CANARY_EN_0_CAN_20_SHIFT                                                   (20U)
#define CTRL_CANARY_EN_0_CAN_20_MASK                                                    (0x00100000U)

#define CTRL_CANARY_EN_0_CAN_21_SHIFT                                                   (21U)
#define CTRL_CANARY_EN_0_CAN_21_MASK                                                    (0x00200000U)

#define CTRL_CANARY_EN_0_CAN_22_SHIFT                                                   (22U)
#define CTRL_CANARY_EN_0_CAN_22_MASK                                                    (0x00400000U)

#define CTRL_CANARY_EN_0_CAN_23_SHIFT                                                   (23U)
#define CTRL_CANARY_EN_0_CAN_23_MASK                                                    (0x00800000U)

#define CTRL_CANARY_EN_0_CAN_24_SHIFT                                                   (24U)
#define CTRL_CANARY_EN_0_CAN_24_MASK                                                    (0x01000000U)

#define CTRL_CANARY_EN_0_CAN_25_SHIFT                                                   (25U)
#define CTRL_CANARY_EN_0_CAN_25_MASK                                                    (0x02000000U)

#define CTRL_CANARY_EN_0_CAN_26_SHIFT                                                   (26U)
#define CTRL_CANARY_EN_0_CAN_26_MASK                                                    (0x04000000U)

#define CTRL_CANARY_EN_0_CAN_27_SHIFT                                                   (27U)
#define CTRL_CANARY_EN_0_CAN_27_MASK                                                    (0x08000000U)

#define CTRL_CANARY_EN_0_CAN_28_SHIFT                                                   (28U)
#define CTRL_CANARY_EN_0_CAN_28_MASK                                                    (0x10000000U)

#define CTRL_CANARY_EN_0_CAN_29_SHIFT                                                   (29U)
#define CTRL_CANARY_EN_0_CAN_29_MASK                                                    (0x20000000U)

#define CTRL_CANARY_EN_0_CAN_30_SHIFT                                                   (30U)
#define CTRL_CANARY_EN_0_CAN_30_MASK                                                    (0x40000000U)

#define CTRL_CANARY_EN_0_CAN_31_SHIFT                                                   (31U)
#define CTRL_CANARY_EN_0_CAN_31_MASK                                                    (0x80000000U)

#define CTRL_CANARY_EN_1_CAN_32_SHIFT                                                   (0U)
#define CTRL_CANARY_EN_1_CAN_32_MASK                                                    (0x00000001U)

#define CTRL_CANARY_EN_1_CAN_33_SHIFT                                                   (1U)
#define CTRL_CANARY_EN_1_CAN_33_MASK                                                    (0x00000002U)

#define CTRL_CANARY_EN_1_CAN_34_SHIFT                                                   (2U)
#define CTRL_CANARY_EN_1_CAN_34_MASK                                                    (0x00000004U)

#define CTRL_CANARY_EN_1_CAN_35_SHIFT                                                   (3U)
#define CTRL_CANARY_EN_1_CAN_35_MASK                                                    (0x00000008U)

#define CTRL_CANARY_EN_1_CAN_36_SHIFT                                                   (4U)
#define CTRL_CANARY_EN_1_CAN_36_MASK                                                    (0x00000010U)

#define CTRL_CANARY_EN_1_CAN_37_SHIFT                                                   (5U)
#define CTRL_CANARY_EN_1_CAN_37_MASK                                                    (0x00000020U)

#define CTRL_CANARY_EN_1_CAN_38_SHIFT                                                   (6U)
#define CTRL_CANARY_EN_1_CAN_38_MASK                                                    (0x00000040U)

#define CTRL_CANARY_EN_1_CAN_39_SHIFT                                                   (7U)
#define CTRL_CANARY_EN_1_CAN_39_MASK                                                    (0x00000080U)

#define CTRL_CANARY_EN_1_CAN_40_SHIFT                                                   (8U)
#define CTRL_CANARY_EN_1_CAN_40_MASK                                                    (0x00000100U)

#define CTRL_CANARY_EN_1_CAN_41_SHIFT                                                   (9U)
#define CTRL_CANARY_EN_1_CAN_41_MASK                                                    (0x00000200U)

#define CTRL_CANARY_EN_1_CAN_42_SHIFT                                                   (10U)
#define CTRL_CANARY_EN_1_CAN_42_MASK                                                    (0x00000400U)

#define CTRL_CANARY_EN_1_CAN_43_SHIFT                                                   (11U)
#define CTRL_CANARY_EN_1_CAN_43_MASK                                                    (0x00000800U)

#define CTRL_CANARY_EN_1_CAN_44_SHIFT                                                   (12U)
#define CTRL_CANARY_EN_1_CAN_44_MASK                                                    (0x00001000U)

#define CTRL_CANARY_EN_1_CAN_45_SHIFT                                                   (13U)
#define CTRL_CANARY_EN_1_CAN_45_MASK                                                    (0x00002000U)

#define CTRL_CANARY_EN_1_CAN_46_SHIFT                                                   (14U)
#define CTRL_CANARY_EN_1_CAN_46_MASK                                                    (0x00004000U)

#define CTRL_CANARY_EN_1_CAN_47_SHIFT                                                   (15U)
#define CTRL_CANARY_EN_1_CAN_47_MASK                                                    (0x00008000U)

#define CTRL_CANARY_EN_1_CAN_48_SHIFT                                                   (16U)
#define CTRL_CANARY_EN_1_CAN_48_MASK                                                    (0x00010000U)

#define CTRL_CANARY_EN_1_CAN_49_SHIFT                                                   (17U)
#define CTRL_CANARY_EN_1_CAN_49_MASK                                                    (0x00020000U)

#define CTRL_CANARY_EN_1_CAN_50_SHIFT                                                   (18U)
#define CTRL_CANARY_EN_1_CAN_50_MASK                                                    (0x00040000U)

#define CTRL_CANARY_EN_1_CAN_51_SHIFT                                                   (19U)
#define CTRL_CANARY_EN_1_CAN_51_MASK                                                    (0x00080000U)

#define CTRL_CANARY_EN_1_CAN_52_SHIFT                                                   (20U)
#define CTRL_CANARY_EN_1_CAN_52_MASK                                                    (0x00100000U)

#define CTRL_CANARY_EN_1_CAN_53_SHIFT                                                   (21U)
#define CTRL_CANARY_EN_1_CAN_53_MASK                                                    (0x00200000U)

#define CTRL_CANARY_EN_1_CAN_54_SHIFT                                                   (22U)
#define CTRL_CANARY_EN_1_CAN_54_MASK                                                    (0x00400000U)

#define CTRL_CANARY_EN_1_CAN_55_SHIFT                                                   (23U)
#define CTRL_CANARY_EN_1_CAN_55_MASK                                                    (0x00800000U)

#define CTRL_CANARY_EN_1_CAN_56_SHIFT                                                   (24U)
#define CTRL_CANARY_EN_1_CAN_56_MASK                                                    (0x01000000U)

#define CTRL_CANARY_EN_1_CAN_57_SHIFT                                                   (25U)
#define CTRL_CANARY_EN_1_CAN_57_MASK                                                    (0x02000000U)

#define CTRL_CANARY_EN_1_CAN_58_SHIFT                                                   (26U)
#define CTRL_CANARY_EN_1_CAN_58_MASK                                                    (0x04000000U)

#define CTRL_CANARY_EN_1_CAN_59_SHIFT                                                   (27U)
#define CTRL_CANARY_EN_1_CAN_59_MASK                                                    (0x08000000U)

#define CTRL_CANARY_EN_1_CAN_60_SHIFT                                                   (28U)
#define CTRL_CANARY_EN_1_CAN_60_MASK                                                    (0x10000000U)

#define CTRL_CANARY_EN_1_CAN_61_SHIFT                                                   (29U)
#define CTRL_CANARY_EN_1_CAN_61_MASK                                                    (0x20000000U)

#define CTRL_CANARY_EN_1_CAN_62_SHIFT                                                   (30U)
#define CTRL_CANARY_EN_1_CAN_62_MASK                                                    (0x40000000U)

#define CTRL_CANARY_EN_1_CAN_63_SHIFT                                                   (31U)
#define CTRL_CANARY_EN_1_CAN_63_MASK                                                    (0x80000000U)

#define CTRL_CANARY_STAT_0_CAN_SHIFT                                                    (0U)
#define CTRL_CANARY_STAT_0_CAN_MASK                                                     (0x00000001U)

#define CTRL_CANARY_STAT_0_CAN_1_SHIFT                                                  (1U)
#define CTRL_CANARY_STAT_0_CAN_1_MASK                                                   (0x00000002U)

#define CTRL_CANARY_STAT_0_CAN_2_SHIFT                                                  (2U)
#define CTRL_CANARY_STAT_0_CAN_2_MASK                                                   (0x00000004U)

#define CTRL_CANARY_STAT_0_CAN_3_SHIFT                                                  (3U)
#define CTRL_CANARY_STAT_0_CAN_3_MASK                                                   (0x00000008U)

#define CTRL_CANARY_STAT_0_CAN_4_SHIFT                                                  (4U)
#define CTRL_CANARY_STAT_0_CAN_4_MASK                                                   (0x00000010U)

#define CTRL_CANARY_STAT_0_CAN_5_SHIFT                                                  (5U)
#define CTRL_CANARY_STAT_0_CAN_5_MASK                                                   (0x00000020U)

#define CTRL_CANARY_STAT_0_CAN_6_SHIFT                                                  (6U)
#define CTRL_CANARY_STAT_0_CAN_6_MASK                                                   (0x00000040U)

#define CTRL_CANARY_STAT_0_CAN_7_SHIFT                                                  (7U)
#define CTRL_CANARY_STAT_0_CAN_7_MASK                                                   (0x00000080U)

#define CTRL_CANARY_STAT_0_CAN_8_SHIFT                                                  (8U)
#define CTRL_CANARY_STAT_0_CAN_8_MASK                                                   (0x00000100U)

#define CTRL_CANARY_STAT_0_CAN_9_SHIFT                                                  (9U)
#define CTRL_CANARY_STAT_0_CAN_9_MASK                                                   (0x00000200U)

#define CTRL_CANARY_STAT_0_CAN_10_SHIFT                                                 (10U)
#define CTRL_CANARY_STAT_0_CAN_10_MASK                                                  (0x00000400U)

#define CTRL_CANARY_STAT_0_CAN_11_SHIFT                                                 (11U)
#define CTRL_CANARY_STAT_0_CAN_11_MASK                                                  (0x00000800U)

#define CTRL_CANARY_STAT_0_CAN_12_SHIFT                                                 (12U)
#define CTRL_CANARY_STAT_0_CAN_12_MASK                                                  (0x00001000U)

#define CTRL_CANARY_STAT_0_CAN_13_SHIFT                                                 (13U)
#define CTRL_CANARY_STAT_0_CAN_13_MASK                                                  (0x00002000U)

#define CTRL_CANARY_STAT_0_CAN_14_SHIFT                                                 (14U)
#define CTRL_CANARY_STAT_0_CAN_14_MASK                                                  (0x00004000U)

#define CTRL_CANARY_STAT_0_CAN_15_SHIFT                                                 (15U)
#define CTRL_CANARY_STAT_0_CAN_15_MASK                                                  (0x00008000U)

#define CTRL_CANARY_STAT_0_CAN_16_SHIFT                                                 (16U)
#define CTRL_CANARY_STAT_0_CAN_16_MASK                                                  (0x00010000U)

#define CTRL_CANARY_STAT_0_CAN_17_SHIFT                                                 (17U)
#define CTRL_CANARY_STAT_0_CAN_17_MASK                                                  (0x00020000U)

#define CTRL_CANARY_STAT_0_CAN_18_SHIFT                                                 (18U)
#define CTRL_CANARY_STAT_0_CAN_18_MASK                                                  (0x00040000U)

#define CTRL_CANARY_STAT_0_CAN_19_SHIFT                                                 (19U)
#define CTRL_CANARY_STAT_0_CAN_19_MASK                                                  (0x00080000U)

#define CTRL_CANARY_STAT_0_CAN_20_SHIFT                                                 (20U)
#define CTRL_CANARY_STAT_0_CAN_20_MASK                                                  (0x00100000U)

#define CTRL_CANARY_STAT_0_CAN_21_SHIFT                                                 (21U)
#define CTRL_CANARY_STAT_0_CAN_21_MASK                                                  (0x00200000U)

#define CTRL_CANARY_STAT_0_CAN_22_SHIFT                                                 (22U)
#define CTRL_CANARY_STAT_0_CAN_22_MASK                                                  (0x00400000U)

#define CTRL_CANARY_STAT_0_CAN_23_SHIFT                                                 (23U)
#define CTRL_CANARY_STAT_0_CAN_23_MASK                                                  (0x00800000U)

#define CTRL_CANARY_STAT_0_CAN_24_SHIFT                                                 (24U)
#define CTRL_CANARY_STAT_0_CAN_24_MASK                                                  (0x01000000U)

#define CTRL_CANARY_STAT_0_CAN_25_SHIFT                                                 (25U)
#define CTRL_CANARY_STAT_0_CAN_25_MASK                                                  (0x02000000U)

#define CTRL_CANARY_STAT_0_CAN_26_SHIFT                                                 (26U)
#define CTRL_CANARY_STAT_0_CAN_26_MASK                                                  (0x04000000U)

#define CTRL_CANARY_STAT_0_CAN_27_SHIFT                                                 (27U)
#define CTRL_CANARY_STAT_0_CAN_27_MASK                                                  (0x08000000U)

#define CTRL_CANARY_STAT_0_CAN_28_SHIFT                                                 (28U)
#define CTRL_CANARY_STAT_0_CAN_28_MASK                                                  (0x10000000U)

#define CTRL_CANARY_STAT_0_CAN_29_SHIFT                                                 (29U)
#define CTRL_CANARY_STAT_0_CAN_29_MASK                                                  (0x20000000U)

#define CTRL_CANARY_STAT_0_CAN_30_SHIFT                                                 (30U)
#define CTRL_CANARY_STAT_0_CAN_30_MASK                                                  (0x40000000U)

#define CTRL_CANARY_STAT_0_CAN_31_SHIFT                                                 (31U)
#define CTRL_CANARY_STAT_0_CAN_31_MASK                                                  (0x80000000U)

#define CTRL_CANARY_STAT_1_CAN_32_SHIFT                                                 (0U)
#define CTRL_CANARY_STAT_1_CAN_32_MASK                                                  (0x00000001U)

#define CTRL_CANARY_STAT_1_CAN_33_SHIFT                                                 (1U)
#define CTRL_CANARY_STAT_1_CAN_33_MASK                                                  (0x00000002U)

#define CTRL_CANARY_STAT_1_CAN_34_SHIFT                                                 (2U)
#define CTRL_CANARY_STAT_1_CAN_34_MASK                                                  (0x00000004U)

#define CTRL_CANARY_STAT_1_CAN_35_SHIFT                                                 (3U)
#define CTRL_CANARY_STAT_1_CAN_35_MASK                                                  (0x00000008U)

#define CTRL_CANARY_STAT_1_CAN_36_SHIFT                                                 (4U)
#define CTRL_CANARY_STAT_1_CAN_36_MASK                                                  (0x00000010U)

#define CTRL_CANARY_STAT_1_CAN_37_SHIFT                                                 (5U)
#define CTRL_CANARY_STAT_1_CAN_37_MASK                                                  (0x00000020U)

#define CTRL_CANARY_STAT_1_CAN_38_SHIFT                                                 (6U)
#define CTRL_CANARY_STAT_1_CAN_38_MASK                                                  (0x00000040U)

#define CTRL_CANARY_STAT_1_CAN_39_SHIFT                                                 (7U)
#define CTRL_CANARY_STAT_1_CAN_39_MASK                                                  (0x00000080U)

#define CTRL_CANARY_STAT_1_CAN_40_SHIFT                                                 (8U)
#define CTRL_CANARY_STAT_1_CAN_40_MASK                                                  (0x00000100U)

#define CTRL_CANARY_STAT_1_CAN_41_SHIFT                                                 (9U)
#define CTRL_CANARY_STAT_1_CAN_41_MASK                                                  (0x00000200U)

#define CTRL_CANARY_STAT_1_CAN_42_SHIFT                                                 (10U)
#define CTRL_CANARY_STAT_1_CAN_42_MASK                                                  (0x00000400U)

#define CTRL_CANARY_STAT_1_CAN_43_SHIFT                                                 (11U)
#define CTRL_CANARY_STAT_1_CAN_43_MASK                                                  (0x00000800U)

#define CTRL_CANARY_STAT_1_CAN_44_SHIFT                                                 (12U)
#define CTRL_CANARY_STAT_1_CAN_44_MASK                                                  (0x00001000U)

#define CTRL_CANARY_STAT_1_CAN_45_SHIFT                                                 (13U)
#define CTRL_CANARY_STAT_1_CAN_45_MASK                                                  (0x00002000U)

#define CTRL_CANARY_STAT_1_CAN_46_SHIFT                                                 (14U)
#define CTRL_CANARY_STAT_1_CAN_46_MASK                                                  (0x00004000U)

#define CTRL_CANARY_STAT_1_CAN_47_SHIFT                                                 (15U)
#define CTRL_CANARY_STAT_1_CAN_47_MASK                                                  (0x00008000U)

#define CTRL_CANARY_STAT_1_CAN_48_SHIFT                                                 (16U)
#define CTRL_CANARY_STAT_1_CAN_48_MASK                                                  (0x00010000U)

#define CTRL_CANARY_STAT_1_CAN_49_SHIFT                                                 (17U)
#define CTRL_CANARY_STAT_1_CAN_49_MASK                                                  (0x00020000U)

#define CTRL_CANARY_STAT_1_CAN_50_SHIFT                                                 (18U)
#define CTRL_CANARY_STAT_1_CAN_50_MASK                                                  (0x00040000U)

#define CTRL_CANARY_STAT_1_CAN_51_SHIFT                                                 (19U)
#define CTRL_CANARY_STAT_1_CAN_51_MASK                                                  (0x00080000U)

#define CTRL_CANARY_STAT_1_CAN_52_SHIFT                                                 (20U)
#define CTRL_CANARY_STAT_1_CAN_52_MASK                                                  (0x00100000U)

#define CTRL_CANARY_STAT_1_CAN_53_SHIFT                                                 (21U)
#define CTRL_CANARY_STAT_1_CAN_53_MASK                                                  (0x00200000U)

#define CTRL_CANARY_STAT_1_CAN_54_SHIFT                                                 (22U)
#define CTRL_CANARY_STAT_1_CAN_54_MASK                                                  (0x00400000U)

#define CTRL_CANARY_STAT_1_CAN_55_SHIFT                                                 (23U)
#define CTRL_CANARY_STAT_1_CAN_55_MASK                                                  (0x00800000U)

#define CTRL_CANARY_STAT_1_CAN_56_SHIFT                                                 (24U)
#define CTRL_CANARY_STAT_1_CAN_56_MASK                                                  (0x01000000U)

#define CTRL_CANARY_STAT_1_CAN_57_SHIFT                                                 (25U)
#define CTRL_CANARY_STAT_1_CAN_57_MASK                                                  (0x02000000U)

#define CTRL_CANARY_STAT_1_CAN_58_SHIFT                                                 (26U)
#define CTRL_CANARY_STAT_1_CAN_58_MASK                                                  (0x04000000U)

#define CTRL_CANARY_STAT_1_CAN_59_SHIFT                                                 (27U)
#define CTRL_CANARY_STAT_1_CAN_59_MASK                                                  (0x08000000U)

#define CTRL_CANARY_STAT_1_CAN_60_SHIFT                                                 (28U)
#define CTRL_CANARY_STAT_1_CAN_60_MASK                                                  (0x10000000U)

#define CTRL_CANARY_STAT_1_CAN_61_SHIFT                                                 (29U)
#define CTRL_CANARY_STAT_1_CAN_61_MASK                                                  (0x20000000U)

#define CTRL_CANARY_STAT_1_CAN_62_SHIFT                                                 (30U)
#define CTRL_CANARY_STAT_1_CAN_62_MASK                                                  (0x40000000U)

#define CTRL_CANARY_STAT_1_CAN_63_SHIFT                                                 (31U)
#define CTRL_CANARY_STAT_1_CAN_63_MASK                                                  (0x80000000U)

#define CTRL_CANARY_FSM_ENA_SHIFT                                                       (0U)
#define CTRL_CANARY_FSM_ENA_MASK                                                        (0x00000001U)

#define CTRL_CANARY_FSM_TMRCTR_SHIFT                                                    (1U)
#define CTRL_CANARY_FSM_TMRCTR_MASK                                                     (0x000003feU)

#define CTRL_CANARY_FSM_THRCTR_SHIFT                                                    (10U)
#define CTRL_CANARY_FSM_THRCTR_MASK                                                     (0x0007fc00U)

#define CTRL_CANARY_FSM_CAN_RSVDB_SHIFT                                                 (19U)
#define CTRL_CANARY_FSM_CAN_RSVDB_MASK                                                  (0x00f80000U)

#define CTRL_CANARY_FSM_RST_QSM_SHIFT                                                   (24U)
#define CTRL_CANARY_FSM_RST_QSM_MASK                                                    (0x01000000U)

#define CTRL_CANARY_FSM_DISTIMER_SHIFT                                                  (25U)
#define CTRL_CANARY_FSM_DISTIMER_MASK                                                   (0x02000000U)

#define CTRL_CANARY_FSM_CAN_RSVDA2_SHIFT                                                (26U)
#define CTRL_CANARY_FSM_CAN_RSVDA2_MASK                                                 (0xfc000000U)

#define CTRL_SSM_END_FAST_SECRAM_SHIFT                                                  (10U)
#define CTRL_SSM_END_FAST_SECRAM_MASK                                                   (0x0000fc00U)

#define CTRL_SSM_END_L3_SECRAM_SHIFT                                                    (10U)
#define CTRL_SSM_END_L3_SECRAM_MASK                                                     (0x0000fc00U)

#define CTRL_SSM_START_L3_SECRAM_SHIFT                                                  (10U)
#define CTRL_SSM_START_L3_SECRAM_MASK                                                   (0xfffffc00U)

#define CTRL_CORTEX_VBBLDO_NOVBGBYR_SHIFT                                               (0U)
#define CTRL_CORTEX_VBBLDO_NOVBGBYR_MASK                                                (0x00000001U)

#define CTRL_CORTEX_VBBLDO_NOCAP_SHIFT                                                  (1U)
#define CTRL_CORTEX_VBBLDO_NOCAP_MASK                                                   (0x00000002U)

#define CTRL_CORTEX_VBBLDO_BBSEL_SHIFT                                                  (2U)
#define CTRL_CORTEX_VBBLDO_BBSEL_MASK                                                   (0x00000004U)

#define CTRL_CORTEX_VBBLDO_HZ_SHIFT                                                     (3U)
#define CTRL_CORTEX_VBBLDO_HZ_MASK                                                      (0x00000008U)

#define CTRL_CORTEX_VBBLDO_LOWPWR_SHIFT                                                 (4U)
#define CTRL_CORTEX_VBBLDO_LOWPWR_MASK                                                  (0x00000010U)

#define CTRL_CORTEX_VBBLDO_LDOBYPASSZ_SHIFT                                             (5U)
#define CTRL_CORTEX_VBBLDO_LDOBYPASSZ_MASK                                              (0x00000020U)

#define CTRL_CORTEX_VBBLDO_VSETRBB_SHIFT                                                (16U)
#define CTRL_CORTEX_VBBLDO_VSETRBB_MASK                                                 (0x001f0000U)

#define CTRL_CORTEX_VBBLDO_VSETFBB_SHIFT                                                (21U)
#define CTRL_CORTEX_VBBLDO_VSETFBB_MASK                                                 (0x03e00000U)

#define CTRL_CORE_SLDO_VSET_SHIFT                                                       (16U)
#define CTRL_CORE_SLDO_VSET_MASK                                                        (0x03ff0000U)

#define CTRL_MPU_SLDO_VSET_SHIFT                                                        (16U)
#define CTRL_MPU_SLDO_VSET_MASK                                                         (0x03ff0000U)

#define CTRL_CLK32KDIVRATIO_CLKDIVOPP50_EN_SHIFT                                        (0U)
#define CTRL_CLK32KDIVRATIO_CLKDIVOPP50_EN_MASK                                         (0x00000001U)

#define CTRL_BANDGAP_TSHUT_SHIFT                                                        (0U)
#define CTRL_BANDGAP_TSHUT_MASK                                                         (0x00000001U)

#define CTRL_BANDGAP_ECOZ_SHIFT                                                         (1U)
#define CTRL_BANDGAP_ECOZ_MASK                                                          (0x00000002U)

#define CTRL_BANDGAP_CONTCONV_SHIFT                                                     (2U)
#define CTRL_BANDGAP_CONTCONV_MASK                                                      (0x00000004U)

#define CTRL_BANDGAP_CLRZ_SHIFT                                                         (3U)
#define CTRL_BANDGAP_CLRZ_MASK                                                          (0x00000008U)

#define CTRL_BANDGAP_SOC_SHIFT                                                          (4U)
#define CTRL_BANDGAP_SOC_MASK                                                           (0x00000010U)

#define CTRL_BANDGAP_TMPSOFF_SHIFT                                                      (5U)
#define CTRL_BANDGAP_TMPSOFF_MASK                                                       (0x00000020U)

#define CTRL_BANDGAP_BGROFF_SHIFT                                                       (6U)
#define CTRL_BANDGAP_BGROFF_MASK                                                        (0x00000040U)

#define CTRL_BANDGAP_CBIASSEL_SHIFT                                                     (7U)
#define CTRL_BANDGAP_CBIASSEL_MASK                                                      (0x00000080U)

#define CTRL_BANDGAP_DTEMP_SHIFT                                                        (8U)
#define CTRL_BANDGAP_DTEMP_MASK                                                         (0x0000ff00U)

#define CTRL_BANDGAP_TRIM_DTRTEMPSC_SHIFT                                               (0U)
#define CTRL_BANDGAP_TRIM_DTRTEMPSC_MASK                                                (0x000000ffU)

#define CTRL_BANDGAP_TRIM_DTRTEMPS_SHIFT                                                (8U)
#define CTRL_BANDGAP_TRIM_DTRTEMPS_MASK                                                 (0x0000ff00U)

#define CTRL_BANDGAP_TRIM_DTRBGAPV_SHIFT                                                (16U)
#define CTRL_BANDGAP_TRIM_DTRBGAPV_MASK                                                 (0x00ff0000U)

#define CTRL_BANDGAP_TRIM_DTRBGAPC_SHIFT                                                (24U)
#define CTRL_BANDGAP_TRIM_DTRBGAPC_MASK                                                 (0xff000000U)

#define CTRL_PLL_CLKINPULOW_MPU_DPLL_SEL_SHIFT                                          (0U)
#define CTRL_PLL_CLKINPULOW_MPU_DPLL_SEL_MASK                                           (0x00000001U)

#define CTRL_PLL_CLKINPULOW_DISP_SEL_SHIFT                                              (1U)
#define CTRL_PLL_CLKINPULOW_DISP_SEL_MASK                                               (0x00000002U)

#define CTRL_PLL_CLKINPULOW_DDR_SEL_SHIFT                                               (2U)
#define CTRL_PLL_CLKINPULOW_DDR_SEL_MASK                                                (0x00000004U)

#define CTRL_MOSC_RESSELECT_SHIFT                                                       (0U)
#define CTRL_MOSC_RESSELECT_MASK                                                        (0x00000001U)

#define CTRL_SMA7_BIT0_SHIFT                                                            (0U)
#define CTRL_SMA7_BIT0_MASK                                                             (0x00000001U)

#define CTRL_DEEPSLEEP_DSCOUNT_SHIFT                                                    (0U)
#define CTRL_DEEPSLEEP_DSCOUNT_MASK                                                     (0x0000ffffU)

#define CTRL_DEEPSLEEP_DSEN_SHIFT                                                       (17U)
#define CTRL_DEEPSLEEP_DSEN_MASK                                                        (0x00020000U)

#define CTRL_DEEPSLEEP_FORCE_DSPADCONF_EN_SHIFT                                         (18U)
#define CTRL_DEEPSLEEP_FORCE_DSPADCONF_EN_MASK                                          (0x00040000U)

#define CTRL_PE_SCRATCHPAD_0_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_0_MASK                                                       (0xffffffffU)

#define CTRL_PE_SCRATCHPAD_1_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_1_MASK                                                       (0xffffffffU)

#define CTRL_PE_SCRATCHPAD_2_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_2_MASK                                                       (0xffffffffU)

#define CTRL_DPLL_PWR_SW_STS_PONOUT_MPU_SHIFT                                           (0U)
#define CTRL_DPLL_PWR_SW_STS_PONOUT_MPU_MASK                                            (0x00000001U)

#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_MPU_SHIFT                                         (1U)
#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_MPU_MASK                                          (0x00000002U)

#define CTRL_DPLL_PWR_SW_STS_PONOUT_PER_SHIFT                                           (8U)
#define CTRL_DPLL_PWR_SW_STS_PONOUT_PER_MASK                                            (0x00000100U)

#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_PER_SHIFT                                         (9U)
#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_PER_MASK                                          (0x00000200U)

#define CTRL_DPLL_PWR_SW_STS_PONOUT_DISP_SHIFT                                          (16U)
#define CTRL_DPLL_PWR_SW_STS_PONOUT_DISP_MASK                                           (0x00010000U)

#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_DISP_SHIFT                                        (17U)
#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_DISP_MASK                                         (0x00020000U)

#define CTRL_DPLL_PWR_SW_STS_PONOUT_DDR_SHIFT                                           (24U)
#define CTRL_DPLL_PWR_SW_STS_PONOUT_DDR_MASK                                            (0x01000000U)

#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_DDR_SHIFT                                         (25U)
#define CTRL_DPLL_PWR_SW_STS_PGOODOUT_DDR_MASK                                          (0x02000000U)

#define CTRL_PE_SCRATCHPAD_3_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_3_MASK                                                       (0xffffffffU)

#define CTRL_PE_SCRATCHPAD_4_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_4_MASK                                                       (0xffffffffU)

#define CTRL_PE_SCRATCHPAD_5_SHIFT                                                      (0U)
#define CTRL_PE_SCRATCHPAD_5_MASK                                                       (0xffffffffU)

#define CTRL_DISPLAY_PLL_SEL_SELECT_SHIFT                                               (0U)
#define CTRL_DISPLAY_PLL_SEL_SELECT_MASK                                                (0x00000001U)

#define CTRL_USIM_VCC_EN5V_SHIFT                                                        (0U)
#define CTRL_USIM_VCC_EN5V_MASK                                                         (0x00000001U)

#define CTRL_USIM_VCC_EN3V_SHIFT                                                        (1U)
#define CTRL_USIM_VCC_EN3V_MASK                                                         (0x00000002U)

#define CTRL_USIM_VCC_EN1P8V_SHIFT                                                      (2U)
#define CTRL_USIM_VCC_EN1P8V_MASK                                                       (0x00000004U)

#define CTRL_USIM_VCCEN_POL_SHIFT                                                       (3U)
#define CTRL_USIM_VCCEN_POL_MASK                                                        (0x00000008U)

#define CTRL_USIM_SVCC_SHIFT                                                            (10U)
#define CTRL_USIM_SVCC_MASK                                                             (0x00000400U)

#define CTRL_USIM_DATALINE_DIR_CTRL0_SHIFT                                              (11U)
#define CTRL_USIM_DATALINE_DIR_CTRL0_MASK                                               (0x00000800U)

#define CTRL_USIM_DATALINE_DIR_CTRL1_SHIFT                                              (12U)
#define CTRL_USIM_DATALINE_DIR_CTRL1_MASK                                               (0x00001000U)

#define CTRL_DEVICE_ID_LSB_SHIFT                                                        (0U)
#define CTRL_DEVICE_ID_LSB_MASK                                                         (0x00000001U)

#define CTRL_DEVICE_ID_MFGR_SHIFT                                                       (1U)
#define CTRL_DEVICE_ID_MFGR_MASK                                                        (0x00000ffeU)

#define CTRL_DEVICE_ID_PARTNUM_SHIFT                                                    (12U)
#define CTRL_DEVICE_ID_PARTNUM_MASK                                                     (0x0ffff000U)

#define CTRL_DEVICE_ID_DEVREV_SHIFT                                                     (28U)
#define CTRL_DEVICE_ID_DEVREV_MASK                                                      (0xf0000000U)

#define CTRL_DEV_FEATURE_ICSS_SHIFT                                                     (0U)
#define CTRL_DEV_FEATURE_ICSS_MASK                                                      (0x00000001U)

#define CTRL_DEV_FEATURE_CPSW_SHIFT                                                     (1U)
#define CTRL_DEV_FEATURE_CPSW_MASK                                                      (0x00000002U)

#define CTRL_DEV_FEATURE_AES_SHIFT                                                      (2U)
#define CTRL_DEV_FEATURE_AES_MASK                                                       (0x00000004U)

#define CTRL_DEV_FEATURE_DES_SHIFT                                                      (3U)
#define CTRL_DEV_FEATURE_DES_MASK                                                       (0x00000008U)

#define CTRL_DEV_FEATURE_PKA_SHIFT                                                      (4U)
#define CTRL_DEV_FEATURE_PKA_MASK                                                       (0x00000010U)

#define CTRL_DEV_FEATURE_RNG_SHIFT                                                      (5U)
#define CTRL_DEV_FEATURE_RNG_MASK                                                       (0x00000020U)

#define CTRL_DEV_FEATURE_SHA_SHIFT                                                      (6U)
#define CTRL_DEV_FEATURE_SHA_MASK                                                       (0x00000040U)

#define CTRL_DEV_FEATURE_DCAN_SHIFT                                                     (7U)
#define CTRL_DEV_FEATURE_DCAN_MASK                                                      (0x00000080U)

#define CTRL_DEV_FEATURE_CTRMEASURES_SHIFT                                              (8U)
#define CTRL_DEV_FEATURE_CTRMEASURES_MASK                                               (0x00000100U)

#define CTRL_DEV_FEATURE_PRINTER_IO_PROTECT_SHIFT                                       (9U)
#define CTRL_DEV_FEATURE_PRINTER_IO_PROTECT_MASK                                        (0x00000200U)

#define CTRL_DEV_FEATURE_TPMSS_SHIFT                                                    (10U)
#define CTRL_DEV_FEATURE_TPMSS_MASK                                                     (0x00000400U)

#define CTRL_DEV_FEATURE_CORE_TPM_SHIFT                                                 (11U)
#define CTRL_DEV_FEATURE_CORE_TPM_MASK                                                  (0x00000800U)

#define CTRL_DEV_FEATURE_CANARY_SHIFT                                                   (12U)
#define CTRL_DEV_FEATURE_CANARY_MASK                                                    (0x00001000U)

#define CTRL_DEV_FEATURE_MAG_CARD_SHIFT                                                 (13U)
#define CTRL_DEV_FEATURE_MAG_CARD_MASK                                                  (0x00002000U)

#define CTRL_DEV_FEATURE_OTFA_SHIFT                                                     (14U)
#define CTRL_DEV_FEATURE_OTFA_MASK                                                      (0x00004000U)

#define CTRL_DEV_FEATURE_ICSS_FEA_SHIFT                                                 (16U)
#define CTRL_DEV_FEATURE_ICSS_FEA_MASK                                                  (0x00ff0000U)

#define CTRL_DEV_FEATURE_CANARY_MASTER_OSC_SHIFT                                        (24U)
#define CTRL_DEV_FEATURE_CANARY_MASTER_OSC_MASK                                         (0x01000000U)

#define CTRL_DEV_FEATURE_DSS_SHIFT                                                      (25U)
#define CTRL_DEV_FEATURE_DSS_MASK                                                       (0x02000000U)

#define CTRL_DEV_FEATURE_HF_ATTACK_DETECTION_SHIFT                                      (26U)
#define CTRL_DEV_FEATURE_HF_ATTACK_DETECTION_MASK                                       (0x04000000U)

#define CTRL_DEV_FEATURE_JTAG_SHIFT                                                     (27U)
#define CTRL_DEV_FEATURE_JTAG_MASK                                                      (0x08000000U)

#define CTRL_DEV_FEATURE_SGX_SHIFT                                                      (29U)
#define CTRL_DEV_FEATURE_SGX_MASK                                                       (0x20000000U)

#define CTRL_INIT_PRIORITY_0_HOST_ARM_SHIFT                                             (0U)
#define CTRL_INIT_PRIORITY_0_HOST_ARM_MASK                                              (0x00000003U)

#define CTRL_INIT_PRIORITY_0_PRUSS0_SHIFT                                               (2U)
#define CTRL_INIT_PRIORITY_0_PRUSS0_MASK                                                (0x0000000cU)

#define CTRL_INIT_PRIORITY_0_PRUSS1_SHIFT                                               (4U)
#define CTRL_INIT_PRIORITY_0_PRUSS1_MASK                                                (0x00000030U)

#define CTRL_INIT_PRIORITY_0_P1500_SHIFT                                                (14U)
#define CTRL_INIT_PRIORITY_0_P1500_MASK                                                 (0x0000c000U)

#define CTRL_INIT_PRIORITY_0_TCRD0_SHIFT                                                (16U)
#define CTRL_INIT_PRIORITY_0_TCRD0_MASK                                                 (0x00030000U)

#define CTRL_INIT_PRIORITY_0_TCWR0_SHIFT                                                (18U)
#define CTRL_INIT_PRIORITY_0_TCWR0_MASK                                                 (0x000c0000U)

#define CTRL_INIT_PRIORITY_0_TCRD1_SHIFT                                                (20U)
#define CTRL_INIT_PRIORITY_0_TCRD1_MASK                                                 (0x00300000U)

#define CTRL_INIT_PRIORITY_0_TCWR1_SHIFT                                                (22U)
#define CTRL_INIT_PRIORITY_0_TCWR1_MASK                                                 (0x00c00000U)

#define CTRL_INIT_PRIORITY_0_TCRD2_SHIFT                                                (24U)
#define CTRL_INIT_PRIORITY_0_TCRD2_MASK                                                 (0x03000000U)

#define CTRL_INIT_PRIORITY_0_TCWR2_SHIFT                                                (26U)
#define CTRL_INIT_PRIORITY_0_TCWR2_MASK                                                 (0x0c000000U)

#define CTRL_INIT_PRIORITY_0_CRYPTO_DMA_RD_SHIFT                                        (28U)
#define CTRL_INIT_PRIORITY_0_CRYPTO_DMA_RD_MASK                                         (0x30000000U)

#define CTRL_INIT_PRIORITY_0_CRYPTO_DMA_WR_SHIFT                                        (30U)
#define CTRL_INIT_PRIORITY_0_CRYPTO_DMA_WR_MASK                                         (0xc0000000U)

#define CTRL_INIT_PRIORITY_1_CPSW_SHIFT                                                 (0U)
#define CTRL_INIT_PRIORITY_1_CPSW_MASK                                                  (0x00000003U)

#define CTRL_INIT_PRIORITY_1_DSS_SHIFT                                                  (2U)
#define CTRL_INIT_PRIORITY_1_DSS_MASK                                                   (0x0000000cU)

#define CTRL_INIT_PRIORITY_1_SPARE4_SHIFT                                               (4U)
#define CTRL_INIT_PRIORITY_1_SPARE4_MASK                                                (0x00000030U)

#define CTRL_INIT_PRIORITY_1_SPARE3_SHIFT                                               (6U)
#define CTRL_INIT_PRIORITY_1_SPARE3_MASK                                                (0x000000c0U)

#define CTRL_INIT_PRIORITY_1_VPFE0_SHIFT                                                (8U)
#define CTRL_INIT_PRIORITY_1_VPFE0_MASK                                                 (0x00000300U)

#define CTRL_INIT_PRIORITY_1_VPFE1_SHIFT                                                (10U)
#define CTRL_INIT_PRIORITY_1_VPFE1_MASK                                                 (0x00000c00U)

#define CTRL_INIT_PRIORITY_1_SPARE2_SHIFT                                               (14U)
#define CTRL_INIT_PRIORITY_1_SPARE2_MASK                                                (0x0000c000U)

#define CTRL_INIT_PRIORITY_1_SPARE1_SHIFT                                               (16U)
#define CTRL_INIT_PRIORITY_1_SPARE1_MASK                                                (0x00030000U)

#define CTRL_INIT_PRIORITY_1_SGX_SHIFT                                                  (20U)
#define CTRL_INIT_PRIORITY_1_SGX_MASK                                                   (0x00300000U)

#define CTRL_INIT_PRIORITY_1_DBG_SHIFT                                                  (24U)
#define CTRL_INIT_PRIORITY_1_DBG_MASK                                                   (0x03000000U)

#define CTRL_DEV_ATTR_REG_SHIFT                                                         (0U)
#define CTRL_DEV_ATTR_REG_MASK                                                          (0xffffffffU)

#define CTRL_TPTC_CFG_TC0DBS_SHIFT                                                      (0U)
#define CTRL_TPTC_CFG_TC0DBS_MASK                                                       (0x00000003U)

#define CTRL_TPTC_CFG_TC1DBS_SHIFT                                                      (2U)
#define CTRL_TPTC_CFG_TC1DBS_MASK                                                       (0x0000000cU)

#define CTRL_TPTC_CFG_TC2DBS_SHIFT                                                      (4U)
#define CTRL_TPTC_CFG_TC2DBS_MASK                                                       (0x00000030U)

#define CTRL_OCMC_CFG_PAR_EN_SHIFT                                                      (0U)
#define CTRL_OCMC_CFG_PAR_EN_MASK                                                       (0x00000001U)

#define CTRL_OCMC_CFG_PAR_RESP_EN_SHIFT                                                 (1U)
#define CTRL_OCMC_CFG_PAR_RESP_EN_MASK                                                  (0x00000002U)

#define CTRL_OCMC_CFG_PAR_INT_CLR_SHIFT                                                 (4U)
#define CTRL_OCMC_CFG_PAR_INT_CLR_MASK                                                  (0x00000010U)

#define CTRL_USB_CTRL0_CM_PWRDN_SHIFT                                                   (0U)
#define CTRL_USB_CTRL0_CM_PWRDN_MASK                                                    (0x00000001U)

#define CTRL_USB_CTRL0_OTG_PWRDN_SHIFT                                                  (1U)
#define CTRL_USB_CTRL0_OTG_PWRDN_MASK                                                   (0x00000002U)

#define CTRL_USB_CTRL0_CHGDET_DIS_SHIFT                                                 (2U)
#define CTRL_USB_CTRL0_CHGDET_DIS_MASK                                                  (0x00000004U)

#define CTRL_USB_CTRL0_CHGDET_RSTRT_SHIFT                                               (3U)
#define CTRL_USB_CTRL0_CHGDET_RSTRT_MASK                                                (0x00000008U)

#define CTRL_USB_CTRL0_SRCONDM_SHIFT                                                    (4U)
#define CTRL_USB_CTRL0_SRCONDM_MASK                                                     (0x00000010U)

#define CTRL_USB_CTRL0_SINKONDP_SHIFT                                                   (5U)
#define CTRL_USB_CTRL0_SINKONDP_MASK                                                    (0x00000020U)

#define CTRL_USB_CTRL0_CHGISINK_EN_SHIFT                                                (6U)
#define CTRL_USB_CTRL0_CHGISINK_EN_MASK                                                 (0x00000040U)

#define CTRL_USB_CTRL0_CHGVSRC_EN_SHIFT                                                 (7U)
#define CTRL_USB_CTRL0_CHGVSRC_EN_MASK                                                  (0x00000080U)

#define CTRL_USB_CTRL0_DMPULLDN_SHIFT                                                   (8U)
#define CTRL_USB_CTRL0_DMPULLDN_MASK                                                    (0x00000100U)

#define CTRL_USB_CTRL0_DPPULLUP_SHIFT                                                   (9U)
#define CTRL_USB_CTRL0_DPPULLUP_MASK                                                    (0x00000200U)

#define CTRL_USB_CTRL0_CDET_EXTCTL_SHIFT                                                (10U)
#define CTRL_USB_CTRL0_CDET_EXTCTL_MASK                                                 (0x00000400U)

#define CTRL_USB_CTRL0_GPIOMODE_SHIFT                                                   (12U)
#define CTRL_USB_CTRL0_GPIOMODE_MASK                                                    (0x00001000U)

#define CTRL_USB_CTRL0_GPIO_SIG_INV_SHIFT                                               (13U)
#define CTRL_USB_CTRL0_GPIO_SIG_INV_MASK                                                (0x00002000U)

#define CTRL_USB_CTRL0_GPIO_SIG_CROSS_SHIFT                                             (14U)
#define CTRL_USB_CTRL0_GPIO_SIG_CROSS_MASK                                              (0x00004000U)

#define CTRL_USB_CTRL0_DPGPIO_PD_SHIFT                                                  (17U)
#define CTRL_USB_CTRL0_DPGPIO_PD_MASK                                                   (0x00020000U)

#define CTRL_USB_CTRL0_DMGPIO_PD_SHIFT                                                  (18U)
#define CTRL_USB_CTRL0_DMGPIO_PD_MASK                                                   (0x00040000U)

#define CTRL_USB_CTRL0_OTGVDET_EN_SHIFT                                                 (19U)
#define CTRL_USB_CTRL0_OTGVDET_EN_MASK                                                  (0x00080000U)

#define CTRL_USB_CTRL0_OTGSESSENDEN_SHIFT                                               (20U)
#define CTRL_USB_CTRL0_OTGSESSENDEN_MASK                                                (0x00100000U)

#define CTRL_USB_CTRL0_WUEN_SHIFT                                                       (21U)
#define CTRL_USB_CTRL0_WUEN_MASK                                                        (0x00200000U)

#define CTRL_USB_CTRL0_PHY_SMA2_SHIFT                                                   (22U)
#define CTRL_USB_CTRL0_PHY_SMA2_MASK                                                    (0x00400000U)

#define CTRL_USB_CTRL0_DATAPOLARITY_INV_SHIFT                                           (23U)
#define CTRL_USB_CTRL0_DATAPOLARITY_INV_MASK                                            (0x00800000U)

#define CTRL_USB_CTRL0_SPAREIN_SHIFT                                                    (24U)
#define CTRL_USB_CTRL0_SPAREIN_MASK                                                     (0xff000000U)

#define CTRL_USB_STS0_CHGDETDONE_SHIFT                                                  (0U)
#define CTRL_USB_STS0_CHGDETDONE_MASK                                                   (0x00000001U)

#define CTRL_USB_STS0_CHGDETECT_SHIFT                                                   (1U)
#define CTRL_USB_STS0_CHGDETECT_MASK                                                    (0x00000002U)

#define CTRL_USB_STS0_CDET_DATADET_SHIFT                                                (2U)
#define CTRL_USB_STS0_CDET_DATADET_MASK                                                 (0x00000004U)

#define CTRL_USB_STS0_CDET_DPDET_SHIFT                                                  (3U)
#define CTRL_USB_STS0_CDET_DPDET_MASK                                                   (0x00000008U)

#define CTRL_USB_STS0_CDET_DMDET_SHIFT                                                  (4U)
#define CTRL_USB_STS0_CDET_DMDET_MASK                                                   (0x00000010U)

#define CTRL_USB_STS0_CHGDETSTS_SHIFT                                                   (5U)
#define CTRL_USB_STS0_CHGDETSTS_MASK                                                    (0x000000e0U)

#define CTRL_USB_STS0_WUEVT_SHIFT                                                       (8U)
#define CTRL_USB_STS0_WUEVT_MASK                                                        (0x00000100U)

#define CTRL_USB_CTRL1_CM_PWRDN_SHIFT                                                   (0U)
#define CTRL_USB_CTRL1_CM_PWRDN_MASK                                                    (0x00000001U)

#define CTRL_USB_CTRL1_OTG_PWRDN_SHIFT                                                  (1U)
#define CTRL_USB_CTRL1_OTG_PWRDN_MASK                                                   (0x00000002U)

#define CTRL_USB_CTRL1_CHGDET_DIS_SHIFT                                                 (2U)
#define CTRL_USB_CTRL1_CHGDET_DIS_MASK                                                  (0x00000004U)

#define CTRL_USB_CTRL1_CHGDET_RSTRT_SHIFT                                               (3U)
#define CTRL_USB_CTRL1_CHGDET_RSTRT_MASK                                                (0x00000008U)

#define CTRL_USB_CTRL1_SRCONDM_SHIFT                                                    (4U)
#define CTRL_USB_CTRL1_SRCONDM_MASK                                                     (0x00000010U)

#define CTRL_USB_CTRL1_SINKONDP_SHIFT                                                   (5U)
#define CTRL_USB_CTRL1_SINKONDP_MASK                                                    (0x00000020U)

#define CTRL_USB_CTRL1_CHGISINK_EN_SHIFT                                                (6U)
#define CTRL_USB_CTRL1_CHGISINK_EN_MASK                                                 (0x00000040U)

#define CTRL_USB_CTRL1_CHGVSRC_EN_SHIFT                                                 (7U)
#define CTRL_USB_CTRL1_CHGVSRC_EN_MASK                                                  (0x00000080U)

#define CTRL_USB_CTRL1_DMPULLDN_SHIFT                                                   (8U)
#define CTRL_USB_CTRL1_DMPULLDN_MASK                                                    (0x00000100U)

#define CTRL_USB_CTRL1_DPPULLUP_SHIFT                                                   (9U)
#define CTRL_USB_CTRL1_DPPULLUP_MASK                                                    (0x00000200U)

#define CTRL_USB_CTRL1_CDET_EXTCTL_SHIFT                                                (10U)
#define CTRL_USB_CTRL1_CDET_EXTCTL_MASK                                                 (0x00000400U)

#define CTRL_USB_CTRL1_GPIOMODE_SHIFT                                                   (12U)
#define CTRL_USB_CTRL1_GPIOMODE_MASK                                                    (0x00001000U)

#define CTRL_USB_CTRL1_GPIO_SIG_INV_SHIFT                                               (13U)
#define CTRL_USB_CTRL1_GPIO_SIG_INV_MASK                                                (0x00002000U)

#define CTRL_USB_CTRL1_GPIO_SIG_CROSS_SHIFT                                             (14U)
#define CTRL_USB_CTRL1_GPIO_SIG_CROSS_MASK                                              (0x00004000U)

#define CTRL_USB_CTRL1_DPGPIO_PD_SHIFT                                                  (17U)
#define CTRL_USB_CTRL1_DPGPIO_PD_MASK                                                   (0x00020000U)

#define CTRL_USB_CTRL1_DMGPIO_PD_SHIFT                                                  (18U)
#define CTRL_USB_CTRL1_DMGPIO_PD_MASK                                                   (0x00040000U)

#define CTRL_USB_CTRL1_OTGVDET_EN_SHIFT                                                 (19U)
#define CTRL_USB_CTRL1_OTGVDET_EN_MASK                                                  (0x00080000U)

#define CTRL_USB_CTRL1_OTGSESSENDEN_SHIFT                                               (20U)
#define CTRL_USB_CTRL1_OTGSESSENDEN_MASK                                                (0x00100000U)

#define CTRL_USB_CTRL1_WUEN_SHIFT                                                       (21U)
#define CTRL_USB_CTRL1_WUEN_MASK                                                        (0x00200000U)

#define CTRL_USB_CTRL1_PHY_SMA2_SHIFT                                                   (22U)
#define CTRL_USB_CTRL1_PHY_SMA2_MASK                                                    (0x00400000U)

#define CTRL_USB_CTRL1_DATAPOLARITY_INV_SHIFT                                           (23U)
#define CTRL_USB_CTRL1_DATAPOLARITY_INV_MASK                                            (0x00800000U)

#define CTRL_USB_CTRL1_SPAREIN_SHIFT                                                    (24U)
#define CTRL_USB_CTRL1_SPAREIN_MASK                                                     (0xff000000U)

#define CTRL_USB_STS1_CHGDETDONE_SHIFT                                                  (0U)
#define CTRL_USB_STS1_CHGDETDONE_MASK                                                   (0x00000001U)

#define CTRL_USB_STS1_CHGDETECT_SHIFT                                                   (1U)
#define CTRL_USB_STS1_CHGDETECT_MASK                                                    (0x00000002U)

#define CTRL_USB_STS1_CDET_DATADET_SHIFT                                                (2U)
#define CTRL_USB_STS1_CDET_DATADET_MASK                                                 (0x00000004U)

#define CTRL_USB_STS1_CDET_DPDET_SHIFT                                                  (3U)
#define CTRL_USB_STS1_CDET_DPDET_MASK                                                   (0x00000008U)

#define CTRL_USB_STS1_CDET_DMDET_SHIFT                                                  (4U)
#define CTRL_USB_STS1_CDET_DMDET_MASK                                                   (0x00000010U)

#define CTRL_USB_STS1_CHGDETSTS_SHIFT                                                   (5U)
#define CTRL_USB_STS1_CHGDETSTS_MASK                                                    (0x000000e0U)

#define CTRL_USB_STS1_WUEVT_SHIFT                                                       (8U)
#define CTRL_USB_STS1_WUEVT_MASK                                                        (0x00000100U)

#define CTRL_MAC_ID0_LO_MACADDR_15_8_SHIFT                                              (0U)
#define CTRL_MAC_ID0_LO_MACADDR_15_8_MASK                                               (0x000000ffU)

#define CTRL_MAC_ID0_LO_MACADDR_7_0_SHIFT                                               (8U)
#define CTRL_MAC_ID0_LO_MACADDR_7_0_MASK                                                (0x0000ff00U)

#define CTRL_MAC_ID0_HI_MACADDR_47_40_SHIFT                                             (0U)
#define CTRL_MAC_ID0_HI_MACADDR_47_40_MASK                                              (0x000000ffU)

#define CTRL_MAC_ID0_HI_MACADDR_39_32_SHIFT                                             (8U)
#define CTRL_MAC_ID0_HI_MACADDR_39_32_MASK                                              (0x0000ff00U)

#define CTRL_MAC_ID0_HI_MACADDR_31_24_SHIFT                                             (16U)
#define CTRL_MAC_ID0_HI_MACADDR_31_24_MASK                                              (0x00ff0000U)

#define CTRL_MAC_ID0_HI_MACADDR_23_16_SHIFT                                             (24U)
#define CTRL_MAC_ID0_HI_MACADDR_23_16_MASK                                              (0xff000000U)

#define CTRL_MAC_ID1_LO_MACADDR_15_8_SHIFT                                              (0U)
#define CTRL_MAC_ID1_LO_MACADDR_15_8_MASK                                               (0x000000ffU)

#define CTRL_MAC_ID1_LO_MACADDR_7_0_SHIFT                                               (8U)
#define CTRL_MAC_ID1_LO_MACADDR_7_0_MASK                                                (0x0000ff00U)

#define CTRL_MAC_ID1_HI_MACADDR_47_40_SHIFT                                             (0U)
#define CTRL_MAC_ID1_HI_MACADDR_47_40_MASK                                              (0x000000ffU)

#define CTRL_MAC_ID1_HI_MACADDR_39_32_SHIFT                                             (8U)
#define CTRL_MAC_ID1_HI_MACADDR_39_32_MASK                                              (0x0000ff00U)

#define CTRL_MAC_ID1_HI_MACADDR_31_24_SHIFT                                             (16U)
#define CTRL_MAC_ID1_HI_MACADDR_31_24_MASK                                              (0x00ff0000U)

#define CTRL_MAC_ID1_HI_MACADDR_23_16_SHIFT                                             (24U)
#define CTRL_MAC_ID1_HI_MACADDR_23_16_MASK                                              (0xff000000U)

#define CTRL_DCAN_RAMINIT_DCAN0_START_SHIFT                                             (0U)
#define CTRL_DCAN_RAMINIT_DCAN0_START_MASK                                              (0x00000001U)

#define CTRL_DCAN_RAMINIT_DCAN1_START_SHIFT                                             (1U)
#define CTRL_DCAN_RAMINIT_DCAN1_START_MASK                                              (0x00000002U)

#define CTRL_DCAN_RAMINIT_DCAN0_DONE_SHIFT                                              (8U)
#define CTRL_DCAN_RAMINIT_DCAN0_DONE_MASK                                               (0x00000100U)

#define CTRL_DCAN_RAMINIT_DCAN1_DONE_SHIFT                                              (9U)
#define CTRL_DCAN_RAMINIT_DCAN1_DONE_MASK                                               (0x00000200U)

#define CTRL_SMA5_SHIFT                                                                 (0U)
#define CTRL_SMA5_MASK                                                                  (0xffffffffU)

#define CTRL_USB_CTRL2_PHY0_FILTER_BYPASS_SHIFT                                         (0U)
#define CTRL_USB_CTRL2_PHY0_FILTER_BYPASS_MASK                                          (0x00000001U)

#define CTRL_USB_CTRL2_PHY0_FILTER_THR_IDDIG_SHIFT                                      (1U)
#define CTRL_USB_CTRL2_PHY0_FILTER_THR_IDDIG_MASK                                       (0x00000006U)

#define CTRL_USB_CTRL2_PHY0_FILTER_THR_SESSEND_SHIFT                                    (3U)
#define CTRL_USB_CTRL2_PHY0_FILTER_THR_SESSEND_MASK                                     (0x00000018U)

#define CTRL_USB_CTRL2_PHY0_FILTER_THR_BVALID_SHIFT                                     (5U)
#define CTRL_USB_CTRL2_PHY0_FILTER_THR_BVALID_MASK                                      (0x00000060U)

#define CTRL_USB_CTRL2_PHY0_FILTER_THR_AVALID_SHIFT                                     (7U)
#define CTRL_USB_CTRL2_PHY0_FILTER_THR_AVALID_MASK                                      (0x00000180U)

#define CTRL_USB_CTRL2_PHY0_FILTER_THR_VBUSVALID_SHIFT                                  (9U)
#define CTRL_USB_CTRL2_PHY0_FILTER_THR_VBUSVALID_MASK                                   (0x00000600U)

#define CTRL_USB_CTRL2_PHY1_FILTER_BYPASS_SHIFT                                         (16U)
#define CTRL_USB_CTRL2_PHY1_FILTER_BYPASS_MASK                                          (0x00010000U)

#define CTRL_USB_CTRL2_PHY1_FILTER_THR_IDDIG_SHIFT                                      (17U)
#define CTRL_USB_CTRL2_PHY1_FILTER_THR_IDDIG_MASK                                       (0x00060000U)

#define CTRL_USB_CTRL2_PHY1_FILTER_THR_SESSEND_SHIFT                                    (19U)
#define CTRL_USB_CTRL2_PHY1_FILTER_THR_SESSEND_MASK                                     (0x00180000U)

#define CTRL_USB_CTRL2_PHY1_FILTER_THR_BVALID_SHIFT                                     (21U)
#define CTRL_USB_CTRL2_PHY1_FILTER_THR_BVALID_MASK                                      (0x00600000U)

#define CTRL_USB_CTRL2_PHY1_FILTER_THR_AVALID_SHIFT                                     (23U)
#define CTRL_USB_CTRL2_PHY1_FILTER_THR_AVALID_MASK                                      (0x01800000U)

#define CTRL_USB_CTRL2_PHY1_FILTER_THR_VBUSVALID_SHIFT                                  (25U)
#define CTRL_USB_CTRL2_PHY1_FILTER_THR_VBUSVALID_MASK                                   (0x06000000U)

#define CTRL_GMII_SEL_GMII1_SHIFT                                                       (0U)
#define CTRL_GMII_SEL_GMII1_MASK                                                        (0x00000003U)

#define CTRL_GMII_SEL_GMII2_SHIFT                                                       (2U)
#define CTRL_GMII_SEL_GMII2_MASK                                                        (0x0000000cU)

#define CTRL_GMII_SEL_RGMII1_IDMODE_SHIFT                                               (4U)
#define CTRL_GMII_SEL_RGMII1_IDMODE_MASK                                                (0x00000010U)

#define CTRL_GMII_SEL_RGMII2_IDMODE_SHIFT                                               (5U)
#define CTRL_GMII_SEL_RGMII2_IDMODE_MASK                                                (0x00000020U)

#define CTRL_GMII_SEL_RMII1_IO_CLK_EN_SHIFT                                             (6U)
#define CTRL_GMII_SEL_RMII1_IO_CLK_EN_MASK                                              (0x00000040U)

#define CTRL_GMII_SEL_RMII2_IO_CLK_EN_SHIFT                                             (7U)
#define CTRL_GMII_SEL_RMII2_IO_CLK_EN_MASK                                              (0x00000080U)

#define CTRL_MPUSS_PIUSEL2SRAM_SHIFT                                                    (0U)
#define CTRL_MPUSS_PIUSEL2SRAM_MASK                                                     (0x00000001U)

#define CTRL_MPUSS_PIL2SRAMCLKDIV_SHIFT                                                 (1U)
#define CTRL_MPUSS_PIL2SRAMCLKDIV_MASK                                                  (0x00000006U)

#define CTRL_MPUSS_HSDCC_SHIFT                                                          (3U)
#define CTRL_MPUSS_HSDCC_MASK                                                           (0x000007f8U)

#define CTRL_TIMER_CASCADE_TIMER23CASCADE_EN_SHIFT                                      (0U)
#define CTRL_TIMER_CASCADE_TIMER23CASCADE_EN_MASK                                       (0x00000001U)

#define CTRL_TIMER_CASCADE_TIMER45CASCADE_EN_SHIFT                                      (1U)
#define CTRL_TIMER_CASCADE_TIMER45CASCADE_EN_MASK                                       (0x00000002U)

#define CTRL_PWMSS_PWMSS0_TBCLKEN_SHIFT                                                 (0U)
#define CTRL_PWMSS_PWMSS0_TBCLKEN_MASK                                                  (0x00000001U)

#define CTRL_PWMSS_PWMMS1_TBCLKEN_SHIFT                                                 (1U)
#define CTRL_PWMSS_PWMMS1_TBCLKEN_MASK                                                  (0x00000002U)

#define CTRL_PWMSS_PWMSS2_TBCLKEN_SHIFT                                                 (2U)
#define CTRL_PWMSS_PWMSS2_TBCLKEN_MASK                                                  (0x00000004U)

#define CTRL_PWMSS_PWM_SYNCSEL_SHIFT                                                    (3U)
#define CTRL_PWMSS_PWM_SYNCSEL_MASK                                                     (0x00000008U)

#define CTRL_PWMSS_PWMSS3_TBCLKEN_SHIFT                                                 (4U)
#define CTRL_PWMSS_PWMSS3_TBCLKEN_MASK                                                  (0x00000010U)

#define CTRL_PWMSS_PWMMS4_TBCLKEN_SHIFT                                                 (5U)
#define CTRL_PWMSS_PWMMS4_TBCLKEN_MASK                                                  (0x00000020U)

#define CTRL_PWMSS_PWMSS5_TBCLKEN_SHIFT                                                 (6U)
#define CTRL_PWMSS_PWMSS5_TBCLKEN_MASK                                                  (0x00000040U)

#define CTRL_MREQPRIO_0_SAB_INIT0_SHIFT                                                 (0U)
#define CTRL_MREQPRIO_0_SAB_INIT0_MASK                                                  (0x00000007U)

#define CTRL_MREQPRIO_0_SAB_INIT1_SHIFT                                                 (4U)
#define CTRL_MREQPRIO_0_SAB_INIT1_MASK                                                  (0x00000070U)

#define CTRL_MREQPRIO_0_PRUSS1_PRU0_SHIFT                                               (8U)
#define CTRL_MREQPRIO_0_PRUSS1_PRU0_MASK                                                (0x00000700U)

#define CTRL_MREQPRIO_0_PRUSS1_PRU1_SHIFT                                               (12U)
#define CTRL_MREQPRIO_0_PRUSS1_PRU1_MASK                                                (0x00007000U)

#define CTRL_MREQPRIO_0_CPSW_SHIFT                                                      (16U)
#define CTRL_MREQPRIO_0_CPSW_MASK                                                       (0x00070000U)

#define CTRL_MREQPRIO_0_USB0_SHIFT                                                      (20U)
#define CTRL_MREQPRIO_0_USB0_MASK                                                       (0x00700000U)

#define CTRL_MREQPRIO_0_USB1_SHIFT                                                      (24U)
#define CTRL_MREQPRIO_0_USB1_MASK                                                       (0x07000000U)

#define CTRL_MREQPRIO_0_SGX_SHIFT                                                       (28U)
#define CTRL_MREQPRIO_0_SGX_MASK                                                        (0x70000000U)

#define CTRL_MREQPRIO_1_DSS_SHIFT                                                       (4U)
#define CTRL_MREQPRIO_1_DSS_MASK                                                        (0x00000070U)

#define CTRL_MREQPRIO_1_VPFE0_SHIFT                                                     (8U)
#define CTRL_MREQPRIO_1_VPFE0_MASK                                                      (0x00000700U)

#define CTRL_MREQPRIO_1_VPFE1_SHIFT                                                     (12U)
#define CTRL_MREQPRIO_1_VPFE1_MASK                                                      (0x00007000U)

#define CTRL_MREQPRIO_1_CRYPTO_RD_SHIFT                                                 (16U)
#define CTRL_MREQPRIO_1_CRYPTO_RD_MASK                                                  (0x00070000U)

#define CTRL_MREQPRIO_1_CRYPTO_WR_SHIFT                                                 (20U)
#define CTRL_MREQPRIO_1_CRYPTO_WR_MASK                                                  (0x00700000U)

#define CTRL_HW_EVT_SEL_GRP1_EVT1_SHIFT                                                 (0U)
#define CTRL_HW_EVT_SEL_GRP1_EVT1_MASK                                                  (0x000000ffU)

#define CTRL_HW_EVT_SEL_GRP1_EVT2_SHIFT                                                 (8U)
#define CTRL_HW_EVT_SEL_GRP1_EVT2_MASK                                                  (0x0000ff00U)

#define CTRL_HW_EVT_SEL_GRP1_EVT3_SHIFT                                                 (16U)
#define CTRL_HW_EVT_SEL_GRP1_EVT3_MASK                                                  (0x00ff0000U)

#define CTRL_HW_EVT_SEL_GRP1_EVT4_SHIFT                                                 (24U)
#define CTRL_HW_EVT_SEL_GRP1_EVT4_MASK                                                  (0xff000000U)

#define CTRL_HW_EVT_SEL_GRP2_EVT5_SHIFT                                                 (0U)
#define CTRL_HW_EVT_SEL_GRP2_EVT5_MASK                                                  (0x000000ffU)

#define CTRL_HW_EVT_SEL_GRP2_EVT6_SHIFT                                                 (8U)
#define CTRL_HW_EVT_SEL_GRP2_EVT6_MASK                                                  (0x0000ff00U)

#define CTRL_HW_EVT_SEL_GRP2_EVT7_SHIFT                                                 (16U)
#define CTRL_HW_EVT_SEL_GRP2_EVT7_MASK                                                  (0x00ff0000U)

#define CTRL_HW_EVT_SEL_GRP2_EVT8_SHIFT                                                 (24U)
#define CTRL_HW_EVT_SEL_GRP2_EVT8_MASK                                                  (0xff000000U)

#define CTRL_HW_EVT_SEL_GRP3_EVT9_SHIFT                                                 (0U)
#define CTRL_HW_EVT_SEL_GRP3_EVT9_MASK                                                  (0x000000ffU)

#define CTRL_HW_EVT_SEL_GRP3_EVT10_SHIFT                                                (8U)
#define CTRL_HW_EVT_SEL_GRP3_EVT10_MASK                                                 (0x0000ff00U)

#define CTRL_HW_EVT_SEL_GRP3_EVT11_SHIFT                                                (16U)
#define CTRL_HW_EVT_SEL_GRP3_EVT11_MASK                                                 (0x00ff0000U)

#define CTRL_HW_EVT_SEL_GRP3_EVT12_SHIFT                                                (24U)
#define CTRL_HW_EVT_SEL_GRP3_EVT12_MASK                                                 (0xff000000U)

#define CTRL_HW_EVT_SEL_GRP4_EVT13_SHIFT                                                (0U)
#define CTRL_HW_EVT_SEL_GRP4_EVT13_MASK                                                 (0x000000ffU)

#define CTRL_HW_EVT_SEL_GRP4_EVT14_SHIFT                                                (8U)
#define CTRL_HW_EVT_SEL_GRP4_EVT14_MASK                                                 (0x0000ff00U)

#define CTRL_HW_EVT_SEL_GRP4_EVT15_SHIFT                                                (16U)
#define CTRL_HW_EVT_SEL_GRP4_EVT15_MASK                                                 (0x00ff0000U)

#define CTRL_HW_EVT_SEL_GRP4_EVT16_SHIFT                                                (24U)
#define CTRL_HW_EVT_SEL_GRP4_EVT16_MASK                                                 (0xff000000U)

#define CTRL_SMRT_SR0_SLEEP_SHIFT                                                       (0U)
#define CTRL_SMRT_SR0_SLEEP_MASK                                                        (0x00000001U)

#define CTRL_SMRT_SR1_SLEEP_SHIFT                                                       (1U)
#define CTRL_SMRT_SR1_SLEEP_MASK                                                        (0x00000002U)

#define CTRL_MPUSS_HW_DBG_SEL_SHIFT                                                     (0U)
#define CTRL_MPUSS_HW_DBG_SEL_MASK                                                      (0x0000000fU)

#define CTRL_MPUSS_HW_DBG_SEL_GATE_EN_SHIFT                                             (9U)
#define CTRL_MPUSS_HW_DBG_SEL_GATE_EN_MASK                                              (0x00000200U)

#define CTRL_MPUSS_HW_DBG_INFO_SHIFT                                                    (0U)
#define CTRL_MPUSS_HW_DBG_INFO_MASK                                                     (0xffffffffU)

#define CTRL_MRGN_MODE0_MMODE0_SHIFT                                                    (0U)
#define CTRL_MRGN_MODE0_MMODE0_MASK                                                     (0x00000003U)

#define CTRL_MRGN_MODE0_MMODE1_SHIFT                                                    (2U)
#define CTRL_MRGN_MODE0_MMODE1_MASK                                                     (0x0000000cU)

#define CTRL_MRGN_MODE0_MMODE2_SHIFT                                                    (4U)
#define CTRL_MRGN_MODE0_MMODE2_MASK                                                     (0x00000030U)

#define CTRL_MRGN_MODE0_MMODE3_SHIFT                                                    (6U)
#define CTRL_MRGN_MODE0_MMODE3_MASK                                                     (0x000000c0U)

#define CTRL_MRGN_MODE0_MMODE4_SHIFT                                                    (8U)
#define CTRL_MRGN_MODE0_MMODE4_MASK                                                     (0x00000300U)

#define CTRL_MRGN_MODE0_MMODE5_SHIFT                                                    (10U)
#define CTRL_MRGN_MODE0_MMODE5_MASK                                                     (0x00000c00U)

#define CTRL_MRGN_MODE0_MMODE6_SHIFT                                                    (12U)
#define CTRL_MRGN_MODE0_MMODE6_MASK                                                     (0x00003000U)

#define CTRL_MRGN_MODE0_MMODE7_SHIFT                                                    (14U)
#define CTRL_MRGN_MODE0_MMODE7_MASK                                                     (0x0000c000U)

#define CTRL_MRGN_MODE0_MMODE8_SHIFT                                                    (16U)
#define CTRL_MRGN_MODE0_MMODE8_MASK                                                     (0x00030000U)

#define CTRL_MRGN_MODE0_MMODE9_SHIFT                                                    (18U)
#define CTRL_MRGN_MODE0_MMODE9_MASK                                                     (0x000c0000U)

#define CTRL_MRGN_MODE0_MMODE10_SHIFT                                                   (20U)
#define CTRL_MRGN_MODE0_MMODE10_MASK                                                    (0x00300000U)

#define CTRL_MRGN_MODE0_MMODE11_SHIFT                                                   (22U)
#define CTRL_MRGN_MODE0_MMODE11_MASK                                                    (0x00c00000U)

#define CTRL_MRGN_MODE0_MMODE12_SHIFT                                                   (24U)
#define CTRL_MRGN_MODE0_MMODE12_MASK                                                    (0x03000000U)

#define CTRL_MRGN_MODE0_MMODE13_SHIFT                                                   (26U)
#define CTRL_MRGN_MODE0_MMODE13_MASK                                                    (0x0c000000U)

#define CTRL_MRGN_MODE0_MMODE14_SHIFT                                                   (28U)
#define CTRL_MRGN_MODE0_MMODE14_MASK                                                    (0x30000000U)

#define CTRL_MRGN_MODE0_MMODE15_SHIFT                                                   (30U)
#define CTRL_MRGN_MODE0_MMODE15_MASK                                                    (0xc0000000U)

#define CTRL_MRGN_MODE1_MMODE16_SHIFT                                                   (0U)
#define CTRL_MRGN_MODE1_MMODE16_MASK                                                    (0x00000003U)

#define CTRL_MRGN_MODE1_MMODE17_SHIFT                                                   (2U)
#define CTRL_MRGN_MODE1_MMODE17_MASK                                                    (0x0000000cU)

#define CTRL_MRGN_MODE1_MMODE18_SHIFT                                                   (4U)
#define CTRL_MRGN_MODE1_MMODE18_MASK                                                    (0x00000030U)

#define CTRL_MRGN_MODE1_MMODE19_SHIFT                                                   (6U)
#define CTRL_MRGN_MODE1_MMODE19_MASK                                                    (0x000000c0U)

#define CTRL_VDD_MPU_OPP_050_NTARGET_SHIFT                                              (0U)
#define CTRL_VDD_MPU_OPP_050_NTARGET_MASK                                               (0x00ffffffU)

#define CTRL_VDD_MPU_OPP_100_NTARGET_SHIFT                                              (0U)
#define CTRL_VDD_MPU_OPP_100_NTARGET_MASK                                               (0x00ffffffU)

#define CTRL_VDD_MPU_OPP_119_NTARGET_SHIFT                                              (0U)
#define CTRL_VDD_MPU_OPP_119_NTARGET_MASK                                               (0x00ffffffU)

#define CTRL_VDD_MPU_OPP_TURBO_NTARGET_SHIFT                                            (0U)
#define CTRL_VDD_MPU_OPP_TURBO_NTARGET_MASK                                             (0x00ffffffU)

#define CTRL_VDD_MPU_OPP_NITRO_NTARGET_SHIFT                                            (0U)
#define CTRL_VDD_MPU_OPP_NITRO_NTARGET_MASK                                             (0x00ffffffU)

#define CTRL_VDD_CORE_OPP_050_NTARGET_SHIFT                                             (0U)
#define CTRL_VDD_CORE_OPP_050_NTARGET_MASK                                              (0x00ffffffU)

#define CTRL_VDD_CORE_OPP_100_NTARGET_SHIFT                                             (0U)
#define CTRL_VDD_CORE_OPP_100_NTARGET_MASK                                              (0x00ffffffU)

#define CTRL_BB_SCALE_BBIAS_SHIFT                                                       (0U)
#define CTRL_BB_SCALE_BBIAS_MASK                                                        (0x00000003U)

#define CTRL_BB_SCALE_SHIFT                                                             (8U)
#define CTRL_BB_SCALE_MASK                                                              (0x00000f00U)

#define CTRL_USB_VIDPID_PID_SHIFT                                                       (0U)
#define CTRL_USB_VIDPID_PID_MASK                                                        (0x0000ffffU)

#define CTRL_USB_VIDPID_VID_SHIFT                                                       (16U)
#define CTRL_USB_VIDPID_VID_MASK                                                        (0xffff0000U)

#define CTRL_EFUSE_SMA_SHIFT                                                            (0U)
#define CTRL_EFUSE_SMA_MASK                                                             (0xffffffffU)

#define CTRL_RESET_ISO_CPSW_SHIFT                                                       (0U)
#define CTRL_RESET_ISO_CPSW_MASK                                                        (0x00000001U)

#define CTRL_RESET_ISO_JTAG_SHIFT                                                       (1U)
#define CTRL_RESET_ISO_JTAG_MASK                                                        (0x00000002U)

#define CTRL_DPLL_PWR_SW_PONIN_MPU_SHIFT                                                (0U)
#define CTRL_DPLL_PWR_SW_PONIN_MPU_MASK                                                 (0x00000001U)

#define CTRL_DPLL_PWR_SW_PGOODIN_MPU_SHIFT                                              (1U)
#define CTRL_DPLL_PWR_SW_PGOODIN_MPU_MASK                                               (0x00000002U)

#define CTRL_DPLL_PWR_SW_ISO_MPU_SHIFT                                                  (2U)
#define CTRL_DPLL_PWR_SW_ISO_MPU_MASK                                                   (0x00000004U)

#define CTRL_DPLL_PWR_SW_RESET_MPU_SHIFT                                                (3U)
#define CTRL_DPLL_PWR_SW_RESET_MPU_MASK                                                 (0x00000008U)

#define CTRL_DPLL_PWR_SW_RET_MPU_SHIFT                                                  (4U)
#define CTRL_DPLL_PWR_SW_RET_MPU_MASK                                                   (0x00000010U)

#define CTRL_DPLL_PWR_SW_ISOSCAN_MPU_SHIFT                                              (5U)
#define CTRL_DPLL_PWR_SW_ISOSCAN_MPU_MASK                                               (0x00000020U)

#define CTRL_DPLL_PWR_SW_MPU_PLL_SHIFT                                                  (7U)
#define CTRL_DPLL_PWR_SW_MPU_PLL_MASK                                                   (0x00000080U)

#define CTRL_DPLL_PWR_SW_PONIN_PER_SHIFT                                                (8U)
#define CTRL_DPLL_PWR_SW_PONIN_PER_MASK                                                 (0x00000100U)

#define CTRL_DPLL_PWR_SW_PGOODIN_PER_SHIFT                                              (9U)
#define CTRL_DPLL_PWR_SW_PGOODIN_PER_MASK                                               (0x00000200U)

#define CTRL_DPLL_PWR_SW_ISO_PER_SHIFT                                                  (10U)
#define CTRL_DPLL_PWR_SW_ISO_PER_MASK                                                   (0x00000400U)

#define CTRL_DPLL_PWR_SW_RESET_PER_SHIFT                                                (11U)
#define CTRL_DPLL_PWR_SW_RESET_PER_MASK                                                 (0x00000800U)

#define CTRL_DPLL_PWR_SW_RET_PER_SHIFT                                                  (12U)
#define CTRL_DPLL_PWR_SW_RET_PER_MASK                                                   (0x00001000U)

#define CTRL_DPLL_PWR_SW_ISOSCAN_PER_SHIFT                                              (13U)
#define CTRL_DPLL_PWR_SW_ISOSCAN_PER_MASK                                               (0x00002000U)

#define CTRL_DPLL_PWR_SW_PER_PLL_SHIFT                                                  (15U)
#define CTRL_DPLL_PWR_SW_PER_PLL_MASK                                                   (0x00008000U)

#define CTRL_DPLL_PWR_SW_PONIN_DISP_SHIFT                                               (16U)
#define CTRL_DPLL_PWR_SW_PONIN_DISP_MASK                                                (0x00010000U)

#define CTRL_DPLL_PWR_SW_PGOODIN_DISP_SHIFT                                             (17U)
#define CTRL_DPLL_PWR_SW_PGOODIN_DISP_MASK                                              (0x00020000U)

#define CTRL_DPLL_PWR_SW_ISO_DISP_SHIFT                                                 (18U)
#define CTRL_DPLL_PWR_SW_ISO_DISP_MASK                                                  (0x00040000U)

#define CTRL_DPLL_PWR_SW_RESET_DISP_SHIFT                                               (19U)
#define CTRL_DPLL_PWR_SW_RESET_DISP_MASK                                                (0x00080000U)

#define CTRL_DPLL_PWR_SW_RET_DISP_SHIFT                                                 (20U)
#define CTRL_DPLL_PWR_SW_RET_DISP_MASK                                                  (0x00100000U)

#define CTRL_DPLL_PWR_SW_ISOSCAN_DISP_SHIFT                                             (21U)
#define CTRL_DPLL_PWR_SW_ISOSCAN_DISP_MASK                                              (0x00200000U)

#define CTRL_DPLL_PWR_SW_DISP_PLL_SHIFT                                                 (23U)
#define CTRL_DPLL_PWR_SW_DISP_PLL_MASK                                                  (0x00800000U)

#define CTRL_DPLL_PWR_SW_PONIN_DDR_SHIFT                                                (24U)
#define CTRL_DPLL_PWR_SW_PONIN_DDR_MASK                                                 (0x01000000U)

#define CTRL_DPLL_PWR_SW_PGOODIN_DDR_SHIFT                                              (25U)
#define CTRL_DPLL_PWR_SW_PGOODIN_DDR_MASK                                               (0x02000000U)

#define CTRL_DPLL_PWR_SW_ISO_DDR_SHIFT                                                  (26U)
#define CTRL_DPLL_PWR_SW_ISO_DDR_MASK                                                   (0x04000000U)

#define CTRL_DPLL_PWR_SW_RESET_DDR_SHIFT                                                (27U)
#define CTRL_DPLL_PWR_SW_RESET_DDR_MASK                                                 (0x08000000U)

#define CTRL_DPLL_PWR_SW_RET_DDR_SHIFT                                                  (28U)
#define CTRL_DPLL_PWR_SW_RET_DDR_MASK                                                   (0x10000000U)

#define CTRL_DPLL_PWR_SW_ISOSCAN_DDR_SHIFT                                              (29U)
#define CTRL_DPLL_PWR_SW_ISOSCAN_DDR_MASK                                               (0x20000000U)

#define CTRL_DPLL_PWR_SW_DDR_PLL_SHIFT                                                  (31U)
#define CTRL_DPLL_PWR_SW_DDR_PLL_MASK                                                   (0x80000000U)

#define CTRL_DDR_CKE_CKE0_SHIFT                                                         (0U)
#define CTRL_DDR_CKE_CKE0_MASK                                                          (0x00000001U)

#define CTRL_DDR_CKE_CKE1_SHIFT                                                         (1U)
#define CTRL_DDR_CKE_CKE1_MASK                                                          (0x00000002U)

#define CTRL_DDR_CKE_CKE0_ST_SHIFT                                                      (2U)
#define CTRL_DDR_CKE_CKE0_ST_MASK                                                       (0x00000004U)

#define CTRL_DDR_CKE_CKE1_ST_SHIFT                                                      (3U)
#define CTRL_DDR_CKE_CKE1_ST_MASK                                                       (0x00000008U)

#define CTRL_DDR_CKE_SMA1_SHIFT                                                         (4U)
#define CTRL_DDR_CKE_SMA1_MASK                                                          (0xfffffff0U)

#define CTRL_SMA2_BIT0_SHIFT                                                            (0U)
#define CTRL_SMA2_BIT0_MASK                                                             (0x00000001U)

#define CTRL_SMA2_VSLDO_CORE_AUTO_RAMP_EN_SHIFT                                         (1U)
#define CTRL_SMA2_VSLDO_CORE_AUTO_RAMP_EN_MASK                                          (0x00000002U)

#define CTRL_SMA2_SHIFT                                                                 (2U)
#define CTRL_SMA2_MASK                                                                  (0xfffffffcU)

#define CTRL_WAKEM3_TXEV_EOI_SHIFT                                                      (0U)
#define CTRL_WAKEM3_TXEV_EOI_MASK                                                       (0x00000001U)

#define CTRL_WAKEM3_TXEV_EOI_SMA3_SHIFT                                                 (1U)
#define CTRL_WAKEM3_TXEV_EOI_SMA3_MASK                                                  (0xfffffffeU)

#define CTRL_IPC_MSG_REG0_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG0_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG1_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG1_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG2_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG2_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG3_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG3_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG4_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG4_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG5_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG5_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG6_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG6_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG7_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG7_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG8_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG8_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG9_SHIFT                                                         (0U)
#define CTRL_IPC_MSG_REG9_MASK                                                          (0xffffffffU)

#define CTRL_IPC_MSG_REG10_SHIFT                                                        (0U)
#define CTRL_IPC_MSG_REG10_MASK                                                         (0xffffffffU)

#define CTRL_IPC_MSG_REG11_SHIFT                                                        (0U)
#define CTRL_IPC_MSG_REG11_MASK                                                         (0xffffffffU)

#define CTRL_IPC_MSG_REG12_SHIFT                                                        (0U)
#define CTRL_IPC_MSG_REG12_MASK                                                         (0xffffffffU)

#define CTRL_IPC_MSG_REG13_SHIFT                                                        (0U)
#define CTRL_IPC_MSG_REG13_MASK                                                         (0xffffffffU)

#define CTRL_IPC_MSG_REG14_SHIFT                                                        (0U)
#define CTRL_IPC_MSG_REG14_MASK                                                         (0xffffffffU)

#define CTRL_IPC_INTR_MSG_REG15_SHIFT                                                   (0U)
#define CTRL_IPC_INTR_MSG_REG15_MASK                                                    (0x7fffffffU)

#define CTRL_IPC_INTR_INTR2WAKEM3_SHIFT                                                 (31U)
#define CTRL_IPC_INTR_INTR2WAKEM3_MASK                                                  (0x80000000U)

#define CTRL_DPLL_PWR_SW_CTRL2_PONIN_EXTCLK_SHIFT                                       (0U)
#define CTRL_DPLL_PWR_SW_CTRL2_PONIN_EXTCLK_MASK                                        (0x00000001U)

#define CTRL_DPLL_PWR_SW_CTRL2_PGOODIN_EXTCLK_SHIFT                                     (1U)
#define CTRL_DPLL_PWR_SW_CTRL2_PGOODIN_EXTCLK_MASK                                      (0x00000002U)

#define CTRL_DPLL_PWR_SW_CTRL2_ISO_EXTCLK_SHIFT                                         (2U)
#define CTRL_DPLL_PWR_SW_CTRL2_ISO_EXTCLK_MASK                                          (0x00000004U)

#define CTRL_DPLL_PWR_SW_CTRL2_RESET_EXTCLK_SHIFT                                       (3U)
#define CTRL_DPLL_PWR_SW_CTRL2_RESET_EXTCLK_MASK                                        (0x00000008U)

#define CTRL_DPLL_PWR_SW_CTRL2_RET_EXTCLK_SHIFT                                         (4U)
#define CTRL_DPLL_PWR_SW_CTRL2_RET_EXTCLK_MASK                                          (0x00000010U)

#define CTRL_DPLL_PWR_SW_CTRL2_ISOSCAN_EXTCLK_SHIFT                                     (5U)
#define CTRL_DPLL_PWR_SW_CTRL2_ISOSCAN_EXTCLK_MASK                                      (0x00000020U)

#define CTRL_DPLL_PWR_SW_CTRL2_EXTCLK_PLL_SHIFT                                         (7U)
#define CTRL_DPLL_PWR_SW_CTRL2_EXTCLK_PLL_MASK                                          (0x00000080U)

#define CTRL_DPLL_PWR_SW_STS2_PONOUT_EXTCLK_SHIFT                                       (0U)
#define CTRL_DPLL_PWR_SW_STS2_PONOUT_EXTCLK_MASK                                        (0x00000001U)

#define CTRL_DPLL_PWR_SW_STS2_PGOODOUT_EXTCLK_SHIFT                                     (1U)
#define CTRL_DPLL_PWR_SW_STS2_PGOODOUT_EXTCLK_MASK                                      (0x00000002U)

#define CTRL_SMA4_SHIFT                                                                 (0U)
#define CTRL_SMA4_MASK                                                                  (0xffffffffU)

#define CTRL_CQDETECT_STS_CQSTAT_GPMC_SHIFT                                             (0U)
#define CTRL_CQDETECT_STS_CQSTAT_GPMC_MASK                                              (0x00000001U)

#define CTRL_CQDETECT_STS_CQSTAT_MMCSD_A_SHIFT                                          (1U)
#define CTRL_CQDETECT_STS_CQSTAT_MMCSD_A_MASK                                           (0x00000002U)

#define CTRL_CQDETECT_STS_CQSTAT_MMCSD_B_SHIFT                                          (2U)
#define CTRL_CQDETECT_STS_CQSTAT_MMCSD_B_MASK                                           (0x00000004U)

#define CTRL_CQDETECT_STS_CQSTAT_GEMAC_A_SHIFT                                          (3U)
#define CTRL_CQDETECT_STS_CQSTAT_GEMAC_A_MASK                                           (0x00000008U)

#define CTRL_CQDETECT_STS_CQSTAT_GEMAC_B_SHIFT                                          (4U)
#define CTRL_CQDETECT_STS_CQSTAT_GEMAC_B_MASK                                           (0x00000010U)

#define CTRL_CQDETECT_STS_CQSTAT_GENERAL_SHIFT                                          (5U)
#define CTRL_CQDETECT_STS_CQSTAT_GENERAL_MASK                                           (0x00000020U)

#define CTRL_CQDETECT_STS_CQSTAT_LCDC_SHIFT                                             (6U)
#define CTRL_CQDETECT_STS_CQSTAT_LCDC_MASK                                              (0x00000040U)

#define CTRL_CQDETECT_STS_CQSTAT_CAMERA_SHIFT                                           (7U)
#define CTRL_CQDETECT_STS_CQSTAT_CAMERA_MASK                                            (0x00000080U)

#define CTRL_CQDETECT_STS_CQERR_GPMC_SHIFT                                              (8U)
#define CTRL_CQDETECT_STS_CQERR_GPMC_MASK                                               (0x00000100U)

#define CTRL_CQDETECT_STS_CQERR_MMCSD_A_SHIFT                                           (9U)
#define CTRL_CQDETECT_STS_CQERR_MMCSD_A_MASK                                            (0x00000200U)

#define CTRL_CQDETECT_STS_CQERR_MMCSD_B_SHIFT                                           (10U)
#define CTRL_CQDETECT_STS_CQERR_MMCSD_B_MASK                                            (0x00000400U)

#define CTRL_CQDETECT_STS_CQERR_GEMAC_A_SHIFT                                           (11U)
#define CTRL_CQDETECT_STS_CQERR_GEMAC_A_MASK                                            (0x00000800U)

#define CTRL_CQDETECT_STS_CQERR_GEMAC_B_SHIFT                                           (12U)
#define CTRL_CQDETECT_STS_CQERR_GEMAC_B_MASK                                            (0x00001000U)

#define CTRL_CQDETECT_STS_CQERR_GENERAL_SHIFT                                           (13U)
#define CTRL_CQDETECT_STS_CQERR_GENERAL_MASK                                            (0x00002000U)

#define CTRL_CQDETECT_STS_CQERR_LCDC_SHIFT                                              (14U)
#define CTRL_CQDETECT_STS_CQERR_LCDC_MASK                                               (0x00004000U)

#define CTRL_CQDETECT_STS_CQERR_CAMERA_SHIFT                                            (15U)
#define CTRL_CQDETECT_STS_CQERR_CAMERA_MASK                                             (0x00008000U)

#define CTRL_CQDETECT_STS_CQMODE_GPMC_SHIFT                                             (16U)
#define CTRL_CQDETECT_STS_CQMODE_GPMC_MASK                                              (0x00010000U)

#define CTRL_CQDETECT_STS_CQMODE_MMCSD_A_SHIFT                                          (17U)
#define CTRL_CQDETECT_STS_CQMODE_MMCSD_A_MASK                                           (0x00020000U)

#define CTRL_CQDETECT_STS_CQMODE_MMCSD_B_SHIFT                                          (18U)
#define CTRL_CQDETECT_STS_CQMODE_MMCSD_B_MASK                                           (0x00040000U)

#define CTRL_CQDETECT_STS_CQMODE_GEMAC_A_SHIFT                                          (19U)
#define CTRL_CQDETECT_STS_CQMODE_GEMAC_A_MASK                                           (0x00080000U)

#define CTRL_CQDETECT_STS_CQMODE_GEMAC_B_SHIFT                                          (20U)
#define CTRL_CQDETECT_STS_CQMODE_GEMAC_B_MASK                                           (0x00100000U)

#define CTRL_CQDETECT_STS_CQMODE_GENERAL_SHIFT                                          (21U)
#define CTRL_CQDETECT_STS_CQMODE_GENERAL_MASK                                           (0x00200000U)

#define CTRL_CQDETECT_STS_CQMODE_LCDC_SHIFT                                             (22U)
#define CTRL_CQDETECT_STS_CQMODE_LCDC_MASK                                              (0x00400000U)

#define CTRL_CQDETECT_STS_CQMODE_CAMERA_SHIFT                                           (23U)
#define CTRL_CQDETECT_STS_CQMODE_CAMERA_MASK                                            (0x00800000U)

#define CTRL_DDR_IO_MDDR_SEL_SHIFT                                                      (28U)
#define CTRL_DDR_IO_MDDR_SEL_MASK                                                       (0x10000000U)

#define CTRL_DDR_IO_SPARE_SHIFT                                                         (30U)
#define CTRL_DDR_IO_SPARE_MASK                                                          (0x40000000U)

#define CTRL_DDR_IO_DDR3_RST_DEF_VAL_SHIFT                                              (31U)
#define CTRL_DDR_IO_DDR3_RST_DEF_VAL_MASK                                               (0x80000000U)

#define CTRL_CQDETECT_STS2_CQSTAT_CLKOUT_SHIFT                                          (0U)
#define CTRL_CQDETECT_STS2_CQSTAT_CLKOUT_MASK                                           (0x00000001U)

#define CTRL_CQDETECT_STS2_CQSTAT_MDIO_SHIFT                                            (1U)
#define CTRL_CQDETECT_STS2_CQSTAT_MDIO_MASK                                             (0x00000002U)

#define CTRL_CQDETECT_STS2_CQERR_CLKOUT_SHIFT                                           (8U)
#define CTRL_CQDETECT_STS2_CQERR_CLKOUT_MASK                                            (0x00000100U)

#define CTRL_CQDETECT_STS2_CQERR_MDIO_SHIFT                                             (9U)
#define CTRL_CQDETECT_STS2_CQERR_MDIO_MASK                                              (0x00000200U)

#define CTRL_CQDETECT_STS2_CQMODE_CLKOUT_SHIFT                                          (16U)
#define CTRL_CQDETECT_STS2_CQMODE_CLKOUT_MASK                                           (0x00010000U)

#define CTRL_CQDETECT_STS2_CQMODE_MDIO_SHIFT                                            (17U)
#define CTRL_CQDETECT_STS2_CQMODE_MDIO_MASK                                             (0x00020000U)

#define CTRL_VTP_CLRZ_SHIFT                                                             (0U)
#define CTRL_VTP_CLRZ_MASK                                                              (0x00000001U)

#define CTRL_VTP_FILTER_SHIFT                                                           (1U)
#define CTRL_VTP_FILTER_MASK                                                            (0x0000000eU)

#define CTRL_VTP_LOCK_SHIFT                                                             (4U)
#define CTRL_VTP_LOCK_MASK                                                              (0x00000010U)

#define CTRL_VTP_READY_SHIFT                                                            (5U)
#define CTRL_VTP_READY_MASK                                                             (0x00000020U)

#define CTRL_VTP_EN_SHIFT                                                               (6U)
#define CTRL_VTP_EN_MASK                                                                (0x00000040U)

#define CTRL_VTP_NCIN_SHIFT                                                             (8U)
#define CTRL_VTP_NCIN_MASK                                                              (0x00007f00U)

#define CTRL_VTP_PCIN_SHIFT                                                             (16U)
#define CTRL_VTP_PCIN_MASK                                                              (0x007f0000U)

#define CTRL_VREF_DDR_EN_SHIFT                                                          (0U)
#define CTRL_VREF_DDR_EN_MASK                                                           (0x00000001U)

#define CTRL_VREF_DDR_TAP_SHIFT                                                         (1U)
#define CTRL_VREF_DDR_TAP_MASK                                                          (0x00000006U)

#define CTRL_VREF_DDR_CCAP_SHIFT                                                        (3U)
#define CTRL_VREF_DDR_CCAP_MASK                                                         (0x00000018U)

#define CTRL_TPCC_EVT_MUX_0_3_MUX0_SHIFT                                                (0U)
#define CTRL_TPCC_EVT_MUX_0_3_MUX0_MASK                                                 (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_0_3_MUX1_SHIFT                                                (8U)
#define CTRL_TPCC_EVT_MUX_0_3_MUX1_MASK                                                 (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_0_3_MUX2_SHIFT                                                (16U)
#define CTRL_TPCC_EVT_MUX_0_3_MUX2_MASK                                                 (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_0_3_MUX3_SHIFT                                                (24U)
#define CTRL_TPCC_EVT_MUX_0_3_MUX3_MASK                                                 (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_4_7_MUX4_SHIFT                                                (0U)
#define CTRL_TPCC_EVT_MUX_4_7_MUX4_MASK                                                 (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_4_7_MUX5_SHIFT                                                (8U)
#define CTRL_TPCC_EVT_MUX_4_7_MUX5_MASK                                                 (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_4_7_MUX6_SHIFT                                                (16U)
#define CTRL_TPCC_EVT_MUX_4_7_MUX6_MASK                                                 (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_4_7_MUX7_SHIFT                                                (24U)
#define CTRL_TPCC_EVT_MUX_4_7_MUX7_MASK                                                 (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_8_11_MUX8_SHIFT                                               (0U)
#define CTRL_TPCC_EVT_MUX_8_11_MUX8_MASK                                                (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_8_11_MUX9_SHIFT                                               (8U)
#define CTRL_TPCC_EVT_MUX_8_11_MUX9_MASK                                                (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_8_11_MUX10_SHIFT                                              (16U)
#define CTRL_TPCC_EVT_MUX_8_11_MUX10_MASK                                               (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_8_11_MUX11_SHIFT                                              (24U)
#define CTRL_TPCC_EVT_MUX_8_11_MUX11_MASK                                               (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_12_15_MUX12_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_12_15_MUX12_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_12_15_MUX13_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_12_15_MUX13_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_12_15_MUX14_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_12_15_MUX14_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_12_15_MUX15_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_12_15_MUX15_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_16_19_MUX16_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_16_19_MUX16_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_16_19_MUX17_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_16_19_MUX17_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_16_19_MUX18_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_16_19_MUX18_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_16_19_MUX19_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_16_19_MUX19_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_20_23_MUX20_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_20_23_MUX20_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_20_23_MUX21_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_20_23_MUX21_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_20_23_MUX22_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_20_23_MUX22_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_20_23_MUX23_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_20_23_MUX23_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_24_27_MUX24_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_24_27_MUX24_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_24_27_MUX25_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_24_27_MUX25_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_24_27_MUX26_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_24_27_MUX26_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_24_27_MUX27_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_24_27_MUX27_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_28_31_MUX28_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_28_31_MUX28_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_28_31_MUX29_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_28_31_MUX29_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_28_31_MUX30_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_28_31_MUX30_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_28_31_MUX31_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_28_31_MUX31_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_32_35_MUX32_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_32_35_MUX32_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_32_35_MUX33_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_32_35_MUX33_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_32_35_MUX34_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_32_35_MUX34_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_32_35_MUX35_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_32_35_MUX35_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_36_39_MUX36_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_36_39_MUX36_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_36_39_MUX37_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_36_39_MUX37_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_36_39_MUX38_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_36_39_MUX38_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_36_39_MUX39_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_36_39_MUX39_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_40_43_MUX40_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_40_43_MUX40_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_40_43_MUX41_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_40_43_MUX41_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_40_43_MUX42_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_40_43_MUX42_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_40_43_MUX43_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_40_43_MUX43_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_44_47_MUX44_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_44_47_MUX44_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_44_47_MUX45_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_44_47_MUX45_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_44_47_MUX46_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_44_47_MUX46_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_44_47_MUX47_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_44_47_MUX47_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_48_51_MUX48_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_48_51_MUX48_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_48_51_MUX49_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_48_51_MUX49_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_48_51_MUX50_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_48_51_MUX50_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_48_51_MUX51_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_48_51_MUX51_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_52_55_MUX52_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_52_55_MUX52_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_52_55_MUX53_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_52_55_MUX53_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_52_55_MUX54_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_52_55_MUX54_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_52_55_MUX55_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_52_55_MUX55_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_56_59_MUX56_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_56_59_MUX56_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_56_59_MUX57_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_56_59_MUX57_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_56_59_MUX58_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_56_59_MUX58_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_56_59_MUX59_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_56_59_MUX59_MASK                                              (0x3f000000U)

#define CTRL_TPCC_EVT_MUX_60_63_MUX63_SHIFT                                             (0U)
#define CTRL_TPCC_EVT_MUX_60_63_MUX63_MASK                                              (0x0000003fU)

#define CTRL_TPCC_EVT_MUX_60_63_MUX62_SHIFT                                             (8U)
#define CTRL_TPCC_EVT_MUX_60_63_MUX62_MASK                                              (0x00003f00U)

#define CTRL_TPCC_EVT_MUX_60_63_MUX61_SHIFT                                             (16U)
#define CTRL_TPCC_EVT_MUX_60_63_MUX61_MASK                                              (0x003f0000U)

#define CTRL_TPCC_EVT_MUX_60_63_MUX60_SHIFT                                             (24U)
#define CTRL_TPCC_EVT_MUX_60_63_MUX60_MASK                                              (0x3f000000U)

#define CTRL_TIMER_EVT_CAPT_TIMER5_EVTCAPT_SHIFT                                        (0U)
#define CTRL_TIMER_EVT_CAPT_TIMER5_EVTCAPT_MASK                                         (0x0000001fU)

#define CTRL_TIMER_EVT_CAPT_TIMER6_EVTCAPT_SHIFT                                        (8U)
#define CTRL_TIMER_EVT_CAPT_TIMER6_EVTCAPT_MASK                                         (0x00001f00U)

#define CTRL_TIMER_EVT_CAPT_TIMER7_EVTCAPT_SHIFT                                        (16U)
#define CTRL_TIMER_EVT_CAPT_TIMER7_EVTCAPT_MASK                                         (0x001f0000U)

#define CTRL_ECAP_EVT_CAPT_ECAP0_EVTCAPT_SHIFT                                          (0U)
#define CTRL_ECAP_EVT_CAPT_ECAP0_EVTCAPT_MASK                                           (0x0000001fU)

#define CTRL_ECAP_EVT_CAPT_ECAP1_EVTCAPT_SHIFT                                          (8U)
#define CTRL_ECAP_EVT_CAPT_ECAP1_EVTCAPT_MASK                                           (0x00001f00U)

#define CTRL_ECAP_EVT_CAPT_ECAP2_EVTCAPT_SHIFT                                          (16U)
#define CTRL_ECAP_EVT_CAPT_ECAP2_EVTCAPT_MASK                                           (0x001f0000U)

#define CTRL_ADC_EVT_CAPT_EVTCAPT_SHIFT                                                 (0U)
#define CTRL_ADC_EVT_CAPT_EVTCAPT_MASK                                                  (0x0000000fU)

#define CTRL_MAG_EVT_CAPT_EVTCAPT_SHIFT                                                 (0U)
#define CTRL_MAG_EVT_CAPT_EVTCAPT_MASK                                                  (0x0000000fU)

#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_I_SHIFT                                      (0U)
#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_I_MASK                                       (0x00000007U)

#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_SR_SHIFT                                     (3U)
#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_SR_MASK                                      (0x00000018U)

#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_I_CLK_SHIFT                                  (5U)
#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_I_CLK_MASK                                   (0x000000e0U)

#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_SR_CLK_SHIFT                                 (8U)
#define CTRL_DDR_ADDRCTRL_IOCTRL_IO_CONFIG_SR_CLK_MASK                                  (0x00000300U)

#define CTRL_DDR_ADDRCTRL_WD0_IOCTRL_REG_SHIFT                                          (0U)
#define CTRL_DDR_ADDRCTRL_WD0_IOCTRL_REG_MASK                                           (0xffffffffU)

#define CTRL_DDR_ADDRCTRL_WD1_IOCTRL_REG_SHIFT                                          (0U)
#define CTRL_DDR_ADDRCTRL_WD1_IOCTRL_REG_MASK                                           (0xffffffffU)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_I_SHIFT                                         (0U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_I_MASK                                          (0x00000007U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_SR_SHIFT                                        (3U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_SR_MASK                                         (0x00000018U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_I_CLK_SHIFT                                     (5U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_I_CLK_MASK                                      (0x000000e0U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_SR_CLK_SHIFT                                    (8U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_SR_CLK_MASK                                     (0x00000300U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DQ_SHIFT                                    (10U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DQ_MASK                                     (0x0003fc00U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DM_SHIFT                                    (18U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DM_MASK                                     (0x00040000U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DQS_SHIFT                                   (19U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD0_DQS_MASK                                    (0x00080000U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DQ_SHIFT                                    (20U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DQ_MASK                                     (0x0ff00000U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DM_SHIFT                                    (28U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DM_MASK                                     (0x10000000U)

#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DQS_SHIFT                                   (29U)
#define CTRL_DDR_DATA0_IOCTRL_IO_CONFIG_WD1_DQS_MASK                                    (0x20000000U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_I_SHIFT                                         (0U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_I_MASK                                          (0x00000007U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_SR_SHIFT                                        (3U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_SR_MASK                                         (0x00000018U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_I_CLK_SHIFT                                     (5U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_I_CLK_MASK                                      (0x000000e0U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_SR_CLK_SHIFT                                    (8U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_SR_CLK_MASK                                     (0x00000300U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DQ_SHIFT                                    (10U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DQ_MASK                                     (0x0003fc00U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DM_SHIFT                                    (18U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DM_MASK                                     (0x00040000U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DQS_SHIFT                                   (19U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD0_DQS_MASK                                    (0x00080000U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DQ_SHIFT                                    (20U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DQ_MASK                                     (0x0ff00000U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DM_SHIFT                                    (28U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DM_MASK                                     (0x10000000U)

#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DQS_SHIFT                                   (29U)
#define CTRL_DDR_DATA1_IOCTRL_IO_CONFIG_WD1_DQS_MASK                                    (0x20000000U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_I_SHIFT                                         (0U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_I_MASK                                          (0x00000007U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_SR_SHIFT                                        (3U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_SR_MASK                                         (0x00000018U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_I_CLK_SHIFT                                     (5U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_I_CLK_MASK                                      (0x000000e0U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_SR_CLK_SHIFT                                    (8U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_SR_CLK_MASK                                     (0x00000300U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DQ_SHIFT                                    (10U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DQ_MASK                                     (0x0003fc00U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DM_SHIFT                                    (18U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DM_MASK                                     (0x00040000U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DQS_SHIFT                                   (19U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD0_DQS_MASK                                    (0x00080000U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DQ_SHIFT                                    (20U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DQ_MASK                                     (0x0ff00000U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DM_SHIFT                                    (28U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DM_MASK                                     (0x10000000U)

#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DQS_SHIFT                                   (29U)
#define CTRL_DDR_DATA2_IOCTRL_IO_CONFIG_WD1_DQS_MASK                                    (0x20000000U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_I_SHIFT                                         (0U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_I_MASK                                          (0x00000007U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_SR_SHIFT                                        (3U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_SR_MASK                                         (0x00000018U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_I_CLK_SHIFT                                     (5U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_I_CLK_MASK                                      (0x000000e0U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_SR_CLK_SHIFT                                    (8U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_SR_CLK_MASK                                     (0x00000300U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DQ_SHIFT                                    (10U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DQ_MASK                                     (0x0003fc00U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DM_SHIFT                                    (18U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DM_MASK                                     (0x00040000U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DQS_SHIFT                                   (19U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD0_DQS_MASK                                    (0x00080000U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DQ_SHIFT                                    (20U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DQ_MASK                                     (0x0ff00000U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DM_SHIFT                                    (28U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DM_MASK                                     (0x10000000U)

#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DQS_SHIFT                                   (29U)
#define CTRL_DDR_DATA3_IOCTRL_IO_CONFIG_WD1_DQS_MASK                                    (0x20000000U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_0_SHIFT                                     (0U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_0_MASK                                      (0x00000001U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_1_SHIFT                                     (1U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_1_MASK                                      (0x00000002U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_2_SHIFT                                     (2U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_SLICE_2_MASK                                      (0x00000004U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_DFI_CLOCK_PHASE_SHIFT                                (3U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_DFI_CLOCK_PHASE_MASK                                 (0x00000008U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_RD_LOCAL_ODT_SHIFT                               (5U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_RD_LOCAL_ODT_MASK                                (0x00000060U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_DYNAMIC_PWRDN_EN_SHIFT                               (8U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_DYNAMIC_PWRDN_EN_MASK                                (0x00000100U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_OUTPUT_STS_SELECT_SHIFT                          (9U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_OUTPUT_STS_SELECT_MASK                           (0x00000e00U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_ALL_DQ_MPR_RD_RESP_SHIFT                         (12U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_ALL_DQ_MPR_RD_RESP_MASK                          (0x00001000U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_SEL_LOGIC_SHIFT                                  (13U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_SEL_LOGIC_MASK                                   (0x00002000U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_NUM_OF_SAMPLES_SHIFT                             (14U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_PHY_NUM_OF_SAMPLES_MASK                              (0x0000c000U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_ECC_SHIFT                                         (16U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_EN_ECC_MASK                                          (0x00010000U)

#define CTRL_EMIF_SDRAM_CONFIG_EXT_NARROW_ONLY_SHIFT                                    (17U)
#define CTRL_EMIF_SDRAM_CONFIG_EXT_NARROW_ONLY_MASK                                     (0x00020000U)

#define CTRL_EMIF_SDRAM_STS_EXT_REG_SHIFT                                               (0U)
#define CTRL_EMIF_SDRAM_STS_EXT_REG_MASK                                                (0xffffffffU)

#define CTRL_PRINTER_STROBE_POLARITY_SHIFT                                              (0U)
#define CTRL_PRINTER_STROBE_POLARITY_MASK                                               (0x00000001U)

#define CTRL_PRINTER_MA_POLARITY_SHIFT                                                  (1U)
#define CTRL_PRINTER_MA_POLARITY_MASK                                                   (0x00000002U)

#define CTRL_PRINTER_MNA_POLARITY_SHIFT                                                 (2U)
#define CTRL_PRINTER_MNA_POLARITY_MASK                                                  (0x00000004U)

#define CTRL_PRINTER_MB_POLARITY_SHIFT                                                  (3U)
#define CTRL_PRINTER_MB_POLARITY_MASK                                                   (0x00000008U)

#define CTRL_PRINTER_MNB_POLARITY_SHIFT                                                 (4U)
#define CTRL_PRINTER_MNB_POLARITY_MASK                                                  (0x00000010U)

#define CTRL_PRINTER_ON_POLARITY_SHIFT                                                  (5U)
#define CTRL_PRINTER_ON_POLARITY_MASK                                                   (0x00000020U)

#define CTRL_PRINTER_SPI_CS_POLARITY_SHIFT                                              (6U)
#define CTRL_PRINTER_SPI_CS_POLARITY_MASK                                               (0x00000040U)

#define CTRL_PRINTER_GPIO5_BIT7_POLARITY_SHIFT                                          (7U)
#define CTRL_PRINTER_GPIO5_BIT7_POLARITY_MASK                                           (0x00000080U)

#define CTRL_PRINTER_STROBE_CTR_PRESCALER_SHIFT                                         (8U)
#define CTRL_PRINTER_STROBE_CTR_PRESCALER_MASK                                          (0x00000300U)

#define CTRL_PRINTER_TIMER_PRINTMA_EN_SHIFT                                             (10U)
#define CTRL_PRINTER_TIMER_PRINTMA_EN_MASK                                              (0x00000400U)

#define CTRL_PRINTER_TIMER_PRINTMNA_EN_SHIFT                                            (11U)
#define CTRL_PRINTER_TIMER_PRINTMNA_EN_MASK                                             (0x00000800U)

#define CTRL_PRINTER_TIMER_PRINTMB_EN_SHIFT                                             (12U)
#define CTRL_PRINTER_TIMER_PRINTMB_EN_MASK                                              (0x00001000U)

#define CTRL_PRINTER_TIMER_PRINTMNB_EN_SHIFT                                            (13U)
#define CTRL_PRINTER_TIMER_PRINTMNB_EN_MASK                                             (0x00002000U)

#define CTRL_STRB_CNTR_LOAD_VAL_REG_SHIFT                                               (0U)
#define CTRL_STRB_CNTR_LOAD_VAL_REG_MASK                                                (0x0000ffffU)

#define CTRL_STRB_CNTR_LOAD_REG_SHIFT                                                   (0U)
#define CTRL_STRB_CNTR_LOAD_REG_MASK                                                    (0x00000001U)

#define CTRL_STRB_CNTR_EOI_SHIFT                                                        (0U)
#define CTRL_STRB_CNTR_EOI_MASK                                                         (0x00000001U)

#define CTRL_STRB_CNTR_REG_SHIFT                                                        (0U)
#define CTRL_STRB_CNTR_REG_MASK                                                         (0x0000ffffU)

#define CTRL_SPI_CNTR_LOAD_VAL_REG_SHIFT                                                (0U)
#define CTRL_SPI_CNTR_LOAD_VAL_REG_MASK                                                 (0x000003ffU)

#define CTRL_SPI_CNTR_LOAD_STRB_REG_SHIFT                                               (0U)
#define CTRL_SPI_CNTR_LOAD_STRB_REG_MASK                                                (0x00000001U)

#define CTRL_SPI_CNTR_EOI_SHIFT                                                         (0U)
#define CTRL_SPI_CNTR_EOI_MASK                                                          (0x00000001U)

#define CTRL_PRINTER_TIMER_TIMEOUT_REG_SHIFT                                            (0U)
#define CTRL_PRINTER_TIMER_TIMEOUT_REG_MASK                                             (0x000000ffU)

#define CTRL_DIE_ID2_ID_SHIFT                                                           (0U)
#define CTRL_DIE_ID2_ID_MASK                                                            (0xffffffffU)

#define CTRL_ID_UNLOCK1_SHIFT                                                           (0U)
#define CTRL_ID_UNLOCK1_MASK                                                            (0xffffffffU)

#define CTRL_ID_UNLOCK2_SHIFT                                                           (0U)
#define CTRL_ID_UNLOCK2_MASK                                                            (0xffffffffU)

#define CTRL_DIE_ID0_ID_SHIFT                                                           (0U)
#define CTRL_DIE_ID0_ID_MASK                                                            (0xffffffffU)

#define CTRL_ID_UNLOCK0_SHIFT                                                           (0U)
#define CTRL_ID_UNLOCK0_MASK                                                            (0xffffffffU)

#define CTRL_DIE_ID1_ID_SHIFT                                                           (0U)
#define CTRL_DIE_ID1_ID_MASK                                                            (0xffffffffU)

#define CTRL_ID_UNLOCK3_SHIFT                                                           (0U)
#define CTRL_ID_UNLOCK3_MASK                                                            (0xffffffffU)

#define CTRL_DIE_ID3_ID_SHIFT                                                           (0U)
#define CTRL_DIE_ID3_ID_MASK                                                            (0xffffffffU)

#define CTRL_DISPPLL_CLKCTRL_TINITZ_SHIFT                                               (0U)
#define CTRL_DISPPLL_CLKCTRL_TINITZ_MASK                                                (0x00000001U)

#define CTRL_DISPPLL_CLKCTRL_RELAXED_LOCK_SHIFT                                         (8U)
#define CTRL_DISPPLL_CLKCTRL_RELAXED_LOCK_MASK                                          (0x00000100U)

#define CTRL_DISPPLL_CLKCTRL_REGM4XEN_SHIFT                                             (10U)
#define CTRL_DISPPLL_CLKCTRL_REGM4XEN_MASK                                              (0x00000400U)

#define CTRL_DISPPLL_CLKCTRL_DRIFTGUARDEN_SHIFT                                         (11U)
#define CTRL_DISPPLL_CLKCTRL_DRIFTGUARDEN_MASK                                          (0x00000800U)

#define CTRL_DISPPLL_CLKCTRL_LPMODE_SHIFT                                               (12U)
#define CTRL_DISPPLL_CLKCTRL_LPMODE_MASK                                                (0x00001000U)

#define CTRL_DISPPLL_CLKCTRL_LOWCURRSTDBY_SHIFT                                         (13U)
#define CTRL_DISPPLL_CLKCTRL_LOWCURRSTDBY_MASK                                          (0x00002000U)

#define CTRL_DISPPLL_CLKCTRL_STOPMODE_SHIFT                                             (14U)
#define CTRL_DISPPLL_CLKCTRL_STOPMODE_MASK                                              (0x00004000U)

#define CTRL_DISPPLL_CLKCTRL_M3PWDNZ_SHIFT                                              (15U)
#define CTRL_DISPPLL_CLKCTRL_M3PWDNZ_MASK                                               (0x00008000U)

#define CTRL_DISPPLL_CLKCTRL_M2PWDNZ_SHIFT                                              (16U)
#define CTRL_DISPPLL_CLKCTRL_M2PWDNZ_MASK                                               (0x00010000U)

#define CTRL_DISPPLL_CLKCTRL_CLKDCOLDOPWDNZ_SHIFT                                       (17U)
#define CTRL_DISPPLL_CLKCTRL_CLKDCOLDOPWDNZ_MASK                                        (0x00020000U)

#define CTRL_DISPPLL_CLKCTRL_ULOWCLKEN_SHIFT                                            (18U)
#define CTRL_DISPPLL_CLKCTRL_ULOWCLKEN_MASK                                             (0x00040000U)

#define CTRL_DISPPLL_CLKCTRL_CLKOUTEN_SHIFT                                             (20U)
#define CTRL_DISPPLL_CLKCTRL_CLKOUTEN_MASK                                              (0x00100000U)

#define CTRL_DISPPLL_CLKCTRL_STBYRET_SHIFT                                              (21U)
#define CTRL_DISPPLL_CLKCTRL_STBYRET_MASK                                               (0x00200000U)

#define CTRL_DISPPLL_CLKCTRL_BYPASSACKZ_SHIFT                                           (22U)
#define CTRL_DISPPLL_CLKCTRL_BYPASSACKZ_MASK                                            (0x00400000U)

#define CTRL_DISPPLL_CLKCTRL_IDLE_SHIFT                                                 (23U)
#define CTRL_DISPPLL_CLKCTRL_IDLE_MASK                                                  (0x00800000U)

#define CTRL_DISPPLL_CLKCTRL_NWELLTRIM_SHIFT                                            (24U)
#define CTRL_DISPPLL_CLKCTRL_NWELLTRIM_MASK                                             (0x1f000000U)

#define CTRL_DISPPLL_CLKCTRL_ENSSC_SHIFT                                                (30U)
#define CTRL_DISPPLL_CLKCTRL_ENSSC_MASK                                                 (0x40000000U)

#define CTRL_DISPPLL_CLKCTRL_CYCLESLIPEN_SHIFT                                          (31U)
#define CTRL_DISPPLL_CLKCTRL_CYCLESLIPEN_MASK                                           (0x80000000U)

#define CTRL_DISPPLL_TEN_SHIFT                                                          (0U)
#define CTRL_DISPPLL_TEN_MASK                                                           (0x00000001U)

#define CTRL_DISPPLL_TENIV_SHIFT                                                        (0U)
#define CTRL_DISPPLL_TENIV_MASK                                                         (0x00000001U)

#define CTRL_DISPPLL_M2NDIV_N_SHIFT                                                     (0U)
#define CTRL_DISPPLL_M2NDIV_N_MASK                                                      (0x000000ffU)

#define CTRL_DISPPLL_M2NDIV_M2_SHIFT                                                    (16U)
#define CTRL_DISPPLL_M2NDIV_M2_MASK                                                     (0x007f0000U)

#define CTRL_DISPPLL_MN2DIV_M_SHIFT                                                     (0U)
#define CTRL_DISPPLL_MN2DIV_M_MASK                                                      (0x00000fffU)

#define CTRL_DISPPLL_MN2DIV_N2_SHIFT                                                    (16U)
#define CTRL_DISPPLL_MN2DIV_N2_MASK                                                     (0x000f0000U)

#define CTRL_DISPPLL_FRACDIV_FRACTIONALM_SHIFT                                          (0U)
#define CTRL_DISPPLL_FRACDIV_FRACTIONALM_MASK                                           (0x0003ffffU)

#define CTRL_DISPPLL_FRACDIV_REGSD_SHIFT                                                (24U)
#define CTRL_DISPPLL_FRACDIV_REGSD_MASK                                                 (0xff000000U)

#define CTRL_DISPPLL_BWCTRL_SHIFT                                                       (1U)
#define CTRL_DISPPLL_BWCTRL_MASK                                                        (0x00000006U)

#define CTRL_DISPPLL_FRACCTRL_DELTAMSTEPFRACTION_SHIFT                                  (0U)
#define CTRL_DISPPLL_FRACCTRL_DELTAMSTEPFRACTION_MASK                                   (0x0003ffffU)

#define CTRL_DISPPLL_FRACCTRL_DELTAMSTEPINTEGER_SHIFT                                   (18U)
#define CTRL_DISPPLL_FRACCTRL_DELTAMSTEPINTEGER_MASK                                    (0x001c0000U)

#define CTRL_DISPPLL_FRACCTRL_MODFREQDIVIDERMANTISSA_SHIFT                              (21U)
#define CTRL_DISPPLL_FRACCTRL_MODFREQDIVIDERMANTISSA_MASK                               (0x0fe00000U)

#define CTRL_DISPPLL_FRACCTRL_MODFREQDIVIDEREXPONENT_SHIFT                              (28U)
#define CTRL_DISPPLL_FRACCTRL_MODFREQDIVIDEREXPONENT_MASK                               (0x70000000U)

#define CTRL_DISPPLL_FRACCTRL_DOWNSPREAD_SHIFT                                          (31U)
#define CTRL_DISPPLL_FRACCTRL_DOWNSPREAD_MASK                                           (0x80000000U)

#define CTRL_DISPPLL_STS_BYPASS_SHIFT                                                   (0U)
#define CTRL_DISPPLL_STS_BYPASS_MASK                                                    (0x00000001U)

#define CTRL_DISPPLL_STS_HIGHJITTER_SHIFT                                               (1U)
#define CTRL_DISPPLL_STS_HIGHJITTER_MASK                                                (0x00000002U)

#define CTRL_DISPPLL_STS_LIMP_SHIFT                                                     (2U)
#define CTRL_DISPPLL_STS_LIMP_MASK                                                      (0x00000004U)

#define CTRL_DISPPLL_STS_M2CHANGEACK_SHIFT                                              (3U)
#define CTRL_DISPPLL_STS_M2CHANGEACK_MASK                                               (0x00000008U)

#define CTRL_DISPPLL_STS_LOCK2_SHIFT                                                    (4U)
#define CTRL_DISPPLL_STS_LOCK2_MASK                                                     (0x00000010U)

#define CTRL_DISPPLL_STS_CLKOUTACK_SHIFT                                                (5U)
#define CTRL_DISPPLL_STS_CLKOUTACK_MASK                                                 (0x00000020U)

#define CTRL_DISPPLL_STS_LOSSREF_SHIFT                                                  (6U)
#define CTRL_DISPPLL_STS_LOSSREF_MASK                                                   (0x00000040U)

#define CTRL_DISPPLL_STS_STBYRETACK_SHIFT                                               (7U)
#define CTRL_DISPPLL_STS_STBYRETACK_MASK                                                (0x00000080U)

#define CTRL_DISPPLL_STS_BYPASSACK_SHIFT                                                (8U)
#define CTRL_DISPPLL_STS_BYPASSACK_MASK                                                 (0x00000100U)

#define CTRL_DISPPLL_STS_FREQLOCK_SHIFT                                                 (9U)
#define CTRL_DISPPLL_STS_FREQLOCK_MASK                                                  (0x00000200U)

#define CTRL_DISPPLL_STS_PHASELOCK_SHIFT                                                (10U)
#define CTRL_DISPPLL_STS_PHASELOCK_MASK                                                 (0x00000400U)

#define CTRL_DISPPLL_STS_RECAL_PIN_SHIFT                                                (27U)
#define CTRL_DISPPLL_STS_RECAL_PIN_MASK                                                 (0x08000000U)

#define CTRL_DISPPLL_STS_RECAL_BSTS3_SHIFT                                              (28U)
#define CTRL_DISPPLL_STS_RECAL_BSTS3_MASK                                               (0x10000000U)

#define CTRL_DISPPLL_STS_LDOPWDN_SHIFT                                                  (29U)
#define CTRL_DISPPLL_STS_LDOPWDN_MASK                                                   (0x20000000U)

#define CTRL_DISPPLL_STS_SSACK_SHIFT                                                    (30U)
#define CTRL_DISPPLL_STS_SSACK_MASK                                                     (0x40000000U)

#define CTRL_DISPPLL_M3DIV_M3_SHIFT                                                     (0U)
#define CTRL_DISPPLL_M3DIV_M3_MASK                                                      (0x0000001fU)

#define CTRL_DISPPLL_RAMPCTRL_RELOCK_RAMP_EN_SHIFT                                      (0U)
#define CTRL_DISPPLL_RAMPCTRL_RELOCK_RAMP_EN_MASK                                       (0x00000001U)

#define CTRL_DISPPLL_RAMPCTRL_CLKRAMPRATE_SHIFT                                         (16U)
#define CTRL_DISPPLL_RAMPCTRL_CLKRAMPRATE_MASK                                          (0x00070000U)

#define CTRL_DISPPLL_RAMPCTRL_CLKRAMPLEVEL_SHIFT                                        (19U)
#define CTRL_DISPPLL_RAMPCTRL_CLKRAMPLEVEL_MASK                                         (0x00180000U)

#define CTRL_CONF_GPMC_AD0_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD0_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD0_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD0_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD0_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD0_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD0_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD0_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD0_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD0_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD0_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD0_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD0_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD0_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD0_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD0_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD0_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD0_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD0_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD0_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD0_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD0_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD0_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD0_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD0_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD0_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD1_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD1_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD1_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD1_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD1_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD1_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD1_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD1_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD1_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD1_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD1_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD1_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD1_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD1_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD1_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD1_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD1_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD1_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD1_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD1_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD1_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD1_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD1_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD1_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD1_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD1_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD2_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD2_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD2_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD2_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD2_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD2_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD2_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD2_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD2_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD2_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD2_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD2_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD2_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD2_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD2_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD2_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD2_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD2_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD2_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD2_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD2_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD2_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD2_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD2_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD2_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD2_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD3_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD3_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD3_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD3_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD3_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD3_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD3_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD3_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD3_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD3_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD3_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD3_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD3_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD3_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD3_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD3_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD3_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD3_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD3_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD3_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD3_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD3_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD3_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD3_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD3_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD3_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD4_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD4_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD4_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD4_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD4_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD4_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD4_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD4_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD4_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD4_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD4_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD4_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD4_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD4_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD4_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD4_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD4_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD4_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD4_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD4_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD4_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD4_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD4_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD4_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD4_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD4_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD5_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD5_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD5_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD5_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD5_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD5_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD5_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD5_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD5_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD5_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD5_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD5_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD5_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD5_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD5_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD5_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD5_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD5_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD5_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD5_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD5_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD5_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD5_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD5_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD5_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD5_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD6_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD6_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD6_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD6_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD6_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD6_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD6_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD6_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD6_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD6_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD6_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD6_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD6_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD6_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD6_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD6_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD6_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD6_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD6_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD6_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD6_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD6_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD6_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD6_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD6_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD6_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD7_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD7_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD7_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD7_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD7_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD7_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD7_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD7_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD7_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD7_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD7_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD7_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD7_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD7_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD7_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD7_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD7_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD7_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD7_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD7_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD7_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD7_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD7_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD7_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD7_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD7_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD8_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD8_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD8_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD8_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD8_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD8_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD8_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD8_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD8_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD8_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD8_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD8_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD8_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD8_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD8_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD8_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD8_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD8_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD8_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD8_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD8_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD8_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD8_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD8_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD8_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD8_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD9_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_AD9_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_AD9_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_AD9_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_AD9_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_AD9_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_AD9_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_AD9_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_AD9_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_AD9_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_AD9_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_AD9_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_AD9_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_AD9_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_AD9_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_AD9_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_AD9_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_AD9_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_AD9_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_AD9_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_AD9_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_AD9_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_AD9_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_AD9_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_AD9_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_AD9_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_AD10_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD10_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD10_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD10_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD10_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD10_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD10_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD10_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD10_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD10_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD10_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD10_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD10_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD10_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD10_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD10_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD10_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD10_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD10_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD10_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD10_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD10_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD10_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD10_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD10_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD10_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_AD11_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD11_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD11_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD11_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD11_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD11_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD11_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD11_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD11_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD11_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD11_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD11_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD11_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD11_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD11_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD11_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD11_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD11_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD11_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD11_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD11_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD11_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD11_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD11_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD11_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD11_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_AD12_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD12_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD12_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD12_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD12_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD12_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD12_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD12_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD12_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD12_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD12_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD12_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD12_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD12_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD12_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD12_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD12_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD12_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD12_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD12_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD12_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD12_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD12_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD12_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD12_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD12_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_AD13_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD13_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD13_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD13_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD13_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD13_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD13_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD13_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD13_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD13_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD13_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD13_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD13_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD13_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD13_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD13_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD13_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD13_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD13_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD13_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD13_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD13_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD13_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD13_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD13_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD13_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_AD14_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD14_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD14_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD14_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD14_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD14_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD14_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD14_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD14_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD14_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD14_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD14_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD14_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD14_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD14_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD14_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD14_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD14_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD14_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD14_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD14_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD14_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD14_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD14_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD14_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD14_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_AD15_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_AD15_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_AD15_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_AD15_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_AD15_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_AD15_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_AD15_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_AD15_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_AD15_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_AD15_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_AD15_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_AD15_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_AD15_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_AD15_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_AD15_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_AD15_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_AD15_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_AD15_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_AD15_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_AD15_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_AD15_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_AD15_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_AD15_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_AD15_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_AD15_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_AD15_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_A0_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A0_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A0_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A0_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A0_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A0_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A0_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A0_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A0_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A0_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A0_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A0_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A0_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A0_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A0_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A0_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A0_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A0_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A0_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A0_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A0_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A0_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A0_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A0_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A0_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A0_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A1_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A1_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A1_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A1_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A1_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A1_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A1_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A1_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A1_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A1_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A1_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A1_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A1_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A1_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A1_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A1_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A1_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A1_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A1_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A1_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A1_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A1_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A1_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A1_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A1_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A1_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A2_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A2_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A2_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A2_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A2_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A2_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A2_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A2_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A2_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A2_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A2_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A2_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A2_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A2_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A2_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A2_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A2_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A2_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A2_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A2_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A2_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A2_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A2_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A2_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A2_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A2_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A3_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A3_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A3_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A3_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A3_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A3_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A3_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A3_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A3_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A3_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A3_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A3_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A3_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A3_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A3_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A3_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A3_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A3_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A3_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A3_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A3_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A3_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A3_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A3_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A3_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A3_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A4_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A4_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A4_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A4_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A4_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A4_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A4_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A4_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A4_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A4_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A4_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A4_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A4_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A4_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A4_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A4_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A4_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A4_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A4_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A4_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A4_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A4_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A4_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A4_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A4_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A4_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A5_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A5_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A5_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A5_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A5_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A5_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A5_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A5_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A5_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A5_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A5_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A5_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A5_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A5_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A5_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A5_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A5_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A5_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A5_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A5_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A5_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A5_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A5_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A5_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A5_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A5_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A6_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A6_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A6_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A6_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A6_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A6_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A6_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A6_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A6_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A6_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A6_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A6_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A6_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A6_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A6_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A6_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A6_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A6_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A6_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A6_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A6_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A6_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A6_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A6_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A6_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A6_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A7_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A7_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A7_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A7_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A7_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A7_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A7_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A7_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A7_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A7_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A7_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A7_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A7_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A7_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A7_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A7_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A7_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A7_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A7_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A7_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A7_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A7_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A7_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A7_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A7_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A7_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A8_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A8_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A8_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A8_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A8_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A8_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A8_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A8_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A8_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A8_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A8_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A8_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A8_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A8_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A8_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A8_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A8_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A8_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A8_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A8_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A8_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A8_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A8_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A8_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A8_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A8_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A9_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_GPMC_A9_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_GPMC_A9_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_GPMC_A9_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_GPMC_A9_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_GPMC_A9_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_GPMC_A9_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_GPMC_A9_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_GPMC_A9_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_GPMC_A9_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_GPMC_A9_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_GPMC_A9_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_GPMC_A9_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_GPMC_A9_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_GPMC_A9_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_GPMC_A9_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_GPMC_A9_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_GPMC_A9_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_GPMC_A9_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_GPMC_A9_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_GPMC_A9_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_GPMC_A9_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_GPMC_A9_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_GPMC_A9_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_GPMC_A9_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_GPMC_A9_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_GPMC_A10_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_A10_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_A10_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_A10_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_A10_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_A10_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_A10_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_A10_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_A10_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_A10_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_A10_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_A10_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_A10_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_A10_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_A10_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_A10_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_A10_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_A10_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_A10_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_A10_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_A10_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_A10_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_A10_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_A10_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_A10_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_A10_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_A11_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_A11_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_A11_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_A11_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_A11_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_A11_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_A11_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_A11_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_A11_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_A11_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_A11_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_A11_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_A11_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_A11_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_A11_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_A11_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_A11_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_A11_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_A11_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_A11_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_A11_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_A11_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_A11_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_A11_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_A11_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_A11_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_WAIT0_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_GPMC_WAIT0_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_GPMC_WAIT0_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_GPMC_WAIT0_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_GPMC_WAIT0_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_GPMC_WAIT0_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_GPMC_WAIT0_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_GPMC_WAIT0_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_GPMC_WAIT0_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_GPMC_WAIT0_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_GPMC_WAIT0_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_GPMC_WAIT0_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_GPMC_WAIT0_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_GPMC_WAIT0_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_GPMC_WAIT0_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_GPMC_WAIT0_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_GPMC_WAIT0_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_GPMC_WAIT0_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_GPMC_WAIT0_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_GPMC_WAIT0_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_GPMC_WAIT0_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_GPMC_WAIT0_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_GPMC_WAIT0_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_GPMC_WAIT0_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_GPMC_WAIT0_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_GPMC_WAIT0_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_GPMC_WPN_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_WPN_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_WPN_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_WPN_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_WPN_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_WPN_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_WPN_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_WPN_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_WPN_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_WPN_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_WPN_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_WPN_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_WPN_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_WPN_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_WPN_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_WPN_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_WPN_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_WPN_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_WPN_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_WPN_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_WPN_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_WPN_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_WPN_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_WPN_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_WPN_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_WPN_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_BE1N_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_BE1N_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_BE1N_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_BE1N_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_BE1N_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_BE1N_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_BE1N_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_BE1N_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_BE1N_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_BE1N_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_BE1N_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_BE1N_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_BE1N_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_BE1N_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_BE1N_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_BE1N_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_BE1N_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_BE1N_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_BE1N_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_BE1N_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_BE1N_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_BE1N_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_BE1N_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_BE1N_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_BE1N_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_BE1N_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_CSN0_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_CSN0_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_CSN0_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_CSN0_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_CSN0_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_CSN0_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_CSN0_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_CSN0_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_CSN0_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_CSN0_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_CSN0_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_CSN0_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_CSN0_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_CSN0_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_CSN0_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_CSN0_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_CSN0_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_CSN0_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_CSN0_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_CSN0_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_CSN0_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_CSN0_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_CSN0_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_CSN0_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_CSN0_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_CSN0_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_CSN1_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_CSN1_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_CSN1_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_CSN1_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_CSN1_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_CSN1_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_CSN1_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_CSN1_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_CSN1_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_CSN1_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_CSN1_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_CSN1_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_CSN1_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_CSN1_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_CSN1_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_CSN1_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_CSN1_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_CSN1_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_CSN1_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_CSN1_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_CSN1_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_CSN1_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_CSN1_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_CSN1_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_CSN1_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_CSN1_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_CSN2_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_CSN2_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_CSN2_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_CSN2_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_CSN2_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_CSN2_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_CSN2_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_CSN2_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_CSN2_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_CSN2_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_CSN2_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_CSN2_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_CSN2_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_CSN2_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_CSN2_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_CSN2_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_CSN2_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_CSN2_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_CSN2_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_CSN2_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_CSN2_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_CSN2_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_CSN2_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_CSN2_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_CSN2_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_CSN2_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_CSN3_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_GPMC_CSN3_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_GPMC_CSN3_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_GPMC_CSN3_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_GPMC_CSN3_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_GPMC_CSN3_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_GPMC_CSN3_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_GPMC_CSN3_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_GPMC_CSN3_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_GPMC_CSN3_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_GPMC_CSN3_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_GPMC_CSN3_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_GPMC_CSN3_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_GPMC_CSN3_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_GPMC_CSN3_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_GPMC_CSN3_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_GPMC_CSN3_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_GPMC_CSN3_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_GPMC_CSN3_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_GPMC_CSN3_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_GPMC_CSN3_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_GPMC_CSN3_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_GPMC_CSN3_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_GPMC_CSN3_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_GPMC_CSN3_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_GPMC_CSN3_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_GPMC_CLK_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_CLK_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_CLK_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_CLK_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_CLK_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_CLK_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_CLK_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_CLK_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_CLK_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_CLK_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_CLK_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_CLK_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_CLK_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_CLK_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_CLK_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_CLK_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_CLK_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_CLK_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_CLK_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_CLK_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_CLK_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_CLK_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_CLK_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_CLK_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_CLK_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_CLK_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_ADVN_ALE_LOCK_SHIFT                                              (31U)
#define CTRL_CONF_GPMC_ADVN_ALE_LOCK_MASK                                               (0x80000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_WUEVT_SHIFT                                             (30U)
#define CTRL_CONF_GPMC_ADVN_ALE_WUEVT_MASK                                              (0x40000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_WUEN_SHIFT                                              (29U)
#define CTRL_CONF_GPMC_ADVN_ALE_WUEN_MASK                                               (0x20000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_DSPULLTYPESELECT_SHIFT                                  (28U)
#define CTRL_CONF_GPMC_ADVN_ALE_DSPULLTYPESELECT_MASK                                   (0x10000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_DSPULLUDEN_SHIFT                                        (27U)
#define CTRL_CONF_GPMC_ADVN_ALE_DSPULLUDEN_MASK                                         (0x08000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_DS0OUTVALUE_SHIFT                                       (26U)
#define CTRL_CONF_GPMC_ADVN_ALE_DS0OUTVALUE_MASK                                        (0x04000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_DS0OUTEN_SHIFT                                          (25U)
#define CTRL_CONF_GPMC_ADVN_ALE_DS0OUTEN_MASK                                           (0x02000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_DS0EN_SHIFT                                             (24U)
#define CTRL_CONF_GPMC_ADVN_ALE_DS0EN_MASK                                              (0x01000000U)

#define CTRL_CONF_GPMC_ADVN_ALE_SLEWCTRL_SHIFT                                          (19U)
#define CTRL_CONF_GPMC_ADVN_ALE_SLEWCTRL_MASK                                           (0x00080000U)

#define CTRL_CONF_GPMC_ADVN_ALE_RXACTIVE_SHIFT                                          (18U)
#define CTRL_CONF_GPMC_ADVN_ALE_RXACTIVE_MASK                                           (0x00040000U)

#define CTRL_CONF_GPMC_ADVN_ALE_PUTYPESEL_SHIFT                                         (17U)
#define CTRL_CONF_GPMC_ADVN_ALE_PUTYPESEL_MASK                                          (0x00020000U)

#define CTRL_CONF_GPMC_ADVN_ALE_PUDEN_SHIFT                                             (16U)
#define CTRL_CONF_GPMC_ADVN_ALE_PUDEN_MASK                                              (0x00010000U)

#define CTRL_CONF_GPMC_ADVN_ALE_MMODE_SHIFT                                             (0U)
#define CTRL_CONF_GPMC_ADVN_ALE_MMODE_MASK                                              (0x0000000fU)

#define CTRL_CONF_GPMC_OEN_REN_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_GPMC_OEN_REN_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_GPMC_OEN_REN_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_GPMC_OEN_REN_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_GPMC_OEN_REN_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_GPMC_OEN_REN_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_GPMC_OEN_REN_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_GPMC_OEN_REN_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_GPMC_OEN_REN_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_GPMC_OEN_REN_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_GPMC_OEN_REN_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_GPMC_OEN_REN_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_GPMC_OEN_REN_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_GPMC_OEN_REN_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_GPMC_OEN_REN_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_GPMC_OEN_REN_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_GPMC_OEN_REN_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_GPMC_OEN_REN_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_GPMC_OEN_REN_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_GPMC_OEN_REN_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_GPMC_OEN_REN_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_GPMC_OEN_REN_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_GPMC_OEN_REN_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_GPMC_OEN_REN_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_GPMC_OEN_REN_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_GPMC_OEN_REN_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_GPMC_WEN_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_GPMC_WEN_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_GPMC_WEN_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_GPMC_WEN_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_GPMC_WEN_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_GPMC_WEN_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_GPMC_WEN_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_GPMC_WEN_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_GPMC_WEN_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_GPMC_WEN_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_GPMC_WEN_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_GPMC_WEN_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_GPMC_WEN_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_GPMC_WEN_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_GPMC_WEN_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_GPMC_WEN_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_GPMC_WEN_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_GPMC_WEN_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_GPMC_WEN_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_GPMC_WEN_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_GPMC_WEN_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_GPMC_WEN_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_GPMC_WEN_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_GPMC_WEN_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_GPMC_WEN_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_GPMC_WEN_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_GPMC_BE0N_CLE_LOCK_SHIFT                                              (31U)
#define CTRL_CONF_GPMC_BE0N_CLE_LOCK_MASK                                               (0x80000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_WUEVT_SHIFT                                             (30U)
#define CTRL_CONF_GPMC_BE0N_CLE_WUEVT_MASK                                              (0x40000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_WUEN_SHIFT                                              (29U)
#define CTRL_CONF_GPMC_BE0N_CLE_WUEN_MASK                                               (0x20000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_DSPULLTYPESELECT_SHIFT                                  (28U)
#define CTRL_CONF_GPMC_BE0N_CLE_DSPULLTYPESELECT_MASK                                   (0x10000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_DSPULLUDEN_SHIFT                                        (27U)
#define CTRL_CONF_GPMC_BE0N_CLE_DSPULLUDEN_MASK                                         (0x08000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_DS0OUTVALUE_SHIFT                                       (26U)
#define CTRL_CONF_GPMC_BE0N_CLE_DS0OUTVALUE_MASK                                        (0x04000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_DS0OUTEN_SHIFT                                          (25U)
#define CTRL_CONF_GPMC_BE0N_CLE_DS0OUTEN_MASK                                           (0x02000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_DS0EN_SHIFT                                             (24U)
#define CTRL_CONF_GPMC_BE0N_CLE_DS0EN_MASK                                              (0x01000000U)

#define CTRL_CONF_GPMC_BE0N_CLE_SLEWCTRL_SHIFT                                          (19U)
#define CTRL_CONF_GPMC_BE0N_CLE_SLEWCTRL_MASK                                           (0x00080000U)

#define CTRL_CONF_GPMC_BE0N_CLE_RXACTIVE_SHIFT                                          (18U)
#define CTRL_CONF_GPMC_BE0N_CLE_RXACTIVE_MASK                                           (0x00040000U)

#define CTRL_CONF_GPMC_BE0N_CLE_PUTYPESEL_SHIFT                                         (17U)
#define CTRL_CONF_GPMC_BE0N_CLE_PUTYPESEL_MASK                                          (0x00020000U)

#define CTRL_CONF_GPMC_BE0N_CLE_PUDEN_SHIFT                                             (16U)
#define CTRL_CONF_GPMC_BE0N_CLE_PUDEN_MASK                                              (0x00010000U)

#define CTRL_CONF_GPMC_BE0N_CLE_MMODE_SHIFT                                             (0U)
#define CTRL_CONF_GPMC_BE0N_CLE_MMODE_MASK                                              (0x0000000fU)

#define CTRL_CONF_LCD_DATA0_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA0_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA0_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA0_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA0_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA0_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA0_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA0_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA0_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA0_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA0_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA0_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA0_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA0_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA0_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA0_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA0_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA0_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA0_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA0_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA0_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA0_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA0_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA0_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA0_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA0_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA1_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA1_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA1_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA1_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA1_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA1_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA1_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA1_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA1_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA1_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA1_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA1_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA1_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA1_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA1_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA1_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA1_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA1_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA1_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA1_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA1_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA1_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA1_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA1_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA1_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA1_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA2_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA2_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA2_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA2_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA2_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA2_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA2_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA2_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA2_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA2_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA2_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA2_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA2_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA2_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA2_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA2_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA2_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA2_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA2_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA2_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA2_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA2_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA2_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA2_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA2_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA2_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA3_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA3_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA3_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA3_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA3_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA3_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA3_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA3_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA3_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA3_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA3_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA3_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA3_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA3_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA3_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA3_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA3_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA3_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA3_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA3_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA3_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA3_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA3_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA3_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA3_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA3_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA4_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA4_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA4_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA4_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA4_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA4_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA4_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA4_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA4_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA4_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA4_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA4_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA4_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA4_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA4_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA4_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA4_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA4_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA4_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA4_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA4_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA4_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA4_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA4_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA4_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA4_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA5_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA5_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA5_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA5_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA5_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA5_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA5_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA5_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA5_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA5_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA5_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA5_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA5_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA5_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA5_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA5_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA5_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA5_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA5_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA5_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA5_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA5_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA5_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA5_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA5_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA5_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA6_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA6_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA6_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA6_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA6_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA6_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA6_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA6_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA6_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA6_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA6_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA6_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA6_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA6_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA6_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA6_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA6_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA6_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA6_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA6_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA6_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA6_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA6_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA6_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA6_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA6_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA7_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA7_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA7_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA7_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA7_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA7_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA7_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA7_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA7_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA7_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA7_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA7_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA7_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA7_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA7_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA7_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA7_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA7_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA7_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA7_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA7_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA7_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA7_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA7_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA7_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA7_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA8_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA8_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA8_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA8_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA8_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA8_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA8_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA8_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA8_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA8_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA8_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA8_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA8_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA8_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA8_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA8_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA8_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA8_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA8_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA8_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA8_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA8_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA8_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA8_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA8_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA8_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA9_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_DATA9_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_DATA9_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_DATA9_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_DATA9_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_DATA9_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_DATA9_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_DATA9_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_DATA9_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_DATA9_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_DATA9_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_DATA9_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_DATA9_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_DATA9_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_DATA9_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_DATA9_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_DATA9_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_DATA9_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_DATA9_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_DATA9_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_DATA9_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_DATA9_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_DATA9_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_DATA9_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_DATA9_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_DATA9_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_DATA10_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA10_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA10_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA10_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA10_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA10_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA10_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA10_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA10_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA10_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA10_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA10_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA10_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA10_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA10_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA10_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA10_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA10_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA10_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA10_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA10_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA10_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA10_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA10_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA10_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA10_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_DATA11_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA11_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA11_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA11_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA11_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA11_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA11_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA11_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA11_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA11_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA11_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA11_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA11_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA11_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA11_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA11_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA11_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA11_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA11_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA11_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA11_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA11_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA11_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA11_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA11_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA11_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_DATA12_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA12_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA12_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA12_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA12_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA12_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA12_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA12_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA12_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA12_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA12_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA12_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA12_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA12_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA12_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA12_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA12_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA12_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA12_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA12_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA12_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA12_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA12_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA12_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA12_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA12_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_DATA13_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA13_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA13_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA13_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA13_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA13_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA13_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA13_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA13_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA13_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA13_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA13_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA13_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA13_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA13_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA13_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA13_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA13_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA13_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA13_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA13_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA13_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA13_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA13_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA13_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA13_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_DATA14_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA14_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA14_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA14_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA14_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA14_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA14_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA14_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA14_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA14_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA14_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA14_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA14_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA14_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA14_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA14_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA14_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA14_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA14_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA14_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA14_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA14_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA14_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA14_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA14_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA14_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_DATA15_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_LCD_DATA15_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_LCD_DATA15_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_LCD_DATA15_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_LCD_DATA15_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_LCD_DATA15_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_LCD_DATA15_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_LCD_DATA15_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_LCD_DATA15_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_LCD_DATA15_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_LCD_DATA15_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_LCD_DATA15_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_LCD_DATA15_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_LCD_DATA15_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_LCD_DATA15_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_LCD_DATA15_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_LCD_DATA15_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_LCD_DATA15_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_LCD_DATA15_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_LCD_DATA15_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_LCD_DATA15_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_LCD_DATA15_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_LCD_DATA15_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_LCD_DATA15_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_LCD_DATA15_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_LCD_DATA15_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_LCD_VSYNC_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_VSYNC_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_VSYNC_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_VSYNC_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_VSYNC_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_VSYNC_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_VSYNC_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_VSYNC_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_VSYNC_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_VSYNC_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_VSYNC_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_VSYNC_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_VSYNC_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_VSYNC_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_VSYNC_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_VSYNC_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_VSYNC_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_VSYNC_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_VSYNC_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_VSYNC_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_VSYNC_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_VSYNC_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_VSYNC_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_VSYNC_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_VSYNC_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_VSYNC_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_HSYNC_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_LCD_HSYNC_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_LCD_HSYNC_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_LCD_HSYNC_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_LCD_HSYNC_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_LCD_HSYNC_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_LCD_HSYNC_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_LCD_HSYNC_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_LCD_HSYNC_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_LCD_HSYNC_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_LCD_HSYNC_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_LCD_HSYNC_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_LCD_HSYNC_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_LCD_HSYNC_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_LCD_HSYNC_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_LCD_HSYNC_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_LCD_HSYNC_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_LCD_HSYNC_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_LCD_HSYNC_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_LCD_HSYNC_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_LCD_HSYNC_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_LCD_HSYNC_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_LCD_HSYNC_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_LCD_HSYNC_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_LCD_HSYNC_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_LCD_HSYNC_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_LCD_PCLK_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_LCD_PCLK_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_LCD_PCLK_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_LCD_PCLK_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_LCD_PCLK_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_LCD_PCLK_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_LCD_PCLK_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_LCD_PCLK_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_LCD_PCLK_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_LCD_PCLK_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_LCD_PCLK_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_LCD_PCLK_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_LCD_PCLK_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_LCD_PCLK_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_LCD_PCLK_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_LCD_PCLK_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_LCD_PCLK_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_LCD_PCLK_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_LCD_PCLK_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_LCD_PCLK_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_LCD_PCLK_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_LCD_PCLK_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_LCD_PCLK_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_LCD_PCLK_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_LCD_PCLK_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_LCD_PCLK_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_LCD_AC_BIAS_EN_LOCK_SHIFT                                             (31U)
#define CTRL_CONF_LCD_AC_BIAS_EN_LOCK_MASK                                              (0x80000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_WUEVT_SHIFT                                            (30U)
#define CTRL_CONF_LCD_AC_BIAS_EN_WUEVT_MASK                                             (0x40000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_WUEN_SHIFT                                             (29U)
#define CTRL_CONF_LCD_AC_BIAS_EN_WUEN_MASK                                              (0x20000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_DSPULLTYPESELECT_SHIFT                                 (28U)
#define CTRL_CONF_LCD_AC_BIAS_EN_DSPULLTYPESELECT_MASK                                  (0x10000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_DSPULLUDEN_SHIFT                                       (27U)
#define CTRL_CONF_LCD_AC_BIAS_EN_DSPULLUDEN_MASK                                        (0x08000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_DS0OUTVALUE_SHIFT                                      (26U)
#define CTRL_CONF_LCD_AC_BIAS_EN_DS0OUTVALUE_MASK                                       (0x04000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_DS0OUTEN_SHIFT                                         (25U)
#define CTRL_CONF_LCD_AC_BIAS_EN_DS0OUTEN_MASK                                          (0x02000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_DS0EN_SHIFT                                            (24U)
#define CTRL_CONF_LCD_AC_BIAS_EN_DS0EN_MASK                                             (0x01000000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_SLEWCTRL_SHIFT                                         (19U)
#define CTRL_CONF_LCD_AC_BIAS_EN_SLEWCTRL_MASK                                          (0x00080000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_RXACTIVE_SHIFT                                         (18U)
#define CTRL_CONF_LCD_AC_BIAS_EN_RXACTIVE_MASK                                          (0x00040000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_PUTYPESEL_SHIFT                                        (17U)
#define CTRL_CONF_LCD_AC_BIAS_EN_PUTYPESEL_MASK                                         (0x00020000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_PUDEN_SHIFT                                            (16U)
#define CTRL_CONF_LCD_AC_BIAS_EN_PUDEN_MASK                                             (0x00010000U)

#define CTRL_CONF_LCD_AC_BIAS_EN_MMODE_SHIFT                                            (0U)
#define CTRL_CONF_LCD_AC_BIAS_EN_MMODE_MASK                                             (0x0000000fU)

#define CTRL_CONF_MMC0_DAT3_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MMC0_DAT3_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MMC0_DAT3_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MMC0_DAT3_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MMC0_DAT3_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MMC0_DAT3_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MMC0_DAT3_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MMC0_DAT3_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MMC0_DAT3_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MMC0_DAT3_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MMC0_DAT3_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MMC0_DAT3_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MMC0_DAT3_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MMC0_DAT3_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MMC0_DAT3_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MMC0_DAT3_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MMC0_DAT3_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MMC0_DAT3_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MMC0_DAT3_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MMC0_DAT3_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MMC0_DAT3_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MMC0_DAT3_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MMC0_DAT3_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MMC0_DAT3_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MMC0_DAT3_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MMC0_DAT3_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MMC0_DAT2_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MMC0_DAT2_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MMC0_DAT2_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MMC0_DAT2_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MMC0_DAT2_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MMC0_DAT2_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MMC0_DAT2_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MMC0_DAT2_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MMC0_DAT2_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MMC0_DAT2_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MMC0_DAT2_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MMC0_DAT2_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MMC0_DAT2_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MMC0_DAT2_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MMC0_DAT2_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MMC0_DAT2_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MMC0_DAT2_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MMC0_DAT2_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MMC0_DAT2_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MMC0_DAT2_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MMC0_DAT2_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MMC0_DAT2_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MMC0_DAT2_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MMC0_DAT2_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MMC0_DAT2_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MMC0_DAT2_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MMC0_DAT1_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MMC0_DAT1_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MMC0_DAT1_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MMC0_DAT1_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MMC0_DAT1_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MMC0_DAT1_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MMC0_DAT1_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MMC0_DAT1_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MMC0_DAT1_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MMC0_DAT1_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MMC0_DAT1_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MMC0_DAT1_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MMC0_DAT1_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MMC0_DAT1_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MMC0_DAT1_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MMC0_DAT1_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MMC0_DAT1_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MMC0_DAT1_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MMC0_DAT1_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MMC0_DAT1_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MMC0_DAT1_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MMC0_DAT1_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MMC0_DAT1_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MMC0_DAT1_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MMC0_DAT1_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MMC0_DAT1_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MMC0_DAT0_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MMC0_DAT0_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MMC0_DAT0_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MMC0_DAT0_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MMC0_DAT0_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MMC0_DAT0_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MMC0_DAT0_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MMC0_DAT0_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MMC0_DAT0_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MMC0_DAT0_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MMC0_DAT0_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MMC0_DAT0_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MMC0_DAT0_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MMC0_DAT0_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MMC0_DAT0_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MMC0_DAT0_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MMC0_DAT0_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MMC0_DAT0_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MMC0_DAT0_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MMC0_DAT0_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MMC0_DAT0_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MMC0_DAT0_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MMC0_DAT0_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MMC0_DAT0_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MMC0_DAT0_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MMC0_DAT0_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MMC0_CLK_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_MMC0_CLK_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_MMC0_CLK_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_MMC0_CLK_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_MMC0_CLK_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_MMC0_CLK_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_MMC0_CLK_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_MMC0_CLK_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_MMC0_CLK_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_MMC0_CLK_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_MMC0_CLK_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_MMC0_CLK_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_MMC0_CLK_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_MMC0_CLK_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_MMC0_CLK_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_MMC0_CLK_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_MMC0_CLK_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_MMC0_CLK_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_MMC0_CLK_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_MMC0_CLK_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_MMC0_CLK_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_MMC0_CLK_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_MMC0_CLK_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_MMC0_CLK_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_MMC0_CLK_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_MMC0_CLK_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_MMC0_CMD_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_MMC0_CMD_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_MMC0_CMD_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_MMC0_CMD_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_MMC0_CMD_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_MMC0_CMD_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_MMC0_CMD_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_MMC0_CMD_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_MMC0_CMD_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_MMC0_CMD_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_MMC0_CMD_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_MMC0_CMD_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_MMC0_CMD_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_MMC0_CMD_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_MMC0_CMD_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_MMC0_CMD_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_MMC0_CMD_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_MMC0_CMD_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_MMC0_CMD_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_MMC0_CMD_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_MMC0_CMD_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_MMC0_CMD_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_MMC0_CMD_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_MMC0_CMD_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_MMC0_CMD_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_MMC0_CMD_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_MII1_COL_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_MII1_COL_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_MII1_COL_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_MII1_COL_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_MII1_COL_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_MII1_COL_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_MII1_COL_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_MII1_COL_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_MII1_COL_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_MII1_COL_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_MII1_COL_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_MII1_COL_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_MII1_COL_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_MII1_COL_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_MII1_COL_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_MII1_COL_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_MII1_COL_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_MII1_COL_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_MII1_COL_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_MII1_COL_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_MII1_COL_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_MII1_COL_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_MII1_COL_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_MII1_COL_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_MII1_COL_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_MII1_COL_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_MII1_CRS_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_MII1_CRS_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_MII1_CRS_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_MII1_CRS_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_MII1_CRS_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_MII1_CRS_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_MII1_CRS_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_MII1_CRS_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_MII1_CRS_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_MII1_CRS_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_MII1_CRS_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_MII1_CRS_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_MII1_CRS_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_MII1_CRS_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_MII1_CRS_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_MII1_CRS_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_MII1_CRS_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_MII1_CRS_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_MII1_CRS_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_MII1_CRS_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_MII1_CRS_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_MII1_CRS_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_MII1_CRS_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_MII1_CRS_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_MII1_CRS_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_MII1_CRS_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_MII1_RXERR_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_MII1_RXERR_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_MII1_RXERR_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_MII1_RXERR_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_MII1_RXERR_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_MII1_RXERR_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_MII1_RXERR_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_MII1_RXERR_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_MII1_RXERR_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_MII1_RXERR_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_MII1_RXERR_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_MII1_RXERR_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_MII1_RXERR_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_MII1_RXERR_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_MII1_RXERR_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_MII1_RXERR_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_MII1_RXERR_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_MII1_RXERR_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_MII1_RXERR_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_MII1_RXERR_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_MII1_RXERR_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_MII1_RXERR_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_MII1_RXERR_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_MII1_RXERR_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_MII1_RXERR_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_MII1_RXERR_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_MII1_TXEN_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_TXEN_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_TXEN_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_TXEN_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_TXEN_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_TXEN_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_TXEN_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_TXEN_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_TXEN_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_TXEN_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_TXEN_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_TXEN_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_TXEN_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_TXEN_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_TXEN_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_TXEN_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_TXEN_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_TXEN_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_TXEN_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_TXEN_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_TXEN_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_TXEN_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_TXEN_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_TXEN_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_TXEN_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_TXEN_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_RXDV_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_RXDV_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_RXDV_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_RXDV_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_RXDV_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_RXDV_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_RXDV_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_RXDV_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_RXDV_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_RXDV_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_RXDV_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_RXDV_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_RXDV_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_RXDV_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_RXDV_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_RXDV_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_RXDV_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_RXDV_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_RXDV_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_RXDV_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_RXDV_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_RXDV_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_RXDV_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_RXDV_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_RXDV_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_RXDV_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_TXD3_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_TXD3_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_TXD3_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_TXD3_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_TXD3_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_TXD3_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_TXD3_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_TXD3_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_TXD3_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_TXD3_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_TXD3_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_TXD3_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_TXD3_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_TXD3_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_TXD3_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_TXD3_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_TXD3_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_TXD3_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_TXD3_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_TXD3_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_TXD3_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_TXD3_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_TXD3_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_TXD3_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_TXD3_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_TXD3_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_TXD2_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_TXD2_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_TXD2_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_TXD2_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_TXD2_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_TXD2_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_TXD2_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_TXD2_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_TXD2_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_TXD2_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_TXD2_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_TXD2_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_TXD2_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_TXD2_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_TXD2_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_TXD2_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_TXD2_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_TXD2_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_TXD2_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_TXD2_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_TXD2_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_TXD2_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_TXD2_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_TXD2_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_TXD2_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_TXD2_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_TXD1_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_TXD1_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_TXD1_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_TXD1_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_TXD1_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_TXD1_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_TXD1_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_TXD1_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_TXD1_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_TXD1_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_TXD1_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_TXD1_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_TXD1_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_TXD1_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_TXD1_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_TXD1_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_TXD1_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_TXD1_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_TXD1_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_TXD1_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_TXD1_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_TXD1_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_TXD1_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_TXD1_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_TXD1_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_TXD1_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_TXD0_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_TXD0_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_TXD0_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_TXD0_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_TXD0_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_TXD0_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_TXD0_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_TXD0_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_TXD0_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_TXD0_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_TXD0_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_TXD0_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_TXD0_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_TXD0_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_TXD0_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_TXD0_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_TXD0_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_TXD0_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_TXD0_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_TXD0_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_TXD0_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_TXD0_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_TXD0_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_TXD0_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_TXD0_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_TXD0_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_TXCLK_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_MII1_TXCLK_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_MII1_TXCLK_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_MII1_TXCLK_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_MII1_TXCLK_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_MII1_TXCLK_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_MII1_TXCLK_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_MII1_TXCLK_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_MII1_TXCLK_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_MII1_TXCLK_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_MII1_TXCLK_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_MII1_TXCLK_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_MII1_TXCLK_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_MII1_TXCLK_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_MII1_TXCLK_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_MII1_TXCLK_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_MII1_TXCLK_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_MII1_TXCLK_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_MII1_TXCLK_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_MII1_TXCLK_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_MII1_TXCLK_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_MII1_TXCLK_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_MII1_TXCLK_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_MII1_TXCLK_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_MII1_TXCLK_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_MII1_TXCLK_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_MII1_RXCLK_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_MII1_RXCLK_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_MII1_RXCLK_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_MII1_RXCLK_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_MII1_RXCLK_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_MII1_RXCLK_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_MII1_RXCLK_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_MII1_RXCLK_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_MII1_RXCLK_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_MII1_RXCLK_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_MII1_RXCLK_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_MII1_RXCLK_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_MII1_RXCLK_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_MII1_RXCLK_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_MII1_RXCLK_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_MII1_RXCLK_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_MII1_RXCLK_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_MII1_RXCLK_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_MII1_RXCLK_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_MII1_RXCLK_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_MII1_RXCLK_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_MII1_RXCLK_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_MII1_RXCLK_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_MII1_RXCLK_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_MII1_RXCLK_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_MII1_RXCLK_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_MII1_RXD3_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_RXD3_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_RXD3_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_RXD3_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_RXD3_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_RXD3_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_RXD3_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_RXD3_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_RXD3_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_RXD3_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_RXD3_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_RXD3_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_RXD3_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_RXD3_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_RXD3_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_RXD3_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_RXD3_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_RXD3_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_RXD3_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_RXD3_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_RXD3_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_RXD3_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_RXD3_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_RXD3_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_RXD3_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_RXD3_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_RXD2_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_RXD2_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_RXD2_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_RXD2_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_RXD2_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_RXD2_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_RXD2_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_RXD2_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_RXD2_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_RXD2_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_RXD2_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_RXD2_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_RXD2_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_RXD2_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_RXD2_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_RXD2_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_RXD2_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_RXD2_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_RXD2_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_RXD2_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_RXD2_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_RXD2_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_RXD2_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_RXD2_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_RXD2_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_RXD2_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_RXD1_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_RXD1_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_RXD1_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_RXD1_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_RXD1_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_RXD1_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_RXD1_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_RXD1_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_RXD1_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_RXD1_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_RXD1_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_RXD1_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_RXD1_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_RXD1_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_RXD1_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_RXD1_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_RXD1_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_RXD1_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_RXD1_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_RXD1_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_RXD1_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_RXD1_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_RXD1_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_RXD1_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_RXD1_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_RXD1_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MII1_RXD0_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MII1_RXD0_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MII1_RXD0_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MII1_RXD0_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MII1_RXD0_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MII1_RXD0_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MII1_RXD0_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MII1_RXD0_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MII1_RXD0_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MII1_RXD0_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MII1_RXD0_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MII1_RXD0_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MII1_RXD0_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MII1_RXD0_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MII1_RXD0_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MII1_RXD0_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MII1_RXD0_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MII1_RXD0_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MII1_RXD0_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MII1_RXD0_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MII1_RXD0_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MII1_RXD0_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MII1_RXD0_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MII1_RXD0_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MII1_RXD0_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MII1_RXD0_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_RMII1_REFCLK_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_RMII1_REFCLK_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_RMII1_REFCLK_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_RMII1_REFCLK_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_RMII1_REFCLK_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_RMII1_REFCLK_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_RMII1_REFCLK_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_RMII1_REFCLK_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_RMII1_REFCLK_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_RMII1_REFCLK_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_RMII1_REFCLK_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_RMII1_REFCLK_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_RMII1_REFCLK_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_RMII1_REFCLK_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_RMII1_REFCLK_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_RMII1_REFCLK_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_RMII1_REFCLK_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_RMII1_REFCLK_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_RMII1_REFCLK_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_RMII1_REFCLK_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_RMII1_REFCLK_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_RMII1_REFCLK_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_RMII1_REFCLK_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_RMII1_REFCLK_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_RMII1_REFCLK_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_RMII1_REFCLK_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_MDIO_DATA_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_MDIO_DATA_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_MDIO_DATA_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_MDIO_DATA_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_MDIO_DATA_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_MDIO_DATA_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_MDIO_DATA_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_MDIO_DATA_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_MDIO_DATA_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_MDIO_DATA_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_MDIO_DATA_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_MDIO_DATA_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_MDIO_DATA_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_MDIO_DATA_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_MDIO_DATA_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_MDIO_DATA_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_MDIO_DATA_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_MDIO_DATA_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_MDIO_DATA_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_MDIO_DATA_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_MDIO_DATA_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_MDIO_DATA_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_MDIO_DATA_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_MDIO_DATA_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_MDIO_DATA_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_MDIO_DATA_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_MDIO_CLK_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_MDIO_CLK_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_MDIO_CLK_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_MDIO_CLK_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_MDIO_CLK_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_MDIO_CLK_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_MDIO_CLK_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_MDIO_CLK_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_MDIO_CLK_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_MDIO_CLK_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_MDIO_CLK_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_MDIO_CLK_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_MDIO_CLK_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_MDIO_CLK_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_MDIO_CLK_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_MDIO_CLK_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_MDIO_CLK_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_MDIO_CLK_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_MDIO_CLK_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_MDIO_CLK_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_MDIO_CLK_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_MDIO_CLK_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_MDIO_CLK_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_MDIO_CLK_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_MDIO_CLK_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_MDIO_CLK_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_SPI0_SCLK_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_SPI0_SCLK_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_SPI0_SCLK_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_SPI0_SCLK_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_SPI0_SCLK_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_SPI0_SCLK_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_SPI0_SCLK_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_SPI0_SCLK_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_SPI0_SCLK_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_SPI0_SCLK_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_SPI0_SCLK_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_SPI0_SCLK_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_SPI0_SCLK_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_SPI0_SCLK_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_SPI0_SCLK_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_SPI0_SCLK_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_SPI0_SCLK_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_SPI0_SCLK_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_SPI0_SCLK_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_SPI0_SCLK_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_SPI0_SCLK_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_SPI0_SCLK_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_SPI0_SCLK_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_SPI0_SCLK_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_SPI0_SCLK_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_SPI0_SCLK_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_SPI0_D0_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI0_D0_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI0_D0_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI0_D0_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI0_D0_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI0_D0_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI0_D0_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI0_D0_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI0_D0_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI0_D0_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI0_D0_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI0_D0_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI0_D0_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI0_D0_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI0_D0_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI0_D0_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI0_D0_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI0_D0_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI0_D0_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI0_D0_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI0_D0_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI0_D0_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI0_D0_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI0_D0_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI0_D0_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI0_D0_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI0_D1_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI0_D1_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI0_D1_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI0_D1_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI0_D1_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI0_D1_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI0_D1_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI0_D1_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI0_D1_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI0_D1_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI0_D1_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI0_D1_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI0_D1_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI0_D1_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI0_D1_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI0_D1_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI0_D1_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI0_D1_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI0_D1_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI0_D1_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI0_D1_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI0_D1_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI0_D1_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI0_D1_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI0_D1_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI0_D1_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI0_CS0_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_SPI0_CS0_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_SPI0_CS0_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_SPI0_CS0_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_SPI0_CS0_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_SPI0_CS0_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_SPI0_CS0_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_SPI0_CS0_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_SPI0_CS0_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_SPI0_CS0_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_SPI0_CS0_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_SPI0_CS0_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_SPI0_CS0_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_SPI0_CS0_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_SPI0_CS0_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_SPI0_CS0_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_SPI0_CS0_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_SPI0_CS0_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_SPI0_CS0_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_SPI0_CS0_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_SPI0_CS0_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_SPI0_CS0_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_SPI0_CS0_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_SPI0_CS0_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_SPI0_CS0_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_SPI0_CS0_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_SPI0_CS1_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_SPI0_CS1_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_SPI0_CS1_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_SPI0_CS1_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_SPI0_CS1_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_SPI0_CS1_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_SPI0_CS1_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_SPI0_CS1_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_SPI0_CS1_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_SPI0_CS1_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_SPI0_CS1_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_SPI0_CS1_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_LOCK_SHIFT                                          (31U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_LOCK_MASK                                           (0x80000000U)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_SLEWCTRL_SHIFT                                      (19U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_SLEWCTRL_MASK                                       (0x00080000U)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_RXACTIVE_SHIFT                                      (18U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_RXACTIVE_MASK                                       (0x00040000U)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_PUTYPESEL_SHIFT                                     (17U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_PUTYPESEL_MASK                                      (0x00020000U)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_PUDEN_SHIFT                                         (16U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_PUDEN_MASK                                          (0x00010000U)

#define CTRL_CONF_ECAP0_IN_PWM0_OUT_MMODE_SHIFT                                         (0U)
#define CTRL_CONF_ECAP0_IN_PWM0_OUT_MMODE_MASK                                          (0x0000000fU)

#define CTRL_CONF_UART0_CTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART0_CTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART0_CTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART0_CTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART0_CTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART0_CTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART0_CTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART0_CTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART0_CTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART0_CTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART0_CTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART0_CTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART0_CTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART0_CTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART0_CTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART0_CTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART0_CTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART0_CTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART0_CTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART0_CTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART0_CTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART0_CTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART0_CTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART0_CTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART0_CTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART0_CTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_UART0_RTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART0_RTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART0_RTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART0_RTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART0_RTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART0_RTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART0_RTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART0_RTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART0_RTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART0_RTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART0_RTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART0_RTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART0_RTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART0_RTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART0_RTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART0_RTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART0_RTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART0_RTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART0_RTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART0_RTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART0_RTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART0_RTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART0_RTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART0_RTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART0_RTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART0_RTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_UART0_RXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART0_RXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART0_RXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART0_RXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART0_RXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART0_RXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART0_RXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART0_RXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART0_RXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART0_RXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART0_RXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART0_RXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART0_RXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART0_RXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART0_RXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART0_RXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART0_RXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART0_RXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART0_RXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART0_RXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART0_RXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART0_RXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART0_RXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART0_RXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART0_RXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART0_RXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_UART0_TXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART0_TXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART0_TXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART0_TXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART0_TXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART0_TXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART0_TXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART0_TXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART0_TXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART0_TXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART0_TXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART0_TXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART0_TXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART0_TXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART0_TXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART0_TXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART0_TXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART0_TXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART0_TXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART0_TXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART0_TXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART0_TXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART0_TXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART0_TXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART0_TXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART0_TXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_UART1_CTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART1_CTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART1_CTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART1_CTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART1_CTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART1_CTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART1_CTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART1_CTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART1_CTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART1_CTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART1_CTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART1_CTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART1_CTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART1_CTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART1_CTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART1_CTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART1_CTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART1_CTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART1_CTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART1_CTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART1_CTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART1_CTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART1_CTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART1_CTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART1_CTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART1_CTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_UART1_RTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART1_RTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART1_RTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART1_RTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART1_RTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART1_RTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART1_RTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART1_RTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART1_RTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART1_RTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART1_RTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART1_RTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART1_RTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART1_RTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART1_RTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART1_RTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART1_RTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART1_RTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART1_RTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART1_RTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART1_RTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART1_RTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART1_RTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART1_RTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART1_RTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART1_RTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_UART1_RXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART1_RXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART1_RXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART1_RXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART1_RXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART1_RXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART1_RXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART1_RXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART1_RXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART1_RXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART1_RXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART1_RXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART1_RXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART1_RXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART1_RXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART1_RXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART1_RXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART1_RXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART1_RXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART1_RXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART1_RXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART1_RXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART1_RXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART1_RXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART1_RXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART1_RXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_UART1_TXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART1_TXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART1_TXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART1_TXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART1_TXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART1_TXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART1_TXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART1_TXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART1_TXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART1_TXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART1_TXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART1_TXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART1_TXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART1_TXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART1_TXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART1_TXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART1_TXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART1_TXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART1_TXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART1_TXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART1_TXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART1_TXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART1_TXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART1_TXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART1_TXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART1_TXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_I2C0_SDA_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_I2C0_SDA_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_I2C0_SDA_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_I2C0_SDA_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_I2C0_SDA_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_I2C0_SDA_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_I2C0_SDA_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_I2C0_SDA_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_I2C0_SDA_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_I2C0_SDA_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_I2C0_SDA_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_I2C0_SDA_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_I2C0_SCL_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_I2C0_SCL_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_I2C0_SCL_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_I2C0_SCL_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_I2C0_SCL_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_I2C0_SCL_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_I2C0_SCL_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_I2C0_SCL_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_I2C0_SCL_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_I2C0_SCL_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_I2C0_SCL_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_I2C0_SCL_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_MCASP0_ACLKX_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_MCASP0_ACLKX_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_MCASP0_ACLKX_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_MCASP0_ACLKX_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_MCASP0_ACLKX_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_MCASP0_ACLKX_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_MCASP0_ACLKX_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_MCASP0_ACLKX_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_MCASP0_ACLKX_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_MCASP0_ACLKX_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_MCASP0_ACLKX_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_MCASP0_ACLKX_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_MCASP0_ACLKX_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_MCASP0_ACLKX_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_MCASP0_ACLKX_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_MCASP0_ACLKX_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_MCASP0_ACLKX_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_MCASP0_ACLKX_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_MCASP0_ACLKX_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_MCASP0_ACLKX_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_MCASP0_ACLKX_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_MCASP0_ACLKX_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_MCASP0_ACLKX_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_MCASP0_ACLKX_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_MCASP0_ACLKX_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_MCASP0_ACLKX_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_MCASP0_FSX_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_MCASP0_FSX_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_MCASP0_FSX_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_MCASP0_FSX_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_MCASP0_FSX_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_MCASP0_FSX_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_MCASP0_FSX_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_MCASP0_FSX_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_MCASP0_FSX_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_MCASP0_FSX_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_MCASP0_FSX_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_MCASP0_FSX_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_MCASP0_FSX_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_MCASP0_FSX_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_MCASP0_FSX_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_MCASP0_FSX_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_MCASP0_FSX_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_MCASP0_FSX_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_MCASP0_FSX_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_MCASP0_FSX_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_MCASP0_FSX_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_MCASP0_FSX_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_MCASP0_FSX_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_MCASP0_FSX_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_MCASP0_FSX_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_MCASP0_FSX_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_MCASP0_AXR0_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_MCASP0_AXR0_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_MCASP0_AXR0_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_MCASP0_AXR0_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_MCASP0_AXR0_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_MCASP0_AXR0_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_MCASP0_AXR0_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_MCASP0_AXR0_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_MCASP0_AXR0_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_MCASP0_AXR0_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_MCASP0_AXR0_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_MCASP0_AXR0_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_MCASP0_AXR0_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_MCASP0_AXR0_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_MCASP0_AXR0_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_MCASP0_AXR0_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_MCASP0_AXR0_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_MCASP0_AXR0_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_MCASP0_AXR0_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_MCASP0_AXR0_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_MCASP0_AXR0_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_MCASP0_AXR0_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_MCASP0_AXR0_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_MCASP0_AXR0_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_MCASP0_AXR0_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_MCASP0_AXR0_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_MCASP0_AHCLKR_LOCK_SHIFT                                              (31U)
#define CTRL_CONF_MCASP0_AHCLKR_LOCK_MASK                                               (0x80000000U)

#define CTRL_CONF_MCASP0_AHCLKR_WUEVT_SHIFT                                             (30U)
#define CTRL_CONF_MCASP0_AHCLKR_WUEVT_MASK                                              (0x40000000U)

#define CTRL_CONF_MCASP0_AHCLKR_WUEN_SHIFT                                              (29U)
#define CTRL_CONF_MCASP0_AHCLKR_WUEN_MASK                                               (0x20000000U)

#define CTRL_CONF_MCASP0_AHCLKR_DSPULLTYPESELECT_SHIFT                                  (28U)
#define CTRL_CONF_MCASP0_AHCLKR_DSPULLTYPESELECT_MASK                                   (0x10000000U)

#define CTRL_CONF_MCASP0_AHCLKR_DSPULLUDEN_SHIFT                                        (27U)
#define CTRL_CONF_MCASP0_AHCLKR_DSPULLUDEN_MASK                                         (0x08000000U)

#define CTRL_CONF_MCASP0_AHCLKR_DS0OUTVALUE_SHIFT                                       (26U)
#define CTRL_CONF_MCASP0_AHCLKR_DS0OUTVALUE_MASK                                        (0x04000000U)

#define CTRL_CONF_MCASP0_AHCLKR_DS0OUTEN_SHIFT                                          (25U)
#define CTRL_CONF_MCASP0_AHCLKR_DS0OUTEN_MASK                                           (0x02000000U)

#define CTRL_CONF_MCASP0_AHCLKR_DS0EN_SHIFT                                             (24U)
#define CTRL_CONF_MCASP0_AHCLKR_DS0EN_MASK                                              (0x01000000U)

#define CTRL_CONF_MCASP0_AHCLKR_SLEWCTRL_SHIFT                                          (19U)
#define CTRL_CONF_MCASP0_AHCLKR_SLEWCTRL_MASK                                           (0x00080000U)

#define CTRL_CONF_MCASP0_AHCLKR_RXACTIVE_SHIFT                                          (18U)
#define CTRL_CONF_MCASP0_AHCLKR_RXACTIVE_MASK                                           (0x00040000U)

#define CTRL_CONF_MCASP0_AHCLKR_PUTYPESEL_SHIFT                                         (17U)
#define CTRL_CONF_MCASP0_AHCLKR_PUTYPESEL_MASK                                          (0x00020000U)

#define CTRL_CONF_MCASP0_AHCLKR_PUDEN_SHIFT                                             (16U)
#define CTRL_CONF_MCASP0_AHCLKR_PUDEN_MASK                                              (0x00010000U)

#define CTRL_CONF_MCASP0_AHCLKR_MMODE_SHIFT                                             (0U)
#define CTRL_CONF_MCASP0_AHCLKR_MMODE_MASK                                              (0x0000000fU)

#define CTRL_CONF_MCASP0_ACLKR_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_MCASP0_ACLKR_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_MCASP0_ACLKR_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_MCASP0_ACLKR_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_MCASP0_ACLKR_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_MCASP0_ACLKR_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_MCASP0_ACLKR_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_MCASP0_ACLKR_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_MCASP0_ACLKR_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_MCASP0_ACLKR_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_MCASP0_ACLKR_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_MCASP0_ACLKR_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_MCASP0_ACLKR_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_MCASP0_ACLKR_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_MCASP0_ACLKR_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_MCASP0_ACLKR_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_MCASP0_ACLKR_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_MCASP0_ACLKR_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_MCASP0_ACLKR_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_MCASP0_ACLKR_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_MCASP0_ACLKR_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_MCASP0_ACLKR_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_MCASP0_ACLKR_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_MCASP0_ACLKR_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_MCASP0_ACLKR_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_MCASP0_ACLKR_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_MCASP0_FSR_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_MCASP0_FSR_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_MCASP0_FSR_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_MCASP0_FSR_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_MCASP0_FSR_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_MCASP0_FSR_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_MCASP0_FSR_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_MCASP0_FSR_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_MCASP0_FSR_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_MCASP0_FSR_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_MCASP0_FSR_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_MCASP0_FSR_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_MCASP0_FSR_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_MCASP0_FSR_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_MCASP0_FSR_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_MCASP0_FSR_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_MCASP0_FSR_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_MCASP0_FSR_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_MCASP0_FSR_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_MCASP0_FSR_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_MCASP0_FSR_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_MCASP0_FSR_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_MCASP0_FSR_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_MCASP0_FSR_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_MCASP0_FSR_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_MCASP0_FSR_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_MCASP0_AXR1_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_MCASP0_AXR1_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_MCASP0_AXR1_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_MCASP0_AXR1_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_MCASP0_AXR1_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_MCASP0_AXR1_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_MCASP0_AXR1_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_MCASP0_AXR1_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_MCASP0_AXR1_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_MCASP0_AXR1_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_MCASP0_AXR1_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_MCASP0_AXR1_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_MCASP0_AXR1_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_MCASP0_AXR1_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_MCASP0_AXR1_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_MCASP0_AXR1_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_MCASP0_AXR1_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_MCASP0_AXR1_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_MCASP0_AXR1_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_MCASP0_AXR1_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_MCASP0_AXR1_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_MCASP0_AXR1_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_MCASP0_AXR1_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_MCASP0_AXR1_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_MCASP0_AXR1_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_MCASP0_AXR1_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_MCASP0_AHCLKX_LOCK_SHIFT                                              (31U)
#define CTRL_CONF_MCASP0_AHCLKX_LOCK_MASK                                               (0x80000000U)

#define CTRL_CONF_MCASP0_AHCLKX_WUEVT_SHIFT                                             (30U)
#define CTRL_CONF_MCASP0_AHCLKX_WUEVT_MASK                                              (0x40000000U)

#define CTRL_CONF_MCASP0_AHCLKX_WUEN_SHIFT                                              (29U)
#define CTRL_CONF_MCASP0_AHCLKX_WUEN_MASK                                               (0x20000000U)

#define CTRL_CONF_MCASP0_AHCLKX_DSPULLTYPESELECT_SHIFT                                  (28U)
#define CTRL_CONF_MCASP0_AHCLKX_DSPULLTYPESELECT_MASK                                   (0x10000000U)

#define CTRL_CONF_MCASP0_AHCLKX_DSPULLUDEN_SHIFT                                        (27U)
#define CTRL_CONF_MCASP0_AHCLKX_DSPULLUDEN_MASK                                         (0x08000000U)

#define CTRL_CONF_MCASP0_AHCLKX_DS0OUTVALUE_SHIFT                                       (26U)
#define CTRL_CONF_MCASP0_AHCLKX_DS0OUTVALUE_MASK                                        (0x04000000U)

#define CTRL_CONF_MCASP0_AHCLKX_DS0OUTEN_SHIFT                                          (25U)
#define CTRL_CONF_MCASP0_AHCLKX_DS0OUTEN_MASK                                           (0x02000000U)

#define CTRL_CONF_MCASP0_AHCLKX_DS0EN_SHIFT                                             (24U)
#define CTRL_CONF_MCASP0_AHCLKX_DS0EN_MASK                                              (0x01000000U)

#define CTRL_CONF_MCASP0_AHCLKX_SLEWCTRL_SHIFT                                          (19U)
#define CTRL_CONF_MCASP0_AHCLKX_SLEWCTRL_MASK                                           (0x00080000U)

#define CTRL_CONF_MCASP0_AHCLKX_RXACTIVE_SHIFT                                          (18U)
#define CTRL_CONF_MCASP0_AHCLKX_RXACTIVE_MASK                                           (0x00040000U)

#define CTRL_CONF_MCASP0_AHCLKX_PUTYPESEL_SHIFT                                         (17U)
#define CTRL_CONF_MCASP0_AHCLKX_PUTYPESEL_MASK                                          (0x00020000U)

#define CTRL_CONF_MCASP0_AHCLKX_PUDEN_SHIFT                                             (16U)
#define CTRL_CONF_MCASP0_AHCLKX_PUDEN_MASK                                              (0x00010000U)

#define CTRL_CONF_MCASP0_AHCLKX_MMODE_SHIFT                                             (0U)
#define CTRL_CONF_MCASP0_AHCLKX_MMODE_MASK                                              (0x0000000fU)

#define CTRL_CONF_CCDC0_HD_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_CCDC0_HD_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_CCDC0_HD_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_CCDC0_HD_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_CCDC0_HD_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_CCDC0_HD_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_CCDC0_HD_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_CCDC0_HD_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_CCDC0_HD_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_CCDC0_HD_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_CCDC0_HD_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_CCDC0_HD_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_CCDC0_HD_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_CCDC0_HD_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_CCDC0_HD_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_CCDC0_HD_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_CCDC0_HD_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_CCDC0_HD_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_CCDC0_HD_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_CCDC0_HD_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_CCDC0_HD_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_CCDC0_HD_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_CCDC0_HD_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_CCDC0_HD_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_CCDC0_HD_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_CCDC0_HD_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_CCDC0_VD_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_CCDC0_VD_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_CCDC0_VD_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_CCDC0_VD_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_CCDC0_VD_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_CCDC0_VD_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_CCDC0_VD_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_CCDC0_VD_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_CCDC0_VD_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_CCDC0_VD_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_CCDC0_VD_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_CCDC0_VD_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_CCDC0_VD_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_CCDC0_VD_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_CCDC0_VD_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_CCDC0_VD_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_CCDC0_VD_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_CCDC0_VD_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_CCDC0_VD_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_CCDC0_VD_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_CCDC0_VD_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_CCDC0_VD_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_CCDC0_VD_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_CCDC0_VD_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_CCDC0_VD_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_CCDC0_VD_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_CCDC0_FIELD_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_FIELD_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_FIELD_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_FIELD_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_FIELD_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_FIELD_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_FIELD_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_FIELD_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_FIELD_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_FIELD_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_FIELD_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_FIELD_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_FIELD_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_FIELD_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_FIELD_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_FIELD_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_FIELD_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_FIELD_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_FIELD_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_FIELD_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_FIELD_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_FIELD_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_FIELD_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_FIELD_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_FIELD_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_FIELD_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_WEN_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_CCDC0_WEN_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_CCDC0_WEN_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_CCDC0_WEN_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_CCDC0_WEN_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_CCDC0_WEN_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_CCDC0_WEN_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_CCDC0_WEN_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_CCDC0_WEN_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_CCDC0_WEN_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_CCDC0_WEN_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_CCDC0_WEN_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_CCDC0_WEN_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_CCDC0_WEN_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_CCDC0_WEN_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_CCDC0_WEN_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_CCDC0_WEN_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_CCDC0_WEN_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_CCDC0_WEN_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_CCDC0_WEN_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_CCDC0_WEN_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_CCDC0_WEN_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_CCDC0_WEN_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_CCDC0_WEN_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_CCDC0_WEN_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_CCDC0_WEN_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_CCDC0_PCLK_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_CCDC0_PCLK_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_CCDC0_PCLK_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_CCDC0_PCLK_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_CCDC0_PCLK_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_CCDC0_PCLK_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_CCDC0_PCLK_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_CCDC0_PCLK_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_CCDC0_PCLK_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_CCDC0_PCLK_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_CCDC0_PCLK_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_CCDC0_PCLK_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_CCDC0_PCLK_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_CCDC0_PCLK_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_CCDC0_PCLK_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_CCDC0_PCLK_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_CCDC0_PCLK_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_CCDC0_PCLK_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_CCDC0_PCLK_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_CCDC0_PCLK_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_CCDC0_PCLK_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_CCDC0_PCLK_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_CCDC0_PCLK_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_CCDC0_PCLK_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_CCDC0_PCLK_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_CCDC0_PCLK_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA8_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA8_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA8_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA8_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA8_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA8_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA8_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA8_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA8_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA8_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA8_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA8_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA8_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA8_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA8_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA8_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA8_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA8_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA8_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA8_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA8_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA8_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA8_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA8_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA8_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA8_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA9_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA9_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA9_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA9_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA9_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA9_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA9_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA9_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA9_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA9_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA9_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA9_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA9_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA9_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA9_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA9_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA9_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA9_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA9_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA9_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA9_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA9_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA9_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA9_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA9_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA9_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA9_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA9_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA9_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA9_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA9_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA9_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA9_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA9_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA9_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA9_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA9_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA9_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA9_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA9_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA9_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA9_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA9_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA9_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA9_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA9_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA9_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA9_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA9_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA9_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA9_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA9_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA8_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA8_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA8_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA8_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA8_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA8_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA8_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA8_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA8_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA8_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA8_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA8_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA8_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA8_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA8_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA8_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA8_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA8_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA8_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA8_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA8_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA8_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA8_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA8_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA8_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA8_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_HD_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_CCDC1_HD_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_CCDC1_HD_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_CCDC1_HD_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_CCDC1_HD_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_CCDC1_HD_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_CCDC1_HD_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_CCDC1_HD_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_CCDC1_HD_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_CCDC1_HD_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_CCDC1_HD_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_CCDC1_HD_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_CCDC1_HD_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_CCDC1_HD_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_CCDC1_HD_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_CCDC1_HD_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_CCDC1_HD_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_CCDC1_HD_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_CCDC1_HD_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_CCDC1_HD_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_CCDC1_HD_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_CCDC1_HD_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_CCDC1_HD_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_CCDC1_HD_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_CCDC1_HD_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_CCDC1_HD_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_CCDC1_VD_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_CCDC1_VD_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_CCDC1_VD_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_CCDC1_VD_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_CCDC1_VD_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_CCDC1_VD_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_CCDC1_VD_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_CCDC1_VD_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_CCDC1_VD_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_CCDC1_VD_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_CCDC1_VD_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_CCDC1_VD_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_CCDC1_VD_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_CCDC1_VD_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_CCDC1_VD_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_CCDC1_VD_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_CCDC1_VD_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_CCDC1_VD_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_CCDC1_VD_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_CCDC1_VD_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_CCDC1_VD_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_CCDC1_VD_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_CCDC1_VD_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_CCDC1_VD_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_CCDC1_VD_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_CCDC1_VD_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_CCDC1_PCLK_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_CCDC1_PCLK_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_CCDC1_PCLK_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_CCDC1_PCLK_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_CCDC1_PCLK_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_CCDC1_PCLK_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_CCDC1_PCLK_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_CCDC1_PCLK_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_CCDC1_PCLK_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_CCDC1_PCLK_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_CCDC1_PCLK_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_CCDC1_PCLK_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_CCDC1_PCLK_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_CCDC1_PCLK_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_CCDC1_PCLK_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_CCDC1_PCLK_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_CCDC1_PCLK_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_CCDC1_PCLK_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_CCDC1_PCLK_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_CCDC1_PCLK_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_CCDC1_PCLK_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_CCDC1_PCLK_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_CCDC1_PCLK_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_CCDC1_PCLK_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_CCDC1_PCLK_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_CCDC1_PCLK_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_CCDC1_FIELD_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_FIELD_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_FIELD_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_FIELD_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_FIELD_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_FIELD_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_FIELD_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_FIELD_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_FIELD_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_FIELD_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_FIELD_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_FIELD_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_FIELD_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_FIELD_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_FIELD_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_FIELD_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_FIELD_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_FIELD_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_FIELD_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_FIELD_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_FIELD_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_FIELD_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_FIELD_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_FIELD_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_FIELD_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_FIELD_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_WEN_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_CCDC1_WEN_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_CCDC1_WEN_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_CCDC1_WEN_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_CCDC1_WEN_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_CCDC1_WEN_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_CCDC1_WEN_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_CCDC1_WEN_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_CCDC1_WEN_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_CCDC1_WEN_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_CCDC1_WEN_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_CCDC1_WEN_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_CCDC1_WEN_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_CCDC1_WEN_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_CCDC1_WEN_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_CCDC1_WEN_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_CCDC1_WEN_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_CCDC1_WEN_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_CCDC1_WEN_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_CCDC1_WEN_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_CCDC1_WEN_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_CCDC1_WEN_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_CCDC1_WEN_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_CCDC1_WEN_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_CCDC1_WEN_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_CCDC1_WEN_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA0_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA0_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA0_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA0_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA0_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA0_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA0_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA0_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA0_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA0_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA0_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA0_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA0_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA0_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA0_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA0_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA0_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA0_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA0_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA0_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA0_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA0_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA0_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA0_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA0_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA0_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA1_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA1_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA1_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA1_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA1_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA1_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA1_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA1_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA1_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA1_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA1_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA1_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA1_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA1_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA1_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA1_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA1_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA1_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA1_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA1_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA1_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA1_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA1_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA1_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA1_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA1_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA2_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA2_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA2_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA2_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA2_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA2_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA2_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA2_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA2_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA2_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA2_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA2_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA2_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA2_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA2_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA2_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA2_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA2_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA2_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA2_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA2_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA2_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA2_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA2_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA2_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA2_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA3_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA3_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA3_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA3_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA3_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA3_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA3_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA3_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA3_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA3_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA3_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA3_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA3_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA3_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA3_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA3_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA3_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA3_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA3_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA3_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA3_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA3_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA3_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA3_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA3_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA3_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA4_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA4_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA4_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA4_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA4_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA4_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA4_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA4_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA4_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA4_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA4_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA4_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA4_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA4_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA4_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA4_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA4_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA4_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA4_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA4_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA4_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA4_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA4_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA4_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA4_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA4_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA5_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA5_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA5_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA5_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA5_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA5_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA5_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA5_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA5_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA5_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA5_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA5_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA5_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA5_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA5_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA5_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA5_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA5_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA5_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA5_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA5_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA5_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA5_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA5_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA5_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA5_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA6_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA6_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA6_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA6_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA6_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA6_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA6_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA6_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA6_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA6_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA6_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA6_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA6_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA6_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA6_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA6_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA6_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA6_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA6_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA6_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA6_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA6_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA6_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA6_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA6_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA6_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC1_DATA7_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC1_DATA7_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC1_DATA7_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC1_DATA7_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC1_DATA7_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC1_DATA7_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC1_DATA7_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC1_DATA7_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC1_DATA7_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC1_DATA7_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC1_DATA7_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC1_DATA7_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC1_DATA7_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC1_DATA7_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC1_DATA7_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC1_DATA7_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC1_DATA7_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC1_DATA7_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC1_DATA7_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC1_DATA7_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC1_DATA7_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC1_DATA7_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC1_DATA7_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC1_DATA7_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC1_DATA7_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC1_DATA7_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA0_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA0_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA0_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA0_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA0_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA0_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA0_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA0_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA0_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA0_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA0_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA0_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA0_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA0_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA0_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA0_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA0_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA0_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA0_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA0_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA0_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA0_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA0_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA0_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA0_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA0_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA1_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA1_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA1_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA1_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA1_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA1_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA1_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA1_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA1_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA1_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA1_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA1_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA1_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA1_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA1_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA1_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA1_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA1_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA1_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA1_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA1_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA1_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA1_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA1_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA1_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA1_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA2_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA2_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA2_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA2_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA2_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA2_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA2_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA2_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA2_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA2_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA2_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA2_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA2_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA2_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA2_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA2_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA2_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA2_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA2_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA2_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA2_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA2_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA2_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA2_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA2_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA2_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA3_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA3_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA3_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA3_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA3_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA3_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA3_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA3_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA3_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA3_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA3_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA3_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA3_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA3_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA3_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA3_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA3_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA3_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA3_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA3_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA3_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA3_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA3_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA3_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA3_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA3_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA4_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA4_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA4_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA4_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA4_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA4_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA4_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA4_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA4_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA4_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA4_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA4_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA4_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA4_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA4_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA4_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA4_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA4_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA4_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA4_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA4_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA4_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA4_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA4_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA4_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA4_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA5_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA5_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA5_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA5_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA5_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA5_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA5_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA5_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA5_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA5_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA5_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA5_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA5_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA5_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA5_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA5_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA5_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA5_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA5_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA5_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA5_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA5_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA5_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA5_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA5_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA5_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA6_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA6_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA6_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA6_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA6_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA6_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA6_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA6_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA6_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA6_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA6_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA6_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA6_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA6_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA6_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA6_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA6_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA6_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA6_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA6_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA6_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA6_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA6_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA6_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA6_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA6_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_CCDC0_DATA7_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_CCDC0_DATA7_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_CCDC0_DATA7_WUEVT_SHIFT                                               (30U)
#define CTRL_CONF_CCDC0_DATA7_WUEVT_MASK                                                (0x40000000U)

#define CTRL_CONF_CCDC0_DATA7_WUEN_SHIFT                                                (29U)
#define CTRL_CONF_CCDC0_DATA7_WUEN_MASK                                                 (0x20000000U)

#define CTRL_CONF_CCDC0_DATA7_DSPULLTYPESELECT_SHIFT                                    (28U)
#define CTRL_CONF_CCDC0_DATA7_DSPULLTYPESELECT_MASK                                     (0x10000000U)

#define CTRL_CONF_CCDC0_DATA7_DSPULLUDEN_SHIFT                                          (27U)
#define CTRL_CONF_CCDC0_DATA7_DSPULLUDEN_MASK                                           (0x08000000U)

#define CTRL_CONF_CCDC0_DATA7_DS0OUTVALUE_SHIFT                                         (26U)
#define CTRL_CONF_CCDC0_DATA7_DS0OUTVALUE_MASK                                          (0x04000000U)

#define CTRL_CONF_CCDC0_DATA7_DS0OUTEN_SHIFT                                            (25U)
#define CTRL_CONF_CCDC0_DATA7_DS0OUTEN_MASK                                             (0x02000000U)

#define CTRL_CONF_CCDC0_DATA7_DS0EN_SHIFT                                               (24U)
#define CTRL_CONF_CCDC0_DATA7_DS0EN_MASK                                                (0x01000000U)

#define CTRL_CONF_CCDC0_DATA7_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_CCDC0_DATA7_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_CCDC0_DATA7_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_CCDC0_DATA7_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_CCDC0_DATA7_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_CCDC0_DATA7_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_CCDC0_DATA7_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_CCDC0_DATA7_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_CCDC0_DATA7_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_CCDC0_DATA7_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_UART3_RXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART3_RXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART3_RXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART3_RXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART3_RXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART3_RXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART3_RXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART3_RXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART3_RXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART3_RXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART3_RXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART3_RXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART3_RXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART3_RXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART3_RXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART3_RXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART3_RXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART3_RXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART3_RXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART3_RXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART3_RXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART3_RXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART3_RXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART3_RXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART3_RXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART3_RXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_UART3_TXD_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_UART3_TXD_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_UART3_TXD_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_UART3_TXD_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_UART3_TXD_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_UART3_TXD_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_UART3_TXD_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_UART3_TXD_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_UART3_TXD_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_UART3_TXD_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_UART3_TXD_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_UART3_TXD_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_UART3_TXD_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_UART3_TXD_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_UART3_TXD_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_UART3_TXD_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_UART3_TXD_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_UART3_TXD_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_UART3_TXD_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_UART3_TXD_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_UART3_TXD_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_UART3_TXD_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_UART3_TXD_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_UART3_TXD_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_UART3_TXD_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_UART3_TXD_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_UART3_CTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART3_CTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART3_CTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART3_CTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART3_CTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART3_CTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART3_CTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART3_CTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART3_CTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART3_CTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART3_CTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART3_CTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART3_CTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART3_CTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART3_CTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART3_CTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART3_CTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART3_CTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART3_CTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART3_CTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART3_CTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART3_CTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART3_CTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART3_CTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART3_CTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART3_CTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_UART3_RTSN_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_UART3_RTSN_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_UART3_RTSN_WUEVT_SHIFT                                                (30U)
#define CTRL_CONF_UART3_RTSN_WUEVT_MASK                                                 (0x40000000U)

#define CTRL_CONF_UART3_RTSN_WUEN_SHIFT                                                 (29U)
#define CTRL_CONF_UART3_RTSN_WUEN_MASK                                                  (0x20000000U)

#define CTRL_CONF_UART3_RTSN_DSPULLTYPESELECT_SHIFT                                     (28U)
#define CTRL_CONF_UART3_RTSN_DSPULLTYPESELECT_MASK                                      (0x10000000U)

#define CTRL_CONF_UART3_RTSN_DSPULLUDEN_SHIFT                                           (27U)
#define CTRL_CONF_UART3_RTSN_DSPULLUDEN_MASK                                            (0x08000000U)

#define CTRL_CONF_UART3_RTSN_DS0OUTVALUE_SHIFT                                          (26U)
#define CTRL_CONF_UART3_RTSN_DS0OUTVALUE_MASK                                           (0x04000000U)

#define CTRL_CONF_UART3_RTSN_DS0OUTEN_SHIFT                                             (25U)
#define CTRL_CONF_UART3_RTSN_DS0OUTEN_MASK                                              (0x02000000U)

#define CTRL_CONF_UART3_RTSN_DS0EN_SHIFT                                                (24U)
#define CTRL_CONF_UART3_RTSN_DS0EN_MASK                                                 (0x01000000U)

#define CTRL_CONF_UART3_RTSN_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_UART3_RTSN_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_UART3_RTSN_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_UART3_RTSN_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_UART3_RTSN_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_UART3_RTSN_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_UART3_RTSN_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_UART3_RTSN_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_UART3_RTSN_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_UART3_RTSN_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_PRINT_NSTROBE_LOCK_SHIFT                                              (31U)
#define CTRL_CONF_PRINT_NSTROBE_LOCK_MASK                                               (0x80000000U)

#define CTRL_CONF_PRINT_NSTROBE_WUEVT_SHIFT                                             (30U)
#define CTRL_CONF_PRINT_NSTROBE_WUEVT_MASK                                              (0x40000000U)

#define CTRL_CONF_PRINT_NSTROBE_WUEN_SHIFT                                              (29U)
#define CTRL_CONF_PRINT_NSTROBE_WUEN_MASK                                               (0x20000000U)

#define CTRL_CONF_PRINT_NSTROBE_DSPULLTYPESELECT_SHIFT                                  (28U)
#define CTRL_CONF_PRINT_NSTROBE_DSPULLTYPESELECT_MASK                                   (0x10000000U)

#define CTRL_CONF_PRINT_NSTROBE_DSPULLUDEN_SHIFT                                        (27U)
#define CTRL_CONF_PRINT_NSTROBE_DSPULLUDEN_MASK                                         (0x08000000U)

#define CTRL_CONF_PRINT_NSTROBE_DS0OUTVALUE_SHIFT                                       (26U)
#define CTRL_CONF_PRINT_NSTROBE_DS0OUTVALUE_MASK                                        (0x04000000U)

#define CTRL_CONF_PRINT_NSTROBE_DS0OUTEN_SHIFT                                          (25U)
#define CTRL_CONF_PRINT_NSTROBE_DS0OUTEN_MASK                                           (0x02000000U)

#define CTRL_CONF_PRINT_NSTROBE_DS0EN_SHIFT                                             (24U)
#define CTRL_CONF_PRINT_NSTROBE_DS0EN_MASK                                              (0x01000000U)

#define CTRL_CONF_PRINT_NSTROBE_SLEWCTRL_SHIFT                                          (19U)
#define CTRL_CONF_PRINT_NSTROBE_SLEWCTRL_MASK                                           (0x00080000U)

#define CTRL_CONF_PRINT_NSTROBE_RXACTIVE_SHIFT                                          (18U)
#define CTRL_CONF_PRINT_NSTROBE_RXACTIVE_MASK                                           (0x00040000U)

#define CTRL_CONF_PRINT_NSTROBE_PUTYPESEL_SHIFT                                         (17U)
#define CTRL_CONF_PRINT_NSTROBE_PUTYPESEL_MASK                                          (0x00020000U)

#define CTRL_CONF_PRINT_NSTROBE_PUDEN_SHIFT                                             (16U)
#define CTRL_CONF_PRINT_NSTROBE_PUDEN_MASK                                              (0x00010000U)

#define CTRL_CONF_PRINT_NSTROBE_MMODE_SHIFT                                             (0U)
#define CTRL_CONF_PRINT_NSTROBE_MMODE_MASK                                              (0x0000000fU)

#define CTRL_CONF_PRINT_MA_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_PRINT_MA_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_PRINT_MA_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_PRINT_MA_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_PRINT_MA_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_PRINT_MA_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_PRINT_MA_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_PRINT_MA_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_PRINT_MA_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_PRINT_MA_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_PRINT_MA_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_PRINT_MA_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_PRINT_MA_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_PRINT_MA_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_PRINT_MA_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_PRINT_MA_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_PRINT_MA_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_PRINT_MA_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_PRINT_MA_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_PRINT_MA_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_PRINT_MA_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_PRINT_MA_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_PRINT_MA_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_PRINT_MA_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_PRINT_MA_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_PRINT_MA_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_PRINT_MNA_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_PRINT_MNA_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_PRINT_MNA_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_PRINT_MNA_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_PRINT_MNA_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_PRINT_MNA_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_PRINT_MNA_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_PRINT_MNA_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_PRINT_MNA_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_PRINT_MNA_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_PRINT_MNA_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_PRINT_MNA_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_PRINT_MNA_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_PRINT_MNA_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_PRINT_MNA_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_PRINT_MNA_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_PRINT_MNA_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_PRINT_MNA_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_PRINT_MNA_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_PRINT_MNA_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_PRINT_MNA_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_PRINT_MNA_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_PRINT_MNA_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_PRINT_MNA_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_PRINT_MNA_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_PRINT_MNA_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_PRINT_MB_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_PRINT_MB_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_PRINT_MB_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_PRINT_MB_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_PRINT_MB_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_PRINT_MB_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_PRINT_MB_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_PRINT_MB_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_PRINT_MB_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_PRINT_MB_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_PRINT_MB_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_PRINT_MB_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_PRINT_MB_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_PRINT_MB_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_PRINT_MB_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_PRINT_MB_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_PRINT_MB_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_PRINT_MB_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_PRINT_MB_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_PRINT_MB_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_PRINT_MB_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_PRINT_MB_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_PRINT_MB_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_PRINT_MB_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_PRINT_MB_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_PRINT_MB_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_PRINT_MNB_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_PRINT_MNB_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_PRINT_MNB_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_PRINT_MNB_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_PRINT_MNB_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_PRINT_MNB_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_PRINT_MNB_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_PRINT_MNB_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_PRINT_MNB_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_PRINT_MNB_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_PRINT_MNB_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_PRINT_MNB_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_PRINT_MNB_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_PRINT_MNB_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_PRINT_MNB_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_PRINT_MNB_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_PRINT_MNB_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_PRINT_MNB_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_PRINT_MNB_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_PRINT_MNB_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_PRINT_MNB_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_PRINT_MNB_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_PRINT_MNB_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_PRINT_MNB_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_PRINT_MNB_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_PRINT_MNB_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_PRINT_ON_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_PRINT_ON_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_PRINT_ON_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_PRINT_ON_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_PRINT_ON_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_PRINT_ON_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_PRINT_ON_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_PRINT_ON_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_PRINT_ON_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_PRINT_ON_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_PRINT_ON_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_PRINT_ON_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_PRINT_ON_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_PRINT_ON_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_PRINT_ON_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_PRINT_ON_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_PRINT_ON_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_PRINT_ON_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_PRINT_ON_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_PRINT_ON_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_PRINT_ON_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_PRINT_ON_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_PRINT_ON_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_PRINT_ON_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_PRINT_ON_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_PRINT_ON_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_SPI4_SCLK_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_SPI4_SCLK_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_SPI4_SCLK_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_SPI4_SCLK_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_SPI4_SCLK_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_SPI4_SCLK_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_SPI4_SCLK_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_SPI4_SCLK_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_SPI4_SCLK_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_SPI4_SCLK_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_SPI4_SCLK_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_SPI4_SCLK_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_SPI4_SCLK_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_SPI4_SCLK_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_SPI4_SCLK_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_SPI4_SCLK_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_SPI4_SCLK_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_SPI4_SCLK_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_SPI4_SCLK_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_SPI4_SCLK_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_SPI4_SCLK_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_SPI4_SCLK_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_SPI4_SCLK_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_SPI4_SCLK_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_SPI4_SCLK_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_SPI4_SCLK_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_SPI4_D0_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI4_D0_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI4_D0_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI4_D0_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI4_D0_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI4_D0_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI4_D0_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI4_D0_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI4_D0_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI4_D0_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI4_D0_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI4_D0_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI4_D0_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI4_D0_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI4_D0_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI4_D0_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI4_D0_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI4_D0_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI4_D0_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI4_D0_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI4_D0_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI4_D0_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI4_D0_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI4_D0_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI4_D0_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI4_D0_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI4_D1_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI4_D1_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI4_D1_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI4_D1_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI4_D1_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI4_D1_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI4_D1_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI4_D1_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI4_D1_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI4_D1_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI4_D1_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI4_D1_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI4_D1_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI4_D1_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI4_D1_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI4_D1_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI4_D1_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI4_D1_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI4_D1_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI4_D1_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI4_D1_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI4_D1_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI4_D1_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI4_D1_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI4_D1_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI4_D1_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI4_CS0_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_SPI4_CS0_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_SPI4_CS0_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_SPI4_CS0_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_SPI4_CS0_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_SPI4_CS0_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_SPI4_CS0_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_SPI4_CS0_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_SPI4_CS0_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_SPI4_CS0_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_SPI4_CS0_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_SPI4_CS0_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_SPI4_CS0_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_SPI4_CS0_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_SPI4_CS0_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_SPI4_CS0_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_SPI4_CS0_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_SPI4_CS0_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_SPI4_CS0_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_SPI4_CS0_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_SPI4_CS0_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_SPI4_CS0_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_SPI4_CS0_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_SPI4_CS0_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_SPI4_CS0_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_SPI4_CS0_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_SPI2_SCLK_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_SPI2_SCLK_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_SPI2_SCLK_WUEVT_SHIFT                                                 (30U)
#define CTRL_CONF_SPI2_SCLK_WUEVT_MASK                                                  (0x40000000U)

#define CTRL_CONF_SPI2_SCLK_WUEN_SHIFT                                                  (29U)
#define CTRL_CONF_SPI2_SCLK_WUEN_MASK                                                   (0x20000000U)

#define CTRL_CONF_SPI2_SCLK_DSPULLTYPESELECT_SHIFT                                      (28U)
#define CTRL_CONF_SPI2_SCLK_DSPULLTYPESELECT_MASK                                       (0x10000000U)

#define CTRL_CONF_SPI2_SCLK_DSPULLUDEN_SHIFT                                            (27U)
#define CTRL_CONF_SPI2_SCLK_DSPULLUDEN_MASK                                             (0x08000000U)

#define CTRL_CONF_SPI2_SCLK_DS0OUTVALUE_SHIFT                                           (26U)
#define CTRL_CONF_SPI2_SCLK_DS0OUTVALUE_MASK                                            (0x04000000U)

#define CTRL_CONF_SPI2_SCLK_DS0OUTEN_SHIFT                                              (25U)
#define CTRL_CONF_SPI2_SCLK_DS0OUTEN_MASK                                               (0x02000000U)

#define CTRL_CONF_SPI2_SCLK_DS0EN_SHIFT                                                 (24U)
#define CTRL_CONF_SPI2_SCLK_DS0EN_MASK                                                  (0x01000000U)

#define CTRL_CONF_SPI2_SCLK_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_SPI2_SCLK_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_SPI2_SCLK_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_SPI2_SCLK_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_SPI2_SCLK_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_SPI2_SCLK_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_SPI2_SCLK_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_SPI2_SCLK_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_SPI2_SCLK_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_SPI2_SCLK_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_SPI2_D0_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI2_D0_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI2_D0_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI2_D0_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI2_D0_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI2_D0_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI2_D0_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI2_D0_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI2_D0_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI2_D0_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI2_D0_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI2_D0_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI2_D0_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI2_D0_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI2_D0_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI2_D0_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI2_D0_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI2_D0_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI2_D0_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI2_D0_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI2_D0_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI2_D0_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI2_D0_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI2_D0_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI2_D0_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI2_D0_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI2_D1_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_SPI2_D1_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_SPI2_D1_WUEVT_SHIFT                                                   (30U)
#define CTRL_CONF_SPI2_D1_WUEVT_MASK                                                    (0x40000000U)

#define CTRL_CONF_SPI2_D1_WUEN_SHIFT                                                    (29U)
#define CTRL_CONF_SPI2_D1_WUEN_MASK                                                     (0x20000000U)

#define CTRL_CONF_SPI2_D1_DSPULLTYPESELECT_SHIFT                                        (28U)
#define CTRL_CONF_SPI2_D1_DSPULLTYPESELECT_MASK                                         (0x10000000U)

#define CTRL_CONF_SPI2_D1_DSPULLUDEN_SHIFT                                              (27U)
#define CTRL_CONF_SPI2_D1_DSPULLUDEN_MASK                                               (0x08000000U)

#define CTRL_CONF_SPI2_D1_DS0OUTVALUE_SHIFT                                             (26U)
#define CTRL_CONF_SPI2_D1_DS0OUTVALUE_MASK                                              (0x04000000U)

#define CTRL_CONF_SPI2_D1_DS0OUTEN_SHIFT                                                (25U)
#define CTRL_CONF_SPI2_D1_DS0OUTEN_MASK                                                 (0x02000000U)

#define CTRL_CONF_SPI2_D1_DS0EN_SHIFT                                                   (24U)
#define CTRL_CONF_SPI2_D1_DS0EN_MASK                                                    (0x01000000U)

#define CTRL_CONF_SPI2_D1_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_SPI2_D1_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_SPI2_D1_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_SPI2_D1_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_SPI2_D1_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_SPI2_D1_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_SPI2_D1_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_SPI2_D1_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_SPI2_D1_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_SPI2_D1_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_SPI2_CS0_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_SPI2_CS0_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_SPI2_CS0_WUEVT_SHIFT                                                  (30U)
#define CTRL_CONF_SPI2_CS0_WUEVT_MASK                                                   (0x40000000U)

#define CTRL_CONF_SPI2_CS0_WUEN_SHIFT                                                   (29U)
#define CTRL_CONF_SPI2_CS0_WUEN_MASK                                                    (0x20000000U)

#define CTRL_CONF_SPI2_CS0_DSPULLTYPESELECT_SHIFT                                       (28U)
#define CTRL_CONF_SPI2_CS0_DSPULLTYPESELECT_MASK                                        (0x10000000U)

#define CTRL_CONF_SPI2_CS0_DSPULLUDEN_SHIFT                                             (27U)
#define CTRL_CONF_SPI2_CS0_DSPULLUDEN_MASK                                              (0x08000000U)

#define CTRL_CONF_SPI2_CS0_DS0OUTVALUE_SHIFT                                            (26U)
#define CTRL_CONF_SPI2_CS0_DS0OUTVALUE_MASK                                             (0x04000000U)

#define CTRL_CONF_SPI2_CS0_DS0OUTEN_SHIFT                                               (25U)
#define CTRL_CONF_SPI2_CS0_DS0OUTEN_MASK                                                (0x02000000U)

#define CTRL_CONF_SPI2_CS0_DS0EN_SHIFT                                                  (24U)
#define CTRL_CONF_SPI2_CS0_DS0EN_MASK                                                   (0x01000000U)

#define CTRL_CONF_SPI2_CS0_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_SPI2_CS0_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_SPI2_CS0_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_SPI2_CS0_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_SPI2_CS0_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_SPI2_CS0_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_SPI2_CS0_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_SPI2_CS0_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_SPI2_CS0_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_SPI2_CS0_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_12_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_12_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_12_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_12_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_12_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_12_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_12_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_12_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_12_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_12_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_12_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_12_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_4_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_4_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_4_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_4_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_4_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_4_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_4_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_4_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_4_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_4_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_4_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_4_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_13_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_13_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_13_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_13_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_13_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_13_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_13_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_13_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_13_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_13_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_13_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_13_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_5_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_5_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_5_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_5_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_5_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_5_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_5_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_5_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_5_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_5_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_5_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_5_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_14_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_14_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_14_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_14_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_14_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_14_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_14_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_14_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_14_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_14_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_14_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_14_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_6_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_6_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_6_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_6_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_6_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_6_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_6_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_6_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_6_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_6_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_6_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_6_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_15_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_15_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_15_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_15_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_15_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_15_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_15_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_15_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_15_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_15_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_15_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_15_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_7_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_7_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_7_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_7_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_7_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_7_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_7_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_7_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_7_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_7_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_7_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_7_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_8_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_8_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_8_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_8_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_8_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_8_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_8_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_8_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_8_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_8_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_8_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_8_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_0_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_0_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_0_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_0_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_0_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_0_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_0_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_0_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_0_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_0_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_0_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_0_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_9_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_9_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_9_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_9_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_9_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_9_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_9_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_9_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_9_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_9_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_9_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_9_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_1_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_1_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_1_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_1_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_1_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_1_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_1_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_1_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_1_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_1_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_1_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_1_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_10_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_10_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_10_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_10_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_10_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_10_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_10_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_10_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_10_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_10_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_10_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_10_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_2_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_2_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_2_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_2_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_2_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_2_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_2_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_2_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_2_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_2_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_2_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_2_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TM_PIO_11_LOCK_SHIFT                                                  (31U)
#define CTRL_CONF_TM_PIO_11_LOCK_MASK                                                   (0x80000000U)

#define CTRL_CONF_TM_PIO_11_SLEWCTRL_SHIFT                                              (19U)
#define CTRL_CONF_TM_PIO_11_SLEWCTRL_MASK                                               (0x00080000U)

#define CTRL_CONF_TM_PIO_11_RXACTIVE_SHIFT                                              (18U)
#define CTRL_CONF_TM_PIO_11_RXACTIVE_MASK                                               (0x00040000U)

#define CTRL_CONF_TM_PIO_11_PUTYPESEL_SHIFT                                             (17U)
#define CTRL_CONF_TM_PIO_11_PUTYPESEL_MASK                                              (0x00020000U)

#define CTRL_CONF_TM_PIO_11_PUDEN_SHIFT                                                 (16U)
#define CTRL_CONF_TM_PIO_11_PUDEN_MASK                                                  (0x00010000U)

#define CTRL_CONF_TM_PIO_11_MMODE_SHIFT                                                 (0U)
#define CTRL_CONF_TM_PIO_11_MMODE_MASK                                                  (0x0000000fU)

#define CTRL_CONF_TM_PIO_3_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_TM_PIO_3_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_TM_PIO_3_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_TM_PIO_3_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_TM_PIO_3_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_TM_PIO_3_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_TM_PIO_3_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_TM_PIO_3_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_TM_PIO_3_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_TM_PIO_3_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_TM_PIO_3_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_TM_PIO_3_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TAMPER_EVT_LOCK_SHIFT                                                 (31U)
#define CTRL_CONF_TAMPER_EVT_LOCK_MASK                                                  (0x80000000U)

#define CTRL_CONF_TAMPER_EVT_SLEWCTRL_SHIFT                                             (19U)
#define CTRL_CONF_TAMPER_EVT_SLEWCTRL_MASK                                              (0x00080000U)

#define CTRL_CONF_TAMPER_EVT_RXACTIVE_SHIFT                                             (18U)
#define CTRL_CONF_TAMPER_EVT_RXACTIVE_MASK                                              (0x00040000U)

#define CTRL_CONF_TAMPER_EVT_PUTYPESEL_SHIFT                                            (17U)
#define CTRL_CONF_TAMPER_EVT_PUTYPESEL_MASK                                             (0x00020000U)

#define CTRL_CONF_TAMPER_EVT_PUDEN_SHIFT                                                (16U)
#define CTRL_CONF_TAMPER_EVT_PUDEN_MASK                                                 (0x00010000U)

#define CTRL_CONF_TAMPER_EVT_MMODE_SHIFT                                                (0U)
#define CTRL_CONF_TAMPER_EVT_MMODE_MASK                                                 (0x0000000fU)

#define CTRL_CONF_XDMA_EVT_INTR0_LOCK_SHIFT                                             (31U)
#define CTRL_CONF_XDMA_EVT_INTR0_LOCK_MASK                                              (0x80000000U)

#define CTRL_CONF_XDMA_EVT_INTR0_SLEWCTRL_SHIFT                                         (19U)
#define CTRL_CONF_XDMA_EVT_INTR0_SLEWCTRL_MASK                                          (0x00080000U)

#define CTRL_CONF_XDMA_EVT_INTR0_RXACTIVE_SHIFT                                         (18U)
#define CTRL_CONF_XDMA_EVT_INTR0_RXACTIVE_MASK                                          (0x00040000U)

#define CTRL_CONF_XDMA_EVT_INTR0_PUTYPESEL_SHIFT                                        (17U)
#define CTRL_CONF_XDMA_EVT_INTR0_PUTYPESEL_MASK                                         (0x00020000U)

#define CTRL_CONF_XDMA_EVT_INTR0_PUDEN_SHIFT                                            (16U)
#define CTRL_CONF_XDMA_EVT_INTR0_PUDEN_MASK                                             (0x00010000U)

#define CTRL_CONF_XDMA_EVT_INTR0_MMODE_SHIFT                                            (0U)
#define CTRL_CONF_XDMA_EVT_INTR0_MMODE_MASK                                             (0x0000000fU)

#define CTRL_CONF_XDMA_EVT_INTR1_LOCK_SHIFT                                             (31U)
#define CTRL_CONF_XDMA_EVT_INTR1_LOCK_MASK                                              (0x80000000U)

#define CTRL_CONF_XDMA_EVT_INTR1_SLEWCTRL_SHIFT                                         (19U)
#define CTRL_CONF_XDMA_EVT_INTR1_SLEWCTRL_MASK                                          (0x00080000U)

#define CTRL_CONF_XDMA_EVT_INTR1_RXACTIVE_SHIFT                                         (18U)
#define CTRL_CONF_XDMA_EVT_INTR1_RXACTIVE_MASK                                          (0x00040000U)

#define CTRL_CONF_XDMA_EVT_INTR1_PUTYPESEL_SHIFT                                        (17U)
#define CTRL_CONF_XDMA_EVT_INTR1_PUTYPESEL_MASK                                         (0x00020000U)

#define CTRL_CONF_XDMA_EVT_INTR1_PUDEN_SHIFT                                            (16U)
#define CTRL_CONF_XDMA_EVT_INTR1_PUDEN_MASK                                             (0x00010000U)

#define CTRL_CONF_XDMA_EVT_INTR1_MMODE_SHIFT                                            (0U)
#define CTRL_CONF_XDMA_EVT_INTR1_MMODE_MASK                                             (0x0000000fU)

#define CTRL_CONF_CLKREQ_LOCK_SHIFT                                                     (31U)
#define CTRL_CONF_CLKREQ_LOCK_MASK                                                      (0x80000000U)

#define CTRL_CONF_CLKREQ_SLEWCTRL_SHIFT                                                 (19U)
#define CTRL_CONF_CLKREQ_SLEWCTRL_MASK                                                  (0x00080000U)

#define CTRL_CONF_CLKREQ_RXACTIVE_SHIFT                                                 (18U)
#define CTRL_CONF_CLKREQ_RXACTIVE_MASK                                                  (0x00040000U)

#define CTRL_CONF_CLKREQ_PUTYPESEL_SHIFT                                                (17U)
#define CTRL_CONF_CLKREQ_PUTYPESEL_MASK                                                 (0x00020000U)

#define CTRL_CONF_CLKREQ_PUDEN_SHIFT                                                    (16U)
#define CTRL_CONF_CLKREQ_PUDEN_MASK                                                     (0x00010000U)

#define CTRL_CONF_CLKREQ_MMODE_SHIFT                                                    (0U)
#define CTRL_CONF_CLKREQ_MMODE_MASK                                                     (0x0000000fU)

#define CTRL_CONF_NRESETIN_OUT_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_NRESETIN_OUT_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_NRESETIN_OUT_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_NRESETIN_OUT_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_NRESETIN_OUT_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_NRESETIN_OUT_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_NRESETIN_OUT_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_NRESETIN_OUT_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_NRESETIN_OUT_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_NRESETIN_OUT_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_NRESETIN_OUT_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_NRESETIN_OUT_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_PORZ_LOCK_SHIFT                                                       (31U)
#define CTRL_CONF_PORZ_LOCK_MASK                                                        (0x80000000U)

#define CTRL_CONF_PORZ_SLEWCTRL_SHIFT                                                   (19U)
#define CTRL_CONF_PORZ_SLEWCTRL_MASK                                                    (0x00080000U)

#define CTRL_CONF_PORZ_RXACTIVE_SHIFT                                                   (18U)
#define CTRL_CONF_PORZ_RXACTIVE_MASK                                                    (0x00040000U)

#define CTRL_CONF_PORZ_PUTYPESEL_SHIFT                                                  (17U)
#define CTRL_CONF_PORZ_PUTYPESEL_MASK                                                   (0x00020000U)

#define CTRL_CONF_PORZ_PUDEN_SHIFT                                                      (16U)
#define CTRL_CONF_PORZ_PUDEN_MASK                                                       (0x00010000U)

#define CTRL_CONF_PORZ_MMODE_SHIFT                                                      (0U)
#define CTRL_CONF_PORZ_MMODE_MASK                                                       (0x0000000fU)

#define CTRL_CONF_NNMI_LOCK_SHIFT                                                       (31U)
#define CTRL_CONF_NNMI_LOCK_MASK                                                        (0x80000000U)

#define CTRL_CONF_NNMI_SLEWCTRL_SHIFT                                                   (19U)
#define CTRL_CONF_NNMI_SLEWCTRL_MASK                                                    (0x00080000U)

#define CTRL_CONF_NNMI_RXACTIVE_SHIFT                                                   (18U)
#define CTRL_CONF_NNMI_RXACTIVE_MASK                                                    (0x00040000U)

#define CTRL_CONF_NNMI_PUTYPESEL_SHIFT                                                  (17U)
#define CTRL_CONF_NNMI_PUTYPESEL_MASK                                                   (0x00020000U)

#define CTRL_CONF_NNMI_PUDEN_SHIFT                                                      (16U)
#define CTRL_CONF_NNMI_PUDEN_MASK                                                       (0x00010000U)

#define CTRL_CONF_NNMI_MMODE_SHIFT                                                      (0U)
#define CTRL_CONF_NNMI_MMODE_MASK                                                       (0x0000000fU)

#define CTRL_CONF_OSC0_IN_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_OSC0_IN_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_OSC0_IN_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_OSC0_IN_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_OSC0_IN_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_OSC0_IN_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_OSC0_IN_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_OSC0_IN_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_OSC0_IN_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_OSC0_IN_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_OSC0_IN_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_OSC0_IN_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_OSC0_OUT_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_OSC0_OUT_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_OSC0_OUT_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_OSC0_OUT_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_OSC0_OUT_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_OSC0_OUT_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_OSC0_OUT_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_OSC0_OUT_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_OSC0_OUT_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_OSC0_OUT_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_OSC0_OUT_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_OSC0_OUT_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_TMS_LOCK_SHIFT                                                        (31U)
#define CTRL_CONF_TMS_LOCK_MASK                                                         (0x80000000U)

#define CTRL_CONF_TMS_SLEWCTRL_SHIFT                                                    (19U)
#define CTRL_CONF_TMS_SLEWCTRL_MASK                                                     (0x00080000U)

#define CTRL_CONF_TMS_RXACTIVE_SHIFT                                                    (18U)
#define CTRL_CONF_TMS_RXACTIVE_MASK                                                     (0x00040000U)

#define CTRL_CONF_TMS_PUTYPESEL_SHIFT                                                   (17U)
#define CTRL_CONF_TMS_PUTYPESEL_MASK                                                    (0x00020000U)

#define CTRL_CONF_TMS_PUDEN_SHIFT                                                       (16U)
#define CTRL_CONF_TMS_PUDEN_MASK                                                        (0x00010000U)

#define CTRL_CONF_TMS_MMODE_SHIFT                                                       (0U)
#define CTRL_CONF_TMS_MMODE_MASK                                                        (0x0000000fU)

#define CTRL_CONF_TDI_LOCK_SHIFT                                                        (31U)
#define CTRL_CONF_TDI_LOCK_MASK                                                         (0x80000000U)

#define CTRL_CONF_TDI_SLEWCTRL_SHIFT                                                    (19U)
#define CTRL_CONF_TDI_SLEWCTRL_MASK                                                     (0x00080000U)

#define CTRL_CONF_TDI_RXACTIVE_SHIFT                                                    (18U)
#define CTRL_CONF_TDI_RXACTIVE_MASK                                                     (0x00040000U)

#define CTRL_CONF_TDI_PUTYPESEL_SHIFT                                                   (17U)
#define CTRL_CONF_TDI_PUTYPESEL_MASK                                                    (0x00020000U)

#define CTRL_CONF_TDI_PUDEN_SHIFT                                                       (16U)
#define CTRL_CONF_TDI_PUDEN_MASK                                                        (0x00010000U)

#define CTRL_CONF_TDI_MMODE_SHIFT                                                       (0U)
#define CTRL_CONF_TDI_MMODE_MASK                                                        (0x0000000fU)

#define CTRL_CONF_TDO_LOCK_SHIFT                                                        (31U)
#define CTRL_CONF_TDO_LOCK_MASK                                                         (0x80000000U)

#define CTRL_CONF_TDO_SLEWCTRL_SHIFT                                                    (19U)
#define CTRL_CONF_TDO_SLEWCTRL_MASK                                                     (0x00080000U)

#define CTRL_CONF_TDO_RXACTIVE_SHIFT                                                    (18U)
#define CTRL_CONF_TDO_RXACTIVE_MASK                                                     (0x00040000U)

#define CTRL_CONF_TDO_PUTYPESEL_SHIFT                                                   (17U)
#define CTRL_CONF_TDO_PUTYPESEL_MASK                                                    (0x00020000U)

#define CTRL_CONF_TDO_PUDEN_SHIFT                                                       (16U)
#define CTRL_CONF_TDO_PUDEN_MASK                                                        (0x00010000U)

#define CTRL_CONF_TDO_MMODE_SHIFT                                                       (0U)
#define CTRL_CONF_TDO_MMODE_MASK                                                        (0x0000000fU)

#define CTRL_CONF_TCK_LOCK_SHIFT                                                        (31U)
#define CTRL_CONF_TCK_LOCK_MASK                                                         (0x80000000U)

#define CTRL_CONF_TCK_SLEWCTRL_SHIFT                                                    (19U)
#define CTRL_CONF_TCK_SLEWCTRL_MASK                                                     (0x00080000U)

#define CTRL_CONF_TCK_RXACTIVE_SHIFT                                                    (18U)
#define CTRL_CONF_TCK_RXACTIVE_MASK                                                     (0x00040000U)

#define CTRL_CONF_TCK_PUTYPESEL_SHIFT                                                   (17U)
#define CTRL_CONF_TCK_PUTYPESEL_MASK                                                    (0x00020000U)

#define CTRL_CONF_TCK_PUDEN_SHIFT                                                       (16U)
#define CTRL_CONF_TCK_PUDEN_MASK                                                        (0x00010000U)

#define CTRL_CONF_TCK_MMODE_SHIFT                                                       (0U)
#define CTRL_CONF_TCK_MMODE_MASK                                                        (0x0000000fU)

#define CTRL_CONF_NTRST_LOCK_SHIFT                                                      (31U)
#define CTRL_CONF_NTRST_LOCK_MASK                                                       (0x80000000U)

#define CTRL_CONF_NTRST_SLEWCTRL_SHIFT                                                  (19U)
#define CTRL_CONF_NTRST_SLEWCTRL_MASK                                                   (0x00080000U)

#define CTRL_CONF_NTRST_RXACTIVE_SHIFT                                                  (18U)
#define CTRL_CONF_NTRST_RXACTIVE_MASK                                                   (0x00040000U)

#define CTRL_CONF_NTRST_PUTYPESEL_SHIFT                                                 (17U)
#define CTRL_CONF_NTRST_PUTYPESEL_MASK                                                  (0x00020000U)

#define CTRL_CONF_NTRST_PUDEN_SHIFT                                                     (16U)
#define CTRL_CONF_NTRST_PUDEN_MASK                                                      (0x00010000U)

#define CTRL_CONF_NTRST_MMODE_SHIFT                                                     (0U)
#define CTRL_CONF_NTRST_MMODE_MASK                                                      (0x0000000fU)

#define CTRL_CONF_EMU0_LOCK_SHIFT                                                       (31U)
#define CTRL_CONF_EMU0_LOCK_MASK                                                        (0x80000000U)

#define CTRL_CONF_EMU0_SLEWCTRL_SHIFT                                                   (19U)
#define CTRL_CONF_EMU0_SLEWCTRL_MASK                                                    (0x00080000U)

#define CTRL_CONF_EMU0_RXACTIVE_SHIFT                                                   (18U)
#define CTRL_CONF_EMU0_RXACTIVE_MASK                                                    (0x00040000U)

#define CTRL_CONF_EMU0_PUTYPESEL_SHIFT                                                  (17U)
#define CTRL_CONF_EMU0_PUTYPESEL_MASK                                                   (0x00020000U)

#define CTRL_CONF_EMU0_PUDEN_SHIFT                                                      (16U)
#define CTRL_CONF_EMU0_PUDEN_MASK                                                       (0x00010000U)

#define CTRL_CONF_EMU0_MMODE_SHIFT                                                      (0U)
#define CTRL_CONF_EMU0_MMODE_MASK                                                       (0x0000000fU)

#define CTRL_CONF_EMU1_LOCK_SHIFT                                                       (31U)
#define CTRL_CONF_EMU1_LOCK_MASK                                                        (0x80000000U)

#define CTRL_CONF_EMU1_SLEWCTRL_SHIFT                                                   (19U)
#define CTRL_CONF_EMU1_SLEWCTRL_MASK                                                    (0x00080000U)

#define CTRL_CONF_EMU1_RXACTIVE_SHIFT                                                   (18U)
#define CTRL_CONF_EMU1_RXACTIVE_MASK                                                    (0x00040000U)

#define CTRL_CONF_EMU1_PUTYPESEL_SHIFT                                                  (17U)
#define CTRL_CONF_EMU1_PUTYPESEL_MASK                                                   (0x00020000U)

#define CTRL_CONF_EMU1_PUDEN_SHIFT                                                      (16U)
#define CTRL_CONF_EMU1_PUDEN_MASK                                                       (0x00010000U)

#define CTRL_CONF_EMU1_MMODE_SHIFT                                                      (0U)
#define CTRL_CONF_EMU1_MMODE_MASK                                                       (0x0000000fU)

#define CTRL_CONF_OSC1_IN_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_OSC1_IN_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_OSC1_IN_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_OSC1_IN_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_OSC1_IN_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_OSC1_IN_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_OSC1_IN_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_OSC1_IN_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_OSC1_IN_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_OSC1_IN_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_OSC1_IN_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_OSC1_IN_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_OSC1_OUT_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_OSC1_OUT_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_OSC1_OUT_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_OSC1_OUT_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_OSC1_OUT_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_OSC1_OUT_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_OSC1_OUT_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_OSC1_OUT_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_OSC1_OUT_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_OSC1_OUT_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_OSC1_OUT_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_OSC1_OUT_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_RTC_PORZ_LOCK_SHIFT                                                   (31U)
#define CTRL_CONF_RTC_PORZ_LOCK_MASK                                                    (0x80000000U)

#define CTRL_CONF_RTC_PORZ_SLEWCTRL_SHIFT                                               (19U)
#define CTRL_CONF_RTC_PORZ_SLEWCTRL_MASK                                                (0x00080000U)

#define CTRL_CONF_RTC_PORZ_RXACTIVE_SHIFT                                               (18U)
#define CTRL_CONF_RTC_PORZ_RXACTIVE_MASK                                                (0x00040000U)

#define CTRL_CONF_RTC_PORZ_PUTYPESEL_SHIFT                                              (17U)
#define CTRL_CONF_RTC_PORZ_PUTYPESEL_MASK                                               (0x00020000U)

#define CTRL_CONF_RTC_PORZ_PUDEN_SHIFT                                                  (16U)
#define CTRL_CONF_RTC_PORZ_PUDEN_MASK                                                   (0x00010000U)

#define CTRL_CONF_RTC_PORZ_MMODE_SHIFT                                                  (0U)
#define CTRL_CONF_RTC_PORZ_MMODE_MASK                                                   (0x0000000fU)

#define CTRL_CONF_EXT_WAKEUP0_LOCK_SHIFT                                                (31U)
#define CTRL_CONF_EXT_WAKEUP0_LOCK_MASK                                                 (0x80000000U)

#define CTRL_CONF_EXT_WAKEUP0_SLEWCTRL_SHIFT                                            (19U)
#define CTRL_CONF_EXT_WAKEUP0_SLEWCTRL_MASK                                             (0x00080000U)

#define CTRL_CONF_EXT_WAKEUP0_RXACTIVE_SHIFT                                            (18U)
#define CTRL_CONF_EXT_WAKEUP0_RXACTIVE_MASK                                             (0x00040000U)

#define CTRL_CONF_EXT_WAKEUP0_PUTYPESEL_SHIFT                                           (17U)
#define CTRL_CONF_EXT_WAKEUP0_PUTYPESEL_MASK                                            (0x00020000U)

#define CTRL_CONF_EXT_WAKEUP0_PUDEN_SHIFT                                               (16U)
#define CTRL_CONF_EXT_WAKEUP0_PUDEN_MASK                                                (0x00010000U)

#define CTRL_CONF_EXT_WAKEUP0_MMODE_SHIFT                                               (0U)
#define CTRL_CONF_EXT_WAKEUP0_MMODE_MASK                                                (0x0000000fU)

#define CTRL_CONF_PMIC_POWER_EN0_LOCK_SHIFT                                             (31U)
#define CTRL_CONF_PMIC_POWER_EN0_LOCK_MASK                                              (0x80000000U)

#define CTRL_CONF_PMIC_POWER_EN0_SLEWCTRL_SHIFT                                         (19U)
#define CTRL_CONF_PMIC_POWER_EN0_SLEWCTRL_MASK                                          (0x00080000U)

#define CTRL_CONF_PMIC_POWER_EN0_RXACTIVE_SHIFT                                         (18U)
#define CTRL_CONF_PMIC_POWER_EN0_RXACTIVE_MASK                                          (0x00040000U)

#define CTRL_CONF_PMIC_POWER_EN0_PUTYPESEL_SHIFT                                        (17U)
#define CTRL_CONF_PMIC_POWER_EN0_PUTYPESEL_MASK                                         (0x00020000U)

#define CTRL_CONF_PMIC_POWER_EN0_PUDEN_SHIFT                                            (16U)
#define CTRL_CONF_PMIC_POWER_EN0_PUDEN_MASK                                             (0x00010000U)

#define CTRL_CONF_PMIC_POWER_EN0_MMODE_SHIFT                                            (0U)
#define CTRL_CONF_PMIC_POWER_EN0_MMODE_MASK                                             (0x0000000fU)

#define CTRL_CONF_USB0_DRVVBUS_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_USB0_DRVVBUS_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_USB0_DRVVBUS_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_USB0_DRVVBUS_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_USB0_DRVVBUS_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_USB0_DRVVBUS_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_USB0_DRVVBUS_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_USB0_DRVVBUS_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_USB0_DRVVBUS_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_USB0_DRVVBUS_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_USB0_DRVVBUS_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_USB0_DRVVBUS_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_USB0_DRVVBUS_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_USB0_DRVVBUS_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_USB0_DRVVBUS_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_USB0_DRVVBUS_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_USB0_DRVVBUS_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_USB0_DRVVBUS_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_USB0_DRVVBUS_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_USB0_DRVVBUS_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_USB0_DRVVBUS_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_USB0_DRVVBUS_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_USB0_DRVVBUS_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_USB0_DRVVBUS_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_USB0_DRVVBUS_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_USB0_DRVVBUS_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_USB1_DRVVBUS_LOCK_SHIFT                                               (31U)
#define CTRL_CONF_USB1_DRVVBUS_LOCK_MASK                                                (0x80000000U)

#define CTRL_CONF_USB1_DRVVBUS_WUEVT_SHIFT                                              (30U)
#define CTRL_CONF_USB1_DRVVBUS_WUEVT_MASK                                               (0x40000000U)

#define CTRL_CONF_USB1_DRVVBUS_WUEN_SHIFT                                               (29U)
#define CTRL_CONF_USB1_DRVVBUS_WUEN_MASK                                                (0x20000000U)

#define CTRL_CONF_USB1_DRVVBUS_DSPULLTYPESELECT_SHIFT                                   (28U)
#define CTRL_CONF_USB1_DRVVBUS_DSPULLTYPESELECT_MASK                                    (0x10000000U)

#define CTRL_CONF_USB1_DRVVBUS_DSPULLUDEN_SHIFT                                         (27U)
#define CTRL_CONF_USB1_DRVVBUS_DSPULLUDEN_MASK                                          (0x08000000U)

#define CTRL_CONF_USB1_DRVVBUS_DS0OUTVALUE_SHIFT                                        (26U)
#define CTRL_CONF_USB1_DRVVBUS_DS0OUTVALUE_MASK                                         (0x04000000U)

#define CTRL_CONF_USB1_DRVVBUS_DS0OUTEN_SHIFT                                           (25U)
#define CTRL_CONF_USB1_DRVVBUS_DS0OUTEN_MASK                                            (0x02000000U)

#define CTRL_CONF_USB1_DRVVBUS_DS0EN_SHIFT                                              (24U)
#define CTRL_CONF_USB1_DRVVBUS_DS0EN_MASK                                               (0x01000000U)

#define CTRL_CONF_USB1_DRVVBUS_SLEWCTRL_SHIFT                                           (19U)
#define CTRL_CONF_USB1_DRVVBUS_SLEWCTRL_MASK                                            (0x00080000U)

#define CTRL_CONF_USB1_DRVVBUS_RXACTIVE_SHIFT                                           (18U)
#define CTRL_CONF_USB1_DRVVBUS_RXACTIVE_MASK                                            (0x00040000U)

#define CTRL_CONF_USB1_DRVVBUS_PUTYPESEL_SHIFT                                          (17U)
#define CTRL_CONF_USB1_DRVVBUS_PUTYPESEL_MASK                                           (0x00020000U)

#define CTRL_CONF_USB1_DRVVBUS_PUDEN_SHIFT                                              (16U)
#define CTRL_CONF_USB1_DRVVBUS_PUDEN_MASK                                               (0x00010000U)

#define CTRL_CONF_USB1_DRVVBUS_MMODE_SHIFT                                              (0U)
#define CTRL_CONF_USB1_DRVVBUS_MMODE_MASK                                               (0x0000000fU)

#define CTRL_CONF_TEST_EN_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_TEST_EN_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_TEST_EN_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_TEST_EN_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_TEST_EN_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_TEST_EN_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_TEST_EN_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_TEST_EN_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_TEST_EN_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_TEST_EN_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_TEST_EN_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_TEST_EN_MMODE_MASK                                                    (0x0000000fU)

#define CTRL_CONF_IFORCE_LOCK_SHIFT                                                     (31U)
#define CTRL_CONF_IFORCE_LOCK_MASK                                                      (0x80000000U)

#define CTRL_CONF_IFORCE_SLEWCTRL_SHIFT                                                 (19U)
#define CTRL_CONF_IFORCE_SLEWCTRL_MASK                                                  (0x00080000U)

#define CTRL_CONF_IFORCE_RXACTIVE_SHIFT                                                 (18U)
#define CTRL_CONF_IFORCE_RXACTIVE_MASK                                                  (0x00040000U)

#define CTRL_CONF_IFORCE_PUTYPESEL_SHIFT                                                (17U)
#define CTRL_CONF_IFORCE_PUTYPESEL_MASK                                                 (0x00020000U)

#define CTRL_CONF_IFORCE_PUDEN_SHIFT                                                    (16U)
#define CTRL_CONF_IFORCE_PUDEN_MASK                                                     (0x00010000U)

#define CTRL_CONF_IFORCE_MMODE_SHIFT                                                    (0U)
#define CTRL_CONF_IFORCE_MMODE_MASK                                                     (0x0000000fU)

#define CTRL_CONF_VSENSE_LOCK_SHIFT                                                     (31U)
#define CTRL_CONF_VSENSE_LOCK_MASK                                                      (0x80000000U)

#define CTRL_CONF_VSENSE_SLEWCTRL_SHIFT                                                 (19U)
#define CTRL_CONF_VSENSE_SLEWCTRL_MASK                                                  (0x00080000U)

#define CTRL_CONF_VSENSE_RXACTIVE_SHIFT                                                 (18U)
#define CTRL_CONF_VSENSE_RXACTIVE_MASK                                                  (0x00040000U)

#define CTRL_CONF_VSENSE_PUTYPESEL_SHIFT                                                (17U)
#define CTRL_CONF_VSENSE_PUTYPESEL_MASK                                                 (0x00020000U)

#define CTRL_CONF_VSENSE_PUDEN_SHIFT                                                    (16U)
#define CTRL_CONF_VSENSE_PUDEN_MASK                                                     (0x00010000U)

#define CTRL_CONF_VSENSE_MMODE_SHIFT                                                    (0U)
#define CTRL_CONF_VSENSE_MMODE_MASK                                                     (0x0000000fU)

#define CTRL_CONF_TESTOUT_LOCK_SHIFT                                                    (31U)
#define CTRL_CONF_TESTOUT_LOCK_MASK                                                     (0x80000000U)

#define CTRL_CONF_TESTOUT_SLEWCTRL_SHIFT                                                (19U)
#define CTRL_CONF_TESTOUT_SLEWCTRL_MASK                                                 (0x00080000U)

#define CTRL_CONF_TESTOUT_RXACTIVE_SHIFT                                                (18U)
#define CTRL_CONF_TESTOUT_RXACTIVE_MASK                                                 (0x00040000U)

#define CTRL_CONF_TESTOUT_PUTYPESEL_SHIFT                                               (17U)
#define CTRL_CONF_TESTOUT_PUTYPESEL_MASK                                                (0x00020000U)

#define CTRL_CONF_TESTOUT_PUDEN_SHIFT                                                   (16U)
#define CTRL_CONF_TESTOUT_PUDEN_MASK                                                    (0x00010000U)

#define CTRL_CONF_TESTOUT_MMODE_SHIFT                                                   (0U)
#define CTRL_CONF_TESTOUT_MMODE_MASK                                                    (0x0000000fU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CONTROL_AM43XX_H_ */

