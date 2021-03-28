/******************************************************************************
 * Copyright (c) 2010-2015 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_cfg.h"
#include "board_internal.h"

#include <ti/csl/csl_emif4fAux.h>
#include <ti/csl/cslr_dmm.h>
#include <ti/csl/cslr_ma_mpu_lsm.h>
#include <ti/csl/src/ip/emif4/V2/csl_emif4d5.h>

#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)

static void ddr_delay(uint32_t ix);

static void ddr_delay(uint32_t ix)
{
    while (ix--) {
        asm("   NOP");
    }
}

void emifConfigureDdr3
(
    CSL_emifHandle hEmif,
    CSL_emifDdrConfig *ddr3Config,
    Uint32 enableHwLeveling
);

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_DDR3Init()
{
    CSL_emifObj emifObj1;
    CSL_emifHandle hEmif1 = &emifObj1;
    CSL_emifDdrConfig ddr3Config1;
    CSL_ckgen_cm_core_aonRegs *hCkgenCmCoreAon =
        (CSL_ckgen_cm_core_aonRegs *) CSL_MPU_CKGEN_CM_CORE_AON_REGS;
    CSL_control_core_padRegs *hCtrlCorePad =
        (CSL_control_core_padRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_REGS;
    CSL_control_core_wkupRegs *hCtrlCoreWkup =
        (CSL_control_core_wkupRegs *) CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS;
    CSL_DmmRegs *hDmmCfg =(CSL_DmmRegs *) CSL_MPU_DMM_CONF_REGS_REGS;
    CSL_MampuLsmRegs *hMampuLsm = (CSL_MampuLsmRegs *) CSL_MPU_MA_MPU_LSM_REGS;

    hEmif1->regs = (CSL_emifRegsOvly)CSL_MPU_EMIF1_CONF_REGS_REGS;

    /* DLL override disable =0 ; enable = 1 */
    hCkgenCmCoreAon->CM_DLL_CTRL_REG = 0x00000000;

    /*
     * CONTROL_DDR3CH1_0 -- channel_1 CMDs
     * -- 40Ohm Ron (011)
     * -- SR=slowest-3 (111) on CMDs
     * -- CLK SR=slow (011)
     * -- No pulls (00)
     */
    hCtrlCorePad->CONTROL_DDRCACH1_0 = 0x80808080;

    /*
     * CONTROL_DDR3CH2_0 -- channel_2 CMDs
     * -- 40Ohm Ron (011)
     * -- SR=slowest-3 (111) on CMDs
     * -- CLK SR=slow (011)
     * -- No pulls (00)
     */
    hCtrlCorePad->CONTROL_DDRCACH2_0 = 0x80808080;

    /*
     * CONTROL_DDRCH1_0 -- channel_1 DATA byte 0+1
     * -- 40Ohm Ron (011)
     * -- SR=faster (001)
     * -- Pull-up (10) on DQS
     * -- No pull (00) on DQ
     */
    hCtrlCorePad->CONTROL_DDRCH1_0 = 0x40404040;

    /*
     * CONTROL_DDRCH1_1 -- channel_1 DATA byte 2+3
     * -- 40Ohm Ron (011)
     * -- SR=faster (001)
     * -- Pull-up (10) on DQS
     * -- No pull (00) on DQ
     */
    hCtrlCorePad->CONTROL_DDRCH1_1 = 0x40404040;

    /*
     * CONTROL_DDRCH2_0 -- channel_2 DATA byte 0+1
     * -- 40Ohm Ron (011)
     * -- SR=faster (001)
     * -- Pull-up (10) on DQS
     * -- No pull (00) on DQ
     */
    hCtrlCorePad->CONTROL_DDRCH2_0 = 0x40404040;

    /*
     * CONTROL_DDRCH2_1 -- channel_2 DATA byte 2+3
     * -- 40Ohm Ron (011)
     * -- SR=faster (001)
     * -- Pull-up (10) on DQS
     * -- No pull (00) on DQ
     */
    hCtrlCorePad->CONTROL_DDRCH2_1 = 0x40404040;

    /*
     * CONTROL_LPDDR2CH1_0
     * -- channel_1 LPDDR2 CMD PHYs IOs not used
     */
    hCtrlCorePad->CONTROL_DDRCH1_2 = 0x40404040;

    /*
     * CONTROL_CONTROL_LPDDR2CH1_1
     * -- channel_1 LPDDR2 CMD PHYs IOs not used
     */
    hCtrlCorePad->CONTROL_DDRCH2_2 = 0x80808080;

    /*
     * DDRIO_0 -- VREF cells
     * (CH1 DQ3/0 INT 2uA / Cap to GND / CMD1/0 DDR3 INT-OUT 32uA / Cap to GND)
     */
    hCtrlCorePad->CONTROL_DDRIO_0 = 0xA2084210;

    /*
     * DDRIO_1 -- VREF cells
     * (CH1 OUT 32uA Cap to GND / CH2 DQ3/0 INT 2uA / Cap to GND / CH2 OUT 32uA Cap to GND)
     */
    hCtrlCorePad->CONTROL_DDRIO_1 = 0x84210840;

    /*
     * DDRIO_2 -- VREF cells (LPDDR2 CH1/2 CA INT/OUT - unused on OMAP5432)
     */
    hCtrlCorePad->CONTROL_HYST_1 = 0x84210000;

    /* CONTROL_DDRIO_EXT_0 */
    hCtrlCorePad->CONTROL_DDRIO_EXT_0 = 0xA2000000;

    /*
     * EMIF1_SDRAM_CONFIG_EXT
     * -- cslice_en[2:0]=111 / Local_odt=01 / dyn_pwrdn=1 / dis_reset=0 / rd_lvl_samples=11 (128)
     */
    hCtrlCoreWkup->EMIF1_SDRAM_CONFIG_EXT = 0x0001C127;

    ddr3Config1.emifDdrParam.ddrPhyCtrl = 0x0024400AU;
    ddr3Config1.emifDdrParam.sdramTim1 = 0xCEEF266BU;
    ddr3Config1.emifDdrParam.sdramTim2 = 0x328F7FDAU;
    ddr3Config1.emifDdrParam.sdramTim3 = 0x427F88A8U;
    ddr3Config1.emifDdrParam.sdramCfg = 0x61851B32U;
    ddr3Config1.emifDdrParam.sdramCfg2 = 0x00000000U;
    ddr3Config1.emifDdrParam.sdramRefCtrl = 0x00001035U;
    ddr3Config1.emifDdrParam.zqConfig = 0x0007190BU;
    ddr3Config1.emifDdrParam.sdramPwrMngtCtrl = 0x00000000U;

    ddr3Config1.emifDdrPhyParam.ctrlSlaveRatio = 0x100U;
    ddr3Config1.emifDdrPhyParam.gateLevelRatio = 0x40U;
    ddr3Config1.emifDdrPhyParam.writeLevelInitRatio = 0x00;
    ddr3Config1.emifDdrPhyParam.writeDqsSlaveRatio = 0U;
    ddr3Config1.emifDdrPhyParam.fifoWeSlaveRatio = 0U;
    ddr3Config1.emifDdrPhyParam.useRank0Delays = 0U;
    ddr3Config1.emifDdrPhyParam.fifoWeInDelay = 0x0U;
    ddr3Config1.emifDdrPhyParam.ctrlSlaveDelay = 0x0U;
    ddr3Config1.emifDdrPhyParam.readDqsSlaveDelay = 0x0020U;
    ddr3Config1.emifDdrPhyParam.writeDqsSlaveDelay = 0x0060U;
    ddr3Config1.emifDdrPhyParam.dqOffset = 0x40U;
    ddr3Config1.emifDdrPhyParam.gateLevelInitMode = 0x01U;
    ddr3Config1.emifDdrPhyParam.writeDataSlaveDelay = 0x80U;
    ddr3Config1.emifDdrPhyParam.gateLevelNumDq0 = 0xFU;
    ddr3Config1.emifDdrPhyParam.writeLevelNumDq0 = 0xFU;

    emifConfigureDdr3(hEmif1, &ddr3Config1, 1U);

    /* MA_LISA_MAP_i */
    hMampuLsm->MAP_0 = 0x80600100U;
    hMampuLsm->MAP_1 = 0x00000000U;
    hMampuLsm->MAP_2 = 0x00000000U;
    hMampuLsm->MAP_3 = 0x00000000U;

    /* DMM_LISA_MAP_i */
    hDmmCfg->LISA_MAP[0U] = 0x80600100U;
    hDmmCfg->LISA_MAP[1U] = 0x00000000U;
    hDmmCfg->LISA_MAP[2U] = 0x00000000U;
    hDmmCfg->LISA_MAP[3U] = 0x00000000U;

    return BOARD_SOK;
}

