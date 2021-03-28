/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016-2017
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
 */

/**
 * \file        pmhal_tps65218.c
 *
 * \brief       Power Management IC - TPS65218 specific API implementation.
 *              APIs are exported by using function pointers.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <ti/csl/hw_types.h>
#include "pm_types.h"
#include "pm_utils.h"
#include "pmhal_pmic.h"
#include <ti/drv/pm/include/pmic/pmhal_tps65218.h>
#include <ti/starterware/include/hw/hw_tps65218.h>
#include "pmhal_pmicComm.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief   Check if the TPS65218 PMIC is present. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   void
 *
 * \return  PM_SUCCESS - TPS65218 PMIC is present.
 *          PM_PMHAL_PMIC_VENDOR_ID_INVALID - PMIC vendor id doesn't match the
 *                                     expected value.
 *          PM_PMHAL_PMIC_PRODUCT_ID_INVALID - PMIC product id doesn't match the
 *                                      expected value.
 */
static pmErrCode_t PMHALTps65218IsPresent(void);

/**
 * \brief   Return the PMIC Product ID. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   productId   The Product ID is populated in this parameter.
 *
 * \return  status      PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65218GetProductId(uint32_t *productId);

/**
 * \brief  Get the voltage setting of the given regulator. The declaration is
 *         present here to ensure this function is used only via function
 *         pointer.
 *
 * \param  regId    Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param  voltage  Voltage in mV returned.
 *
 * \return status   PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65218GetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                  *voltage);

/**
 * \brief  Set the voltage of the regulator to the mV given. The declaration is
 *         present here to ensure this function is used only via function
 *         pointer.
 *
 *         NOTE:
 *         PMIC allows controlling the voltage in many ways. The approach
 *         taken by this routine is to use the current configuration for
 *         voltage setting and try to succeed. It doesn't try to alter the
 *         configuration to ensure success. For example, if ROOF_FLOOR_EN
 *         control bit is set to 1 to mean that the voltage is controlled
 *         by the device resource pins, then this routine returns error;
 *         even though this bit can be changed to 0U to succeed.
 *
 * \param  regId    Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param  voltage  Voltage in mV returned.
 * \param  timeout  Timeout iterations to wait for setting the right regulator
 *                  voltage value. Possible values can be:
 *                  PM_TIMEOUT_NOWAIT   Do not wait for voltage setting.
 *                  PM_TIMEOUT_INFINITE Wait infinitely till the voltage is set.
 *                  Non Zero Value      Wait for the time provided by the user.
 *
 * \return Status   PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65218SetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   timeout);

/**
 * \brief  API to check if the given regulator enabled. The declaration is
 *         present here to ensure this function is used only via function
 *         pointer.
 *
 * \param  regId  Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 *
 * \return enabled  TRUE if regulator is enabled; FALSE otherwise.
 */
