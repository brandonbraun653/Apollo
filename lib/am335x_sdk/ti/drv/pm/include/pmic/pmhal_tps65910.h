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
 *  \file  pmhal_tps65910.h
 *
 *  \brief The Power Management IC (PMIC) tps65910 specific API definition.
 *
 *         The APIs defined here are to control the voltage of the
 *         PMIC rails and to query the status.
 */

#ifndef PM_TPS65910_H_
#define PM_TPS65910_H_

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
 * \brief       PMHAL_TPS65910_SMPS Regulator Register Fields Mask Field
 *              PMHAL_TPS65910_SMPSxx_CTRL.ST
 *      1:0     ST: PMHAL_TPS65910_SMPS State Mode
 *              0x00: OFF  (Default)
 *              0x01: ON, high power (ACTIVE)
 *              0x10: OFF
 *              0x11: ON, low power (SLEEP)
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_ST_MASK               (0x03U)

/**
 * \brief       PMHAL_TPS65910_SMPS Regulator Register Fields Shift Field
 *              PMHAL_TPS65910_SMPSxx_CTRL.ST
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_ST_SHIFT              (0x0U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_CTRL.TSTEP Mask.
 *      4:2     TSTEP: PMHAL_TPS65910_SMPS Time Step
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_TSTEP_MASK            (0x1CU)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_CTRL.TSTEP Shift.
 *      4:2     TSTEP: PMHAL_TPS65910_SMPS Time Step
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_TSTEP_SHIFT           (2U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_CTRL.VGAIN_SEL Mask.
 *      7:6     VGAIN_SEL: PMHAL_TPS65910_SMPS Output Voltage Gain
 *              0x00: x1  (Default)
 *              0x01: x1
 *              0x10: x2
 *              0x11: x3
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_VGAIN_SEL_MASK        (0xC0U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_CTRL.VGAIN_SEL Shift.
 *      7:6     VGAIN_SEL: PMHAL_TPS65910_SMPS Output Voltage Gain
 */
#define PMHAL_TPS65910_SMPSxx_CTRL_VGAIN_SEL_SHIFT       (6U)

/** \brief       Number of possible SMPS VGAIN_SEL values */
#define SMPS_CTRL_MAX_VGAIN_SEL                   (4U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_OP/SR.SEL Mask.
 *      6:0     SEL: PMHAL_TPS65910_SMPS Output Voltage
 *              0x0000000 => 0V (OFF)
 *              0x0000001 - 0x0000011 => 0.6V
 *              Step voltage is 0.0125V (12.5mv)
 *              0x1001011 - 1.5V (max)
 *              Vout = ((SEL[6:0] * 12.5mV)/1000 + 0.5625V) * VGAIN_SEL
 */
#define PMHAL_TPS65910_SMPSxx_SEL_MASK                   (0x7FU)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_OP/SR.SEL Shift.
 */
#define PMHAL_TPS65910_SMPSxx_SEL_SHIFT                  (0U)

/** \brief       Number of possible SMPS VGAIN_SEL values */
#define SMPS_CTRL_SEL_OFFSET_UV                          (562500U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_OP.CMD Mask.
 *      7       CMD: SmartReflex command
 *              0x0: VDDx_OP_REG.SEL is applied.
 *              0x1: VDDx_SR_REG.SEL is applied.
 */
#define PMHAL_TPS65910_SMPSxx_OP_CMD_MASK                (0x80U)

/**
 * \brief       PMHAL_TPS65910_SMPSxx_OP.CMD Shift.
 */
#define PMHAL_TPS65910_SMPSxx_OP_CMD_SHIFT               (7U)

/**
 * \brief   PMHAL_TPS65910_LDO Regulator Register Fields:
 *
 *      PMHAL_TPS65910_LDOxx_CTRL.ST Mask
 *      1:0     ST: PMHAL_TPS65910_LDO State Mode
 *              0x00: OFF  (Default)
 *              0x01: ON, high power (ACTIVE)
 *              0x10: OFF
 *              0x11: ON, low power (SLEEP)
 */
#define PMHAL_TPS65910_LDOxx_CTRL_ST_MASK                (0x03U)

/**
 * \brief   PMHAL_TPS65910_LDO Regulator Register
 *          PMHAL_TPS65910_LDOxx_CTRL.ST Shift
 */
#define PMHAL_TPS65910_LDOxx_CTRL_ST_SHIFT               (0U)

/** \brief       First Possible Control State Macro for Off. */
#define CTRL_STATE_OFF0                      (0U)
/** \brief       Second Possible Control State Macro for Off. */
#define CTRL_STATE_OFF1                      (2U)

/**
 * \brief       PMHAL_TPS65910_LDOxx_CTRL.SEL Mask
 *      3:2     SEL: PMHAL_TPS65910_LDO Output Voltage
 */
