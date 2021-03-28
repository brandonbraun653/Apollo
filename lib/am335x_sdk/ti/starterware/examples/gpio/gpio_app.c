/**
 * \file   gpio_app.c
 *
 * \brief  Source file containing the GPIO IP related configuration functions.
 *         These functions will be called by example application.
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
#include "chipdb.h"
#include "pinmux.h"
#include "gpio.h"
#include "error.h"
#include "console_utils.h"

/* Application header files */
#include "gpio_app.h"
#include "prcm.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API implements counter based delay.
 *
 * \param   baseAddr        Base address of GPIO instance used.
 * \param   pinNum          GPIO pin number
 * \param   pGpioPinConfig  pointer to the pin configuration data structure.
 */
static void GpioAppPinConfig(uint32_t baseAddr,
                             uint32_t pinNum,
                             gpioAppPinCfg_t *pGpioPinConfig);


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of GPIO IP configuration structure. */
gpioAppPinObj_t GPIOAPPPINOBJ_DEFAULT =
{
    0U,  /* pin number */
    0U,  /* Instance number */
    0U,  /* Instance Address */
    {
        GPIO_DIRECTION_OUTPUT, /* dir */
        FALSE,  /* debounceEnable */
        0U,     /* debounceTime */
        FALSE,  /* intrEnable */
        0U,     /* intrType */
        0U,     /* intrLine */
        FALSE,  /* wakeEnable */
        0U,     /* wakeLine */
    } /* gpioAppPinCfg_t */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void GPIOAppInit(gpioAppPinObj_t *pGpio)
{
    int32_t status = S_PASS;

    /* Clock Configuration  */
    PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, pGpio->instNum, 0);

    /* PinMux Configuration */
    status = PINMUXModuleConfig(CHIPDB_MOD_ID_GPIO, pGpio->instNum, &pGpio->pinNum);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Pin Muxing failed !\n");
    }

    /* Enabling the GPIO module. */
    GPIOModuleEnable(pGpio->instAddr, TRUE);


/* TODO: GPIO will fall in a special category, which requires following two
         clocks should be enabled for proper reset of GPIO - functional clock
         and optional clock. Current prcm clock configuration is generic and
         enables only functional clock. Without enabling the optional clock,
         module reset will not be completed. So this function is temporarily
         commented till prcm enables the optional clock also. This needs to be
         resolved.
*/
    /* Resetting the GPIO module. */
    /* GPIOModuleReset(pGpio->instAddr); */



    /* GPIO pin characteristics configuration */
    GpioAppPinConfig(pGpio->instAddr, pGpio->pinNum, &pGpio->pinCfg);

}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static void GpioAppPinConfig(uint32_t baseAddr,
                             uint32_t pinNum,
                             gpioAppPinCfg_t *pGpioPinConfig)
{
    /* Configure Pin as an Input/Output Pin. */
    GPIODirModeSet(baseAddr, pinNum, pGpioPinConfig->dir);

    /* Enable Debouncing feature for the GPIO Pin. */
    GPIODebounceFuncEnable(baseAddr, pinNum, pGpioPinConfig->debounceEnable);

    if(TRUE == pGpioPinConfig->debounceEnable)
    {
        /*
         * Configure the Debouncing Time for all the input pins of
         * the selected GPIO instance.
         */
        GPIODebounceTimeConfig(baseAddr, pGpioPinConfig->debounceTime);
    }

    if(FALSE == pGpioPinConfig->intrEnable)
    {
        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /*
         * Configure interrupt generation on detection of a logic HIGH or
         * LOW levels or a rising or a falling edge.
         */
        GPIOIntTypeSet(baseAddr, pinNum, pGpioPinConfig->intrType);

        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }

    if(FALSE == pGpioPinConfig->wakeEnable)
    {
        /* Enable wakeup generation for GPIO Module */
        GPIOWakeupGlobalDisable(baseAddr);

        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
}