static uint32_t    PMHALTps65218IsRegulatorEnabled(
    pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief  Enable the given regulator. The declaration is
 *         present here to ensure this function is used only via function
 *         pointer.
 *
 * \param  regId  Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 *
 * \return status PM_SUCCESS if API is a success. PM_BADARGS/FAIL otherwise.
 */
static pmErrCode_t PMHALTps65218EnableRegulator(
    pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief  Disable the given regulator. The declaration is
 *         present here to ensure this function is used only via function
 *         pointer.
 *
 * \param  regId  Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 *
 * \return status PM_SUCCESS if API is a success. PM_BADARGS/FAIL otherwise.
 */
static pmErrCode_t PMHALTps65218DisableRegulator(
    pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief   Return the Regulator Step voltage size. This is required by the
 *          voltage manager to understand the opp for the given voltage set for
 *          the given voltage rail.
 *
 * \param   regId       Regulator ID. Refer #pmhalPrcmPmicRegulatorId_t for
 *                      details.
 * \param   avsVolt     AVS voltage which is to be converted to regulator
 *                      voltage
 *
 * \return  convVolt    The voltage that would be supplied by the regulator if
 *                      the AVS voltage is given to the API.
 *                      NOTE: This API does not program the PMIC. It just
 *                      returns the calculated value of AVS voltage converted to
 *                      PMIC voltage based on the PMIC voltage resolution.
 */
static uint32_t PMHALTps65218GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage);

#ifdef __cplusplus
}
#endif

/**
 * \brief Given voltage in mV, return the voltage offset
 *
 * \param   regId      Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   voltage    Voltage in mV.
 * \param   voltOffset Voltage offset value returned.
 *
 * \return  status
 */
static pmErrCode_t PmhalTps65218VoltageToVoltOffset(
    pmhalPrcmPmicRegulatorId_t  regId,
    uint32_t                    voltage,
    uint32_t                   *voltOffset);

/**
 * \brief Given voltage offset convert it to voltage in mV and return.
 *
 * \param   regId    Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   sel      Voltage offset value returned.
 *
 * \return  voltage Voltage in mV.
 */
static uint32_t PmhalTps65218VoltOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltOffset);

/**
 * \brief  Read the register value at the given physical address.
 *
 * \param   i2cNum      I2C instance number used to communicate with PMIC.
 * \param   phyAddr     Address to be read.
 * \param   value       Returns the value read.
 *
 * \return  status      Return PM_SUCCESS if read is successful. Else returns
 *                      PM_FAIL.
 */
static pmErrCode_t PmhalTps65218ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                             uint32_t *value);

/**
 * \brief  Write the given register value at the given physical address.
 *
 * \param   i2cNum      I2C instance number used to communicate with PMIC.
 * \param   phyAddr     Address to be written to.
 * \param   value       Returns the value to be written.
 *
 * \return Return success or failure.
 */
static pmErrCode_t PmhalTps65218WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                              uint32_t value);

/**
 * \brief  Is the given regulator enabled?
 *         This utility function must only be called by functions in this
 *         file and the caller must ensure that the PMIC communication is
 *         configured and enabled before calling this function.
 *
 * \param  regId  Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 *
 * \return TRUE if regulator is enabled; FALSE otherwise.
 */
