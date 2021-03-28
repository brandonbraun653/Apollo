/**
 *  \file  sbl_am43xx_platform_ddr.c
 *
 * \brief  This file contain functions which configure EMIF and DDR.
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "hw_types.h"
#include "hw_emif4d.h"
#include "am437x.h"
#include "hw_cm_per.h"
#include "hw_cm_device.h"
#include "hw_control_am43xx.h"
#include "console_utils.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "gpio_app.h"
#include "sbl_am43xx_platform_ddr.h"
#include "sbl_platform.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**< \brief Enumerates the memory types. */
typedef enum sblPlatformMemoryType
{
    SBL_PLATFORM_MEM_TYPE_MIN,
    /**< Invalid memory type. */
    SBL_PLATFORM_MEM_TYPE_INVALID = SBL_PLATFORM_MEM_TYPE_MIN,
    /**< Invalid memory type. */
    SBL_PLATFORM_MEM_TYPE_LPDDR1,
    /**< LPDDR1 memory type. */
    SBL_PLATFORM_MEM_TYPE_LPDDR2,
    /**< LPDDR2 memory type. */
    SBL_PLATFORM_MEM_TYPE_DDR3,
    /**< DDR3 memory type. */
    SBL_PLATFORM_MEM_TYPE_MAX = SBL_PLATFORM_MEM_TYPE_DDR3
    /**< Maximum value of memory type. */
}sblPlatformMemoryType_t;

/**< \brief Structure holding the values of control registers. */
typedef struct sblPlatformDdrCtrlCfg
{
    uint32_t addrIoCtrl;
    /**<
     *  DDR addr io control to configure
     *  -# slew rate of clock IO pads
     *  -# pull up and pull down output impedence of clock IO pads
     *  -# addr/cmd IO Pads output Slew Rate
     *  -# program addr/cmd IO Pad Pull up Pull down output Impedance
     */
    uint32_t dataIoCtrl;
    /**<
     *  DDR data0/1/2 io control to configure
     *  -# controls WD0 & WD1 of DQS0/1/2.
     *  -# controls WD0 & WD1 of DM0/1/2.
     *  -# controls WD0 & WD1 of DDR data pins.
     *  -# clock IO Pads (DQS(0/1/2)/DQ(0/1/2)S#) output Slew Rate.
     *  -# clock IO Pads (DQS/DQS#) Pull up Pull down output Impedance.
     *  -# data IO Pads output Slew Rate.
     *  -# data IO Pad Pull up Pull down output Impedance.
     * Please refer to DDR IO buffer spec for details
     */
    uint32_t emifSdramCfgExt;
    /**<
     *  EMIF SDRAM configuration for
     *  -# Narrow mode operation
     *  -# ECC support.
     *  -# number of samples used during read data eye training.
     *  -# Selects data read eye training algorithm.
     *  -# Controls the number of DQ pins used during read data eye training.
     *  -# Select the status to be observed on the spare_out pins.
     *  -# Dynamic PWRDN control in the IOs to reduce power consumption.
     *  -# DDR IOs termination control value during reads.
     *  -# DFI clock division phase control
     *  -# Enable CMD PHY0/1/2.
     */
}sblPlatformDdrCtrlCfg_t;

/**< \brief Structure holding the values of DDR Emif registers. */
typedef struct sblPlatformDdrEmifCfg
{
    uint32_t ddrPhyCtrl;
    /**< DDR phy control register value. */
    uint32_t sdramTim1;
    /**< SDRAM timing1 register value. */
    uint32_t sdramTim2;
    /**< SDRAM timing2 register value. */
    uint32_t sdramTim3;
    /**< SDRAM timing3 register value. */
    uint32_t sdramCfg;
    /**< SDRAM config register value. */
    uint32_t sdramRefCtrl;
    /**< SDRAM ref control register value. */
    uint32_t zqConfig;
    /**< ZQ config register value. */
}sblPlatformDdrEmifCfg_t;

/**< \brief Structure holding the parameters to configure EMIF phy registers. */
typedef struct sblPlatformDdrEmifPhyCfg
{
    uint32_t phyGateLevelRatio;
    /**< Phy Gate level init Ratio. */
    uint32_t wrDqsSlaveRatio;
    /**< Write DQS slave ratio. */
    uint32_t fifoWeSlaveRatio;
    /**< FIFO write enable slave ratio. */
    uint32_t useRank0Delays;
    /**< Use RANKo delay. */
}sblPlatformDdrEmifPhyCfg_t;

