/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2014
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
 *  \file        pmhal_tps65917.c
 *
 *  \brief       Power Management IC - TPS65917 specific API implementation.
 *               APIs are exported by using function pointers.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/csl/hw_types.h>
#include "pm_types.h"
#include "pm_utils.h"
#include "pmhal_pmic.h"
#include <ti/drv/pm/include/pmic/pmhal_tps65917.h>
#include "pmhal_pmicComm.h"
#include "pmhal_prcm.h"

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
 * \brief   Check if the TPS65917 PMIC is present. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   void
 *
 * \return  PM_SUCCESS - TPS65917 PMIC is present.
 *          PM_PMHAL_PMIC_VENDOR_ID_INVALID - PMIC vendor id doesn't match the
 *                                     expected value.
 *          PM_PMHAL_PMIC_PRODUCT_ID_INVALID - PMIC product id doesn't match the
 *                                      expected value.
 */
static pmErrCode_t PMHALTps65917IsPresent(void);

/**
 * \brief   Get the TPS65917 PMIC chip revision. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   void
 *
 * \return  revString - The revision. "INVALID" is returned in case of error.
 */
static const char *PMHALTps65917GetRevision(void);

/**
 * \brief   Return the PMIC Vendor ID. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   vendorId    The Vendor ID is populated in this parameter.
 *
 * \return  status      PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65917GetVendorId(uint32_t *vendorId);

/**
 * \brief   Return the PMIC Product ID. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   productId   The Product ID is populated in this parameter.
 *
 * \return  status      PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65917GetProductId(uint32_t *productId);

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
static pmErrCode_t PMHALTps65917GetRegulatorVoltage(
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
static pmErrCode_t PMHALTps65917SetRegulatorVoltage(
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
static uint32_t    PMHALTps65917IsRegulatorEnabled(
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
static pmErrCode_t PMHALTps65917EnableRegulator(
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
static pmErrCode_t PMHALTps65917DisableRegulator(
    pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief   Return the Regulator Step voltage size. This is required by the
 *          voltage manager to understand the opp for the given voltage set for
 *          the given voltage rail.
 *
 * \param   regId       Regulator ID. Refer #pmhalPrcmPmicRegulatorId_t for
 *                      details.
 * \param   avsVoltage  AVS voltage which is to be converted to regulator
 *                      voltage
 *
 * \return  convVolt    The voltage that would be supplied by the regulator if
 *                      the AVS voltage is given to the API.
 *                      NOTE: This API does not program the PMIC. It just
 *                      returns the calculated value of AVS voltage converted to
 *                      PMIC voltage based on the PMIC voltage resolution.
 */
static uint32_t PMHALTps65917GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage);

#ifdef __cplusplus
}
#endif

/**
 * \brief Given voltage in mV and range, return the VSEL offset
 *
 * \param   regId   Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   voltage Voltage in mV.
 * \param   range   Range of the VSEL voltage.
 * \param   vsel    VSEL value returned.
 *
 * \return  status
 */
static pmErrCode_t PmhalTps65917VoltageToVselOffset(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   range,
    uint32_t                  *vsel);

/**
 * \brief Given VSEL offset convert it to voltage in mV and return.
 *
 * \param   regId   Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   range   Range of the VSEL voltage.
 * \param   vsel    VSEL value returned.
 *
 * \return  voltage Voltage in mV.
 */
static uint32_t    PmhalTps65917VselOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   vsel,
    uint32_t                   range);

/**
 * \brief  Read the register value at the given physical address.
 *
 * \param   i2cNum      I2C Instance number to which the PMIC is connected
 * \param   phyAddr     Address to be read.
 * \param   value       Returns the value read.
 *
 * \return  status      Return PM_SUCCESS if read is successful. Else returns
 *                      PM_FAIL.
 */
static pmErrCode_t PmhalTps65917ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                            uint32_t *value);

/**
 * \brief  Write the given register value at the given physical address.
 *
 * \param   i2cNum      I2C Instance number to which the PMIC is connected
 * \param   phyAddr     Address to be written to.
 * \param   value       Returns the value to be written.
 *
 * \return Return success or failure.
 */
static pmErrCode_t PmhalTps65917WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                             uint32_t value);

/**
 * \brief Check if the given product ID is the ID of a supported PMIC.
 *
 * \param       prodId  Product ID to be checked.
 *
 * \return true if the product ID is valid; false otherwise
 */
