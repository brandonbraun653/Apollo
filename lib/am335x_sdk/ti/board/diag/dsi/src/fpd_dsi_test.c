/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  Targeted Functionality: Verification of basic functionality of remote csi
 *  module connected to fpd interface.
 *
 *  Operation: This test is used for detection of remote fpd serializer and,
 *  camera module. Verification of the camera module access through the FPD
 *  interface.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 *
 */
 
#include "fpd_dsi_test.h"

extern I2C_config_list I2C_config;

Board_FpdModuleObj fpdModParams = {0x2C, 0x16, 0x11};

Board_FpdRmtDevObj fpdRmtParams[8] =
{
    {0x2c, 0x11}, //Remote derializer(UB924) divice physical and alias addresses
    {0x40, 0x12}, //Remote sensor device0 physial and alias addresses
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00},
    {0x00, 0x00}
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
/**
 *  \brief    Runs the fpd dsi test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_fpd_dsi_test(void)
{
    uint8_t dutyCycle;
    int8_t ret = 0;
    uint8_t index;
    uint8_t domain,regData;
    uint8_t i2cInst;
    uint8_t slaveAddr;
    uint8_t userInput;
    
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

    fpdModParams.serSlvAddr = slaveAddr;

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
                                &fpdModParams,
                                &fpdRmtParams[0]);
    if(ret != 0)
    {
        UART_printf("FPD serializer initialization failed\n\r");
    }
    else
    {
        UART_printf("FPD serializer initialization successful\n\r");
    }

#if 0
    ret = Board_fpdUb941DsiModuleInit((void *)handle,
                                      &fpdModParams);
    if(ret != 0)
    {
        UART_printf("FPD serializer DSI module init failed\n\r");
    }
    else
    {
        UART_printf("FPD serializer DSI module init successful\n\r");
    }

    ret = Board_fpdUb941PatternGenConfig((void *)handle,
                                         &fpdModParams);
    if(ret != 0)
    {
        UART_printf("FPD serializer pattern generation configuration failed\n\r");
    }
    else
    {
        UART_printf("FPD serializer pattern generation configuration successful\n\r");
    }

    ret = Board_fpdUb924ModuleInit((void *)handle,
                                   &fpdModParams);
    if(ret != 0)
    {
        UART_printf("FPD deserializer DSI module init failed\n\r");
    }
    else
    {
        UART_printf("FPD deserializer DSI module init successful\n\r");
    }
#endif

    UART_printf("Enabling the LED through LED\n\r");
    /* Led Enabling through IO/Exp */
    regData = 0xFE;
    ret = Board_i2c8BitRegWr(handle,
                             0x27U,
                             0x00U,
                             &regData, //enabling led_en - GPIO
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        UART_printf("LED enabling through IO EXP failed\n\r");
        return ret;
    }


    UART_printf("Configuring LED driver ...\n\r");
    Board_tlc59108LedDrvCfg((void *)handle,
                            &fpdModParams,
                            &fpdRmtParams[1]);

    UART_printf("Press 'y' or 'Y' to exit the test, once after observing\n\r\
                 the change in LCD back light brightness...\n\r");
    while(1)
    {
        UART_printf("\n\rBightness changing from min to max...\n\r");
        dutyCycle = (uint8_t)MIN_BRIGHTNESS;
        while(dutyCycle <= (uint8_t)MAX_BRIGHTNESS)
        {
            UART_printf("Duty cycle percentage - %d\n\r", dutyCycle);
            ret = Board_tlc59108PwmDutycycleCntrl((void *)handle,
                                                  &fpdRmtParams[1],
                                                  BOARD_FPD_TLC59108_PWM_CH2,
                                                  dutyCycle);
            dutyCycle += 10;
            Board_delay(200);
        }

        UART_printf("\n\rBightness changing from max to min...\n\r");
        dutyCycle = MAX_BRIGHTNESS;
        while(dutyCycle != MIN_BRIGHTNESS)
        {
            UART_printf("Duty cycle percentage - %d\n\r", dutyCycle);
            ret = Board_tlc59108PwmDutycycleCntrl((void *)handle,
                                                  &fpdRmtParams[1],
                                                  BOARD_FPD_TLC59108_PWM_CH2,
                                                  dutyCycle);

            dutyCycle -= 10;
            Board_delay(200);
        }

        userInput = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((userInput == 'y') || (userInput == 'Y'))
        {
            UART_printf("Exiting...\n");
            break;
        }
    }

    I2C_close(handle);

    return ret;
}

/**
 *  \brief    The function performs the fpd dsi verification test.
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

	UART_printf("\n*********************************************\n"); 
	UART_printf("*               FPD DSI TEST                *\n");
	UART_printf("*********************************************\n");    

    UART_printf("\nRunning FPD DSI access test\n");

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

/**
 *  \brief   FPD dsi Diagnostic test main function
 *
 *  \return  int - EEPROM Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO |
               BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

	return BoardDiag_fpd_dsi_test();
}

