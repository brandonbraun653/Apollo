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

/**
 *  \file   evmAM572x_mmc.c
 *
 *  \brief  AM572x MMC signalling voltage switching function.
 *
 *   This file contains the function used by MMCSD driver which switchges
 *   the MMC signalling voltage from 3.0V to 1.8V and vice versa.
 *   This is achieved by changing the LDO1 voltage output of the PMIC
 *   which feeds the signalling voltage in the EVM. This function also
 *   updates the PBAIS registers accordingly.
 *
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <ti/board/board.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_mmcsd.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/pm/include/pm_types.h>
#include <ti/drv/pm/include/prcm/pmhal_pmic.h>
#include <ti/drv/pm/include/pmic/pmhal_tps659039.h>
#include <ti/drv/pm/include/prcm/pmhal_i2cComm.h>
extern I2C_config_list I2C_config;
static I2C_Handle pmic_i2c_handle = NULL;

/* #define CTRL_CORE_CONTROL_PBIAS                         CSL_CONTROL_CORE_PAD_CONTROL_PBIAS */
/* #define CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ_MASK CSL_CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ_MASK */
/* #define CTRL_CORE_CONTROL_PBIAS_SDCARD_IO_PWRDNZ_MASK   CSL_CONTROL_CORE_PAD_CONTROL_PBIAS_SDCARD_IO_PWRDNZ_MASK */
/* #define CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_VMODE_MASK  CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_VMODE_MASK */

/* The below function applies to EVM_AM572x (A3) whose Bus voltages could be switched to 1.8V and back through a PMIC chip */
static void delay(uint32_t delay)
{
    volatile uint32_t i;

    for (i = 0; i < (1000 * delay); ++i)
        ;
}

