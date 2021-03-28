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
 * \file        pmhal_tps65910.c
 *
 * \brief       Power Management IC - TPS65910 specific API implementation.
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
#include <ti/drv/pm/include/pmic/pmhal_tps65910.h>
#include <ti/starterware/include/hw/hw_tps65910.h>
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
 * \brief   Check if the TPS65910 PMIC is present. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   void
 *
 * \return  PM_SUCCESS - TPS65910 PMIC is present.
 *          PM_PMHAL_PMIC_VENDOR_ID_INVALID - PMIC vendor id doesn't match the
 *                                     expected value.
 *          PM_PMHAL_PMIC_PRODUCT_ID_INVALID - PMIC product id doesn't match the
 *                                      expected value.
 */
static pmErrCode_t PMHALTps65910IsPresent(void);

/**
 * \brief   Return the PMIC Product ID. The declaration is present
 *          here to ensure this function is used only via function pointer.
 *
 * \param   productId   The Product ID is populated in this parameter.
 *
 * \return  status      PM_SUCCESS if API is a success. PM_BADARGS otherwise.
 */
static pmErrCode_t PMHALTps65910GetProductId(uint32_t *productId);

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
static pmErrCode_t PMHALTps65910GetRegulatorVoltage(
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
static pmErrCode_t PMHALTps65910SetRegulatorVoltage(
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
static uint32_t    PMHALTps65910IsRegulatorEnabled(
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
static pmErrCode_t PMHALTps65910EnableRegulator(
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
static pmErrCode_t PMHALTps65910DisableRegulator(
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
static uint32_t PMHALTps65910GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage);

#ifdef __cplusplus
}
#endif

/**
 * \brief Given voltage in mV and range, return the VSEL offset
 *
 * \param   regId   Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   voltage  Voltage in mV.
 * \param   sel      SEL value returned.
 * \param   vGainSel Gain multiplier of the SEL voltage.
 *
 * \return  status
 */
static pmErrCode_t PmhalTps65910VoltageToSelOffset(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                  *sel,
    uint32_t                  *vGainSel);

/**
 * \brief Given VSEL offset convert it to voltage in mV and return.
 *
 * \param   regId    Regulator Id. Refer Enum #pmhalPrcmPmicRegulatorId_t
 * \param   sel      VSEL value returned.
 * \param   vGainSel Gain multiplier of the SEL voltage.
 *
 * \return  voltage Voltage in mV.
 */
static uint32_t PmhalTps65910SelOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t sel, uint32_t vGainSel);

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
static pmErrCode_t PmhalTps65910ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
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
static pmErrCode_t PmhalTps65910WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
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
static uint32_t PmhalTps65910CheckRegulatorEnabled
    (pmhalPrcmPmicRegulatorId_t regId);

/**
 * \brief Function to convert the physical address to the slave address.
 *
 * \param   phyAddr     Physical Address
 * \return  slaveAddr   Slave Address
 */
static uint8_t PmhalTps65910PhytoSlaveAddr(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page offset
 */
static uint8_t PmhalTps65910PhyToPageOffset(uint32_t phyAddr);

/**
 * \brief In line function to find the Offset of a register address in a page.
 *
 * \param   phyAddr   Physical Address
 * \return  Page Number
 */
static uint32_t PmhalTps65910PhyToPage(uint32_t phyAddr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Power Management IC device callbacks. */
const pmhalPmicOperations_t          gPmhalTps65910Ops =
{
    &PMHALTps65910IsPresent,               /* isPresent */
    NULL,                                  /* getRevision */
    NULL,                                  /* getVendorId */
    &PMHALTps65910GetProductId,            /* getProductId */
    &PMHALTps65910IsRegulatorEnabled,      /* isRegulatorEnabled */
    &PMHALTps65910EnableRegulator,         /* regulatorEnable */
    &PMHALTps65910DisableRegulator,        /* regulatorDisable */
    &PMHALTps65910GetRegulatorVoltage,     /* regulatorGetVoltage */
    &PMHALTps65910SetRegulatorVoltage,     /* regulatorSetVoltage */
    &PMHALTps65910GetRegulatorConvVoltage, /* regulatorGetConvVoltage */
};

/* Data structure to describe the VIO SMPS Regulator SEL values.
 * Use pmhalTps65910LdoSel_t since VIO_REG aligns with LDO SEL
 * register element structure. */
const pmhalTps65910LdoSel_t gPmhalTps65910VioSel[LDO_CTRL_MAX_SEL] =
{
    {1500U, 0U},
    {1800U, 1U},
    {2500U, 2U},
    {3300U, 3U}
};

/* Data structure to describe the VDD1 SMPS Regulator SEL values. */
const pmhalTps65910SmpsSel_t gPmhalTps65910SmpsVdd1Sel[
    SMPS_CTRL_MAX_VGAIN_SEL] =
{
    {1U, 0U,  600U, 0x03U, 1500U, 0x4BU},
    {1U, 1U,  600U, 0x03U, 1500U, 0x4BU},
    {2U, 2U, 1200U, 0x03U, 2200U, 0x2BU},
    {3U, 3U, 1800U, 0x03U, 3200U, 0x28U}
};

/* Data structure to describe the VDD2 SMPS Regulator SEL values. */
const pmhalTps65910SmpsSel_t gPmhalTps65910SmpsVdd2Sel[
    SMPS_CTRL_MAX_VGAIN_SEL] =
{
    {1U, 0U,  600U, 0x03U, 1500U, 0x4BU},
    {1U, 1U,  600U, 0x03U, 1500U, 0x4BU},
    {2U, 2U, 1200U, 0x03U, 2200U, 0x2BU},
    {3U, 3U, 1800U, 0x03U, 3300U, 0x2BU}
};

/* Data structure to describe the VDIG1 LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVdig1Sel[LDO_CTRL_MAX_SEL] =
{
    {1200U, 0U},
    {1500U, 1U},
    {1800U, 2U},
    {2700U, 3U}
};

/* Data structure to describe the VDIG2 LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVdig2Sel[LDO_CTRL_MAX_SEL] =
{
    {1000U, 0U},
    {1100U, 1U},
    {1200U, 2U},
    {1800U, 3U}
};

/* Data structure to describe the VAUX1 LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVaux1Sel[LDO_CTRL_MAX_SEL] =
{
    {1800U, 0U},
    {2500U, 1U},
    {2800U, 2U},
    {2850U, 3U}
};

/* Data structure to describe the VAUX2 LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVaux2Sel[LDO_CTRL_MAX_SEL] =
{
    {1800U, 0U},
    {2800U, 1U},
    {2900U, 2U},
    {3300U, 3U}
};

/* Data structure to describe the VAUX33 LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVaux33Sel[LDO_CTRL_MAX_SEL] =
{
    {1800U, 0U},
    {2000U, 1U},
    {2800U, 2U},
    {3300U, 3U}
};

/* Data structure to describe the VMMC LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVmmcSel[LDO_CTRL_MAX_SEL] =
{
    {1800U, 0U},
    {2800U, 1U},
    {3000U, 2U},
    {3300U, 3U}
};

/* Data structure to describe the VPLL LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVpllSel[LDO_CTRL_MAX_SEL] =
{
    {1000U, 0U},
    {1100U, 1U},
    {1800U, 2U},
    {2500U, 3U}
};

/* Data structure to describe the VDAC LDO Regulator SEL values. */
const pmhalTps65910LdoSel_t gPmhalTps65910LdoVdacSel[LDO_CTRL_MAX_SEL] =
{
    {1800U, 0U},
    {2600U, 1U},
    {2800U, 2U},
    {2850U, 3U}
};

/* Data structure to describe the regulator for all the regulators. */
const pmhalTps65910RegulatorProp_t  gPmhalTps65910Regulator[
    PMHAL_TPS65910_REGULATOR_MAX] =
{
    /* PMHAL_TPS65910_REGULATOR_LDORTC */
    {
        1780U, 1880U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0U,
        {.ldoSel = NULL},
        VRTC_REG, 0U, 0U
    },
    /* PMHAL_TPS65910_REGULATOR_SMPSVIO (Registers align with LDO type) */
    {
        1500U, 3300U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0U,
        {.ldoSel = &gPmhalTps65910VioSel[0]},
        VIO_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_SMPSVDD1 */
    {
        600U, 3200U, 12500U, PMHAL_TPS65910_RTYPE_SMPS, 12500U,
        {&gPmhalTps65910SmpsVdd1Sel[0]},
        VDD1_REG, VDD1_OP_REG, VDD1_SR_REG
    },
    /* PMHAL_TPS65910_REGULATOR_SMPSVDD2 */
    {
        600U, 3300U, 12500U, PMHAL_TPS65910_RTYPE_SMPS, 12500U,
        {&gPmhalTps65910SmpsVdd2Sel[0]},
        VDD2_REG, VDD2_OP_REG, VDD2_SR_REG
    },
    /* PMHAL_TPS65910_REGULATOR_SMPSVDD3 */
    {
        4650U, 5250U, 0U, PMHAL_TPS65910_RTYPE_SMPS, 0x0U,
        {NULL},
        VDD3_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_LDOVDIG1 */
    {
        1200U, 2700U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVdig1Sel[0]},
        VDIG1_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_LDOVDIG2 */
    {
        1200U, 2700U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVdig2Sel[0]},
        VDIG2_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_LDOVAUX1 */
    {
        1800U, 2850U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVaux1Sel[0]},
        VAUX1_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_LDOVAUX2 */
    {
        1800U, 2850U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVaux2Sel[0]},
        VAUX2_REG, 0x0U, 0x0U
    },
    /* PMHAL_TPS65910_REGULATOR_LDOVAUX33 */
    {
        1800U, 3300U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVaux33Sel[0]},
        VAUX33_REG, 0x0U, 0x0U
    },
    /*  PMHAL_TPS65910_REGULATOR_LDOVMMC */
    {
        1800U, 3300U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVmmcSel[0]},
        VMMC_REG, 0x0U, 0x0U
    },
    /*  PMHAL_TPS65910_REGULATOR_LDOVPLL */
    {
        1800U, 28500U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVpllSel[0]},
        VPLL_REG, 0x0U, 0x0U
    },
    /*  PMHAL_TPS65910_REGULATOR_LDOVDAC */
    {
        1800U, 2850U, 0U, PMHAL_TPS65910_RTYPE_LDO, 0x0U,
        {.ldoSel = &gPmhalTps65910LdoVdacSel[0]},
        VDAC_REG, 0x0U, 0x0U
    }
};

/* Table mapping from SMPS/LDO to Voltage Rails on the device */
pmhalTps65910RegulatorMap_t         gPmhalDefaultTps65910RegulatorTable[
    PMHAL_PRCM_PMIC_REGULATOR_COUNT] =
{
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MPU */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_SMPSVDD1],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_CORE */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_SMPSVDD2],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MMC */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_LDOVMMC],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_SHV5 */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_LDOVAUX2],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PHY */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_LDOVAUX1],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    },
    /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PLL */
    {
        &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_LDOVDIG2],
        (uint8_t) PMHAL_TPS65910_I2C_NUM_1
    }
};

