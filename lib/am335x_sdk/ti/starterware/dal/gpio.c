/**
 *  \file     gpio.c
 *
 *  \brief    This file contains the device abstraction layer APIs for GPIO
 *            peripheral.
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
#include "hw_types.h"
#include "gpio.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

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
void GPIOModuleReset(uint32_t baseAddr)
{
    /*
     * Setting the SOFTRESET bit in System Configuration register.
     * Doing so would reset the GPIO module.
     */
    HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_SOFTRESET, GPIO_SYSCONFIG_SOFTRESET_RESET);

    /* Waiting until the GPIO Module is reset.*/
    while(0U ==
        ((HW_RD_REG32(baseAddr + GPIO_SYSSTS)) & (GPIO_SYSSTS_RESETDONE_MASK)));
}


void GPIOModuleEnable(uint32_t baseAddr, uint32_t enableModule)
{
    if (TRUE == enableModule)
    {
        /* Enable GPIO module */
        HW_WR_FIELD32((baseAddr +GPIO_CTRL),
            GPIO_CTRL_DISABLEMODULE, GPIO_CTRL_DISABLEMODULE_ENABLED);
    }
    else
    {
        /* Disable GPIO modle */
        HW_WR_FIELD32((baseAddr +GPIO_CTRL),
            GPIO_CTRL_DISABLEMODULE, GPIO_CTRL_DISABLEMODULE_DISABLED);
    }
}


void GPIOSetDirMode(uint32_t baseAddr,
                    uint32_t pinNumber,
                    uint32_t pinDirection)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + GPIO_OE);

    /* Checking if pin is required to be an output pin. */
    if (GPIO_DIRECTION_OUTPUT == pinDirection)
    {
        regVal &= ~(1U << pinNumber);
    }
    else
    {
        regVal |= (1U << pinNumber);
    }
    HW_WR_REG32((baseAddr + GPIO_OE), regVal);
}


void GPIOPinWrite(uint32_t baseAddr, uint32_t pinNumber, uint32_t pinValue)
{
    if(GPIO_PIN_HIGH == pinValue)
    {
        HW_WR_REG32((baseAddr + GPIO_SETDATAOUT), (1U << pinNumber));
    }
    else
    {
        HW_WR_REG32((baseAddr + GPIO_CLRDATAOUT), (1U << pinNumber));
    }
}


uint32_t GPIOPinRead(uint32_t baseAddr, uint32_t pinNumber)
{
    return((HW_RD_REG32(baseAddr + GPIO_DATAIN)) & (1U << pinNumber));
}


void GPIOMultiplePinsWrite(uint32_t baseAddr,
                           uint32_t setMask,
                           uint32_t clrMask)
{
    /* Setting the specified output pins in GPIO_DATAOUT register. */
    HW_WR_REG32((baseAddr + GPIO_SETDATAOUT), setMask);

    /* Clearing the specified output pins in GPIO_DATAOUT register. */
    HW_WR_REG32((baseAddr + GPIO_CLRDATAOUT), clrMask);
}


uint32_t GPIOMultiplePinsRead(uint32_t baseAddr, uint32_t readMask)
{
    return((HW_RD_REG32(baseAddr + GPIO_DATAIN)) & (readMask));
}


void GPIOSetIntrType(uint32_t baseAddr, uint32_t pinNumber, uint32_t eventType)
{
    uint32_t regVal = 0U;
    eventType &= 0xFFU;

    switch(eventType)
    {
        case GPIO_INTR_MASK_NO_LEVEL:
        {
            /* Disabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Disabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);
            break;
        }

        case GPIO_INTR_MASK_LEVEL_LOW:
        {
            /* Enabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Disabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);

            /* Disabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Disabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);
            break;
        }

        case GPIO_INTR_MASK_LEVEL_HIGH:
        {
            /* Disabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Enabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);

            /* Disabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Disabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);
            break;
        }

        case GPIO_INTR_MASK_BOTH_LEVEL:
        {
            /* Enabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Enabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);

            /* Disabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Disabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);
            break;
        }

        case GPIO_INTR_MASK_NO_EDGE:
        {
            /* Disabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Disabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);
            break;
        }

        case GPIO_INTR_MASK_RISE_EDGE:
        {
            /* Enabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Disabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);

            /* Disabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Disabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);
            break;
        }

        case GPIO_INTR_MASK_FALL_EDGE:
        {
            /* Disabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);;

            /* Enabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);

            /* Disabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Disabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);
            break;
        }

        case GPIO_INTR_MASK_BOTH_EDGE:
        {
            /* Enabling rising edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_RISINGDETECT);
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_RISINGDETECT), regVal);

            /* Enabling falling edge detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT);
            regVal |= (1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_FALLINGDETECT), regVal);

            /* Disabling logic LOW level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW)), regVal);

            /* Disabling logic HIGH level detect interrupt generation. */
            regVal = HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH));
            regVal &= ~(1U << pinNumber);
            HW_WR_REG32((baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH)), regVal);
            break;
        }

        default:
        break;
    }
}


