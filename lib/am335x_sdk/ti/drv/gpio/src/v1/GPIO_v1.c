/**
 *  \file   GPIO_v1.c
 *
 *  \brief  GPIO Driver APIs implementation specific to IP version 1.
 *
 *   This file contains the driver APIs for GPIO controller.
 */

/*
 * Copyright (C) 2014-2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>
#include <ti/csl/src/ip/gpio/V1/gpio_v2.h>
#include <ti/csl/src/ip/gpio/V1/hw_gpio.h>
#include <ti/drv/gpio/src/GPIO_osal.h>

/* Mask for true value */
#define TRUE_VALUE    (1U)

/* Number of gpio ports present in the soc */
#define NUM_PORTS           (8u)

/* Number of gpio pins for each port */
#define NUM_PINS_PER_PORT    (32u)

/* Uninitialized callbackInfo pinIndex */
#define CALLBACK_INDEX_NOT_CONFIGURED (0xFFu)

/* Macro to extract GPIO pin number from the gpio pin configuration */
#define GPIO_GET_PIN_NUM(gpioConfig)  (((gpioConfig) & GPIO_CFG_PIN_NUM_MASK) >> \
                                        GPIO_CFG_PIN_NUM_SHIFT)

/* Macro to extract GPIO port number from the gpio pin configuration */
#define GPIO_GET_PORT_NUM(gpioConfig) (((gpioConfig) & GPIO_CFG_PORT_NUM_MASK) \
                                        >> GPIO_CFG_PORT_NUM_SHIFT)

/** \brief Mask for all pins of single gpio port */
#define GPIO_PIN_MASK_ALL           (0xFFFFFFFFU)

/*
 * User defined pin indexes assigned to a port's 8 pins. Used by port interrupt
 * function to located callback assigned to a pin.
 */
typedef struct GPIO_PortCallbackInfo_s {
    /* The port's 8 corresponding user defined pinId indices */
    uint8_t pinIndex[NUM_PINS_PER_PORT];
} GPIO_PortCallbackInfo;


/* Table of callbacks per port. */
static GPIO_PortCallbackInfo gpioCallbackInfo[NUM_PORTS];

/*
 * Bit mask used to determine if a Hwi has been created/constructed for a port
 * already.
 */
static uint32_t portHwiCreatedBitMask = 0;

/* Boolean to confirm that GPIO_init() has been called */
static volatile bool initCalled = false;

/* GPIO driver config data structure */
extern GPIO_v1_Config GPIO_v1_config;

/* GPIO driver SoC specific hardware attributes */
extern GPIO_v1_hwAttrs_list GPIO_v1_hwAttrs;

/* GPIO driver Interrupt Service Routine */
static void GPIO_v1_hwiFxn(uintptr_t portIdx);

/* Function to get the gpio port index */
static uint8_t getGpioIntIndex(GPIO_PinConfig pinConfig);

/* Function to find the index of the right most set bit */
static inline uint32_t getPinNumber(uint32_t x);

static void GPIO_setConfig_v1(uint32_t index, GPIO_PinConfig pinConfig);

/*
 *  ======== getPinNumber ========
 *
 *  Internal function to efficiently find the index of the right most set bit.
 */
static inline uint32_t getPinNumber(uint32_t x) {
    uint32_t idx = 0;

    while((x & 0x1U) == 0)
    {
        idx++;
        x = x>>1;
    }

    return idx;
}

/*
 *  ======== getGpioIntIndex ========
 *
 *  Calculates the index into gpioInterruptVectors for a given pinConfig.
 */
static uint8_t getGpioIntIndex(GPIO_PinConfig pinConfig) {

    return ((uint8_t)GPIO_GET_PORT_NUM(pinConfig));
}

/*
 *  ======== GPIO_clearInt_v1 ========
 */
static void GPIO_clearInt_v1(uint32_t index);/*for misra warnings*/
static void GPIO_clearInt_v1(uint32_t index)
{
    uint32_t intrLineNum = GPIO_INT_LINE_1;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint32_t pinConfig;
    uint32_t pinNum;
    uint32_t portNum;

    /* Input parameter validation */
    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        GPIOPinIntClear(hwAttrs->baseAddr, intrLineNum, pinNum);
    }
}

