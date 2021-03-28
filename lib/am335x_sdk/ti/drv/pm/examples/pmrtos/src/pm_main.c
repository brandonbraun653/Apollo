/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2014-2017
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
 *  \brief  pm rtos implementation example.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#endif

#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_timer.h>
#include <ti/drv/pm/pmhal.h>
#include <ti/drv/pm/pmlib.h>
#include <ti/drv/pm/Power.h>
#include <ti/drv/pm/PowerExtended.h>
#include <ti/drv/pm/PowerDevice.h>
#include <ti/drv/pm/include/pmlib_boardconfig.h>
#include <ti/drv/pm/include/prcm/pmhal_i2cComm.h>
#include <ti/drv/pm/include/prcm/pmhal_pmicComm.h>
#if defined (SOC_TDA2EX)
#include <ti/drv/pm/include/pmic/pmhal_tps65917.h>
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#include <ti/drv/pm/include/pmic/pmhal_tps65917.h>
#include <ti/drv/pm/include/pmic/pmhal_tps659039.h>
#include <ti/drv/pm/include/pmic/pmhal_lp8731.h>
#elif defined (SOC_AM572x) || defined (SOC_AM571x)
#include <ti/drv/pm/include/pmic/pmhal_tps659037.h>
#elif defined (SOC_AM335x)
#include <ti/drv/pm/include/pmic/pmhal_tps65910.h>
#elif defined (SOC_AM437x)
#include <ti/drv/pm/include/pmic/pmhal_tps65218.h>
#else
#include <ti/drv/pm/include/pmic/pmhal_tps659039.h>
#endif
#include <ti/csl/arch/csl_arch.h>
#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#else
#include <ti/csl/csl_i2c.h>
#endif
#if defined (SOC_AM335x)
#include <ti/drv/pm/firmware/pmfirmware.h>
#endif

#include "app_utils.h"

#include <ti/sysbios/knl/Clock.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define TIMER_INITIAL_COUNT             (0xFFF00000U)
#define TIMER_RLD_COUNT                 (0xFFF00000U)

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#define I2C_PMIC_INSTANCE (0)
#else
#if defined (__ARM_ARCH_7A__)
#define CSL_XBAR_IRQ_CPU_ID CSL_XBAR_IRQ_CPU_ID_MPU
#define IRQ_NO (uint16_t) (40)
#endif

#if defined (__TI_ARM_V7M4__)
#define CSL_XBAR_IRQ_CPU_ID CSL_XBAR_IRQ_CPU_ID_IPU1
#define IRQ_NO (uint16_t) (54)
#endif

#if defined (_TMS320C6X)
#define CSL_XBAR_IRQ_CPU_ID CSL_XBAR_IRQ_CPU_ID_DSP1
#define IRQ_NO (uint16_t) (66)
#endif

/** I2C System Clock - PER_96M_CLK:  96 MHz */
#define PM_TEST_UTILS_I2C_SYSTEM_CLOCK       (96000000U)

/** I2C Internal Clock -  9.6 MHz , Fast Mode of Communication is
 *  is used here. A pre-scaler of 23 would be calculated here. Refer
 *  TRM for details on the different I2C modes.
 */
#define PM_TEST_UTILS_I2C_INTERNAL_CLOCK     (9600000U)

/** I2C Output Clock -  400 KHz, This complies with the Fast Mode
 *  of the I2C operation of 100 Kbps.
 */
#define PM_TEST_UTILS_I2C_OUTPUT_CLOCK       (400000U)
#endif

/**
 * When checking for I2C IRQSTATUS setting this count is used to
 * repeatedly check the status. This number is empirically derived.
 */
#define PM_TEST_UTILS_I2C_TIMEOUT_COUNT      (4000U)

/** Write Flag used when checking for the transfer status. */
#define PM_TEST_UTILS_I2C_WRITE              (1U)

/** Read Flag used when checking for the transfer status. */
#define PM_TEST_UTILS_I2C_READ               (2U)
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void mainTimerTick(UArg arg);

void CpuIdleTest(UArg arg0, UArg arg1);

/**
 * \brief   This function performs the I2C initialization to talk to PMIC.
 *
 * \param   None.
 *
 * \retval  None.
 */
static int32_t PmTestUtilsI2cInit(void);

