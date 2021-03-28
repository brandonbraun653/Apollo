/**
 *  \file  gpio_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the gpio.
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

#ifndef GPIO_APP_H_
#define GPIO_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "gpio.h"
#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding gpio pin configuration parameters. */
typedef struct gpioAppPinCfg
{
    uint32_t dir;
    /**< pin direction . */
    uint32_t debounceEnable;
    /**< Enable/disable debounce feature. */
    uint32_t debounceTime;
    /**< deboune timing control. */
    uint32_t intrEnable;
    /**< Interrupt enable/disable. */
    uint32_t intrType;
    /**< Interrupt type edge or level . */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t wakeEnable;
    /**< Wake up enable/disable control. */
    uint32_t wakeLine;
    /**< Wakeup line number. */
}gpioAppPinCfg_t;

/**< \brief Structure holding the GPIO pin object data structure. */
typedef struct gpioAppPinObj
{
    uint32_t     pinNum;
    /**< GPIO pin number. */
    uint32_t     instNum;
    /**< GPIO instance number. */
    uint32_t     instAddr;
    /**< GPIO instance address. */
    gpioAppPinCfg_t pinCfg;
    /**< GPIO pin configuration structure.*/
}gpioAppPinObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/** \brief Global structure holding the default GPIO IP configuration values. */
extern gpioAppPinObj_t GPIOAPPPINOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   GPIO IP configuration initialization api.
 *
 * \param   pGpio        Pointer to the pin object.
 */
void GPIOAppInit(gpioAppPinObj_t *pGpio);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef GPIO_APP_H_ */
