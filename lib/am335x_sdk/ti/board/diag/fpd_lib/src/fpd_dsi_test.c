/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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

/**
 *  \file   fpd_dsi_test.c
 *
 *  \brief  fpd dsi test file
 *
 *  Targeted Functionality: Verification of basic read write verification 
 *  of FPD library API's
 *
 *  Operation: This test is used to verify write and read back of all
 *  fpd library API's by setting and clearing the most possible bits
 *  of all register configurations supported by library API's.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 *
 */
 
#include "fpd_dsi_test.h"

extern I2C_config_list I2C_config;

Board_FpdModuleObj fpdDsiModParams = {0x2C, 0x16, 0x11};

Board_FpdRmtDevObj fpdDsiRmtParams[8] =
{
    {0x2c, 0x11},//Remote derializer(UB924) divice physical and alias addresses
    {0x40, 0x12},//Remote sensor device0 physial and alias addresses
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00}
};

Board_FpdRmtDevObj testSetfpdDsiRmtParams[8] =
{
    {0xff, 0xff}, 
    {0xff, 0xff}, 
    {0xff, 0xff},
    {0xff, 0xff},
    {0xff, 0xff},
    {0xff, 0xff},
    {0xff, 0xff},
    {0xff, 0xff}
};

Board_FpdRmtDevObj testClrfpdDsiRmtParams[8] =
{
    {0x01, 0x01}, 
    {0x01, 0x01}, 
    {0x01, 0x01},
    {0x01, 0x01},
    {0x01, 0x01},
    {0x01, 0x01},
    {0x01, 0x01},
    {0x01, 0x01}
};

uint8_t ub941DefReg[] = {
    0x08,
    0x00,
    0x58,
    0x01,  
    0x10,
    0x92,
    0x02,
    0x07,
    0x80,
    0x8c,
    0x10,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x1E
};

