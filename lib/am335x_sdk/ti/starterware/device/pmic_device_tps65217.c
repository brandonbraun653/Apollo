/**
 * \file   pmic_device_tps65217.c
 *
 * \brief  Source file containing the functional implementation specific to
 *         PMIC device TPS65217.
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
#include "hw_tps65217.h"
#include "pmic_device_tps65217.h"
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
uint32_t PMICDevTps65217GetRegProtectLevel(uint32_t regAddr);

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
int32_t PMICDeviceTps65217RegWrite(uint32_t devId,
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
int32_t PMICDeviceTps65217RegRead(uint32_t devId,
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
uint32_t PMICDevTps65217VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv);

/**
 * \brief  Compute the voltage value of given output source.
 *
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageReg         Value of voltage register.
 *
 * \retval Voltage value in mV.
 */
uint32_t PMICDevTps65217VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t PMICDevTps65217Init(uint32_t devId, uint32_t devInst)
{
    uint32_t regVal = 0U;
    uint32_t retStatus = E_FAIL;

    retStatus = PMICDeviceTps65217RegRead(devId, devInst, POWER_PATH, (uint8_t *) &regVal);

    if(S_PASS == retStatus)
    {
        HW_SET_FIELD(regVal, POWER_PATH_USB_EN, POWER_PATH_USB_EN_ON);
        HW_SET_FIELD(regVal, POWER_PATH_IUSB, POWER_PATH_IUSB_1300MA);
        retStatus = PMICDeviceTps65217RegWrite(devId, devInst, POWER_PATH, regVal);
    }

    if(S_PASS == retStatus)
    {
        retStatus = PMICDeviceTps65217RegRead(devId, devInst, DEFLS1, (uint8_t *) &regVal);
    }

    if(S_PASS == retStatus)
    {
        HW_SET_FIELD(regVal, DEFLS1_LDO3, POWER_PATH_USB_EN_ON);
        retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFLS1, regVal);
    }

    if(S_PASS == retStatus)
    {
        HW_SET_FIELD(regVal, DEFLS1_LDO3, POWER_PATH_USB_EN_ON);
        retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFLS2, regVal);
    }

    return retStatus;
}

int32_t PMICDevTps65217SetOutputVoltage(uint32_t devId,
                                        uint32_t devInst,
                                        uint32_t outputPowerSource,
                                        uint32_t voltageMv)
{
    uint32_t retStatus = E_FAIL;
    uint32_t regVal = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC1:
        {
            voltageReg = PMICDevTps65217VoltageRegCompute(outputPowerSource,
                voltageMv);

            if(0U != voltageReg)
            {
                retStatus = PMICDeviceTps65217RegRead(devId, devInst, DEFDCDC1, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DEFLS1_LDO3, voltageReg);
                retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFDCDC1, regVal);
            }

            if(S_PASS == voltageReg)
            {
                retStatus = PMICDeviceTps65217RegRead(devId, devInst, DEFSLEW, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_GO, DCDC_GO_INITIATE);
                retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFSLEW, regVal);
            }
        }
        break;

        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC2:
        {
            voltageReg = PMICDevTps65217VoltageRegCompute(outputPowerSource,
                voltageMv);

            if(0U != voltageReg)
            {
                retStatus = PMICDeviceTps65217RegRead(devId, devInst, DEFDCDC2, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DEFLS2_LDO4, voltageReg);
                retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFDCDC2, regVal);
            }

            if(S_PASS == voltageReg)
            {
                retStatus = PMICDeviceTps65217RegRead(devId, devInst, DEFSLEW, (uint8_t *) &regVal);
            }

            if(S_PASS == retStatus)
            {
                HW_SET_FIELD(regVal, DCDC_GO, DCDC_GO_INITIATE);
                retStatus = PMICDeviceTps65217RegWrite(devId, devInst, DEFSLEW, regVal);
            }
        }
        break;

        default:
        break;
    }

    return retStatus;
}