/**< \brief Structure holding the ddr configurations. */
typedef struct sblPlatformDdrCfg
{
    sblPlatformDdrCtrlCfg_t    ddrCtrlCfg;
    /**< DDR ctrl config registers. */
    sblPlatformDdrEmifCfg_t    ddrEmifCfg;
    /**< DDR Emif config registers. */
    sblPlatformDdrEmifPhyCfg_t ddrEmifPhyCfg;
    /**< EMIF phy config registers. */
}sblPlatformDdrCfg_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function sets up the DDR PHY
 *
 * \param pDdrCfg DDR configuration
 * \param memType value to differentiate between two memory types
 *                It takes one of the macro value from #sblPlatformMemoryType_t.
 *                enum.
 */
static void SblPlatformDdrPhyInit(sblPlatformDdrEmifPhyCfg_t *pDdrEmifPhyCfg,
                                  uint32_t memType);

/**
 * \brief This function initializes the DDR
 *
 * \param pDdrCfg DDR configuration
 * \param memType #sblPlatformMemoryType_t.
 */
static void SblPlatformDdrConfig(sblPlatformDdrCfg_t *pDdrCfg, uint32_t memType);

/**
 * \brief This function initializes the EMIF
 */
static void  SblPlatformDdrEmifInit(void);

/**
 *  \brief This function enables VTT.
 */
static void SblPlatformDdrVttEnable(void);

/**
 * \brief   This API gets the board info like pin number and instance.
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      Board info successful retrieved. VTT is connected to
 *                      GPIO on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - VTT device may not be available on this board.
 *                      - VTT may not be connected to GPIO on this board.
 */
static int32_t SblPlatformDdrVttBoardInfoGet(gpioAppPinObj_t *pObj);

/**
 * \brief   This API gets the soc info - base address of gpio instance.
 *
 * \param   pObj        Pointer to the pin object.
 */
static void SblPlatformDdrVttSocInfoGet(gpioAppPinObj_t *pObj);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief VTT pin default configuration */
static const gpioAppPinObj_t VTT_DEFAULT =
{
    0U,  /* pin number */
    0U,  /* Instance number */
    0U,  /* Instance Address */
    {
        GPIO_DIRECTION_OUTPUT, /* dir */
        FALSE, /* debouEnable */
        0U, /* debouTime */
        FALSE, /* intrEnable */
        0U, /* intrType */
        0U, /* intrLine */
        FALSE, /* wakeEnable */
        0U /* wakeLine */
    } /* gpioAppPinCfg_t */
};

/** \brief GPEVM DDR3 configuration */
static const sblPlatformDdrCfg_t GPEVM_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        GPEVM_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE /* emif sdram config ext */
    }, /* ddrCtrl_t */
    {
        GPEVM_DDR3_EMIF_DDR_PHY_CTRL_VALUE, /* ddr phy control */
        GPEVM_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        GPEVM_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        GPEVM_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        GPEVM_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        GPEVM_DDR3_EMIF_SDRAM_REF_CTRL_VALUE, /* sdram ref control */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        DDR3_PHY_GATELVL_INIT_RATIO, /* Phy Gate level init ratio. */
        GPEVM_DDR3_PHY_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        GPEVM_DDR3_PHY_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        DDR3_PHY_USE_RANK0_DELAYS /* use rank0 delay */
    } /* ddrEmifPhy_t */
};

/** \brief EVMSK DDR3 configuration */
static const sblPlatformDdrCfg_t EVMSK_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        EVMSK_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE /* emif sdram config ext */
    }, /* ddrCtrl_t */
    {
        EVMSK_DDR3_EMIF_DDR_PHY_CTRL_VALUE, /* ddr phy control */
        EVMSK_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        EVMSK_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        EVMSK_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        EVMSK_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        EVMSK_DDR3_EMIF_SDRAM_REF_CTRL_VALUE, /* sdram ref control */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        DDR3_PHY_GATELVL_INIT_RATIO, /* Phy Gate level init ratio. */
        EVMSK_DDR3_PHY_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        EVMSK_DDR3_PHY_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        DDR3_PHY_USE_RANK0_DELAYS /* use rank0 delay */
    } /* ddrEmifPhy_t */
};