void emifConfigureDdr3
(
    CSL_emifHandle hEmif,
    CSL_emifDdrConfig *ddr3Config,
    Uint32 enableHwLeveling
)
{
    Uint32 regVal = 0U;

    hEmif->regs->DDR_PHY_CONTROL_1 = ddr3Config->emifDdrParam.ddrPhyCtrl;
    hEmif->regs->DDR_PHY_CONTROL_1_SHADOW = ddr3Config->emifDdrParam.ddrPhyCtrl;

    regVal = EXT_PHY_CTRL_VALUE(ddr3Config->emifDdrPhyParam.ctrlSlaveRatio);
    hEmif->regs->EXT_PHY_CONTROL_1 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_1_SHADOW = regVal;

    /* Force Slave ratio values not required if HW levelling is enabled */

    /* Use Init values if HW leveling is enabled */
    /* Gate level Init ratios */
    regVal = EXT_PHY_GATE_LVL_INIT_VALUE(ddr3Config->emifDdrPhyParam.gateLevelRatio);
    hEmif->regs->EXT_PHY_CONTROL_26 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_26_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_27 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_27_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_28 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_28_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_29 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_29_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_30 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_30_SHADOW = regVal;

    /* WR DQS Init ratios */
    regVal = EXT_PHY_WR_LVL_INIT_VALUE(ddr3Config->emifDdrPhyParam.writeLevelInitRatio);
    hEmif->regs->EXT_PHY_CONTROL_31 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_31_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_32 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_32_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_33 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_33_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_34 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_34_SHADOW = regVal;
    hEmif->regs->EXT_PHY_CONTROL_35 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_35_SHADOW = regVal;

    /* PHY settings for DQ offset, DLL override delay, levelling etc. */
    regVal = EXT_PHY_FIFO_WE_SLAVE_CTRL_DELAY(ddr3Config->emifDdrPhyParam.fifoWeInDelay,
            ddr3Config->emifDdrPhyParam.ctrlSlaveDelay);
    hEmif->regs->EXT_PHY_CONTROL_22 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_22_SHADOW = regVal;
    regVal = EXT_PHY_WR_RD_DQS_SLAVE_DELAY(ddr3Config->emifDdrPhyParam.writeDqsSlaveDelay,
            ddr3Config->emifDdrPhyParam.readDqsSlaveDelay);
    hEmif->regs->EXT_PHY_CONTROL_23 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_23_SHADOW = regVal;
    regVal = EXT_PHY_RANK0_DELAY_VALUE(ddr3Config->emifDdrPhyParam.dqOffset,
            ddr3Config->emifDdrPhyParam.gateLevelInitMode,
            ddr3Config->emifDdrPhyParam.useRank0Delays,
            ddr3Config->emifDdrPhyParam.writeDataSlaveDelay);
    hEmif->regs->EXT_PHY_CONTROL_24 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_24_SHADOW = regVal;
    regVal = EXT_PHY_DQ_VALUE(ddr3Config->emifDdrPhyParam.dqOffset);
    hEmif->regs->EXT_PHY_CONTROL_25 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_25_SHADOW = regVal;
    regVal = EXT_PHY_WR_LVL_GATE_LVL_NUM_DQ0(ddr3Config->emifDdrPhyParam.writeLevelNumDq0,
            ddr3Config->emifDdrPhyParam.gateLevelNumDq0);
    hEmif->regs->EXT_PHY_CONTROL_36 = regVal;
    hEmif->regs->EXT_PHY_CONTROL_36_SHADOW = regVal;

    /* Apply PHY RESET to latch all the PHY registers */
    hEmif->regs->IODFT_TEST_LOGIC_GLOBAL_CONTROL = 0x00002011;
    hEmif->regs->IODFT_TEST_LOGIC_GLOBAL_CONTROL = 0x00002411;
    hEmif->regs->IODFT_TEST_LOGIC_GLOBAL_CONTROL = 0x00002011;

    /* Disable initialization and refreshes until the EMIF is programmed */
    hEmif->regs->SDRAM_REFRESH_CONTROL = 0x80003000;
    hEmif->regs->SDRAM_REFRESH_CONTROL_SHADOW = 0x80003000;

    /* Set up the EMIF registers */
    hEmif->regs->SDRAM_TIMING_1 = ddr3Config->emifDdrParam.sdramTim1;
    hEmif->regs->SDRAM_TIMING_1_SHADOW = ddr3Config->emifDdrParam.sdramTim1;
    hEmif->regs->SDRAM_TIMING_2 = ddr3Config->emifDdrParam.sdramTim2;
    hEmif->regs->SDRAM_TIMING_2_SHADOW = ddr3Config->emifDdrParam.sdramTim2;
    hEmif->regs->SDRAM_TIMING_3 = ddr3Config->emifDdrParam.sdramTim3;
    hEmif->regs->SDRAM_TIMING_3_SHADOW = ddr3Config->emifDdrParam.sdramTim3;

    hEmif->regs->POWER_MANAGEMENT_CONTROL = ddr3Config->emifDdrParam.sdramPwrMngtCtrl;
    hEmif->regs->POWER_MANAGEMENT_CONTROL_SHADOW = ddr3Config->emifDdrParam.sdramPwrMngtCtrl;

    /* Leave these as RESET values */
    hEmif->regs->IODFT_TEST_LOGIC_GLOBAL_CONTROL = 0x00002011U;
    hEmif->regs->SDRAM_OUTPUT_IMPEDANCE_CALIBRATION_CONFIG = ddr3Config->emifDdrParam.zqConfig;
    hEmif->regs->READ_WRITE_LEVELING_RAMP_WINDOW = 0x00000000;
    hEmif->regs->READ_WRITE_LEVELING_RAMP_CONTROL = 0x80000000;
    hEmif->regs->READ_WRITE_LEVELING_CONTROL = 0x00000000;

    /* Set up long refresh time so that RESET-CKE timing is met */
    hEmif->regs->SDRAM_REFRESH_CONTROL_SHADOW = 0x3000;
    hEmif->regs->SDRAM_REFRESH_CONTROL = 0x3000;
    hEmif->regs->SDRAM_CONFIG_2 = ddr3Config->emifDdrParam.sdramCfg2;
    hEmif->regs->SDRAM_CONFIG = ddr3Config->emifDdrParam.sdramCfg;

    /* Now update with the correct refresh time */
    hEmif->regs->SDRAM_REFRESH_CONTROL_SHADOW = ddr3Config->emifDdrParam.sdramRefCtrl;
    hEmif->regs->SDRAM_REFRESH_CONTROL = ddr3Config->emifDdrParam.sdramRefCtrl;

    /* Some clock cycle delay for refresh to complete. */
    ddr_delay(100000);

    regVal = hEmif->regs->EXT_PHY_CONTROL_36;
    regVal = (regVal | 0x00000100U);
    hEmif->regs->EXT_PHY_CONTROL_36 = regVal;
    regVal = hEmif->regs->EXT_PHY_CONTROL_36_SHADOW;
    regVal = (regVal | 0x00000100U);
    hEmif->regs->EXT_PHY_CONTROL_36_SHADOW = regVal;

    hEmif->regs->READ_WRITE_LEVELING_RAMP_CONTROL = 0x80000000;
    hEmif->regs->READ_WRITE_LEVELING_CONTROL = 0x80000000;

    /* hwlvmod wait for read and write levelling bit to clear RDWRLVLFULL_START bit 31 */
    while((hEmif->regs->READ_WRITE_LEVELING_CONTROL & 0x80000000) != 0x0U);
}
