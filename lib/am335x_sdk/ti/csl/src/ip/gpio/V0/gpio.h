/**
 *  \file   gpio.h
 *
 *  \brief  File provides functional level API prototypes for GPIO interface.
 *
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

#ifndef  GPIO_V0_H_
#define  GPIO_V0_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/src/ip/gpio/V0/cslr_gpio.h>

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

/** \brief GPIO pin is at logic low.*/
#define GPIO_PIN_LOW                     (0x0U)
/** \brief GPIO pin is at logic high.*/
#define GPIO_PIN_HIGH                    (0x1U)

/** \brief Macro to configure GPIO pin as output */
#define GPIO_OE_OUTPUTEN_N_ENABLED       (0U)

/** \brief Macro to configure GPIO pin as input */
#define GPIO_OE_OUTPUTEN_N_DISABLED      (1U)

/** \brief Mask for all pins of single gpio port */
#define GPIO_PIN_MASK_ALL   0xFF

/**
 *  \anchor gpioIntrMask_t
 *  \name GPIO Interrupt mask
 *  @{
 */
/** \brief Enumerates the possible GPIO interrupt generation events. */
typedef uint32_t gpioIntrMask_t;
#define GPIO_INTR_MASK_NO_EDGE              (0x01U)
/**< No interrupt request on either rising or
       falling edges on the pin. */
#define GPIO_INTR_MASK_RISE_EDGE            (0x02U)
/**< Interrupt request on occurrence of a rising edge
       on the input GPIO pin. */
#define GPIO_INTR_MASK_FALL_EDGE            (0x04U)
/**< Interrupt request on occurrence of a falling edge
       on the input GPIO pin. */
#define GPIO_INTR_MASK_BOTH_EDGE            (0x08U)
/**< Interrupt request on occurrence of both a rising
       and a falling edge on the pin. */
/* @} */

/**
 *  \anchor gpioDirection_t
 *  \name GPIO Direction
 *  @{
 */
/** \brief Enumerates the direction of GPIO pin. */
typedef uint32_t gpioDirection_t;
#define GPIO_DIRECTION_INPUT                (GPIO_OE_OUTPUTEN_N_DISABLED)
/**< Input pin. */
#define GPIO_DIRECTION_OUTPUT               (GPIO_OE_OUTPUTEN_N_ENABLED)
/**< Output pin. */
/* @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding the GPIO context. */
typedef struct gpioContext
{
    uint32_t ctrl;
    /**< GPIO control register value. */
    uint32_t dir;
    /**< GPIO direction control register value. */
    uint32_t data;
    /**< GPIO pin value register. */
}gpioContext_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This API configures the direction of a specified GPIO pin as being
 *         either input or output.
 *
 * \param  baseAddr      The memory address of the GPIO instance being used.
 * \param  pinNumber     The number of the pin in the GPIO instance.
 *         'pinNumber' can take one of the following values:
 *         (0 <= pinNumber <= 63).
 * \param  pinDirection  The required direction for the GPIO pin.
 *         pinDirection' can take one of the value from the following enum:
 *         - #gpioDirection_t.
 */
void GPIOSetDirMode_v0(uint32_t baseAddr,
                       uint32_t pinNumber,
                       uint32_t pinDirection);


/**
 * \brief  This API drives an output GPIO pin to a logic HIGH or a logic LOW
 *         state.
 *
 * \param  baseAddr    The memory address of the GPIO instance being used
 * \param  pinNumber   The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 63).
 * \param  pinValue    This specifies whether a logic HIGH or a logic LOW
 *         should be driven on the output pin.
 *         'pinValue' can take one of the following values:
 *         - #GPIO_PIN_LOW  - indicating to drive a logic LOW(0) on the pin.
 *         - #GPIO_PIN_HIGH - indicating to drive a logic HIGH(1) on the pin.
 */
void GPIOPinWrite_v0(uint32_t baseAddr,
                     uint32_t pinNumber,
                     uint32_t pinValue);

/**
 * \brief   This API determines the logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 63)
 *
 * \retval  #GPIO_PIN_LOW  - indicating to drive a logic LOW(0) on the pin.
 * \retval  #GPIO_PIN_HIGH - indicating to drive a logic HIGH(1) on the pin.
 */
uint32_t GPIOPinRead_v0(uint32_t baseAddr, uint32_t pinNumber);


