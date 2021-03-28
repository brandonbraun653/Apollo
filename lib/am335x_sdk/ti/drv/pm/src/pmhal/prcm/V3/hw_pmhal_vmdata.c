/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
 * \file hw_pmhal_vmdata.c
 *
 * \brief   Voltage Domain Information specific to the SoC.
 *
 *          The Voltage Domain structures are populated with data specific to
 *          AM335x
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include "pm_types.h"
#include "pm_utils.h"
#include "pmhal_pmic.h"
#include "pmhal_vm.h"
#include "hw_pmhal_vmdata.h"
#include "hw_pmhal_data.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief Enum to index into the gPmhalVmOpp array.
 */
typedef enum pmhalVmVoltOppIndex
{
    PMHAL_VM_INDEX_MIN = 0U,
    /**< Min Index for gPmhalVmOpp array */
    PMHAL_VM_INDEX_MPU_LOW = PMHAL_VM_INDEX_MIN,
    /**< VDD_MPU, OPP_50 Index */
    PMHAL_VM_INDEX_MPU_NOM = 1U,
    /**< VDD_MPU, OPP_100 Index */
    PMHAL_VM_INDEX_MPU_OD = 2U,
    /**< VDD_MPU, OPP_120 Index */
    PMHAL_VM_INDEX_MPU_HIGH = 3U,
    /**< VDD_MPU, OPP_TURBO Index */
    PMHAL_VM_INDEX_MPU_HIGH2 = 4U,
    /**< VDD_MPU, OPP_NITRO Index */
    PMHAL_VM_INDEX_CORE_NOM = 5U,
    /**< VDD_CORE, OPP_100 Index */
    PMHAL_VM_INDEX_RTC_NOM = 6U,
    /**< VDD_RTC, OPP All Index */
    PMHAL_VM_INDEX_MAX = PMHAL_VM_INDEX_RTC_NOM,
    /**< Max Index for gPmhalVmOpp array */
    PMHAL_VM_INDEX_COUNT = PMHAL_VM_INDEX_MAX + 1U
    /**< Count of Indices for gPmhalVmOpp array */
} pmhalVmVoltOppIndex_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/**
 *  \brief Array defining CPU Id list of PMHAL_PRCM_VD_MPU
 */
pmhalPrcmCpuId_t PMHAL_PRCM_VD_MPU_cpuIdList[] =
{
    PMHAL_PRCM_CPU_ID_MPU
};
/**
 *  \brief Array defining CPU Id list of PMHAL_PRCM_VD_CORE
 */
pmhalPrcmCpuId_t PMHAL_PRCM_VD_CORE_cpuIdList[] =
{
    PMHAL_PRCM_CPU_ID_UNDEF
};
/**
 *  \brief Array defining CPU Id list of PMHAL_PRCM_VD_RTC
 */
