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

/**
 *  \file   pm_main.c
 *
 *  \brief  pm rtos implementation example for K2G.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/Power.h>
#include <ti/drv/pm/PowerExtended.h>
#include <ti/drv/pm/PowerDevice.h>

#include <ti/drv/pm/firmware/pmfirmware.h>

#include "app_utils.h"

#include <ti/sysbios/knl/Clock.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

void mainTimerTick(UArg arg);

void CpuIdleTest(UArg arg0, UArg arg1);

void appReset(void);

static int NotifyCallbk(unsigned int eventType, uintptr_t eventArg,
                        uintptr_t clientArg);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

int32_t           testResult;

#if defined (__ARM_ARCH_7A__)
PowerDevice_Cfg_t PowerDevice_config __attribute__ ((section (".noinit")));
#elif defined (_TMS320C6X)
#pragma DATA_SECTION(PowerDevice_config, ".noinit")
PowerDevice_Cfg_t PowerDevice_config;
#else
#pragma NOINIT(PowerDevice_config)
PowerDevice_Cfg_t PowerDevice_config;
#endif

Power_NotifyObj   pmNotiObj;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* On reset bios tick needs to be up
   PRCM configuration is done in the app and hence
   timer which are used by bios are to be initialized at reset only.
   PowerDevice_Cfg_Init is called to reset the global structure
   along with software init */
void appReset(void)
{
    PowerDevice_Cfg_Init(&PowerDevice_config);
    PowerDevice_config.swInit = TRUE;
    Power_init();

    Power_setDependency(PMHAL_PMMC_MOD_TIMER64_1);
    Power_setDependency(PMHAL_PMMC_MOD_TIMER64_2);
}

