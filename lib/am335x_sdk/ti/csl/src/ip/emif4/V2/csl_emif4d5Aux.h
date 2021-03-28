/**
 *   @file  csl_emif4fAux.h
 *
 *   @brief
 *      This is the EMIF4F Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the EMIF4FV Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2013, Texas Instruments, Inc.
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

#ifndef CSL_EMIF4D5AUX_V2_H_
#define CSL_EMIF4D5AUX_V2_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/src/ip/emif4/V2/csl_emif4d5.h>

/** \brief Compute EMIF phy control. */
#define EXT_PHY_CTRL_VALUE(ctrlSlaveRatio)                                     \
    (((ctrlSlaveRatio) << 20U) | ((ctrlSlaveRatio) << 10U) | ((ctrlSlaveRatio) << 0U))

/** \brief Compute EMIF phy FIFO WE. */
#define EXT_PHY_FIFO_WE_VALUE(fifoWeSlaveRatio)                                \
    (((fifoWeSlaveRatio) << 16U) | ((fifoWeSlaveRatio) << 0U))

/** \brief Compute EMIF phy read DQS. */
#define EXT_PHY_RD_DQS_VALUE(rdDqsSlaveRatio)                                  \
    (((rdDqsSlaveRatio) << 16U) | ((rdDqsSlaveRatio) << 0U))

/** \brief Compute EMIF phy write data. */
#define EXT_PHY_WR_DATA_VALUE(wrDataslaveRatio)                                \
    (((wrDataslaveRatio) << 16U) | ((wrDataslaveRatio) << 0U))

/** \brief Compute EMIF phy write DQS. */
#define EXT_PHY_WR_DQS_VALUE(wrDqsSlaveRatio)                                  \
    (((wrDqsSlaveRatio) << 16U) | ((wrDqsSlaveRatio) << 0U))

/** \brief Compute EMIF phy DQ. */
#define EXT_PHY_DQ_VALUE(dqOffset)                                             \
    (((dqOffset) << 21U) | ((dqOffset) << 14U) | ((dqOffset) << 7U) | ((dqOffset) << 0U))

/** \brief Compute EMIF phy gate level init. */
#define EXT_PHY_GATE_LVL_INIT_VALUE(gateLvlInitRatio)                          \
    (((gateLvlInitRatio) << 16U) | ((gateLvlInitRatio) << 0U))

/** \brief Compute EMIF phy gate level init. */
#define EXT_PHY_WR_LVL_INIT_VALUE(wrLvlInitRatio)                              \
    (((wrLvlInitRatio) << 16U) | ((wrLvlInitRatio) << 0U))

/** \brief Compute EMIF phy . */
#define EXT_PHY_RANK0_DELAY_VALUE(dqOffset, gateLvlInitRatio, rank0Delay,      \
    wrDataslaveRatio)                                                          \
    (((dqOffset) << 24U) | ((gateLvlInitRatio) << 16U) | ((rank0Delay) << 12U) |     \
    ((wrDataslaveRatio) << 0U))

/** \brief Compute EMIF phy slave and Rank0 delays. */
#define EXT_PHY_RANK0_DELAY_MODE(dqOffset, gateLvlInitMode, rank0Delay,        \
    wrDataslaveDelay)                                                          \
    (((dqOffset) << 24U) | ((gateLvlInitMode) << 16U) | ((rank0Delay) << 12U) |      \
    ((wrDataslaveDelay) << 0U))

/** \brief Compute FIFO_WE_IN and Phy control slave delay .*/
#define EXT_PHY_FIFO_WE_SLAVE_CTRL_DELAY(fifoWeInDelay, ctrlSlaveDelay)        \
    (((fifoWeInDelay) << 16U) | ((ctrlSlaveDelay) << 0U))

/** \brief Compute WR_LVL_NUM_DQ0 and GATE_LVL_NUM_DQ0.*/
#define EXT_PHY_WR_LVL_GATE_LVL_NUM_DQ0(wrLvlNumDq0, gateLvlNumDq0)            \
    (((wrLvlNumDq0) << 4U) | ((gateLvlNumDq0) << 0U))