uint32_t PMICDevTps65217GetOutputVoltage(uint32_t devId,
                                         uint32_t devInst,
                                         uint32_t outputPowerSource)
{
    uint32_t retVal = 0U;
    uint32_t status = E_FAIL;
    uint32_t regVal = 0U;
    uint32_t voltageReg = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC1:
        {
            /* Select the source configuration. */
            status = PMICDeviceTps65217RegRead(devId, devInst, DEFDCDC1,
                (uint8_t *) &regVal);

            /* Read the voltage register. */
            if(S_PASS == status)
            {
                voltageReg = HW_GET_FIELD(regVal, DEFLS1_LDO3);
                retVal = PMICDevTps65217VoltageCompute(outputPowerSource,
                    voltageReg);
            }
        }
        break;

        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC2:
        {
            /* Select the source configuration. */
            status = PMICDeviceTps65217RegRead(devId, devInst, DEFDCDC2,
                (uint8_t *) &regVal);

            /* Read the voltage register. */
            if(S_PASS == status)
            {
                voltageReg = HW_GET_FIELD(regVal, DEFLS2_LDO4);
                retVal = PMICDevTps65217VoltageCompute(outputPowerSource,
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

uint32_t PMICDevTps65217GetRegProtectLevel(uint32_t regAddr)
{
    int32_t retVal = PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_INVALID;

    switch(regAddr)
    {
        case CHIPID:
        case POWER_PATH:
        case INTERRUPT:
        case CHGCONFIG0:
        case CHGCONFIG1:
        case CHGCONFIG2:
        case CHGCONFIG3:
        case WLEDCTRL1:
        case WLEDCTRL2:
        case MUXCTRL:
        case STATUS:
        case PASSWORD:
        case PGOOD:
            retVal = PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_NONE;
            break;

        case DEFPG:
        case ENABLE:
        case DEFUVLO:
        case SEQ1:
        case SEQ2:
        case SEQ3:
        case SEQ4:
        case SEQ5:
        case SEQ6:
            retVal = PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_1;
            break;

        case DEFDCDC1:
        case DEFDCDC2:
        case DEFDCDC3:
        case DEFSLEW:
        case DEFLDO1:
        case DEFLDO2:
        case DEFLS1:
        case DEFLS2:
            retVal = PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_2;
            break;

        default:
            break;
    }

    return retVal;
}

int32_t PMICDeviceTps65217RegWrite(uint32_t devId,
                                   uint32_t devInst,
                                   uint32_t regAddr,
                                   uint32_t regVal)
{
    int32_t retVal = E_FAIL;
    uint32_t tempRegVal = regVal;
    uint32_t tempRegAddr = regAddr;
    uint32_t instNum = 0U;
    uint32_t regProtectLevel = PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_INVALID;
    uint32_t modId = CHIPDB_MOD_ID_INVALID;
    uint8_t pwdRegAddr = PASSWORD;
    uint8_t pwdRegVal = regAddr ^ PASSWORD_UNLOCK;
    i2cUtilsTxRxParams_t i2cTxRxParams;

    regProtectLevel = PMICDevTps65217GetRegProtectLevel(regAddr);

    if(PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_INVALID != regProtectLevel)
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

        if((PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_1 != regProtectLevel)
             && (S_PASS == retVal))
        {
            i2cTxRxParams.pOffset = (uint8_t *)&pwdRegAddr;
            i2cTxRxParams.pBuffer = (uint8_t *)&pwdRegVal;
            retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
        }

        if((S_PASS == retVal))
        {
            i2cTxRxParams.pOffset = (uint8_t *)&tempRegAddr;
            i2cTxRxParams.pBuffer = (uint8_t *)&tempRegVal;
            retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
        }

        if((PMIC_DEVICE_TP65217_REG_PROTECT_LEVEL_2 == regProtectLevel)
             && (S_PASS == retVal))
        {
            i2cTxRxParams.pOffset = (uint8_t *)&pwdRegAddr;
            i2cTxRxParams.pBuffer = (uint8_t *)&pwdRegVal;
            retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);

            if(S_PASS == retVal)
            {
                i2cTxRxParams.pOffset = (uint8_t *)&tempRegAddr;
                i2cTxRxParams.pBuffer = (uint8_t *)&tempRegVal;
                retVal = I2CUtilsWrite(instNum, &i2cTxRxParams, BOARD_I2C_TIMEOUT_VAL);
            }
        }
    }

    return retVal;
}

int32_t PMICDeviceTps65217RegRead(uint32_t devId,
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

uint32_t PMICDevTps65217VoltageRegCompute(uint32_t outputPowerSource,
                                          uint32_t voltageMv)
{
    int32_t retVal = 0U;
    uint32_t voltageReg = 0U;
    uint32_t voltageUv = 1000U * voltageMv;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC1:
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC2:
        {
            if((voltageUv >= 900000U) && (voltageUv <= 1500000U))
            {
                voltageReg = ((voltageUv - 900000U) / 25000U);
            }
            else if((voltageUv > 1500000U) && (voltageUv <= 2900000U))
            {
                voltageReg = ((voltageUv - 1500000U) / 50000U);
            }
            else if((voltageUv > 2900000U) && (voltageUv <= 3300000U))
            {
                voltageReg = ((voltageUv - 2900000U) / 100000U);
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

uint32_t PMICDevTps65217VoltageCompute(uint32_t outputPowerSource,
                                       uint32_t voltageReg)
{
    int32_t retVal = 0U;
    uint32_t voltageUv = 0U;

    switch(outputPowerSource)
    {
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC1:
        case PMIC_DEVICE_TP65217_OUTPUT_POWER_SOURCE_DEFDCDC2:
        {
            if((voltageReg > 0x0U) && (voltageReg <= 0x18U))
            {
                voltageUv = voltageReg * 25000U + 900000U;
            }
            else if((voltageReg > 0x18U) && (voltageReg <= 0x34U))
            {
                voltageUv = voltageReg * 50000U + 1500000U;
            }
            else if((voltageReg > 0x34U) && (voltageReg <= 0x38U))
            {
                voltageUv = voltageReg * 50000U + 1500000U;
            }
            else if(voltageReg > 0x38U)
            {
                voltageUv = 3300000U;
            }
            else
            {
            }

            if(0U != voltageUv)
            {
                if(voltageUv < 900000U)
                {
                    retVal = 900U;
                }
                else if(voltageUv > 3300000U)
                {
                    retVal = 3300U;
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
