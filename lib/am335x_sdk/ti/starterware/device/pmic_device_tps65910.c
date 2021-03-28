/**
 * \file   pmic_device_tps65910.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         PMIC device TPS65910.
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
#include "hw_types.h"
#include "error.h"
#include "device.h"
#include "ethernet.h"
#include "cpsw.h"
#include "chipdb_defs.h"
#include "chipdb.h"
#include "i2c_utils.h"
#include "board.h"
#include "pmic_device.h"
#include "hw_tps65910.h"
#include "pmic_device_tps65910.h"
#include "console_utils.h"
#include "delay_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Macro indicating the i2c time out value. */
#define BOARD_I2C_TIMEOUT_VAL           (1000000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  Writes to given register address.
 *
 * \param  devId      PMIC device ID.
 * \param  devInst    PMIC device instance.
 * \param  regAddr    Address of register.
 * \param  regVal     Value to write into register.
 *
 * \retval S_PASS     Successfully read from register.
 * \retval E_FAIL     Failed to read from register.
 */
int32_t PMICDeviceTps65910RegWrite(uint32_t devId,
                                   uint32_t devInst,
                                   uint32_t regAddr,
                                   uint32_t regVal);

/**
 * \brief  Read from given register address.
 *
 * \param  devId      PMIC device ID.
 * \param  devInst    PMIC device instance.
 * \param  regAddr    Address of register.
 * \param  pRegVal    Value read from register.
 *
 * \retval S_PASS     Successfully read given rail voltage.
 * \retval E_FAIL     Failed to read given rail voltage.
 */
int32_t PMICDeviceTps65910RegRead(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t regAddr,
                                  uint8_t *pRegVal);

/**
 * \brief  Compute the voltage register value of given output source.
 *
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageMv          Voltage of rail in mV.
 * \param  voltageGain        Gain on the output power source.
 * \param  voltageStep        Voltage step for output power source.
 *
 * \retval Voltage register value.
 */
uint32_t PMICDevTps65910VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv,
                                          uint32_t voltageGain,
                                          uint32_t voltageStep);

/**
 * \brief  Compute the voltage value of given output source.
 *
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageReg         Value of voltage register.
 * \param  voltageGain        Gain on the output power source.
 * \param  voltageStep        Voltage step for output power source.
 *
 * \retval Voltage value in mV.
 */
uint32_t PMICDevTps65910VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg,
                                       uint32_t voltageGain,
                                       uint32_t voltageStep);

/**
 * \brief  Read voltage of a rail.
 *
 * \param  devId      PMIC device ID.
 * \param  devInst    PHY device instance.
 * \param  railType   Rail of SoC to be read.
 * \param  voltage    Voltage of rail.
 *
 * \retval S_PASS     Successfully read given rail voltage.
 * \retval E_FAIL     Failed to read given rail voltage.
 */
int32_t PMICDevTps65910I2cIntrfSelect(uint32_t devId,
                                      uint32_t devInst,
                                      uint32_t i2cIntrfType);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PMICDevTps65910Init(uint32_t devId, uint32_t devInst)
{
    uint32_t retStatus = E_FAIL;

    /* Configure to use I2C control interface. */
    retStatus = PMICDevTps65910I2cIntrfSelect(devId, devInst,
        PMIC_DEVICE_TP65217_I2C_INTRF_TYPE_CTRL);

    return retStatus;
}

int32_t PMICDevTps65910SetOutputVoltage(uint32_t devId,
                                        uint32_t devInst,
                                        uint32_t outputPowerSource,
                                        uint32_t voltageMv)
{
    uint32_t retStatus = E_FAIL;
    volatile uint32_t regVal = 0U;
    uint32_t voltageGain = 0U;
    uint32_t voltageStep = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD1:
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD2:
        {
            voltageGain = 1U;
            voltageStep = 12500U;
            voltageReg = PMICDevTps65910VoltageRegCompute(outputPowerSource,
                voltageMv, voltageGain, voltageStep);

            /* Select the source configuration. */
            if(0U != voltageReg)
            {
                retStatus = PMICDeviceTps65910RegRead(devId, devInst,
                    VDD1_REG, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, PMIC_VDD1_REG_VGAIN_SEL,
                    PMIC_VDD1_REG_VGAIN_SEL_X1);
                HW_SET_FIELD(regVal, PMIC_VDD1_REG_ILMAX, PMIC_VDD1_REG_ILMAX_1_5_A);
                HW_SET_FIELD(regVal, PMIC_VDD1_REG_TSTEP, PMIC_VDD1_REG_TSTEP_12_5);
                HW_SET_FIELD(regVal, PMIC_VDD1_REG_ST, PMIC_VDD1_REG_ST_ON_HI_POW);
                retStatus = PMICDeviceTps65910RegWrite(devId, devInst,
                    VDD1_REG, regVal);
            }

            /* Configure the voltage source. */
            if(S_PASS == retStatus)
            {
                retStatus = PMICDeviceTps65910RegRead(devId, devInst, VDD1_OP_REG, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, PMIC_VDD1_OP_REG_CMD, PMIC_VDD1_OP_REG_CMD_OP);
                retStatus = PMICDeviceTps65910RegWrite(devId, devInst, VDD1_OP_REG, regVal);
            }

            /* Configure the voltage source. */
            if(S_PASS == retStatus)
            {
                retStatus = PMICDeviceTps65910RegRead(devId, devInst, VDD1_OP_REG, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, PMIC_VDD1_OP_REG_SEL, voltageReg);
                retStatus = PMICDeviceTps65910RegWrite(devId, devInst, VDD1_OP_REG, regVal);
            }
        }
        break;

        default:
        break;
    }

    return retStatus;
}

