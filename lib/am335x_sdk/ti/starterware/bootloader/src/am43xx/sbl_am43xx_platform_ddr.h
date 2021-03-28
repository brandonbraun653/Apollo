/**
 *  \file  sbl_am43xx_platform_ddr.h
 *
 *  \brief This file contain functions which configure EMIF and DDR.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef BL_PLATFORM_DDR_H_
#define BL_PLATFORM_DDR_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Compute EMIF phy control. */
#define EXT_PHY_CTRL_VALUE(ctrlSlaveRatio)                                     \
    ((ctrlSlaveRatio << 20U) | (ctrlSlaveRatio << 10U) | (ctrlSlaveRatio << 0U))

/** \brief Compute EMIF phy FIFO WE. */
#define EXT_PHY_FIFO_WE_VALUE(fifoWeSlaveRatio)                                \
    ((fifoWeSlaveRatio << 16U) | (fifoWeSlaveRatio << 0U))

/** \brief Compute EMIF phy read DQS. */
#define EXT_PHY_RD_DQS_VALUE(rdDqsSlaveRatio)                                  \
    ((rdDqsSlaveRatio << 16U) | (rdDqsSlaveRatio << 0U))

/** \brief Compute EMIF phy write data. */
#define EXT_PHY_WR_DATA_VALUE(wrDataslaveRatio)                                \
    ((wrDataslaveRatio << 16U) | (wrDataslaveRatio << 0U))

/** \brief Compute EMIF phy write DQS. */
#define EXT_PHY_WR_DQS_VALUE(wrDqsSlaveRatio)                                  \
    ((wrDqsSlaveRatio << 16U) | (wrDqsSlaveRatio << 0U))

/** \brief Compute EMIF phy DQ. */
#define EXT_PHY_DQ_VALUE(dqOffset)                                             \
    ((dqOffset << 21U) | (dqOffset << 14U) | (dqOffset << 7U) | (dqOffset << 0U))

/** \brief Compute EMIF phy gate level init. */
#define EXT_PHY_GATE_LVL_INIT_VALUE(gateLvlInitRatio)                         \
    ((gateLvlInitRatio << 16U) | (gateLvlInitRatio << 0U))

/** \brief Compute EMIF phy gate level init. */
#define EXT_PHY_WR_LVL_INIT_VALUE(wrLvlInitRatio)                              \
    ((wrLvlInitRatio << 16U) | (wrLvlInitRatio << 0U))

/** \brief Compute EMIF phy . */
#define EXT_PHY_RANK0_DELAY_VALUE(dqOffset, gateLvlInitRatio, rank0Delay,      \
    wrDataslaveRatio)                                                          \
    ((dqOffset << 24U) | (gateLvlInitRatio << 16U) | (rank0Delay << 12U) |     \
    (wrDataslaveRatio << 0U))

/** \brief Compute EMIF phy slave and Rank0 delays. */
#define EXT_PHY_RANK0_DELAY_MODE(dqOffset, gateLvlInitMode, rank0Delay,      \
    wrDataslaveDelay)                                                          \
    ((dqOffset << 24U) | (gateLvlInitMode << 16U) | (rank0Delay << 12U) |     \
    (wrDataslaveDelay << 0U))


/** \brief Compute FIFO_WE_IN and Phy control slave delay .*/
/** \brief Compute FIFO_WE_IN and Phy control slave delay .*/
#define EXT_PHY_FIFO_WE_SLAVE_CTRL_DELAY(fifoWeInDelay, ctrlSlaveDelay)        \
    ((fifoWeInDelay << 16U) | (ctrlSlaveDelay << 0U))

/** \brief Compute Read and WriteDQS slave delay. */
#define EXT_PHY_WR_RD_DQS_SLAVE_DELAY(wrDqsSlaveDelay, rdDqsSlaveDelay)        \
    ((wrDqsSlaveDelay << 16U) | (rdDqsSlaveDelay << 0U))

/**
 * LPDDR2 configurations for EPOS.
 */

/** Slew rate:  slow, Impedance: 44ohms, no pullup/down. */
#define  LPDDR2_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE        (0x00000294U)

/** Slew rate:  fast, Impedance: 44ohms, pullup on DQSn, pulldown on DQS. */
#define  LPDDR2_CONTROL_DDR_DATA_IOCTRL_VALUE            (0x20000294U)

/**
 * timings for 266MHz LPDDR2 (8Gb)
 * mask out h/w training
 * invert_clkout = 0
 * disable phy calibration reset
 * disable half delay mode (266MHz LPDDR2)
 * RD_Latency = RL(from memory) + 1
 */
