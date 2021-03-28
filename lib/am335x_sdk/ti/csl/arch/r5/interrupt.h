/*
 *  Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \brief This file contains the API prototypes for configuring interrupt
 *         support for the ARM Cortex-R5 and VIM
 *
 *  The following is the recommended calling sequence for this API:
 *
 *  1. Call Intc_Init() to initialize the interrupt support
 *  2. For each interrupt you wish to enable...
 *     a. Call Intc_IntSetSrcType() to set interrupt type (level or pulse)
 *     b. Call Intc_IntPrioritySet() to set the interrupt priority (0-15) and
 *        mapping (IRQ or FIQ)
 *     c. Call Intc_IntRegister() to register the interrupt
 *     d. Call Intc_IntEnable() to enable the interrupt
 *  3. Call Intc_SystemEnable() to enable the R5 IRQ and FIQ interrupts
 *
 *  When an interrupt occurs, control goes to the ISR given as a parameter
 *  in the Intc_IntRegister() call for that specific interrupt. The pending
 *  interrupt is automatically cleared and acknowledged in the VIM.
 *
 *  Other calls available:
 *  o Call Intc_IntUnregister() to unregister a previously registered interrupt
 *  o Call Intc_IntDisable() to disable a previously enabled interrupt
 *  o Call Intc_SystemDisable() to disable the R5 IRQ and FIQ interrupts
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdint.h>
#include <ti/csl/arch/r5/csl_vim.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
typedef void  (*IntrFuncPtr)(void *ptr);
typedef void  (*exptnHandlerPtr)(void *ptr);

/**
 * \brief   List of Exceptions in R5. These exceptions are interrupts from
 *          0 to 6 in Vector table
 *
 **/

/** \brief Exception for RESET*/
#define EXCEPTION_R5_RESET                                  (0U)
/** \brief Exception for Undefined Instruction */
#define EXCEPTION_R5_UNDEF_INSTR                            (1U)
/** \brief Exception for Software interrupt */
#define EXCEPTION_R5_SW_INTR                                (2U)
/** \brief Exception for Abort (prefetch) */
#define EXCEPTION_R5_ABORT_PREFETCH                         (3U)
/** \brief Exception for Abort (data) */
#define EXCEPTION_R5_ABORT_DATA                             (4U)
/** \brief Exception for IRQ */
#define EXCEPTION_R5_IRQ                                    (5U)
/** \brief Exception for FIQ */
#define EXCEPTION_R5_FIQ                                    (6U)
/** \brief Maximum supported interrupts by VIM */
#define R5_VIM_INTR_NUM             (512U)

#if defined(SOC_TPR12)
/** \brief Base address of MCU Domain R5 VIM */
#define CSL_MCU_DOMAIN_VIM_BASE_ADDR0           (0x02080000U)
#define CSL_MCU_DOMAIN_VIM_BASE_ADDR1           (0x020A0000U)

/** \brief Base address of MAIN Domain R5 VIM */
#define CSL_MAIN_DOMAIN_VIM_BASE_ADDR0          (0x00000000U)
#define CSL_MAIN_DOMAIN_VIM_BASE_ADDR1          (0x00000000U)
#else
/** \brief Base address of MCU Domain R5 VIM */
#define CSL_MCU_DOMAIN_VIM_BASE_ADDR            (0x40F80000U)
#define CSL_MCU_DOMAIN_VIM_BASE_ADDR0           CSL_MCU_DOMAIN_VIM_BASE_ADDR
#define CSL_MCU_DOMAIN_VIM_BASE_ADDR1           CSL_MCU_DOMAIN_VIM_BASE_ADDR

/** \brief Base address of MAIN Domain R5 VIM */
#define CSL_MAIN_DOMAIN_VIM_BASE_ADDR           (0x0FF80000U)
#define CSL_MAIN_DOMAIN_VIM_BASE_ADDR0          CSL_MAIN_DOMAIN_VIM_BASE_ADDR
#define CSL_MAIN_DOMAIN_VIM_BASE_ADDR1          CSL_MAIN_DOMAIN_VIM_BASE_ADDR
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 * \brief  Structure containing the Exception Handlers.
 *         If application does not want register an exception handler then
 *         below handlers can be assigned to 'NULL' value.
 *         In such case, default handler will be used which have
 *         the infinite loop.
 */
