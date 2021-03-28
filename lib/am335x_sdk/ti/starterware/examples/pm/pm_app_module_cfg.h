/**
 *  \file  pm_app_module_cfg.h
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

#ifndef PM_APP_MODULE_CFG_H_
#define PM_APP_MODULE_CFG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *
 * \brief Device Packaging variations.
 * TBD: Update for AM43xx
 *
 */
typedef enum pmAppModuleSuspendCfg
{
    PM_APP_MODULE_SUSPEND_CFG_MIN          = 0x0,
    /**< Indicates the minimum supported value in this enum */
    PM_APP_MODULE_SUSPEND_CFG_NONE         = PM_APP_MODULE_SUSPEND_CFG_MIN,
    /**< No suspend configuration is selected for module */
    PM_APP_MODULE_SUSPEND_CFG_SAVE_CONTEXT = 0x1,
    /**< Save context of module */
    PM_APP_MODULE_SUSPEND_CFG_HALT         = 0x2,
    /**< Halt module */
    PM_APP_MODULE_SUSPEND_CFG_DISABLE      = 0x3,
    /**< Disable module */
    PM_APP_MODULE_SUSPEND_CFG_MAX          = PM_APP_MODULE_SUSPEND_CFG_DISABLE
    /**< Indicates the maximum supported value in this enum */
} pmAppModuleSuspendCfg_t;

/**
 *
 * \brief Device Packaging variations.
 * TBD: Update for AM43xx
 *
 */
typedef enum pmAppModuleSuspendCfgMask
{
    PM_APP_MODULE_SUSPEND_CFG_MASK_NONE         = 0U,
    /**< No suspend configuration is selected for module */
    PM_APP_MODULE_SUSPEND_CFG_MASK_SAVE_CONTEXT = (1U << 0U),
    /**< Save context of module */
    PM_APP_MODULE_SUSPEND_CFG_MASK_HALT         = (1U << 1U),
    /**< Halt module */
    PM_APP_MODULE_SUSPEND_CFG_MASK_DISABLE      = (1U << 2U),
    /**< Disable module */
} pmAppModuleSuspendCfgMask_t;

/**
 *
 * \brief Device Packaging variations.
 * TBD: Update for AM43xx
 *
 */
typedef enum pmAppModuleResumeCfg
{
    PM_APP_MODULE_RESUME_CFG_MIN             = 0x0,
    /**< Indicates the minimum supported value in this enum */
    PM_APP_MODULE_RESUME_CFG_NONE            = PM_APP_MODULE_RESUME_CFG_MIN,
    /**< No suspend configuration is selected for module */
    PM_APP_MODULE_RESUME_CFG_RESTORE_CONTEXT = 0x1,
    /**< Save context of module */
    PM_APP_MODULE_RESUME_CFG_RESUME          = 0x2,
    /**< Halt module */
    PM_APP_MODULE_RESUME_CFG_ENABLE          = 0x3,
    /**< Disable module */
    PM_APP_MODULE_RESUME_CFG_MAX             = PM_APP_MODULE_RESUME_CFG_ENABLE
    /**< Indicates the maximum supported value in this enum */
} pmAppModuleResumeCfg_t;

/**
 *
 * \brief Device Packaging variations.
 * TBD: Update for AM43xx
 *
 */
typedef enum pmAppModuleResumeCfgMask
{
    PM_APP_MODULE_RESUME_CFG_MASK_NONE            = 0U,
    /**< No suspend configuration is selected for module */
    PM_APP_MODULE_RESUME_CFG_MASK_RESTORE_CONTEXT = (1U << 0U),
    /**< Save context of module */
    PM_APP_MODULE_RESUME_CFG_MASK_RESUME          = (1U << 1U),
    /**< Halt module */
    PM_APP_MODULE_RESUME_CFG_MASK_ENABLE          = (1U << 2U),
    /**< Disable module */
} pmAppModuleResumeCfgMask_t;

typedef struct pmAppModuleInstObj
{
    uint32_t moduleId;
    /**< Power domain of the module. */
    uint32_t moduleInst;
    /**< Power domain of the module. */
    uint32_t activeStatus;
    /**< Module active mode status. */
    uint32_t cfgPmEnable;
    /**< Configure for suspend. */
    void *pContext;
    /**< Context of all module instances. */
}pmAppModuleInstObj_t;

typedef struct pmAppModuleInterfObj
{
    uint32_t noOfInst;
    /**< Number of instances of the module. */
    void *pWakeSrcConfig;
    /**< Possible wake source configurations. */
    int32_t (*pFnContextSave) (uint32_t moduleInst, void *pModuleCfg, void *pContext);
    /**< Function pointer to save context on the given instance of module. */
    int32_t (*pFnContextRestore) (uint32_t moduleInst, void *pModuleCfg, void *pContext);
    /**< Function pointer to restore context on the given instance of module. */
    int32_t (*pFnHalt) (uint32_t moduleInst);
    /**< Function pointer to halt the given instance of module. */
    int32_t (*pFnResume) (uint32_t moduleInst);
    /**< Function pointer to resume the given instance of module. */
    int32_t (*pFnEnable) (uint32_t moduleInst, uint32_t enableModule);
    /**< Function pointer to enable the given instance of module. */
    int32_t (*pFnWakeEnable) (uint32_t moduleInst, uint32_t wakeType,
        void *pConfigParam, uint32_t enableWake);
    /**< Function pointer to enable the given instance of module. */
}pmAppModuleInterfObj_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

extern pmAppModuleInterfObj_t *gPmAppModuleCfg[];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef PM_APP_MODULE_CFG_H_ */