#define PMHAL_TPS65910_LDOxx_CTRL_SEL_MASK               (0x0CU)

/** \brief       PMHAL_TPS65910_LDOxx_CTRL.SEL Shift */
#define PMHAL_TPS65910_LDOxx_CTRL_SEL_SHIFT              (2U)

/** \brief       Number of possible LDO SEL values */
#define LDO_CTRL_MAX_SEL                     (4U)

/**
 * \brief Slave Address:
 *
 * The TPS65910 PMIC uses the standard 7-bit slave I2C address to access
 * the register address space. This PMIC has 1 internal pages each of 256
 * bytes. The register address is 8-bits and can address one page. Multiple
 * pages are addressed using different slave addresses. The table below
 * gives the slave address for the register pages as programmed in the
 * AM335x device EVMs.
 */
#define PMHAL_TPS65910_SLAVE_ADDR_COUNT     (1U)

/**
 *   \brief SLAVE Address Page 0
 *
 *    Page    Phy Addr Range      Slave Address      OTP choice     Register
 *    ------------------------------------------------------------------------
 *     0      0x000 - 0x0FF       0x2D                0x2D          All regs
 */
#define PMHAL_TPS65910_SLAVE_ADDR_PAGE0     (0x2DU)

/**
 *   \brief SLAVE SmartReflex Address Page 0
 *
 *    Page    Phy Addr Range      Slave Address      OTP choice     Register
 *    ------------------------------------------------------------------------
 *     0      0x000 - 0x0FF       0x12                0x12          All regs
 */
#define PMHAL_TPS65910_SLAVE_ADDR_SR_PAGE0  (0x12U)

/** \brief Invalid Page Address */
#define PMHAL_TPS65910_SLAVE_ADDR_INVALID   (0xFFU)

/** \brief Regulator Type for SMPS */
#define PMHAL_TPS65910_RTYPE_SMPS                (1U)

/** \brief Regulator Type for LDO */
#define PMHAL_TPS65910_RTYPE_LDO                 (2U)

/** \brief The I2C number to which the voltage rail is connected */
#define PMHAL_TPS65910_I2C_NUM_1                 (0x0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief Abstract Enumeration for the Regulators.
 */
typedef enum pmhalTps65910RegulatorId
{
    PMHAL_TPS65910_REGULATOR_INVALID = -1,
    /**< Invalid PMIC regulator ID */
    PMHAL_TPS65910_REGULATOR_MIN = 0,
    /**< Minimum Abstracted PMIC Regulator ID */
    PMHAL_TPS65910_REGULATOR_LDOVRTC = PMHAL_PRCM_PMIC_REGULATOR_MIN,
    /**< Abstracted PMIC Regulator ID for LDOVRTC */
    PMHAL_TPS65910_REGULATOR_SMPSVIO = 1,
    /**< Abstracted PMIC Regulator ID for SMPSVIO */
    PMHAL_TPS65910_REGULATOR_SMPSVDD1 = 2,
    /**< Abstracted PMIC Regulator ID for SMPSVDD1 */
    PMHAL_TPS65910_REGULATOR_SMPSVDD2 = 3,
    /**< Abstracted PMIC Regulator ID for SMPSVDD2 */
    PMHAL_TPS65910_REGULATOR_SMPSVDD3 = 4,
    /**< Abstracted PMIC Regulator ID for SMPSVDD3 */
    PMHAL_TPS65910_REGULATOR_LDOVDIG1 = 5,
    /**< Abstracted PMIC Regulator ID for LDOVDIG1 */
    PMHAL_TPS65910_REGULATOR_LDOVDIG2 = 6,
    /**< Abstracted PMIC Regulator ID for LDOVDIG2 */
    PMHAL_TPS65910_REGULATOR_LDOVAUX1 = 7,
    /**< Abstracted PMIC Regulator ID for LDOVAUX1 */
    PMHAL_TPS65910_REGULATOR_LDOVAUX2 = 8,
    /**< Abstracted PMIC Regulator ID for LDOVAUX2 */
    PMHAL_TPS65910_REGULATOR_LDOVAUX33 = 9,
    /**< Abstracted PMIC Regulator ID for LDOVAUX33 */
    PMHAL_TPS65910_REGULATOR_LDOVMMC = 10,
    /**< Abstracted PMIC Regulator ID for LDOVMMC */
    PMHAL_TPS65910_REGULATOR_LDOVPLL = 11,
    /**< Abstracted PMIC Regulator ID for LDOVPLL */
    PMHAL_TPS65910_REGULATOR_LDOVDAC = 12,
    /**< Abstracted PMIC Regulator ID for LDOVDAC */
    PMHAL_TPS65910_REGULATOR_MAX = (PMHAL_TPS65910_REGULATOR_LDOVDAC + 1)
                                    /**< Maximum Abstracted PMIC Regulator ID */
} pmhalTps65910RegulatorId_t;

