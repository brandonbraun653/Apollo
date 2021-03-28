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
 *  \file board_lld_init.c
 *
 *  \brief This file initializes UART and I2C LLD modules 
 *
 */

#include "board_internal.h"
#include "board_utils.h"
#include "board_cfg.h"
#include "board_control.h"

I2C_Handle gBoardI2CHandle = NULL;
extern Board_I2cInitCfg_t gBoardI2cInitCfg;
extern Board_initParams_t gBoardInitParams;
static uint32_t gI2CBaseAddr = 0;
static uint32_t gUARTBaseAddr = 0;
static uint32_t gUARTClkFreq = 0;

uint32_t gBoardI2cBaseAddr[BOARD_SOC_DOMAIN_MAX][I2C_HWIP_MAX_CNT] =
    {{CSL_I2C0_CFG_BASE, CSL_I2C1_CFG_BASE, CSL_I2C2_CFG_BASE, CSL_I2C3_CFG_BASE,
      CSL_I2C4_CFG_BASE, CSL_I2C5_CFG_BASE, CSL_I2C6_CFG_BASE},
     {CSL_WKUP_I2C0_CFG_BASE, 0, 0, 0, 0, 0, 0},
     {CSL_MCU_I2C0_CFG_BASE, CSL_MCU_I2C1_CFG_BASE, 0, 0, 0, 0, 0}};

uint32_t gBoardUartBaseAddr[BOARD_SOC_DOMAIN_MAX][CSL_UART_MAIN_CNT] =
    {{CSL_UART0_BASE, CSL_UART1_BASE, CSL_UART2_BASE, CSL_UART3_BASE, CSL_UART4_BASE,
      CSL_UART5_BASE, CSL_UART6_BASE, CSL_UART7_BASE, CSL_UART8_BASE, CSL_UART9_BASE},
     {CSL_WKUP_UART0_BASE, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {CSL_MCU_UART0_BASE, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

/**
  *  \brief   Returns base address of given I2C instance
  *
  *  \param   instNum [IN] I2C instance
  *
  *  \param   domain  [IN] Domain of I2C controller
  *                           BOARD_SOC_DOMAIN_MAIN - Main Domain
  *                           BOARD_SOC_DOMAIN_WKUP - Wakeup domain
  *                           BOARD_SOC_DOMAIN_MCU - MCU domain
  * 
  *  \return  Valid base address in case of success or 0
  *
  */
static uint32_t Board_getI2cBaseAddr(uint8_t instNum,
                                     uint8_t domain)
{
    uint32_t baseAddr = 0;

    if((instNum < I2C_HWIP_MAX_CNT) &&
       (domain <= BOARD_SOC_DOMAIN_MCU))
    {
        baseAddr = gBoardI2cBaseAddr[domain][instNum];
    }

    return (baseAddr);
}

/**
  *  \brief   Returns base address of given UART instance
  *
  *  \param   instNum [IN] UART instance
  *
  *  \param   domain  [IN] Domain of UART controller
  *                           BOARD_SOC_DOMAIN_MAIN - Main Domain
  *                           BOARD_SOC_DOMAIN_WKUP - Wakeup domain
  *                           BOARD_SOC_DOMAIN_MCU - MCU domain
  * 
  *  \return  Valid base address in case of success or 0
  *
  */
static uint32_t Board_getUartBaseAddr(uint8_t instNum,
                                      uint8_t domain)
{
    uint32_t baseAddr = 0;

    if((instNum < CSL_UART_MAIN_CNT) &&
       (domain <= BOARD_SOC_DOMAIN_MCU))
    {
        baseAddr = gBoardUartBaseAddr[domain][instNum];
    }

    return (baseAddr);
}

/**
 *  \brief   This function initializes the default UART instance for use for
 *           console operations.
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_uartStdioInit(void)
{
    Board_STATUS status;
    Board_IoExpCfg_t ioExpCfg;
    UART_HwAttrs uart_cfg;
    uint32_t uartInst;
    uint32_t uartBaseAddr;
    uint32_t socDomainUART;
    uint32_t socDomainCore;

    uartInst      = gBoardInitParams.uartInst;
    socDomainUART = gBoardInitParams.uartSocDomain;

    socDomainCore = Board_getSocDomain();

    /* Disable the UART interrupt */  
    UART_socGetInitCfg(uartInst, &uart_cfg);

    if(socDomainUART != socDomainCore)
    {
        uartBaseAddr = Board_getUartBaseAddr(uartInst, socDomainUART);
        if(uartBaseAddr != 0)
        {
            gUARTBaseAddr = uart_cfg.baseAddr;
            uart_cfg.baseAddr = uartBaseAddr;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }

        gUARTClkFreq = uart_cfg.frequency;
        if(socDomainUART == BOARD_SOC_DOMAIN_MAIN)
        {
            uart_cfg.frequency = BOARD_UART_CLK_MAIN;
        }
        else
        {
            uart_cfg.frequency = BOARD_UART_CLK_WKUP;
        }
    }

    uart_cfg.enableInterrupt = false;
    UART_socSetInitCfg(uartInst, &uart_cfg);

    /* MAIN UART4 instance is connected through mux which is controlled by
       IO expander. Need to configure the mux to use UART4 instance */
    if(uartInst == 4)
    {
        ioExpCfg.slaveAddr   = BOARD_I2C_IOEXP_DEVICE2_ADDR;
        ioExpCfg.i2cInst     = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
        ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
        ioExpCfg.enableIntr  = false;
        ioExpCfg.ioExpType   = THREE_PORT_IOEXP;
        ioExpCfg.portNum     = PORTNUM_1;
        ioExpCfg.pinNum      = PIN_NUM_1;
        ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;

        status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);
        if(status != BOARD_SOK)
        {
            return status;
        }

        ioExpCfg.pinNum      = PIN_NUM_2;
        ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_HIGH;

        status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, (void *)&ioExpCfg);
        if(status != BOARD_SOK)
        {
            return status;
        }
    }

    UART_stdioInit(uartInst);

    return BOARD_SOK;
}