static uint32_t    PmhalTps65917IsProductIdValid(uint32_t prodId);

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
static uint32_t PmhalTps65917CheckRegulatorEnabled
    (pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief Function to convert the physical address to the slave address.
 *
 * \param   phyAddr     Physical Address
 * \return  slaveAddr   Slave Address
 */
static uint8_t PmhalTps65917PhytoSlaveAddr(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page offset
 */
static inline uint8_t PmhalTps65917PhyToPageOffset(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page Number
 */
static inline uint32_t PmhalTps65917PhyToPage(uint32_t phyAddr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Power Management IC device callbacks. */
const pmhalPmicOperations_t         gPmhalTps65917Ops =
{
    &PMHALTps65917IsPresent,               /* isPresent */
    &PMHALTps65917GetRevision,             /* getRevision */
    &PMHALTps65917GetVendorId,             /* getVendorId */
    &PMHALTps65917GetProductId,            /* getProductId */
    &PMHALTps65917IsRegulatorEnabled,      /* isRegulatorEnabled */
    &PMHALTps65917EnableRegulator,         /* regulatorEnable */
    &PMHALTps65917DisableRegulator,        /* regulatorDisable */
    &PMHALTps65917GetRegulatorVoltage,     /* regulatorGetVoltage */
    &PMHALTps65917SetRegulatorVoltage,     /* regulatorSetVoltage */
    &PMHALTps65917GetRegulatorConvVoltage, /* regulatorGetConvVoltage */
};

/* Data structure to describe the regulator for all the regulators. */
const pmhalTps65917RegulatorProp_t  gPmhalTps65917Regulator[
    PMHAL_TPS65917_REGULATOR_MAX] =
{
    /* PMHAL_TPS65917_REGULATOR_SMPS1 */
    {
        500U, 1650U, 10U, PMHAL_TPS65917_RTYPE_SMPS, 2500U, 0x06U, 0x79U,
        PMHAL_TPS65917_SMPS1_CTRL, PMHAL_TPS65917_SMPS1_VOLTAGE,
        PMHAL_TPS65917_SMPS1_FORCE,
    },
    /* PMHAL_TPS65917_REGULATOR_SMPS2 */
    {
        500U, 1650U, 10U, PMHAL_TPS65917_RTYPE_SMPS, 2500U, 0x06U, 0x79U,
        PMHAL_TPS65917_SMPS2_CTRL, PMHAL_TPS65917_SMPS2_VOLTAGE,
        PMHAL_TPS65917_SMPS2_FORCE
    },
    /* PMHAL_TPS65917_REGULATOR_SMPS3 */
    {
        500U, 1650U, 10U, PMHAL_TPS65917_RTYPE_SMPS, 2500U, 0x06U, 0x79U,
        PMHAL_TPS65917_SMPS3_CTRL, PMHAL_TPS65917_SMPS3_VOLTAGE,
        PMHAL_TPS65917_SMPS3_FORCE
    },
    /* PMHAL_TPS65917_REGULATOR_SMPS4 */
    {
        500U, 1650U, 10U, PMHAL_TPS65917_RTYPE_SMPS, 2500U, 0x06U, 0x79U,
        PMHAL_TPS65917_SMPS4_CTRL, PMHAL_TPS65917_SMPS4_VOLTAGE,
        0x0U
    },
    /* PMHAL_TPS65917_REGULATOR_SMPS5 */
    {
        500U, 1650U, 10U, PMHAL_TPS65917_RTYPE_SMPS, 2500U, 0x06U, 0x79U,
        PMHAL_TPS65917_SMPS5_CTRL, PMHAL_TPS65917_SMPS5_VOLTAGE,
        0x0U
    },
    /*  PMHAL_TPS65917_REGULATOR_LDO1 */
    {
        900U, 3300U, 50U, PMHAL_TPS65917_RTYPE_LDO, 2500U, 0x01U, 0x31U,
        PMHAL_TPS65917_LDO1_CTRL, PMHAL_TPS65917_LDO1_VOLTAGE,
        0x0U
    },
    /*  PMHAL_TPS65917_REGULATOR_LDO2 */
    {
        900U, 3300U, 50U, PMHAL_TPS65917_RTYPE_LDO, 2500U, 0x01U, 0x31U,
        PMHAL_TPS65917_LDO2_CTRL, PMHAL_TPS65917_LDO2_VOLTAGE,
        0x0U
    },
    /*  PMHAL_TPS65917_REGULATOR_LDO3 */
    {
        900U, 3300U, 50U, PMHAL_TPS65917_RTYPE_LDO, 2500U, 0x01U, 0x31U,
        PMHAL_TPS65917_LDO3_CTRL, PMHAL_TPS65917_LDO3_VOLTAGE,
        0x0U
    },
    /*  PMHAL_TPS65917_REGULATOR_LDO4 */
    {
        900U, 3300U, 50U, PMHAL_TPS65917_RTYPE_LDO, 2500U, 0x01U, 0x31U,
        PMHAL_TPS65917_LDO4_CTRL, PMHAL_TPS65917_LDO4_VOLTAGE,
        0x0U
    },
    /*  PMHAL_TPS65917_REGULATOR_LDO5 */
    {
        900U, 3300U, 50U, PMHAL_TPS65917_RTYPE_LDO, 2500U, 0x01U, 0x31U,
        PMHAL_TPS65917_LDO5_CTRL, PMHAL_TPS65917_LDO5_VOLTAGE,
        0x0U
    }
};

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
/* Table mapping from SMPS/LDO to Voltage Rails on the device */
pmhalTps65917RegulatorMap_t         gPmhalDefaultTps65917RegulatorTable[
    PMHAL_PRCM_PMIC_REGULATOR_COUNT] =
{
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_CORE */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS2],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_DSPEVE */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS1],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PHY */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS3],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_DDR_DV */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS4],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PLL */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_LDO5],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    }
};
#else
/* Table mapping from SMPS/LDO to Voltage Rails on the device */
pmhalTps65917RegulatorMap_t         gPmhalDefaultTps65917RegulatorTable[
    PMHAL_PRCM_PMIC_REGULATOR_COUNT] =
{
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MPU */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS1],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_CORE */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS2],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_IVA */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS3],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_DSPEVE */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS3],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_GPU */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_SMPS3],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MMC13V3 */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_LDO1],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_SHV5. Takes it from
     * 3.3 V input */
    {
        NULL,
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PHY */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_LDO3],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PLL */
    {
        &gPmhalTps65917Regulator[PMHAL_TPS65917_REGULATOR_LDO5],
        (uint8_t) PMHAL_TPS65917_I2C_NUM_1
    }
};
#endif