pmhalPrcmCpuId_t PMHAL_PRCM_VD_RTC_cpuIdList[] =
{
    PMHAL_PRCM_CPU_ID_UNDEF
};
/*
 *  OPP Voltage Table for AM335x devices.  Based on Operating Performance Point
 *  section in am335x specification (SPRS717J at the time of development)
 *
 *  AVS info unknown - Disabling for now
 *
 *  OPP 50 not supported due to PMIC hardware bugs
 *
 *     +------------+------------------+-------------------+-----------------+
 *     | Voltage    |    OPP_50 (NS)   |      OPP_100      |     OPP_120     |
 *     | Domain     |    Min/Nom/Max   |    Min/Nom/Max    |   Min/Nom/Max   |
 *     +------------+------------------+-------------------+-----------------+
 *     | VD_MPU     |                  |                   |                 |
 *     | AVS Not En | 0.912/0.95/0.988 |  1.056/1.1/1.144  | 1.152/1.2/1.248 |
 *     | AVS En     |        NA        |         NA        |        NA       |
 *     +------------+------------------+-------------------+-----------------+
 *     | VD_CORE    |                  |                   |                 |
 *     | AVS Not En | 0.912/0.95/0.988 |  1.056/1.1/1.144  |        NA       |
 *     | AVS En     |        NA        |         NA        |        NA       |
 *     +------------+------------------+-------------------+-----------------+
 *     | VD_RTC     |                  |                   |                 |
 *     | AVS Not En |   1.71/1.8/1.89  |   1.71/1.8/1.89   |  1.71/1.8/1.89  |
 *     | AVS En     |        NA        |         NA        |       NA        |
 *     +------------+------------------+-------------------+-----------------+
 *                  |     OPP_TURBO    |     OPP_NITRO     |
 *                  |    Min/Nom/Max   |    Min/Nom/Max    |
 *                  +------------------+-------------------+
 *                  |                  |                   |
 *                  | 1.210/1.26/1.326 | 1.272/1.325/1.378 |
 *                  |        NA        |         NA        |
 *                  +------------------+-------------------+
 *                  |                  |                   |
 *                  |        NA        |         NA        |
 *                  |        NA        |         NA        |
 *                  +------------------+-------------------+
 *                  |                  |                   |
 *                  |  1.71/1.8/1.89   |   1.71/1.8/1.89   |
 *                  |        NA        |         NA        |
 *                  +------------------+-------------------+
 */

static const pmhalVmOppVoltage_t
    gPmhalVmOpp[PMHAL_VM_INDEX_COUNT] =
{
    /* VD_MPU voltage domain OPP definitions */
    {
        /* VD_MPU, OPP LOW (50) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {950U, 950U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_MPU, OPP NOM (100) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {1100U, 1100U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_MPU, OPP OD (120) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {1200U, 1200U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_MPU, OPP HIGH (Turbo) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {1260U, 1260U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_MPU, OPP HIGH2 (Nitro) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {1325U, 1325U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_CORE, OPP NOM (100) Voltage Initialization :
         *                        AVS & ABB Not Supported */
        {1100U, 1100U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    },
    {
        /* VD_RTC OPP NOM Voltage Initialization : AVS & ABB Not Supported */
        {1800U, 1800U},
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U,
        0U
    }
};

const pmhalVmVoltageDomain_t gPmhalVmDomains[PMHAL_PRCM_VD_COUNT] =
{
    /*
     * minSafemV, maxSafemV, minOppNommV (OPP100min), maxOppNommV (OPP100max),
     * sldoSetupAddr,
     * sldoCtrlAddr,
     * sLdoValidRetMode,
     * {OppVoltage-Low,
     * OppVoltage-nom,
     * OppVoltage-OD,
     * OppVoltage-High,
     * OppVoltage-High2},
     * cpuIdArr,
     * numCpus
     */
    {
     /* VD_MPU */
     912U, 1378U, 1056U, 1144U,
     SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_LDO_SRAM_MPU_SETUP,
     SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_LDO_SRAM_MPU_CTRL,
     (uint8_t) (((uint32_t) 1U <<
                 (uint32_t) PMHAL_PRCM_SRAM_LDO_RET_STATE_NO_RET) |
                ((uint32_t) 1U <<
                (uint32_t) PMHAL_PRCM_SRAM_LDO_RET_STATE_RET)),
     {&gPmhalVmOpp[PMHAL_VM_INDEX_MPU_LOW],
      &gPmhalVmOpp[PMHAL_VM_INDEX_MPU_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_MPU_OD],
      &gPmhalVmOpp[PMHAL_VM_INDEX_MPU_HIGH],
      &gPmhalVmOpp[PMHAL_VM_INDEX_MPU_HIGH2]},
     {PMHAL_VM_OPP_LOW, PMHAL_VM_OPP_NOM, PMHAL_VM_OPP_OD,
      PMHAL_VM_OPP_HIGH, PMHAL_VM_OPP_HIGH2},
     PMHAL_PRCM_VD_MPU_cpuIdList,
     PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_MPU_cpuIdList, pmhalPrcmCpuId_t)
    },
    {
     /* VD_CORE */
     850U, 1250U, 990U, 1200U,
     SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_LDO_SRAM_CORE_SETUP,
     SOC_PRM_DEVICE_REGS + PRM_DEVICE_PRM_LDO_SRAM_CORE_CTRL,
     (uint8_t) ((uint32_t) 1U << (uint32_t) PMHAL_PRCM_SRAM_LDO_RET_STATE_RET),
     {&gPmhalVmOpp[PMHAL_VM_INDEX_CORE_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_CORE_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_CORE_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_CORE_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_CORE_NOM]},
     {PMHAL_VM_OPP_LOW, PMHAL_VM_OPP_NOM, PMHAL_VM_OPP_OD,
      PMHAL_VM_OPP_HIGH, PMHAL_VM_OPP_HIGH2},
     PMHAL_PRCM_VD_CORE_cpuIdList,
     PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_CORE_cpuIdList, pmhalPrcmCpuId_t)
    },
    {
     /* VD_RTC */
     840U, 1250U, 840U, 1200U,
     PMHAL_REG_NOTAPPLICABLE,
     PMHAL_REG_NOTAPPLICABLE,
     0U,
     {&gPmhalVmOpp[PMHAL_VM_INDEX_RTC_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_RTC_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_RTC_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_RTC_NOM],
      &gPmhalVmOpp[PMHAL_VM_INDEX_RTC_NOM]},
     {PMHAL_VM_OPP_LOW, PMHAL_VM_OPP_NOM, PMHAL_VM_OPP_OD,
      PMHAL_VM_OPP_HIGH, PMHAL_VM_OPP_HIGH2},
     PMHAL_PRCM_VD_RTC_cpuIdList,
     PM_UTIL_VSIZE_TYPE(PMHAL_PRCM_VD_RTC_cpuIdList, pmhalPrcmCpuId_t)
    }
};

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

