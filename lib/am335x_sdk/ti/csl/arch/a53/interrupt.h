/*
 *  Copyright (c) Texas Instruments Incorporated 2013-2017
 *
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

/**
 *  \file  interrupt.h
 *
 *  \brief This file contains the API prototypes for configuring INTC for
 *         ARM Cortex-A8
 */

#ifndef INTERRUPT_GICV3_H
#define INTERRUPT_GICV3_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/src/ip/arm_gic/V2/cslr_gic500.h>
#include <ti/csl/hw_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros & typedefs                          */
/* ========================================================================== */
/*
 * \brief Macros which can be passed to IntPrioritySet API as hostIntRoute.
  *  @{
*/

/* External interrupt from the system
 * ID00-ID15: SGI (Software generated interrupts)
 * ID16-ID31: PPI (Private Peripheral interrupts)
 * ID31-ID960: SPI (Shared peripheral interrupts)
 */
#define NUM_INTERRUPTS_EXTERNAL     (960U)
#define NUM_INTERRUPTS              (1024U)
/* @} */

/* ========================================================================== */
/*                          Internal typedef Declarations                     */
/* ========================================================================== */
typedef void (*IntrFuncPtr)(void *handle);

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    Registers an interrupt Handler in the interrupt vector table for
 *           system interrupts.
 *
 * \param    intrNum - Interrupt Number
 * \param    fnHandler - Function pointer to the ISR
 * \param    fun_arg - Argument to the ISR
 *
 * Note: When the interrupt occurs for the sytem interrupt number indicated,
 * the control goes to the ISR given as the parameter.
 *
 * \return      None.
 **/
void Intc_IntRegister(uint16_t intrNum, IntrFuncPtr fptr, void *fun_arg);

/**
 * \brief   Unregisters an interrupt
 *
 * \param   intrNum - Interrupt Number
 *
 * Note: Once an interrupt is unregistered it will enter infinite loop once
 * an interrupt occurs
 *
 * \return      None.
 **/
void Intc_IntUnregister(uint16_t intrNum);

/**
 * \brief   This API is used to initialize the interrupt controller. This API
 *          shall be called before using the interrupt controller.
 *
 * \param   coreId - core ID
 *
 * \return  None.
 *
 **/
void Intc_Init(uint8_t corId);

/**
 * \brief   This API assigns a priority to an interrupt and routes it to
 *          either IRQ or to FIQ. Priority 0 is the highest priority level
 *          Among the host interrupts, FIQ has more priority than IRQ.
 *
 * \param   intrNum  - Interrupt number
 * \param   priority - Interrupt priority level
 * \param   cpuId   - CPU ID of the cluster
 *
 * \return  None.
 *
 **/
void Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority,
                         uint8_t cpuId);

/**
 * \brief   This API enables the system interrupt in INTC. However, for
 *          the interrupt generation, make sure that the interrupt is
 *          enabled at the peripheral level also.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  Previous state of PSR.
 *
 **/
uint32_t Intc_SystemEnable(uint16_t intrNum);

/**
 * \brief   This API disables the system interrupt in INTC.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  Previous state of PSR.
 *
 **/
uint32_t Intc_SystemDisable(uint16_t intrNum);

/**
 * \brief   This API sets the status of the interrupt passed to pending.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  None.
 *
 **/
void IntSetPendingState(uint32_t intrNum);

/**
 * \brief   This API clears the pending status of interrupt passed.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  None.
 *
 **/
void IntClearPendingState(uint32_t intrNum);

/**
 * \brief   This API gets the pending status of interrupt passed.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  non zero value if pending.
 *          0              if not pending
 *
 **/
uint32_t IntGetPendingState(uint32_t intrNum);

/**
 * \brief   This API gets the active status of interrupt passed.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  non zero value if active.
 *          0              if not active
 *
 **/
uint32_t IntGetActiveState(uint32_t intrNum);

/**
 * \brief   This API clears the Active status of interrupt passed.
 *
 * \param   intrNum  - Interrupt number
 *
 * \return  None.
 *
 **/
void IntClearActiveState(uint32_t intrNum);

/**
 * \brief     This API is called when the CPU is aborted When the abort
 *            interrupt occurs , the control goes to the ISR which is registered
 *            using Intc_IntRegister else will result in infinite loop.
 *
 * \param     None.
 *
 * \return    None.
 *
 **/
void Intc_AbortHandler(uint64_t *excStack);

/**
 * \brief     This API is called  When the interrupt occurs ,
 *            the control goes to the ISR which is registered
 *            using Intc_IntRegister else will result in infinite loop.
 *
 * \param     None.
 *
 * \return    None.
 *
 **/
void IntCommonHandler(void);

/**
 *
 * \brief The Default Interrupt Handler.
 *
 * This is the default interrupt handler for all interrupts.  It simply loops
 * forever so that the system state is preserved for observation by a
 * debugger.  Since interrupts should be disabled before unregistering the
 * corresponding handler, this should never be called.
 *
 * \param     dummy argument.
 *
 * \return    None - it traps to infinite loop to debug the bare metal app.
 **/

void IntDefaultHandler(void *dummy);


/**
 * \brief     This API is called to check if interrupt controller
 *            is initialized via INTC CSL APIs.
 *
 * \param     None.
 *
 * \return    True if intc is initialized via CSL.
 *
 **/

Bool Intc_isInitialized(void);

/**
 * \brief     This API is called to Assign Level interrupt
 *            to the SPI interrupt number.
 *
 * \param     None.
 *
 * \return    True if operation is successful
 *
 **/
int32_t Intc_IntAssignLevelIntType(uint16_t intrNum);

/**
 * \brief     This API is called to Assign Edge interrupt
 *            to the SPI interrupt number.
 *
 * \param     None.
 *
 * \return    True if operation is successful
 *
 **/
int32_t Intc_IntAssignEdgeIntType(uint16_t intrNum);


#ifdef __cplusplus
}
#endif
#endif /* INTERRUPT_GICV3_H */
/********************************* End of file ******************************/
