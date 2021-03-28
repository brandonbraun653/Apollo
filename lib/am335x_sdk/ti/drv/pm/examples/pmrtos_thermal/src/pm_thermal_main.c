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
 *  \file   pm_thermal_main.c
 *
 *  \brief  pm rtos thermal management implementation example.
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
#include <ti/sysbios/knl/Clock.h>

#endif

#include <string.h>
#include <math.h>

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
#else
#include <ti/drv/pm/include/pmic/pmhal_tps659039.h>
#endif
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/csl_i2c.h>
#include "app_utils.h"

#include <ti/sysbios/knl/Clock.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define TIMER_INITIAL_COUNT             (0xFFF00000U)
#define TIMER_RLD_COUNT                 (0xFFF00000U)

#if defined (__ARM_ARCH_7A__)
#define CSL_XBAR_IRQ CSL_XBAR_INST_MPU_IRQ_49
#define IRQ_NO (uint32_t) (49U)
#define INT_NO (int32_t)  (81)

#define LOW_SET_POINT_IDX PowerDevice_SET_POINT_IDX_LOW_MPU
#define HIGH_SET_POINT_IDX PowerDevice_SET_POINT_IDX_HIGH_MPU
#endif

#if defined (__TI_ARM_V7M4__)
#define CSL_XBAR_IRQ CSL_XBAR_INST_IPU1_IRQ_33
#define IRQ_NO (uint32_t) (33U)
#define INT_NO (int32_t)  (33)

#define LOW_SET_POINT_IDX PowerDevice_SET_POINT_IDX_LOW_IVA
#define HIGH_SET_POINT_IDX PowerDevice_SET_POINT_IDX_HIGH_IVA
#endif

#if defined (_TMS320C6X)
#define CSL_XBAR_IRQ CSL_XBAR_INST_DSP1_IRQ_50
#define IRQ_NO (uint32_t) (50U)
#define INT_NO (int32_t)  (8)

#define LOW_SET_POINT_IDX PowerDevice_SET_POINT_IDX_LOW_DSPEVE
#define HIGH_SET_POINT_IDX PowerDevice_SET_POINT_IDX_HIGH_DSPEVE
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

/**
 * When checking for I2C IRQSTATUS setting this count is used to
 * repeatedly check the status. This number is empirically derived.
 */
#define PM_TEST_UTILS_I2C_TIMEOUT_COUNT      (4000U)

/** Write Flag used when checking for the transfer status. */
#define PM_TEST_UTILS_I2C_WRITE              (1U)

/** Read Flag used when checking for the transfer status. */
#define PM_TEST_UTILS_I2C_READ               (2U)

/** Depth of temperature history buffer */
#define TEMP_HISTORY                         (10U)
/** Heat up loop iterations */
#if defined(__TI_ARM_V7M4__)
#define HEAT_UP_ITERATIONS                   (10000)
#elif defined (_TMS320C6X)
#define HEAT_UP_ITERATIONS                   (10000000)
#else
#define HEAT_UP_ITERATIONS                   (1000000)
#endif
/** Stable temperature standard deviation */
#define TEMP_STABLE_STDDEV                   (1U)
/** High offset from stable temperature to raise to hit hot alert */
#if defined(__TI_ARM_V7M4__) || defined (_TMS320C6X)
#define TEMP_HIGH_MOD                        (1U)
#else
#define TEMP_HIGH_MOD                        (4U)
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void mainTimerTick(UArg arg);

void CpuThermalTest(UArg arg0, UArg arg1);

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
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

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

/* Boolean for thermal high reached */
static bool gotThermalHighInt;
/* Boolean for thermal low reached */
static bool gotThermalLowInt;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    Task_Handle task;
    Error_Block eb;
    const pmhalPmicOperations_t *pmicOps;
    uint32_t    retVal;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    uint32_t    siliconPackageType;