fpdRegCfgObj_t ub941RegDetails[] = 
{
    {
        BOARD_FPD_UB941_RESET_CTL_REG_ADDR,
        0U,
        (uint8_t)RESET_CTL_REG_CMP_MASK,
        (uint8_t)(~(RESET_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR,
        0U,
        (uint8_t)DEVICE_CFG_REG_CMP_MASK,
        (uint8_t)(~(DEVICE_CFG_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_DES_ID_REG_ADDR,
        0U,
        0U,
        0U,
        0x81U,
        0x01U
    },

    {
        BOARD_FPD_UB941_TX_PORT_SEL_REG_ADDR,
        0U,
        (uint8_t)TX_PORT_SEL_REG_CMP_MASK,
        (uint8_t)(~(TX_PORT_SEL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR,
        0U,
        (uint8_t)IND_ACC_CTL_REG_CMP_MASK,
        (uint8_t)(~(IND_ACC_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR,
        0U,
        (uint8_t)GENERAL_CFG_REG_CMP_MASK, 
        (uint8_t)(~(GENERAL_CFG_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_BRIDGE_CFG_REG_ADDR,
        0U,
        (uint8_t)BRIDGE_CFG_REG_CMP_MASK,
        (uint8_t)(~(BRIDGE_CFG_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_DUAL_CTL2_REG_ADDR,
        0U,
        (uint8_t)DUAL_CTL2_REG_CMP_MASK,
        (uint8_t)(~(DUAL_CTL2_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_DUAL_CTL1_REG_ADDR,
        0U,
        (uint8_t)DUAL_CTL1_REG_CMP_MASK,
        0xF8U,
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR,
        0U,
        (uint8_t)BRIDGE_CTL_REG_CMP_MASK,
        (uint8_t)(~(BRIDGE_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR,
        0U,
        (uint8_t)PGCTL_PGCTL_P1_REG_CMP_MASK,
        (uint8_t)~(PGCTL_PGCTL_P1_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID0_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID1_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID2_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ID7_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_0_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_1_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_2_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_SLAVE_ALIAS_7_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB941_I2C_CONTROL_REG_ADDR,
        0U,
        (uint8_t)I2C_CONTROL_REG_CMP_MASK,
        (uint8_t)~(I2C_CONTROL_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_DEVICES_CONFIG_END,
        0U,
        0U,
        0U,
        0U,
        0U
    }
};

uint8_t ub924DefReg[] = {
    0xf0,
    0x1e,
    0x00,
    0x80,
    0x83,
    0x00,
    0x00,
    0x08,
    0x08,
    0x10,
    0x00,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00
};

fpdRegCfgObj_t ub924RegDetails[] = {
    {
        BOARD_FPD_UB924_GENERAL_CNFG1_REG_ADDR,
        0U,
        GENERAL_CNFG1_REG_CMP_MASK,
        (uint8_t)~(GENERAL_CNFG1_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_I2C_CONTROL1_REG_ADDR,
        0U,
        BOARD_FPD_UB924_I2C_PASS_ALL_BIT_MASK,
        (uint8_t)~(BOARD_FPD_UB924_I2C_PASS_ALL_BIT_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_GENERAL_CNFG0_REG_ADDR,
        0U,
        GENERAL_CNFG0_REG_CMP_MASK,
        (uint8_t)~(GENERAL_CNFG0_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_DATA_PATH_CONTROL_REG_ADDR,
        0U,
        (uint8_t)DATA_PATH_CONTROL_REG_CMP_MASK,
        (uint8_t)~(DATA_PATH_CONTROL_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_SCL_HIGH_TIME_REG_ADDR,
        0U,
        0U,
        0U,
        0x50U,
        (uint8_t)(0x50U)
    },
    
    {
        BOARD_FPD_UB924_FRC_CONTROL_REG_ADDR,
        0U,
        FRC_CONTROL_REG_CMP_MASK,
        (uint8_t)~(FRC_CONTROL_REG_CMP_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_PG_INT_CLK_EN_REG_ADDR,
        0U,
        BOARD_FPD_UB924_PG_INT_CLK_EN_BIT_MASK,
        (uint8_t)~(BOARD_FPD_UB924_PG_INT_CLK_EN_BIT_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_LVDS_DRV_SETTING_REG_ADDR,
        0U,
        0U,
        (uint8_t)~0U,
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_LOOP_THR_DRV_REG_ADDR,
        0U,
        BOARD_FPD_UB924_LOOP_THR_DRV_BIT_MASK,
        (uint8_t)~(BOARD_FPD_UB924_LOOP_THR_DRV_BIT_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_PG_CONTROL_REG_ADDR,
        0U,
        FPD_UB924_PG_CONTROL_REG_MASK,
        (uint8_t)~(FPD_UB924_PG_CONTROL_REG_MASK),
         0U,
         0U
     }, 

    {
        BOARD_FPD_UB924_PG_CNFG_REG_ADDR,
        0U,
        FPD_UB924_PG_CNFG_REG_MASK, 
        (uint8_t)~(FPD_UB924_PG_CNFG_REG_MASK),
         0U,
         0U
     },

    {
        BOARD_FPD_UB924_GPIO0_CFG_REG_ADDR,
        0U,
        FPD_UB924_GPIO0_CFG_REG_MASK, 
        (uint8_t)~(FPD_UB924_GPIO0_CFG_REG_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_GPIO1_CFG_REG_ADDR,
        0U,
        FPD_UB924_GPIO1_CFG_REG_MASK, 
        (uint8_t)~(FPD_UB924_GPIO1_CFG_REG_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_GPIO3_CFG_REG_ADDR,
        0U,
        FPD_UB924_GPIO3_CFG_REG_MASK,
        (uint8_t)~(FPD_UB924_GPIO3_CFG_REG_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_GPIO5_CFG_REG_ADDR,
        0U,
        FPD_UB924_GPIO5_CFG_REG_MASK,
        (uint8_t)~(FPD_UB924_GPIO5_CFG_REG_MASK),
        0U,
        0U
    },

    {
        BOARD_FPD_UB924_GPIO7_CFG_REG_ADDR,
        0U,
        FPD_UB924_GPIO7_CFG_REG_MASK,
        (uint8_t )~(FPD_UB924_GPIO7_CFG_REG_MASK),
        0U,
        0U
    },

    {
        BOARD_DEVICES_CONFIG_END,
        0U,
        0U,
        0U,
        0U,
        0U
    }
};

#if !defined (__aarch64__)
/**
 * \brief   Configures the i2c domain base address
 *
 * \param   instNum [IN] I2C instance number.
 *
 * \return  int8_t  
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
static bool BoardDiag_setMainI2CInstBaseAddr(uint8_t instNum)
{
    bool errStatFlag = false;
    switch(instNum)
    {
        case 0:
        enableMAINI2C(instNum, CSL_I2C0_CFG_BASE);
        break;
        case 1:
        enableMAINI2C(instNum, CSL_I2C1_CFG_BASE);
        break;
        case 2:
        enableMAINI2C(instNum, CSL_I2C2_CFG_BASE);
        break;
        case 3:
        enableMAINI2C(instNum, CSL_I2C3_CFG_BASE);
        break;
        case 4:
        enableMAINI2C(instNum, CSL_I2C4_CFG_BASE);
        break;
        case 5:
        enableMAINI2C(instNum, CSL_I2C5_CFG_BASE);
        break;
        case 6:
        enableMAINI2C(instNum, CSL_I2C6_CFG_BASE);
        break;
        default:
        UART_printf("The user requested instance doesn't available\n\r");
        errStatFlag = true;
        break;
    }
    return errStatFlag;
}
#endif

static int8_t Board_fpdUB941SetCfg(void *handle)
{
    int8_t ret = 0;
    
    ret = Board_fpdUb941SetResetModeCtrl((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_MODE_RESET);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetResetModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetDsi1ClkPinOrd((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_UB941_CLK_LANE_PN_SWAP);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetDsi1ClkPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi1DataPinOrd((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_UB941_DATA_LANE_PN_SWAP);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi1DataPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi0ClkPinOrd((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_UB941_CLK_LANE_PN_SWAP);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi0ClkPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi0DataPinOrd((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_UB941_DATA_LANE_PN_SWAP);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi0DataPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941DevIdCfg((void *)handle,
                                 &fpdDsiModParams,
                                 0x40);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941DevIdCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelI2CAccessPort((void *)handle,
                                         &fpdDsiModParams,
                                         (BOARD_FPD_UB941_PORT0_SEL | \
                                         BOARD_FPD_UB941_PORT1_SEL | \
                                         BOARD_FPD_UB941_PORT1_I2C_EN));
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelI2CAccessPort' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941IndirRegAccBlkSel((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_UB941_FPD_LINK_III_PORT0_PORT1_REG);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941IndirRegAccBlkSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941InDirRegAccModeSel((void *)handle,
                                           &fpdDsiModParams,
                                           BOARD_FPD_UB941_WRITE_ACCESS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941InDirRegAccModeSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetRxCRCCheckerEn((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetRxCRCCheckerEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetFilterEn((void *)handle,
                                    &fpdDsiModParams,
                                    BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetFilterEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetPCLKAutoEnModeCfg((void *)handle,
                                             &fpdDsiModParams,
                                             BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetPCLKAutoEnModeCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetPixelBytes((void *)handle,
                                      &fpdDsiModParams,
                                      0x03);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetPixelBytes' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetFreqStblThr((void *)handle,
                                       &fpdDsiModParams,
                                       BOARD_FPD_UB941_FREQ_STBL_1280);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetFreqStblThr' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetIndirRegRdEn((void *)handle,
                                        &fpdDsiModParams,
                                        BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetIndirRegRdEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941Tx_Mode((void *)handle,
                                &fpdDsiModParams,
                                BOARD_FPD_UB941_FORCED_SPLITTER_MODE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941Tx_Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetSerClkModeCtrl((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetSerClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetDsiLaneModeCtrl((void *)handle,
                                           &fpdDsiModParams,
                                           BOARD_FPD_UB941_LANES_4);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetDsiLaneModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetInvtdClrPattEn((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetInvtdClrPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetAutoScrollPattEn((void *)handle,
                                            &fpdDsiModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetAutoScrollPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941ColorBarEn((void *)handle,
                                   &fpdDsiModParams,
                                   BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941ColorBarEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelPatt((void *)handle,
                                &fpdDsiModParams,
                                BOARD_FPD_UB941_PATTERN_VCOM);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelPatt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941PattGenEn((void *)handle,
                                  &fpdDsiModParams,
                                  BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941PattGenEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941RmtDesAliasCfg((void *)handle,
                                       &fpdDsiModParams,
                                       testSetfpdDsiRmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941RmtDesAliasCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetI2CPassAllModeCtrl((void *)handle,
                                              &fpdDsiModParams,
                                              BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetI2CPassAllModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetI2CPassThrModeCfg((void *)handle,
                                             &fpdDsiModParams,
                                             BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetI2CPassThrModeCfg' cfg failed\n\r");
        return -1;
    }

    return ret;
}

static int8_t Board_fpdUB941ClrCfg(void *handle)
{
    int8_t ret = 0;
    
    ret = Board_fpdUb941RmtDesAliasCfg((void *)handle,
                                       &fpdDsiModParams,
                                       testClrfpdDsiRmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941RmtDesAliasCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetI2CPassAllModeCtrl((void *)handle,
                                              &fpdDsiModParams,
                                              BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetI2CPassAllModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetI2CPassThrModeCfg((void *)handle,
                                             &fpdDsiModParams,
                                             BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetI2CPassThrModeCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetResetModeCtrl((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_MODE_NORMAL);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetResetModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetDsi1ClkPinOrd((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetDsi1ClkPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi1DataPinOrd((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi1DataPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi0ClkPinOrd((void *)handle,
                                         &fpdDsiModParams,
                                         BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi0ClkPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelDsi0DataPinOrd((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelDsi0DataPinOrd' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941DevIdCfg((void *)handle,
                                 &fpdDsiModParams,
                                 0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941DevIdCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelI2CAccessPort((void *)handle,
                                         &fpdDsiModParams,
                                         0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelI2CAccessPort' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941IndirRegAccBlkSel((void *)handle,
                                          &fpdDsiModParams,
                                          0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941IndirRegAccBlkSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941InDirRegAccModeSel((void *)handle,
                                           &fpdDsiModParams,
                                           BOARD_FPD_UB941_READ_ACCESS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941InDirRegAccModeSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetRxCRCCheckerEn((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetRxCRCCheckerEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetFilterEn((void *)handle,
                                    &fpdDsiModParams,
                                    BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetFilterEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetPCLKAutoEnModeCfg((void *)handle,
                                             &fpdDsiModParams,
                                             BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetPCLKAutoEnModeCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetPixelBytes((void *)handle,
                                      &fpdDsiModParams,
                                      0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetPixelBytes' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetIndirRegRdEn((void *)handle,
                                        &fpdDsiModParams,
                                        BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetIndirRegRdEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941Tx_Mode((void *)handle,
                                &fpdDsiModParams,
                                BOARD_FPD_UB941_AUTO_DETECT_FPD3_MODE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941Tx_Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetSerClkModeCtrl((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetSerClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetDsiLaneModeCtrl((void *)handle,
                                           &fpdDsiModParams,
                                           BOARD_FPD_UB941_LANES_1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetDsiLaneModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetInvtdClrPattEn((void *)handle,
                                          &fpdDsiModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetInvtdClrPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetAutoScrollPattEn((void *)handle,
                                            &fpdDsiModParams,
                                            BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetAutoScrollPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SelPatt((void *)handle,
                                &fpdDsiModParams,
                                0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SelPatt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941ColorBarEn((void *)handle,
                                   &fpdDsiModParams,
                                   BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941ColorBarEn' cfg failed\n\r");
        return -1;
    }
    
    ret = Board_fpdUb941PattGenEn((void *)handle,
                                  &fpdDsiModParams,
                                  BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941PattGenEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb941SetFreqStblThr((void *)handle,
                                       &fpdDsiModParams,
                                       BOARD_FPD_UB941_FREQ_STBL_40);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb941SetFreqStblThr' cfg failed\n\r");
        return -1;
    }

    return ret;
}

static int8_t Board_fpdUB941VerifyCfg(void *handle,
                                      cfgVerifyFlag_t flag)
{
    int8_t index;
    int8_t ret;
    uint8_t regData;
    index = 0;
    while(ub941RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ret = Board_i2c8BitRegRd(handle,
                                 fpdDsiModParams.serSlvAddr,
                                 ub941RegDetails[index].regAddr,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            UART_printf("I2C register read fialed!\n\r"\
                        "while reading register with addr - 0x%x\n\r",
                        ub941RegDetails[index].regAddr);
        }

        if(flag == VERIFY_CLR_CONFIG)
        {
            if(regData == ub941RegDetails[index].expClrVal)
            {
                UART_printf("Clr verification successful\tRegAddr: 0x%x\tExpClrVal: 0x%x\tRegData: 0x%x\n\r", ub941RegDetails[index].regAddr, ub941RegDetails[index].expClrVal, regData);
            }
            else
            {
                UART_printf("Clr verification failed\tRegAddr:0x%x\tExpClrVal:0x%x\tRegData:0x%x\n\r", ub941RegDetails[index].regAddr, ub941RegDetails[index].expClrVal, regData);
                return -1;
            }
        }
        else
        {
            if(regData == ub941RegDetails[index].expSetVal)
            {
                UART_printf("Set verification successful\tRegAddr: 0x%x\texpSetVal: 0x%x\tRegData: 0x%x\n\r", ub941RegDetails[index].regAddr , ub941RegDetails[index].expSetVal, regData);
            }
            else
            {
                UART_printf("Set verification failed\tRegAddr0x%x\texpSetVal: 0x%x\tRegData: 0x%x\n\r", ub941RegDetails[index].regAddr , ub941RegDetails[index].expSetVal, regData);
                return -1;
            }
        }
        index++;
    }

    return 0;
}

static int8_t Board_fpdUB924SetCfg(void *handle)
{
    Board_STATUS ret;
    
    ret = Board_fpdUb924SelDesHSSyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHSSyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesVSSyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesVSSyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDESyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDESyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesFRC2Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFRC2Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesFRC1Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFRC1Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesHiFRC2Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHiFRC2Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesHiFRC1Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHiFRC1Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesFilterEnMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFilterEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetI2CPassThrModeCfg(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetI2CPassThrModeCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesAutoACKMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesAutoACKMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDEGateMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDEGateMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPassAllMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPassAllMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesAutoClkEnMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesAutoClkEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesBKWDMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesBKWDMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDEPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDEPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetDesI2cBusFreq(handle, &fpdDsiModParams, 0x50);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetDesI2cBusFreq' cfg failed\n\r");
        return -1;
    }

   ret = Board_fpdUb924SetDesPGIntClkEn(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetDesPGIntClkEn' cfg failed\n\r");
        return -1;
    }
    
    ret = Board_fpdUb924CfgDesLoopThrDrv(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924CfgDesLoopThrDrv' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesClrBarPatMode(handle,
                                            &fpdDsiModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesClrBarPatMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGBitMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGBitMode' cfg failed\n\r");
        return -1;
    } 

    ret = Board_fpdUb924SelDesPGExtClk(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGExtClk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGTmngSel(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGTmngSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetAutoScrollPattEn(handle, &fpdDsiModParams, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetAutoScrollPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

   return 0;
}

static int8_t Board_fpdUB924ClrCfg(void *handle)
{
    Board_STATUS ret;

    ret = Board_fpdUb924SelDesFilterEnMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFilterEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetI2CPassThrModeCfg(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetI2CPassThrModeCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesAutoACKMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesAutoACKMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDEGateMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDEGateMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPassAllMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPassAllMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesAutoClkEnMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesAutoClkEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesBKWDMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesBKWDMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDEPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDEPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetDesI2cBusFreq(handle, &fpdDsiModParams, 0x50);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetDesI2cBusFreq' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesHSSyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHSSyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesVSSyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesVSSyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesDESyncPolarity(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesDESyncPolarity' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesFRC2Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFRC2Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesFRC1Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesFRC1Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesHiFRC2Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHiFRC2Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesHiFRC1Mode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesHiFRC1Mode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetDesPGIntClkEn(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetDesPGIntClkEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924CfgDesLoopThrDrv(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924CfgDesLoopThrDrv' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesClrBarPatMode(handle,
                                            &fpdDsiModParams,
                                            BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesClrBarPatMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGBitMode(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGBitMode' cfg failed\n\r");
        return -1;
    } 

    ret = Board_fpdUb924SelDesPGExtClk(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGExtClk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesPGTmngSel(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesPGTmngSel' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SetAutoScrollPattEn(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SetAutoScrollPattEn' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO0, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO1, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO2, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioRemoteMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioRemoteMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO3, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO5, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO6, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO7, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioOutputMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioOutputMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioDirectionMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioDirectionMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924GpioEnMode(handle, &fpdDsiModParams, BOARD_FPD_UB924_GPIO8, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924GpioEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesLFMODEOvr(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesLFMODE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb924SelDesLFMODEOvr(handle, &fpdDsiModParams, BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb924SelDesLFMODE' cfg failed\n\r");
        return -1;
    }

    return 0;
}

static int8_t Board_fpdUB924VerifyCfg(void *handle,
                                      cfgVerifyFlag_t flag)
{
    int8_t index;
    int8_t ret;
    uint8_t regData;
    index = 0;
    while(ub924RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ret = Board_i2c8BitRegRd(handle,
                                 0x11,
                                 ub924RegDetails[index].regAddr,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            UART_printf("I2C register read fialed!\n\r"\
                        "while reading register with addr - 0x%x\n\r",
                        ub924RegDetails[index].regAddr);
        }

        if(flag == VERIFY_CLR_CONFIG)
        {
            if(regData == ub924RegDetails[index].expClrVal)
            {
                UART_printf("Clr verification successful\tRegAddr: 0x%x\tExpClrVal: 0x%x\tRegData: 0x%x\n\r", ub924RegDetails[index].regAddr, ub924RegDetails[index].expClrVal, regData);
            }
            else
            {
                UART_printf("Clr verification failed\tRegAddr:0x%x\tExpClrVal:0x%x\tRegData:0x%x\n\r", ub924RegDetails[index].regAddr, ub924RegDetails[index].expClrVal, regData);
                return -1;
            }
        }
        else
        {
            if(regData == ub924RegDetails[index].expSetVal)
            {
                UART_printf("Set verification successful\tRegAddr: 0x%x\texpSetVal: 0x%x\tRegData: 0x%x\n\r", ub924RegDetails[index].regAddr , ub924RegDetails[index].expSetVal, regData);
            }
            else
            {
                UART_printf("Set verification failed\tRegAddr0x%x\texpSetVal: 0x%x\tRegData: 0x%x\n\r", ub924RegDetails[index].regAddr , ub924RegDetails[index].expSetVal, regData);
                return -1;
            }
        }
        index++;
    }

    return 0;
}

/**
 *  \brief    Runs the fpd lib test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_fpd_dsi_test(void)
{
    Board_STATUS ret = BOARD_SOK;
    int8_t index = 0;
    uint8_t domain;
    uint8_t i2cInst;
    uint8_t slaveAddr;
    
#if !defined (__aarch64__)
    bool errFlag;
#endif

    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz; /* 400KHz */

    Board_fpdUb941GetI2CAddr(&domain, &i2cInst, &slaveAddr);

    if(domain == BOARD_SOC_DOMAIN_MAIN)
    {
#if !defined (__aarch64__)
        /* MCU I2C instance will be active by default for R5 core.
         * Need update HW attrs to enable MAIN I2C instance.
         */
        errFlag = BoardDiag_setMainI2CInstBaseAddr(i2cInst);
        if(errFlag == true)
        {
            return -1;            
        }
#endif
    }
    else if(domain == BOARD_SOC_DOMAIN_WKUP)
    {
#if !defined (__aarch64__)
        /* MCU I2C instance will be active by default for R5 core.
         * Need update HW attrs to enable MAIN I2C instance.
         */
        enableI2C(CSL_WKUP_I2C0_CFG_BASE);
#endif
    }
    else
    {
#if defined (__aarch64__)
        /* MCU I2C instance will be active by default for R5 core.
         * Need update HW attrs to enable MAIN I2C instance.
         */
        enableI2C(CSL_MCU_I2C0_CFG_BASE);
#endif
    }

    fpdDsiModParams.serSlvAddr = slaveAddr;

    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(i2cInst, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        ret = -1;
        return ret;
    }

    UART_printf("Initializing the host serializer...\n\r");
    ret = Board_fpdUb941SerInit((void *)handle,
                                &fpdDsiModParams,
                                &fpdDsiRmtParams[0]);
    if(ret != 0)
    {
        UART_printf("FPD serializer initialization failed\n\r");
        return -1;
    }
    else
    {
        UART_printf("FPD serializer initialization successful\n\r");
    }

    index = 0;
    while(ub924RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ub924RegDetails[index].defVal = ub924DefReg[index];
        if(ub924RegDetails[index].expSetVal == 0U)
        {
            ub924RegDetails[index].expSetVal = (ub924RegDetails[index].defVal | ub924RegDetails[index].setVal);
        }
        if(ub924RegDetails[index].expClrVal == 0U)
        {
            ub924RegDetails[index].expClrVal = (ub924RegDetails[index].defVal & ub924RegDetails[index].clrVal);
        }
        index++;

    }

    UART_printf("Set FPD UB924 deserializer configuration...\n\r");
    ret = Board_fpdUB924SetCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Deserializer configuration set successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer configuration set failed\n\r\n\r");
        return -1;
    }
    ret = Board_fpdUB924VerifyCfg((void *)handle,
                                  VERIFY_SET_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB924) set config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB924) set config verification failed\n\r\n\r");
        return -1;
    }

    UART_printf("Clear FPD UB941 serializer configuration...\n\r");
    ret = Board_fpdUB924ClrCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB924) clear config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB924) clear config failed\n\r\n\r");
        return -1;
    }

    ret = Board_fpdUB924VerifyCfg((void *)handle,
                                  VERIFY_CLR_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB924) clear config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB924) clear config verification failed\n\r\n\r");
        return -1;
    }

    index = 0;
    UART_printf("Initializing with default reg value...\n\r");
    while(ub941RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ub941RegDetails[index].defVal = ub941DefReg[index];
        if(ub941RegDetails[index].expSetVal == 0U)
        {
            ub941RegDetails[index].expSetVal = (ub941RegDetails[index].defVal | ub941RegDetails[index].setVal);
        }
        if(ub941RegDetails[index].expClrVal == 0U)
        {
            ub941RegDetails[index].expClrVal = (ub941RegDetails[index].defVal & ub941RegDetails[index].clrVal);
        }
        index++;
    }

    /* serilizer digital reset to reset all the serializer configurations */
    UART_printf("Resetting the serializer...\n\r");
    ret = Board_fpdUb941SetDigitalRst1ModeCtrl(handle,
                                               &fpdDsiModParams,
                                               BOARD_FPD_MODE_RESET);
    if(ret != 0)
    {
        UART_printf("Resetting the serializer failed\n\r");
        return -1;
    }

    UART_printf("Set FPD UB941 serializer configuration...\n\r");
    ret = Board_fpdUB941SetCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Serializer(UB941) set config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Serializer(UB941) set config failed\n\r\n\r");
        return -1;
    }

    ret = Board_fpdUB941VerifyCfg((void *)handle,
                                  VERIFY_SET_CONFIG);
    if(ret == 0)
    {
        UART_printf("Serializer(UB941) set config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Serializer(UB941) set config verification failed\n\r\n\r");
        return -1;
    }

    UART_printf("Clear FPD UB941 serializer configuration...\n\r");
    ret = Board_fpdUB941ClrCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Serializer(UB941) clear config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Serializer(UB941) clear config failed\n\r\n\r");
        return -1;
    }

    ret = Board_fpdUB941VerifyCfg((void *)handle,
                                  VERIFY_CLR_CONFIG);
    if(ret == 0)
    {
        UART_printf("Serializer(UB941) clear config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Serializer(UB941) clear config verification failed\n\r\n\r");
        return -1;
    }

    I2C_close(handle);

    return ret;
}

/**
 *  \brief    The function performs the fpd lib verification test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
 
int8_t BoardDiag_fpd_dsi_test(void)
{
	int8_t ret = 0;
    Board_I2cInitCfg_t i2cCfg;

    UART_printf("\nRunning FPD LIB verification test\n");

    /*setting power mux for dsi lcd*/
    i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE4_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    Board_i2cIoExpInit();

    UART_printf("UB941 serializer enable external power reset\n\r");
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE4_ADDR,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_7,
                                  PIN_DIRECTION_OUTPUT);

    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE4_ADDR,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_7,
                              GPIO_SIGNAL_LEVEL_HIGH);

    UART_printf("DSI power switch control enable\n\r");
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE4_ADDR,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_2,
                                  PIN_DIRECTION_OUTPUT);

    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE4_ADDR,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_2,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cIoExpDeInit();
    
    ret = BoardDiag_run_fpd_dsi_test();
    if(ret == 0)
    {
        UART_printf("\nFPD DSI test Passed\n");             
    }
    else
    {
        UART_printf("\nFPD DSI test Failed\n");                     
    }

    return ret;
    
}