/** \brief IDK EVM DDR3 configuration */
static const sblPlatformDdrCfg_t IDKEVM_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        IDKEVM_DDR3_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE /* emif sdram config ext */
    }, /* ddrCtrl_t */
    {
        IDKEVM_DDR3_EMIF_DDR_PHY_CTRL_VALUE, /* ddr phy control */
        IDKEVM_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        IDKEVM_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        IDKEVM_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        IDKEVM_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        IDKEVM_DDR3_EMIF_SDRAM_REF_CTRL_VALUE, /* sdram ref control */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        DDR3_PHY_GATELVL_INIT_RATIO, /* Phy Gate level init ratio. */
        IDKEVM_DDR3_PHY_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        IDKEVM_DDR3_PHY_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        DDR3_PHY_USE_RANK0_DELAYS /* use rank0 delay */
    } /* ddrEmifPhy_t */
};

/** \brief EPOS EVM LPDDR2 configuration */
static const sblPlatformDdrCfg_t EPOSEVM_LPDDR2_CONFIG =
{
    {
        LPDDR2_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        LPDDR2_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        LPDDR2_CONTROL_EMIF_SDRAM_CONFIG_EXT_VALUE /* emif sdram config ext */
    }, /* ddrCtrl_t */
    {
        LPDDR2_EMIF_DDR_PHY_CTRL_VALUE, /* ddr phy control */
        LPDDR2_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        LPDDR2_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        LPDDR2_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        LPDDR2_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        LPDDR2_EMIF_SDRAM_REF_CTRL_VALUE, /* sdram ref control */
        LPDDR2_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        LPDDR2_PHY_GATELVL_INIT_RATIO, /* Phy Gate level init ratio. */
        LPDDR2_PHY_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        LPDDR2_PHY_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        LPDDR2_PHY_USE_RANK0_DELAYS /* use rank0 delay */
    } /* ddrEmifPhy_t */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void SBLPlatformDdrInit(uint32_t boardId)
{
    sblPlatformDdrCfg_t ddrCfg = GPEVM_DDR3_CONFIG;
    uint32_t memType = SBL_PLATFORM_MEM_TYPE_INVALID;

    if(BOARD_GPEVM == boardId) /* For GP EVM - DDR3 */
    {
        ddrCfg = GPEVM_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
        SblPlatformDdrVttEnable();
    }
    else if(BOARD_EVMSK == boardId) /* For IDK EVM - DDR3 */
    {
        ddrCfg = EVMSK_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
    }
    else if(BOARD_IDKEVM == boardId) /* For IDK EVM - DDR3 */
    {
        ddrCfg = IDKEVM_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
    }
    else if(BOARD_EPOSEVM == boardId) /* For EPOS EVM - LPDDR2 */
    {
        ddrCfg = EPOSEVM_LPDDR2_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_LPDDR2;
    }
    else if(BOARD_CUSTOM == boardId)
    {
        /* ***CUSTOM BOARD*** Custom board code starts */

        /* Provide memory configurations for CUSTOM board. */

        /* ***CUSTOM BOARD*** Custom board code ends */
    }
    else
    {
        /* It is expected to pass proper value as this doesn't return error. */
    }

    /* EMIF Initialization */
    SblPlatformDdrEmifInit();

    SblPlatformDdrConfig(&ddrCfg, memType);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void SblPlatformVtpEnable(void)
{
    /* Enable VTP */
    HW_WR_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_VTP, CTRL_VTP_EN, 1U);
    HW_WR_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_VTP, CTRL_VTP_CLRZ, 0U);
    HW_WR_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_VTP, CTRL_VTP_CLRZ, 1U);

    while(1U != HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_VTP,
        CTRL_VTP_READY));
}

