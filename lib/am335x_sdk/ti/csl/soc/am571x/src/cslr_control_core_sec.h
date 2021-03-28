/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_CONTROL_CORE_SEC_H
#define CSLR_CONTROL_CORE_SEC_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 SECURITY_MASTER_CTRL_REG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 L4_CFG_ROLES_0_LOWER;
    volatile Uint32 L4_CFG_ROLES_0_UPPER;
    volatile Uint32 L4_CFG_MEMBERS_0;
    volatile Uint8  RSVD1[4];
    volatile Uint32 L4_CFG_ROLES_1_LOWER;
    volatile Uint32 L4_CFG_ROLES_1_UPPER;
    volatile Uint32 L4_CFG_MEMBERS_1;
    volatile Uint8  RSVD2[4];
    volatile Uint32 L4_CFG_ROLES_5_LOWER;
    volatile Uint32 L4_CFG_ROLES_5_UPPER;
    volatile Uint32 L4_CFG_MEMBERS_5;
    volatile Uint8  RSVD3[4];
    volatile Uint32 L4_PER_1_ROLES_0_LOWER;
    volatile Uint32 L4_PER_1_ROLES_0_UPPER;
    volatile Uint32 L4_PER_1_MEMBERS_0;
    volatile Uint8  RSVD4[4];
    volatile Uint32 L4_PER_1_ROLES_1_LOWER;
    volatile Uint32 L4_PER_1_ROLES_1_UPPER;
    volatile Uint32 L4_PER_1_MEMBERS_1;
    volatile Uint8  RSVD5[4];
    volatile Uint32 L4_PER_2_ROLES_0_LOWER;
    volatile Uint32 L4_PER_2_ROLES_0_UPPER;
    volatile Uint32 L4_PER_2_MEMBERS_0;
    volatile Uint8  RSVD6[4];
    volatile Uint32 L4_PER_3_ROLES_0_LOWER;
    volatile Uint32 L4_PER_3_ROLES_0_UPPER;
    volatile Uint32 L4_PER_3_MEMBER_0;
    volatile Uint8  RSVD7[4];
    volatile Uint32 L4_WKUP_ROLES_0_LOWER;
    volatile Uint32 L4_WKUP_ROLES_0_UPPER;
    volatile Uint32 L4_WKUP_MEMBERS_0;
    volatile Uint8  RSVD8[4];
    volatile Uint32 L4_WKUP_ROLES_1_LOWER;
    volatile Uint32 L4_WKUP_ROLES_1_UPPER;
    volatile Uint32 L4_WKUP_MEMBERS_1;
    volatile Uint8  RSVD9[4];
    volatile Uint32 L4_WKUP_ROLES_3_LOWER;
    volatile Uint32 L4_WKUP_ROLES_3_UPPER;
    volatile Uint32 L4_WKUP_MEMBERS_3;
    volatile Uint8  RSVD10[4];
    volatile Uint32 L4_WKUP_ROLES_4_LOWER;
    volatile Uint32 L4_WKUP_ROLES_4_UPPER;
    volatile Uint32 L4_WKUP_MEMBERS_4;
    volatile Uint8  RSVD11[68];
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_0;
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_1;
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_2;
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_3;
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_4;
    volatile Uint32 STD_FUSE_OPP_VMIN_GPU_5;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_0;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_1;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_2;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_3;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_4;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_5;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_6;
    volatile Uint32 STD_FUSE_OPP_VMIN_MPU_7;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_LVT_0;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_LVT_1;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_LVT_2;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_LVT_3;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_LVT_4;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_LVT_0;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_LVT_1;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_LVT_2;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_LVT_3;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_LVT_4;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_LVT_0;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_LVT_1;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_LVT_2;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_LVT_3;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_LVT_4;
    volatile Uint32 LDOSRAM_CORE_4_VOLTAGE_CTRL;
    volatile Uint32 LDOSRAM_CORE_5_VOLTAGE_CTRL;
    volatile Uint32 LDOSRAM_DSPEVE_2_VOLTAGE_CTRL;
    volatile Uint32 MEM_DFT_RW_DMM;
    volatile Uint32 MEM_DFT_RW_SAR_RAM;
    volatile Uint32 MEM_DFT_RW_OCMC_RAM;
    volatile Uint32 MEM_DFT_RW_OCMC_ROM;
    volatile Uint32 MEM_DFT_RW_SAR_ROM;
    volatile Uint32 MEM_DFT_RW_SDMA;
    volatile Uint32 MEM_DFT_RW_CDMA;
    volatile Uint32 MEM_DFT_RW_FPKA;
    volatile Uint32 MEM_DFT_RW_MMC;
    volatile Uint32 MEM_DFT_RW_UART;
    volatile Uint32 MEM_DFT_RW_DEBUGSS;
    volatile Uint32 MEM_DFT_RW_DCAN;
    volatile Uint32 MEM_DFT_RW_VCP;
    volatile Uint32 MEM_DFT_RW_I2C;
    volatile Uint32 MEM_DFT_RW_VIP;
    volatile Uint32 MEM_DFT_RW_VPE;
    volatile Uint32 MEM_DFT_RW_PRUSS;
    volatile Uint32 MEM_DFT_RW_GMAC_SW;
    volatile Uint32 MEM_DFT_RW_USB;
    volatile Uint32 MEM_DFT_RW_PCIE;
    volatile Uint32 MEM_DFT_RW_MLB;
    volatile Uint32 MEM_DFT_RW_EDMA_TC;
    volatile Uint32 MEM_DFT_RW_EDMA_TPCC;
    volatile Uint32 MEM_DFT_RW_DSS;
    volatile Uint32 MEM_DFT_RW_PBIST;
    volatile Uint32 MEM_DFT_RW_IPU;
    volatile Uint32 MEM_DFT_RW_MPU;
    volatile Uint32 MEM_DFT_RW_IVA;
    volatile Uint32 MEM_DFT_RW_GPU;
    volatile Uint32 MEM_DFT_RW_BB2D;
    volatile Uint32 MEM_DFT_RW_DSP;
    volatile Uint32 MEM_DFT_RW_EVE1;
    volatile Uint32 MEM_DFT_RW_EVE2;
    volatile Uint32 SMA_SW_2;
    volatile Uint32 SMA_SW_3;
    volatile Uint32 SMA_SW_4;
    volatile Uint32 SMA_SW_5;
    volatile Uint32 SMA_SW_6;
    volatile Uint32 SMA_SW_7;
    volatile Uint32 SMA_SW_8;
    volatile Uint32 SMA_SW_9;
    volatile Uint32 PCIESS1_PCS1;
    volatile Uint32 PCIESS1_PCS2;
    volatile Uint32 PCIESS2_PCS1;
    volatile Uint32 PCIESS2_PCS2;
    volatile Uint32 PCIE_PCS;
    volatile Uint32 PCIE_PCS_REVISION;
    volatile Uint32 PCIE_CONTROL;
    volatile Uint32 PHY_POWER_PCIESS1;
    volatile Uint32 PHY_POWER_PCIESS2;
} CSL_control_core_secRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Security Master Control Register */
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG           (0x0U)

