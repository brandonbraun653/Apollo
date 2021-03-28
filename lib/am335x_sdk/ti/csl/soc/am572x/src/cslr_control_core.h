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
#ifndef CSLR_CONTROL_CORE_H
#define CSLR_CONTROL_CORE_H

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
    volatile Uint32 EXTERNAL_SEC_CTRL;
    volatile Uint32 SEC_SW_HW;
    volatile Uint32 MREQDOMAIN_EXP1;
    volatile Uint32 MREQDOMAIN_EXP2;
    volatile Uint32 MREQDOMAIN_EXP3;
    volatile Uint32 L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1;
    volatile Uint32 L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1;
    volatile Uint32 L4_HW_FW_EXPORTED_VALUES_CONF;
    volatile Uint32 SEC_LOAD_FW_EXPORTED_VALUE;
    volatile Uint32 DMM_MMU_FW;
    volatile Uint32 SECURE_EMIF_OBFUSC_KEY;
    volatile Uint32 SEC_CTRL_RO;
    volatile Uint32 SSM_END_FAST_SECRAM;
    volatile Uint32 STATUS;
    volatile Uint32 SEC_STATUS;
    volatile Uint32 SEC_MEM_STATUS;
    volatile Uint32 SEC_STATUS_MASK_DISABLE;
    volatile Uint32 SEC_MEM_STATUS_MASK_DISABLE;
    volatile Uint32 SEC_ERR_STATUS_FUNC_1;
    volatile Uint32 SEC_ERR_STATUS_FUNC_MASK_DISABLE_1;
    volatile Uint32 SEC_ERR_STATUS_DEBUG_1;
    volatile Uint32 HDCP_SEED0;
    volatile Uint32 HDCP_SEED1;
    volatile Uint32 MPU_FORCEWRNP;
    volatile Uint32 KEK_SW_0;
    volatile Uint32 KEK_SW_1;
    volatile Uint32 KEK_SW_2;
    volatile Uint32 KEK_SW_3;
    volatile Uint32 KEK_SW_4;
    volatile Uint32 KEK_SW_5;
    volatile Uint32 KEK_SW_6;
    volatile Uint32 KEK_SW_7;
    volatile Uint32 CEK_0;
    volatile Uint32 CEK_1;
    volatile Uint32 CEK_2;
    volatile Uint32 CEK_3;
    volatile Uint32 MSV;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_0;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_1;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_2;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_3;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_4;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_5;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_0;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_1;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_2;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_3;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_4;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_5;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_6;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_7;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_0;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_1;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_2;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_3;
    volatile Uint32 STD_FUSE_OPP_VDD_CORE_4;
    volatile Uint32 STD_FUSE_OPP_BGAP_GPU;
    volatile Uint32 STD_FUSE_OPP_BGAP_MPU;
    volatile Uint32 STD_FUSE_OPP_BGAP_CORE;
    volatile Uint32 STD_FUSE_OPP_BGAP_MPU23;
    volatile Uint8  RSVD0[48];
    volatile Uint32 STD_FUSE_MPK_0;
    volatile Uint32 STD_FUSE_MPK_1;
    volatile Uint32 STD_FUSE_MPK_2;
    volatile Uint32 STD_FUSE_MPK_3;
    volatile Uint32 STD_FUSE_MPK_4;
    volatile Uint32 STD_FUSE_MPK_5;
    volatile Uint32 STD_FUSE_MPK_6;
    volatile Uint32 STD_FUSE_MPK_7;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_0;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_1;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_2;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_3;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_4;
    volatile Uint32 STD_FUSE_OPP_VDD_GPU_LVT_5;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_0;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_1;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_2;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_3;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_4;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_5;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_6;
    volatile Uint32 STD_FUSE_OPP_VDD_MPU_LVT_7;
    volatile Uint8  RSVD1[20];
    volatile Uint32 CUST_FUSE_CEK_BCH_0;
    volatile Uint32 CUST_FUSE_CEK_BCH_1;
    volatile Uint32 CUST_FUSE_CEK_BCH_2;
    volatile Uint32 CUST_FUSE_CEK_BCH_3;
    volatile Uint32 CUST_FUSE_CEK_BCH_4;
    volatile Uint32 CUST_FUSE_CEK2_BCH_0;
    volatile Uint32 CUST_FUSE_CEK2_BCH_1;
    volatile Uint32 CUST_FUSE_CEK2_BCH_2;
    volatile Uint32 CUST_FUSE_CEK2_BCH_3;
    volatile Uint32 CUST_FUSE_CEK2_BCH_4;
    volatile Uint32 CUST_FUSE_MSV_BCH_0;
    volatile Uint32 CUST_FUSE_MSV_BCH_1;
    volatile Uint32 CUST_FUSE_SWRV_0;
    volatile Uint32 CUST_FUSE_SWRV_1;
    volatile Uint32 CUST_FUSE_SWRV_2;
    volatile Uint32 CUST_FUSE_SWRV_3;
    volatile Uint32 CUST_FUSE_SWRV_4;
    volatile Uint32 CUST_FUSE_SWRV_5;
    volatile Uint32 CUST_FUSE_SWRV_6;
    volatile Uint32 HWOBSDIVIDER1;
    volatile Uint32 HWOBSDIVIDER2;
    volatile Uint32 BREG_SELECTION;
    volatile Uint32 DPLL_BCLK;
    volatile Uint32 DPLL_BADDR_BDATAW;
    volatile Uint32 DPLL_BDATAR;
    volatile Uint8  RSVD2[16];
    volatile Uint32 DEV_CONF;
    volatile Uint32 IVA3_BOOTADDR;
    volatile Uint8  RSVD3[36];
    volatile Uint32 TEMP_SENSOR_MPU;
    volatile Uint32 TEMP_SENSOR_GPU;
    volatile Uint32 TEMP_SENSOR_CORE;
    volatile Uint8  RSVD4[4];
    volatile Uint32 STD_FUSE_DFT_MEM_RW_MPU;
    volatile Uint32 STD_FUSE_DFT_MEM_RW_MM;
    volatile Uint32 STD_FUSE_DFT_MEM_RW_CORE;
    volatile Uint8  RSVD5[16];
    volatile Uint32 DUCATI_MMUADDRTRANSLTR;
    volatile Uint32 DUCATI_MMUADDRLOGICTR;
    volatile Uint32 HWOBS_CONTROL;
    volatile Uint32 PCS1;
    volatile Uint32 PCS2;
    volatile Uint32 PCS_REVISION;
    volatile Uint32 PHY_POWER_USB;
    volatile Uint32 PHY_POWER_SATA;
    volatile Uint8  RSVD6[8];
    volatile Uint32 BANDGAP_MASK_1;
    volatile Uint32 BANDGAP_THRESHOLD_MPU;
    volatile Uint32 BANDGAP_THRESHOLD_GPU;
    volatile Uint32 BANDGAP_THRESHOLD_CORE;
    volatile Uint32 BANDGAP_TSHUT_MPU;
    volatile Uint32 BANDGAP_TSHUT_GPU;
    volatile Uint32 BANDGAP_TSHUT_CORE;
    volatile Uint32 BANDGAP_CUMUL_DTEMP_MPU;
    volatile Uint32 BANDGAP_CUMUL_DTEMP_GPU;
    volatile Uint32 BANDGAP_CUMUL_DTEMP_CORE;
    volatile Uint32 BANDGAP_STATUS_1;
    volatile Uint32 SATA_EXT_MODE;
    volatile Uint32 CEK2_0;
    volatile Uint32 CEK2_1;
    volatile Uint32 CEK2_2;
    volatile Uint32 CEK2_3;
    volatile Uint32 DTEMP_MPU_0;
    volatile Uint32 DTEMP_MPU_1;
    volatile Uint32 DTEMP_MPU_2;
    volatile Uint32 DTEMP_MPU_3;
    volatile Uint32 DTEMP_MPU_4;
    volatile Uint32 DTEMP_GPU_0;
    volatile Uint32 DTEMP_GPU_1;
    volatile Uint32 DTEMP_GPU_2;
    volatile Uint32 DTEMP_GPU_3;
    volatile Uint32 DTEMP_GPU_4;
    volatile Uint32 DTEMP_CORE_0;
    volatile Uint32 DTEMP_CORE_1;
    volatile Uint32 DTEMP_CORE_2;
    volatile Uint32 DTEMP_CORE_3;
    volatile Uint32 DTEMP_CORE_4;
    volatile Uint32 SMA_SW_0;
    volatile Uint32 MREQDOMAIN_EXP4;
    volatile Uint32 MREQDOMAIN_EXP5;
    volatile Uint32 L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2;
    volatile Uint32 L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2;
    volatile Uint8  RSVD7[4];
    volatile Uint32 SEC_ERR_STATUS_FUNC_2;
    volatile Uint32 SEC_ERR_STATUS_FUNC_MASK_DISABLE_2;
    volatile Uint32 SEC_ERR_STATUS_DEBUG_2;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_1;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_2;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_3;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_4;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_5;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_6;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_7;
    volatile Uint32 L3_INITIATOR_PRESSURE_1;
    volatile Uint32 L3_INITIATOR_PRESSURE_2;
    volatile Uint32 L3_INITIATOR_PRESSURE_3;
    volatile Uint32 L3_INITIATOR_PRESSURE_4;
    volatile Uint32 L3_INITIATOR_PRESSURE_5;
    volatile Uint32 L3_INITIATOR_PRESSURE_6;
    volatile Uint32 L3_INITIATOR_PRESSURE_7;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_0;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_1;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_2;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_3;
    volatile Uint32 STD_FUSE_OPP_VDD_IVA_4;
    volatile Uint32 LDOVBB_DSPEVE_VOLTAGE_CTRL;
    volatile Uint32 LDOVBB_IVA_VOLTAGE_CTRL;
    volatile Uint8  RSVD8[116];
    volatile Uint32 CUST_FUSE_UID_0;
    volatile Uint32 CUST_FUSE_UID_1;
    volatile Uint32 CUST_FUSE_UID_2;
    volatile Uint32 CUST_FUSE_UID_3;
    volatile Uint32 CUST_FUSE_UID_4;
    volatile Uint32 CUST_FUSE_UID_5;
    volatile Uint32 CUST_FUSE_UID_6;
    volatile Uint32 PCIE_ID_SW_0;
    volatile Uint32 CUST_FUSE_PCIE_ID_0;
    volatile Uint32 USB_ID_SW_0;
    volatile Uint32 CUST_FUSE_USB_ID_0;
    volatile Uint32 MAC_ID_SW_0;
    volatile Uint32 MAC_ID_SW_1;
    volatile Uint32 MAC_ID_SW_2;
    volatile Uint32 MAC_ID_SW_3;
    volatile Uint32 SW_ID_SW_0;
    volatile Uint32 SW_ID_SW_1;
    volatile Uint32 EFUSE_DISABLE_SW_0;
    volatile Uint32 SLEW_SW_0;
    volatile Uint32 SMA_SW_1;
    volatile Uint32 DSS_PLL_CONTROL;
    volatile Uint32 EMIF_INITIATOR_PRIORITY_8;
    volatile Uint32 MMR_LOCK_1;
    volatile Uint32 MMR_LOCK_2;
    volatile Uint32 MMR_LOCK_3;
    volatile Uint32 MMR_LOCK_4;
    volatile Uint32 MMR_LOCK_5;
    volatile Uint32 CONTROL_IO_1;
    volatile Uint32 CONTROL_IO_2;
    volatile Uint32 CONTROL_DSP1_RST_VECT;
    volatile Uint32 CONTROL_DSP2_RST_VECT;
    volatile Uint32 STD_FUSE_OPP_BGAP_DSPEVE;
    volatile Uint32 STD_FUSE_OPP_BGAP_IVA;
    volatile Uint32 LDOSRAM_DSPEVE_VOLTAGE_CTRL;
    volatile Uint32 LDOSRAM_IVA_VOLTAGE_CTRL;
    volatile Uint32 TEMP_SENSOR_DSPEVE;
    volatile Uint32 TEMP_SENSOR_IVA;
    volatile Uint32 BANDGAP_MASK_2;
    volatile Uint32 BANDGAP_THRESHOLD_DSPEVE;
    volatile Uint32 BANDGAP_THRESHOLD_IVA;
    volatile Uint32 BANDGAP_TSHUT_DSPEVE;
    volatile Uint32 BANDGAP_TSHUT_IVA;
    volatile Uint32 BANDGAP_CUMUL_DTEMP_DSPEVE;
    volatile Uint32 BANDGAP_CUMUL_DTEMP_IVA;
    volatile Uint32 BANDGAP_STATUS_2;
    volatile Uint32 DTEMP_DSPEVE_0;
    volatile Uint32 DTEMP_DSPEVE_1;
    volatile Uint32 DTEMP_DSPEVE_2;
    volatile Uint32 DTEMP_DSPEVE_3;
    volatile Uint32 DTEMP_DSPEVE_4;
    volatile Uint32 DTEMP_IVA_0;
    volatile Uint32 DTEMP_IVA_1;
    volatile Uint32 DTEMP_IVA_2;
    volatile Uint32 DTEMP_IVA_3;
    volatile Uint32 DTEMP_IVA_4;
    volatile Uint32 STD_FUSE_OPP_VMIN_IVA_0;
    volatile Uint32 STD_FUSE_OPP_VMIN_IVA_1;
    volatile Uint32 STD_FUSE_OPP_VMIN_IVA_2;
    volatile Uint32 STD_FUSE_OPP_VMIN_IVA_3;
    volatile Uint32 STD_FUSE_OPP_VMIN_IVA_4;
    volatile Uint32 STD_FUSE_OPP_VMIN_DSPEVE_0;
    volatile Uint32 STD_FUSE_OPP_VMIN_DSPEVE_1;
    volatile Uint32 STD_FUSE_OPP_VMIN_DSPEVE_2;
    volatile Uint32 STD_FUSE_OPP_VMIN_DSPEVE_3;
    volatile Uint32 STD_FUSE_OPP_VMIN_DSPEVE_4;
    volatile Uint32 STD_FUSE_OPP_VMIN_CORE_0;
    volatile Uint32 STD_FUSE_OPP_VMIN_CORE_1;
    volatile Uint32 STD_FUSE_OPP_VMIN_CORE_2;
    volatile Uint32 STD_FUSE_OPP_VMIN_CORE_3;
    volatile Uint32 STD_FUSE_OPP_VMIN_CORE_4;
    volatile Uint32 TRB1_LOW;
    volatile Uint32 TRB1_HIGH;
    volatile Uint32 TRB1_BUFFER;
    volatile Uint32 TRB1_NORMAL;
    volatile Uint32 TRB2_LOW;
    volatile Uint32 TRB2_HIGH;
    volatile Uint32 TRB2_BUFFER;
    volatile Uint32 TRB2_NORMAL;
    volatile Uint32 TRB3_LOW;
    volatile Uint32 TRB3_HIGH;
    volatile Uint32 TRB3_BUFFER;
    volatile Uint32 TRB3_NORMAL;
    volatile Uint32 DUMMY0;
    volatile Uint32 DUMMY1;
    volatile Uint32 DUMMY2;
    volatile Uint32 DUMMY3;
    volatile Uint32 CTRB1_LOW;
    volatile Uint32 CTRB1_HIGH;
    volatile Uint32 CTRB1_BUFFER;
    volatile Uint32 CTRB1_NORMAL;
    volatile Uint32 CTRB2_LOW;
    volatile Uint32 CTRB2_HIGH;
    volatile Uint32 CTRB2_BUFFER;
    volatile Uint32 CTRB2_NORMAL;
    volatile Uint32 CTRB3_LOW;
    volatile Uint32 CTRB3_HIGH;
    volatile Uint32 CTRB3_BUFFER;
    volatile Uint32 CTRB3_NORMAL;
    volatile Uint32 CDUMMY0;
    volatile Uint32 CDUMMY1;
    volatile Uint32 CDUMMY2;
    volatile Uint32 CDUMMY3;
    volatile Uint32 LDOSRAM_CORE_2_VOLTAGE_CTRL;
    volatile Uint32 LDOSRAM_CORE_3_VOLTAGE_CTRL;
    volatile Uint32 EFUSE_DISABLE_SW_1;
    volatile Uint32 NMI_DESTINATION_1;
    volatile Uint32 NMI_DESTINATION_2;
    volatile Uint32 DYNAMIC_DMM_ROUTING;
    volatile Uint32 IP_PRESSURE;
    volatile Uint32 SHA2_EVENT_MAPPING;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_0;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_1;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_2;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_3;
    volatile Uint32 STD_FUSE_OPP_VDD_DSPEVE_4;
    volatile Uint32 CUST_FUSE_SWRV_7;
    volatile Uint32 STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0;
    volatile Uint32 STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1;
    volatile Uint32 PCIE_POWER_STATE;
    volatile Uint32 BOOTSTRAP;
    volatile Uint32 MLB_SIG_IO_CTRL;
    volatile Uint32 MLB_DAT_IO_CTRL;
    volatile Uint32 MLB_CLK_BG_CTRL;
    volatile Uint8  RSVD9[8];
    volatile Uint32 CONTROL_LVDSRX;
    volatile Uint8  RSVD10[32];
    volatile Uint32 MEK_BCH_0;
    volatile Uint32 MEK_BCH_1;
    volatile Uint32 MEK_BCH_2;
    volatile Uint32 MEK_BCH_3;
    volatile Uint32 MEK_BCH_4;
    volatile Uint32 MEK_BCH_5;
    volatile Uint32 MEK_BCH_6;
    volatile Uint32 MEK_BCH_7;
    volatile Uint32 MEK_BCH_8;
    volatile Uint32 MEK_0;
    volatile Uint32 MEK_1;
    volatile Uint32 MEK_2;
    volatile Uint32 MEK_3;
    volatile Uint32 MEK_4;
    volatile Uint32 MEK_5;
    volatile Uint32 MEK_6;
    volatile Uint32 MEK_7;
    volatile Uint32 SMPK_BCH_0;
    volatile Uint32 SMPK_BCH_1;
    volatile Uint32 SMPK_BCH_2;
    volatile Uint32 SMPK_BCH_3;
    volatile Uint32 SMPK_BCH_4;
    volatile Uint32 SMPK_BCH_5;
    volatile Uint32 SMPK_BCH_6;
    volatile Uint32 SMPK_BCH_7;
    volatile Uint32 SMPK_BCH_8;
    volatile Uint32 SMPK_0;
    volatile Uint32 SMPK_1;
    volatile Uint32 SMPK_2;
    volatile Uint32 SMPK_3;
    volatile Uint32 SMPK_4;
    volatile Uint32 SMPK_5;
    volatile Uint32 SMPK_6;
    volatile Uint32 SMPK_7;
    volatile Uint32 SEC_SWRV_0;
    volatile Uint32 SEC_SWRV_1;
    volatile Uint32 MREQDOMAIN_EXP6;
    volatile Uint8  RSVD11[2156];
    volatile Uint32 HWOBS_FINAL_MUX_SEL;
    volatile Uint8  RSVD12[4];
    volatile Uint32 HWOBS_MMR_MPU;
    volatile Uint32 CONF_DEBUG_SEL_TST_0;
    volatile Uint32 CONF_DEBUG_SEL_TST_1;
    volatile Uint32 CONF_DEBUG_SEL_TST_2;
    volatile Uint32 CONF_DEBUG_SEL_TST_3;
    volatile Uint32 CONF_DEBUG_SEL_TST_4;
    volatile Uint32 CONF_DEBUG_SEL_TST_5;
    volatile Uint32 CONF_DEBUG_SEL_TST_6;
    volatile Uint32 CONF_DEBUG_SEL_TST_7;
    volatile Uint32 CONF_DEBUG_SEL_TST_8;
    volatile Uint32 CONF_DEBUG_SEL_TST_9;
    volatile Uint32 CONF_DEBUG_SEL_TST_10;
    volatile Uint32 CONF_DEBUG_SEL_TST_11;
    volatile Uint32 CONF_DEBUG_SEL_TST_12;
    volatile Uint32 CONF_DEBUG_SEL_TST_13;
    volatile Uint32 CONF_DEBUG_SEL_TST_14;
    volatile Uint32 CONF_DEBUG_SEL_TST_15;
    volatile Uint32 CONF_DEBUG_SEL_TST_16;
    volatile Uint32 CONF_DEBUG_SEL_TST_17;
    volatile Uint32 CONF_DEBUG_SEL_TST_18;
    volatile Uint32 CONF_DEBUG_SEL_TST_19;
    volatile Uint32 CONF_DEBUG_SEL_TST_20;
    volatile Uint32 CONF_DEBUG_SEL_TST_21;
    volatile Uint32 CONF_DEBUG_SEL_TST_22;
    volatile Uint32 CONF_DEBUG_SEL_TST_23;
    volatile Uint32 CONF_DEBUG_SEL_TST_24;
    volatile Uint32 CONF_DEBUG_SEL_TST_25;
    volatile Uint32 CONF_DEBUG_SEL_TST_26;
    volatile Uint32 CONF_DEBUG_SEL_TST_27;
    volatile Uint32 CONF_DEBUG_SEL_TST_28;
    volatile Uint32 CONF_DEBUG_SEL_TST_29;
    volatile Uint32 CONF_DEBUG_SEL_TST_30;
    volatile Uint32 CONF_DEBUG_SEL_TST_31;
    volatile Uint32 CONF_DEBUG_SEL_TST_32;
    volatile Uint32 CONF_DEBUG_SEL_TST_33;
    volatile Uint32 CONF_DEBUG_SEL_TST_34;
    volatile Uint32 CONF_DEBUG_SEL_TST_35;
    volatile Uint32 CONF_DEBUG_SEL_TST_36;
    volatile Uint32 CONF_DEBUG_SEL_TST_37;
    volatile Uint32 CONF_DEBUG_SEL_TST_38;
    volatile Uint32 CONF_DEBUG_SEL_TST_39;
    volatile Uint32 CONF_DEBUG_SEL_TST_40;
    volatile Uint32 CONF_DEBUG_SEL_TST_41;
    volatile Uint32 CONF_DEBUG_SEL_TST_42;
    volatile Uint32 CONF_DEBUG_SEL_TST_43;
    volatile Uint32 CONF_DEBUG_SEL_TST_44;
    volatile Uint32 CONF_DEBUG_SEL_TST_45;
    volatile Uint32 CONF_DEBUG_SEL_TST_46;
    volatile Uint32 CONF_DEBUG_SEL_TST_47;
} CSL_control_coreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* External Security Control Register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL                      (0x0U)

/* Security SW Register. GP device: Read-Write All. HS/T/E/B devices:
 * Read-Write Secure Privilege. */
#define CSL_CONTROL_CORE_SEC_SW_HW                              (0x4U)

/* CONTROL_MREQDOMAIN_EXP1 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1                        (0x8U)

/* CONTROL_MREQDOMAIN_EXP2 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2                        (0xCU)

/* CONTROL_MREQDOMAIN_EXP3 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3                        (0x10U)

/* L3_HW_FIREWALL_EXPORTED_VALUES_CONF_DBG register. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1    (0x14U)

/* L3_HW_FIREWALL_EXPORTED_VALUES_CONF_LOCK register. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1   (0x18U)

/* OMAP5430 L4_HW_FIREWALL_EXPORTED_VALUES_CONF register. Read All / Write
 * Secure Privilege. */
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF          (0x1CU)

/* CONTROL_SEC_ LOAD_FW_EXPORTED_VALUE register. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE             (0x20U)

/* DMM MMU firewall register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_DMM_MMU_FW                             (0x24U)

/* OMAP5430 EMIF Obfuscator registers. Read Secure Privilege / Write Secure
 * Privilege. No access when r_secure_emif_obfusc_en=1. */
#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY                 (0x28U)

/* Security Control Register extension in core. GP device: Read-Write All.
 * HS/T/E/B devices: Read-Write Secure Privilege. */
#define CSL_CONTROL_CORE_SEC_CTRL_RO                            (0x2CU)

/* Defines any public area in the TZ OCM-RAM inside MPU subsystem */
#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM                    (0x30U)

/* Control Module Status Register */
#define CSL_CONTROL_CORE_STATUS                                 (0x34U)

/* Security Status Register.#br#All bits in this register reflect chip
 * internal events [Application and debug] related to the Chip
 * security.#br#The individual bits are cleared on a write access (same value
 * written) in secure mode.#br#The software has the responsibility to clear
 * each bit after perusal of the events. */
#define CSL_CONTROL_CORE_SEC_STATUS                             (0x38U)

/* Security Memory Status Register.#br#All bits in this register reflect chip
 * internal events related to the Chip security.#br#The individual bits are
 * cleared on a write access (same value written) in secure mode.#br#The
 * software has the responsibility to clear each bit after perusal of the
 * events. */
#define CSL_CONTROL_CORE_SEC_MEM_STATUS                         (0x3CU)

/* Security Status Register Mask disable.#br#All bits in this register reflect
 * chip internal events [Application and debug] related to the Chip security
 * that can be masked through the bit settings. */
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE                (0x40U)

/* Security Memory Status Register Mask disable.#br#All bits in this register
 * reflect chip internal events related to the Chip security that can be
 * masked through the bit settings. */
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE            (0x44U)

/* Security Error Status functional Register */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1                  (0x48U)

/* Security Error Status functional mask disable Register */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1     (0x4CU)

/* Security Error Status functional Register */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1                 (0x50U)

/* HDCP seed 0 */
#define CSL_CONTROL_CORE_HDCP_SEED0                             (0x54U)

/* HDCP seed1 */
#define CSL_CONTROL_CORE_HDCP_SEED1                             (0x58U)

/* FORCE WRITE NON POSTED */
#define CSL_CONTROL_CORE_MPU_FORCEWRNP                          (0x5CU)

/* Standard Fuse keys, Random_key [31:0]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_0                               (0x60U)

/* Standard Fuse keys, Random_key [63:32]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_1                               (0x64U)

/* Standard Fuse keys, Random_key [95:64]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_2                               (0x68U)

/* Standard Fuse keys, Random_key [127:96]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_3                               (0x6CU)

/* Standard Fuse keys, Random_key [159:128]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_4                               (0x70U)

/* Standard Fuse keys, Random_key [191:160]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_5                               (0x74U)

/* Standard Fuse keys, Random_key [223:192]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_6                               (0x78U)

/* Standard Fuse keys, Random_key [255:224]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_KEK_SW_7                               (0x7CU)

/* Customer Fuse keys, Customer_key [31:0]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_CEK_0                                  (0x80U)

/* Customer Fuse keys, Customer_key [63:32]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK_1                                  (0x84U)

/* Customer Fuse keys, Customer_key [95:64]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK_2                                  (0x88U)

/* Customer Fuse keys, Customer_key [127:96]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK_3                                  (0x8CU)

/* Customer Fuse keys Model Identifier [31:0]. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_MSV                                    (0x90U)

/* Standard Fuse OPP VDD_GPU [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0                 (0x94U)

/* Standard Fuse OPP VDD_GPU [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1                 (0x98U)

/* Standard Fuse OPP VDD_GPU [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2                 (0x9CU)

/* Standard Fuse OPP VDD_GPU [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3                 (0xA0U)

/* Standard Fuse OPP VDD_GPU [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4                 (0xA4U)

/* Standard Fuse OPP VDD_GPU [191:160]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5                 (0xA8U)

/* Standard Fuse OPP VDD_MPU [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0                 (0xACU)

/* Standard Fuse OPP VDD_MPU [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1                 (0xB0U)

/* Standard Fuse OPP VDD_MPU [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2                 (0xB4U)

/* Standard Fuse OPP VDD_MPU [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3                 (0xB8U)

/* Standard Fuse OPP VDD_MPU [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4                 (0xBCU)

/* Standard Fuse OPP VDD_MPU [191:160]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5                 (0xC0U)

/* Standard Fuse OPP VDD_MPU [223:192]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6                 (0xC4U)

/* Standard Fuse OPP VDD_MPU [255:224]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7                 (0xC8U)

/* Standard Fuse OPP VDD_CORE [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0                (0xCCU)

/* Standard Fuse OPP VDD_CORE [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1                (0xD0U)

/* Standard Fuse OPP VDD_CORE [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2                (0xD4U)

/* Standard Fuse OPP VDD_CORE [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3                (0xD8U)

/* Standard Fuse OPP VDD_CORE [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4                (0xDCU)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU                  (0xE0U)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU                  (0xE4U)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE                 (0xE8U)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23                (0xECU)

/* Standard Fuse keys. Root_public_key_hash [31:0]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_0                         (0x120U)

/* Standard Fuse keys. Root_public_key_hash [63:32]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_1                         (0x124U)

/* Standard Fuse keys. Root_public_key_hash [95:64]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_2                         (0x128U)

/* Standard Fuse keys. Root_public_key_hash [127:96]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_3                         (0x12CU)

/* Standard Fuse keys. Root_public_key_hash [159:128]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_4                         (0x130U)

/* Standard Fuse keys. Root_public_key_hash [191:160]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_5                         (0x134U)

/* Standard Fuse keys. Root_public_key_hash [223:192]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_6                         (0x138U)

/* Standard Fuse keys. Root_public_key_hash [255:224]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_MPK_7                         (0x13CU)

/* Standard Fuse OPP VDD_GPU [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0             (0x140U)

/* Standard Fuse OPP VDD_GPU [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1             (0x144U)

/* Standard Fuse OPP VDD_GPU [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2             (0x148U)

/* Standard Fuse OPP VDD_GPU [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3             (0x14CU)

/* Standard Fuse OPP VDD_GPU [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4             (0x150U)

/* Standard Fuse OPP VDD_GPU [191:160]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5             (0x154U)

/* Standard Fuse OPP VDD_MPU [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0             (0x158U)

/* Standard Fuse OPP VDD_MPU [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1             (0x15CU)

/* Standard Fuse OPP VDD_MPU [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2             (0x160U)

/* Standard Fuse OPP VDD_MPU [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3             (0x164U)

/* Standard Fuse OPP VDD_MPU [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4             (0x168U)

/* Standard Fuse OPP VDD_MPU [191:160]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5             (0x16CU)

/* Standard Fuse OPP VDD_MPU [223:192]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6             (0x170U)

/* Standard Fuse OPP VDD_MPU [255:224]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7             (0x174U)

/* Coded Customer Fuse keys. Customer_key [31:0]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0                    (0x18CU)

/* Coded Customer Fuse keys. Customer_key [63:32]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1                    (0x190U)

/* Coded Customer Fuse keys. Customer_key [95:64]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2                    (0x194U)

/* Coded Customer Fuse keys. Customer_key [127:96]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3                    (0x198U)

/* Coded Customer Fuse keys. Customer_key [159:128]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4                    (0x19CU)

/* Coded Customer Fuse keys 2. Customer_key [31:0]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0                   (0x1A0U)

/* Coded Customer Fuse keys 2. Customer_key [63:32]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1                   (0x1A4U)

/* Coded Customer Fuse keys 2. Customer_key [95:64]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2                   (0x1A8U)

/* Coded Customer Fuse keys 2. Customer_key [127:96]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3                   (0x1ACU)

/* Coded Customer Fuse keys 2. Customer_key [159:128]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4                   (0x1B0U)

/* Coded Customer Fuse keys. Model Identifier [31:0]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0                    (0x1B4U)

/* Coded Customer Fuse keys. Model Identifier [63:32]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. Outside Secure Mode a read attempt to this registers returns an OCP
 * access error and no value is returned. */
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1                    (0x1B8U)

/* Customer Fuse keys. Software Version Control [031:000] (16 bits upper
 * Redundant field) [FIELD OVERFLOW]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0                       (0x1BCU)

/* Customer Fuse keys. Software Version Control [063:032] (16 bits upper
 * Redundant field) [FIELD F]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1                       (0x1C0U)

/* Customer Fuse keys. Software Version Control [095:064] (16 bits upper
 * Redundant field) [FIELD E]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2                       (0x1C4U)

/* Customer Fuse keys. Software Version Control [127:096] (16 bits upper
 * Redundant field) [FIELD D]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3                       (0x1C8U)

/* Customer Fuse keys. Software Version Control [159:127] (16 bits upper
 * Redundant field) [FIELD C]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4                       (0x1CCU)

/* Customer Fuse keys. Software Version Control [191:160] (16 bits upper
 * Redundant field) [FIELD B]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5                       (0x1D0U)

/* Customer Fuse keys. Software Version Control [223:192] (16 bits upper
 * Redundant field) [FIELD A]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6                       (0x1D4U)

/* Reserved */
#define CSL_CONTROL_CORE_HWOBSDIVIDER1                          (0x1D8U)

/* Reserved */
#define CSL_CONTROL_CORE_HWOBSDIVIDER2                          (0x1DCU)

/* DPLL selection */
#define CSL_CONTROL_CORE_BREG_SELECTION                         (0x1E0U)

/* DPLL selection */
#define CSL_CONTROL_CORE_DPLL_BCLK                              (0x1E4U)

/* DPLL selection */
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW                      (0x1E8U)

/* DPLL selection */
#define CSL_CONTROL_CORE_DPLL_BDATAR                            (0x1ECU)

/* Device configuration register. */
#define CSL_CONTROL_CORE_DEV_CONF                               (0x200U)

/* IVA3 boot loader physical address */
#define CSL_CONTROL_CORE_IVA3_BOOTADDR                          (0x204U)

/* Control VBGAPTS temperature sensor and thermal comparator shutdown register */
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU                        (0x22CU)

/* Control VBGAPTS temperature sensor and thermal comparator shutdown register */
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU                        (0x230U)

/* Control VBGAPTS temperature sensor and thermal comparator shutdown register */
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE                       (0x234U)

/* DFT Read and Write controls for memory blocks. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU                (0x23CU)

/* STD_FUSE_DFT_MEM_RW_MM */
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM                 (0x240U)

/* STD_FUSE_DFT_MEM_RW_CORE */
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE               (0x244U)

/* Ducati reg */
#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR                 (0x258U)

/* DUCATI_MMUADDRLOGICTR */
#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR                  (0x25CU)

/* HW observability control. This register enables or disables HW
 * observability outputs (to save power primarily) */
#define CSL_CONTROL_CORE_HWOBS_CONTROL                          (0x260U)

/* pcs1 */
#define CSL_CONTROL_CORE_PCS1                                   (0x264U)

/* pcs2 */
#define CSL_CONTROL_CORE_PCS2                                   (0x268U)

/* pcs_revision */
#define CSL_CONTROL_CORE_PCS_REVISION                           (0x26CU)

/* phy_power_usb */
#define CSL_CONTROL_CORE_PHY_POWER_USB                          (0x270U)

/* phy_power_sata */
#define CSL_CONTROL_CORE_PHY_POWER_SATA                         (0x274U)

/* bgap_mask */
#define CSL_CONTROL_CORE_BANDGAP_MASK_1                         (0x280U)

/* BGAP THRESHOLD MPU */
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU                  (0x284U)

/* BGAP THRESHOLD MM */
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU                  (0x288U)

/* BGAP THRESHOLD CORE */
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE                 (0x28CU)

/* BGAP TSHUT THRESHOLD MPU */
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU                      (0x290U)

/* BGAP TSHUT THRESHOLD GPU */
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU                      (0x294U)

/* BGAP TSHUT THRESHOLD CORE */
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE                     (0x298U)

/* BGAP COUNTER MPU */
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU                (0x29CU)

/* BGAP COUNTER MM */
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU                (0x2A0U)

/* BGAP COUNTER CORE */
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE               (0x2A4U)

/* BGAP STATUS */
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1                       (0x2A8U)

/* SATA EXTENDED MODE */
#define CSL_CONTROL_CORE_SATA_EXT_MODE                          (0x2ACU)

/* Customer Fuse keys, Customer_key2 [31:0]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK2_0                                 (0x2B0U)

/* Customer Fuse keys, Customer_key2 [63:32]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK2_1                                 (0x2B4U)

/* Customer Fuse keys, Customer_key2 [95:64]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK2_2                                 (0x2B8U)

/* Customer Fuse keys, Customer_key2 [127:96]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. */
#define CSL_CONTROL_CORE_CEK2_3                                 (0x2BCU)

/* TAGGED TEMPERATURE MPU DOMAIN. Most recent sample */
#define CSL_CONTROL_CORE_DTEMP_MPU_0                            (0x2C0U)

/* TAGGED TEMPERATURE MPU DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_MPU_1                            (0x2C4U)

/* TAGGED TEMPERATURE MPU DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_MPU_2                            (0x2C8U)

/* TAGGED TEMPERATURE MPU DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_MPU_3                            (0x2CCU)

/* TAGGED TEMPERATURE MPU DOMAIN. Oldest sample */
#define CSL_CONTROL_CORE_DTEMP_MPU_4                            (0x2D0U)

/* TAGGED TEMPERATURE GPU DOMAIN. Most recent sample. */
#define CSL_CONTROL_CORE_DTEMP_GPU_0                            (0x2D4U)

/* TAGGED TEMPERATURE GPU DOMAIN. */
#define CSL_CONTROL_CORE_DTEMP_GPU_1                            (0x2D8U)

/* TAGGED TEMPERATURE GPU DOMAIN. */
#define CSL_CONTROL_CORE_DTEMP_GPU_2                            (0x2DCU)

/* TAGGED TEMPERATURE GPU DOMAIN. */
#define CSL_CONTROL_CORE_DTEMP_GPU_3                            (0x2E0U)

/* TAGGED TEMPERATURE GPU DOMAIN. Oldest sample. */
#define CSL_CONTROL_CORE_DTEMP_GPU_4                            (0x2E4U)

/* TAGGED TEMPERATURE CORE DOMAIN. Most recent sample. */
#define CSL_CONTROL_CORE_DTEMP_CORE_0                           (0x2E8U)

/* TAGGED TEMPERATURE CORE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_CORE_1                           (0x2ECU)

/* TAGGED TEMPERATURE CORE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_CORE_2                           (0x2F0U)

/* TAGGED TEMPERATURE CORE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_CORE_3                           (0x2F4U)

/* TAGGED TEMPERATURE CORE DOMAIN. Oldest sample. */
#define CSL_CONTROL_CORE_DTEMP_CORE_4                           (0x2F8U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SMA_SW_0                               (0x2FCU)

/* CONTROL_MREQDOMAIN_EXP4 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4                        (0x300U)

/* CONTROL_MREQDOMAIN_EXP5 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5                        (0x304U)

/* L3_HW_FIREWALL_EXPORTED_VALUES_CONF_DBG register. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2    (0x308U)

/* L3_HW_FIREWALL_EXPORTED_VALUES_CONF_LOCK register. Read All / Write Secure
 * Privilege. */
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2   (0x30CU)

/* SEC_ERR_STATUS_FUNC_2 */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2                  (0x314U)

/* Security Error Status functional mask disable Register */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2     (0x318U)