/* Pointer to array of pointers describing the mapping from regulators to
 * device voltage rails.
 */
static pmhalTps65910RegulatorMap_t *gPmhalTps65910RegulatorTable =
    gPmhalDefaultTps65910RegulatorTable;

/*
 * PMIC uses different slave addresses to access different register
 *        pages. This table lists the page slave addresses.
 */
const uint8_t gPmhalTps65910SlaveAddressTable[
    PMHAL_TPS65910_SLAVE_ADDR_COUNT] =
{
    PMHAL_TPS65910_SLAVE_ADDR_PAGE0
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

const pmhalPmicOperations_t *PMHALTps65910GetPMICOps(void)
{
    return &gPmhalTps65910Ops;
}

void PMHALTps65910ConfigureRegulatorMap(
    pmhalTps65910RegulatorMapPtr_t regulatorMap)
{
    /* If the regulatorMap provided by the caller is NULL then the default
     * regulator map as present on TI EVMs is used. */
    if (NULL == regulatorMap)
    {
        gPmhalTps65910RegulatorTable = gPmhalDefaultTps65910RegulatorTable;
    }
    else
    {
        gPmhalTps65910RegulatorTable = regulatorMap;
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static pmErrCode_t PMHALTps65910GetProductId(uint32_t *productId)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    version = 0U;
    uint8_t     i2cNum;

    if (NULL == productId)
    {
        status = PM_BADARGS;
    }
    else
    {
        i2cNum =
            gPmhalTps65910RegulatorTable[PMHAL_PRCM_PMIC_REGULATOR_MIN].
            i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * Read the silcon version number.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65910ReadPhyAddr(
                i2cNum,
                (uint32_t)
                JTAGVERNUM_REG,
                &version);
        }

        if (PM_SUCCESS == status)
        {
            *productId = version;
        }
        else
        {
            *productId = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65910IsPresent(void)
{
    uint32_t    prodId = 0U;
    pmErrCode_t status = PM_SUCCESS;

    /*
     * Check if the TPS65910 PMIC is present. This function
     * ensures that this specific PMIC is in the system by
     * reading and verifying the silicon version.
     * Return success only if the silicon version is returned
     * by the PMIC.
     */

    /* Check the Product ID. */
    status = PMHALTps65910GetProductId(&prodId);
    if (PM_SUCCESS == status)
    {
        if (prodId == 0U)
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

static pmErrCode_t PMHALTps65910GetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                  *voltage)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    ctrl = 0U;
    uint32_t    op = 0U;
    uint32_t    sr = 0U;
    uint32_t    opCmd = 0U;
    uint32_t    sel = 0U;
    uint32_t    vGainSel = 0U;
    const pmhalTps65910RegulatorProp_t *regulator;
    uint8_t     i2cNum;

    if ((NULL == voltage) || (regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65910RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * If the regulator has the SR register and if the OP.CMD bit is
         * set to 0x0, the pmic uses the voltage value in the OP.SEL
         * register bits. Otherwise, the pmic uses the voltage value in the
         * SR.SEL bits. Read the OP.CMD bit to choose the right
         * register to read.
         */
        if ((0x0U != regulator->voltSrRegAddr) && (PM_SUCCESS == status))
        {
            status = PmhalTps65910ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                              &op);

            if (PM_SUCCESS == status)
            {
                opCmd = HW_GET_FIELD(op, PMHAL_TPS65910_SMPSxx_OP_CMD);
            }
        }

        if ((PM_SUCCESS == status) && (0x0U != regulator->voltSrRegAddr))
        {
            /*
             * If OP.CMD is 0x0, read the SEL value from OP.SEL bits.
             */
            if (0x0U == opCmd)
            {
                sel = HW_GET_FIELD(op, PMHAL_TPS65910_SMPSxx_SEL);
            }
            /*
             * If OP.CMD is 0x1, read the SEL value to SR.SEL bits.
             */
            else
            {
                status =
                    PmhalTps65910ReadPhyAddr(i2cNum, regulator->voltSrRegAddr,
                                             &sr);
                if (PM_SUCCESS == status)
                {
                    sel = HW_GET_FIELD(sr, PMHAL_TPS65910_SMPSxx_SEL);
                }
            }
        }

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65910ReadPhyAddr(i2cNum, regulator->ctrlRegAddr,
                                              &ctrl);
            if (PM_SUCCESS == status)
            {
                if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
                {
                    /*
                     * Extract the VGAIN_SEL value from CTRL.VGAIN_SEL.
                     */
                    vGainSel = HW_GET_FIELD(ctrl,
                                        PMHAL_TPS65910_SMPSxx_CTRL_VGAIN_SEL);
                }
                else
                {
                    /*
                     * For LDO, get voltage from CTRL.SEL.
                     */
                    sel = HW_GET_FIELD(ctrl,
                                       PMHAL_TPS65910_LDOxx_CTRL_SEL);
                }
            }
        }

        if (PM_SUCCESS == status)
        {
            *voltage = PmhalTps65910SelOffsetToVoltage(regId, sel, vGainSel);
        }
        else
        {
            *voltage = 0U;
        }
    }

    return status;
}

static pmErrCode_t PMHALTps65910SetRegulatorVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                   timeout)
{
    pmErrCode_t status   = PM_SUCCESS;
    uint32_t    ctrl     = 0U;
    uint32_t    op       = 0U;
    uint32_t    sr       = 0U;
    uint32_t    opCmd    = 0U;
    uint32_t    sel      = 0U;
    uint32_t    vGainSel = 0U;
    const pmhalTps65910RegulatorProp_t *regulator;
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
        regulator = gPmhalTps65910RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;
        /*
         * Configure and enable PMIC communication bus.
         */
        status = PMHALPmicCommConfigure(i2cNum);

        /*
         * If the regulator has the SR register and if the OP.CMD bit is
         * set to 0x0, the pmic uses the voltage value in the OP.SEL
         * register bits. Otherwise, the pmic uses the voltage value in the
         * SR.SEL bits. Read the OP.CMD bit to choose the right
         * register to program.
         */
        if ((0x0U != regulator->voltSrRegAddr) && (PM_SUCCESS == status))
        {
            status = PmhalTps65910ReadPhyAddr(i2cNum, regulator->voltRegAddr,
                                              &op);

            if (PM_SUCCESS == status)
            {
                opCmd = HW_GET_FIELD(op, PMHAL_TPS65910_SMPSxx_OP_CMD);
            }
        }

        /*
         * Convert the given voltage value to the SEL offset and, for SMPS,
         * the proper VGAIN_SEL value.
         */
        if (PM_SUCCESS == status)
        {
            status = PmhalTps65910VoltageToSelOffset(regId, voltage,
                                                     &sel, &vGainSel);
            if ((PM_SUCCESS == status) && (0x0U != regulator->voltSrRegAddr))
            {
                /*
                 * If OP.CMD is 0x0, write the SEL value to OP.SEL bits.
                 */
                if (0x0U == opCmd)
                {
                    HW_SET_FIELD32(op, PMHAL_TPS65910_SMPSxx_SEL, sel);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->voltRegAddr,
                                                  op);
                }
                /*
                 * If OP.CMD is 0x1, write the SEL value to SR.SEL
                 * bits.
                 */
                else
                {
                    status = PmhalTps65910ReadPhyAddr(i2cNum,
                                                      regulator->voltRegAddr,
                                                      &sr);
                    if (PM_SUCCESS == status)
                    {
                        HW_SET_FIELD32(sr, PMHAL_TPS65910_SMPSxx_SEL, sel);
                        status =
                            PmhalTps65910WritePhyAddr(i2cNum,
                                                      regulator->voltSrRegAddr,
                                                      sr);
                    }
                }
            }

            if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
            {
                /* Program the VGAIN_SEL for SMPS */
                HW_SET_FIELD32(op, PMHAL_TPS65910_SMPSxx_CTRL_VGAIN_SEL,
                               vGainSel);
                status =
                    PmhalTps65910WritePhyAddr(i2cNum,
                                              regulator->voltRegAddr,
                                              op);
            }
            else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
            {
                status = PmhalTps65910ReadPhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  &ctrl);
                if (PM_SUCCESS == status)
                {
                    HW_SET_FIELD32(ctrl, PMHAL_TPS65910_LDOxx_CTRL_SEL,
                                   sel);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
            }
            else
            {
                ; /* should not get here */
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
            uint32_t newV = PmhalTps65910SelOffsetToVoltage(regId, sel,
                                                            vGainSel);

            if (PM_TIMEOUT_INFINITE == timeout)
            {
                while (newV != currVolt)
                {
                    PMHALTps65910GetRegulatorVoltage(regId, &currVolt);
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
                    PMHALTps65910GetRegulatorVoltage(regId, &currVolt);
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

static uint32_t PMHALTps65910IsRegulatorEnabled(
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
        i2cNum = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);
    }

    if (PM_SUCCESS == status)
    {
        enabled = (uint32_t) PmhalTps65910CheckRegulatorEnabled(regId);
    }

    return enabled;
}

static pmErrCode_t PMHALTps65910EnableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    pmErrCode_t status = PM_SUCCESS;
    const pmhalTps65910RegulatorProp_t *regulator;
    uint32_t    ctrl = 0U;
    uint32_t    enabled = FALSE;
    uint8_t     i2cNum;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65910RegulatorTable[regId].regulatorMap;
        i2cNum    = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;

        /* Configure and enable PMIC communication bus.  */
        status = PMHALPmicCommConfigure(i2cNum);

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65910ReadPhyAddr(i2cNum,
                                              regulator->ctrlRegAddr,
                                              &ctrl);
        }

        if (PM_SUCCESS == status)
        {
            /*
             * If the Regulator is disabled, enable by setting the MODE_ACTIVE
             * and MODE_SLEEP to 0x01 (Forced PWM)
             */
            enabled = PmhalTps65910CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65910_SMPSxx_CTRL_ST,
                                   0x01U);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65910_LDOxx_CTRL_ST,
                                   0x01U);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else
                {
                    ; /* Should not reach here */
                }
            }
            enabled = PmhalTps65910CheckRegulatorEnabled(regId);
            if (FALSE == enabled)
            {
                status = PM_FAIL;
            }
        }
    }
    return status;
}

