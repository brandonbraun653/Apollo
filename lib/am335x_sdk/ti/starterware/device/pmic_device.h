/**
 *  \file  pmic_device.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the PMIC devices.
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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

#ifndef PMIC_DEVICE_H_
#define PMIC_DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief PMIC DCDC3 output voltage value to set 1.35V for DDR3L. */
#define DCDC3_OUTPUT_1_35V                         (0x12U)
#define DCDC3_CONTROL_REG                          (0x18U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates types of PMIC device power sources. */
typedef enum pmicDeviceInputPowerSourceType
{
    PMIC_DEVICE_INPUT_POWER_SOURCE_TYPE_AC  = 0x00U,
    /**< AC power input. */
    PMIC_DEVICE_INPUT_POWER_SOURCE_TYPE_USB = 0x01U
    /**< USB power input. */
}pmicDeviceInputPowerSourceType_t;

/** \brief Structure holding the PMIC configuration parameters. */
typedef struct pmicDeviceData
{
    uint32_t devId;
    /**< PMIC device ID. */
    uint32_t numOutputPowerSource;
    /**< Output power sources in PMIC. */
}pmicDeviceData_t;

/** \brief Enumerates the PMIC device Rail type. */
typedef enum pmicDeviceRailType
{
    PMIC_DEVICE_RAIL_TYPE_MPU = 1U,
    /**< PMIC Device MPU Rail. */
    PMIC_DEVICE_RAIL_TYPE_CORE = 2U
    /**< PMIC Device Core Rail. */
}pmicDeviceRailType;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API returns the related data of PMIC connected to the board.
 *
 * \param devId     The device id of the PMIC device.
 *
 * \retval enet_phy_device_data Pointer to the PMIC device data.
 */
pmicDeviceData_t *PMICGetDeviceData(uint32_t devId);

/**
 * \brief This API returns the list of PMIC devices available.
 *
 * \retval pmic_device_id_list Pointer to the PMIC devices list
 */
uint32_t *PMICGetDeviceIdList(void);

/**
 * \brief Initialize PMIC device of board.
 *
 * \retval S_PASS    PMIC initialization successful.
 * \retval E_FAIL    PMIC initialization failed.
 */
int32_t PMICInit(void);

/**
 * \brief  Set voltage of a rail.
 *
 * \param  railType   Rail of SoC to be configured.
 * \param  voltageMv  Voltage of rail in mV.
 *
 * \retval S_PASS     Successfully configured given rail voltage.
 * \retval E_FAIL     Failed to configure given rail voltage.
 */
int32_t PMICSetRailVoltage(uint32_t railType, uint32_t voltageMv);

/**
 * \brief  Read voltage of a rail.
 *
 * \param  railType   Rail of SoC to be read.
 *
 * \retval S_PASS     Successfully read given rail voltage.
 * \retval E_FAIL     Failed to read given rail voltage.
 */
uint32_t PMICGetRailVoltage(uint32_t railType);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PMIC_DEVICE_H_ */
