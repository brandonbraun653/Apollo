/**
 * \file   pmic_device.c
 *
 * \brief  Source file containing the abstraction of functional implementation
 *         for PMIC device to configure a rail.
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
#include "pmic_device_tps65217.h"
#include "pmic_device_tps65910.h"
#include "pmic_device_tps65218.h"
#include "pmic_device.h"
#include "console_utils.h"
#include "delay_utils.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Macro value to identify the Output source for MPU rail. */
#define PMIC_MPU_RAIL_MASK              (0x000000FFU)

/** \brief Macro value to identify the Output source for CORE rail. */
#define PMIC_CORE_RAIL_MASK             (0x0000FF00U)

/** \brief Macro value identifying the shift value to identify Core Rail. */
#define PMIC_CORE_RAIL_SHIFT            (8U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static uint32_t PmicGetVoltageSource(uint32_t devId, uint32_t railType);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Structure holding the supported PMIC device ids. */
uint32_t gPmicDeviceIdList[] =
{
    DEVICE_ID_PMIC_TPS65217,
    /**< PMIC part number TPS65217. */
    DEVICE_ID_PMIC_TPS65910,
    /**< PMIC part number TPS65910. */
    DEVICE_ID_PMIC_TPS65218,
    /**< PMIC part number TPS65218. */
    DEVICE_ID_INVALID
    /**< Invalid device ID. */
};

/** \brief Structure holding the panel parameters of different PMICs. */
pmicDeviceData_t gPmicDeviceData[] =
{
    {
        /* PMIC part number TPS65217 */
        DEVICE_ID_PMIC_TPS65217,             /* devId */
        2U                                   /* numOutputPowerSource */
    },
    {
        /* PMIC part number TPS65910. */
        DEVICE_ID_PMIC_TPS65910,             /* devId */
        2U                                   /* numOutputPowerSource */
    },
    {
        /* PMIC part number TPS65218 */
        DEVICE_ID_PMIC_TPS65218,             /* devId */
        2U                                   /* numOutputPowerSource */
    }
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmicDeviceData_t *PMICGetDeviceData(uint32_t devId)
{
    uint32_t numDev = sizeof(gPmicDeviceData) / sizeof(pmicDeviceData_t);
    uint32_t devIndex = 0U;
    pmicDeviceData_t *pPmicDeviceData = NULL;

    for (devIndex = 0U; devIndex < numDev; devIndex++)
    {
        if (devId == gPmicDeviceData[devIndex].devId)
        {
            /* Device Found */
            pPmicDeviceData = &gPmicDeviceData[devIndex];
            break;
        }
    }
    return pPmicDeviceData;
}

uint32_t *PMICGetDeviceIdList(void)
{
    return gPmicDeviceIdList;
}

int32_t PMICInit(void)
{
    int32_t retVal = E_FAIL;
    uint32_t instNum = 0U;
    uint32_t modId = 0U;
    uint32_t devId = DEVICE_ID_INVALID;
    uint32_t devIndex = 0U;
    uint32_t noOfDev = 0U;
    uint32_t idx = 0U;
    uint32_t *pPMICDeviceIdlist;

    /* Get the list of PMIC devices. */
    pPMICDeviceIdlist = PMICGetDeviceIdList();

    do
    {
        if (TRUE == BOARDIsDevicePresent(pPMICDeviceIdlist[devIndex]))
        {
            /* PMIC device found */
            retVal = S_PASS;
            devId = pPMICDeviceIdlist[devIndex];
            noOfDev = BOARDGetNumDevices(pPMICDeviceIdlist[devIndex]);

            for (idx = 0U; ((S_PASS == retVal) && (idx < noOfDev)); idx++)
            {
                /* Get the control mod id for the current device */
                modId = BOARDGetDeviceCtrlModId(devId, idx);

                if(CHIPDB_MOD_ID_I2C == modId)
                {
                    i2cUtilsInitParams_t i2cUtilsParams = I2CUTILSINITPARAMS_DEFAULT;

                    instNum = BOARDGetDeviceCtrlModInstNum(devId, idx);
                    retVal = I2CUtilsInit(instNum, &i2cUtilsParams);

                    if(S_PASS == retVal)
                    {
                        switch(devId)
                        {
                            case DEVICE_ID_PMIC_TPS65217:
                            {
                                PMICDevTps65217Init(devId, idx);
                            }
                            break;

                            case DEVICE_ID_PMIC_TPS65910:
                            {
                                PMICDevTps65910Init(devId, idx);
                            }
                            break;

                            case DEVICE_ID_PMIC_TPS65218:
                            {
                                PMICDevTps65218Init(devId, idx);
                            }
                            break;

                            default:
                                retVal = E_FAIL;
                            break;
                        }
                    }
                }
            }
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != pPMICDeviceIdlist[devIndex]);

    return retVal;
}

int32_t PMICSetRailVoltage(uint32_t railType, uint32_t voltage)
{
    int32_t retVal = E_FAIL;
    uint32_t devId = DEVICE_ID_INVALID;
    uint32_t devIndex = 0U;
    uint32_t railPmicOutputVoltageSource = 0U;
    uint32_t noOfDev = 0U;
    uint32_t idx = 0U;
    uint32_t *pPMICDeviceIdlist;
    uint32_t pmicOpSrcMap = 0U;

    /* Get the list of PMIC devices. */
    pPMICDeviceIdlist = PMICGetDeviceIdList();

    do
    {
        if (TRUE == BOARDIsDevicePresent(pPMICDeviceIdlist[devIndex]))
        {
            /* PMIC device found */
            retVal = S_PASS;
            devId = pPMICDeviceIdlist[devIndex];
            noOfDev = BOARDGetNumDevices(pPMICDeviceIdlist[devIndex]);

            for (idx = 0U; ((S_PASS == retVal) && (idx < noOfDev)); idx++)
            {
                pmicOpSrcMap = BOARDGetDeviceDataModId(devId, idx);

                /* API for Rail type to PMIC voltage terminal mapping. */
                railPmicOutputVoltageSource = PmicGetVoltageSource(pmicOpSrcMap, railType);

                if(0xFFFFFFFF != railPmicOutputVoltageSource)
                {
                    switch(devId)
                    {
                        case DEVICE_ID_PMIC_TPS65217:
                        {
                            retVal = PMICDevTps65217SetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource, voltage);
                        }
                        break;

                        case DEVICE_ID_PMIC_TPS65910:
                        {
                            retVal = PMICDevTps65910SetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource, voltage);
                        }
                        break;

                        case DEVICE_ID_PMIC_TPS65218:
                        {
                            retVal = PMICDevTps65218SetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource, voltage);
                        }
                        break;

                        default:
                            retVal = E_FAIL;
                        break;
                    }
                    break;
                }
            }
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != pPMICDeviceIdlist[devIndex]);

    return retVal;
}

