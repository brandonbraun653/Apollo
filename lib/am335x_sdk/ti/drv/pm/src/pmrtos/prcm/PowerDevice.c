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

/*
 * PowerDevice.c
 *
 * Power API implementation for the following devices:
 *     SOC_TDA2XX
 *     SOC_AM572X
 *     SOC_DRA75x
 *     SOC_TDA2EX
 *     SOC_AM571X
 *     SOC_AM335x
 *     SOC_AM437x
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>

#include <ti/osal/HwiP.h>
#include <ti/osal/osal.h>

#include <Power.h>
#include <PowerExtended.h>
#include <PowerDevice.h>
#include <PowerPRCM_deviceInit.h>

#include "List.h"
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/pmhal.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Default value of the counter delay */
#define DEFAULT_COUNTER_DELAY            (PMHAL_BGAP_BAND_GAP_1_MS)

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
#if (PowerDevice_CAPABILITY_Thermal == 1)
    HwiP_Handle  hwi;              /* Hwi handle tied to thermal alert */
    int          intNum;           /* processor interrupt number tied to thermal
                                    * alert */
#endif
    uint32_t     dependencyCount[PMHAL_PRCM_MOD_COUNT -
                    PMHAL_PRCM_MOD_LOWER_BOUND]; /* Dependency count  */
                                                /* for every module element */
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

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
/*
 *  ======== getVoltageDomainId ========
 */
static pmhalPrcmVdId_t getVoltageDomainId(uint32_t setPointIdx);

/*
 *  ======== isHighSetPoint ========
 */
static bool isHighSetPoint(uint32_t setPointIdx);
#endif

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
 */
/* PowerDevice_module is placed in the noinit section as the PowerDevice_module
   may be in use even before the code reaches main.
   Placing the PowerDevice_module structure in noinit section allows
   the application to have full control on when the structure is initialized
   (in a reset function before main or after reaching main).  */

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
    unsigned int     retVal = Power_EFAIL;
#if (PowerDevice_CAPABILITY_Thermal == 1)
    HwiP_Params      hwiParams;
    HwiP_Fxn         hwiFxn;
    CSL_XbarIrqCpuId cpuId;
    uint32_t         idx;
#endif

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
#if (PowerDevice_CAPABILITY_Thermal == 1)
        PowerDevice_module.hwi              = NULL;
        PowerDevice_module.intNum           = -1;
#endif
    }

    /* if performance control is enabled, go to the initial performance
    *level */
    if (PowerDevice_config.enablePerf)
    {
        PowerDevice_module.perfInitialized  = TRUE;
        PowerDevice_module.currentPerfLevel =
            PowerDevice_config.initialPerfLevel;
    }

    /* if there is a configured policy init function, call it now ... */
    if (PowerDevice_config.policyInitFxn != NULL)
    {
        (*(PowerDevice_config.policyInitFxn))();
    }

    if (PowerDevice_config.hwInit == TRUE)
    {
        PowerDevice_config.siliconPkgType = PRCM_GetPackageType();
        retVal = PRCM_ConfigAllVoltageRails(PowerDevice_module.currentPerfLevel,
                                            PowerDevice_config.siliconPkgType);
        if (retVal == Power_SOK)
        {

            retVal = notify(Power_EV_DONE_AVSCONFIG, 0U);
            retVal = PRCM_ConfigAllDPLL(PowerDevice_module.currentPerfLevel,
                                        PowerDevice_config.siliconPkgType);
            if (retVal == Power_SOK)
            {
                retVal = notify(Power_EV_DONE_DPLLCONFIG, 0U);
#if defined (SOC_TDA2EX) || defined (SOC_TDA2XX) || \
    defined (SOC_AM571x) || defined (SOC_AM572x)
                PRCM_UnlockControlIODSS();
#endif
                retVal = PRCM_InitModulePowerState();
                if (retVal == Power_SOK)
                {
                    retVal = notify(Power_EV_DONE_MODULEPOWERSTATE, 0U);
                }
            }
        }

#if (PowerDevice_CAPABILITY_PmCoprocessor == 1)
        if (retVal == Power_SOK)
        {
            /* Configure coprocessor firmware */
            retVal = PRCM_ConfigFirmware(PowerDevice_config.pFirmware,
                                         PowerDevice_config.sizeFirmware);
        }
#endif
    }