/**
 * \brief   This function reads a byte from the PMIC via I2C
 *
 * \param   i2cNum   Instance Id of the I2C. 1 - for I2C1, 2 - for I2C2
 * \param   i2cDevAddr  I2C Slave address for the PMIC
 * \param   regAddr     Pointer to the register address which is to be read.
 * \param   regValue    Pointer to the location where the read value will be
 *                      placed.
 * \param   numRegs     Number of registers to be read.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cReadByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                      const uint8_t *regAddr,
                                      uint8_t *regValue,
                                      uint32_t numRegs);

/**
 * \brief   This function writes a byte of data to the register of PMIC via I2C
 *
 * \param   i2cNum   Instance Id of the I2C. 1 - for I2C1, 2 - for I2C2
 * \param   i2cDevAddr  I2C Slave address for the PMIC
 * \param   regAddr     Pointer to the register address which is to be written.
 * \param   regValue    Pointer to the location where the write value will be
 *                      placed.
 * \param   numRegs     Number of registers to be written.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cWriteByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                       const uint8_t *regAddr,
                                       const uint8_t *regValue,
                                       uint32_t numRegs);

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
/**
 * \brief   Poll for Bus Busy and return when bus is not busy or timed out.
 *
 * \param   i2cNum      The I2C number used on the board to connect to the
 *                      desired PMIC.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cWaitForBB(uint32_t i2cNum);

/**
 * \brief  Poll for the given flags and return when any of the flags is set or
 *         timed out.
 *
 * \param   i2cNum      The I2C number used on the board to connect to the
 *                      desired PMIC.
 * \param   flags       Flag to be waited for.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cWaitForFlags(uint32_t i2cNum, uint32_t flags);

/**
 * \brief  Write the given number of bytes to the given slave address.
 *
 * \param   i2cNum      The I2C number used on the board to connect to the
 *                      desired PMIC.
 * \param   slaveAddr   Address to which the data should be written.
 * \param   data        Data to be written.
 * \param   count       Number of Bytes to be written.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cWrite(uint32_t i2cNum,
                                   uint8_t slaveAddr, const uint8_t data[],
                                   uint8_t count);

/**
 * \brief  Read one byte from the given slave address.
 *
 * \param   i2cNum      The I2C number used on the board to connect to the
 *                      desired PMIC.
 * \param   slaveAddr   Address to which the data should be written.
 * \param   value       Data to be read is returned.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cRead(uint32_t i2cNum,
                                  uint8_t  slaveAddr,
                                  uint8_t *value);
/**
 * \brief Check the status of the transfer and handle the error conditions.
 *
 * \param   i2cNum  The I2C number used on the board to connect to the
 *                  desired PMIC.
 * \param   xfr     Transfer Type. Can be any one of PM_TEST_UTILS_I2C_WRITE or
 *                  PM_TEST_UTILS_I2C_READ.
 *
 * \retval  status      Pass or fail value of the operations. STW_SOK - If Pass
 *                      STW_EFAIL - If Fail
 */
static int32_t PmTestUtilsI2cCheckXfrStatus(uint32_t i2cNum, uint32_t xfr);
#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static volatile uint32_t gXbarInst = 35U;

/**
 * \brief Holds the root clock frequencies specific for a given platform
 */
static uint32_t         *gRootClkFreqList;

/**
 * \brief Holds the voltage domains information whose rails are shared
 */
static pmlibBoardVdRailShare_t       *gVdRailShareList;

/*
 * Table containing pointers to the functions to program I2C to talk to PMIC IC.
 */
static const pmhalI2cCommOperations_t gPmicI2cfunc = {
    &PmTestUtilsI2cInit,
    &PmTestUtilsI2cReadByte,
    &PmTestUtilsI2cWriteByte,
    NULL,
    NULL
};

#if defined (SOC_AM335x) || defined (SOC_AM437x)
/* I2C driver instance handle */
I2C_Handle handle = NULL;
#endif

#if defined (SOC_AM572x) && defined (idkAM572x)
/*
 * PMIC regulator map for AM572x IDK
 */
const pmhalTps659037RegulatorMap_t regulatorMap[
    PMHAL_PRCM_PMIC_REGULATOR_COUNT] = {
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MPU */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS12],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_CORE */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS7],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_IVA */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS8],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_DSPEVE */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS45],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_GPU */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS6],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_MMC13V3 */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_LDO1],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_SHV5 */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_SMPS9],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PHY */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_LDO3],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        },
        /* HW Regulator for PMHAL_PRCM_PMIC_REGULATOR_1V8PLL */
        {
            &gPmhalTps659037Regulator[PMHAL_TPS659037_REGULATOR_LDOLN],
            (uint8_t) PMHAL_TPS659037_I2C_NUM_1
        }
};
#endif

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
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