void GPIOIntrEnable(uint32_t baseAddr, uint32_t intrLine, uint32_t pinNumber)
{
    /* Enable the specified gpio pin interrupt */
    HW_WR_REG32((baseAddr + GPIO_IRQSTS_SET(intrLine)), (1U << pinNumber));
}


void GPIOIntrDisable(uint32_t baseAddr, uint32_t intrLine, uint32_t pinNumber)
{
    /* Disable the specified gpio pin interrupt */
    HW_WR_REG32((baseAddr + GPIO_IRQSTS_CLR(intrLine)), (1U << pinNumber));
}


uint32_t GPIOIntrStatus(uint32_t baseAddr,
                        uint32_t intrLine,
                        uint32_t pinNumber)
{
    uint32_t intrStatus = 0U;

    intrStatus = ((HW_RD_REG32(baseAddr + GPIO_IRQSTS(intrLine))) &
        (1U << pinNumber));

    return intrStatus;
}


void GPIOIntrClear(uint32_t baseAddr, uint32_t intrLine, uint32_t pinNumber)
{
    /* Clear the interrupt status of specified gpio pin */
    HW_WR_REG32((baseAddr + GPIO_IRQSTS(intrLine)), (1U << pinNumber));
}


uint32_t GPIOIntrRawStatus(uint32_t baseAddr,
                           uint32_t intrLine,
                           uint32_t pinNumber)
{
    uint32_t intrStatus = 0U;

    intrStatus = ((HW_RD_REG32(baseAddr + GPIO_IRQSTS_RAW(intrLine))) &
        (1U << pinNumber));

    return intrStatus;
}


void GPIOIntrTrigger(uint32_t baseAddr, uint32_t intrLine, uint32_t pinNumber)
{
    HW_WR_REG32((baseAddr + GPIO_IRQSTS_RAW(intrLine)), (1U << pinNumber));
}


void GPIOWakeupIntrEnable(uint32_t baseAddr,
                          uint32_t smartWakeupLine,
                          uint32_t pinNumber)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + GPIO_IRQWAKEN(smartWakeupLine));
    regVal |= (1U << pinNumber);
    HW_WR_REG32((baseAddr + GPIO_IRQWAKEN(smartWakeupLine)), regVal);

    /* Check if Global wake up is enabled already, if not enable global wakeup*/
    if (0U ==
        ((HW_RD_REG32(baseAddr + GPIO_SYSCONFIG)) &
            (GPIO_SYSCONFIG_ENAWAKEUP_MASK)))
    {
        /* Enable GPIO global wake up */
        HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
            GPIO_SYSCONFIG_ENAWAKEUP, GPIO_SYSCONFIG_ENAWAKEUP_ENABLE);
    }
}


void GPIOWakeupIntrDisable(uint32_t baseAddr,
                           uint32_t smartWakeupLine,
                           uint32_t pinNumber)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + GPIO_IRQWAKEN(smartWakeupLine));
    regVal &= ~(1U << pinNumber);
    HW_WR_REG32((baseAddr + GPIO_IRQWAKEN(smartWakeupLine)), regVal);
}


void GPIOGlobalWakeupEnable(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_ENAWAKEUP, GPIO_SYSCONFIG_ENAWAKEUP_ENABLE);
}


void GPIOGlobalWakeupDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_ENAWAKEUP, GPIO_SYSCONFIG_ENAWAKEUP_DISABLE);
}


void GPIOAutoIdleModeEnable(uint32_t baseAddr, uint32_t enableAutoIdle)
{
    if (TRUE == enableAutoIdle)
    {
        /* Enable Auto idle mode */
        HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
            GPIO_SYSCONFIG_AUTOIDLE, GPIO_SYSCONFIG_AUTOIDLE_AUTOMATIC);
    }
    else
    {
        /* Disable Auto idle mode */
        HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
            GPIO_SYSCONFIG_AUTOIDLE, GPIO_SYSCONFIG_AUTOIDLE_FREERUN);
    }
}


