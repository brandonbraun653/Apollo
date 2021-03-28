/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 *  \defgroup DRV_OSAL_MuxIntcP MuxIntcP
 *            MuxIntcP interface
 *
 *  @{
 */ 
/** ============================================================================
 *  @file       MuxIntcP.h
 *
 *  @brief      Interrupt Controller Mux module for the RTOS Porting Interface
 *
 *
 *  ============================================================================
 */

#ifndef ti_osal_MuxIntcP__include
#define ti_osal_MuxIntcP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*!
 *  @brief    Status codes for MuxIntcP APIs
 */
typedef enum MuxIntcP_Status_e {
    MuxIntcP_OK       = 0,
    MuxIntcP_FAILURE  = (-(int32_t)1)
} MuxIntcP_Status;
/* Cross bar MuxNum to be used for MuxIntcP_create() */
#define MUXINTCP_CROSSBAR_MUXNUM_DSP1  (0)
#define MUXINTCP_CROSSBAR_MUXNUM_DSP2  (1)
#define MUXINTCP_CROSSBAR_MUXNUM_IPU1  (2)
#define MUXINTCP_CROSSBAR_MUXNUM_IPU2  (3)
#define MUXINTCP_CROSSBAR_MUXNUM_MPU   (4)

#define MUXINTCP_CROSSBAR_MUXNUM_INVALID (-(int32_t)1)

/*!
 *  @brief  Prototype for the entry function for a cpIntc interrupt
 */
typedef void (*MuxIntcP_Fxn)(uintptr_t arg);

/*!
 *  @brief  Prototype for the MuxIntc dispatch function
 */
typedef void (*MuxIntcFxn)(uintptr_t arg);

/*!
 *  @brief    Basic MuxIntcP Input Parameters
 *
 *  Structure that contains the parameters passed into ::MuxIntcP_create
 *  when creating a MuxIntcP instance.
 */
typedef struct MuxIntcP_inParams_s {
 /* Input parameters */
    uintptr_t  arg;          /*!< Argument passed into the MuxIntc function. */
    int32_t    muxNum;       /*!< K2: CIC number; AM: Xbar instance number:MUXINTCP_CROSSBAR_MUXNUM_##,-1: reserved for RM */
    int32_t    muxInEvent;   /*!< K2: CIC input event; AM: Xbar input system event; -1: reserved for RM  */
    int32_t    muxOutEvent;  /*!< K2: Host int num, output int from CIC; AM: Xbar IRQ instance */
    MuxIntcFxn muxIntcFxn;   /*!< K2: ISR function for CIC; AM: not used */
} MuxIntcP_inParams;

typedef struct MuxIntcP_outParams_s {
 /* Output parameters */
    uintptr_t  arg;          /*!< Argument passed out from the MuxIntc function. */
    uint32_t   eventId;      /*!< K2: Mapped CorePac Event Id, input event to CorePac IntC; AM: not used */
    MuxIntcFxn muxIntcFxn;   /*!< K2: CIC dispatch function for Intc; AM: not used */
} MuxIntcP_outParams;

/*!
 *  @brief  Function to create an interrupt controller mux
 *
 *  @param  inParams  Pointer to the MuxIntcP input Parameters
 *
 *  @param  outParams  Pointer to the MuxIntcP output Parameters
 *
 *  @return MuxIntcP_Status on MuxIntcP_OK or MuxIntcP_FAILURE
 */
extern MuxIntcP_Status MuxIntcP_create(MuxIntcP_inParams *inParams, MuxIntcP_outParams *outParams);

/*!
 *  @brief  Function to enable interrupt controller mux for an input event
 *
 *  @param  muxNum      Interrupt Controller mux number
 *  @param  muxInEvent  Interrupt Controller mux input event ID
 */
extern void MuxIntcP_enableInEvent(int32_t muxNum, int32_t muxInEvent);

/*!
 *  @brief  Function to disable interrupt controller mux for an input event
 *
 *  @param  muxNum      Interrupt Controller mux number
 *  @param  muxInEvent  Interrupt Controller mux input event ID
 */
extern void MuxIntcP_disableInEvent(int32_t muxNum, int32_t muxInEvent);

/*!
 *  @brief  Function to clear interrupt controller mux for an input event
 *
 *  @param  muxNum      Interrupt Controller mux number
 *  @param  muxInEvent  Interrupt Controller mux input event ID
 */
extern void MuxIntcP_clearInEvent(int32_t muxNum, int32_t muxInEvent);

/*!
 *  @brief  Function to enable interrupt controller mux  for an output event
 *
 *  @param  muxNum       Interrupt Controller mux number
 *  @param  muxOutEvent  Interrupt Controller mux output event ID
 */
extern void MuxIntcP_enableOutEvent(int32_t muxNum, int32_t muxOutEvent);

/*!
 *  @brief  Function to disable interrupt controller mux  for an output event
 *
 *  @param  muxNum       Interrupt Controller mux number
 *  @param  muxOutEvent  Interrupt Controller mux output event ID
 */
extern void MuxIntcP_disableOutEvent(int32_t muxNum, int32_t muxOutEvent);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_MuxIntcP__include */
/* @} */
