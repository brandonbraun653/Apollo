/*
 * Copyright (c) 2017-present, Texas Instruments Incorporated
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
 *  \defgroup DRV_OSAL_RegisterIntr RegisterIntr
 *            RegisterIntr interface
 *
 *  @{
 */
/** ============================================================================
 *  @file       RegisterIntr.h
 *
 *  @brief      Interrupt register routines
 *
 *
 *  ============================================================================
 */

#ifndef ti_osal_RegisterIntr__include
#define ti_osal_RegisterIntr__include

#include <ti/osal/EventCombinerP.h>
#include <ti/osal/HwiP.h>
#include <ti/osal/MuxIntcP.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
typedef void (*Osal_IsrRoutine)(uintptr_t arg);
/*!
 *  @brief  Interrupt Configuration parameters for the corepac (c6x/a15/m5/a8/a9)
 */
typedef struct {
    char    *name; /* Name of the instance for debugging purposes, could be set to NULL */
    int32_t corepacEventNum; /* Event number going in to the corepac */
    int32_t intVecNum; /* Interrupt vector */
    Osal_IsrRoutine isrRoutine; /* The ISR routine to hook the corepacEventNum to */
    uintptr_t arg; /* Argument to the ISR routine */
    uint32_t priority;
    uint32_t triggerSensitivity;
} OsalRegisterIntParams_corepac_t;

/* For C6x, if intVec=16, then event combiner is to be used */
#define OSAL_REGINT_INTVEC_EVENT_COMBINER (16) 

/*!
 *  @brief  Interrupt Configuration parameters for soc mux prior to reaching the core
 */
typedef struct {
   MuxIntcP_inParams *muxInParams;
   MuxIntcP_outParams *muxOutParams;
} OsalRegisterIntParams_socmux_t;

/*!
 *  @brief  Interrupt Configuration parameters for soc mux prior to reaching the core
 *          This is the data structure used to configure the interrupts in the system.
 *   coreConfig: This part configures the interrupt for corepac such as c66x, arm, m4
 *   socMuxConfig: This part configures the interrupt path for any SOC level mux such as CIC/GIC or cross bar,
 *                 leading up to the corepac
 */
typedef struct {
    OsalRegisterIntParams_corepac_t corepacConfig;
    OsalRegisterIntParams_socmux_t  socMuxConfig;
} OsalRegisterIntrParams_t;

/**
 *  \anchor OsalInterruptRetCode_e
 *  \name Osal Interrupt return Codes
 *  @{
 */
/*!
 *  @brief  Return error codes for  Osal Interrupt functions
 */
typedef int32_t OsalInterruptRetCode_e;
#define  OSAL_INT_SUCCESS                       ((int32_t) 0)
/* Success return code */
#define  OSAL_INT_ERR_INVALID_PARAMS            ((int32_t) -1)
/* Invalid input parameters */
#define  OSAL_INT_ERR_HWICREATE                 ((int32_t) -2)
/* Error while registering the Hwi object */
#define  OSAL_INT_ERR_EVENTCOMBINER_REG         ((int32_t) -3)
/* Error while registering the event combiner to the defaults */
#define  OSAL_INT_ERR_DELETE                    ((int32_t) -4)
/* Failed to delete a Interrupt handle. */
/* @} */

void Osal_RegisterInterrupt_initParams(OsalRegisterIntrParams_t *interruptRegParams);
/*!
 *  @brief  Function to initialize the interrupt registration configuration data structure
 *
 */
OsalInterruptRetCode_e Osal_RegisterInterrupt(OsalRegisterIntrParams_t *interruptRegParams,HwiP_Handle *hwiPHandlePtr);
/*!
 *  @brief  Function to register interrupt with parameters provided
 *
 */
OsalInterruptRetCode_e Osal_DeleteInterrupt(HwiP_Handle hwiPhandle,int32_t corepacEventNum);
/*!
 *  @brief  Function to delete interrupt corresponding to an event number
 *
 */
void Osal_EnableInterrupt(int32_t corepacEvent,int32_t interruptNum);
/*!
 *  @brief  Function to enable the interrupt corresponding to an event number
 *
 */
void Osal_DisableInterrupt(int32_t corepacEvent,int32_t interruptNum);
/*!
 *  @brief  Function to disable the  interrupt corresponding to an event number
 *
 */
void Osal_ClearInterrupt(int32_t corepacEvent,int32_t interruptNum);
/*!
 *  @brief  Function to clear the interrupts corresponding to an event number
 *
 */

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_RegisterIntr__include */
/* @} */
