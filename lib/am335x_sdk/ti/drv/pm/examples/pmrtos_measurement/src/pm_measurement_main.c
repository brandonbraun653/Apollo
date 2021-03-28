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
 *  \brief  pm rtos implementation example.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Types.h>

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
#if defined (SOC_AM335x)
#include <ti/drv/pm/include/pmic/pmhal_tps65910.h>
#elif defined (SOC_AM437x)
#include <ti/drv/pm/include/pmic/pmhal_tps65218.h>
#endif
#include <ti/csl/arch/csl_arch.h>
#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#endif
#if defined (SOC_AM335x)
#include <ti/drv/pm/firmware/pmfirmware.h>
#endif

#include "app_utils.h"

#include <ti/sysbios/knl/Clock.h>

#include "dhry.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#define I2C_PMIC_INSTANCE (0)
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
typedef enum
{
    OPP_LOW = 1,
    OPP_NOM = 2,
    OPP_OD = 3,
    OPP_HIGH = 4,
    OPP_HIGH2 = 5,
    DHRY = 6,
    QUIT = 7
} menuOptions_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void MenuTask(UArg arg0, UArg arg1);

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

#if defined (SOC_AM335x) || defined (SOC_AM437x)
/* I2C driver instance handle */
I2C_Handle handle = NULL;
#endif

/* This is needed for the dhrystone application called within MenuTask */
extern int dhry_main(void);

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