/*
 *  ======== GPIO_disableInt_v1 ========
 */
static void GPIO_disableInt_v1(uint32_t index);/*for misra warnings*/
static void GPIO_disableInt_v1(uint32_t index)
{
    uint32_t key;
    uint32_t pinConfig;
    uint32_t intrLineNum = GPIO_INT_LINE_1;
    GPIO_v1_HwAttrs *hwAttrs;
    uint32_t pinNum;
    uint32_t portNum;

    /* Input parameter validation */
    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        /* Make atomic update */
        key = GPIO_osalHardwareIntDisable();

        GPIOPinIntDisable(hwAttrs->baseAddr, intrLineNum, pinNum);

        GPIO_osalHardwareIntRestore(key);
    }
}

/*
 *  ======== GPIO_enableInt_v1 ========
 */
static void GPIO_enableInt_v1(uint32_t index);/*for misra warnings*/
static void GPIO_enableInt_v1(uint32_t index)
{
    uint32_t key;
    uint32_t pinConfig;
    uint32_t intrLineNum = GPIO_INT_LINE_1;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint32_t portNum;
    uint32_t pinNum;

    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        /* Make atomic update */
        key = GPIO_osalHardwareIntDisable();

        GPIOPinIntEnable(hwAttrs->baseAddr, intrLineNum, pinNum);

        GPIO_osalHardwareIntRestore(key);
    }
}

/*
 *  ======== GPIO_hwiIntFxn ========
 *  Hwi function that processes GPIO interrupts.
 */
static void GPIO_v1_hwiFxn(uintptr_t portIdx)
{
    uint32_t               gpioPins;
    uint32_t               gpioBase;
    uint32_t               gpioIndex;
    uint32_t               bitNum;
    uint32_t               portNo = (uint32_t)portIdx;
    GPIO_PortCallbackInfo *portCallbackInfo;
    GPIO_v1_HwAttrs       *hwAttrs = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[portNo - 1U];
    uint32_t               intrLineNum = GPIO_INT_LINE_1;
    uint32_t               gpioPinsClear;

    portCallbackInfo = &gpioCallbackInfo[portNo -1U];
    gpioBase         = hwAttrs->baseAddr;

    /* Find out which pins have their interrupt flags set */
    gpioPins         = GPIORawIntStatus(gpioBase, intrLineNum, GPIO_PIN_MASK_ALL);
    gpioPinsClear    = gpioPins;

    /* Match each set bit to its corresponding callback function */
    while (gpioPins) {
        /* Gets the lowest order set bit number */
        bitNum = getPinNumber(gpioPins);
        gpioIndex = portCallbackInfo->pinIndex[bitNum];
        if (gpioIndex != CALLBACK_INDEX_NOT_CONFIGURED) {
            GPIO_v1_config.callbacks[gpioIndex]();
        }
        gpioPins &= ~(((uint32_t)1U) << bitNum);
    }

    /* Clear all the set bits at once */
    GPIOIntrClearMask(gpioBase, intrLineNum, gpioPinsClear);
}

/*
 *  ======== GPIO_init_v1 ========
 */