static void SblPlatformDdrPhyInit(sblPlatformDdrEmifPhyCfg_t *pDdrEmifPhyCfg, uint32_t memType)
{
    uint32_t regVal = 0U;
    uint32_t idx = 0U;

    /* DDR PHY reg ctrl slave ratio */
    regVal = EXT_PHY_CTRL_VALUE(PHY_CTRL_SLAVE_RATIO);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_1)        , regVal);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_1_SHDW)   , regVal);

    /*
    ** Phy configurations required for DDR2 memory. These settings are not applicable if hardware
    ** levelling is not used.
    */
    if(SBL_PLATFORM_MEM_TYPE_LPDDR2 == memType)
    {
            /* DDR PHY reg ctrl slave ratio */
        regVal = EXT_PHY_CTRL_VALUE(PHY_CTRL_SLAVE_RATIO);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_1)        , regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_1_SHDW)   , regVal);

        regVal = EXT_PHY_FIFO_WE_VALUE(pDdrEmifPhyCfg->fifoWeSlaveRatio);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_2 + 4U * idx) , regVal);
        }

        /* DDR PHY rd dqs slave ratio */
        regVal = EXT_PHY_RD_DQS_VALUE(PHY_RD_DQS_SLAVE_RATIO);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_7 + 4U * idx) , regVal);
        }

        /* DDR PHY wr data slave ratio */
        regVal = EXT_PHY_WR_DATA_VALUE(PHY_WR_DATA_SLAVE_RATIO);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_12 + 4U * idx) , regVal);
        }

        /* DDR PHY wr dqs slave ratio */
        regVal = EXT_PHY_WR_DQS_VALUE(pDdrEmifPhyCfg->wrDqsSlaveRatio);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_17 + 4U * idx) , regVal);
        }

        regVal = EXT_PHY_RANK0_DELAY_MODE(PHY_DQ_OFFSET, LPDDR2_PHY_GATELVL_INIT_MODE,
                    LPDDR2_PHY_USE_RANK0_DELAYS, LPDDR2_PHY_WR_DATA_SLAVE_DELAY);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_24), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_24_SHDW), regVal);

        regVal = EXT_PHY_DQ_VALUE(PHY_DQ_OFFSET);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_25), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_25_SHDW), regVal);

        regVal = EXT_PHY_GATE_LVL_INIT_VALUE(PHY_GATELVL_INIT_RATIO);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_26), regVal);
        }

        regVal = EXT_PHY_GATE_LVL_INIT_VALUE(PHY_WRLVL_INIT_RATIO);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_31), regVal);
        }

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36), 0x00U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36_SHDW), 0x00U);
    }
    else if(SBL_PLATFORM_MEM_TYPE_DDR3 == memType)
    {
        /* DDR PHY gate level init mode */
        regVal = EXT_PHY_GATE_LVL_INIT_VALUE(pDdrEmifPhyCfg->phyGateLevelRatio);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_26 + 4U * idx) , regVal);
        }

        /* DDR PHY wr level init ratio */
        regVal = EXT_PHY_WR_LVL_INIT_VALUE(PHY_WRLVL_INIT_RATIO);
        for(idx = 0U; idx < 2U * 5U; idx++)
        {
            HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_31 + 4U * idx) , regVal);
        }

            /* DDR PHY control slave delay. */
        regVal = ((PHY_FIFO_WE_IN_DELAY << 16U)|(PHY_CTRL_SLAVE_DELAY << 0U));
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_22), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_22_SHDW), regVal);

        regVal = EXT_PHY_WR_RD_DQS_SLAVE_DELAY(PHY_WR_DQS_SLAVE_DELAY,
                 PHY_RD_DQS_SLAVE_DELAY);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_23), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_23_SHDW), regVal);

        regVal = EXT_PHY_RANK0_DELAY_VALUE(PHY_DQ_OFFSET, PHY_GATELVL_INIT_MODE,
            PHY_USE_RANK0_DELAYS, PHY_WR_DATA_SLAVE_DELAY);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_24), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_24_SHDW), regVal);

        regVal = EXT_PHY_DQ_VALUE(PHY_DQ_OFFSET);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_25), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_25_SHDW), regVal);

        regVal = ((PHY_WRLVL_NUM_DQ0 << 4U)|(PHY_GATELVL_NUM_DQ0 << 0U));
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36_SHDW), regVal);
    }
    else
    {
        /* This case does not occur. */
    }
}