void appReset(void);
static int NotifyCallbk(unsigned int eventType, uintptr_t eventArg,
                        uintptr_t clientArg);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* On reset bios tick needs to be up
   PRCM configuration is done in the app and hence
   timer which are used by bios are to be initialized at reset only.
   PowerDevice_Cfg_Init is called to reset the global structure
   along with software init
   */
void appReset(void)
{
    PowerDevice_Cfg_Init(&PowerDevice_config);
    PowerDevice_config.swInit = TRUE;
    Power_init();
#if defined (__ARM_ARCH_7A__)
#if defined (SOC_AM335x)
    Power_setDependency(PMHAL_PRCM_MOD_TIMER2);
    Power_setDependency(PMHAL_PRCM_MOD_TIMER4);
#elif defined (SOC_AM437x)
    Power_setDependency(PMHAL_PRCM_MOD_TIMER3);
    Power_setDependency(PMHAL_PRCM_MOD_TIMER4);
#else
    Power_setDependency(PMHAL_PRCM_MOD_TIMER2);
    Power_setDependency(PMHAL_PRCM_MOD_TIMER3);
#endif
#else
    Power_setDependency(PMHAL_PRCM_MOD_TIMER3);
    Power_setDependency(PMHAL_PRCM_MOD_TIMER4);
#endif
}

#if defined (SOC_AM335x) || defined (SOC_AM437x)
void initTimers(void)
{
    PowerDevice_Cfg_Init(&PowerDevice_config);
    PowerDevice_config.swInit = TRUE;
    Power_init();

#if defined (SOC_AM335x)
    Power_setDependency(PMHAL_PRCM_MOD_TIMER2);
#else
    Power_setDependency(PMHAL_PRCM_MOD_TIMER3);
#endif
    Power_setDependency(PMHAL_PRCM_MOD_TIMER4);

}
#endif

int main(void)
{
    Task_Handle task;
    Error_Block eb;
    uint32_t    retVal = PM_SUCCESS;
    Error_init(&eb);

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    AppUtils_defaultInit();
#endif

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
    uint32_t perfLevel;
    int32_t retVal = PM_SUCCESS;
    unsigned int mod1, mod2;
#if defined (__ARM_ARCH_7A__)
    int32_t i;
#endif
#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
    uint32_t powerLatency;
#endif
    int32_t dependencyCount;
    pmlibSysConfigPowerState_t modState;
    const pmhalPmicOperations_t *pmicOps;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    uint32_t    siliconPackageType;
#endif

    PowerDevice_Cfg_Init(&PowerDevice_config);

    PowerDevice_config.swInit = TRUE;
    PowerDevice_config.hwInit = TRUE;
#if defined (__ARM_ARCH_7A__)
    PowerDevice_config.enablePerf       = TRUE;
    PowerDevice_config.initialPerfLevel = Power_PERFLEVEL_NOM;
#endif
#if defined (SOC_AM335x)
    PowerDevice_config.pFirmware = (const void *)&cm3image[0];
    PowerDevice_config.sizeFirmware = sizeof(cm3image);
#elif !defined (SOC_AM437x)
    PowerDevice_config.thermalCfg.cfgThermalAlert = FALSE;
#endif

    /* Register the I2C functions with the PMIC Communication to ensure the
     * PMIC can be communicated with I2C driver specific to SBL
     */
    PMHALI2CCommRegister(&gPmicI2cfunc);
    /*
     * Get the pmic ops and register with the pmic interface.
     */
#if defined (SOC_TDA2EX)
    pmicOps = PMHALTps65917GetPMICOps();
#elif defined (SOC_TDA2XX)
    pmicOps = PMHALTps659039GetPMICOps();
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    siliconPackageType = AppUtils_GetSiliconPackageType();
    /*
     * Get the pmic ops and register with the pmic interface.
     */
    if (PLATFORM_SILICON_PACKAGE_TYPE_15X15 == siliconPackageType)
    {
        pmicOps = PMHALTps65917GetPMICOps();
    }
    else
    {
        pmicOps = PMHALLP8731GetPMICOps();
    }
#elif defined (SOC_AM572x) || defined (SOC_AM571x)
#if defined (idkAM572x)
    /* AM572x IDK has different PMIC regulator layout than GP EVM.  GP EVM
     * regulator layout is default in PMIC driver */
    PMHALTps659037ConfigureRegulatorMap(&regulatorMap);
#endif
    pmicOps = PMHALTps659037GetPMICOps();
#elif defined (SOC_AM335x)
    pmicOps = PMHALTps65910GetPMICOps();
#elif defined (SOC_AM437x)
    pmicOps = PMHALTps65218GetPMICOps();
#endif
    retVal = PMHALPmicRegister(pmicOps);

    gRootClkFreqList = PMLIBBoardConfigGetRootClks();
    gVdRailShareList = PMLIBBoardConfigGetVdRailShareInfo();
    PMLIBClkRateInit(gRootClkFreqList, gVdRailShareList);

    /* Initialize the system here */
    /* assign policy function for CPU idle */
    PowerDevice_config.policyInitFxn   = &PowerDevice_policyInitFxn;
    PowerDevice_config.policyDeinitFxn = &PowerDevice_policyDeinitFxn;
    PowerDevice_config.policyFxn       = &PowerDevice_policyFxn;

    /* Enable policy function for CPU idle */
    Power_enablePolicy();
    Power_init();

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
    AppUtils_defaultInit();
#endif
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

#if defined (SOC_AM335x)
    mod1 = PMHAL_PRCM_MOD_GFX;
    mod2 = PMHAL_PRCM_MOD_LCDC;
#elif defined (SOC_AM437x)
    mod1 = PMHAL_PRCM_MOD_GFX;
    mod2 = PMHAL_PRCM_MOD_DSS;
#else
    mod1 = PMHAL_PRCM_MOD_VIP1;
    mod2 = PMHAL_PRCM_MOD_DSS;
#endif
    /* TEST set release and dependency count */
    testResult += Power_setDependency(mod1);
    testResult += Power_setDependency(mod2);
#if !defined (SOC_AM335x) && !defined (SOC_AM437x) && !defined (_TMS320C6X)
    testResult += Power_setDependency(PMHAL_PRCM_MOD_DSP1);
#endif

    dependencyCount =  Power_getDependencyCount(mod2);
    if(dependencyCount != 0)
    {
        AppUtils_printf(" \n Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
        testResult +=  Power_setDependency(mod2);
        PMLIBSysConfigGetPowerState((pmhalPrcmModuleId_t)mod2,&modState,NULL);
        if(modState == PMLIB_SYS_CONFIG_ALWAYS_ENABLED)
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
            AppUtils_printf(" \n FAIL Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
            testResult += PM_FAIL;
        }
    }
    else
    {
        AppUtils_printf(" \n FAIL Power_releaseDependency for DSS dependencyCount %d ", dependencyCount);
        testResult += PM_FAIL;
    }

    testResult += Power_releaseDependency(mod1);
    testResult += Power_releaseDependency(mod2);
#if !defined (SOC_AM335x) && !defined (SOC_AM437x) && !defined (_TMS320C6X)
    testResult += Power_releaseDependency(PMHAL_PRCM_MOD_DSP1);
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
            PMLIBSysConfigGetPowerState((pmhalPrcmModuleId_t)mod2, &modState,
                                        NULL);
            if(modState == PMLIB_SYS_CONFIG_DISABLED)
            {
                AppUtils_printf(" \n Module is disabled ");
            }
            else
            {
                testResult += PM_FAIL;
                AppUtils_printf(" \n Module is enabled ");

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

/* TransitionLatency and Shutdown APIs are not verified for am335x and am437x yet */
#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
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
/* Power_shutdown not supported on AM335x yet */
#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
    Power_shutdown(Power_SHUTDOWN, 10);

    /* MPU cannot be put into off state so Power_shutdown will wake */
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

static int32_t PmTestUtilsI2cInit(void)
{
    int32_t  status = STW_SOK;
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    I2C_HwAttrs i2c_cfg;
    I2C_Params  i2cParams;
#else
    uint32_t timeout;
    uint32_t baseAddr = SOC_I2C1_BASE;
#endif

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Force Wake-up clock domain L4PER1 */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4PER1,
                          PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                          PM_TIMEOUT_NOWAIT);
#elif defined (SOC_AM335x) || defined (SOC_AM437x)
    /* Force Wake-up clock domain L4LS */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4_WKUP,
                          PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                          PM_TIMEOUT_NOWAIT);
#else
    /* Force Wake-up clock domain L4PER */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4PER,
                          PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                          PM_TIMEOUT_NOWAIT);
#endif

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    /* Enable I2C1 for PMIC Communication */
    PMHALModuleModeSet(PMHAL_PRCM_MOD_I2C0,
                       PMHAL_PRCM_MODULE_MODE_ENABLED,
                       PM_TIMEOUT_INFINITE);

    /* Get the default I2C init configurations */
    I2C_socGetInitCfg(I2C_PMIC_INSTANCE, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */

    /* Set the default I2C init configurations */
    I2C_socSetInitCfg(I2C_PMIC_INSTANCE, &i2c_cfg);

    I2C_init();

    I2C_Params_init(&i2cParams);
    handle = I2C_open(I2C_PMIC_INSTANCE, &i2cParams);
#else
    /* Enable I2C1 for PMIC Communication */
    PMHALModuleModeSet(PMHAL_PRCM_MOD_I2C1,
                       PMHAL_PRCM_MODULE_MODE_ENABLED,
                       PM_TIMEOUT_INFINITE);
    /*
     * Do a soft reset so we can clear any incorrect state and
     * configure to suit the PMIC communication.
     */
    I2CSoftReset(baseAddr);

    /*
     * Ensure that the reset is completed. The RDONE bit is set
     * only when the I2C is enabled, so enable I2C before
     * checking for the reset completion.
     */
    I2CMasterEnable(baseAddr);

    timeout = 50U;  /* Approximately 50ms */
    while ((I2CSystemStatusGet(baseAddr) !=
            I2C_SYSS_RDONE_RSTCOMP)
           && (timeout > 0))
    {
        PMUtilsMinDelayMS((uint32_t) 1U);
        timeout--;
    }

    if (timeout == 0)
    {
        status = STW_EFAIL;
    }

    if (status == STW_SOK)
    {
        /* Disable I2C so we can configure for the PMIC communication. */
        I2CMasterEnable(baseAddr);

        /* Configure the I2C BUS clock frequency (I2C_SCL). */
        I2CMasterInitExpClk(baseAddr,
                            PM_TEST_UTILS_I2C_SYSTEM_CLOCK,
                            PM_TEST_UTILS_I2C_INTERNAL_CLOCK,
                            PM_TEST_UTILS_I2C_OUTPUT_CLOCK);

        /*
         * The PMIC communication is always as a master so we don't have
         * to configure the I2C own address. However, it doesn't hurt.
         */
        I2COwnAddressSet(baseAddr, 0,
                         I2C_OWN_ADDR_0);

        /*
         * Make sure the I2C is not in Forced Idle Mode by setting it to No
         * Idle mode.
         */
        I2CSyscInit(baseAddr,
                    (uint32_t) (I2C_AUTOIDLE_DISABLE |
                                I2C_CUT_OFF_BOTH_CLK |
                                I2C_ENAWAKEUP_DISABLE |
                                I2C_NO_IDLE_MODE));

        /*
         * Configure the I2C:
         *    Select Fast/Standard Mode
         *    Select normal mode (vs. start byte mode)
         *    Select 7-bit slave address mode
         *
         * Note that this API writes the 32-bit value passed to the I2C_CON
         * register; the config bits not mentioned below is set to zero.
         */
        I2CConfig(baseAddr, I2C_CFG_N0RMAL_MODE |
                  I2C_CFG_7BIT_SLAVE_ADDR |
                  I2C_OPMODE_FAST_STAND_MODE);

        /* PMIC Comm uses polling mode; disable all the interrupts. */
        I2CMasterIntDisableEx(baseAddr, I2C_INT_ALL);

        /*
         * Bypass the Tx/Rx FIFO. For PRCM access we always read one byte
         * at a time so FIFO is bypassed.
         */
        I2CFIFOThresholdConfig(baseAddr,
                               0, I2C_TX_MODE);
        I2CFIFOThresholdConfig(baseAddr,
                               0, I2C_RX_MODE);
        I2CFIFOClear(baseAddr, I2C_TX_MODE);
        I2CFIFOClear(baseAddr, I2C_RX_MODE);

        /* Enable I2C module. */
        I2CMasterEnable(baseAddr);

        /*
         * This is required to ensure that the I2C communication continues
         * even if A15 (the master core) is debug halted on a breakpoint.
         */
        I2CMasterEnableFreeRun(baseAddr);
    }

    /* Clear status register  */
    I2CMasterIntClearEx(baseAddr, I2C_INT_ALL);
#endif

    return status;
}

static int32_t PmTestUtilsI2cReadByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                      const uint8_t *regAddr,
                                      uint8_t *regValue,
                                      uint32_t numRegs)
{
    int32_t status = STW_SOK;
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    I2C_Transaction i2cTransaction;
    int16_t         transferStatus;

    if (i2cNum != I2C_PMIC_INSTANCE)
    {
        status = STW_EFAIL;
    }

    if (status ==  STW_SOK)
    {
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = (uint8_t)i2cDevAddr;
        i2cTransaction.writeBuf = (uint8_t *) regAddr;
        i2cTransaction.writeCount = 1;
        i2cTransaction.readBuf = regValue;
        i2cTransaction.readCount = 1;
        i2cTransaction.timeout   = 0;
        transferStatus = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS != transferStatus)
        {
            status = STW_EFAIL;
        }
    }
#else
    status = PmTestUtilsI2cWrite(i2cNum, i2cDevAddr, regAddr, 1U);

    /* Then read the value sent by the slave.  */
    if (status == STW_SOK)
    {
        status = PmTestUtilsI2cRead(i2cNum, i2cDevAddr, regValue);
    }
    else
    {
        *regValue = 0U;
    }
#endif

    return status;
}

static int32_t PmTestUtilsI2cWriteByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                       const uint8_t *regAddr,
                                       const uint8_t *regValue,
                                       uint32_t numRegs)
{
    int32_t  status      = STW_SOK;
    uint8_t  data[2];
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    I2C_Transaction i2cTransaction;
    int16_t         transferStatus;

    if (i2cNum != I2C_PMIC_INSTANCE)
    {
        status = STW_EFAIL;
    }

    if (status ==  STW_SOK)
    {
        data[0] = *regAddr;
        data[1] = *regValue;
        
        i2cTransaction.slaveAddress = (uint8_t)i2cDevAddr;
        i2cTransaction.writeBuf = (uint8_t *)&data[0];
        i2cTransaction.writeCount = 2;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.readCount = 0;
        i2cTransaction.timeout   = 0;
        transferStatus = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS != transferStatus)
        {
            status = STW_EFAIL;
        }
    }
