/**
 *  \file  sbl_am335x_platform_ddr.c
 *
 * \brief  This file contain functions which configure EMIF and DDR.
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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
#include "soc_am335x.h"
#include "hw_cm_per.h"
#include "hw_cm_device.h"
#include "hw_control_am335x.h"
#include "console_utils.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "gpio_app.h"
#include "sbl_am335x_platform_ddr.h"
#include "sbl_platform.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define BIT(n)                             (1 << (n))
#define PAD_CTRL_PULLUDDISABLE             (BIT(3))
#define PAD_CTRL_PULLUPSEL                 (BIT(4))
#define PAD_CTRL_RXACTIVE                  (BIT(5))
#define PAD_CTRL_SLOWSLEW                  (BIT(6))
#define PAD_CTRL_MUXMODE(n)                (n)

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
    SBL_PLATFORM_MEM_TYPE_DDR2,
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
    uint32_t ddrIoCtrl;
    /**<
     *  DDR io control
     */
}sblPlatformDdrCtrlCfg_t;

/**< \brief Structure holding the values of DDR Emif registers. */
typedef struct sblPlatformDdrEmifCfg
{
    uint32_t ddrPhyCtrl;
    /**< DDR phy control register value. */
    uint32_t ddrPhyCtrlDyPwrdn;
    /**< DDR phy control dynamic power down register value. */
    uint32_t sdramTim1;
    /**< SDRAM timing1 register value. */
    uint32_t sdramTim2;
    /**< SDRAM timing2 register value. */
    uint32_t sdramTim3;
    /**< SDRAM timing3 register value. */
    uint32_t sdramCfg;
    /**< SDRAM config register value. */
    uint32_t sdramRefCtrl1;
    /**< SDRAM ref control register value 1. */
    uint32_t sdramRefCtrl2;
    /**< SDRAM ref control register value 2. */
    uint32_t zqConfig;
    /**< ZQ config register value. */
}sblPlatformDdrEmifCfg_t;

/**< \brief Structure holding the parameters to configure EMIF phy registers. */
typedef struct sblPlatformDdrEmifPhyCfg
{
    /**< COMMAND */
    uint32_t slaveRatio;
    /**< slave ratio. */
    uint32_t slaveForce;
    /**< slave force. */
    uint32_t slaveDelay;
    /**< slave delay. */
    uint32_t invertClkout;
    /**< invert clockout. */

    /**< DATA */
    uint32_t rdDqsSlaveRatio;
    /**< Read DQS slave ratio. */
    uint32_t wrDqsSlaveRatio;
    /**< Write DQS slave ratio. */
    uint32_t fifoWeSlaveRatio;
    /**< FIFO write enable slave ratio. */
    uint32_t wrDataSlaveRatio;
    /**< writer data slave ratio. */
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
 * \brief This function sets up the DDR2 PHY
 */
static void SblPlatformDdrPhyInit(sblPlatformDdrEmifPhyCfg_t *pDdrEmifPhyCfg, uint32_t memType);

/**
 * \brief This function initializes the DDR
 *
 * \param dynPwrDown  Is dynamic power down condifuration applicable.
 *                    - FALSE for SoC revisons 1.x.
 *                    - TRUE for SoC revisons 2.x and above.
 * \param pDdrCfg DDR configuration
 * \param memType #sblPlatformMemoryType_t.
 */
static void SblPlatformDdrConfig(uint32_t dynPwrDown, sblPlatformDdrCfg_t *pDdrCfg, uint32_t memType);

/**
 * \brief This function initializes the EMIF
 */
static void  SblPlatformDdrEmifInit(void);

/**
 * \brief This function Enables DDR_VTT
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

/** \brief BEAGLEBONE DDR2 configuration */
static const sblPlatformDdrCfg_t BBW_DDR2_CONFIG =
{
    {
        DDR2_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR2_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR2_CONTROL_DDR_IOCTRL_VALUE, /* ddr io cntrol */
    }, /* ddrCtrl_t */
    {
        BBW_DDR2_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        BBW_DDR2_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */

        BBW_DDR2_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        BBW_DDR2_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        BBW_DDR2_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        BBW_DDR2_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */

        BBW_DDR2_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        BBW_DDR2_EMIF_SDRAM_REF_CTRL_VAL2, /* sdram ref control value 2 */
        DDR_NOTAPPLICABLE_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        BBW_DDR2_CMD_SLAVE_RATIO, /* slave ratio */
        BBW_DDR2_CMD_SLAVE_FORCE, /* slave force */
        BBW_DDR2_CMD_SLAVE_DELAY, /* slave delay */
        BBW_DDR2_CMD_INVERT_CLKOUT,	/* invert clockout */

        BBW_DDR2_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        BBW_DDR2_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        BBW_DDR2_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        BBW_DDR2_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};

/** \brief BEAGLEBONE BLACK DDR3 configuration */
static const sblPlatformDdrCfg_t BBB_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR3_CONTROL_DDR_IOCTRL_VALUE, /* ddr io control */
    }, /* ddrCtrl_t */
    {
        BBB_DDR3_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        BBB_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */

        BBB_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        BBB_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        BBB_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        BBB_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */

        BBB_DDR3_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        DDR_NOTAPPLICABLE_VALUE,/* sdram ref control value 2 */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        BBB_DDR3_CMD_SLAVE_RATIO, /* slave ratio */
        DDR_NOTAPPLICABLE_VALUE, /* slave force */
        DDR_NOTAPPLICABLE_VALUE, /* slave delay */
        BBB_DDR3_CMD_INVERT_CLKOUT,	/* invert clockout */

        BBB_DDR3_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        BBB_DDR3_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        BBB_DDR3_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        BBB_DDR3_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};

/** \brief SK DDR3 configuration */
static const sblPlatformDdrCfg_t SK_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR3_CONTROL_DDR_IOCTRL_VALUE, /* ddr io control */
    }, /* ddrCtrl_t */
    {
        SK_DDR3_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        SK_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */

        SK_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        SK_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        SK_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        SK_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */

        SK_DDR3_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        DDR_NOTAPPLICABLE_VALUE,/* sdram ref control value 2 */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        SK_DDR3_CMD_SLAVE_RATIO, /* slave ratio */
        DDR_NOTAPPLICABLE_VALUE, /* slave force */
        DDR_NOTAPPLICABLE_VALUE, /* slave delay */
        SK_DDR3_CMD_INVERT_CLKOUT, /* invert clockout */

        SK_DDR3_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        SK_DDR3_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        SK_DDR3_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        SK_DDR3_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};