#if (PowerDevice_CAPABILITY_Thermal == 1)
    if (PowerDevice_config.thermalCfg.cfgThermalAlert == TRUE)
    {
        switch(getModuleId())
        {
#if !defined (SOC_TDA3XX) && !defined (SOC_DRA78x)
            case PMHAL_PRCM_MOD_MPU:
                    cpuId = CSL_XBAR_IRQ_CPU_ID_MPU;
                break;
#endif
            case PMHAL_PRCM_MOD_IPU1:
                    cpuId = CSL_XBAR_IRQ_CPU_ID_IPU1;
                break;
            case PMHAL_PRCM_MOD_DSP1:
                    cpuId = CSL_XBAR_IRQ_CPU_ID_DSP1;
                break;
#if !(defined (SOC_TDA2EX) || defined (SOC_AM571x))
            case PMHAL_PRCM_MOD_DSP2:
                cpuId = CSL_XBAR_IRQ_CPU_ID_DSP2;
                break;
#endif
            default:
                retVal = Power_EFAIL;
                break;
        }

        if (retVal == Power_SOK)
        {
            /* XBar configuration */
            CSL_xbarIrqConfigure(cpuId,
                                PowerDevice_config.thermalCfg.xbarCpuIrq,
                                CSL_XBAR_CTRL_MODULE_CORE_IRQ_THERMAL_ALERT);

            /* Configure and enable interrupt */
            HwiP_Params_init(&hwiParams);
            hwiParams.name = "Thermal_Int";
            hwiParams.priority = PowerDevice_config.thermalCfg.alertIntPriority;
            hwiParams.evtId = PowerDevice_config.thermalCfg.eventId;
            hwiFxn = (HwiP_Fxn) (&Power_ThermalAlertFunc);
            /* arg not used at the moment */
            hwiParams.arg = 0;
            PowerDevice_module.hwi = HwiP_create(
                PowerDevice_config.thermalCfg.intNum, hwiFxn, &hwiParams);
            /* Clear any previous interrupts to ensure we are not getting
            * false interrupts */
            HwiP_clearInterrupt(PowerDevice_config.thermalCfg.intNum);
            HwiP_enableInterrupt(PowerDevice_config.thermalCfg.intNum);
            PowerDevice_module.intNum = PowerDevice_config.thermalCfg.intNum;

            /* Thermal comparator output masks are all disabled on reset.
             * Enable will take place in Power_enableThermalSetPoint */

            /* Configure set points to be thermal min and max as default to avoid
             * spurious thermal alerts */
            for (idx = 0; idx < PowerDevice_NUMSETPOINTS; idx++)
            {
                if (isHighSetPoint(idx) == TRUE)
                {
                    Power_enableThermalSetPoint(idx,
                        PowerDevice_SET_POINT_MAX_TEMP * 1000);
                }
                else
                {
                    Power_enableThermalSetPoint(idx,
                        PowerDevice_SET_POINT_MIN_TEMP * 1000);
                }
                /* Immediately disable */
                Power_disableThermalSetPoint(idx);
            }
        }
    }
#endif

    return retVal;
}

/*
 *  ======== Power_deinit ========
 *  Deinitialize setup from Power_init
 */
