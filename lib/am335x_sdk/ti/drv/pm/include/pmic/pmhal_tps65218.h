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
 *  \file  pmhal_tps65218.h
 *
 *  \brief The Power Management IC (PMIC) tps65218 specific API definition.
 *
 *         The APIs defined here are to control the voltage of the
 *         PMIC rails and to query the status.
 */

#ifndef PM_TPS65218_H_
#define PM_TPS65218_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \brief       PMHAL_TPS65218 CHIPID Register Fields Mask Field
 *              PMHAL_TPS65218_CHIPID.CHIP
 *      7:3     CHIP: Chip ID
 */
#define PMHAL_TPS65218_CHIPID_CHIP_MASK                  (0xF8U)

/**
 * \brief       PMHAL_TPS65218 CHIPID Register Fields Shift Field
 *              PMHAL_TPS65218_CHIPID.CHIP
 */
#define PMHAL_TPS65218_CHIPID_CHIP_SHIFT                 (0x3U)

/**
 * \brief       PMHAL_TPS65218_PASSWORD.PWRD Mask.
 *      7:0     PWRD: Password for accessing protected registers
 */
#define PMHAL_TPS65218_PASSWORD_PWRD_MASK                (0xFFU)

/**
 * \brief       PMHAL_TPS65218_PASSWORD.PWRD Shift.
 */
#define PMHAL_TPS65218_PASSWORD_PWRD_SHIFT               (0U)

/**
 * \brief       PMHAL_TPS65218_DCDCx/LDOx.VOLT Mask.
 *      5:0     VOLT: PMHAL_TPS65218 Output Voltages
 */
#define PMHAL_TPS65218_VOLT_MASK                         (0x3FU)

/**
 * \brief       PMHAL_TPS65218_DCDCx/LDOx.VOLT Shift.
 */
#define PMHAL_TPS65218_VOLT_SHIFT                        (0U)

/**
 * \brief       PMHAL_TPS65218_ENABLEx.DCx_EN Mask.
 *      1:0     ENx: PMHAL_TPS65218 Regulator x enable bit
 */
#define PMHAL_TPS65218_ENABLEx_DCx_EN_MASK(x)            (0x1U << x)

/**
 * \brief       PMHAL_TPS65218_ENABLEx.DCx_EN Shift.
 */
#define PMHAL_TPS65218_ENABLEx_DCx_EN_SHIFT(x)           (x)

/**
 * \brief       PMHAL_TPS65218_ENABLEx.LDO1_EN Mask.
 *      1:0     ENx: PMHAL_TPS65218 LDO1 Regulator enable bit
 */
#define PMHAL_TPS65218_ENABLEx_LDO1_EN_MASK              (0x1U)

/**
 * \brief       PMHAL_TPS65218_ENABLEx.LDO1_EN Shift.
 */
#define PMHAL_TPS65218_ENABLEx_LDO1_EN_SHIFT             (0U)

/** \brief      Enable state macro for off. */
#define ENABLE_STATE_OFF                                 (0U)

/** \brief      Enable state macro for on. */
#define ENABLE_STATE_ON                                  (1U)

/**
 * \brief       PMHAL_TPS65218_SLEW.GO Mask.
 *      7       VOLT: PMHAL_TPS65218 Slew Go bit
 */
#define PMHAL_TPS65218_SLEW_GO_MASK                      (0x80U)

/**
 * \brief       PMHAL_TPS65218_SLEW.GO Shift.
 */
#define PMHAL_TPS65218_SLEW_GO_SHIFT                     (7U)

/** \brief      Enable GO bit. */
#define ENABLE_SLEW_GO                                   (1U)

/**
 * \brief Slave Address:
 *
 * The TPS65218 PMIC uses the standard 7-bit slave I2C address to access
 * the register address space. This PMIC has 1 internal pages each of 256
 * bytes. The register address is 8-bits and can address one page. Multiple
 * pages are addressed using different slave addresses. The table below
 * gives the slave address for the register pages as programmed in the
 * AM335x device EVMs.
 */
#define PMHAL_TPS65218_SLAVE_ADDR_COUNT     (1U)

/**
 *   \brief SLAVE Address Page 0
 *
 *    Page    Phy Addr Range      Slave Address      OTP choice     Register
 *    ------------------------------------------------------------------------
 *     0      0x000 - 0x0FF       0x24                0x24          All regs
 */
#define PMHAL_TPS65218_SLAVE_ADDR_PAGE0     (0x24U)

/** \brief Invalid Page Address */
#define PMHAL_TPS65218_SLAVE_ADDR_INVALID   (0xFFU)

/** \brief Regulator Type for DCDC */
#define PMHAL_TPS65218_RTYPE_DCDC           (1U)

/** \brief Regulator Type for LDO */
#define PMHAL_TPS65218_RTYPE_LDO            (2U)

/** \brief The I2C number to which the voltage rail is connected */
#define PMHAL_TPS65218_I2C_NUM_1            (0x0U)

/** \brief TPS65218 Chip ID */
#define PMHAL_TPS65218_CHIP_ID              (0x0U)

/** \brief TPS65218 Invalid Chip ID */
#define PMHAL_TPS65218_CHIP_ID_INVALID      (0x1FU)

/** \brief TPS65218 Protection password */
#define PMHAL_TPS65218_PROTECTION_PASSWORD  (0x7DU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief Abstract Enumeration for the Regulators.
 */