static pmErrCode_t PMHALTps65910DisableRegulator(
    pmhalPrcmPmicRegulatorId_t regId)
{
    pmErrCode_t status = PM_SUCCESS;
    const pmhalTps65910RegulatorProp_t *regulator;
    uint8_t     i2cNum;
    uint32_t    ctrl = 0U;

    if ((regId >= PMHAL_PRCM_PMIC_REGULATOR_COUNT) ||
        (regId < PMHAL_PRCM_PMIC_REGULATOR_MIN))
    {
        status = PM_BADARGS;
    }
    else
    {
        regulator = gPmhalTps65910RegulatorTable[regId].regulatorMap;
        i2cNum = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;
        /* Configure and enable PMIC communication bus. */
        status = PMHALPmicCommConfigure(i2cNum);

        if (PM_SUCCESS == status)
        {
            status = PmhalTps65910ReadPhyAddr(i2cNum,
                                              regulator->ctrlRegAddr,
                                              &ctrl);
        }

        /* If the Regulator is enabled, disable by setting the state to 0U. */
        if (PM_SUCCESS == status)
        {
            if (PmhalTps65910CheckRegulatorEnabled(regId) == TRUE)
            {
                if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65910_SMPSxx_CTRL_ST,
                                   0x00U);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
                {
                    HW_SET_FIELD32(ctrl,
                                   PMHAL_TPS65910_LDOxx_CTRL_ST,
                                   0x00U);
                    status =
                        PmhalTps65910WritePhyAddr(i2cNum,
                                                  regulator->ctrlRegAddr,
                                                  ctrl);
                }
                else
                {
                    ; /* Should not reach here */
                }

                /* Check if the regulator is truly disabled */
                if (TRUE == PmhalTps65910CheckRegulatorEnabled(regId))
                {
                    status = PM_FAIL;
                }
            }
        }
    }

    return status;
}