#else
    uint8_t  count       = (uint8_t) 2U;

    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    data[0] = *regAddr;
    data[1] = *regValue;
    status  = PmTestUtilsI2cWrite(i2cNum, i2cDevAddr, data, count);

    if (status == STW_SOK)
    {
        /*
         * Generate a stop condition and ensure the
         * bus is free before returning.
         */
        I2CMasterStop(baseAddress);

        status = PmTestUtilsI2cWaitForFlags(i2cNum,
                                            I2C_INT_BUS_FREE |
                                            I2C_INT_ADRR_READY_ACESS);

        I2CFlushFifo(baseAddress);

        /* Clear the data count and all the flags. */
        I2CMasterIntClearEx(baseAddress, I2C_INT_ALL);
        I2CSetDataCount(baseAddress, (uint32_t) 0U);
    }
#endif
    return status;
}

#if !defined (SOC_AM335x) && !defined (SOC_AM437x)
static int32_t PmTestUtilsI2cRead(uint32_t i2cNum,
                                  uint8_t  slaveAddr,
                                  uint8_t *value)
{
    int32_t  status      = STW_SOK;
    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    /* Set the slave address */
    I2CMasterSlaveAddrSet(baseAddress,
                          (uint32_t) slaveAddr);

    /* Configure to read 1 data word from the PMIC register.  */
    I2CSetDataCount(baseAddress, (uint32_t) 1U);

    /*
     * Configure i2c as master-receive and enable.
     * Make sure stop condition is generated after the transaction.
     */
    I2CMasterControl(baseAddress,
                     (uint32_t) (I2C_CFG_MST_RX | I2C_CFG_START | I2C_CFG_STOP));

    /* Read the data if the data is ready. */
    status = PmTestUtilsI2cCheckXfrStatus(i2cNum,
                                          (uint32_t) PM_TEST_UTILS_I2C_READ);
    if (status == STW_SOK)
    {
        *value = I2CMasterDataGet(baseAddress);
    }
    else
    {
        *value = 0U;
    }

    /* Wait for I2C access ready before returning. */
    if (status == STW_SOK)
    {
        uint32_t flags = I2C_INT_ADRR_READY_ACESS |
                         I2C_INT_BUS_FREE;
        status = PmTestUtilsI2cWaitForFlags(i2cNum, flags);
    }

    /* Clear the status of the I2C  */
    I2CFlushFifo(baseAddress);
    I2CMasterIntClearEx(baseAddress, I2C_INT_ALL);
    I2CSetDataCount(baseAddress, (uint32_t) 0U);

    return status;
}