uint32_t PMICDevTps65910GetOutputVoltage(uint32_t devId,
                                         uint32_t devInst,
                                         uint32_t outputPowerSource)
{
    uint32_t retVal = 0U;
    uint32_t status = E_FAIL;
    volatile uint32_t regVal = 0U;
    uint32_t voltageGain = 0U;
    uint32_t voltageStep = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD1:
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD2:
        {
            /* Select the source configuration. */
            status = PMICDeviceTps65910RegRead(devId, devInst, VDD1_OP_REG,
                (uint8_t *) &regVal);

            if(S_PASS == status)
            {
                if(PMIC_VDD1_OP_REG_CMD_SR == HW_GET_FIELD(regVal,
                    PMIC_VDD1_OP_REG_CMD))
                {
                    status = PMICDeviceTps65910RegRead(devId, devInst,
                        VDD1_SR_REG, (uint8_t *) &regVal);
                }
            }

            /* Read the voltage register. */
            if(S_PASS == status)
            {
                voltageReg = HW_GET_FIELD(regVal, PMIC_VDD1_OP_REG_SEL);
                status = PMICDeviceTps65910RegRead(devId, devInst,
                    VDD1_REG, (uint8_t *) &regVal);
            }

            /* Read the voltage gain, time step and compute voltage. */
            if(S_PASS == status)
            {
                voltageGain = HW_GET_FIELD(regVal, PMIC_VDD1_REG_VGAIN_SEL);

                if(PMIC_VDD1_REG_VGAIN_SEL_X1 == voltageGain)
                {
                    voltageGain = 1U;
                }

                switch(HW_GET_FIELD(regVal, PMIC_VDD1_REG_TSTEP))
                {
                    case PMIC_VDD1_REG_TSTEP_0:
                        voltageStep = 0U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_12_5:
                        voltageStep = 12500U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_9_4:
                        voltageStep = 9400U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_7_5:
                        voltageStep = 7500U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_6_25:
                        voltageStep = 6250U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_4_7:
                        voltageStep = 4700U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_3_12:
                        voltageStep = 3120U;
                    break;

                    case PMIC_VDD1_REG_TSTEP_2_5:
                        voltageStep = 2500U;
                    break;

                    default:
                        voltageStep = 0U;
                    break;
                }

                retVal = PMICDevTps65910VoltageCompute(outputPowerSource,
                    voltageReg, voltageGain, voltageStep);
            }
        }
        break;

        default:
        break;
    }

    return retVal;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

int32_t PMICDeviceTps65910RegWrite(uint32_t devId,
                                   uint32_t devInst,
                                   uint32_t regAddr,
                                   uint32_t regVal)
{
    int32_t retVal = E_FAIL;
    uint32_t tempRegVal = regVal;
    uint32_t tempRegAddr = regAddr;
    uint32_t instNum = CHIPDB_MOD_ID_INVALID;
    uint32_t modId = 0U;
    i2cUtilsTxRxParams_t i2cTxRxParams;

    modId = BOARDGetDeviceCtrlModId(devId, devInst);

    if(CHIPDB_MOD_ID_I2C == modId)
    {
        instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
        i2cTxRxParams.slaveAddr = BOARDGetDeviceCtrlInfo(devId, devInst);
        i2cTxRxParams.pOffset    = (uint8_t *)&tempRegAddr;
        i2cTxRxParams.offsetSize = 1U;
        i2cTxRxParams.bufLen     = 1U;
        i2cTxRxParams.pBuffer    = (uint8_t *)&tempRegVal;

        retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
    }

    return retVal;
}

