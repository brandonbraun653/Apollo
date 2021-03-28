/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \file  PowerPMMC_deviceInit.h
 *
 *  \brief  This file declares the interface for configuring the device init.
 *          All Module, CLock and DPLL Init API interface .
 *
 */

#ifndef POWERPMMC_DEVICEINIT_H_
#define POWERPMMC_DEVICEINIT_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/drv/pm/include/pmmc/pmhal_pmmc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Package Type 1: Corresponds to 12x12 package */
#define POWERPRCM_PACKAGE_TYPE_0 (0U)

/** \brief Package Type 2: Corresponds to 15x15 package */
#define POWERPRCM_PACKAGE_TYPE_1 (1U)

/** \brief Package Type 1: Corresponds to 17x17 package */
#define POWERPRCM_PACKAGE_TYPE_2 (2U)

/** \brief Package Type 2: Corresponds to 23x23 package */
#define POWERPRCM_PACKAGE_TYPE_3 (3U)
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None  */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configures the system modules to desired Power State .
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                  PM_SUCCESS  If the desired power state was met.
 *                  PM_FAIL     If the desired power state was not met.
 */
int32_t PMMC_InitModulePowerState();

/**
 * \brief   Configure firmware on processors dedicated to power management
 *
 * \param   pImage   Pointer to firmware image to be loaded onto processor
 *
 * \param   imageSize   Size of image in bytes
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                  PM_SUCCESS  If the firmware was loaded and configured
 *                              successfully
 *                  PM_FAIL     If an error occurred during firmware load and
 *                              configure
 */
int32_t PMMC_ConfigFirmware(const void *pImage, uint32_t imageSize);

/**
 * \brief   Cleanup elements related to usage of the PM-dedicated firmware
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                  PM_SUCCESS  If the firmware cleanup completed
 *                              successfully
 *                  PM_FAIL     If an error occurred during firmware cleanup
 */
int32_t PMMC_CleanupFirmware(void);

#ifdef __cplusplus
}
#endif

#endif /* POWERPMMC_DEVICEINIT_H_ */

