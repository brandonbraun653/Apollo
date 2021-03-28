/**
 *  \file   GPIO_v0.c
 *
 *  \brief  GPIO Driver APIs implementation specific to IP version 0.
 *
 *   This file contains the driver APIs for GPIO controller.
 */

/*
 * Copyright (C) 2015 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include <string.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/csl_types.h>
#include <ti/drv/gpio/src/v0/GPIO_v0.h>
#include <ti/csl/src/ip/gpio/V0/gpio.h>
#include <ti/drv/gpio/src/GPIO_osal.h>

/* Uninitialized callbackInfo pinIndex */
#define CALLBACK_INDEX_NOT_CONFIGURED (0xFFU)

/* Macro to extract GPIO pin number from the gpio pin configuration */
#define GPIO_GET_PIN_NUM(gpioConfig)  (((gpioConfig) & GPIO_CFG_PIN_NUM_MASK) >> \
                                        GPIO_CFG_PIN_NUM_SHIFT)

/* Macro to extract GPIO port number from the gpio pin configuration */
#define GPIO_GET_PORT_NUM(gpioConfig) (((gpioConfig) & GPIO_CFG_PORT_NUM_MASK) \
                                        >> GPIO_CFG_PORT_NUM_SHIFT)


/*
 * User defined pin indexes assigned to a port's 8 pins. Used by port interrupt
 * function to located callback assigned to a pin.
 */
typedef struct GPIO_PortCallbackInfo_s {
    /* The port's 8 corresponding user defined pinId indices */
    uint8_t pinIndex[GPIO_MAX_NUM_PINS_PER_PORT];
} GPIO_PortCallbackInfo;


/* Table of callbacks per port. */
static GPIO_PortCallbackInfo gpioCallbackInfo[GPIO_MAX_HWATTRS_V0_CNT];

/*
 * Bit mask used to determine if a Hwi has been created/constructed for a port
 * already.
 */
static uint32_t portHwiCreatedBitMask = 0;

/* Boolean to confirm that GPIO_init() has been called */
static volatile bool initCalled = (bool)false;

/* GPIO driver config data structure */
extern GPIO_v0_Config GPIO_v0_config;

/* GPIO driver SoC specific hardware attributes */
extern GPIO_v0_hwAttrsList GPIO_v0_hwAttrs;

/* GPIO driver Interrupt Service Routine */
static void GPIO_v0_hwiFxn(uintptr_t portIdx);

/* Function to get the gpio port index */
static uint8_t getGpioIntIndex(GPIO_PinConfig pinConfig);

/* Function to find the index of the right most set bit */
static inline uint32_t getPinNumber(uint32_t x);

static void GPIO_setConfig_v0(uint32_t idx, GPIO_PinConfig pinConfig);

/*
 *  ======== getPinNumber ========
 *
 *  Internal function to efficiently find the index of the right most set bit.
 */
static inline uint32_t getPinNumber(uint32_t x) {
    uint32_t idx = 0;
    uint32_t v = x;

    while((v & 0x1U) == 0U)
    {
        idx++;
        v = v >> 1U;
    }

    return idx;
}

/*
 *  ======== getGpioIntIndex ========
 *
 *  Calculates the index into gpioInterruptVectors for a given pinConfig.
 */
static uint8_t getGpioIntIndex(GPIO_PinConfig pinConfig) {

    return ((uint8_t)(GPIO_GET_PORT_NUM(pinConfig)));
}

/*
 *  ======== GPIO_clearInt_v0 ========
 */
static void GPIO_clearInt_v0(uint32_t idx); /*for misra warnings*/
static void GPIO_clearInt_v0(uint32_t idx)
{
    uint32_t pinConfig;
    uint32_t pinNum;
    uint32_t portNum;

    /* Input parameter validation */
    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            GPIOIntrClear_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum);
        }
    }
}

/*
 *  ======== GPIO_disableInt_v0 ========
 */
static void GPIO_disableInt_v0(uint32_t idx); /*for misra warnings*/
static void GPIO_disableInt_v0(uint32_t idx)
{
    uintptr_t key;
    uint32_t  pinConfig;
    uint32_t  pinNum;
    uint32_t  portNum;

    /* Input parameter validation */
    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            GPIOIntrDisable_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum);

            GPIO_osalHardwareIntRestore(key);
        }
    }
}