static int NotifyCallbk(unsigned int eventType, uintptr_t eventArg,
                        uintptr_t clientArg);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    Task_Handle task;
    Error_Block eb;
    uint32_t    retVal = PM_SUCCESS;
    Error_init(&eb);

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    AppUtils_defaultInit();
#endif

    task = Task_create(MenuTask, NULL, &eb);
    if (task == NULL)
    {
        AppUtils_printf("Task_create() menuTask failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();

    return retVal;
}

/*
 *  ChangeOpp
 *  This function sets the performance
 *  level in hardware and informs Bios.
 */
static uint32_t ChangeOpp(int32_t oppInput)
{
    int32_t         oppLevel = oppInput;
    int32_t         oppFreq  = 0;
    Types_FreqHz    cpuFreq;
    uint32_t        perfLevel;
    int32_t         retVal = PM_SUCCESS;

    switch(oppLevel)
    {
        case Power_PERFLEVEL_LOW:
            AppUtils_printf(" \n Power_PERFLEVEL_LOW" );
            oppFreq = PowerDevice_FREQ_OPP_LOW;
            break;
        case Power_PERFLEVEL_NOM:
            AppUtils_printf(" \n Power_PERFLEVEL_NOM" );
            oppFreq = PowerDevice_FREQ_OPP_NOM;
            break;
        case Power_PERFLEVEL_OD:
            AppUtils_printf(" \n Power_PERFLEVEL_OD" );
            oppFreq = PowerDevice_FREQ_OPP_OD;
            break;
        case Power_PERFLEVEL_HIGH:
            AppUtils_printf(" \n Power_PERFLEVEL_HIGH" );
            oppFreq = PowerDevice_FREQ_OPP_HIGH;
            break;
        case Power_PERFLEVEL_HIGH2:
            AppUtils_printf(" \n Power_PERFLEVEL_HIGH2" );
            oppFreq = PowerDevice_FREQ_OPP_HIGH2;
            break;
        default :
            AppUtils_printf(" \n Error: Bad OPP Value!" );
            retVal = Power_EOPP_UNSUPPORTED;
            break;
    }

    if (retVal == PM_SUCCESS)
    {
        BIOS_getCpuFreq(&cpuFreq);
        AppUtils_printf (" \n Bios frequency before setting OPP: %d ", cpuFreq.lo);

        retVal = Power_setPerformanceLevel(oppLevel);

        if (retVal == PM_SUCCESS)
        {
            memset(&cpuFreq, 0, sizeof(cpuFreq));
            cpuFreq.lo = oppFreq;
            BIOS_setCpuFreq(&cpuFreq);

            BIOS_getCpuFreq(&cpuFreq);
            AppUtils_printf (" \n Bios frequency after setting OPP: %d ", cpuFreq.lo);
        }
    }

    if (Power_EOPP_UNSUPPORTED == retVal)
    {
        AppUtils_printf(" \n Power_setPerformanceLevel returned %d - "
                        " PERFLEVEL %d unsupported on core", retVal, oppLevel);
    }
    else if (PM_SUCCESS != retVal)
    {
        /* Unsuccessful OPP Setting */
        AppUtils_printf(" \n Power_setPerformanceLevel returned %d ",
                        retVal);
        AppUtils_printf(" \n Power_getPerformanceLevel TEST FAIL ");
        testResult += PM_FAIL;
    }
    else
    {
        /* OPP set without errors, verify value */

        /* try to get the perf value and verify if set correctly */
        perfLevel = Power_getPerformanceLevel();
        AppUtils_printf(" \n Power_getPerformanceLevel returned %d ",
                            perfLevel);
        if (perfLevel == oppLevel)
        {
            /* OPP value matches set OPP value */
            testResult += PM_SUCCESS;
            AppUtils_printf(" \n Power_getPerformanceLevel TEST PASS ");
        }
        else
        {
            /* OPP value does not match set OPP value */
            testResult += PM_FAIL;
            AppUtils_printf(" \n Power_getPerformanceLevel TEST FAIL ");
        }
    }

    return (retVal);
}

static int NotifyCallbk(unsigned int eventType, uintptr_t eventArg,
                        uintptr_t clientArg)
{
    AppUtils_printf(" \n NotifyCallbk registered for %d and "
                    "called for event %d ", pmNotiObj.eventTypes, eventType);
    return Power_NOTIFYDONE;
}

static void PrintMenu(void)
{
    AppUtils_printf(" \n\n\n Available PM Menu Option:");
    AppUtils_printf(" \n 1. Power_PERFLEVEL_LOW   ( 300 MHz, level 0, MPU 0.95V,  CORE 1.1V,  RTC=1.8V)"
                    " \n 2. Power_PERFLEVEL_NOM   ( 600 MHz, level 1, MPU 1.1V,   CORE 1.1V,  RTC=1.8V)"
                    " \n 3. Power_PERFLEVEL_OD    ( 720 MHz, level 2, MPU 1.2V,   CORE NA,    RTC=1.8V)"
                    " \n 4. Power_PERFLEVEL_HIGH  ( 800 MHz, level 3, MPU 1.26V,  CORE NA,    RTC=1.8V)"
                    " \n 5. Power_PERFLEVEL_HIGH2 (1000 MHz, level 4, MPU 1.325V, CORE NA,    RTC=1.8V)");
    AppUtils_printf(" \n 6. Run Dhrystone"
                    " \n 7. Quit");
}

void MenuTask(UArg arg0, UArg arg1)
{
    const                        pmhalPmicOperations_t *pmicOps;
    int32_t                      retVal = PM_SUCCESS;
#if defined (__ARM_ARCH_7A__)
    int32_t                      quitMenu = 0;

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
#endif

    /* Register the I2C functions with the PMIC Communication to ensure the
     * PMIC can be communicated with I2C driver specific to SBL
     */
    PMHALI2CCommRegister(&gPmicI2cfunc);
    /*
     * Get the pmic ops and register with the pmic interface.
     */
#if defined (SOC_AM335x)
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
    /* register a notify callback */
    Power_registerNotify(&pmNotiObj, Power_EVENT_ALL,
                         (Power_NotifyFxn) NotifyCallbk,
                         (uintptr_t) NULL);
    /* set the constraint such that usecase doesn't shutdown */
    Power_setConstraint(Power_DISALLOW_SHUTDOWN);


#if defined (__ARM_ARCH_7A__)

    /* Set initial OPP value */
    ChangeOpp(Power_PERFLEVEL_LOW);

    while (quitMenu == 0)
    {
        PrintMenu();
        menuOptions_t menu_option = AppUtils_getNum();

        /* Take actions based on menu selection */
        switch(menu_option)
        {
            case OPP_LOW:
                ChangeOpp(Power_PERFLEVEL_LOW);
                break;
            case OPP_NOM:
                ChangeOpp(Power_PERFLEVEL_NOM);
                break;
            case OPP_OD:
                ChangeOpp(Power_PERFLEVEL_OD);
                break;
            case OPP_HIGH:
                ChangeOpp(Power_PERFLEVEL_HIGH);
                break;
            case OPP_HIGH2:
                ChangeOpp(Power_PERFLEVEL_HIGH2);
                break;
            case DHRY:
                AppUtils_printf(" \n Starting Dhrystone\n" );
                int err;
                err = dhry_main();
                AppUtils_printf(" \n dhry_main returned %d ", err);
                break;
            case QUIT:
                AppUtils_printf(" \n Quitting Menu\n" );
                quitMenu = 1;
                continue;
            default :
                AppUtils_printf(" \n Invalid Menu Selection\n" );
                break;
        }
#endif
    }

    Power_deinit();
}

static int32_t PmTestUtilsI2cInit(void)
{
    int32_t  status = STW_SOK;
#if defined (SOC_AM335x) || defined (SOC_AM437x)
    I2C_HwAttrs i2c_cfg;
    I2C_Params  i2cParams;
#endif

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    /* Force Wake-up clock domain L4LS */
    PMHALCMSetCdClockMode(PMHAL_PRCM_CD_L4_WKUP,
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
#endif
    return status;
}
