/*
 * Copyright (c) 2014-2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       GPIO_v1.h
 *
 *  @brief      GPIO driver
 *
 *  The GPIO header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/gpio/soc/GPIO_v1.h>
 *  @endcode
 *
 *  # Operation #
 *
 *  The GPIO module allows you to manage General Purpose I/O pins via simple
 *  and portable APIs. The application is required to supply a GPIO_v1_Config
 *  structure to the module (see example below). This structure communicates to
 *  the GPIO module how to configure the pins used by the application (See the
 *  description of GPIO_PinConfig in the GPIO.h file).
 *
 *  The application is required to call GPIO_init(). This function will
 *  initialize all the GPIO pins defined in the GPIO_PinConfig table to the
 *  configurations specified. Once completed the other APIs can be used to
 *  access the pins.
 *
 *  Asserts are used to verify that the driver has been initialized, and is
 *  reading/writing a valid index.
 *
 *  The following is an example of the code required to use 2 LEDs on an
 *  AM57X IDK board.
 *
 *  Board header file:
 *  @code
 *  // Enum of GPIO names on the AM57X IDK EVM dev board
 *  typedef enum AM57X_IDK_EVM_GPIOName {
 *      AM57X_IDK_EVM_GRN_LED = 0,
 *      AM57X_IDK_EVM_YEL_LED,
 *  } AM57X_IDK_EVM_GPIOName;
 *  @endcode
 *
 *  Board initialization code:
 *  @code
 *  #include <ti/drv/GPIO.h>
 *  #include <ti/drv/gpio/soc/GPIO_v1.h>
 *
 *  // Array of pin configurations
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in header file.
 *  // NOTE: Pins not used for interrupts should be placed at the end of the
 *           array.  Callback entries can be omitted from callbacks array to
 *           reduce memory usage.
 *  const GPIO_PinConfig gpioPinConfigs[] = {
 *      // Input pins
 *      // AM57X_IDK_LED_GRN
 *      AM57X_IDK_GPIO_GRN_PIN | GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT,
 *
 *      // Output pins
 *      // AM57X_IDK_LED_YEL
 *      AM57X_IDK_GPIO_YEL_PIN | GPIO_CFG_OUTPUT,
 *  };
 *
 *  // Array of callback function pointers
 *  // NOTE: The order of the pin configurations must coincide with what was
 *  //       defined in header file.
 *  // NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *           reduce memory usage (if placed at end of gpioPinConfigs array).
 *  const GPIO_callbackFxn gpioCallbackFunctions[] = {
 *      NULL,       // AM57X_IDK_LED_GRN
 *      NULL
 *  };
 *
 *  // The device-specific GPIO_config structure
 *  const GPIO_v1_Config GPIO_v1_config = {
 *      .pinConfigs = (GPIO_PinConfig *) gpioPinConfigs,
 *      .callbacks = (GPIO_CallbackFxn *) gpioCallbackFunctions,
 *      .numberOfPinConfigs = sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
 *      .numberOfCallbacks = sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
 *      .intPriority = (~0)
 *  };
 *
 *  // Initialize peripheral and pins using the following init API.
 *
 *      GPIO_init();
 *
 *  @endcode
 *
 *  Keep in mind that the callback functions will be called in the context of
 *  an interrupt service routine and should be designed accordingly.  When an
 *  interrupt is triggered, the interrupt status of all (interrupt enabled) pins
 *  on a port will be read, cleared, and the respective callbacks will be
 *  executed.  Callbacks will be called in order from least significant bit to
 *  most significant bit.
 *
 *  ============================================================================
 */

#ifndef GPIO__V1__H
#define GPIO__V1__H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ti/drv/gpio/GPIO.h>

/* Mask for GPIO pin number */
#define GPIO_CFG_PIN_NUM_MASK     (0x000000FFU)

/* Shift for GPIO pin number */
#define GPIO_CFG_PIN_NUM_SHIFT    (0x00U)

/* Mask for GPIO port number */
#define GPIO_CFG_PORT_NUM_MASK    (0x0000FF00U)

/* Shift for GPIO port number */
#define GPIO_CFG_PORT_NUM_SHIFT   (0x8U)

/* Macro to formulated device specific port pin configuration */
#define GPIO_DEVICE_CONFIG(port, pin)  \
              ((((port) << GPIO_CFG_PORT_NUM_SHIFT) &(GPIO_CFG_PORT_NUM_MASK)) | \
              (((pin) << GPIO_CFG_PIN_NUM_SHIFT) & (GPIO_CFG_PIN_NUM_MASK)))


/*!
 *  @brief  GPIO Am57x Hardware attributes
 */
typedef struct GPIO_v1_HwAttrs_s {
    /*! GPIO Peripheral base address */
    uint32_t baseAddr;
    /*! GPIO Peripheral interrupt vector */
    uint32_t line1IntNum;
    /*! GPIO Peripheral interrupt vector */
    uint32_t line2IntNum;
    /*! GPIO Peripheral interrupt vector */
    uint32_t line1EventId;
    /*! GPIO Peripheral interrupt vector */
    uint32_t line2EventId;
} GPIO_v1_HwAttrs;

/* Avoid Misra warning "MISRA.DECL.ARRAY_SIZE" by pairing config array type 
 * with its array size to avoid externs with [] (no size) */
#define GPIO_MAX_HWATTRS_CNT       (8U) 
typedef GPIO_v1_HwAttrs GPIO_v1_hwAttrs_list[GPIO_MAX_HWATTRS_CNT];

/*!
 *  @brief  GPIO device specific driver configuration structure
 */
typedef struct GPIO_v1_Config_s {
    /*! Pointer to the board's PinConfig array */
    GPIO_PinConfig *pinConfigs;

    /*! Pointer to the board's callback array */
    GPIO_CallbackFxn *callbacks;

    /*! Number of pin configs defined */
    uint32_t numberOfPinConfigs;

    /*! Number of callbacks defined */
    uint32_t numberOfCallbacks;

    /*! Interrupt priority used for call back interrupts.  Setting ~0 will
     *  configure the lowest possible priority
     */
    uint32_t intPriority;
} GPIO_v1_Config;

/*!
 *  @brief  Device specific port/pin definition macros
 *
 *  Below are the port/pin definitions to be used within the board's pin
 *  configuration table.  These macros should be OR'd in with the respective pin
 *  configuration settings.
 */
#define GPIO_v1_EMPTY_PIN 0x0000

extern const GPIO_FxnTable GPIO_FxnTable_v1;

#ifdef __cplusplus
}
#endif

#endif /* _GPIO_V1_H */