/* L4 Config Protection Group 0 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER               (0x10U)

/* L4 Config Protection Group 0 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER               (0x14U)

/* L4 Config Protection Group 0 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0                   (0x18U)

/* L4 Config Protection Group 1 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER               (0x20U)

/* L4 Config Protection Group 1 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER               (0x24U)

/* L4 Config Protection Group 1 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1                   (0x28U)

/* L4 Config Protection Group 5 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER               (0x30U)

/* L4 Config Protection Group 5 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER               (0x34U)

/* L4 Config Protection Group 5 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5                   (0x38U)

/* L4 Per 1 Protection Group 0 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER             (0x40U)

/* L4 Per 1 Protection Group 0 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER             (0x44U)

/* L4 Per 1 Protection Group 0 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0                 (0x48U)

/* L4 Per 1 Protection Group 1 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER             (0x50U)

/* L4 Per 1 Protection Group 1 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER             (0x54U)

/* L4 Per 1 Protection Group 1 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1                 (0x58U)

/* L4 Per 2 Protection Group 0 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER             (0x60U)

/* L4 Per 2 Protection Group 0 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER             (0x64U)

/* L4 Per 2 Protection Group 0 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0                 (0x68U)

/* L4 Per 3 Protection Group 0 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER             (0x70U)

/* L4 Per 3 Protection Group 0 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER             (0x74U)

/* L4 Per 3 Protection Group 0 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0                  (0x78U)

/* L4 Wakeup Protection Group 0 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER              (0x80U)

/* L4 Wakeup Protection Group 0 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER              (0x84U)

/* L4 Wakeup Protection Group 0 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0                  (0x88U)

/* L4 Wakeup Protection Group 1 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER              (0x90U)

/* L4 Wakeup Protection Group 1 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER              (0x94U)

/* L4 Wakeup Protection Group 1 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1                  (0x98U)

/* L4 Wakeup Protection Group 3 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER              (0xA0U)

/* L4 Wakeup Protection Group 3 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER              (0xA4U)

/* L4 Wakeup Protection Group 3 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3                  (0xA8U)

/* L4 Wakeup Protection Group 4 Roles [31:0] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER              (0xB0U)

/* L4 Wakeup Protection Group 4 Roles [63:32] */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER              (0xB4U)

/* L4 Wakeup Protection Group 4 Members and lock */
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4                  (0xB8U)

/* Standard Fuse OPP Vmin_GPU [31:0]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0            (0x100U)

/* Standard Fuse OPP Vmin_GPU [63:32]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1            (0x104U)

/* Standard Fuse OPP Vmin_GPU [95:64]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2            (0x108U)

/* Standard Fuse OPP Vmin_GPU [127:96]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3            (0x10CU)

/* Standard Fuse OPP Vmin_GPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4            (0x110U)

/* Standard Fuse OPP Vmin_GPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5            (0x114U)

/* Standard Fuse OPP Vmin_MPU [31:0]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0            (0x118U)

/* Standard Fuse OPP Vmin_MPU [63:32]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1            (0x11CU)

/* Standard Fuse OPP Vmin_MPU [95:64]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2            (0x120U)

/* Standard Fuse OPP Vmin_MPU [127:96]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3            (0x124U)

/* Standard Fuse OPP Vmin_MPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4            (0x128U)

/* Standard Fuse OPP Vmin_MPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5            (0x12CU)

/* Standard Fuse OPP Vmin_MPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6            (0x130U)

/* Standard Fuse OPP Vmin_MPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7            (0x134U)

/* Standard Fuse OPP VDD_GPU [31:0]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0      (0x138U)

/* Standard Fuse OPP VDD_GPU [63:32]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1      (0x13CU)

/* Standard Fuse OPP VDD_GPU [95:64]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2      (0x140U)

/* Standard Fuse OPP VDD_GPU [127:96]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3      (0x144U)

/* Standard Fuse OPP VDD_GPU [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4      (0x148U)

/* Standard Fuse OPP VDD_IVA [31:0]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0         (0x14CU)

/* Standard Fuse OPP VDD_IVA [63:32]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1         (0x150U)

/* Standard Fuse OPP VDD_IVA [95:64]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2         (0x154U)

/* Standard Fuse OPP VDD_IVA [127:96]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3         (0x158U)

/* Standard Fuse OPP VDD_IVA [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4         (0x15CU)

/* Standard Fuse OPP VDD_CORE [31:0]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0        (0x160U)

/* Standard Fuse OPP VDD_CORE [63:32]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1        (0x164U)

/* Standard Fuse OPP VDD_CORE [95:64]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2        (0x168U)

/* Standard Fuse OPP VDD_CORE [127:96]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3        (0x16CU)

/* Standard Fuse OPP VDD_CORE [159:128]. Register shows part of the chip eFuse 
 * configuration on the OCP interface. Reading at the address of one of these 
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4        (0x170U)

/* CORE 4th SRAM LDO Control register */
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL        (0x174U)

/* CORE 5th SRAM LDO Control register */
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL        (0x178U)

