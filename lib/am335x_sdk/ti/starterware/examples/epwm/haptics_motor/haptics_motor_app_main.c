/**
 * \file   haptics_motor_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case. This application demonstrates the use of
 *         EPWM to rotate the haptics motor.
 *
 *         Application Use-case:
 *         1. PWM output will be generated with 50% duty cycle.
 *         2. Haptics motor will be driven by this PWM output.
 *
 *         Running the example:
 *         1. Load the example application on the target and run.
 *         2. When the application is executed haptics motor will rotate.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "board.h"
#include "soc.h"
#include "device.h"
#include "chipdb.h"
#include "cache.h"
#include "mmu.h"
#include "example_utils_mmu.h"
#include "console_utils.h"

/* Application header files */
#include "epwm_app.h"
#include "haptics_motor_app.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief HAPTICS device instance number */
#define EPWM_HAPTICS_INST_NUM     (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the board info like PWM channel [A or B] and instance.
 *
 * \param   pObj     Pointer to the pin object.
 *
 * \retval  S_PASS   Board info successful retrieved. Haptics motor is
 *                   connected to EPWM on this board.
 * \retval  E_FAIL   This board does not support this application.
 *                   - Haptics motor device may not be available on this board.
 *                   - Haptics motor may not be connected to EPWM on this board.
 */
static int32_t EpwmAppBoardInfoGet(epwmAppPwmObj_t *pObj);

/**
 * \brief   This API gets the soc info - base address of epwm instance.
 *
 * \param   pObj     Pointer to the pwm object.
 *
 * \retval  S_PASS   SOC info is successfully retrieved.
 * \retval  E_FAIL   SOC info retrieval is failed. Resource is not present.
 */
static uint32_t EpwmAppSocInfoGet(epwmAppPwmObj_t *pObj);

/**
 * \brief   This API sets the default configuration for entire EPWM sub-module.
 *
 * \param   pPwm        Pointer to the pwm object.
 * \param   pHaptics    Pointer to haptics motor use case data structure.
 */
static void EpwmAppUpdateCfgParams(epwmAppPwmObj_t *pPwm,
                                   epwmAppHapticsCfg_t *pHaptics);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Application Use Case default configuration */
static const epwmAppHapticsCfg_t EPWMAPPHAPTICSCFG_DEFAULT =
{
        10U * FREQ_MHZ, /* tbClk */
        20U * FREQ_KHZ, /* pwmFreq */
        FALSE, /* enableDeadband */
        FALSE, /* enableChopper */
        FALSE, /* enableTripzone */
        FALSE, /* enableEventTrigger */
        FALSE  /* enableHighResolution */
};


/** \brief Global object for the EPWM Haptics motor Use case data structure.  */
static epwmAppHapticsCfg_t gHapticsCfg;

/** \brief Global object for the EPWM IP configuration data structure.  */
static epwmAppPwmObj_t gPwmCfg;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /* Initialize the Haptics motor use case object with default values. */
    gHapticsCfg = EPWMAPPHAPTICSCFG_DEFAULT;

    /* Initialize the global IP configuration with default configuration. */
    gPwmCfg     = EPWMAPPPWMOBJ_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare EPWM Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get board info */
    status = EpwmAppBoardInfoGet(&gPwmCfg);
    if (S_PASS == status)
    {
        /* Get SoC info */
        status = EpwmAppSocInfoGet(&gPwmCfg);
        if(S_PASS == status)
        {
            /* EPWM Default configuration */
            EpwmAppUpdateCfgParams(&gPwmCfg, &gHapticsCfg);

            /* EPWM IP configuration */
            status = EPWMAppInit(&gPwmCfg);
            if(S_PASS == status)
            {
                CONSOLEUtilsPrintf("\nNow running the haptics motor ...\n");
                while(1)
                {
                    /* Infinite loop */
                }
            }
            else
            {
                CONSOLEUtilsPrintf
                    ("\n FAILURE!!! EPWM IP configuration is failed ...\n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\nEPWM IP instance is not present ...\n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board!\n");
    }

    return (S_PASS);
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t EpwmAppBoardInfoGet(epwmAppPwmObj_t *pObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t  epwmInstNum;
    uint32_t  epwmOutputCh;

    /* Get the PWMSS[EPWM] data for HAPTICS MOTOR from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_HAPTICS, EPWM_HAPTICS_INST_NUM);
    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_PWMSS == modId)
    {
        epwmInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_HAPTICS,
            EPWM_HAPTICS_INST_NUM);
        epwmOutputCh = BOARDGetDeviceCtrlInfo(DEVICE_ID_HAPTICS,
            EPWM_HAPTICS_INST_NUM);

        if ((INVALID_INST_NUM == epwmInstNum) || (INVALID_INFO == epwmOutputCh))
        {
            CONSOLEUtilsPrintf("Invalid EPWM board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("EPWM Instance number: %d\n", epwmInstNum);
            CONSOLEUtilsPrintf("EPWM Output Channel : %d\n", epwmOutputCh);
            pObj->instNum = epwmInstNum;
            pObj->pwmCh   = epwmOutputCh;
            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to EPWM!\n");
    }

    return (status);
}

static uint32_t EpwmAppSocInfoGet(epwmAppPwmObj_t *pObj)
{
    uint32_t status = S_PASS;

    /* Get the base address of the Module */
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_PWMSS, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_PWMSS, pObj->instNum);
    }
    else
    {
       CONSOLEUtilsPrintf("PWMSS instance number is not present!\n");
       status = E_FAIL;
    }

    return status;
}

static void EpwmAppUpdateCfgParams(epwmAppPwmObj_t *pPwm,
                                   epwmAppHapticsCfg_t *pHaptics)
{
    epwmAppPwmCfg_t *pCfg = &pPwm->pwmCfg;

    /* Disable all the sub-modules by default */
    pPwm->enableDeadband = pHaptics->enableDeadband;
    pPwm->enableChopper = pHaptics->enableDeadband;
    pPwm->enableTripZone = pHaptics->enableDeadband;
    pPwm->enableEventTrigger = pHaptics->enableDeadband;
    pPwm->enableHighResolution = pHaptics->enableDeadband;

    /* Tb period/freq has to be double the required pwm frequency. */
    pCfg->tbCfg.pwmtbCounterFreqPrd = pHaptics->pwmFreq * 2U;
    pCfg->tbCfg.tbClk = pHaptics->tbClk;

    /* Action Qualifier Action Values */
    /* Toggle output when counter is equal to period value. */
    pCfg->aqCfg.prdAction      = EPQM_AQ_ACTION_TOLLGE;
}