#endif
    Error_init(&eb);

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
#endif
    retVal = PMHALPmicRegister(pmicOps);

    gRootClkFreqList = PMLIBBoardConfigGetRootClks();
    gVdRailShareList = PMLIBBoardConfigGetVdRailShareInfo();
    PMLIBClkRateInit(gRootClkFreqList, gVdRailShareList);

    task = Task_create(CpuThermalTest, NULL, &eb);
    if (task == NULL)
    {
        AppUtils_printf("Task_create() CpuThermalTest failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();

    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
int32_t           testResult = PM_SUCCESS;
PowerDevice_Cfg_t PowerDevice_config;
Power_NotifyObj   pmNotifyObjHot;
Power_NotifyObj   pmNotifyObjCold;
bool              unstableTemp;
int32_t           stableTemp;

static int NotifyHotCallbk(unsigned int eventType, uintptr_t eventArg,
                           uintptr_t clientArg)
{
    uint32_t setPointIdx = eventArg;
    int      minTemp, maxTemp;

    Power_getCurrentTemp(setPointIdx, &minTemp, &maxTemp);

    gotThermalHighInt = TRUE;
    /* enable policy function for CPU idle */
    Power_enablePolicy();

    return Power_NOTIFYDONE;
}

static int NotifyColdCallbk(unsigned int eventType, uintptr_t eventArg,
                            uintptr_t clientArg)
{
    uint32_t setPointIdx = eventArg;
    int      minTemp, maxTemp;

    Power_getCurrentTemp(setPointIdx, &minTemp, &maxTemp);

    gotThermalLowInt = TRUE;
    /* disable policy function for CPU idle */
    Power_disablePolicy();

    return Power_NOTIFYDONE;
}

void CpuThermalTest(UArg arg0, UArg arg1)
{
    int32_t retVal;
    int32_t avgTempHist[TEMP_HISTORY];
    int     minTemp, maxTemp;

    AppUtils_defaultInit();
    AppUtils_printf("\n PM RTOS Thermal Test App");

    PowerDevice_Cfg_Init(&PowerDevice_config);

    PowerDevice_config.swInit           = TRUE;
    PowerDevice_config.hwInit           = TRUE;
#if defined (__ARM_ARCH_7A__)
    PowerDevice_config.enablePerf       = TRUE;
    PowerDevice_config.initialPerfLevel = Power_PERFLEVEL_NOM;
#endif

    /* Assign policy function for CPU idle */
    PowerDevice_config.policyInitFxn   = &PowerDevice_policyInitFxn;
    PowerDevice_config.policyDeinitFxn = &PowerDevice_policyDeinitFxn;
    PowerDevice_config.policyFxn       = &PowerDevice_policyFxn;

    /* Thermal interrupt configuration */
    PowerDevice_config.thermalCfg.cfgThermalAlert = TRUE;
    PowerDevice_config.thermalCfg.alertIntPriority = 0x0U;
    PowerDevice_config.thermalCfg.eventId = IRQ_NO;
    PowerDevice_config.thermalCfg.xbarCpuIrq = CSL_XBAR_IRQ;
    PowerDevice_config.thermalCfg.intNum = INT_NO;

    gotThermalHighInt = FALSE;
    gotThermalLowInt = FALSE;

    /* Initialize the system here */
    retVal = Power_init();
    if (retVal != Power_SOK)
    {
        AppUtils_printf(" \n Power_init returned %d ", retVal);
        AppUtils_printf(" \n TEST FAILED ");
        testResult += retVal;
        return;
    }

    /* register notify callbacks for hot and cold events */
    Power_registerNotify(&pmNotifyObjHot, PowerDevice_THERMAL_HIGH,
                         (Power_NotifyFxn) NotifyHotCallbk, 0);
    Power_registerNotify(&pmNotifyObjCold, PowerDevice_THERMAL_LOW,
                         (Power_NotifyFxn) NotifyColdCallbk, 0);

    /* get temperature until stable */
    AppUtils_printf(" \n Calculating stable temperature.");
    unstableTemp = TRUE;
    while (unstableTemp)
    {
        uint32_t i;
        double   sum;
        double   mean;
        double   stddev;

        memset(&avgTempHist[0], 0, sizeof(avgTempHist));

        for (i = 0; i < TEMP_HISTORY; i++)
        {
            retVal = Power_getCurrentTemp(HIGH_SET_POINT_IDX, &minTemp, &maxTemp);
            if (retVal != Power_SOK)
            {
                AppUtils_printf(" \n Power_getCurrTemp returned %d ", retVal);
                AppUtils_printf(" \n TEST FAILED ");
                testResult += retVal;
                return;
            }

            /* take average of returned temp range then convert to C from
             * milli-degree C*/
            avgTempHist[i] = (((minTemp + maxTemp) / 2U) / 1000U);
            /* wait until next measurement */
            AppUtils_printf(".");
            Task_sleep(100000/Clock_tickPeriod);
        }

        /* find standard deviation */
        for (i = 0, sum = 0; i < TEMP_HISTORY; i++)
        {
            sum += (double) avgTempHist[i];
        }
        mean = sum / (double)TEMP_HISTORY;

        for (i = 0, sum = 0; i < TEMP_HISTORY; i++)
        {
            sum += pow((double)avgTempHist[i] - mean, 2);
        }
        stddev = sqrt(sum / (double)TEMP_HISTORY);

        if (stddev < TEMP_STABLE_STDDEV)
        {
            unstableTemp = FALSE;
            stableTemp = (int32_t) mean;
        }
    }

    AppUtils_printf(" \n Stable temperature reached : %d C ", stableTemp);

    /* configure high setpoint to be slightly above average temp */
    retVal = Power_enableThermalSetPoint(HIGH_SET_POINT_IDX,
                                        (stableTemp + TEMP_HIGH_MOD) * 1000);
    if (retVal != Power_SOK)
    {
        AppUtils_printf(" \n Power_enableThermalSetPoint returned %d ", retVal);
        AppUtils_printf(" \n TEST FAILED ");
        testResult += retVal;
        return;
    }
    else
    {
        Power_getThermalSetPoint(HIGH_SET_POINT_IDX, &minTemp, &maxTemp);
        AppUtils_printf(" \n Configured high set point to %.1f - %.1f C ",
                        ((float) minTemp) / 1000,
                        ((float) maxTemp) / 1000);
    }

    /* Do some work to increase processor temperature */
    AppUtils_printf(" \n Doing work to raise processor temperature! ");
    while (!gotThermalHighInt)
    {
        int i;

        for (i = 0; i < TEMP_HISTORY; i++)
        {
            int j;
            volatile long long result = 0;
            volatile long long a = 23, b = 27, c = 0x12345678u;

            for (j = 0; j < HEAT_UP_ITERATIONS; j++)
            {
                result += (a - j) * (b * j) + (c + j);
            }
            Power_getCurrentTemp(HIGH_SET_POINT_IDX, &minTemp, &maxTemp);
            avgTempHist[i] = (minTemp + maxTemp) / 2u / 1000U;
        }

        if (!gotThermalHighInt)
        {
            /* Print last temp range to relay progress */
            AppUtils_printf(
                " \n Raising temp - current range : %.1f - %.1f C ",
                ((float) minTemp) / 1000, ((float) maxTemp) / 1000);
        }
    }

    Power_getCurrentTemp(HIGH_SET_POINT_IDX, &minTemp, &maxTemp);
    AppUtils_printf(" \n Temperature range at moment of high alert: "
                    "%.1f - %.1f C ",
                    ((float) minTemp) / 1000, ((float) maxTemp) / 1000);

    /* configure low setpoint to be stable temp */
    retVal = Power_enableThermalSetPoint(LOW_SET_POINT_IDX,
                                        (stableTemp) * 1000);

    if (retVal != Power_SOK)
    {
        AppUtils_printf(" \n Power_enableThermalSetPoint returned %d ", retVal);
        AppUtils_printf(" \n TEST FAILED ");
        testResult += retVal;
        return;
    }
    else
    {
        Power_getThermalSetPoint(LOW_SET_POINT_IDX, &minTemp, &maxTemp);
        AppUtils_printf(" \n Configured low set point to %.1f - %.1f C ",
                        ((float) minTemp) / 1000,
                        ((float) maxTemp) / 1000);
    }

    /* Wait for temperature to come down to stable temp */
    while (!gotThermalLowInt)
    {
        /* wait until next measurement */
        Task_sleep(10000/Clock_tickPeriod);

        if (!gotThermalLowInt)
        {
            Power_getCurrentTemp(LOW_SET_POINT_IDX, &minTemp, &maxTemp);
            AppUtils_printf(
                " \n Lowering temp - current range : %.1f - %.1f C ",
                ((float) minTemp) / 1000, ((float) maxTemp) / 1000);
        }
    }

    Power_getCurrentTemp(LOW_SET_POINT_IDX, &minTemp, &maxTemp);
    AppUtils_printf(" \n Temperature range at moment of low alert: "
                    "%.1f - %.1f C ",
                    ((float) minTemp) / 1000, ((float) maxTemp) / 1000);

    /* Reconfigure high setpoint to be slightly above average temp */
    retVal = Power_enableThermalSetPoint(HIGH_SET_POINT_IDX,
                                        (stableTemp + TEMP_HIGH_MOD) * 1000);
    if (retVal != Power_SOK)
    {
        AppUtils_printf(" \n Power_enableThermalSetPoint returned %d ", retVal);
        AppUtils_printf(" \n TEST FAILED ");
        testResult += retVal;
        return;
    }
    else
    {
        Power_getThermalSetPoint(HIGH_SET_POINT_IDX, &minTemp, &maxTemp);
        AppUtils_printf(" \n Configured high set point to %.1f - %.1f C ",
                        ((float) minTemp) / 1000,
                        ((float) maxTemp) / 1000);
    }

    AppUtils_printf("\n Test Completed!!");

    retVal = Power_deinit();
    if (retVal != Power_SOK)
    {
        AppUtils_printf(" \n Power_deinit returned %d ", retVal);
        AppUtils_printf(" \n TEST FAILED ");
    }
    else
    {
        AppUtils_printf("\n All Test Passed!!");
    }
}

void mainTimerTick(UArg arg)
{
    Clock_tick();
}

static int32_t PmTestUtilsI2cInit(void)
{
    int32_t  status = STW_SOK;
    uint32_t timeout;
    uint32_t baseAddr = SOC_I2C1_BASE;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Force Wake-up clock domain L4PER1 */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4PER1,
                          PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                          PM_TIMEOUT_NOWAIT);

#else
    /* Force Wake-up clock domain L4PER */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4PER,
                          PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP,
                          PM_TIMEOUT_NOWAIT);
#endif

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

    return status;
}

static int32_t PmTestUtilsI2cReadByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                      const uint8_t *regAddr,
                                      uint8_t *regValue,
                                      uint32_t numRegs)
{
    int32_t status = STW_SOK;
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
    return status;
}

static int32_t PmTestUtilsI2cWriteByte(uint32_t i2cNum, uint32_t i2cDevAddr,
                                       const uint8_t *regAddr,
                                       const uint8_t *regValue,
                                       uint32_t numRegs)
{
    uint8_t  data[2];
    uint8_t  count       = (uint8_t) 2U;
    int32_t  status      = STW_SOK;
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
    return status;
}

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