void GPIOSetIdleMode(uint32_t baseAddr, uint32_t idleModeType)
{
    HW_WR_FIELD32((baseAddr + GPIO_SYSCONFIG),
        GPIO_SYSCONFIG_IDLEMODE, idleModeType);
}


void GPIOSetGatingRatio(uint32_t baseAddr, uint32_t gatingRatio)
{
    HW_WR_FIELD32((baseAddr + GPIO_CTRL), GPIO_CTRL_GATINGRATIO, gatingRatio);
}


void GPIODebounceFuncEnable(uint32_t baseAddr,
                            uint32_t pinNumber,
                            uint32_t debounceEnable)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + GPIO_DEBOUNCEN);

    if(TRUE == debounceEnable)
    {
        /* Enable debounce functionality */
        regVal &= ~(1U << pinNumber);
        regVal |= (GPIO_DEBOUNCEN_DEBOUNCEEN_N_DEBOUNCE << pinNumber);
    }
    else
    {
        /* Disable debounce functionality */
        regVal &= ~(1U << pinNumber);
        regVal |= (GPIO_DEBOUNCEN_DEBOUNCEEN_N_NODEBOUNCE << pinNumber);
    }
    HW_WR_REG32((baseAddr + GPIO_DEBOUNCEN), regVal);
}


void GPIOSetDebounceTime(uint32_t baseAddr, uint32_t debounceTime)
{
    HW_WR_FIELD32((baseAddr + GPIO_DEBOUNCINGTIME),
        GPIO_DEBOUNCINGTIME_DEBOUNCETIME, debounceTime);
}


uint32_t GPIOGetRevision(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + GPIO_REVISION));
}


void GPIOContextSave(uint32_t baseAddr, gpioContext_t *pCtx)
{
    pCtx->ctrl = HW_RD_REG32(baseAddr + GPIO_CTRL);
    pCtx->dir  = HW_RD_REG32(baseAddr + GPIO_OE);
    pCtx->data = HW_RD_REG32(baseAddr + GPIO_SETDATAOUT);
}


void GPIOContextRestore(uint32_t baseAddr, gpioContext_t *pCtx)
{
    HW_WR_REG32((baseAddr + GPIO_CTRL), pCtx->ctrl);
    HW_WR_REG32((baseAddr + GPIO_OE), pCtx->dir);
    HW_WR_REG32((baseAddr + GPIO_SETDATAOUT), pCtx->data);
}


/* ========================================================================== */
/*                   Deprecated Function Definitions                          */
/* ========================================================================== */

uint32_t GPIODirModeGet(uint32_t baseAddr, uint32_t pinNumber)
{
    uint32_t retVal = GPIO_DIRECTION_INPUT;

    if(0U == ((HW_RD_REG32(baseAddr + GPIO_OE)) & (1U << pinNumber)))
    {
        retVal = GPIO_DIRECTION_OUTPUT;
    }

    return retVal;
}

uint32_t GPIOIntTypeGet(uint32_t baseAddr, uint32_t pinNumber)
{
    uint32_t intrEvent = (GPIO_INTR_MASK_NO_LEVEL | GPIO_INTR_MASK_NO_EDGE);

    /* Checking if logic LOW level trigger interrupt is enabled. */
    if((HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_LOW))) &
        (1U << pinNumber))
    {
        intrEvent &= ~(GPIO_INTR_MASK_NO_LEVEL);
        intrEvent |= GPIO_INTR_MASK_LEVEL_LOW;
    }

    /* Checking if logic HIGH level trigger interrupt is enabled. */
    if((HW_RD_REG32(baseAddr + GPIO_LEVELDETECT(GPIO_LEVEL_HIGH))) &
        (1U << pinNumber))
    {
        intrEvent &= ~(GPIO_INTR_MASK_NO_LEVEL);
        intrEvent |= GPIO_INTR_MASK_LEVEL_HIGH;
    }

    /* Checking if rising edge trigger interrupt is enabled. */
    if((HW_RD_REG32(baseAddr + GPIO_RISINGDETECT)) & (1U << pinNumber))
    {
        intrEvent &= ~(GPIO_INTR_MASK_NO_EDGE);
        intrEvent |= GPIO_INTR_MASK_RISE_EDGE;
    }

    /* Checking if falling edge trigger interrupt is enabled. */
    if((HW_RD_REG32(baseAddr + GPIO_FALLINGDETECT)) & (1U << pinNumber))
    {
        intrEvent &= ~(GPIO_INTR_MASK_NO_EDGE);
        intrEvent |= GPIO_INTR_MASK_FALL_EDGE;
    }

    return intrEvent;
}