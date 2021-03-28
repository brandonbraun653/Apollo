/*
 * Copyright (c) 2018, Texas Instruments Incorporated
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
 *  \defgroup DRV_OSAL_SwiP SwiP
 *            SwiP interface
 *
 *  @{
 */
/** ============================================================================
 *  @file       SwiP.h
 *
 *  @brief      Software Interrupt module for the RTOS Porting Interface
 *
 *  ============================================================================
 */

#ifndef ti_osal_SwiP__include
#define ti_osal_SwiP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*!
 *  @brief    SwiP handle of an instance
 *
 *  A SwiP_Handle returned from the ::SwiP_create represents that instance.
 */
typedef  void *SwiP_Handle;

/*!
 *  @brief    Status codes for SwiP APIs
 */
typedef enum SwiP_Status_e {
    SwiP_OK       = 0,
    SwiP_FAILURE  = (-(int32_t)1)
} SwiP_Status;

/*!
 *  @brief  Prototype for the entry function for a software interrupt
 */
typedef void (*SwiP_Fxn)(uintptr_t arg0, uintptr_t arg1);

/*!
 *  @brief    Basic SwiP Parameters
 *
 *  Structure that contains the parameters passed into ::SwiP_create
 *  when creating a SwiP instance. The ::SwiP_Params_init function should
 *  be used to initialize the fields to default values before the application sets
 *  the fields manually. The SwiP default parameters are noted in
 *  SwiP_Params_init.
 */
typedef struct SwiP_Params_s {
    uintptr_t  arg0;       /*!< Argument 0 passed into the Swi function. */
    uintptr_t  arg1;       /*!< Argument 1 passed into the Swi function. */

} SwiP_Params;

/*!
 *  @brief  Function to create a software interrupt
 *
 *  @param  swiFxn entry function of the software interrupt
 *
 *  @param  swiPparams    Pointer to the instance configuration parameters. NULL
 *                    denotes to use the default parameters. The SwiP default
 *                    parameters are noted in ::SwiP_Params_init.
 *
 *  @return SwiP_Handle
 */
extern SwiP_Handle SwiP_create(SwiP_Fxn swiFxn, const SwiP_Params *swiPparams);

/*!
 *  @brief  Function to delete an interrupt on CortexM devices
 *
 *  @param  pHandle pointer of the handle returned from the SwiP_create call
 *
 *  @return SwiP_OK if successfull, SwiP_FAILURE if fail
 */
extern SwiP_Status SwiP_delete(SwiP_Handle *pHandle);

/*!
 *  @brief  Initialize params structure to default values.
 *
 *  @param swiPparams  Pointer to the instance configuration parameters.
 */
extern void SwiP_Params_init(SwiP_Params *swiPparams);

/*!
 *  @brief  Function to post the Swi interrupt
 *
 *  @param  swiPhandle The swiP handle
 * 
 *  @return  SwiP_OK if successfull, SwiP_FAILURE if fail
 */
extern SwiP_Status SwiP_post(SwiP_Handle swiPhandle);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_SwiP__include */
/* @} */