#define LPDDR2_EMIF_DDR_PHY_CTRL_VALUE                   (0x0E084006U)

#define LPDDR2_EMIF_SDRAM_TIM_1_VALUE                    (0xEA86B411U)
#define LPDDR2_EMIF_SDRAM_TIM_2_VALUE                    (0x103A0E8AU)
#define LPDDR2_EMIF_SDRAM_TIM_3_VALUE                    (0x0F6BA37FU)

/**
 * 32-bit LPDDR2
 * differential DQS
 * normal drive strength
 * CWL
 * CL = 4
 * 5 = 14 row bits
 * 2 = 10 column bits
 * 2 chip selects
 */
#define LPDDR2_EMIF_SDRAM_CONFIG_VALUE                   (0x808012BAU)

/** 266 * 3.9us = 0x40d. */
#define LPDDR2_EMIF_SDRAM_REF_CTRL_VALUE                 (0x0000040DU)

#define LPDDR2_ZQ_CONFIG_VALUE                           (0x50074BE4U)

/**
 * for 32-bit
 * only cmd0 slice is used for LPDDR2
 */
#define LPDDR2_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE       (0x00000001U)

#define LPDDR2_PHY_FIFO_WE_SLAVE_RATIO                   (0x50U)

#define LPDDR2_PHY_WR_DQS_SLAVE_RATIO                    (0x00U)

#define LPDDR2_PHY_GATELVL_INIT_RATIO                    (0x00U)

#define LPDDR2_PHY_GATELVL_INIT_MODE                     (0x00U)

#define LPDDR2_PHY_WR_DATA_SLAVE_DELAY                   (0x00U)

/** must enable use rank0 delays to avoid 32K boundary errors */
#define LPDDR2_PHY_USE_RANK0_DELAYS                      (0x01U)

/**
 * DDR3 configurations for GP and IDK EVM.
 */

/** Slew rate:  fastest, Impedance:  44ohms, no pullup/down */
#define DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE           (0x84U)

/** Slew rate:  fastest, Impedance:  44ohms, no pullup/down */
#define DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE               (0x84U)

/**
 * 400MHz DDR3
 * enable h/w training
 * invert_clkout=0
 * disable half delay mode
 * RD_Latency = (CL + 2) - 1
 */
#define GPEVM_DDR3_EMIF_DDR_PHY_CTRL_VALUE               (0x00008009U)

#define DDR3_ZQ_CONFIG_VALUE                             (0x50074BE4U)

#define DDR3_PHY_USE_RANK0_DELAYS                    (0x00U)

/**
 * DDR3 configurations for GP EVM.
 */

/**
 * for 32-bit
 * enable CMD PHY0 and PHY1
 * full thevenin load
 */
#define GPEVM_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE   (0x0C163U)

/**
 * 32-bit DDR3
 * termination = RZQ/6
 * differential DQS
 * dynamic ODT off
 * drive strength = RZQ/7
 * CWL = 5
 * CL = 6
 * 7 = 16 row bits
 * 2 = 10 column bits
 * 1 chip select
 */
#define GPEVM_DDR3_EMIF_SDRAM_CONFIG_VALUE               (0x61A013B2U)

#define GPEVM_DDR3_EMIF_SDRAM_TIM_1_VALUE                (0xEAAAD4DBU)
#define GPEVM_DDR3_EMIF_SDRAM_TIM_2_VALUE                (0x266B7FDAU)
#define GPEVM_DDR3_EMIF_SDRAM_TIM_3_VALUE                (0x107F8678U)

/** 400 * 7.8us = 0xC30 */
#define GPEVM_DDR3_EMIF_SDRAM_REF_CTRL_VALUE             (0x00000C30U)

#define GPEVM_DDR3_PHY_FIFO_WE_SLAVE_RATIO               (0x40U)

#define GPEVM_DDR3_PHY_WR_DQS_SLAVE_RATIO                (0x34U)

#define DDR3_PHY_GATELVL_INIT_RATIO                      (0x20U)

/**
 * DDR3 configurations for IDK EVM.
 */

/**
 * for 32-bit
 * enable CMD PHY0 and PHY1
 * half thevenin load
 */
#define IDKEVM_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE  (0x0C163U)

/**
 * 400MHz DDR3
 * mask out h/w training
 * invert_clkout=0
 * disable half delay mode
 * RD_Latency = (CL + 2) - 1
 */