/* Pointer to array of pointers describing the mapping from regulators to
 * device voltage rails.
 */
static pmhalTps65917RegulatorMap_t *gPmhalTps65917RegulatorTable =
    gPmhalDefaultTps65917RegulatorTable;

/*
 * PMIC uses different slave addresses to access different register
 *        pages. This table lists the page slave addresses.
 */
const uint8_t gPmhalTps65917SlaveAddressTable[
    PMHAL_TPS65917_SLAVE_ADDR_COUNT] =
{
    PMHAL_TPS65917_SLAVE_ADDR_PAGE0,
    PMHAL_TPS65917_SLAVE_ADDR_PAGE1,
    PMHAL_TPS65917_SLAVE_ADDR_PAGE2,
    PMHAL_TPS65917_SLAVE_ADDR_PAGE3,
    PMHAL_TPS65917_SLAVE_ADDR_PAGE4
};

/* Chip Revisions of the PMIC. */
const char   *gPmhalTps65917RevStrings[PMHAL_PMIC_MAX_REV] =
{"CS1.0", "CS2.0", "CS2.1", "CS2.2"};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

const pmhalPmicOperations_t *PMHALTps65917GetPMICOps(void)
{
    return &gPmhalTps65917Ops;
}

void PMHALTps65917ConfigureRegulatorMap(
    pmhalTps65917RegulatorMapPtr_t regulatorMap)
{
    /* If the regulatorMap provided by the caller is NULL then the default
     * regulator map as present on TI EVMs is used.
     */
    if (NULL == regulatorMap)
    {
        gPmhalTps65917RegulatorTable = gPmhalDefaultTps65917RegulatorTable;
    }
    else
    {
        gPmhalTps65917RegulatorTable = regulatorMap;
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static pmErrCode_t PMHALTps65917GetVendorId(uint32_t *vendorId)
{
    uint32_t    lsb    = 0U;
    uint32_t    msb    = 0U;
    uint32_t    value  = 0U;
    pmErrCode_t status = PM_SUCCESS;
    uint8_t     i2cNum =
        gPmhalTps65917RegulatorTable[PMHAL_PRCM_PMIC_REGULATOR_MIN].
        i2cInstanceNum;

    if (NULL == vendorId)
    {
        status = PM_BADARGS;
    }
    else
    {
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * Check the Vendor ID.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65917ReadPhyAddr(
                i2cNum,
                (uint32_t)
                PMHAL_TPS65917_PHYADDR_VENDOR_ID_LSB,
                &value);
            lsb = value & 0xFFU;
        }

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65917ReadPhyAddr(
                i2cNum,
                (uint32_t)
                PMHAL_TPS65917_PHYADDR_VENDOR_ID_MSB,
                &value);
            msb = value & 0xFFU;
        }

        if (PM_SUCCESS == status)
        {
            *vendorId = ((uint32_t) msb << 8U) | lsb;
        }
        else
        {
            *vendorId = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65917GetProductId(uint32_t *productId)
{
    uint32_t    lsb    = 0U, msb = 0U;
    pmErrCode_t status = PM_SUCCESS;
    uint8_t     i2cNum =
        gPmhalTps65917RegulatorTable[PMHAL_PRCM_PMIC_REGULATOR_MIN].
        i2cInstanceNum;

    if (NULL == productId)
    {
        status = PM_BADARGS;
    }
    else
    {
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * Read the LSB and MSB of the product ID.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65917ReadPhyAddr(
                i2cNum,
                (uint32_t)
                PMHAL_TPS65917_PHYADDR_PRODUCT_ID_LSB,
                &lsb);
        }

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65917ReadPhyAddr(
                i2cNum,
                (uint32_t)
                PMHAL_TPS65917_PHYADDR_PRODUCT_ID_MSB, &msb);
        }

        if (PM_SUCCESS == status)
        {
            *productId = ((uint32_t) msb << 8U) | lsb;
        }
        else
        {
            *productId = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65917IsPresent(void)
{
    uint32_t    prodId = 0U, vendorId = 0U;
    pmErrCode_t status = PM_SUCCESS;

    /*
     * Check if the TPS65917 PMIC is present. This function
     * ensures that this specific PMIC is in the system by
     * reading and verifying the vendor ID and product ID.
     * Return success only if the vendor ID and product ID
     * matches the expected value.
     */

    /* Check the Vendor ID. */
    status = PMHALTps65917GetVendorId(&vendorId);

    /* Check the Product ID. */
    if (PMHAL_TPS65917_VENDOR_ID == vendorId)
    {
        status = PMHALTps65917GetProductId(&prodId);
        if (PM_SUCCESS == status)
        {
            if (PmhalTps65917IsProductIdValid(prodId) == FALSE)
            {
                status = PM_PMIC_PRODUCT_ID_INVALID;
            }
        }
    }
    else
    {
        status = PM_PMIC_VENDOR_ID_INVALID;
    }

    return status;
}

static const char *PMHALTps65917GetRevision(void)
{
    uint32_t    rev=0;
    const char *revString = "INVALID";
    pmErrCode_t status    = PM_SUCCESS;
    uint8_t     i2cNum    =
        gPmhalTps65917RegulatorTable[PMHAL_PRCM_PMIC_REGULATOR_MIN].
        i2cInstanceNum;

    /*
     * Configure and enable PMIC communication bus.
     */
    status = PMHALPmicCommConfigure(i2cNum);

    /*
     * Get the Chip Revision ID.
     */
    if (PM_SUCCESS == status)
    {
        status = PmhalTps65917ReadPhyAddr(
            i2cNum,
            (uint32_t)
            PMHAL_TPS65917_PHYADDR_CHIP_REVISION_ID, &rev);
    }

    if (PM_SUCCESS == status)
    {
        rev = HW_GET_FIELD(rev, PMHAL_TPS65917_CHIP_REVISION_ID);
        if (rev < PMHAL_PMIC_MAX_REV)
        {
            revString = gPmhalTps65917RevStrings[rev];
        }
    }

    return revString;
}

static pmErrCode_t PMHALTps65917GetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                  *voltage)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    ctrl, force, volt;
    uint32_t    forceCmd = 0U;
    uint32_t    range    = 0U;
    uint32_t    vsel     = 0U;
    const pmhalTps65917RegulatorProp_t *regulator;
    uint8_t     i2cNum;

    if ((NULL == voltage) || (regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum    = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;
        regulator = gPmhalTps65917RegulatorTable[regId].regulatorMap;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        if ((TRUE == PmhalTps65917CheckRegulatorEnabled(regId)) &&
            (PM_SUCCESS == status))
        {
            uint32_t ctrlRoofEn = 0U;

            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->ctrlRegAddr,
                                              &ctrl);

            /*
             * If CTRL.ROOF_FLOOR_EN bit is 0x0, the voltage is controlled by
             * the FORCE.CMD bit. If it is 0x1, the voltage is controlled by the
             * device resource pins. Since we want to set the voltage, proceed
             * only when the voltage is controlled by FORCE.CMD bit. So, return
             * error if CTRL.ROOF_FLOOR_EN bit is set to 1.
             *
             * Note: Note that we can override this bit to 0x0 and proceed but
             * we choose not to do this. The OTP will set it to 0x0 and if this
             * default value has been overwritten, let us not assume that we can
             * override it.
             */
            if (PM_SUCCESS == status)
            {
                ctrlRoofEn = HW_GET_FIELD(
                    ctrl,
                    PMHAL_TPS65917_SMPSxx_CTRL_ROOF_FLOOR_EN);

                if ((PMHAL_TPS65917_RTYPE_SMPS == regulator->type) &&
                    (1U == ctrlRoofEn))
                {
                    status = PM_REGULATOR_STATE_INVALID;
                }
            }
        }

        /*
         * If the regulator has the force register and if the FORCE.CMD bit is
         * set to 0x0, the pmic uses the voltage value in the FORCE.VSEL
         * register bits. Otherwise, the pmic uses the voltage value in the
         * VOLTAGE.VSEL bits. Read the FORCE.CMD bit to choose the right
         * register to program.
         */
        if ((0x0U != regulator->forceRegAddr) && (PM_SUCCESS == status))
        {
            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->forceRegAddr,
                                              &force);

            if (PM_SUCCESS == status)
            {
                forceCmd = HW_GET_FIELD(force,
                                        PMHAL_TPS65917_SMPSxx_FORCE_CMD);
            }
        }

        /*
         * Read the VOLTAGE register and determine the range. The range bit
         * determines the voltage range:
         *   0x0 - 0U.5V to 1.65V
         *   0x1 - 1.0V to 3.3V
         * Note that this function reads the range and uses it to calculate the
         * right VSEL offset for the given voltage. It wont' change the range
         * value to suit the given voltage. If the range bit doesn't support
         * the input voltage an error is returned.
         */
        if ((PM_SUCCESS == status) &&
            (PMHAL_TPS65917_RTYPE_SMPS == regulator->type))
        {
            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                              &volt);
            if (PM_SUCCESS == status)
            {
                range = HW_GET_FIELD(volt,
                                     PMHAL_TPS65917_SMPSxx_VOLTAGE_RANGE);
            }
        }

        /*
         * If FORCE.CMD is 0x0, read the VSEL value from FORCE.VSEL bits.
         */
        if (PM_SUCCESS == status)
        {
            if ((0x0U != regulator->forceRegAddr) && (0x0U == forceCmd))
            {
                status =
                    PmhalTps65917ReadPhyAddr(i2cNum, regulator->forceRegAddr,
                                             &force);
                vsel = HW_GET_FIELD(force, PMHAL_TPS65917_SMPSxx_FORCE_VSEL);
            }
            /*
             * If FORCE.CMD is 0x1, read the VSEL value to VOLTAGE.VSEL bits.
             */
            else
            {
                status =
                    PmhalTps65917ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                             &volt);
                if (PMHAL_TPS65917_RTYPE_SMPS == regulator->type)
                {
                    vsel = HW_GET_FIELD(volt,
                                        PMHAL_TPS65917_SMPSxx_VOLTAGE_VSEL);
                }
                else
                {
                    vsel = HW_GET_FIELD(volt,
                                        PMHAL_TPS65917_LDOxx_VOLTAGE_VSEL);
                }
            }
        }

        if (PM_SUCCESS == status)
        {
            *voltage = PmhalTps65917VselOffsetToVoltage(regId, vsel, range);
        }
        else
        {
            *voltage = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65917SetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   timeout)
{
    pmErrCode_t status   = PM_SUCCESS;
    uint32_t    ctrl     = 0U;
    uint32_t    force    = 0U, volt = 0U;
    uint32_t    forceCmd = 0U;
    uint32_t    range    = 0U;
    uint32_t    vsel     = 0U;
    const pmhalTps65917RegulatorProp_t *regulator;
    uint8_t     i2cNum;
    uint32_t    currVolt = 0U;

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
        i2cNum    = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;
        regulator = gPmhalTps65917RegulatorTable[regId].regulatorMap;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        if (TRUE == PmhalTps65917CheckRegulatorEnabled(regId))
        {
            uint32_t ctrlRoofEn = 0U;

            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->ctrlRegAddr,
                                              &ctrl);

            /*
             * If CTRL.ROOF_FLOOR_EN bit is 0x0, the voltage is controlled by
             * the FORCE.CMD bit. If it is 0x1, the voltage is controlled by the
             * device resource pins. Since we want to set the voltage, proceed
             * only when the voltage is controlled by FORCE.CMD bit. So, return
             * error if CTRL.ROOF_FLOOR_EN bit is set to 1.
             *
             * Note: Note that we can override this bit to 0x0 and proceed but
             * we choose not to do this. The OTP will set it to 0x0 and if this
             * default value has been overwritten, let us not assume that we can
             * override it.
             */
            if (PM_SUCCESS == status)
            {
                ctrlRoofEn = HW_GET_FIELD(
                    ctrl,
                    PMHAL_TPS65917_SMPSxx_CTRL_ROOF_FLOOR_EN);

                if ((PMHAL_TPS65917_RTYPE_SMPS == regulator->type) &&
                    (1U == ctrlRoofEn))
                {
                    status = PM_REGULATOR_STATE_INVALID;
                }
            }
        }

        /*
         * If the FORCE.CMD bit is set to 0x0, the PMIC uses the voltage value
         * in the FORCE.VSEL register bits. Otherwise, the PMIC uses the voltage
         * value in the VOLTAGE.VSEL bits. Read the FORCE.CMD bit to choose
         * the right register to program.
         */
        if ((0x0U != regulator->forceRegAddr) && (PM_SUCCESS == status))
        {
            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->forceRegAddr,
                                              &force);
            if (PM_SUCCESS == status)
            {
                forceCmd = HW_GET_FIELD(force,
                                        PMHAL_TPS65917_SMPSxx_FORCE_CMD);
            }
        }

        /*
         * Read the VOLTAGE register and determine the range. The range bit
         * determines the voltage range:
         *   0x0 - 0.5V to 1.65V
         *   0x1 - 1.0V to 3.3V
         * Note that this function reads the range and uses it to calculate the
         * right VSEL offset for the given voltage. If the range bit doesn't
         * support the input voltage the range is appropriately updated.
         */
        range = 0U;
        if ((PM_SUCCESS == status) &&
            (PMHAL_TPS65917_RTYPE_SMPS == regulator->type))
        {
            status = PmhalTps65917ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                              &volt);
            if (PM_SUCCESS == status)
            {
                range = HW_GET_FIELD(volt, PMHAL_TPS65917_SMPSxx_VOLTAGE_RANGE);
                /* Apply correction to the range value if it is out of range */
                if ((voltage < 1000U) && (range == 1U))
                {
                    range = 0U;
                }
                else if ((voltage > 1650U) && (range == 0U))
                {
                    range = 1U;
                }
                else
                {
                    ; /* Do nothing */
                }
            }
        }

        /*
         * Convert the given voltage value to the VSEL offset; use the range
         * read above to convert the offset.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65917VoltageToVselOffset(regId, voltage, range,
                                                      &vsel);
            if (PM_SUCCESS == status)
            {
                /*
                 * If FORCE.CMD is 0x0, write the VSEL value to FORCE.VSEL bits.
                 */
                if ((0x0U != regulator->forceRegAddr) && (0x0U == forceCmd))
                {
                    HW_SET_FIELD32(force, PMHAL_TPS65917_SMPSxx_FORCE_VSEL,
                                   vsel);
                    status =
                        PmhalTps65917WritePhyAddr(i2cNum,
                                                  regulator->forceRegAddr,
                                                  force);
                }
                /*
                 * If FORCE.CMD is 0x1, write the VSEL value to VOLTAGE.VSEL
                 * bits.
                 */
                else if (PMHAL_TPS65917_RTYPE_SMPS == regulator->type)
                {
                    HW_SET_FIELD32(volt, PMHAL_TPS65917_SMPSxx_VOLTAGE_VSEL,
                                   vsel);
                    HW_SET_FIELD32(volt, PMHAL_TPS65917_SMPSxx_VOLTAGE_RANGE,
                                   range);
                    status =
                        PmhalTps65917WritePhyAddr(i2cNum,
                                                  regulator->voltRegAddr,
                                                  volt);
                }
                else if (PMHAL_TPS65917_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(volt, PMHAL_TPS65917_LDOxx_VOLTAGE_VSEL,
                                   vsel);
                    status =
                        PmhalTps65917WritePhyAddr(i2cNum,
                                                  regulator->voltRegAddr,
                                                  volt);
                }
                else
                {
                    ; /* should not get here */
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
            uint32_t newV = PmhalTps65917VselOffsetToVoltage(regId, vsel,
                                                             range);

            if (PM_TIMEOUT_INFINITE == timeout)
            {
                while (newV != currVolt)
                {
                    PMHALTps65917GetRegulatorVoltage(regId, &currVolt);
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
                    PMHALTps65917GetRegulatorVoltage(regId, &currVolt);
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

static uint32_t PMHALTps65917IsRegulatorEnabled(
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
        i2cNum = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);
    }

    if (PM_SUCCESS == status)
    {
        enabled = (uint32_t) PmhalTps65917CheckRegulatorEnabled(regId);
    }

    return enabled;
}

static pmErrCode_t PMHALTps65917EnableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    pmErrCode_t status = PM_SUCCESS;
    const pmhalTps65917RegulatorProp_t *regulator;
    uint32_t    value   = 0U;
    uint32_t    enabled = FALSE;
    uint8_t     i2cNum;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum    = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;
        regulator = gPmhalTps65917RegulatorTable[regId].regulatorMap;

        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);
        if (PM_SUCCESS == status)
        {
            /*
             * If the Regulator is disabled, enable by setting the MODE_ACTIVE
             * and MODE_SLEEP to 0x01 (Forced PWM)
             */
            enabled = PmhalTps65917CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                if (PMHAL_TPS65917_RTYPE_SMPS == regulator->type)
                {
                    HW_SET_FIELD32(
                        value,
                        PMHAL_TPS65917_SMPSxx_CTRL_MODE_ACTIVE,
                        0x01U);
                    HW_SET_FIELD32(value,
                                   PMHAL_TPS65917_SMPSxx_CTRL_MODE_SLEEP,
                                   0x01U);
                    status =
                        PmhalTps65917WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  value);
                }
                else if (PMHAL_TPS65917_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(value, PMHAL_TPS65917_LDOxx_CTRL_MODE_ACTIVE,
                                   0x01U);
                    HW_SET_FIELD32(value, PMHAL_TPS65917_LDOxx_CTRL_MODE_SLEEP,
                                   0x01U);
                    status =
                        PmhalTps65917WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  value);
                }
                else
                {
                    ; /* Should not reach here */
                }
            }
            enabled = PmhalTps65917CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                status = PM_FAIL;
            }
        }
    }
    return status;
}