/** \brief EVM DDR3 configuration */
static const sblPlatformDdrCfg_t EVM_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR3_CONTROL_DDR_IOCTRL_VALUE, /* ddr io control */
    }, /* ddrCtrl_t */
    {
        EVM_DDR3_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        EVM_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */

        EVM_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        EVM_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        EVM_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        EVM_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */

        EVM_DDR3_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        DDR_NOTAPPLICABLE_VALUE,/* sdram ref control value 2 */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        EVM_DDR3_CMD_SLAVE_RATIO, /* slave ratio */
        DDR_NOTAPPLICABLE_VALUE, /* slave force */
        DDR_NOTAPPLICABLE_VALUE, /* slave delay */
        EVM_DDR3_CMD_INVERT_CLKOUT, /* invert clockout */

        EVM_DDR3_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        EVM_DDR3_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        EVM_DDR3_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        EVM_DDR3_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};

static const sblPlatformDdrCfg_t ICEv1_DDR2_CONFIG =
{
    {
        DDR2_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR2_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR2_CONTROL_DDR_IOCTRL_VALUE, /* ddr io cntrol */
    }, /* ddrCtrl_t */
    {
        ICEv1_DDR2_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        ICEv1_DDR2_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */
        ICEv1_DDR2_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        ICEv1_DDR2_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        ICEv1_DDR2_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        ICEv1_DDR2_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        ICEv1_DDR2_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        ICEv1_DDR2_EMIF_SDRAM_REF_CTRL_VAL2, /* sdram ref control value 2 */
        DDR_NOTAPPLICABLE_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        ICEv1_DDR2_CMD_SLAVE_RATIO, /* slave ratio */
        ICEv1_DDR2_CMD_SLAVE_FORCE, /* slave force */
        ICEv1_DDR2_CMD_SLAVE_DELAY, /* slave delay */
        ICEv1_DDR2_CMD_INVERT_CLKOUT,	/* invert clockout */
        ICEv1_DDR2_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        ICEv1_DDR2_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        ICEv1_DDR2_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        ICEv1_DDR2_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};
static const sblPlatformDdrCfg_t ICEv2_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR3_CONTROL_DDR_IOCTRL_VALUE, /* ddr io control */
    }, /* ddrCtrl_t */
    {
        ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */
        ICEv2_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        ICEv2_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        ICEv2_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        ICEv2_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        ICEv2_DDR3_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        DDR_NOTAPPLICABLE_VALUE,/* sdram ref control value 2 */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        ICEv2_DDR3_CMD_SLAVE_RATIO, /* slave ratio */
        DDR_NOTAPPLICABLE_VALUE, /* slave force */
        DDR_NOTAPPLICABLE_VALUE, /* slave delay */
        ICEv2_DDR3_CMD_INVERT_CLKOUT, /* invert clockout */
        ICEv2_DDR3_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        ICEv2_DDR3_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        ICEv2_DDR3_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        ICEv2_DDR3_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};