uint32_t PMICGetRailVoltage(uint32_t railType)
{
    int32_t retVal = 0U;
    int32_t status = E_FAIL;
    uint32_t devId = DEVICE_ID_INVALID;
    uint32_t devIndex = 0U;
    uint32_t railPmicOutputVoltageSource = 0U;
    uint32_t noOfDev = 0U;
    uint32_t idx = 0U;
    uint32_t *pPMICDeviceIdlist;
    uint32_t pmicOpSrcMap = 0U;

    /* Get the list of PMIC devices. */
    pPMICDeviceIdlist = PMICGetDeviceIdList();

    do
    {
        if (TRUE == BOARDIsDevicePresent(pPMICDeviceIdlist[devIndex]))
        {
            /* PMIC device found */
            status = S_PASS;
            devId = pPMICDeviceIdlist[devIndex];
            noOfDev = BOARDGetNumDevices(pPMICDeviceIdlist[devIndex]);

            for (idx = 0U; ((S_PASS == status) && (idx < noOfDev)); idx++)
            {
                pmicOpSrcMap = BOARDGetDeviceDataModId(devId, idx);

                /* Resolve the Rail type to PMIC voltage terminal mapping. */
                railPmicOutputVoltageSource = PmicGetVoltageSource(pmicOpSrcMap, railType);

                if(0xFFFFFFFF != railPmicOutputVoltageSource)
                {
                    switch(devId)
                    {
                        case DEVICE_ID_PMIC_TPS65217:
                        {
                            retVal = PMICDevTps65217GetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource);
                        }
                        break;

                        case DEVICE_ID_PMIC_TPS65910:
                        {
                            retVal = PMICDevTps65910GetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource);
                        }
                        break;

                        case DEVICE_ID_PMIC_TPS65218:
                        {
                            retVal = PMICDevTps65218GetOutputVoltage(devId, idx,
                                railPmicOutputVoltageSource);
                        }
                        break;

                        default:
                            status = E_FAIL;
                        break;
                    }
                    break;
                }
            }
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != pPMICDeviceIdlist[devIndex]);

    return retVal;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static uint32_t PmicGetVoltageSource(uint32_t pmicOpSrcMap, uint32_t railType)
{
    uint32_t pmicOpTerminal= 0U;

    switch(railType)
    {
        case PMIC_DEVICE_RAIL_TYPE_MPU:
        {
            pmicOpTerminal = (pmicOpSrcMap & PMIC_MPU_RAIL_MASK);
        }
        break;

        case PMIC_DEVICE_RAIL_TYPE_CORE:
        {
            pmicOpTerminal = ((pmicOpSrcMap & PMIC_CORE_RAIL_MASK) >>
                                PMIC_CORE_RAIL_SHIFT);
        }
        break;

        default:
        {
            pmicOpTerminal = (pmicOpSrcMap & PMIC_MPU_RAIL_MASK);
        }
        break;
    }

    return pmicOpTerminal;
}