int main(void)
{
    Task_Handle task;
    Error_Block eb;
    uint32_t    retVal = PM_SUCCESS;

    Error_init(&eb);

    AppUtils_defaultInit();

    task = Task_create(CpuIdleTest, NULL, &eb);
    if (task == NULL)
    {
        AppUtils_printf("Task_create() CpuIdleTest failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();

    return retVal;
}


static int NotifyCallbk(unsigned int eventType, uintptr_t eventArg,
                        uintptr_t clientArg)
{
    AppUtils_printf(" \n NotifyCallbk registered for %d and "
                    "called for event %d ", pmNotiObj.eventTypes, eventType);
    return Power_NOTIFYDONE;
}

void CpuIdleTest(UArg arg0, UArg arg1)
{
    uint32_t              perfLevel;
    int32_t               retVal = PM_SUCCESS;
    pmhalPmmcModuleId_t   mod1, mod2;
    pmhalPmmcClockId_t    mod2Clock;
    pmhalPmmcClockState_t mod2ClockState;
#if defined (__ARM_ARCH_7A__)
    int32_t               i;
#endif
#if !defined (SOC_K2G)
    uint32_t              powerLatency;
#endif
    int32_t               dependencyCount;
    /* modState is state element of ti_sci_msg_req_set_device_state in
     * pmmc/pmhal_ti_sci.h */
    uint32_t              modState;

    PowerDevice_Cfg_Init(&PowerDevice_config);

    PowerDevice_config.swInit = TRUE;
    PowerDevice_config.hwInit = TRUE;
#if defined (__ARM_ARCH_7A__)
    PowerDevice_config.enablePerf       = TRUE;
    PowerDevice_config.initialPerfLevel = Power_PERFLEVEL_NOM;
#endif
    PowerDevice_config.pFirmware = (const void *)&pmmcimage[0];
    PowerDevice_config.sizeFirmware = sizeof(pmmcimage);

    /* Initialize the system here */
    /* assign policy function for CPU idle */
    PowerDevice_config.policyInitFxn   = &PowerDevice_policyInitFxn;
    PowerDevice_config.policyDeinitFxn = &PowerDevice_policyDeinitFxn;
    PowerDevice_config.policyFxn       = &PowerDevice_policyFxn;

    /* Enable policy function for CPU idle */
    Power_enablePolicy();
    Power_init();

    AppUtils_printf("\n PM RTOS Test App");

    /* register a notify callback */
    Power_registerNotify(&pmNotiObj, Power_EVENT_ALL,
                         (Power_NotifyFxn) NotifyCallbk,
                         NULL);
    /* set the constraint such that usecase doesn't shutdown */
    Power_setConstraint(Power_DISALLOW_SHUTDOWN);

    /* try to setperf for cores other than a15 it should fail */
    retVal = Power_setPerformanceLevel(Power_PERFLEVEL_LOW);
    if (PM_SUCCESS != retVal)
    {
        AppUtils_printf(" \n Power_setPerformanceLevel returned %d ", retVal);
        AppUtils_printf(" \n enablePerf was not set TEST PASS ");
        testResult += PM_SUCCESS;
    }

    perfLevel = Power_getPerformanceLevel();
    AppUtils_printf(" \n Power_getPerformanceLevel returned %d ", perfLevel);

    mod1 = PMHAL_PMMC_MOD_MLB0;
    mod2 = PMHAL_PMMC_MOD_DSS0;
    mod2Clock = PMHAL_PMMC_CLK_DSS_PI_DSS_OCP_CLK;

    /* Set state of module clock so it will be disabled by PMMC when module is
     * disabled via Power_releaseDependency */
    testResult += PMHALPmmcClockSetState(mod2, mod2Clock, 0,
                                         MSG_CLOCK_SW_STATE_AUTO,
                                         PMHAL_PMMC_TIMEOUT_DEFAULT);
    if (testResult != PM_SUCCESS)
    {
        AppUtils_printf(" \n FAIL PMHALPmmcClockSetState for DSS clock ");
    }

    /* Check the state of the module clock */
    testResult += PMHALPmmcClockGetState(mod2, mod2Clock, &mod2ClockState,
                                         PMHAL_PMMC_TIMEOUT_DEFAULT);
    if (testResult == PM_SUCCESS)
    {
        if (mod2ClockState.currentState == MSG_CLOCK_HW_STATE_READY)
        {
            AppUtils_printf(" \n DSS module clock in ready state ");
        }
        else if (mod2ClockState.currentState == MSG_CLOCK_HW_STATE_NOT_READY)
        {
            AppUtils_printf(" \n DSS module clock in not ready state ");
        }
        else
        {
            AppUtils_printf(" \n DSS module clock in unknown state ");
        }
    }
    else
    {
        AppUtils_printf(" \n FAIL PMHALPmmcClockGetState for DSS clock ");
    }

    /* TEST set release and dependency count */
    testResult += Power_setDependency(mod1);
    testResult += Power_setDependency(mod2);
#if !defined (_TMS320C6X)
    testResult += Power_setDependency(PMHAL_PMMC_MOD_CGEM0);
#endif

    dependencyCount =  Power_getDependencyCount(mod2);
    if(dependencyCount != 0)
    {
        AppUtils_printf(" \n Power_setDependency for DSS dependencyCount %d ", dependencyCount);
        testResult +=  Power_setDependency(mod2);

        PMLIBSysConfigPmmcGetPowerState((pmhalPmmcModuleId_t)mod2,
                                        &modState, NULL);
        if(modState == MSG_DEVICE_HW_STATE_ON)
        {
            AppUtils_printf(" \n Module is enabled ");
        }
        else
        {
            testResult += PM_FAIL;
            AppUtils_printf(" \n Module is disabled ");
        }

        dependencyCount =  Power_getDependencyCount(mod2);
        if(dependencyCount != 2)
        {
            AppUtils_printf(" \n FAIL Power_setDependency for DSS dependencyCount %d ", dependencyCount);
            testResult += PM_FAIL;
        }

        /* Check the state of the module clock */
        testResult += PMHALPmmcClockGetState(mod2, mod2Clock, &mod2ClockState,
                                             PMHAL_PMMC_TIMEOUT_DEFAULT);
        if (testResult == PM_SUCCESS)
        {
            if (mod2ClockState.currentState == MSG_CLOCK_HW_STATE_READY)
            {
                AppUtils_printf(" \n DSS module clock in ready state ");
            }
            else if (mod2ClockState.currentState == MSG_CLOCK_HW_STATE_NOT_READY)
            {
                AppUtils_printf(" \n DSS module clock in not ready state ");
            }
            else
            {
                AppUtils_printf(" \n FAIL DSS module clock in unknown state ");
                testResult += PM_FAIL;
            }
        }
        else
        {
            AppUtils_printf(" \n FAIL PMHALPmmcClockGetState for DSS clock ");
        }
    }
    else
    {
        AppUtils_printf(" \n FAIL Power_setDependency for DSS dependencyCount %d ", dependencyCount);
        testResult += PM_FAIL;
    }

    testResult += Power_releaseDependency(mod1);
    testResult += Power_releaseDependency(mod2);
#if !defined (_TMS320C6X)
    testResult += Power_releaseDependency(PMHAL_PMMC_MOD_CGEM0);
#endif

    dependencyCount =  Power_getDependencyCount(mod2);
    if(dependencyCount == 1)
    {
        AppUtils_printf(" \n Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
        testResult +=  Power_releaseDependency(mod2);
        dependencyCount =  Power_getDependencyCount(mod2);
        if(dependencyCount != 0)
        {
            AppUtils_printf(" \n FAIL Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
            testResult += PM_FAIL;
        }
        else
        {
            PMLIBSysConfigPmmcGetPowerState((pmhalPmmcModuleId_t)mod2,
                                            &modState, NULL);
            if(modState == MSG_DEVICE_HW_STATE_OFF)
            {
                AppUtils_printf(" \n Module is disabled ");
            }
            else
            {
                testResult += PM_FAIL;
                AppUtils_printf(" \n Module is enabled ");
            }

            /* Check the state of the module clock */
            testResult += PMHALPmmcClockGetState(mod2, mod2Clock,
                                                 &mod2ClockState,
                                                 PMHAL_PMMC_TIMEOUT_DEFAULT);
            if (testResult == PM_SUCCESS)
            {
                if (mod2ClockState.currentState == MSG_CLOCK_HW_STATE_READY)
                {
                    AppUtils_printf(" \n DSS module clock in ready state.  Attempting to disable... ");

                    /* Attempt to Disable clock since dependency was released */
                    testResult += PMHALPmmcClockSetState(mod2, mod2Clock, 0,
                                         MSG_CLOCK_SW_STATE_UNREQ,
                                         PMHAL_PMMC_TIMEOUT_DEFAULT);
                    if (testResult != PM_SUCCESS)
                    {
                        AppUtils_printf(" \n FAIL PMHALPmmcClockSetState for DSS clock ");
                    }
                    else
                    {
                        testResult += PMHALPmmcClockGetState(mod2, mod2Clock,
                                                 &mod2ClockState,
                                                 PMHAL_PMMC_TIMEOUT_DEFAULT);
                        if ((mod2ClockState.currentState ==
                            MSG_CLOCK_HW_STATE_READY))
                        {
                            AppUtils_printf(" \n DSS module clock in ready state ");
                        }
                        else if (mod2ClockState.currentState ==
                                 MSG_CLOCK_HW_STATE_NOT_READY)
                        {
                            AppUtils_printf(" \n DSS module clock in not ready state ");
                        }
                        else
                        {
                            AppUtils_printf(" \n FAIL DSS module clock in unknown state ");
                            testResult += PM_FAIL;
                        }

                        if ((mod2ClockState.programmedState ==
                            MSG_CLOCK_HW_STATE_READY))
                        {
                            AppUtils_printf(" \n FAIL DSS module clock programmed to ready state ");
                            testResult += PM_FAIL;
                        }
                        else if (mod2ClockState.programmedState ==
                                 MSG_CLOCK_HW_STATE_NOT_READY)
                        {
                            AppUtils_printf(" \n DSS module clock programmed to not ready state ");
                        }
                        else
                        {
                            AppUtils_printf(" \n FAIL DSS module programmed to unknown state ");
                            testResult += PM_FAIL;
                        }
                    }
                }
                else if (mod2ClockState.currentState ==
                         MSG_CLOCK_HW_STATE_NOT_READY)
                {
                    AppUtils_printf(" \n DSS module clock in not ready state ");
                }
                else
                {
                    AppUtils_printf(" \n FAIL DSS module clock in an unknown state ");
                    testResult += PM_FAIL;
                }
            }
            else
            {
                AppUtils_printf(" \n FAIL PMHALPmmcClockGetState for DSS clock ");
            }
        }
    }
    else
    {
        AppUtils_printf(" \n FAIL Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
        testResult += PM_FAIL;
    }

#if defined (__ARM_ARCH_7A__)
    for (i = 0; i < Power_NUMPERFLEVELS; i++)
    {
        AppUtils_printf (" \n Setting performance level %d ", i);
        retVal = Power_setPerformanceLevel(i);
        if (Power_EOPP_UNSUPPORTED == retVal)
        {
            AppUtils_printf(" \n Power_setPerformanceLevel returned %d - "
                            "PERFLEVEL %d unsupported on core", retVal, i);
            testResult += PM_SUCCESS;
            AppUtils_printf(" \n Power_getPerformanceLevel TEST PASS ");
        }
        else if (PM_SUCCESS != retVal)
        {
            AppUtils_printf(" \n Power_setPerformanceLevel returned %d ",
                            retVal);
            AppUtils_printf(" \n Power_getPerformanceLevel TEST FAIL ");
            testResult += PM_FAIL;
        }
        else
        {
            /* try to get the perf value and verify if set correctly */
            perfLevel = Power_getPerformanceLevel();
            AppUtils_printf(" \n Power_getPerformanceLevel returned %d ",
                            perfLevel);
            if (perfLevel == i)
            {
                testResult += PM_SUCCESS;
                AppUtils_printf(" \n Power_getPerformanceLevel TEST PASS ");
            }
            else
            {
                testResult += PM_FAIL;
                AppUtils_printf(" \n Power_getPerformanceLevel TEST FAIL ");
            }
        }
    }

    AppUtils_printf(" \n Reset to PERFLEVEL_OD preparing for constraint test ");
    retVal = Power_setPerformanceLevel(Power_PERFLEVEL_OD);
    AppUtils_printf(" \n Power_setPerformanceLevel returned %d ", retVal);

    Power_setConstraint(Power_DISALLOW_PERFLEVEL_HIGH);
    Task_sleep(10);
    retVal = Power_setPerformanceLevel(Power_PERFLEVEL_HIGH);
    if (PM_SUCCESS != retVal)
    {
        AppUtils_printf(" \n Power_setPerformanceLevel returned %d ", retVal);
        AppUtils_printf(" \n Power_setConstraint TEST PASS ");
        testResult += PM_SUCCESS;
    }
    else
    {
        testResult += PM_FAIL;
        AppUtils_printf(" \n Power_setConstraint TEST FAIL ");
    }
    Task_sleep(10);
    Power_releaseConstraint(Power_DISALLOW_PERFLEVEL_HIGH);

    retVal = Power_setPerformanceLevel(Power_PERFLEVEL_HIGH);
    if (PM_SUCCESS != retVal)
    {
        AppUtils_printf(" \n Power_setPerformanceLevel returned %d ", retVal);
        AppUtils_printf(" \n Power_releaseConstraint TEST FAIL ");
        testResult += PM_FAIL;
    }
    else
    {
        AppUtils_printf(" \n Power_releaseConstraint TEST PASS ");
        perfLevel = Power_getPerformanceLevel();
        if (perfLevel == 3)
        {
            testResult += PM_SUCCESS;
            AppUtils_printf(" \n Power_getPerformanceLevel TEST PASS ");
        }
        else
        {
            testResult += PM_FAIL;
            AppUtils_printf(" \n Power_getPerformanceLevel TEST FAIL ");
        }
    }
#endif

    /* enable policy function for CPU idle */
    Power_enablePolicy();
    Task_sleep(10);

/* TransitionLatency and Shutdown APIs are not verified for K2G yet */
#if !defined (SOC_K2G)
    /* verify if latency is to much for app if yes then disallow deepsleep */
    powerLatency = Power_getTransitionLatency(Power_DEEPSLEEP, Power_RESUME);
    if (powerLatency > 150)
    {
        /* set constarint to disallow deepsleep */
        Power_setConstraint(Power_DISALLOW_DEEPSLEEP);
    }
    Task_sleep(10);

    /* release constraint to disallow deepsleep */
    Power_releaseConstraint(Power_DISALLOW_DEEPSLEEP);
    Task_sleep(10);

    /* print all the latency */
    powerLatency = Power_getTransitionLatency(Power_SLEEP, Power_RESUME);
    AppUtils_printf("\n Power Latency to resume from sleep = %d !!",
                    powerLatency);
    powerLatency = Power_getTransitionLatency(Power_SLEEP, Power_TOTAL);
    AppUtils_printf("\n Total Power Latency = %d !!", powerLatency);

    powerLatency = Power_getTransitionLatency(Power_DEEPSLEEP, Power_RESUME);
    AppUtils_printf("\n Power Latency to resume from deep sleep = %d !!",
                    powerLatency);
    powerLatency = Power_getTransitionLatency(Power_DEEPSLEEP, Power_TOTAL);
    AppUtils_printf("\n Total Power Latency = %d !!", powerLatency);
#endif

    /* disable policy function for CPU idle */
    Power_disablePolicy();
    Power_unregisterNotify(&pmNotiObj);

    Power_shutdown(Power_SHUTDOWN, 10);

    AppUtils_printf(
        "\n App shouldn't shutdown as constraint is set disallow shutdown!!");
    testResult += PM_SUCCESS;

    Power_releaseConstraint(Power_DISALLOW_SHUTDOWN);
    AppUtils_printf("\n Test Completed!!");

    if (testResult == PM_SUCCESS)
    {
        AppUtils_printf("\n All Test Passed!!");
    }

    Power_deinit();
/* Power_shutdown not supported on AM335x, AM437x, and K2G yet */
#if !defined (SOC_K2G)
    Power_shutdown(Power_SHUTDOWN, 10);
#if !defined (__ARM_ARCH_7A__)
    testResult += PM_FAIL;
    AppUtils_printf("\n If this print is executed shutdown test failed!!");
#endif
#endif
}

void mainTimerTick(UArg arg)
{
    Clock_tick();
}

