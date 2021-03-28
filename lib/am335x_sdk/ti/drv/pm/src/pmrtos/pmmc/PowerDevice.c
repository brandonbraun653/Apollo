/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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

/*
 * PowerDevice.c
 *
 * Power API implementation for the following devices:
 *     SOC_K2G
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <ti/osal/HwiP.h>

#include <Power.h>
#include <PowerExtended.h>
#include <PowerDevice.h>
#include <PowerPMMC_deviceInit.h>

#include "List.h"
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/pmhal.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                      Internal Structures and Enums                         */
/* ========================================================================== */

/*
 *  Internal structure defining Power module state.
 */
typedef struct PowerDevice_ModuleState {
    List_List    notifyList;       /* List of registered notify callback
                                    * functions */
    bool         notifyRegistered; /* notify function is registered */
    unsigned int constraintMask;   /* constraint bitfield */
    unsigned int state;            /* power module state */
    unsigned int currentPerfLevel; /* current performance level */
    bool         enablePolicy;     /* power policy is enable during idle loop */
    bool         perfInitialized;  /* performance control enabled */
    uint8_t      constraintCounts[Power_NUMCONSTRAINTS]; /* constraint count */
    uint32_t     dependencyCount[PMHAL_PMMC_MOD_COUNT -
                    PMHAL_PMMC_MOD_LOWER_BOUND]; /* Dependency count for every
                                                  * module element */
} PowerDevice_ModuleState_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/*
 *  ======== notify ========
 */
static uint32_t notify(uint32_t eventType, uint32_t eventArg);

/*
 *  ======== getModuleId ========
 */
static uint32_t getModuleId();

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/*
 *  ======== PowerDevice_config ========
 *  Power configuration global variable specified by the application
 */
extern PowerDevice_Cfg_t  PowerDevice_config;

/*
 *  ======== PowerDevice_module ========
 *  Power internal module statue global variable
 *
 * PowerDevice_module is placed in the noinit section as the PowerDevice_module
 * may be in use even before the code reaches main.
 * Placing the PowerDevice_module structure in noinit section allows
 * the application to have full control on when the structure is initialized
 * (in a reset function before main or after reaching main).
 */
#if defined (__ARM_ARCH_7A__)
/* For the A15 GCC Compiler */
PowerDevice_ModuleState_t PowerDevice_module __attribute__ ((section (".noinit")));
#elif defined (__TI_ARM_V7M4__)
/* For the M4 TI Compiler */
#pragma NOINIT(PowerDevice_module)
PowerDevice_ModuleState_t PowerDevice_module;
#else
/* For the C66x TI Compiler */
PowerDevice_ModuleState_t PowerDevice_module;
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== Power_init ========
 *  Initialize the Power state
 */
unsigned int Power_init()
{
    unsigned int retVal = Power_SOK;

    if (PowerDevice_config.swInit == TRUE)
    {
        memset(PowerDevice_module.dependencyCount,0,
               sizeof(PowerDevice_module.dependencyCount));
        memset(PowerDevice_module.constraintCounts,0,
               sizeof(PowerDevice_module.constraintCounts));
        PowerDevice_module.notifyList.head  = NULL;
        PowerDevice_module.notifyList.tail  = NULL;
        PowerDevice_module.notifyRegistered = FALSE;
        PowerDevice_module.enablePolicy     = FALSE;
        PowerDevice_module.perfInitialized  = FALSE;
        PowerDevice_module.constraintMask   = 0U;
        PowerDevice_module.state            = Power_ACTIVE;
        PowerDevice_module.currentPerfLevel = 0U;
    }

    /* If performance control is enabled, go to the initial performance
     * level */
    if (PowerDevice_config.enablePerf)
    {
        PowerDevice_module.perfInitialized  = TRUE;
        PowerDevice_module.currentPerfLevel =
            PowerDevice_config.initialPerfLevel;
    }

    /* If there is a configured policy init function, call it now... */
    if (PowerDevice_config.policyInitFxn != NULL)
    {
        (*(PowerDevice_config.policyInitFxn))();
    }

    if (PowerDevice_config.hwInit == TRUE)
    {
#if (PowerDevice_CAPABILITY_PmCoprocessor == 1)
        if (retVal == Power_SOK)
        {
            /* Configure coprocessor firmware */
            retVal = PMMC_ConfigFirmware(PowerDevice_config.pFirmware,
                                         PowerDevice_config.sizeFirmware);
        }
#endif

        if (retVal == Power_SOK)
        {
            retVal = PMMC_InitModulePowerState();
            if (retVal == Power_SOK)
            {
                retVal = notify(Power_EV_DONE_MODULEPOWERSTATE, 0U);
            }
        }
    }

    return retVal;
}