unsigned int Power_deinit()
{
    unsigned int retVal = Power_SOK;

    /* if there is a configured policy deinit function, call it now ... */
    if (PowerDevice_config.policyDeinitFxn != NULL)
    {
        (*(PowerDevice_config.policyDeinitFxn))();
    }

#if (PowerDevice_CAPABILITY_Thermal == 1)
    if (PowerDevice_module.hwi != NULL)
    {
        HwiP_disableInterrupt(PowerDevice_module.intNum);
        HwiP_delete(PowerDevice_module.hwi);
    }
#endif

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
#if (PowerDevice_CAPABILITY_Thermal == 1)
        /* Need to configure to default and take care in app */
        PowerDevice_config->thermalCfg.cfgThermalAlert  = FALSE; /* bool */
        PowerDevice_config->thermalCfg.alertIntPriority = 0U;    /* unsigned int */
        PowerDevice_config->thermalCfg.eventId          = 0U;    /* unsigned int */
        PowerDevice_config->thermalCfg.xbarCpuIrq       = 0U;    /* unsigned int */
        PowerDevice_config->thermalCfg.intNum           = 0;     /* int */
#endif
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
                        PMHAL_PRCM_MOD_MPU,
                        PMHAL_PRCM_CLK_GENERIC,
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
    pmhalPrcmModuleId_t moduleId  = PMHAL_PRCM_MOD_UNDEF;
    uint32_t            event     = Power_EV_ENTERING_SLEEP;
    uint32_t            postEvent = Power_EV_ENTERING_SLEEP;
    unsigned int        status    = Power_EFAIL;
    pmlibCpuIdleMode_t  mode      = PMLIB_IDLE_CPU_MODE_IDLE;

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
            moduleId = (pmhalPrcmModuleId_t) getModuleId();
            if (moduleId != PMHAL_PRCM_MOD_UNDEF)
            {
                if (Power_SLEEP == sleepState)
                {
                    event     = Power_EV_ENTERING_SLEEP;
                    mode      = PMLIB_IDLE_CPU_MODE_IDLE;
                    postEvent = Power_EV_AWAKE_SLEEP;
                }
                else if (Power_DEEPSLEEP == sleepState)
                {
                    event     = Power_EV_ENTERING_DEEPSLEEP;
                    mode      = PMLIB_IDLE_CPU_MODE_AUTOCG;
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
                    /* Prepare for low power mode */
                    status = PMLIBCpuModePrepare(moduleId, mode);

                    if (status == Power_SOK)
                    {
                        /* Enter Low power here */
                        status = PMLIBCpuIdle(PMHAL_PRCM_PD_STATE_RETENTION);

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
    pmhalPrcmModuleId_t moduleId;

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
                    moduleId = (pmhalPrcmModuleId_t) getModuleId();
                    if (moduleId != PMHAL_PRCM_MOD_UNDEF)
                    {
                        status = PMLIBCpuModePrepare(moduleId,
                                                     PMLIB_IDLE_CPU_MODE_OFF);

                        if (status == Power_SOK)
                        {
                            status = PMLIBCpuIdle(
                                PMHAL_PRCM_PD_STATE_RETENTION);
                        }
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

/*
 *  ======== getModuleId ========
 *  Return processor ID
 */
static uint32_t getModuleId()
{
    uint32_t moduleId = PMHAL_PRCM_MOD_UNDEF;
#if defined (__TI_ARM_V7M4__)
    moduleId = PMHAL_PRCM_MOD_IPU1;
#elif defined (__ARM_ARCH_7A__)
    moduleId = PMHAL_PRCM_MOD_MPU;
#elif defined (_TMS320C6X)
    uint32_t coreVer;
    coreVer = HW_RD_FIELD32_RAW(PowerDevice_DSP_SYS_HWINFO,
                                DSP_HWINFO_NUM_MASK,
                                DSP_HWINFO_NUM_SHIFT);
    if (coreVer == 0U)
    {
        moduleId = PMHAL_PRCM_MOD_DSP1;
    }
#if !(defined (SOC_TDA2EX) || defined (SOC_AM571x))
    else if (coreVer == 1U)
    {
        moduleId = PMHAL_PRCM_MOD_DSP2;
    }
#endif
    else
    {
        moduleId = PMHAL_PRCM_MOD_UNDEF;
    }
#endif

    return moduleId;
}

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
/*
 *  ======== getVoltageDomainId ========
 *  Return voltage domain ID
 */
static pmhalPrcmVdId_t getVoltageDomainId(uint32_t setPointIdx)
{
    pmhalPrcmVdId_t vdId;

    switch (setPointIdx)
    {
#if !defined (SOC_TDA3XX) && !defined (SOC_DRA78x)
        case PowerDevice_SET_POINT_IDX_LOW_MPU:
        case PowerDevice_SET_POINT_IDX_HIGH_MPU:
            vdId = PMHAL_PRCM_VD_MPU;
            break;
        case PowerDevice_SET_POINT_IDX_LOW_IVA:
        case PowerDevice_SET_POINT_IDX_HIGH_IVA:
            vdId = PMHAL_PRCM_VD_IVAHD;
            break;
        case PowerDevice_SET_POINT_IDX_LOW_DSPEVE:
        case PowerDevice_SET_POINT_IDX_HIGH_DSPEVE:
            vdId = PMHAL_PRCM_VD_DSPEVE;
            break;
        case PowerDevice_SET_POINT_IDX_LOW_GPU:
        case PowerDevice_SET_POINT_IDX_HIGH_GPU:
            vdId = PMHAL_PRCM_VD_GPU;
            break;
#endif
        case PowerDevice_SET_POINT_IDX_LOW_CORE:
        case PowerDevice_SET_POINT_IDX_HIGH_CORE:
            vdId = PMHAL_PRCM_VD_CORE;
            break;
        default:
            vdId = PMHAL_PRCM_VD_UNDEF;
            break;
    }

    return vdId;
}

/*
 *  ======== isHighSetPoint ========
 *  Checks whether the input set point index is a hot or cold set point.
 *  Returns:
 *      0 - low set point
 *      1 - high set point
 */
static bool isHighSetPoint(uint32_t setPointIdx)
{
    bool retVal = FALSE;

    if (setPointIdx & 0x1)
    {
        retVal = TRUE;
    }

    return retVal;
}
#endif

/*
 *  ======== Power_getCurrentTemp ========
 *  Retrieve current temperature at the temperature sensor mapped to provided
 *  index.  Temperature returned is within a range given ADC implementation
 */
unsigned int Power_getCurrentTemp(unsigned int  setPointIdx,
                                  int          *pTempMin,
                                  int          *pTempMax)
{
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    unsigned int    retVal = Power_NOTSUPPORTED;
#else
    unsigned int     retVal = Power_SOK;
    pmhalPrcmVdId_t  vdId;
    pmhalBgapRange_t tempRange;
    int32_t          status;

    if (setPointIdx >= PowerDevice_NUMSETPOINTS)
    {
        retVal = Power_EFAIL;
    }
    else if ((pTempMin == NULL) || (pTempMax == NULL))
    {
        retVal = Power_EINVALIDPOINTER;
    }
    else
    {
        vdId = getVoltageDomainId(setPointIdx);
        if (vdId != PMHAL_PRCM_VD_UNDEF)
        {
            status = PMHALBgapGetCurrTemperature(vdId, &tempRange);
            if (status == PM_SUCCESS)
            {
                *pTempMin = tempRange.minTemp;
                *pTempMax = tempRange.maxTemp;
            }
            else
            {
                retVal = Power_EFAIL;
            }
        }
        else
        {
            retVal = Power_EINVALID_SET_POINT_INDEX;
        }
    }
#endif

    return retVal;
}

/*
 *  ======== Power_getThermalSetPoint ========
 *  Retrieve programmed set point temperature mapped to provided
 *  index.  Temperature returned is within a range given ADC implementation
 */
unsigned int Power_getThermalSetPoint(unsigned int  setPointIdx,
                                      int          *pTempMin,
                                      int          *pTempMax)
{
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    unsigned int    retVal = Power_NOTSUPPORTED;
#else
    unsigned int     retVal = Power_SOK;
    pmhalPrcmVdId_t  vdId;
    pmhalBgapRange_t tempRange;
    pmErrCode_t      status;

    if (setPointIdx >= PowerDevice_NUMSETPOINTS)
    {
        retVal = Power_EFAIL;
    }
    else if ((pTempMin == NULL) || (pTempMax == NULL))
    {
        retVal = Power_EINVALIDPOINTER;
    }
    else
    {
        vdId = getVoltageDomainId(setPointIdx);
        if (vdId != PMHAL_PRCM_VD_UNDEF)
        {
            if (isHighSetPoint(setPointIdx) == TRUE)
            {
                status = (pmErrCode_t) PMHALBgapGetHotThreshold(vdId,
                                                                &tempRange);
            }
            else
            {
                status = (pmErrCode_t) PMHALBgapGetColdThreshold(vdId,
                                                                 &tempRange);
            }

            if (status == PM_SUCCESS)
            {
                *pTempMin = tempRange.minTemp;
                *pTempMax = tempRange.maxTemp;
            }
            else
            {
                retVal = Power_EFAIL;
            }
        }
        else
        {
            retVal = Power_EINVALID_SET_POINT_INDEX;
        }
    }
#endif

    return retVal;
}

/*
 *  ======== Power_enableThermalSetPoint ========
 *  Programs and enables the temperature set point mapped to provided index.
 *  The thermal alert mechanism will trigger if the temperature threshold is
 *  crossed.
 */
unsigned int Power_enableThermalSetPoint(unsigned int setPointIdx, int temp)
{
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    unsigned int    retVal = Power_NOTSUPPORTED;
#else
    unsigned int    retVal = Power_SOK;
    pmhalPrcmVdId_t vdId;
    pmErrCode_t     status;
    uintptr_t       key;

    if (setPointIdx >= PowerDevice_NUMSETPOINTS)
    {
        retVal = Power_EFAIL;
    }
    else
    {
        vdId = getVoltageDomainId(setPointIdx);
        if (vdId != PMHAL_PRCM_VD_UNDEF)
        {
            key = HwiP_disable();
            /* Disable the system interrupt */
            HwiP_disableInterrupt(PowerDevice_module.intNum);
            PMHALBgapSetMeasureDelay(PMHAL_BGAP_BAND_GAP_IMMEDIATE);

            if (isHighSetPoint(setPointIdx) == TRUE)
            {
                status = (pmErrCode_t) PMHALBgapSetHotThreshold(vdId, temp);
            }
            else
            {
                status = (pmErrCode_t) PMHALBgapSetColdThreshold(vdId, temp);
            }

            if (status != PM_SUCCESS)
            {
                retVal = Power_EFAIL;
            }

            /* Clear any pending interrupts */
            HwiP_clearInterrupt(PowerDevice_module.intNum);

            PMHALBgapSetMeasureDelay(DEFAULT_COUNTER_DELAY);
            /* Enable the system interrupt */
            HwiP_enableInterrupt(PowerDevice_module.intNum);
            HwiP_restore(key);
        }
        else
        {
            retVal = Power_EINVALID_SET_POINT_INDEX;
        }
    }
#endif

    return retVal;
}

/*
 *  ======== Power_disabledThermalSetPoint ========
 *  Disables the temperature set point mapped to the provided index
 */
unsigned int Power_disableThermalSetPoint(unsigned int setPointIdx)
{
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    unsigned int    retVal = Power_NOTSUPPORTED;
#else
    unsigned int    retVal = Power_SOK;
    pmhalPrcmVdId_t vdId;
    pmErrCode_t     status;

    if (setPointIdx >= PowerDevice_NUMSETPOINTS)
    {
        retVal = Power_EFAIL;
    }
    else
    {
        vdId = getVoltageDomainId(setPointIdx);
        if (vdId != PMHAL_PRCM_VD_UNDEF)
        {
            if (isHighSetPoint(setPointIdx) == TRUE)
            {
                status = (pmErrCode_t) PMHALBgapDisableHotEvent(vdId);
            }
            else
            {
                status = (pmErrCode_t) PMHALBgapDisableColdEvent(vdId);
            }

            if (status != PM_SUCCESS)
            {
                retVal = Power_EFAIL;
            }
        }
        else
        {
            retVal = Power_EINVALID_SET_POINT_INDEX;
        }
    }
#endif

    return retVal;
}

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
/*
 *  ======== Power_getCurrentTemp ========
 *  Base thermal alert function executed when the thermal alert IRQ is enabled.
 *  The function will demux where the alert originated then call all notify
 *  functions registered for the demux'd thermal event.
 */
void Power_ThermalAlertFunc(void)
{
    pmhalPrcmVdId_t   vdId;
    volatile uint32_t hotStatus[PMHAL_BGAP_NUM_FSM] = {0U};
    volatile uint32_t coldStatus[PMHAL_BGAP_NUM_FSM] = {0U};
    bool              counterChangedFlag = FALSE;
    uint32_t          idx;
    uintptr_t         key;

    /* Disabling the global interrupts */
    key = HwiP_disable();

    for(vdId = PMHAL_PRCM_VD_MIN;
        vdId < (pmhalPrcmVdId_t) PMHAL_BGAP_NUM_FSM;
        vdId++)
    {
        /* First read all the status bits in one go. Reading it in phases is
         * found to give incorrect values. */
        PMHALBgapGetHotAlertStatus(vdId, (uint32_t *) &hotStatus[vdId]);
        PMHALBgapGetColdAlertStatus(vdId, (uint32_t *) &coldStatus[vdId]);
        counterChangedFlag = TRUE;
    }

    if (counterChangedFlag == TRUE)
    {
        PMHALBgapSetMeasureDelay(PMHAL_BGAP_BAND_GAP_IMMEDIATE);
    }

    for(vdId = PMHAL_PRCM_VD_MIN;
        vdId < (pmhalPrcmVdId_t) PMHAL_BGAP_NUM_FSM;
        vdId++)
    {
        if(hotStatus[vdId] == 1U)
        {
            /* get set point index from voltage domain */
            idx = (vdId << 1) + 1;

            /* disable event while transitioning out of event */
            PMHALBgapDisableHotEvent(vdId);
            /* signal all clients registered for thermal high alert */
            notify(PowerDevice_THERMAL_HIGH, idx);
        }

        if(coldStatus[vdId] == 1U)
        {
            /* get set point index from voltage domain */
            idx = (vdId << 1);

            /* disable event while transitioning out of event */
            PMHALBgapDisableColdEvent(vdId);
            /* signal all clients registered for thermal low alert */
            notify(PowerDevice_THERMAL_LOW, idx);
        }
    }

    /* Clear any pending interrupts */
    HwiP_clearInterrupt(PowerDevice_module.intNum);
    if (counterChangedFlag == TRUE)
    {
        PMHALBgapSetMeasureDelay(DEFAULT_COUNTER_DELAY);
    }

    /* Restore interrupts */
    HwiP_restore(key);
}
#endif

/* Below functions have not been implemented yet */

unsigned int Power_getDependencyCount(unsigned int resourceId)
{
    unsigned int retVal;
    pmhalPrcmModuleId_t modId;

    modId = PMUtilsGetModuleId((pmhalPrcmModuleId_t)resourceId);

    if(modId > PMHAL_PRCM_MOD_COUNT)
    {
         retVal = Power_INVALIDINPUT;
         /* This is a error case, resourceId is invalid */
    }
    else
    {
        retVal = PowerDevice_module.dependencyCount[modId];
    }
    return retVal;
}

uint32_t Power_releaseDependency(unsigned int resourceId)
{
    uint8_t count;
    unsigned int key;
    pmlibSysConfigPowerStateParams_t moduleDependency;
    int32_t retVal = Power_SOK;
    pmhalPrcmModuleId_t modId;

    modId = PMUtilsGetModuleId((pmhalPrcmModuleId_t)resourceId);


    /* Check if the resource id is valid*/
    if(modId > PMHAL_PRCM_MOD_COUNT)
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
           Count indicates number of dependent on the resource.
           decrement the count*/
            count--;

            PowerDevice_module.dependencyCount[modId] = count;

            /* if this was the last dependency being released then
               disable the module */
            if (count == 0)
            {

                moduleDependency.modId = (pmhalPrcmModuleId_t)resourceId;
                moduleDependency.pwrState = PMLIB_SYS_CONFIG_DISABLED;

                retVal = PMLIBSysConfigSetPowerState(&moduleDependency, 1U,
                                                PM_TIMEOUT_INFINITE, NULL);
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
    uint32_t retVal = Power_SOK;
    uint8_t count;
    uintptr_t key;
    pmlibSysConfigPowerStateParams_t moduleDependency;
    pmhalPrcmModuleId_t modId;

    modId = PMUtilsGetModuleId((pmhalPrcmModuleId_t)resourceId);
    /* Check if the resource id is valid*/
    if(modId > PMHAL_PRCM_MOD_COUNT)
    {
         retVal = Power_INVALIDINPUT;
    }
    else
    {
        /* disable interrupts */
        key = HwiP_disable();

        /* read dependency count */
        count = PowerDevice_module.dependencyCount[modId];

        /* if resource dependency count is 0 indicates it was NOT
          activated previously. Activate the resource and increment the count */
        if (count == 0U)
        {

            moduleDependency.modId = (pmhalPrcmModuleId_t)resourceId;
            moduleDependency.pwrState = PMLIB_SYS_CONFIG_ALWAYS_ENABLED;

            retVal = PMLIBSysConfigSetPowerState(&moduleDependency, 1U,
                                                PM_TIMEOUT_INFINITE, NULL);
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