/* Security Error Status functional Register */
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2                 (0x31CU)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1              (0x320U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2              (0x324U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3              (0x328U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4              (0x32CU)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5              (0x330U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6              (0x334U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7              (0x338U)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1                (0x33CU)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2                (0x340U)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3                (0x344U)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4                (0x348U)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5                (0x34CU)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6                (0x350U)

/* Register for pressure settings for L3 arbitration */
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_7                (0x354U)

/* Standard Fuse OPP VDD_iva [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0                 (0x358U)

/* Standard Fuse OPP VDD_iva [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1                 (0x35CU)

/* Standard Fuse OPP VDD_iva [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2                 (0x360U)

/* Standard Fuse OPP VDD_iva [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3                 (0x364U)

/* Standard Fuse OPP VDD_iva [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4                 (0x368U)

/* DSPEVE Voltage Body Bias LDO Control register */
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL             (0x36CU)

/* IVA Voltage Body Bias LDO Control register */
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL                (0x370U)

/* Customer Fuse keys. UID [031:000] (16 bits upper Redundant field) [FIELD
 * OVERFLOW]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_0                        (0x3E8U)

/* Customer Fuse keys. UID [063:032] (16 bits upper Redundant field) [FIELD
 * F]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_1                        (0x3ECU)

/* Customer Fuse keys. UID [095:064] (16 bits upper Redundant field) [FIELD
 * E]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_2                        (0x3F0U)

/* Customer Fuse keys. UID [127:096] (16 bits upper Redundant field) [FIELD
 * D]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_3                        (0x3F4U)

/* Customer Fuse keys. UID [159:127] (16 bits upper Redundant field) [FIELD
 * C]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_4                        (0x3F8U)

/* Customer Fuse keys. UID [191:160] (16 bits upper Redundant field) [FIELD
 * B]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_5                        (0x3FCU)

/* Customer Fuse keys. UID [223:192] (16 bits upper Redundant field) [FIELD
 * A]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_UID_6                        (0x400U)

/* Standard Fuse keys, PCIe ID [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_PCIE_ID_SW_0                           (0x404U)

/* Customer Fuse keys. PCIe ID [031:000] (16 bits upper Redundant field)
 * [FIELD OVERFLOW]. Register shows part of the chip eFuse configuration on
 * the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0                    (0x408U)

/* Standard Fuse keys, USB ID [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_USB_ID_SW_0                            (0x40CU)

/* Customer Fuse keys. USB ID [031:000] (16 bits upper Redundant field) [FIELD
 * OVERFLOW]. Register shows part of the chip eFuse configuration on the OCP
 * interface. Reading at the address of one of these registers provides a
 * direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0                     (0x410U)

/* Standard Fuse keys, MAC ID_1 [63:32]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MAC_ID_SW_0                            (0x414U)

/* Standard Fuse keys, MAC ID_1 [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MAC_ID_SW_1                            (0x418U)

/* Standard Fuse keys, MAC ID_2 [63:32]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MAC_ID_SW_2                            (0x41CU)

/* Standard Fuse keys, MAC ID_2 [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MAC_ID_SW_3                            (0x420U)

/* Standard Fuse keys, SW ID [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SW_ID_SW_0                             (0x424U)

/* Standard Fuse keys, SW ID [31:0]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. Read
 * Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SW_ID_SW_1                             (0x428U)

/* Standard Fuse keys, IP DISABLE [31:0]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0                     (0x42CU)

/* Standard Fuse keys, SLEW [31:0]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. Read Secure
 * Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SLEW_SW_0                              (0x430U)

/* OCP Spare Register */
#define CSL_CONTROL_CORE_SMA_SW_1                               (0x434U)

/* DSS PLLs Mux control register */
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL                        (0x438U)

/* Register for priority settings for EMIF arbitration */
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8              (0x43CU)

/* Register to lock memory region */
#define CSL_CONTROL_CORE_MMR_LOCK_1                             (0x440U)

/* Register to lock memory region */
#define CSL_CONTROL_CORE_MMR_LOCK_2                             (0x444U)

/* Register to lock memory region */
#define CSL_CONTROL_CORE_MMR_LOCK_3                             (0x448U)

/* Register to lock memory region */
#define CSL_CONTROL_CORE_MMR_LOCK_4                             (0x44CU)

/* Register to lock memory region */
#define CSL_CONTROL_CORE_MMR_LOCK_5                             (0x450U)

/* Register to configure some IP level signals */
#define CSL_CONTROL_CORE_CONTROL_IO_1                           (0x454U)

/* Register to configure some IP level signals */
#define CSL_CONTROL_CORE_CONTROL_IO_2                           (0x458U)

/* Register for storing DSP1 reset vector */
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT                  (0x45CU)

/* Register for storing DSP2 reset vector */
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT                  (0x460U)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE               (0x464U)

/* Standard Fuse OPP BGAP. Register shows part of the chip eFuse configuration
 * on the OCP interface. Reading at the address of one of these registers
 * provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA                  (0x468U)

/* DSPEVE SRAM LDO Control register */
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL            (0x46CU)

/* IVA SRAM LDO Control register */
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL               (0x470U)

/* Control VBGAPTS temperature sensor and thermal comparator shutdown register */
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE                     (0x474U)

/* Control VBGAPTS temperature sensor and thermal comparator shutdown register */
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA                        (0x478U)

/* bgap_mask */
#define CSL_CONTROL_CORE_BANDGAP_MASK_2                         (0x47CU)

/* BGAP THRESHOLD DSPEVE */
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE               (0x480U)

/* BGAP THRESHOLD IVA */
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA                  (0x484U)

/* BGAP TSHUT THRESHOLD IVA */
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE                   (0x488U)

/* BGAP TSHUT THRESHOLD IVA */
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA                      (0x48CU)

/* BGAP COUNTER DSPEVE */
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE             (0x490U)

/* BGAP COUNTER IVA */
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA                (0x494U)

/* BGAP STATUS */
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2                       (0x498U)

/* TAGGED TEMPERATURE DSPEVE DOMAIN. Most recent sample */
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0                         (0x49CU)

/* TAGGED TEMPERATURE DSPEVE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1                         (0x4A0U)

/* TAGGED TEMPERATURE DSPEVE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2                         (0x4A4U)

/* TAGGED TEMPERATURE DSPEVE DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3                         (0x4A8U)

/* TAGGED TEMPERATURE DSPEVE DOMAIN. Oldest sample */
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4                         (0x4ACU)

/* TAGGED TEMPERATURE IVA DOMAIN. Most recent sample */
#define CSL_CONTROL_CORE_DTEMP_IVA_0                            (0x4B0U)

/* TAGGED TEMPERATURE IVA DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_IVA_1                            (0x4B4U)

/* TAGGED TEMPERATURE IVA DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_IVA_2                            (0x4B8U)

/* TAGGED TEMPERATURE IVA DOMAIN */
#define CSL_CONTROL_CORE_DTEMP_IVA_3                            (0x4BCU)

/* TAGGED TEMPERATURE IVA DOMAIN. Oldest sample */
#define CSL_CONTROL_CORE_DTEMP_IVA_4                            (0x4C0U)

/* Standard Fuse OPP Vmin_IVA [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0                (0x4C4U)

/* Standard Fuse OPP Vmin_IVA [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1                (0x4C8U)

/* Standard Fuse OPP Vmin_IVA [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2                (0x4CCU)

/* Standard Fuse OPP Vmin_IVA [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3                (0x4D0U)

/* Standard Fuse OPP Vmin_IVA [159:128]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4                (0x4D4U)

/* Standard Fuse OPP Vmin_DSPEVE [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0             (0x4D8U)

/* Standard Fuse OPP Vmin_DSPEVE [63:32]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1             (0x4DCU)

/* Standard Fuse OPP Vmin_DSPEVE [95:64]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2             (0x4E0U)

/* Standard Fuse OPP Vmin_DSPEVE [127:96]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3             (0x4E4U)

/* Standard Fuse OPP Vmin_DSPEVE [159:128]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4             (0x4E8U)

/* Standard Fuse OPP Vmin_CORE [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0               (0x4ECU)

/* Standard Fuse OPP Vmin_CORE [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1               (0x4F0U)

/* Standard Fuse OPP Vmin_CORE [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2               (0x4F4U)

/* Standard Fuse OPP Vmin_CORE [127:96]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3               (0x4F8U)

/* Standard Fuse OPP Vmin_CORE [159:128]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4               (0x4FCU)

/* TRB1_LOW */
#define CSL_CONTROL_CORE_TRB1_LOW                               (0x500U)

/* TRB1_HIGH */
#define CSL_CONTROL_CORE_TRB1_HIGH                              (0x504U)

/* TRB1_BUFFER */
#define CSL_CONTROL_CORE_TRB1_BUFFER                            (0x508U)

/* TRB1_NORMAL */
#define CSL_CONTROL_CORE_TRB1_NORMAL                            (0x50CU)

/* TRB2_LOW */
#define CSL_CONTROL_CORE_TRB2_LOW                               (0x510U)

/* TRB2_HIGH */
#define CSL_CONTROL_CORE_TRB2_HIGH                              (0x514U)

/* TRB2_BUFFER */
#define CSL_CONTROL_CORE_TRB2_BUFFER                            (0x518U)

/* TRB2_NORMAL */
#define CSL_CONTROL_CORE_TRB2_NORMAL                            (0x51CU)

/* TRB3_LOW */
#define CSL_CONTROL_CORE_TRB3_LOW                               (0x520U)

/* TRB3_HIGH */
#define CSL_CONTROL_CORE_TRB3_HIGH                              (0x524U)

/* TRB3_BUFFER */
#define CSL_CONTROL_CORE_TRB3_BUFFER                            (0x528U)

/* TRB3_NORMAL */
#define CSL_CONTROL_CORE_TRB3_NORMAL                            (0x52CU)

/* DUMMY0 */
#define CSL_CONTROL_CORE_DUMMY0                                 (0x530U)

/* DUMMY1 */
#define CSL_CONTROL_CORE_DUMMY1                                 (0x534U)

/* DUMMY2 */
#define CSL_CONTROL_CORE_DUMMY2                                 (0x538U)

/* DUMMY3 */
#define CSL_CONTROL_CORE_DUMMY3                                 (0x53CU)

/* CTRB1_LOW */
#define CSL_CONTROL_CORE_CTRB1_LOW                              (0x540U)

/* CTRB1_HIGH */
#define CSL_CONTROL_CORE_CTRB1_HIGH                             (0x544U)

/* CTRB1_BUFFER */
#define CSL_CONTROL_CORE_CTRB1_BUFFER                           (0x548U)

/* CTRB1_NORMAL */
#define CSL_CONTROL_CORE_CTRB1_NORMAL                           (0x54CU)

/* CTRB2_LOW */
#define CSL_CONTROL_CORE_CTRB2_LOW                              (0x550U)

/* CTRB2_HIGH */
#define CSL_CONTROL_CORE_CTRB2_HIGH                             (0x554U)

/* CTRB2_BUFFER */
#define CSL_CONTROL_CORE_CTRB2_BUFFER                           (0x558U)

/* CTRB2_NORMAL */
#define CSL_CONTROL_CORE_CTRB2_NORMAL                           (0x55CU)

/* CTRB3_LOW */
#define CSL_CONTROL_CORE_CTRB3_LOW                              (0x560U)

/* CTRB3_HIGH */
#define CSL_CONTROL_CORE_CTRB3_HIGH                             (0x564U)

/* CTRB3_BUFFER */
#define CSL_CONTROL_CORE_CTRB3_BUFFER                           (0x568U)

/* CTRB3_NORMAL */
#define CSL_CONTROL_CORE_CTRB3_NORMAL                           (0x56CU)

/* CDUMMY0 */
#define CSL_CONTROL_CORE_CDUMMY0                                (0x570U)

/* CDUMMY1 */
#define CSL_CONTROL_CORE_CDUMMY1                                (0x574U)

/* CDUMMY2 */
#define CSL_CONTROL_CORE_CDUMMY2                                (0x578U)

/* CDUMMY3 */
#define CSL_CONTROL_CORE_CDUMMY3                                (0x57CU)

/* CORE 2nd SRAM LDO Control register */
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL            (0x580U)

/* CORE 3rd SRAM LDO Control register */
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL            (0x584U)

/* Standard Fuse keys, IP DISABLE [31:0]. Outside Secure Mode a read attempt
 * to this registers returns an OCP access error and no value is returned.
 * Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1                     (0x588U)

/* Register for routing NMI interrupt to respective cores */
#define CSL_CONTROL_CORE_NMI_DESTINATION_1                      (0x58CU)

/* NMI_DESTINATION_2 */
#define CSL_CONTROL_CORE_NMI_DESTINATION_2                      (0x590U)

/* Register for routing some IP initiator ports to DMM ports */
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING                    (0x594U)

/* Register to override L3 pressure setting for some IPs */
#define CSL_CONTROL_CORE_IP_PRESSURE                            (0x598U)

/* Register to set the mux control for 2nd instance of SHA2MD5 */
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING                     (0x59CU)

/* Standard Fuse OPP VDD_DSPEVE [31:0]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0              (0x5A0U)

/* Standard Fuse OPP VDD_DSPEVE [63:32]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1              (0x5A4U)

/* Standard Fuse OPP VDD_DSPEVE [95:64]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2              (0x5A8U)

/* Standard Fuse OPP VDD_DSPEVE [127:96]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3              (0x5ACU)

/* Standard Fuse OPP VDD_DSPEVE [159:128]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4              (0x5B0U)

/* Customer Fuse keys. SWRV [31:0] (16 bits upper Redundant field) [FIELD A].
 * Register shows part of the chip eFuse configuration on the OCP interface.
 * Reading at the address of one of these registers provides a direct view
 * into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7                       (0x5B4U)

/* Standard Fuse Calibration override value [31:0]. Register shows part of the
 * chip eFuse configuration on the OCP interface. Reading at the address of
 * one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0  (0x5B8U)

/* Standard Fuse Calibration override value [63:32]. Register shows part of
 * the chip eFuse configuration on the OCP interface. Reading at the address
 * of one of these registers provides a direct view into a part of the eFuse
 * chain. */
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1  (0x5BCU)

/* Register to PCIe related controls */
#define CSL_CONTROL_CORE_PCIE_POWER_STATE                       (0x5C0U)

/* Register to view all the sysboot settings */
#define CSL_CONTROL_CORE_BOOTSTRAP                              (0x5C4U)

/* Register to set the MLB's SIG IO characteristics */
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL                        (0x5C8U)

/* Register to set the MLB's DAT IO characteristics */
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL                        (0x5CCU)

/* Register to set the MLB's clock receiver IO and bandgap characteristics */
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL                        (0x5D0U)

/* Register to configure LVDSRX signals */
#define CSL_CONTROL_CORE_CONTROL_LVDSRX                         (0x5DCU)

/* Coded Standard Fuse keys. MEK_BCH[31:0]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain.
 * Outside Secure Mode a read attempt to this registers returns an OCP access
 * error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_BCH_0                              (0x600U)

/* Coded Standard Fuse keys. MEK_BCH[63:32]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain.
 * Outside Secure Mode a read attempt to this registers returns an OCP access
 * error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_BCH_1                              (0x604U)

/* Coded Standard Fuse keys. MEK_BCH[95:64]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_2                              (0x608U)

/* Coded Standard Fuse keys. MEK_BCH[127:96]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_3                              (0x60CU)

/* Coded Standard Fuse keys. MEK_BCH[159:128]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_4                              (0x610U)

/* Coded Standard Fuse keys. MEK_BCH[191:160]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_5                              (0x614U)

/* Coded Standard Fuse keys. MEK_BCH[223:192]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_6                              (0x618U)

/* Coded Standard Fuse keys. MEK_BCH[255:224]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_7                              (0x61CU)

/* Coded Standard Fuse keys. MEK_BCH[287:256]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MEK_BCH_8                              (0x620U)

/* Standard Fuse keys, MEK[31:0]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_0                                  (0x624U)

/* Standard Fuse keys, MEK[63:32]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_1                                  (0x628U)

/* Standard Fuse keys, MEK[95:64]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_2                                  (0x62CU)

/* Standard Fuse keys, MEK[127:96]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_3                                  (0x630U)

/* Standard Fuse keys, MEK[159:128]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_4                                  (0x634U)

/* Standard Fuse keys, MEK[191:160]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_5                                  (0x638U)

/* Standard Fuse keys, MEK[223:192]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_6                                  (0x63CU)

/* Standard Fuse keys, MEK[255:224]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_MEK_7                                  (0x640U)

/* Coded Customer Fuse keys. SMPK_BCH[31:0]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain.
 * Outside Secure Mode a read attempt to this registers returns an OCP access
 * error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_BCH_0                             (0x644U)

/* Coded Customer Fuse keys. SMPK_BCH[63:32]. Register shows part of the chip
 * eFuse configuration on the OCP interface. Reading at the address of one of
 * these registers provides a direct view into a part of the eFuse chain.
 * Outside Secure Mode a read attempt to this registers returns an OCP access
 * error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_BCH_1                             (0x648U)

/* Coded Customer Fuse keys. SMPK_BCH[95:64]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_2                             (0x64CU)

/* Coded Customer Fuse keys. SMPK_BCH[127:96]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_3                             (0x650U)

/* Coded Customer Fuse keys. SMPK_BCH[159:128]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_4                             (0x654U)

/* Coded Customer Fuse keys. SMPK_BCH[191:160]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_5                             (0x658U)

/* Coded Customer Fuse keys. SMPK_BCH[223:192]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_6                             (0x65CU)

/* Coded Customer Fuse keys. SMPK_BCH[255:224]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_7                             (0x660U)

/* Coded Customer Fuse keys. SMPK_BCH[287:256]. Outside Secure Mode a read
 * attempt to this registers returns an OCP access error and no value is
 * returned. Read Secure Privilege / Write Secure Privilege. */
#define CSL_CONTROL_CORE_SMPK_BCH_8                             (0x664U)

/* Customer Fuse keys, SMPK[31:0]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_0                                 (0x668U)

/* Customer Fuse keys, SMPK[63:32]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_1                                 (0x66CU)

/* Customer Fuse keys, SMPK[95:64]. Outside Secure Mode a read attempt to this
 * registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_2                                 (0x670U)

/* Customer Fuse keys, SMPK[127:96]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_3                                 (0x674U)

/* Customer Fuse keys, SMPK[159:128]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_4                                 (0x678U)

/* Customer Fuse keys, SMPK[191:160]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_5                                 (0x67CU)

/* Customer Fuse keys, SMPK[223:192]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_6                                 (0x680U)

/* Customer Fuse keys, SMPK[256:224]. Outside Secure Mode a read attempt to
 * this registers returns an OCP access error and no value is returned. */
#define CSL_CONTROL_CORE_SMPK_7                                 (0x684U)

/* Customer Fuse keys. Software Version Control [31:0] (16 bits upper
 * Redundant field) [FIELD OVERFLOW]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_SWRV_0                             (0x688U)

/* Customer Fuse keys. Software Version Control [63:32] (16 bits upper
 * Redundant field) [FIELD F]. Register shows part of the chip eFuse
 * configuration on the OCP interface. Reading at the address of one of these
 * registers provides a direct view into a part of the eFuse chain. */
#define CSL_CONTROL_CORE_SEC_SWRV_1                             (0x68CU)

/* CONTROL_MREQDOMAIN_EXP6 register. Read All / Write Secure Privilege. */
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6                        (0x690U)

/* HWOBS_FINAL_MUX_SEL */
#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL                    (0xF00U)

/* HWOBS_MMR_MPU */
#define CSL_CONTROL_CORE_HWOBS_MMR_MPU                          (0xF08U)

/* CONF_DEBUG_SEL_TST_0 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0                   (0xF0CU)

/* CONF_DEBUG_SEL_TST_1 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1                   (0xF10U)

/* CONF_DEBUG_SEL_TST_2 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2                   (0xF14U)

/* CONF_DEBUG_SEL_TST_3 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3                   (0xF18U)

/* CONF_DEBUG_SEL_TST_4 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4                   (0xF1CU)

/* CONF_DEBUG_SEL_TST_5 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5                   (0xF20U)

/* CONF_DEBUG_SEL_TST_6 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6                   (0xF24U)

/* CONF_DEBUG_SEL_TST_7 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7                   (0xF28U)

/* CONF_DEBUG_SEL_TST_8 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8                   (0xF2CU)

/* CONF_DEBUG_SEL_TST_9 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9                   (0xF30U)

/* CONF_DEBUG_SEL_TST_10 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10                  (0xF34U)

/* CONF_DEBUG_SEL_TST_11 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11                  (0xF38U)

/* CONF_DEBUG_SEL_TST_12 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12                  (0xF3CU)

/* CONF_DEBUG_SEL_TST_13 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13                  (0xF40U)

/* CONF_DEBUG_SEL_TST_14 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14                  (0xF44U)

/* CONF_DEBUG_SEL_TST_15 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15                  (0xF48U)

/* CONF_DEBUG_SEL_TST_16 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16                  (0xF4CU)

/* CONF_DEBUG_SEL_TST_17 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17                  (0xF50U)

/* CONF_DEBUG_SEL_TST_18 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18                  (0xF54U)

/* CONF_DEBUG_SEL_TST_19 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19                  (0xF58U)

/* CONF_DEBUG_SEL_TST_20 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20                  (0xF5CU)

/* CONF_DEBUG_SEL_TST_21 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21                  (0xF60U)

/* CONF_DEBUG_SEL_TST_22 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22                  (0xF64U)

/* CONF_DEBUG_SEL_TST_23 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23                  (0xF68U)

/* CONF_DEBUG_SEL_TST_24 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24                  (0xF6CU)

/* CONF_DEBUG_SEL_TST_25 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25                  (0xF70U)

/* CONF_DEBUG_SEL_TST_26 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26                  (0xF74U)

/* CONF_DEBUG_SEL_TST_27 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27                  (0xF78U)

/* CONF_DEBUG_SEL_TST_28 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28                  (0xF7CU)

/* CONF_DEBUG_SEL_TST_29 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29                  (0xF80U)

/* CONF_DEBUG_SEL_TST_30 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30                  (0xF84U)

/* CONF_DEBUG_SEL_TST_31 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31                  (0xF88U)

/* CONF_DEBUG_SEL_TST_32 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32                  (0xF8CU)

/* CONF_DEBUG_SEL_TST_33 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33                  (0xF90U)

/* CONF_DEBUG_SEL_TST_34 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34                  (0xF94U)

/* CONF_DEBUG_SEL_TST_35 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35                  (0xF98U)

/* CONF_DEBUG_SEL_TST_36 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36                  (0xF9CU)

/* CONF_DEBUG_SEL_TST_37 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37                  (0xFA0U)

/* CONF_DEBUG_SEL_TST_38 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38                  (0xFA4U)

/* CONF_DEBUG_SEL_TST_39 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39                  (0xFA8U)

/* CONF_DEBUG_SEL_TST_40 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40                  (0xFACU)

/* CONF_DEBUG_SEL_TST_41 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41                  (0xFB0U)

/* CONF_DEBUG_SEL_TST_42 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42                  (0xFB4U)

/* CONF_DEBUG_SEL_TST_43 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43                  (0xFB8U)

/* CONF_DEBUG_SEL_TST_44 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44                  (0xFBCU)

/* CONF_DEBUG_SEL_TST_45 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45                  (0xFC0U)

/* CONF_DEBUG_SEL_TST_46 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46                  (0xFC4U)

/* CONF_DEBUG_SEL_TST_47 */
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47                  (0xFC8U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* EXTERNAL_SEC_CTRL */

#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION1_CHIP_SEC_ENABLE_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION1_CHIP_SEC_ENABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION1_CHIP_SEC_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION1_CHIP_SEC_ENABLE_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION1_CHIP_SEC_ENABLE_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_I2CS_ENABLE_MASK     (0x00000004U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_I2CS_ENABLE_SHIFT    (2U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_I2CS_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_I2CS_ENABLE_RESTRICTED  (0x00000001U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_I2CS_ENABLE_UNRESTRICTED  (0x00000000U)

#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION0_CHIP_SEC_ENABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION0_CHIP_SEC_ENABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION0_CHIP_SEC_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION0_CHIP_SEC_ENABLE_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_COMPANION0_CHIP_SEC_ENABLE_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_SECURE_EXECUTION_INDICATOR_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_SECURE_EXECUTION_INDICATOR_SHIFT  (0U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_SECURE_EXECUTION_INDICATOR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_SECURE_EXECUTION_INDICATOR_SET  (0x00000001U)
#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_SECURE_EXECUTION_INDICATOR_RESET  (0x00000000U)

#define CSL_CONTROL_CORE_EXTERNAL_SEC_CTRL_RESETVAL             (0x00000000U)

/* SEC_SW_HW */

#define CSL_CONTROL_CORE_SEC_SW_HW_SEC_SW_HW_PARAM_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SW_HW_SEC_SW_HW_PARAM_SHIFT        (0U)
#define CSL_CONTROL_CORE_SEC_SW_HW_SEC_SW_HW_PARAM_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SW_HW_SEC_SW_HW_PARAM_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SW_HW_RESETVAL                     (0x00000000U)

/* MREQDOMAIN_EXP1 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_EXP1_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_EXP1_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_EXP1_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_EXP1_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU2_MASK   (0x38000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU2_SHIFT  (27U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU2_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP2_CFG_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP2_CFG_SHIFT  (24U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP2_CFG_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP2_CFG_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_GPU_P1_MASK  (0x00E00000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_GPU_P1_SHIFT  (21U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_GPU_P1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_GPU_P1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU1_MASK   (0x001C0000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU1_SHIFT  (18U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IPU1_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED2_ISS_MASK  (0x00038000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED2_ISS_SHIFT  (15U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED2_ISS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED2_ISS_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IVAHD_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IVAHD_SHIFT  (12U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IVAHD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_IVAHD_MAX   (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSS_MASK    (0x00000E00U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSS_SHIFT   (9U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSS_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP1_CFG_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP1_CFG_SHIFT  (6U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP1_CFG_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_DSP1_CFG_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED1_FACEDETECT_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED1_FACEDETECT_SHIFT  (3U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED1_FACEDETECT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_RESERVED1_FACEDETECT_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_P1500_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_P1500_SHIFT  (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_P1500_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_MREQDOMAIN_P1500_MAX   (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP1_RESETVAL               (0x00000000U)

/* MREQDOMAIN_EXP2 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EXP2_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EXP2_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EXP2_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EXP2_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE3_TC0_MASK  (0x38000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE3_TC0_SHIFT  (27U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE3_TC0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE3_TC0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_SATA_MASK   (0x07000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_SATA_SHIFT  (24U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_SATA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_SATA_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB3_MASK   (0x00E00000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB3_SHIFT  (21U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB3_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB2_MASK   (0x001C0000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB2_SHIFT  (18U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB2_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB1_MASK   (0x00007000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB1_SHIFT  (12U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_USB1_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE2_TC0_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE2_TC0_SHIFT  (9U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE2_TC0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE2_TC0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE1_TC0_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE1_TC0_SHIFT  (6U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE1_TC0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_EVE1_TC0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC2_MASK   (0x00000038U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC2_SHIFT  (3U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC2_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC1_MASK   (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC1_SHIFT  (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_MREQDOMAIN_MMC1_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP2_RESETVAL               (0x00000000U)

/* MREQDOMAIN_EXP3 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EXP3_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EXP3_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EXP3_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EXP3_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_USB4_MASK   (0x07000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_USB4_SHIFT  (24U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_USB4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_USB4_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP3_P1_MASK  (0x00E00000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP3_P1_SHIFT  (21U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP3_P1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP3_P1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP2_P1_MASK  (0x001C0000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP2_P1_SHIFT  (18U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP2_P1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP2_P1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP1_P1_MASK  (0x00038000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP1_P1_SHIFT  (15U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP1_P1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_VIP1_P1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS2_PRU0_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS2_PRU0_SHIFT  (12U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS2_PRU0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS2_PRU0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS1_PRU0_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS1_PRU0_SHIFT  (9U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS1_PRU0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_PRUSS1_PRU0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_BB2D_MASK   (0x000001C0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_BB2D_SHIFT  (6U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_BB2D_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_BB2D_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EVE4_TC0_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EVE4_TC0_SHIFT  (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EVE4_TC0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_MREQDOMAIN_EVE4_TC0_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP3_RESETVAL               (0x00000000U)

/* L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1 */

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_BB2D_SECDBG_EN_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_BB2D_SECDBG_EN_SHIFT  (31U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_BB2D_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_BB2D_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES2_SECDBG_EN_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES2_SECDBG_EN_SHIFT  (30U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES1_SECDBG_EN_MASK  (0x20000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES1_SECDBG_EN_SHIFT  (29U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_AES1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP3_SECDBG_EN_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP3_SECDBG_EN_SHIFT  (28U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP3_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP3_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP2_SECDBG_EN_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP2_SECDBG_EN_SHIFT  (27U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP1_SECDBG_EN_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP1_SECDBG_EN_SHIFT  (26U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_MCASP1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP2_SECDBG_EN_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP2_SECDBG_EN_SHIFT  (25U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP1_SECDBG_EN_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP1_SECDBG_EN_SHIFT  (24U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_VCP1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU2_SECDBG_EN_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU2_SECDBG_EN_SHIFT  (23U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU1_SECDBG_EN_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU1_SECDBG_EN_SHIFT  (22U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IPU1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS2_SECDBG_EN_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS2_SECDBG_EN_SHIFT  (21U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS1_SECDBG_EN_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS1_SECDBG_EN_SHIFT  (20U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_PCIESS1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE4_SECDBG_EN_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE4_SECDBG_EN_SHIFT  (19U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE4_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE4_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE3_SECDBG_EN_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE3_SECDBG_EN_SHIFT  (18U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE3_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE3_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE2_SECDBG_EN_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE2_SECDBG_EN_SHIFT  (17U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE1_SECDBG_EN_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE1_SECDBG_EN_SHIFT  (16U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EVE1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CT_TBR_SECDBG_EN_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CT_TBR_SECDBG_EN_SHIFT  (13U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CT_TBR_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CT_TBR_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DEBUGSS_SECDBG_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DEBUGSS_SECDBG_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DEBUGSS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DEBUGSS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EMIF_SECDBG_EN_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EMIF_SECDBG_EN_SHIFT  (11U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EMIF_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_EMIF_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_OCMC_ROM_SECDBG_EN_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_OCMC_ROM_SECDBG_EN_SHIFT  (10U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_OCMC_ROM_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_OCMC_ROM_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CRYPTO_SECDBG_EN_RESERVED_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CRYPTO_SECDBG_EN_RESERVED_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CRYPTO_SECDBG_EN_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_CRYPTO_SECDBG_EN_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SECDBG_EN_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SECDBG_EN_SHIFT  (8U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SL2_SECDBG_EN_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SL2_SECDBG_EN_SHIFT  (7U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SL2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_IVAHD_SL2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPU_SECDBG_EN_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPU_SECDBG_EN_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPU_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPU_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DSS_SECDBG_EN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DSS_SECDBG_EN_SHIFT  (4U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DSS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_DSS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_L3RAM1_SECDBG_EN_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_L3RAM1_SECDBG_EN_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_L3RAM1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_L3RAM1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPMC_SECDBG_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPMC_SECDBG_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPMC_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_GPMC_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_1_RESETVAL  (0x00000000U)

/* L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1 */

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_BB2D_SECLOCK_EN_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_BB2D_SECLOCK_EN_SHIFT  (31U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_BB2D_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_BB2D_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES2_SECLOCK_EN_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES2_SECLOCK_EN_SHIFT  (30U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES1_SECLOCK_EN_MASK  (0x20000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES1_SECLOCK_EN_SHIFT  (29U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_AES1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP3_SECLOCK_EN_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP3_SECLOCK_EN_SHIFT  (28U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP3_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP3_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP2_SECLOCK_EN_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP2_SECLOCK_EN_SHIFT  (27U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP1_SECLOCK_EN_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP1_SECLOCK_EN_SHIFT  (26U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_MCASP1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP2_SECLOCK_EN_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP2_SECLOCK_EN_SHIFT  (25U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP1_SECLOCK_EN_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP1_SECLOCK_EN_SHIFT  (24U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_VCP1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU2_SECLOCK_EN_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU2_SECLOCK_EN_SHIFT  (23U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU1_SECLOCK_EN_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU1_SECLOCK_EN_SHIFT  (22U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IPU1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS2_SECLOCK_EN_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS2_SECLOCK_EN_SHIFT  (21U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS1_SECLOCK_EN_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS1_SECLOCK_EN_SHIFT  (20U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_PCIESS1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE4_SECLOCK_EN_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE4_SECLOCK_EN_SHIFT  (19U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE4_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE4_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE3_SECLOCK_EN_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE3_SECLOCK_EN_SHIFT  (18U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE3_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE3_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE2_SECLOCK_EN_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE2_SECLOCK_EN_SHIFT  (17U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE1_SECLOCK_EN_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE1_SECLOCK_EN_SHIFT  (16U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EVE1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CT_TBR_SECLOCK_EN_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CT_TBR_SECLOCK_EN_SHIFT  (13U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CT_TBR_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CT_TBR_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DEBUGSS_SECLOCK_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DEBUGSS_SECLOCK_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DEBUGSS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DEBUGSS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EMIF_SECLOCK_EN_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EMIF_SECLOCK_EN_SHIFT  (11U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EMIF_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_EMIF_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_OCMC_ROM_SECLOCK_EN_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_OCMC_ROM_SECLOCK_EN_SHIFT  (10U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_OCMC_ROM_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_OCMC_ROM_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CRYPTO_SECLOCK_EN_RESERVED_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CRYPTO_SECLOCK_EN_RESERVED_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CRYPTO_SECLOCK_EN_RESERVED_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_CRYPTO_SECLOCK_EN_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SECLOCK_EN_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SECLOCK_EN_SHIFT  (8U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SL2_SECLOCK_EN_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SL2_SECLOCK_EN_SHIFT  (7U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SL2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_IVAHD_SL2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPU_SECLOCK_EN_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPU_SECLOCK_EN_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPU_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPU_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DSS_SECLOCK_EN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DSS_SECLOCK_EN_SHIFT  (4U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DSS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_DSS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_L3RAM1_SECLOCK_EN_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_L3RAM1_SECLOCK_EN_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_L3RAM1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_L3RAM1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPMC_SECLOCK_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPMC_SECLOCK_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPMC_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_GPMC_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_1_RESETVAL  (0xffffffffU)

/* L4_HW_FW_EXPORTED_VALUES_CONF */

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECDBG_EN_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECDBG_EN_SHIFT  (28U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECDBG_EN_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECDBG_EN_SHIFT  (27U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECDBG_EN_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECDBG_EN_SHIFT  (26U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECDBG_EN_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECDBG_EN_SHIFT  (25U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECDBG_EN_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECDBG_EN_SHIFT  (24U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECDBG_EN_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECDBG_EN_SHIFT  (23U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECDBG_EN_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECDBG_EN_SHIFT  (21U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECDBG_EN_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECDBG_EN_SHIFT  (20U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECDBG_EN_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECDBG_EN_SHIFT  (17U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECDBG_EN_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECDBG_EN_SHIFT  (16U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECLOCK_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECLOCK_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_SECURETARGETS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECLOCK_EN_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECLOCK_EN_SHIFT  (11U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER3_AP_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECLOCK_EN_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECLOCK_EN_SHIFT  (10U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_SECURETARGETS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECLOCK_EN_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECLOCK_EN_SHIFT  (9U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER2_AP_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECLOCK_EN_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECLOCK_EN_SHIFT  (8U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_SECURETARGETS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECLOCK_EN_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECLOCK_EN_SHIFT  (7U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4WAKEUP_AP_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECLOCK_EN_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECLOCK_EN_SHIFT  (5U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_SECURETARGETS_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECLOCK_EN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECLOCK_EN_SHIFT  (4U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4CONFIG_AP_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECLOCK_EN_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECLOCK_EN_SHIFT  (1U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_CRYPTO_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECLOCK_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECLOCK_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_L4PER1_AP_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L4_HW_FW_EXPORTED_VALUES_CONF_RESETVAL  (0x00001fb3U)

/* SEC_LOAD_FW_EXPORTED_VALUE */

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER3_LOAD_FW_EXPORTED_VALUE_REQN_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER3_LOAD_FW_EXPORTED_VALUE_REQN_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER3_LOAD_FW_EXPORTED_VALUE_REQN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER3_LOAD_FW_EXPORTED_VALUE_REQN_LOADED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER3_LOAD_FW_EXPORTED_VALUE_REQN_REQUESTED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER2_LOAD_FW_EXPORTED_VALUE_REQN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER2_LOAD_FW_EXPORTED_VALUE_REQN_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER2_LOAD_FW_EXPORTED_VALUE_REQN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER2_LOAD_FW_EXPORTED_VALUE_REQN_LOADED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER2_LOAD_FW_EXPORTED_VALUE_REQN_REQUESTED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER1_LOAD_FW_EXPORTED_VALUE_REQN_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER1_LOAD_FW_EXPORTED_VALUE_REQN_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER1_LOAD_FW_EXPORTED_VALUE_REQN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER1_LOAD_FW_EXPORTED_VALUE_REQN_LOADED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_PER1_LOAD_FW_EXPORTED_VALUE_REQN_REQUESTED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_CONFIG_LOAD_FW_EXPORTED_VALUE_REQN_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_CONFIG_LOAD_FW_EXPORTED_VALUE_REQN_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_CONFIG_LOAD_FW_EXPORTED_VALUE_REQN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_CONFIG_LOAD_FW_EXPORTED_VALUE_REQN_LOADED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_CONFIG_LOAD_FW_EXPORTED_VALUE_REQN_REQUESTED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_WAKEUP_LOAD_FW_EXPORTED_VALUE_REQN_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_WAKEUP_LOAD_FW_EXPORTED_VALUE_REQN_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_WAKEUP_LOAD_FW_EXPORTED_VALUE_REQN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_WAKEUP_LOAD_FW_EXPORTED_VALUE_REQN_LOADED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_L4_WAKEUP_LOAD_FW_EXPORTED_VALUE_REQN_REQUESTED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_LOAD_FW_EXPORTED_VALUE_RESETVAL    (0x00000000U)

/* DMM_MMU_FW */

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVA_SMSET_PROFILING_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVA_SMSET_PROFILING_SHIFT  (15U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVA_SMSET_PROFILING_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVA_SMSET_PROFILING_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PROFILING_OCP_WP_MASK   (0x00004000U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PROFILING_OCP_WP_SHIFT  (14U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PROFILING_OCP_WP_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PROFILING_OCP_WP_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PROFILING_OCP_WP_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC1_HW_INSTR_MASK   (0x00002000U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC1_HW_INSTR_SHIFT  (13U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC1_HW_INSTR_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC1_HW_INSTR_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_SATA_MASK               (0x00001000U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_SATA_SHIFT              (12U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_SATA_RESETVAL           (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_SATA_ALLOWED            (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_SATA_FORBIDDEN          (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_USB_MASK                (0x00000800U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_USB_SHIFT               (11U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_USB_RESETVAL            (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_USB_MAX                 (0x00000001U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_MMC_GPU_BB2D_GMAC_SW_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_MMC_GPU_BB2D_GMAC_SW_SHIFT  (10U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_MMC_GPU_BB2D_GMAC_SW_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_MMC_GPU_BB2D_GMAC_SW_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_MMC_GPU_BB2D_GMAC_SW_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_VIP_VPE_MASK            (0x00000200U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_VIP_VPE_SHIFT           (9U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_VIP_VPE_RESETVAL        (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_VIP_VPE_ALLOWED         (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_VIP_VPE_FORBIDDEN       (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSS_MLB_MMU_PCIESS_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSS_MLB_MMU_PCIESS_SHIFT  (8U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSS_MLB_MMU_PCIESS_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSS_MLB_MMU_PCIESS_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSS_MLB_MMU_PCIESS_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EDMA_TC0_TC1_MASK       (0x00000080U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EDMA_TC0_TC1_SHIFT      (7U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EDMA_TC0_TC1_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EDMA_TC0_TC1_ALLOWED    (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EDMA_TC0_TC1_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IPU1_IPU2_DMA_CRYPTO_DMA_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IPU1_IPU2_DMA_CRYPTO_DMA_SHIFT  (6U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IPU1_IPU2_DMA_CRYPTO_DMA_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IPU1_IPU2_DMA_CRYPTO_DMA_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IPU1_IPU2_DMA_CRYPTO_DMA_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PRUSS1_PRUSS2_MASK      (0x00000020U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PRUSS1_PRUSS2_SHIFT     (5U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PRUSS1_PRUSS2_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PRUSS1_PRUSS2_ALLOWED   (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PRUSS1_PRUSS2_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC0_SW_INSTR_MASK   (0x00000010U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC0_SW_INSTR_SHIFT  (4U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC0_SW_INSTR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC0_SW_INSTR_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_EVE_TC0_SW_INSTR_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVAHD_DSP2_MASK         (0x00000008U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVAHD_DSP2_SHIFT        (3U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVAHD_DSP2_RESETVAL     (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVAHD_DSP2_ALLOWED      (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_IVAHD_DSP2_FORBIDDEN    (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSP1_DSP2_EDMA_MASK     (0x00000004U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSP1_DSP2_EDMA_SHIFT    (2U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSP1_DSP2_EDMA_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSP1_DSP2_EDMA_ALLOWED  (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_DSP1_DSP2_EDMA_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_P1500_MASK              (0x00000002U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_P1500_SHIFT             (1U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_P1500_RESETVAL          (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_P1500_ALLOWED           (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_P1500_FORBIDDEN         (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PUBLIC_ARM_MASK         (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PUBLIC_ARM_SHIFT        (0U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PUBLIC_ARM_RESETVAL     (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PUBLIC_ARM_ALLOWED      (0x00000001U)
#define CSL_CONTROL_CORE_DMM_MMU_FW_DMM_PUBLIC_ARM_FORBIDDEN    (0x00000000U)

#define CSL_CONTROL_CORE_DMM_MMU_FW_RESETVAL                    (0x0000ffefU)

/* SECURE_EMIF_OBFUSC_KEY */

#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY_SECURE_EMIF_OBFUSC_KEY_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY_SECURE_EMIF_OBFUSC_KEY_SHIFT  (0U)
#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY_SECURE_EMIF_OBFUSC_KEY_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY_SECURE_EMIF_OBFUSC_KEY_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_SECURE_EMIF_OBFUSC_KEY_RESETVAL        (0x00000000U)

/* SEC_CTRL_RO */

#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECKEYACCENABLE_MASK       (0x00000008U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECKEYACCENABLE_SHIFT      (3U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECKEYACCENABLE_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECKEYACCENABLE_ALLOWED    (0x00000001U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECKEYACCENABLE_FORBIDDEN  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_EMIF_OBFUSC_EN_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_EMIF_OBFUSC_EN_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_EMIF_OBFUSC_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_EMIF_OBFUSC_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_SAR_MEMORY_RO_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_SAR_MEMORY_RO_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_SAR_MEMORY_RO_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_SAR_MEMORY_RO_EN_RO  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_CTRL_RO_SECURE_SAR_MEMORY_RO_EN_RW  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_CTRL_RO_RESETVAL                   (0x00000008U)

/* SSM_END_FAST_SECRAM */

#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM_END_FAST_SECRAM_MASK  (0x0000FC00U)
#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM_END_FAST_SECRAM_SHIFT  (10U)
#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM_END_FAST_SECRAM_RESETVAL  (0x0000003fU)
#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM_END_FAST_SECRAM_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_SSM_END_FAST_SECRAM_RESETVAL           (0x0000fc00U)

/* STATUS */

#define CSL_CONTROL_CORE_STATUS_HIGHLY_SECURE_MASK              (0x00000200U)
#define CSL_CONTROL_CORE_STATUS_HIGHLY_SECURE_SHIFT             (9U)
#define CSL_CONTROL_CORE_STATUS_HIGHLY_SECURE_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_STATUS_HIGHLY_SECURE_MAX               (0x00000001U)

#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_MASK                (0x000001C0U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_SHIFT               (6U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_RESETVAL            (0x00000000U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_B_2             (0x00000006U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_B_0             (0x00000004U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_E               (0x00000001U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_GP              (0x00000003U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_T               (0x00000000U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_B_3             (0x00000007U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_HS              (0x00000002U)
#define CSL_CONTROL_CORE_STATUS_DEVICE_TYPE_DEV_B_1             (0x00000005U)

#define CSL_CONTROL_CORE_STATUS_SYS_BOOT_RESERVED_MASK          (0x0000003FU)
#define CSL_CONTROL_CORE_STATUS_SYS_BOOT_RESERVED_SHIFT         (0U)
#define CSL_CONTROL_CORE_STATUS_SYS_BOOT_RESERVED_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_STATUS_SYS_BOOT_RESERVED_MAX           (0x0000003fU)

#define CSL_CONTROL_CORE_STATUS_RESETVAL                        (0x00000000U)

/* SEC_STATUS */

#define CSL_CONTROL_CORE_SEC_STATUS_VPE_RST_ACT_ST_MASK         (0x04000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_VPE_RST_ACT_ST_SHIFT        (26U)
#define CSL_CONTROL_CORE_SEC_STATUS_VPE_RST_ACT_ST_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_VPE_RST_ACT_ST_VPERESET     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_VPE_RST_ACT_ST_NO_VPERESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_IPU2_RST_ACT_ST_MASK        (0x01000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU2_RST_ACT_ST_SHIFT       (24U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU2_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU2_RST_ACT_ST_CAMRESET    (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU2_RST_ACT_ST_NO_CAMRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_IPU1_RST_ACT_ST_MASK        (0x00800000U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU1_RST_ACT_ST_SHIFT       (23U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU1_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU1_RST_ACT_ST_IPU1RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_IPU1_RST_ACT_ST_NO_IPU1RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_EVE4_RST_ACT_ST_MASK        (0x00400000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE4_RST_ACT_ST_SHIFT       (22U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE4_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE4_RST_ACT_ST_EVE4RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE4_RST_ACT_ST_NO_EVE4RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_EVE3_RST_ACT_ST_MASK        (0x00200000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE3_RST_ACT_ST_SHIFT       (21U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE3_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE3_RST_ACT_ST_EVE3RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE3_RST_ACT_ST_NO_EVE3RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_EVE2_RST_ACT_ST_MASK        (0x00100000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE2_RST_ACT_ST_SHIFT       (20U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE2_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE2_RST_ACT_ST_EVE2RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE2_RST_ACT_ST_NO_EVE2RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_EVE1_RST_ACT_ST_MASK        (0x00080000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE1_RST_ACT_ST_SHIFT       (19U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE1_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE1_RST_ACT_ST_EVE1RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_EVE1_RST_ACT_ST_NO_EVE1RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_DSP2_RST_ACT_ST_MASK        (0x00040000U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP2_RST_ACT_ST_SHIFT       (18U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP2_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP2_RST_ACT_ST_DSP2RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP2_RST_ACT_ST_NO_DSP2RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_GPU_RST_ACT_ST_MASK         (0x00020000U)
#define CSL_CONTROL_CORE_SEC_STATUS_GPU_RST_ACT_ST_SHIFT        (17U)
#define CSL_CONTROL_CORE_SEC_STATUS_GPU_RST_ACT_ST_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_GPU_RST_ACT_ST_GFXRESET     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_GPU_RST_ACT_ST_NO_GFXRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_CPFROM_RST_ACT_ST_MASK      (0x00008000U)
#define CSL_CONTROL_CORE_SEC_STATUS_CPFROM_RST_ACT_ST_SHIFT     (15U)
#define CSL_CONTROL_CORE_SEC_STATUS_CPFROM_RST_ACT_ST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_CPFROM_RST_ACT_ST_CPFROMRESET  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_CPFROM_RST_ACT_ST_NO_CPFROMRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_EMU_RST_ACT_ST_MASK         (0x00004000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EMU_RST_ACT_ST_SHIFT        (14U)
#define CSL_CONTROL_CORE_SEC_STATUS_EMU_RST_ACT_ST_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_EMU_RST_ACT_ST_EMURESET     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_EMU_RST_ACT_ST_NO_EMURESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_L4PER_RST_ACT_ST_MASK       (0x00002000U)
#define CSL_CONTROL_CORE_SEC_STATUS_L4PER_RST_ACT_ST_SHIFT      (13U)
#define CSL_CONTROL_CORE_SEC_STATUS_L4PER_RST_ACT_ST_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_L4PER_RST_ACT_ST_L4PERRESET  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_L4PER_RST_ACT_ST_NO_L4PERRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_L3INIT_RST_ACT_ST_MASK      (0x00001000U)
#define CSL_CONTROL_CORE_SEC_STATUS_L3INIT_RST_ACT_ST_SHIFT     (12U)
#define CSL_CONTROL_CORE_SEC_STATUS_L3INIT_RST_ACT_ST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_L3INIT_RST_ACT_ST_L3INITRESET  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_L3INIT_RST_ACT_ST_NO_L3INITRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_CORE_RST_ACT_ST_MASK        (0x00000800U)
#define CSL_CONTROL_CORE_SEC_STATUS_CORE_RST_ACT_ST_SHIFT       (11U)
#define CSL_CONTROL_CORE_SEC_STATUS_CORE_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_CORE_RST_ACT_ST_CORERESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_CORE_RST_ACT_ST_NO_CORERESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_IVAHD_RST_ACT_ST_MASK       (0x00000200U)
#define CSL_CONTROL_CORE_SEC_STATUS_IVAHD_RST_ACT_ST_SHIFT      (9U)
#define CSL_CONTROL_CORE_SEC_STATUS_IVAHD_RST_ACT_ST_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_IVAHD_RST_ACT_ST_IVAHDRESET  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_IVAHD_RST_ACT_ST_NO_IVAHDRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_SEC_STATUS_ISS_RESERVED_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_STATUS_ISS_RESERVED_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_STATUS_ISS_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_STATUS_ISS_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_STATUS_DSS_RST_ACT_ST_MASK         (0x00000080U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSS_RST_ACT_ST_SHIFT        (7U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSS_RST_ACT_ST_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSS_RST_ACT_ST_DSSRESET     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSS_RST_ACT_ST_NO_DSSRESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_DSP1_RST_ACT_ST_MASK        (0x00000040U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP1_RST_ACT_ST_SHIFT       (6U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP1_RST_ACT_ST_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP1_RST_ACT_ST_DSP1RESET   (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_DSP1_RST_ACT_ST_NO_DSP1RESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MPU_RST_ACT_ST_MASK         (0x00000020U)
#define CSL_CONTROL_CORE_SEC_STATUS_MPU_RST_ACT_ST_SHIFT        (5U)
#define CSL_CONTROL_CORE_SEC_STATUS_MPU_RST_ACT_ST_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MPU_RST_ACT_ST_MPURESET     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MPU_RST_ACT_ST_NO_MPURESET  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_DEVICE_OFF_WKUP_RESERVED_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_STATUS_DEVICE_OFF_WKUP_RESERVED_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_STATUS_DEVICE_OFF_WKUP_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_DEVICE_OFF_WKUP_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_STATUS_SEC_VIOL_RST_ACT_ST_MASK    (0x00000008U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_VIOL_RST_ACT_ST_SHIFT   (3U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_VIOL_RST_ACT_ST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_VIOL_RST_ACT_ST_VIOLATION  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_VIOL_RST_ACT_ST_NO_VIOLATION  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_SEC_WD_RST_ACT_ST_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_WD_RST_ACT_ST_SHIFT     (2U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_WD_RST_ACT_ST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_WD_RST_ACT_ST_PREV_RST_WAS_SWD  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_SEC_WD_RST_ACT_ST_PREV_RST_WAS_NOT_SWD  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_GLBL_WARM_RST_ACT_ST_MASK   (0x00000002U)
#define CSL_CONTROL_CORE_SEC_STATUS_GLBL_WARM_RST_ACT_ST_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_STATUS_GLBL_WARM_RST_ACT_ST_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_GLBL_WARM_RST_ACT_ST_PREV_RST_WAS_SW  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_GLBL_WARM_RST_ACT_ST_PREV_RST_WAS_NOT_SW  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_POWERON_RST_ACT_ST_MASK     (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_POWERON_RST_ACT_ST_SHIFT    (0U)
#define CSL_CONTROL_CORE_SEC_STATUS_POWERON_RST_ACT_ST_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_POWERON_RST_ACT_ST_PREV_RST_WAS_PWR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_POWERON_RST_ACT_ST_PREV_RST_WAS_NOT_PWR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_RESETVAL                    (0x00000001U)

/* SEC_MEM_STATUS */

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_NOT_ACCESSIBLE_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_NOT_ACCESSIBLE_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_NOT_ACCESSIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_NOT_ACCESSIBLE_NO_ACCESS  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_NOT_ACCESSIBLE_ACCESS  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_NOT_ACCESSIBLE_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_NOT_ACCESSIBLE_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_NOT_ACCESSIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_NOT_ACCESSIBLE_NO_ACCESS  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_NOT_ACCESSIBLE_ACCESS  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_NOT_ACCESSIBLE_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_NOT_ACCESSIBLE_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_NOT_ACCESSIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_NOT_ACCESSIBLE_NO_ACCESS  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_NOT_ACCESSIBLE_ACCESS  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_NOT_ACCESSIBLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_NOT_ACCESSIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_NOT_ACCESSIBLE_NO_ACCESS  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_NOT_ACCESSIBLE_ACCESS  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_NOT_ACCESSIBLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_NOT_ACCESSIBLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_NOT_ACCESSIBLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_NOT_ACCESSIBLE_NO_ACCESS  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_NOT_ACCESSIBLE_ACCESS  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_DESTROYED_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_DESTROYED_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_DESTROYED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_DESTROYED_DESTROYED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM3_DESTROYED_SAFE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_DESTROYED_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_DESTROYED_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_DESTROYED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_DESTROYED_DESTROYED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM2_DESTROYED_SAFE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_DESTROYED_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_DESTROYED_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_DESTROYED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_DESTROYED_DESTROYED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_L3SECRAM1_DESTROYED_SAFE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_DESTROYED_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_DESTROYED_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_DESTROYED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_DESTROYED_DESTROYED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_FASTSECRAMBANK_DESTROYED_SAFE  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_DESTROYED_MASK   (0x00000002U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_DESTROYED_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_DESTROYED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_DESTROYED_DESTROYED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MPU_L2_DESTROYED_SAFE   (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_RESETVAL                (0x00000000U)

/* SEC_STATUS_MASK_DISABLE */

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GPU_RST_ACT_ST_MASK_DISABLE_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GPU_RST_ACT_ST_MASK_DISABLE_SHIFT  (25U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GPU_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GPU_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GPU_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_VPE_RST_ACT_ST_MASK_DISABLE_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_VPE_RST_ACT_ST_MASK_DISABLE_SHIFT  (24U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_VPE_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_VPE_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_VPE_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SDRAM_RST_ACT_ST_MASK_DISABLE_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SDRAM_RST_ACT_ST_MASK_DISABLE_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SDRAM_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SDRAM_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SDRAM_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU2_RST_ACT_ST_MASK_DISABLE_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU2_RST_ACT_ST_MASK_DISABLE_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU2_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU2_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU2_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU1_RST_ACT_ST_MASK_DISABLE_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU1_RST_ACT_ST_MASK_DISABLE_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU1_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU1_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IPU1_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE4_RST_ACT_ST_MASK_DISABLE_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE4_RST_ACT_ST_MASK_DISABLE_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE4_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE4_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE4_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE3_RST_ACT_ST_MASK_DISABLE_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE3_RST_ACT_ST_MASK_DISABLE_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE3_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE3_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE3_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE2_RST_ACT_ST_MASK_DISABLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE2_RST_ACT_ST_MASK_DISABLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE2_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE2_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE2_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE1_RST_ACT_ST_MASK_DISABLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE1_RST_ACT_ST_MASK_DISABLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE1_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE1_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EVE1_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP2_RST_ACT_ST_MASK_DISABLE_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP2_RST_ACT_ST_MASK_DISABLE_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP2_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP2_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP2_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CPFROM_RST_ACT_ST_MASK_DISABLE_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CPFROM_RST_ACT_ST_MASK_DISABLE_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CPFROM_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CPFROM_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CPFROM_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EMU_RST_ACT_ST_MASK_DISABLE_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EMU_RST_ACT_ST_MASK_DISABLE_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EMU_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EMU_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_EMU_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L4PER_RST_ACT_ST_MASK_DISABLE_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L4PER_RST_ACT_ST_MASK_DISABLE_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L4PER_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L4PER_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L4PER_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L3INIT_RST_ACT_ST_MASK_DISABLE_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L3INIT_RST_ACT_ST_MASK_DISABLE_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L3INIT_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L3INIT_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_L3INIT_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CORE_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CORE_RST_ACT_ST_MASK_DISABLE_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CORE_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CORE_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_CORE_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IVAHD_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IVAHD_RST_ACT_ST_MASK_DISABLE_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IVAHD_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IVAHD_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_IVAHD_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_STATUS_MASK_DISABLE_ISS_RESERVED_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_STATUS_MASK_DISABLE_ISS_RESERVED_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_STATUS_MASK_DISABLE_ISS_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_STATUS_MASK_DISABLE_ISS_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSS_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSS_RST_ACT_ST_MASK_DISABLE_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSS_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSS_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSS_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP1_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP1_RST_ACT_ST_MASK_DISABLE_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP1_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP1_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DSP1_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_MPU_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_MPU_RST_ACT_ST_MASK_DISABLE_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_MPU_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_MPU_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_MPU_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DEVICE_OFF_WKUP_MASK_DISABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DEVICE_OFF_WKUP_MASK_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DEVICE_OFF_WKUP_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DEVICE_OFF_WKUP_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_DEVICE_OFF_WKUP_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_VIOL_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_VIOL_RST_ACT_ST_MASK_DISABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_VIOL_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_VIOL_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_VIOL_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_WD_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_WD_RST_ACT_ST_MASK_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_WD_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_WD_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_SEC_WD_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GLBL_WARM_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GLBL_WARM_RST_ACT_ST_MASK_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GLBL_WARM_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GLBL_WARM_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_GLBL_WARM_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_POWERON_RST_ACT_ST_MASK_DISABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_POWERON_RST_ACT_ST_MASK_DISABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_POWERON_RST_ACT_ST_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_POWERON_RST_ACT_ST_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_POWERON_RST_ACT_ST_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_STATUS_MASK_DISABLE_RESETVAL       (0x00000000U)

/* SEC_MEM_STATUS_MASK_DISABLE */

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_NOT_ACCESSIBLE_MASK_DISABLE_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_NOT_ACCESSIBLE_MASK_DISABLE_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_NOT_ACCESSIBLE_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_NOT_ACCESSIBLE_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_NOT_ACCESSIBLE_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_NOT_ACCESSIBLE_MASK_DISABLE_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_NOT_ACCESSIBLE_MASK_DISABLE_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_NOT_ACCESSIBLE_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_NOT_ACCESSIBLE_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_NOT_ACCESSIBLE_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_NOT_ACCESSIBLE_MASK_DISABLE_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_NOT_ACCESSIBLE_MASK_DISABLE_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_NOT_ACCESSIBLE_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_NOT_ACCESSIBLE_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_NOT_ACCESSIBLE_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK_DISABLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK_DISABLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_NOT_ACCESSIBLE_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_NOT_ACCESSIBLE_MASK_DISABLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_NOT_ACCESSIBLE_MASK_DISABLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_NOT_ACCESSIBLE_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_NOT_ACCESSIBLE_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_NOT_ACCESSIBLE_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_DESTROYED_MASK_DISABLE_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_DESTROYED_MASK_DISABLE_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_DESTROYED_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_DESTROYED_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM3_DESTROYED_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_DESTROYED_MASK_DISABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_DESTROYED_MASK_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_DESTROYED_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_DESTROYED_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM2_DESTROYED_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_DESTROYED_MASK_DISABLE_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_DESTROYED_MASK_DISABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_DESTROYED_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_DESTROYED_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_L3SECRAM1_DESTROYED_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_DESTROYED_MASK_DISABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_DESTROYED_MASK_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_DESTROYED_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_DESTROYED_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_FASTSECRAMBANK_DESTROYED_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_DESTROYED_MASK_DISABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_DESTROYED_MASK_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_DESTROYED_MASK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_DESTROYED_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_MPU_L2_DESTROYED_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_MEM_STATUS_MASK_DISABLE_RESETVAL   (0x00000000U)

/* SEC_ERR_STATUS_FUNC_1 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE4_FW_ERROR_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE4_FW_ERROR_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE4_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE4_FW_ERROR_EVE4_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE4_FW_ERROR_NO_EVE4_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE3_FW_ERROR_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE3_FW_ERROR_SHIFT  (30U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE3_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE3_FW_ERROR_EVE3_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE3_FW_ERROR_NO_EVE3_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE2_FW_ERROR_MASK  (0x20000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE2_FW_ERROR_SHIFT  (29U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE2_FW_ERROR_EVE2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE2_FW_ERROR_NO_EVE2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE1_FW_ERROR_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE1_FW_ERROR_SHIFT  (28U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE1_FW_ERROR_EVE1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EVE1_FW_ERROR_NO_EVE1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_OCMC_ROM_FW_ERROR_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_OCMC_ROM_FW_ERROR_SHIFT  (27U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_OCMC_ROM_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_OCMC_ROM_FW_ERROR_OCMC_ROM_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_OCMC_ROM_FW_ERROR_NO_OCMC_ROM_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_CT_TRACE_BUFFER_ROUTER_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_NO_CT_TRACE_BUFFER_ROUTER_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_BB2D_FW_ERROR_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_BB2D_FW_ERROR_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_BB2D_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_BB2D_FW_ERROR_BB2D_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_BB2D_FW_ERROR_NO_BB2D_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_WAKEUP_FW_ERROR_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_WAKEUP_FW_ERROR_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_WAKEUP_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_WAKEUP_FW_ERROR_L4WKUP_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_WAKEUP_FW_ERROR_NO_L4WKUP_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DEBUGSS_FW_ERROR_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DEBUGSS_FW_ERROR_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DEBUGSS_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DEBUGSS_FW_ERROR_DEBUGSS_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DEBUGSS_FW_ERROR_NO_DEBUGSS_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_CONFIG_FW_ERROR_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_CONFIG_FW_ERROR_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_CONFIG_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_CONFIG_FW_ERROR_L4CONFIG_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_CONFIG_FW_ERROR_NO_L4CONFIG_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_PERIPH1_FW_ERROR_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_PERIPH1_FW_ERROR_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_PERIPH1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_PERIPH1_FW_ERROR_L4PERIPH1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L4_PERIPH1_FW_ERROR_NO_L4PERIPH1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DSS_FW_ERROR_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DSS_FW_ERROR_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DSS_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DSS_FW_ERROR_DSS_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DSS_FW_ERROR_NO_DSS_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPU_FW_ERROR_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPU_FW_ERROR_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPU_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPU_FW_ERROR_GPU_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPU_FW_ERROR_NO_GPU_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SECMOD_FW_ERROR_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SECMOD_FW_ERROR_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SECMOD_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SECMOD_FW_ERROR_SECMOD_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SECMOD_FW_ERROR_NO_SECMOD_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DISPDMA_ACC_ERROR_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DISPDMA_ACC_ERROR_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DISPDMA_ACC_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DISPDMA_ACC_ERROR_DISPDMA_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_DISPDMA_ACC_ERROR_NO_DISPDMA_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SYSTEMDMA_ACC_ERROR_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SYSTEMDMA_ACC_ERROR_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SYSTEMDMA_ACC_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SYSTEMDMA_ACC_ERROR_SYSTEMDMA_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_SYSTEMDMA_ACC_ERROR_NO_SYSTEMDMA_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_DMA_FW_ERROR_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_DMA_FW_ERROR_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_DMA_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_DMA_FW_ERROR_CRYPTODMA_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_DMA_FW_ERROR_NO_CRYPTODMA_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_SL2_FW_ERROR_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_SL2_FW_ERROR_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_SL2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_SL2_FW_ERROR_IVAHD_SL2_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_SL2_FW_ERROR_NO_IVAHD_SL2_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IPU1_FW_ERROR_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IPU1_FW_ERROR_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IPU1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IPU1_FW_ERROR_IPU1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IPU1_FW_ERROR_NO_IPU1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_FW_ERROR_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_FW_ERROR_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_FW_ERROR_IVAHD_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_IVAHD_FW_ERROR_NO_IVAHD_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EMIF_FW_ERROR_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EMIF_FW_ERROR_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EMIF_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EMIF_FW_ERROR_EMIF_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_EMIF_FW_ERROR_NO_EMIF_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPMC_FW_ERROR_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPMC_FW_ERROR_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPMC_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPMC_FW_ERROR_GPMC_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_GPMC_FW_ERROR_NO_GPMC_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L3RAM1_FW_ERROR_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L3RAM1_FW_ERROR_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L3RAM1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L3RAM1_FW_ERROR_L3RAM1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_L3RAM1_FW_ERROR_NO_L3RAM1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_FW_ERROR_RESERVED_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_FW_ERROR_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_FW_ERROR_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_CRYPTO_FW_ERROR_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_1_RESETVAL         (0x00000000U)

/* SEC_ERR_STATUS_FUNC_MASK_DISABLE_1 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE4_FW_ERROR_MASK_DISABLE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE4_FW_ERROR_MASK_DISABLE_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE4_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE4_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE4_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE3_FW_ERROR_MASK_DISABLE_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE3_FW_ERROR_MASK_DISABLE_SHIFT  (30U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE3_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE3_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE3_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE2_FW_ERROR_MASK_DISABLE_MASK  (0x20000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE2_FW_ERROR_MASK_DISABLE_SHIFT  (29U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE1_FW_ERROR_MASK_DISABLE_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE1_FW_ERROR_MASK_DISABLE_SHIFT  (28U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EVE1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_OCMC_ROM_FW_ERROR_MASK_DISABLE_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_OCMC_ROM_FW_ERROR_MASK_DISABLE_SHIFT  (27U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_OCMC_ROM_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_OCMC_ROM_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_OCMC_ROM_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK_DISABLE_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK_DISABLE_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CT_TRACE_BUFFER_ROUTER_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_BB2D_FW_ERROR_MASK_DISABLE_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_BB2D_FW_ERROR_MASK_DISABLE_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_BB2D_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_BB2D_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_BB2D_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_WAKEUP_FW_ERROR_MASK_DISABLE_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_WAKEUP_FW_ERROR_MASK_DISABLE_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_WAKEUP_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_WAKEUP_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_WAKEUP_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DEBUGSS_FW_ERROR_MASK_DISABLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DEBUGSS_FW_ERROR_MASK_DISABLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DEBUGSS_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DEBUGSS_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DEBUGSS_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_CONFIG_FW_ERROR_MASK_DISABLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_CONFIG_FW_ERROR_MASK_DISABLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_CONFIG_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_CONFIG_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_CONFIG_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_PERIPH1_FW_ERROR_MASK_DISABLE_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_PERIPH1_FW_ERROR_MASK_DISABLE_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_PERIPH1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_PERIPH1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L4_PERIPH1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DSS_FW_ERROR_MASK_DISABLE_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DSS_FW_ERROR_MASK_DISABLE_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DSS_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DSS_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DSS_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPU_FW_ERROR_MASK_DISABLE_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPU_FW_ERROR_MASK_DISABLE_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPU_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPU_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPU_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SECMOD_FW_ERROR_MASK_DISABLE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SECMOD_FW_ERROR_MASK_DISABLE_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SECMOD_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SECMOD_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SECMOD_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DISPDMA_ACC_ERROR_MASK_DISABLE_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DISPDMA_ACC_ERROR_MASK_DISABLE_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DISPDMA_ACC_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DISPDMA_ACC_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_DISPDMA_ACC_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SYSTEMDMA_ACC_ERROR_MASK_DISABLE_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SYSTEMDMA_ACC_ERROR_MASK_DISABLE_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SYSTEMDMA_ACC_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SYSTEMDMA_ACC_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_SYSTEMDMA_ACC_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_DMA_FW_ERROR_MASK_DISABLE_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_DMA_FW_ERROR_MASK_DISABLE_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_DMA_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_DMA_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_DMA_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_SL2_FW_ERROR_MASK_DISABLE_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_SL2_FW_ERROR_MASK_DISABLE_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_SL2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_SL2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_SL2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IPU1_FW_ERROR_MASK_DISABLE_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IPU1_FW_ERROR_MASK_DISABLE_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IPU1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IPU1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IPU1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_FW_ERROR_MASK_DISABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_FW_ERROR_MASK_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_IVAHD_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EMIF_FW_ERROR_MASK_DISABLE_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EMIF_FW_ERROR_MASK_DISABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EMIF_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EMIF_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_EMIF_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPMC_FW_ERROR_MASK_DISABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPMC_FW_ERROR_MASK_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPMC_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPMC_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_GPMC_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L3RAM1_FW_ERROR_MASK_DISABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L3RAM1_FW_ERROR_MASK_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L3RAM1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L3RAM1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_L3RAM1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_FW_ERROR_MASK_DISABLE_RESERVED_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_FW_ERROR_MASK_DISABLE_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_FW_ERROR_MASK_DISABLE_RESERVED_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_CRYPTO_FW_ERROR_MASK_DISABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_1_RESETVAL  (0xffffffffU)

/* SEC_ERR_STATUS_DEBUG_1 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE4_DBGFW_ERROR_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE4_DBGFW_ERROR_SHIFT  (31U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE4_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE4_DBGFW_ERROR_EVE4_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE4_DBGFW_ERROR_NO_EVE4_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE3_DBGFW_ERROR_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE3_DBGFW_ERROR_SHIFT  (30U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE3_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE3_DBGFW_ERROR_EVE3_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE3_DBGFW_ERROR_NO_EVE3_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE2_DBGFW_ERROR_MASK  (0x20000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE2_DBGFW_ERROR_SHIFT  (29U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE2_DBGFW_ERROR_EVE2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE2_DBGFW_ERROR_NO_EVE2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE1_DBGFW_ERROR_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE1_DBGFW_ERROR_SHIFT  (28U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE1_DBGFW_ERROR_EVE1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EVE1_DBGFW_ERROR_NO_EVE1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_OCMC_ROM_DBGFW_ERROR_MASK  (0x08000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_OCMC_ROM_DBGFW_ERROR_SHIFT  (27U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_OCMC_ROM_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_OCMC_ROM_DBGFW_ERROR_OCMC_ROM_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_OCMC_ROM_DBGFW_ERROR_NO_OCMC_ROM_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CT_TRACE_BUFFER_ROUTER_DBGFW_ERROR_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CT_TRACE_BUFFER_ROUTER_DBGFW_ERROR_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CT_TRACE_BUFFER_ROUTER_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CT_TRACE_BUFFER_ROUTER_DBGFW_ERROR_CT_TRACE_BUFFER_ROUTER_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CT_TRACE_BUFFER_ROUTER_DBGFW_ERROR_NO_CT_TRACE_BUFFER_ROUTER_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_BB2D_DBGFW_ERROR_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_BB2D_DBGFW_ERROR_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_BB2D_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_BB2D_DBGFW_ERROR_BB2D_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_BB2D_DBGFW_ERROR_NO_BB2D_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_WAKEUP_DBGFW_ERROR_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_WAKEUP_DBGFW_ERROR_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_WAKEUP_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_WAKEUP_DBGFW_ERROR_L4WKUP_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_WAKEUP_DBGFW_ERROR_NO_L4WKUP_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DEBUGSS_DBGFW_ERROR_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DEBUGSS_DBGFW_ERROR_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DEBUGSS_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DEBUGSS_DBGFW_ERROR_DEBUGSS_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DEBUGSS_DBGFW_ERROR_NO_DEBUGSS_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_CONFIG_DBGFW_ERROR_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_CONFIG_DBGFW_ERROR_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_CONFIG_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_CONFIG_DBGFW_ERROR_L4CONFIG_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_CONFIG_DBGFW_ERROR_NO_L4CONFIG_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_PERIPH1_DBGFW_ERROR_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_PERIPH1_DBGFW_ERROR_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_PERIPH1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_PERIPH1_DBGFW_ERROR_L4PERIPH1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L4_PERIPH1_DBGFW_ERROR_NO_L4PERIPH1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DSS_DBGFW_ERROR_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DSS_DBGFW_ERROR_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DSS_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DSS_DBGFW_ERROR_DSS_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_DSS_DBGFW_ERROR_NO_DSS_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPU_DBGFW_ERROR_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPU_DBGFW_ERROR_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPU_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPU_DBGFW_ERROR_GPU_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPU_DBGFW_ERROR_NO_GPU_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_SL2_DBGFW_ERROR_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_SL2_DBGFW_ERROR_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_SL2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_SL2_DBGFW_ERROR_IVAHD_SL2_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_SL2_DBGFW_ERROR_NO_IVAHD_SL2_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IPU1_DBGFW_ERROR_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IPU1_DBGFW_ERROR_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IPU1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IPU1_DBGFW_ERROR_IPU1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IPU1_DBGFW_ERROR_NO_IPU1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_DBGFW_ERROR_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_DBGFW_ERROR_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_DBGFW_ERROR_IVAHD_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_IVAHD_DBGFW_ERROR_NO_IVAHD_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EMIF_DBGFW_ERROR_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EMIF_DBGFW_ERROR_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EMIF_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EMIF_DBGFW_ERROR_EMIF_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_EMIF_DBGFW_ERROR_NO_EMIF_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPMC_DBGFW_ERROR_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPMC_DBGFW_ERROR_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPMC_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPMC_DBGFW_ERROR_GPMC_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_GPMC_DBGFW_ERROR_NO_GPMC_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L3RAM1_DBGFW_ERROR_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L3RAM1_DBGFW_ERROR_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L3RAM1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L3RAM1_DBGFW_ERROR_L3RAM1_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_L3RAM1_DBGFW_ERROR_NO_L3RAM1_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CRYPTO_DBGFW_ERROR_RESERVED_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CRYPTO_DBGFW_ERROR_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CRYPTO_DBGFW_ERROR_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_CRYPTO_DBGFW_ERROR_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_1_RESETVAL        (0x00000000U)

/* HDCP_SEED0 */

#define CSL_CONTROL_CORE_HDCP_SEED0_HDCP_SEED0_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_HDCP_SEED0_HDCP_SEED0_SHIFT            (0U)
#define CSL_CONTROL_CORE_HDCP_SEED0_HDCP_SEED0_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_HDCP_SEED0_HDCP_SEED0_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_HDCP_SEED0_RESETVAL                    (0x00000000U)

/* HDCP_SEED1 */

#define CSL_CONTROL_CORE_HDCP_SEED1_HDCP_SEED1_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_HDCP_SEED1_HDCP_SEED1_SHIFT            (0U)
#define CSL_CONTROL_CORE_HDCP_SEED1_HDCP_SEED1_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_HDCP_SEED1_HDCP_SEED1_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_HDCP_SEED1_RESETVAL                    (0x00000000U)

/* MPU_FORCEWRNP */

#define CSL_CONTROL_CORE_MPU_FORCEWRNP_MPU_FORCEWRNP_MASK       (0x00000001U)
#define CSL_CONTROL_CORE_MPU_FORCEWRNP_MPU_FORCEWRNP_SHIFT      (0U)
#define CSL_CONTROL_CORE_MPU_FORCEWRNP_MPU_FORCEWRNP_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_MPU_FORCEWRNP_MPU_FORCEWRNP_ENABLE     (0x00000001U)
#define CSL_CONTROL_CORE_MPU_FORCEWRNP_MPU_FORCEWRNP_DISABLE    (0x00000000U)

#define CSL_CONTROL_CORE_MPU_FORCEWRNP_RESETVAL                 (0x00000000U)

/* KEK_SW_0 */

#define CSL_CONTROL_CORE_KEK_SW_0_STD_FUSE_KEK_SW_0_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_0_STD_FUSE_KEK_SW_0_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_0_STD_FUSE_KEK_SW_0_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_0_STD_FUSE_KEK_SW_0_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_0_RESETVAL                      (0x00000000U)

/* KEK_SW_1 */

#define CSL_CONTROL_CORE_KEK_SW_1_STD_FUSE_KEK_SW_1_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_1_STD_FUSE_KEK_SW_1_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_1_STD_FUSE_KEK_SW_1_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_1_STD_FUSE_KEK_SW_1_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_1_RESETVAL                      (0x00000000U)

/* KEK_SW_2 */

#define CSL_CONTROL_CORE_KEK_SW_2_STD_FUSE_KEK_SW_2_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_2_STD_FUSE_KEK_SW_2_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_2_STD_FUSE_KEK_SW_2_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_2_STD_FUSE_KEK_SW_2_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_2_RESETVAL                      (0x00000000U)

/* KEK_SW_3 */

#define CSL_CONTROL_CORE_KEK_SW_3_STD_FUSE_KEK_SW_3_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_3_STD_FUSE_KEK_SW_3_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_3_STD_FUSE_KEK_SW_3_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_3_STD_FUSE_KEK_SW_3_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_3_RESETVAL                      (0x00000000U)

/* KEK_SW_4 */

#define CSL_CONTROL_CORE_KEK_SW_4_STD_FUSE_KEK_SW_4_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_4_STD_FUSE_KEK_SW_4_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_4_STD_FUSE_KEK_SW_4_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_4_STD_FUSE_KEK_SW_4_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_4_RESETVAL                      (0x00000000U)

/* KEK_SW_5 */

#define CSL_CONTROL_CORE_KEK_SW_5_STD_FUSE_KEK_SW_5_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_5_STD_FUSE_KEK_SW_5_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_5_STD_FUSE_KEK_SW_5_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_5_STD_FUSE_KEK_SW_5_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_5_RESETVAL                      (0x00000000U)

/* KEK_SW_6 */

#define CSL_CONTROL_CORE_KEK_SW_6_STD_FUSE_KEK_SW_6_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_6_STD_FUSE_KEK_SW_6_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_6_STD_FUSE_KEK_SW_6_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_6_STD_FUSE_KEK_SW_6_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_6_RESETVAL                      (0x00000000U)

/* KEK_SW_7 */

#define CSL_CONTROL_CORE_KEK_SW_7_STD_FUSE_KEK_SW_7_MASK        (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_KEK_SW_7_STD_FUSE_KEK_SW_7_SHIFT       (0U)
#define CSL_CONTROL_CORE_KEK_SW_7_STD_FUSE_KEK_SW_7_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_KEK_SW_7_STD_FUSE_KEK_SW_7_MAX         (0xffffffffU)

#define CSL_CONTROL_CORE_KEK_SW_7_RESETVAL                      (0x00000000U)

/* CEK_0 */

#define CSL_CONTROL_CORE_CEK_0_CUST_FUSE_CEK_0_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK_0_CUST_FUSE_CEK_0_SHIFT            (0U)
#define CSL_CONTROL_CORE_CEK_0_CUST_FUSE_CEK_0_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CEK_0_CUST_FUSE_CEK_0_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CEK_0_RESETVAL                         (0x00000000U)

/* CEK_1 */

#define CSL_CONTROL_CORE_CEK_1_CUST_FUSE_CEK_1_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK_1_CUST_FUSE_CEK_1_SHIFT            (0U)
#define CSL_CONTROL_CORE_CEK_1_CUST_FUSE_CEK_1_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CEK_1_CUST_FUSE_CEK_1_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CEK_1_RESETVAL                         (0x00000000U)

/* CEK_2 */

#define CSL_CONTROL_CORE_CEK_2_CUST_FUSE_CEK_2_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK_2_CUST_FUSE_CEK_2_SHIFT            (0U)
#define CSL_CONTROL_CORE_CEK_2_CUST_FUSE_CEK_2_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CEK_2_CUST_FUSE_CEK_2_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CEK_2_RESETVAL                         (0x00000000U)

/* CEK_3 */

#define CSL_CONTROL_CORE_CEK_3_CUST_FUSE_CEK_3_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK_3_CUST_FUSE_CEK_3_SHIFT            (0U)
#define CSL_CONTROL_CORE_CEK_3_CUST_FUSE_CEK_3_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CEK_3_CUST_FUSE_CEK_3_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CEK_3_RESETVAL                         (0x00000000U)

/* MSV */

#define CSL_CONTROL_CORE_MSV_CUST_FUSE_MSV_MASK                 (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MSV_CUST_FUSE_MSV_SHIFT                (0U)
#define CSL_CONTROL_CORE_MSV_CUST_FUSE_MSV_RESETVAL             (0x00000000U)
#define CSL_CONTROL_CORE_MSV_CUST_FUSE_MSV_MAX                  (0xffffffffU)

#define CSL_CONTROL_CORE_MSV_RESETVAL                           (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0_STD_FUSE_OPP_VDD_GPU_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0_STD_FUSE_OPP_VDD_GPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0_STD_FUSE_OPP_VDD_GPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0_STD_FUSE_OPP_VDD_GPU_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_0_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1_STD_FUSE_OPP_VDD_GPU_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1_STD_FUSE_OPP_VDD_GPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1_STD_FUSE_OPP_VDD_GPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1_STD_FUSE_OPP_VDD_GPU_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_1_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2_STD_FUSE_OPP_VDD_GPU_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2_STD_FUSE_OPP_VDD_GPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2_STD_FUSE_OPP_VDD_GPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2_STD_FUSE_OPP_VDD_GPU_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_2_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3_STD_FUSE_OPP_VDD_GPU_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3_STD_FUSE_OPP_VDD_GPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3_STD_FUSE_OPP_VDD_GPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3_STD_FUSE_OPP_VDD_GPU_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_3_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4_STD_FUSE_OPP_VDD_GPU_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4_STD_FUSE_OPP_VDD_GPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4_STD_FUSE_OPP_VDD_GPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4_STD_FUSE_OPP_VDD_GPU_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_4_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_5 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5_STD_FUSE_OPP_VDD_GPU_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5_STD_FUSE_OPP_VDD_GPU_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5_STD_FUSE_OPP_VDD_GPU_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5_STD_FUSE_OPP_VDD_GPU_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_5_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0_STD_FUSE_OPP_VDD_MPU_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0_STD_FUSE_OPP_VDD_MPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0_STD_FUSE_OPP_VDD_MPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0_STD_FUSE_OPP_VDD_MPU_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_0_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1_STD_FUSE_OPP_VDD_MPU_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1_STD_FUSE_OPP_VDD_MPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1_STD_FUSE_OPP_VDD_MPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1_STD_FUSE_OPP_VDD_MPU_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_1_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2_STD_FUSE_OPP_VDD_MPU_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2_STD_FUSE_OPP_VDD_MPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2_STD_FUSE_OPP_VDD_MPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2_STD_FUSE_OPP_VDD_MPU_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_2_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3_STD_FUSE_OPP_VDD_MPU_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3_STD_FUSE_OPP_VDD_MPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3_STD_FUSE_OPP_VDD_MPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3_STD_FUSE_OPP_VDD_MPU_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_3_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4_STD_FUSE_OPP_VDD_MPU_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4_STD_FUSE_OPP_VDD_MPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4_STD_FUSE_OPP_VDD_MPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4_STD_FUSE_OPP_VDD_MPU_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_4_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_5 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5_STD_FUSE_OPP_VDD_MPU_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5_STD_FUSE_OPP_VDD_MPU_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5_STD_FUSE_OPP_VDD_MPU_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5_STD_FUSE_OPP_VDD_MPU_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_5_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_6 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6_STD_FUSE_OPP_VDD_MPU_6_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6_STD_FUSE_OPP_VDD_MPU_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6_STD_FUSE_OPP_VDD_MPU_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6_STD_FUSE_OPP_VDD_MPU_6_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_6_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_7 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7_STD_FUSE_OPP_VDD_MPU_7_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7_STD_FUSE_OPP_VDD_MPU_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7_STD_FUSE_OPP_VDD_MPU_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7_STD_FUSE_OPP_VDD_MPU_7_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_7_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0_STD_FUSE_OPP_VDD_CORE_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0_STD_FUSE_OPP_VDD_CORE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0_STD_FUSE_OPP_VDD_CORE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0_STD_FUSE_OPP_VDD_CORE_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_0_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1_STD_FUSE_OPP_VDD_CORE_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1_STD_FUSE_OPP_VDD_CORE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1_STD_FUSE_OPP_VDD_CORE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1_STD_FUSE_OPP_VDD_CORE_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_1_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2_STD_FUSE_OPP_VDD_CORE_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2_STD_FUSE_OPP_VDD_CORE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2_STD_FUSE_OPP_VDD_CORE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2_STD_FUSE_OPP_VDD_CORE_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_2_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3_STD_FUSE_OPP_VDD_CORE_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3_STD_FUSE_OPP_VDD_CORE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3_STD_FUSE_OPP_VDD_CORE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3_STD_FUSE_OPP_VDD_CORE_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_3_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VDD_CORE_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4_STD_FUSE_OPP_VDD_CORE_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4_STD_FUSE_OPP_VDD_CORE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4_STD_FUSE_OPP_VDD_CORE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4_STD_FUSE_OPP_VDD_CORE_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_CORE_4_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_BGAP_GPU */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU_STD_FUSE_OPP_BGAP_GPU_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU_STD_FUSE_OPP_BGAP_GPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU_STD_FUSE_OPP_BGAP_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU_STD_FUSE_OPP_BGAP_GPU_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_GPU_RESETVAL         (0x00000000U)

/* STD_FUSE_OPP_BGAP_MPU */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU_STD_FUSE_OPP_BGAP_MPU_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU_STD_FUSE_OPP_BGAP_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU_STD_FUSE_OPP_BGAP_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU_STD_FUSE_OPP_BGAP_MPU_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU_RESETVAL         (0x00000000U)

/* STD_FUSE_OPP_BGAP_CORE */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE_STD_FUSE_OPP_BGAP_CORE_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE_STD_FUSE_OPP_BGAP_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE_STD_FUSE_OPP_BGAP_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE_STD_FUSE_OPP_BGAP_CORE_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_CORE_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_BGAP_MPU23 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU3_MASK  (0xFFFF0000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU3_SHIFT  (16U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU3_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU2_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_STD_FUSE_OPP_BGAP_MPU2_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_MPU23_RESETVAL       (0x00000000U)

/* STD_FUSE_MPK_0 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_0_STD_FUSE_MPK_0_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_0_STD_FUSE_MPK_0_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_0_STD_FUSE_MPK_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_0_STD_FUSE_MPK_0_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_0_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_1 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_1_STD_FUSE_MPK_1_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_1_STD_FUSE_MPK_1_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_1_STD_FUSE_MPK_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_1_STD_FUSE_MPK_1_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_1_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_2 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_2_STD_FUSE_MPK_2_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_2_STD_FUSE_MPK_2_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_2_STD_FUSE_MPK_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_2_STD_FUSE_MPK_2_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_2_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_3 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_3_STD_FUSE_MPK_3_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_3_STD_FUSE_MPK_3_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_3_STD_FUSE_MPK_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_3_STD_FUSE_MPK_3_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_3_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_4 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_4_STD_FUSE_MPK_4_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_4_STD_FUSE_MPK_4_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_4_STD_FUSE_MPK_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_4_STD_FUSE_MPK_4_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_4_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_5 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_5_STD_FUSE_MPK_5_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_5_STD_FUSE_MPK_5_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_5_STD_FUSE_MPK_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_5_STD_FUSE_MPK_5_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_5_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_6 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_6_STD_FUSE_MPK_6_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_6_STD_FUSE_MPK_6_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_6_STD_FUSE_MPK_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_6_STD_FUSE_MPK_6_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_6_RESETVAL                (0x00000000U)

/* STD_FUSE_MPK_7 */

#define CSL_CONTROL_CORE_STD_FUSE_MPK_7_STD_FUSE_MPK_7_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_7_STD_FUSE_MPK_7_SHIFT    (0U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_7_STD_FUSE_MPK_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_MPK_7_STD_FUSE_MPK_7_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_MPK_7_RESETVAL                (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0_STD_FUSE_OPP_VDD_GPU_LVT_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0_STD_FUSE_OPP_VDD_GPU_LVT_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0_STD_FUSE_OPP_VDD_GPU_LVT_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0_STD_FUSE_OPP_VDD_GPU_LVT_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_0_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1_STD_FUSE_OPP_VDD_GPU_LVT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1_STD_FUSE_OPP_VDD_GPU_LVT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1_STD_FUSE_OPP_VDD_GPU_LVT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1_STD_FUSE_OPP_VDD_GPU_LVT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_1_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2_STD_FUSE_OPP_VDD_GPU_LVT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2_STD_FUSE_OPP_VDD_GPU_LVT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2_STD_FUSE_OPP_VDD_GPU_LVT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2_STD_FUSE_OPP_VDD_GPU_LVT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_2_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3_STD_FUSE_OPP_VDD_GPU_LVT_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3_STD_FUSE_OPP_VDD_GPU_LVT_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3_STD_FUSE_OPP_VDD_GPU_LVT_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3_STD_FUSE_OPP_VDD_GPU_LVT_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_3_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4_STD_FUSE_OPP_VDD_GPU_LVT_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4_STD_FUSE_OPP_VDD_GPU_LVT_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4_STD_FUSE_OPP_VDD_GPU_LVT_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4_STD_FUSE_OPP_VDD_GPU_LVT_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_4_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_GPU_LVT_5 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5_STD_FUSE_OPP_VDD_GPU_LVT_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5_STD_FUSE_OPP_VDD_GPU_LVT_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5_STD_FUSE_OPP_VDD_GPU_LVT_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5_STD_FUSE_OPP_VDD_GPU_LVT_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_GPU_LVT_5_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0_STD_FUSE_OPP_VDD_MPU_LVT_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0_STD_FUSE_OPP_VDD_MPU_LVT_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0_STD_FUSE_OPP_VDD_MPU_LVT_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0_STD_FUSE_OPP_VDD_MPU_LVT_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_0_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1_STD_FUSE_OPP_VDD_MPU_LVT_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1_STD_FUSE_OPP_VDD_MPU_LVT_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1_STD_FUSE_OPP_VDD_MPU_LVT_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1_STD_FUSE_OPP_VDD_MPU_LVT_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_1_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2_STD_FUSE_OPP_VDD_MPU_LVT_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2_STD_FUSE_OPP_VDD_MPU_LVT_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2_STD_FUSE_OPP_VDD_MPU_LVT_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2_STD_FUSE_OPP_VDD_MPU_LVT_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_2_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3_STD_FUSE_OPP_VDD_MPU_LVT_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3_STD_FUSE_OPP_VDD_MPU_LVT_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3_STD_FUSE_OPP_VDD_MPU_LVT_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3_STD_FUSE_OPP_VDD_MPU_LVT_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_3_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4_STD_FUSE_OPP_VDD_MPU_LVT_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4_STD_FUSE_OPP_VDD_MPU_LVT_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4_STD_FUSE_OPP_VDD_MPU_LVT_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4_STD_FUSE_OPP_VDD_MPU_LVT_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_4_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_5 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5_STD_FUSE_OPP_VDD_MPU_LVT_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5_STD_FUSE_OPP_VDD_MPU_LVT_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5_STD_FUSE_OPP_VDD_MPU_LVT_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5_STD_FUSE_OPP_VDD_MPU_LVT_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_5_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_6 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6_STD_FUSE_OPP_VDD_MPU_LVT_6_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6_STD_FUSE_OPP_VDD_MPU_LVT_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6_STD_FUSE_OPP_VDD_MPU_LVT_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6_STD_FUSE_OPP_VDD_MPU_LVT_6_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_6_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VDD_MPU_LVT_7 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7_STD_FUSE_OPP_VDD_MPU_LVT_7_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7_STD_FUSE_OPP_VDD_MPU_LVT_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7_STD_FUSE_OPP_VDD_MPU_LVT_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7_STD_FUSE_OPP_VDD_MPU_LVT_7_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_MPU_LVT_7_RESETVAL    (0x00000000U)

/* CUST_FUSE_CEK_BCH_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0_CUST_FUSE_CEK_BCH_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0_CUST_FUSE_CEK_BCH_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0_CUST_FUSE_CEK_BCH_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0_CUST_FUSE_CEK_BCH_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_0_RESETVAL           (0x00000000U)

/* CUST_FUSE_CEK_BCH_1 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1_CUST_FUSE_CEK_BCH_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1_CUST_FUSE_CEK_BCH_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1_CUST_FUSE_CEK_BCH_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1_CUST_FUSE_CEK_BCH_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_1_RESETVAL           (0x00000000U)

/* CUST_FUSE_CEK_BCH_2 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2_CUST_FUSE_CEK_BCH_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2_CUST_FUSE_CEK_BCH_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2_CUST_FUSE_CEK_BCH_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2_CUST_FUSE_CEK_BCH_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_2_RESETVAL           (0x00000000U)

/* CUST_FUSE_CEK_BCH_3 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3_CUST_FUSE_CEK_BCH_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3_CUST_FUSE_CEK_BCH_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3_CUST_FUSE_CEK_BCH_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3_CUST_FUSE_CEK_BCH_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_3_RESETVAL           (0x00000000U)

/* CUST_FUSE_CEK_BCH_4 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4_CUST_FUSE_CEK_BCH_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4_CUST_FUSE_CEK_BCH_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4_CUST_FUSE_CEK_BCH_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4_CUST_FUSE_CEK_BCH_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK_BCH_4_RESETVAL           (0x00000000U)

/* CUST_FUSE_CEK2_BCH_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0_CUST_FUSE_CEK2_BCH_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0_CUST_FUSE_CEK2_BCH_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0_CUST_FUSE_CEK2_BCH_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0_CUST_FUSE_CEK2_BCH_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_0_RESETVAL          (0x00000000U)

/* CUST_FUSE_CEK2_BCH_1 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1_CUST_FUSE_CEK2_BCH_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1_CUST_FUSE_CEK2_BCH_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1_CUST_FUSE_CEK2_BCH_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1_CUST_FUSE_CEK2_BCH_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_1_RESETVAL          (0x00000000U)

/* CUST_FUSE_CEK2_BCH_2 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2_CUST_FUSE_CEK2_BCH_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2_CUST_FUSE_CEK2_BCH_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2_CUST_FUSE_CEK2_BCH_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2_CUST_FUSE_CEK2_BCH_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_2_RESETVAL          (0x00000000U)

/* CUST_FUSE_CEK2_BCH_3 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3_CUST_FUSE_CEK2_BCH_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3_CUST_FUSE_CEK2_BCH_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3_CUST_FUSE_CEK2_BCH_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3_CUST_FUSE_CEK2_BCH_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_3_RESETVAL          (0x00000000U)

/* CUST_FUSE_CEK2_BCH_4 */

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4_CUST_FUSE_CEK2_BCH_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4_CUST_FUSE_CEK2_BCH_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4_CUST_FUSE_CEK2_BCH_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4_CUST_FUSE_CEK2_BCH_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_CEK2_BCH_4_RESETVAL          (0x00000000U)

/* CUST_FUSE_MSV_BCH_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0_CUST_FUSE_MSV_BCH_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0_CUST_FUSE_MSV_BCH_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0_CUST_FUSE_MSV_BCH_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0_CUST_FUSE_MSV_BCH_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_0_RESETVAL           (0x00000000U)

/* CUST_FUSE_MSV_BCH_1 */

#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1_CUST_FUSE_MSV_BCH_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1_CUST_FUSE_MSV_BCH_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1_CUST_FUSE_MSV_BCH_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1_CUST_FUSE_MSV_BCH_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_MSV_BCH_1_RESETVAL           (0x00000000U)

/* CUST_FUSE_SWRV_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0_CUST_FUSE_SWRV_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0_CUST_FUSE_SWRV_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0_CUST_FUSE_SWRV_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0_CUST_FUSE_SWRV_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_0_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_1 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1_CUST_FUSE_SWRV_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1_CUST_FUSE_SWRV_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1_CUST_FUSE_SWRV_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1_CUST_FUSE_SWRV_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_1_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_2 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2_CUST_FUSE_SWRV_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2_CUST_FUSE_SWRV_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2_CUST_FUSE_SWRV_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2_CUST_FUSE_SWRV_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_2_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_3 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3_CUST_FUSE_SWRV_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3_CUST_FUSE_SWRV_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3_CUST_FUSE_SWRV_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3_CUST_FUSE_SWRV_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_3_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_4 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4_CUST_FUSE_SWRV_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4_CUST_FUSE_SWRV_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4_CUST_FUSE_SWRV_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4_CUST_FUSE_SWRV_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_4_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_5 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5_CUST_FUSE_SWRV_5_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5_CUST_FUSE_SWRV_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5_CUST_FUSE_SWRV_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5_CUST_FUSE_SWRV_5_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_5_RESETVAL              (0x00000000U)

/* CUST_FUSE_SWRV_6 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6_CUST_FUSE_SWRV_6_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6_CUST_FUSE_SWRV_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6_CUST_FUSE_SWRV_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6_CUST_FUSE_SWRV_6_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_6_RESETVAL              (0x00000000U)

/* HWOBSDIVIDER1 */

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_10_RESERVED_MASK  (0x38000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_10_RESERVED_SHIFT  (27U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_10_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_10_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_9_RESERVED_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_9_RESERVED_SHIFT  (24U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_9_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_9_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_8_RESERVED_MASK  (0x00E00000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_8_RESERVED_SHIFT  (21U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_8_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_8_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_7_RESERVED_MASK  (0x001C0000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_7_RESERVED_SHIFT  (18U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_7_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_7_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_6_RESERVED_MASK  (0x00038000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_6_RESERVED_SHIFT  (15U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_6_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_6_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_5_RESERVED_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_5_RESERVED_SHIFT  (12U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_5_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_5_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_4_RESERVED_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_4_RESERVED_SHIFT  (9U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_4_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_4_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_3_RESERVED_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_3_RESERVED_SHIFT  (6U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_3_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_3_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_2_RESERVED_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_2_RESERVED_SHIFT  (3U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_2_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_2_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_1_RESERVED_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_1_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_1_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER1_HWOBSDIV_1_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER1_RESETVAL                 (0x00000000U)

/* HWOBSDIVIDER2 */

#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_14_RESERVED_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_14_RESERVED_SHIFT  (9U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_14_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_14_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_13_RESERVED_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_13_RESERVED_SHIFT  (6U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_13_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_13_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_12_RESERVED_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_12_RESERVED_SHIFT  (3U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_12_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_12_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_11_RESERVED_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_11_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_11_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBSDIVIDER2_HWOBSDIV_11_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_HWOBSDIVIDER2_RESETVAL                 (0x00000000U)

/* BREG_SELECTION */

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DDR_MASK            (0x00004000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DDR_SHIFT           (14U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DDR_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DDR_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DDR_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GPU_MASK            (0x00002000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GPU_SHIFT           (13U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GPU_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GPU_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GPU_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GMAC_MASK           (0x00001000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GMAC_SHIFT          (12U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GMAC_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GMAC_SEL            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_GMAC_NOSEL          (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSP_MASK            (0x00000800U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSP_SHIFT           (11U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSP_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSP_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSP_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_EVE_MASK            (0x00000400U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_EVE_SHIFT           (10U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_EVE_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_EVE_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_EVE_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_USB_MASK            (0x00000200U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_USB_SHIFT           (9U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_USB_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_USB_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_USB_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IVA_MASK            (0x00000100U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IVA_SHIFT           (8U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IVA_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IVA_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IVA_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PCIE_MASK           (0x00000080U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PCIE_SHIFT          (7U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PCIE_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PCIE_SEL            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PCIE_NOSEL          (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_SATA_MASK           (0x00000040U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_SATA_SHIFT          (6U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_SATA_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_SATA_SEL            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_SATA_NOSEL          (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PER_MASK            (0x00000020U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PER_SHIFT           (5U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PER_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PER_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_PER_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_HDMI_MASK           (0x00000010U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_HDMI_SHIFT          (4U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_HDMI_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_HDMI_SEL            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_HDMI_NOSEL          (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1C_MASK          (0x00000008U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1C_SHIFT         (3U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1C_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1C_SEL           (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1C_NOSEL         (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1A_MASK          (0x00000004U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1A_SHIFT         (2U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1A_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1A_SEL           (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_DSI1A_NOSEL         (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_CORE_MASK           (0x00000002U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_CORE_SHIFT          (1U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_CORE_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_CORE_SEL            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_CORE_NOSEL          (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IPU_MASK            (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IPU_SHIFT           (0U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IPU_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IPU_SEL             (0x00000001U)
#define CSL_CONTROL_CORE_BREG_SELECTION_SEL_IPU_NOSEL           (0x00000000U)

#define CSL_CONTROL_CORE_BREG_SELECTION_RESETVAL                (0x00000000U)

/* DPLL_BCLK */

#define CSL_CONTROL_CORE_DPLL_BCLK_BRW_MASK                     (0x00000002U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BRW_SHIFT                    (1U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BRW_RESETVAL                 (0x00000000U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BRW_SEL                      (0x00000001U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BRW_NOSEL                    (0x00000000U)

#define CSL_CONTROL_CORE_DPLL_BCLK_BCLK_MASK                    (0x00000001U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BCLK_SHIFT                   (0U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BCLK_RESETVAL                (0x00000000U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BCLK_SEL                     (0x00000001U)
#define CSL_CONTROL_CORE_DPLL_BCLK_BCLK_NOSEL                   (0x00000000U)

#define CSL_CONTROL_CORE_DPLL_BCLK_RESETVAL                     (0x00000000U)

/* DPLL_BADDR_BDATAW */

#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BADDR_MASK           (0x000F0000U)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BADDR_SHIFT          (16U)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BADDR_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BADDR_MAX            (0x0000000fU)

#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BDATAW_MASK          (0x0000FFFFU)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BDATAW_SHIFT         (0U)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BDATAW_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_BDATAW_MAX           (0x0000ffffU)

#define CSL_CONTROL_CORE_DPLL_BADDR_BDATAW_RESETVAL             (0x00000000U)

/* DPLL_BDATAR */

#define CSL_CONTROL_CORE_DPLL_BDATAR_BDATAR_MASK                (0x0000FFFFU)
#define CSL_CONTROL_CORE_DPLL_BDATAR_BDATAR_SHIFT               (0U)
#define CSL_CONTROL_CORE_DPLL_BDATAR_BDATAR_RESETVAL            (0x00000000U)
#define CSL_CONTROL_CORE_DPLL_BDATAR_BDATAR_MAX                 (0x0000ffffU)

#define CSL_CONTROL_CORE_DPLL_BDATAR_RESETVAL                   (0x00000000U)

/* DEV_CONF */

#define CSL_CONTROL_CORE_DEV_CONF_DEV_CONF_RESERVED_MASK        (0xFFFFFFFEU)
#define CSL_CONTROL_CORE_DEV_CONF_DEV_CONF_RESERVED_SHIFT       (1U)
#define CSL_CONTROL_CORE_DEV_CONF_DEV_CONF_RESERVED_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_DEV_CONF_DEV_CONF_RESERVED_MAX         (0x7fffffffU)

#define CSL_CONTROL_CORE_DEV_CONF_USBPHY_PD_RESERVED_MASK       (0x00000001U)
#define CSL_CONTROL_CORE_DEV_CONF_USBPHY_PD_RESERVED_SHIFT      (0U)
#define CSL_CONTROL_CORE_DEV_CONF_USBPHY_PD_RESERVED_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DEV_CONF_USBPHY_PD_RESERVED_MAX        (0x00000001U)

#define CSL_CONTROL_CORE_DEV_CONF_RESETVAL                      (0x00000000U)

/* IVA3_BOOTADDR */

#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_LOAD_ADDR_RESERVED_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_LOAD_ADDR_RESERVED_SHIFT  (10U)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_LOAD_ADDR_RESERVED_RESETVAL  (0x00080000U)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_LOAD_ADDR_RESERVED_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_REV_ID_RESERVED_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_REV_ID_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_REV_ID_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IVA3_BOOTADDR_IVA3_BOOT_REV_ID_RESERVED_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_IVA3_BOOTADDR_RESETVAL                 (0x20000000U)

/* TEMP_SENSOR_MPU */

#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_TMPSOFF_MPU_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_TMPSOFF_MPU_SHIFT  (11U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_TMPSOFF_MPU_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_TMPSOFF_MPU_MAX   (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_EOCZ_MPU_MASK     (0x00000400U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_EOCZ_MPU_SHIFT    (10U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_EOCZ_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_EOCZ_MPU_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_DTEMP_MPU_MASK    (0x000003FFU)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_DTEMP_MPU_SHIFT   (0U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_DTEMP_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_BGAP_DTEMP_MPU_MAX     (0x000003ffU)

#define CSL_CONTROL_CORE_TEMP_SENSOR_MPU_RESETVAL               (0x00000800U)

/* TEMP_SENSOR_GPU */

#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_TMPSOFF_GPU_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_TMPSOFF_GPU_SHIFT  (11U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_TMPSOFF_GPU_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_TMPSOFF_GPU_MAX   (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_EOCZ_GPU_MASK     (0x00000400U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_EOCZ_GPU_SHIFT    (10U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_EOCZ_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_EOCZ_GPU_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_DTEMP_GPU_MASK    (0x000003FFU)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_DTEMP_GPU_SHIFT   (0U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_DTEMP_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_BGAP_DTEMP_GPU_MAX     (0x000003ffU)

#define CSL_CONTROL_CORE_TEMP_SENSOR_GPU_RESETVAL               (0x00000800U)

/* TEMP_SENSOR_CORE */

#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_TMPSOFF_CORE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_TMPSOFF_CORE_SHIFT  (11U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_TMPSOFF_CORE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_TMPSOFF_CORE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_EOCZ_CORE_MASK   (0x00000400U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_EOCZ_CORE_SHIFT  (10U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_EOCZ_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_EOCZ_CORE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_DTEMP_CORE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_DTEMP_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_DTEMP_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_BGAP_DTEMP_CORE_MAX   (0x000003ffU)

#define CSL_CONTROL_CORE_TEMP_SENSOR_CORE_RESETVAL              (0x00000800U)

/* STD_FUSE_DFT_MEM_RW_MPU */

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU_STD_FUSE_DFT_MEM_RW_MPU_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU_STD_FUSE_DFT_MEM_RW_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU_STD_FUSE_DFT_MEM_RW_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU_STD_FUSE_DFT_MEM_RW_MPU_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MPU_RESETVAL       (0x00000000U)

/* STD_FUSE_DFT_MEM_RW_MM */

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM_STD_FUSE_DFT_MEM_RW_MM_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM_STD_FUSE_DFT_MEM_RW_MM_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM_STD_FUSE_DFT_MEM_RW_MM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM_STD_FUSE_DFT_MEM_RW_MM_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_MM_RESETVAL        (0x00000000U)

/* STD_FUSE_DFT_MEM_RW_CORE */

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE_STD_FUSE_DFT_MEM_RW_CORE_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE_STD_FUSE_DFT_MEM_RW_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE_STD_FUSE_DFT_MEM_RW_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE_STD_FUSE_DFT_MEM_RW_CORE_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_STD_FUSE_DFT_MEM_RW_CORE_RESETVAL      (0x00000000U)

/* DUCATI_MMUADDRTRANSLTR */

#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR_DUCATI_MMUADDRTRANSLTR_MASK  (0x000FFFFFU)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR_DUCATI_MMUADDRTRANSLTR_SHIFT  (0U)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR_DUCATI_MMUADDRTRANSLTR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR_DUCATI_MMUADDRTRANSLTR_MAX  (0x000fffffU)

#define CSL_CONTROL_CORE_DUCATI_MMUADDRTRANSLTR_RESETVAL        (0x00000000U)

/* DUCATI_MMUADDRLOGICTR */

#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR_DUCATI_MMUADDRLOGICTR_MASK  (0x000FFFFFU)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR_DUCATI_MMUADDRLOGICTR_SHIFT  (0U)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR_DUCATI_MMUADDRLOGICTR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR_DUCATI_MMUADDRLOGICTR_MAX  (0x000fffffU)

#define CSL_CONTROL_CORE_DUCATI_MMUADDRLOGICTR_RESETVAL         (0x00000000U)

/* HWOBS_CONTROL */

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_2_MASK  (0x0007C000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_2_SHIFT  (14U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_2_MAX   (0x0000001fU)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_1_MASK  (0x00003E00U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_1_SHIFT  (9U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_1_MAX   (0x0000001fU)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKOBS_GATE_ENABLE_RESERVED_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKOBS_GATE_ENABLE_RESERVED_SHIFT  (8U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKOBS_GATE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKOBS_GATE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_MASK    (0x000000F8U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_SHIFT   (3U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_CLKDIV_SEL_MAX     (0x0000001fU)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ZERO_MODE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ZERO_MODE_SHIFT  (2U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ZERO_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ZERO_MODE_ENABLED  (0x00000001U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ZERO_MODE_DISABLED  (0x00000000U)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ONE_MODE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ONE_MODE_SHIFT  (1U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ONE_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ONE_MODE_ENABLED  (0x00000001U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_ALL_ONE_MODE_DISABLED  (0x00000000U)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_MACRO_ENABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_MACRO_ENABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_MACRO_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_MACRO_ENABLE_ENABLED  (0x00000001U)
#define CSL_CONTROL_CORE_HWOBS_CONTROL_HWOBS_MACRO_ENABLE_DISABLED  (0x00000000U)

#define CSL_CONTROL_CORE_HWOBS_CONTROL_RESETVAL                 (0x00000000U)

/* PCS1 */

#define CSL_CONTROL_CORE_PCS1_USB_TEST_TXDATA_MASK              (0xFFC00000U)
#define CSL_CONTROL_CORE_PCS1_USB_TEST_TXDATA_SHIFT             (22U)
#define CSL_CONTROL_CORE_PCS1_USB_TEST_TXDATA_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS1_USB_TEST_TXDATA_MAX               (0x000003ffU)

#define CSL_CONTROL_CORE_PCS1_USB_ERR_USB_BIT_EN_MASK           (0x003FF000U)
#define CSL_CONTROL_CORE_PCS1_USB_ERR_USB_BIT_EN_SHIFT          (12U)
#define CSL_CONTROL_CORE_PCS1_USB_ERR_USB_BIT_EN_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_PCS1_USB_ERR_USB_BIT_EN_MAX            (0x000003ffU)

#define CSL_CONTROL_CORE_PCS1_USB_CFG_HOLDOFF_MASK              (0x00000FF0U)
#define CSL_CONTROL_CORE_PCS1_USB_CFG_HOLDOFF_SHIFT             (4U)
#define CSL_CONTROL_CORE_PCS1_USB_CFG_HOLDOFF_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS1_USB_CFG_HOLDOFF_MAX               (0x000000ffU)

#define CSL_CONTROL_CORE_PCS1_USB_DET_DELAY_MASK                (0x0000000FU)
#define CSL_CONTROL_CORE_PCS1_USB_DET_DELAY_SHIFT               (0U)
#define CSL_CONTROL_CORE_PCS1_USB_DET_DELAY_RESETVAL            (0x00000001U)
#define CSL_CONTROL_CORE_PCS1_USB_DET_DELAY_MAX                 (0x0000000fU)

#define CSL_CONTROL_CORE_PCS1_RESETVAL                          (0x00000001U)

/* PCS2 */

#define CSL_CONTROL_CORE_PCS2_USB_CFG_SYNC_MASK                 (0xF8000000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_SYNC_SHIFT                (27U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_SYNC_RESETVAL             (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_SYNC_MAX                  (0x0000001fU)

#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_FUNC_MASK              (0x07800000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_FUNC_SHIFT             (23U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_FUNC_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_FUNC_MAX               (0x0000000fU)

#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_HOLD_MASK              (0x00780000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_HOLD_SHIFT             (19U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_HOLD_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_HOLD_MAX               (0x0000000fU)

#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_INIT_MASK              (0x00078000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_INIT_SHIFT             (15U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_INIT_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_CFG_EQ_INIT_MAX               (0x0000000fU)

#define CSL_CONTROL_CORE_PCS2_USB_TEST_OSEL_MASK                (0x00007000U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_OSEL_SHIFT               (12U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_OSEL_RESETVAL            (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_OSEL_MAX                 (0x00000007U)

#define CSL_CONTROL_CORE_PCS2_USB_RC_DELAY_MASK                 (0x00000C00U)
#define CSL_CONTROL_CORE_PCS2_USB_RC_DELAY_SHIFT                (10U)
#define CSL_CONTROL_CORE_PCS2_USB_RC_DELAY_RESETVAL             (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_RC_DELAY_MAX                  (0x00000003U)

#define CSL_CONTROL_CORE_PCS2_USB_TEST_LSEL_MASK                (0x00000200U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_LSEL_SHIFT               (9U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_LSEL_RESETVAL            (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_LSEL_MAX                 (0x00000001U)

#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_MODE_MASK             (0x000000C0U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_MODE_SHIFT            (6U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_MODE_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_MODE_MAX              (0x00000003U)

#define CSL_CONTROL_CORE_PCS2_USB_L1_SLEEP_MASK                 (0x00000020U)
#define CSL_CONTROL_CORE_PCS2_USB_L1_SLEEP_SHIFT                (5U)
#define CSL_CONTROL_CORE_PCS2_USB_L1_SLEEP_RESETVAL             (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_L1_SLEEP_MAX                  (0x00000001U)

#define CSL_CONTROL_CORE_PCS2_USB_TEST_MODE_MASK                (0x00000010U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_MODE_SHIFT               (4U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_MODE_RESETVAL            (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_TEST_MODE_MAX                 (0x00000001U)

#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_LN_EN_MASK            (0x00000008U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_LN_EN_SHIFT           (3U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_LN_EN_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_ERR_USB_LN_EN_MAX             (0x00000001U)

#define CSL_CONTROL_CORE_PCS2_USB_SHORT_TIMES_MASK              (0x00000001U)
#define CSL_CONTROL_CORE_PCS2_USB_SHORT_TIMES_SHIFT             (0U)
#define CSL_CONTROL_CORE_PCS2_USB_SHORT_TIMES_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_PCS2_USB_SHORT_TIMES_MAX               (0x00000001U)

#define CSL_CONTROL_CORE_PCS2_RESETVAL                          (0x00000000U)

/* PCS_REVISION */

#define CSL_CONTROL_CORE_PCS_REVISION_USB_REVISION_MASK         (0xE0000000U)
#define CSL_CONTROL_CORE_PCS_REVISION_USB_REVISION_SHIFT        (29U)
#define CSL_CONTROL_CORE_PCS_REVISION_USB_REVISION_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_PCS_REVISION_USB_REVISION_MAX          (0x00000007U)

#define CSL_CONTROL_CORE_PCS_REVISION_RESETVAL                  (0x00000000U)

/* PHY_POWER_USB */

#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_FREQ_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_FREQ_SHIFT  (22U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_FREQ_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_FREQ_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_CMD_MASK  (0x003FC000U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_CMD_SHIFT  (14U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_CMD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PHY_POWER_USB_USB_PWRCTL_CLK_CMD_MAX   (0x000000ffU)

#define CSL_CONTROL_CORE_PHY_POWER_USB_RESETVAL                 (0x00000000U)

/* PHY_POWER_SATA */

#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_FREQ_MASK  (0xFFC00000U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_FREQ_SHIFT  (22U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_FREQ_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_FREQ_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_CMD_MASK  (0x003FC000U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_CMD_SHIFT  (14U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_CMD_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PHY_POWER_SATA_SATA_PWRCTL_CLK_CMD_MAX  (0x000000ffU)

#define CSL_CONTROL_CORE_PHY_POWER_SATA_RESETVAL                (0x00000000U)

/* BANDGAP_MASK_1 */

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_MASK          (0xC0000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_SHIFT         (30U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_FORCEIDLE     (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_NOFUNC        (0x00000003U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_NOIDLE        (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_SIDLEMODE_SMARTIDLE     (0x00000002U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_MASK      (0x38000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_SHIFT     (27U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_250MS   (0x00000004U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_1MS     (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_100MS   (0x00000003U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_IMEDIAT  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_10MS    (0x00000002U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_COUNTER_DELAY_C_500MS   (0x00000005U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_CORE_MASK        (0x00800000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_CORE_SHIFT       (23U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_CORE_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_CORE_FREEZE      (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_CORE_NO_OP       (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_GPU_MASK         (0x00400000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_GPU_SHIFT        (22U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_GPU_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_GPU_FREEZE       (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_GPU_NO_OP        (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_MPU_MASK         (0x00200000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_MPU_SHIFT        (21U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_MPU_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_MPU_FREEZE       (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_FREEZE_MPU_NO_OP        (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_CORE_MASK         (0x00100000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_CORE_SHIFT        (20U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_CORE_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_CORE_RESET        (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_CORE_NO_OP        (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_GPU_MASK          (0x00080000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_GPU_SHIFT         (19U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_GPU_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_GPU_RESET         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_GPU_NO_OP         (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_MPU_MASK          (0x00040000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_MPU_SHIFT         (18U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_MPU_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_MPU_RESET         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_MPU_NO_OP         (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_CORE_MASK   (0x00020000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_CORE_SHIFT  (17U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_CORE_RESET  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_CORE_NO_OP  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_GPU_MASK    (0x00010000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_GPU_SHIFT   (16U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_GPU_RESET   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_GPU_NO_OP   (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_MPU_MASK    (0x00008000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_MPU_SHIFT   (15U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_MPU_RESET   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_CLEAR_ACCUM_MPU_NO_OP   (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_CORE_MASK      (0x00000020U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_CORE_SHIFT     (5U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_CORE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_CORE_MASKED    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_CORE_MASK     (0x00000010U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_CORE_SHIFT    (4U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_CORE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_CORE_MASKED   (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_GPU_MASK       (0x00000008U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_GPU_SHIFT      (3U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_GPU_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_GPU_UNMASKED   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_GPU_MASKED     (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_GPU_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_GPU_SHIFT     (2U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_GPU_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_GPU_MASKED    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_MPU_MASK       (0x00000002U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_MPU_SHIFT      (1U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_MPU_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_MPU_UNMASKED   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_HOT_MPU_MASKED     (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_MPU_MASK      (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_MPU_SHIFT     (0U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_MPU_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_1_MASK_COLD_MPU_MASKED    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_1_RESETVAL                (0x00000000U)

/* BANDGAP_THRESHOLD_MPU */

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_HOT_MPU_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_HOT_MPU_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_HOT_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_HOT_MPU_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_COLD_MPU_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_COLD_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_COLD_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_THOLD_COLD_MPU_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_MPU_RESETVAL         (0x00000000U)

/* BANDGAP_THRESHOLD_GPU */

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_HOT_GPU_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_HOT_GPU_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_HOT_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_HOT_GPU_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_COLD_GPU_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_COLD_GPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_COLD_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_THOLD_COLD_GPU_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_GPU_RESETVAL         (0x00000000U)

/* BANDGAP_THRESHOLD_CORE */

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_HOT_CORE_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_HOT_CORE_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_HOT_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_HOT_CORE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_COLD_CORE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_COLD_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_COLD_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_THOLD_COLD_CORE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_CORE_RESETVAL        (0x00000000U)

/* BANDGAP_TSHUT_MPU */

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_MUXCTRL_MPU_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_MUXCTRL_MPU_SHIFT  (31U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_MUXCTRL_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_MUXCTRL_MPU_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_MUXCTRL_MPU_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_HOT_MPU_MASK   (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_HOT_MPU_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_HOT_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_HOT_MPU_MAX    (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_COLD_MPU_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_COLD_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_COLD_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_TSHUT_COLD_MPU_MAX   (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_MPU_RESETVAL             (0x00000000U)

/* BANDGAP_TSHUT_GPU */

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_MUXCTRL_GPU_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_MUXCTRL_GPU_SHIFT  (31U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_MUXCTRL_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_MUXCTRL_GPU_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_MUXCTRL_GPU_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_HOT_GPU_MASK   (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_HOT_GPU_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_HOT_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_HOT_GPU_MAX    (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_COLD_GPU_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_COLD_GPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_COLD_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_TSHUT_COLD_GPU_MAX   (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_GPU_RESETVAL             (0x00000000U)

/* BANDGAP_TSHUT_CORE */

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_MUXCTRL_CORE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_MUXCTRL_CORE_SHIFT  (31U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_MUXCTRL_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_MUXCTRL_CORE_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_MUXCTRL_CORE_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_HOT_CORE_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_HOT_CORE_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_HOT_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_HOT_CORE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_COLD_CORE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_COLD_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_COLD_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_TSHUT_COLD_CORE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_CORE_RESETVAL            (0x00000000U)

/* BANDGAP_CUMUL_DTEMP_MPU */

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU_CUMUL_DTEMP_MPU_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU_CUMUL_DTEMP_MPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU_CUMUL_DTEMP_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU_CUMUL_DTEMP_MPU_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_MPU_RESETVAL       (0x00000000U)

/* BANDGAP_CUMUL_DTEMP_GPU */

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU_CUMUL_DTEMP_GPU_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU_CUMUL_DTEMP_GPU_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU_CUMUL_DTEMP_GPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU_CUMUL_DTEMP_GPU_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_GPU_RESETVAL       (0x00000000U)

/* BANDGAP_CUMUL_DTEMP_CORE */

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE_CUMUL_DTEMP_CORE_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE_CUMUL_DTEMP_CORE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE_CUMUL_DTEMP_CORE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE_CUMUL_DTEMP_CORE_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_CORE_RESETVAL      (0x00000000U)

/* BANDGAP_STATUS_1 */

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_ALERT_MASK            (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_ALERT_SHIFT           (31U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_ALERT_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_ALERT_MAX             (0x00000001U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_CORE_MASK         (0x00000020U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_CORE_SHIFT        (5U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_CORE_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_CORE_EVENT        (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_CORE_NOEVENT      (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_CORE_MASK        (0x00000010U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_CORE_SHIFT       (4U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_CORE_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_CORE_EVENT       (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_CORE_NOEVENT     (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_GPU_MASK          (0x00000008U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_GPU_SHIFT         (3U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_GPU_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_GPU_EVENT         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_GPU_NOEVENT       (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_GPU_MASK         (0x00000004U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_GPU_SHIFT        (2U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_GPU_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_GPU_EVENT        (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_GPU_NOEVENT      (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_MPU_MASK          (0x00000002U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_MPU_SHIFT         (1U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_MPU_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_MPU_EVENT         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_HOT_MPU_NOEVENT       (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_MPU_MASK         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_MPU_SHIFT        (0U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_MPU_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_MPU_EVENT        (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_COLD_MPU_NOEVENT      (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_1_RESETVAL              (0x00000000U)

/* SATA_EXT_MODE */

#define CSL_CONTROL_CORE_SATA_EXT_MODE_SATA_EXTENDED_MODE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SATA_EXT_MODE_SATA_EXTENDED_MODE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SATA_EXT_MODE_SATA_EXTENDED_MODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SATA_EXT_MODE_SATA_EXTENDED_MODE_EXTENDED  (0x00000001U)
#define CSL_CONTROL_CORE_SATA_EXT_MODE_SATA_EXTENDED_MODE_NO_EX  (0x00000000U)

#define CSL_CONTROL_CORE_SATA_EXT_MODE_RESETVAL                 (0x00000000U)

/* CEK2_0 */

#define CSL_CONTROL_CORE_CEK2_0_CUST_FUSE_CEK2_0_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK2_0_CUST_FUSE_CEK2_0_SHIFT          (0U)
#define CSL_CONTROL_CORE_CEK2_0_CUST_FUSE_CEK2_0_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_CEK2_0_CUST_FUSE_CEK2_0_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_CEK2_0_RESETVAL                        (0x00000000U)

/* CEK2_1 */

#define CSL_CONTROL_CORE_CEK2_1_CUST_FUSE_CEK2_1_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK2_1_CUST_FUSE_CEK2_1_SHIFT          (0U)
#define CSL_CONTROL_CORE_CEK2_1_CUST_FUSE_CEK2_1_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_CEK2_1_CUST_FUSE_CEK2_1_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_CEK2_1_RESETVAL                        (0x00000000U)

/* CEK2_2 */

#define CSL_CONTROL_CORE_CEK2_2_CUST_FUSE_CEK2_2_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK2_2_CUST_FUSE_CEK2_2_SHIFT          (0U)
#define CSL_CONTROL_CORE_CEK2_2_CUST_FUSE_CEK2_2_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_CEK2_2_CUST_FUSE_CEK2_2_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_CEK2_2_RESETVAL                        (0x00000000U)

/* CEK2_3 */

#define CSL_CONTROL_CORE_CEK2_3_CUST_FUSE_CEK2_3_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CEK2_3_CUST_FUSE_CEK2_3_SHIFT          (0U)
#define CSL_CONTROL_CORE_CEK2_3_CUST_FUSE_CEK2_3_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_CEK2_3_CUST_FUSE_CEK2_3_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_CEK2_3_RESETVAL                        (0x00000000U)

/* DTEMP_MPU_0 */

#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TAG_MPU_0_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TAG_MPU_0_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TAG_MPU_0_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TAG_MPU_0_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TEMPERATURE_MPU_0_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TEMPERATURE_MPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TEMPERATURE_MPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_0_DTEMP_TEMPERATURE_MPU_0_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_0_RESETVAL                   (0x00000000U)

/* DTEMP_MPU_1 */

#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TAG_MPU_1_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TAG_MPU_1_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TAG_MPU_1_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TAG_MPU_1_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TEMPERATURE_MPU_1_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TEMPERATURE_MPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TEMPERATURE_MPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_1_DTEMP_TEMPERATURE_MPU_1_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_1_RESETVAL                   (0x00000000U)

/* DTEMP_MPU_2 */

#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TAG_MPU_2_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TAG_MPU_2_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TAG_MPU_2_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TAG_MPU_2_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TEMPERATURE_MPU_2_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TEMPERATURE_MPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TEMPERATURE_MPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_2_DTEMP_TEMPERATURE_MPU_2_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_2_RESETVAL                   (0x00000000U)

/* DTEMP_MPU_3 */

#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TAG_MPU_3_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TAG_MPU_3_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TAG_MPU_3_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TAG_MPU_3_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TEMPERATURE_MPU_3_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TEMPERATURE_MPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TEMPERATURE_MPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_3_DTEMP_TEMPERATURE_MPU_3_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_3_RESETVAL                   (0x00000000U)

/* DTEMP_MPU_4 */

#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TAG_MPU_4_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TAG_MPU_4_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TAG_MPU_4_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TAG_MPU_4_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TEMPERATURE_MPU_4_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TEMPERATURE_MPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TEMPERATURE_MPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_MPU_4_DTEMP_TEMPERATURE_MPU_4_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_MPU_4_RESETVAL                   (0x00000000U)

/* DTEMP_GPU_0 */

#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TAG_GPU_0_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TAG_GPU_0_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TAG_GPU_0_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TAG_GPU_0_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TEMPERATURE_GPU_0_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TEMPERATURE_GPU_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TEMPERATURE_GPU_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_0_DTEMP_TEMPERATURE_GPU_0_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_0_RESETVAL                   (0x00000000U)

/* DTEMP_GPU_1 */

#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TAG_GPU_1_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TAG_GPU_1_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TAG_GPU_1_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TAG_GPU_1_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TEMPERATURE_GPU_1_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TEMPERATURE_GPU_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TEMPERATURE_GPU_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_1_DTEMP_TEMPERATURE_GPU_1_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_1_RESETVAL                   (0x00000000U)

/* DTEMP_GPU_2 */

#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TAG_GPU_2_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TAG_GPU_2_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TAG_GPU_2_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TAG_GPU_2_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TEMPERATURE_GPU_2_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TEMPERATURE_GPU_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TEMPERATURE_GPU_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_2_DTEMP_TEMPERATURE_GPU_2_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_2_RESETVAL                   (0x00000000U)

/* DTEMP_GPU_3 */

#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TAG_GPU_3_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TAG_GPU_3_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TAG_GPU_3_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TAG_GPU_3_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TEMPERATURE_GPU_3_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TEMPERATURE_GPU_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TEMPERATURE_GPU_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_3_DTEMP_TEMPERATURE_GPU_3_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_3_RESETVAL                   (0x00000000U)

/* DTEMP_GPU_4 */

#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TAG_GPU_4_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TAG_GPU_4_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TAG_GPU_4_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TAG_GPU_4_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TEMPERATURE_GPU_4_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TEMPERATURE_GPU_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TEMPERATURE_GPU_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_GPU_4_DTEMP_TEMPERATURE_GPU_4_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_GPU_4_RESETVAL                   (0x00000000U)

/* DTEMP_CORE_0 */

#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TAG_CORE_0_MASK     (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TAG_CORE_0_SHIFT    (10U)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TAG_CORE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TAG_CORE_0_MAX      (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TEMPERATURE_CORE_0_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TEMPERATURE_CORE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TEMPERATURE_CORE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_0_DTEMP_TEMPERATURE_CORE_0_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_0_RESETVAL                  (0x00000000U)

/* DTEMP_CORE_1 */

#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TAG_CORE_1_MASK     (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TAG_CORE_1_SHIFT    (10U)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TAG_CORE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TAG_CORE_1_MAX      (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TEMPERATURE_CORE_1_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TEMPERATURE_CORE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TEMPERATURE_CORE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_1_DTEMP_TEMPERATURE_CORE_1_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_1_RESETVAL                  (0x00000000U)

/* DTEMP_CORE_2 */

#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TAG_CORE_2_MASK     (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TAG_CORE_2_SHIFT    (10U)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TAG_CORE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TAG_CORE_2_MAX      (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TEMPERATURE_CORE_2_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TEMPERATURE_CORE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TEMPERATURE_CORE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_2_DTEMP_TEMPERATURE_CORE_2_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_2_RESETVAL                  (0x00000000U)

/* DTEMP_CORE_3 */

#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TAG_CORE_3_MASK     (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TAG_CORE_3_SHIFT    (10U)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TAG_CORE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TAG_CORE_3_MAX      (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TEMPERATURE_CORE_3_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TEMPERATURE_CORE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TEMPERATURE_CORE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_3_DTEMP_TEMPERATURE_CORE_3_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_3_RESETVAL                  (0x00000000U)

/* DTEMP_CORE_4 */

#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TAG_CORE_4_MASK     (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TAG_CORE_4_SHIFT    (10U)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TAG_CORE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TAG_CORE_4_MAX      (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TEMPERATURE_CORE_4_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TEMPERATURE_CORE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TEMPERATURE_CORE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_CORE_4_DTEMP_TEMPERATURE_CORE_4_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_CORE_4_RESETVAL                  (0x00000000U)

/* SMA_SW_0 */

#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED2_MASK       (0xFFF80000U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED2_SHIFT      (19U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED2_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED2_MAX        (0x00001fffU)

#define CSL_CONTROL_CORE_SMA_SW_0_SATA_PLL_SOFT_RESET_MASK      (0x00040000U)
#define CSL_CONTROL_CORE_SMA_SW_0_SATA_PLL_SOFT_RESET_SHIFT     (18U)
#define CSL_CONTROL_CORE_SMA_SW_0_SATA_PLL_SOFT_RESET_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_0_SATA_PLL_SOFT_RESET_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED1_MASK       (0x0003FFFFU)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED1_SHIFT      (0U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED1_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_0_SMA_SW_0_RESERVED1_MAX        (0x0003ffffU)

#define CSL_CONTROL_CORE_SMA_SW_0_RESETVAL                      (0x00000000U)

/* MREQDOMAIN_EXP4 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_EXP4_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_EXP4_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_EXP4_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_EXP4_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP2_MDMA_MASK  (0x38000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP2_MDMA_SHIFT  (27U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP2_MDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP2_MDMA_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP1_MDMA_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP1_MDMA_SHIFT  (24U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP1_MDMA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_DSP1_MDMA_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_VPE_P1_MASK  (0x00E00000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_VPE_P1_SHIFT  (21U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_VPE_P1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_VPE_P1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_GMACSW_MASK  (0x001C0000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_GMACSW_SHIFT  (18U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_GMACSW_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_GMACSW_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU2_MASK   (0x00038000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU2_SHIFT  (15U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU2_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU1_MASK   (0x00007000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU1_SHIFT  (12U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MMU1_MAX    (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS2_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS2_SHIFT  (9U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS1_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS1_SHIFT  (6U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_PCIESS1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MLB_MASK    (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MLB_SHIFT   (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MLB_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_MREQDOMAIN_MLB_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP4_RESETVAL               (0x00000000U)

/* MREQDOMAIN_EXP5 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EXP5_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EXP5_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EXP5_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EXP5_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE3_TC1_MASK  (0x38000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE3_TC1_SHIFT  (27U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE3_TC1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE3_TC1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE2_TC1_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE2_TC1_SHIFT  (24U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE2_TC1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE2_TC1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE1_TC1_MASK  (0x00E00000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE1_TC1_SHIFT  (21U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE1_TC1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_EVE1_TC1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS2_PRU1_MASK  (0x001C0000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS2_PRU1_SHIFT  (18U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS2_PRU1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS2_PRU1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS1_PRU1_MASK  (0x00038000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS1_PRU1_SHIFT  (15U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS1_PRU1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_PRUSS1_PRU1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_GPU_P2_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_GPU_P2_SHIFT  (12U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_GPU_P2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_GPU_P2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VPE_P2_MASK  (0x00000E00U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VPE_P2_SHIFT  (9U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VPE_P2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VPE_P2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP3_P2_MASK  (0x000001C0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP3_P2_SHIFT  (6U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP3_P2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP3_P2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP2_P2_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP2_P2_SHIFT  (3U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP2_P2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP2_P2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP1_P2_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP1_P2_SHIFT  (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP1_P2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_MREQDOMAIN_VIP1_P2_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP5_RESETVAL               (0x00000000U)

/* L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2 */

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_CFG_SECDBG_EN_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_CFG_SECDBG_EN_SHIFT  (13U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_CFG_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_CFG_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_SL2IF_SECDBG_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_SL2IF_SECDBG_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_SL2IF_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_IVA2_SL2IF_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_TSC_ADC_SECDBG_EN_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_TSC_ADC_SECDBG_EN_SHIFT  (11U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_TSC_ADC_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SPARE_TSC_ADC_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TPCC_SECDBG_EN_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TPCC_SECDBG_EN_SHIFT  (10U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TPCC_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TPCC_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TC_SECDBG_EN_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TC_SECDBG_EN_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TC_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_EDMA_TC_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_QSPI_SECDBG_EN_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_QSPI_SECDBG_EN_SHIFT  (8U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_QSPI_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_QSPI_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS2_SECDBG_EN_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS2_SECDBG_EN_SHIFT  (7U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS1_SECDBG_EN_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS1_SECDBG_EN_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_PRUSS1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_2_SECDBG_EN_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_2_SECDBG_EN_SHIFT  (5U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_1_SECDBG_EN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_1_SECDBG_EN_SHIFT  (4U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_SHA2MD5_1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM3_SECDBG_EN_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM3_SECDBG_EN_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM3_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM3_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM2_SECDBG_EN_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM2_SECDBG_EN_SHIFT  (2U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_L3RAM2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP2_SECDBG_EN_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP2_SECDBG_EN_SHIFT  (1U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP2_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP2_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP1_SECDBG_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP1_SECDBG_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP1_SECDBG_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_DSP1_SECDBG_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_DBG_2_RESETVAL  (0x00000000U)

/* L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2 */

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_CFG_SECLOCK_EN_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_CFG_SECLOCK_EN_SHIFT  (13U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_CFG_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_CFG_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_SL2IF_SECLOCK_EN_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_SL2IF_SECLOCK_EN_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_SL2IF_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_IVA2_SL2IF_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_TSC_ADC_SECLOCK_EN_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_TSC_ADC_SECLOCK_EN_SHIFT  (11U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_TSC_ADC_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SPARE_TSC_ADC_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TPCC_SECLOCK_EN_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TPCC_SECLOCK_EN_SHIFT  (10U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TPCC_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TPCC_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TC_SECLOCK_EN_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TC_SECLOCK_EN_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TC_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_EDMA_TC_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_QSPI_SECLOCK_EN_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_QSPI_SECLOCK_EN_SHIFT  (8U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_QSPI_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_QSPI_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS2_SECLOCK_EN_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS2_SECLOCK_EN_SHIFT  (7U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS1_SECLOCK_EN_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS1_SECLOCK_EN_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_PRUSS1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_2_SECLOCK_EN_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_2_SECLOCK_EN_SHIFT  (5U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_1_SECLOCK_EN_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_1_SECLOCK_EN_SHIFT  (4U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_SHA2MD5_1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM3_SECLOCK_EN_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM3_SECLOCK_EN_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM3_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM3_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM2_SECLOCK_EN_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM2_SECLOCK_EN_SHIFT  (2U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_L3RAM2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP2_SECLOCK_EN_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP2_SECLOCK_EN_SHIFT  (1U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP2_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP2_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP1_SECLOCK_EN_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP1_SECLOCK_EN_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP1_SECLOCK_EN_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_DSP1_SECLOCK_EN_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_L3_HW_FW_EXPORTED_VALUES_CONF_LOCK_2_RESETVAL  (0x00003fffU)

/* SEC_ERR_STATUS_FUNC_2 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC1_EDMA_FW_ERROR_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC1_EDMA_FW_ERROR_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC1_EDMA_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC1_EDMA_FW_ERROR_EDMA_TC1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC1_EDMA_FW_ERROR_NO_EDMA_TC1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_CFG_FW_ERROR_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_CFG_FW_ERROR_SHIFT  (25U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_CFG_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_CFG_FW_ERROR_SPARE_IVA2_CFG_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_CFG_FW_ERROR_NO_SPARE_IVA2_CFG_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_SL2IF_FW_ERROR_SHIFT  (24U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_SL2IF_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_SL2IF_FW_ERROR_SPARE_IVA2_SL2IF_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_IVA2_SL2IF_FW_ERROR_NO_SPARE_IVA2_SL2IF_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_TSC_ADC_FW_ERROR_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_TSC_ADC_FW_ERROR_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_TSC_ADC_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_TSC_ADC_FW_ERROR_SPARE_TSC_ADC_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SPARE_TSC_ADC_FW_ERROR_NO_SPARE_TSC_ADC_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_QSPI_FW_ERROR_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_QSPI_FW_ERROR_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_QSPI_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_QSPI_FW_ERROR_QSPI_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_QSPI_FW_ERROR_NO_QSPI_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS2_FW_ERROR_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS2_FW_ERROR_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS2_FW_ERROR_PRUSS2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS2_FW_ERROR_NO_PRUSS2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS1_FW_ERROR_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS1_FW_ERROR_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS1_FW_ERROR_PRUSS1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PRUSS1_FW_ERROR_NO_PRUSS1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_2_FW_ERROR_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_2_FW_ERROR_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_2_FW_ERROR_SHA2MD5_2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_2_FW_ERROR_NO_SHA2MD5_2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_1_FW_ERROR_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_1_FW_ERROR_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_1_FW_ERROR_SHA2MD5_1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_SHA2MD5_1_FW_ERROR_NO_SHA2MD5_1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TPCC_EDMA_FW_ERROR_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TPCC_EDMA_FW_ERROR_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TPCC_EDMA_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TPCC_EDMA_FW_ERROR_EDMA_TPCC_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TPCC_EDMA_FW_ERROR_NO_EDMA_TPCC_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC0_EDMA_FW_ERROR_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC0_EDMA_FW_ERROR_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC0_EDMA_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC0_EDMA_FW_ERROR_EDMA_TC0_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_TC0_EDMA_FW_ERROR_NO_EDMA_TC0_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES2_FW_ERROR_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES2_FW_ERROR_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES2_FW_ERROR_AES2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES2_FW_ERROR_NO_AES2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES1_FW_ERROR_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES1_FW_ERROR_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES1_FW_ERROR_AES1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_AES1_FW_ERROR_NO_AES1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP3_FW_ERROR_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP3_FW_ERROR_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP3_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP3_FW_ERROR_MCASP3_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP3_FW_ERROR_NO_MCASP3_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP2_FW_ERROR_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP2_FW_ERROR_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP2_FW_ERROR_MCASP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP2_FW_ERROR_NO_MCASP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP1_FW_ERROR_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP1_FW_ERROR_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP1_FW_ERROR_MCASP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_MCASP1_FW_ERROR_NO_MCASP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP2_FW_ERROR_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP2_FW_ERROR_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP2_FW_ERROR_VCP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP2_FW_ERROR_NO_VCP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP1_FW_ERROR_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP1_FW_ERROR_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP1_FW_ERROR_VCP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_VCP1_FW_ERROR_NO_VCP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS2_FW_ERROR_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS2_FW_ERROR_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS2_FW_ERROR_PCIESS2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS2_FW_ERROR_NO_PCIESS2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS1_FW_ERROR_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS1_FW_ERROR_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS1_FW_ERROR_PCIESS1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_PCIESS1_FW_ERROR_NO_PCIESS1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_IPU2_FW_ERROR_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_IPU2_FW_ERROR_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_IPU2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_IPU2_FW_ERROR_IPU2_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_IPU2_FW_ERROR_NO_IPU2_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH3_FW_ERROR_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH3_FW_ERROR_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH3_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH3_FW_ERROR_L4PERIPH3_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH3_FW_ERROR_NO_L4PERIPH3_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH2_FW_ERROR_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH2_FW_ERROR_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH2_FW_ERROR_L4PERIPH2_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L4_PERIPH2_FW_ERROR_NO_L4PERIPH2_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM3_FW_ERROR_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM3_FW_ERROR_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM3_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM3_FW_ERROR_L3RAM3_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM3_FW_ERROR_NO_L3RAM3_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM2_FW_ERROR_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM2_FW_ERROR_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM2_FW_ERROR_L3RAM2_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_L3RAM2_FW_ERROR_NO_L3RAM2_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP2_FW_ERROR_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP2_FW_ERROR_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP2_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP2_FW_ERROR_DSP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP2_FW_ERROR_NO_DSP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP1_FW_ERROR_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP1_FW_ERROR_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP1_FW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP1_FW_ERROR_DSP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_DSP1_FW_ERROR_NO_DSP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_2_RESETVAL         (0x00000000U)

/* SEC_ERR_STATUS_FUNC_MASK_DISABLE_2 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC1_EDMA_FW_ERROR_MASK_DISABLE_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC1_EDMA_FW_ERROR_MASK_DISABLE_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC1_EDMA_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC1_EDMA_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC1_EDMA_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_CFG_FW_ERROR_MASK_DISABLE_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_CFG_FW_ERROR_MASK_DISABLE_SHIFT  (25U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_CFG_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_CFG_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_CFG_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK_DISABLE_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK_DISABLE_SHIFT  (24U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_IVA2_SL2IF_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_TSC_ADC_FW_ERROR_MASK_DISABLE_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_TSC_ADC_FW_ERROR_MASK_DISABLE_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_TSC_ADC_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_TSC_ADC_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SPARE_TSC_ADC_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_QSPI_FW_ERROR_MASK_DISABLE_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_QSPI_FW_ERROR_MASK_DISABLE_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_QSPI_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_QSPI_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_QSPI_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS2_FW_ERROR_MASK_DISABLE_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS2_FW_ERROR_MASK_DISABLE_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS1_FW_ERROR_MASK_DISABLE_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS1_FW_ERROR_MASK_DISABLE_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PRUSS1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_2_FW_ERROR_MASK_DISABLE_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_2_FW_ERROR_MASK_DISABLE_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_1_FW_ERROR_MASK_DISABLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_1_FW_ERROR_MASK_DISABLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_SHA2MD5_1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TPCC_EDMA_FW_ERROR_MASK_DISABLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TPCC_EDMA_FW_ERROR_MASK_DISABLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TPCC_EDMA_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TPCC_EDMA_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TPCC_EDMA_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC0_EDMA_FW_ERROR_MASK_DISABLE_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC0_EDMA_FW_ERROR_MASK_DISABLE_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC0_EDMA_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC0_EDMA_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_TC0_EDMA_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES2_FW_ERROR_MASK_DISABLE_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES2_FW_ERROR_MASK_DISABLE_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES1_FW_ERROR_MASK_DISABLE_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES1_FW_ERROR_MASK_DISABLE_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_AES1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP3_FW_ERROR_MASK_DISABLE_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP3_FW_ERROR_MASK_DISABLE_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP3_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP3_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP3_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP2_FW_ERROR_MASK_DISABLE_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP2_FW_ERROR_MASK_DISABLE_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP1_FW_ERROR_MASK_DISABLE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP1_FW_ERROR_MASK_DISABLE_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_MCASP1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP2_FW_ERROR_MASK_DISABLE_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP2_FW_ERROR_MASK_DISABLE_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP1_FW_ERROR_MASK_DISABLE_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP1_FW_ERROR_MASK_DISABLE_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_VCP1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS2_FW_ERROR_MASK_DISABLE_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS2_FW_ERROR_MASK_DISABLE_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS1_FW_ERROR_MASK_DISABLE_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS1_FW_ERROR_MASK_DISABLE_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_PCIESS1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_IPU2_FW_ERROR_MASK_DISABLE_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_IPU2_FW_ERROR_MASK_DISABLE_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_IPU2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_IPU2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_IPU2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH3_FW_ERROR_MASK_DISABLE_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH3_FW_ERROR_MASK_DISABLE_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH3_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH3_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH3_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH2_FW_ERROR_MASK_DISABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH2_FW_ERROR_MASK_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L4_PERIPH2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM3_FW_ERROR_MASK_DISABLE_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM3_FW_ERROR_MASK_DISABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM3_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM3_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM3_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM2_FW_ERROR_MASK_DISABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM2_FW_ERROR_MASK_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_L3RAM2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP2_FW_ERROR_MASK_DISABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP2_FW_ERROR_MASK_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP2_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP2_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP2_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP1_FW_ERROR_MASK_DISABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP1_FW_ERROR_MASK_DISABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP1_FW_ERROR_MASK_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP1_FW_ERROR_MASK_DISABLE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_DSP1_FW_ERROR_MASK_DISABLE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_FUNC_MASK_DISABLE_2_RESETVAL  (0x07ffffffU)

/* SEC_ERR_STATUS_DEBUG_2 */

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC1_EDMA_DBGFW_ERROR_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC1_EDMA_DBGFW_ERROR_SHIFT  (26U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC1_EDMA_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC1_EDMA_DBGFW_ERROR_EDMA_TC1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC1_EDMA_DBGFW_ERROR_NO_EDMA_TC1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_CFG_DBGFW_ERROR_MASK  (0x02000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_CFG_DBGFW_ERROR_SHIFT  (25U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_CFG_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_CFG_DBGFW_ERROR_SPARE_IVA2_CFG_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_CFG_DBGFW_ERROR_NO_SPARE_IVA2_CFG_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_SL2IF_DBGFW_ERROR_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_SL2IF_DBGFW_ERROR_SHIFT  (24U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_SL2IF_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_SL2IF_DBGFW_ERROR_SPARE_IVA2_SL2IF_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_IVA2_SL2IF_DBGFW_ERROR_NO_SPARE_IVA2_SL2IF_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_TSC_ADC_DBGFW_ERROR_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_TSC_ADC_DBGFW_ERROR_SHIFT  (23U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_TSC_ADC_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_TSC_ADC_DBGFW_ERROR_SPARE_TSC_ADC_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SPARE_TSC_ADC_DBGFW_ERROR_NO_SPARE_TSC_ADC_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_QSPI_DBGFW_ERROR_MASK  (0x00400000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_QSPI_DBGFW_ERROR_SHIFT  (22U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_QSPI_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_QSPI_DBGFW_ERROR_QSPI_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_QSPI_DBGFW_ERROR_NO_QSPI_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS2_DBGFW_ERROR_MASK  (0x00200000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS2_DBGFW_ERROR_SHIFT  (21U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS2_DBGFW_ERROR_PRUSS2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS2_DBGFW_ERROR_NO_PRUSS2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS1_DBGFW_ERROR_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS1_DBGFW_ERROR_SHIFT  (20U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS1_DBGFW_ERROR_PRUSS1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PRUSS1_DBGFW_ERROR_NO_PRUSS1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_2_DBGFW_ERROR_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_2_DBGFW_ERROR_SHIFT  (19U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_2_DBGFW_ERROR_SHA2MD5_2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_2_DBGFW_ERROR_NO_SHA2MD5_2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_1_DBGFW_ERROR_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_1_DBGFW_ERROR_SHIFT  (18U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_1_DBGFW_ERROR_SHA2MD5_1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_SHA2MD5_1_DBGFW_ERROR_NO_SHA2MD5_1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TPCC_EDMA_DBGFW_ERROR_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TPCC_EDMA_DBGFW_ERROR_SHIFT  (17U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TPCC_EDMA_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TPCC_EDMA_DBGFW_ERROR_EDMA_TPCC_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TPCC_EDMA_DBGFW_ERROR_NO_EDMA_TPCC_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC0_EDMA_DBGFW_ERROR_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC0_EDMA_DBGFW_ERROR_SHIFT  (16U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC0_EDMA_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC0_EDMA_DBGFW_ERROR_EDMA_TC0_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_TC0_EDMA_DBGFW_ERROR_NO_EDMA_TC0_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES2_DBGFW_ERROR_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES2_DBGFW_ERROR_SHIFT  (15U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES2_DBGFW_ERROR_AES2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES2_DBGFW_ERROR_NO_AES2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES1_DBGFW_ERROR_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES1_DBGFW_ERROR_SHIFT  (14U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES1_DBGFW_ERROR_AES1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_AES1_DBGFW_ERROR_NO_AES1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP3_DBGFW_ERROR_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP3_DBGFW_ERROR_SHIFT  (13U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP3_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP3_DBGFW_ERROR_MCASP3_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP3_DBGFW_ERROR_NO_MCASP3_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP2_DBGFW_ERROR_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP2_DBGFW_ERROR_SHIFT  (12U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP2_DBGFW_ERROR_MCASP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP2_DBGFW_ERROR_NO_MCASP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP1_DBGFW_ERROR_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP1_DBGFW_ERROR_SHIFT  (11U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP1_DBGFW_ERROR_MCASP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_MCASP1_DBGFW_ERROR_NO_MCASP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP2_DBGFW_ERROR_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP2_DBGFW_ERROR_SHIFT  (10U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP2_DBGFW_ERROR_VCP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP2_DBGFW_ERROR_NO_VCP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP1_DBGFW_ERROR_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP1_DBGFW_ERROR_SHIFT  (9U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP1_DBGFW_ERROR_VCP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_VCP1_DBGFW_ERROR_NO_VCP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS2_DBGFW_ERROR_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS2_DBGFW_ERROR_SHIFT  (8U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS2_DBGFW_ERROR_PCIESS2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS2_DBGFW_ERROR_NO_PCIESS2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS1_DBGFW_ERROR_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS1_DBGFW_ERROR_SHIFT  (7U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS1_DBGFW_ERROR_PCIESS1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_PCIESS1_DBGFW_ERROR_NO_PCIESS1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_IPU2_DBGFW_ERROR_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_IPU2_DBGFW_ERROR_SHIFT  (6U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_IPU2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_IPU2_DBGFW_ERROR_IPU2_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_IPU2_DBGFW_ERROR_NO_IPU2_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH3_DBGFW_ERROR_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH3_DBGFW_ERROR_SHIFT  (5U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH3_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH3_DBGFW_ERROR_L4PERIPH3_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH3_DBGFW_ERROR_NO_L4PERIPH3_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH2_DBGFW_ERROR_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH2_DBGFW_ERROR_SHIFT  (4U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH2_DBGFW_ERROR_L4PERIPH2_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L4_PERIPH2_DBGFW_ERROR_NO_L4PERIPH2_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM3_DBGFW_ERROR_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM3_DBGFW_ERROR_SHIFT  (3U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM3_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM3_DBGFW_ERROR_L3RAM3_INIT_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM3_DBGFW_ERROR_NO_L3RAM3_INIT_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM2_DBGFW_ERROR_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM2_DBGFW_ERROR_SHIFT  (2U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM2_DBGFW_ERROR_L3RAM2_TARGET_FW_ERR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_L3RAM2_DBGFW_ERROR_NO_L3RAM2_TARGET_FW_ERR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP2_DBGFW_ERROR_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP2_DBGFW_ERROR_SHIFT  (1U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP2_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP2_DBGFW_ERROR_DSP2_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP2_DBGFW_ERROR_NO_DSP2_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP1_DBGFW_ERROR_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP1_DBGFW_ERROR_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP1_DBGFW_ERROR_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP1_DBGFW_ERROR_DSP1_FW_ERROR  (0x00000001U)
#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_DSP1_DBGFW_ERROR_NO_DSP1_FW_ERROR  (0x00000000U)

#define CSL_CONTROL_CORE_SEC_ERR_STATUS_DEBUG_2_RESETVAL        (0x00000000U)

/* EMIF_INITIATOR_PRIORITY_1 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_MPU_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_MPU_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_MPU_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_MPU_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_MPU_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_CS_DAP_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_CS_DAP_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_CS_DAP_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_CS_DAP_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_CS_DAP_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_IEEE1500_2_OCP_EMIF_PRIORITY_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_IEEE1500_2_OCP_EMIF_PRIORITY_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_IEEE1500_2_OCP_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_IEEE1500_2_OCP_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_IEEE1500_2_OCP_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_MDMA_EMIF_PRIORITY_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_MDMA_EMIF_PRIORITY_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_MDMA_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_MDMA_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_MDMA_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_CFG_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_CFG_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_CFG_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_CFG_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_CFG_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_EDMA_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_EDMA_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_EDMA_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_EDMA_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP1_EDMA_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_EDMA_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_EDMA_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_EDMA_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_EDMA_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_EDMA_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_CFG_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_CFG_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_CFG_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_CFG_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_DSP2_CFG_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_1_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_2 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_DSP2_MDMA_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_DSP2_MDMA_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_DSP2_MDMA_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_DSP2_MDMA_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_DSP2_MDMA_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT1_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT1_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT2_EMIF_PRIORITY_RESERVED_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT2_EMIF_PRIORITY_RESERVED_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT2_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_IVA_ICONT2_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE1_TC0_EMIF_PRIORITY_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE1_TC0_EMIF_PRIORITY_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE1_TC0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE1_TC0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE1_TC0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE2_TC0_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE2_TC0_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE2_TC0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE2_TC0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE2_TC0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE3_TC0_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE3_TC0_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE3_TC0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE3_TC0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE3_TC0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE4_TC0_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE4_TC0_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE4_TC0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE4_TC0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_EVE4_TC0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_PRUSS1_PRU0_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_PRUSS1_PRU0_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_PRUSS1_PRU0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_PRUSS1_PRU0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_PRUSS1_PRU0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_2_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_3 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS1_PRU1_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS1_PRU1_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS1_PRU1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS1_PRU1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS1_PRU1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU0_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU0_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU1_EMIF_PRIORITY_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU1_EMIF_PRIORITY_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_PRUSS2_PRU1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU1_EMIF_PRIORITY_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU1_EMIF_PRIORITY_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU2_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU2_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_IPU2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_SYSTEM_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_SYSTEM_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_SYSTEM_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_SYSTEM_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_SYSTEM_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_CRYPTO_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_CRYPTO_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_CRYPTO_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_CRYPTO_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_DMA_CRYPTO_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_EDMA_TC0_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_EDMA_TC0_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_EDMA_TC0_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_EDMA_TC0_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_EDMA_TC0_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_3_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_4 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_EDMA_TC1_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_EDMA_TC1_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_EDMA_TC1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_EDMA_TC1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_EDMA_TC1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_DSS_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_DSS_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_DSS_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_DSS_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_DSS_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_MLB_MMU1_EMIF_PRIORITY_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_MLB_MMU1_EMIF_PRIORITY_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_MLB_MMU1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_MLB_MMU1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_MLB_MMU1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS1_EMIF_PRIORITY_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS1_EMIF_PRIORITY_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS2_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS2_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_PCIESS2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP1_P1_P2_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP1_P1_P2_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP1_P1_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP1_P1_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP1_P1_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP2_P1_P2_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP2_P1_P2_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP2_P1_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP2_P1_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP2_P1_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP3_P1_P2_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP3_P1_P2_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP3_P1_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP3_P1_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_VIP3_P1_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_4_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_5 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_VPE_P1_P2_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_VPE_P1_P2_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_VPE_P1_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_VPE_P1_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_VPE_P1_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC1_GPU_P1_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC1_GPU_P1_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC1_GPU_P1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC1_GPU_P1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC1_GPU_P1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC2_GPU_P2_EMIF_PRIORITY_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC2_GPU_P2_EMIF_PRIORITY_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC2_GPU_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC2_GPU_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_MMC2_GPU_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_BB2D_P1_P2_EMIF_PRIORITY_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_BB2D_P1_P2_EMIF_PRIORITY_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_BB2D_P1_P2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_BB2D_P1_P2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_BB2D_P1_P2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_GMAC_SW_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_GMAC_SW_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_GMAC_SW_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_GMAC_SW_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_GMAC_SW_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB1_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB1_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB2_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB2_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB3_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB3_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB3_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB3_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_USB3_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_5_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_6 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_USB4_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_USB4_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_USB4_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_USB4_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_USB4_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_1_EMIF_PRIORITY_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_1_EMIF_PRIORITY_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_2_EMIF_PRIORITY_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_2_EMIF_PRIORITY_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_2_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_2_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_CSI2_2_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SPARE_IVA2_SMSET_EMIF_PRIORITY_RESERVED_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SPARE_IVA2_SMSET_EMIF_PRIORITY_RESERVED_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SPARE_IVA2_SMSET_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SPARE_IVA2_SMSET_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SATA_EMIF_PRIORITY_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SATA_EMIF_PRIORITY_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SATA_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SATA_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_SATA_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE1_TC1_EMIF_PRIORITY_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE1_TC1_EMIF_PRIORITY_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE1_TC1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE1_TC1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE1_TC1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE2_TC1_EMIF_PRIORITY_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE2_TC1_EMIF_PRIORITY_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE2_TC1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE2_TC1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE2_TC1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE3_TC1_EMIF_PRIORITY_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE3_TC1_EMIF_PRIORITY_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE3_TC1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE3_TC1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_EVE3_TC1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_6_RESETVAL     (0x44444444U)

/* EMIF_INITIATOR_PRIORITY_7 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_EVE4_TC1_EMIF_PRIORITY_MASK  (0x70000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_EVE4_TC1_EMIF_PRIORITY_SHIFT  (28U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_EVE4_TC1_EMIF_PRIORITY_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_EVE4_TC1_EMIF_PRIORITY_HIGHESTPRIORITY  (0x00000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_EVE4_TC1_EMIF_PRIORITY_LOWESTPRIORITY  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PERF_PROBE_EMIF_PRIORITY_RESERVED_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PERF_PROBE_EMIF_PRIORITY_RESERVED_SHIFT  (24U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PERF_PROBE_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PERF_PROBE_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_OCP_WP_EMIF_PRIORITY_RESERVED_MASK  (0x00700000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_OCP_WP_EMIF_PRIORITY_RESERVED_SHIFT  (20U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_OCP_WP_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_OCP_WP_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_DMA_PROFILING_EMIF_PRIORITY_RESERVED_MASK  (0x00070000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_DMA_PROFILING_EMIF_PRIORITY_RESERVED_SHIFT  (16U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_DMA_PROFILING_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_DMA_PROFILING_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_SYS_EVENT_EMIF_PRIORITY_RESERVED_MASK  (0x00007000U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_SYS_EVENT_EMIF_PRIORITY_RESERVED_SHIFT  (12U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_SYS_EVENT_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_SYS_EVENT_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_IVA_SMSET_EMIF_PRIORITY_RESERVED_MASK  (0x00000700U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_IVA_SMSET_EMIF_PRIORITY_RESERVED_SHIFT  (8U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_IVA_SMSET_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_IVA_SMSET_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PM_PROFILING_EMIF_PRIORITY_RESERVED_MASK  (0x00000070U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PM_PROFILING_EMIF_PRIORITY_RESERVED_SHIFT  (4U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PM_PROFILING_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_PM_PROFILING_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_CM_CORE_AON_PROFILING_EMIF_PRIORITY_RESERVED_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_CM_CORE_AON_PROFILING_EMIF_PRIORITY_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_CM_CORE_AON_PROFILING_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_CM_CORE_AON_PROFILING_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_7_RESETVAL     (0x44444444U)

/* L3_INITIATOR_PRESSURE_1 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_MPU_L3_PRESSURE_MASK  (0x0C000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_MPU_L3_PRESSURE_SHIFT  (26U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_MPU_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_MPU_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_MPU_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP1_CFG_L3_PRESSURE_MASK  (0x00060000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP1_CFG_L3_PRESSURE_SHIFT  (17U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP1_CFG_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP1_CFG_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP1_CFG_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP2_CFG_L3_PRESSURE_MASK  (0x00000600U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP2_CFG_L3_PRESSURE_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP2_CFG_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP2_CFG_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_DSP2_CFG_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_1_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_2 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_1_L3_PRESSURE_MASK  (0x000C0000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_1_L3_PRESSURE_SHIFT  (18U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_2_L3_PRESSURE_MASK  (0x00018000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_2_L3_PRESSURE_SHIFT  (15U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_2_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_2_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_CSI2_2_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU1_L3_PRESSURE_MASK  (0x00003000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU1_L3_PRESSURE_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU2_L3_PRESSURE_MASK  (0x00000600U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU2_L3_PRESSURE_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU2_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU2_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_IPU2_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU0_L3_PRESSURE_MASK  (0x000000C0U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU0_L3_PRESSURE_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU0_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU0_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU0_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU1_L3_PRESSURE_MASK  (0x00000018U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU1_L3_PRESSURE_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS1_PRU1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS2_PRU0_L3_PRESSURE_MASK  (0x00000003U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS2_PRU0_L3_PRESSURE_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS2_PRU0_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS2_PRU0_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_PRUSS2_PRU0_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_2_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_3 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_PRUSS2_PRU1_L3_PRESSURE_MASK  (0x0C000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_PRUSS2_PRU1_L3_PRESSURE_SHIFT  (26U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_PRUSS2_PRU1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_PRUSS2_PRU1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_PRUSS2_PRU1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_3_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_4 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P1_L3_PRESSURE_MASK  (0x01800000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P1_L3_PRESSURE_SHIFT  (23U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P2_L3_PRESSURE_MASK  (0x00300000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P2_L3_PRESSURE_SHIFT  (20U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P2_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P2_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_GPU_P2_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_BB2D_L3_PRESSURE_RESERVED_MASK  (0x00060000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_BB2D_L3_PRESSURE_RESERVED_SHIFT  (17U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_BB2D_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_BB2D_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_RD_L3_PRESSURE_RESERVED_MASK  (0x00018000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_RD_L3_PRESSURE_RESERVED_SHIFT  (15U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_RD_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_RD_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_WR_L3_PRESSURE_RESERVED_MASK  (0x00003000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_WR_L3_PRESSURE_RESERVED_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_WR_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_DMA_SYSTEM_WR_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_4_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_5 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_RD_L3_PRESSURE_MASK  (0x01800000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_RD_L3_PRESSURE_SHIFT  (23U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_RD_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_RD_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_RD_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_WR_L3_PRESSURE_MASK  (0x00300000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_WR_L3_PRESSURE_SHIFT  (20U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_WR_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_WR_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_DMA_CRYPTO_WR_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_SATA_L3_PRESSURE_MASK  (0x00000018U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_SATA_L3_PRESSURE_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_SATA_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_SATA_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_SATA_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_MMC1_L3_PRESSURE_MASK  (0x00000003U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_MMC1_L3_PRESSURE_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_MMC1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_MMC1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_MMC1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_5_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_6 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_MMC2_L3_PRESSURE_MASK  (0x00060000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_MMC2_L3_PRESSURE_SHIFT  (17U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_MMC2_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_MMC2_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_MMC2_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB1_L3_PRESSURE_MASK  (0x00018000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB1_L3_PRESSURE_SHIFT  (15U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB1_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB1_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB1_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB2_L3_PRESSURE_MASK  (0x00003000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB2_L3_PRESSURE_SHIFT  (12U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB2_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB2_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB2_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB3_L3_PRESSURE_MASK  (0x00000600U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB3_L3_PRESSURE_SHIFT  (9U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB3_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB3_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB3_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB4_L3_PRESSURE_MASK  (0x000000C0U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB4_L3_PRESSURE_SHIFT  (6U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB4_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB4_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_USB4_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_CS_DAP_L3_PRESSURE_MASK  (0x00000018U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_CS_DAP_L3_PRESSURE_SHIFT  (3U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_CS_DAP_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_CS_DAP_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_CS_DAP_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_IEEE1500_2_OCP_L3_PRESSURE_MASK  (0x00000003U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_IEEE1500_2_OCP_L3_PRESSURE_SHIFT  (0U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_IEEE1500_2_OCP_L3_PRESSURE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_IEEE1500_2_OCP_L3_PRESSURE_LOWEST  (0x00000000U)
#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_IEEE1500_2_OCP_L3_PRESSURE_HIGHEST  (0x00000003U)

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_6_RESETVAL       (0x00000000U)

/* L3_INITIATOR_PRESSURE_7 */

#define CSL_CONTROL_CORE_L3_INITIATOR_PRESSURE_7_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0_STD_FUSE_OPP_VDD_IVA_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0_STD_FUSE_OPP_VDD_IVA_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0_STD_FUSE_OPP_VDD_IVA_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0_STD_FUSE_OPP_VDD_IVA_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_0_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1_STD_FUSE_OPP_VDD_IVA_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1_STD_FUSE_OPP_VDD_IVA_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1_STD_FUSE_OPP_VDD_IVA_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1_STD_FUSE_OPP_VDD_IVA_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_1_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2_STD_FUSE_OPP_VDD_IVA_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2_STD_FUSE_OPP_VDD_IVA_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2_STD_FUSE_OPP_VDD_IVA_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2_STD_FUSE_OPP_VDD_IVA_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_2_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3_STD_FUSE_OPP_VDD_IVA_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3_STD_FUSE_OPP_VDD_IVA_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3_STD_FUSE_OPP_VDD_IVA_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3_STD_FUSE_OPP_VDD_IVA_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_3_RESETVAL        (0x00000000U)

/* STD_FUSE_OPP_VDD_IVA_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4_STD_FUSE_OPP_VDD_IVA_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4_STD_FUSE_OPP_VDD_IVA_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4_STD_FUSE_OPP_VDD_IVA_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4_STD_FUSE_OPP_VDD_IVA_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_IVA_4_RESETVAL        (0x00000000U)

/* LDOVBB_DSPEVE_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_LDOVBBDSPEVE_FBB_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOVBB_DSPEVE_VOLTAGE_CTRL_RESETVAL    (0x00000000U)

/* LDOVBB_IVA_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_LDOVBBIVA_FBB_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOVBB_IVA_VOLTAGE_CTRL_RESETVAL       (0x00000000U)

/* CUST_FUSE_UID_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_0_CUST_FUSE_UID_0_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_0_CUST_FUSE_UID_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_0_CUST_FUSE_UID_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_0_CUST_FUSE_UID_0_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_0_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_1 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_1_CUST_FUSE_UID_1_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_1_CUST_FUSE_UID_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_1_CUST_FUSE_UID_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_1_CUST_FUSE_UID_1_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_1_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_2 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_2_CUST_FUSE_UID_2_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_2_CUST_FUSE_UID_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_2_CUST_FUSE_UID_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_2_CUST_FUSE_UID_2_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_2_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_3 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_3_CUST_FUSE_UID_3_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_3_CUST_FUSE_UID_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_3_CUST_FUSE_UID_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_3_CUST_FUSE_UID_3_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_3_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_4 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_4_CUST_FUSE_UID_4_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_4_CUST_FUSE_UID_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_4_CUST_FUSE_UID_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_4_CUST_FUSE_UID_4_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_4_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_5 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_5_CUST_FUSE_UID_5_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_5_CUST_FUSE_UID_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_5_CUST_FUSE_UID_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_5_CUST_FUSE_UID_5_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_5_RESETVAL               (0x00000000U)

/* CUST_FUSE_UID_6 */

#define CSL_CONTROL_CORE_CUST_FUSE_UID_6_CUST_FUSE_UID_6_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_6_CUST_FUSE_UID_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_6_CUST_FUSE_UID_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_UID_6_CUST_FUSE_UID_6_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_UID_6_RESETVAL               (0x00000000U)

/* PCIE_ID_SW_0 */

#define CSL_CONTROL_CORE_PCIE_ID_SW_0_STD_FUSE_PCIE_ID_SW_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_PCIE_ID_SW_0_STD_FUSE_PCIE_ID_SW_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_PCIE_ID_SW_0_STD_FUSE_PCIE_ID_SW_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PCIE_ID_SW_0_STD_FUSE_PCIE_ID_SW_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_PCIE_ID_SW_0_RESETVAL                  (0x00000000U)

/* CUST_FUSE_PCIE_ID_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0_CUST_FUSE_PCIE_ID_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0_CUST_FUSE_PCIE_ID_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0_CUST_FUSE_PCIE_ID_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0_CUST_FUSE_PCIE_ID_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_PCIE_ID_0_RESETVAL           (0x00000000U)

/* USB_ID_SW_0 */

#define CSL_CONTROL_CORE_USB_ID_SW_0_STD_FUSE_USB_ID_SW_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_USB_ID_SW_0_STD_FUSE_USB_ID_SW_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_USB_ID_SW_0_STD_FUSE_USB_ID_SW_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_USB_ID_SW_0_STD_FUSE_USB_ID_SW_0_MAX   (0xffffffffU)

#define CSL_CONTROL_CORE_USB_ID_SW_0_RESETVAL                   (0x00000000U)

/* CUST_FUSE_USB_ID_0 */

#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0_CUST_FUSE_USB_ID_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0_CUST_FUSE_USB_ID_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0_CUST_FUSE_USB_ID_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0_CUST_FUSE_USB_ID_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_USB_ID_0_RESETVAL            (0x00000000U)

/* MAC_ID_SW_0 */

#define CSL_CONTROL_CORE_MAC_ID_SW_0_STD_FUSE_MAC_ID_SW_0_MASK  (0x01FFFFFFU)
#define CSL_CONTROL_CORE_MAC_ID_SW_0_STD_FUSE_MAC_ID_SW_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_MAC_ID_SW_0_STD_FUSE_MAC_ID_SW_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MAC_ID_SW_0_STD_FUSE_MAC_ID_SW_0_MAX   (0x01ffffffU)

#define CSL_CONTROL_CORE_MAC_ID_SW_0_RESETVAL                   (0x00000000U)

/* MAC_ID_SW_1 */

#define CSL_CONTROL_CORE_MAC_ID_SW_1_STD_FUSE_MAC_ID_SW_1_MASK  (0x01FFFFFFU)
#define CSL_CONTROL_CORE_MAC_ID_SW_1_STD_FUSE_MAC_ID_SW_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_MAC_ID_SW_1_STD_FUSE_MAC_ID_SW_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MAC_ID_SW_1_STD_FUSE_MAC_ID_SW_1_MAX   (0x01ffffffU)

#define CSL_CONTROL_CORE_MAC_ID_SW_1_RESETVAL                   (0x00000000U)

/* MAC_ID_SW_2 */

#define CSL_CONTROL_CORE_MAC_ID_SW_2_STD_FUSE_MAC_ID_SW_2_MASK  (0x01FFFFFFU)
#define CSL_CONTROL_CORE_MAC_ID_SW_2_STD_FUSE_MAC_ID_SW_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_MAC_ID_SW_2_STD_FUSE_MAC_ID_SW_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MAC_ID_SW_2_STD_FUSE_MAC_ID_SW_2_MAX   (0x01ffffffU)

#define CSL_CONTROL_CORE_MAC_ID_SW_2_RESETVAL                   (0x00000000U)

/* MAC_ID_SW_3 */

#define CSL_CONTROL_CORE_MAC_ID_SW_3_STD_FUSE_MAC_ID_SW_3_MASK  (0x01FFFFFFU)
#define CSL_CONTROL_CORE_MAC_ID_SW_3_STD_FUSE_MAC_ID_SW_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_MAC_ID_SW_3_STD_FUSE_MAC_ID_SW_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MAC_ID_SW_3_STD_FUSE_MAC_ID_SW_3_MAX   (0x01ffffffU)

#define CSL_CONTROL_CORE_MAC_ID_SW_3_RESETVAL                   (0x00000000U)

/* SW_ID_SW_0 */

#define CSL_CONTROL_CORE_SW_ID_SW_0_STD_FUSE_SW_ID_SW_0_MASK    (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SW_ID_SW_0_STD_FUSE_SW_ID_SW_0_SHIFT   (0U)
#define CSL_CONTROL_CORE_SW_ID_SW_0_STD_FUSE_SW_ID_SW_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SW_ID_SW_0_STD_FUSE_SW_ID_SW_0_MAX     (0xffffffffU)

#define CSL_CONTROL_CORE_SW_ID_SW_0_RESETVAL                    (0x00000000U)

/* SW_ID_SW_1 */

#define CSL_CONTROL_CORE_SW_ID_SW_1_STD_FUSE_SW_ID_SW_1_MASK    (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SW_ID_SW_1_STD_FUSE_SW_ID_SW_1_SHIFT   (0U)
#define CSL_CONTROL_CORE_SW_ID_SW_1_STD_FUSE_SW_ID_SW_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SW_ID_SW_1_STD_FUSE_SW_ID_SW_1_MAX     (0xffffffffU)

#define CSL_CONTROL_CORE_SW_ID_SW_1_RESETVAL                    (0x00000000U)

/* EFUSE_DISABLE_SW_0 */

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_STD_FUSE_EFUSE_DISABLE_SW_0_RESERVED_MASK  (0xFFF00000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_STD_FUSE_EFUSE_DISABLE_SW_0_RESERVED_SHIFT  (20U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_STD_FUSE_EFUSE_DISABLE_SW_0_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_STD_FUSE_EFUSE_DISABLE_SW_0_RESERVED_MAX  (0x00000fffU)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EMIF2_DISABLE_MASK  (0x00080000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EMIF2_DISABLE_SHIFT  (19U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EMIF2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EMIF2_DISABLE_MAX   (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IVA_DISABLE_MASK    (0x00040000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IVA_DISABLE_SHIFT   (18U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IVA_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IVA_DISABLE_MAX     (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO3_CLK_DISABLE_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO3_CLK_DISABLE_SHIFT  (17U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO3_CLK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO3_CLK_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO2_CLK_DISABLE_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO2_CLK_DISABLE_SHIFT  (16U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO2_CLK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO2_CLK_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO_CLK_DISABLE_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO_CLK_DISABLE_SHIFT  (15U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO_CLK_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSS_VIDEO_CLK_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP3_DISABLE_MASK   (0x00004000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP3_DISABLE_SHIFT  (14U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP3_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP3_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP2_DISABLE_MASK   (0x00002000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP2_DISABLE_SHIFT  (13U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VIP2_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_BB2D_DISABLE_MASK   (0x00001000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_BB2D_DISABLE_SHIFT  (12U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_BB2D_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_BB2D_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM3_DISABLE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM3_DISABLE_SHIFT  (11U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM3_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM3_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM2_DISABLE_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM2_DISABLE_SHIFT  (10U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM2_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM1_DISABLE_MASK  (0x00000200U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM1_DISABLE_SHIFT  (9U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM1_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_OCMC_RAM1_DISABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU1_BOOT_ENABLE_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU1_BOOT_ENABLE_SHIFT  (8U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU1_BOOT_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU1_BOOT_ENABLE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VPE_DISABLE_MASK    (0x00000080U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VPE_DISABLE_SHIFT   (7U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VPE_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_VPE_DISABLE_MAX     (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU2_DISABLE_MASK   (0x00000040U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU2_DISABLE_SHIFT  (6U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_IPU2_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE4_DISABLE_MASK   (0x00000020U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE4_DISABLE_SHIFT  (5U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE4_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE4_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE3_DISABLE_MASK   (0x00000010U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE3_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE3_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE3_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE2_DISABLE_MASK   (0x00000008U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE2_DISABLE_SHIFT  (3U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE2_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE1_DISABLE_MASK   (0x00000004U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE1_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE1_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_EVE1_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP2_DISABLE_MASK   (0x00000002U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP2_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP2_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP2_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP1_DISABLE_MASK   (0x00000001U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP1_DISABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP1_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_DSP1_DISABLE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_0_RESETVAL            (0x00000000U)

/* SLEW_SW_0 */

#define CSL_CONTROL_CORE_SLEW_SW_0_STD_FUSE_SLEW_SW_0_MASK      (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SLEW_SW_0_STD_FUSE_SLEW_SW_0_SHIFT     (0U)
#define CSL_CONTROL_CORE_SLEW_SW_0_STD_FUSE_SLEW_SW_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SLEW_SW_0_STD_FUSE_SLEW_SW_0_MAX       (0xffffffffU)

#define CSL_CONTROL_CORE_SLEW_SW_0_RESETVAL                     (0x00000000U)

/* SMA_SW_1 */

#define CSL_CONTROL_CORE_SMA_SW_1_SMA_SW_1_RESERVED_MASK        (0xFE000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_SMA_SW_1_RESERVED_SHIFT       (25U)
#define CSL_CONTROL_CORE_SMA_SW_1_SMA_SW_1_RESERVED_RESETVAL    (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_SMA_SW_1_RESERVED_MAX         (0x0000007fU)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_IPC_MASK              (0x01000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_IPC_SHIFT             (24U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_IPC_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_IPC_MAX               (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_IPC_MASK              (0x00800000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_IPC_SHIFT             (23U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_IPC_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_IPC_MAX               (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_IPC_MASK              (0x00400000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_IPC_SHIFT             (22U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_IPC_RESETVAL          (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_IPC_MAX               (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_ON_OFF_MASK           (0x00200000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_ON_OFF_SHIFT          (21U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_ON_OFF_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_ON_OFF_MAX            (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_ON_OFF_MASK           (0x00100000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_ON_OFF_SHIFT          (20U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_ON_OFF_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_ON_OFF_MAX            (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_ON_OFF_MASK           (0x00080000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_ON_OFF_SHIFT          (19U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_ON_OFF_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_ON_OFF_MAX            (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_RF_MASK               (0x00040000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_RF_SHIFT              (18U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_RF_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH2_RF_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_RF_MASK               (0x00020000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_RF_SHIFT              (17U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_RF_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH1_RF_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_RF_MASK               (0x00010000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_RF_SHIFT              (16U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_RF_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_DSS_CH0_RF_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_1A_MASK     (0x00000400U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_1A_SHIFT    (10U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_1A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_1A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_2A_MASK     (0x00000200U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_2A_SHIFT    (9U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_2A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP3_CLK_INV_PORT_2A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VPE_CLK_DIV_BY_2_EN_MASK      (0x00000100U)
#define CSL_CONTROL_CORE_SMA_SW_1_VPE_CLK_DIV_BY_2_EN_SHIFT     (8U)
#define CSL_CONTROL_CORE_SMA_SW_1_VPE_CLK_DIV_BY_2_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VPE_CLK_DIV_BY_2_EN_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2B_MASK     (0x00000080U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2B_SHIFT    (7U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2B_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2B_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1B_MASK     (0x00000040U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1B_SHIFT    (6U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1B_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1B_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2A_MASK     (0x00000020U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2A_SHIFT    (5U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_2A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1A_MASK     (0x00000010U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1A_SHIFT    (4U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP2_CLK_INV_PORT_1A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2B_MASK     (0x00000008U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2B_SHIFT    (3U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2B_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2B_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1B_MASK     (0x00000004U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1B_SHIFT    (2U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1B_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1B_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2A_MASK     (0x00000002U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2A_SHIFT    (1U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_2A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1A_MASK     (0x00000001U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1A_SHIFT    (0U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1A_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMA_SW_1_VIP1_CLK_INV_PORT_1A_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_SMA_SW_1_RESETVAL                      (0x00000000U)

/* DSS_PLL_CONTROL */

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_SDVENC_CLK_SELECTION_MASK  (0x00000600U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_SDVENC_CLK_SELECTION_SHIFT  (9U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_SDVENC_CLK_SELECTION_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_SDVENC_CLK_SELECTION_DPLL_VIDEO1_HSDIVIDER_CLKOUT3  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_SDVENC_CLK_SELECTION_HDMI_CLK  (0x00000000U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_MASK  (0x00000180U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_SHIFT  (7U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_DPLL_VIDEO1  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_DPLL_VIDEO2  (0x00000000U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_C_CLK1_SELECTION_DPLL_HDMI  (0x00000002U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_MASK  (0x00000060U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_SHIFT  (5U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_DPLL_VIDEO2  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_DPLL_ABE  (0x00000003U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_DPLL_VIDEO1  (0x00000000U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_B_CLK1_SELECTION_DPLL_HDMI  (0x00000002U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_A_CLK1_SELECTION_MASK  (0x00000018U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_A_CLK1_SELECTION_SHIFT  (3U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_A_CLK1_SELECTION_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_A_CLK1_SELECTION_DPLL_HDMI  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_DSI1_A_CLK1_SELECTION_DPLL_VIDEO1  (0x00000000U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_HDMI_DSS_CONTROL_DISABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_HDMI_DSS_CONTROL_DISABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_HDMI_DSS_CONTROL_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_HDMI_DSS_CONTROL_DISABLE_PLLDISABLED  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_HDMI_DSS_CONTROL_DISABLE_PLLENABLED  (0x00000000U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO2_DSS_CONTROL_DISABLE_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO2_DSS_CONTROL_DISABLE_SHIFT  (1U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO2_DSS_CONTROL_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO2_DSS_CONTROL_DISABLE_PLLDISABLED  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO2_DSS_CONTROL_DISABLE_PLLENABLED  (0x00000000U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO1_DSS_CONTROL_DISABLE_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO1_DSS_CONTROL_DISABLE_SHIFT  (0U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO1_DSS_CONTROL_DISABLE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO1_DSS_CONTROL_DISABLE_PLLDISABLED  (0x00000001U)
#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_PLL_VIDEO1_DSS_CONTROL_DISABLE_PLLENABLED  (0x00000000U)

#define CSL_CONTROL_CORE_DSS_PLL_CONTROL_RESETVAL               (0x000002afU)

/* EMIF_INITIATOR_PRIORITY_8 */

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8_CM_CORE_PROFILING_EMIF_PRIORITY_RESERVED_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8_CM_CORE_PROFILING_EMIF_PRIORITY_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8_CM_CORE_PROFILING_EMIF_PRIORITY_RESERVED_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8_CM_CORE_PROFILING_EMIF_PRIORITY_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_EMIF_INITIATOR_PRIORITY_8_RESETVAL     (0x00000004U)

/* MMR_LOCK_1 */

#define CSL_CONTROL_CORE_MMR_LOCK_1_MMR_LOCK_1_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MMR_LOCK_1_MMR_LOCK_1_SHIFT            (0U)
#define CSL_CONTROL_CORE_MMR_LOCK_1_MMR_LOCK_1_RESETVAL         (0x1a1c8144U)
#define CSL_CONTROL_CORE_MMR_LOCK_1_MMR_LOCK_1_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MMR_LOCK_1_RESETVAL                    (0x1a1c8144U)

/* MMR_LOCK_2 */

#define CSL_CONTROL_CORE_MMR_LOCK_2_MMR_LOCK_2_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MMR_LOCK_2_MMR_LOCK_2_SHIFT            (0U)
#define CSL_CONTROL_CORE_MMR_LOCK_2_MMR_LOCK_2_RESETVAL         (0xfdf45530U)
#define CSL_CONTROL_CORE_MMR_LOCK_2_MMR_LOCK_2_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MMR_LOCK_2_RESETVAL                    (0xfdf45530U)

/* MMR_LOCK_3 */

#define CSL_CONTROL_CORE_MMR_LOCK_3_MMR_LOCK_3_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MMR_LOCK_3_MMR_LOCK_3_SHIFT            (0U)
#define CSL_CONTROL_CORE_MMR_LOCK_3_MMR_LOCK_3_RESETVAL         (0x1ae6e320U)
#define CSL_CONTROL_CORE_MMR_LOCK_3_MMR_LOCK_3_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MMR_LOCK_3_RESETVAL                    (0x1ae6e320U)

/* MMR_LOCK_4 */

#define CSL_CONTROL_CORE_MMR_LOCK_4_MMR_LOCK_4_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MMR_LOCK_4_MMR_LOCK_4_SHIFT            (0U)
#define CSL_CONTROL_CORE_MMR_LOCK_4_MMR_LOCK_4_RESETVAL         (0x2ffa927cU)
#define CSL_CONTROL_CORE_MMR_LOCK_4_MMR_LOCK_4_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MMR_LOCK_4_RESETVAL                    (0x2ffa927cU)

/* MMR_LOCK_5 */

#define CSL_CONTROL_CORE_MMR_LOCK_5_MMR_LOCK_5_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MMR_LOCK_5_MMR_LOCK_5_SHIFT            (0U)
#define CSL_CONTROL_CORE_MMR_LOCK_5_MMR_LOCK_5_RESETVAL         (0x143f832cU)
#define CSL_CONTROL_CORE_MMR_LOCK_5_MMR_LOCK_5_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MMR_LOCK_5_RESETVAL                    (0x143f832cU)

/* CONTROL_IO_1 */

#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PADORDER_RESERVED_MASK  (0x10000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PADORDER_RESERVED_SHIFT  (28U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PADORDER_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PADORDER_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PULLUPDET_RESERVED_MASK  (0x01000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PULLUPDET_RESERVED_SHIFT  (24U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PULLUPDET_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_HDMI_PHY_PULLUPDET_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU2_DISABLE_MASK         (0x00100000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU2_DISABLE_SHIFT        (20U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU2_DISABLE_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU2_DISABLE_MAX          (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU1_DISABLE_MASK         (0x00010000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU1_DISABLE_SHIFT        (16U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU1_DISABLE_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_MMU1_DISABLE_MAX          (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_TC1_DEFAULT_BURST_SIZE_MASK  (0x00003000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC1_DEFAULT_BURST_SIZE_SHIFT  (12U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC1_DEFAULT_BURST_SIZE_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC1_DEFAULT_BURST_SIZE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_TC0_DEFAULT_BURST_SIZE_MASK  (0x00000300U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC0_DEFAULT_BURST_SIZE_SHIFT  (8U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC0_DEFAULT_BURST_SIZE_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_TC0_DEFAULT_BURST_SIZE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII2_SEL_MASK            (0x00000030U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII2_SEL_SHIFT           (4U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII2_SEL_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII2_SEL_MAX             (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII1_SEL_MASK            (0x00000003U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII1_SEL_SHIFT           (0U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII1_SEL_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_1_GMII1_SEL_MAX             (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_IO_1_RESETVAL                  (0x00003300U)

/* CONTROL_IO_2 */

#define CSL_CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE_SHIFT  (23U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE_RESETISOLATED  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE_NOTRESETISOLATED  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS3_TBCLKEN_MASK       (0x00400000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS3_TBCLKEN_SHIFT      (22U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS3_TBCLKEN_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS3_TBCLKEN_MAX        (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS2_TBCLKEN_MASK       (0x00200000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS2_TBCLKEN_SHIFT      (21U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS2_TBCLKEN_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS2_TBCLKEN_MAX        (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS1_TBCLKEN_MASK       (0x00100000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS1_TBCLKEN_SHIFT      (20U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS1_TBCLKEN_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PWMSS1_TBCLKEN_MAX        (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_MLB_CLOCK_DOUBLER_ENABLE_MASK  (0x00040000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_MLB_CLOCK_DOUBLER_ENABLE_SHIFT  (18U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_MLB_CLOCK_DOUBLER_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_MLB_CLOCK_DOUBLER_ENABLE_MLB6PINCLOCKDOUBLERISENABLED  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_MLB_CLOCK_DOUBLER_ENABLE_MLB6PINCLOCKISENABLED  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN2_INPUT_SELECTION_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN2_INPUT_SELECTION_SHIFT  (17U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN2_INPUT_SELECTION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN2_INPUT_SELECTION_FROMLVDSRXPORT2  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN2_INPUT_SELECTION_FROMPINS  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN1_INPUT_SELECTION_MASK  (0x00010000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN1_INPUT_SELECTION_SHIFT  (16U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN1_INPUT_SELECTION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN1_INPUT_SELECTION_FROMLVDSRXPORT1  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP2_VIN1_INPUT_SELECTION_FROMPINS  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN2_INPUT_SELECTION_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN2_INPUT_SELECTION_SHIFT  (15U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN2_INPUT_SELECTION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN2_INPUT_SELECTION_FROMLVDSRXPORT2  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN2_INPUT_SELECTION_FROMPINS  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN1_INPUT_SELECTION_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN1_INPUT_SELECTION_SHIFT  (14U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN1_INPUT_SELECTION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN1_INPUT_SELECTION_FROMLVDSRXPORT1  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_VIP1_VIN1_INPUT_SELECTION_FROMPINS  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_PCIE_1LANE_2LANE_SELECTION_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PCIE_1LANE_2LANE_SELECTION_SHIFT  (13U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PCIE_1LANE_2LANE_SELECTION_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PCIE_1LANE_2LANE_SELECTION__2_LANE  (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_PCIE_1LANE_2LANE_SELECTION__1_LANE  (0x00000000U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_QSPI_MEMMAPPED_CS_MASK    (0x00000700U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_QSPI_MEMMAPPED_CS_SHIFT   (8U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_QSPI_MEMMAPPED_CS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_QSPI_MEMMAPPED_CS_MAX     (0x00000007U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP2_SECURE_EN_RESERVED_MASK  (0x00000080U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP2_SECURE_EN_RESERVED_SHIFT  (7U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP2_SECURE_EN_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP2_SECURE_EN_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP1_SECURE_EN_RESERVED_MASK  (0x00000040U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP1_SECURE_EN_RESERVED_SHIFT  (6U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP1_SECURE_EN_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSP1_SECURE_EN_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_SHIFT  (5U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_DISABLE_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_DISABLE_SHIFT  (4U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_DISABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_DISABLE_MAX   (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_SHIFT  (3U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_START_CAUSESTHEINITIALIZATIONPULSETOHAPPEN_NONEEDFORSWTOWRITE0  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_MASK   (0x00000004U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_SHIFT  (2U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN2_RAMINIT_DONE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_MASK   (0x00000002U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_SHIFT  (1U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DCAN1_RAMINIT_DONE_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_CLKEN_MASK    (0x00000001U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_CLKEN_SHIFT   (0U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_CLKEN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_IO_2_DSS_DESHDCP_CLKEN_MAX     (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_IO_2_RESETVAL                  (0x00000000U)

/* CONTROL_DSP1_RST_VECT */

#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_RESERVED_MASK  (0xF8000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_RESERVED_SHIFT  (27U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_RESERVED_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_NUM_MM_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_NUM_MM_SHIFT  (24U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_NUM_MM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_NUM_MM_TWODSPS  (0x00000002U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_NUM_MM_ONEDSP  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_VECT_MASK  (0x003FFFFFU)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_VECT_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_VECT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_DSP1_RST_VECT_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_CONTROL_DSP1_RST_VECT_RESETVAL         (0x00000000U)

/* CONTROL_DSP2_RST_VECT */

#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_RESERVED_MASK  (0xF8000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_RESERVED_SHIFT  (27U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_RESERVED_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_NUM_MM_MASK  (0x07000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_NUM_MM_SHIFT  (24U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_NUM_MM_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_NUM_MM_TWODSPS  (0x00000002U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_NUM_MM_ONEDSP  (0x00000001U)

#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_VECT_MASK  (0x003FFFFFU)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_VECT_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_VECT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_DSP2_RST_VECT_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_CONTROL_DSP2_RST_VECT_RESETVAL         (0x00000000U)

/* STD_FUSE_OPP_BGAP_DSPEVE */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE_STD_FUSE_OPP_BGAP_DSPEVE_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE_STD_FUSE_OPP_BGAP_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE_STD_FUSE_OPP_BGAP_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE_STD_FUSE_OPP_BGAP_DSPEVE_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_DSPEVE_RESETVAL      (0x00000000U)

/* STD_FUSE_OPP_BGAP_IVA */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA_STD_FUSE_OPP_BGAP_IVA_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA_STD_FUSE_OPP_BGAP_IVA_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA_STD_FUSE_OPP_BGAP_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA_STD_FUSE_OPP_BGAP_IVA_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_BGAP_IVA_RESETVAL         (0x00000000U)

/* LDOSRAM_DSPEVE_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_LDOSRAMDSPEVE_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_DSPEVE_VOLTAGE_CTRL_RESETVAL   (0x00000000U)

/* LDOSRAM_IVA_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_LDOSRAMIVA_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_IVA_VOLTAGE_CTRL_RESETVAL      (0x00000000U)

/* TEMP_SENSOR_DSPEVE */

#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_TMPSOFF_DSPEVE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_TMPSOFF_DSPEVE_SHIFT  (11U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_TMPSOFF_DSPEVE_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_TMPSOFF_DSPEVE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_EOCZ_DSPEVE_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_EOCZ_DSPEVE_SHIFT  (10U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_EOCZ_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_EOCZ_DSPEVE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_DTEMP_DSPEVE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_DTEMP_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_DTEMP_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_BGAP_DTEMP_DSPEVE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_TEMP_SENSOR_DSPEVE_RESETVAL            (0x00000800U)

/* TEMP_SENSOR_IVA */

#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_TMPSOFF_IVA_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_TMPSOFF_IVA_SHIFT  (11U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_TMPSOFF_IVA_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_TMPSOFF_IVA_MAX   (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_EOCZ_IVA_MASK     (0x00000400U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_EOCZ_IVA_SHIFT    (10U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_EOCZ_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_EOCZ_IVA_MAX      (0x00000001U)

#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_DTEMP_IVA_MASK    (0x000003FFU)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_DTEMP_IVA_SHIFT   (0U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_DTEMP_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_BGAP_DTEMP_IVA_MAX     (0x000003ffU)

#define CSL_CONTROL_CORE_TEMP_SENSOR_IVA_RESETVAL               (0x00000800U)

/* BANDGAP_MASK_2 */

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_BANDGAP_RESERVED_MASK   (0xC0000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_BANDGAP_RESERVED_SHIFT  (30U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_BANDGAP_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_BANDGAP_RESERVED_MAX    (0x00000003U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_IVA_MASK         (0x00400000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_IVA_SHIFT        (22U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_IVA_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_IVA_UNMASKED     (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_IVA_MASKED       (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_DSPEVE_MASK      (0x00200000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_DSPEVE_SHIFT     (21U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_DSPEVE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_FREEZE_DSPEVE_MASKED    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_IVA_MASK          (0x00080000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_IVA_SHIFT         (19U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_IVA_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_IVA_UNMASKED      (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_IVA_MASKED        (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_DSPEVE_MASK       (0x00040000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_DSPEVE_SHIFT      (18U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_DSPEVE_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_DSPEVE_UNMASKED   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_DSPEVE_MASKED     (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_IVA_MASK    (0x00010000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_IVA_SHIFT   (16U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_IVA_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_IVA_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_DSPEVE_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_DSPEVE_SHIFT  (15U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_DSPEVE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_CLEAR_ACCUM_DSPEVE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_IVA_MASK       (0x00000008U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_IVA_SHIFT      (3U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_IVA_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_IVA_UNMASKED   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_IVA_MASKED     (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_IVA_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_IVA_SHIFT     (2U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_IVA_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_IVA_MASKED    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_DSPEVE_MASK    (0x00000002U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_DSPEVE_SHIFT   (1U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_DSPEVE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_HOT_DSPEVE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_DSPEVE_MASK   (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_DSPEVE_UNMASKED  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_MASK_2_MASK_COLD_DSPEVE_MASKED  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_MASK_2_RESETVAL                (0x00000000U)

/* BANDGAP_THRESHOLD_DSPEVE */

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_HOT_DSPEVE_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_HOT_DSPEVE_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_HOT_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_HOT_DSPEVE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_COLD_DSPEVE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_COLD_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_COLD_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_THOLD_COLD_DSPEVE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_DSPEVE_RESETVAL      (0x00000000U)

/* BANDGAP_THRESHOLD_IVA */

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_HOT_IVA_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_HOT_IVA_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_HOT_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_HOT_IVA_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_COLD_IVA_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_COLD_IVA_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_COLD_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_THOLD_COLD_IVA_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_THRESHOLD_IVA_RESETVAL         (0x00000000U)

/* BANDGAP_TSHUT_DSPEVE */

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_MUXCTRL_DSPEVE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_MUXCTRL_DSPEVE_SHIFT  (31U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_MUXCTRL_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_MUXCTRL_DSPEVE_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_MUXCTRL_DSPEVE_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_HOT_DSPEVE_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_HOT_DSPEVE_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_HOT_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_HOT_DSPEVE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_COLD_DSPEVE_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_COLD_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_COLD_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_TSHUT_COLD_DSPEVE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_DSPEVE_RESETVAL          (0x00000000U)

/* BANDGAP_TSHUT_IVA */

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_MUXCTRL_IVA_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_MUXCTRL_IVA_SHIFT  (31U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_MUXCTRL_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_MUXCTRL_IVA_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_MUXCTRL_IVA_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_HOT_IVA_MASK   (0x03FF0000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_HOT_IVA_SHIFT  (16U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_HOT_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_HOT_IVA_MAX    (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_COLD_IVA_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_COLD_IVA_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_COLD_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_TSHUT_COLD_IVA_MAX   (0x000003ffU)

#define CSL_CONTROL_CORE_BANDGAP_TSHUT_IVA_RESETVAL             (0x00000000U)

/* BANDGAP_CUMUL_DTEMP_DSPEVE */

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE_CUMUL_DTEMP_DSPEVE_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE_CUMUL_DTEMP_DSPEVE_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE_CUMUL_DTEMP_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE_CUMUL_DTEMP_DSPEVE_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_DSPEVE_RESETVAL    (0x00000000U)

/* BANDGAP_CUMUL_DTEMP_IVA */

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA_CUMUL_DTEMP_IVA_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA_CUMUL_DTEMP_IVA_SHIFT  (0U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA_CUMUL_DTEMP_IVA_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA_CUMUL_DTEMP_IVA_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_BANDGAP_CUMUL_DTEMP_IVA_RESETVAL       (0x00000000U)

/* BANDGAP_STATUS_2 */

#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_IVA_MASK          (0x00000008U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_IVA_SHIFT         (3U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_IVA_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_IVA_EVENT         (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_IVA_NOEVENT       (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_IVA_MASK         (0x00000004U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_IVA_SHIFT        (2U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_IVA_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_IVA_EVENT        (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_IVA_NOEVENT      (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_DSPEVE_MASK       (0x00000002U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_DSPEVE_SHIFT      (1U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_DSPEVE_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_DSPEVE_EVENT      (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_HOT_DSPEVE_NOEVENT    (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_DSPEVE_MASK      (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_DSPEVE_SHIFT     (0U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_DSPEVE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_DSPEVE_EVENT     (0x00000001U)
#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_COLD_DSPEVE_NOEVENT   (0x00000000U)

#define CSL_CONTROL_CORE_BANDGAP_STATUS_2_RESETVAL              (0x00000000U)

/* DTEMP_DSPEVE_0 */

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TAG_DSPEVE_0_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TAG_DSPEVE_0_SHIFT  (10U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TAG_DSPEVE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TAG_DSPEVE_0_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TEMPERATURE_DSPEVE_0_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TEMPERATURE_DSPEVE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TEMPERATURE_DSPEVE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_DTEMP_TEMPERATURE_DSPEVE_0_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_0_RESETVAL                (0x00000000U)

/* DTEMP_DSPEVE_1 */

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TAG_DSPEVE_1_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TAG_DSPEVE_1_SHIFT  (10U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TAG_DSPEVE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TAG_DSPEVE_1_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TEMPERATURE_DSPEVE_1_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TEMPERATURE_DSPEVE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TEMPERATURE_DSPEVE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_DTEMP_TEMPERATURE_DSPEVE_1_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_1_RESETVAL                (0x00000000U)

/* DTEMP_DSPEVE_2 */

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TAG_DSPEVE_2_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TAG_DSPEVE_2_SHIFT  (10U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TAG_DSPEVE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TAG_DSPEVE_2_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TEMPERATURE_DSPEVE_2_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TEMPERATURE_DSPEVE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TEMPERATURE_DSPEVE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_DTEMP_TEMPERATURE_DSPEVE_2_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_2_RESETVAL                (0x00000000U)

/* DTEMP_DSPEVE_3 */

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TAG_DSPEVE_3_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TAG_DSPEVE_3_SHIFT  (10U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TAG_DSPEVE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TAG_DSPEVE_3_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TEMPERATURE_DSPEVE_3_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TEMPERATURE_DSPEVE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TEMPERATURE_DSPEVE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_DTEMP_TEMPERATURE_DSPEVE_3_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_3_RESETVAL                (0x00000000U)

/* DTEMP_DSPEVE_4 */

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TAG_DSPEVE_4_MASK  (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TAG_DSPEVE_4_SHIFT  (10U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TAG_DSPEVE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TAG_DSPEVE_4_MAX  (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TEMPERATURE_DSPEVE_4_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TEMPERATURE_DSPEVE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TEMPERATURE_DSPEVE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_DTEMP_TEMPERATURE_DSPEVE_4_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_DSPEVE_4_RESETVAL                (0x00000000U)

/* DTEMP_IVA_0 */

#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TAG_IVA_0_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TAG_IVA_0_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TAG_IVA_0_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TAG_IVA_0_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TEMPERATURE_IVA_0_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TEMPERATURE_IVA_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TEMPERATURE_IVA_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_0_DTEMP_TEMPERATURE_IVA_0_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_0_RESETVAL                   (0x00000000U)

/* DTEMP_IVA_1 */

#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TAG_IVA_1_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TAG_IVA_1_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TAG_IVA_1_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TAG_IVA_1_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TEMPERATURE_IVA_1_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TEMPERATURE_IVA_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TEMPERATURE_IVA_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_1_DTEMP_TEMPERATURE_IVA_1_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_1_RESETVAL                   (0x00000000U)

/* DTEMP_IVA_2 */

#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TAG_IVA_2_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TAG_IVA_2_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TAG_IVA_2_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TAG_IVA_2_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TEMPERATURE_IVA_2_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TEMPERATURE_IVA_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TEMPERATURE_IVA_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_2_DTEMP_TEMPERATURE_IVA_2_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_2_RESETVAL                   (0x00000000U)

/* DTEMP_IVA_3 */

#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TAG_IVA_3_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TAG_IVA_3_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TAG_IVA_3_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TAG_IVA_3_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TEMPERATURE_IVA_3_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TEMPERATURE_IVA_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TEMPERATURE_IVA_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_3_DTEMP_TEMPERATURE_IVA_3_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_3_RESETVAL                   (0x00000000U)

/* DTEMP_IVA_4 */

#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TAG_IVA_4_MASK       (0xFFFFFC00U)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TAG_IVA_4_SHIFT      (10U)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TAG_IVA_4_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TAG_IVA_4_MAX        (0x003fffffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TEMPERATURE_IVA_4_MASK  (0x000003FFU)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TEMPERATURE_IVA_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TEMPERATURE_IVA_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DTEMP_IVA_4_DTEMP_TEMPERATURE_IVA_4_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_DTEMP_IVA_4_RESETVAL                   (0x00000000U)

/* STD_FUSE_OPP_VMIN_IVA_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0_STD_FUSE_OPP_VMIN_IVA_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0_STD_FUSE_OPP_VMIN_IVA_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0_STD_FUSE_OPP_VMIN_IVA_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0_STD_FUSE_OPP_VMIN_IVA_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_0_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VMIN_IVA_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1_STD_FUSE_OPP_VMIN_IVA_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1_STD_FUSE_OPP_VMIN_IVA_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1_STD_FUSE_OPP_VMIN_IVA_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1_STD_FUSE_OPP_VMIN_IVA_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_1_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VMIN_IVA_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2_STD_FUSE_OPP_VMIN_IVA_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2_STD_FUSE_OPP_VMIN_IVA_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2_STD_FUSE_OPP_VMIN_IVA_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2_STD_FUSE_OPP_VMIN_IVA_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_2_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VMIN_IVA_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3_STD_FUSE_OPP_VMIN_IVA_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3_STD_FUSE_OPP_VMIN_IVA_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3_STD_FUSE_OPP_VMIN_IVA_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3_STD_FUSE_OPP_VMIN_IVA_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_3_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VMIN_IVA_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4_STD_FUSE_OPP_VMIN_IVA_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4_STD_FUSE_OPP_VMIN_IVA_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4_STD_FUSE_OPP_VMIN_IVA_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4_STD_FUSE_OPP_VMIN_IVA_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_IVA_4_RESETVAL       (0x00000000U)

/* STD_FUSE_OPP_VMIN_DSPEVE_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0_STD_FUSE_OPP_VMIN_DSPEVE_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0_STD_FUSE_OPP_VMIN_DSPEVE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0_STD_FUSE_OPP_VMIN_DSPEVE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0_STD_FUSE_OPP_VMIN_DSPEVE_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_0_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VMIN_DSPEVE_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1_STD_FUSE_OPP_VMIN_DSPEVE_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1_STD_FUSE_OPP_VMIN_DSPEVE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1_STD_FUSE_OPP_VMIN_DSPEVE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1_STD_FUSE_OPP_VMIN_DSPEVE_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_1_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VMIN_DSPEVE_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2_STD_FUSE_OPP_VMIN_DSPEVE_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2_STD_FUSE_OPP_VMIN_DSPEVE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2_STD_FUSE_OPP_VMIN_DSPEVE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2_STD_FUSE_OPP_VMIN_DSPEVE_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_2_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VMIN_DSPEVE_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3_STD_FUSE_OPP_VMIN_DSPEVE_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3_STD_FUSE_OPP_VMIN_DSPEVE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3_STD_FUSE_OPP_VMIN_DSPEVE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3_STD_FUSE_OPP_VMIN_DSPEVE_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_3_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VMIN_DSPEVE_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4_STD_FUSE_OPP_VMIN_DSPEVE_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4_STD_FUSE_OPP_VMIN_DSPEVE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4_STD_FUSE_OPP_VMIN_DSPEVE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4_STD_FUSE_OPP_VMIN_DSPEVE_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_DSPEVE_4_RESETVAL    (0x00000000U)

/* STD_FUSE_OPP_VMIN_CORE_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0_STD_FUSE_OPP_VMIN_CORE_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0_STD_FUSE_OPP_VMIN_CORE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0_STD_FUSE_OPP_VMIN_CORE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0_STD_FUSE_OPP_VMIN_CORE_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_0_RESETVAL      (0x00000000U)

/* STD_FUSE_OPP_VMIN_CORE_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1_STD_FUSE_OPP_VMIN_CORE_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1_STD_FUSE_OPP_VMIN_CORE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1_STD_FUSE_OPP_VMIN_CORE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1_STD_FUSE_OPP_VMIN_CORE_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_1_RESETVAL      (0x00000000U)

/* STD_FUSE_OPP_VMIN_CORE_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2_STD_FUSE_OPP_VMIN_CORE_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2_STD_FUSE_OPP_VMIN_CORE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2_STD_FUSE_OPP_VMIN_CORE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2_STD_FUSE_OPP_VMIN_CORE_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_2_RESETVAL      (0x00000000U)

/* STD_FUSE_OPP_VMIN_CORE_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3_STD_FUSE_OPP_VMIN_CORE_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3_STD_FUSE_OPP_VMIN_CORE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3_STD_FUSE_OPP_VMIN_CORE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3_STD_FUSE_OPP_VMIN_CORE_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_3_RESETVAL      (0x00000000U)

/* STD_FUSE_OPP_VMIN_CORE_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4_STD_FUSE_OPP_VMIN_CORE_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4_STD_FUSE_OPP_VMIN_CORE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4_STD_FUSE_OPP_VMIN_CORE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4_STD_FUSE_OPP_VMIN_CORE_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VMIN_CORE_4_RESETVAL      (0x00000000U)

/* TRB1_LOW */

#define CSL_CONTROL_CORE_TRB1_LOW_TRB1_LOW_MASK                 (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB1_LOW_TRB1_LOW_SHIFT                (0U)
#define CSL_CONTROL_CORE_TRB1_LOW_TRB1_LOW_RESETVAL             (0x54800000U)
#define CSL_CONTROL_CORE_TRB1_LOW_TRB1_LOW_MAX                  (0xffffffffU)

#define CSL_CONTROL_CORE_TRB1_LOW_RESETVAL                      (0x54800000U)

/* TRB1_HIGH */

#define CSL_CONTROL_CORE_TRB1_HIGH_TRB1_HIGH_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB1_HIGH_TRB1_HIGH_SHIFT              (0U)
#define CSL_CONTROL_CORE_TRB1_HIGH_TRB1_HIGH_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_TRB1_HIGH_TRB1_HIGH_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_TRB1_HIGH_RESETVAL                     (0x00000000U)

/* TRB1_BUFFER */

#define CSL_CONTROL_CORE_TRB1_BUFFER_TRB1_BUFFER_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB1_BUFFER_TRB1_BUFFER_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB1_BUFFER_TRB1_BUFFER_RESETVAL       (0x00800000U)
#define CSL_CONTROL_CORE_TRB1_BUFFER_TRB1_BUFFER_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB1_BUFFER_RESETVAL                   (0x00800000U)

/* TRB1_NORMAL */

#define CSL_CONTROL_CORE_TRB1_NORMAL_TRB1_NORMAL_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB1_NORMAL_TRB1_NORMAL_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB1_NORMAL_TRB1_NORMAL_RESETVAL       (0x00000011U)
#define CSL_CONTROL_CORE_TRB1_NORMAL_TRB1_NORMAL_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB1_NORMAL_RESETVAL                   (0x00000011U)

/* TRB2_LOW */

#define CSL_CONTROL_CORE_TRB2_LOW_TRB2_LOW_MASK                 (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB2_LOW_TRB2_LOW_SHIFT                (0U)
#define CSL_CONTROL_CORE_TRB2_LOW_TRB2_LOW_RESETVAL             (0x54800000U)
#define CSL_CONTROL_CORE_TRB2_LOW_TRB2_LOW_MAX                  (0xffffffffU)

#define CSL_CONTROL_CORE_TRB2_LOW_RESETVAL                      (0x54800000U)

/* TRB2_HIGH */

#define CSL_CONTROL_CORE_TRB2_HIGH_TRB2_HIGH_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB2_HIGH_TRB2_HIGH_SHIFT              (0U)
#define CSL_CONTROL_CORE_TRB2_HIGH_TRB2_HIGH_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_TRB2_HIGH_TRB2_HIGH_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_TRB2_HIGH_RESETVAL                     (0x00000000U)

/* TRB2_BUFFER */

#define CSL_CONTROL_CORE_TRB2_BUFFER_TRB2_BUFFER_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB2_BUFFER_TRB2_BUFFER_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB2_BUFFER_TRB2_BUFFER_RESETVAL       (0x00800000U)
#define CSL_CONTROL_CORE_TRB2_BUFFER_TRB2_BUFFER_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB2_BUFFER_RESETVAL                   (0x00800000U)

/* TRB2_NORMAL */

#define CSL_CONTROL_CORE_TRB2_NORMAL_TRB2_NORMAL_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB2_NORMAL_TRB2_NORMAL_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB2_NORMAL_TRB2_NORMAL_RESETVAL       (0x00000011U)
#define CSL_CONTROL_CORE_TRB2_NORMAL_TRB2_NORMAL_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB2_NORMAL_RESETVAL                   (0x00000011U)

/* TRB3_LOW */

#define CSL_CONTROL_CORE_TRB3_LOW_TRB3_LOW_MASK                 (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB3_LOW_TRB3_LOW_SHIFT                (0U)
#define CSL_CONTROL_CORE_TRB3_LOW_TRB3_LOW_RESETVAL             (0x4a002640U)
#define CSL_CONTROL_CORE_TRB3_LOW_TRB3_LOW_MAX                  (0xffffffffU)

#define CSL_CONTROL_CORE_TRB3_LOW_RESETVAL                      (0x4a002640U)

/* TRB3_HIGH */

#define CSL_CONTROL_CORE_TRB3_HIGH_TRB3_HIGH_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB3_HIGH_TRB3_HIGH_SHIFT              (0U)
#define CSL_CONTROL_CORE_TRB3_HIGH_TRB3_HIGH_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_TRB3_HIGH_TRB3_HIGH_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_TRB3_HIGH_RESETVAL                     (0x00000000U)

/* TRB3_BUFFER */

#define CSL_CONTROL_CORE_TRB3_BUFFER_TRB3_BUFFER_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB3_BUFFER_TRB3_BUFFER_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB3_BUFFER_TRB3_BUFFER_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_TRB3_BUFFER_TRB3_BUFFER_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB3_BUFFER_RESETVAL                   (0x00000000U)

/* TRB3_NORMAL */

#define CSL_CONTROL_CORE_TRB3_NORMAL_TRB3_NORMAL_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_TRB3_NORMAL_TRB3_NORMAL_SHIFT          (0U)
#define CSL_CONTROL_CORE_TRB3_NORMAL_TRB3_NORMAL_RESETVAL       (0x00000081U)
#define CSL_CONTROL_CORE_TRB3_NORMAL_TRB3_NORMAL_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_TRB3_NORMAL_RESETVAL                   (0x00000081U)

/* DUMMY0 */

#define CSL_CONTROL_CORE_DUMMY0_DUMMY0_MASK                     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_DUMMY0_DUMMY0_SHIFT                    (0U)
#define CSL_CONTROL_CORE_DUMMY0_DUMMY0_RESETVAL                 (0x00000000U)
#define CSL_CONTROL_CORE_DUMMY0_DUMMY0_MAX                      (0xffffffffU)

#define CSL_CONTROL_CORE_DUMMY0_RESETVAL                        (0x00000000U)

/* DUMMY1 */

#define CSL_CONTROL_CORE_DUMMY1_DUMMY1_MASK                     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_DUMMY1_DUMMY1_SHIFT                    (0U)
#define CSL_CONTROL_CORE_DUMMY1_DUMMY1_RESETVAL                 (0x00000000U)
#define CSL_CONTROL_CORE_DUMMY1_DUMMY1_MAX                      (0xffffffffU)

#define CSL_CONTROL_CORE_DUMMY1_RESETVAL                        (0x00000000U)

/* DUMMY2 */

#define CSL_CONTROL_CORE_DUMMY2_DUMMY2_MASK                     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_DUMMY2_DUMMY2_SHIFT                    (0U)
#define CSL_CONTROL_CORE_DUMMY2_DUMMY2_RESETVAL                 (0x00000000U)
#define CSL_CONTROL_CORE_DUMMY2_DUMMY2_MAX                      (0xffffffffU)

#define CSL_CONTROL_CORE_DUMMY2_RESETVAL                        (0x00000000U)

/* DUMMY3 */

#define CSL_CONTROL_CORE_DUMMY3_DUMMY3_MASK                     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_DUMMY3_DUMMY3_SHIFT                    (0U)
#define CSL_CONTROL_CORE_DUMMY3_DUMMY3_RESETVAL                 (0x00000000U)
#define CSL_CONTROL_CORE_DUMMY3_DUMMY3_MAX                      (0xffffffffU)

#define CSL_CONTROL_CORE_DUMMY3_RESETVAL                        (0x00000000U)

/* CTRB1_LOW */

#define CSL_CONTROL_CORE_CTRB1_LOW_CTRB1_LOW_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB1_LOW_CTRB1_LOW_SHIFT              (0U)
#define CSL_CONTROL_CORE_CTRB1_LOW_CTRB1_LOW_RESETVAL           (0x54800000U)
#define CSL_CONTROL_CORE_CTRB1_LOW_CTRB1_LOW_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB1_LOW_RESETVAL                     (0x54800000U)

/* CTRB1_HIGH */

#define CSL_CONTROL_CORE_CTRB1_HIGH_CTRB1_HIGH_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB1_HIGH_CTRB1_HIGH_SHIFT            (0U)
#define CSL_CONTROL_CORE_CTRB1_HIGH_CTRB1_HIGH_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CTRB1_HIGH_CTRB1_HIGH_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB1_HIGH_RESETVAL                    (0x00000000U)

/* CTRB1_BUFFER */

#define CSL_CONTROL_CORE_CTRB1_BUFFER_CTRB1_BUFFER_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB1_BUFFER_CTRB1_BUFFER_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB1_BUFFER_CTRB1_BUFFER_RESETVAL     (0x00800000U)
#define CSL_CONTROL_CORE_CTRB1_BUFFER_CTRB1_BUFFER_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB1_BUFFER_RESETVAL                  (0x00800000U)

/* CTRB1_NORMAL */

#define CSL_CONTROL_CORE_CTRB1_NORMAL_CTRB1_NORMAL_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB1_NORMAL_CTRB1_NORMAL_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB1_NORMAL_CTRB1_NORMAL_RESETVAL     (0x00000011U)
#define CSL_CONTROL_CORE_CTRB1_NORMAL_CTRB1_NORMAL_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB1_NORMAL_RESETVAL                  (0x00000011U)

/* CTRB2_LOW */

#define CSL_CONTROL_CORE_CTRB2_LOW_CTRB2_LOW_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB2_LOW_CTRB2_LOW_SHIFT              (0U)
#define CSL_CONTROL_CORE_CTRB2_LOW_CTRB2_LOW_RESETVAL           (0x54800000U)
#define CSL_CONTROL_CORE_CTRB2_LOW_CTRB2_LOW_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB2_LOW_RESETVAL                     (0x54800000U)

/* CTRB2_HIGH */

#define CSL_CONTROL_CORE_CTRB2_HIGH_CTRB2_HIGH_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB2_HIGH_CTRB2_HIGH_SHIFT            (0U)
#define CSL_CONTROL_CORE_CTRB2_HIGH_CTRB2_HIGH_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CTRB2_HIGH_CTRB2_HIGH_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB2_HIGH_RESETVAL                    (0x00000000U)

/* CTRB2_BUFFER */

#define CSL_CONTROL_CORE_CTRB2_BUFFER_CTRB2_BUFFER_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB2_BUFFER_CTRB2_BUFFER_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB2_BUFFER_CTRB2_BUFFER_RESETVAL     (0x00800000U)
#define CSL_CONTROL_CORE_CTRB2_BUFFER_CTRB2_BUFFER_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB2_BUFFER_RESETVAL                  (0x00800000U)

/* CTRB2_NORMAL */

#define CSL_CONTROL_CORE_CTRB2_NORMAL_CTRB2_NORMAL_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB2_NORMAL_CTRB2_NORMAL_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB2_NORMAL_CTRB2_NORMAL_RESETVAL     (0x00000011U)
#define CSL_CONTROL_CORE_CTRB2_NORMAL_CTRB2_NORMAL_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB2_NORMAL_RESETVAL                  (0x00000011U)

/* CTRB3_LOW */

#define CSL_CONTROL_CORE_CTRB3_LOW_CTRB3_LOW_MASK               (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB3_LOW_CTRB3_LOW_SHIFT              (0U)
#define CSL_CONTROL_CORE_CTRB3_LOW_CTRB3_LOW_RESETVAL           (0x4a002640U)
#define CSL_CONTROL_CORE_CTRB3_LOW_CTRB3_LOW_MAX                (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB3_LOW_RESETVAL                     (0x4a002640U)

/* CTRB3_HIGH */

#define CSL_CONTROL_CORE_CTRB3_HIGH_CTRB3_HIGH_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB3_HIGH_CTRB3_HIGH_SHIFT            (0U)
#define CSL_CONTROL_CORE_CTRB3_HIGH_CTRB3_HIGH_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_CTRB3_HIGH_CTRB3_HIGH_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB3_HIGH_RESETVAL                    (0x00000000U)

/* CTRB3_BUFFER */

#define CSL_CONTROL_CORE_CTRB3_BUFFER_CTRB3_BUFFER_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB3_BUFFER_CTRB3_BUFFER_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB3_BUFFER_CTRB3_BUFFER_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_CTRB3_BUFFER_CTRB3_BUFFER_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB3_BUFFER_RESETVAL                  (0x00000000U)

/* CTRB3_NORMAL */

#define CSL_CONTROL_CORE_CTRB3_NORMAL_CTRB3_NORMAL_MASK         (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CTRB3_NORMAL_CTRB3_NORMAL_SHIFT        (0U)
#define CSL_CONTROL_CORE_CTRB3_NORMAL_CTRB3_NORMAL_RESETVAL     (0x00000081U)
#define CSL_CONTROL_CORE_CTRB3_NORMAL_CTRB3_NORMAL_MAX          (0xffffffffU)

#define CSL_CONTROL_CORE_CTRB3_NORMAL_RESETVAL                  (0x00000081U)

/* CDUMMY0 */

#define CSL_CONTROL_CORE_CDUMMY0_CDUMMY0_MASK                   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CDUMMY0_CDUMMY0_SHIFT                  (0U)
#define CSL_CONTROL_CORE_CDUMMY0_CDUMMY0_RESETVAL               (0x00000000U)
#define CSL_CONTROL_CORE_CDUMMY0_CDUMMY0_MAX                    (0xffffffffU)

#define CSL_CONTROL_CORE_CDUMMY0_RESETVAL                       (0x00000000U)

/* CDUMMY1 */

#define CSL_CONTROL_CORE_CDUMMY1_CDUMMY1_MASK                   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CDUMMY1_CDUMMY1_SHIFT                  (0U)
#define CSL_CONTROL_CORE_CDUMMY1_CDUMMY1_RESETVAL               (0x00000000U)
#define CSL_CONTROL_CORE_CDUMMY1_CDUMMY1_MAX                    (0xffffffffU)

#define CSL_CONTROL_CORE_CDUMMY1_RESETVAL                       (0x00000000U)

/* CDUMMY2 */

#define CSL_CONTROL_CORE_CDUMMY2_CDUMMY2_MASK                   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CDUMMY2_CDUMMY2_SHIFT                  (0U)
#define CSL_CONTROL_CORE_CDUMMY2_CDUMMY2_RESETVAL               (0x00000000U)
#define CSL_CONTROL_CORE_CDUMMY2_CDUMMY2_MAX                    (0xffffffffU)

#define CSL_CONTROL_CORE_CDUMMY2_RESETVAL                       (0x00000000U)

/* CDUMMY3 */

#define CSL_CONTROL_CORE_CDUMMY3_CDUMMY3_MASK                   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CDUMMY3_CDUMMY3_SHIFT                  (0U)
#define CSL_CONTROL_CORE_CDUMMY3_CDUMMY3_RESETVAL               (0x00000000U)
#define CSL_CONTROL_CORE_CDUMMY3_CDUMMY3_MAX                    (0xffffffffU)

#define CSL_CONTROL_CORE_CDUMMY3_RESETVAL                       (0x00000000U)

/* LDOSRAM_CORE_2_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_LDOSRAMCORE_2_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_2_VOLTAGE_CTRL_RESETVAL   (0x00000000U)

/* LDOSRAM_CORE_3_VOLTAGE_CTRL */

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_MUX_CTRL_MASK  (0x04000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_MUX_CTRL_SHIFT  (26U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_IN_MASK  (0x03E00000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_IN_SHIFT  (21U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_OUT_MASK  (0x001F0000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_OUT_SHIFT  (16U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_RETMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_MUX_CTRL_MASK  (0x00000400U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_MUX_CTRL_SHIFT  (10U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_MUX_CTRL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_MUX_CTRL_OCP  (0x00000001U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_MUX_CTRL_EFUSE  (0x00000000U)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_IN_MASK  (0x000003E0U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_IN_SHIFT  (5U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_IN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_IN_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_OUT_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_OUT_SHIFT  (0U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_OUT_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_LDOSRAMCORE_3_ACTMODE_VSET_OUT_MAX  (0x0000001fU)

#define CSL_CONTROL_CORE_LDOSRAM_CORE_3_VOLTAGE_CTRL_RESETVAL   (0x00000000U)

/* EFUSE_DISABLE_SW_1 */

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1_STD_FUSE_EFUSE_DISABLE_SW_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1_STD_FUSE_EFUSE_DISABLE_SW_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1_STD_FUSE_EFUSE_DISABLE_SW_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1_STD_FUSE_EFUSE_DISABLE_SW_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_EFUSE_DISABLE_SW_1_RESETVAL            (0x00000000U)

/* NMI_DESTINATION_1 */

#define CSL_CONTROL_CORE_NMI_DESTINATION_1_NMI_RESERVED_1_MASK  (0xFF000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_NMI_RESERVED_1_SHIFT  (24U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_NMI_RESERVED_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_NMI_RESERVED_1_MAX   (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C1_MASK         (0x00FF0000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C1_SHIFT        (16U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C1_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C1_MAX          (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C0_MASK         (0x0000FF00U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C0_SHIFT        (8U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C0_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU2_C0_MAX          (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU1_C1_MASK         (0x000000FFU)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU1_C1_SHIFT        (0U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU1_C1_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_1_IPU1_C1_MAX          (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_1_RESETVAL             (0x00000000U)

/* NMI_DESTINATION_2 */

#define CSL_CONTROL_CORE_NMI_DESTINATION_2_IPU1_C0_MASK         (0xFF000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_IPU1_C0_SHIFT        (24U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_IPU1_C0_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_IPU1_C0_MAX          (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP2_MASK            (0x00FF0000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP2_SHIFT           (16U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP2_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP2_MAX             (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP1_MASK            (0x0000FF00U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP1_SHIFT           (8U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP1_RESETVAL        (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_DSP1_MAX             (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_2_MPU_MASK             (0x000000FFU)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_MPU_SHIFT            (0U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_MPU_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_NMI_DESTINATION_2_MPU_MAX              (0x000000ffU)

#define CSL_CONTROL_CORE_NMI_DESTINATION_2_RESETVAL             (0x00000000U)

/* DYNAMIC_DMM_ROUTING */

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DMM_RESERVED_MASK  (0xFFFFFF80U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DMM_RESERVED_SHIFT  (7U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DMM_RESERVED_MAX   (0x01ffffffU)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU2_DMM_RESERVED_MASK  (0x00000010U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU2_DMM_RESERVED_SHIFT  (4U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU2_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU2_DMM_RESERVED_PORTP2  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU2_DMM_RESERVED_PORTP1  (0x00000000U)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU1_DMM_RESERVED_MASK  (0x00000008U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU1_DMM_RESERVED_SHIFT  (3U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU1_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU1_DMM_RESERVED_PORTP2  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_MMU1_DMM_RESERVED_PORTP1  (0x00000000U)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_USB1_DMM_RESERVED_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_USB1_DMM_RESERVED_SHIFT  (2U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_USB1_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_USB1_DMM_RESERVED_PORTP2  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_USB1_DMM_RESERVED_PORTP1  (0x00000000U)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_IVA_DMM_RESERVED_MASK  (0x00000002U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_IVA_DMM_RESERVED_SHIFT  (1U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_IVA_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_IVA_DMM_RESERVED_PORTP2  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_IVA_DMM_RESERVED_PORTP1  (0x00000000U)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DSS_DMM_RESERVED_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DSS_DMM_RESERVED_SHIFT  (0U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DSS_DMM_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DSS_DMM_RESERVED_PORTP2  (0x00000001U)
#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_DSS_DMM_RESERVED_PORTP1  (0x00000000U)

#define CSL_CONTROL_CORE_DYNAMIC_DMM_ROUTING_RESETVAL           (0x00000000U)

/* IP_PRESSURE */

#define CSL_CONTROL_CORE_IP_PRESSURE_PRESSURE_RESERVED_MASK     (0xFF000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_PRESSURE_RESERVED_SHIFT    (24U)
#define CSL_CONTROL_CORE_IP_PRESSURE_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_PRESSURE_RESERVED_MAX      (0x000000ffU)

#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00800000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (23U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_RESERVED_MASK  (0x00600000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_RESERVED_SHIFT  (21U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_DSS_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00100000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (20U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_RESERVED_MASK  (0x000C0000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_RESERVED_SHIFT  (18U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P1_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00020000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (17U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_RESERVED_MASK  (0x00018000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_RESERVED_SHIFT  (15U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP1_P2_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (14U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_RESERVED_MASK  (0x00003000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_RESERVED_SHIFT  (12U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P1_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (11U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_RESERVED_MASK  (0x00000600U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_RESERVED_SHIFT  (9U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP2_P2_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00000100U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (8U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_RESERVED_MASK  (0x000000C0U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_RESERVED_SHIFT  (6U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P1_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_ENABLE_RESERVED_MASK  (0x00000020U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_ENABLE_RESERVED_SHIFT  (5U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_ENABLE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_ENABLE_RESERVED_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_RESERVED_MASK  (0x00000018U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_RESERVED_SHIFT  (3U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_VIP3_P2_L3_PRESSURE_RESERVED_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_ENABLE_MASK  (0x00000004U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_ENABLE_SHIFT  (2U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_ENABLE_ENABLE  (0x00000001U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_ENABLE_DISABLE  (0x00000000U)

#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_MASK       (0x00000003U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_SHIFT      (0U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_RESETVAL   (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_LOWEST     (0x00000000U)
#define CSL_CONTROL_CORE_IP_PRESSURE_MLB_L3_PRESSURE_HIGHEST    (0x00000003U)

#define CSL_CONTROL_CORE_IP_PRESSURE_RESETVAL                   (0x00000000U)

/* SHA2_EVENT_MAPPING */

#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_RESERVED_MASK  (0xFFFFFFFEU)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_RESERVED_SHIFT  (1U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_RESERVED_MAX   (0x7fffffffU)

#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_EVENT_MUX_SETTING_MASK  (0x00000001U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_EVENT_MUX_SETTING_SHIFT  (0U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_EVENT_MUX_SETTING_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_EVENT_MUX_SETTING_PUBLICCONTEXTMAPPING  (0x00000001U)
#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_SHA2_EVENT_MUX_SETTING_SECURECONTEXTMAPPING  (0x00000000U)

#define CSL_CONTROL_CORE_SHA2_EVENT_MAPPING_RESETVAL            (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_0 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0_STD_FUSE_OPP_VDD_DSPEVE_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0_STD_FUSE_OPP_VDD_DSPEVE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0_STD_FUSE_OPP_VDD_DSPEVE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0_STD_FUSE_OPP_VDD_DSPEVE_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_0_RESETVAL     (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_1 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1_STD_FUSE_OPP_VDD_DSPEVE_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1_STD_FUSE_OPP_VDD_DSPEVE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1_STD_FUSE_OPP_VDD_DSPEVE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1_STD_FUSE_OPP_VDD_DSPEVE_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_1_RESETVAL     (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_2 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2_STD_FUSE_OPP_VDD_DSPEVE_2_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2_STD_FUSE_OPP_VDD_DSPEVE_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2_STD_FUSE_OPP_VDD_DSPEVE_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2_STD_FUSE_OPP_VDD_DSPEVE_2_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_2_RESETVAL     (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_3 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3_STD_FUSE_OPP_VDD_DSPEVE_3_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3_STD_FUSE_OPP_VDD_DSPEVE_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3_STD_FUSE_OPP_VDD_DSPEVE_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3_STD_FUSE_OPP_VDD_DSPEVE_3_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_3_RESETVAL     (0x00000000U)

/* STD_FUSE_OPP_VDD_DSPEVE_4 */

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4_STD_FUSE_OPP_VDD_DSPEVE_4_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4_STD_FUSE_OPP_VDD_DSPEVE_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4_STD_FUSE_OPP_VDD_DSPEVE_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4_STD_FUSE_OPP_VDD_DSPEVE_4_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_OPP_VDD_DSPEVE_4_RESETVAL     (0x00000000U)

/* CUST_FUSE_SWRV_7 */

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7_CUST_FUSE_SWRV_7_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7_CUST_FUSE_SWRV_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7_CUST_FUSE_SWRV_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7_CUST_FUSE_SWRV_7_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_CUST_FUSE_SWRV_7_RESETVAL              (0x00000000U)

/* STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0 */

#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_0_RESETVAL  (0x00000000U)

/* STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1 */

#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_STD_FUSE_CALIBRATION_OVERRIDE_VALUE_1_RESETVAL  (0x00000000U)

/* PCIE_POWER_STATE */

#define CSL_CONTROL_CORE_PCIE_POWER_STATE_BYPASS_EN_APLL_PCIE_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_BYPASS_EN_APLL_PCIE_SHIFT  (31U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_BYPASS_EN_APLL_PCIE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_BYPASS_EN_APLL_PCIE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_PCIE_POWER_STATE_CLKOOUTEN_APLL_PCIE_MASK  (0x40000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_CLKOOUTEN_APLL_PCIE_SHIFT  (30U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_CLKOOUTEN_APLL_PCIE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_CLKOOUTEN_APLL_PCIE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_ACS_PCIE_MASK  (0x03FF0000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_ACS_PCIE_SHIFT  (16U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_ACS_PCIE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_ACS_PCIE_MAX  (0x000003ffU)

#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_PCIE_PLL_MASK  (0x0000FFFFU)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_PCIE_PLL_SHIFT  (0U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_PCIE_PLL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_PCIE_POWER_STATE_EFUSE_TRIM_PCIE_PLL_MAX  (0x0000ffffU)

#define CSL_CONTROL_CORE_PCIE_POWER_STATE_RESETVAL              (0x00000000U)

/* BOOTSTRAP */

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_15_DSP_CLOCK_DIVIDER_MASK  (0x00008000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_15_DSP_CLOCK_DIVIDER_SHIFT  (15U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_15_DSP_CLOCK_DIVIDER_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_15_DSP_CLOCK_DIVIDER_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_14_IODELAYLINE_CALIBRATION_OVERRIDE_MASK  (0x00004000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_14_IODELAYLINE_CALIBRATION_OVERRIDE_SHIFT  (14U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_14_IODELAYLINE_CALIBRATION_OVERRIDE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_14_IODELAYLINE_CALIBRATION_OVERRIDE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_13_BOOTDEVICESIZE_MASK  (0x00002000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_13_BOOTDEVICESIZE_SHIFT  (13U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_13_BOOTDEVICESIZE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_13_BOOTDEVICESIZE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_12_MUXCS0DEVICE_MASK  (0x00001000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_12_MUXCS0DEVICE_SHIFT  (12U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_12_MUXCS0DEVICE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_12_MUXCS0DEVICE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_11_MUXCS0DEVICE_MASK  (0x00000800U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_11_MUXCS0DEVICE_SHIFT  (11U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_11_MUXCS0DEVICE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_11_MUXCS0DEVICE_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_10_BOOTWAITEN_MASK   (0x00000400U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_10_BOOTWAITEN_SHIFT  (10U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_10_BOOTWAITEN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_10_BOOTWAITEN_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_9_MASK               (0x00000200U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_9_SHIFT              (9U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_9_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_9_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_8_MASK               (0x00000100U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_8_SHIFT              (8U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_8_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_8_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_7_MASK               (0x00000080U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_7_SHIFT              (7U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_7_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_7_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_6_MASK               (0x00000040U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_6_SHIFT              (6U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_6_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_6_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_5_MASK               (0x00000020U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_5_SHIFT              (5U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_5_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_5_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_4_MASK               (0x00000010U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_4_SHIFT              (4U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_4_RESETVAL           (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_4_MAX                (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_3_BOOTMODE_MASK      (0x00000008U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_3_BOOTMODE_SHIFT     (3U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_3_BOOTMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_3_BOOTMODE_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_2_BOOTMODE_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_2_BOOTMODE_SHIFT     (2U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_2_BOOTMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_2_BOOTMODE_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_1_BOOTMODE_MASK      (0x00000002U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_1_BOOTMODE_SHIFT     (1U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_1_BOOTMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_1_BOOTMODE_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_0_BOOTMODE_MASK      (0x00000001U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_0_BOOTMODE_SHIFT     (0U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_0_BOOTMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_BOOTSTRAP_SYSBOOT_0_BOOTMODE_MAX       (0x00000001U)

#define CSL_CONTROL_CORE_BOOTSTRAP_RESETVAL                     (0x00000000U)

/* MLB_SIG_IO_CTRL */

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_NC_IN_MASK         (0x003F0000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_NC_IN_SHIFT        (16U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_NC_IN_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_NC_IN_MAX          (0x0000003fU)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PC_IN_MASK         (0x00003F00U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PC_IN_SHIFT        (8U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PC_IN_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PC_IN_MAX          (0x0000003fU)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_REMOVE_SKEW_MASK   (0x00000040U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_REMOVE_SKEW_SHIFT  (6U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_REMOVE_SKEW_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_REMOVE_SKEW_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNRX_MASK       (0x00000020U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNRX_SHIFT      (5U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNRX_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNRX_POWEREDOFF  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNRX_POWEREDON  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNTX_MASK       (0x00000010U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNTX_SHIFT      (4U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNTX_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNTX_POWEREDOFF  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_PWRDNTX_POWEREDON  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_EN_EXT_RES_MASK    (0x00000008U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_EN_EXT_RES_SHIFT   (3U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_EN_EXT_RES_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_EN_EXT_RES_ENABLEEXTERNALRESISTORS  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_EN_EXT_RES_DISABLEEXTERNALRESISTORS  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENLVCMOS_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENLVCMOS_SHIFT     (2U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENLVCMOS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENLVCMOS_ENABLE    (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENLVCMOS_DISABLE   (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENN_MASK           (0x00000002U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENN_SHIFT          (1U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENN_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENN_ENABLE         (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENN_DISABLE        (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENP_MASK           (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENP_SHIFT          (0U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENP_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENP_ENABLE         (0x00000001U)
#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_SIG_ENP_DISABLE        (0x00000000U)

#define CSL_CONTROL_CORE_MLB_SIG_IO_CTRL_RESETVAL               (0x00000030U)

/* MLB_DAT_IO_CTRL */

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_NC_IN_MASK         (0x003F0000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_NC_IN_SHIFT        (16U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_NC_IN_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_NC_IN_MAX          (0x0000003fU)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PC_IN_MASK         (0x00003F00U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PC_IN_SHIFT        (8U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PC_IN_RESETVAL     (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PC_IN_MAX          (0x0000003fU)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_REMOVE_SKEW_MASK   (0x00000040U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_REMOVE_SKEW_SHIFT  (6U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_REMOVE_SKEW_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_REMOVE_SKEW_MAX    (0x00000001U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNRX_MASK       (0x00000020U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNRX_SHIFT      (5U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNRX_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNRX_POWEREDOFF  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNRX_POWEREDON  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNTX_MASK       (0x00000010U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNTX_SHIFT      (4U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNTX_RESETVAL   (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNTX_POWEREDOFF  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_PWRDNTX_POWEREDON  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_EN_EXT_RES_MASK    (0x00000008U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_EN_EXT_RES_SHIFT   (3U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_EN_EXT_RES_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_EN_EXT_RES_ENABLEEXTERNALRESISTORS  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_EN_EXT_RES_DISABLEEXTERNALRESISTORS  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENLVCMOS_MASK      (0x00000004U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENLVCMOS_SHIFT     (2U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENLVCMOS_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENLVCMOS_ENABLE    (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENLVCMOS_DISABLE   (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENN_MASK           (0x00000002U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENN_SHIFT          (1U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENN_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENN_ENABLE         (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENN_DISABLE        (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENP_MASK           (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENP_SHIFT          (0U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENP_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENP_ENABLE         (0x00000001U)
#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_DAT_ENP_DISABLE        (0x00000000U)

#define CSL_CONTROL_CORE_MLB_DAT_IO_CTRL_RESETVAL               (0x00000030U)

/* MLB_CLK_BG_CTRL */

#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_T_HYSTERISIS_EN_MASK   (0x00010000U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_T_HYSTERISIS_EN_SHIFT  (16U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_T_HYSTERISIS_EN_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_T_HYSTERISIS_EN_ENABLE  (0x00000001U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_T_HYSTERISIS_EN_DISABLE  (0x00000000U)

#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_TRIM_MASK           (0x000000FCU)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_TRIM_SHIFT          (2U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_TRIM_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_TRIM_MAX            (0x0000003fU)

#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_PWRDN_MASK          (0x00000002U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_PWRDN_SHIFT         (1U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_PWRDN_RESETVAL      (0x00000000U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_PWRDN_ENABLE        (0x00000001U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_BG_PWRDN_DISABLE       (0x00000000U)

#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_CLK_PWRDN_MASK         (0x00000001U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_CLK_PWRDN_SHIFT        (0U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_CLK_PWRDN_RESETVAL     (0x00000001U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_CLK_PWRDN_ENABLE       (0x00000001U)
#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_CLK_PWRDN_DISABLE      (0x00000000U)

#define CSL_CONTROL_CORE_MLB_CLK_BG_CTRL_RESETVAL               (0x00000001U)

/* CONTROL_LVDSRX */

#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_LANEENABLE_MASK  (0x03000000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_LANEENABLE_SHIFT  (24U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_LANEENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_LANEENABLE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_LANEENABLE_MASK  (0x00030000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_LANEENABLE_SHIFT  (16U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_LANEENABLE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_LANEENABLE_MAX  (0x00000003U)

#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_CAMMODE_MASK  (0x00001F00U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_CAMMODE_SHIFT  (8U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_CAMMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX2_CAMMODE_MAX   (0x0000001fU)

#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_CAMMODE_MASK  (0x0000001FU)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_CAMMODE_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_CAMMODE_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONTROL_LVDSRX_CAMERARX1_CAMMODE_MAX   (0x0000001fU)

#define CSL_CONTROL_CORE_CONTROL_LVDSRX_RESETVAL                (0x00000000U)

/* MEK_BCH_0 */

#define CSL_CONTROL_CORE_MEK_BCH_0_CUST_FUSE_MEK_BCH_0_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_0_CUST_FUSE_MEK_BCH_0_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_0_CUST_FUSE_MEK_BCH_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_0_CUST_FUSE_MEK_BCH_0_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_0_RESETVAL                     (0x00000000U)

/* MEK_BCH_1 */

#define CSL_CONTROL_CORE_MEK_BCH_1_CUST_FUSE_MEK_BCH_1_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_1_CUST_FUSE_MEK_BCH_1_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_1_CUST_FUSE_MEK_BCH_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_1_CUST_FUSE_MEK_BCH_1_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_1_RESETVAL                     (0x00000000U)

/* MEK_BCH_2 */

#define CSL_CONTROL_CORE_MEK_BCH_2_CUST_FUSE_MEK_BCH_2_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_2_CUST_FUSE_MEK_BCH_2_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_2_CUST_FUSE_MEK_BCH_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_2_CUST_FUSE_MEK_BCH_2_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_2_RESETVAL                     (0x00000000U)

/* MEK_BCH_3 */

#define CSL_CONTROL_CORE_MEK_BCH_3_CUST_FUSE_MEK_BCH_3_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_3_CUST_FUSE_MEK_BCH_3_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_3_CUST_FUSE_MEK_BCH_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_3_CUST_FUSE_MEK_BCH_3_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_3_RESETVAL                     (0x00000000U)

/* MEK_BCH_4 */

#define CSL_CONTROL_CORE_MEK_BCH_4_CUST_FUSE_MEK_BCH_4_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_4_CUST_FUSE_MEK_BCH_4_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_4_CUST_FUSE_MEK_BCH_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_4_CUST_FUSE_MEK_BCH_4_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_4_RESETVAL                     (0x00000000U)

/* MEK_BCH_5 */

#define CSL_CONTROL_CORE_MEK_BCH_5_CUST_FUSE_MEK_BCH_5_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_5_CUST_FUSE_MEK_BCH_5_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_5_CUST_FUSE_MEK_BCH_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_5_CUST_FUSE_MEK_BCH_5_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_5_RESETVAL                     (0x00000000U)

/* MEK_BCH_6 */

#define CSL_CONTROL_CORE_MEK_BCH_6_CUST_FUSE_MEK_BCH_6_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_6_CUST_FUSE_MEK_BCH_6_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_6_CUST_FUSE_MEK_BCH_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_6_CUST_FUSE_MEK_BCH_6_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_6_RESETVAL                     (0x00000000U)

/* MEK_BCH_7 */

#define CSL_CONTROL_CORE_MEK_BCH_7_CUST_FUSE_MEK_BCH_7_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_7_CUST_FUSE_MEK_BCH_7_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_7_CUST_FUSE_MEK_BCH_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_7_CUST_FUSE_MEK_BCH_7_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_7_RESETVAL                     (0x00000000U)

/* MEK_BCH_8 */

#define CSL_CONTROL_CORE_MEK_BCH_8_CUST_FUSE_MEK_BCH_8_MASK     (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_BCH_8_CUST_FUSE_MEK_BCH_8_SHIFT    (0U)
#define CSL_CONTROL_CORE_MEK_BCH_8_CUST_FUSE_MEK_BCH_8_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MEK_BCH_8_CUST_FUSE_MEK_BCH_8_MAX      (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_BCH_8_RESETVAL                     (0x00000000U)

/* MEK_0 */

#define CSL_CONTROL_CORE_MEK_0_CUST_FUSE_MEK_0_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_0_CUST_FUSE_MEK_0_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_0_CUST_FUSE_MEK_0_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_0_CUST_FUSE_MEK_0_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_0_RESETVAL                         (0x00000000U)

/* MEK_1 */

#define CSL_CONTROL_CORE_MEK_1_CUST_FUSE_MEK_1_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_1_CUST_FUSE_MEK_1_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_1_CUST_FUSE_MEK_1_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_1_CUST_FUSE_MEK_1_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_1_RESETVAL                         (0x00000000U)

/* MEK_2 */

#define CSL_CONTROL_CORE_MEK_2_CUST_FUSE_MEK_2_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_2_CUST_FUSE_MEK_2_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_2_CUST_FUSE_MEK_2_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_2_CUST_FUSE_MEK_2_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_2_RESETVAL                         (0x00000000U)

/* MEK_3 */

#define CSL_CONTROL_CORE_MEK_3_CUST_FUSE_MEK_3_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_3_CUST_FUSE_MEK_3_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_3_CUST_FUSE_MEK_3_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_3_CUST_FUSE_MEK_3_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_3_RESETVAL                         (0x00000000U)

/* MEK_4 */

#define CSL_CONTROL_CORE_MEK_4_CUST_FUSE_MEK_4_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_4_CUST_FUSE_MEK_4_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_4_CUST_FUSE_MEK_4_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_4_CUST_FUSE_MEK_4_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_4_RESETVAL                         (0x00000000U)

/* MEK_5 */

#define CSL_CONTROL_CORE_MEK_5_CUST_FUSE_MEK_5_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_5_CUST_FUSE_MEK_5_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_5_CUST_FUSE_MEK_5_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_5_CUST_FUSE_MEK_5_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_5_RESETVAL                         (0x00000000U)

/* MEK_6 */

#define CSL_CONTROL_CORE_MEK_6_CUST_FUSE_MEK_6_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_6_CUST_FUSE_MEK_6_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_6_CUST_FUSE_MEK_6_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_6_CUST_FUSE_MEK_6_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_6_RESETVAL                         (0x00000000U)

/* MEK_7 */

#define CSL_CONTROL_CORE_MEK_7_CUST_FUSE_MEK_7_MASK             (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_MEK_7_CUST_FUSE_MEK_7_SHIFT            (0U)
#define CSL_CONTROL_CORE_MEK_7_CUST_FUSE_MEK_7_RESETVAL         (0x00000000U)
#define CSL_CONTROL_CORE_MEK_7_CUST_FUSE_MEK_7_MAX              (0xffffffffU)

#define CSL_CONTROL_CORE_MEK_7_RESETVAL                         (0x00000000U)

/* SMPK_BCH_0 */

#define CSL_CONTROL_CORE_SMPK_BCH_0_CUST_FUSE_SMPK_BCH_0_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_0_CUST_FUSE_SMPK_BCH_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_0_CUST_FUSE_SMPK_BCH_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_0_CUST_FUSE_SMPK_BCH_0_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_0_RESETVAL                    (0x00000000U)

/* SMPK_BCH_1 */

#define CSL_CONTROL_CORE_SMPK_BCH_1_CUST_FUSE_SMPK_BCH_1_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_1_CUST_FUSE_SMPK_BCH_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_1_CUST_FUSE_SMPK_BCH_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_1_CUST_FUSE_SMPK_BCH_1_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_1_RESETVAL                    (0x00000000U)

/* SMPK_BCH_2 */

#define CSL_CONTROL_CORE_SMPK_BCH_2_CUST_FUSE_SMPK_BCH_2_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_2_CUST_FUSE_SMPK_BCH_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_2_CUST_FUSE_SMPK_BCH_2_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_2_CUST_FUSE_SMPK_BCH_2_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_2_RESETVAL                    (0x00000000U)

/* SMPK_BCH_3 */

#define CSL_CONTROL_CORE_SMPK_BCH_3_CUST_FUSE_SMPK_BCH_3_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_3_CUST_FUSE_SMPK_BCH_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_3_CUST_FUSE_SMPK_BCH_3_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_3_CUST_FUSE_SMPK_BCH_3_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_3_RESETVAL                    (0x00000000U)

/* SMPK_BCH_4 */

#define CSL_CONTROL_CORE_SMPK_BCH_4_CUST_FUSE_SMPK_BCH_4_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_4_CUST_FUSE_SMPK_BCH_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_4_CUST_FUSE_SMPK_BCH_4_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_4_CUST_FUSE_SMPK_BCH_4_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_4_RESETVAL                    (0x00000000U)

/* SMPK_BCH_5 */

#define CSL_CONTROL_CORE_SMPK_BCH_5_CUST_FUSE_SMPK_BCH_5_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_5_CUST_FUSE_SMPK_BCH_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_5_CUST_FUSE_SMPK_BCH_5_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_5_CUST_FUSE_SMPK_BCH_5_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_5_RESETVAL                    (0x00000000U)

/* SMPK_BCH_6 */

#define CSL_CONTROL_CORE_SMPK_BCH_6_CUST_FUSE_SMPK_BCH_6_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_6_CUST_FUSE_SMPK_BCH_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_6_CUST_FUSE_SMPK_BCH_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_6_CUST_FUSE_SMPK_BCH_6_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_6_RESETVAL                    (0x00000000U)

/* SMPK_BCH_7 */

#define CSL_CONTROL_CORE_SMPK_BCH_7_CUST_FUSE_SMPK_BCH_7_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_7_CUST_FUSE_SMPK_BCH_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_7_CUST_FUSE_SMPK_BCH_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_7_CUST_FUSE_SMPK_BCH_7_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_7_RESETVAL                    (0x00000000U)

/* SMPK_BCH_8 */

#define CSL_CONTROL_CORE_SMPK_BCH_8_CUST_FUSE_SMPK_BCH_8_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_BCH_8_CUST_FUSE_SMPK_BCH_8_SHIFT  (0U)
#define CSL_CONTROL_CORE_SMPK_BCH_8_CUST_FUSE_SMPK_BCH_8_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_BCH_8_CUST_FUSE_SMPK_BCH_8_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_BCH_8_RESETVAL                    (0x00000000U)

/* SMPK_0 */

#define CSL_CONTROL_CORE_SMPK_0_CUST_FUSE_SMPK_0_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_0_CUST_FUSE_SMPK_0_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_0_CUST_FUSE_SMPK_0_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_0_CUST_FUSE_SMPK_0_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_0_RESETVAL                        (0x00000000U)

/* SMPK_1 */

#define CSL_CONTROL_CORE_SMPK_1_CUST_FUSE_SMPK_1_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_1_CUST_FUSE_SMPK_1_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_1_CUST_FUSE_SMPK_1_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_1_CUST_FUSE_SMPK_1_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_1_RESETVAL                        (0x00000000U)

/* SMPK_2 */

#define CSL_CONTROL_CORE_SMPK_2_CUST_FUSE_SMPK_2_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_2_CUST_FUSE_SMPK_2_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_2_CUST_FUSE_SMPK_2_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_2_CUST_FUSE_SMPK_2_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_2_RESETVAL                        (0x00000000U)

/* SMPK_3 */

#define CSL_CONTROL_CORE_SMPK_3_CUST_FUSE_SMPK_3_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_3_CUST_FUSE_SMPK_3_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_3_CUST_FUSE_SMPK_3_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_3_CUST_FUSE_SMPK_3_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_3_RESETVAL                        (0x00000000U)

/* SMPK_4 */

#define CSL_CONTROL_CORE_SMPK_4_CUST_FUSE_SMPK_4_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_4_CUST_FUSE_SMPK_4_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_4_CUST_FUSE_SMPK_4_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_4_CUST_FUSE_SMPK_4_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_4_RESETVAL                        (0x00000000U)

/* SMPK_5 */

#define CSL_CONTROL_CORE_SMPK_5_CUST_FUSE_SMPK_5_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_5_CUST_FUSE_SMPK_5_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_5_CUST_FUSE_SMPK_5_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_5_CUST_FUSE_SMPK_5_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_5_RESETVAL                        (0x00000000U)

/* SMPK_6 */

#define CSL_CONTROL_CORE_SMPK_6_CUST_FUSE_SMPK_6_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_6_CUST_FUSE_SMPK_6_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_6_CUST_FUSE_SMPK_6_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_6_CUST_FUSE_SMPK_6_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_6_RESETVAL                        (0x00000000U)

/* SMPK_7 */

#define CSL_CONTROL_CORE_SMPK_7_CUST_FUSE_SMPK_7_MASK           (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SMPK_7_CUST_FUSE_SMPK_7_SHIFT          (0U)
#define CSL_CONTROL_CORE_SMPK_7_CUST_FUSE_SMPK_7_RESETVAL       (0x00000000U)
#define CSL_CONTROL_CORE_SMPK_7_CUST_FUSE_SMPK_7_MAX            (0xffffffffU)

#define CSL_CONTROL_CORE_SMPK_7_RESETVAL                        (0x00000000U)

/* SEC_SWRV_0 */

#define CSL_CONTROL_CORE_SEC_SWRV_0_CUST_FUSE_SEC_SWRV_0_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SWRV_0_CUST_FUSE_SEC_SWRV_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SWRV_0_CUST_FUSE_SEC_SWRV_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SWRV_0_CUST_FUSE_SEC_SWRV_0_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SWRV_0_RESETVAL                    (0x00000000U)

/* SEC_SWRV_1 */

#define CSL_CONTROL_CORE_SEC_SWRV_1_CUST_FUSE_SEC_SWRV_1_MASK   (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_SEC_SWRV_1_CUST_FUSE_SEC_SWRV_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_SEC_SWRV_1_CUST_FUSE_SEC_SWRV_1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_SEC_SWRV_1_CUST_FUSE_SEC_SWRV_1_MAX    (0xffffffffU)

#define CSL_CONTROL_CORE_SEC_SWRV_1_RESETVAL                    (0x00000000U)

/* MREQDOMAIN_EXP6 */

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EXP6_LOCK_MASK  (0x80000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EXP6_LOCK_SHIFT  (31U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EXP6_LOCK_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EXP6_LOCK_MAX  (0x00000001U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_SPARE_SATA2_RESERVED_MASK  (0x00000038U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_SPARE_SATA2_RESERVED_SHIFT  (3U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_SPARE_SATA2_RESERVED_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_SPARE_SATA2_RESERVED_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EVE4_TC1_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EVE4_TC1_SHIFT  (0U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EVE4_TC1_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_MREQDOMAIN_EVE4_TC1_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_MREQDOMAIN_EXP6_RESETVAL               (0x00000000U)

/* HWOBS_FINAL_MUX_SEL */

#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL_DEBOBS_FINAL_MUX_SEL_MASK  (0xFFFFFFFFU)
#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL_DEBOBS_FINAL_MUX_SEL_SHIFT  (0U)
#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL_DEBOBS_FINAL_MUX_SEL_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL_DEBOBS_FINAL_MUX_SEL_MAX  (0xffffffffU)

#define CSL_CONTROL_CORE_HWOBS_FINAL_MUX_SEL_RESETVAL           (0x00000000U)

/* HWOBS_MMR_MPU */

#define CSL_CONTROL_CORE_HWOBS_MMR_MPU_DEBOBS_MMR_MPU_MASK      (0x0000000FU)
#define CSL_CONTROL_CORE_HWOBS_MMR_MPU_DEBOBS_MMR_MPU_SHIFT     (0U)
#define CSL_CONTROL_CORE_HWOBS_MMR_MPU_DEBOBS_MMR_MPU_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_HWOBS_MMR_MPU_DEBOBS_MMR_MPU_MAX       (0x0000000fU)

#define CSL_CONTROL_CORE_HWOBS_MMR_MPU_RESETVAL                 (0x00000000U)

/* CONF_DEBUG_SEL_TST_0 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0_CONF_DEBUG_SEL_TST_0_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0_CONF_DEBUG_SEL_TST_0_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0_CONF_DEBUG_SEL_TST_0_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0_CONF_DEBUG_SEL_TST_0_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_0_RESETVAL          (0x00000000U)

/* CONF_DEBUG_SEL_TST_1 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1_CONF_DEBUG_SEL_TST_1_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1_CONF_DEBUG_SEL_TST_1_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1_CONF_DEBUG_SEL_TST_1_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1_CONF_DEBUG_SEL_TST_1_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_1_RESETVAL          (0x00000001U)

/* CONF_DEBUG_SEL_TST_2 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2_CONF_DEBUG_SEL_TST_2_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2_CONF_DEBUG_SEL_TST_2_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2_CONF_DEBUG_SEL_TST_2_RESETVAL  (0x00000002U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2_CONF_DEBUG_SEL_TST_2_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_2_RESETVAL          (0x00000002U)

/* CONF_DEBUG_SEL_TST_3 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3_CONF_DEBUG_SEL_TST_3_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3_CONF_DEBUG_SEL_TST_3_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3_CONF_DEBUG_SEL_TST_3_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3_CONF_DEBUG_SEL_TST_3_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_3_RESETVAL          (0x00000003U)

/* CONF_DEBUG_SEL_TST_4 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4_CONF_DEBUG_SEL_TST_4_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4_CONF_DEBUG_SEL_TST_4_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4_CONF_DEBUG_SEL_TST_4_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4_CONF_DEBUG_SEL_TST_4_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_4_RESETVAL          (0x00000004U)

/* CONF_DEBUG_SEL_TST_5 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5_CONF_DEBUG_SEL_TST_5_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5_CONF_DEBUG_SEL_TST_5_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5_CONF_DEBUG_SEL_TST_5_RESETVAL  (0x00000005U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5_CONF_DEBUG_SEL_TST_5_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_5_RESETVAL          (0x00000005U)

/* CONF_DEBUG_SEL_TST_6 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6_CONF_DEBUG_SEL_TST_6_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6_CONF_DEBUG_SEL_TST_6_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6_CONF_DEBUG_SEL_TST_6_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6_CONF_DEBUG_SEL_TST_6_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_6_RESETVAL          (0x00000000U)

/* CONF_DEBUG_SEL_TST_7 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7_CONF_DEBUG_SEL_TST_7_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7_CONF_DEBUG_SEL_TST_7_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7_CONF_DEBUG_SEL_TST_7_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7_CONF_DEBUG_SEL_TST_7_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_7_RESETVAL          (0x00000000U)

/* CONF_DEBUG_SEL_TST_8 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8_CONF_DEBUG_SEL_TST_8_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8_CONF_DEBUG_SEL_TST_8_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8_CONF_DEBUG_SEL_TST_8_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8_CONF_DEBUG_SEL_TST_8_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_8_RESETVAL          (0x00000001U)

/* CONF_DEBUG_SEL_TST_9 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9_CONF_DEBUG_SEL_TST_9_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9_CONF_DEBUG_SEL_TST_9_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9_CONF_DEBUG_SEL_TST_9_RESETVAL  (0x00000002U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9_CONF_DEBUG_SEL_TST_9_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_9_RESETVAL          (0x00000002U)

/* CONF_DEBUG_SEL_TST_10 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10_CONF_DEBUG_SEL_TST_10_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10_CONF_DEBUG_SEL_TST_10_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10_CONF_DEBUG_SEL_TST_10_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10_CONF_DEBUG_SEL_TST_10_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_10_RESETVAL         (0x00000003U)

/* CONF_DEBUG_SEL_TST_11 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11_CONF_DEBUG_SEL_TST_11_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11_CONF_DEBUG_SEL_TST_11_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11_CONF_DEBUG_SEL_TST_11_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11_CONF_DEBUG_SEL_TST_11_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_11_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_12 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12_CONF_DEBUG_SEL_TST_12_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12_CONF_DEBUG_SEL_TST_12_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12_CONF_DEBUG_SEL_TST_12_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12_CONF_DEBUG_SEL_TST_12_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_12_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_13 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13_CONF_DEBUG_SEL_TST_13_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13_CONF_DEBUG_SEL_TST_13_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13_CONF_DEBUG_SEL_TST_13_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13_CONF_DEBUG_SEL_TST_13_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_13_RESETVAL         (0x00000001U)

/* CONF_DEBUG_SEL_TST_14 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14_CONF_DEBUG_SEL_TST_14_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14_CONF_DEBUG_SEL_TST_14_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14_CONF_DEBUG_SEL_TST_14_RESETVAL  (0x00000002U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14_CONF_DEBUG_SEL_TST_14_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_14_RESETVAL         (0x00000002U)

/* CONF_DEBUG_SEL_TST_15 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15_CONF_DEBUG_SEL_TST_15_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15_CONF_DEBUG_SEL_TST_15_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15_CONF_DEBUG_SEL_TST_15_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15_CONF_DEBUG_SEL_TST_15_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_15_RESETVAL         (0x00000003U)

/* CONF_DEBUG_SEL_TST_16 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16_CONF_DEBUG_SEL_TST_16_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16_CONF_DEBUG_SEL_TST_16_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16_CONF_DEBUG_SEL_TST_16_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16_CONF_DEBUG_SEL_TST_16_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_16_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_17 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17_CONF_DEBUG_SEL_TST_17_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17_CONF_DEBUG_SEL_TST_17_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17_CONF_DEBUG_SEL_TST_17_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17_CONF_DEBUG_SEL_TST_17_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_17_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_18 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18_CONF_DEBUG_SEL_TST_18_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18_CONF_DEBUG_SEL_TST_18_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18_CONF_DEBUG_SEL_TST_18_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18_CONF_DEBUG_SEL_TST_18_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_18_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_19 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19_CONF_DEBUG_SEL_TST_19_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19_CONF_DEBUG_SEL_TST_19_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19_CONF_DEBUG_SEL_TST_19_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19_CONF_DEBUG_SEL_TST_19_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_19_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_20 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20_CONF_DEBUG_SEL_TST_20_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20_CONF_DEBUG_SEL_TST_20_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20_CONF_DEBUG_SEL_TST_20_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20_CONF_DEBUG_SEL_TST_20_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_20_RESETVAL         (0x00000001U)

/* CONF_DEBUG_SEL_TST_21 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21_CONF_DEBUG_SEL_TST_21_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21_CONF_DEBUG_SEL_TST_21_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21_CONF_DEBUG_SEL_TST_21_RESETVAL  (0x00000002U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21_CONF_DEBUG_SEL_TST_21_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_21_RESETVAL         (0x00000002U)

/* CONF_DEBUG_SEL_TST_22 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22_CONF_DEBUG_SEL_TST_22_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22_CONF_DEBUG_SEL_TST_22_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22_CONF_DEBUG_SEL_TST_22_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22_CONF_DEBUG_SEL_TST_22_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_22_RESETVAL         (0x00000003U)

/* CONF_DEBUG_SEL_TST_23 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23_CONF_DEBUG_SEL_TST_23_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23_CONF_DEBUG_SEL_TST_23_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23_CONF_DEBUG_SEL_TST_23_RESETVAL  (0x00000004U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23_CONF_DEBUG_SEL_TST_23_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_23_RESETVAL         (0x00000004U)

/* CONF_DEBUG_SEL_TST_24 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24_CONF_DEBUG_SEL_TST_24_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24_CONF_DEBUG_SEL_TST_24_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24_CONF_DEBUG_SEL_TST_24_RESETVAL  (0x00000005U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24_CONF_DEBUG_SEL_TST_24_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_24_RESETVAL         (0x00000005U)

/* CONF_DEBUG_SEL_TST_25 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25_CONF_DEBUG_SEL_TST_25_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25_CONF_DEBUG_SEL_TST_25_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25_CONF_DEBUG_SEL_TST_25_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25_CONF_DEBUG_SEL_TST_25_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_25_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_26 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26_CONF_DEBUG_SEL_TST_26_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26_CONF_DEBUG_SEL_TST_26_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26_CONF_DEBUG_SEL_TST_26_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26_CONF_DEBUG_SEL_TST_26_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_26_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_27 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27_CONF_DEBUG_SEL_TST_27_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27_CONF_DEBUG_SEL_TST_27_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27_CONF_DEBUG_SEL_TST_27_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27_CONF_DEBUG_SEL_TST_27_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_27_RESETVAL         (0x00000001U)

/* CONF_DEBUG_SEL_TST_28 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28_CONF_DEBUG_SEL_TST_28_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28_CONF_DEBUG_SEL_TST_28_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28_CONF_DEBUG_SEL_TST_28_RESETVAL  (0x00000002U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28_CONF_DEBUG_SEL_TST_28_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_28_RESETVAL         (0x00000002U)

/* CONF_DEBUG_SEL_TST_29 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29_CONF_DEBUG_SEL_TST_29_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29_CONF_DEBUG_SEL_TST_29_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29_CONF_DEBUG_SEL_TST_29_RESETVAL  (0x00000003U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29_CONF_DEBUG_SEL_TST_29_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_29_RESETVAL         (0x00000003U)

/* CONF_DEBUG_SEL_TST_30 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30_CONF_DEBUG_SEL_TST_30_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30_CONF_DEBUG_SEL_TST_30_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30_CONF_DEBUG_SEL_TST_30_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30_CONF_DEBUG_SEL_TST_30_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_30_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_31 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31_CONF_DEBUG_SEL_TST_31_MASK  (0x0000003FU)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31_CONF_DEBUG_SEL_TST_31_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31_CONF_DEBUG_SEL_TST_31_RESETVAL  (0x00000001U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31_CONF_DEBUG_SEL_TST_31_MAX  (0x0000003fU)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_31_RESETVAL         (0x00000001U)

/* CONF_DEBUG_SEL_TST_32 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32_CONF_DEBUG_SEL_TST_32_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32_CONF_DEBUG_SEL_TST_32_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32_CONF_DEBUG_SEL_TST_32_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32_CONF_DEBUG_SEL_TST_32_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_32_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_33 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33_CONF_DEBUG_SEL_TST_33_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33_CONF_DEBUG_SEL_TST_33_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33_CONF_DEBUG_SEL_TST_33_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33_CONF_DEBUG_SEL_TST_33_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_33_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_34 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34_CONF_DEBUG_SEL_TST_34_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34_CONF_DEBUG_SEL_TST_34_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34_CONF_DEBUG_SEL_TST_34_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34_CONF_DEBUG_SEL_TST_34_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_34_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_35 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35_CONF_DEBUG_SEL_TST_35_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35_CONF_DEBUG_SEL_TST_35_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35_CONF_DEBUG_SEL_TST_35_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35_CONF_DEBUG_SEL_TST_35_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_35_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_36 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36_CONF_DEBUG_SEL_TST_36_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36_CONF_DEBUG_SEL_TST_36_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36_CONF_DEBUG_SEL_TST_36_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36_CONF_DEBUG_SEL_TST_36_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_36_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_37 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37_CONF_DEBUG_SEL_TST_37_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37_CONF_DEBUG_SEL_TST_37_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37_CONF_DEBUG_SEL_TST_37_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37_CONF_DEBUG_SEL_TST_37_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_37_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_38 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38_CONF_DEBUG_SEL_TST_38_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38_CONF_DEBUG_SEL_TST_38_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38_CONF_DEBUG_SEL_TST_38_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38_CONF_DEBUG_SEL_TST_38_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_38_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_39 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39_CONF_DEBUG_SEL_TST_39_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39_CONF_DEBUG_SEL_TST_39_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39_CONF_DEBUG_SEL_TST_39_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39_CONF_DEBUG_SEL_TST_39_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_39_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_40 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40_CONF_DEBUG_SEL_TST_40_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40_CONF_DEBUG_SEL_TST_40_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40_CONF_DEBUG_SEL_TST_40_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40_CONF_DEBUG_SEL_TST_40_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_40_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_41 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41_CONF_DEBUG_SEL_TST_41_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41_CONF_DEBUG_SEL_TST_41_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41_CONF_DEBUG_SEL_TST_41_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41_CONF_DEBUG_SEL_TST_41_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_41_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_42 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42_CONF_DEBUG_SEL_TST_42_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42_CONF_DEBUG_SEL_TST_42_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42_CONF_DEBUG_SEL_TST_42_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42_CONF_DEBUG_SEL_TST_42_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_42_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_43 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43_CONF_DEBUG_SEL_TST_43_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43_CONF_DEBUG_SEL_TST_43_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43_CONF_DEBUG_SEL_TST_43_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43_CONF_DEBUG_SEL_TST_43_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_43_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_44 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44_CONF_DEBUG_SEL_TST_44_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44_CONF_DEBUG_SEL_TST_44_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44_CONF_DEBUG_SEL_TST_44_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44_CONF_DEBUG_SEL_TST_44_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_44_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_45 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45_CONF_DEBUG_SEL_TST_45_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45_CONF_DEBUG_SEL_TST_45_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45_CONF_DEBUG_SEL_TST_45_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45_CONF_DEBUG_SEL_TST_45_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_45_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_46 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46_CONF_DEBUG_SEL_TST_46_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46_CONF_DEBUG_SEL_TST_46_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46_CONF_DEBUG_SEL_TST_46_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46_CONF_DEBUG_SEL_TST_46_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_46_RESETVAL         (0x00000000U)

/* CONF_DEBUG_SEL_TST_47 */

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47_CONF_DEBUG_SEL_TST_47_MASK  (0x00000007U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47_CONF_DEBUG_SEL_TST_47_SHIFT  (0U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47_CONF_DEBUG_SEL_TST_47_RESETVAL  (0x00000000U)
#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47_CONF_DEBUG_SEL_TST_47_MAX  (0x00000007U)

#define CSL_CONTROL_CORE_CONF_DEBUG_SEL_TST_47_RESETVAL         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