/*
 *  ======== Power_deinit ========
 *  Deinitialize setup from Power_init
 */
unsigned int Power_deinit()
{
    unsigned int retVal = Power_SOK;

#if (PowerDevice_CAPABILITY_PmCoprocessor == 1)
    retVal = PMMC_CleanupFirmware();
#endif

    /* if there is a configured policy deinit function, call it now ... */
    if (PowerDevice_config.policyDeinitFxn != NULL)
    {
        (*(PowerDevice_config.policyDeinitFxn))();
    }

    return retVal;
}

/*
 *  ======== Power_enablePolicy ========
 *  Enable the power policy to run on each pass through the idle loop
 */
void Power_enablePolicy(void)
{
    PowerDevice_module.enablePolicy = TRUE;
}

/*
 *  ======== Power_disablePolicy ========
 *  Disable the power policy from running on each pass through the idle loop
 */
void Power_disablePolicy(void)
{
    PowerDevice_module.enablePolicy = FALSE;
}

unsigned int PowerDevice_Cfg_Init(PowerDevice_Cfg_t * PowerDevice_config)
{
    unsigned int     retVal = Power_EFAIL;
    if (PowerDevice_config != NULL)
    {
        PowerDevice_config->policyInitFxn    = NULL;
        PowerDevice_config->policyFxn        = NULL;
        PowerDevice_config->initialPerfLevel = 0U;
        PowerDevice_config->enablePolicy     = (Bool)FALSE;
        PowerDevice_config->enablePerf       = (Bool)FALSE;
        PowerDevice_config->hwInit           = (Bool)FALSE;
        PowerDevice_config->swInit           = (Bool)TRUE;
        PowerDevice_config->siliconPkgType   = 0U;
#if (PowerDevice_CAPABILITY_PmCoprocessor == 1)
        PowerDevice_config->pFirmware        = NULL;
        PowerDevice_config->sizeFirmware     = 0;
#endif
        retVal = Power_SOK;
    }
    return retVal;
}
/*
 *  ======== Power_getConstraintMask ========
 *  Get a bitmask indicating the constraints that have been registered with
 *  Power.
 */
unsigned int Power_getConstraintMask(void)
{
    return (PowerDevice_module.constraintMask);
}

/*
 *  ======== Power_getPerformanceLevel ========
 *  Get the current performance level.
 */
unsigned int Power_getPerformanceLevel(void)
{
    return (PowerDevice_module.currentPerfLevel);
}

/*
 *  ======== Power_getTransitionLatency ========
 *  Get the transition latency for a sleep state.  The latency is reported
 *  in units of microseconds.
 */
unsigned int Power_getTransitionLatency(unsigned int sleepState,
                                        unsigned int type)
{
    unsigned int latency = 0;

    if (type == Power_RESUME)
    {
        if (sleepState == Power_SLEEP)
        {
            latency = PowerDevice_RESUMETIMESLEEP;
        }
        else if (sleepState == Power_DEEPSLEEP)
        {
            latency = PowerDevice_RESUMETIMEDEEPSLEEP;
        }
    }
    else
    {
        if (sleepState == Power_SLEEP)
        {
            latency = PowerDevice_TOTALTIMESLEEP;
        }
        else if (sleepState == Power_DEEPSLEEP)
        {
            latency = PowerDevice_TOTALTIMEDEEPSLEEP;
        }
    }

    return (latency);
}

