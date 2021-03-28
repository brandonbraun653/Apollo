/**
 * \file   buzzer_app_main.c
 *
 * \brief  Example application main source file, which configures the IP and
 *         executes the use-case.
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
#include <stdio.h>
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
#include "gpio_app.h"
#include "buzzer_app.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Buzzer device instance number */
#define GPIO_BUZZER_INST_NUM     (0U)


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the board info like pin number and instance.
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      Board info successful retrieved. Buzzer is connected to
 *                      GPIO on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - Buzzer device may not be available on this board.
 *                      - Buzzer may not be connected to GPIO on this board.
 */
static int32_t GpioAppBoardInfoGet(gpioAppPinObj_t *pObj);

/**
 * \brief   This API gets the soc info - base address of gpio instance.
 *
 * \param   pObj        Pointer to the pin object.
 */
static void GpioAppSocInfoGet(gpioAppPinObj_t *pObj);

/**
 * \brief   GPIO Buzzer beep use case api.
 *
 * \param   delayValue  Delay value between buzzer toggle.
 * \param   pPin        Pointer to the pin object.
 */
static void GpioAppBuzzer(uint32_t delayValue, gpioAppPinObj_t *pPin);

/**
 * \brief   This API implements counter based delay.
 *
 * \param   delayValue  Delay value between led toggle.
 */
static void GpioAppDelay(volatile uint32_t count);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static const gpioAppBuzzerCfg_t GPIOAPPBUZZERCFG_DEFAULT =
{
    0x6FFFFFU     /* delay */
};

/** \brief Global object for the audio buzzer use case information. */
static gpioAppBuzzerCfg_t gBuzzerAppCfg;

/** \brief Global object for the GPIO IP configuration. */
static gpioAppPinObj_t gGpioAppCfg;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main()
{
    int32_t status = S_PASS;

    /* Enable cache memory and MMU */
    MMUConfigAndEnable();
    CACHEEnable(CACHE_IDCACHE, CACHE_INNER_OUTER);

    /*
     * Initialize the global objects of use case and IP configuration
     * data structures with default values.
     */
    gBuzzerAppCfg  = GPIOAPPBUZZERCFG_DEFAULT;
    gGpioAppCfg    = GPIOAPPPINOBJ_DEFAULT;

    status = BOARDInit(NULL);

    /* Initialize the UART console */
    CONSOLEUtilsInit();

    /* Select the console type based on compile time check */
    CONSOLEUtilsSetType(CONSOLE_UTILS_TYPE_UART);

    CONSOLEUtilsPrintf("\n StarterWare GPIO Application!!\n");
    CONSOLEUtilsPrintf("BOARDInit status [0x%x]\n", status);

    /* Print SoC & Board Information. */
    SOCPrintInfo();
    BOARDPrintInfo();

    /* Get board info */
    status = GpioAppBoardInfoGet(&gGpioAppCfg);
    if (S_PASS == status)
    {
        /* Get SoC info */
        GpioAppSocInfoGet(&gGpioAppCfg);

        /* GPIO clock/pin mux and IP configuration */
        GPIOAppInit(&gGpioAppCfg);

        CONSOLEUtilsPrintf("\nNow triggering a buzzer beep ...\n");
        /* Buzzer beep Use Case */
        GpioAppBuzzer(gBuzzerAppCfg.delay, &gGpioAppCfg);
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

static int32_t GpioAppBoardInfoGet(gpioAppPinObj_t *pObj)
{
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t  gpioInstNum;
    uint32_t  pinNum;

    /* Get the GPIO data for Buzzer from the board data */
    modId = BOARDGetDeviceCtrlModId(DEVICE_ID_BUZZER, GPIO_BUZZER_INST_NUM);
    if (CHIPDB_MOD_ID_INVALID == modId)
    {
        CONSOLEUtilsPrintf("Device is not available on this board!\n");
    }
    else if (CHIPDB_MOD_ID_GPIO == modId)
    {
        gpioInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_BUZZER,
            GPIO_BUZZER_INST_NUM);
        pinNum = BOARDGetDeviceCtrlInfo(DEVICE_ID_BUZZER, GPIO_BUZZER_INST_NUM);

        if ((INVALID_INST_NUM == gpioInstNum) || (INVALID_INFO == pinNum))
        {
            CONSOLEUtilsPrintf("Invalid GPIO board data!\n");
        }
        else
        {
            CONSOLEUtilsPrintf("GPIO Instance number: %d\n", gpioInstNum);
            CONSOLEUtilsPrintf("Pin number: %d\n", pinNum);
            pObj->instNum = gpioInstNum;
            pObj->pinNum  = pinNum;
            status = S_PASS;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("Device is not connected to GPIO!\n");
    }

    return (status);
}

static void GpioAppSocInfoGet(gpioAppPinObj_t *pObj)
{
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPIO, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_GPIO, pObj->instNum);
    }
    else
    {
        /* GPIO instance number is not present. */
    }
}

/* -------------------------------------------------------------------------- */
/*              Use-case specific Internal Function Definitions               */
/* -------------------------------------------------------------------------- */

static void GpioAppBuzzer(uint32_t delayValue, gpioAppPinObj_t *pPin)
{
    /* Driving a logic high on the GPIO pin. */
    GPIOPinWrite(pPin->instAddr, pPin->pinNum, GPIO_PIN_HIGH);
    GpioAppDelay(delayValue);

    /* Driving a logic LOW on the GPIO pin. */
    GPIOPinWrite(pPin->instAddr, pPin->pinNum, GPIO_PIN_LOW);
    GpioAppDelay(delayValue);
}

static void __attribute__((optimize("O0")))GpioAppDelay(volatile uint32_t count)
{
    while(count--);
}