/** \brief Compute Read and WriteDQS slave delay. */
#define EXT_PHY_WR_RD_DQS_SLAVE_DELAY(wrDqsSlaveDelay, rdDqsSlaveDelay)        \
    (((wrDqsSlaveDelay) << 16U) | ((rdDqsSlaveDelay) << 0U))

/** @addtogroup CSL_EMIF4D5_FUNCTION
 @{ */

/** ============================================================================
 *   @n@b CSL_EMIF4D5_GetModuleInfo
 *
 *   @b Description
 *   @n This function reads the peripheral ID register which identifies the
 *      module id, RTL version information etc.
 *
 *   @b Arguments
     @verbatim
          moduleID     Module Id Information populated by this API
          rtlInfo      RTL Version Information populated by this API
          majRev       Major Revision Information populated by this API
          minRev       Minor Revision Information populated by this API
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @n None
 *
 *   <b> Pre Condition </b>
 *   @n None
 *
 *   <b> Post Condition </b>
 *   @n None
 *
 *   @b Reads
 *   @n EMIF4FV_EMIF_MOD_ID_REV_REG_MODULE_ID,EMIF4FV_EMIF_MOD_ID_REV_REG_RTL_VERSION,
 *      EMIF4FV_EMIF_MOD_ID_REV_REG_MAJOR_REVISION,EMIF4FV_EMIF_MOD_ID_REV_REG_MINOR_REVISION
 *
 *   @b Example
 *   @verbatim
        Uint8   moduleID;
        Uint8   rtlInfo;
        Uint8   majRev;
        Uint8   minRev;

        // Get the EMIF4F Module Information.
        CSL_EMIF4D5_GetModuleInfo (&moduleID, &rtlInfo, &majRev, &minRev);
        ...
     @endverbatim
 * =============================================================================
 */
static inline void CSL_emifConfigureDdr3
(
    CSL_emifHandle hEmif,
    CSL_emifDdrConfig *ddr3Config,
    Uint32 enableHwLeveling
);
static inline void CSL_emifConfigureDdr3
(
    CSL_emifHandle hEmif,
    CSL_emifDdrConfig *ddr3Config,
    Uint32 enableHwLeveling
)
{
    Uint32 regVal = 0U;
    Uint32 i = 0U;

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
    hEmif->regs->SDRAM_REFRESH_CONTROL = 0x80003000U;
    hEmif->regs->SDRAM_REFRESH_CONTROL_SHADOW = 0x80003000U;

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
    hEmif->regs->READ_WRITE_LEVELING_RAMP_CONTROL = 0x80000000U;
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
    for(i = 0; i < (uint32_t)1000U; i++){}

    regVal = hEmif->regs->EXT_PHY_CONTROL_36;
    regVal = (regVal | 0x00000100U);
    hEmif->regs->EXT_PHY_CONTROL_36_SHADOW = regVal;
    regVal = hEmif->regs->EXT_PHY_CONTROL_36_SHADOW;
    regVal = (regVal | 0x00000100U);
    hEmif->regs->EXT_PHY_CONTROL_36_SHADOW = regVal;

    hEmif->regs->READ_WRITE_LEVELING_RAMP_WINDOW = 0x00000000;
    hEmif->regs->READ_WRITE_LEVELING_RAMP_CONTROL = 0x80000000U;
    hEmif->regs->READ_WRITE_LEVELING_CONTROL = 0x80000000U;

    /* hwlvmod wait for read and write levelling bit to clear RDWRLVLFULL_START bit 31 */
    while((hEmif->regs->READ_WRITE_LEVELING_CONTROL & 0x80000000U) != 0x0U){}
}

/* @} */

#ifdef __cplusplus
}
#endif

#endif /* CSL_EMIF4D5AUX_V2_H_ */