/*
 *  ======== Power_getTransitionState ========
 *  Get the current sleep transition state.
 */
unsigned int Power_getTransitionState(void)
{
    return (PowerDevice_module.state);
}

/*
 *  ======== Power_idleFunc ========
 *  Stub function to call the power policy from the OS idle loop.
 */
void Power_idleFunc()
{
    /* only call the policy function if this has been enabled */
    if (PowerDevice_module.enablePolicy)
    {
        if (PowerDevice_config.policyFxn != NULL)
        {
            (*(PowerDevice_config.policyFxn))();
        }
    }
}

/*
 *  ======== Power_registerNotify ========
 *  Register a function to be called upon a specific power event.
 */
unsigned int Power_registerNotify(Power_NotifyObj *pNotifyObj,
                                  unsigned int     eventTypes,
                                  Power_NotifyFxn  notifyFxn,
                                  uintptr_t        clientArg)
{
    unsigned int retVal = Power_SOK;

    if ((pNotifyObj == NULL) || (notifyFxn == NULL))
    {
        retVal = Power_EINVALIDPOINTER;
    }
    else
    {
        /* fill in notify object elements */
        pNotifyObj->eventTypes = eventTypes;
        pNotifyObj->notifyFxn  = notifyFxn;
        pNotifyObj->clientArg  = clientArg;

        /* place notify object on event notification queue */
        List_put(&PowerDevice_module.notifyList, (List_Elem *) pNotifyObj);
        PowerDevice_module.notifyRegistered = TRUE;
    }

    return retVal;
}

/*
 *  ======== Power_unregisterNotify ========
 *  Unregister for a power notification.
 */
void Power_unregisterNotify(Power_NotifyObj *pNotifyObj)
{
    uint32_t key;

    /* disable interrupts */
    key = HwiP_disable();

    /* remove notify object from its event queue */
    List_remove(&PowerDevice_module.notifyList, (List_Elem *) pNotifyObj);

    /* re-enable interrupts */
    HwiP_restore(key);
}

/*
 *  ======== Power_releaseConstraint ========
 *  Release a previously declared constraint.
 */
unsigned int Power_releaseConstraint(unsigned int constraintId)
{
    uintptr_t    key;
    uint8_t      count;
    unsigned int retVal = Power_SOK;

    if (constraintId >= Power_NUMCONSTRAINTS)
    {
        retVal = Power_EFAIL;
    }
    else
    {
        /* disable interrupts */
        key = HwiP_disable();

        /* get the count of the constraint */
        count = PowerDevice_module.constraintCounts[constraintId];

        if (count == 0)
        {
            retVal = Power_EFAIL;
        }
        else
        {
            /* decrement the count */
            count--;

            /* save the updated count */
            PowerDevice_module.constraintCounts[constraintId] = count;

            /* if constraint count reaches 0, remove constraint from mask */
            if (count == 0)
            {
                PowerDevice_module.constraintMask &= ~(1 << constraintId);
            }
        }

        /* re-enable interrupts */
        HwiP_restore(key);
    }

    return retVal;
}

/*
 *  ======== Power_setConstraint ========
 *  Declare an operational constraint.
 */
unsigned int Power_setConstraint(unsigned int constraintId)
{
    uintptr_t    key;
    unsigned int retVal = Power_SOK;

    if (constraintId >= Power_NUMCONSTRAINTS)
    {
        retVal = Power_EFAIL;
    }
    else
    {
        /* disable interrupts */
        key = HwiP_disable();

        /* set the specified constraint in the constraintMask */
        PowerDevice_module.constraintMask |= 1 << constraintId;

        /* increment the specified constraint count */
        PowerDevice_module.constraintCounts[constraintId]++;

        /* re-enable interrupts */
        HwiP_restore(key);
    }

    return retVal;
}

/*
 *  ======== Power_setPerformanceLevel ========
 *  Set a new performance level for the device.
 *  This function should only be called from Task context.
 *  For now A15 only supports dynamic opp change .
 */
unsigned int Power_setPerformanceLevel(unsigned int level)
{
    unsigned int retVal = Power_SOK;
#if defined (__ARM_ARCH_7A__)
    uint32_t     hwiKey;
    uint32_t     constraints;
    uint32_t     newFreq;

    /* return immediately if performance control not enabled and initialized */
    if (!PowerDevice_module.perfInitialized)
    {
        retVal = Power_EFAIL;
    }
    else
    {
        /* disable interrupts */
        hwiKey = HwiP_disable();

        /* check to make sure not busy with another transition */
        if (Power_getTransitionState() != Power_ACTIVE)
        {
            retVal = Power_EBUSY;
        }
        /* validate the performance level */
        else if (level >= Power_NUMPERFLEVELS)
        {
            retVal = Power_EFAIL;
        }
        else
        {
            /* check if there is a constraint prohibiting the transition */
            constraints = Power_getConstraintMask();

            /* check if constraint set to prohibit *any* perf changes */
            if ((constraints & (1 << Power_DISALLOW_PERF_CHANGES)) != 0)
            {
                retVal = Power_ECHANGE_NOT_ALLOWED;
            }
            /* now check if a constraint is set for this perf level */
            else if
            (((level == 0) &&
              ((constraints & (1 << Power_DISALLOW_PERFLEVEL_LOW)) !=
               0)) ||
             ((level == 1) &&
              ((constraints & (1 << Power_DISALLOW_PERFLEVEL_NOM)) !=
               0)) ||
             ((level == 2) &&
              ((constraints & (1 << Power_DISALLOW_PERFLEVEL_OD)) != 0)) ||
             ((level == 3) &&
              ((constraints & (1 << Power_DISALLOW_PERFLEVEL_HIGH)) != 0)) ||
             ((level == 4) &&
              ((constraints & (1 << Power_DISALLOW_PERFLEVEL_HIGH2)) != 0)))
            {
                retVal = Power_ECHANGE_NOT_ALLOWED;
            }
        }

        /* if any checks failed, or already at this performance level,
         * exit now */
        if (retVal != Power_SOK)
        {
            HwiP_restore(hwiKey);
        }
        else
        {
            if (level != PowerDevice_module.currentPerfLevel)
            {
                /* set Power's transition state */
                PowerDevice_module.state = Power_CHANGING_PERF_LEVEL;
                /* notify any clients registered for a start-change
                 * notification */
                retVal = notify(Power_EV_START_CHANGE_PERF_LEVEL, level);

                switch (level)
                {
                    case Power_PERFLEVEL_LOW:
                        newFreq = PowerDevice_FREQ_OPP_LOW;
                        break;
                    case Power_PERFLEVEL_NOM:
                        newFreq = PowerDevice_FREQ_OPP_NOM;
                        break;
                    case Power_PERFLEVEL_OD:
                        newFreq = PowerDevice_FREQ_OPP_OD;
                        break;
                    case Power_PERFLEVEL_HIGH:
                        newFreq = PowerDevice_FREQ_OPP_HIGH;
                        break;
                    case Power_PERFLEVEL_HIGH2:
                        newFreq = PowerDevice_FREQ_OPP_HIGH2;
                        break;
                    default:
                        retVal = Power_EFAIL;
                        break;
                }

                if ((retVal == Power_SOK) && (newFreq != 0U))
                {
                    retVal = (uint32_t) PMLIBClkRateSet(
                        PMHAL_PMMC_MOD_TETRIS0,
                        PMHAL_PMMC_CLK_TETRIS_CORE_CLK,
                        newFreq);
                    if (retVal == PM_CLOCKRATE_SAME_FREQ_CHANGE_REQ)
                    {
                        retVal = Power_SOK;
                    }
                    if (retVal == Power_SOK)
                    {
                        PowerDevice_module.currentPerfLevel = level;
                        /* notify any done-change notification clients */
                        retVal = notify(Power_EV_DONE_CHANGE_PERF_LEVEL,
                                        level);
                    }
                }
                else
                {
                    retVal = Power_EOPP_UNSUPPORTED;
                }
            }
            /* set Power's state to active */
            PowerDevice_module.state = Power_ACTIVE;

            /* re-enable interrupts */
            HwiP_restore(hwiKey);
        }
    }
#else
    retVal = Power_ECHANGE_NOT_ALLOWED;
#endif
    return retVal;
}

