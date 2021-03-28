/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_internal.h"
#include "board_cfg.h"
static uint32_t gAM65xI2cBaseAddr[BOARD_SOC_DOMAIN_MAX][I2C_HWIP_MAX_CNT] =
    {{CSL_I2C0_CFG_BASE, CSL_I2C1_CFG_BASE, CSL_I2C2_CFG_BASE, CSL_I2C3_CFG_BASE},
     {CSL_WKUP_I2C0_CFG_BASE, 0, 0, 0},
     {CSL_MCU_I2C0_CFG_BASE, 0, 0, 0}};

/**
 * \brief   This function initializes the default UART instance for use for
 *          console operations.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_uartStdioInit(void)
{
    UART_stdioInit(BOARD_UART_INSTANCE);
    return BOARD_SOK;
}

/**
 * \brief   This function initializes the i2c instance connected to the
 *          board Id EEPROM.
 *
 * This function disables the interrupt mode as the Board i2c instance 
 * doesn't require interrupt mode and restores back original at the end.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_internalInitI2C(void)
{
    I2C_Params i2cParams;
    int i;
    Board_STATUS ret;
    I2C_HwAttrs   i2c_cfg;
    uint8_t flag = 0;

    /* Board i2c usage does not depend on interrupts */
    for (i=0; I2C_config[i].fxnTablePtr != NULL; i++)
    {
        /* Check if interrupt set to true. Change it to false and raise a flag
            Note that number of i2c instances will not exceed 8 */
        if (((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr == true)
        {
            I2C_socGetInitCfg(i, &i2c_cfg);
            flag |= (1<<i);
            i2c_cfg.enableIntr = false;
            I2C_socSetInitCfg(i, &i2c_cfg);
        }
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    /* Note:- the Board ID EEPROM and the I2C IO EXPANDER are connected to
       same i2c instance. */
    Board_obj.i2cHandle = I2C_open(BOARD_I2C_EEPROM_INSTANCE, &i2cParams);
    if (Board_obj.i2cHandle == NULL)
        ret = BOARD_I2C_OPEN_FAIL;
    else
        ret = BOARD_SOK;

    /* Restore the original I2C_config table */
    for (i=0; I2C_config[i].fxnTablePtr != NULL; i++)
    {
        if (flag & (1<<i))
        {
            I2C_socGetInitCfg(i, &i2c_cfg);
            i2c_cfg.enableIntr = true;
            I2C_socSetInitCfg(i, &i2c_cfg);
        }
    }

    return ret;
}

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
        baseAddr = gAM65xI2cBaseAddr[domain][instNum];
    }

    return (baseAddr);
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
    I2C_Handle handle = NULL;
    I2C_Params i2cParams;
    I2C_HwAttrs i2cCfg;

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    /* Use I2C in polling mode*/
    I2C_socGetInitCfg(i2cInst, &i2cCfg);
    i2cCfg.baseAddr = Board_getI2cBaseAddr(i2cInst, domainType);
    i2cCfg.enableIntr = false;
    I2C_socSetInitCfg(i2cInst, &i2cCfg);

    handle = I2C_open(i2cInst, &i2cParams);

    return handle;
}