static void GPIO_init_v1(void);/*for misra warnings*/
static void GPIO_init_v1(void)
{
    uint32_t i, j;
    uint32_t portCfgDone[NUM_PORTS] = {0U,0U,0U,0U,0U,0U,0U,0U};
    uint32_t pinConfig;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint32_t portNum;

    portHwiCreatedBitMask = 0;

    /* Initialize all entries with 'not configured' key */
    for (i = 0; i < NUM_PORTS; i++) {
        for (j = 0; j < NUM_PINS_PER_PORT; j++) {
            gpioCallbackInfo[i].pinIndex[j] = CALLBACK_INDEX_NOT_CONFIGURED;
        }
    }

    /* Perform GPIO Reset and Module Enable only once for port */
    for(i = 0; i < GPIO_v1_config.numberOfPinConfigs; i++)
    {
        pinConfig = GPIO_v1_config.pinConfigs[i];
        if ((pinConfig & GPIO_DO_NOT_CONFIG) !=
            GPIO_DO_NOT_CONFIG)
        {
            portNum   = GPIO_GET_PORT_NUM(pinConfig);
            if ((portNum > 0U) && (portNum <= NUM_PORTS))
            {
                hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

                if(portCfgDone[portNum - 1U] == 0U)
                {
                    portCfgDone[portNum - 1U] = 1U;

                    /* Enable the GPIO module. */
                    GPIOModuleEnable(hwAttrs->baseAddr);
                }
            }
        }
    }

    /* Configure pins and create Hwis per static array content */
    for (i = 0; i < GPIO_v1_config.numberOfPinConfigs; i++) {
        if ((GPIO_v1_config.pinConfigs[i] & GPIO_DO_NOT_CONFIG) !=
            GPIO_DO_NOT_CONFIG) {
            GPIO_setConfig_v1(i, GPIO_v1_config.pinConfigs[i]);
        }
        if (i < GPIO_v1_config.numberOfCallbacks) {
            if (GPIO_v1_config.callbacks[i] != NULL) {
                GPIO_setCallback(i, GPIO_v1_config.callbacks[i]);
            }
        }
    }

    initCalled = (bool)true;
}

/*
 *  ======== GPIO_read_v1 ========
 */
static uint32_t GPIO_read_v1(uint32_t index); /*for misra warnings*/
static uint32_t GPIO_read_v1(uint32_t index)
{
    uint32_t value = 0;
    uint32_t pinConfig;
    uint32_t portNum;
    uint32_t pinNum;
    GPIO_v1_HwAttrs *hwAttrs = NULL;

    /* Input parameter validation */
    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        value = GPIOPinRead2(hwAttrs->baseAddr, pinNum);
    }

    return value;
}

/*
 *  ======== GPIO_setCallback_v1 ========
 */
static void GPIO_setCallback_v1(uint32_t index, GPIO_CallbackFxn callback); /*for misra warnings*/
static void GPIO_setCallback_v1(uint32_t index, GPIO_CallbackFxn callback)
{
    uint32_t key;
    uint32_t pinConfig;
    uint32_t pinNum;
    uint32_t portNum;

    GPIO_osalAssert(index >= GPIO_v1_config.numberOfCallbacks);

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        /* Make atomic update */
        key = GPIO_osalHardwareIntDisable();

        /* Store index into corresponding port's callbackInfo pinIndex entry */
        gpioCallbackInfo[(portNum) - 1U].pinIndex[pinNum] =
            (callback) ? index : CALLBACK_INDEX_NOT_CONFIGURED;

        /*
         * Only update callBackFunctions entry if different. This allows the
         * callBackFunctions array to be in flash for static systems.
         */
        if (GPIO_v1_config.callbacks[index] != callback) {
            GPIO_v1_config.callbacks[index] = callback;
        }

        GPIO_osalHardwareIntRestore(key);
    }
}

/*
 *  ======== GPIO_setConfig_v1 ========
 */