/*
 *  ======== Power_sleep ========
 */
unsigned int Power_sleep(unsigned int sleepState)
{
    pmhalPmmcModuleId_t moduleId  = PMHAL_PMMC_MOD_UNDEF;
    uint32_t            event     = Power_EV_ENTERING_SLEEP;
    uint32_t            postEvent = Power_EV_ENTERING_SLEEP;
    unsigned int        status    = Power_EFAIL;
    uint32_t            mode      = MSG_DEVICE_SW_STATE_ON;

    /* first validate the sleep code */
    if ((sleepState == Power_SLEEP) ||
        (sleepState == Power_DEEPSLEEP))
    {
        if (PowerDevice_module.state == Power_ACTIVE)
        {
            /* set transition state to entering sleep */
            PowerDevice_module.state = Power_ENTERING_SLEEP;
            status = Power_SOK;
        }
        else
        {
            status = Power_EBUSY;
        }

        if (status == Power_SOK)
        {
            moduleId = (pmhalPmmcModuleId_t) getModuleId();
            if (moduleId != PMHAL_PMMC_MOD_UNDEF)
            {
                if (Power_SLEEP == sleepState)
                {
                    event     = Power_EV_ENTERING_SLEEP;
                    mode      = MSG_DEVICE_SW_STATE_RETENTION;
                    postEvent = Power_EV_AWAKE_SLEEP;
                }
                else if (Power_DEEPSLEEP == sleepState)
                {
                    /* Same as sleep which is an idle mode.  Anything more
                     * than retention is not supported at the moment */
                    event     = Power_EV_ENTERING_DEEPSLEEP;
                    mode      = MSG_DEVICE_SW_STATE_RETENTION;
                    postEvent = Power_EV_AWAKE_DEEPSLEEP;
                }
                else
                {
                    ; /* Should not come here */
                }
                /* notify any clients registered for a start-change
                 * notification */
                status = notify(event, sleepState);
                if (status == Power_SOK)
                {
                    if (status == Power_SOK)
                    {
                        /* Prepare CPU for low power mode */
                        status = PMLIBPmmcCpuModeModify(moduleId, mode);

                        if (status == PM_SUCCESS)
                        {
                            /* Enter low power mode */
                            PMLIBPmmcCpuIdle();
                        }

                        /* Restore active state after wakeup */
                        status = PMLIBPmmcCpuModeModify(moduleId,
                                                        MSG_DEVICE_SW_STATE_ON);

                        /* set transition state to EXITING_SLEEP */
                        PowerDevice_module.state = Power_ACTIVE;
                        /* signal clients registered for post-sleep
                         * notification */
                        status += notify(postEvent, PowerDevice_module.state);
                    }
                }
                if (status != Power_SOK)
                {
                    /* Set back the state in Power Active */
                    PowerDevice_module.state = Power_ACTIVE;
                }
            }
        }
    }

    return status;
}

/*
 *  ======== Power_shutdown ========
 *  Put the device into a low power shutdown state.
 */