const pmhalVmVoltageDomain_t *PmhalVmGetVoltageDomain(uint32_t vId)
{
    const pmhalVmVoltageDomain_t *vd = NULL;
    /* unsigned int need not be compared against minimum value of 0U */
    if (vId >= PMHAL_PRCM_VD_MAX)
    {
        vd = NULL;
    }
    else
    {
        vd = (const pmhalVmVoltageDomain_t *) &gPmhalVmDomains[vId];
    }
    return (const pmhalVmVoltageDomain_t *) vd;
}

const pmhalVmOppVoltage_t *PmhalVmGetOppVoltage(
    const pmhalVmVoltageDomain_t *vd,
    uint32_t                      oppId)
{
    const pmhalVmOppVoltage_t *oppVoltage = NULL;
    /* unsigned int oppId need not be compared against minimum value of 0U */
    if ((oppId >= PMHAL_VM_OPP_MAX) || (vd == NULL))
    {
        oppVoltage = NULL;
    }
    else
    {
        oppVoltage = (const pmhalVmOppVoltage_t *) vd->oppVoltages[oppId];
    }
    return (const pmhalVmOppVoltage_t *) oppVoltage;
}

pmhalPrcmPmicRegulatorId_t PmhalVmGetRegulatorId(pmhalPrcmVdId_t voltDomId)
{
    pmhalPrcmPmicRegulatorId_t regId = PMHAL_PRCM_PMIC_REGULATOR_INVALID;

    switch (voltDomId)
    {
        case PMHAL_PRCM_VD_MPU:
            regId = PMHAL_PRCM_PMIC_REGULATOR_MPU;
            break;

        case PMHAL_PRCM_VD_CORE:
            regId = PMHAL_PRCM_PMIC_REGULATOR_CORE;
            break;

        default:
            regId = PMHAL_PRCM_PMIC_REGULATOR_INVALID;
            break;
    }

    return regId;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */

