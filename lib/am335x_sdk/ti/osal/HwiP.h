/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
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
/**
 *  \ingroup DRV_OSAL_MODULE
 *  \defgroup DRV_OSAL_HwiP HwiP
 *            HWIP interface
 *
 *  @{
 */

/** ============================================================================
 *  @file       HwiP.h
 *
 *  @brief      Hardware Interrupt module for the RTOS Porting Interface
 *
 *  The ::HwiP_disable/::HwiP_restore APIs can be called recursively. The order
 *  of the HwiP_restore calls, must be in reversed order. For example:
 *  @code
 *  uintptr_t key1, key2;
 *  key1 = HwiP_disable();
 *  key2 = HwiP_disable();
 *  HwiP_restore(key2);
 *  HwiP_restore(key1);
 *  @endcode
 *
 *  ============================================================================
 */

#ifndef ti_osal_HwiP__include
#define ti_osal_HwiP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*********************************************************************
 * @def HWIP_USE_DEFAULT_PRIORITY
 * Use the default priority for the interrupts
 *
 *********************************************************************/
#define  HWIP_USE_DEFAULT_PRIORITY   (~((uint32_t)0))

/*!
 *  @brief    Opaque client reference to an instance of a HwiP
 *
 *  A HwiP_Handle returned from the ::HwiP_create represents that instance.
 */
typedef  void *HwiP_Handle;

/*!
 *  @brief    Status codes for HwiP APIs
 */
typedef enum HwiP_Status_e {
    HwiP_OK       = 0,
    HwiP_FAILURE  = (-(int32_t)1)
} HwiP_Status;

/**
 *  @brief Enumerates the types different trigger types.
 *  Please refer to Section 4.3.13 Interrupt Configuration Registers, GICD_ICFGRn
 *  of ARM® Generic Interrupt Controller Architecture version 2.0
 *  Architecture Specification document for details.
 */
typedef enum
{

    /**< Corresponding interrupt is level-sensitive */
    OSAL_ARM_GIC_TRIG_TYPE_LEVEL = 1,

    /**< Corresponding interrupt is edge  */
    OSAL_ARM_GIC_TRIG_TYPE_EDGE = 2,

    /**< Coressponding interrupt is high level sensitive */
    OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL = 3,

    /**< Coressponding interrupt is low level sensitive */
    OSAL_ARM_GIC_TRIG_TYPE_LOW_LEVEL = 4,

    /**< Coressponding interrupt is rising edge sensitive */
    OSAL_ARM_GIC_TRIG_TYPE_RISING_EDGE = 5,

    /**< Coressponding interrupt is falling edge sensitive */
    OSAL_ARM_GIC_TRIG_TYPE_FALLING_EDGE = 6

} OSAL_armGicTrigType_t;

/*!
 *  @brief  Prototype for the entry function for a hardware interrupt
 */
typedef void (*HwiP_Fxn)(uintptr_t arg);

/*!
 *  @brief    Basic HwiP Parameters
 *
 *  Structure that contains the parameters passed into ::HwiP_create
 *  when creating a HwiP instance. The ::HwiP_Params_init function should
 *  be used to initialize the fields to default values before the application sets
 *  the fields manually. The HwiP default parameters are noted in
 *  HwiP_Params_init.
 */
typedef struct HwiP_Params_s {
    char      *name;      /*!< Name of the clock instance. Memory must
                               persist for the life of the clock instance.
                               This can be used for debugging purposes, or
                               set to NULL if not needed. */
    uintptr_t  arg;       /*!< Argument passed into the Hwi function. */
    uint32_t   priority;  /*!< Device specific priority. */
    uint32_t   enableIntr; /*!< When set to TRUE, interrupt is enabled after the create
                                otherwise interrupt is disabled after HwiP_Create */
    uint32_t   evtId;     /*!< Event Id associated */
#if defined (__ARM_ARCH_7A__) || defined(__aarch64__) || defined (__TI_ARM_V7R4__)
    uint32_t   triggerSensitivity; /*!< Set an interrupt's trigger sensitivity for 
                                        ARM cortex-A Generic Interrupt Controller(GIC)
                                        v2.0 specific implementations as @ref OSAL_armGicTrigType_t 
                                    */
#endif
} HwiP_Params;

/*!
 *  @brief  Function to clear a single interrupt
 *
 *  @param  interruptNum interrupt number to clear
 */
extern void HwiP_clearInterrupt(int32_t interruptNum);

/*!
 *  @brief  Function to create an interrupt on CortexM devices
 *
 *  @param  interruptNum Interrupt Vector Id
 *
 *  @param  hwiFxn entry function of the hardware interrupt
 *
 *  @param  hwipParams    Pointer to the instance configuration parameters. NULL
 *                    denotes to use the default parameters. The HwiP default
 *                    parameters are noted in ::HwiP_Params_init.
 *
 *  @return 
 */
extern HwiP_Handle HwiP_create(int32_t interruptNum, HwiP_Fxn hwiFxn,
                               const HwiP_Params *hwipParams);

/*!
 *  @brief  Function to delete an interrupt on CortexM devices
 *
 *  @param  hwiPhandle returned from the HwiP_create call
 *
 *  @return A HwiP_Handle on success or a NULL
 */
extern HwiP_Status HwiP_delete(HwiP_Handle hwiPhandle);

/*!
 *  @brief  Function to disable interrupts to enter a critical region
 *
 *  This function can be called multiple times, but must unwound in the reverse
 *  order. For example
 *  @code
 *  uintptr_t key1, key2;
 *  key1 = HwiP_disable();
 *  key2 = HwiP_disable();
 *  HwiP_restore(key2);
 *  HwiP_restore(key1);
 *  @endcode
 *
 *  @return A key that must be passed to HwiP_restore to re-enable interrupts.
 */
extern uintptr_t HwiP_disable(void);

/*!
 *  @brief  Function to disable a single interrupt
 *
 *  @param  interruptNum interrupt number to disable
 */
extern void HwiP_disableInterrupt(int32_t interruptNum);

/*!
 *  @brief  Function to enable a single interrupt
 *
 *  @param  interruptNum interrupt number to enable
 */
extern void HwiP_enableInterrupt(int32_t interruptNum);

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  The default parameters are:
 *   - name: NULL
 *   - arg: 0
 *   - priority: ~0
 *
 *  @param hwipParams  Pointer to the instance configuration parameters.
 */
extern void HwiP_Params_init(HwiP_Params *hwipParams);

/*!
 *  @brief  Function to restore interrupts to exit a critical region
 *
 *  @param  key return from HwiP_disable
 */
extern void HwiP_restore(uintptr_t key);
/*!
 *  @brief  Function to get HwiP Handle from an interrupt number
 *
 *  @param  interruptNum the interrupt number
 */
HwiP_Handle HwiP_getHandle(int32_t interruptNum);
/*!
 *  @brief  Function to get the eventId associated with an interrupt number
 *
 *  @param  interruptNum the interrupt number
 */
int32_t HwiP_getEventId(int32_t interruptNum);
/*!
 *  @brief  Function to post the Hwi interrupt by software
 *
 *  @param  interruptNum the interrupt number
 * 
 *  @return  osal_OK if successfull, osal_UNSUPPORTED if not supported by SOC 
 */
extern int32_t HwiP_post(uint32_t interruptNum);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_HwiP__include */
/* @} */
