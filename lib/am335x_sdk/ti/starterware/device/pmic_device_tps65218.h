/**
 *  \file  pmic_device_tps65218.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the PMIC device TPS65218.
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

#ifndef PMIC_DEVICE_TPS65218_H_
#define PMIC_DEVICE_TPS65218_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates types of PMIC device register protection level. */
typedef enum pmicDeviceTps65218RegProtectLevel
{
    PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_NONE    = 0x00U,
    /**< Register has no protection. */
    PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_1       = 0x01U,
    /**< Register protection level1. */
    PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_2       = 0x02U,
    /**< Register protection level2. */
    PMIC_DEVICE_TP65218_REG_PROTECT_LEVEL_INVALID = 0x03U,
    /**< Invalid Register protection level. */
}pmicDeviceTps65218GetRegProtectLevel_t;

/** \brief Enumerates types of PMIC device power sources. */
typedef enum pmicDeviceTps65218OutputPowerSource
{
    PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC1 = 0x01U,
    /**< Power Source 1. */
    PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC2 = 0x02U,
    /**< Power Source 2. */
    PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC3 = 0x03U,
    /**< Power Source 3. */
    PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC4 = 0x04U,
    /**< Power Source 4. */
    PMIC_DEVICE_TP65218_OUTPUT_POWER_SOURCE_DCDC5 = 0x05U,
    /**< Power Source 5. */
}pmicDeviceTps65218OutputPowerSource_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Initialize PMIC device of board.
 *
 * \param  devId      PMIC device ID.
 * \param  devInst    PMIC device instance.
 *
 * \retval S_PASS   PMIC initialization successful.
 * \retval E_FAIL   PMIC initialization failed.
 */
int32_t PMICDevTps65218Init(uint32_t devId, uint32_t devInst);

/**
 * \brief  Set voltage of a rail.
 *
 * \param  devId              PMIC device ID.
 * \param  devInst            PMIC device instance.
 * \param  outputPowerSource  PMIC output power source.
 * \param  voltageMv          Voltage of rail.
 *
 * \retval S_PASS             Successfully configured given output power source.
 * \retval E_FAIL             Failed to configure given output power source.
 */
int32_t PMICDevTps65218SetOutputVoltage(uint32_t devId,
                                        uint32_t devInst,
                                        uint32_t outputPowerSource,
                                        uint32_t voltageMv);

/**
 * \brief  Read voltage of a rail.
 *
 * \param  devId              PMIC device ID.
 * \param  devInst            PMIC device instance.
 * \param  outputPowerSource  PMIC output power source.
 *
 * \retval Voltage in mV.
 */
uint32_t PMICDevTps65218GetOutputVoltage(uint32_t devId,
                                         uint32_t devInst,
                                         uint32_t outputPowerSource);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PMIC_DEVICE_TPS65218_H_ */