void SblPlatformDdrConfig(sblPlatformDdrCfg_t *pDdrCfg, uint32_t memType)
{
    uint32_t regVal;
    sblPlatformDdrCtrlCfg_t *pDdrCtrlCfg = &pDdrCfg->ddrCtrlCfg;
    sblPlatformDdrEmifCfg_t *pDdrEmifCfg = &pDdrCfg->ddrEmifCfg;
    uint32_t i = 0U;

    /* DDR3 Phy Initialization */
    SblPlatformVtpEnable();

    /* Check DLL is ready. */
    HW_WR_FIELD32(SOC_CM_DEVICE_REG + PRCM_CM_DLL_CTRL,
        PRCM_CM_DLL_CTRL_OVERRIDE, PRCM_CM_DLL_CTRL_OVERRIDE_NO_OVR);

    while(PRCM_CM_DLL_CTRL_READYST_NOT_READY ==
        HW_RD_FIELD32(SOC_CM_DEVICE_REG + PRCM_CM_DLL_CTRL,
        PRCM_CM_DLL_CTRL_READYST));

    /* Configure DDR I/O and Control module registers. */

    regVal = pDdrCtrlCfg->addrIoCtrl;
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_ADDRCTRL_IOCTRL), regVal);

    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_ADDRCTRL_WD0_IOCTRL),
        0x00000000U);
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_ADDRCTRL_WD1_IOCTRL),
        0x00000000U);

    regVal = pDdrCtrlCfg->dataIoCtrl;
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_DATA0_IOCTRL), regVal);
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_DATA1_IOCTRL), regVal);
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_DATA2_IOCTRL), regVal);
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_DATA3_IOCTRL), regVal);

    /*
    * DDR RESET controlled by EMIF/DDR PHY
    * IOs set to STL mode for DDR3
    */
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_IO), 0x0U);

    /*
     * DDR3 CKE controlled by EMIF/DDR PHY
     */
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_DDR_CKE), 0x00000003U);

    /* IO to work for DDR3 */
    /* SDRAM_CONFIG_EXT is used coming out of low power modes */
    regVal = pDdrCtrlCfg->emifSdramCfgExt;
    HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_EMIF_SDRAM_CONFIG_EXT), regVal);

    if(SBL_PLATFORM_MEM_TYPE_DDR3 == memType)
    {
        /* hwlvmod reset applied after DDR PHY & IO control settings. */
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002011U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002411U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002011U);

        /* Configure DDR I/O and Control module registers complete. */
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL), 0x80003000U);

        regVal = pDdrEmifCfg->ddrPhyCtrl;
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_DDR_PHY_CTRL_1), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_DDR_PHY_CTRL_1_SHDW), regVal);

        /* Setting up DDR3 H/W levelling configuration. */
        SblPlatformDdrPhyInit(&pDdrCfg->ddrEmifPhyCfg, memType);

        /* hwlvmod reset applied after DDR PHY & IO control settings. */
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002011U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002411U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_IODFT_TLGC), 0x00002011U);
    }
    else if(SBL_PLATFORM_MEM_TYPE_LPDDR2 == memType)
    {
        /* Configure DDR I/O and Control module registers complete. */
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL), 0x80003000U);
    }
    else
    {
        /* This case does not occur. */
    }

    regVal = pDdrEmifCfg->sdramTim1;
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_1), regVal);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_1_SHDW), regVal);

    regVal = pDdrEmifCfg->sdramTim2;
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_2), regVal);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_2_SHDW), regVal);

    regVal = pDdrEmifCfg->sdramTim3;
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_3), regVal);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_TIM_3_SHDW), regVal);

    if(SBL_PLATFORM_MEM_TYPE_LPDDR2 == memType)
    {
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_CONFIG_2), 0x00000000U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_NVM_TIM), 0x00000000U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_NVM_TIM_SHDW), 0x00000000U);
    }

    regVal = pDdrEmifCfg->zqConfig;
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_ZQ_CONFIG), regVal);

    HW_WR_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_PWR_MGMT_CTRL, 0x00000000U);
    HW_WR_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_PWR_MGMT_CTRL_SHDW, 0x00000000U);
    /* only used with voltage ramps */
    HW_WR_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_DLL_CALIB_CTRL, 0x00050000U);
    /* only used with voltage ramps. */
    HW_WR_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_DLL_CALIB_CTRL_SHDW, 0x00050000U);
    HW_WR_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_TEMP_ALERT_CONFIG, 0x00000000U);

     /* Priority settings. */
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_PRI_COS_MAP)       , 0x00000000U);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_CONNID_COS_1_MAP)  , 0x00000000U);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_CONNID_COS_2_MAP)  , 0x00000000U);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_RD_WR_EXEC_THR)    , 0x00000405U);
    HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_COS_CONFIG)        , 0x00FFFFFFU);

    if(SBL_PLATFORM_MEM_TYPE_LPDDR2 == memType)
    {
        /* Setting up DDR PHY Initializations. */
        SblPlatformDdrPhyInit(&pDdrCfg->ddrEmifPhyCfg, memType);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL), 0x3000U);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_CONFIG),
            LPDDR2_EMIF_SDRAM_CONFIG_VALUE);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL),
            LPDDR2_EMIF_SDRAM_REF_CTRL_VALUE);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL_SHDW),
            LPDDR2_EMIF_SDRAM_REF_CTRL_VALUE);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG), 0x00000000U);

        while((HW_RD_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA) & 0xFF)
            != 0x18U));

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x0000000AU);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA),
            0x56U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x8000000AU);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x56U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x0000001U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x43U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x80000001U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x43U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x00000002U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x2U);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x80000002U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x2U);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0x40000002U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x2U);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_CONFIG),
            0xC0000002U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_LPDDR2_MODE_REG_DATA), 0x2U);
    }
    else if(SBL_PLATFORM_MEM_TYPE_DDR3 == memType)
    {
        /* Finished with EMIF config. Set init bit back to enable. */
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL)    , 0x00003000U);

        /* EMIF initialization and also latches values to PHY */
        regVal = pDdrEmifCfg->sdramCfg;
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_CONFIG), regVal);

        regVal = pDdrEmifCfg->sdramRefCtrl;
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL), regVal);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_SDRAM_REF_CTRL_SHDW), regVal);

        /* Some clock cycle delay for refresh to complete. */
        for(i = 0; i < 1000; i++);

        regVal = HW_RD_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36);
        regVal = (regVal | 0x00000100U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36), regVal);
        regVal = HW_RD_REG32(SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36_SHDW);
        regVal = (regVal | 0x00000100U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_EXT_PHY_CTRL_36_SHDW), regVal);

        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_RDWR_LVL_RMP_WIN)   , 0x00000000U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_RDWR_LVL_RMP_CTRL)  , 0x80000000U);
        HW_WR_REG32((SOC_EMIF_ADDRSP0_REG + EMIF_RDWR_LVL_CTRL)      , 0x80000000U);

        /* hwlvmod wait for read and write levelling bit to clear RDWRLVLFULL_START bit 31 */
        while((HW_RD_REG32(SOC_EMIF_ADDRSP0_REG +EMIF_RDWR_LVL_CTRL) & 0x80000000) != 0x0U);
    }
}