static uint32_t GPIO_getIntEvtType(GPIO_PinConfig pinConfig); /*for misra warnings*/
static uint32_t GPIO_getIntEvtType(GPIO_PinConfig pinConfig)
{
    /* Map correct interrupt type event based on the flag */
    uint32_t evtType, intrEvtType;

    evtType = (pinConfig & GPIO_CFG_INT_MASK) >> GPIO_CFG_INT_LSB;

    switch(evtType)
    {
        case 1U:
            intrEvtType = GPIO_INTR_MASK_FALL_EDGE;
            break;
        case 2U:
            intrEvtType = GPIO_INTR_MASK_RISE_EDGE;
            break;
        case 3U:
            intrEvtType = GPIO_INTR_MASK_BOTH_EDGE;
            break;
        default:
            /** If event type is none of the above then it will be forced to
            * FALLING EDGE interrupt event type.
            */
            intrEvtType = GPIO_INTR_MASK_FALL_EDGE;
            break;
    }
    return intrEvtType;
}

/*
 *  ======== GPIO_enableInt_v0 ========
 */
static void GPIO_enableInt_v0(uint32_t idx); /*for misra warnings*/
static void GPIO_enableInt_v0(uint32_t idx)
{
    uintptr_t key;
    uint32_t  pinConfig;
    uint32_t  pinNum;
    uint32_t  portNum;
    uint32_t  intrEvtType;

    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            intrEvtType = GPIO_getIntEvtType(pinConfig);
            GPIOIntrEnable_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum, intrEvtType);

            GPIO_osalHardwareIntRestore(key);
        }
    }
}

/*
*  ======== GPIO_hwiIntFxn ========
*  Hwi function that processes GPIO interrupts.
*/
static void GPIO_v0_hwiFxn(uintptr_t portIdx)
{
    uint32_t          gpioIntStatus;
    uint32_t          gpioBase;
    uint32_t          gpioIndex;
    uint32_t          pinNum;
    uint32_t          bankIdx, bankMaxIdx;
    uint32_t          portNum = (uint32_t)portIdx;
    uint32_t          numPins, numPorts;
    GPIO_v0_HwAttrs   *hwAttrs = &GPIO_v0_hwAttrs[portNum];
    GPIO_PortCallbackInfo *portCallbackInfo;
    GPIO_IntCfg       *intCfg;

    portCallbackInfo = &gpioCallbackInfo[portNum];
    gpioBase = hwAttrs->baseAddr;

    GPIO_socGetNumPinsPorts(&numPins, &numPorts);

    bankMaxIdx = numPins / GPIO_NUM_PINS_PER_BANK;
    if ((bankMaxIdx * GPIO_NUM_PINS_PER_BANK) < numPins)
    {
        bankMaxIdx++;
    }
    for (bankIdx = 0; bankIdx < bankMaxIdx; bankIdx++)
    {
        /* Find out which pins have their interrupt flags set */
        GPIOIntrStatusMask_v0(gpioBase, bankIdx, &gpioIntStatus);

        /* Clear all the set bits at once */
        GPIOIntrClearMask_v0(gpioBase, bankIdx, gpioIntStatus);

        /* Match each set bit to its corresponding callback function */
        while (gpioIntStatus != 0U)
        {
            /* Gets the lowest order set bit number */
            pinNum = getPinNumber(gpioIntStatus) + (bankIdx * GPIO_NUM_PINS_PER_BANK);
            gpioIndex = portCallbackInfo->pinIndex[pinNum];
            if (gpioIndex != CALLBACK_INDEX_NOT_CONFIGURED)
            {
                GPIO_v0_config.callbacks[gpioIndex]();
            }
            gpioIntStatus &= ~(((uint32_t)1U) << (pinNum % GPIO_NUM_PINS_PER_BANK));

            intCfg = hwAttrs->intCfg + pinNum;
            if (intCfg->intcMuxNum != INVALID_INTC_MUX_NUM)
            {
                GPIO_osalHardwareIntrClear((int32_t)intCfg->intcMuxInEvent, (int32_t)intCfg->intNum);
                GPIO_osalMuxIntcClearSysInt(intCfg->intcMuxNum, intCfg->intcMuxInEvent);
            }
        }
    }
}


