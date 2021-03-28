/**
 * \file   pmic_device_tps65218.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         PMIC device TPS65218.
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
#include "delay_utils.h"
#include "board.h"
#include "pmic_device.h"
#include "hw_tps65218.h"
#include "pmic_device_tps65218.h"
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

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  Gives the protection level of the register.
 *
 * \param  regAddr    Address of register.
 *
 * \retval S_PASS     Successfully written into register.
 * \retval E_FAIL     Failed to write into register.
 */
uint32_t PMICDevTps65218GetRegProtectLevel(uint32_t regAddr);

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
int32_t PMICDeviceTps65218RegWrite(uint32_t devId,
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
int32_t PMICDeviceTps65218RegRead(uint32_t devId,
                                  uint32_t devInst,
                                  uint32_t regAddr,
                                  uint8_t *pRegVal);

/**
 * \brief  Compute the voltage register value of given output source.
 *
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageMv          Voltage of rail in mV.
 *
 * \retval Voltage register value.
 */
uint32_t PMICDevTps65218VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv);

/**
 * \brief  Compute the voltage value of given output source.
 *
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageReg         Value of voltage register.
 *
 * \retval Voltage value in mV.
 */
uint32_t PMICDevTps65218VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PMICDevTps65218Init(uint32_t devId, uint32_t devInst)
{
    uint32_t regVal = 0U;
    uint32_t retStatus = E_FAIL;

    /* Reads the device Chip Id. */
    retStatus = PMICDeviceTps65218RegRead(devId, devInst, CHIPID,
                 (uint8_t *) &regVal);

    return retStatus;
}

int32_t PMICDevTps65218SetOutputVoltage(uint32_t devId,
                                        uint32_t devInst,
                                        uint32_t outputPowerSource,
                                        uint32_t voltageMv)
{
    uint32_t retStatus = E_FAIL;
    uint32_t regVal = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC1:
        {
            voltageReg = PMICDevTps65218VoltageRegCompute(outputPowerSource,
                voltageMv);

            if(0U != voltageReg)
            {
                retStatus = PMICDeviceTps65218RegRead(devId, devInst, DCDC1, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_OP_VOLT, voltageReg);
                retStatus = PMICDeviceTps65218RegWrite(devId, devInst, DCDC1, regVal);
            }

            if(S_PASS == voltageReg)
            {
                retStatus = PMICDeviceTps65218RegRead(devId, devInst, SLEW, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_GO, DCDC_GO_INITIATE);
                retStatus = PMICDeviceTps65218RegWrite(devId, devInst, SLEW, regVal);
            }
        }
        break;

        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC2:
        {
            voltageReg = PMICDevTps65218VoltageRegCompute(outputPowerSource,
                voltageMv);

            if(0U != voltageReg)
            {
                retStatus = PMICDeviceTps65218RegRead(devId, devInst, DCDC2, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_OP_VOLT, voltageReg);
                retStatus = PMICDeviceTps65218RegWrite(devId, devInst, DCDC2, regVal);
            }

            if(S_PASS == voltageReg)
            {
                retStatus = PMICDeviceTps65218RegRead(devId, devInst, SLEW, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_GO, DCDC_GO_INITIATE);
                retStatus = PMICDeviceTps65218RegWrite(devId, devInst, SLEW, regVal);
            }
        }
        break;

        default:
        break;
    }

    return retStatus;
}

uint32_t PMICDevTps65218GetOutputVoltage(uint32_t devId,
                                         uint32_t devInst,
                                         uint32_t outputPowerSource)
{
    uint32_t retVal = 0U;
    uint32_t status = E_FAIL;
    uint32_t regVal = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC1:
        {
            /* Select the source configuration. */
            status = PMICDeviceTps65218RegRead(devId, devInst, DCDC1,
                (uint8_t *) &regVal);

            /* Read the voltage register. */
            if(S_PASS == status)
            {
                voltageReg = HW_GET_FIELD(regVal, DCDC_OP_VOLT);
                retVal = PMICDevTps65218VoltageCompute(outputPowerSource,
                    voltageReg);
            }
        }
        break;

        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC2:
        {
            /* Select the source configuration. */
            status = PMICDeviceTps65218RegRead(devId, devInst, DCDC2,
                (uint8_t *) &regVal);

            /* Read the voltage register. */
            if(S_PASS == status)
            {
                voltageReg = HW_GET_FIELD(regVal, DCDC_OP_VOLT);
                retVal = PMICDevTps65218VoltageCompute(outputPowerSource,
                    voltageReg);
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

uint32_t PMICDevTps65218GetRegProtectLevel(uint32_t regAddr)
{
    int32_t retVal = PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_INVALID;

    switch(regAddr)
    {
        case CHIPID:
        case INTERRUPT1:
        case INTERRUPT2:
        case INT_MASK1:
        case INT_MASK2:
        case STATUS:
        case CONTROL:
        case FLAG:
        case PASSWORD:
            retVal = PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_NONE;
            break;

        case ENABLE1:
        case ENABLE2:
        case CONFIG1:
        case CONFIG2:
        case CONFIG3:
        case DCDC1:
        case DCDC2:
        case DCDC3:
        case DCDC4:
        case SLEW:
        case LDO1:
        case SEQ1:
        case SEQ2:
        case SEQ3:
        case SEQ4:
        case SEQ5:
        case SEQ6:
        case SEQ7:
            retVal = PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_1;
            break;

        default:
            break;
    }

    return retVal;
}

int32_t PMICDeviceTps65218RegWrite(uint32_t devId,
                                   uint32_t devInst,
                                   uint32_t regAddr,
                                   uint32_t regVal)
{
    int32_t retVal = E_FAIL;
    uint32_t tempRegVal = regVal;
    uint32_t tempRegAddr = regAddr;
    uint32_t instNum = 0U;
    uint32_t regProtectLevel = PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_INVALID;
    uint32_t modId = CHIPDB_MOD_ID_INVALID;
    uint8_t pwdRegAddr = PASSWORD;
    uint8_t pwdRegVal = regAddr ^ PASSWORD_UNLOCK;
    i2cUtilsTxRxParams_t i2cTxRxParams;

    /*This sequence might not be applicable for TPS65218 */
    regProtectLevel = PMICDevTps65218GetRegProtectLevel(regAddr);

    if(PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_INVALID != regProtectLevel)
    {
        modId = BOARDGetDeviceCtrlModId(devId, devInst);
    }

    if(CHIPDB_MOD_ID_I2C == modId)
    {
        retVal = S_PASS;
        instNum = BOARDGetDeviceCtrlModInstNum(devId, devInst);
        i2cTxRxParams.slaveAddr = BOARDGetDeviceCtrlInfo(devId, devInst);
        i2cTxRxParams.offsetSize = 1U;
        i2cTxRxParams.bufLen = 1U;

        if((PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_1 == regProtectLevel)
             && (S_PASS == retVal))
        {
            i2cTxRxParams.pOffset = (uint8_t *)&pwdRegAddr;
            i2cTxRxParams.pBuffer = (uint8_t *)&pwdRegVal;
            retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);

            if((S_PASS == retVal))
            {
                i2cTxRxParams.pOffset = (uint8_t *)&tempRegAddr;
                i2cTxRxParams.pBuffer = (uint8_t *)&tempRegVal;
                retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
            }
        }

        if((PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_NONE == regProtectLevel)
             && (S_PASS == retVal))
        {
            if(S_PASS == retVal)
            {
                i2cTxRxParams.pOffset = (uint8_t *)&tempRegAddr;
                i2cTxRxParams.pBuffer = (uint8_t *)&tempRegVal;
                i2cTxRxParams.offsetSize = 1U;
                i2cTxRxParams.bufLen = 1U;
                retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
            }
        }
    }

    return retVal;
}

int32_t PMICDeviceTps65218RegRead(uint32_t devId,
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

uint32_t PMICDevTps65218VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv)
{
    int32_t retVal = 0U;
    uint32_t voltageReg = 0U;
    uint32_t voltageUv = 1000U * voltageMv;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC1:
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC2:
        {
            if((voltageUv >= 850000U) && (voltageUv <= 1350000U))
            {
                voltageReg = ((voltageUv - 850000U) / 10000U);
            }
            else if((voltageUv > 1350000U) && (voltageUv <= 1675000U))
            {
                voltageReg = ((voltageUv - 1350000U) / 25000U);
            }
            else
            {
            }

            if(voltageReg > 0x3FU)
            {
                retVal = 0U;
            }
            else
            {
                retVal = voltageReg;
            }
        }
        break;

        default:
        break;
    }
    return retVal;
}

uint32_t PMICDevTps65218VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg)
{
    int32_t retVal = 0U;
    uint32_t voltageUv = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC1:
        case PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC2:
        {
            if((voltageReg > 0x0U) && (voltageReg <= 0x32U))
            {
                voltageUv = voltageReg * 10000U + 850000U;
            }
            else if((voltageReg > 0x32U) && (voltageReg <= 0x3FU))
            {
                voltageUv = voltageReg * 25000U + 1375000U;
            }
            else
            {
            }

            if(0U != voltageUv)
            {
                if(voltageUv < 850000U)
                {
                    retVal = 850U;
                }
                else if(voltageUv > 1675000U)
                {
                    retVal = 1675U;
                }
                else
                {
                    retVal = voltageUv / 1000U;
                }
            }
        }
        break;

        default:
        break;
    }

    return retVal;
}