/*
 * \brief This function initializes the EMIF
 */
void SblPlatformDdrEmifInit(void)
{
    /* Enable the clocks for EMIF */
    HW_WR_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKCTRL,
        PRCM_CM_PER_EMIF_CLKCTRL_MODULEMODE,
        PRCM_CM_PER_EMIF_CLKCTRL_MODULEMODE_ENABLE);

    while(PRCM_CM_PER_EMIF_CLKCTRL_MODULEMODE_ENABLE !=
        HW_RD_FIELD32(SOC_CM_PER_REG + PRCM_CM_PER_EMIF_CLKCTRL,
        PRCM_CM_PER_EMIF_CLKCTRL_MODULEMODE));
}

static void SblPlatformDdrVttEnable(void)
{
    int32_t status = S_PASS;
    gpioAppPinObj_t vttPin = VTT_DEFAULT;

    /* Get board info */
    status = SblPlatformDdrVttBoardInfoGet(&vttPin);

    if (S_PASS == status)
    {
        /* Get SoC info */
        SblPlatformDdrVttSocInfoGet(&vttPin);

        /* GPIO clock/pin mux and IP configuration */
        GPIOAppInit(&vttPin);

        /* Driving a logic high on the GPIO pin. */
        GPIOPinWrite(vttPin.instAddr, vttPin.pinNum, GPIO_PIN_HIGH);

    }
    else
    {
        CONSOLEUtilsPrintf("VTT configuration failed!\n");
    }
}

static int32_t SblPlatformDdrVttBoardInfoGet(gpioAppPinObj_t *pObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t  gpioInstNum;
    uint32_t  pinNum;

    /* Get the GPIO data for VTT from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_VTT, 0U);
    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_GPIO == modId)
    {
        gpioInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_VTT,
            0U);
        pinNum = BOARDGetDeviceCtrlInfo(DEVICE_ID_VTT, 0U);

        if ((INVALID_INST_NUM == gpioInstNum) || (INVALID_INFO == pinNum))
        {
            CONSOLEUtilsPrintf("Invalid GPIO board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("GPIO Instance number: %d\n", gpioInstNum);
            CONSOLEUtilsPrintf("Pin number: %d\n", pinNum);
            pObj->instNum = gpioInstNum;
            pObj->pinNum  = pinNum;
            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to GPIO!\n");
    }

    return (status);
}

static void SblPlatformDdrVttSocInfoGet(gpioAppPinObj_t *pObj)
{
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, pObj->instNum);
    }
    else
    {
        /* GPIO instance number is not present. */
    }
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */
