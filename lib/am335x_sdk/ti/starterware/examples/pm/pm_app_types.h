/**
 *  \file  pm_app_types.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the PM.
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

#ifndef PM_APP_TYPES_H_
#define PM_APP_TYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "pm_app_module_cfg.h"

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

/**
 *
 * \brief Device Packaging variations.
 * TBD: Update for AM43xx
 *
 */
typedef enum pmAppSleepMode
{
    PM_APP_SLEEP_MODE_DS0     = 0U,
    /**< No suspend configuration is selected for module */
    PM_APP_SLEEP_MODE_DS1     = 1U,
    /**< Save context of module */
    PM_APP_SLEEP_MODE_STANDBY = 2U,
    /**< Halt module */
    PM_APP_SLEEP_MODE_MAX = PM_APP_SLEEP_MODE_STANDBY,
    /**< Halt module */
} pmAppSleepMode_t;

typedef struct pmAppModuleInfo
{
    uint32_t moduleId;
    /**< Module ID. */
    uint32_t moduleInst;
    /**< Instance of module. */
}pmAppModuleInfo_t;

typedef struct pmAppModuleSelCfg
{
    uint32_t moduleId;
    /**< Module ID. */
    uint32_t moduleInst;
    /**< Instance of module. */
    uint32_t sel;
    /**< Configure module for suspend. */
}pmAppModuleSelCfg_t;

typedef struct pmAppDevSelCfg
{
    uint32_t devId;
    /**< Device ID. */
    uint32_t devInst;
    /**< Instances of device. */
    uint32_t sel;
    /**< Configure device for suspend. */
}pmAppDevSelCfg_t;

typedef struct pmAppWakeSrcCfg
{
    uint32_t moduleId;
    /**< Module ID. */
    uint32_t moduleInst;
    /**< Instance of module. */
    uint32_t wakeCfgType;
    /**< Type of wake configuration of the module. */
    uint32_t wakeCfgInst;
    /**< Instance of wake configuration for the module. */
    void *pWakeCfg;
    /**< Wake configuration for the module. */
}pmAppWakeSrcCfg_t;

typedef struct pmAppWakeSrcSelCfg
{
    pmAppWakeSrcCfg_t wakeSrc;
    /**< Module ID. */
    uint32_t sel;
    /**< Configure device for suspend. */
}pmAppWakeSrcSelCfg_t;

typedef struct pmAppPwrDomainCfg
{
    uint32_t pwrDomain;
    /**< Power domain. */
    uint32_t suspendState;
    /**< State in suspend. */
}pmAppPwrDomainCfg_t;

typedef struct pmAppPwrModeCfg
{
    uint32_t pwrMode;
    /**< Power mode. */
    pmAppPwrDomainCfg_t *pPwrDomainCfg;
    /**< Power domains configuration. */
    uint32_t maxPwrDomains;
    /**< Number of power domain configurations. */
    pmAppWakeSrcCfg_t *pWakeSrcList;
    /**< Possible wake source configuration in power domain. */
    uint32_t maxWakeSrc;
    /**< Number of wake source configurations. */
}pmAppPwrModeCfg_t;

typedef struct pmAppInitObj
{
    pmAppModuleInterfObj_t *pModulesInterf;
    /**< Interface to configure module. */
    uint32_t maxModuleIds;
    /**< Number of modules. */
    pmAppModuleInstObj_t *pModulesCfg;
    /**< Configuration of modules. */
    uint32_t maxModules;
    /**< Number of power modes. */
    pmAppPwrModeCfg_t *pPwrModeCfg;
    /**< Configuration of power modes. */
    uint32_t maxPwrModes;
    /**< Number of power modes. */
    pmAppModuleSelCfg_t *pBootModules;
    /**< List of boot modules. */
    uint32_t maxBootModules;
    /**< Number of boot modules. */
    pmAppModuleSelCfg_t *pModulesSkip;
    /**< List of modules to skip for PM configuration. */
    uint32_t maxModulesSkip;
    /**< Number of skipped modules. */
    pmAppModuleSelCfg_t *pSecureModules;
    /**< List of modules to skip for PM configuration. */
    uint32_t maxSecureModules;
    /**< Number of secure modules. */
}pmAppInitObj_t;

typedef struct pmAppCfgObj
{
    uint32_t pwrMode;
    /**< Power mode. */
    pmAppInitObj_t *pInitObj;
    /**< Init configurations. */
    pmAppDevSelCfg_t *pDevicesSkipList;
    /**< List of devices to skip for PM configuration. */
    uint32_t maxDeviceSkip;
    /**< Number of devices to skip. */
    pmAppWakeSrcSelCfg_t *pWakeSrcList;
    /**< Modules configured as wake source. */
    uint32_t maxWakeSrc;
    /**< Number of wake source configurations. */
    pmAppModuleSelCfg_t *pSysModulesList;
    /**< System modules configuration for PM. */
    uint32_t maxSysModules;
    /**< Number of system modules. */
    pmAppModuleSelCfg_t *pInterfModulesList;
    /**< Interface modules configuration for PM. */
    uint32_t maxInterfModules;
    /**< Number of wake source configurations. */
}pmAppCfgObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef PM_APP_TYPES_H_ */