/* AMIC110 board uses icev2 settings except for the timing values */
static const sblPlatformDdrCfg_t AMIC110_DDR3_CONFIG =
{
    {
        DDR3_CONTROL_DDR_ADDRCTRL_IOCTRL_VALUE, /* ddr address io control */
        DDR3_CONTROL_DDR_DATA_IOCTRL_VALUE, /* ddr data io control */
        DDR3_CONTROL_DDR_IOCTRL_VALUE, /* ddr io control */
    }, /* ddrCtrl_t */
    {
        ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1, /* ddr phy control */
        ICEv2_DDR3_EMIF_DDR_PHY_CTRL_1_DY_PWRDN, /* ddr phy control dynamic power down */
        AMIC110_DDR3_EMIF_SDRAM_TIM_1_VALUE, /* sdram timing1 */
        AMIC110_DDR3_EMIF_SDRAM_TIM_2_VALUE, /* sdram timing2 */
        AMIC110_DDR3_EMIF_SDRAM_TIM_3_VALUE, /* sdram timing3 */
        AMIC110_DDR3_EMIF_SDRAM_CONFIG_VALUE, /* sdram config */
        ICEv2_DDR3_EMIF_SDRAM_REF_CTRL_VAL1, /* sdram ref control value 1 */
        DDR_NOTAPPLICABLE_VALUE,/* sdram ref control value 2 */
        DDR3_ZQ_CONFIG_VALUE /* ZQ config */
    }, /* ddrEmif_t */
    {
        ICEv2_DDR3_CMD_SLAVE_RATIO, /* slave ratio */
        DDR_NOTAPPLICABLE_VALUE, /* slave force */
        DDR_NOTAPPLICABLE_VALUE, /* slave delay */
        ICEv2_DDR3_CMD_INVERT_CLKOUT, /* invert clockout */
        ICEv2_DDR3_DATA_RD_DQS_SLAVE_RATIO, /* rd dqs slave ratio */
        AMIC110_DDR3_DATA_WR_DQS_SLAVE_RATIO, /* wr dqs slave ratio */
        ICEv2_DDR3_DATA_FIFO_WE_SLAVE_RATIO, /* fifo we slave ratio */
        AMIC110_DDR3_DATA_WR_DATA_SLAVE_RATIO  /* wr data slave ratio */
    } /* ddrEmifPhy_t */
};
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void SBLPlatformDdrInit(uint32_t dynPwrDown, uint32_t boardId)
{
    sblPlatformDdrCfg_t ddrCfg = BBW_DDR2_CONFIG;
    uint32_t memType = SBL_PLATFORM_MEM_TYPE_INVALID;

    if(BOARD_BEAGLEBONE == boardId) /* For BEAGLEBONE - DDR2 */
    {
        ddrCfg = BBW_DDR2_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR2;
    }
    else if(BOARD_BEAGLEBONEBLACK == boardId) /* For BEAGLEBONE BLACK - DDR3 */
    {
        ddrCfg = BBB_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
    }
    else if(BOARD_EVMSK == boardId)
    {
        ddrCfg = SK_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
        SblPlatformDdrVttEnable();
    }
    else if(BOARD_GPEVM == boardId)
    {
        ddrCfg = EVM_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
    }
    else if(BOARD_ICEV1 == boardId)
    {
        ddrCfg = ICEv1_DDR2_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR2;
    }
    else if(BOARD_ICEV2 == boardId)
    {
        ddrCfg = ICEv2_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
        SblPlatformDdrVttEnable();
    }
    else if(BOARD_AMIC110 == boardId)
    {
        ddrCfg = AMIC110_DDR3_CONFIG;
        memType = SBL_PLATFORM_MEM_TYPE_DDR3;
    }
    else
    {
     /* Support for other boards need to be added. */
    }

    /* EMIF Initialization */
    SblPlatformDdrEmifInit();

    SblPlatformDdrConfig(dynPwrDown,&ddrCfg, memType);
}

/* ========================================================================== */
/*                          Internal Function Definitions                              */
/* ========================================================================== */

