/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   fpd_ub9702.c
 */
 
#include "fpd_csi_test.h"

I2C_Handle csiHandle = NULL;

Board_FpdModuleObj fpdUb9702ModParams = {0x32, 0x00, 0x00};

Board_FpdRmtDevObj fpdUb9702RmtParams[8] =
{
    {0x00, 0x00}, //Remote serializer(UB925) divice physical and alias addresses
    {0x00, 0x00}, //Remote sensor device0 physial and alias addresses
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00}
};

Board_FpdRmtDevObj testSetfpdUb9702RmtParams[8] =
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

Board_FpdRmtDevObj testClrfpdUb9702RmtParams[8] =
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

uint8_t ub9702DefReg[] = {
    /*0x64,//BOARD_FPD_UB9702_I2C_DEVICE_ID_REG_ADDR*/
    0x1e,
    0xfe,
    0x0f,
    0xb9,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x04,
    0x02,
    0xf0,
    0x00,
    0x00,
    0x40,
    0x00,
    0x1a,
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
    0x00
};

fpdRegCfgObj_t ub9702RegDetails[] = {

    /*{
        BOARD_FPD_UB9702_I2C_DEVICE_ID_REG_ADDR,
        0U,
        (uint8_t)I2C_DEVICE_ID_REG_CMP_MASK,
        (uint8_t)(~(I2C_DEVICE_ID_REG_CMP_MASK)),
        0U,
        0U
    },*/

    {
        BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR,
        0U,
        (uint8_t)GENERAL_CFG_REG_CMP_MASK,
        (uint8_t)(~(GENERAL_CFG_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_BCC_WATCHDOG_CONTROL_REG_ADDR,
        0U,
        (uint8_t)(BCC_WATCHDOG_CONTROL_REG_CMP_MASK | BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_BIT_MASK),
        (uint8_t)(~(BCC_WATCHDOG_CONTROL_REG_CMP_MASK)) | BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_BIT_MASK,
        0U,
        0x01U,
    },

    {
        BOARD_FPD_UB9702_RX_PORT_CTL_REG_ADDR,
        0U,
        (uint8_t)RX_PORT_CTL_REG_CMP_MASK,
        (uint8_t)(~(RX_PORT_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_IO_CTL_REG_ADDR,
        0U,
        (uint8_t)IO_CTL_REG_CMP_MASK,
        0U,
        0U,
        0x49U
    },

    {
        BOARD_FPD_UB9702_FS_CTL_REG_ADDR,
        0U,
        (uint8_t)FS_CTL_REG_CMP_MASK,
        (uint8_t)(~(FS_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FS_HIGH_TIME_1_REG_ADDR,
        0U,
        (uint8_t)FS_HIGH_TIME_1_REG_CMP_MASK,
        (uint8_t)(~(FS_HIGH_TIME_1_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FS_HIGH_TIME_0_REG_ADDR,
        0U,
        (uint8_t)FS_HIGH_TIME_0_REG_CMP_MASK,
        (uint8_t)(~(FS_HIGH_TIME_0_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FS_LOW_TIME_1_REG_ADDR,
        0U,
        (uint8_t)FS_LOW_TIME_1_REG_CMP_MASK,
        (uint8_t)(~(FS_LOW_TIME_1_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FS_LOW_TIME_0_REG_ADDR,
        0U,
        (uint8_t)FS_LOW_TIME_0_REG_CMP_MASK,
        (uint8_t)(~(FS_LOW_TIME_0_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_MAX_FRM_HI_REG_ADDR,
        0U,
        (uint8_t)MAX_FRM_HI_REG_CMP_MASK,
        (uint8_t)(~(MAX_FRM_HI_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_MAX_FRM_LO_REG_ADDR,
        0U,
        (uint8_t)MAX_FRM_LO_REG_CMP_MASK,
        (uint8_t)(~(MAX_FRM_LO_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_CSI_PLL_CTL_REG_ADDR,
        0U,
        (uint8_t)CSI_PLL_CTL_REG_CMP_MASK,
        (uint8_t)(~(CSI_PLL_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FWD_CTL1_REG_ADDR,
        0U,
        (uint8_t)FWD_CTL1_REG_CMP_MASK,
        (uint8_t)(~(FWD_CTL1_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_CSI_PORT_SEL_REG_ADDR,
        0U,
        (uint8_t)CSI_PORT_SEL_REG_CMP_MASK,
        (uint8_t)(~(CSI_PORT_SEL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_CSI_CTL_REG_ADDR,
        0U,
        (uint8_t)CSI_CTL_REG_CMP_MASK,
        (uint8_t)(~(CSI_CTL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_CSI_CTL2_REG_ADDR,
        0U,
        (uint8_t)CSI_CTL2_REG_CMP_MASK,
        (uint8_t)(~(CSI_CTL2_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_FPD3_PORT_SEL_REG_ADDR,
        0U,
        (uint8_t)FPD3_PORT_SEL_REG_CMP_MASK,
        (uint8_t)(~(FPD3_PORT_SEL_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR,
        0U,
        (uint8_t)BCC_CONFIG_REG_CMP_MASK,
        (uint8_t)(~(BCC_CONFIG_REG_CMP_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB9702_SlaveID_0_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_1_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_2_REG_ADDR, 
        0U, 
        0U, 
        0U, 
        0xfeU, 
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveID_7_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_0_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_1_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_2_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB9702_SlaveAlias_7_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
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

static int8_t Board_fpdUB9702SetCfg(void *csiHandle)
{
    int8_t ret = 0;
#if 0
    ret = Board_fpdUb9702SetDesDevId((void *)csiHandle,
                                     &fpdUb9702ModParams,
                                     0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetDesDevId' cfg failed\n\r");
        return -1;
    }
#endif
    ret = Board_fpdUb9702SetI2cMstrEnModeCtrl((void *)csiHandle,
                                              &fpdUb9702ModParams,
                                              BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2cMstrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOutputEnMode((void *)csiHandle,
                                         &fpdUb9702ModParams,
                                         BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOutputEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOutputEnCtrlMode((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOutputEnCtrlMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOSSSelModeCtrl((void *)csiHandle,
                                           &fpdUb9702ModParams,
                                           BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOSSSelModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCWatchDogTImer((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCWatchDogTImer' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC3_MAP,
                                             BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC3_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC2_MAP,
                                             BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC2_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC1_MAP,
                                             BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC1_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC0_MAP,
                                             BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC0_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC3_MAP,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC3_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC2_MAP,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC2_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC1_MAP,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC1_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC0_MAP,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC0_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSModeCtrl((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO7);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSGenEnModeCtrl((void *)csiHandle,
                                            &fpdUb9702ModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSGenEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSHighTime1((void *)csiHandle,
                                        &fpdUb9702ModParams,
                                        0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSHighTime1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSHighTime0((void *)csiHandle,
                                        &fpdUb9702ModParams,
                                        0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSHighTime0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSLowTime1((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSLowTime1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSLowTime0((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSLowTime0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetMaxFrameHiCnt((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetMaxFrameHiCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetMaxFrameLoCnt((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetMaxFrameLoCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelOscClk((void *)csiHandle,
                                   &fpdUb9702ModParams,
                                   BOARD_FPD_9702_SEL_INT_REF_CLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelOscClk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRefClkModeCtrl((void *)csiHandle,
                                           &fpdUb9702ModParams,
                                           BOARD_FPD_9702_REf_CLK_100MHZ);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRefClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelCSITxSpeed((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_SERIAL_RATE_400_MBPS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelCSITxSpeed' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_3,
                                               BOARD_FPD_9702_FORWARD_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_3_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_2,
                                               BOARD_FPD_9702_FORWARD_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_2_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_1,
                                               BOARD_FPD_9702_FORWARD_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_1_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_0,
                                               BOARD_FPD_9702_FORWARD_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_0_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX3_MAP,
                                      BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX3_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX2_MAP,
                                      BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX2_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX1_MAP,
                                      BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX1_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX0_MAP,
                                      BOARD_I2C_SLAVE_PORT1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX0_PORT1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelTxPortRdBackRegBlk((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_TX_PORT_1_REG_BLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelTxPortRdBackRegBlk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetTxPort1WrEnModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetTxPort1WrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetTxPort0WrEnModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetTxPort0WrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSILaneCnt((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_CSI_LANES_1);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSILaneCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSIContsClkModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIContsClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSIEnableModeCtrl((void *)csiHandle,
                                              &fpdUb9702ModParams,
                                              BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIEnableModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSIPassModeCtrl((void *)csiHandle,
                                            &fpdUb9702ModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIPassModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelRxPortRdBackRegBlk((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_PORT_3_REG_BLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelRxPortRdBackRegBlk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_3,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_3_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_2,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_2_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_1,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_1_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_0,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_0_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetI2CPassThrAllModeCtrl((void *)csiHandle,
                                                  &fpdUb9702ModParams,
                                                  BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CPassThrAllModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetI2CPassThrModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CPassThrModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetI2CAutoAckModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CAutoAckModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCEnModeCtrl((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelBCFreq((void *)csiHandle,
                                   &fpdUb9702ModParams,
                                   BOARD_FPD_9702_100_MBPS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelBCFreq' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRmtSerId((void *)csiHandle,
                                     &fpdUb9702ModParams,
                                     0xFF);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRmtSerId' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702RmtSerSlvDevAliasIdCfg((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                testSetfpdUb9702RmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702RmtSerSlvDevAliasIdCfg' cfg failed\n\r");
        return -1;
    }
    return ret;
}

static int8_t Board_fpdUB9702ClrCfg(void *csiHandle)
{
    int8_t ret = 0;
    
    ret = Board_fpdUb9702RmtSerSlvDevAliasIdCfg((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                testClrfpdUb9702RmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702RmtSerSlvDevAliasIdCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSILaneCnt((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_CSI_LANES_4);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSILaneCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSIContsClkModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIContsClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetCSIEnableModeCtrl((void *)csiHandle,
                                              &fpdUb9702ModParams,
                                              BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIEnableModeCtrl' cfg failed\n\r");
        return -1;
    }
    
        ret = Board_fpdUb9702SetCSIPassModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetCSIPassModeCtrl' cfg failed\n\r");
        return -1;
    }
    
    ret = Board_fpdUb9702SetI2CPassThrAllModeCtrl((void *)csiHandle,
                                                  &fpdUb9702ModParams,
                                                  BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CPassThrAllModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetI2CPassThrModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CPassThrModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetI2CAutoAckModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2CAutoAckModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCEnModeCtrl((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelBCFreq((void *)csiHandle,
                                   &fpdUb9702ModParams,
                                   BOARD_FPD_9702_2500_KBPS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelBCFreq' cfg failed\n\r");
        return -1;
    }
#if 0
    ret = Board_fpdUb9702SetDesDevId((void *)csiHandle,
                                     &fpdUb9702ModParams,
                                     0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetDesDevId' cfg failed\n\r");
        return -1;
    }
#endif
    ret = Board_fpdUb9702SetI2cMstrEnModeCtrl((void *)csiHandle,
                                              &fpdUb9702ModParams,
                                              BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetI2cMstrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOutputEnMode((void *)csiHandle,
                                         &fpdUb9702ModParams,
                                         BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOutputEnMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOutputEnCtrlMode((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOutputEnCtrlMode' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetOSSSelModeCtrl((void *)csiHandle,
                                           &fpdUb9702ModParams,
                                           BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetOSSSelModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCWatchDogTImer((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCWatchDogTImer' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC3_MAP,
                                             BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC3_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC2_MAP,
                                             BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC2_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC1_MAP,
                                             BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC1_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetBCCI2CSlvPortMap((void *)csiHandle,
                                             &fpdUb9702ModParams,
                                             BOARD_FPD_UB9702_BCC0_MAP,
                                             BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetBCCI2CSlvPortMap_BCC0_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC3_MAP,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC3_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC2_MAP,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC2_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC1_MAP,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC1_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRcvrPortEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_UB9702_BCC0_MAP,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRcvrPortEnModeCtrl_BCC0_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSModeCtrl((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_INT_GEN_BC_FS_CLK_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSGenEnModeCtrl((void *)csiHandle,
                                            &fpdUb9702ModParams,
                                            BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSGenEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSHighTime1((void *)csiHandle,
                                        &fpdUb9702ModParams,
                                        0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSHighTime1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSHighTime0((void *)csiHandle,
                                        &fpdUb9702ModParams,
                                        0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSHighTime0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSLowTime1((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSLowTime1' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFSLowTime0((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFSLowTime0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetMaxFrameHiCnt((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetMaxFrameHiCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetMaxFrameLoCnt((void *)csiHandle,
                                          &fpdUb9702ModParams,
                                          0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetMaxFrameLoCnt' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelOscClk((void *)csiHandle,
                                   &fpdUb9702ModParams,
                                   BOARD_FPD_9702_SEL_EXT_REF_CLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelOscClk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRefClkModeCtrl((void *)csiHandle,
                                           &fpdUb9702ModParams,
                                           BOARD_FPD_9702_REf_CLK_200MHZ);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRefClkModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelCSITxSpeed((void *)csiHandle,
                                       &fpdUb9702ModParams,
                                       BOARD_FPD_9702_SERIAL_RATE_1600_MBPS);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelCSITxSpeed' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_3,
                                               BOARD_FPD_9702_FORWARD_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_3_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_2,
                                               BOARD_FPD_9702_FORWARD_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_2_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_1,
                                               BOARD_FPD_9702_FORWARD_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_1_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetFwdPortDisModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_FWD_PORT_0,
                                               BOARD_FPD_9702_FORWARD_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetFwdPortDisModeCtrl_PORT_0_ENABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX3_MAP,
                                      BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX3_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX2_MAP,
                                      BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX2_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX1_MAP,
                                      BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX1_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortMap((void *)csiHandle,
                                      &fpdUb9702ModParams,
                                      BOARD_FPD_9702_RX0_MAP,
                                      BOARD_I2C_SLAVE_PORT0);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortMap_RX0_PORT0' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelTxPortRdBackRegBlk((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_TX_PORT_0_REG_BLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelTxPortRdBackRegBlk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetTxPort1WrEnModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetTxPort1WrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetTxPort0WrEnModeCtrl((void *)csiHandle,
                                                &fpdUb9702ModParams,
                                                BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetTxPort0WrEnModeCtrl' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SelRxPortRdBackRegBlk((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_PORT_0_REG_BLK);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SelRxPortRdBackRegBlk' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_3,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_3_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_2,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_2_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_1,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_1_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRxPortWrEnModeCtrl((void *)csiHandle,
                                               &fpdUb9702ModParams,
                                               BOARD_FPD_9702_RX_WR_PORT_0,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRxPortWrEnModeCtrl_PORT_0_DISABLE' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetRmtSerId((void *)csiHandle,
                                     &fpdUb9702ModParams,
                                     0x00);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetRmtSerId' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetIOSupplyOverrideModeCtrl((void *)csiHandle,
                                                     &fpdUb9702ModParams,
                                                     BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetIOSupplyOverrideModeCtrl' cfg failed\n\r");
        return -1;
    }
    
    ret = Board_fpdUb9702SetIOPinSupply((void *)csiHandle,
                                        &fpdUb9702ModParams,
                                        BOARD_FPD_UB9702_IO_PIN_SUPPLY_1V8);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetIOPinSupply' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb9702SetIOSupplyMode((void *)csiHandle,
                                         &fpdUb9702ModParams,
                                         BOARD_FPD_UB9702_IO_SUPPLY_MODE_1V8);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb9702SetIOSupplyMode' cfg failed\n\r");
        return -1;
    }

    return ret;    
}

static int8_t Board_fpdUB9702VerifyCfg(void *csiHandle,
                                      cfgVerifyFlag_t flag)
{
    int8_t index;
    int8_t ret;
    uint8_t regData;
    index = 0;
    while(ub9702RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ret = Board_i2c8BitRegRd(csiHandle,
                                 fpdUb9702ModParams.desSlvAddr,
                                 ub9702RegDetails[index].regAddr,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            UART_printf("I2C register read fialed!\n\r"\
                        "while reading register with addr - 0x%x\n\r",
                        ub9702RegDetails[index].regAddr);
        }

        if(flag == VERIFY_CLR_CONFIG)
        {
            if(regData == ub9702RegDetails[index].expClrVal)
            {
                UART_printf("Clr verification successful\t0x%x\t0x%x\n\r", ub9702RegDetails[index].regAddr, ub9702RegDetails[index].expClrVal);
            }
            else
            {
                UART_printf("Clr verification failed\t0x%x\t0x%x\t0x%x\n\r", ub9702RegDetails[index].regAddr, ub9702RegDetails[index].expClrVal,regData);
            }
        }
        else
        {
            if(regData == ub9702RegDetails[index].expSetVal)
            {
                UART_printf("Set verification successful\t0x%x\t0x%x\n\r", ub9702RegDetails[index].regAddr, ub9702RegDetails[index].expSetVal);
            }
            else
            {
                UART_printf("Set verification failed\t0x%x\t0x%x\t0x%x\n\r", ub9702RegDetails[index].regAddr, ub9702RegDetails[index].expSetVal,regData);
            }
        }
        index++;
    }

    return 0;
}

int32_t BoardDiag_fpdCsi_run_test()
{
    int32_t ret;
    int8_t index = 0;
    uint8_t domain;
    uint8_t i2cInst;
    uint8_t slaveAddr;

#if !defined (__aarch64__)
    bool errFlag;
#endif

    I2C_Params i2cParams;
    I2C_Handle csiHandle = NULL;
    Board_I2cInitCfg_t i2cCfg;

    i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE5_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    Board_i2cIoExpInit();
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE5_ADDR,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_0,
                                  PIN_DIRECTION_OUTPUT);

    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE5_ADDR,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cDeInit();

	UART_printf("\n*********************************************\n"); 
	UART_printf("*               CSI 9702 HUB TEST                *\n");
	UART_printf("*********************************************\n");    
    for (index = 0; I2C_config[index].fxnTablePtr != NULL; index++)
    {
        ((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    Board_fpdUb9702GetI2CAddr(BOARD_FPD_9702_CSI2_DES_HUB1,&domain, &i2cInst, &slaveAddr);
    
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

    fpdUb9702ModParams.desSlvAddr = slaveAddr;

    /* Configures the I2C instance with the passed parameters*/
    csiHandle = I2C_open(i2cInst, &i2cParams);
	if(csiHandle == NULL)
	{
		UART_printf("\nI2C Open failed!\n");
		ret = -1;
		return ret;
	}

    index = 0;
    UART_printf("Initializing with default reg value...\n\r");
    while(ub9702RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ub9702RegDetails[index].defVal = ub9702DefReg[index];
        if(ub9702RegDetails[index].expSetVal == 0U)
        {
            ub9702RegDetails[index].expSetVal = (ub9702RegDetails[index].defVal | ub9702RegDetails[index].setVal);
        }
        if(ub9702RegDetails[index].expClrVal == 0U)
        {
            ub9702RegDetails[index].expClrVal = (ub9702RegDetails[index].defVal & ub9702RegDetails[index].clrVal);
        }
        index++;
        
    }

    UART_printf("Set FPD UB9702 deserializer configuration...\n\r");
    ret = Board_fpdUB9702SetCfg((void *)csiHandle);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB9702) set config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB9702) set config failed\n\r\n\r");
    }

    ret = Board_fpdUB9702VerifyCfg((void *)csiHandle, VERIFY_SET_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB9702) set config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB9702) set config verification failed\n\r\n\r");
    }

    UART_printf("Clear FPD UB9702 Deserializer configuration...\n\r");
    ret = Board_fpdUB9702ClrCfg((void *)csiHandle);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB9702) clear config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB9702) clear config failed\n\r\n\r");
    }

    ret = Board_fpdUB9702VerifyCfg((void *)csiHandle, VERIFY_CLR_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB9702) clear config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB9702) clear config verification failed\n\r\n\r");
    }

    return ret;
}