/**
 * \brief TPS65910 SMPS Regulator SEL description structure
 */
typedef struct pmhalTps65910SmpsSel
{
    uint8_t vGain;
    /**< Gain multiplier supported by the VGAIN_SEL value. */
    uint8_t vGainSel;
    /**< VGAIN_SEL value corresponding to a gain.*/
    uint16_t minVolt;
    /**< Minimum voltage supported by the gain in mV. */
    uint16_t minVoltSel;
    /**< SEL value corresponding to the minVolt for the gain.*/
    uint16_t maxVolt;
    /**< Maximum voltage supported by the gain in mV. */
    uint16_t maxVoltSel;
    /**< SEL value corresponding to the maxVolt for the gain.*/
} pmhalTps65910SmpsSel_t;

/**
 * \brief TPS65910 LDO Regulator SEL description structure
 */
typedef struct pmhalTps65910LdoSel
{
    uint16_t volt;
    /**< Voltage supported by the SEL value in mV. */
    uint8_t  voltSel;
    /**< SEL value corresponding to a voltage.*/
} pmhalTps65910LdoSel_t;

/**
 * \brief TPS65910 Regulator description structure
 */
typedef struct pmhalTps65910RegulatorProp
{
    uint16_t minVolt;
    /**< Minimum voltage supported by the regulator in mV. */
    uint16_t maxVolt;
    /**< Maximum voltage supported by the regulator in mV. */
    uint16_t  stepVolt;
    /**< Step voltage in uV. */
    uint8_t  type;
    /**< The regulator type namely PMHAL_TPS65910_RTYPE_SMPS or
     * PMHAL_TPS65910_RTYPE_LDO. */
    uint16_t slewRate;
    /**< The voltage ramp delay in uV/us */
    union
    {
        const pmhalTps65910SmpsSel_t *smpsSel;
        /**< Pointer to array of SMPS SEL entries */
        const pmhalTps65910LdoSel_t *ldoSel;
        /**< Pointer to array of LDO SEL entries */
    } pSel_u;
    /**< Union of regulator SEL property structure pointers */
    uint32_t ctrlRegAddr;
    /**< The regulator control register address.*/
    uint32_t voltRegAddr;
    /**< The regulator voltage register address. Not all
     *   regulators have the voltage register; if not present the value
     *   of this field is expected to be NULL. */
    uint32_t voltSrRegAddr;
    /**< The regulator SmartReflex voltage register address. Not all
     *   regulators have the SR register; if not present the value
     *   of this field is expected to be NULL. */
} pmhalTps65910RegulatorProp_t;

/** \brief  Pointer to pmhalTps65910RegulatorProp_t structure.
 */
typedef const pmhalTps65910RegulatorProp_t *pmhalTps65910RegulatorPtr_t;

typedef struct pmhalTps65910RegulatorMap
{
    pmhalTps65910RegulatorPtr_t regulatorMap;
    /**< Pointer to the regulator properties */
    uint8_t                     i2cInstanceNum;
    /**< SoC I2C instance number to which the regulator of the PMIC will be
     *   connected to.
     */
} pmhalTps65910RegulatorMap_t;

/** \brief Pointer to the structure pmhalTps65910RegulatorMap_t */
typedef pmhalTps65910RegulatorMap_t *const pmhalTps65910RegulatorMapPtr_t;

/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */

/* Array of the properties of all the SMPS and LDO PMIC regulators */
extern const pmhalTps65910RegulatorProp_t gPmhalTps65910Regulator[
    PMHAL_TPS65910_REGULATOR_MAX];

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
const pmhalPmicOperations_t *PMHALTps65910GetPMICOps(void);

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
 *       | #pmhalPrcmPmicRegulatorId_t)   | gPmhalTps65910Regulator         |
 *       |                                | refer                            |
 *       |                                | #pmhalTps65910RegulatorId_t     |
 *       ---------------------------------------------------------------------
 *          This table when translated to code is as below:
 *       pmhalTps65910RegulatorMap_t regulatorMap[
 *          PMHAL_PRCM_PMIC_REGULATOR_COUNT] = {
 *              {
 *                  &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_SMPS12],
 *                  I2C_INSTANCE,
 *                  PMIC_I2C_SLAVE_ADDRESS
 *              },
 *              {
 *                  &gPmhalTps65910Regulator[PMHAL_TPS65910_REGULATOR_SMPS7],
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
void PMHALTps65910ConfigureRegulatorMap(
    pmhalTps65910RegulatorMapPtr_t regulatorMap);

#ifdef __cplusplus
}
#endif

#endif