/*
 *  ======== GPIO_init_v0 ========
 */
static void GPIO_init_v0(void); /*for misra warnings*/
static void GPIO_init_v0(void)
{
    uint32_t i, j;
    uint32_t numPins, numPorts;

    GPIO_socGetNumPinsPorts(&numPins, &numPorts);

    /* Initialize all entries with 'not configured' key */
    for (i = 0; i < numPorts; i++)
    {
        if(i < GPIO_MAX_HWATTRS_V0_CNT)
	{
	    for (j = 0; j < numPins; j++)
            {
	        gpioCallbackInfo[i].pinIndex[j] = CALLBACK_INDEX_NOT_CONFIGURED;
	    }
	}
    }

    /* Configure pins and create Hwis per static array content */
    for (i = 0; i < GPIO_v0_config.numberOfPinConfigs; i++)
    {
        if ((GPIO_v0_config.pinConfigs[i] & GPIO_DO_NOT_CONFIG) !=
            GPIO_DO_NOT_CONFIG)
        {
            GPIO_setConfig_v0(i, GPIO_v0_config.pinConfigs[i]);
        }
        if (i < GPIO_v0_config.numberOfCallbacks)
        {
            if (GPIO_v0_config.callbacks[i] != NULL)
            {
                GPIO_setCallback(i, GPIO_v0_config.callbacks[i]);
            }
        }
    }

    initCalled = (bool)true;
}

/*
 *  ======== GPIO_read_v0 ========
 */
static uint32_t GPIO_read_v0(uint32_t idx); /*for misra warnings*/
static uint32_t GPIO_read_v0(uint32_t idx)
{
    uint32_t value = 0;
    uint32_t pinConfig;
    uint32_t portNum;
    uint32_t pinNum;

    /* Input parameter validation */
    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            value = GPIOPinRead_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum);
        }
    }

    return value;
}

/*
 *  ======== GPIO_setCallback_v0 ========
 */
static void GPIO_setCallback_v0(uint32_t idx, GPIO_CallbackFxn callback); /*for misra warnings*/
static void GPIO_setCallback_v0(uint32_t idx, GPIO_CallbackFxn callback)
{
    uintptr_t key;
    uint32_t  pinConfig;
    uint32_t  pinNum;
    uint32_t  portNum;

    if (idx < GPIO_v0_config.numberOfCallbacks)
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            /* Store index into corresponding port's callbackInfo pinIndex entry */
            gpioCallbackInfo[portNum].pinIndex[pinNum] =
                (callback) ? (uint8_t)idx : (uint8_t)CALLBACK_INDEX_NOT_CONFIGURED;

            /*
             * Only update callBackFunctions entry if different. This allows the
             * callBackFunctions array to be in flash for static systems.
             */
            if (GPIO_v0_config.callbacks[idx] != callback) {
                GPIO_v0_config.callbacks[idx] = callback;
            }

            GPIO_osalHardwareIntRestore(key);
        }
    }
}

/*
 *  ======== GPIO_setConfig_v0 ========
 */