typedef struct
{
    exptnHandlerPtr udefExptnHandler;
    /**< Undefined Instruction exception handler */
    void *udefExptnHandlerArgs;
    /**< Undefined Instruction exception handler Args */
    exptnHandlerPtr swiExptnHandler;
    /**< Software Interrupt exception handler */
    void *swiExptnHandlerArgs;
    /**< Software Interrupt exception handler Args */
    exptnHandlerPtr pabtExptnHandler;
    /**< Prefetch Abort exception handler */
    void *pabtExptnHandlerArgs;
    /**< Prefetch Abort exception handler Args */
    exptnHandlerPtr dabtExptnHandler;
    /**< Data Abort exception handler */
    void *dabtExptnHandlerArgs;
    /**< Data Abort exception handler Args */
    exptnHandlerPtr irqExptnHandler;
    /**< Interrupt Request exception handler.
     *   This will be used only if VIM is not enabled.
     */
    void *irqExptnHandlerArgs;
    /**< Interrupt Request exception handler Args.
     *   This will be used only if VIM is not enabled.
     */
    exptnHandlerPtr fiqExptnHandler;
    /**< Fast Interrupt Request exception handler.
     *   This will be used only if VIM is not enabled.
     */
    void *fiqExptnHandlerArgs;
    /**< Fast Interrupt Request exception handler Args.
     *   This will be used only if VIM is not enabled.
     */
}CSL_R5ExptnHandlers;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API is used to initialize the interrupt controller. This API
 *          shall be called before using the interrupt controller.
 *
 * \param   None
 *
 * \return  None
 *
 **/
void Intc_Init(void);

/**
 * \brief   This API configures the Interrupt Source Type in VIM.
 *
 * Note: This function should called before calling 'Intc_IntRegister()' function.
 *
 * \param   intrNum  - Interrupt number
 * \param   type     - Interrupt Type:
 *                     0 = Interrupt source is a level interrupt
 *                     1 = Interrupt source is a pulse interrupt
 *
 * \return  None
 *
 **/
void Intc_IntSetSrcType(uint16_t intrNum, uint32_t type);

/**
 * \brief   This API assigns a priority to an interrupt and routing as
 *          either IRQ or to FIQ. Priority 0 is the highest priority level.
 *          Among the host interrupts, FIQ has more priority than IRQ.
 *
 * Note: This function should called before calling 'Intc_IntRegister()' function.
 *
 * \param   intrNum  - Interrupt number
 * \param   priority - Interrupt priority level (0..15 with 0 being the
 *                     highest priority and 15 being the lowest priority)
 * \param   hostIntRoute - 0 = IRQ, otherwise FIQ
 *
 * \return  None
 *
 **/
void Intc_IntPrioritySet(uint16_t intrNum, uint16_t priority, uint8_t hostIntRoute);

/**
 * \brief    Registers an interrupt Handler in the interrupt vector table for
 *           system interrupts.
 *
 * \param    intrNum - Interrupt Number
 * \param    fnHandler - Function pointer to the ISR
 * \param    fun_arg - Argument to the ISR
 *
 * Note: When the interrupt occurs for the system interrupt number indicated,
 * the control goes to the ISR given as the parameter.
 *
 * \return      None
 **/
void Intc_IntRegister(uint16_t intrNum, IntrFuncPtr fptr, void *fun_arg);

/**
 * \brief   Un-registers an interrupt
 *
 * \param   intrNum - Interrupt Number
 *
 * Note: Once an interrupt is unregistered it will enter infinite loop once
 * an interrupt occurs
 *
 * \return      None
 **/
void Intc_IntUnregister(uint16_t intrNum);

/**
 * \brief   This function enables the Cortex-R5's IRQ and FIQ interrupts
 *
 * \param   None
 *
 * \return  None
 *
 **/
void Intc_SystemEnable(void);

/**
 * \brief   This function disables the Cortex-R5's IRQ and FIQ interrupts
 *
 * \param   None
 *
 * \return  cookie          IRQ and FIQ enable status(CPSR register value)
 *
 **/
uintptr_t Intc_SystemDisable(void);

/**
 * \brief   This function enables the Cortex-R5's IRQ and FIQ interrupts
 *          This can be called after Intc_SystemDisable() to restore
 *          system IRQ/FIQ.
 *
 * \param   cookie          Mask to enable IRQ and FIQ
 *
 * \return  None
 *
 **/
void Intc_SystemRestore(uintptr_t cookie);

/**
 * \brief  This function disables the specified interrupt in the VIM
 *
 * \param    intrNum - Interrupt number
 *
 * \return   Current status of IRQ
 *
 *
 **/
void Intc_IntDisable(uint16_t intrNum);

/**
 * \brief  This function enables the specified interrupt in the VIM
 *
 * \param    intrNum - Interrupt number
 *
 * \return   None
 *
 **/
void Intc_IntEnable(uint16_t intrNum);

/**
 * \brief   This API clears the pending system interrupt in INTC.
 **/
void Intc_IntClrPend(uint16_t intrNum);

/**
 * \brief  This function initializes exception  handlers for various exceptions.
 *
 * \param    handlers       Reference Exception handlers list.
 *                          Refer struct #CSL_R5ExptnHandlers
 *
 * \return   None
 *
 **/
void Intc_InitExptnHandlers(CSL_R5ExptnHandlers *handlers);

/**
 * \brief  This function registers handlers for various exceptions.
 *
 * \param    handlers       Exception handlers list.
 *                          Refer struct #CSL_R5ExptnHandlers
 *
 * \return   None
 *
 **/
void Intc_RegisterExptnHandlers(const CSL_R5ExptnHandlers *handlers);

#ifdef __cplusplus
}
#endif
#endif
/********************************* End of file ******************************/