unsigned int Power_shutdown(unsigned int shutdownState,
                            unsigned int shutdownTime)
{
    unsigned int        status = Power_EFAIL;
    uint32_t            constraints;
    uint32_t            hwiKey;
    pmhalPmmcModuleId_t moduleId;

    /* first validate shutdownState */
    if (shutdownState == Power_SHUTDOWN)
    {
        /* disable interrupts */
        hwiKey = HwiP_disable();

        /* make sure shutdown request doesn't violate a constraint */
        constraints = Power_getConstraintMask();
        if ((constraints & (1 << Power_DISALLOW_SHUTDOWN)) != 0)
        {
            status = Power_ECHANGE_NOT_ALLOWED;
        }
        else
        {
            /* make sure not busy with some other transition */
            if (PowerDevice_module.state == Power_ACTIVE)
            {
                /* set new transition state to entering shutdown */
                PowerDevice_module.state = Power_ENTERING_SHUTDOWN;

                /* signal all clients registered for pre-shutdown
                 * notification */
                status = notify(Power_EV_ENTERING_SHUTDOWN, shutdownState);

                /* if no notification error... proceed to shutdown ... */
                if (status == Power_NOTIFYDONE)
                {
                    moduleId = (pmhalPmmcModuleId_t) getModuleId();
                    if (moduleId != PMHAL_PMMC_MOD_UNDEF)
                    {
                        status = PMHALPmmcModuleSetState(moduleId,
                                    MSG_DEVICE_SW_STATE_AUTO_OFF,
                                    PMHAL_PMMC_TIMEOUT_DEFAULT);
                    }
                }
            }
        }
        /* set state to Power_ACTIVE */
        PowerDevice_module.state = Power_ACTIVE;

        /* re-enable interrupts */
        HwiP_restore(hwiKey);
    }

    return status;
}

unsigned int Power_getDependencyCount(unsigned int resourceId)
{
    unsigned int        retVal;
    pmhalPmmcModuleId_t modId;

    modId = (pmhalPmmcModuleId_t)resourceId;

    if(modId > PMHAL_PMMC_MOD_COUNT)
    {
         retVal = Power_INVALIDINPUT;
    }
    else
    {
        retVal = PowerDevice_module.dependencyCount[modId];
    }
    return retVal;
}

uint32_t Power_releaseDependency(unsigned int resourceId)
{
    uint8_t                              count;
    uintptr_t                            key;
    pmlibSysConfigPmmcPowerStateParams_t moduleDependency;
    int32_t                              retVal = Power_SOK;
    pmhalPmmcModuleId_t                  modId;

    modId = (pmhalPmmcModuleId_t)resourceId;

    /* Check if the resource id is valid*/
    if(modId > PMHAL_PMMC_MOD_COUNT)
    {
         retVal = Power_INVALIDINPUT;
    }
    else
    {
        key = HwiP_disable();

        /* read and decrement the reference count */
        count = PowerDevice_module.dependencyCount[modId];

        if(count > 0)
        {
            /* Count is greater than zero implies the module is on.
               Count indicates number of dependencies on the resource.
               decrement the count*/
            count--;

            PowerDevice_module.dependencyCount[modId] = count;

            /* if this was the last dependency being released then
               disable the module */
            if (count == 0)
            {

                moduleDependency.modId = modId;
                moduleDependency.pwrState = MSG_DEVICE_SW_STATE_AUTO_OFF;

                retVal = PMLIBSysConfigPmmcSetPowerState(&moduleDependency, 1U,
                            PMHAL_PMMC_TIMEOUT_DEFAULT, NULL);
                if((retVal == PM_SYS_CONFIG_MODULE_CANNOT_BE_DISABLED) ||
                   (retVal == PM_SYS_CONFIG_MODULE_HAS_DEPENDENCIES))
                {
                    /* The module cannot be disabled or has dependency */
                    /* Certain modules are always in ON state and cannot
                       be disabled for such modules PMLIBSysConfigSetPowerState
                       would return PM_SYS_CONFIG_MODULE_CANNOT_BE_DISABLED.
                       The case when PMLIBSysConfigSetPowerState
                       would return PM_SYS_CONFIG_MODULE_HAS_DEPENDENCIES.
                       Certain modules would be dependent on other hence needed
                       to be disabled in order.Higher level software needs to
                       take care of the dependencies while disabling.*/
                    retVal = Power_SOK;
                }
            }
        }
        HwiP_restore(key);
    }
    if(retVal != Power_SOK)
    {
        retVal = Power_EFAIL;
    }
    return retVal;
}