int32_t PMICDeviceTps65910RegRead(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t regAddr,
                                  uint8_t *pRegVal)
{
    int32_t retVal = E_FAIL;
    uint32_t tempRegAddr = regAddr;
    uint32_t instNum = CHIPDB_MOD_ID_INVALID;
    uint32_t modId = 0U;
    i2cUtilsTxRxParams_t i2cTxRxParams;

    if(NULL != pRegVal)
    {
        modId = BOARDGetDeviceCtrlModId(devId, devInst);
    }

    if(CHIPDB_MOD_ID_I2C == modId)
    {
        instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
        i2cTxRxParams.slaveAddr = BOARDGetDeviceCtrlInfo(devId, devInst);
        i2cTxRxParams.pOffset    = (uint8_t *)&tempRegAddr;
        i2cTxRxParams.offsetSize = 1U;
        i2cTxRxParams.bufLen     = 1U;
        i2cTxRxParams.pBuffer    = (uint8_t *)pRegVal;

        retVal = I2CUtilsRead(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
    }

    return retVal;
}

uint32_t PMICDevTps65910VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv,
                                          uint32_t voltageGain,
                                          uint32_t voltageStep)
{
    uint32_t retVal = 0U;
    uint32_t voltageReg = 0U;
    uint32_t voltageUv = 1000U * voltageMv;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD1:
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD2:
        {
            if(((voltageUv >= 600000U) && (voltageUv <= 1500000U)) && (0U != voltageGain))
            {
                if(0U == voltageStep)
                {
                    voltageReg = ((voltageUv / voltageGain) - 562500);
                }
                else if((12500U == voltageStep) || (9400U == voltageStep) ||
                    (7500U == voltageStep) || (6250U == voltageStep) ||
                    (4700U == voltageStep) || (3120U == voltageStep) ||
                    (2500U == voltageStep))
                {
                    voltageReg = ((voltageUv / voltageGain) - 562500) / voltageStep;
                }
                else
                {
                }

                if(voltageReg > 0x7FU)
                {
                    retVal = 0U;
                }
                else
                {
                    retVal = voltageReg;
                }
            }
        }
        break;

        default:
        break;
    }

    return retVal;
}

uint32_t PMICDevTps65910VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg,
                                       uint32_t voltageGain,
                                       uint32_t voltageStep)
{
    uint32_t retVal = 0U;
    int32_t status = E_FAIL;
    uint32_t voltageUv = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD1:
        case PMIC_DEVICE_TP65910_OUTPUT_POWER_SOURCE_VDD2:
        {
            if(((voltageReg > 0x0U) && (voltageReg <= 0x7FU)) && (0U != voltageGain))
            {
                status = S_PASS;

                if(0U == voltageStep)
                {
                    voltageUv = (voltageReg + 562500) * voltageGain;
                }
                else if((12500 == voltageStep) || (9400 == voltageStep) ||
                    (7500 == voltageStep) || (6250 == voltageStep) ||
                    (4700 == voltageStep) || (3120 == voltageStep) ||
                    (2500 == voltageStep))
                {
                    voltageUv = ((voltageReg * voltageStep) + 562500) * voltageGain;
                }
                else
                {
                    status = E_FAIL;
                }

                if((S_PASS == status))
                {
                    if(voltageUv < 600000U)
                    {
                        retVal = 600U;
                    }
                    else if(voltageUv > 1500000U)
                    {
                        retVal = 1500U;
                    }
                    else
                    {
                        retVal = voltageUv / 1000U;
                    }
                }
            }
        }
        break;

        default:
        break;
    }

    return retVal;
}

int32_t PMICDevTps65910I2cIntrfSelect(uint32_t devId,
                                      uint32_t devInst,
                                      uint32_t i2cIntrfType)
{
    int32_t retVal = E_FAIL;
    uint32_t regVal = 0U;
    uint32_t regFieldVal = 0U;

    retVal = PMICDeviceTps65910RegRead(devId, devInst, DEVCTRL_REG, (uint8_t *) &regVal);

    if(S_PASS == retVal)
    {
        if(PMIC_DEVICE_TP65217_I2C_INTRF_TYPE_CTRL == i2cIntrfType)
        {
            regFieldVal = PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_CTL_I2C;
        }
        else if(PMIC_DEVICE_TP65217_I2C_INTRF_TYPE_SR == i2cIntrfType)
        {
            regFieldVal = PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_SR_I2C;
        }
        else
        {
            retVal = E_FAIL;
        }
    }

    if(S_PASS == retVal)
    {
        HW_SET_FIELD(regVal, PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL, regFieldVal);
        retVal = PMICDeviceTps65910RegWrite(devId, devInst, DEVCTRL_REG, regVal);
    }

    return retVal;
}