static int32_t PmTestUtilsI2cWrite(uint32_t i2cNum,
                                   uint8_t slaveAddr, const uint8_t data[],
                                   uint8_t count)
{
    int32_t  status = STW_SOK;
    uint32_t rawSt;
    uint8_t  i;
    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    /*
     * Poll the BUS BUSY bit to ensure the bus is not busy before initiating
     * the transaction on the bus.
     */
    status = PmTestUtilsI2cWaitForBB(i2cNum);

    if (status == STW_SOK)
    {
        /* Set the slave address */
        I2CMasterSlaveAddrSet(baseAddress,
                              (uint32_t) slaveAddr);

        /* Configure to send 'count' data words */
        I2CSetDataCount(baseAddress, (uint32_t) count);

        /*
         * Configure i2c as master-transmitter, enable and set start condition.
         * Stop condition is NOT generated as this could be a part of write
         * followed by read (combined format).
         */
        I2CMasterControl(baseAddress,
                         I2C_CFG_MST_TX | I2C_CFG_START);

        /* Transmit 'count' bytes.  */
        for (i = 0; ((i < count) && (status == STW_SOK)); i++)
        {
            /*
             * Check the status to see if the data can be transferred and
             * send data.
             */
            status = PmTestUtilsI2cCheckXfrStatus(
                i2cNum,
                (uint32_t)
                PM_TEST_UTILS_I2C_WRITE);
            if (status == PM_SUCCESS)
            {
                I2CMasterDataPut(baseAddress, data[i]);
            }

            /* Clear XRDY flags */
            rawSt = I2CMasterIntRawStatus(baseAddress);
            I2CMasterIntClearEx(baseAddress,
                                rawSt & I2C_INT_TRANSMIT_READY);
        }

        /*
         * Once we complete writing the 'count' bytes, wait for the
         * ARDY flag to be set. This flag indicates that the I2C
         * is access ready for next transmission. ARDY can also be
         * set if we received NACK so ensure it is not the case.
         */
        if (status == STW_SOK)
        {
            status = PmTestUtilsI2cWaitForFlags(i2cNum,
                                                I2C_INT_ADRR_READY_ACESS);
            if (status == STW_SOK)
            {
                rawSt = I2CMasterIntRawStatus(baseAddress);
                if ((rawSt & I2C_INT_NO_ACK) != 0)
                {
                    status = STW_EFAIL;
                    /* Clear the NACK flag. */
                    I2CMasterIntClearEx(baseAddress,
                                        rawSt & I2C_INT_NO_ACK);
                }

                /* Clear the ARDY flag. */
                I2CMasterIntClearEx(baseAddress,
                                    rawSt & I2C_INT_ADRR_READY_ACESS);
            }
        }
    }

    return status;
}

static int32_t PmTestUtilsI2cWaitForFlags(uint32_t i2cNum, uint32_t flags)
{
    int32_t  status = STW_SOK;
    uint32_t timeout;
    uint32_t rawSt;
    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    timeout = PM_TEST_UTILS_I2C_TIMEOUT_COUNT;

    rawSt = I2CMasterIntRawStatus(baseAddress);

    while (((rawSt & flags) == 0) && (timeout > 0U))
    {
        rawSt = I2CMasterIntRawStatus(baseAddress);
        timeout--;
    }

    if (timeout == 0U)
    {
        status = STW_EFAIL;
    }

    return status;
}

static int32_t PmTestUtilsI2cWaitForBB(uint32_t i2cNum)
{
    int32_t  status = STW_SOK;
    uint32_t timeout;
    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    /*
     * Clear all current interrupts first.
     */
    I2CMasterIntClearEx(baseAddress, I2C_INT_ALL);

    /*
     * Poll the BUS BUSY bit to ensure the bus is not busy before initiating
     * the transaction on the bus.
     */
    for (timeout = PM_TEST_UTILS_I2C_TIMEOUT_COUNT; timeout > 0U; --timeout)
    {
        if (I2CMasterBusBusy(baseAddress) == 0)
        {
            break;
        }
        I2CMasterIntClearEx(baseAddress, I2C_INT_BUS_BUSY);
    }

    if (timeout == 0U)
    {
        status = STW_EFAIL;
    }

    /*
     * Clear all current interrupts.
     */
    I2CMasterIntClearEx(baseAddress, I2C_INT_ALL);

    return status;
}