static void GPIO_setConfig_v0(uint32_t idx, GPIO_PinConfig pinConfig)
{
    uintptr_t       key;
    void *          hwiHandle = NULL;
    uint32_t        gpioBase;
    uint32_t        intrEvtType;
    uint8_t         gpio_Direction;
    uint8_t         gpioPortIntIdx;
    uint32_t        gpioPortIntBitMask;
    GPIO_PinConfig  gpioPinConfig;
    uint32_t        pinConfigVal;
    uint32_t        pinNum;
    uint32_t        portNum;
	OsalRegisterIntrParams_t interruptRegParams;
    MuxIntcP_inParams  muxInParams;
    MuxIntcP_outParams muxOutParams;
    GPIO_v0_HwAttrs *hwAttrs;
    GPIO_IntCfg     *intCfg;
    int32_t ret_socIntrPath=CSL_PASS;
    uint8_t ret_flag = 0U;  

    if (idx < GPIO_v0_config.numberOfPinConfigs)
    {
        portNum = GPIO_GET_PORT_NUM(pinConfig);
        pinNum  = GPIO_GET_PIN_NUM(pinConfig);
    }
    else
    {
        ret_flag = 1U;
    }
    if ((ret_flag == 0U)                    &&
        (portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
        (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
    {
        pinConfigVal  = GPIO_v0_config.pinConfigs[idx];
        hwAttrs       = &GPIO_v0_hwAttrs[portNum];
        gpioBase      = hwAttrs->baseAddr;
        intCfg        = hwAttrs->intCfg + pinNum;

        if ((pinConfig & GPIO_CFG_IN_INT_ONLY) == 0U) {
            /* Get GPIO configuration settings */

            /* Determine settings for GPIO as input or output */
            if ((pinConfig & GPIO_CFG_INPUT) != 0U)
            {
                gpio_Direction = GPIO_DIRECTION_INPUT;
            }
            else
            {
                gpio_Direction = GPIO_DIRECTION_OUTPUT;
            }

            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            /* Set output value */
            if (gpio_Direction == GPIO_DIRECTION_OUTPUT) {
                GPIOPinWrite_v0(gpioBase, pinNum,
                    (((pinConfig & GPIO_CFG_OUT_HIGH) != 0U) ? 1U : 0U));
            }

            /* Configure the GPIO pin */
            GPIOSetDirMode_v0(gpioBase, pinNum, (uint32_t)gpio_Direction);

            /* Update pinConfig with the latest GPIO configuration */
            gpioPinConfig = GPIO_v0_config.pinConfigs[idx];
            gpioPinConfig &= ~GPIO_CFG_IO_MASK;
            gpioPinConfig |= (pinConfig & GPIO_CFG_IO_MASK);
            GPIO_v0_config.pinConfigs[idx] = gpioPinConfig;

            GPIO_osalHardwareIntRestore(key);
        }

        /* Set type of interrupt and then clear it */
        if ((pinConfig & GPIO_CFG_INT_MASK) != 0U)
        {
            /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            /* Calculate the gpioInterruptVectors index for the GPIO pin */
            gpioPortIntIdx = getGpioIntIndex(pinConfigVal);
            gpioPortIntBitMask = ((uint32_t)1U) << gpioPortIntIdx;

            /* If Hwi has not already been created, do so */
            if ((portHwiCreatedBitMask & gpioPortIntBitMask) == 0U) {
                if (intCfg->intcMuxNum != INVALID_INTC_MUX_NUM)
                {
                    /* Setup intc mux */
                    muxInParams.arg         = (uintptr_t)(portNum);
                    muxInParams.muxNum      = intCfg->intcMuxNum;
                    muxInParams.muxInEvent  = intCfg->intcMuxInEvent;
                    muxInParams.muxOutEvent = intCfg->intcMuxOutEvent;
                    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&GPIO_v0_hwiFxn);
                    (void)memset(&muxOutParams, 0, sizeof(MuxIntcP_outParams));
                    (void)GPIO_osalMuxIntcSetup(&muxInParams, &muxOutParams);

                    interruptRegParams.corepacConfig.isrRoutine  = muxOutParams.muxIntcFxn;
                    interruptRegParams.corepacConfig.arg         = muxOutParams.arg;
                }
                else
                {
                    interruptRegParams.corepacConfig.isrRoutine  = (&GPIO_v0_hwiFxn);
                    interruptRegParams.corepacConfig.arg         = (uintptr_t)(portNum);
                }

                /* Setup Hardware Interrupt Controller */
#if !defined (__ARM_ARCH_7A__)
                if (intCfg->eventId == INVALID_INTC_EVENT_ID)
                {
                    /* error constructing the Hwi for GPIO Port */
                    ret_flag = 1U;
                }
#endif
                if(ret_flag == 0U)
                {
                    /* Populate the interrupt parameters */
                    interruptRegParams.corepacConfig.priority = GPIO_v0_config.intPriority;
                    interruptRegParams.corepacConfig.name=NULL;
                    interruptRegParams.corepacConfig.corepacEventNum = (int32_t)intCfg->eventId; /* Event going in to CPU */
                    interruptRegParams.corepacConfig.intVecNum = (int32_t)intCfg->intNum; /* Host Interrupt vector */
#if defined (__aarch64__)
                    interruptRegParams.corepacConfig.triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_EDGE; /* interrupt edge triggered */
#endif
#if defined (__TI_ARM_V7R4__)
                    interruptRegParams.corepacConfig.triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_EDGE;
#endif
                    /* Configure SOC interrupt path if any */
                    if(hwAttrs->socConfigIntrPath!=NULL) {
                        ret_socIntrPath = (*hwAttrs->socConfigIntrPath)(portNum,pinNum,hwAttrs,TRUE);
                    }

                    if(ret_socIntrPath==CSL_PASS) {
                        /* Register interrupts */
                        (void)GPIO_osalRegisterInterrupt(&interruptRegParams,&(hwiHandle));
                    }  

                    if (hwiHandle == NULL) {
                        /* error constructing the Hwi for GPIO Port */
                        ret_flag = 1U;
                    }
                }
            }
            
            if(ret_flag == 0U)
            {
                key = GPIO_osalHardwareIntDisable();

                /* Mark the Hwi as created */
                portHwiCreatedBitMask |= gpioPortIntBitMask;

                intrEvtType = GPIO_getIntEvtType(pinConfig);
                GPIOSetIntrType_v0(hwAttrs->baseAddr, pinNum, intrEvtType);
                GPIOIntrClear_v0(hwAttrs->baseAddr, pinNum);

                /* Update pinConfig with the latest interrupt configuration */
                gpioPinConfig = GPIO_v0_config.pinConfigs[idx];
                gpioPinConfig &= ~(GPIO_CFG_INT_MASK);
                gpioPinConfig |= (pinConfig & GPIO_CFG_INT_MASK);
                GPIO_v0_config.pinConfigs[idx] = gpioPinConfig;

                GPIO_osalHardwareIntRestore(key);
            }
        }
    }
    return;
}

/*
 *  ======== GPIO_toggle_v0 ========
 */
static void GPIO_toggle_v0(uint32_t idx); /*for misra warnings*/
static void GPIO_toggle_v0(uint32_t idx)
{
    uintptr_t key;
    uint32_t  value;
    uint32_t  pinConfig;
    uint32_t  pinNum;
    uint32_t  portNum;

    /* Input parameter validation */
    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            /* Make atomic update */
            key = GPIO_osalHardwareIntDisable();

            value = GPIOPinOutValueRead_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum);
            value = (value == 0U) ? 1U : 0U;
            GPIOPinWrite_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum, value);

            /* Update pinConfig with new output value */
            GPIO_v0_config.pinConfigs[idx] ^= GPIO_CFG_OUT_HIGH;

            GPIO_osalHardwareIntRestore(key);
        }
    }
}