static pmErrCode_t PMHALTps65917DisableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    pmErrCode_t status = PM_SUCCESS;
    uint8_t     i2cNum;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus. */
        status = PMHALPmicCommConfigure(i2cNum);

        /* If the Regulator is enabled, disable by setting the voltage to 0U. */
        if (PM_SUCCESS == status)
        {
            if (TRUE == PmhalTps65917CheckRegulatorEnabled(regId))
            {
                /*
                 * Setting the SMPS Voltage to 0U effectively disables the
                 * Regulator. The same is the case for LDO as well.
                 */
                PMHALTps65917SetRegulatorVoltage(regId, (uint32_t) 0U,
                                                 PM_TIMEOUT_INFINITE);

                /* Check if the regulator is truly disabled */
                if (TRUE == PmhalTps65917CheckRegulatorEnabled(regId))
                {
                    status = PM_FAIL;
                }
            }
        }
    }

    return status;
}

static uint32_t PMHALTps65917GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage)
{
    pmErrCode_t status       = PM_SUCCESS;
    uint32_t    convVoltage  = 0U;
    uint32_t    internalVsel = 0U;

    status = PmhalTps65917VoltageToVselOffset(regId, avsVoltage, (uint32_t) 0U,
                                              &internalVsel);
    if (PM_SUCCESS == status)
    {
        convVoltage = PmhalTps65917VselOffsetToVoltage(regId,
                                                       internalVsel,
                                                       (uint32_t) 0U);
    }

    return convVoltage;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t PmhalTps65917CheckRegulatorEnabled(
    pmhalPrcmPmicRegulatorId_t regId)
{
    uint32_t enabled = FALSE;
    uint32_t ctrl    = 0U;
    uint8_t  i2cNum;
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65917RegulatorProp_t *regulator =
        gPmhalTps65917RegulatorTable[regId].regulatorMap;

    i2cNum = gPmhalTps65917RegulatorTable[regId].i2cInstanceNum;

    /* Read the regulator CTRL_STATUS and return the status. */
    if (PM_SUCCESS ==
        PmhalTps65917ReadPhyAddr(i2cNum, regulator->ctrlRegAddr, &ctrl))
    {
        /*
         * Check if the regulator type is SMPS or LDO. Based on this check if
         * the regulator is enabled or not.
         */
        if (PMHAL_TPS65917_RTYPE_SMPS == regulator->type)
        {
            if (HW_GET_FIELD(ctrl,
                             PMHAL_TPS65917_SMPSxx_CTRL_STATUS) !=
                CTRL_STATUS_OFF)
            {
                enabled = TRUE;
            }
        }
        else if (PMHAL_TPS65917_RTYPE_LDO == regulator->type)
        {
            if (HW_GET_FIELD(ctrl,
                             PMHAL_TPS65917_LDOxx_CTRL_STATUS) !=
                CTRL_STATUS_OFF)
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

static pmErrCode_t PmhalTps65917VoltageToVselOffset(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   range,
    uint32_t                  *vsel)
{
    pmErrCode_t status = PM_SUCCESS;
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65917RegulatorProp_t *regulator =
        gPmhalTps65917RegulatorTable[regId].regulatorMap;

    if (NULL == vsel)
    {
        status = PM_BADARGS;
    }
    else
    {
        /* Ensure range is 0U or 1. */
        range = range & 0x1U;

        /*
         * It is easier to operate on the non-range-adjusted voltage as we
         * keep the step, min/max volts in non-range-adjusted voltages.
         * Divide by the voltage by 2 if range is 0x1.
         */
        voltage = voltage >> range;

        if (0U == voltage)
        {
            *vsel = 0U;
        }
        else if (voltage > regulator->maxVolt)
        {
            *vsel  = regulator->maxVoltVsel;
            status = PM_BADARGS;
        }
        else
        {
            /* The vsel is always chosen to be greater than equal to the AVS
             * voltage.
             */
            *vsel = (((voltage - regulator->minVolt) +
                      (regulator->stepVolt - 1U)) /
                     regulator->stepVolt) +
                    regulator->minVoltVsel;
        }
    }

    return status;
}

static uint32_t PmhalTps65917VselOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t vsel, uint32_t range)
{
    uint32_t mv;
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65917RegulatorProp_t *regulator =
        gPmhalTps65917RegulatorTable[regId].regulatorMap;

    /* Ensure range is 0 or 1. */
    range = range & 0x1U;

    if (0U == vsel)
    {
        mv = 0U;
    }
    else if (vsel <= regulator->minVoltVsel)
    {
        mv = regulator->minVolt;
    }
    else if (vsel >= regulator->maxVoltVsel)
    {
        mv = regulator->maxVolt;
    }
    else
    {
        mv = regulator->minVolt +
             (regulator->stepVolt * (vsel - regulator->minVoltVsel));
    }

    /* Apply range multiplier. */
    mv = mv << range;

    return mv;
}

static uint8_t PmhalTps65917PhytoSlaveAddr(uint32_t phyAddr)
{
    uint32_t page      = PmhalTps65917PhyToPage(phyAddr);
    uint8_t  slaveAddr = (uint8_t) PMHAL_TPS65917_SLAVE_ADDR_INVALID;

    if (page < PMHAL_TPS65917_SLAVE_ADDR_COUNT)
    {
        slaveAddr = gPmhalTps65917SlaveAddressTable[page];
    }

    return slaveAddr;
}

static pmErrCode_t PmhalTps65917ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
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
        slaveAddr = PmhalTps65917PhytoSlaveAddr(phyAddr);
        regAddr   = PmhalTps65917PhyToPageOffset(phyAddr);
        status    = PMHALPmicCommReadByte(i2cNum, slaveAddr, regAddr, &byte);
        *value    = byte;
    }

    return status;
}

static pmErrCode_t PmhalTps65917WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                             uint32_t value)
{
    uint8_t     slaveAddr;
    uint8_t     regAddr;
    uint8_t     byte;
    pmErrCode_t status;

    byte      = (uint8_t) value;
    slaveAddr = PmhalTps65917PhytoSlaveAddr(phyAddr);
    regAddr   = PmhalTps65917PhyToPageOffset(phyAddr);
    status    = PMHALPmicCommWriteByte(i2cNum, slaveAddr, regAddr, byte);

    return status;
}

static uint32_t PmhalTps65917IsProductIdValid(uint32_t prodId)
{
    uint32_t prodIdValid = FALSE;
    /* TDA3xx EVM can have PMIC v1.0 */
    if (PMHAL_TPS65917_1_0_PRODUCT_ID == prodId)
    {
        prodIdValid = TRUE;
    }

    return prodIdValid;
}

static inline uint8_t PmhalTps65917PhyToPageOffset(uint32_t phyAddr)
{
    return (uint8_t) phyAddr;
}

static inline uint32_t PmhalTps65917PhyToPage(uint32_t phyAddr)
{
    return ((phyAddr) >> 8U);
}