/**
 * \brief   This API determines the output logic level(value) on a specified
 *          GPIO pin.
 *
 * \param   baseAddr    The memory address of the GPIO instance being used
 * \param   pinNumber   The number of the pin in the GPIO instance
 *          'pinNumber' can take one of the following values:
 *          (0 <= pinNumber <= 63)
 *
 * \retval  #GPIO_PIN_LOW  - indicating to drive a logic LOW(0) on the pin.
 * \retval  #GPIO_PIN_HIGH - indicating to drive a logic HIGH(1) on the pin.
 */
uint32_t GPIOPinOutValueRead_v0(uint32_t baseAddr, uint32_t pinNumber);


/**
 * \brief  This API configures the event type for a specified input GPIO pin.
 *         Whenever the selected event occurs on that GPIO pin and if interrupt
 *         generation is enabled for that pin, the GPIO module will send an
 *         interrupt to CPU.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  pinNumber  The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *         (0 <= pinNumber <= 63).
 * \param  eventType  This specifies the event type on whose detection,
 *                    the GPIO module will send an interrupt to CPU,
 *                    provided interrupt generation for that pin is enabled.
 *         'eventType' can take one of the following values following enum:
 *         - #gpioIntrMask_t.
 *
 * \note  A typical use case of this API is explained below:
 *        If it is initially required that interrupt should be generated on a
 *        LOW level only, then this API can be called with
 *        #GPIO_INTR_MASK_LEVEL_LOW as the parameter.
 *        At a later point of time, if logic HIGH level only should be made as
 *        the interrupt generating event, then this API has to be first called
 *        with #GPIO_INTR_MASK_NO_LEVEL as the parameter and later with
 *        #GPIO_INTR_MASK_LEVEL_HIGH as the parameter. Doing this ensures that
 *        logic LOW level trigger for interrupts is disabled.
 */
void GPIOSetIntrType_v0(uint32_t baseAddr, uint32_t pinNumber, uint32_t eventType);


/**
 * \brief  This API enables the configured interrupt event on a specified input
 *         GPIO pin to trigger an interrupt request.
 *
 * \param  baseAddr    The memory address of the GPIO instance being used
 * \param  pinNumber  The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *        (0 <= pinNumber <= 63)
 */
void GPIOIntrEnable_v0(uint32_t baseAddr, uint32_t pinNumber, uint32_t eventType);

/**
 * \brief  This API disables interrupt generation due to the detection
 *         of any event on a specified input GPIO pin.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  pinNumber  The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *        (0 <= pinNumber <= 63)
 * \param  eventType  This specifies the event type on whose detection,
 *                    the GPIO module will send an interrupt to CPU,
 *                    provided interrupt generation for that pin is enabled.
 *         'eventType' can take one of the following values following enum:
 *         - #gpioIntrMask_t.
 */
void GPIOIntrDisable_v0(uint32_t baseAddr, uint32_t pinNumber);

/**
 * \brief  This API determines the enabled interrupt status of a specified pin.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  pinNumber  The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *        (0 <= pinNumber <= 63)
 *
 * \retval int_status The enabled interrupt status of the pin on the specified
 *                    interrupt line. This could either be a non-zero or a
 *                    zero value.
 */
uint32_t GPIOIntrStatus_v0(uint32_t baseAddr, uint32_t pinNumber);

/**
 * \brief  This API determines the enabled interrupt status of a specified pin.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  bankIdx    Bank index of the GPIO instance
 * \param  intrStatusMask  pointer of the interrupt status for the GPIO bank
 *
 */
void GPIOIntrStatusMask_v0(uint32_t baseAddr, uint32_t bankIdx, uint32_t *intrStatusMask);

/**
 * \brief  This API clears the enabled interrupt status of a specified GPIO
 *         pin.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  pinNumber  The number of the pin in the GPIO instance
 *         'pinNumber' can take one of the following values:
 *        (0 <= pinNumber <= 63)
 */
void GPIOIntrClear_v0(uint32_t baseAddr, uint32_t pinNumber);

/**
 * \brief  This API clears the enabled interrupt status of specified GPIO
 *         pins.
 *
 * \param  baseAddr   The memory address of the GPIO instance being used
 * \param  bankIdx    Bank index of the GPIO instance
 * \param  pinMask    Mask of pins whose interrupts need to be
 *                    cleared for the GPIO bank.
 */
void GPIOIntrClearMask_v0(uint32_t baseAddr, uint32_t bankIdx, uint32_t pinMask);

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef GPIO_V0_H_ */