uint32_t Power_setDependency(unsigned int resourceId)
{
    uint32_t                             retVal = Power_SOK;
    uint8_t                              count;
    uintptr_t                            key;
    pmlibSysConfigPmmcPowerStateParams_t moduleDependency;
    pmhalPmmcModuleId_t                  modId;

    modId = (pmhalPmmcModuleId_t)resourceId;
    /* Check if the resource id is valid*/
    if(modId > PMHAL_PMMC_MOD_COUNT)
    {
         retVal = Power_INVALIDINPUT;
    }
    else
    {
        /* disable interrupts */
        key = HwiP_disable();

        /* read dependency count */
        count = PowerDevice_module.dependencyCount[modId];

        /* A resource dependency count of 0 indicates it was NOT
           activated previously. Activate the resource and increment the count */
        if (count == 0U)
        {
            moduleDependency.modId = modId;
            moduleDependency.pwrState = MSG_DEVICE_SW_STATE_ON;

            retVal = PMLIBSysConfigPmmcSetPowerState(&moduleDependency, 1U,
                        PMHAL_PMMC_TIMEOUT_DEFAULT, NULL);
        }
        
        /* Increment the count for resource for every entry */
        count++;
        PowerDevice_module.dependencyCount[modId] = count;
        /* re-enable interrupts */
        HwiP_restore(key);
    }
    if(retVal != Power_SOK)
    {
        retVal = Power_EFAIL;
    }
    return retVal;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== notify ========
 *  Notify clients registered for eventType notifications.
 *  When this function is called interrupts are disabled.
 */
static uint32_t notify(uint32_t eventType, uint32_t eventArg)
{
    int32_t         status = Power_SOK;
    Power_NotifyFxn notifyFxn;
    List_List      *notifyList;
    uint32_t        notifyStatus;
    List_Elem      *elem;
    uint32_t        clientArg;

    if(PowerDevice_module.notifyRegistered == TRUE)
    {
        notifyList = &PowerDevice_module.notifyList;

        /* point to first notify object */
        elem = List_head(notifyList);

        /* while queue is not empty, service each element */
        while (elem != NULL)
        {
            /* check if this client wants notification of this event type... */
            if ((((Power_NotifyObj *) elem)->eventTypes & eventType) == eventType)
            {
                /* yes, pull params from notify object */
                notifyFxn = ((Power_NotifyObj *) elem)->notifyFxn;
                clientArg = ((Power_NotifyObj *) elem)->clientArg;

                /* call the client's notification function */
                notifyStatus = (uint32_t) (*(Power_NotifyFxn) notifyFxn)(
                    eventType, eventArg, clientArg);

                /* if notification failed: stop all further notifications */
                if (notifyStatus != Power_NOTIFYDONE)
                {
                    status = Power_EFAIL;
                }
            }

            /* get next element in the notification queue */
            elem = List_next(elem);
        }
    }

    return (status);
}

/*
 *  ======== getModuleId ========
 *  Return processor ID
 */
static uint32_t getModuleId()
{
    uint32_t moduleId = PMHAL_PMMC_MOD_UNDEF;
#if defined (__ARM_ARCH_7A__)
    moduleId = PMHAL_PMMC_MOD_TETRIS0;
#elif defined (_TMS320C6X)
    moduleId = PMHAL_PMMC_MOD_CGEM0;
#endif

    return moduleId;
}