static void SblPlatformVtpEnable(void)
{
    /* Enable VTP */
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_VTP_CTRL, CONTROL_VTP_CTRL_ENABLE,
        CONTROL_VTP_CTRL_ENABLE_SHIFT, 1U);
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_VTP_CTRL, CONTROL_VTP_CTRL_CLRZ,
        CONTROL_VTP_CTRL_CLRZ_SHIFT, 0U);
    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_VTP_CTRL, CONTROL_VTP_CTRL_CLRZ,
        CONTROL_VTP_CTRL_CLRZ_SHIFT, 1U);

    while(1U != HW_RD_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_VTP_CTRL,
        CONTROL_VTP_CTRL_READY, CONTROL_VTP_CTRL_READY_SHIFT));
}

static void SblPlatformDdrPhyInit(sblPlatformDdrEmifPhyCfg_t *pDdrEmifPhyCfg, uint32_t memType)
{
    volatile uint32_t regVal;

    /* Enable VTP */
    SblPlatformVtpEnable();

	/* DDR PHY CMD Register configuration */
    regVal = pDdrEmifPhyCfg->slaveRatio;
    HW_WR_REG32((CMD0_SLAVE_RATIO_0)   , regVal);
    HW_WR_REG32((CMD1_SLAVE_RATIO_0)   , regVal);
    HW_WR_REG32((CMD2_SLAVE_RATIO_0)   , regVal);

    if(SBL_PLATFORM_MEM_TYPE_DDR2 == memType)
    {
        regVal = pDdrEmifPhyCfg->slaveForce;
        HW_WR_REG32((CMD0_SLAVE_FORCE_0)   , regVal);
        HW_WR_REG32((CMD1_SLAVE_FORCE_0)   , regVal);
	HW_WR_REG32((CMD2_SLAVE_FORCE_0)   , regVal);

	regVal = pDdrEmifPhyCfg->slaveDelay;
	HW_WR_REG32((CMD0_SLAVE_DELAY_0)   , regVal);
	HW_WR_REG32((CMD1_SLAVE_DELAY_0)   , regVal);
	HW_WR_REG32((CMD2_SLAVE_DELAY_0)   , regVal);
    }

    regVal = pDdrEmifPhyCfg->invertClkout;
    HW_WR_REG32((CMD0_INVERT_CLKOUT_0)   , regVal);
    HW_WR_REG32((CMD1_INVERT_CLKOUT_0)   , regVal);
    HW_WR_REG32((CMD2_INVERT_CLKOUT_0)   , regVal);

    /* DDR PHY DATA Register configuration */
    regVal = pDdrEmifPhyCfg->rdDqsSlaveRatio;
    HW_WR_REG32((DATA0_RD_DQS_SLAVE_RATIO_0)  , regVal);
    HW_WR_REG32((DATA1_RD_DQS_SLAVE_RATIO_0)  , regVal);

    regVal = pDdrEmifPhyCfg->wrDqsSlaveRatio;
    HW_WR_REG32((DATA0_WR_DQS_SLAVE_RATIO_0)  , regVal);
    HW_WR_REG32((DATA1_WR_DQS_SLAVE_RATIO_0)  , regVal);

    regVal = pDdrEmifPhyCfg->fifoWeSlaveRatio;
    HW_WR_REG32((DATA0_FIFO_WE_SLAVE_RATIO_0)  , regVal);
    HW_WR_REG32((DATA1_FIFO_WE_SLAVE_RATIO_0)  , regVal);

    regVal = pDdrEmifPhyCfg->wrDataSlaveRatio;
    HW_WR_REG32((DATA0_WR_DATA_SLAVE_RATIO_0)  , regVal);
    HW_WR_REG32((DATA1_WR_DATA_SLAVE_RATIO_0)  , regVal);
}