static uint32_t PmhalTps65218CheckRegulatorEnabled
    (pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief Function to convert the physical address to the slave address.
 *
 * \param   phyAddr     Physical Address
 * \return  slaveAddr   Slave Address
 */
static uint8_t PmhalTps65218PhytoSlaveAddr(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page offset
 */
static uint8_t PmhalTps65218PhyToPageOffset(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page Number
 */
static uint32_t PmhalTps65218PhyToPage(uint32_t phyAddr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Power Management IC device callbacks. */
const pmhalPmicOperations_t          gPmhalTps65218Ops =
{
    &PMHALTps65218IsPresent,               /* isPresent */
    NULL,                                  /* getRevision */
    NULL,                                  /* getVendorId */
    &PMHALTps65218GetProductId,            /* getProductId */
    &PMHALTps65218IsRegulatorEnabled,      /* isRegulatorEnabled */
    &PMHALTps65218EnableRegulator,         /* regulatorEnable */
    &PMHALTps65218DisableRegulator,        /* regulatorDisable */
    &PMHALTps65218GetRegulatorVoltage,     /* regulatorGetVoltage */
    &PMHALTps65218SetRegulatorVoltage,     /* regulatorSetVoltage */
    &PMHALTps65218GetRegulatorConvVoltage, /* regulatorGetConvVoltage */
};

/* Data structure to describe the regulator for all the regulators. */
const pmhalTps65218RegulatorProp_t  gPmhalTps65218Regulator[
    PMHAL_TPS65218_REGULATOR_MAX] =
{
    /* PMHAL_TPS65218_REGULATOR_DCDC1 */
    {
        850U, 1650U, 1350U, 0x32U, 10U, 25U, PMHAL_TPS65218_REGULATOR_DCDC1,
        PMHAL_TPS65218_RTYPE_DCDC, ENABLE1, DCDC1, SLEW
    },
    /* PMHAL_TPS65218_REGULATOR_DCDC2 */
    {
        850U, 1650U, 1350U, 0x32U, 10U, 25U, PMHAL_TPS65218_REGULATOR_DCDC2,
        PMHAL_TPS65218_RTYPE_DCDC, ENABLE1, DCDC2, SLEW
    },
    /* PMHAL_TPS65218_REGULATOR_DCDC3 */
    {
        900U, 3400U, 1550U, 0x1AU, 25U, 50U, PMHAL_TPS65218_REGULATOR_DCDC3,
        PMHAL_TPS65218_RTYPE_DCDC, ENABLE1, DCDC3, 0x0
    },
    /* PMHAL_TPS65218_REGULATOR_DCDC4 */
    {
        1175U, 3400U, 1550U, 0x0FU, 25U, 50U, PMHAL_TPS65218_REGULATOR_DCDC4,
        PMHAL_TPS65218_RTYPE_DCDC, ENABLE1, DCDC4, 0x0
    },
    /* PMHAL_TPS65218_REGULATOR_LDO1 */
    {
        900U, 3400U, 1550U, 0x1AU, 25U, 50U, PMHAL_TPS65218_REGULATOR_LDO1,
        PMHAL_TPS65218_RTYPE_LDO, ENABLE2, LDO1, 0x0
    }
};

/* Table mapping from SMPS/LDO to Voltage Rails on the device */
pmhalTps65218RegulatorMap_t         gPmhalDefaultTps65218RegulatorTable[
    PMHAL_PRCM_PMIC_REGULATOR_COUNT] =
{
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MPU */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_DCDC2],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_CORE */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_DCDC1],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MMC */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_DCDC4],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_SHV5 */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_DCDC4],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PHY */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_LDO1],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PLL */
    {
        &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_LDO1],
        (uint8_t) PMHAL_TPS65218_I2C_NUM_1
    }
};

/* Pointer to array of pointers describing the mapping from regulators to
 * device voltage rails.
 */
static pmhalTps65218RegulatorMap_t *gPmhalTps65218RegulatorTable =
    gPmhalDefaultTps65218RegulatorTable;

/*
 * PMIC uses different slave addresses to access different register
 *        pages. This table lists the page slave addresses.
 */
