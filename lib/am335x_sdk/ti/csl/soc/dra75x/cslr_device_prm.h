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
#ifndef CSLR_DEVICE_PRM_H
#define CSLR_DEVICE_PRM_H

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
    volatile Uint32 PRM_RSTCTRL_REG;
    volatile Uint32 PRM_RSTST_REG;
    volatile Uint32 PRM_RSTTIME_REG;
    volatile Uint32 PRM_CLKREQCTRL_REG;
    volatile Uint32 PRM_VOLTCTRL_REG;
    volatile Uint32 PRM_PWRREQCTRL_REG;
    volatile Uint32 PRM_PSCON_COUNT_REG;
    volatile Uint32 PRM_IO_COUNT_REG;
    volatile Uint32 PRM_IO_PMCTRL_REG;
    volatile Uint32 PRM_VOLTSETUP_WARMRESET_REG;
    volatile Uint32 PRM_VOLTSETUP_CORE_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_MPU_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_MM_OFF_REG;
    volatile Uint32 PRM_VOLTSETUP_CORE_RET_SLEEP_REG;
    volatile Uint32 PRM_VOLTSETUP_MPU_RET_SLEEP_REG;
    volatile Uint32 PRM_VOLTSETUP_MM_RET_SLEEP_REG;
    volatile Uint32 PRM_VP_CORE_CONFIG_REG;
    volatile Uint32 PRM_VP_CORE_STATUS_REG;
    volatile Uint32 PRM_VP_CORE_VLIMITTO_REG;
    volatile Uint32 PRM_VP_CORE_VOLTAGE_REG;
    volatile Uint32 PRM_VP_CORE_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_CORE_VSTEPMIN_REG;
    volatile Uint32 PRM_VP_MPU_CONFIG_REG;
    volatile Uint32 PRM_VP_MPU_STATUS_REG;
    volatile Uint32 PRM_VP_MPU_VLIMITTO_REG;
    volatile Uint32 PRM_VP_MPU_VOLTAGE_REG;
    volatile Uint32 PRM_VP_MPU_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_MPU_VSTEPMIN_REG;
    volatile Uint32 PRM_VP_MM_CONFIG_REG;
    volatile Uint32 PRM_VP_MM_STATUS_REG;
    volatile Uint32 PRM_VP_MM_VLIMITTO_REG;
    volatile Uint32 PRM_VP_MM_VOLTAGE_REG;
    volatile Uint32 PRM_VP_MM_VSTEPMAX_REG;
    volatile Uint32 PRM_VP_MM_VSTEPMIN_REG;
    volatile Uint32 PRM_VC_SMPS_CORE_CONFIG_REG;
    volatile Uint32 PRM_VC_SMPS_MM_CONFIG_REG;
    volatile Uint32 PRM_VC_SMPS_MPU_CONFIG_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_CORE_L_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_MM_L_REG;
    volatile Uint32 PRM_VC_VAL_CMD_VDD_MPU_L_REG;
    volatile Uint32 PRM_VC_VAL_BYPASS_REG;
    volatile Uint32 PRM_VC_CORE_ERRST_REG;
    volatile Uint32 PRM_VC_MM_ERRST_REG;
    volatile Uint32 PRM_VC_MPU_ERRST_REG;
    volatile Uint32 PRM_VC_BYPASS_ERRST_REG;
    volatile Uint32 PRM_VC_CFG_I2C_MODE_REG;
    volatile Uint32 PRM_VC_CFG_I2C_CLK_REG;
    volatile Uint32 PRM_SRAM_COUNT_REG;
    volatile Uint32 PRM_SRAM_WKUP_SETUP_REG;
    volatile Uint32 PRM_SLDO_CORE_SETUP_REG;
    volatile Uint32 PRM_SLDO_CORE_CTRL_REG;
    volatile Uint32 PRM_SLDO_MPU_SETUP_REG;
    volatile Uint32 PRM_SLDO_MPU_CTRL_REG;
    volatile Uint32 PRM_SLDO_GPU_SETUP_REG;
    volatile Uint32 PRM_SLDO_GPU_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_MPU_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_MPU_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_GPU_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_GPU_CTRL_REG;
    volatile Uint32 PRM_BANDGAP_SETUP_REG;
    volatile Uint32 PRM_DEVICE_OFF_CTRL_REG;
    volatile Uint32 PRM_PHASE1_CNDP_REG;
    volatile Uint32 PRM_PHASE2A_CNDP_REG;
    volatile Uint32 PRM_PHASE2B_CNDP_REG;
    volatile Uint32 PRM_MODEM_IF_CTRL_REG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 PRM_VOLTST_MPU_REG;
    volatile Uint32 PRM_VOLTST_MM_REG;
    volatile Uint32 PRM_SLDO_DSPEVE_SETUP_REG;
    volatile Uint32 PRM_SLDO_IVA_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_DSPEVE_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_IVA_CTRL_REG;
    volatile Uint32 PRM_SLDO_DSPEVE_CTRL_REG;
    volatile Uint32 PRM_SLDO_IVA_CTRL_REG;
    volatile Uint32 PRM_ABBLDO_DSPEVE_SETUP_REG;
    volatile Uint32 PRM_ABBLDO_IVA_SETUP_REG;
} CSL_device_prmRegs;

#define CSL_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_MASK          (PRM_IO_PMCTRL_ISOCLK_OVERRIDE_MASK)
#define CSL_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_SHIFT         (PRM_IO_PMCTRL_ISOCLK_OVERRIDE_SHIFT)
#define CSL_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE    (PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE)
#define CSL_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE      (PRM_IO_PMCTRL_ISOCLK_OVERRIDE_OVERRIDE)

#define CSL_PRM_IO_PMCTRL_ISOCLK_STATUS_MASK            (PRM_IO_PMCTRL_ISOCLK_STATUS_MASK)
#define CSL_PRM_IO_PMCTRL_ISOCLK_STATUS_SHIFT           (PRM_IO_PMCTRL_ISOCLK_STATUS_SHIFT)

#ifdef __cplusplus
}
#endif
#endif