/**
 *  \brief   This function is to get the i2c handle of the requested
 *           instance of the specifed domain
 *
 *  \param   domainType [IN] Domain of I2C controller
 *                             BOARD_SOC_DOMAIN_MAIN - Main Domain
 *                             BOARD_SOC_DOMAIN_WKUP - Wakeup domain
 *                             BOARD_SOC_DOMAIN_MCU - MCU domain
 *
 *  \param   i2cInst    [IN]        I2C instance
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 *
 */
I2C_Handle Board_getI2CHandle(uint8_t domainType,
                              uint32_t i2cInst)
{
    Board_STATUS status;

    Board_I2cInitCfg_t i2cCfg;
    
    i2cCfg.i2cInst    = i2cInst;
    i2cCfg.socDomain  = domainType;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    status = Board_i2cInit();
    if(status != BOARD_SOK)
    {
        return NULL;
    }

    return gBoardI2CHandle;
}

/**
  *  \brief   This function initializes the i2c instance set using
  *           Board_setI2cInitConfig API.
  *
  *  \return  Board_STATUS in case of success or appropriate error code.
  *
  */
Board_STATUS Board_i2cInit(void)
{
    I2C_Params i2cParams;
    I2C_HwAttrs i2c_cfg;
    uint32_t i2cInst;
    uint32_t i2cBaseAddr;
    uint32_t socDomainI2c;
    uint32_t socDomainCore;

    i2cInst      = gBoardI2cInitCfg.i2cInst;
    socDomainI2c = gBoardI2cInitCfg.socDomain;

    socDomainCore = Board_getSocDomain();

    I2C_init();
    I2C_socGetInitCfg(i2cInst, &i2c_cfg);

    if(socDomainI2c != socDomainCore)
    {
        i2cBaseAddr = Board_getI2cBaseAddr(i2cInst, socDomainI2c);
        if(i2cBaseAddr != 0)
        {
            gI2CBaseAddr = i2c_cfg.baseAddr;
            i2c_cfg.baseAddr = i2cBaseAddr;
        }
        else
        {
            return BOARD_INVALID_PARAM;
        }
    }

    i2c_cfg.enableIntr = gBoardI2cInitCfg.enableIntr;

    I2C_socSetInitCfg(i2cInst, &i2c_cfg);
    I2C_Params_init(&i2cParams);

    gBoardI2CHandle = I2C_open(i2cInst, &i2cParams);
    if (gBoardI2CHandle == NULL)
    {
        return BOARD_I2C_OPEN_FAIL;
    }

    return BOARD_SOK;
}

/**
 *  \brief   This function is used to close the initialized board I2C handle.
 */
Board_STATUS Board_i2cDeInit(void)
{
    uint32_t socDomainCore;
    I2C_HwAttrs i2c_cfg;

    I2C_close(gBoardI2CHandle);
    gBoardI2CHandle = NULL;

    socDomainCore = Board_getSocDomain();

    if(gBoardI2cInitCfg.socDomain != socDomainCore)
    {
        I2C_socGetInitCfg(gBoardI2cInitCfg.i2cInst, &i2c_cfg);
        i2c_cfg.baseAddr = gI2CBaseAddr;
        I2C_socSetInitCfg(gBoardI2cInitCfg.i2cInst, &i2c_cfg);
    }

    return BOARD_SOK;
}

/**
 *  \brief   This function is used to de-initialize board UART handles.
 */
Board_STATUS Board_uartDeInit(void)
{
    UART_HwAttrs uart_cfg;
    uint32_t socDomainCore;
    
    UART_stdioDeInit();

    socDomainCore = Board_getSocDomain();

    if(gBoardInitParams.uartSocDomain != socDomainCore)
    {
        UART_socGetInitCfg(gBoardInitParams.uartInst, &uart_cfg);
        uart_cfg.baseAddr  = gUARTBaseAddr;
        uart_cfg.frequency = gUARTClkFreq;
        UART_socSetInitCfg(gBoardInitParams.uartInst, &uart_cfg);
    }

    return BOARD_SOK;
}