static void GPIO_setConfig_v1(uint32_t index, GPIO_PinConfig pinConfig)
{
    uint32_t   key;
    void *         hwiHandle;
    uint32_t       gpioBase;
    uint32_t       evtType;
    uint32_t       intrEvtType;
    /* there exist a variable with same name "gpioDirection". changed to solve the misra warning "MISRA.CT.UNIQUE.ID"*/
    uint8_t        gpio_Direction;
    uint8_t        gpioPin;
    uint8_t        gpioPortIntIdx;
    uint32_t       gpioPortIntBitMask;
    GPIO_PinConfig gpioPinConfig;
	OsalRegisterIntrParams_t interruptRegParams;
    uint32_t intrLineNum = GPIO_INT_LINE_1;
    uint32_t pinConfigVal;
    uint32_t portNum;
    uint32_t pinNum;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint8_t ret_flag = 0U;

    GPIO_osalAssert(!(index < GPIO_v1_config.numberOfPinConfigs));

    pinConfigVal = GPIO_v1_config.pinConfigs[index];
    portNum      = GPIO_GET_PORT_NUM(pinConfigVal);
    pinNum       = GPIO_GET_PIN_NUM(pinConfigVal);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs  = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        gpioBase = hwAttrs->baseAddr;
        gpioPin  = (uint8_t)pinNum;

        if ((pinConfig & GPIO_CFG_IN_INT_ONLY) == 0) {
            /* Get GPIO configuration settings */

            /* Determine settings for GPIO as input or output */
            if (pinConfig & GPIO_CFG_INPUT) {
                gpio_Direction = (uint8_t)GPIO_DIR_INPUT;
            }
            else {
                gpio_Direction = (uint8_t)GPIO_DIR_OUTPUT;
            }

            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            /* Set output value */
            if (gpio_Direction == GPIO_DIR_OUTPUT) {
                GPIOPinWrite(gpioBase, (uint32_t)gpioPin,
                    ((pinConfig & GPIO_CFG_OUT_HIGH) ? 1U : 0U));
            }

            /* Configure the GPIO pin */
            GPIODirModeSet(gpioBase, (uint32_t)gpioPin, (uint32_t)gpio_Direction);

            /* Update pinConfig with the latest GPIO configuration */
            gpioPinConfig = GPIO_v1_config.pinConfigs[index];
            gpioPinConfig &= ~GPIO_CFG_IO_MASK;
            gpioPinConfig |= (pinConfig & GPIO_CFG_IO_MASK);
            GPIO_v1_config.pinConfigs[index] = gpioPinConfig;

            GPIO_osalHardwareIntRestore(key);
        }

        /* Set type of interrupt and then clear it */
        if (pinConfig & GPIO_CFG_INT_MASK) {
            /* Calculate the gpioInterruptVectors index for the GPIO pin */
            gpioPortIntIdx = getGpioIntIndex(pinConfigVal);
            gpioPortIntBitMask = (((uint32_t)1U) << (gpioPortIntIdx - 1u));

            /* If Hwi has not already been created, do so */
            if ((portHwiCreatedBitMask & gpioPortIntBitMask) == 0) {

                /* Initialize with defaults */
                Osal_RegisterInterrupt_initParams(&interruptRegParams);

                interruptRegParams.corepacConfig.isrRoutine  = (&GPIO_v1_hwiFxn);
                interruptRegParams.corepacConfig.arg         = (uintptr_t)(portNum);

                interruptRegParams.corepacConfig.priority = GPIO_v1_config.intPriority;
                interruptRegParams.corepacConfig.name=NULL;
                interruptRegParams.corepacConfig.corepacEventNum=hwAttrs->line1EventId; /* Event going in to CPU */
                interruptRegParams.corepacConfig.intVecNum=hwAttrs->line1IntNum; /* Host Interrupt vector */

                /* Register interrupts */
                GPIO_osalRegisterInterrupt(&interruptRegParams,&(hwiHandle));

                if (hwiHandle == NULL) {
                    /* error constructing the Hwi for GPIO Port */
                    ret_flag = 1U;
                }
            }

            if(ret_flag == 0u)
            {
                key = GPIO_osalHardwareIntDisable();

                /* Mark the Hwi as created */
                portHwiCreatedBitMask |= gpioPortIntBitMask;

                /* Map correct interrupt type event based on the flag */
                evtType = (pinConfig & GPIO_CFG_INT_MASK) >> GPIO_CFG_INT_LSB;

                switch(evtType)
                {
                    case 1U:
                        intrEvtType = GPIO_INT_TYPE_FALL_EDGE;
                        break;
                    case 2U:
                        intrEvtType = GPIO_INT_TYPE_RISE_EDGE;
                        break;
                    case 3U:
                        intrEvtType = GPIO_INT_TYPE_BOTH_EDGE;
                        break;
                    case 4U:
                        intrEvtType = GPIO_INT_TYPE_LEVEL_LOW;
                        break;
                    case 5U:
                        intrEvtType = GPIO_INT_TYPE_LEVEL_HIGH;
                        break;
                    default:
                        /** If event type is none of the above then it will be forced to
                          * FALLING EDGE interrupt event type.
                          */
                        intrEvtType = GPIO_INT_TYPE_FALL_EDGE;
                    break;
                }

                GPIOIntTypeSet(hwAttrs->baseAddr, (uint32_t)gpioPin, intrEvtType);
                GPIOPinIntClear(hwAttrs->baseAddr, intrLineNum, (uint32_t)gpioPin);

                /* Update pinConfig with the latest interrupt configuration */
                gpioPinConfig = GPIO_v1_config.pinConfigs[index];
                gpioPinConfig &= ~(GPIO_CFG_INT_MASK);
                gpioPinConfig |= (pinConfig & GPIO_CFG_INT_MASK);
                GPIO_v1_config.pinConfigs[index] = gpioPinConfig;

                GPIO_osalHardwareIntRestore(key);
            }
        }
    }
    return;
}