typedef enum pmhalTps65218RegulatorId
{
    PMHAL_TPS65218_REGULATOR_INVALID = -1,
    /**< Invalid PMIC regulator ID */
    PMHAL_TPS65218_REGULATOR_MIN = 0,
    /**< Minimum Abstracted PMIC Regulator ID */
    PMHAL_TPS65218_REGULATOR_DCDC1 = PMHAL_PRCM_PMIC_REGULATOR_MIN,
    /**< Abstracted PMIC Regulator ID for DCDC1 */
    PMHAL_TPS65218_REGULATOR_DCDC2 = 1,
    /**< Abstracted PMIC Regulator ID for DCDC2 */
    PMHAL_TPS65218_REGULATOR_DCDC3 = 2,
    /**< Abstracted PMIC Regulator ID for DCDC3 */
    PMHAL_TPS65218_REGULATOR_DCDC4 = 3,
    /**< Abstracted PMIC Regulator ID for DCDC4 */
    PMHAL_TPS65218_REGULATOR_LDO1 = 4,
    /**< Abstracted PMIC Regulator ID for LDO1 */
    PMHAL_TPS65218_REGULATOR_MAX = (PMHAL_TPS65218_REGULATOR_LDO1 + 1)
                                    /**< Maximum Abstracted PMIC Regulator ID */
} pmhalTps65218RegulatorId_t;

/**
 * \brief TPS65218 Regulator description structure
 */
typedef struct pmhalTps65218RegulatorProp
{
    uint16_t minVolt;
    /**< Minimum voltage supported by the regulator in mV. */
    uint16_t maxVolt;
    /**< Maximum voltage supported by the regulator in mV. */
    uint16_t stepVoltTransition;
    /**< Transition step voltage in mV. Voltage at which step voltage
     *   changes from stepVoltLow to stepVoltHigh. */
    uint16_t stepVoltTransBits;
    /**< Bitfield value of step voltage transition value */
    uint16_t stepVoltLow;
    /**< Low step voltage in mV. Step voltage used in lower portion of
     *   supported voltage range. */
    uint16_t stepVoltHigh;
    /**< High step voltage in mV. Step voltage used in upper portion of
     *   supported voltage range. */
    uint8_t  regId;
    /**< TPS65218 Regulator Id for ENABLE fields */
    uint8_t  type;
    /**< The regulator type namely PMHAL_TPS65218_RTYPE_DCDC or
     *   PMHAL_TPS65218_RTYPE_LDO. */
    uint32_t ctrlRegAddr;
    /**< The regulator control register address.*/
    uint32_t voltRegAddr;
    /**< The regulator voltage register address. */
    uint32_t slewRegAddr;
    /**< The regulator slew register address. */
} pmhalTps65218RegulatorProp_t;

/** \brief  Pointer to pmhalTps65218RegulatorProp_t structure.
 */
typedef const pmhalTps65218RegulatorProp_t *pmhalTps65218RegulatorPtr_t;

typedef struct pmhalTps65218RegulatorMap
{
    pmhalTps65218RegulatorPtr_t regulatorMap;
    /**< Pointer to the regulator properties */
    uint8_t                     i2cInstanceNum;
    /**< SoC I2C instance number to which the regulator of the PMIC will be
     *   connected to.
     */
} pmhalTps65218RegulatorMap_t;

/** \brief Pointer to the structure pmhalTps65218RegulatorMap_t */
typedef pmhalTps65218RegulatorMap_t *const pmhalTps65218RegulatorMapPtr_t;

/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */

/* Array of the properties of all the SMPS and LDO PMIC regulators */
extern const pmhalTps65218RegulatorProp_t gPmhalTps65218Regulator[
    PMHAL_TPS65218_REGULATOR_MAX];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Get PMIC ops structure. All the other functions are accessed via
 *          function pointers whose array is exported by this function.
 *
 * \param   None
 *
 * \return  Return pointer to the PMIC ops structure.
 */
const pmhalPmicOperations_t *PMHALTps65218GetPMICOps(void);

/**
 * \brief   The PMIC regulator output to the device input mapping can be
 *          different on different boards. This API can be used to provide
 *          a different mapping to the PMIC driver if the mapping does not
 *          match the default. Example table is shown below:
 *       ---------------------------------------------------------------------
 *       | Device voltage Rail            | Ptr to Regulator                 |
 *       ---------------------------------------------------------------------
 *       | PMHAL_PRCM_PMIC_REGULATOR_MPU  | PMHAL_TPS65037_REGULATOR_SMPS12  |
 *       | PMHAL_PRCM_PMIC_REGULATOR_CORE | PMHAL_TPS65037_REGULATOR_SMPS7   |
 *       | ....                                                              |
 *       | index (Refer                   | For index of the                 |
 *       | #pmhalPrcmPmicRegulatorId_t)   | gPmhalTps65218Regulator         |
 *       |                                | refer                            |
 *       |                                | #pmhalTps65218RegulatorId_t     |
 *       ---------------------------------------------------------------------
 *          This table when translated to code is as below:
 *       pmhalTps65218RegulatorMap_t regulatorMap[
 *          PMHAL_PRCM_PMIC_REGULATOR_COUNT] = {
 *              {
 *                  &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_SMPS12],
 *                  I2C_INSTANCE,
 *                  PMIC_I2C_SLAVE_ADDRESS
 *              },
 *              {
 *                  &gPmhalTps65218Regulator[PMHAL_TPS65218_REGULATOR_SMPS7],
 *                  I2C_INSTANCE,
 *                  PMIC_I2C_SLAVE_ADDRESS
 *              },
 *               ......
 *          };
 *
 * \param   regulatorMap    Pointer to the array of pointers which gives the
 *                          mapping. The array is defined as above.
 *
 * \return  None
 */
void PMHALTps65218ConfigureRegulatorMap(
    pmhalTps65218RegulatorMapPtr_t regulatorMap);

#ifdef __cplusplus
}
#endif

#endif