const uint8_t gPmhalTps65218SlaveAddressTable[
    PMHAL_TPS65218_SLAVE_ADDR_COUNT] =
{
    PMHAL_TPS65218_SLAVE_ADDR_PAGE0
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

const pmhalPmicOperations_t *PMHALTps65218GetPMICOps(void)
{
    return &gPmhalTps65218Ops;
}

void PMHALTps65218ConfigureRegulatorMap(
    pmhalTps65218RegulatorMapPtr_t regulatorMap)
{
    /* If the regulatorMap provided by the caller is NULL then the default
     * regulator map as present on TI EVMs is used. */
    if (NULL == regulatorMap)
    {
        gPmhalTps65218RegulatorTable = gPmhalDefaultTps65218RegulatorTable;
    }
    else
    {
        gPmhalTps65218RegulatorTable = regulatorMap;
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static pmErrCode_t PMHALTps65218GetProductId(uint32_t *productId)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    chipId = PMHAL_TPS65218_CHIP_ID_INVALID;
    uint8_t     i2cNum;

    if (NULL == productId)
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum =
            gPmhalTps65218RegulatorTable[PMHAL_PRCM_PMIC_REGULATOR_MIN].
            i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * Read the chip ID.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65218ReadPhyAddr(
                i2cNum,
                (uint32_t)
                CHIPID,
                &chipId);
        }

        if (PM_SUCCESS == status)
        {
            *productId = HW_GET_FIELD(chipId, PMHAL_TPS65218_CHIPID_CHIP);
        }
        else
        {
            *productId = PMHAL_TPS65218_CHIP_ID_INVALID;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65218IsPresent(void)
{
    uint32_t    prodId = PMHAL_TPS65218_CHIP_ID_INVALID;
    pmErrCode_t status = PM_SUCCESS;

    /*
     * Check if the TPS65218 PMIC is present. This function
     * ensures that this specific PMIC is in the system by
     * reading and verifying the chip ID.
     * Return success only if the chip ID is returned
     * by the PMIC.
     */

    /* Check the Product ID. */
    status = PMHALTps65218GetProductId(&prodId);
    if (PM_SUCCESS == status)
    {
        if (prodId != PMHAL_TPS65218_CHIP_ID)
        {
            status = PM_PMIC_PRODUCT_ID_INVALID;
        }
    }
    else
    {
        status = PM_PMIC_PRODUCT_ID_INVALID;
    }

    return status;
}

static pmErrCode_t PMHALTps65218GetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                  *voltage)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    voltReg=0;
    uint32_t    voltOffset = 0U;
    const pmhalTps65218RegulatorProp_t *regulator;
    uint8_t     i2cNum;

    if ((NULL == voltage) || (regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65218RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        if ((0x0U != regulator->voltRegAddr) && (PM_SUCCESS == status))
        {
            status = PmhalTps65218ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                              &voltReg);
        }
        else
        {
            status = PM_VOLTAGE_INVALID;
        }

        if (PM_SUCCESS == status)
        {
            voltOffset = HW_GET_FIELD(voltReg, PMHAL_TPS65218_VOLT);

            *voltage = PmhalTps65218VoltOffsetToVoltage(regId, voltOffset);
        }
        else
        {
            *voltage = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65218SetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   timeout)
{
    pmErrCode_t status = PM_SUCCESS;
    const pmhalTps65218RegulatorProp_t *regulator;
    uint8_t     i2cNum;
    uint32_t    password = 0U;
    uint32_t    passwordReg = 0U;
    uint32_t    voltOffset = 0U;
    uint32_t    voltReg = 0U;
    uint32_t    slewReg = 0U;
    uint32_t    i = 0;
    uint32_t    pmicRegs1[0x26] = {0};
    uint32_t    pmicRegs2[0x26] = {0};

    /*
     * Check whether input arguments are correct. Check for the voltage is done
     * later in the function.
     */
    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65218RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /* Convert the given voltage value to the voltage offset. */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65218VoltageToVoltOffset(regId, voltage,
                                                      &voltOffset);
            if ((PM_SUCCESS == status) && (0x0U != regulator->voltRegAddr))
            {
                for (i = 0; i<0x26; i++) {
                    status = PmhalTps65218ReadPhyAddr(i2cNum,
                                                      i,
                                                      &pmicRegs1[i]);
                }

                
                status = PmhalTps65218ReadPhyAddr(i2cNum,
                                                  regulator->voltRegAddr,
                                                  &voltReg);

                /* Write destination register XOR'd with protection
                 * password to PASSWORD register prior to writing new
                 * voltage */
                password = regulator->voltRegAddr ^
                           PMHAL_TPS65218_PROTECTION_PASSWORD;
                HW_SET_FIELD32(passwordReg, PMHAL_TPS65218_PASSWORD_PWRD,
                               password);
                status = PmhalTps65218WritePhyAddr(i2cNum, PASSWORD,
                                                   passwordReg);

                HW_SET_FIELD32(voltReg, PMHAL_TPS65218_VOLT,
                               voltOffset);
                status = PmhalTps65218WritePhyAddr(i2cNum,
                                                   regulator->voltRegAddr,
                                                   voltReg);

                /* If applicable, write GO bit for voltage change to
                 * take effect */
                if (regulator->slewRegAddr)
                {
                    status = PmhalTps65218ReadPhyAddr(i2cNum,
                                                      regulator->slewRegAddr,
                                                      &slewReg);

                    password = regulator->slewRegAddr ^
                               PMHAL_TPS65218_PROTECTION_PASSWORD;
                    HW_SET_FIELD32(passwordReg, PMHAL_TPS65218_PASSWORD_PWRD,
                                   password);
                    status = PmhalTps65218WritePhyAddr(i2cNum, PASSWORD,
                                                       passwordReg);

                    HW_SET_FIELD32(slewReg, PMHAL_TPS65218_SLEW_GO,
                                   ENABLE_SLEW_GO);
                    status = PmhalTps65218WritePhyAddr(i2cNum,
                                                       regulator->slewRegAddr,
                                                       slewReg);
                }
            }
        }

        /*
         * Wait for the voltage ramp up to complete. The caller can perform
         * operations that require the voltage rail to be at the given voltage
         * right after this call. So, ensure the voltage ramps up before
         * returning.
         */
        if (PM_SUCCESS == status)
        {
            uint32_t newV = PmhalTps65218VoltOffsetToVoltage(regId,
                                                             voltOffset);
            uint32_t currVolt = 0U;

            if (PM_TIMEOUT_INFINITE == timeout)
            {
                for (i = 0; i<0x26; i++) {
                    status = PmhalTps65218ReadPhyAddr(i2cNum,
                                                      i,
                                                      &pmicRegs2[i]);
                }

                
                while (newV != currVolt)
                {
                    PMHALTps65218GetRegulatorVoltage(regId, &currVolt);
                }
            }
            else if (PM_TIMEOUT_NOWAIT == timeout)
            {
                ; /* nothing to do here */
            }
            else
            {
                uint32_t timeToWait = timeout;

                while ((newV != currVolt) && (0U != timeToWait))
                {
                    PMHALTps65218GetRegulatorVoltage(regId, &currVolt);
                    timeToWait--;
                }

                if (0U == timeToWait)
                {
                    status = PM_FAIL;
                }
            }
        }
    }

    return status;
}

static uint32_t PMHALTps65218IsRegulatorEnabled(
    pmhalPrcmPmicRegulatorId_t regId)
{
    uint32_t    enabled = 0U;
    pmErrCode_t status  = PM_SUCCESS;
    uint8_t     i2cNum;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);
    }

    if (PM_SUCCESS == status)
    {
        enabled = (uint32_t) PmhalTps65218CheckRegulatorEnabled(regId);
    }

    return enabled;
}