#define IDKEVM_DDR3_EMIF_DDR_PHY_CTRL_VALUE              (0x00008009U)

/**
 * 32-bit DDR3
 * termination = RZQ/6
 * differential DQS
 * dynamic ODT off
 * drive strength = RZQ/6 (lower strength for IDK)
 * CWL = 5 400MHz
 * CL = 6  400MHz
 * 7 = 16 row bits
 * 2 = 10 column bits
 * 1 chip select
 */
#define IDKEVM_DDR3_EMIF_SDRAM_CONFIG_VALUE              (0x61A11B32U)

#define IDKEVM_DDR3_EMIF_SDRAM_TIM_1_VALUE               (0xEAAAD4DBU)
#define IDKEVM_DDR3_EMIF_SDRAM_TIM_2_VALUE               (0x266B7FDAU)
#define IDKEVM_DDR3_EMIF_SDRAM_TIM_3_VALUE               (0x107F8678U)

/** 400 * 7.8us = 0xC30 */
#define IDKEVM_DDR3_EMIF_SDRAM_REF_CTRL_VALUE            (0x00000C30U)

#define IDKEVM_DDR3_PHY_FIFO_WE_SLAVE_RATIO              (0x70U)

#define IDKEVM_DDR3_PHY_WR_DQS_SLAVE_RATIO               (0x34U)



/**
 * DDR3 configurations for EVMSK.
 */

/**
 * for 32-bit
 * enable CMD PHY0 and PHY1
 * half thevenin load
 */
#define EVMSK_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE  (0x0C163U)

/**
 * 400MHz DDR3
 * mask out h/w training
 * invert_clkout=0
 * disable half delay mode
 * RD_Latency = (CL + 2) - 1
 */
#define EVMSK_DDR3_EMIF_DDR_PHY_CTRL_VALUE              (0x00008009U)

/**
 * 32-bit DDR3
 * termination = RZQ/6
 * differential DQS
 * dynamic ODT off
 * drive strength = RZQ/6 (lower strength for IDK)
 * CWL = 5 400MHz
 * CL = 6  400MHz
 * 7 = 16 row bits
 * 2 = 10 column bits
 * 1 chip select
 */
#define EVMSK_DDR3_EMIF_SDRAM_CONFIG_VALUE              (0x61A11B32U)

#define EVMSK_DDR3_EMIF_SDRAM_TIM_1_VALUE               (0xEAAAD4DBU)
#define EVMSK_DDR3_EMIF_SDRAM_TIM_2_VALUE               (0x266B7FDAU)
#define EVMSK_DDR3_EMIF_SDRAM_TIM_3_VALUE               (0x107F8678U)

/** 400 * 7.8us = 0xC30 */
#define EVMSK_DDR3_EMIF_SDRAM_REF_CTRL_VALUE            (0x00000C30U)

#define EVMSK_DDR3_PHY_FIFO_WE_SLAVE_RATIO              (0x70U)

#define EVMSK_DDR3_PHY_WR_DQS_SLAVE_RATIO               (0x34U)



/**
 * EMIF PHY configurations MACRO
 */

#define PHY_FIFO_WE_SLAVE_RATIO                          (0x40U)
#define PHY_RD_DQS_SLAVE_RATIO                           (0x35U)
#define PHY_CTRL_SLAVE_RATIO                             (0x80U)
#define PHY_WR_DATA_SLAVE_RATIO                          (0x00U)
#define PHY_WR_DQS_SLAVE_RATIO                           (0x00U)
#define PHY_DQ_OFFSET                                    (0x40U)
#define PHY_GATELVL_INIT_MODE                            (0x01U)
#define PHY_WR_DATA_SLAVE_DELAY                          (0x80U)
#define PHY_USE_RANK0_DELAYS                             (0x00U)
#define PHY_GATELVL_INIT_RATIO                           (0x00U)
#define PHY_WRLVL_INIT_RATIO                             (0x00U)
#define PHY_CTRL_SLAVE_DELAY                             (0x00U)
#define PHY_FIFO_WE_IN_DELAY                             (0x00U)
#define PHY_WR_DQS_SLAVE_DELAY                           (0x60U)
#define PHY_RD_DQS_SLAVE_DELAY                           (0x20U)
#define PHY_GATELVL_NUM_DQ0                              (0xFU)
#define PHY_WRLVL_NUM_DQ0                                (0xFU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function initializes the DDR
 *
 * \param boardId Board ID.
 */
void SBLPlatformDdrInit(uint32_t boardId);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef BL_PLATFORM_DDR_H_ */