void SblPlatformDdrConfig(uint32_t dynPwrDown,sblPlatformDdrCfg_t *pDdrCfg, uint32_t memType)
{
    volatile uint32_t delay = 5000;
    volatile uint32_t regVal, structVal;
    sblPlatformDdrCtrlCfg_t *pDdrCtrlCfg = &pDdrCfg->ddrCtrlCfg;
    sblPlatformDdrEmifCfg_t *pDdrEmifCfg = &pDdrCfg->ddrEmifCfg;

    /* DDR2 Phy Initialization */
    SblPlatformDdrPhyInit(&pDdrCfg->ddrEmifPhyCfg, memType);

    regVal = pDdrCtrlCfg->addrIoCtrl;
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_CMD_IOCTRL(0)) , regVal);
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_CMD_IOCTRL(1)) , regVal);
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_CMD_IOCTRL(2)) , regVal);

    regVal = pDdrCtrlCfg->dataIoCtrl;
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_DATA_IOCTRL(0)) , regVal);
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_DATA_IOCTRL(1)) , regVal);

    /* IO to work for DDR */
    regVal = HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_DDR_IO_CTRL);
    structVal = pDdrCtrlCfg->ddrIoCtrl;
    regVal &= structVal;
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_DDR_IO_CTRL), regVal);

    HW_WR_FIELD32_RAW(SOC_CONTROL_REGS + CONTROL_DDR_CKE_CTRL,
        CONTROL_DDR_CKE_CTRL_DDR_CKE_CTRL, CONTROL_DDR_CKE_CTRL_DDR_CKE_CTRL_SHIFT, 1U);

    regVal = pDdrEmifCfg->ddrPhyCtrl;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1) , regVal);

    /* Dynamic Power Down */
    if(TRUE == dynPwrDown)
    {
        regVal = HW_RD_REG32(SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1);
        structVal = pDdrEmifCfg->ddrPhyCtrlDyPwrdn;
        regVal |= structVal;
        HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1), regVal);
    }
    regVal = pDdrEmifCfg->ddrPhyCtrl;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1_SHDW) ,
                                                 regVal);

    /* Dynamic Power Down */
    if(TRUE == dynPwrDown)
    {
        regVal = HW_RD_REG32(SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1_SHDW);
        structVal = pDdrEmifCfg->ddrPhyCtrlDyPwrdn;
        regVal |= structVal;
        HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_1_SHDW), regVal);
    }
    regVal = pDdrEmifCfg->ddrPhyCtrl;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_DDR_PHY_CTRL_2) , regVal);

    regVal = pDdrEmifCfg->sdramTim1;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_1)      , regVal);
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_1_SHDW) , regVal);

    regVal = pDdrEmifCfg->sdramTim2;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_2)      , regVal);
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_2_SHDW) , regVal);

    regVal = pDdrEmifCfg->sdramTim3;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_3)      , regVal);
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_TIM_3_SHDW) , regVal);

    regVal = pDdrEmifCfg->sdramCfg;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_CONFIG)     , regVal);

    regVal = pDdrEmifCfg->sdramRefCtrl1;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_REF_CTRL)   , regVal);
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_REF_CTRL_SHDW) , regVal);

    if(SBL_PLATFORM_MEM_TYPE_DDR2 == memType)
    {
        while(delay--);
        regVal = pDdrEmifCfg->sdramRefCtrl2;
        HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_REF_CTRL) , regVal);
        HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_REF_CTRL_SHDW) , regVal);
    }

    if(SBL_PLATFORM_MEM_TYPE_DDR3 == memType)
    {
        regVal = pDdrEmifCfg->zqConfig;
        HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_ZQ_CONFIG)     , regVal);
    }

    regVal = pDdrEmifCfg->sdramCfg;
    HW_WR_REG32((SOC_EMIF_0_REGS + EMIF_SDRAM_CONFIG)     , regVal);

    /* The CONTROL_SECURE_EMIF_SDRAM_CONFIG register exports SDRAM configuration
       information to the EMIF */
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_SECURE_EMIF_SDRAM_CONFIG) , regVal);
}

/*
 * \brief This function initializes the EMIF
 */
void SblPlatformDdrEmifInit(void)
{
    HW_WR_FIELD32_RAW(SOC_CM_PER_REGS + CM_PER_EMIF_FW_CLKCTRL,
        CM_PER_EMIF_FW_CLKCTRL_MODULEMODE,
        CM_PER_EMIF_FW_CLKCTRL_MODULEMODE_SHIFT,
        CM_PER_EMIF_FW_CLKCTRL_MODULEMODE_ENABLE);

    HW_WR_FIELD32_RAW(SOC_CM_PER_REGS + CM_PER_EMIF_CLKCTRL,
        CM_PER_EMIF_CLKCTRL_MODULEMODE,
        CM_PER_EMIF_CLKCTRL_MODULEMODE_SHIFT,
        CM_PER_EMIF_CLKCTRL_MODULEMODE_ENABLE);

    while((CM_PER_L3_CLKSTCTRL_CLKACTIVITY_EMIF_GCLK_ACT !=
        HW_RD_FIELD32_RAW(SOC_CM_PER_REGS + CM_PER_L3_CLKSTCTRL,
        CM_PER_L3_CLKSTCTRL_CLKACTIVITY_EMIF_GCLK,
        CM_PER_L3_CLKSTCTRL_CLKACTIVITY_EMIF_GCLK_SHIFT)) ||
        (CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_ACT !=
        HW_RD_FIELD32_RAW(SOC_CM_PER_REGS + CM_PER_L3_CLKSTCTRL,
        CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK,
        CM_PER_L3_CLKSTCTRL_CLKACTIVITY_L3_GCLK_SHIFT)));
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

		//while(1);
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
