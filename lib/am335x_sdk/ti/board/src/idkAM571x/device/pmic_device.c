/**
 *  \file   pmic_device.c
 *
 *  \brief  This file contains PRCM functions used in SBL to enable clocks
 *		    to the slave cores.
 *
 */

/*
 * Copyright (C) 2015-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* TI RTOS header files */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pmic_device.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Standard offset is 0.5v expressed in uv */
#define PALMAS_SMPS_BASE_VOLT_UV            500000

/* I2C instance to which PMIC is connected. */
#define PMIC_DEV_INSTANCE                   1

/* ========================================================================== */
/*                           Global Variables                                 */
/* ========================================================================== */
extern I2C_config_list I2C_config;

I2C_Handle handle = NULL;

/* ========================================================================== */
/*                           Internal Functions                               */
/* ========================================================================== */

/**
 *  \brief    This API initializes the I2C instance associated with the pmic
 *            device connected on the board.
 *
 *  \param  instance   I2C instance.
 */
void Board_PMICDevOpen(uint32_t instance);

/**
 *  \brief    This API closes the communication interface to the on board PMIC
 *            device.
 *
 */
void Board_PMICDevClose();

/**
 *  \brief    This API returns the offset value for given mV to be written to
 *            the pmic register.
 *
 *  \param  instance   I2C instance.
 */
uint32_t Board_GetPMICOffset(uint32_t voltOffset, pmic_data_t *pmic);

/**
 *  \brief    This API sets the voltage value to the PMIC register.
 *
 *  \param    slaveAddr    Slave address of the PMIC device.
 *  \param    regAddr      register address of the pmic
 *  \param    value        value to be written to the pmic register.
 */
bool Board_SetPMICVoltage(uint32_t slaveAddr, uint8_t regAddr, uint8_t value);

pmic_data_t   tps659039 = {
    PALMAS_SMPS_BASE_VOLT_UV,
    10000, /* 10 mV represented in uV */
    /*
     * Offset codes 1-6 all give the base voltage in Palmas
     * Offset code 0 switches OFF the SMPS
     */
    6,
    TPS659039_I2C_SLAVE_ADDR,
    PMIC_DEV_INSTANCE,
    Board_PMICDevOpen,
    Board_SetPMICVoltage,
    Board_GetPMICOffset,
    Board_PMICDevClose
};

pmic_data_t* Board_GetPmicData()
{
    return &tps659039;
}

void Board_PMICDevOpen(uint32_t instance)
{
    I2C_Params i2cParams;
    int i;

    for (i=0; i < I2C_HWIP_MAX_CNT; i++)
    {
        ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(instance, &i2cParams);
}

void Board_PMICDevClose()
{
    I2C_close(handle);
    handle = NULL;
}

uint32_t Board_GetPMICOffset(uint32_t voltOffset, pmic_data_t *pmic)
{
    uint32_t offsetCode;

    offsetCode = (26 + ((voltOffset - 700 + 9)/10)) & 0x7F;

    return offsetCode;
}

bool Board_SetPMICVoltage(uint32_t slaveAddr, uint8_t regAddr, uint8_t value)
{
    bool status = false;

    I2C_Transaction i2cTransaction;
    uint8_t txBuf[2] = {0x00, 0x00};

    I2C_transactionInit(&i2cTransaction);

    i2cTransaction.slaveAddress = slaveAddr;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 0;

    /* Set the address and the value to be written. */
    txBuf[0] = regAddr;
    txBuf[1] = value;

    status = I2C_transfer(handle, &i2cTransaction);

    return status;
}
