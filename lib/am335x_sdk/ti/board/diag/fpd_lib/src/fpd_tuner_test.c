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
 * \file   fpd_tuner_test.c
 *
 * \brief  This file contains API's used for configuring the local serializer
 *         connected to host controller to control remote AFE8310 tuner.
 *
 */

#include "fpd_tuner_test.h"

I2C_Handle handle = NULL;

Board_FpdModuleObj fpdTunerModParams = {0x2C, 0x1B, 0x11};

Board_FpdRmtDevObj fpdTunerRmtParams[8] =
{
    {0x1B, 0x11}, //Remote serializer(UB925) divice physical and alias addresses
    {0x4b, 0x12}, //Remote sensor device0 physial and alias addresses
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00}
};

Board_FpdRmtDevObj testSetfpdTunerRmtParams[8] =
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

Board_FpdRmtDevObj testClrfpdTunerRmtParams[8] =
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

uint8_t ub926DefReg[] = {
    0x04,
    0xf0,
    0x1e,
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
    0x00
};

fpdRegCfgObj_t ub926RegDetails[] = 
{
    {
        BOARD_FPD_UB926_RESET_REG_ADDR,
        0U,
        (uint8_t)RESET_REG_MASK,
        (uint8_t)(~(RESET_REG_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB926_CONFIGURATION1_REG_ADDR,
        0U,
        (uint8_t)CONFIGURATION1_REG_MASK,
        (uint8_t)(~(CONFIGURATION1_REG_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB926_I2C_CONTROL1_REG_ADDR,
        0U,
        (uint8_t)I2C_CONTROL1_REG_MASK,
        (uint8_t)(~(I2C_CONTROL1_REG_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR,
        0U,
        (uint8_t)DATA_PATH_CONTROL_REG_MASK,
        0U,
        0U,
        0x80U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID0_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID1_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID2_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ID7_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS0_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS1_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS2_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS3_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS4_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS5_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS6_REG_ADDR,
        0U,
        0U,
        0U,
        0xfeU,
        0x02U
    },

    {
        BOARD_FPD_UB926_SLAVE_ALIAS7_REG_ADDR,
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

uint8_t ub925DefReg[] = {
    0x80,
    0x00
};

fpdRegCfgObj_t ub925RegDetails[] = {
    {
        BOARD_FPD_UB925_CONFIGURATION1_REG_ADDR,
        0U,
        (uint8_t)CONFIGURATION925_REG_MASK,
        (uint8_t)(~(CONFIGURATION925_REG_MASK)),
        0U,
        0U
    },

    {
        BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR,
        0U,
        (uint8_t)DATA_PATH925_CONTROL_REG_MASK,
        (uint8_t)(~(DATA_PATH925_CONTROL_REG_MASK)),
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

int32_t BoardDiag_tunerPowerEnable(void)
{
    int32_t ret = 0;
    
    Board_I2cInitCfg_t i2cCfg;

    i2cCfg.i2cInst   = BOARD_I2C_AUDIO_IOEXP_DEVICE_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    ret = Board_i2cIoExpInit();
    if(ret != 0)
    {
        UART_printf("Audio IO Expander failed\n");
        ret = -1;
        return ret;
    }
    /* Tuner reset GPIO */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE3_ADDR,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_4,
                                  PIN_DIRECTION_OUTPUT);
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE3_ADDR,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_4,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE3_ADDR,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_2,
                                  PIN_DIRECTION_OUTPUT);
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE3_ADDR,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_2,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cIoExpDeInit();
    
    return ret;
}

static int8_t Board_fpdUB926SetCfg(void *handle)
{
    int8_t ret = 0;
    
    ret = Board_fpdUb926SetOverrideFCConfigModeCtrl((void *)handle,
                                                    &fpdTunerModParams,
                                                    BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetOverrideFCConfigModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SChBOverrideModeCtrl((void *)handle,
                                                  &fpdTunerModParams,
                                                  BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SChBOverrideModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SChBEnableModeCtrl((void *)handle,
                                                &fpdTunerModParams,
                                                BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SChBEnableModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetRmtAutoPwrDwnModeCtrl((void *)handle,
                                                 &fpdTunerModParams,
                                                 BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetRmtAutoPwrDwnModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetPassRGBModeCtrl((void *)handle,
                                           &fpdTunerModParams,
                                           BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetPassRGBModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SGenModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SGenModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2STransportSelModeCtrl((void *)handle,
                                                   &fpdTunerModParams,
                                                   BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2STransportSelModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetRGB18bitModeCtrl((void *)handle,
                                            &fpdTunerModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetRGB18bitModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2CPassThrAllModeCtrl((void *)handle,
                                                 &fpdTunerModParams,
                                                 BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2CPassThrAllModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2CPassThrModeCtrl((void *)handle,
                                              &fpdTunerModParams,
                                              BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2CPassThrModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetBackChModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetBackChModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926RmtSerSlvDevAliasIdCfg((void *)handle,
                                               &fpdTunerModParams,
                                               testSetfpdTunerRmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926RmtSerSlvDevAliasIdCfg' cfg failed\n\r");
        return -1;
    }

    return ret;
}

static int8_t Board_fpdUB926ClrCfg(void *handle)
{
    int8_t ret = 0;
    
    ret = Board_fpdUb926RmtSerSlvDevAliasIdCfg((void *)handle,
                                               &fpdTunerModParams,
                                               testClrfpdTunerRmtParams);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926RmtSerSlvDevAliasIdCfg' cfg failed\n\r");
        return -1;
    }

    ret = Board_fpdUb926SetOverrideFCConfigModeCtrl((void *)handle,
                                                        &fpdTunerModParams,
                                                        BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetOverrideFCConfigModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SChBOverrideModeCtrl((void *)handle,
                                                  &fpdTunerModParams,
                                                  BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SChBOverrideModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SChBEnableModeCtrl((void *)handle,
                                                &fpdTunerModParams,
                                                BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SChBEnableModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetRmtAutoPwrDwnModeCtrl((void *)handle,
                                                 &fpdTunerModParams,
                                                 BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetRmtAutoPwrDwnModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetPassRGBModeCtrl((void *)handle,
                                           &fpdTunerModParams,
                                           BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetPassRGBModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2SGenModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2SGenModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2STransportSelModeCtrl((void *)handle,
                                                   &fpdTunerModParams,
                                                   BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2STransportSelModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetRGB18bitModeCtrl((void *)handle,
                                            &fpdTunerModParams,
                                            BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetRGB18bitModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2CPassThrAllModeCtrl((void *)handle,
                                                 &fpdTunerModParams,
                                                 BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2CPassThrAllModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetI2CPassThrModeCtrl((void *)handle,
                                              &fpdTunerModParams,
                                              BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetI2CPassThrModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb926SetBackChModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb926SetBackChModeCtrl' cfg failed\n\r");
    }
    
    return ret;    
}

static int8_t Board_fpdUB926VerifyCfg(void *handle,
                                      cfgVerifyFlag_t flag)
{
    int8_t index;
    int8_t ret;
    uint8_t regData;
    index = 0;
    while(ub926RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ret = Board_i2c8BitRegRd(handle,
                                 fpdTunerModParams.desSlvAddr,
                                 ub926RegDetails[index].regAddr,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            UART_printf("I2C register read fialed!\n\r"\
                        "while reading register with addr - 0x%x\n\r",
                        ub926RegDetails[index].regAddr);
        }

        if(flag == VERIFY_CLR_CONFIG)
        {
            if(regData == ub926RegDetails[index].expClrVal)
            {
                UART_printf("Clr verification successful\t0x%x\t0x%x\n\r", ub926RegDetails[index].regAddr, ub926RegDetails[index].expClrVal);
            }
            else
            {
                UART_printf("Clr verification failed\t0x%x\t0x%x\t0x%x\n\r", ub926RegDetails[index].regAddr, ub926RegDetails[index].expClrVal,regData);
            }
        }
        else
        {
            if(regData == ub926RegDetails[index].expSetVal)
            {
                UART_printf("Set verification successful\t0x%x\t0x%x\n\r", ub926RegDetails[index].regAddr, ub926RegDetails[index].expSetVal);
            }
            else
            {
                UART_printf("Set verification failed\t0x%x\t0x%x\t0x%x\n\r", ub926RegDetails[index].regAddr, ub926RegDetails[index].expSetVal,regData);
            }
        }
        index++;
    }

    return 0;
}

static int8_t Board_fpdUB925SetCfg(void *handle)
{
    int8_t ret = 0;

    
    ret = Board_fpdUb925SetRGBGateDEModeCtrl((void *)handle,
                                             &fpdTunerModParams,
                                             BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetRGBGateDEModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2SChBModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2SChBModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2STransSelModeCtrl((void *)handle,
                                               &fpdTunerModParams,
                                               BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2STransSelModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetRGB18bitModeCtrl((void *)handle,
                                            &fpdTunerModParams,
                                            BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetRGB18bitModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2SChBOverrideModeCtrl((void *)handle,
                                                  &fpdTunerModParams,
                                                  BOARD_FPD_MODE_ENABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2SChBOverrideModeCtrl' cfg failed\n\r");
    }


   return 0;
}

static int8_t Board_fpdUB925ClrCfg(void *handle)
{
    int8_t ret = 0;

    
    ret = Board_fpdUb925SetRGBGateDEModeCtrl((void *)handle,
                                             &fpdTunerModParams,
                                             BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetRGBGateDEModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2SChBModeCtrl((void *)handle,
                                          &fpdTunerModParams,
                                          BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2SChBModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2STransSelModeCtrl((void *)handle,
                                               &fpdTunerModParams,
                                               BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2STransSelModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetRGB18bitModeCtrl((void *)handle,
                                            &fpdTunerModParams,
                                            BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetRGB18bitModeCtrl' cfg failed\n\r");
    }

    ret = Board_fpdUb925SetI2SChBOverrideModeCtrl((void *)handle,
                                                  &fpdTunerModParams,
                                                  BOARD_FPD_MODE_DISABLE);
    if(ret != 0)
    {
        UART_printf("'Board_fpdUb925SetI2SChBOverrideModeCtrl' cfg failed\n\r");
    }


    return 0;
}

static int8_t Board_fpdUB925VerifyCfg(void *handle,
                                      cfgVerifyFlag_t flag)
{
    int8_t index;
    int8_t ret;
    uint8_t regData;
    index = 0;
    while(ub925RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ret = Board_i2c8BitRegRd(handle,
                                 fpdTunerModParams.serSlvAddr,
                                 ub925RegDetails[index].regAddr,
                                 &regData,
                                 1U,
                                 BOARD_I2C_TRANSACTION_TIMEOUT);
        if(ret != 0)
        {
            UART_printf("I2C register read fialed!\n\r"\
                        "while reading register with addr - 0x%x\n\r",
                        ub925RegDetails[index].regAddr);
        }

        if(flag == VERIFY_CLR_CONFIG)
        {
            if(regData == ub925RegDetails[index].expClrVal)
            {
                UART_printf("Clr verification successful\t0x%x\t0x%x\n\r", ub925RegDetails[index].regAddr, ub925RegDetails[index].expClrVal);
            }
            else
            {
                UART_printf("Clr verification failed\t0x%x\t0x%x\t0x%x\n\r", ub925RegDetails[index].regAddr, ub925RegDetails[index].expClrVal,regData);
            }
        }
        else
        {
            if(regData == ub925RegDetails[index].expSetVal)
            {
                UART_printf("Set verification successful\t0x%x\t0x%x\n\r", ub925RegDetails[index].regAddr, ub925RegDetails[index].expSetVal);
            }
            else
            {
                UART_printf("Set verification failed\t0x%x\t0x%x\t0x%x\n\r", ub925RegDetails[index].regAddr, ub925RegDetails[index].expSetVal,regData);
            }
        }
        index++;
    }

    return 0;
}


int32_t BoardDiag_fpdTuner_run_test()
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
    I2C_Handle handle = NULL;

    UART_printf("TUNER board Power Enable\n");
    ret = BoardDiag_tunerPowerEnable();
    if(ret != 0)
    {
        UART_printf("TUNER board Power enable failed\n");
        ret = -1;
        return ret;
    }
    
    for (index = 0; I2C_config[index].fxnTablePtr != NULL; index++)
    {
        ((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    Board_fpdUb926GetI2CAddr(&domain,
                             &i2cInst,
                             &slaveAddr);
    
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

    fpdTunerModParams.desSlvAddr = slaveAddr;

    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(i2cInst, &i2cParams);
	if(handle == NULL)
	{
		UART_printf("\nI2C Open failed!\n");
		ret = -1;
		return ret;
	}

    index = 0;
    UART_printf("Initializing with default reg value...\n\r");
    while(ub926RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ub926RegDetails[index].defVal = ub926DefReg[index];
        if(ub926RegDetails[index].expSetVal == 0U)
        {
            ub926RegDetails[index].expSetVal = (ub926RegDetails[index].defVal | ub926RegDetails[index].setVal);
        }
        if(ub926RegDetails[index].expClrVal == 0U)
        {
            ub926RegDetails[index].expClrVal = (ub926RegDetails[index].defVal & ub926RegDetails[index].clrVal);
        }
        index++;
        
    }

    index = 0;
    while(ub925RegDetails[index].regAddr != BOARD_DEVICES_CONFIG_END)
    {
        ub925RegDetails[index].defVal = ub925DefReg[index];
        if(ub925RegDetails[index].expSetVal == 0U)
        {
            ub925RegDetails[index].expSetVal = (ub925RegDetails[index].defVal | ub925RegDetails[index].setVal);
        }
        if(ub925RegDetails[index].expClrVal == 0U)
        {
            ub925RegDetails[index].expClrVal = (ub925RegDetails[index].defVal & ub925RegDetails[index].clrVal);
        }
        index++; 
    }

    UART_printf("Set FPD UB926 deserializer configuration...\n\r");
    ret = Board_fpdUB926SetCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB926) set config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB926) set config failed\n\r\n\r");
    }

    ret = Board_fpdUB926VerifyCfg((void *)handle,
                                  VERIFY_SET_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB926) set config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB926) set config verification failed\n\r\n\r");
    }

    UART_printf("Clear FPD UB926 Deserializer configuration...\n\r");
    ret = Board_fpdUB926ClrCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB926) clear config successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB926) clear config failed\n\r\n\r");
    }

    ret = Board_fpdUB926VerifyCfg((void *)handle,
                                  VERIFY_CLR_CONFIG);
    if(ret == 0)
    {
        UART_printf("Deserializer(UB926) clear config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("Deserializer(UB926) clear config verification failed\n\r\n\r");
    }

    /*925 access*/
    ret = Board_fpdUb926RmtSlvDevAccEn((void *)handle,
                                       fpdTunerRmtParams,
                                       &fpdTunerModParams);
    if(ret != 0)
    {
        UART_printf("FPD serializer remote access failed\n\r");
    }

    UART_printf("Set FPD UB925 serializer configuration...\n\r");
    ret = Board_fpdUB925SetCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("serializer configuration set successful\n\r\n\r");
    }
    else
    {
        UART_printf("serializer configuration set failed\n\r\n\r");
    }
    ret = Board_fpdUB925VerifyCfg((void *)handle,
                                  VERIFY_SET_CONFIG);
    if(ret == 0)
    {
        UART_printf("serializer(UB925) set config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("serializer(UB925) set config verification failed\n\r\n\r");
    }

    UART_printf("Clear FPD UB926 serializer configuration...\n\r");
    ret = Board_fpdUB925ClrCfg((void *)handle);
    if(ret == 0)
    {
        UART_printf("serializer(UB925) clear config successful\n\r\n\r");
    }
    else
    {
        UART_printf("serializer(UB925) clear config failed\n\r\n\r");
    }

    ret = Board_fpdUB925VerifyCfg((void *)handle,
                                  VERIFY_CLR_CONFIG);
    if(ret == 0)
    {
        UART_printf("serializer(UB925) clear config verification successful\n\r\n\r");
    }
    else
    {
        UART_printf("serializer(UB925) clear config verification failed\n\r\n\r");
    }

    return ret;
}