/*
 *  ======== GPIO_toggle_v1 ========
 */
static void GPIO_toggle_v1(uint32_t index); /*for misra warnings*/
static void GPIO_toggle_v1(uint32_t index)
{
    uint32_t key;
    uint32_t     value;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint32_t pinConfig;
    uint32_t pinNum;
    uint32_t portNum;

    /* Input parameter validation */
    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        /* Make atomic update */
        key = GPIO_osalHardwareIntDisable();

        value = GPIOPinOutValueRead(hwAttrs->baseAddr, pinNum);
        value = (value == 0U) ? 1U : 0U;
        GPIOPinWrite(hwAttrs->baseAddr, pinNum, value);

        /* Update pinConfig with new output value */
        GPIO_v1_config.pinConfigs[index] ^= GPIO_CFG_OUT_HIGH;

        GPIO_osalHardwareIntRestore(key);
    }
}

/*
 *  ======== GPIO_write_v1 ========
 */
static void GPIO_write_v1(uint32_t index, uint32_t value); /*for misra warnings*/
static void GPIO_write_v1(uint32_t index, uint32_t value)
{
    uint32_t key;
    GPIO_v1_HwAttrs *hwAttrs = NULL;
    uint32_t pinConfig;
    uint32_t pinNum;
    uint32_t portNum;

    /* Input parameter validation */
    GPIO_osalAssert(!((((bool)true) == initCalled) &&
        (index < GPIO_v1_config.numberOfPinConfigs)));

    pinConfig = GPIO_v1_config.pinConfigs[index];
    portNum   = GPIO_GET_PORT_NUM(pinConfig);
    pinNum    = GPIO_GET_PIN_NUM(pinConfig);
    if (((portNum > 0U) && (portNum <= NUM_PORTS)) &&
        (pinNum < NUM_PINS_PER_PORT))
    {
        hwAttrs   = (GPIO_v1_HwAttrs *)&GPIO_v1_hwAttrs[(portNum - 1U)];

        key = GPIO_osalHardwareIntDisable();

        /* Clear output from pinConfig */
        GPIO_v1_config.pinConfigs[index] &= ~GPIO_CFG_OUT_HIGH;

        if (value) {
            /* Set the pinConfig output bit to high */
            GPIO_v1_config.pinConfigs[index] |= GPIO_CFG_OUT_HIGH;
        }

        GPIOPinWrite(hwAttrs->baseAddr, pinNum, value);

        GPIO_osalHardwareIntRestore(key);
    }
}

/* GPIO function table for GPIO_v0 implementation */
const GPIO_FxnTable GPIO_FxnTable_v1 = {
    &GPIO_init_v1,
    &GPIO_read_v1,
    &GPIO_write_v1,
    &GPIO_clearInt_v1,
    &GPIO_disableInt_v1,
    &GPIO_enableInt_v1,
    &GPIO_setCallback_v1,
    &GPIO_setConfig_v1,
    &GPIO_toggle_v1,
};