static int32_t PmTestUtilsI2cCheckXfrStatus(uint32_t i2cNum, uint32_t xfr)
{
    int32_t  status = STW_SOK;
    uint32_t rawSt;
    uint32_t flags = I2C_INT_ADRR_READY_ACESS | I2C_INT_NO_ACK |
                     I2C_INT_ARBITRATION_LOST;
    uint32_t baseAddress = (i2cNum == 0U) ? (SOC_I2C1_BASE) : (SOC_I2C2_BASE);

    if (xfr == PM_TEST_UTILS_I2C_WRITE)
    {
        flags |= I2C_INT_TRANSMIT_READY;
    }
    else if (xfr == PM_TEST_UTILS_I2C_READ)
    {
        flags |= I2C_INT_RECV_READY;
    }
    else
    {
        status = STW_EFAIL;
    }

    /*
     * Wait for any of the following conditions to occur and
     * handle them in the loop before transmitting data.
     * NACK, AL, XRDY/RRDY, ARDY
     */
    if (status == STW_SOK)
    {
        status = PmTestUtilsI2cWaitForFlags(i2cNum, flags);
    }

    if (status == STW_SOK)
    {
        rawSt = I2CMasterIntRawStatus(baseAddress);

        /*
         * When I2C is configured as master-transmitter and didn't
         * receive ACK from slave, NACK condition is generated. The
         * following could cause this situation:
         * 1. No receiver is present on the bus with the transmitted
         *    address; board issue
         * 2. Receiver is not ready to communicate with the master
         *    (probably a board/pmic device issue).
         * 3. Receiver gets data or commands it doesn't understand
         *    (incorrect PMIC)
         * 4. Receiver can't receive any more data bytes.
         *
         * NACK can be handled by a master by either generating a
         * STOP condition or a repeated START condition to start
         * a new transfer. In PMIC COMM we generate a STOP
         * condition to abort the transfer and clear the NACK
         * flag.
         *
         * I2C HW clears STT and STP bits in I2C_CON registers.
         */
        if ((rawSt & I2C_INT_NO_ACK) != 0)
        {
            I2CMasterStop(baseAddress);
            I2CMasterIntClearEx(baseAddress,
                                rawSt & I2C_INT_NO_ACK);
            status = STW_EFAIL;
        }
        /*
         * Arbitration loss occurs when multiple masters initiate
         * transfer at the same time. Only one master wins and others
         * loose the arbitration. The arbitration loss flag is set
         * if this local host lost the arbitration. After an
         * arbitration loss, the local host can continue to generate
         * clock till the end of the byte transfer on the bus and
         * must restart the transmission. Recovering from arbitration
         * loss slightly complicates the code and this can be added
         * if there is a need. At present we clear the flag  and
         * return error.
         *
         * When arbitration loss occurs, the I2C HW clears the
         * STT, STP and MST bits. The local host switches to the
         * slave mode.
         */
        else if ((rawSt & I2C_INT_ARBITRATION_LOST) != 0)
        {
            I2CMasterIntClearEx(baseAddress,
                                rawSt & I2C_INT_ARBITRATION_LOST);
            status = STW_EFAIL;
        }
        /*
         * ARDY flag is set to indicate that the local host is access
         * ready. We are in the middle of a data transfer and hence
         * it is bad if we get ARDY flag set. For example, if we
         * get NACKed, the ARDY flag is set in the middle of data
         * transfer.
         */
        else if ((rawSt & I2C_INT_ADRR_READY_ACESS) != 0)
        {
            I2CMasterIntClearEx(baseAddress,
                                rawSt & I2C_INT_ADRR_READY_ACESS);
            status = STW_EFAIL;
        }
        /*
         * XRDY flag is set when the TX FIFO is empty or the TX FIFO
         * threshold is not reached. This means the local host can
         * transmit now.
         *
         * RRDY flag is set when the RX FIFO is empty or the RX FIFO
         * threshold is not reached. This means the local host can
         * receive now.
         */
        else if (((xfr == PM_TEST_UTILS_I2C_WRITE) &&
                  ((rawSt & I2C_INT_TRANSMIT_READY) != 0)) ||
                 ((xfr == PM_TEST_UTILS_I2C_READ) &&
                  ((rawSt & I2C_INT_RECV_READY) != 0)))
        {
            /*
             * Return success so that the caller can send/receive the data
             * Note that the caller needs to clear the XRDY/RRDY flag as
             * needed.
             */
            status = STW_SOK;
        }
        else
        {
            /*
             * We should not get here...
             */
            status = STW_EFAIL;
        }
    }

    return status;
}
#endif
