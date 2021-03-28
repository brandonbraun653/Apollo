/**
 *  \file   gpio.c
 *
 *  \brief  Low lever APIs performing hardware register writes and reads for
 *          GPIO IP version 0.
 *
 *   This file contains the hardware register write/read APIs for GPIO.
 */

/*
 * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/*TODO: This is defined to avoid the build error which is occurring when
        trying to include "hw_types.h". ARM asm instructions present inside
        some functions are giving error when tried to compile for C66. Ideally
        this should be taken care in the "hw_types.h" file itself. */
#define MEM_BARRIER_DISABLE

#include <ti/csl/src/ip/gpio/V0/gpio.h>

#include <stdint.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_gpioAux.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/*!
 *  \brief Macro indicating true value
 */
#define TRUE_VAL 1U

/*!
 *  \brief Macro indicating false value
 */
#define FALSE_VAL 0U

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void GPIOSetDirMode_v0(uint32_t baseAddr,
                       uint32_t pinNumber,
                       uint32_t pinDirection)
{
    /* Checking if pin is required to be an output pin. */
    if (GPIO_DIRECTION_OUTPUT == pinDirection)
    {
        CSL_GPIO_setPinDirOutput((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
    }
    else
    {
        CSL_GPIO_setPinDirInput ((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
    }
}


void GPIOPinWrite_v0(uint32_t baseAddr, uint32_t pinNumber, uint32_t pinValue)
{
    if(GPIO_PIN_HIGH == pinValue)
    {
        CSL_GPIO_setOutputData((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
    }
    else
    {
        CSL_GPIO_clearOutputData((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
    }
}


uint32_t GPIOPinRead_v0(uint32_t baseAddr, uint32_t pinNumber)
{
    uint8_t inData = 0;

    CSL_GPIO_getInputData((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber, &inData);

    return((uint32_t)inData);
}


uint32_t GPIOPinOutValueRead_v0(uint32_t baseAddr, uint32_t pinNumber)
{
    uint8_t outData = 0;

    CSL_GPIO_getOutputData((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber, &outData);

    return((uint32_t)outData);
}


void GPIOSetIntrType_v0(uint32_t baseAddr, uint32_t pinNumber, uint32_t eventType)
{
    uint32_t  tempEventType = eventType & 0xFFU;

    switch(tempEventType)
    {
        case GPIO_INTR_MASK_NO_EDGE:
        {
            /* Disable both rising and falling edge detection interrupts */
            CSL_GPIO_clearRisingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            CSL_GPIO_clearFallingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            break;
        }

        case GPIO_INTR_MASK_RISE_EDGE:
        {
			/* Only enable rising edge detection interupt */
            CSL_GPIO_clearFallingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            CSL_GPIO_setRisingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            break;
        }

        case GPIO_INTR_MASK_FALL_EDGE:
        {
			/* Only enable falling edge detection interupt */
             CSL_GPIO_clearRisingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            CSL_GPIO_setFallingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            break;
        }

        case GPIO_INTR_MASK_BOTH_EDGE:
        {
            /* Enable both rising and falling edge detection interrupts */
            CSL_GPIO_setRisingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            CSL_GPIO_setFallingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
            break;
        }

        default:
        break;
    }
}


void GPIOIntrEnable_v0(uint32_t baseAddr, uint32_t pinNumber, uint32_t eventType)
{
    /* Enable the specified gpio pin interrupt */
    if (CSL_GPIO_isBankInterruptEnabled((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)(pinNumber / 16U)) == FALSE)
    {
        CSL_GPIO_bankInterruptEnable((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)(pinNumber / 16U));
    }
    GPIOSetIntrType_v0(baseAddr, pinNumber, eventType);
}


void GPIOIntrDisable_v0(uint32_t baseAddr, uint32_t pinNumber)
{
    /* Disable both rising and falling edge detection interrupts */
    CSL_GPIO_clearRisingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
    CSL_GPIO_clearFallingEdgeDetect((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
}


uint32_t GPIOIntrStatus_v0(uint32_t baseAddr, uint32_t pinNumber)
{
    CSL_GpioHandle  hGpio = (CSL_GpioHandle)((uintptr_t) baseAddr);
    uint32_t intrStatus;

    intrStatus = (((uint32_t)CSL_GPIO_getInterruptStatus(hGpio, (uint8_t)pinNumber)) << pinNumber);

    return intrStatus;
}

void GPIOIntrStatusMask_v0(uint32_t baseAddr, uint32_t bankIdx, uint32_t *intrStatusMask)
{
    CSL_GpioHandle  hGpio = (CSL_GpioHandle)((uintptr_t) baseAddr);

    *intrStatusMask = (hGpio->BANK_REGISTERS[bankIdx].INTSTAT);
}

void GPIOIntrClear_v0(uint32_t baseAddr, uint32_t pinNumber)
{
    /* Clear the interrupt status of specified gpio pin */
    CSL_GPIO_clearInterruptStatus((CSL_GpioHandle)((uintptr_t) baseAddr), (uint8_t)pinNumber);
}


void GPIOIntrClearMask_v0(uint32_t baseAddr, uint32_t bankIdx, uint32_t pinMask)
{
    CSL_GpioHandle hGpio = (CSL_GpioHandle)((uintptr_t) baseAddr);

    /* Clear the interrupt status of gpio banks */
    hGpio->BANK_REGISTERS[bankIdx].INTSTAT = pinMask;
}