/* DSPEVE 2nd SRAM LDO Control register */
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL      (0x17CU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM                     (0x180U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM                 (0x184U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM                (0x188U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM                (0x18CU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM                 (0x190U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA                    (0x194U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA                    (0x198U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA                    (0x19CU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC                     (0x1A0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART                    (0x1A4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS                 (0x1A8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN                    (0x1ACU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP                     (0x1B0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C                     (0x1B4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP                     (0x1B8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE                     (0x1BCU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS                   (0x1C0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW                 (0x1C4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB                     (0x1C8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE                    (0x1CCU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB                     (0x1D0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC                 (0x1D4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC               (0x1D8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS                     (0x1DCU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST                   (0x1E0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU                     (0x1E4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU                     (0x1E8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA                     (0x1ECU)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU                     (0x1F0U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D                    (0x1F4U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP                     (0x1F8U)

/* Memory DFT read-write software control */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1                    (0x1FCU)

/* MEM_DFT_RW_EVE2 */
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2                    (0x200U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_2                           (0x204U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_3                           (0x208U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_4                           (0x20CU)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_5                           (0x210U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_6                           (0x214U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SEC_SMA_SW_7                           (0x218U)

/* Test control inputs used by the module */
#define CSL_CONTROL_CORE_SEC_SMA_SW_8                           (0x21CU)

/* Test control inputs used by the module */
#define CSL_CONTROL_CORE_SEC_SMA_SW_9                           (0x220U)

/* PCIESS1_PCS1 */
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1                       (0x224U)

/* PCIESS1_PCS2 */
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2                       (0x228U)

/* PCIESS2_PCS1 */
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1                       (0x22CU)

/* PCIESS2_PCS2 */
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2                       (0x230U)

/* PCIE_PCS */
#define CSL_CONTROL_CORE_SEC_PCIE_PCS                           (0x234U)

/* pcs_revision */
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION                  (0x238U)

/* serdes control selection PCIE C0 (0 default) vs PCIE B1 (1) */
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL                       (0x23CU)

/* PHY_POWER_PCIESS1 */
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1                  (0x240U)

/* PHY_POWER_PCIESS2 */
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2                  (0x244U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SECURITY_MASTER_CTRL_REG */

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_SECURITY_MASTER_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_SECURITY_MASTER_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_SECURITY_MASTER_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_SECURITY_MASTER_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_MPU_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_MPU_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_MPU_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_MPU_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_L3_ROM_VISIBLE_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_L3_ROM_VISIBLE_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_L3_ROM_VISIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_L3_ROM_VISIBLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_IPU_1_SECURE_ENABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_IPU_1_SECURE_ENABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_IPU_1_SECURE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_IPU_1_SECURE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_TEST_ENABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_TEST_ENABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_TEST_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_TEST_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_ENABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_ENABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_DSP_1_SECURE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SECURITY_MASTER_CTRL_REG_RESETVAL  (0x00000000U)

/* L4_CFG_ROLES_0_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER_L4_CFG_ROLES_0_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER_L4_CFG_ROLES_0_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER_L4_CFG_ROLES_0_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER_L4_CFG_ROLES_0_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_LOWER_RESETVAL      (0x00000000U)

/* L4_CFG_ROLES_0_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER_L4_CFG_ROLES_0_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER_L4_CFG_ROLES_0_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER_L4_CFG_ROLES_0_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER_L4_CFG_ROLES_0_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_0_UPPER_RESETVAL      (0x00000000U)

/* L4_CFG_MEMBERS_0 */

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_DISABLE_0_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_DISABLE_0_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_DISABLE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_DISABLE_0_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_MEMBERS_0_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_MEMBERS_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_MEMBERS_0_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_L4_CFG_MEMBERS_0_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_0_RESETVAL          (0x0000ffffU)

/* L4_CFG_ROLES_1_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER_L4_CFG_ROLES_1_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER_L4_CFG_ROLES_1_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER_L4_CFG_ROLES_1_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER_L4_CFG_ROLES_1_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_LOWER_RESETVAL      (0x00000000U)

/* L4_CFG_ROLES_1_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER_L4_CFG_ROLES_1_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER_L4_CFG_ROLES_1_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER_L4_CFG_ROLES_1_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER_L4_CFG_ROLES_1_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_1_UPPER_RESETVAL      (0x00000000U)

/* L4_CFG_MEMBERS_1 */

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_DISABLE_1_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_DISABLE_1_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_DISABLE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_DISABLE_1_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_MEMBERS_1_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_MEMBERS_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_MEMBERS_1_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_L4_CFG_MEMBERS_1_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_1_RESETVAL          (0x0000ffffU)

/* L4_CFG_ROLES_5_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER_L4_CFG_ROLES_5_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER_L4_CFG_ROLES_5_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER_L4_CFG_ROLES_5_0_RESETVAL  (0x000000c0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER_L4_CFG_ROLES_5_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_LOWER_RESETVAL      (0x000000c0U)

/* L4_CFG_ROLES_5_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER_L4_CFG_ROLES_5_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER_L4_CFG_ROLES_5_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER_L4_CFG_ROLES_5_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER_L4_CFG_ROLES_5_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_ROLES_5_UPPER_RESETVAL      (0x00000000U)

/* L4_CFG_MEMBERS_5 */

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_DISABLE_5_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_DISABLE_5_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_DISABLE_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_DISABLE_5_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_MEMBERS_5_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_MEMBERS_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_MEMBERS_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_L4_CFG_MEMBERS_5_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_CFG_MEMBERS_5_RESETVAL          (0x00000000U)

/* L4_PER_1_ROLES_0_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER_L4_PER_1_ROLES_0_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER_L4_PER_1_ROLES_0_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER_L4_PER_1_ROLES_0_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER_L4_PER_1_ROLES_0_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_LOWER_RESETVAL    (0x00000000U)

/* L4_PER_1_ROLES_0_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER_L4_PER_1_ROLES_0_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER_L4_PER_1_ROLES_0_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER_L4_PER_1_ROLES_0_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER_L4_PER_1_ROLES_0_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_0_UPPER_RESETVAL    (0x00000000U)

/* L4_PER_1_MEMBERS_0 */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_DISABLE_0_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_DISABLE_0_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_DISABLE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_DISABLE_0_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_MEMBERS_0_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_MEMBERS_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_MEMBERS_0_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_L4_PER_1_MEMBERS_0_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_0_RESETVAL        (0x0000ffffU)

/* L4_PER_1_ROLES_1_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER_L4_PER_1_ROLES_1_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER_L4_PER_1_ROLES_1_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER_L4_PER_1_ROLES_1_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER_L4_PER_1_ROLES_1_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_LOWER_RESETVAL    (0x00000000U)

/* L4_PER_1_ROLES_1_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER_L4_PER_1_ROLES_1_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER_L4_PER_1_ROLES_1_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER_L4_PER_1_ROLES_1_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER_L4_PER_1_ROLES_1_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_ROLES_1_UPPER_RESETVAL    (0x00000000U)

/* L4_PER_1_MEMBERS_1 */

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_DISABLE_1_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_DISABLE_1_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_DISABLE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_DISABLE_1_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_MEMBERS_1_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_MEMBERS_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_MEMBERS_1_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_L4_PER_1_MEMBERS_1_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_1_MEMBERS_1_RESETVAL        (0x0000ffffU)

/* L4_PER_2_ROLES_0_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER_L4_PER_2_ROLES_0_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER_L4_PER_2_ROLES_0_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER_L4_PER_2_ROLES_0_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER_L4_PER_2_ROLES_0_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_LOWER_RESETVAL    (0x00000000U)

/* L4_PER_2_ROLES_0_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER_L4_PER_2_ROLES_0_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER_L4_PER_2_ROLES_0_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER_L4_PER_2_ROLES_0_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER_L4_PER_2_ROLES_0_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_2_ROLES_0_UPPER_RESETVAL    (0x00000000U)

/* L4_PER_2_MEMBERS_0 */

#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_DISABLE_0_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_DISABLE_0_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_DISABLE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_DISABLE_0_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_MEMBERS_0_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_MEMBERS_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_MEMBERS_0_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_L4_PER_2_MEMBERS_0_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_2_MEMBERS_0_RESETVAL        (0x0000ffffU)

/* L4_PER_3_ROLES_0_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER_L4_PER_3_ROLES_0_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER_L4_PER_3_ROLES_0_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER_L4_PER_3_ROLES_0_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER_L4_PER_3_ROLES_0_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_LOWER_RESETVAL    (0x00000000U)

/* L4_PER_3_ROLES_0_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER_L4_PER_3_ROLES_0_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER_L4_PER_3_ROLES_0_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER_L4_PER_3_ROLES_0_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER_L4_PER_3_ROLES_0_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_3_ROLES_0_UPPER_RESETVAL    (0x00000000U)

/* L4_PER_3_MEMBER_0 */

#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_DISABLE_0_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_DISABLE_0_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_DISABLE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_DISABLE_0_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_MEMBERS_0_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_MEMBERS_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_MEMBERS_0_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_L4_PER_3_MEMBERS_0_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_PER_3_MEMBER_0_RESETVAL         (0x0000ffffU)

/* L4_WKUP_ROLES_0_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER_L4_WKUP_ROLES_0_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER_L4_WKUP_ROLES_0_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER_L4_WKUP_ROLES_0_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER_L4_WKUP_ROLES_0_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_LOWER_RESETVAL     (0x00000000U)

/* L4_WKUP_ROLES_0_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER_L4_WKUP_ROLES_0_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER_L4_WKUP_ROLES_0_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER_L4_WKUP_ROLES_0_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER_L4_WKUP_ROLES_0_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_0_UPPER_RESETVAL     (0x00000000U)

/* L4_WKUP_MEMBERS_0 */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_DISABLE_0_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_DISABLE_0_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_DISABLE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_DISABLE_0_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_MEMBERS_0_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_MEMBERS_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_MEMBERS_0_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_L4_WKUP_MEMBERS_0_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_0_RESETVAL         (0x0000ffffU)

/* L4_WKUP_ROLES_1_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER_L4_WKUP_ROLES_1_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER_L4_WKUP_ROLES_1_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER_L4_WKUP_ROLES_1_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER_L4_WKUP_ROLES_1_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_LOWER_RESETVAL     (0x00000000U)

/* L4_WKUP_ROLES_1_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER_L4_WKUP_ROLES_1_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER_L4_WKUP_ROLES_1_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER_L4_WKUP_ROLES_1_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER_L4_WKUP_ROLES_1_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_1_UPPER_RESETVAL     (0x00000000U)

/* L4_WKUP_MEMBERS_1 */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_DISABLE_1_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_DISABLE_1_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_DISABLE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_DISABLE_1_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_MEMBERS_1_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_MEMBERS_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_MEMBERS_1_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_L4_WKUP_MEMBERS_1_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_1_RESETVAL         (0x0000ffffU)

/* L4_WKUP_ROLES_3_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER_L4_WKUP_ROLES_3_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER_L4_WKUP_ROLES_3_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER_L4_WKUP_ROLES_3_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER_L4_WKUP_ROLES_3_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_LOWER_RESETVAL     (0x00000000U)

/* L4_WKUP_ROLES_3_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER_L4_WKUP_ROLES_3_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER_L4_WKUP_ROLES_3_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER_L4_WKUP_ROLES_3_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER_L4_WKUP_ROLES_3_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_3_UPPER_RESETVAL     (0x00000000U)

/* L4_WKUP_MEMBERS_3 */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_DISABLE_3_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_DISABLE_3_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_DISABLE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_DISABLE_3_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_MEMBERS_3_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_MEMBERS_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_MEMBERS_3_RESETVAL  (0x0000ffffU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_L4_WKUP_MEMBERS_3_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_3_RESETVAL         (0x0000ffffU)

/* L4_WKUP_ROLES_4_LOWER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER_L4_WKUP_ROLES_4_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER_L4_WKUP_ROLES_4_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER_L4_WKUP_ROLES_4_0_RESETVAL  (0x000000c0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER_L4_WKUP_ROLES_4_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_LOWER_RESETVAL     (0x000000c0U)

/* L4_WKUP_ROLES_4_UPPER */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER_L4_WKUP_ROLES_4_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER_L4_WKUP_ROLES_4_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER_L4_WKUP_ROLES_4_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER_L4_WKUP_ROLES_4_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_ROLES_4_UPPER_RESETVAL     (0x00000000U)

/* L4_WKUP_MEMBERS_4 */

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_DISABLE_4_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_DISABLE_4_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_DISABLE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_DISABLE_4_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_MEMBERS_4_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_MEMBERS_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_MEMBERS_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_L4_WKUP_MEMBERS_4_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_L4_WKUP_MEMBERS_4_RESETVAL         (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_0 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0_STD_FUSE_OPP_VMIN_GPU_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0_STD_FUSE_OPP_VMIN_GPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0_STD_FUSE_OPP_VMIN_GPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0_STD_FUSE_OPP_VMIN_GPU_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_0_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_1 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1_STD_FUSE_OPP_VMIN_GPU_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1_STD_FUSE_OPP_VMIN_GPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1_STD_FUSE_OPP_VMIN_GPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1_STD_FUSE_OPP_VMIN_GPU_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_1_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_2 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2_STD_FUSE_OPP_VMIN_GPU_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2_STD_FUSE_OPP_VMIN_GPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2_STD_FUSE_OPP_VMIN_GPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2_STD_FUSE_OPP_VMIN_GPU_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_2_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_3 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3_STD_FUSE_OPP_VMIN_GPU_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3_STD_FUSE_OPP_VMIN_GPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3_STD_FUSE_OPP_VMIN_GPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3_STD_FUSE_OPP_VMIN_GPU_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_3_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_4 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4_STD_FUSE_OPP_VMIN_GPU_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4_STD_FUSE_OPP_VMIN_GPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4_STD_FUSE_OPP_VMIN_GPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4_STD_FUSE_OPP_VMIN_GPU_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_4_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_GPU_5 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5_STD_FUSE_OPP_VMIN_GPU_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5_STD_FUSE_OPP_VMIN_GPU_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5_STD_FUSE_OPP_VMIN_GPU_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5_STD_FUSE_OPP_VMIN_GPU_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_GPU_5_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_0 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0_STD_FUSE_OPP_VMIN_MPU_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0_STD_FUSE_OPP_VMIN_MPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0_STD_FUSE_OPP_VMIN_MPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0_STD_FUSE_OPP_VMIN_MPU_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_0_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_1 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1_STD_FUSE_OPP_VMIN_MPU_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1_STD_FUSE_OPP_VMIN_MPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1_STD_FUSE_OPP_VMIN_MPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1_STD_FUSE_OPP_VMIN_MPU_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_1_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_2 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2_STD_FUSE_OPP_VMIN_MPU_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2_STD_FUSE_OPP_VMIN_MPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2_STD_FUSE_OPP_VMIN_MPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2_STD_FUSE_OPP_VMIN_MPU_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_2_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_3 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3_STD_FUSE_OPP_VMIN_MPU_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3_STD_FUSE_OPP_VMIN_MPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3_STD_FUSE_OPP_VMIN_MPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3_STD_FUSE_OPP_VMIN_MPU_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_3_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_4 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4_STD_FUSE_OPP_VMIN_MPU_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4_STD_FUSE_OPP_VMIN_MPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4_STD_FUSE_OPP_VMIN_MPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4_STD_FUSE_OPP_VMIN_MPU_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_4_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_5 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5_STD_FUSE_OPP_VMIN_MPU_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5_STD_FUSE_OPP_VMIN_MPU_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5_STD_FUSE_OPP_VMIN_MPU_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5_STD_FUSE_OPP_VMIN_MPU_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_5_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_6 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6_STD_FUSE_OPP_VMIN_MPU_6_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6_STD_FUSE_OPP_VMIN_MPU_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6_STD_FUSE_OPP_VMIN_MPU_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6_STD_FUSE_OPP_VMIN_MPU_6_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_6_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VMIN_MPU_7 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7_STD_FUSE_OPP_VMIN_MPU_7_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7_STD_FUSE_OPP_VMIN_MPU_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7_STD_FUSE_OPP_VMIN_MPU_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7_STD_FUSE_OPP_VMIN_MPU_7_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VMIN_MPU_7_RESETVAL   (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_LVT_0 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_0_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_LVT_1 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_1_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_LVT_2 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_2_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_LVT_3 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_3_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_LVT_4 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_DSPEVE_LVT_4_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_LVT_0 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0_STD_FUSE_OPP_VDD_IVA_LVT_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0_STD_FUSE_OPP_VDD_IVA_LVT_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0_STD_FUSE_OPP_VDD_IVA_LVT_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0_STD_FUSE_OPP_VDD_IVA_LVT_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_0_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_LVT_1 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1_STD_FUSE_OPP_VDD_IVA_LVT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1_STD_FUSE_OPP_VDD_IVA_LVT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1_STD_FUSE_OPP_VDD_IVA_LVT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1_STD_FUSE_OPP_VDD_IVA_LVT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_1_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_LVT_2 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2_STD_FUSE_OPP_VDD_IVA_LVT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2_STD_FUSE_OPP_VDD_IVA_LVT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2_STD_FUSE_OPP_VDD_IVA_LVT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2_STD_FUSE_OPP_VDD_IVA_LVT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_2_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_LVT_3 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3_STD_FUSE_OPP_VDD_IVA_LVT_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3_STD_FUSE_OPP_VDD_IVA_LVT_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3_STD_FUSE_OPP_VDD_IVA_LVT_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3_STD_FUSE_OPP_VDD_IVA_LVT_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_3_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_LVT_4 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4_STD_FUSE_OPP_VDD_IVA_LVT_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4_STD_FUSE_OPP_VDD_IVA_LVT_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4_STD_FUSE_OPP_VDD_IVA_LVT_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4_STD_FUSE_OPP_VDD_IVA_LVT_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_IVA_LVT_4_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_LVT_0 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0_STD_FUSE_OPP_VDD_CORE_LVT_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0_STD_FUSE_OPP_VDD_CORE_LVT_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0_STD_FUSE_OPP_VDD_CORE_LVT_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0_STD_FUSE_OPP_VDD_CORE_LVT_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_0_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_LVT_1 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1_STD_FUSE_OPP_VDD_CORE_LVT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1_STD_FUSE_OPP_VDD_CORE_LVT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1_STD_FUSE_OPP_VDD_CORE_LVT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1_STD_FUSE_OPP_VDD_CORE_LVT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_1_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_LVT_2 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2_STD_FUSE_OPP_VDD_CORE_LVT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2_STD_FUSE_OPP_VDD_CORE_LVT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2_STD_FUSE_OPP_VDD_CORE_LVT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2_STD_FUSE_OPP_VDD_CORE_LVT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_2_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_LVT_3 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3_STD_FUSE_OPP_VDD_CORE_LVT_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3_STD_FUSE_OPP_VDD_CORE_LVT_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3_STD_FUSE_OPP_VDD_CORE_LVT_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3_STD_FUSE_OPP_VDD_CORE_LVT_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_3_RESETVAL  (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_LVT_4 */

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4_STD_FUSE_OPP_VDD_CORE_LVT_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4_STD_FUSE_OPP_VDD_CORE_LVT_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4_STD_FUSE_OPP_VDD_CORE_LVT_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4_STD_FUSE_OPP_VDD_CORE_LVT_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_STD_FUSE_OPP_VDD_CORE_LVT_4_RESETVAL  (0x00000000U)

/* LDOSRAM_CORE_4_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_LDOSRAMCORE_4_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_4_VOLTAGE_CTRL_RESETVAL  (0x00000000U)

/* LDOSRAM_CORE_5_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_LDOSRAMCORE_5_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_CORE_5_VOLTAGE_CTRL_RESETVAL  (0x00000000U)

/* LDOSRAM_DSPEVE_2_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_LDOSRAMDSPEVE_2_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_LDOSRAM_DSPEVE_2_VOLTAGE_CTRL_RESETVAL  (0x00000000U)

/* MEM_DFT_RW_DMM */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_MUX_CTRL_DMM_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_MUX_CTRL_DMM_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_MUX_CTRL_DMM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_MUX_CTRL_DMM_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_MUX_CTRL_DMM_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_BRGLNT_DMM_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_BRGLNT_DMM_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_BRGLNT_DMM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_MEM_RW_BRGLNT_DMM_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DMM_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_SAR_RAM */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_MUX_CTRL_SAR_RAM_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_MUX_CTRL_SAR_RAM_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_MUX_CTRL_SAR_RAM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_MUX_CTRL_SAR_RAM_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_MUX_CTRL_SAR_RAM_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_BRGLNT_SAR_RAM_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_BRGLNT_SAR_RAM_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_BRGLNT_SAR_RAM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_MEM_RW_BRGLNT_SAR_RAM_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_RAM_RESETVAL        (0x00000000U)

/* MEM_DFT_RW_OCMC_RAM */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_MUX_CTRL_OCMC_RAM_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_MUX_CTRL_OCMC_RAM_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_MUX_CTRL_OCMC_RAM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_MUX_CTRL_OCMC_RAM_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_MUX_CTRL_OCMC_RAM_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_BRGLNT_OCMC_RAM_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_BRGLNT_OCMC_RAM_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_BRGLNT_OCMC_RAM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_MEM_RW_BRGLNT_OCMC_RAM_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_RAM_RESETVAL       (0x00000000U)

/* MEM_DFT_RW_OCMC_ROM */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_MUX_CTRL_OCMC_ROM_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_MUX_CTRL_OCMC_ROM_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_MUX_CTRL_OCMC_ROM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_MUX_CTRL_OCMC_ROM_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_MUX_CTRL_OCMC_ROM_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_BRGLNT_OCMC_ROM_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_BRGLNT_OCMC_ROM_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_BRGLNT_OCMC_ROM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_MEM_RW_BRGLNT_OCMC_ROM_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_OCMC_ROM_RESETVAL       (0x00000000U)

/* MEM_DFT_RW_SAR_ROM */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_MUX_CTRL_SAR_ROM_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_MUX_CTRL_SAR_ROM_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_MUX_CTRL_SAR_ROM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_MUX_CTRL_SAR_ROM_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_MUX_CTRL_SAR_ROM_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_BRGLNT_SAR_ROM_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_BRGLNT_SAR_ROM_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_BRGLNT_SAR_ROM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_MEM_RW_BRGLNT_SAR_ROM_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SAR_ROM_RESETVAL        (0x00000000U)

/* MEM_DFT_RW_SDMA */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_MUX_CTRL_SDMA_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_MUX_CTRL_SDMA_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_MUX_CTRL_SDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_MUX_CTRL_SDMA_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_MUX_CTRL_SDMA_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_BRGLNT_SDMA_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_BRGLNT_SDMA_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_BRGLNT_SDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_MEM_RW_BRGLNT_SDMA_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_SDMA_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_CDMA */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_MUX_CTRL_CDMA_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_MUX_CTRL_CDMA_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_MUX_CTRL_CDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_MUX_CTRL_CDMA_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_MUX_CTRL_CDMA_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_BRGLNT_CDMA_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_BRGLNT_CDMA_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_BRGLNT_CDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_MEM_RW_BRGLNT_CDMA_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_CDMA_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_FPKA */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_MUX_CTRL_FPKA_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_MUX_CTRL_FPKA_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_MUX_CTRL_FPKA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_MUX_CTRL_FPKA_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_MUX_CTRL_FPKA_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_BRGLNT_FPKA_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_BRGLNT_FPKA_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_BRGLNT_FPKA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_MEM_RW_BRGLNT_FPKA_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_FPKA_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_MMC */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_MUX_CTRL_MMC_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_MUX_CTRL_MMC_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_MUX_CTRL_MMC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_MUX_CTRL_MMC_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_MUX_CTRL_MMC_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_BRGLNT_MMC_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_BRGLNT_MMC_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_BRGLNT_MMC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_MEM_RW_BRGLNT_MMC_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MMC_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_UART */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_MUX_CTRL_UART_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_MUX_CTRL_UART_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_MUX_CTRL_UART_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_MUX_CTRL_UART_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_MUX_CTRL_UART_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_BRGLNT_UART_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_BRGLNT_UART_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_BRGLNT_UART_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_MEM_RW_BRGLNT_UART_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_UART_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_DEBUGSS */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_MUX_CTRL_DEBUGSS_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_MUX_CTRL_DEBUGSS_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_MUX_CTRL_DEBUGSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_MUX_CTRL_DEBUGSS_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_MUX_CTRL_DEBUGSS_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_BRGLNT_DEBUGSS_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_BRGLNT_DEBUGSS_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_BRGLNT_DEBUGSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_MEM_RW_BRGLNT_DEBUGSS_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DEBUGSS_RESETVAL        (0x00000000U)

/* MEM_DFT_RW_DCAN */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_MUX_CTRL_DCAN_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_MUX_CTRL_DCAN_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_MUX_CTRL_DCAN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_MUX_CTRL_DCAN_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_MUX_CTRL_DCAN_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_BRGLNT_DCAN_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_BRGLNT_DCAN_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_BRGLNT_DCAN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_MEM_RW_BRGLNT_DCAN_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DCAN_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_VCP */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_MUX_CTRL_VCP_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_MUX_CTRL_VCP_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_MUX_CTRL_VCP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_MUX_CTRL_VCP_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_MUX_CTRL_VCP_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_BRGLNT_VCP_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_BRGLNT_VCP_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_BRGLNT_VCP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_MEM_RW_BRGLNT_VCP_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VCP_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_I2C */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_MUX_CTRL_I2C_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_MUX_CTRL_I2C_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_MUX_CTRL_I2C_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_MUX_CTRL_I2C_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_MUX_CTRL_I2C_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_BRGLNT_I2C_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_BRGLNT_I2C_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_BRGLNT_I2C_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_MEM_RW_BRGLNT_I2C_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_I2C_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_VIP */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_MUX_CTRL_VIP_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_MUX_CTRL_VIP_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_MUX_CTRL_VIP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_MUX_CTRL_VIP_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_MUX_CTRL_VIP_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_BRGLNT_VIP_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_BRGLNT_VIP_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_BRGLNT_VIP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_MEM_RW_BRGLNT_VIP_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VIP_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_VPE */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_MUX_CTRL_VPE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_MUX_CTRL_VPE_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_MUX_CTRL_VPE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_MUX_CTRL_VPE_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_MUX_CTRL_VPE_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_BRGLNT_VPE_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_BRGLNT_VPE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_BRGLNT_VPE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_MEM_RW_BRGLNT_VPE_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_VPE_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_PRUSS */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_MUX_CTRL_PRUSS_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_MUX_CTRL_PRUSS_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_MUX_CTRL_PRUSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_MUX_CTRL_PRUSS_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_MUX_CTRL_PRUSS_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_BRGLNT_PRUSS_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_BRGLNT_PRUSS_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_BRGLNT_PRUSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_MEM_RW_BRGLNT_PRUSS_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PRUSS_RESETVAL          (0x00000000U)

/* MEM_DFT_RW_GMAC_SW */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_MUX_CTRL_GMAC_SW_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_MUX_CTRL_GMAC_SW_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_MUX_CTRL_GMAC_SW_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_MUX_CTRL_GMAC_SW_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_MUX_CTRL_GMAC_SW_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_BRGLNT_GMAC_SW_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_BRGLNT_GMAC_SW_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_BRGLNT_GMAC_SW_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_MEM_RW_BRGLNT_GMAC_SW_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GMAC_SW_RESETVAL        (0x00000000U)

/* MEM_DFT_RW_USB */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_MUX_CTRL_USB_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_MUX_CTRL_USB_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_MUX_CTRL_USB_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_MUX_CTRL_USB_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_MUX_CTRL_USB_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_BRGLNT_USB_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_BRGLNT_USB_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_BRGLNT_USB_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_MEM_RW_BRGLNT_USB_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_USB_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_PCIE */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_MUX_CTRL_PCIE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_MUX_CTRL_PCIE_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_MUX_CTRL_PCIE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_MUX_CTRL_PCIE_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_MUX_CTRL_PCIE_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_BRGLNT_PCIE_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_BRGLNT_PCIE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_BRGLNT_PCIE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_MEM_RW_BRGLNT_PCIE_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PCIE_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_MLB */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_MUX_CTRL_MLB_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_MUX_CTRL_MLB_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_MUX_CTRL_MLB_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_MUX_CTRL_MLB_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_MUX_CTRL_MLB_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_BRGLNT_MLB_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_BRGLNT_MLB_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_BRGLNT_MLB_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_MEM_RW_BRGLNT_MLB_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MLB_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_EDMA_TC */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_MUX_CTRL_EDMA_TC_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_MUX_CTRL_EDMA_TC_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_MUX_CTRL_EDMA_TC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_MUX_CTRL_EDMA_TC_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_MUX_CTRL_EDMA_TC_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_BRGLNT_EDMA_TC_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_BRGLNT_EDMA_TC_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_BRGLNT_EDMA_TC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_MEM_RW_BRGLNT_EDMA_TC_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TC_RESETVAL        (0x00000000U)

/* MEM_DFT_RW_EDMA_TPCC */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_MUX_CTRL_EDMA_TPCC_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_MUX_CTRL_EDMA_TPCC_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_MUX_CTRL_EDMA_TPCC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_MUX_CTRL_EDMA_TPCC_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_MUX_CTRL_EDMA_TPCC_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_BRGLNT_EDMA_TPCC_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_BRGLNT_EDMA_TPCC_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_BRGLNT_EDMA_TPCC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_MEM_RW_BRGLNT_EDMA_TPCC_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EDMA_TPCC_RESETVAL      (0x00000000U)

/* MEM_DFT_RW_DSS */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_MUX_CTRL_DSS_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_MUX_CTRL_DSS_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_MUX_CTRL_DSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_MUX_CTRL_DSS_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_MUX_CTRL_DSS_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_BRGLNT_DSS_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_BRGLNT_DSS_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_BRGLNT_DSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_MEM_RW_BRGLNT_DSS_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSS_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_PBIST */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_MUX_CTRL_PBIST_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_MUX_CTRL_PBIST_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_MUX_CTRL_PBIST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_MUX_CTRL_PBIST_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_MUX_CTRL_PBIST_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_BRGLNT_PBIST_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_BRGLNT_PBIST_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_BRGLNT_PBIST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_MEM_RW_BRGLNT_PBIST_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_PBIST_RESETVAL          (0x00000000U)

/* MEM_DFT_RW_IPU */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_MUX_CTRL_IPU_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_MUX_CTRL_IPU_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_MUX_CTRL_IPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_MUX_CTRL_IPU_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_MUX_CTRL_IPU_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_BRGLNT_IPU_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_BRGLNT_IPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_BRGLNT_IPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_MEM_RW_BRGLNT_IPU_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IPU_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_MPU */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_MUX_CTRL_MPU_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_MUX_CTRL_MPU_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_MUX_CTRL_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_MUX_CTRL_MPU_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_MUX_CTRL_MPU_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_BRGLNT_MPU_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_BRGLNT_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_BRGLNT_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_MEM_RW_BRGLNT_MPU_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_MPU_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_IVA */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_MUX_CTRL_IVA_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_MUX_CTRL_IVA_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_MUX_CTRL_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_MUX_CTRL_IVA_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_MUX_CTRL_IVA_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_BRGLNT_IVA_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_BRGLNT_IVA_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_BRGLNT_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_MEM_RW_BRGLNT_IVA_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_IVA_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_GPU */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_MUX_CTRL_GPU_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_MUX_CTRL_GPU_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_MUX_CTRL_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_MUX_CTRL_GPU_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_MUX_CTRL_GPU_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_BRGLNT_GPU_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_BRGLNT_GPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_BRGLNT_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_MEM_RW_BRGLNT_GPU_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_GPU_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_BB2D */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_MUX_CTRL_BB2D_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_MUX_CTRL_BB2D_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_MUX_CTRL_BB2D_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_MUX_CTRL_BB2D_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_MUX_CTRL_BB2D_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_BRGLNT_BB2D_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_BRGLNT_BB2D_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_BRGLNT_BB2D_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_MEM_RW_BRGLNT_BB2D_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_BB2D_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_DSP */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_MUX_CTRL_DSP_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_MUX_CTRL_DSP_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_MUX_CTRL_DSP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_MUX_CTRL_DSP_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_MUX_CTRL_DSP_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_BRGLNT_DSP_MASK  (0x7FFFFFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_BRGLNT_DSP_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_BRGLNT_DSP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_MEM_RW_BRGLNT_DSP_MAX  (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_DSP_RESETVAL            (0x00000000U)

/* MEM_DFT_RW_EVE1 */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_MUX_CTRL_EVE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_MUX_CTRL_EVE_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_MUX_CTRL_EVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_MUX_CTRL_EVE_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_MUX_CTRL_EVE_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_BRGLNT_EVE1_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_BRGLNT_EVE1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_BRGLNT_EVE1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_MEM_RW_BRGLNT_EVE1_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE1_RESETVAL           (0x00000000U)

/* MEM_DFT_RW_EVE2 */

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2_MEM_RW_BRGLNT_EVE2_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2_MEM_RW_BRGLNT_EVE2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2_MEM_RW_BRGLNT_EVE2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2_MEM_RW_BRGLNT_EVE2_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SEC_MEM_DFT_RW_EVE2_RESETVAL           (0x00000000U)

/* SMA_SW_2 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_2_SMA_SW_2_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SMA_SW_2_SMA_SW_2_SHIFT            (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_2_SMA_SW_2_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_2_SMA_SW_2_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_2_RESETVAL                  (0x00000000U)

/* SMA_SW_3 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_3_SMA_SW_3_MASK             (0xFFFFFFFCU)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_SMA_SW_3_SHIFT            (2U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_SMA_SW_3_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_SMA_SW_3_MAX              (0x3fffffffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP2_LRST_DONE_RESERVED_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP2_LRST_DONE_RESERVED_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP2_LRST_DONE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP2_LRST_DONE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP1_LRST_DONE_RESERVED_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP1_LRST_DONE_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP1_LRST_DONE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_3_DSP1_LRST_DONE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_3_RESETVAL                  (0x00000000U)

/* SMA_SW_4 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_EXP7_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_EXP7_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_EXP7_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_EXP7_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_2_MASK    (0x00000E00U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_2_SHIFT   (9U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_2_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_1_MASK    (0x000001C0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_1_SHIFT   (6U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_CSI2_1_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP2_EDMA_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP2_EDMA_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP2_EDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP2_EDMA_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP1_EDMA_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP1_EDMA_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP1_EDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_4_MREQDOMAIN_DSP1_EDMA_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_4_RESETVAL                  (0x00000000U)

/* SMA_SW_5 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_5_SMA_SW_5_RESERVED_MASK    (0xFFFFFFFEU)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_SMA_SW_5_RESERVED_SHIFT   (1U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_SMA_SW_5_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_SMA_SW_5_RESERVED_MAX     (0x7fffffffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_5_TSHUT_OVERRIDE_MASK       (0x00000001U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_TSHUT_OVERRIDE_SHIFT      (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_TSHUT_OVERRIDE_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_5_TSHUT_OVERRIDE_MAX        (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_5_RESETVAL                  (0x00000000U)

/* SMA_SW_6 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_SMA_SW_6_RESERVED_MASK    (0xE0000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_SMA_SW_6_RESERVED_SHIFT   (29U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_SMA_SW_6_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_SMA_SW_6_RESERVED_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PLLEN_CONTROL_MASK        (0x1F000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PLLEN_CONTROL_SHIFT       (24U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PLLEN_CONTROL_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PLLEN_CONTROL_MAX         (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PCIE_TX_RX_CONTROL_MASK   (0x00030000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PCIE_TX_RX_CONTROL_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PCIE_TX_RX_CONTROL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_PCIE_TX_RX_CONTROL_MAX    (0x00000003U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_RMII_CLK_SETTING_MASK     (0x00000100U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_RMII_CLK_SETTING_SHIFT    (8U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_RMII_CLK_SETTING_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_RMII_CLK_SETTING_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_MUXSEL_32K_CLKIN_MASK     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_MUXSEL_32K_CLKIN_SHIFT    (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_MUXSEL_32K_CLKIN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_6_MUXSEL_32K_CLKIN_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_6_RESETVAL                  (0x00000000U)

/* SMA_SW_7 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_SMA_SW_7_RESERVED_MASK    (0xFFFC0000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_SMA_SW_7_RESERVED_SHIFT   (18U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_SMA_SW_7_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_SMA_SW_7_RESERVED_MAX     (0x00003fffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU2_ABORT_ENABLE_MASK    (0x00020000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU2_ABORT_ENABLE_SHIFT   (17U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU2_ABORT_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU2_ABORT_ENABLE_MAX     (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU1_ABORT_ENABLE_MASK    (0x00010000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU1_ABORT_ENABLE_SHIFT   (16U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU1_ABORT_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_MMU1_ABORT_ENABLE_MAX     (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_MMU_ROUTE_ENABLE_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_MMU_ROUTE_ENABLE_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_MMU_ROUTE_ENABLE_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_MMU_ROUTE_ENABLE_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_RD_MMU_ROUTE_ENABLE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_RD_MMU_ROUTE_ENABLE_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_RD_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_RD_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_RD_MMU_ROUTE_ENABLE_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_RD_MMU_ROUTE_ENABLE_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_RD_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_RD_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_WR_MMU_ROUTE_ENABLE_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_WR_MMU_ROUTE_ENABLE_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_WR_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC0_WR_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_WR_MMU_ROUTE_ENABLE_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_WR_MMU_ROUTE_ENABLE_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_WR_MMU_ROUTE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_EDMA_TC1_WR_MMU_ROUTE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_AXI2OCP_LEGACY_MODE_ENABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_AXI2OCP_LEGACY_MODE_ENABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_AXI2OCP_LEGACY_MODE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS1_AXI2OCP_LEGACY_MODE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_AXI2OCP_LEGACY_MODE_ENABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_AXI2OCP_LEGACY_MODE_ENABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_AXI2OCP_LEGACY_MODE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_7_PCIE_SS2_AXI2OCP_LEGACY_MODE_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_SMA_SW_7_RESETVAL                  (0x00000000U)

/* SMA_SW_8 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_8_PCIE_PLL_TEST_INPUT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SMA_SW_8_PCIE_PLL_TEST_INPUT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_8_PCIE_PLL_TEST_INPUT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_8_PCIE_PLL_TEST_INPUT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_8_RESETVAL                  (0x00000000U)

/* SMA_SW_9 */

#define CSL_CONTROL_CORE_SEC_SMA_SW_9_PCIE_PLL_TEST_INPUT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SMA_SW_9_PCIE_PLL_TEST_INPUT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_9_PCIE_PLL_TEST_INPUT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SMA_SW_9_PCIE_PLL_TEST_INPUT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SMA_SW_9_RESETVAL                  (0x00000000U)

/* PCIESS1_PCS1 */

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_TEST_TXDATA_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_TEST_TXDATA_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_TEST_TXDATA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_TEST_TXDATA_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_ERR_BIT_EN_MASK  (0x003FF000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_ERR_BIT_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_ERR_BIT_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_ERR_BIT_EN_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_CFG_HOLDOFF_MASK  (0x00000FF0U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_CFG_HOLDOFF_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_CFG_HOLDOFF_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_CFG_HOLDOFF_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_DET_DELAY_MASK  (0x0000000FU)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_DET_DELAY_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_DET_DELAY_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_PCIESS1_PCS_DET_DELAY_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS1_RESETVAL              (0x00000001U)

/* PCIESS1_PCS2 */

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_SYNC_MASK  (0xF8000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_SYNC_SHIFT  (27U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_SYNC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_SYNC_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_FUNC_MASK  (0x07800000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_FUNC_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_FUNC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_FUNC_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_HOLD_MASK  (0x00780000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_HOLD_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_HOLD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_HOLD_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_INIT_MASK  (0x00078000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_INIT_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_INIT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_CFG_EQ_INIT_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_OSEL_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_OSEL_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_OSEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_OSEL_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_LSEL_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_LSEL_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_LSEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_LSEL_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_MODE_MASK  (0x000000C0U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_MODE_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_MODE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_L1_SLEEP_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_L1_SLEEP_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_L1_SLEEP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_L1_SLEEP_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_MODE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_MODE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_TEST_MODE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_LN_EN_MASK  (0x0000000CU)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_LN_EN_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_LN_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_ERR_LN_EN_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_SHORT_TIMES_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_SHORT_TIMES_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_SHORT_TIMES_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_PCIESS1_PCS_SHORT_TIMES_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS1_PCS2_RESETVAL              (0x00000000U)

/* PCIESS2_PCS1 */

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_TEST_TXDATA_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_TEST_TXDATA_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_TEST_TXDATA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_TEST_TXDATA_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_ERR_BIT_EN_MASK  (0x003FF000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_ERR_BIT_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_ERR_BIT_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_ERR_BIT_EN_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_CFG_HOLDOFF_MASK  (0x00000FF0U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_CFG_HOLDOFF_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_CFG_HOLDOFF_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_CFG_HOLDOFF_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_DET_DELAY_MASK  (0x0000000FU)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_DET_DELAY_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_DET_DELAY_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_PCIESS2_PCS_DET_DELAY_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS1_RESETVAL              (0x00000001U)

/* PCIESS2_PCS2 */

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_SYNC_MASK  (0xF8000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_SYNC_SHIFT  (27U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_SYNC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_SYNC_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_FUNC_MASK  (0x07800000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_FUNC_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_FUNC_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_FUNC_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_HOLD_MASK  (0x00780000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_HOLD_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_HOLD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_HOLD_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_INIT_MASK  (0x00078000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_INIT_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_INIT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_CFG_EQ_INIT_MAX  (0x0000000fU)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_OSEL_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_OSEL_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_OSEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_OSEL_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_LSEL_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_LSEL_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_LSEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_LSEL_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_MODE_MASK  (0x000000C0U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_MODE_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_MODE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_L1_SLEEP_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_L1_SLEEP_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_L1_SLEEP_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_L1_SLEEP_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_MODE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_MODE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_TEST_MODE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_LN_EN_MASK  (0x0000000CU)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_LN_EN_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_LN_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_ERR_LN_EN_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_SHORT_TIMES_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_SHORT_TIMES_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_SHORT_TIMES_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_PCIESS2_PCS_SHORT_TIMES_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIESS2_PCS2_RESETVAL              (0x00000000U)

/* PCIE_PCS */

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS2_PCS_RC_DELAY_COUNT_MASK  (0x00FF0000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS2_PCS_RC_DELAY_COUNT_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS2_PCS_RC_DELAY_COUNT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS2_PCS_RC_DELAY_COUNT_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS1_PCS_RC_DELAY_COUNT_MASK  (0x0000FF00U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS1_PCS_RC_DELAY_COUNT_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS1_PCS_RC_DELAY_COUNT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_PCIESS1_PCS_RC_DELAY_COUNT_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_RESETVAL                  (0x00000000U)

/* PCIE_PCS_REVISION */

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIE_RESERVED_MASK  (0xE0000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIE_RESERVED_SHIFT  (29U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIE_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS2_PCS_REVISION_MASK  (0x03800000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS2_PCS_REVISION_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS2_PCS_REVISION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS2_PCS_REVISION_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS1_PCS_REVISION_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS1_PCS_REVISION_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS1_PCS_REVISION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_PCIESS1_PCS_REVISION_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_SEC_PCIE_PCS_REVISION_RESETVAL         (0x00000000U)

/* PCIE_CONTROL */

#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B1C0_MODE_SEL_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B1C0_MODE_SEL_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B1C0_MODE_SEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B1C0_MODE_SEL_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B0_B1_TSYNCEN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B0_B1_TSYNCEN_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B0_B1_TSYNCEN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_PCIE_B0_B1_TSYNCEN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_PCIE_CONTROL_RESETVAL              (0x00000000U)

/* PHY_POWER_PCIESS1 */

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CLKFREQ_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CLKFREQ_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CLKFREQ_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CLKFREQ_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CMD_MASK  (0x003FC000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CMD_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CMD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_PCIESS1_PWRCTL_CMD_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS1_RESETVAL         (0x00000000U)

/* PHY_POWER_PCIESS2 */

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CLKFREQ_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CLKFREQ_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CLKFREQ_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CLKFREQ_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CMD_MASK  (0x003FC000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CMD_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CMD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_PCIESS2_PWRCTL_CMD_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_SEC_PHY_POWER_PCIESS2_RESETVAL         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