/*
 *  ======== GPIO_write_v0 ========
 */
static void GPIO_write_v0(uint32_t idx, uint32_t value); /*for misra warnings*/
static void GPIO_write_v0(uint32_t idx, uint32_t value)
{
    uintptr_t key;
    uint32_t  pinConfig;
    uint32_t  pinNum;
    uint32_t  portNum;

    /* Input parameter validation */
    if (((bool)true == initCalled) &&
        (idx < GPIO_v0_config.numberOfPinConfigs))
    {
        pinConfig = GPIO_v0_config.pinConfigs[idx];
        portNum   = GPIO_GET_PORT_NUM(pinConfig);
        pinNum    = GPIO_GET_PIN_NUM(pinConfig);
        if ((portNum < GPIO_MAX_HWATTRS_V0_CNT) &&
            (pinNum < GPIO_MAX_NUM_PINS_PER_PORT))
        {
            key = GPIO_osalHardwareIntDisable();

            /* Clear output from pinConfig */
            GPIO_v0_config.pinConfigs[idx] &= ~GPIO_CFG_OUT_HIGH;

            if (value != 0U)
            {
                /* Set the pinConfig output bit to high */
                GPIO_v0_config.pinConfigs[idx] |= GPIO_CFG_OUT_HIGH;
            }

            GPIOPinWrite_v0(GPIO_v0_hwAttrs[portNum].baseAddr, pinNum, value);

            GPIO_osalHardwareIntRestore(key);
        }
    }
}

/* GPIO function table for GPIO_v0 implementation */
const GPIO_FxnTable GPIO_FxnTable_v0 = {
    &GPIO_init_v0,
    &GPIO_read_v0,
    &GPIO_write_v0,
    &GPIO_clearInt_v0,
    &GPIO_disableInt_v0,
    &GPIO_enableInt_v0,
    &GPIO_setCallback_v0,
    &GPIO_setConfig_v0,
    &GPIO_toggle_v0,
};