static int32_t PmI2cInit(void)
{
    I2C_Params i2cParams;
    int i;
    int32_t retVal = PM_SUCCESS;

    if (pmic_i2c_handle != NULL)
    {

        /* I2C instance already opened */
        return PM_SUCCESS;
    }

    for (i = 0; I2C_config[i].fxnTablePtr != NULL; i++)
    {
        ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    pmic_i2c_handle = I2C_open(PMHAL_TPS659039_I2C_NUM_1, &i2cParams);

    if (pmic_i2c_handle == NULL)
    {
        retVal = PM_FAIL;
    }

    return (retVal);
}

static int32_t PmI2cReadByte(uint32_t i2cNum,
                             uint32_t i2cDevAddr,
                             const uint8_t *regAddr,
                             uint8_t *regValue,
                             uint32_t numRegs)
{
    unsigned int status = I2C_STATUS_SUCCESS;
    int32_t ret_val     = PM_FAIL;
    uint8_t writebuf[1];
    uint8_t readbuf[2];
    I2C_Transaction i2cTransaction;

    I2C_transactionInit(&i2cTransaction);
    writebuf[0] = *regAddr;

    i2cTransaction.slaveAddress = i2cDevAddr;
    i2cTransaction.writeBuf     = (uint8_t *)&writebuf[0];
    i2cTransaction.writeCount   = 1;

    readbuf[0] = *regAddr;
    i2cTransaction.readBuf   = &readbuf[0];
    i2cTransaction.readCount = 1;
    status = I2C_transfer(pmic_i2c_handle, &i2cTransaction);

    if (status == I2C_STS_SUCCESS)
    {
        ret_val = PM_SUCCESS;
    }

    *regValue = readbuf[0];

    return (ret_val);
}

static int32_t PmI2cWriteByte(uint32_t i2cNum,
                              uint32_t i2cDevAddr,
                              const uint8_t *regAddr,
                              const uint8_t *regValue,
                              uint32_t numRegs)
{
    bool status      = false;
    int32_t ret_val  = PM_FAIL;
    I2C_Transaction i2cTransaction;
    uint8_t txBuf[2] = {0x00, 0x00};

    /* Set the address and the value to be written. */
    txBuf[0] = *regAddr;
    txBuf[1] = *regValue;

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = i2cDevAddr;
    i2cTransaction.writeBuf     = txBuf;
    i2cTransaction.writeCount   = 2;
    i2cTransaction.readCount    = 0;

    status = I2C_transfer(pmic_i2c_handle, &i2cTransaction);

    if (status == I2C_STS_SUCCESS)
    {
        ret_val = PM_SUCCESS;
    }

    return ret_val;
}

static const pmhalI2cCommOperations_t gPmicI2cfunc = {
    &PmI2cInit,
    &PmI2cReadByte,
    &PmI2cWriteByte,
    NULL,
    NULL
};
static volatile uint8_t ldo1_ctrl;
static volatile uint8_t ldo1_voltage;

/* **********  Voltage Switching function for MMCSD *****************
 * Functionality: Change the voltage of the MMC CMD & DAT lines.
 *                This function is called by the MMCSD card driver (if the driver is
 *                configured to use this function at init time by the application) to change
 *                the CMD & DAT voltage from 3.0V to 1.8V if a UHS-I card is found.
 *                This function configures the PMIC controller of the board to switch the voltage
 *                and configures the MMC PBAIS registers to reflect that change
 */

static pmErrCode_t Board_mmc_change_pmic_to_18v(uint32_t regulator_voltage)
{
    pmErrCode_t    retVal;
    const pmhalPmicOperations_t *pmicOps;

    /* Register the I2C functions with the PMIC Communication to ensure the
         * PMIC can be communicated with I2C driver specific to SBL
         */
    PMHALI2CCommRegister(&gPmicI2cfunc);
    pmicOps = PMHALTps659039GetPMICOps();
    retVal  = PMHALPmicRegister(pmicOps);

    if (retVal != PM_SUCCESS)
        return retVal;

    retVal = PMHALPmicSetRegulatorVoltage(PMHAL_PRCM_PMIC_REGULATOR_MMC13V3,
                                          regulator_voltage,
                                          PM_TIMEOUT_INFINITE,
                                          FALSE);

    return retVal;
}

/* This is the time in micro seconds to wait until the voltage supply latches in and stabilize */
#define PBAIS_VOLTAGE_SUPPLY_TIMEOUT_USEC 4

/* **********  Voltage Switching function for MMCSD *****************
 * Functionality: Change the voltage of the MMC CMD & DAT lines.
 *                This function is called by the MMCSD card driver (if the driver is
 *                configured to use this function at init time by the application) to change
 *                the CMD & DAT voltage from 3.0V to 1.8V if a UHS-I card is found.
 *                This function configures the PMIC controller of the board to switch the voltage
 *                and configures the MMC PBAIS registers to reflect that change
 */

MMCSD_Error Board_mmc_voltageSwitchFxn(uint32_t instance, MMCSD_BusVoltage_e switch_voltage)
{
    pmErrCode_t pmRet;
    MMCSD_Error retVal = MMCSD_OK;
    uint32_t switch_voltage_milliVolts;
    uint32_t reg_val   = 0, status_val = 0, waitusec;

    if (switch_voltage == MMCSD_BUS_VOLTAGE_1_8V)
    {
        switch_voltage_milliVolts = 1800; /* 1.8V */
        status_val = CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT_1V8;
    }
    else if (switch_voltage == MMCSD_BUS_VOLTAGE_3_0V)
    {
        switch_voltage_milliVolts = 3000; /* 3V */
        status_val = CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT_3V;
    }
    else
    {
        switch_voltage_milliVolts = 0; /* 3.3V */
        return MMCSD_ERR;
    }

    reg_val = HW_RD_REG32(
        SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE + CTRL_CORE_CONTROL_PBIAS);

    reg_val &= ~CTRL_CORE_CONTROL_PBIAS_SDCARD_IO_PWRDNZ_MASK;
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                CTRL_CORE_CONTROL_PBIAS, reg_val);
    reg_val &= ~CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ_MASK;
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                CTRL_CORE_CONTROL_PBIAS, reg_val);

    /* Reconfigure the PMIC chip on the EVM */
    pmRet = Board_mmc_change_pmic_to_18v(switch_voltage_milliVolts);

    if (pmRet == PM_SUCCESS)
    {
        /*Set SDCARD_BIAS_VMODE to the desired voltage*/
        reg_val  = reg_val & ~CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_VMODE_MASK;
        reg_val  = reg_val & ~CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT_MASK;

        reg_val |= (CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_VMODE_1V8 << CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_VMODE_SHIFT);
        reg_val |=
            (CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT_1V8 <<
            CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT_SHIFT);

        HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                    CTRL_CORE_CONTROL_PBIAS, reg_val);

        /* Read the SDCARD_BIAS_SUPPLY_HI_OUT to see if the status bit is stable for atleast 4 micro seconds*/
        waitusec = 0;

        do
        {
            delay(1); /* Wait for 4 us to stabilize */
            waitusec++;

            if (waitusec > PBAIS_VOLTAGE_SUPPLY_TIMEOUT_USEC)
            {
                /* The MMC supply voltage supply should have stabilized by now */
                retVal = MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE;
                break;
            }
        } while (HW_RD_FIELD32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                               CTRL_CORE_CONTROL_PBIAS,
                               CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_SUPPLY_HI_OUT) != status_val);
    }
    else
    {
        retVal = MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE;
    }

    /* Powering back on */
    reg_val  = HW_RD_REG32(
        SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE + CTRL_CORE_CONTROL_PBIAS);
    reg_val |= CTRL_CORE_CONTROL_PBIAS_SDCARD_BIAS_PWRDNZ_MASK;
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                CTRL_CORE_CONTROL_PBIAS, reg_val);

    reg_val |= CTRL_CORE_CONTROL_PBIAS_SDCARD_IO_PWRDNZ_MASK;
    HW_WR_REG32(SOC_CTRL_MODULE_CORE_CORE_PAD_REGISTERS_BASE +
                CTRL_CORE_CONTROL_PBIAS, reg_val);

    delay(20); /* wait 20 us. This value has been found out by testing */

    return retVal;
}