static uint32_t PMHALTps65910GetRegulatorConvVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   avsVoltage)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    convVoltage = 0U;
    uint32_t    internalSel = 0U;
    uint32_t    internalVGainSel = 0U;

    status = PmhalTps65910VoltageToSelOffset(regId, avsVoltage,
                                             &internalSel, &internalVGainSel);
    if (PM_SUCCESS == status)
    {
        convVoltage = PmhalTps65910SelOffsetToVoltage(regId,
                                                      internalSel,
                                                      internalVGainSel);
    }

    return convVoltage;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t PmhalTps65910CheckRegulatorEnabled(
    pmhalPrcmPmicRegulatorId_t regId)
{
    uint32_t enabled = FALSE;
    uint32_t ctrl    = 0U;
    uint8_t  i2cNum;
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65910RegulatorProp_t *regulator =
        gPmhalTps65910RegulatorTable[regId].regulatorMap;

    i2cNum = gPmhalTps65910RegulatorTable[regId].i2cInstanceNum;

    /* Read the regulator CTRL_STATUS and return the status. */
    if (PM_SUCCESS ==
        PmhalTps65910ReadPhyAddr(i2cNum, regulator->ctrlRegAddr, &ctrl))
    {
        if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
        {
            if ((HW_GET_FIELD(ctrl, PMHAL_TPS65910_SMPSxx_CTRL_ST) !=
                 CTRL_STATE_OFF0) &&
                (HW_GET_FIELD(ctrl, PMHAL_TPS65910_SMPSxx_CTRL_ST) !=
                 CTRL_STATE_OFF1))
            {
                enabled = TRUE;
            }
        }
        else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
        {
            if ((HW_GET_FIELD(ctrl, PMHAL_TPS65910_LDOxx_CTRL_ST) !=
                 CTRL_STATE_OFF0) &&
                (HW_GET_FIELD(ctrl, PMHAL_TPS65910_LDOxx_CTRL_ST) !=
                 CTRL_STATE_OFF1))
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

static pmErrCode_t PmhalTps65910VoltageToSelOffset(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t                   voltage,
    uint32_t                  *sel,
    uint32_t                  *vGainSel)
{
    pmErrCode_t status = PM_SUCCESS;
    
    /*
     * regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function.
     */
    const pmhalTps65910RegulatorProp_t *regulator =
        gPmhalTps65910RegulatorTable[regId].regulatorMap;

    if ((NULL == sel) || (NULL == vGainSel))
    {
        status = PM_BADARGS;
    }
    else
    {
        if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
        {
            uint32_t vGainSelIdx = 0U;

            /* Find first vGainSel range within input voltage sits */
            while (vGainSelIdx < SMPS_CTRL_MAX_VGAIN_SEL)
            {
                if ((voltage >= regulator->pSel_u.smpsSel[
                                                     vGainSelIdx].minVolt) &&
                    (voltage <= regulator->pSel_u.smpsSel[
                                                     vGainSelIdx].maxVolt))
                {
                    break;
                }
                vGainSelIdx++;
            }

            if (voltage >
                regulator->pSel_u.smpsSel[SMPS_CTRL_MAX_VGAIN_SEL - 1].maxVolt)
            {
                *vGainSel = SMPS_CTRL_MAX_VGAIN_SEL - 1;
            }
            
            /* Voltage of 0 is off value for SMPS */
            if (voltage == 0U)
            {
                *vGainSel = 0U;
                *sel = 0U;
            }
            else
            {
                uint32_t uVolt;
                
                *vGainSel = regulator->pSel_u.smpsSel[vGainSelIdx].vGainSel;

                /* Calculate SEL based on configured vGainSel */
                uVolt = voltage * 1000;
                *sel = ((uVolt /
                         regulator->pSel_u.smpsSel[vGainSelIdx].vGain) -
                        SMPS_CTRL_SEL_OFFSET_UV) / regulator->stepVolt;

                if (*sel < regulator->pSel_u.smpsSel[vGainSelIdx].minVoltSel)
                {
                    *sel = regulator->pSel_u.smpsSel[vGainSelIdx].minVoltSel;
                }
                else if (*sel >
                         regulator->pSel_u.smpsSel[vGainSelIdx].maxVoltSel)
                {
                    *sel = regulator->pSel_u.smpsSel[vGainSelIdx].maxVoltSel;
                }
                else
                {
                    /* Should not get here */
                }
            }
        }
        else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
        {
            uint32_t selIdx = 0U;
            uint32_t distVolt;

            /* Find SEL value with voltage closest to input voltage */
            *sel = 0U;
            distVolt = abs(regulator->pSel_u.ldoSel[0].volt - voltage);

            for (selIdx = 1; selIdx < LDO_CTRL_MAX_SEL; selIdx++)
            {
                if (abs(regulator->pSel_u.ldoSel[selIdx].volt - voltage) <
                    distVolt)
                {
                    *sel = regulator->pSel_u.ldoSel[selIdx].voltSel;
                    distVolt = abs(regulator->pSel_u.ldoSel[selIdx].volt -
                                   voltage);
                }
            }
        }
        else
        {
            ; /* Should not get here */
        }
    }

    return status;
}

static uint32_t PmhalTps65910SelOffsetToVoltage(
    pmhalPrcmPmicRegulatorId_t regId,
    uint32_t sel, uint32_t vGainSel)
{
    uint32_t gain = 0U;
    uint32_t mv = 0U;

    /* regId checks are not done here as this is an internal function and
     * the check would have happened before calling this function. */
    const pmhalTps65910RegulatorProp_t *regulator =
        gPmhalTps65910RegulatorTable[regId].regulatorMap;

    if (PMHAL_TPS65910_RTYPE_SMPS == regulator->type)
    {
        if ((vGainSel >= 0) &&
            (vGainSel < SMPS_CTRL_MAX_VGAIN_SEL))
        {
            /* Retrieve gain corresponding to vGainSel value */
            gain = regulator->pSel_u.smpsSel[vGainSel].vGain;
        }

        if (gain > 0)
        {
            if ((sel >= regulator->pSel_u.smpsSel[vGainSel].minVoltSel) &&
                (sel <= regulator->pSel_u.smpsSel[vGainSel].maxVoltSel))
            {
                /* Calculate voltage */
                mv = (((sel * regulator->stepVolt) + 
                        SMPS_CTRL_SEL_OFFSET_UV) * gain) / 1000;
            }
        }
    }
    else if (PMHAL_TPS65910_RTYPE_LDO == regulator->type)
    {
        if ((sel >= 0) &&
            (sel < LDO_CTRL_MAX_SEL))
        {
            /* For LDO, voltage is one of four values based on CTRL.SEL */
            mv = regulator->pSel_u.ldoSel[sel].volt;
        }
    }
    else
    {
        ; /* Should not get here */
    }

    if (mv == 0U)
    {
        mv = 0U;
    }
    else if (mv < regulator->minVolt)
    {
        mv = regulator->minVolt;
    }
    else if (mv > regulator->maxVolt)
    {
        mv = regulator->maxVolt;
    }
    else
    {
        /* Shouldn't get here */
    }

    return mv;
}

static uint8_t PmhalTps65910PhytoSlaveAddr(uint32_t phyAddr)
{
    uint32_t page      = PmhalTps65910PhyToPage(phyAddr);
    uint8_t  slaveAddr = (uint8_t) PMHAL_TPS65910_SLAVE_ADDR_INVALID;

    if (page < PMHAL_TPS65910_SLAVE_ADDR_COUNT)
    {
        slaveAddr = gPmhalTps65910SlaveAddressTable[page];
    }

    return slaveAddr;
}

static pmErrCode_t PmhalTps65910ReadPhyAddr(uint8_t i2cNum, uint32_t phyAddr,
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
        slaveAddr = PmhalTps65910PhytoSlaveAddr(phyAddr);
        regAddr   = PmhalTps65910PhyToPageOffset(phyAddr);
        status    = PMHALPmicCommReadByte(i2cNum, slaveAddr, regAddr, &byte);
        *value    = byte;
    }

    return status;
}

static pmErrCode_t PmhalTps65910WritePhyAddr(uint8_t i2cNum, uint32_t phyAddr,
                                              uint32_t value)
{
    uint8_t     slaveAddr;
    uint8_t     regAddr;
    uint8_t     byte;
    pmErrCode_t status;

    byte      = (uint8_t) value;
    slaveAddr = PmhalTps65910PhytoSlaveAddr(phyAddr);
    regAddr   = PmhalTps65910PhyToPageOffset(phyAddr);
    status    = PMHALPmicCommWriteByte(i2cNum, slaveAddr, regAddr, byte);

    return status;
}

static uint8_t PmhalTps65910PhyToPageOffset(uint32_t phyAddr)
{
    return (uint8_t) phyAddr;
}

static uint32_t PmhalTps65910PhyToPage(uint32_t phyAddr)
{
    return ((phyAddr) >> 8U);
}