static pmErrCode_t PMHALTps65218EnableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    const pmhalTps65218RegulatorProp_t *regulator;
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    ctrl=0;
    uint32_t    password = 0U;
    uint32_t    passwordReg = 0U;
    uint32_t    enabled = FALSE;
    uint8_t     i2cNum;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65218RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;

        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65218ReadPhyAddr(i2cNum,
                                              regulator->ctrlRegAddr,
                                              &ctrl);
        }

        if (PM_SUCCESS == status)
        {
            /*
             * If the Regulator is disabled, enable by setting the enable bit
             */
            enabled = PmhalTps65218CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                /* Write destination register XOR'd with protection
                 * password to PASSWORD register prior to writing new
                 * voltage */
                password = regulator->ctrlRegAddr ^
                           PMHAL_TPS65218_PROTECTION_PASSWORD;
                HW_SET_FIELD32(passwordReg, PMHAL_TPS65218_PASSWORD_PWRD,
                               password);
                status = PmhalTps65218WritePhyAddr(i2cNum, PASSWORD,
                                                   passwordReg);

                if (PMHAL_TPS65218_RTYPE_DCDC == regulator->type)
                {
                    ctrl = (ctrl &
                        (~(uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(regulator->regId)))
                        | ((((uint32_t) ENABLE_STATE_ON) <<
                          (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_SHIFT(regulator->regId))
                        & (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(regulator->regId));
                    status =
                        PmhalTps65218WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else if (PMHAL_TPS65218_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65218_ENABLEx_LDO1_EN,
                                   ENABLE_STATE_ON);
                    status =
                        PmhalTps65218WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else
                {
                    ; /* Should not reach here */
                }
            }
            enabled = PmhalTps65218CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                status = PM_FAIL;
            }
        }
    }
    return status;
}

static pmErrCode_t PMHALTps65218DisableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    const pmhalTps65218RegulatorProp_t *regulator;
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    password = 0U;
    uint32_t    passwordReg = 0U;
    uint8_t     i2cNum;
    uint32_t    ctrl=0;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65218RegulatorTable[regId].regulatorMap;
        i2cNum = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus. */
        status = PMHALPmicCommConfigure(i2cNum);

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65218ReadPhyAddr(i2cNum,
                                              regulator->ctrlRegAddr,
                                              &ctrl);
        }

        /* If the Regulator is enabled, disable by setting the state to 0U. */
        if (PM_SUCCESS == status)
        {
            if (PmhalTps65218CheckRegulatorEnabled(regId) == TRUE)
            {
                /* Write destination register XOR'd with protection
                 * password to PASSWORD register prior to writing new
                 * voltage */
                password = regulator->ctrlRegAddr ^
                           PMHAL_TPS65218_PROTECTION_PASSWORD;
                HW_SET_FIELD32(passwordReg, PMHAL_TPS65218_PASSWORD_PWRD,
                               password);
                status = PmhalTps65218WritePhyAddr(i2cNum, PASSWORD,
                                                   passwordReg);
                
                if (PMHAL_TPS65218_RTYPE_DCDC == regulator->type)
                {
                    ctrl = (ctrl &
                        (~(uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(regulator->regId)))
                        | ((((uint32_t) ENABLE_STATE_OFF) <<
                          (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_SHIFT(regulator->regId))
                        & (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(regulator->regId));
                    status =
                        PmhalTps65218WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else if (PMHAL_TPS65218_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65218_ENABLEx_LDO1_EN,
                                   ENABLE_STATE_OFF);
                    status =
                        PmhalTps65218WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else
                {
                    ; /* Should not reach here */
                }

                /* Check if the regulator is truly disabled */
                if (TRUE == PmhalTps65218CheckRegulatorEnabled(regId))
                {
                    status = PM_FAIL;
                }
            }
        }
    }

    return status;
}

static uint32_t PMHALTps65218GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    convVoltage = 0U;
    uint32_t    internalVoltOffset = 0U;

    status = PmhalTps65218VoltageToVoltOffset(regId, avsVoltage,
                                              &internalVoltOffset);
    if (PM_SUCCESS == status)
    {
        convVoltage = PmhalTps65218VoltOffsetToVoltage(regId,
                                                       internalVoltOffset);
    }

    return convVoltage;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t PmhalTps65218CheckRegulatorEnabled(
    pmhalPrcmPmicRegulatorId_t regId)
{
    uint32_t enabled = FALSE;
    uint32_t ctrl    = 0U;
    uint8_t  i2cNum;
    
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65218RegulatorProp_t *regulator =
        gPmhalTps65218RegulatorTable[regId].regulatorMap;

    i2cNum = gPmhalTps65218RegulatorTable[regId].i2cInstanceNum;

    /* Read the PMIC ENABLE register bit for the regulator and return the
     * status. */
    if (PM_SUCCESS ==
        PmhalTps65218ReadPhyAddr(i2cNum, regulator->ctrlRegAddr, &ctrl))
    {
        if (PMHAL_TPS65218_RTYPE_DCDC == regulator->type)
        {
            if ((((ctrl) &
                  (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(regulator->regId)) >>
                (uint32_t) PMHAL_TPS65218_ENABLEx_DCx_EN_SHIFT(regulator->regId)) !=
                ENABLE_STATE_OFF)
            {
                enabled = TRUE;
            }
        }
        else if (PMHAL_TPS65218_RTYPE_LDO == regulator->type)
        {
            if (HW_GET_FIELD(ctrl, PMHAL_TPS65218_ENABLEx_LDO1_EN) !=
                ENABLE_STATE_OFF)
            {
                enabled = TRUE;
            }
        }
        else
        {
            ; /* Should not get here */
        }
    }

    return enabled;
}

static pmErrCode_t PmhalTps65218VoltageToVoltOffset(
    pmhalPrcmPmicRegulatorId_t  regId,
    uint32_t                    voltage,
    uint32_t                   *voltOffset)
{
    pmErrCode_t status = PM_SUCCESS;

    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65218RegulatorProp_t *regulator =
        gPmhalTps65218RegulatorTable[regId].regulatorMap;

    if (voltOffset == NULL)
    {
        status = PM_BADARGS;
    }
    else
    {
        if (voltage <= regulator->stepVoltTransition)
        {
            *voltOffset = (voltage - regulator->minVolt) /
                          regulator->stepVoltLow;
        }
        else
        {
            *voltOffset = regulator->stepVoltTransBits +
                 ((voltage - regulator->stepVoltTransition) /
                  regulator->stepVoltHigh);
        }
    }

    return status;
}

static uint32_t PmhalTps65218VoltOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltOffset)
{
    uint32_t mv = 0U;

    /* regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function. */
    const pmhalTps65218RegulatorProp_t *regulator =
        gPmhalTps65218RegulatorTable[regId].regulatorMap;

    if (voltOffset < regulator->stepVoltTransBits)
    {
        mv = regulator->minVolt + (voltOffset * regulator->stepVoltLow);
    }
    else
    {
        mv = regulator->stepVoltTransition +
             ((voltOffset - regulator->stepVoltTransBits) *
              regulator->stepVoltHigh);
    }

    return mv;
}

static uint8_t PmhalTps65218PhytoSlaveAddr(uint32_t phyAddr)
{
    uint32_t page      = PmhalTps65218PhyToPage(phyAddr);
    uint8_t  slaveAddr = (uint8_t) PMHAL_TPS65218_SLAVE_ADDR_INVALID;

    if (page < PMHAL_TPS65218_SLAVE_ADDR_COUNT)
    {
        slaveAddr = gPmhalTps65218SlaveAddressTable[page];
    }

    return slaveAddr;
}

static pmErrCode_t PmhalTps65218ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                             uint32_t *value)
{
    uint8_t     slaveAddr;
    uint8_t     regAddr;
    pmErrCode_t status;
    uint8_t     byte;

    if (NULL == value)
    {
        status = PM_BADARGS;
    }
    else
    {
        byte      = (uint8_t) *value;
        slaveAddr = PmhalTps65218PhytoSlaveAddr(phyAddr);
        regAddr   = PmhalTps65218PhyToPageOffset(phyAddr);
        status    = PMHALPmicCommReadByte(i2cNum, slaveAddr, regAddr, &byte);
        *value    = byte;
    }

    return status;
}

static pmErrCode_t PmhalTps65218WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                              uint32_t value)
{
    uint8_t     slaveAddr;
    uint8_t     regAddr;
    uint8_t     byte;
    pmErrCode_t status;

    byte      = (uint8_t) value;
    slaveAddr = PmhalTps65218PhytoSlaveAddr(phyAddr);
    regAddr   = PmhalTps65218PhyToPageOffset(phyAddr);
    status    = PMHALPmicCommWriteByte(i2cNum, slaveAddr, regAddr, byte);

    return status;
}

static uint8_t PmhalTps65218PhyToPageOffset(uint32_t phyAddr)
{
    return (uint8_t) phyAddr;
}

static uint32_t PmhalTps65218PhyToPage(uint32_t phyAddr)
{
    return ((phyAddr) >> 8U);
}

